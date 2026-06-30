


#include "Z1_ManagerBase.h"


// Sets default values
AZ1_ManagerBase::AZ1_ManagerBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AZ1_ManagerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZ1_ManagerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

