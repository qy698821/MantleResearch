// Fill out your copyright notice in the Description page of Project Settings.


#include "MantleComponent.h"
#include "Mantle/MantleCharacter.h"

// Sets default values for this component's properties
UMantleComponent::UMantleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool UMantleComponent::MantleCheck(const FMantleTraceSettings& TraceSettings, EDrawDebugTrace::Type DebugType)
{
	return false;
}

void UMantleComponent::OnJumpInput()
{
	if (GEngine) 
	{
		GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("1111"));
	}
}

// Called when the game starts
void UMantleComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner()) 
	{
		OwnerCharacter = Cast<AMantleCharacter>(GetOwner());
		if (OwnerCharacter) 
		{
			AddTickPrerequisiteActor(OwnerCharacter);

			OwnerCharacter->JumpPressedDelegate.AddUniqueDynamic(this, &UMantleComponent::OnJumpInput);
		}
	}
	
}


// Called every frame
void UMantleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

