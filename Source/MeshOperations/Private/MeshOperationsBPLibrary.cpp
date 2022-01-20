// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshOperationsBPLibrary.h"
#include "KismetProceduralMeshLibrary.h"
#include "UObject/Object.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/UObjectBaseUtility.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/ActorComponent.h"
#include "ProceduralMeshComponent.h"
#include "MeshOperations.h"

UMeshOperationsBPLibrary::UMeshOperationsBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UMeshOperationsBPLibrary::AddStaticMeshCompWithName(const FName In_SMC_Name, AActor* SMC_Outer, EComponentMobility::Type SMC_Mobility, EAttachmentRule SMC_Attachment_Rule, bool SMC_Manual_Attachment, const FTransform SMC_Relative_Transform, bool& Is_SMC_Created, FName& Out_SMC_Name, UStaticMeshComponent*& Out_SMC)
{
    if (SMC_Outer != NULL)
    {
        //Static Mesh Component Creation.
        UStaticMeshComponent* StaticMeshComp = NewObject<UStaticMeshComponent>(SMC_Outer, In_SMC_Name);

        //Set Mobility of Static Mesh Component.
        StaticMeshComp->SetMobility(SMC_Mobility);

        //Render Static Mesh Component.
        StaticMeshComp->RegisterComponent();

        //Get Root Component.
        USceneComponent* ActorRootForSMC = SMC_Outer->GetRootComponent();

        //Create Attachment Rules.
        StaticMeshComp->AttachToComponent(ActorRootForSMC, FAttachmentTransformRules(SMC_Attachment_Rule, true));

        if (SMC_Manual_Attachment == true)

        {
            //Set Realtive Transform.
            StaticMeshComp->SetRelativeTransform(SMC_Relative_Transform);
        }

        //Output Pins.
        Out_SMC_Name = In_SMC_Name;
        Out_SMC = StaticMeshComp;
        Is_SMC_Created = true;
    }

    else
    {
        //If outer is not valid, we can not create a static mesh component and program will crash. So we just return false.
        Is_SMC_Created = false;
    }
}

void UMeshOperationsBPLibrary::AddSceneCompWithName(const FName In_SC_Name, AActor* SC_Outer, EComponentMobility::Type SC_Mobility, EAttachmentRule SC_Attachment_Rule, bool SC_Manual_Attachment, const FTransform SC_Relative_Transform, bool& Is_SC_Created, FName& Out_SC_Name, USceneComponent*& Out_SC)
{
    if (SC_Outer != NULL)
    {
        //Scene Component Creation.
        USceneComponent* SceneComp = NewObject<USceneComponent>(SC_Outer, In_SC_Name);

        //Set Mobility of Scene Component.
        SceneComp->SetMobility(SC_Mobility);

        //Get Root Component.
        USceneComponent* ActorRootForSC = SC_Outer->GetRootComponent();

        //Create Attachment Rules.
        SceneComp->AttachToComponent(ActorRootForSC, FAttachmentTransformRules(SC_Attachment_Rule, true));

        if (SC_Manual_Attachment == true)
        {
            //Set Realtive Transform.
            SceneComp->SetRelativeTransform(SC_Relative_Transform);
        }

        //Output Pins.
        Out_SC_Name = In_SC_Name;
        Out_SC = SceneComp;
        Is_SC_Created = true;
    }

    else
    {
        //If outer is not valid, we can not create a "scene component" and program will crash. So we just return false.       
        Is_SC_Created = false;
    }
}

void UMeshOperationsBPLibrary::AddProcMeshCompWithName(const FName In_PMC_Name, AActor* PMC_Outer, EComponentMobility::Type PMC_Mobility, EAttachmentRule PMC_Attachment_Rule, bool PMC_Manual_Attachment, const FTransform PMC_Relative_Transform, bool& Is_PMC_Created, FName& Out_PMC_Name, UProceduralMeshComponent*& Out_PMC)
{
    if (PMC_Outer != NULL)
    {
        //Procedural Mesh Component Creation.
        UProceduralMeshComponent* ProcMeshComp = NewObject<UProceduralMeshComponent>(PMC_Outer, In_PMC_Name);

        //Set Mobility of Procedural Mesh Component.
        ProcMeshComp->SetMobility(PMC_Mobility);

        //Render Procedural Mesh Component.
        ProcMeshComp->RegisterComponent();

        //Get Root Component of Outer.
        USceneComponent* ActorRootForPMC = PMC_Outer->GetRootComponent();

        //Create Attachment Rules.
        ProcMeshComp->AttachToComponent(ActorRootForPMC, FAttachmentTransformRules(PMC_Attachment_Rule, true));

        if (PMC_Manual_Attachment == true)
        {
            //Set Realtive Transform.
            ProcMeshComp->SetRelativeTransform(PMC_Relative_Transform);
        }

        //Output Pins
        Out_PMC_Name = In_PMC_Name;
        Out_PMC = ProcMeshComp;
        Is_PMC_Created = true;
    }

    else
    {
        //If outer is not valid, we can not create a procedural mesh component and program will crash. So we just return false.
        Is_PMC_Created = false;
    }
}

FString UMeshOperationsBPLibrary::GetFullName(const UObject* Object)
{
    UObject* StopOuter = Object->GetOuter();
    EObjectFullNameFlags Flags = EObjectFullNameFlags::None;
    return Object->GetFullName(StopOuter, Flags);
}

void UMeshOperationsBPLibrary::GetVertexLocations(UStaticMesh* TargetStaticMesh, const int32 LODs, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UVs, TArray<FProcMeshTangent>& Tangents)
{
    int32 MeshSectionCount = TargetStaticMesh->GetNumSections(0);

    for (int32 i = 0; i < (MeshSectionCount--); i++)
    {
        UKismetProceduralMeshLibrary::GetSectionFromStaticMesh(TargetStaticMesh, LODs, i, Vertices, Triangles, Normals, UVs, Tangents);
    }
}