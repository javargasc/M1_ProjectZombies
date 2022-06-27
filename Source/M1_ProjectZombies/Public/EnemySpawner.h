// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

class AC_Enemy;

UCLASS()
class M1_PROJECTZOMBIES_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	UFUNCTION()
		bool Spawn();

	UPROPERTY(EditAnywhere)
		TSubclassOf<AC_Enemy> ActorToSpawn;

	UPROPERTY()
		FVector MyLoc;

	UPROPERTY()
		FRotator MyRot;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
