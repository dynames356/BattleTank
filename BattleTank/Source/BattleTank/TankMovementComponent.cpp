// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
	if (!LeftTrackToSet || !RightTrackToSet) {
		return;
	}

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
	if (!LeftTrack || !RightTrack) {
		return;
	}

	Throw = FMath::Clamp<float>(Throw, -1.0, 1.0);
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw) {
	//UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward throw: %f"), Throw);
	if (!LeftTrack || !RightTrack) {
		return;
	}

	Throw = FMath::Clamp<float>(Throw, -1.0, 1.0);
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}