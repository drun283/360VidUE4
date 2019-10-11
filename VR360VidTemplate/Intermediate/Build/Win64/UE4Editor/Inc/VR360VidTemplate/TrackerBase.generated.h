// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VR360VIDTEMPLATE_TrackerBase_generated_h
#error "TrackerBase.generated.h already included, missing '#pragma once' in TrackerBase.h"
#endif
#define VR360VIDTEMPLATE_TrackerBase_generated_h

#define VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execinitalizeCurves) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->initalizeCurves(); \
		P_NATIVE_END; \
	}


#define VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execinitalizeCurves) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->initalizeCurves(); \
		P_NATIVE_END; \
	}


#define VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATrackerBase(); \
	friend struct Z_Construct_UClass_ATrackerBase_Statics; \
public: \
	DECLARE_CLASS(ATrackerBase, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VR360VidTemplate"), NO_API) \
	DECLARE_SERIALIZER(ATrackerBase)


#define VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_INCLASS \
private: \
	static void StaticRegisterNativesATrackerBase(); \
	friend struct Z_Construct_UClass_ATrackerBase_Statics; \
public: \
	DECLARE_CLASS(ATrackerBase, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VR360VidTemplate"), NO_API) \
	DECLARE_SERIALIZER(ATrackerBase)


#define VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATrackerBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATrackerBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrackerBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrackerBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrackerBase(ATrackerBase&&); \
	NO_API ATrackerBase(const ATrackerBase&); \
public:


#define VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrackerBase(ATrackerBase&&); \
	NO_API ATrackerBase(const ATrackerBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrackerBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrackerBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATrackerBase)


#define VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_PRIVATE_PROPERTY_OFFSET
#define VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_12_PROLOG
#define VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_PRIVATE_PROPERTY_OFFSET \
	VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_RPC_WRAPPERS \
	VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_INCLASS \
	VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_PRIVATE_PROPERTY_OFFSET \
	VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_INCLASS_NO_PURE_DECLS \
	VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VR360VIDTEMPLATE_API UClass* StaticClass<class ATrackerBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID VR360VidTemplate_Source_VR360VidTemplate_TrackerBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
