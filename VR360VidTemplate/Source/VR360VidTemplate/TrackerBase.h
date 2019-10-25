// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/CurveTable.h"
#include "Curves/CurveFloat.h"
#include "TrackerBase.generated.h"


UCLASS(Blueprintable)
class VR360VIDTEMPLATE_API ATrackerBase : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	ATrackerBase();


	
	UPROPERTY(BlueprintReadOnly, Category = "Tracker")
	UCurveFloat* RotationCurve;
	UPROPERTY(BlueprintReadOnly, Category = "Tracker")
	UCurveFloat* PositionXCurve;
	UPROPERTY(BlueprintReadOnly, Category = "Tracker")
	UCurveFloat* PositionYCurve;
	UPROPERTY(BlueprintReadOnly, Category = "Tracker")
	UCurveFloat* ScaleXCurve;
	UPROPERTY(BlueprintReadOnly, Category = "Tracker")
	UCurveFloat* ScaleYCurve;
	UPROPERTY(BlueprintReadOnly, Category = "Tracker")
	UCurveFloat* ScaleZCurve;

	UPROPERTY(EditAnywhere, Category = "Tracker")
	FCurveTableRowHandle RotationRowHandle;

	UPROPERTY(EditAnywhere, Category = "Tracker")
	FCurveTableRowHandle PositionXRowHandle;

	UPROPERTY(EditAnywhere, Category = "Tracker")
	FCurveTableRowHandle PositionYRowHandle;

	UPROPERTY(EditAnywhere, Category = "Tracker")
	FCurveTableRowHandle ScaleXRowHandle;

	UPROPERTY(EditAnywhere, Category = "Tracker")
	FCurveTableRowHandle ScaleYRowHandle;

	UPROPERTY(EditAnywhere, Category = "Tracker")
	FCurveTableRowHandle ScaleZRowHandle;

	UFUNCTION(BlueprintCallable)
	void initalizeCurves();	


};
