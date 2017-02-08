// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyBullet.generated.h"

UCLASS()
class MINOBLIG_API AMyBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBullet();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	//Make editable anywhere
	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;
	//Setting bullet speed
	FVector CurrentVelocity = FVector(1.0f, 0.0f, 0.0f)*800.0f;
	
	//Initialising for collision and overlap
	UShapeComponent* CollisionBox = nullptr;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
};
