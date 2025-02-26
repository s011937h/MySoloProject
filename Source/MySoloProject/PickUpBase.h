// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpBase.generated.h"

class USphereComponent;

UCLASS()
class MYSOLOPROJECT_API APickUpBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void NotifyActorBeginOverlap(AActor * OtherActor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup")
	void OnActivate(AActor* pickedUpBy);
	UFUNCTION(BlueprintCallable)
	void PickedUp(AActor* PickedUpBy);
	
};
