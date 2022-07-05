// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "EnemySpawner.h"
#include "LevelManagerClass.generated.h"

class AEnemySpawner;

UCLASS()
class M1_PROJECTZOMBIES_API ALevelManagerClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelManagerClass();

	UPROPERTY(EditAnywhere)
		TArray<AActor*> Spawners;

	UPROPERTY(VisibleAnywhere)
		int CurrentRound = 0;

	UPROPERTY(VisibleAnywhere)
		bool bCanStartRound;

	UPROPERTY(VisibleAnywhere)
		int32 CurrentRoundEnemyCount;

	UPROPERTY(VisibleAnywhere)
		int32 CurrentRoundLeftToSpawn;

	UPROPERTY()
		int32 MaxEnemiesInMap = 6;

	UPROPERTY()
		int32 CurrentEnemiesInMap = 0;

	UFUNCTION(BlueprintCallable)
		void BeginRound();

	UFUNCTION(BlueprintCallable)
		void EndRound();

	UFUNCTION()
		void SpawnEnemy();

	UFUNCTION()
		void EnemySpawned();

	UFUNCTION()
		void EnemyDied();

	UFUNCTION(BlueprintCallable)
		void Win();

	UFUNCTION(BlueprintCallable)
		void Lose();


	UFUNCTION(BlueprintCallable)
		bool CanWin();

	UFUNCTION(BlueprintCallable)
		bool InRound();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
