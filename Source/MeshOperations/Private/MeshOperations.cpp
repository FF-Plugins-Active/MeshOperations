// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshOperations.h"
//#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FMeshOperationsModule"

void FMeshOperationsModule::StartupModule()
{
	/*
	const FString BasePluginDir = IPluginManager::Get().FindPlugin("MESHOPERATIONS")->GetBaseDir();
	const FString DLL_Folder = FPaths::Combine(*BasePluginDir, TEXT("Source/MeshOperations/ThirdParty/occt/Win64/bin/"));
	const FString DLL_Path = FPaths::Combine(*DLL_Folder, TEXT("TKernel.dll"));
	
	this->Handle_TKernel = FPlatformProcess::GetDllHandle(*DLL_Path);

	if (!this->Handle_TKernel)
	{
		UE_LOG(LogTemp, Fatal, TEXT("OCCT TKernel.ddl couldn't load for Mesh Operations !"));
		return;
	}
	*/
#if defined (_WIN64) && USE_DELAYED_LOAD
	
	const FString BasePluginDir = IPluginManager::Get().FindPlugin("MESHOPERATIONS")->GetBaseDir();
	const FString DLL_Folder = FPaths::Combine(*BasePluginDir, TEXT("Source/MeshOperations/ThirdParty/occt/Win64/bin/"));

	class DllVisitor : public IPlatformFile::FDirectoryVisitor
	{
	public:

		TArray<FString> Files;
		DllVisitor() {}

		virtual bool Visit(const TCHAR* FileName, bool bIsDirectory) override
		{
			if (!bIsDirectory)
			{
				const FString CleanFile = FPaths::GetCleanFilename(FileName);
				Files.Add(CleanFile);
			}

			return true;
		}
	};

	DllVisitor GetFilesVisitor;
	FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*DLL_Folder, GetFilesVisitor);
	TArray<FString> DLL_Files = GetFilesVisitor.Files;

	for (const FString Each_DLL_File : DLL_Files)
	{
		const FString Each_DLL_Path = DLL_Folder + Each_DLL_File;
		void* Each_DLL = FPlatformProcess::GetDllHandle(*Each_DLL_Path);

		if (!Each_DLL)
		{
			UE_LOG(LogTemp, Fatal, TEXT("Mesh Operations : OCCT DLL failed to load : %s"), *Each_DLL_File);
			return;
		}

		this->OCCT_Handles.Add(Each_DLL_Path, Each_DLL);

	}

#endif
}

void FMeshOperationsModule::ShutdownModule()
{
#if defined (_WIN64) && USE_DELAYED_LOAD
	
	TArray<void*> Array_Handles;
	this->OCCT_Handles.GenerateValueArray(Array_Handles);
	
	for (void* Each_DLL : Array_Handles)
	{
		if (Each_DLL)
		{
			FPlatformProcess::FreeDllHandle(Each_DLL);
			Each_DLL = nullptr;
		}
	}

	Array_Handles.Empty();
	this->OCCT_Handles.Empty();

#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMeshOperationsModule, MeshOperations)