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
	PointOnSphere->SetRelativeRotation(DefaultRotation);



	InitalizeMovement();

}



void ATrackerBase::Tick(float DeltaTime)
{

	if (bIsMoving) {
		CurrentTime += DeltaTime;

		//get scale and convert from full being 100.0 to full being 1.0
		float scaleX = ScaleXCurve.Eval(CurrentTime) / 100.0;
		float scaleY = ScaleYCurve.Eval(CurrentTime) / 100.0;
		float scaleZ = ScaleZCurve.Eval(CurrentTime) / 100.0;
		//get position and convert location to deg
		float posX = PositionXCurve.Eval(CurrentTime);
		float posY = PositionYCurve.Eval(CurrentTime);
		//get rotation and convert
		float rot = RotationCurve.Eval(CurrentTime);

		Center->SetWorldRotation(FRotator(posY, posX, 0));
		//PointOnSphere->SetRelativeScale3D(FVector(scaleX, scaleY, scaleZ));
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
	ScaleZCurve = *CurveTable->FindRichCurve("ScaleZ", "trying to get scale z");
	PositionXCurve = *CurveTable->FindRichCurve("PositionX", "trying to get position x");
	PositionYCurve = *CurveTable->FindRichCurve("PositionY", "trying to get position y");
	RotationCurve = *CurveTable->FindRichCurve("Rotation", "trying to get rotation");


	/*
	TArray<FRichCurveEditInfo> curves = CurveTable->GetCurves();

	ScaleXCurve = *curves[0].CurveToEdit;
	ScaleYCurve = *curves[1].CurveToEdit;
	ScaleZCurve = *curves[2].CurveToEdit;
	PositionXCurve = *curves[3].CurveToEdit;
	PositionYCurve = *curves[4].CurveToEdit;
	RotationCurve = *curves[5].CurveToEdit;
	*/

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
		PointOnSphere->SetRelativeRotation(DefaultRotation);

	}
	else if (PropertyName == "Roll" || PropertyName == "Pitch" || PropertyName == "Yaw" || PropertyName == "DefaultRotation")
	{
		GLog->Log("Resetting point on sphere location after value change");
		PointOnSphere->SetRelativeLocation(DefaultLocation);
		PointOnSphere->SetRelativeRotation(DefaultRotation);

	}
	else if (PropertyName == GET_MEMBER_NAME_CHECKED(ATrackerBase, CurveTable))
	{
		GLog->Log("Resetting curves after table change");
		InitalizeMovement();
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

