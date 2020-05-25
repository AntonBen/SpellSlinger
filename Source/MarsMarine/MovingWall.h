// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingWall.generated.h"

/**
 * 
 */
UCLASS()
class MARSMARINE_API AMovingWall : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingWall();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		float Speed = 20;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
		FVector TargetLocation;

private:
	FVector GlobalStartPosition;
	FVector GlobalTargetPostion;
};
