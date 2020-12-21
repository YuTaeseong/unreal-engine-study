// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	InitialLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	WorldOrigin = FVector(0.0f, 0.0f, 0.0f);

	InitialDirection = FVector(0.0f, 0.0f, 0.0f);

	bInitializeFloatorLocations = false;
	bShouldFloat = false;

	InitialForce = FVector(2000000.f, 0.0f, 0.0f);
	InitialTorque = FVector(2000000.f, 0.0f, 0.0f);

	RunningTime = 0.f;

	A = 0.f;
	B = 0.f;
	C = 0.f;
	D = 0.f;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	float Initialx = FMath::FRandRange(-500.f, 500.f);
	float Initialy = FMath::FRandRange(-500.f, 500.f);
	float Initialz = FMath::FRandRange(0.f, 500.f);

	InitialLocation.X = Initialx;
	InitialLocation.Y = Initialy;
	InitialLocation.Z = Initialz;

	PlacedLocation = GetActorLocation();


	if (bInitializeFloatorLocations) {
		SetActorLocation(InitialLocation);
	}

	BaseZLocation = PlacedLocation.Z;
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat) {

		FVector newLocation = GetActorLocation();

		newLocation.Z = BaseZLocation + A * FMath::Sin(B * RunningTime - C) + D;

		SetActorLocation(newLocation);
		RunningTime += DeltaTime;
	}

}

