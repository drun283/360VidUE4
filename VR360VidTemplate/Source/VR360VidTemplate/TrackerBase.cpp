// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackerBase.h"





// Sets default values
ATrackerBase::ATrackerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//initalizeCurves();
}



void ATrackerBase::initalizeCurves()
{
	//Rotation
	if (RotationRowHandle.IsValid("Trying to access Rotation row")) {
		FRichCurve* richCurve = RotationRowHandle.GetRichCurve("Trying to get rich curve from Rotation row");
		//richCurve->BakeCurve(60);
		float min;
		float max;
		richCurve->GetTimeRange(min, max);
		GLog->Log("~~~~~~~~~~~~~~~~~~~rich curve has min time of " + FString::SanitizeFloat(min) + " and max time of " + FString::SanitizeFloat(max));
		if (!RotationCurve) {
			RotationCurve = NewObject<UCurveFloat>();
		}
		auto curves = RotationCurve->GetCurves();
		//curves.Empty();
		curves.Add(FRichCurveEditInfo(richCurve, FName{ TEXT("RotationCurve") }));
		RotationCurve->GetTimeRange(min, max);
		GLog->Log("~~~~~~~~~~~~~~~~~~~float curve has min time of " + FString::SanitizeFloat(min) + " and max time of " + FString::SanitizeFloat(max));
	}
	else {
		GLog->Log("Rotation row is invalid");
	}
	//PositionX
	if (PositionXRowHandle.IsValid("Trying to access PositionX row")) {
		FRichCurve* richCurve = PositionXRowHandle.GetRichCurve("Trying to get rich curve from PositionX row");
		if (!PositionXCurve) {
			PositionXCurve = NewObject<UCurveFloat>();
		}
		TArray<FRichCurveEditInfo> curves = PositionXCurve->GetCurves();
		curves.Empty();
		curves.Add(FRichCurveEditInfo(richCurve, FName(TEXT("PositionXCurve"))));
	}
	else {
		GLog->Log("PositionX row is invalid");
	}
	//PositionY
	if (PositionYRowHandle.IsValid("Trying to access PositionY row")) {
		FRichCurve* richCurve = PositionYRowHandle.GetRichCurve("Trying to get rich curve from PositionY row");
		if (!PositionYCurve) {
			PositionYCurve = NewObject<UCurveFloat>();
		}
		TArray<FRichCurveEditInfo> curves = PositionYCurve->GetCurves();
		curves.Empty();
		curves.Add(FRichCurveEditInfo(richCurve, FName(TEXT("PositionYCurve"))));
	}
	else {
		GLog->Log("PositionY row is invalid");
	}
	//ScaleX
	if (ScaleXRowHandle.IsValid("Trying to access ScaleX row")) {
		FRichCurve* richCurve = ScaleXRowHandle.GetRichCurve("Trying to get rich curve from ScaleX row");
		if (!ScaleXCurve) {
			ScaleXCurve = NewObject<UCurveFloat>();
		}
		TArray<FRichCurveEditInfo> curves = ScaleXCurve->GetCurves();
		curves.Empty();
		curves.Add(FRichCurveEditInfo(richCurve, FName(TEXT("ScaleXCurve"))));
	}
	else {
		GLog->Log("ScaleX row is invalid");
	}
	//ScaleY
	if (ScaleYRowHandle.IsValid("Trying to access ScaleY row")) {
		FRichCurve* richCurve = ScaleYRowHandle.GetRichCurve("Trying to get rich curve from ScaleY row");
		if (!ScaleYCurve) {
			ScaleYCurve = NewObject<UCurveFloat>();
		}
		TArray<FRichCurveEditInfo> curves = ScaleYCurve->GetCurves();
		curves.Empty();
		curves.Add(FRichCurveEditInfo(richCurve, FName(TEXT("ScaleYCurve"))));
	}
	else {
		GLog->Log("ScaleY row is invalid");
	}
	//ScaleZ
	if (ScaleZRowHandle.IsValid("Trying to access ScaleZ row")) {
		FRichCurve* richCurve = ScaleZRowHandle.GetRichCurve("Trying to get rich curve from ScaleZ row");
		if (!ScaleZCurve) {
			ScaleZCurve = NewObject<UCurveFloat>();
		}
		TArray<FRichCurveEditInfo> curves = ScaleZCurve->GetCurves();
		curves.Empty();
		curves.Add(FRichCurveEditInfo(richCurve, FName(TEXT("ScaleZCurve"))));
	}
	else {
		GLog->Log("ScaleZ row is invalid");
	}
}
