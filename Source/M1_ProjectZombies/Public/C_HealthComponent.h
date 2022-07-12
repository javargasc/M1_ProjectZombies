// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "C_HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom),Blueprintable , meta=(BlueprintSpawnableComponent) )
class M1_PROJECTZOMBIES_API UC_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UC_HealthComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float LifeAmountCPP = 100;

	UFUNCTION(BlueprintCallable)
	void ApplyDamage(float damageAmount);

	UFUNCTION(BlueprintCallable)
	bool isLive();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
