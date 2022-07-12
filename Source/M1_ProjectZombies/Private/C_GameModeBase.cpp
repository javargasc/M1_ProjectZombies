// Fill out your copyright notice in the Description page of Project Settings.


#include "C_GameModeBase.h"

AC_GameModeBase::AC_GameModeBase()
{

}

void AC_GameModeBase::SetRoundButton(bool value)
{
	RoundButtonCPP = value;
}

bool AC_GameModeBase::GetRoundButton()
{
	return RoundButtonCPP;
}

void AC_GameModeBase::SetGameInstanceCPP(UC_GameInstance* gameInstance)
{
	GameInstanceCPP = gameInstance;
}

UC_GameInstance* AC_GameModeBase::GetGameInstanceCPP()
{
	return GameInstanceCPP;
}

void AC_GameModeBase::SetLevelManagerCPP(ALevelManagerClass* levelManager)
{
	LevelManagerCPP = levelManager;
}

ALevelManagerClass* AC_GameModeBase::GetLevelManagerCPP()
{
	return LevelManagerCPP;
}

void AC_GameModeBase::SetPlayerCharacterCPP(AM1_ProjectZombiesCharacter* playerCharacter)
{
	PlayerCharacterCPP = playerCharacter;
}

AM1_ProjectZombiesCharacter* AC_GameModeBase::GetPlayerCharacterCPP()
{
	return PlayerCharacterCPP;
}