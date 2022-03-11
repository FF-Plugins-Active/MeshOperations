// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h" 
#include "Engine.h"

// Components.
#include "UObject/Object.h"

#include "AC_Rename.generated.h"


UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FDeleteParents, bool, IsSuccessed);


USTRUCT(BlueprintType)
struct FMeshProperties
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Editanywhere)
	UStaticMesh* Static_Mesh = nullptr;

	UPROPERTY(BlueprintReadWrite, Editanywhere)
	USceneComponent* Grand_Parent = nullptr;

	UPROPERTY(BlueprintReadWrite, Editanywhere)
	FTransform World_Transform;

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MESHOPERATIONS_API UAC_Rename : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_Rename();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Rename Object", ToolTip = "Description", Keywords = "rename, object, mesh, scene"), Category = "Mesh Operations")
	virtual bool RenameObject(bool Use_GUID_Suffix, const FString NewName, UObject* Outer, UObject* TargetObject);

	UFUNCTION(BlueprintCallable, meta = (DispayName = "Delete Empty Parents", Keywords = "optimize,hierarchy,empty,parent,parents"), Category = "MeshOperations")
	virtual void DeleteEmptyParents(USceneComponent* AssetRoot, UObject* Outer, FDeleteParents DelegateDeleteParents);

};
