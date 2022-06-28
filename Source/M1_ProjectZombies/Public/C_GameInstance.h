// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "C_GameStates.h"
#include "Engine/GameInstance.h"
#include "C_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class M1_PROJECTZOMBIES_API UC_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UC_GameInstance();

	UPROPERTY(EditAnywhere)
		int PlayerKillsCount = 0;

	UPROPERTY(EditAnywhere)
		int KillToWin = 1;

	UPROPERTY(EditAnywhere)
		int PlayerDeaths = 0;

	UPROPERTY(EditAnywhere)
		TEnumAsByte<EGameStates> GameState = EGameStates::GAME_START_MENU;

	UFUNCTION(BlueprintCallable)
		void SetGameOver();

	UFUNCTION(BlueprintCallable)
		void SetGameStartMenu();

	UFUNCTION(BlueprintCallable)
		void SetGameTutorial();

	UFUNCTION(BlueprintCallable)
		void SetGameCredits();

	UFUNCTION(BlueprintCallable)
		void SetGameOn();

	UFUNCTION(BlueprintCallable)
		void SetGameWin();

	UFUNCTION(BlueprintCallable)
		void SetGamePause();

	UFUNCTION(BlueprintCallable)
		TEnumAsByte<EGameStates> GetGameState();

	UFUNCTION(BlueprintCallable)
		int GetPlayerKillsCount();

	UFUNCTION(BlueprintCallable)
		void AddKillCount();

	UFUNCTION(BlueprintCallable)
		int GetKillsToWin();

	UFUNCTION(BlueprintCallable)
		int GetPlayerDeaths();

	UFUNCTION(BlueprintCallable)
		void AddPlayerDeathCount();
};
