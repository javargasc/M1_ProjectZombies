// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "C_Enemy.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	MyLoc = this->GetActorLocation();
	MyRot = this->GetActorRotation();
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AEnemySpawner::Spawn()
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;
	if (IsValid(GetWorld()->SpawnActor<AC_Enemy>(ActorToSpawn ,MyLoc, MyRot, SpawnInfo))) return true;
	return false;
}

