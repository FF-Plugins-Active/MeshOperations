// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshOperationsBPLibrary.h"

// Math Functions.
#include "Math/Vector.h"
#include "Kismet/KismetMathLibrary.h"

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

// GLTF Exporter
#include "Builders/GLTFBuilder.h"
#include "UserData/GLTFMaterialUserData.h"

#include "PhysicsEngine/BodySetup.h"
#include "Rendering/PositionVertexBuffer.h"

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

bool UMeshOperationsBPLibrary::AddProcMeshCompWithName(FName& Out_PMC_Name, UProceduralMeshComponent*& Out_PMC, AActor* PMC_Outer, FName InName, EAttachmentRule PMC_Attachment_Rule, bool PMC_Manual_Attachment, bool bUseAsyncCooking, bool bUseComplexCollisionAsSimple, FTransform PMC_Relative_Transform, EComponentMobility::Type PMC_Mobility)
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
    ProcMeshComp->bUseComplexAsSimpleCollision = bUseComplexCollisionAsSimple;
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

void UMeshOperationsBPLibrary::GenerateBoxMeshAtBottom(FVector BoxRadius, TArray<FVector>&Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UVs, TArray<FProcMeshTangent>& Tangents)
{
    // Generate verts
    FVector BoxVerts[8];
    BoxVerts[0] = FVector(-BoxRadius.X, BoxRadius.Y, BoxRadius.Z);
    BoxVerts[1] = FVector(BoxRadius.X, BoxRadius.Y, BoxRadius.Z);
    BoxVerts[2] = FVector(BoxRadius.X, -BoxRadius.Y, BoxRadius.Z);
    BoxVerts[3] = FVector(-BoxRadius.X, -BoxRadius.Y, BoxRadius.Z);

    BoxVerts[4] = FVector(-BoxRadius.X, BoxRadius.Y, 0);
    BoxVerts[5] = FVector(BoxRadius.X, BoxRadius.Y, 0);
    BoxVerts[6] = FVector(BoxRadius.X, -BoxRadius.Y, 0);
    BoxVerts[7] = FVector(-BoxRadius.X, -BoxRadius.Y, 0);

    // Generate triangles (from quads)
    Triangles.Reset();

    const int32 NumVerts = 24; // 6 faces x 4 verts per face

    Vertices.Reset();
    Vertices.AddUninitialized(NumVerts);

    Normals.Reset();
    Normals.AddUninitialized(NumVerts);

    Tangents.Reset();
    Tangents.AddUninitialized(NumVerts);

    Vertices[0] = BoxVerts[0];
    Vertices[1] = BoxVerts[1];
    Vertices[2] = BoxVerts[2];
    Vertices[3] = BoxVerts[3];
    UKismetProceduralMeshLibrary::ConvertQuadToTriangles(Triangles, 0, 1, 2, 3);
    Normals[0] = Normals[1] = Normals[2] = Normals[3] = FVector(0, 0, 1);
    Tangents[0] = Tangents[1] = Tangents[2] = Tangents[3] = FProcMeshTangent(0.f, -1.f, 0.f);

    Vertices[4] = BoxVerts[4];
    Vertices[5] = BoxVerts[0];
    Vertices[6] = BoxVerts[3];
    Vertices[7] = BoxVerts[7];
    UKismetProceduralMeshLibrary::ConvertQuadToTriangles(Triangles, 4, 5, 6, 7);
    Normals[4] = Normals[5] = Normals[6] = Normals[7] = FVector(-1, 0, 0);
    Tangents[4] = Tangents[5] = Tangents[6] = Tangents[7] = FProcMeshTangent(0.f, -1.f, 0.f);

    Vertices[8] = BoxVerts[5];
    Vertices[9] = BoxVerts[1];
    Vertices[10] = BoxVerts[0];
    Vertices[11] = BoxVerts[4];
    UKismetProceduralMeshLibrary::ConvertQuadToTriangles(Triangles, 8, 9, 10, 11);
    Normals[8] = Normals[9] = Normals[10] = Normals[11] = FVector(0, 1, 0);
    Tangents[8] = Tangents[9] = Tangents[10] = Tangents[11] = FProcMeshTangent(-1.f, 0.f, 0.f);

    Vertices[12] = BoxVerts[6];
    Vertices[13] = BoxVerts[2];
    Vertices[14] = BoxVerts[1];
    Vertices[15] = BoxVerts[5];
    UKismetProceduralMeshLibrary::ConvertQuadToTriangles(Triangles, 12, 13, 14, 15);
    Normals[12] = Normals[13] = Normals[14] = Normals[15] = FVector(1, 0, 0);
    Tangents[12] = Tangents[13] = Tangents[14] = Tangents[15] = FProcMeshTangent(0.f, 1.f, 0.f);

    Vertices[16] = BoxVerts[7];
    Vertices[17] = BoxVerts[3];
    Vertices[18] = BoxVerts[2];
    Vertices[19] = BoxVerts[6];
    UKismetProceduralMeshLibrary::ConvertQuadToTriangles(Triangles, 16, 17, 18, 19);
    Normals[16] = Normals[17] = Normals[18] = Normals[19] = FVector(0, -1, 0);
    Tangents[16] = Tangents[17] = Tangents[18] = Tangents[19] = FProcMeshTangent(1.f, 0.f, 0.f);

    Vertices[20] = BoxVerts[7];
    Vertices[21] = BoxVerts[6];
    Vertices[22] = BoxVerts[5];
    Vertices[23] = BoxVerts[4];
    UKismetProceduralMeshLibrary::ConvertQuadToTriangles(Triangles, 20, 21, 22, 23);
    Normals[20] = Normals[21] = Normals[22] = Normals[23] = FVector(0, 0, -1);
    Tangents[20] = Tangents[21] = Tangents[22] = Tangents[23] = FProcMeshTangent(0.f, 1.f, 0.f);

    // UVs
    UVs.Reset();
    UVs.AddUninitialized(NumVerts);

    UVs[0] = UVs[4] = UVs[8] = UVs[12] = UVs[16] = UVs[20] = FVector2D(0.f, 0.f);
    UVs[1] = UVs[5] = UVs[9] = UVs[13] = UVs[17] = UVs[21] = FVector2D(0.f, 1.f);
    UVs[2] = UVs[6] = UVs[10] = UVs[14] = UVs[18] = UVs[22] = FVector2D(1.f, 1.f);
    UVs[3] = UVs[7] = UVs[11] = UVs[15] = UVs[19] = UVs[23] = FVector2D(1.f, 0.f);
}

void UMeshOperationsBPLibrary::GenerateCylinderMesh(double Radius, double ArcSize, TArray<FVector2D>& Vertices, TArray<int32>& Triangles)
{
    TArray<FVector2D> TempVertices;
    TArray<int32> TempTriangles;

    const int32 NumSegments_Cap = FMath::RoundToInt(ArcSize / 2.0f);

    TempVertices.Add(FVector2D(0, 0));
    for (int32 Index = 0; Index < NumSegments_Cap + 2; ++Index)
    {
        const double CurrentAngle = FMath::DegreesToRadians(ArcSize * Index / NumSegments_Cap);
        const FVector2D EdgeDirection(FMath::Cos(CurrentAngle), FMath::Sin(CurrentAngle));
        const FVector2D OuterEdge(Radius * EdgeDirection);

        TempVertices.Add(FVector2D(0, 0) + FVector2D(OuterEdge.X, OuterEdge.Y));
    }

    for (int32 i = 0; i <= NumSegments_Cap; ++i)
    {
        TempTriangles.Add(0);
        TempTriangles.Add(i);
        TempTriangles.Add(i + 1);
    }

    Vertices = TempVertices;
    Triangles = TempTriangles;
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

void UMeshOperationsBPLibrary::ExportLevelGLTF(bool bEnableQuantization, bool bResetLocation, bool bResetRotation, bool bResetScale, const FString ExportPath, TSet<AActor*> TargetActors, FDelegateGLTFExport DelegateGLTFExport)
{
    AsyncTask(ENamedThreads::AnyNormalThreadNormalTask, [DelegateGLTFExport, bEnableQuantization, bResetLocation, bResetRotation, bResetScale, ExportPath, TargetActors]()
        {
            TArray<FVector> Array_Locations;
            TArray<FRotator> Array_Rotations;
            TArray<FVector> Array_Scales;

            for (int32 ActorIndex = 0; ActorIndex < TargetActors.Num(); ActorIndex++)
            {
                if (bResetLocation == true)
                {
                    Array_Locations.Add(TargetActors.Array()[ActorIndex]->GetRootComponent()->GetComponentLocation());
                    TargetActors.Array()[ActorIndex]->GetRootComponent()->SetWorldLocation(FVector(0.0f), false, nullptr, ETeleportType::None);
                }

                if (bResetRotation == true)
                {
                    Array_Rotations.Add(TargetActors.Array()[ActorIndex]->GetRootComponent()->GetComponentRotation());
                    TargetActors.Array()[ActorIndex]->GetRootComponent()->SetWorldRotation(FQuat(0.0f), false, nullptr, ETeleportType::None);
                }

                if (bResetScale == true)
                {
                    Array_Scales.Add(TargetActors.Array()[ActorIndex]->GetRootComponent()->GetComponentScale());
                    TargetActors.Array()[ActorIndex]->GetRootComponent()->SetWorldScale3D(FVector(1.0f));
                }
            }

            AsyncTask(ENamedThreads::GameThread, [DelegateGLTFExport, bEnableQuantization, bResetLocation, bResetRotation, bResetScale, Array_Locations, Array_Rotations, Array_Scales, ExportPath, TargetActors]()
                {
                    UGLTFExportOptions* ExportOptions = NewObject<UGLTFExportOptions>();
                    ExportOptions->ResetToDefault();
                    ExportOptions->bExportProxyMaterials = true;
                    ExportOptions->bExportVertexColors = true;
                    ExportOptions->bUseMeshQuantization = bEnableQuantization;

                    FGLTFExportMessages ExportMessages;
                    bool bIsExportSuccessful = UGLTFExporter::ExportToGLTF(GEngine->GetCurrentPlayWorld(), ExportPath, ExportOptions, TargetActors, ExportMessages);

                    for (int32 ActorIndex = 0; ActorIndex < TargetActors.Num(); ActorIndex++)
                    {
                        if (bResetLocation == true)
                        {
                            TargetActors.Array()[ActorIndex]->GetRootComponent()->SetWorldLocation(Array_Locations[ActorIndex], false, nullptr, ETeleportType::None);
                        }

                        if (bResetRotation == true)
                        {
                            TargetActors.Array()[ActorIndex]->GetRootComponent()->SetWorldRotation(Array_Rotations[ActorIndex], false, nullptr, ETeleportType::None);
                        }

                        if (bResetScale == true)
                        {
                            TargetActors.Array()[ActorIndex]->GetRootComponent()->SetWorldScale3D(Array_Scales[ActorIndex]);
                        }
                    }

                    DelegateGLTFExport.ExecuteIfBound(bIsExportSuccessful, ExportMessages);
                }
            );
        }
    );
}

bool UMeshOperationsBPLibrary::GetVerticesLocations(UStaticMeshComponent* In_SMC, int32 LOD_Index, TArray<FVector>& OutVertices)
{
    if (IsValid(In_SMC) == true)
    {
        FPositionVertexBuffer* PositionVertexBuffer = &In_SMC->GetStaticMesh()->GetRenderData()->LODResources[LOD_Index].VertexBuffers.PositionVertexBuffer;

        FVector3d EachVertices;
        for (uint32 VertexIndex = 0; VertexIndex < PositionVertexBuffer->GetNumVertices(); VertexIndex++)
        {
            EachVertices = In_SMC->GetComponentTransform().TransformPosition((FVector3d)PositionVertexBuffer->VertexPosition(VertexIndex));
            OutVertices.Add(EachVertices);
        }

        return true;
    }

    else
    {
        return false;
    }
}

bool UMeshOperationsBPLibrary::SetPivotLocation(UPARAM(ref) UStaticMeshComponent*& In_SMC, FVector PivotLocation, UObject* Outer)
{
    if (IsValid(In_SMC) == false)
    {
        return false;
    }

    UStaticMesh* StaticMesh = In_SMC->GetStaticMesh();

    if (!StaticMesh)
    {
        return false;
    }

    if (!StaticMesh->bAllowCPUAccess)
    {
        return false;
    }

    FStaticMeshRenderData* RenderData = StaticMesh->GetRenderData();

    if (!RenderData)
    {
        return false;
    }

    FVector PivotDelta = (PivotLocation - In_SMC->GetComponentLocation()) * (-1);

    UStaticMesh* NewStaticMesh = NewObject<UStaticMesh>(Outer ? Outer : GetTransientPackage(), NAME_None, RF_Public);
    NewStaticMesh->bAllowCPUAccess = true;
    NewStaticMesh->NeverStream = true;

    NewStaticMesh->SetRenderData(MakeUnique<FStaticMeshRenderData>());
    FStaticMeshRenderData* NewRenderData = NewStaticMesh->GetRenderData();

    NewRenderData->AllocateLODResources(RenderData->LODResources.Num());

    for (int32 LODIndex = 0; LODIndex < NewRenderData->LODResources.Num(); LODIndex++)
    {
        FStaticMeshLODResources& OriginalLOD = RenderData->LODResources[LODIndex];
        FStaticMeshLODResources& NewLOD = NewRenderData->LODResources[LODIndex];

        TArray<uint32> Indices;
        OriginalLOD.IndexBuffer.GetCopy(Indices);
        NewLOD.IndexBuffer.SetIndices(Indices, OriginalLOD.IndexBuffer.Is32Bit() ? EIndexBufferStride::Force32Bit : EIndexBufferStride::Force16Bit);

        int32 NumPositions = OriginalLOD.VertexBuffers.PositionVertexBuffer.GetNumVertices();
        NewLOD.VertexBuffers.PositionVertexBuffer.Init(NumPositions);
        for (int32 PositionIndex = 0; PositionIndex < NumPositions; PositionIndex++)
        {
            NewLOD.VertexBuffers.PositionVertexBuffer.VertexPosition(PositionIndex) = OriginalLOD.VertexBuffers.PositionVertexBuffer.VertexPosition(PositionIndex) + FVector3f(PivotDelta);
        }

        uint32 NumVertices = OriginalLOD.VertexBuffers.StaticMeshVertexBuffer.GetNumVertices();

        NewLOD.VertexBuffers.StaticMeshVertexBuffer.Init(NumVertices, OriginalLOD.VertexBuffers.StaticMeshVertexBuffer.GetNumTexCoords());

        for (uint32 VertexIndex = 0; VertexIndex < NumVertices; VertexIndex++)
        {
            FVector4f TangentX = OriginalLOD.VertexBuffers.StaticMeshVertexBuffer.VertexTangentX(VertexIndex);
            FVector4f TangentY = OriginalLOD.VertexBuffers.StaticMeshVertexBuffer.VertexTangentY(VertexIndex);
            FVector4f TangentZ = OriginalLOD.VertexBuffers.StaticMeshVertexBuffer.VertexTangentZ(VertexIndex);
            NewLOD.VertexBuffers.StaticMeshVertexBuffer.SetVertexTangents(VertexIndex, TangentX, TangentY, TangentZ);
            for (uint32 UVIndex = 0; UVIndex < OriginalLOD.VertexBuffers.StaticMeshVertexBuffer.GetNumTexCoords(); UVIndex++)
            {
                FVector2f UV = OriginalLOD.VertexBuffers.StaticMeshVertexBuffer.GetVertexUV(VertexIndex, UVIndex);
                NewLOD.VertexBuffers.StaticMeshVertexBuffer.SetVertexUV(VertexIndex, UVIndex, UV);
            }
        }

        TArray<FColor> Colors;
        OriginalLOD.VertexBuffers.ColorVertexBuffer.GetVertexColors(Colors);
        if (Colors.Num() > 0)
        {
            NewLOD.VertexBuffers.ColorVertexBuffer.InitFromColorArray(Colors);
        }

        for (int32 SectionIndex = 0; SectionIndex < OriginalLOD.Sections.Num(); SectionIndex++)
        {
            FStaticMeshSection& OriginalSection = OriginalLOD.Sections[SectionIndex];
            FStaticMeshSection& NewSection = NewLOD.Sections.AddDefaulted_GetRef();
            // copy section configuration
            NewSection = OriginalSection;
        }
    }

    NewStaticMesh->SetStaticMaterials(StaticMesh->GetStaticMaterials());

    NewStaticMesh->InitResources();

    NewRenderData->Bounds = RenderData->Bounds;
    NewRenderData->Bounds.Origin += PivotDelta;

    NewStaticMesh->CalculateExtendedBounds();
    NewStaticMesh->CreateBodySetup();
    NewStaticMesh->GetBodySetup()->CollisionTraceFlag = StaticMesh->GetBodySetup()->CollisionTraceFlag;
    NewStaticMesh->GetBodySetup()->InvalidatePhysicsData();
    NewStaticMesh->GetBodySetup()->AggGeom = StaticMesh->GetBodySetup()->AggGeom;

    for (FKBoxElem& Box : NewStaticMesh->GetBodySetup()->AggGeom.BoxElems)
    {
        Box.Center += PivotDelta;
    }

    for (FKSphereElem& Sphere : NewStaticMesh->GetBodySetup()->AggGeom.SphereElems)
    {
        Sphere.Center += PivotDelta;
    }

    for (FKSphylElem& Sphyle : NewStaticMesh->GetBodySetup()->AggGeom.SphylElems)
    {
        Sphyle.Center += PivotDelta;
    }

    for (FKConvexElem& Convex : NewStaticMesh->GetBodySetup()->AggGeom.ConvexElems)
    {
        for (FVector& Vertex : Convex.VertexData)
        {
            Vertex += PivotDelta;
        }
        Convex.UpdateElemBox();
    }

    NewStaticMesh->GetBodySetup()->CreatePhysicsMeshes();

    In_SMC->SetStaticMesh(NewStaticMesh);
    In_SMC->AddWorldOffset(PivotLocation - In_SMC->Bounds.Origin);
    return true;
}

bool UMeshOperationsBPLibrary::MovePivotsToCenter(USceneComponent* RootComponent, TArray<FString>& ErroredMeshes)
{
    if (IsValid(RootComponent) == false)
    {
        return false;
    }

    TArray<USceneComponent*> Array_Children;
    RootComponent->GetChildrenComponents(true, Array_Children);

    int32 StaticMeshCount = 0;

    for (int32 ChildIndex = 0; ChildIndex < Array_Children.Num(); ChildIndex++)
    {
        UStaticMeshComponent* EachMesh = Cast<UStaticMeshComponent>(Array_Children[ChildIndex]);

        if (IsValid(EachMesh) == true)
        {
            if (UMeshOperationsBPLibrary::SetPivotLocation(EachMesh, EachMesh->Bounds.Origin, EachMesh) == false)
            {
                ErroredMeshes.Add(EachMesh->GetReadableName());
            }

            StaticMeshCount += 1;
        }
    }

    if (ErroredMeshes.Num() == StaticMeshCount)
    {
        return false;
    }

    return true;
}