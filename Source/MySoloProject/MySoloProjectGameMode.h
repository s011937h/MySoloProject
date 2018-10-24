// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
using namespace std;
#include <cstring>
#include<iostream>
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MySoloProjectGameMode.generated.h"

UCLASS(minimalapi)
class AMySoloProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMySoloProjectGameMode();

	char Sequence1[4][10] = { "Pink", "Purple","Blue","Green" };
};



