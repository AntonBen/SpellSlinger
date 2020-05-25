// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingWall.h"

AMovingWall::AMovingWall() 
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingWall::BeginPlay() 
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartPosition = GetActorLocation();
	GlobalTargetPostion = GetTransform().TransformPosition(TargetLocation);

}

void AMovingWall::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
	bool IsServer = HasAuthority();

	if (IsServer)
	{
		FVector Location = GetActorLocation();
		float JurneyLength = (GlobalTargetPostion - GlobalStartPosition).Size();
		float JurneyTraveled = (Location - GlobalStartPosition).Size();

		if (JurneyTraveled >= JurneyLength)
		{
			FVector Swap = GlobalStartPosition;
			GlobalStartPosition = GlobalTargetPostion;
			GlobalTargetPostion = Swap;
		}

		FVector Direction = (GlobalTargetPostion - GlobalStartPosition).GetSafeNormal();
		Location += Speed * DeltaTime * Direction;
		SetActorLocation(Location);
		
	}
	
}
