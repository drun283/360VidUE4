// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/CurveTable.h"
#include "Components/SceneComponent.h"
#include "Runtime/CoreUObject/Public/UObject/UnrealType.h"
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

	UPROPERTY(BlueprintReadOnly)
	USceneComponent* PointOnSphere;

	UPROPERTY()
	USceneComponent* RotatingStuff;

	UPROPERTY()
	USceneComponent* NonRotatingStuff;


	UPROPERTY(EditDefaultsOnly, Category = "Tracker")
	FVector DefaultLocation;

	UPROPERTY(EditDefaultsOnly, Category = "Tracker")
	bool bIsUsingPosition = true;

	UPROPERTY(EditDefaultsOnly, Category = "Tracker")
	bool bIsUsingScale = false;

	UPROPERTY(EditDefaultsOnly, Category = "Tracker")
	bool bIsUsingRotation = false;
	   	
	UPROPERTY(EditDefaultsOnly, Category = "Tracker")
	float VerticalCorrection;

	UPROPERTY(EditDefaultsOnly, Category = "Tracker")
	float HorizontalCorrection;

	UPROPERTY(EditDefaultsOnly, Category = "Tracker")
	float TimeCorrection;
	
private:
	UPROPERTY()
	FRichCurve ScaleXCurve;
	UPROPERTY()
	FRichCurve ScaleYCurve;
	UPROPERTY()
	FRichCurve PositionXCurve;
	UPROPERTY()
	FRichCurve PositionYCurve;
	UPROPERTY()
	FRichCurve RotationCurve;
	
	UFUNCTION()
	void InitalizeMovement();

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	float CurrentTime = 0;
	bool bIsMoving = false;
};
