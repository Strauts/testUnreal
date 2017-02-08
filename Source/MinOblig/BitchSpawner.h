// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BitchSpawner.generated.h"

UCLASS()
class MINOBLIG_API ABitchSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABitchSpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	//UPROPERTY(EditAnywhere, Category = "Spawning")
	//TSubclassOf<class AEnemy> EnemyBlueprint;

	UPROPERTY(EditAnywhere, Category = Projectile)
		TSubclassOf<class AMyEnemy> MyEnemyClass;

	UPROPERTY(EditAnywhere)
		UShapeComponent* RootSphere = nullptr;




	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawning)
		float SpawnDelayRangeLow;

	/** Maximum spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawning)
		float SpawnDelayRangeHigh;

	/** Whether or not spawning is enabled */
	bool bSpawningEnabled;

	/** Calculates a random spawn delay */
	float GetRandomSpawnDelay();

	/** The current spawn delay */
	float SpawnDelay;

	/** The timer for when to spawn the pickup */
	float SpawnTime;

};
