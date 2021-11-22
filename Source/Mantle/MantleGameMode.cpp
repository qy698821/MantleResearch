// Copyright Epic Games, Inc. All Rights Reserved.

#include "MantleGameMode.h"
#include "MantleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMantleGameMode::AMantleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
