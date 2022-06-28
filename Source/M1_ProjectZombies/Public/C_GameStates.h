// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "C_GameStates.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum EGameStates 
{
	GAME_START_MENU	UMETA(DisplayName = "Game Start Menu"),
	GAME_IN_ROUND	UMETA(DisplayName = "Game In Round"),
	GAME_OVER		UMETA(DisplayName = "Game Over"),
	GAME_WIN		UMETA(DisplayName = "Game Win"),
	GAME_PAUSED		UMETA(DisplayName = "Game Paused"),
	GAME_TUTORIAL	UMETA(DisplayName = "Game Tutorial"),
	GAME_CREDITS	UMETA(DisplayName = "Game Credits")
};