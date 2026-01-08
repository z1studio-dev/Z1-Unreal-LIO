// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InputCoreTypes.h"
#include "LioInputInjector.generated.h"

/**
 * 
 */
class UEnhancedInputLocalPlayerSubsystem;
UCLASS(BlueprintType, Blueprintable)
class LIOCORE_API ULioInputInjector : public UObject
{
	GENERATED_BODY()
public:

public:
	/** Push via channel name -> builds key "LIO_<Channel>_Axis1D" */
	UFUNCTION(BlueprintCallable, Category="Lio|Input")
	void PushAxis1D_ByChannel(FName ChannelName, float Value);

	/** Push directly via a registered FKey */
	UFUNCTION(BlueprintCallable, Category="Lio|Input")
	void PushAxis1D_ByKey(FKey Key, float Value);

private:
	static FKey MakeAxis1DKeyFromChannel(FName ChannelName);
};
