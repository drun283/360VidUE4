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

	//Center->SetRelativeRotation(FRotator(0.0, -90, 0.0));

	PointOnSphere->SetRelativeLocation(DefaultLocation);
	PointOnSphere->SetRelativeRotation(FRotator(0.0, 90, 0.0));

	InitalizeMovement();
}



void ATrackerBase::Tick(float DeltaTime)
{

	if (bIsMoving) {
		CurrentTime += DeltaTime;

		float scaleX = ScaleXCurve.Eval(CurrentTime);
		float scaleY = ScaleYCurve.Eval(CurrentTime);
		float yaw = PositionXCurve.Eval(CurrentTime) + 90.0;
		float pitch = PositionYCurve.Eval(CurrentTime);
		float rot = RotationCurve.Eval(CurrentTime);

		Center->SetWorldRotation(FRotator(pitch, yaw, 0));
		//PointOnSphere->SetRelativeScale3D(FVector(scaleX, 1.0, scaleY));
		//RotatingStuff->SetRelativeRotation(FRotator(rot, 0.0, 0.0));
	}

}

void ATrackerBase::StartMovement()
{
	bIsMoving = true;
}

void ATrackerBase::InitalizeMovement()
{
	GLog->Log("Trying to initalize movement");
	if (CurveTable == nullptr) {
		GLog->Log("ERROR: null table");
		return;
	}

	if(!CurveTable->HasRichCurves())
	{
		GLog->Log("ERROR: table doesn't have rich curves");
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
	GLog->Log(PropertyName.ToString() + " changed");
	if (PropertyName == "X" || PropertyName == "Y" || PropertyName == "Z" || PropertyName == "DefaultLocation")
	{
		GLog->Log("Resetting point on sphere distance after value change");
		PointOnSphere->SetRelativeLocation(DefaultLocation);
	}

	else if (PropertyName == GET_MEMBER_NAME_CHECKED(ATrackerBase, CurveTable))
	{
		GLog->Log("Resetting curves after table change");
		InitalizeMovement();
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

