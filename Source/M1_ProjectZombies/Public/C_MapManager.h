// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_GameStates.h"
#include "C_MapManager.generated.h"

UCLASS()
class M1_PROJECTZOMBIES_API AC_MapManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AC_MapManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
		TEnumAsByte<EGameStates> GAME_STATE;

	UFUNCTION(BlueprintCallable)
		void SetupStartMap();

	UFUNCTION(BlueprintCallable)
		void SetupLevel();

	UFUNCTION(BlueprintCallable)
		void SetupWinMap();

	UFUNCTION(BlueprintCallable)
		void SetupGameOverMap();

	UFUNCTION(BlueprintCallable)
		TEnumAsByte<EGameStates> GetGameState();
};
