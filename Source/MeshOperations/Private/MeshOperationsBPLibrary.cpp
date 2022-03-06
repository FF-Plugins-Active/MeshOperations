// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshOperationsBPLibrary.h"
#include "Async/Async.h" 

// Object Types.
#include "UObject/Object.h"
#include "Components/SceneComponent.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ProceduralMeshComponent.h"
#include "KismetProceduralMeshLibrary.h"

// Calculations.
#include "Math/Vector.h"

// Unique Objects.
#include "EditableMesh.h"
#include "EditableMeshTypes.h"
#include "EditableMeshFactory.h"
#include "MeshDescription.h"                    //Pivot System.
#include "MeshDescriptionBase.h"
#include "Engine/StaticMesh.h"

// Buffers.
#include "StaticMeshResources.h"                //Pivot System.
#include "StaticMeshAttributes.h"               //Pivot System.
#include "Rendering/PositionVertexBuffer.h"     //Pivot System.

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
        int32 SectionCount = NameSections.Num();
        int32 DeletedSection = SectionCount - 1;
        NameSections.RemoveAt(DeletedSection);

        GeneratedName = FString::Join(NameSections, *Delimeter);
    }

    else
    {
        for (int32 SectionID = 0; SectionID < 1; SectionID++)
        {
            int32 SectionCount = NameSections.Num();
            int32 DeletedID = SectionCount - 1;
            NameSections.RemoveAt(DeletedID);
        }

        GeneratedName = FString::Join(NameSections, *Delimeter);
    }
    
    OutName = GeneratedName;
}

void UMeshOperationsBPLibrary::GetVertexLocations(UStaticMeshComponent* StaticMeshComponent, int32 LODs, int32& AllVerticesCount, int32& UniqueVerticesCount, TArray<FVector>& OutAllVertices, TArray<FVector>& OutUniqueVertices)
{
    if (StaticMeshComponent != nullptr)
    {
        // Get PositionVertexBuffer at start.
        FPositionVertexBuffer* PositionVertexBuffer = &StaticMeshComponent->GetStaticMesh()->GetRenderData()->LODResources[LODs].VertexBuffers.PositionVertexBuffer;
        AllVerticesCount = PositionVertexBuffer->GetNumVertices();

        // Get vertex positions from PositionVertexBuffer and convert it to world space from mesh space.
        FVector VertexPosition;
        TSet<FVector> UniqueVertices;

        for (int32 VertexIndex = 0; VertexIndex < AllVerticesCount; VertexIndex++)
        {
            VertexPosition = StaticMeshComponent->GetComponentTransform().TransformPosition(PositionVertexBuffer->VertexPosition(VertexIndex));
            OutAllVertices.Add(VertexPosition);
            UniqueVertices.Add(VertexPosition);
        }

        // Output Pins
        OutUniqueVertices = UniqueVertices.Array();
        UniqueVerticesCount = UniqueVertices.Num();
    }
}

void UMeshOperationsBPLibrary::MovePivotToNewLocation(UStaticMeshComponent* StaticMeshComponent, int32 LODs, TEnumAsByte<PivotOperations> Pivot, FVector CustomPivot, TArray<FVector> CurrentVertices, bool &IsSuccessful)
{
    if (ENGINE_MAJOR_VERSION == 4)
    {
        if (StaticMeshComponent != nullptr)
        {
            // Initial Variables.
            UEditableMesh* EditableMesh;
            EditableMesh = UEditableMeshFactory::MakeEditableMesh(StaticMeshComponent, LODs);
            FVector CenterOriginal = StaticMeshComponent->Bounds.Origin;

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

            FVertexToMove EachVertexToMove;
            TArray<FVertexToMove> Array_VerticesToMove;
            for (int32 VertexIndex = 0; VertexIndex < CurrentVertices.Num(); VertexIndex++)
            {
                EachVertexToMove.VertexID = FVertexID(VertexIndex);
                EachVertexToMove.NewVertexPosition = CurrentVertices[VertexIndex] - NewPivot;
                Array_VerticesToMove.Add(EachVertexToMove);
            }

            EditableMesh->MoveVertices(Array_VerticesToMove);
            EditableMesh->Commit();
            EditableMesh->RebuildRenderMesh();

            // Add world offset to retain original world location.
            StaticMeshComponent->AddWorldOffset(CenterOriginal - StaticMeshComponent->Bounds.Origin, false, nullptr, ETeleportType::None);

            if (StaticMeshComponent->GetComponentLocation() == NewPivot)
            {
                IsSuccessful = true;
            }

            else
            {
                IsSuccessful = false;
            }
        }
    }

    else
    {
        IsSuccessful = false;
    }
    
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

void UMeshOperationsBPLibrary::DeleteEmptyParents(USceneComponent* AssetRoot, int32& OutProcessed, TArray<USceneComponent*>& OutChildren)
{
    int32 Processed = 0;

    TArray <USceneComponent*> Children; // Required construction of array variable for children components.
    AssetRoot->GetChildrenComponents(true, Children);

    // MAP Variable.
    TMap<FString, FMeshProperties> MAP_Properties;

    for (int32 ChildID = 0; ChildID < Children.Num(); ChildID++)
    {
        if (Children[ChildID]->GetClass()->GetName() == TEXT("StaticMeshComponent"))
        {
            // Referance of each child component.
            UStaticMeshComponent* LOC_SM_Comp = Cast<UStaticMeshComponent>(Children[ChildID]);

            int32 SiblingsCount = LOC_SM_Comp->GetAttachParent()->GetNumChildrenComponents();

            if (SiblingsCount == 1)
            {
                // Structure Variable
                FMeshProperties STR_Properties;

                // MAP Key Variable.
                FString Parent_Name = LOC_SM_Comp->GetAttachParent()->GetName();

                // MAP Value Variables.
                STR_Properties.Static_Mesh = LOC_SM_Comp->GetStaticMesh();
                STR_Properties.Grand_Parent = LOC_SM_Comp->GetAttachParent()->GetAttachParent();
                STR_Properties.World_Transform = LOC_SM_Comp->GetComponentTransform();

                // Add key and value to MAP.
                MAP_Properties.Add(Parent_Name, STR_Properties);

                // Destroy parent and object after that.
                LOC_SM_Comp->GetAttachParent()->DestroyComponent(true);
                LOC_SM_Comp->DestroyComponent(true);
            }
        }
    }

    TArray<FString> Array_Names; // Required construction of array variable for MAP_Properties' key array strings.
    MAP_Properties.GetKeys(Array_Names);

    for (int32 NameID = 0; NameID < Array_Names.Num(); NameID++)
    {
        // Required local variables for new static mesh component.
        AActor* Outer = AssetRoot->GetOwner();

        // If a static mesh component uses same name and same static mesh after destroying it, it will give error. So we added -N name suffix.
        FString NameString = Array_Names[NameID] + TEXT("-N");
        FName New_SMC_Name = FName(*NameString);

        FTransform RelativeTransform;
        bool Is_SMC_Created = true;
        FName Out_SMC_Name;
        UStaticMeshComponent* Out_SMC;

        // Create new static mesh component.
        AddStaticMeshCompWithName(New_SMC_Name, Outer, EComponentMobility::Movable, EAttachmentRule::KeepWorld, true, RelativeTransform, Is_SMC_Created, Out_SMC_Name, Out_SMC);

        // Get each property variable.
        FMeshProperties* EachProperty = MAP_Properties.Find(Array_Names[NameID]);

        // Set properties of each static mesh.
        Out_SMC->SetStaticMesh(EachProperty->Static_Mesh);
        Out_SMC->AttachToComponent(EachProperty->Grand_Parent, FAttachmentTransformRules::KeepWorldTransform, NAME_None);
        Out_SMC->SetWorldTransform(EachProperty->World_Transform);

        // Count processed items.
        Processed = Processed + 1;
    }

    // Out children components array variable.
    AssetRoot->GetChildrenComponents(true, Children);
    OutChildren = Children;

    // Show processed static mesh components.
    OutProcessed = Processed;
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


/*
DEPRECATED FUNCTION 1

void UMeshOperationsBPLibrary::VerticesOperations(UStaticMeshComponent* StaticMeshComponent, int32 LODs, TEnumAsByte<PivotOperations> Pivot, FVector CustomPivot, int32& AllVerticesCount, int32& UniqueVerticesCount, TArray<FVector>& OutAllVertices, TArray<FVector>& OutUniqueVertices)
// We have "GetVertexLocations" in here.
.
.
.

    if (Pivot != PivotOperations::None)
        {
            // Get original mesh center to calculate offset after moving vertices.
            FVector CenterOriginal = StaticMeshComponent->Bounds.Origin;

            // Change new pivot destination.
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
                NewPivot;
                break;
            }

            // Get static mesh informations for move pivot process.
            FMeshDescription* MeshDescription = StaticMeshComponent->GetStaticMesh()->GetMeshDescription(LODs);
            FStaticMeshLODResources& StaticMeshLODResources = StaticMeshComponent->GetStaticMesh()->GetRenderData()->LODResources[LODs];

            for (int32 VertexIndex = 0; VertexIndex < UniqueVerticesCount; VertexIndex++)
            {
                MeshDescription->VertexAttributes().SetAttribute(FVertexID(VertexIndex), MeshAttribute::Vertex::Position, 0, UniqueVertices.Array()[VertexIndex] - NewPivot);
            }

            TVertexAttributesConstRef<FVector> NewVerticesLocations = MeshDescription->VertexAttributes().GetAttributesRef<FVector>(MeshAttribute::Vertex::Position);

            // Build static mesh again from mesh description.
            StaticMeshComponent->GetStaticMesh()->BuildFromMeshDescription(*MeshDescription, StaticMeshLODResources);
            StaticMeshComponent->GetStaticMesh()->Build(true); // We should not have this in packaged project.

            // Offset mesh to retain its original world location.
            FVector LocationDifference = StaticMeshComponent->GetComponentLocation(); //We will change this with StaticMeshComponent->Bounds.Origin after tangent and normals calculation.
            StaticMeshComponent->AddWorldOffset(CenterOriginal - LocationDifference, false, nullptr, ETeleportType::None);
        }
*/