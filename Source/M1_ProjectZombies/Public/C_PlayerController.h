// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "C_UserWidget.h"
#include "C_GameInstance.h"
#include "C_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class M1_PROJECTZOMBIES_API AC_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UC_GameInstance* GameInstanceCPP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UC_UserWidget* PauseMenuRefCPP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UC_UserWidget* UserWidgetCPP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		APawn* OriginalPawnCPP;
};
