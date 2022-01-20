// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UStaticMesh;
struct FVector;
struct FVector2D;
struct FProcMeshTangent;
class UObject;
class AActor;
enum class EAttachmentRule : uint8;
struct FTransform;
class UProceduralMeshComponent;
class USceneComponent;
class UStaticMeshComponent;
#ifdef MESHOPERATIONS_MeshOperationsBPLibrary_generated_h
#error "MeshOperationsBPLibrary.generated.h already included, missing '#pragma once' in MeshOperationsBPLibrary.h"
#endif
#define MESHOPERATIONS_MeshOperationsBPLibrary_generated_h

#define FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_SPARSE_DATA
#define FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetVertexLocations); \
	DECLARE_FUNCTION(execGetFullName); \
	DECLARE_FUNCTION(execAddProcMeshCompWithName); \
	DECLARE_FUNCTION(execAddSceneCompWithName); \
	DECLARE_FUNCTION(execAddStaticMeshCompWithName);


#define FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetVertexLocations); \
	DECLARE_FUNCTION(execGetFullName); \
	DECLARE_FUNCTION(execAddProcMeshCompWithName); \
	DECLARE_FUNCTION(execAddSceneCompWithName); \
	DECLARE_FUNCTION(execAddStaticMeshCompWithName);


#define FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMeshOperationsBPLibrary(); \
	friend struct Z_Construct_UClass_UMeshOperationsBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UMeshOperationsBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MeshOperations"), NO_API) \
	DECLARE_SERIALIZER(UMeshOperationsBPLibrary)


#define FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_INCLASS \
private: \
	static void StaticRegisterNativesUMeshOperationsBPLibrary(); \
	friend struct Z_Construct_UClass_UMeshOperationsBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UMeshOperationsBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MeshOperations"), NO_API) \
	DECLARE_SERIALIZER(UMeshOperationsBPLibrary)


#define FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMeshOperationsBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMeshOperationsBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMeshOperationsBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMeshOperationsBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMeshOperationsBPLibrary(UMeshOperationsBPLibrary&&); \
	NO_API UMeshOperationsBPLibrary(const UMeshOperationsBPLibrary&); \
public:


#define FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMeshOperationsBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMeshOperationsBPLibrary(UMeshOperationsBPLibrary&&); \
	NO_API UMeshOperationsBPLibrary(const UMeshOperationsBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMeshOperationsBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMeshOperationsBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMeshOperationsBPLibrary)


#define FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_PRIVATE_PROPERTY_OFFSET
#define FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_34_PROLOG
#define FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_PRIVATE_PROPERTY_OFFSET \
	FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_SPARSE_DATA \
	FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_RPC_WRAPPERS \
	FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_INCLASS \
	FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_PRIVATE_PROPERTY_OFFSET \
	FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_SPARSE_DATA \
	FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_INCLASS_NO_PURE_DECLS \
	FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h_37_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class MeshOperationsBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MESHOPERATIONS_API UClass* StaticClass<class UMeshOperationsBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FF_Plugins_Plugins_MeshOperations_Source_MeshOperations_Public_MeshOperationsBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
