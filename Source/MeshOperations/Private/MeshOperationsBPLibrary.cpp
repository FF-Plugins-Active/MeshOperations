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

UMeshOperationsBPLibrary::UMeshOperationsBPLibrary(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
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

FString UMeshOperationsBPLibrary::GetClassName(const UObject* Object)
{
    UClass* Class = Object->GetClass();
    return Class->GetName();
}

void UMeshOperationsBPLibrary::GetVertexValues(UStaticMeshComponent* StaticMeshComponent, const int32 LODs, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UVs, TArray<FProcMeshTangent>& Tangents, TArray<FVector>& ShiftedVertices, FVector& VerticesCenter)
{
    
    // Initial variable for vertices sum.
    FVector Sum(0.f);

    // Get Static Mesh
    UStaticMesh* TargetStaticMesh = StaticMeshComponent->GetStaticMesh();

    // Get Mesh Section Count.
    int32 MeshSectionCount = TargetStaticMesh->GetNumSections(0);

    // Get recursive vertex values for all static mesh sections.
    for (int32 i = 0; i < (MeshSectionCount--); i++)
        {
            UKismetProceduralMeshLibrary::GetSectionFromStaticMesh(TargetStaticMesh, LODs, i, Vertices, Triangles, Normals, UVs, Tangents);
        }
    
    // Get Vertices Center (Relative Location).
    for (int32 VectorID = 0; VectorID < Vertices.Num(); VectorID++)
        {
            Sum += Vertices[VectorID];
        }
    VerticesCenter = Sum / ((float)Vertices.Num());
   
    // Shift vertices with vertices center
    for (int32 VectorID = 0; VectorID < Vertices.Num(); VectorID++)
        {
            ShiftedVertices.Add(Vertices[VectorID] - VerticesCenter);
        }
}

void UMeshOperationsBPLibrary::MoveComponentsToCenter(USceneComponent* AssetRoot)
{
    // Array variable for children components.
    TArray<USceneComponent*> Children;

    // Array variable for children locations.
    TArray<FVector> ChildrenLocations;

    // Get children components of asset root.
    AssetRoot->GetChildrenComponents(false, Children);

    // Add relative locations of children components to children locations array.
    for (int32 ChildID = 0; ChildID < Children.Num(); ChildID++)
        {
            ChildrenLocations.Add(Children[ChildID]->GetRelativeLocation());
        }
    
    // Calculate assembly center (Relative Location).
    FVector Sum(0.f);
    for (int32 ChildID = 0; ChildID < (ChildrenLocations.Num()); ChildID++)
        {
            Sum += ChildrenLocations[ChildID];
        }
    FVector AssemblyCenter = Sum / ((float)ChildrenLocations.Num());

    // Subtract assembly center from each child's relative location.
    for (int32 ChildID = 0; ChildID < ChildrenLocations.Num(); ChildID++)
        {
            Children[ChildID]->SetRelativeLocation((ChildrenLocations[ChildID] - AssemblyCenter), false, nullptr, ETeleportType::None);
        }
}

void UMeshOperationsBPLibrary::OptimizeHierarchy(USceneComponent* AssetRoot)
{
    // Initial while variable
    int32 ChildrenCount = AssetRoot->GetNumChildrenComponents();
    
    // Check if asset root has one direct child or not.
    while (ChildrenCount == 1)
    {
        // Array variable for children components.
        TArray<USceneComponent*> Children;

        // Get children components of asset root.
        AssetRoot->GetChildrenComponents(false, Children);

        // Get first and only child as middle parent.
        USceneComponent* MiddleParent = Children[0];

        // Get class name of middle parent.
        FString ClassName = MiddleParent->GetClass()->GetName();

        // If middle parent is a scene component, do operations.
        if (ClassName == TEXT("SceneComponent"))
        {
            // Create array variable for middle children.
            TArray<USceneComponent*> MiddleChildren;
            
            // Get middle children of middle parent.
            MiddleParent->GetChildrenComponents(false, MiddleChildren);
            
            // For Each Loop function for middle children. It attachs each middle child to asset root.
            for (int32 ChildID = 0; ChildID < MiddleChildren.Num(); ChildID++)
            {
                MiddleChildren[ChildID]->AttachToComponent(AssetRoot, FAttachmentTransformRules::KeepWorldTransform);
            }
            
            // Destroy middle parent after child attachment.
            MiddleParent->DestroyComponent(true);

            // Check asset root's children number after process. If it is equal one return to start.
            ChildrenCount = AssetRoot->GetNumChildrenComponents();
        }
    }
}