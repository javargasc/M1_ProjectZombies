// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "M1_ProjectZombiesProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS(config=Game)
class AM1_ProjectZombiesProjectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere)
		float DeltaTime = 0;

	UFUNCTION(BlueprintCallable)
		void SetDeltaTime(float delta);

	UFUNCTION(BlueprintCallable)
		float GetDeltaTime();

	UPROPERTY(EditAnywhere)
		float BulletDuration = 1;

	UFUNCTION(BlueprintCallable)
		void SetBulletDuration(float time);

	UFUNCTION(BlueprintCallable)
		float DecreaseBulletDuration(float decrement);

	UPROPERTY(EditAnywhere)
		bool Hit_NOCPP = false;

	UFUNCTION(BlueprintCallable)
		void SetHit(bool b);

	UFUNCTION(BlueprintCallable)
		bool GetHit();

public:
	AM1_ProjectZombiesProjectile();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

