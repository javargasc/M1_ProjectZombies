// Fill out your copyright notice in the Description page of Project Settings.


#include "C_MapManager.h"

// Sets default values
AC_MapManager::AC_MapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AC_MapManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AC_MapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AC_MapManager::SetupStartMap()
{
}

void AC_MapManager::SetupLevel()
{
}

void AC_MapManager::SetupWinMap()
{
}

void AC_MapManager::SetupGameOverMap()
{
}

TEnumAsByte<EGameStates> AC_MapManager::GetGameState()
{
	return GAME_STATE;
}
