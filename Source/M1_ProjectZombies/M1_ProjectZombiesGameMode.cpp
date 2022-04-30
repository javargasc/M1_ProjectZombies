// Copyright Epic Games, Inc. All Rights Reserved.

#include "M1_ProjectZombiesGameMode.h"
#include "M1_ProjectZombiesHUD.h"
#include "M1_ProjectZombiesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AM1_ProjectZombiesGameMode::AM1_ProjectZombiesGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AM1_ProjectZombiesHUD::StaticClass();
}
