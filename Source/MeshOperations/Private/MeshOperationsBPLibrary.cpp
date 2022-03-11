// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshOperationsBPLibrary.h"
#include "Math/Vector.h"

// Async Functions.
#include "Async/Async.h" 
#include "Async/IAsyncProgress.h"

// Components.
#include "UObject/Object.h"
#include "Components/SceneComponent.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ProceduralMeshComponent.h"
#include "KismetProceduralMeshLibrary.h"

// Get Vertices Locations.
#include "Rendering/PositionVertexBuffer.h"
#include "Runtime/RenderCore/Public/ShaderCore.h"

// Pivot System.
#include "EditableMesh.h"
#include "EditableMeshTypes.h"
#include "EditableMeshFactory.h"
#include "MeshDescription.h"

#include "MeshOperations.h"

UMeshOperationsBPLibrary::UMeshOperationsBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UMeshOperationsBPLibrary::AddStaticMeshCompWithName(const FName In_SMC_Name, AActor* SMC_Outer, EComponentMobility::Type SMC_Mobility, EAttachmentRule SMC_Attachment_Rule, bool SMC_Manual_Attachment, const FTransform SMC_Relative_Transform, bool& Is_SMC_Created, FName& Out_SMC_Name, UStaticMeshComponent*& Out_SMC)
{
    if (SMC_Outer != NULL)
    {
        //Static Mesh Component Creation.
        UStaticMeshComponent* StaticMeshComp = NewObject<UStaticMeshComponent>(SMC_Outer, In_SMC_Name);

        if (StaticMeshComp != nullptr)
        {
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
            Out_SMC = StaticMeshComp;
            Out_SMC_Name = In_SMC_Name;
            Is_SMC_Created = true;
        }
    }

    else
    {
        //If outer is not valid, we can not create a static mesh component and program will crash. So we just return false.
        Out_SMC = nullptr;
        Out_SMC_Name = TEXT("");
        Is_SMC_Created = false;
    }
}

void UMeshOperationsBPLibrary::AddSceneCompWithName(const FName In_SC_Name, AActor* SC_Outer, EComponentMobility::Type SC_Mobility, EAttachmentRule SC_Attachment_Rule, bool SC_Manual_Attachment, const FTransform SC_Relative_Transform, bool& Is_SC_Created, FName& Out_SC_Name, USceneComponent*& Out_SC)
{
    if (SC_Outer != NULL)
    {
        //Scene Component Creation.
        USceneComponent* SceneComp = NewObject<USceneComponent>(SC_Outer, In_SC_Name);

        if (SceneComp != nullptr)
        {
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
            Out_SC = SceneComp;
            Out_SC_Name = In_SC_Name;
            Is_SC_Created = true;
        }
    }

    else
    {
        //If outer is not valid, we can not create a "scene component" and program will crash. So we just return false.       
        Out_SC = nullptr;
        Out_SC_Name = TEXT("");
        Is_SC_Created = false;
    }
}

void UMeshOperationsBPLibrary::AddProcMeshCompWithName(const FName In_PMC_Name, AActor* PMC_Outer, EComponentMobility::Type PMC_Mobility, EAttachmentRule PMC_Attachment_Rule, bool PMC_Manual_Attachment, const FTransform PMC_Relative_Transform, bool& Is_PMC_Created, FName& Out_PMC_Name, UProceduralMeshComponent*& Out_PMC)
{
    if (PMC_Outer != NULL)
    {
        //Procedural Mesh Component Creation.
        UProceduralMeshComponent* ProcMeshComp = NewObject<UProceduralMeshComponent>(PMC_Outer, In_PMC_Name);

        if (ProcMeshComp != nullptr)
        {
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
            Out_PMC = ProcMeshComp;
            Out_PMC_Name = In_PMC_Name;
            Is_PMC_Created = true;
        }
    }

    else
    {
        //If outer is not valid, we can not create a procedural mesh component and program will crash. So we just return false.
        Out_PMC = nullptr;
        Out_PMC_Name = TEXT("");
        Is_PMC_Created = false;
    }
}

FString UMeshOperationsBPLibrary::GetClassName(const UObject* Object)
{
    UClass* Class = Object->GetClass();
    return Class->GetName();
}

void UMeshOperationsBPLibrary::GetObjectNameForPackage(USceneComponent* Object, FString Delimeter, FString& OutName)
{
    // Initialize variables.
    FString GeneratedName;
    TArray<FString> NameSections;

    FString ObjectName = Object->GetName();
    ObjectName.ParseIntoArray(NameSections, *Delimeter, true);

    if (WITH_EDITOR == true)
    {
        NameSections.RemoveAt(NameSections.Num()-1);
        GeneratedName = FString::Join(NameSections, *Delimeter);
    }

    else
    {
        for (int32 SectionID = 0; SectionID < 1; SectionID++)
        {
            NameSections.RemoveAt(NameSections.Num() - 1 - SectionID);
        }

        GeneratedName = FString::Join(NameSections, *Delimeter);
    }
    
    OutName = GeneratedName;
}

void UMeshOperationsBPLibrary::OptimizeCenter(USceneComponent* AssetRoot)
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

void UMeshOperationsBPLibrary::DeleteEmptyRoots(USceneComponent* AssetRoot)
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

void UMeshOperationsBPLibrary::OptimizeHeight(USceneComponent* AssetRoot, float Z_Offset)
{
    FVector Origin;
    FVector BoxExtent;
    AssetRoot->GetOwner()->GetActorBounds(false, Origin, BoxExtent, true);

    float NewHeight = BoxExtent.Z + Z_Offset;
    FVector NewLocation(0.f, 0.f, NewHeight);

    AssetRoot->AddWorldOffset(NewLocation, false, nullptr, ETeleportType::None);
}

void UMeshOperationsBPLibrary::RecordTransforms(USceneComponent* AssetRoot, TMap<USceneComponent*, FTransform>& MapTransform, TArray<USceneComponent*>& AllComponents, TArray<USceneComponent*>& ChildComponents)
{
    AssetRoot->GetChildrenComponents(true, ChildComponents);
    AllComponents = ChildComponents;
    AllComponents.Add(AssetRoot);

    for (int32 ChildID = 0; ChildID < AllComponents.Num(); ChildID++)
    {
        MapTransform.Add(AllComponents[ChildID], AllComponents[ChildID]->GetRelativeTransform());
    }
}

void UMeshOperationsBPLibrary::GetVertexLocations(UStaticMeshComponent* StaticMeshComponent, int32 LODs, int32& VerticesCount, TArray<FVector>& VerticesLocations)
{
    if (StaticMeshComponent != nullptr)
    {   
        // Get PositionVertexBuffer at start.
        FPositionVertexBuffer* PositionVertexBuffer = &StaticMeshComponent->GetStaticMesh()->GetRenderData()->LODResources[LODs].VertexBuffers.PositionVertexBuffer;

        // Get vertex positions from PositionVertexBuffer and convert it to world space from mesh space.
        FVector VertexPosition;

        for (uint32 VertexIndex = 0; VertexIndex < PositionVertexBuffer->GetNumVertices(); VertexIndex++)
        {
            VertexPosition = StaticMeshComponent->GetComponentTransform().TransformPosition(PositionVertexBuffer->VertexPosition(VertexIndex));

            if (VerticesLocations.Contains(VertexPosition) == false)
            {
                VerticesLocations.Add(VertexPosition);
            }
        }

        // Output Pins
        VerticesCount = VerticesLocations.Num();
    }
}

void UMeshOperationsBPLibrary::MovePivotToNewLocation(UStaticMeshComponent* StaticMeshComponent, int32 LODs, TEnumAsByte<PivotDestination> Pivot, FVector CustomPivot, bool& IsSuccessful)
{
    if (ENGINE_MAJOR_VERSION == 4)
    {
        if (StaticMeshComponent != nullptr)
        {
            // Get original transform values to retain them.
            FVector OriginalCenter = StaticMeshComponent->Bounds.Origin;
            FRotator OriginalRotation = StaticMeshComponent->GetComponentRotation();

            // Reset rotation to get pure (non-rotated) world locations of vertices.
            FRotator ZeroRotation(0.0f, 0.0f, 0.0f);
            StaticMeshComponent->SetWorldRotation(ZeroRotation, false, nullptr, ETeleportType::None);

            // Get vertices of target static mesh at start.
            int32 VerticesCount;
            TArray<FVector> VerticesLocations;
            UMeshOperationsBPLibrary::GetVertexLocations(StaticMeshComponent, LODs, VerticesCount, VerticesLocations);
            
            FVector NewPivot;
            switch (Pivot)
            {
            case None:
                NewPivot;
                break;

            case Center:
                NewPivot = StaticMeshComponent->Bounds.Origin;
                break;

            case Custom:
                NewPivot = CustomPivot;
                break;

            default:
                NewPivot = StaticMeshComponent->Bounds.Origin;
                break;
            }
            
            // Start Pivot Operation
            UEditableMesh* EditableMesh = UEditableMeshFactory::MakeEditableMesh(StaticMeshComponent, LODs);

            FVertexToMove EachVertexToMove;
            TArray<FVertexToMove> Array_VerticesToMove;
            for (int32 VertexIndex = 0; VertexIndex < VerticesLocations.Num(); VertexIndex++)
            {
                EachVertexToMove.VertexID = FVertexID(VertexIndex);
                EachVertexToMove.NewVertexPosition = VerticesLocations[VertexIndex] - NewPivot;
                Array_VerticesToMove.Add(EachVertexToMove);
            }

            EditableMesh->MoveVertices(Array_VerticesToMove);
            EditableMesh->Commit();
            EditableMesh->RebuildRenderMesh();

            // Return object to its original transform.
            StaticMeshComponent->AddWorldOffset(OriginalCenter - StaticMeshComponent->Bounds.Origin, false, nullptr, ETeleportType::None);
            StaticMeshComponent->SetWorldRotation(OriginalRotation, false, nullptr, ETeleportType::None);
            
            IsSuccessful = true;
        }
    }

    else
    {
        IsSuccessful = false;
    }

}

void UMeshOperationsBPLibrary::RecursiveMovePivotToCenter(USceneComponent* RootComponent, int32 LODs, FCenterPivot DelegateMovePivot)
{
    AsyncTask(ENamedThreads::GameThread, [DelegateMovePivot, RootComponent, LODs]()
        {
            FVector CustomPivot(0.f);
            bool IsThisMoveSuccessful = true;
            UStaticMeshComponent* ChildMeshComp = nullptr;
            
            TArray<USceneComponent*> ChildrenMeshComps;
            RootComponent->GetChildrenComponents(true, ChildrenMeshComps);
            
            TArray<FVector> NewVertices;
            for (int32 ChilIndex = 0; ChilIndex < ChildrenMeshComps.Num(); ChilIndex++)
            {
                if (ChildrenMeshComps[ChilIndex]->GetClass()->GetName() == TEXT("StaticMeshComponent"))
                {
                    ChildMeshComp = Cast<UStaticMeshComponent>(ChildrenMeshComps[ChilIndex]);
                    UMeshOperationsBPLibrary::MovePivotToNewLocation(ChildMeshComp, LODs, PivotDestination::Center, CustomPivot, IsThisMoveSuccessful);
                }
            }

            AsyncTask(ENamedThreads::GameThread, [DelegateMovePivot]()
                {
                    DelegateMovePivot.ExecuteIfBound(true);
                }
            );
        }
    );
}

void UMeshOperationsBPLibrary::CreateProcMeshFromSM(UStaticMeshComponent* StaticMeshComponent, int32 LODs, UProceduralMeshComponent* TargetPMC, UMaterial* Material, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UVs, TArray<FProcMeshTangent>& Tangents)
{
    TArray<FColor> VertexColor;
    TSet<FVector> UniqueVertices;
    for (int32 SectionIndex = 0; SectionIndex < StaticMeshComponent->GetStaticMesh()->GetNumSections(LODs); SectionIndex++)
    {
        UKismetProceduralMeshLibrary::GetSectionFromStaticMesh(StaticMeshComponent->GetStaticMesh(), LODs, SectionIndex, Vertices, Triangles, Normals, UVs, Tangents);
        TargetPMC->CreateMeshSection(SectionIndex, Vertices, Triangles, Normals, UVs, VertexColor, Tangents, false);
    }

    for (int32 MaterialIndex = 0; MaterialIndex < StaticMeshComponent->GetNumMaterials(); MaterialIndex++)
    {
        TargetPMC->SetMaterial(MaterialIndex, Material);
    }
}