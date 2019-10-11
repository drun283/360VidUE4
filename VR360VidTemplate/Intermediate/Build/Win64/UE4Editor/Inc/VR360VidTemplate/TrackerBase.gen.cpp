// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VR360VidTemplate/TrackerBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTrackerBase() {}
// Cross Module References
	VR360VIDTEMPLATE_API UClass* Z_Construct_UClass_ATrackerBase_NoRegister();
	VR360VIDTEMPLATE_API UClass* Z_Construct_UClass_ATrackerBase();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_VR360VidTemplate();
	VR360VIDTEMPLATE_API UFunction* Z_Construct_UFunction_ATrackerBase_initalizeCurves();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FCurveTableRowHandle();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
// End Cross Module References
	void ATrackerBase::StaticRegisterNativesATrackerBase()
	{
		UClass* Class = ATrackerBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "initalizeCurves", &ATrackerBase::execinitalizeCurves },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATrackerBase_initalizeCurves_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATrackerBase_initalizeCurves_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TrackerBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATrackerBase_initalizeCurves_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATrackerBase, nullptr, "initalizeCurves", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATrackerBase_initalizeCurves_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATrackerBase_initalizeCurves_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATrackerBase_initalizeCurves()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATrackerBase_initalizeCurves_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATrackerBase_NoRegister()
	{
		return ATrackerBase::StaticClass();
	}
	struct Z_Construct_UClass_ATrackerBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScaleRowHandle_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ScaleRowHandle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ZDegRowHandle_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ZDegRowHandle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_YDegRowHandle_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_YDegRowHandle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_XDegRowHandle_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_XDegRowHandle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Scale;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ZDeg_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ZDeg;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_YDeg_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_YDeg;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_XDeg_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_XDeg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATrackerBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VR360VidTemplate,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATrackerBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATrackerBase_initalizeCurves, "initalizeCurves" }, // 3183405910
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrackerBase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "TrackerBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "TrackerBase.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrackerBase_Statics::NewProp_ScaleRowHandle_MetaData[] = {
		{ "Category", "Tracker" },
		{ "ModuleRelativePath", "TrackerBase.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATrackerBase_Statics::NewProp_ScaleRowHandle = { "ScaleRowHandle", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrackerBase, ScaleRowHandle), Z_Construct_UScriptStruct_FCurveTableRowHandle, METADATA_PARAMS(Z_Construct_UClass_ATrackerBase_Statics::NewProp_ScaleRowHandle_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrackerBase_Statics::NewProp_ScaleRowHandle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrackerBase_Statics::NewProp_ZDegRowHandle_MetaData[] = {
		{ "Category", "Tracker" },
		{ "ModuleRelativePath", "TrackerBase.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATrackerBase_Statics::NewProp_ZDegRowHandle = { "ZDegRowHandle", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrackerBase, ZDegRowHandle), Z_Construct_UScriptStruct_FCurveTableRowHandle, METADATA_PARAMS(Z_Construct_UClass_ATrackerBase_Statics::NewProp_ZDegRowHandle_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrackerBase_Statics::NewProp_ZDegRowHandle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrackerBase_Statics::NewProp_YDegRowHandle_MetaData[] = {
		{ "Category", "Tracker" },
		{ "ModuleRelativePath", "TrackerBase.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATrackerBase_Statics::NewProp_YDegRowHandle = { "YDegRowHandle", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrackerBase, YDegRowHandle), Z_Construct_UScriptStruct_FCurveTableRowHandle, METADATA_PARAMS(Z_Construct_UClass_ATrackerBase_Statics::NewProp_YDegRowHandle_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrackerBase_Statics::NewProp_YDegRowHandle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrackerBase_Statics::NewProp_XDegRowHandle_MetaData[] = {
		{ "Category", "Tracker" },
		{ "ModuleRelativePath", "TrackerBase.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATrackerBase_Statics::NewProp_XDegRowHandle = { "XDegRowHandle", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrackerBase, XDegRowHandle), Z_Construct_UScriptStruct_FCurveTableRowHandle, METADATA_PARAMS(Z_Construct_UClass_ATrackerBase_Statics::NewProp_XDegRowHandle_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrackerBase_Statics::NewProp_XDegRowHandle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrackerBase_Statics::NewProp_Scale_MetaData[] = {
		{ "Category", "Tracker" },
		{ "ModuleRelativePath", "TrackerBase.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATrackerBase_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrackerBase, Scale), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATrackerBase_Statics::NewProp_Scale_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrackerBase_Statics::NewProp_Scale_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrackerBase_Statics::NewProp_ZDeg_MetaData[] = {
		{ "Category", "Tracker" },
		{ "ModuleRelativePath", "TrackerBase.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATrackerBase_Statics::NewProp_ZDeg = { "ZDeg", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrackerBase, ZDeg), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATrackerBase_Statics::NewProp_ZDeg_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrackerBase_Statics::NewProp_ZDeg_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrackerBase_Statics::NewProp_YDeg_MetaData[] = {
		{ "Category", "Tracker" },
		{ "ModuleRelativePath", "TrackerBase.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATrackerBase_Statics::NewProp_YDeg = { "YDeg", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrackerBase, YDeg), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATrackerBase_Statics::NewProp_YDeg_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrackerBase_Statics::NewProp_YDeg_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrackerBase_Statics::NewProp_XDeg_MetaData[] = {
		{ "Category", "Tracker" },
		{ "ModuleRelativePath", "TrackerBase.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATrackerBase_Statics::NewProp_XDeg = { "XDeg", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrackerBase, XDeg), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATrackerBase_Statics::NewProp_XDeg_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrackerBase_Statics::NewProp_XDeg_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATrackerBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrackerBase_Statics::NewProp_ScaleRowHandle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrackerBase_Statics::NewProp_ZDegRowHandle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrackerBase_Statics::NewProp_YDegRowHandle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrackerBase_Statics::NewProp_XDegRowHandle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrackerBase_Statics::NewProp_Scale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrackerBase_Statics::NewProp_ZDeg,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrackerBase_Statics::NewProp_YDeg,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrackerBase_Statics::NewProp_XDeg,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATrackerBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATrackerBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATrackerBase_Statics::ClassParams = {
		&ATrackerBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATrackerBase_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_ATrackerBase_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_ATrackerBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATrackerBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATrackerBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATrackerBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATrackerBase, 1266052124);
	template<> VR360VIDTEMPLATE_API UClass* StaticClass<ATrackerBase>()
	{
		return ATrackerBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATrackerBase(Z_Construct_UClass_ATrackerBase, &ATrackerBase::StaticClass, TEXT("/Script/VR360VidTemplate"), TEXT("ATrackerBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATrackerBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
