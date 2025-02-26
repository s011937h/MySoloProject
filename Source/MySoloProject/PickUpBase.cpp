// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUpBase.h"
#include "Components/SphereComponent.h"
#include "Spawner.h"

// Sets default values
APickUpBase::APickUpBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));

}

// Called when the game starts or when spawned
void APickUpBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickUpBase::NotifyActorBeginOverlap(AActor * OtherActor)
{
	OnActivate(OtherActor);
}

void APickUpBase::PickedUp(AActor * PickedUpBy)
{
	ASpawner* spawner = (ASpawner*)GetOwner();
	if (GetOwner() != NULL)
	{
		spawner->RespawnBegin();
	}
	Destroy();
}