// Fill out your copyright notice in the Description page of Project Settings.


#include "LioInputInjector.h"
#include "LioCore.h"
#include "FLioInputDevice.h"
#define LOCTEXT_NAMESPACE "FLioCoreModule"

void ULioInputInjector::PushAxis1D_ByChannel(FName ChannelName, float Value)
{
	const FKey Key = MakeAxis1DKeyFromChannel(ChannelName); //prepend LIO et append type
	const FName MenuCat   = FName(TEXT("Lio|Input"));
	const FText CatLabel  = LOCTEXT("LioInputCategory", "Lio | Input");

	// Exemple : 4 LFO (ajoute / renomme comme tu veux)
	RegisterAxis1DKeyIfNeeded(Key, LOCTEXT("LioLFO1", "Lio LFO1 Axis1D"), MenuCat, CatLabel);

	PushAxis1D_ByKey(Key, Value);
}

void ULioInputInjector::PushAxis1D_ByKey(FKey Key, float Value)
{
	if (!EKeys::GetKeyDetails(Key).IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Lio: Key %s is not registered."), *Key.ToString());
		return;
	}

	if (FLioInputDevice* Dev = FLioCoreModule::GetDevice())
	{
		Dev->PushAnalog(Key, Value);
	}
}

FKey ULioInputInjector::MakeAxis1DKeyFromChannel(FName ChannelName)
{
	return FKey(FName(*FString::Printf(TEXT("LIO_%s_Axis1D"), *ChannelName.ToString())));
}
