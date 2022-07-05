// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManagerClass.h"
#include "EnemySpawner.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ALevelManagerClass::ALevelManagerClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelManagerClass::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySpawner::StaticClass(), Spawners);
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Emerald, FString::Printf(TEXT("%i spawners found."), Spawners.Num()));
	bCanStartRound = true;
	//BeginRound();
}

// Called every frame
void ALevelManagerClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bCanStartRound)
	{
		if (CurrentRoundEnemyCount == 0)
		{
			EndRound();
		}
		else if (CurrentRoundLeftToSpawn != 0 && CurrentEnemiesInMap < MaxEnemiesInMap)
		{
			SpawnEnemy();
		}

	}
	

	if (bCanStartRound && CurrentRound == 5)
	{
		Win();
	}


}

void ALevelManagerClass::BeginRound()
{
	bCanStartRound = false;
	CurrentRound++;
	CurrentRoundEnemyCount = 1 * CurrentRound;
	CurrentRoundLeftToSpawn = CurrentRoundEnemyCount;

	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Emerald, FString::Printf(TEXT("Round %i Started! (%i enemies)"), CurrentRound, CurrentRoundEnemyCount));
}

void ALevelManagerClass::EndRound()
{
	bCanStartRound = true;

	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Emerald, "Round Ended!");
}

void ALevelManagerClass::SpawnEnemy()
{
	int32 aux = FMath::RandRange(0, Spawners.Num() - 1);
	if (((AEnemySpawner*)Spawners[aux])->Spawn())
	{
		EnemySpawned();
	}
	//GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Emerald, FString::Printf(TEXT("Try to spawn enemy in spawner %i!"), aux));
}

void ALevelManagerClass::EnemySpawned()
{
	CurrentEnemiesInMap++;
	CurrentRoundLeftToSpawn--;
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Emerald, FString::Printf(TEXT("Enemies spawned!")));
}

void ALevelManagerClass::EnemyDied()
{
	CurrentRoundEnemyCount--;
	CurrentEnemiesInMap--;
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Emerald, FString::Printf(TEXT("Enemies left: %i (%i currently spawned)"), CurrentRoundEnemyCount, CurrentEnemiesInMap));
}

void ALevelManagerClass::Win()
{
	//GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Emerald, "You Win!");
}

void ALevelManagerClass::Lose()
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Emerald, "You Lose!");
}

bool ALevelManagerClass::CanWin()
{
	return bCanStartRound && CurrentRound == 5;
}

bool ALevelManagerClass::InRound() 
{
	return !bCanStartRound;
}