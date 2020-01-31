// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FMODStudioEditor/Private/Sequencer/FMODChannelEditors.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFMODChannelEditors() {}
// Cross Module References
	FMODSTUDIOEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FFMODEventControlKeyStruct();
	UPackage* Z_Construct_UPackage__Script_FMODStudioEditor();
	MOVIESCENE_API UScriptStruct* Z_Construct_UScriptStruct_FMovieSceneKeyTimeStruct();
	FMODSTUDIO_API UEnum* Z_Construct_UEnum_FMODStudio_EFMODEventControlKey();
// End Cross Module References
class UScriptStruct* FFMODEventControlKeyStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FMODSTUDIOEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FFMODEventControlKeyStruct, Z_Construct_UPackage__Script_FMODStudioEditor(), TEXT("FMODEventControlKeyStruct"), sizeof(FFMODEventControlKeyStruct), Get_Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Hash());
	}
	return Singleton;
}
template<> FMODSTUDIOEDITOR_API UScriptStruct* StaticStruct<FFMODEventControlKeyStruct>()
{
	return FFMODEventControlKeyStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FFMODEventControlKeyStruct(FFMODEventControlKeyStruct::StaticStruct, TEXT("/Script/FMODStudioEditor"), TEXT("FMODEventControlKeyStruct"), false, nullptr, nullptr);
static struct FScriptStruct_FMODStudioEditor_StaticRegisterNativesFFMODEventControlKeyStruct
{
	FScriptStruct_FMODStudioEditor_StaticRegisterNativesFFMODEventControlKeyStruct()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("FMODEventControlKeyStruct")),new UScriptStruct::TCppStructOps<FFMODEventControlKeyStruct>);
	}
} ScriptStruct_FMODStudioEditor_StaticRegisterNativesFFMODEventControlKeyStruct;
	struct Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Value_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Sequencer/FMODChannelEditors.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFMODEventControlKeyStruct>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Key" },
		{ "ModuleRelativePath", "Private/Sequencer/FMODChannelEditors.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFMODEventControlKeyStruct, Value), Z_Construct_UEnum_FMODStudio_EFMODEventControlKey, METADATA_PARAMS(Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::NewProp_Value_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::NewProp_Value_Underlying,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FMODStudioEditor,
		Z_Construct_UScriptStruct_FMovieSceneKeyTimeStruct,
		&NewStructOps,
		"FMODEventControlKeyStruct",
		sizeof(FFMODEventControlKeyStruct),
		alignof(FFMODEventControlKeyStruct),
		Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FFMODEventControlKeyStruct()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FMODStudioEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("FMODEventControlKeyStruct"), sizeof(FFMODEventControlKeyStruct), Get_Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FFMODEventControlKeyStruct_Hash() { return 1705696007U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
