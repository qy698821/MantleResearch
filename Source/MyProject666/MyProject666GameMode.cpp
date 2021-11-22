// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProject666GameMode.h"
#include "MyProject666Character.h"
#include "UObject/ConstructorHelpers.h"

AMyProject666GameMode::AMyProject666GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
