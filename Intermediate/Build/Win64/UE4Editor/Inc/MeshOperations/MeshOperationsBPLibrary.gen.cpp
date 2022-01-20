// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MeshOperations/Public/MeshOperationsBPLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMeshOperationsBPLibrary() {}
// Cross Module References
	MESHOPERATIONS_API UClass* Z_Construct_UClass_UMeshOperationsBPLibrary_NoRegister();
	MESHOPERATIONS_API UClass* Z_Construct_UClass_UMeshOperationsBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_MeshOperations();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EComponentMobility();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EAttachmentRule();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	PROCEDURALMESHCOMPONENT_API UScriptStruct* Z_Construct_UScriptStruct_FProcMeshTangent();
// End Cross Module References
	DEFINE_FUNCTION(UMeshOperationsBPLibrary::execGetVertexLocations)
	{
		P_GET_OBJECT(UStaticMesh,Z_Param_TargetStaticMesh);
		P_GET_PROPERTY(FIntProperty,Z_Param_LODs);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Vertices);
		P_GET_TARRAY_REF(int32,Z_Param_Out_Triangles);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Normals);
		P_GET_TARRAY_REF(FVector2D,Z_Param_Out_UVs);
		P_GET_TARRAY_REF(FProcMeshTangent,Z_Param_Out_Tangents);
		P_FINISH;
		P_NATIVE_BEGIN;
		UMeshOperationsBPLibrary::GetVertexLocations(Z_Param_TargetStaticMesh,Z_Param_LODs,Z_Param_Out_Vertices,Z_Param_Out_Triangles,Z_Param_Out_Normals,Z_Param_Out_UVs,Z_Param_Out_Tangents);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshOperationsBPLibrary::execGetFullName)
	{
		P_GET_OBJECT(UObject,Z_Param_Object);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UMeshOperationsBPLibrary::GetFullName(Z_Param_Object);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshOperationsBPLibrary::execAddProcMeshCompWithName)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_In_PMC_Name);
		P_GET_OBJECT(AActor,Z_Param_PMC_Outer);
		P_GET_PROPERTY(FByteProperty,Z_Param_PMC_Mobility);
		P_GET_ENUM(EAttachmentRule,Z_Param_PMC_Attachment_Rule);
		P_GET_UBOOL(Z_Param_PMC_Manual_Attachment);
		P_GET_STRUCT(FTransform,Z_Param_PMC_Relative_Transform);
		P_GET_UBOOL_REF(Z_Param_Out_Is_PMC_Created);
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_Out_PMC_Name);
		P_GET_OBJECT_REF(UProceduralMeshComponent,Z_Param_Out_Out_PMC);
		P_FINISH;
		P_NATIVE_BEGIN;
		UMeshOperationsBPLibrary::AddProcMeshCompWithName(Z_Param_In_PMC_Name,Z_Param_PMC_Outer,EComponentMobility::Type(Z_Param_PMC_Mobility),EAttachmentRule(Z_Param_PMC_Attachment_Rule),Z_Param_PMC_Manual_Attachment,Z_Param_PMC_Relative_Transform,Z_Param_Out_Is_PMC_Created,Z_Param_Out_Out_PMC_Name,Z_Param_Out_Out_PMC);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshOperationsBPLibrary::execAddSceneCompWithName)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_In_SC_Name);
		P_GET_OBJECT(AActor,Z_Param_SC_Outer);
		P_GET_PROPERTY(FByteProperty,Z_Param_SC_Mobility);
		P_GET_ENUM(EAttachmentRule,Z_Param_SC_Attachment_Rule);
		P_GET_UBOOL(Z_Param_SC_Manual_Attachment);
		P_GET_STRUCT(FTransform,Z_Param_SC_Relative_Transform);
		P_GET_UBOOL_REF(Z_Param_Out_Is_SC_Created);
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_Out_SC_Name);
		P_GET_OBJECT_REF(USceneComponent,Z_Param_Out_Out_SC);
		P_FINISH;
		P_NATIVE_BEGIN;
		UMeshOperationsBPLibrary::AddSceneCompWithName(Z_Param_In_SC_Name,Z_Param_SC_Outer,EComponentMobility::Type(Z_Param_SC_Mobility),EAttachmentRule(Z_Param_SC_Attachment_Rule),Z_Param_SC_Manual_Attachment,Z_Param_SC_Relative_Transform,Z_Param_Out_Is_SC_Created,Z_Param_Out_Out_SC_Name,Z_Param_Out_Out_SC);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMeshOperationsBPLibrary::execAddStaticMeshCompWithName)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_In_SMC_Name);
		P_GET_OBJECT(AActor,Z_Param_SMC_Outer);
		P_GET_PROPERTY(FByteProperty,Z_Param_SMC_Mobility);
		P_GET_ENUM(EAttachmentRule,Z_Param_SMC_Attachment_Rule);
		P_GET_UBOOL(Z_Param_SMC_Manual_Attachment);
		P_GET_STRUCT(FTransform,Z_Param_SMC_Relative_Transform);
		P_GET_UBOOL_REF(Z_Param_Out_Is_SMC_Created);
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_Out_SMC_Name);
		P_GET_OBJECT_REF(UStaticMeshComponent,Z_Param_Out_Out_SMC);
		P_FINISH;
		P_NATIVE_BEGIN;
		UMeshOperationsBPLibrary::AddStaticMeshCompWithName(Z_Param_In_SMC_Name,Z_Param_SMC_Outer,EComponentMobility::Type(Z_Param_SMC_Mobility),EAttachmentRule(Z_Param_SMC_Attachment_Rule),Z_Param_SMC_Manual_Attachment,Z_Param_SMC_Relative_Transform,Z_Param_Out_Is_SMC_Created,Z_Param_Out_Out_SMC_Name,Z_Param_Out_Out_SMC);
		P_NATIVE_END;
	}
	void UMeshOperationsBPLibrary::StaticRegisterNativesUMeshOperationsBPLibrary()
	{
		UClass* Class = UMeshOperationsBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddProcMeshCompWithName", &UMeshOperationsBPLibrary::execAddProcMeshCompWithName },
			{ "AddSceneCompWithName", &UMeshOperationsBPLibrary::execAddSceneCompWithName },
			{ "AddStaticMeshCompWithName", &UMeshOperationsBPLibrary::execAddStaticMeshCompWithName },
			{ "GetFullName", &UMeshOperationsBPLibrary::execGetFullName },
			{ "GetVertexLocations", &UMeshOperationsBPLibrary::execGetVertexLocations },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics
	{
		struct MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms
		{
			FName In_PMC_Name;
			AActor* PMC_Outer;
			TEnumAsByte<EComponentMobility::Type> PMC_Mobility;
			EAttachmentRule PMC_Attachment_Rule;
			bool PMC_Manual_Attachment;
			FTransform PMC_Relative_Transform;
			bool Is_PMC_Created;
			FName Out_PMC_Name;
			UProceduralMeshComponent* Out_PMC;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_In_PMC_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_In_PMC_Name;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PMC_Outer;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_PMC_Mobility;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_PMC_Attachment_Rule_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_PMC_Attachment_Rule;
		static void NewProp_PMC_Manual_Attachment_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_PMC_Manual_Attachment;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PMC_Relative_Transform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PMC_Relative_Transform;
		static void NewProp_Is_PMC_Created_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Is_PMC_Created;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Out_PMC_Name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Out_PMC_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Out_PMC;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_In_PMC_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_In_PMC_Name = { "In_PMC_Name", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms, In_PMC_Name), METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_In_PMC_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_In_PMC_Name_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Outer = { "PMC_Outer", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms, PMC_Outer), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Mobility = { "PMC_Mobility", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms, PMC_Mobility), Z_Construct_UEnum_Engine_EComponentMobility, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Attachment_Rule_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Attachment_Rule = { "PMC_Attachment_Rule", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms, PMC_Attachment_Rule), Z_Construct_UEnum_Engine_EAttachmentRule, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Manual_Attachment_SetBit(void* Obj)
	{
		((MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms*)Obj)->PMC_Manual_Attachment = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Manual_Attachment = { "PMC_Manual_Attachment", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms), &Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Manual_Attachment_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Relative_Transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Relative_Transform = { "PMC_Relative_Transform", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms, PMC_Relative_Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Relative_Transform_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Relative_Transform_MetaData)) };
	void Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_Is_PMC_Created_SetBit(void* Obj)
	{
		((MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms*)Obj)->Is_PMC_Created = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_Is_PMC_Created = { "Is_PMC_Created", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms), &Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_Is_PMC_Created_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_Out_PMC_Name = { "Out_PMC_Name", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms, Out_PMC_Name), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_Out_PMC_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_Out_PMC = { "Out_PMC", nullptr, (EPropertyFlags)0x0010000000080180, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms, Out_PMC), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_Out_PMC_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_Out_PMC_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_In_PMC_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Outer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Mobility,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Attachment_Rule_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Attachment_Rule,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Manual_Attachment,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_PMC_Relative_Transform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_Is_PMC_Created,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_Out_PMC_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::NewProp_Out_PMC,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshOperations" },
		{ "DispayName", "AddProcMeshCompWithName" },
		{ "Keywords", "procedural,mesh,component,name" },
		{ "ModuleRelativePath", "Public/MeshOperationsBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshOperationsBPLibrary, nullptr, "AddProcMeshCompWithName", nullptr, nullptr, sizeof(MeshOperationsBPLibrary_eventAddProcMeshCompWithName_Parms), Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics
	{
		struct MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms
		{
			FName In_SC_Name;
			AActor* SC_Outer;
			TEnumAsByte<EComponentMobility::Type> SC_Mobility;
			EAttachmentRule SC_Attachment_Rule;
			bool SC_Manual_Attachment;
			FTransform SC_Relative_Transform;
			bool Is_SC_Created;
			FName Out_SC_Name;
			USceneComponent* Out_SC;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_In_SC_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_In_SC_Name;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SC_Outer;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SC_Mobility;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SC_Attachment_Rule_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_SC_Attachment_Rule;
		static void NewProp_SC_Manual_Attachment_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SC_Manual_Attachment;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SC_Relative_Transform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SC_Relative_Transform;
		static void NewProp_Is_SC_Created_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Is_SC_Created;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Out_SC_Name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Out_SC_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Out_SC;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_In_SC_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_In_SC_Name = { "In_SC_Name", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms, In_SC_Name), METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_In_SC_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_In_SC_Name_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Outer = { "SC_Outer", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms, SC_Outer), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Mobility = { "SC_Mobility", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms, SC_Mobility), Z_Construct_UEnum_Engine_EComponentMobility, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Attachment_Rule_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Attachment_Rule = { "SC_Attachment_Rule", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms, SC_Attachment_Rule), Z_Construct_UEnum_Engine_EAttachmentRule, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Manual_Attachment_SetBit(void* Obj)
	{
		((MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms*)Obj)->SC_Manual_Attachment = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Manual_Attachment = { "SC_Manual_Attachment", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms), &Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Manual_Attachment_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Relative_Transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Relative_Transform = { "SC_Relative_Transform", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms, SC_Relative_Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Relative_Transform_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Relative_Transform_MetaData)) };
	void Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_Is_SC_Created_SetBit(void* Obj)
	{
		((MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms*)Obj)->Is_SC_Created = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_Is_SC_Created = { "Is_SC_Created", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms), &Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_Is_SC_Created_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_Out_SC_Name = { "Out_SC_Name", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms, Out_SC_Name), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_Out_SC_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_Out_SC = { "Out_SC", nullptr, (EPropertyFlags)0x0010000000080180, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms, Out_SC), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_Out_SC_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_Out_SC_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_In_SC_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Outer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Mobility,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Attachment_Rule_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Attachment_Rule,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Manual_Attachment,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_SC_Relative_Transform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_Is_SC_Created,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_Out_SC_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::NewProp_Out_SC,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshOperations" },
		{ "Comment", "//Trigger Scene Component Creation With Name\n" },
		{ "DispayName", "AddSceneCompWithName" },
		{ "Keywords", "scene,component,mesh,name" },
		{ "ModuleRelativePath", "Public/MeshOperationsBPLibrary.h" },
		{ "ToolTip", "Trigger Scene Component Creation With Name" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshOperationsBPLibrary, nullptr, "AddSceneCompWithName", nullptr, nullptr, sizeof(MeshOperationsBPLibrary_eventAddSceneCompWithName_Parms), Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics
	{
		struct MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms
		{
			FName In_SMC_Name;
			AActor* SMC_Outer;
			TEnumAsByte<EComponentMobility::Type> SMC_Mobility;
			EAttachmentRule SMC_Attachment_Rule;
			bool SMC_Manual_Attachment;
			FTransform SMC_Relative_Transform;
			bool Is_SMC_Created;
			FName Out_SMC_Name;
			UStaticMeshComponent* Out_SMC;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_In_SMC_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_In_SMC_Name;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SMC_Outer;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SMC_Mobility;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SMC_Attachment_Rule_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_SMC_Attachment_Rule;
		static void NewProp_SMC_Manual_Attachment_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SMC_Manual_Attachment;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SMC_Relative_Transform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SMC_Relative_Transform;
		static void NewProp_Is_SMC_Created_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Is_SMC_Created;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Out_SMC_Name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Out_SMC_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Out_SMC;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_In_SMC_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_In_SMC_Name = { "In_SMC_Name", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms, In_SMC_Name), METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_In_SMC_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_In_SMC_Name_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Outer = { "SMC_Outer", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms, SMC_Outer), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Mobility = { "SMC_Mobility", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms, SMC_Mobility), Z_Construct_UEnum_Engine_EComponentMobility, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Attachment_Rule_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Attachment_Rule = { "SMC_Attachment_Rule", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms, SMC_Attachment_Rule), Z_Construct_UEnum_Engine_EAttachmentRule, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Manual_Attachment_SetBit(void* Obj)
	{
		((MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms*)Obj)->SMC_Manual_Attachment = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Manual_Attachment = { "SMC_Manual_Attachment", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms), &Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Manual_Attachment_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Relative_Transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Relative_Transform = { "SMC_Relative_Transform", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms, SMC_Relative_Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Relative_Transform_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Relative_Transform_MetaData)) };
	void Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_Is_SMC_Created_SetBit(void* Obj)
	{
		((MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms*)Obj)->Is_SMC_Created = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_Is_SMC_Created = { "Is_SMC_Created", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms), &Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_Is_SMC_Created_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_Out_SMC_Name = { "Out_SMC_Name", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms, Out_SMC_Name), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_Out_SMC_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_Out_SMC = { "Out_SMC", nullptr, (EPropertyFlags)0x0010000000080180, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms, Out_SMC), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_Out_SMC_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_Out_SMC_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_In_SMC_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Outer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Mobility,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Attachment_Rule_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Attachment_Rule,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Manual_Attachment,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_SMC_Relative_Transform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_Is_SMC_Created,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_Out_SMC_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::NewProp_Out_SMC,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshOperations" },
		{ "Comment", "//Trigger Static Mesh Component Creation With Name\n" },
		{ "DispayName", "AddStaticMeshCompWithName" },
		{ "Keywords", "static,mesh,component,name" },
		{ "ModuleRelativePath", "Public/MeshOperationsBPLibrary.h" },
		{ "ToolTip", "Trigger Static Mesh Component Creation With Name" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshOperationsBPLibrary, nullptr, "AddStaticMeshCompWithName", nullptr, nullptr, sizeof(MeshOperationsBPLibrary_eventAddStaticMeshCompWithName_Parms), Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics
	{
		struct MeshOperationsBPLibrary_eventGetFullName_Parms
		{
			const UObject* Object;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Object_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::NewProp_Object_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventGetFullName_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::NewProp_Object_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::NewProp_Object_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventGetFullName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::NewProp_Object,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Add Component" },
		{ "DispayName", "GetFullName" },
		{ "Keywords", "original,name" },
		{ "ModuleRelativePath", "Public/MeshOperationsBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshOperationsBPLibrary, nullptr, "GetFullName", nullptr, nullptr, sizeof(MeshOperationsBPLibrary_eventGetFullName_Parms), Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics
	{
		struct MeshOperationsBPLibrary_eventGetVertexLocations_Parms
		{
			UStaticMesh* TargetStaticMesh;
			int32 LODs;
			TArray<FVector> Vertices;
			TArray<int32> Triangles;
			TArray<FVector> Normals;
			TArray<FVector2D> UVs;
			TArray<FProcMeshTangent> Tangents;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TargetStaticMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LODs_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_LODs;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Triangles_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Triangles;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UVs_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_UVs;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Tangents_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Tangents;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_TargetStaticMesh = { "TargetStaticMesh", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventGetVertexLocations_Parms, TargetStaticMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_LODs_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_LODs = { "LODs", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventGetVertexLocations_Parms, LODs), METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_LODs_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_LODs_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventGetVertexLocations_Parms, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Triangles_Inner = { "Triangles", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Triangles = { "Triangles", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventGetVertexLocations_Parms, Triangles), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventGetVertexLocations_Parms, Normals), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_UVs_Inner = { "UVs", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_UVs = { "UVs", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventGetVertexLocations_Parms, UVs), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Tangents_Inner = { "Tangents", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FProcMeshTangent, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Tangents = { "Tangents", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MeshOperationsBPLibrary_eventGetVertexLocations_Parms, Tangents), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_TargetStaticMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_LODs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Vertices_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Vertices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Triangles_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Triangles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Normals_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Normals,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_UVs_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_UVs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Tangents_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::NewProp_Tangents,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::Function_MetaDataParams[] = {
		{ "Category", "MeshOperations" },
		{ "DispayName", "GetVertexLocations" },
		{ "Keywords", "vertex,locations" },
		{ "ModuleRelativePath", "Public/MeshOperationsBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshOperationsBPLibrary, nullptr, "GetVertexLocations", nullptr, nullptr, sizeof(MeshOperationsBPLibrary_eventGetVertexLocations_Parms), Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMeshOperationsBPLibrary_NoRegister()
	{
		return UMeshOperationsBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UMeshOperationsBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMeshOperationsBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_MeshOperations,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMeshOperationsBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMeshOperationsBPLibrary_AddProcMeshCompWithName, "AddProcMeshCompWithName" }, // 4275776735
		{ &Z_Construct_UFunction_UMeshOperationsBPLibrary_AddSceneCompWithName, "AddSceneCompWithName" }, // 1018163744
		{ &Z_Construct_UFunction_UMeshOperationsBPLibrary_AddStaticMeshCompWithName, "AddStaticMeshCompWithName" }, // 4162058932
		{ &Z_Construct_UFunction_UMeshOperationsBPLibrary_GetFullName, "GetFullName" }, // 1253039021
		{ &Z_Construct_UFunction_UMeshOperationsBPLibrary_GetVertexLocations, "GetVertexLocations" }, // 693849607
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshOperationsBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/* \n*\x09""Function library class.\n*\x09""Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*\x09When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*\x09""BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*\x09""BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*\x09""DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*\x09\x09\x09\x09Its lets you name the node using characters not allowed in C++ function names.\n*\x09""CompactNodeTitle - the word(s) that appear on the node.\n*\x09Keywords -\x09the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. \n*\x09\x09\x09\x09Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*\x09""Category -\x09the category your node will be under in the Blueprint drop-down menu.\n*\n*\x09""For more info on custom blueprint nodes visit documentation:\n*\x09https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation\n*/" },
		{ "IncludePath", "MeshOperationsBPLibrary.h" },
		{ "ModuleRelativePath", "Public/MeshOperationsBPLibrary.h" },
		{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMeshOperationsBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMeshOperationsBPLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMeshOperationsBPLibrary_Statics::ClassParams = {
		&UMeshOperationsBPLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMeshOperationsBPLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMeshOperationsBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMeshOperationsBPLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMeshOperationsBPLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMeshOperationsBPLibrary, 1301476773);
	template<> MESHOPERATIONS_API UClass* StaticClass<UMeshOperationsBPLibrary>()
	{
		return UMeshOperationsBPLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMeshOperationsBPLibrary(Z_Construct_UClass_UMeshOperationsBPLibrary, &UMeshOperationsBPLibrary::StaticClass, TEXT("/Script/MeshOperations"), TEXT("UMeshOperationsBPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMeshOperationsBPLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
