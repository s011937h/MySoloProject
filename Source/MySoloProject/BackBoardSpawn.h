// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BackBoardSpawn.generated.h"
class UStaticMeshComponent;

UCLASS()
class MYSOLOPROJECT_API ABackBoardSpawn : public AActor
{
	GENERATED_BODY()

public:
		// Sets default values for this actor's properties
		ABackBoardSpawn();

protected:
		// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent * BackBoardSpawnMesh;
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
		FVector SpawnOffset;
	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<AActor> ObjectToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		bool SpawnNow;
	bool Spawned;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void Spawn();
	UFUNCTION(BlueprintCallable)
		void Despawn();
	UFUNCTION(BlueprintImplementableEvent)
		void OnSpawnEvent();

};

	
	

