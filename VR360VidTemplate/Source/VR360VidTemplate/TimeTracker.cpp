// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeTracker.h"


#define NOW std::chrono::system_clock::now

// Sets default values
ATimeTracker::ATimeTracker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimeTracker::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimeTracker::Tick(float DeltaTime)
{
	if (bHasStarted) {
		auto now = std::chrono::system_clock::now();

		std::chrono::duration<double> deltaTime = now - lastTimeStep;
		lastTimeStep = now;
		
		float delta = deltaTime.count();

		timeSinceStart += delta;

		if (bTrackersMoving)
		{
			timeForTrackers += delta;
			//GLog->Log("Tracker time: " + FString::SanitizeFloat(currentTime));
			DispatchTimeToTrackers(timeForTrackers);
		}

		if (!bHasMusicStarted)
		{
			if (timeSinceStart > musicStartDelay)
			{
				GLog->Log("Start Music");
				bHasMusicStarted = true;
				StartMusic();
			}
		}
		else if (!bHasSpiderStarted)
		{
			if (timeSinceStart > spiderStartDelay)
			{
				GLog->Log("Start Spider");
				bHasSpiderStarted = true;
				StartSpider();
			}
		}
		else if (!bHasMusicStopped)
		{
			if (timeSinceStart > musicStopDelay)
			{
				GLog->Log("Stop Music");
				bHasMusicStopped = true;
				StopMusic();
			}
		}
		else if (!bHasStarsStarted)
		{
			if (timeSinceStart > starsStartDelay)
			{
				GLog->Log("Start Stars");
				bHasStarsStarted = true;
				StartStars();
			}
		}
		else if (!bHasSpiderStopped)
		{
			if (timeSinceStart > spiderStopDelay)
			{
				GLog->Log("Stop Spider");
				bHasSpiderStopped = true;
				StopSpider();
			}
		}
		else if (!bHasCreditsStarted)
		{
			if (timeSinceStart > creditsStartDelay)
			{
				GLog->Log("Start Credits");
				bHasCreditsStarted = true;
				StartCredits();
			}
		}

	}
}

void ATimeTracker::Start()
{
	lastTimeStep = NOW();

	InitRefs();
	bHasStarted = true;
}

void ATimeTracker::StartMotion()
{
	timeForTrackers = TrackerTimeCorrection;
	bTrackersMoving = true;
}

void ATimeTracker::StopMotion()
{
	bTrackersMoving = false;
}

