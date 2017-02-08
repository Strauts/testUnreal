// Fill out your copyright notice in the Description page of Project Settings.

#include "MinOblig.h"
#include "MyEnemy.h"
#include "MyMom.h"


// Sets default values
AMyEnemy::AMyEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Hitbox
	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));
	//What we see
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMyEnemy::BeginPlay()
{
	Super::BeginPlay();
	//Prints in Output Log
	UE_LOG(LogTemp, Warning, TEXT("Enemy Spawned"));
	
}

// Called every frame
void AMyEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Moves enemy
	FVector NewLocation = GetActorLocation() - (CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);

	//Reverses direction of enemy based on position on X axis, and sets speed again (same speed as before)
	FVector Hit = GetActorLocation();
	if (Hit.X <= -750.0f)
	{
		CurrentVelocity = FVector(-1.0f, 0.0f, 0.0f)*250.0f;
	}
	if (Hit.X >= 160.0f)
	{
		CurrentVelocity = FVector(1.0f, 0.0f, 0.0f)*250.0f;
	}

}