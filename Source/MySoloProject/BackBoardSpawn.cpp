// Fill out your copyright notice in the Description page of Project Settings.

#include "BackBoardSpawn.h"
#include "Components/StaticMeshComponent.h" 
#include "Kismet/GameplayStatics.h" 
#include "Engine/World.h"


// Sets default values
ABackBoardSpawn::ABackBoardSpawn()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BackBoardSpawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Backboard Spawn Mesh"));
	BackBoardSpawnMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ABackBoardSpawn::BeginPlay()
{
	Super::BeginPlay();
	
}

	// Called every frame
void ABackBoardSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABackBoardSpawn::Spawn()
{
	Spawned = true;
	FActorSpawnParameters params;		
	params.Owner = this;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AActor* newSpawn = GetWorld()->SpawnActor<AActor>(ObjectToSpawn, this->GetActorLocation() + SpawnOffset, this->GetActorRotation(), params);
	OnSpawnEvent();
}

void ABackBoardSpawn::Despawn()
{
	
}
