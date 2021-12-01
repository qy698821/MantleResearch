#pragma once
#include "CoreMinimal.h"
#include "CharacterStructLibrary.generated.h"

USTRUCT(BlueprintType)
struct FMantleTraceSettings
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = "Mantle System")
		float MaxLedgeHeight = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Mantle System")
		float MinLedgeHeight = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Mantle System")
		float ReachDistance = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Mantle System")
		float ForwardTraceRadius = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Mantle System")
		float DownwardTraceRadius = 0.0f;
};