// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshOperationsBPLibrary.h"

// Math Functions.
#include "Math/Vector.h"
#include "Kismet/KismetMathLibrary.h"

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

// Get Vertices Locations 1.
#include "Rendering/PositionVertexBuffer.h"
#include "Runtime/RenderCore/Public/ShaderCore.h"

// Vertex and Pivot Functions.
#include "EditableMesh.h"
#include "EditableMeshFactory.h"
#include "MeshDescription.h"
#include "StaticMeshAttributes.h" // Set Vertex Location

#include "MeshOperations.h"

UMeshOperationsBPLibrary::UMeshOperationsBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UMeshOperationsBPLibrary::AddStaticMeshCompWithName(const FString In_SMC_Name, AActor* SMC_Outer, EComponentMobility::Type SMC_Mobility, EAttachmentRule SMC_Attachment_Rule, bool SMC_Manual_Attachment, const FTransform SMC_Relative_Transform, bool& Is_SMC_Created, FName& Out_SMC_Name, UStaticMeshComponent*& Out_SMC)
{
    if (SMC_Outer != NULL)
    {
        FName SMC_Name;
        if (In_SMC_Name.IsEmpty() == true)
        {
            SMC_Name = NAME_None;
        }

        else
        {
            SMC_Name = *In_SMC_Name;
        }
        
        //Static Mesh Component Creation.
        UStaticMeshComponent* StaticMeshComp = NewObject<UStaticMeshComponent>(SMC_Outer, SMC_Name);

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
            Out_SMC_Name = SMC_Name;
            Is_SMC_Created = StaticMeshComp->IsValidLowLevel();
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

void UMeshOperationsBPLibrary::AddSceneCompWithName(const FString In_SC_Name, AActor* SC_Outer, EComponentMobility::Type SC_Mobility, EAttachmentRule SC_Attachment_Rule, bool SC_Manual_Attachment, const FTransform SC_Relative_Transform, bool& Is_SC_Created, FName& Out_SC_Name, USceneComponent*& Out_SC)
{
    if (SC_Outer != NULL)
    {
        FName SC_Name;
        if (In_SC_Name.IsEmpty() == true)
        {
           SC_Name = NAME_None;
        }

        else
        {
            SC_Name = *In_SC_Name;
        }

        //Scene Component Creation.
        USceneComponent* SceneComp = NewObject<USceneComponent>(SC_Outer, SC_Name);

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
            Out_SC_Name = SC_Name;
            Is_SC_Created = SceneComp->IsValidLowLevel();
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

void UMeshOperationsBPLibrary::AddProcMeshCompWithName(const FString In_PMC_Name, AActor* PMC_Outer, EComponentMobility::Type PMC_Mobility, EAttachmentRule PMC_Attachment_Rule, bool PMC_Manual_Attachment, const FTransform PMC_Relative_Transform, bool& Is_PMC_Created, FName& Out_PMC_Name, UProceduralMeshComponent*& Out_PMC)
{
    if (PMC_Outer != NULL)
    {
        FName PMC_Name; 
        if (In_PMC_Name.IsEmpty() == true)
        {
            PMC_Name = NAME_None;
        }

        else
        {
            PMC_Name = *In_PMC_Name;
        }
        
        //Procedural Mesh Component Creation.
        UProceduralMeshComponent* ProcMeshComp = NewObject<UProceduralMeshComponent>(PMC_Outer, PMC_Name);

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
            Out_PMC_Name = PMC_Name;
            Is_PMC_Created = ProcMeshComp->IsValidLowLevel();
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

void UMeshOperationsBPLibrary::GetVerticesLocations_1(UStaticMeshComponent* Target_SMC, int32 LODs, TArray<FVector>& AllVertices, TArray<FVector>& UniqueVertices)
{    
    if (Target_SMC != nullptr)
    {   
        // Get PositionVertexBuffer at start.
        FPositionVertexBuffer* PositionVertexBuffer = &Target_SMC->GetStaticMesh()->GetRenderData()->LODResources[LODs].VertexBuffers.PositionVertexBuffer;

        // Get vertex positions from PositionVertexBuffer and convert it to world space from mesh space.
        FVector EachVertex;

        for (uint32 VertexIndex = 0; VertexIndex < PositionVertexBuffer->GetNumVertices(); VertexIndex++)
        {
            EachVertex = Target_SMC->GetComponentTransform().TransformPosition(PositionVertexBuffer->VertexPosition(VertexIndex));
            AllVertices.Add(EachVertex);

            if (UniqueVertices.Contains(EachVertex) == false)
            {
                UniqueVertices.Add(EachVertex);
            }
        }
    }
}

void UMeshOperationsBPLibrary::GetVerticesLocations_2(UStaticMeshComponent* Target_SMC, int32 LODs, TArray<FVector>& VerticesLocations)
{
    if (Target_SMC != nullptr)
    {
        UEditableMesh* TargetEditableMesh = UEditableMeshFactory::MakeEditableMesh(Target_SMC, LODs);
        const TVertexAttributesRef<FVector> Vertices = TargetEditableMesh->GetMeshDescription()->VertexAttributes().GetAttributesRef<FVector>(MeshAttribute::Vertex::Position);
        for (int32 VertexIndex = 0; VertexIndex < Vertices.GetNumElements(); VertexIndex++)
        {
            FVertexID EachVertexID = FVertexID(VertexIndex);
            FVector EachVertex = Target_SMC->GetComponentTransform().TransformPosition(Vertices.Get(EachVertexID));
            VerticesLocations.Add(EachVertex);
        }
    }
}

void UMeshOperationsBPLibrary::SetVertexLocation(UEditableMesh* TargetEditableMesh, FVertexToMove TargetVertexToMove)
{
    // Initial Variables.
    TSet<FPolygonID> PolygonsPendingNewTangentBasis;
    TSet<FPolygonID> PolygonsPendingTriangulation;

    static TSet<FPolygonID> VertexConnectedPolygons;
    VertexConnectedPolygons.Reset();

    static TArray<FAttributesForVertex> VertexAttributesToSet;
    VertexAttributesToSet.Reset();

    const TVertexAttributesRef<FVector> VertexPositions = TargetEditableMesh->GetMeshDescription()->VertexAttributes().GetAttributesRef<FVector>(MeshAttribute::Vertex::Position);

    const FVector CurrentPosition = VertexPositions[TargetVertexToMove.VertexID];

    if (TargetVertexToMove.NewVertexPosition != CurrentPosition)
    {
        VertexAttributesToSet.Emplace();
        FAttributesForVertex& AttributesForVertex = VertexAttributesToSet.Last();


        AttributesForVertex.VertexID = TargetVertexToMove.VertexID;
        AttributesForVertex.VertexAttributes.Attributes.Emplace(MeshAttribute::Vertex::Position, 0, FMeshElementAttributeValue(TargetVertexToMove.NewVertexPosition));

        // All of the polygons that share this vertex will need new normals
        static TArray<FPolygonID> ConnectedPolygonRefs;
        TargetEditableMesh->GetVertexConnectedPolygons(TargetVertexToMove.VertexID, /* Out */ ConnectedPolygonRefs);
        VertexConnectedPolygons.Append(ConnectedPolygonRefs);
    }

    TargetEditableMesh->SetVerticesAttributes(VertexAttributesToSet);

    // Mark all polygons connected to the vertex as requiring a new tangent basis and retriangulation
    // Everything needs to be retriangulated because convexity may have changed
    PolygonsPendingNewTangentBasis.Append(VertexConnectedPolygons);
    PolygonsPendingTriangulation.Append(VertexConnectedPolygons);
}

void UMeshOperationsBPLibrary::MovePivotToNewLocation(UStaticMeshComponent* Target_SMC, int32 LODs, TEnumAsByte<PivotDestination> Pivot, FVector CustomPivot, bool& IsSuccessful)
{
    if (ENGINE_MAJOR_VERSION == 4)
    {
        if (Target_SMC != nullptr)
        {
            // Get original transform values to retain them.
            FVector OriginalCenter = Target_SMC->Bounds.Origin;
            FRotator OriginalRotation = Target_SMC->GetComponentRotation();

            // Reset rotation to get pure (non-rotated) world locations of vertices.
            FRotator ZeroRotation(0.0f, 0.0f, 0.0f);
            Target_SMC->SetWorldRotation(ZeroRotation, false, nullptr, ETeleportType::None);


            // Get vertices of target static mesh at start.
            TArray<FVector> VerticesLocations;
            UMeshOperationsBPLibrary::GetVerticesLocations_2(Target_SMC, LODs, VerticesLocations);
            
            FVector NewPivot;
            switch (Pivot)
            {
            case None:
                NewPivot = FVector(0, 0, 0);
                break;

            case Center:
                NewPivot = Target_SMC->Bounds.Origin;
                break;

            case Custom:
                NewPivot = CustomPivot;
                break;

            default:
                NewPivot = Target_SMC->Bounds.Origin;
                break;
            }

            // Start Pivot Operation
            UEditableMesh* TargetEditableMesh = UEditableMeshFactory::MakeEditableMesh(Target_SMC, LODs);

            for (int32 VertexIndex = 0; VertexIndex < VerticesLocations.Num(); VertexIndex++)
            {
                FVertexToMove EachVTM;
                EachVTM.VertexID = FVertexID(VertexIndex);
                EachVTM.NewVertexPosition = VerticesLocations[VertexIndex] - NewPivot;
                UMeshOperationsBPLibrary::SetVertexLocation(TargetEditableMesh, EachVTM);
            }

            TargetEditableMesh->Commit();
            TargetEditableMesh->RebuildRenderMesh();

            // Return object to its original transform.
            Target_SMC->AddWorldOffset(OriginalCenter - Target_SMC->Bounds.Origin, false, nullptr, ETeleportType::None);
            Target_SMC->SetWorldRotation(OriginalRotation, false, nullptr, ETeleportType::None);

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

void UMeshOperationsBPLibrary::CreatePMFromSM(UStaticMeshComponent* Target_SMC, UProceduralMeshComponent* Target_PMC, UMaterial* Material, int32 LODs, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UVs, TArray<FProcMeshTangent>& Tangents)
{
    TArray<FColor> VertexColor;
    TSet<FVector> UniqueVertices;
    for (int32 SectionIndex = 0; SectionIndex < Target_SMC->GetStaticMesh()->GetNumSections(LODs); SectionIndex++)
    {
        UKismetProceduralMeshLibrary::GetSectionFromStaticMesh(Target_SMC->GetStaticMesh(), LODs, SectionIndex, Vertices, Triangles, Normals, UVs, Tangents);
        Target_PMC->CreateMeshSection(SectionIndex, Vertices, Triangles, Normals, UVs, VertexColor, Tangents, false);
    }

    for (int32 MaterialIndex = 0; MaterialIndex < Target_SMC->GetNumMaterials(); MaterialIndex++)
    {
        Target_PMC->SetMaterial(MaterialIndex, Material);
    }
}