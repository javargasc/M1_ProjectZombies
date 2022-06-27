// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/PawnSensingComponent.h"
#include "AIController.h"
#include "LevelManagerClass.h"
#include "C_Enemy.generated.h"

UCLASS()
class M1_PROJECTZOMBIES_API AC_Enemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AC_Enemy();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float lifeAmount = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool isDead = false;

	UFUNCTION()
		void OnSeePawn(APawn* OtherPawn);

	UFUNCTION(BlueprintCallable)
		void OnDeath();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UPawnSensingComponent* PawnSensor;

	UPROPERTY()
		ALevelManagerClass* LevelManager;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
