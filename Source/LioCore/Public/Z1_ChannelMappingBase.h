// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Z1_ChannelMappingBase.generated.h"

class AZ1_ManagerBase;
class UZ1_ChannelBase;
UCLASS(Blueprintable, ClassGroup=(Z1), meta=(BlueprintSpawnableComponent) )
class LIOCORE_API UZ1_ChannelMappingBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UZ1_ChannelMappingBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UFUNCTION()
	AZ1_ManagerBase* GetManager() const;
	
	UPROPERTY(BlueprintReadOnly, Category ="Core")
	AZ1_ManagerBase* ManagerRef;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Channel")
	FString ChannelNameRef;
	

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "")
	UZ1_ChannelBase* ChannelRef;
};
