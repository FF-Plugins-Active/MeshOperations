// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

#define USE_DELAYED_LOAD 0

class FMeshOperationsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

#if defined (_WIN64) && USE_DELAYED_LOAD
	
	TMap<FString, void*> OCCT_Handles;

#endif
};
