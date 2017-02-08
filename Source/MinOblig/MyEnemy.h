// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyEnemy.generated.h"

UCLASS()
class MINOBLIG_API AMyEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	//Makes editable anywhere
	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;
	//Sets enemy speed
	FVector CurrentVelocity = FVector(1.0f, 0.0f, 0.0f)*250.0f;
};
