// Fill out your copyright notice in the Description page of Project Settings.


#include "C_GameInstance.h"

UC_GameInstance::UC_GameInstance() 
{

}

void UC_GameInstance::SetGameOver() 
{
	GameState = EGameStates::GAME_OVER;
}

void UC_GameInstance::SetGameStartMenu()
{
	GameState = EGameStates::GAME_START_MENU;
}

void UC_GameInstance::SetGameOn()
{
	GameState = EGameStates::GAME_IN_ROUND;
}

void UC_GameInstance::SetGameWin()
{
	GameState = EGameStates::GAME_WIN;
}

void UC_GameInstance::SetGamePause()
{
	GameState = EGameStates::GAME_PAUSED;
}

void UC_GameInstance::SetGameTutorial()
{
	GameState = EGameStates::GAME_TUTORIAL;
}

void UC_GameInstance::SetGameCredits()
{
	GameState = EGameStates::GAME_CREDITS;
}

TEnumAsByte<EGameStates> UC_GameInstance::GetGameState()
{
	return GameState;
}

int UC_GameInstance::GetPlayerKillsCount() 
{
	return PlayerKillsCount;
}

void UC_GameInstance::AddKillCount() 
{
	PlayerKillsCount++;
}

int UC_GameInstance::GetKillsToWin()
{
	return KillToWin;
}

int UC_GameInstance::GetPlayerDeaths()
{
	return PlayerDeaths;
}

void UC_GameInstance::AddPlayerDeathCount()
{
	PlayerDeaths++;
}
