// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/CurveTable.h"
#include "Components/SceneComponent.h"
#include "MediaAssets/Public/MediaPlayer.h"
#include "TrackerBase.generated.h"


UCLASS(Blueprintable)
class VR360VIDTEMPLATE_API ATrackerBase : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	ATrackerBase();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Tracker")
	UCurveTable* CurveTable;

	UFUNCTION(BlueprintCallable)
	void StartMovement();

	UPROPERTY()
	USceneComponent* Center;

	UPROPERTY()
	USceneComponent* PointOnSphere;

	UPROPERTY()
	USceneComponent* RotatingStuff;

	UPROPERTY()
	USceneComponent* NonRotatingStuff;

	UPROPERTY(EditDefaultsOnly)
	FVector DefaultLocation;

	UPROPERTY(EditDefaultsOnly)
	FRotator DefaultRotation;
	   	
	
private:
	UPROPERTY()
	FRealCurve ScaleXCurve;
	UPROPERTY()
	FRealCurve ScaleYCurve;
	UPROPERTY()
	FRealCurve ScaleZCurve;
	UPROPERTY()
	FRealCurve PositionXCurve;
	UPROPERTY()
	FRealCurve PositionYCurve;
	UPROPERTY()
	FRealCurve RotationCurve;
	
	UFUNCTION()
	void InitalizeMovement();


	float CurrentTime = 0;
	bool bIsMoving = false;
};
