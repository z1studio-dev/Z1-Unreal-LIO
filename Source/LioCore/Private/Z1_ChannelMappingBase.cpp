// Fill out your copyright notice in the Description page of Project Settings.


#include "Z1_ChannelMappingBase.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UZ1_ChannelMappingBase::UZ1_ChannelMappingBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UZ1_ChannelMappingBase::BeginPlay()
{
	Super::BeginPlay();

	ManagerRef = GetManager();
	if (!ensureMsgf(ManagerRef, TEXT("Failed to get manager")))
	{
		return;
	}
	
}

AZ1_ManagerBase* UZ1_ChannelMappingBase::GetManager() const
{
	if (!GetWorld()) return nullptr;
	
	return Cast<AZ1_ManagerBase>(UGameplayStatics::GetActorOfClass(GetWorld(), AZ1_ManagerBase::StaticClass()));
}

// Called every frame
void UZ1_ChannelMappingBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

