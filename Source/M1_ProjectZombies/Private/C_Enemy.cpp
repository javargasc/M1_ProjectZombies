// Fill out your copyright notice in the Description page of Project Settings.


#include "C_Enemy.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AC_Enemy::AC_Enemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnSensor = CreateDefaultSubobject<UPawnSensingComponent>("Pawn Sensor");
	PawnSensor->SetPeripheralVisionAngle(45.f);
	PawnSensor->SightRadius = 1500.f;

	PawnSensor->OnSeePawn.AddDynamic(this, &AC_Enemy::OnSeePawn);
	LevelManager = (ALevelManagerClass*)UGameplayStatics::GetActorOfClass(GetWorld(), ALevelManagerClass::StaticClass());
}

// Called when the game starts or when spawned
void AC_Enemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AC_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AC_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AC_Enemy::OnSeePawn(APawn* OtherPawn)
{
	FString message = TEXT("Saw Actor ") + OtherPawn->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "OnSeePawn: " + message);

	AAIController* AIController = Cast<AAIController>(GetController());

	if (AIController)
	{
		AIController->MoveToLocation(OtherPawn->GetNavAgentLocation(), -1, false);
	}
}

void AC_Enemy::OnDeath()
{
	LevelManager->EnemyDied();
}