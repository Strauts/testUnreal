// Fill out your copyright notice in the Description page of Project Settings.

#include "MinOblig.h"
#include "MyMom.h"
#include "MyBullet.h"
#include "MyEnemy.h" 


// Sets default values
AMyMom::AMyMom()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Possess player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	//Hitbox
	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));
	//What we see
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyMom::BeginPlay()
{
	Super::BeginPlay();
	//Sett player cam to CameraOne, which I set to be the new camera I added inside Unreal
	GetWorld()->GetFirstPlayerController()->SetViewTarget(CameraOne);

	UWorld* World = GetWorld();
	FVector EnemyLocation = FVector(1.0f, -300.0f, 1.0f);

	if (World)
	{
		//Set distance between enemies, and height on map
		for (int i = -450; i <= max_Y; i += distance)
		{
			for (int j = -150; j <= max_X; j += distance)
			{
				EnemyLocation = FVector(j, i, 42.0f);
				World->SpawnActor<AMyEnemy>(MyEnemy_BP, EnemyLocation, FRotator::ZeroRotator);
			}
		}
	}
}

// Called every frame
void AMyMom::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//Moves pawn
	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void AMyMom::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveY", this, &AMyMom::Move_YAxis); //Movement
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AMyMom::Shoot); //Shooting


}
//Setting speed for pawn
void AMyMom::Move_YAxis(float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -2.0f, 2.0f)* 1000.0f;
}
//
void AMyMom::Shoot()
{
	UWorld * World = GetWorld();

	if (World)
	{
		FVector Location = GetActorLocation();

		World->SpawnActor<AMyBullet>(MyBullet_BP, Location, FRotator::ZeroRotator); 
	}
}

