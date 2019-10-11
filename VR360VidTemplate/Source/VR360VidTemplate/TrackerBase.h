// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/CurveTable.h"
#include "Curves\CurveFloat.h"
#include "TrackerBase.generated.h"


UCLASS(Blueprintable)
class VR360VIDTEMPLATE_API ATrackerBase : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	ATrackerBase();


	
	UPROPERTY(BlueprintReadOnly, Category = "Tracker")
	UCurveFloat* XDeg;
	UPROPERTY(BlueprintReadOnly, Category = "Tracker")
	UCurveFloat* YDeg;
	UPROPERTY(BlueprintReadOnly, Category = "Tracker")
	UCurveFloat* ZDeg;
	UPROPERTY(BlueprintReadOnly, Category = "Tracker")
	UCurveFloat* Scale;

	
	UPROPERTY(EditAnywhere, Category = "Tracker")
	FCurveTableRowHandle XDegRowHandle;

	UPROPERTY(EditAnywhere, Category = "Tracker")
	FCurveTableRowHandle YDegRowHandle;

	UPROPERTY(EditAnywhere, Category = "Tracker")
	FCurveTableRowHandle ZDegRowHandle;

	UPROPERTY(EditAnywhere, Category = "Tracker")
	FCurveTableRowHandle ScaleRowHandle;

	UFUNCTION(BlueprintCallable)
	void initalizeCurves();	


};
