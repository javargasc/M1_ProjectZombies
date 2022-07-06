// Copyright Epic Games, Inc. All Rights Reserved.

#include "M1_ProjectZombiesProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

AM1_ProjectZombiesProjectile::AM1_ProjectZombiesProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AM1_ProjectZombiesProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AM1_ProjectZombiesProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Destroy();
	}
}

void AM1_ProjectZombiesProjectile::SetDeltaTime(float deltaTime)
{
	DeltaTime = deltaTime;
}

float AM1_ProjectZombiesProjectile::GetDeltaTime()
{
	return DeltaTime;
}

void AM1_ProjectZombiesProjectile::SetBulletDuration(float time)
{
	BulletDuration = time;
}

float AM1_ProjectZombiesProjectile::DecreaseBulletDuration(float decrement)
{
	SetBulletDuration(BulletDuration - decrement);
	return BulletDuration;
}

void AM1_ProjectZombiesProjectile::SetHit(bool b)
{
	Hit_NOCPP = b;
}

bool AM1_ProjectZombiesProjectile::GetHit()
{
	return Hit_NOCPP;
}

void AM1_ProjectZombiesProjectile::SetBulletMatRef(UMaterialInstanceDynamic* Mat)
{
	BulletMatRef = Mat;
}

UMaterialInstanceDynamic* AM1_ProjectZombiesProjectile::GetBulletMatRef()
{
	return BulletMatRef;
}