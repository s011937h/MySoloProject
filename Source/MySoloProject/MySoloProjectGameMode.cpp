// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MySoloProjectGameMode.h"
#include "MySoloProjectHUD.h"
#include "MySoloProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMySoloProjectGameMode::AMySoloProjectGameMode(): Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMySoloProjectHUD::StaticClass();
}

