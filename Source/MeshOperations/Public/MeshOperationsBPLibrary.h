// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
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

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FDeleteParents, bool, IsSuccessed);

UCLASS()
class UMeshOperationsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

    UFUNCTION(BlueprintPure, meta = (DispayName = "GetClassName", Keywords = "name,class"), Category = "MeshOperations")
    static FString GetClassName(const UObject* Object);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "Get Object Name for Package", Keywords = "name,object,package"), Category = "MeshOperations")
    static bool GetObjectNameForPackage(USceneComponent* Object, bool bUseReadableName, FString Delimeter, FString& OutName);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "Get Component By Name", Keywords = "get, component, by, name"), Category = "MeshOperations")
    static bool GetComponentByName(FName InName, UObject* Owner, USceneComponent*& OutComponent);
        
    UFUNCTION(BlueprintCallable, meta = (DispayName = "AddStaticMeshCompWithName", Keywords = "static,mesh,component,name"), Category = "MeshOperations")
    static void AddStaticMeshCompWithName(FName InName, AActor* SMC_Outer, EComponentMobility::Type SMC_Mobility, EAttachmentRule SMC_Attachment_Rule, bool SMC_Manual_Attachment, const FTransform SMC_Relative_Transform, bool& Is_SMC_Created, FName& Out_SMC_Name, UStaticMeshComponent*& Out_SMC);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "AddSceneCompWithName", Keywords = "scene,component,mesh,name"), Category = "MeshOperations")
    static void AddSceneCompWithName(FName InName, AActor* SC_Outer, EComponentMobility::Type SC_Mobility, EAttachmentRule SC_Attachment_Rule, bool SC_Manual_Attachment, const FTransform SC_Relative_Transform, bool& Is_SC_Created, FName& Out_SC_Name, USceneComponent*& Out_SC);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "AddProcMeshCompWithName", Keywords = "procedural,mesh,component,name"), Category = "MeshOperations")
    static void AddProcMeshCompWithName(FName InName, AActor* PMC_Outer, EComponentMobility::Type PMC_Mobility, EAttachmentRule PMC_Attachment_Rule, bool PMC_Manual_Attachment, const FTransform PMC_Relative_Transform, bool& Is_PMC_Created, FName& Out_PMC_Name, UProceduralMeshComponent*& Out_PMC);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "Delete Empty Roots", Keywords = "optimize,hierarchy,empty,root,roots"), Category = "MeshOperations")
    static void DeleteEmptyRoots(USceneComponent* AssetRoot);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "OptimizeCenter", Keywords = "optimize,move,components,center"), Category = "MeshOperations")
    static void OptimizeCenter(USceneComponent* AssetRoot);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "OptimizeHeight", Keywords = "optimize,height"), Category = "MeshOperations")
    static void OptimizeHeight(USceneComponent* AssetRoot, float Z_Offset);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "RecordTransforms", ToolTip = "It should be attached to a MAP. Because we used local variable.", Keywords = "record,transforms"), Category = "MeshOperations")
    static void RecordTransforms(USceneComponent* AssetRoot, TMap<USceneComponent*, FTransform>& MapTransform, TArray<USceneComponent*>& AllComponents, TArray<USceneComponent*>& ChildComponents);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "Create Procedural Mesh From Static Mesh", Keywords = "get, section, static, mesh,helper"), Category = "MeshOperations")
    static bool CreatePMFromSM(UStaticMeshComponent* Target_SMC, UProceduralMeshComponent* Target_PMC, UMaterial* Material, int32 LODs);
    
    UFUNCTION(BlueprintCallable, meta = (DispayName = "Rename Component", Keywords = "rename, component"), Category = "MeshOperations")
    static bool RenameComponent(UPARAM(ref)UObject* Target, UObject* Owner, FName NewName);

    UFUNCTION(BlueprintCallable, meta = (DispayName = "Delete Empty Parents", Keywords = "optimize,hierarchy,empty,parent,parents"), Category = "MeshOperations")
    virtual void DeleteEmptyParents(USceneComponent* AssetRoot, UObject* Outer, FDeleteParents DelegateDeleteParents);
};