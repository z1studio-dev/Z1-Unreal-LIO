#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Z1_ManagerBase.generated.h"

UCLASS(Blueprintable, ClassGroup=(Z1))
class LIOCORE_API AZ1_ManagerBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AZ1_ManagerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
