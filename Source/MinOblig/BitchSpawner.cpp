// Fill out your copyright notice in the Description page of Project Settings.

#include "MinOblig.h"
#include "BitchSpawner.h"
#include"MyEnemy.h"


// Sets default values
ABitchSpawner::ABitchSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootSphere = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));
	RootComponent = RootSphere;


	SpawnDelayRangeLow;
	SpawnDelayRangeHigh;
	SpawnDelay = GetRandomSpawnDelay();

}

// Called when the game starts or when spawned
void ABitchSpawner::BeginPlay()
{
	Super::BeginPlay();

}

float ABitchSpawner::GetRandomSpawnDelay()
{
	// Get a random float that falls within the spawn delay range
	return FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
}


// Called every frame
void ABitchSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Always add delta time to our Spawn Time
	SpawnTime += DeltaTime;

	bool bShouldSpawn = (SpawnTime > SpawnDelay);

	if (bShouldSpawn)
	{
		UWorld* World = GetWorld();
		if (World)
		{

			//Deduct spawn delay from accumulated time value
			SpawnTime -= SpawnDelay;

			SpawnDelay = GetRandomSpawnDelay();

			FVector Location = GetActorLocation();
			World->SpawnActor<AMyEnemy>(MyEnemyClass, Location, FRotator::ZeroRotator);
		}
	}

}