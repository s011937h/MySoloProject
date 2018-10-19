// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawner.h"
#include "Components/StaticMeshComponent.h" 
#include "Kismet/GameplayStatics.h" 
#include "Engine/World.h"


// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spawner Mesh"));
	SpawnerMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Respawning)
	{
		if (RespawnTimeElapsed < RespawnTime)
		{
			RespawnTimeElapsed += DeltaTime;
		}
		else
		{
			Spawn();
			RespawnTimeElapsed = 0.0f;
			Respawning = false;
		}
	}
}

void ASpawner::Spawn()
{
	FActorSpawnParameters params;
	params.Owner = this;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AActor* newSpawn = GetWorld()->SpawnActor<AActor>(ObjectToSpawn, this->GetActorLocation() + SpawnOffset, this->GetActorRotation(), params);
	OnSpawnEvent();
}

void ASpawner::RespawnBegin()
{
	Respawning = true;
}