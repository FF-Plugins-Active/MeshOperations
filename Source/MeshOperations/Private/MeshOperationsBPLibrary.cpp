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

// Procedural to Static Mesh
#include "MeshDescription.h"
#include "StaticMeshDescription.h"
#include "ProceduralMeshConversion.h"

#include "MeshOperations.h"

UMeshOperationsBPLibrary::UMeshOperationsBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

FString UMeshOperationsBPLibrary::GetClassName(const UObject* Object)
{
    UClass* Class = Object->GetClass();
    return Class->GetName();
}

bool UMeshOperationsBPLibrary::GetObjectNameForPackage(USceneComponent* Object, bool bUseReadableName, FString Delimeter, FString& OutName)
{
    if (IsValid(Object) == false)
    {
        return false;
    }
    
    FString ObjectName;
    if (bUseReadableName == true)
    {
        ObjectName = Object->GetReadableName();
    }

    else
    {
        ObjectName = Object->GetName();
    }

    FString GeneratedName;
    TArray<FString> NameSections;
    ObjectName.ParseIntoArray(NameSections, *Delimeter, true);

    if (NameSections.Num() > 1)
    {
        if (WITH_EDITOR == true)
        {
            NameSections.RemoveAt(NameSections.Num() - 1);
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

        return true;
    }

    else
    {
        return false;
    }
}

bool UMeshOperationsBPLibrary::GetComponentByName(FName InName, UObject* Owner, USceneComponent*& OutComponent)
{
    OutComponent = Cast<USceneComponent>(Owner->GetDefaultSubobjectByName(InName));

    if (IsValid(OutComponent) == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool UMeshOperationsBPLibrary::AddStaticMeshCompWithName(UStaticMeshComponent*& Out_SMC, FName& Out_SMC_Name, FName InName, AActor* SMC_Outer, EAttachmentRule SMC_Attachment_Rule, bool SMC_Manual_Attachment, FTransform SMC_Relative_Transform, EComponentMobility::Type SMC_Mobility)
{
    if (IsValid(SMC_Outer) == false)
    {
        Out_SMC = nullptr;
        Out_SMC_Name = NAME_None;

        return false;
    }

    if (InName.ToString().IsEmpty() == true)
    {
        InName = NAME_None;
    }

    //Static Mesh Component Creation.
    UStaticMeshComponent* StaticMeshComp = NewObject<UStaticMeshComponent>(SMC_Outer, InName);

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
        Out_SMC_Name = InName;

        return true;
    }

    else
    {
        Out_SMC = nullptr;
        Out_SMC_Name = NAME_None;

        return false;
    }
}

void UMeshOperationsBPLibrary::AddSceneCompWithName(FName InName, AActor* SC_Outer, EComponentMobility::Type SC_Mobility, EAttachmentRule SC_Attachment_Rule, bool SC_Manual_Attachment, const FTransform SC_Relative_Transform, bool& Is_SC_Created, FName& Out_SC_Name, USceneComponent*& Out_SC)
{
    if (SC_Outer != NULL)
    {
        if (InName.ToString().IsEmpty() == true)
        {
            InName = NAME_None;
        }

        //Scene Component Creation.
        USceneComponent* SceneComp = NewObject<USceneComponent>(SC_Outer, InName);

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
            Out_SC_Name = InName;
            Is_SC_Created = SceneComp->IsValidLowLevel();
        }
    }

    else
    {
        //If outer is not valid, we can not create a "scene component" and program will crash. So we just return false.       
        Out_SC = nullptr;
        Out_SC_Name = NAME_None;
        Is_SC_Created = false;
    }
}

bool UMeshOperationsBPLibrary::AddProcMeshCompWithName(FName& Out_PMC_Name, UProceduralMeshComponent*& Out_PMC, AActor* PMC_Outer, FName InName, EAttachmentRule PMC_Attachment_Rule, bool PMC_Manual_Attachment, bool bUseAsyncCooking, FTransform PMC_Relative_Transform, EComponentMobility::Type PMC_Mobility)
{
    if (IsValid(PMC_Outer) == false)
    {
        return false;
    }
    
    if (InName.ToString().IsEmpty() == true)
    {
        InName = NAME_None;
    }

    //Procedural Mesh Component Creation.
    UProceduralMeshComponent* ProcMeshComp = NewObject<UProceduralMeshComponent>(PMC_Outer, InName);

    if (IsValid(ProcMeshComp) == false)
    {
        return false;
    }

    ProcMeshComp->SetMobility(PMC_Mobility);
    ProcMeshComp->bUseAsyncCooking = bUseAsyncCooking;
    ProcMeshComp->RegisterComponent();
    ProcMeshComp->AttachToComponent(PMC_Outer->GetRootComponent(), FAttachmentTransformRules(PMC_Attachment_Rule, true));

    if (PMC_Manual_Attachment == true)
    {
        //Set Realtive Transform.
        ProcMeshComp->SetRelativeTransform(PMC_Relative_Transform);
    }

    //Output Pins
    Out_PMC = ProcMeshComp;
    Out_PMC_Name = InName;

    return true;
}

bool UMeshOperationsBPLibrary::Convert_SMC_To_PMC(UStaticMeshComponent* Target_SMC, UProceduralMeshComponent* Target_PMC, UMaterial* Material, int32 LODs)
{
    if (IsValid(Target_SMC) && IsValid(Target_PMC) == false)
    {
        return false;
    }

    TArray<FColor> VertexColor;
    TArray<FVector> Vertices;
    TArray<int32> Triangles;
    TArray<FVector> Normals;
    TArray<FVector2D> UVs;
    TArray<FProcMeshTangent> Tangents;

    for (int32 SectionIndex = 0; SectionIndex < Target_SMC->GetStaticMesh()->GetNumSections(LODs); SectionIndex++)
    {
        UKismetProceduralMeshLibrary::GetSectionFromStaticMesh(Target_SMC->GetStaticMesh(), LODs, SectionIndex, Vertices, Triangles, Normals, UVs, Tangents);
        Target_PMC->CreateMeshSection(SectionIndex, Vertices, Triangles, Normals, UVs, VertexColor, Tangents, false);
    }

    for (int32 MaterialIndex = 0; MaterialIndex < Target_SMC->GetNumMaterials(); MaterialIndex++)
    {
        Target_PMC->SetMaterial(MaterialIndex, Material);
    }

    return true;
}

void CustomBuild(FMeshDescription& PMC_Description, UStaticMesh*& StaticMesh)
{
    TArray<const FMeshDescription*> MeshDescriptions;
    MeshDescriptions.Add(&PMC_Description);

    TRACE_CPUPROFILER_EVENT_SCOPE(UStaticMesh::BuildFromMeshDescriptions);
    const int32 NewNumLODs = MeshDescriptions.Num();

    TOptional<FStaticMeshComponentRecreateRenderStateContext> RecreateRenderStateContext;

    bool bNewMesh = true;
    if (StaticMesh->AreRenderingResourcesInitialized())
    {
        bNewMesh = false;
        const bool bInvalidateLighting = true;
        const bool bRefreshBounds = true;
        RecreateRenderStateContext = FStaticMeshComponentRecreateRenderStateContext(StaticMesh, bInvalidateLighting, bRefreshBounds);
        StaticMesh->ReleaseResources();
    }

    StaticMesh->SetRenderData(MakeUnique<FStaticMeshRenderData>());
    StaticMesh->GetRenderData()->AllocateLODResources(NewNumLODs);

    UStaticMesh::FBuildMeshDescriptionsParams Params;
    FStaticMeshLODResourcesArray& LODResourcesArray = StaticMesh->GetRenderData()->LODResources;
    for (int32 LODIndex = 0; LODIndex < LODResourcesArray.Num(); ++LODIndex)
    {
        LODResourcesArray[LODIndex].IndexBuffer.TrySetAllowCPUAccess(true);
        if (Params.PerLODOverrides.IsValidIndex(LODIndex))
        {
            const UStaticMesh::FBuildMeshDescriptionsLODParams& LODParams = Params.PerLODOverrides[LODIndex];
            LODResourcesArray[LODIndex].VertexBuffers.StaticMeshVertexBuffer.SetUseHighPrecisionTangentBasis(LODParams.bUseHighPrecisionTangentBasis);
            LODResourcesArray[LODIndex].VertexBuffers.StaticMeshVertexBuffer.SetUseFullPrecisionUVs(LODParams.bUseFullPrecisionUVs);
        }
    }

    for (int32 LODIndex = 0; LODIndex < NewNumLODs; LODIndex++)
    {
        check(MeshDescriptions[LODIndex] != nullptr);
        FStaticMeshLODResources& LODResources = StaticMesh->GetRenderData()->LODResources[LODIndex];
        StaticMesh->BuildFromMeshDescription(*MeshDescriptions[LODIndex], LODResources);
    }

    StaticMesh->InitResources();

    // Set up RenderData bounds and LOD data
    StaticMesh->GetRenderData()->Bounds = MeshDescriptions[0]->GetBounds();
    StaticMesh->CalculateExtendedBounds();

    for (int32 LOD = 0; LOD < NewNumLODs; ++LOD)
    {
        if (true)
        {
            const float LODPowerBase = 0.75f;
            StaticMesh->GetRenderData()->ScreenSize[LOD].Default = FMath::Pow(LODPowerBase, LOD);
        }

        else
        {
            // Possible model for flexible LODs
            const float MaxDeviation = 100.0f; // specify
            const float PixelError = UE_SMALL_NUMBER;
            const float ViewDistance = (MaxDeviation * 960.0f) / PixelError;

            // Generate a projection matrix.
            const float HalfFOV = UE_PI * 0.25f;
            const float ScreenWidth = 1920.0f;
            const float ScreenHeight = 1080.0f;
            const FPerspectiveMatrix ProjMatrix(HalfFOV, ScreenWidth, ScreenHeight, 1.0f);

            StaticMesh->GetRenderData()->ScreenSize[LOD].Default = ComputeBoundsScreenSize(FVector::ZeroVector, StaticMesh->GetRenderData()->Bounds.SphereRadius, FVector(0.0f, 0.0f, ViewDistance + StaticMesh->GetRenderData()->Bounds.SphereRadius), ProjMatrix);
        }
    }

    // Set up physics-related data
    StaticMesh->CreateBodySetup();
    check(StaticMesh->GetBodySetup());
    StaticMesh->GetBodySetup()->InvalidatePhysicsData();

    if (Params.bBuildSimpleCollision)
    {
        FKBoxElem BoxElem;
        BoxElem.Center = StaticMesh->GetRenderData()->Bounds.Origin;
        BoxElem.X = StaticMesh->GetRenderData()->Bounds.BoxExtent.X * 2.0f;
        BoxElem.Y = StaticMesh->GetRenderData()->Bounds.BoxExtent.Y * 2.0f;
        BoxElem.Z = StaticMesh->GetRenderData()->Bounds.BoxExtent.Z * 2.0f;
        StaticMesh->GetBodySetup()->AggGeom.BoxElems.Add(BoxElem);
        StaticMesh->GetBodySetup()->CreatePhysicsMeshes();
    }

    for (int32 LODIndex = 0; LODIndex < NewNumLODs; LODIndex++)
    {
        FStaticMeshLODResources& LODResources = StaticMesh->GetRenderData()->LODResources[LODIndex];
        for (int32 SectionIndex = 0; SectionIndex < LODResources.Sections.Num(); SectionIndex++)
        {
            const FStaticMeshSection& StaticMeshSection = LODResources.Sections[SectionIndex];
            FMeshSectionInfo SectionInfo;
            SectionInfo.MaterialIndex = StaticMeshSection.MaterialIndex;
            SectionInfo.bEnableCollision = StaticMeshSection.bEnableCollision;
            SectionInfo.bCastShadow = StaticMeshSection.bCastShadow;
            
            // I think problem is about this.
            // StaticMesh->GetSectionInfoMap().Set(LODIndex, SectionIndex, SectionInfo);
        }
    }
}

bool UMeshOperationsBPLibrary::Convert_PMC_To_SMC(UStaticMesh*& Out_Sm, UObject* Outer, UProceduralMeshComponent* In_Pmc)
{
    if (IsValid(In_Pmc) == false)
    {
        return false;
    }
    
    FName PMC_Name = FName(*(In_Pmc->GetName() + "_SM"));
    UStaticMesh* StaticMesh = NewObject<UStaticMesh>(Outer ? Outer : GetTransientPackage(), PMC_Name, RF_Public);
    StaticMesh->bAllowCPUAccess = true;
    StaticMesh->NeverStream = true;

    FMeshDescription PMC_Description = BuildMeshDescription(In_Pmc);
    UStaticMeshDescription* SM_Description = StaticMesh->CreateStaticMeshDescription();
    SM_Description->SetMeshDescription(PMC_Description);
    StaticMesh->BuildFromStaticMeshDescriptions({ SM_Description }, false);
    
    //CustomBuild(PMC_Description, StaticMesh);

    // Collision
    StaticMesh->CalculateExtendedBounds();
    StaticMesh->SetBodySetup(In_Pmc->ProcMeshBodySetup);

    // Materials
    TArray<FStaticMaterial> StaticMaterials;
    TArray<UMaterialInterface*> Materials = In_Pmc->GetMaterials();
    for (int32 Index_Material = 0; Index_Material < Materials.Num(); Index_Material++)
    {
        StaticMaterials.Add(FStaticMaterial(Materials[Index_Material]));
    }
    StaticMesh->SetStaticMaterials(StaticMaterials);
    
    StaticMesh->MarkPackageDirty();
    StaticMesh->InitResources();
    Out_Sm = StaticMesh;

    return true;
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

void UMeshOperationsBPLibrary::DeleteEmptyParents(USceneComponent* AssetRoot, UObject* Outer, FDeleteParents DelegateDeleteParents)
{
    AsyncTask(ENamedThreads::GameThread, [DelegateDeleteParents, AssetRoot, Outer]()
        {
            // Get all children components at start.
            TArray<USceneComponent*> ChildrenComps;
            AssetRoot->GetChildrenComponents(true, ChildrenComps);

            if (ChildrenComps.Num() > 1)
            {
                // Conditions.
                bool IsProcessFinished = false;
                TMap<USceneComponent*, bool> AnyEmptyParentLeft;

                while (IsProcessFinished == false)
                {
                    for (int32 ChildIndex = 0; ChildIndex < ChildrenComps.Num(); ChildIndex++)
                    {
                        if (ChildrenComps[ChildIndex]->GetClass()->GetName() == TEXT("StaticMeshComponent") && ChildrenComps[ChildIndex]->GetAttachParent()->GetNumChildrenComponents() == 1)
                        {
                            USceneComponent* EachChild = ChildrenComps[ChildIndex];
                            USceneComponent* MiddleParent = EachChild->GetAttachParent();
                            USceneComponent* GrandParent = MiddleParent->GetAttachParent();

                            // We will use this name as static mesh's new name.
                            const FString New_SMC_Name = MiddleParent->GetName();

                            // Change middle parent's name and destroy it.
                            FGuid MiddleParentSuffix = FGuid::NewGuid();
                            const FString MiddleParentName = TEXT("DeletedSceneComp") + MiddleParentSuffix.ToString();
                            MiddleParent->Rename(*MiddleParentName, Outer);
                            MiddleParent->DestroyComponent(false);

                            // Change target static mesh name.
                            EachChild->AttachToComponent(GrandParent, FAttachmentTransformRules::KeepWorldTransform, NAME_None);
                            EachChild->Rename(*New_SMC_Name, Outer);

                            // Check if there is any empty parent left.
                            if (EachChild->GetAttachParent()->GetNumChildrenComponents() == 1)
                            {
                                AnyEmptyParentLeft.Add(EachChild, true);
                            }
                        }
                    }

                    // If there is an empty parent, get related component and start loop again. 
                    TArray<bool> Array_Bool_Values;
                    AnyEmptyParentLeft.GenerateValueArray(Array_Bool_Values);

                    if (Array_Bool_Values.Contains(true) == true)
                    {
                        AnyEmptyParentLeft.GenerateKeyArray(ChildrenComps);
                        AnyEmptyParentLeft.Empty();
                        IsProcessFinished = false;
                    }

                    else
                    {
                        AnyEmptyParentLeft.Empty();
                        IsProcessFinished = true;
                    }
                }
            }

            AsyncTask(ENamedThreads::GameThread, [DelegateDeleteParents]()
                {
                    DelegateDeleteParents.ExecuteIfBound(true);
                }
            );
        }
    );
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

bool UMeshOperationsBPLibrary::RenameComponent(UPARAM(ref)UObject* Target, UObject* Outer, FName NewName)
{
    if (IsValid(Target) == false)
    {
        return false;
    }

    Target->Rename(*(NewName.ToString()), Outer);
    return true;
}