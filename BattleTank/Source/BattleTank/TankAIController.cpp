// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possesing a Tank"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possesing: %s"), *ControlledTank->GetName());
	}

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller could not find Player Tank"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found Player Tank: %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	AimTowardsPlayer();
}


ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::AimTowardsPlayer() {
	if (!GetControlledTank()) { return; }
	if (!GetPlayerTank()) { return; }

	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}
