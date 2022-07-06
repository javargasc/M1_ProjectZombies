// Fill out your copyright notice in the Description page of Project Settings.

#include "C_Button.h"
#include "Materials/MaterialInterface.h"

// Sets default values
AC_Button::AC_Button()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCompButton"));
	CollisionComp->InitSphereRadius(5.0f);

	ButtonBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	ButtonBody->AttachTo(GetRootComponent());
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	ButtonBody->SetStaticMesh(SphereMeshAsset.Object);
}

// Called when the game starts or when spawned
void AC_Button::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AC_Button::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AC_Button::GetPlayerEnbabled() 
{
	return PlayerEnbabled;
}

void AC_Button::SetPlayerEnbabled(bool value)
{
	PlayerEnbabled = value;
}

void AC_Button::SetGameModeRef(AC_GameModeBase* GameMode)
{
	GameModeRef = GameMode;
}

AC_GameModeBase* AC_Button::GetGameModeRef()
{
	return GameModeRef;
}

void AC_Button::SetButtonMatRef(UMaterialInstanceDynamic* Mat)
{
	ButtonMatRef = Mat;
}

UMaterialInstanceDynamic* AC_Button::GetButtonMatRef()
{
	return ButtonMatRef;
}
