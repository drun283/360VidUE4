// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <chrono>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeTracker.generated.h"

UCLASS()
class VR360VIDTEMPLATE_API ATimeTracker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeTracker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Start();

	UFUNCTION(BlueprintCallable)
	void StartMotion();

	UFUNCTION(BlueprintCallable)
	void StopMotion();

	UPROPERTY(EditDefaultsOnly, Category = "Tracker")
	float TrackerTimeCorrection;

	UFUNCTION(BlueprintImplementableEvent)
	void InitRefs();

	UFUNCTION(BlueprintImplementableEvent)
	void DispatchTimeToTrackers(float time);

	UFUNCTION(BlueprintImplementableEvent)
	void StartMusic();

	UFUNCTION(BlueprintImplementableEvent)
	void StartSpider();

	UFUNCTION(BlueprintImplementableEvent)
	void StopMusic();

	UFUNCTION(BlueprintImplementableEvent)
	void StartStars();

	UFUNCTION(BlueprintImplementableEvent)
	void StopSpider();

	UFUNCTION(BlueprintImplementableEvent)
	void StartCredits();

	UPROPERTY(EditDefaultsOnly, Category = "Delays")
	float musicStartDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Delays")
	float spiderStartDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Delays")
	float musicStopDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Delays")
	float starsStartDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Delays")
	float spiderStopDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Delays")
	float creditsStartDelay;

private:

	bool bHasStarted = false;
	bool bTrackersMoving = false;

	float timeSinceStart = 0.0f;
	float timeForTrackers = 0.0f;
	std::chrono::time_point<std::chrono::system_clock> lastTimeStep;

	bool bHasMusicStarted = false;
	bool bHasSpiderStarted = false;
	bool bHasMusicStopped = false;
	bool bHasStarsStarted = false;
	bool bHasSpiderStopped = false;
	bool bHasCreditsStarted = false;
};
