// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Z1_ChannelBase.generated.h"


UCLASS(Blueprintable, ClassGroup=(Z1), meta=(BlueprintSpawnableComponent))
class LIOCORE_API UZ1_ChannelBase : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UZ1_ChannelBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
};
