// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"
class UStaticMeshComponent;

UCLASS()
class MYSOLOPROJECT_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SpawnerMesh;
	
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector SpawnOffset;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> ObjectToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float RespawnTime;

	float RespawnTimeElapsed;

	UPROPERTY(BlueprintReadOnly)
	bool Respawning;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Spawn();
	UFUNCTION(BlueprintImplementableEvent)
	void OnSpawnEvent();
	UFUNCTION(BlueprintCallable)
	void RespawnBegin();
	
};
