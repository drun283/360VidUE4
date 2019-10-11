// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackerBase.h"




// Sets default values
ATrackerBase::ATrackerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//initalizeCurves();
}



void ATrackerBase::initalizeCurves()
{
	try {
		if (XDegRowHandle.IsValid("")) {
			GLog->Log("Getting Rich Curve from X handle");
			XDeg = XDegRowHandle.GetCurve("");
		}
		else { GLog->Log("Error populating x curve"); }
		if (YDegRowHandle.IsValid("")) {
			//YDeg->FloatCurve = *YDegRowHandle.GetSimpleCurve("");
		}
		else { GLog->Log("Error populating y curve"); }
		if (ZDegRowHandle.IsValid("")) {
			//ZDeg->FloatCurve = *ZDegRowHandle.GetSimpleCurve("");
		}
		else { GLog->Log("Error populating x curve"); }		
		if (ScaleRowHandle.IsValid("")) {
			//Scale->FloatCurve = *ScaleRowHandle.GetSimpleCurve("");
		}
		else { GLog->Log("Error populating scale curve"); }

	}
	catch (...)
	{
		GLog->Log("ERROR initalizing curves");
	}
}
