// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseActor.h"

// Sets default values
ABaseActor::ABaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseActor::StartChoose()
{
}

void ABaseActor::StopChoose()
{
}

void ABaseActor::ActorPathFinder(TArray<UStaticMeshComponent*>& Cells)
{
}

void ABaseActor::Move(FVector Location)
{
}

// Called every frame
void ABaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

