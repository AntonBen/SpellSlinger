// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MageGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MARSMARINE_API UMageGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
		UMageGameInstance(const FObjectInitializer& ObjectInitializer);
	
		virtual void Init();

		UFUNCTION(Exec)
			void Host();

		UFUNCTION(Exec)
			void Join(const FString& Address);
	
};
