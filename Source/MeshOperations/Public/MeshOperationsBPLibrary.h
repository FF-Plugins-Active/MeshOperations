// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine.h"

//Components.
#include "UObject/Object.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ProceduralMeshComponent.h"

// Vertices and Pivot Functions
#include "EditableMesh.h"

#include "MeshOperationsBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/

UENUM()
enum PivotDestination
{
    None        UMETA(DisplayName = "None"),
    Center      UMETA(DisplayName = "Center"),
    Custom      UMETA(DisplayName = "Custom"),
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FCenterPivot, bool, IsSuccessfull);

UCLASS()
class UMeshOperationsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

    UFUNCTION(BlueprintCallable, meta = (DispayName = "AddStaticMeshCompWithName", Keywords = "static,mesh,component,name"), Category = "MeshOperations")
    static void AddStaticMeshCompWithName(const FString In_SMC_Name, AActor* SMC_Outer, EComponentMobility::Type SMC_Mobility, EAttachmentRule SMC_Attachment_Rule, bool SMC_Manual_Attachment, const FTransform SMC_Relative_Transform, bool& Is_SMC_Created, FName& Out_SMC_Name, UStaticMeshComponent*& Out_SMC);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "AddSceneCompWithName", Keywords = "scene,component,mesh,name"), Category = "MeshOperations")
    static void AddSceneCompWithName(const FString In_SC_Name, AActor* SC_Outer, EComponentMobility::Type SC_Mobility, EAttachmentRule SC_Attachment_Rule, bool SC_Manual_Attachment, const FTransform SC_Relative_Transform, bool& Is_SC_Created, FName& Out_SC_Name, USceneComponent*& Out_SC);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "AddProcMeshCompWithName", Keywords = "procedural,mesh,component,name"), Category = "MeshOperations")
    static void AddProcMeshCompWithName(const FString In_PMC_Name, AActor* PMC_Outer, EComponentMobility::Type PMC_Mobility, EAttachmentRule PMC_Attachment_Rule, bool PMC_Manual_Attachment, const FTransform PMC_Relative_Transform, bool& Is_PMC_Created, FName& Out_PMC_Name, UProceduralMeshComponent*& Out_PMC);

    UFUNCTION(BlueprintPure, meta = (DispayName = "GetClassName", Keywords = "name,class"), Category = "MeshOperations")
    static FString GetClassName(const UObject* Object);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "Get Object Name for Package", Keywords = "name,object,package"), Category = "MeshOperations")
    static void GetObjectNameForPackage(USceneComponent* Object, FString Delimeter, FString& OutName);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "Delete Empty Roots", Keywords = "optimize,hierarchy,empty,root,roots"), Category = "MeshOperations")
    static void DeleteEmptyRoots(USceneComponent* AssetRoot);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "OptimizeCenter", Keywords = "optimize,move,components,center"), Category = "MeshOperations")
    static void OptimizeCenter(USceneComponent* AssetRoot);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "OptimizeHeight", Keywords = "optimize,height"), Category = "MeshOperations")
    static void OptimizeHeight(USceneComponent* AssetRoot, float Z_Offset);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "RecordTransforms", ToolTip = "It should be attached to a MAP. Because we used local variable.", Keywords = "record,transforms"), Category = "MeshOperations")
    static void RecordTransforms(USceneComponent* AssetRoot, TMap<USceneComponent*, FTransform>& MapTransform, TArray<USceneComponent*>& AllComponents, TArray<USceneComponent*>& ChildComponents);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "Get Vertices Locations 1", ToolTip = "It uses PositionalVertexBuffer. It gives correct world positions but don't use it with EditableMesh move vertices. Use it with ProcMesh or vertex snaping.", Keywords = "vertex, vertices, locations, get"), Category = "MeshOperations")
    static void GetVerticesLocations_1(UStaticMeshComponent* Target_SMC, int32 LODs, TArray<FVector>& AllVertices, TArray<FVector>& UniqueVertices);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "Get Vertices Locations 2", ToolTip = "It uses MeshDescription->VertexAttributes. It created specifically for vertices movements. Also you can use it with vertex snaping, too.", Keywords = "vertex, vertices, locations, get"), Category = "MeshOperations")
    static void GetVerticesLocations_2(UStaticMeshComponent* Target_SMC, int32 LODs, TArray<FVector>& VerticesLocations);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "Set Vertex Location", ToolTip = "It uses same algorithm from EditableMesh->MoveVertices but we removed array and for loop. Because we didn't want two for loop for same operation.", Keywords = "vertex, vertices, locations, get"), Category = "MeshOperations")
    static void SetVertexLocation(UEditableMesh* TargetEditableMesh, FVertexToMove TargetVertexToMove);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "MovePivotToNewLocation", ToolTip = "It uses PositionVertexBuffer and EditableMesh", Keywords = "vertex, vertices, locations, pivot, center, custom, move, set"), Category = "MeshOperations")
    static void MovePivotToNewLocation(UStaticMeshComponent* Target_SMC, int32 LODs, TEnumAsByte<PivotDestination> Pivot, FVector CustomPivot, bool& IsSuccessful);
    
    UFUNCTION(BlueprintCallable, meta = (DispayName = "Recursive Move Pivot To Center", Keywords = "vertex, vertices, locations, pivot, center, custom, move, set, recursive"), Category = "MeshOperations")
    static void RecursiveMovePivotToCenter(USceneComponent* RootComponent, int32 LODs, FCenterPivot DelegateMovePivot);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "Create Procedural Mesh From Static Mesh", Keywords = "get, section, static, mesh,helper"), Category = "MeshOperations")
    static void CreatePMFromSM(UStaticMeshComponent* Target_SMC, UProceduralMeshComponent* Target_PMC, UMaterial* Material, int32 LODs, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UVs, TArray<FProcMeshTangent>& Tangents);
    
};