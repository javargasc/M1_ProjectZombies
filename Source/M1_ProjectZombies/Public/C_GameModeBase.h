// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "C_GameInstance.h"
#include "LevelManagerClass.h"
#include "../M1_ProjectZombiesCharacter.h"
#include "C_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class M1_PROJECTZOMBIES_API AC_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	AC_GameModeBase();
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool RoundButtonCPP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UC_GameInstance* GameInstanceCPP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		ALevelManagerClass* LevelManagerCPP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		AM1_ProjectZombiesCharacter* PlayerCharacterCPP;

	UFUNCTION(BlueprintCallable)
		void SetRoundButton(bool value);

	UFUNCTION(BlueprintCallable)
		bool GetRoundButton();

	UFUNCTION(BlueprintCallable)
		void SetGameInstanceCPP(UC_GameInstance* gameInstance);

	UFUNCTION(BlueprintCallable)
		UC_GameInstance* GetGameInstanceCPP();

	UFUNCTION(BlueprintCallable)
		void SetLevelManagerCPP(ALevelManagerClass* levelManager);

	UFUNCTION(BlueprintCallable)
		ALevelManagerClass* GetLevelManagerCPP();

	UFUNCTION(BlueprintCallable)
		void SetPlayerCharacterCPP(AM1_ProjectZombiesCharacter* playerCharacter);

	UFUNCTION(BlueprintCallable)
		AM1_ProjectZombiesCharacter* GetPlayerCharacterCPP();

};
