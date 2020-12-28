// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackerBase.h"
#include <chrono>
#include <ctime>    


ATrackerBase::ATrackerBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Center = CreateDefaultSubobject<USceneComponent>("Center");
	PointOnSphere = CreateDefaultSubobject<USceneComponent>("PointOnSphere");
	RotatingStuff = CreateDefaultSubobject<USceneComponent>("RotatingStuff");
	NonRotatingStuff = CreateDefaultSubobject<USceneComponent>("NonRotatingStuff");
	Center->SetWorldTransform(this->GetTransform());
	PointOnSphere->SetWorldTransform(this->GetTransform());
	RotatingStuff->SetWorldTransform(this->GetTransform());
	NonRotatingStuff->SetWorldTransform(this->GetTransform());

	if (RootComponent)
	{
		Center->SetupAttachment(RootComponent);
	}
	else
	{
		RootComponent = Center;
	}
	PointOnSphere->SetupAttachment(Center);
	RotatingStuff->SetupAttachment(PointOnSphere);
	NonRotatingStuff->SetupAttachment(PointOnSphere);


	PointOnSphere->SetRelativeLocation(DefaultLocation);
	PointOnSphere->SetRelativeRotation(FRotator(0.0, 90, 0.0));

	InitalizeMovement();
}



void ATrackerBase::Tick(float DeltaTime)
{
	/*
	static std::chrono::time_point<std::chrono::system_clock> last;
	static bool first = true;
	if (first) {
		first = false;
		last = std::chrono::system_clock::now();
		GLog->Log("start");
	}
	auto now = std::chrono::system_clock::now();
	
	std::chrono::duration<double> delta = now - last;
	last = now;
	

	if (bIsMoving) {



		CurrentTime += delta.count();
		GLog->Log("time: " + FString::SanitizeFloat(CurrentTime) + ", delta: " + FString::SanitizeFloat(delta.count()) + ", DeltaTime: " + FString::SanitizeFloat(DeltaTime));

		if (bIsUsingPosition)
		{
			float y = PositionXCurve.Eval(CurrentTime);
			float p = PositionYCurve.Eval(CurrentTime);
			//GLog->Log("yaw = " + FString::SanitizeFloat(y) + ", pitch = " + FString::SanitizeFloat(p));
			Center->SetWorldRotation(FRotator(p + VerticalCorrection, y + HorizontalCorrection, 0));
		}
		 // Not being used
		if (bIsUsingScale)
		{
			float scaleX = ScaleXCurve.Eval(CurrentTime);
			float scaleY = ScaleYCurve.Eval(CurrentTime);
			PointOnSphere->SetRelativeScale3D(FVector(scaleX, 1.0, scaleY));
		}
		if (bIsUsingRotation)
		{
			float rot = RotationCurve.Eval(CurrentTime);
			RotatingStuff->SetRelativeRotation(FRotator(rot, 0.0, 0.0));
		}
		
	}
	*/
}

void ATrackerBase::SetTransformToTime(float time)
{
	if (bIsUsingPosition)
	{
		float y = PositionXCurve.Eval(time);
		float p = PositionYCurve.Eval(time);
		//GLog->Log("yaw = " + FString::SanitizeFloat(y) + ", pitch = " + FString::SanitizeFloat(p));
		Center->SetWorldRotation(FRotator(p + VerticalCorrection, y + HorizontalCorrection, 0));
	}
	/* // Not being used
	if (bIsUsingScale)
	{
		float scaleX = ScaleXCurve.Eval(time);
		float scaleY = ScaleYCurve.Eval(time);
		PointOnSphere->SetRelativeScale3D(FVector(scaleX, 1.0, scaleY));
	}
	if (bIsUsingRotation)
	{
		float rot = RotationCurve.Eval(time);
		RotatingStuff->SetRelativeRotation(FRotator(rot, 0.0, 0.0));
	}
	*/
}

void ATrackerBase::StartMovement()
{
	//GLog->Log(this->GetDebugName(this) + " has started movement");
	//bIsMoving = true;
	//CurrentTime = TimeCorrection;
}

void ATrackerBase::InitalizeMovement()
{
	if (CurveTable == nullptr) {
		//GLog->Log(this->GetDebugName(this) + ": null table");
		return;
	}

	if(!CurveTable->HasRichCurves())
	{
		//GLog->Log(this->GetDebugName(this) + ": does not have rich curves");
		return;
	}

	//GLog->Log(this->GetDebugName(this));
	//for (auto c : CurveTable->GetCurves()) {
	//	GLog->Log(c.CurveName.ToString());
	//}

	ScaleXCurve = *CurveTable->FindRichCurve("ScaleX", "trying to get scale x");
	ScaleYCurve = *CurveTable->FindRichCurve("ScaleY", "trying to get scale y");
	PositionXCurve = *CurveTable->FindRichCurve("PositionX", "trying to get position x");
	PositionYCurve = *CurveTable->FindRichCurve("PositionY", "trying to get position y");
	RotationCurve = *CurveTable->FindRichCurve("Rotation", "trying to get rotation");
}

#if WITH_EDITOR
void ATrackerBase::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	if (PropertyName == "X" || PropertyName == "Y" || PropertyName == "Z" || PropertyName == "DefaultLocation")
	{
		GLog->Log("Updating default location for " + this->GetName());
		PointOnSphere->SetRelativeLocation(DefaultLocation);
	}

	else if (PropertyName == GET_MEMBER_NAME_CHECKED(ATrackerBase, CurveTable))
	{
		GLog->Log("Updating curve table for " + this->GetName());
		InitalizeMovement();
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

