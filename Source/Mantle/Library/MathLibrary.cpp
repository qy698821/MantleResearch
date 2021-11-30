// Fill out your copyright notice in the Description page of Project Settings.


#include "Mantle/Library/MathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/CapsuleComponent.h"

FVector UMathLibrary::GetCapsuleBaseLocation(float ZOffset, UCapsuleComponent* Capsule)
{
	return Capsule->GetComponentLocation() - Capsule->GetUpVector() * (Capsule->GetScaledCapsuleHalfHeight() + ZOffset);
}

FVector UMathLibrary::GetCapsuleLocationFromBase(float ZOffset, FVector BaseLocation, UCapsuleComponent* Capsule)
{
	return BaseLocation + Capsule->GetScaledCapsuleHalfHeight() + ZOffset;
}

bool UMathLibrary::CheckIfCapsuleHasRoom(UCapsuleComponent* Capsule, FVector TargetLocation, float RadiusOffset, float HeightOffset)
{
	const float ZTarget = Capsule->GetScaledCapsuleHalfHeight_WithoutHemisphere() - RadiusOffset + HeightOffset;
	FVector TraceStart = TargetLocation;
	TraceStart.Z += ZTarget;
	FVector TraceEnd = TargetLocation;
	TraceEnd.Z -= ZTarget;
	const float Radius = Capsule->GetScaledCapsuleRadius() + RadiusOffset;

	const UWorld* World = Capsule->GetWorld();
	check(World);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(Capsule->GetOwner());
	Params.bDebugQuery = true;
	FHitResult HitResult;
	FCollisionShape SphereCollisionShape = FCollisionShape::MakeSphere(Radius);

	bool bHit = World->SweepSingleByChannel(HitResult, TraceStart, TraceEnd, FQuat::Identity,
		ECollisionChannel::ECC_Visibility, SphereCollisionShape, Params);

	return !(HitResult.bBlockingHit || HitResult.bStartPenetrating);
}
