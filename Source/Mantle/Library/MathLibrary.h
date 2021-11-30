// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathLibrary.generated.h"

class UCapsuleComponent;
/**
 * 
 */
UCLASS()
class MANTLE_API UMathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Math Utils")
	static FVector GetCapsuleBaseLocation(float ZOffset, UCapsuleComponent* Capsule);

	UFUNCTION(BlueprintCallable, Category = "Math Utils")
	static FVector GetCapsuleLocationFromBase(float ZOffset, FVector BaseLocation, UCapsuleComponent* Capsule);

	UFUNCTION(BlueprintCallable, Category = "Math Utils")
	static bool CheckIfCapsuleHasRoom(UCapsuleComponent* Capsule, FVector TargetLocation, float radiusOffset, float HeightOffset);
};
