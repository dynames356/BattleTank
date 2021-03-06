// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankTurret;
class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	void SetTurretReference(UTankTurret* TurretToSet);
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UTankTurret* Turret = nullptr;
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);
};
