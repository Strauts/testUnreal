// Fill out your copyright notice in the Description page of Project Settings.

#include "MinOblig.h"
#include "MyBullet.h"
#include "MyEnemy.h"


// Sets default values
AMyBullet::AMyBullet()
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
void AMyBullet::BeginPlay()
{
	Super::BeginPlay();
	//Info to Output Log
	UE_LOG(LogTemp, Warning, TEXT("Spawn Bullet"));
	//Checks if there is overlap
	CollisionBox = this->FindComponentByClass<USphereComponent>();
	if (CollisionBox) 
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AMyBullet::OnOverlap);
	}

	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("No Collider"));
	}

}


// Called every frame
void AMyBullet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//Moves bullet up the X axis
	FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);

	FVector Destruction = GetActorLocation();
	//Destroys bullet if X value is at or passes set value, then prints in Output Log
	if (Destruction.X >= 400.0f)
	{
		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Destruction"));
	}


}
//Checks to see if there is overlapping between the actors. Then says if the other actor is a enemy (class) it will destroy this actor, then it destroys the bullet
void AMyBullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) 
{
	if (OtherActor->IsA(AMyEnemy::StaticClass())) 
	{
		OtherActor->Destroy();
		Destroy();
	}

}

