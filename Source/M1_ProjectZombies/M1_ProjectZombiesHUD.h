// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "M1_ProjectZombiesHUD.generated.h"

UCLASS()
class AM1_ProjectZombiesHUD : public AHUD
{
	GENERATED_BODY()

public:
	AM1_ProjectZombiesHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

