// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_Rename.h"
#include "UObject/Object.h"

//Calculations.
#include "Math/Vector.h"
#include "Kismet/KismetGuidLibrary.h"

// Async Functions.
#include "Async/Async.h" 
#include "Async/IAsyncProgress.h"

// Sets default values for this component's properties
UAC_Rename::UAC_Rename()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UAC_Rename::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UAC_Rename::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UAC_Rename::RenameObject(bool Use_GUID_Suffix, const FString NewName, UObject* Outer, UObject* TargetObject)
{
	if (Use_GUID_Suffix == true)
	{
		FGuid ObjectGuid = FGuid::NewGuid();
		const FString NewNameString = NewName + ObjectGuid.ToString();
		return TargetObject->Rename(*NewNameString, Outer);
	}
	
	else
	{
		return TargetObject->Rename(*NewName, Outer);
	}
}

void UAC_Rename::DeleteEmptyParents(USceneComponent* AssetRoot, UObject* Outer, FDeleteParents DelegateDeleteParents)
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