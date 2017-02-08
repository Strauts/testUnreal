// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MyMom.generated.h"

UCLASS()
class MINOBLIG_API AMyMom : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyMom();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	void Move_YAxis(float AxisValue);
	void Shoot();
	FVector CurrentVelocity;
	//Giving property to edit anywhere
	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AMyBullet> MyBullet_BP;
	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AMyEnemy> MyEnemy_BP;
	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;
	UPROPERTY(EditAnywhere)
		AActor* CameraOne = nullptr;
	//Sets max distance for spawning, and space between actors 
	const int max_Y = 450;
	const int max_X = 150;
	const int distance = 100;
};
