// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackerBase.h"


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

	if (bIsMoving) {
		CurrentTime += DeltaTime;

		if (bIsUsingPosition)
		{
			float y = PositionXCurve.Eval(CurrentTime);
			float p = PositionYCurve.Eval(CurrentTime);
			GLog->Log("yaw = " + FString::SanitizeFloat(y) + ", pitch = " + FString::SanitizeFloat(p));
			float yaw = y - 90 + HorizontalCorrection;
			float pitch = p + VerticalCorrection;
			Center->SetWorldRotation(FRotator(pitch, yaw, 0));
		}
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

}

void ATrackerBase::StartMovement()
{
	bIsMoving = true;
}

void ATrackerBase::InitalizeMovement()
{
	if (CurveTable == nullptr) {
		return;
	}

	if(!CurveTable->HasRichCurves())
	{
		return;
	}

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
		PointOnSphere->SetRelativeLocation(DefaultLocation);
	}

	else if (PropertyName == GET_MEMBER_NAME_CHECKED(ATrackerBase, CurveTable))
	{
		InitalizeMovement();
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

