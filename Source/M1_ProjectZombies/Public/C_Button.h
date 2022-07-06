// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "C_GameModeBase.h"
#include "C_Button.generated.h"

class UMaterialInstanceDynamicInterface;

UCLASS()
class M1_PROJECTZOMBIES_API AC_Button : public AActor
{
	GENERATED_BODY()
	// Sets default values for this actor's properties
	AC_Button();

public:
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	USphereComponent* CollisionComp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* ButtonBody;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool PlayerEnbabled;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AC_GameModeBase* GameModeRef;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInstanceDynamic* ButtonMatRef;


	UFUNCTION(BlueprintCallable)
	bool GetPlayerEnbabled();

	UFUNCTION(BlueprintCallable)
	void SetPlayerEnbabled(bool value);

	UFUNCTION(BlueprintCallable)
	void SetGameModeRef(AC_GameModeBase* GameMode);

	UFUNCTION(BlueprintCallable)
	AC_GameModeBase* GetGameModeRef();

	UFUNCTION(BlueprintCallable)
	void SetButtonMatRef(UMaterialInstanceDynamic* Mat);

	UFUNCTION(BlueprintCallable)
	UMaterialInstanceDynamic* GetButtonMatRef();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
