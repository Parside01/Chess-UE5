// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/KismetMathLibrary.h"

#include "BaseActor.h"
#include "Cell.h"


ABaseActor::ABaseActor()
{
 
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
}

void ABaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseActor::StartChoose()
{
	UStaticMesh* StaticMesh = StaticMeshComponent->GetStaticMesh();
	bIsWhite ? StaticMesh->SetMaterial(0, ChooseWhiteMaterial) : StaticMesh->SetMaterial(0, ChooseBlackMaterial);
}

void ABaseActor::StopChoose()
{
	UStaticMesh* StaticMesh = StaticMeshComponent->GetStaticMesh();
	bIsWhite ? StaticMesh->SetMaterial(0, WhiteMaterial) : StaticMesh->SetMaterial(0, BlackMaterial);
}

void ABaseActor::ActorPathFinder(TMap<FString, ACell*>& Cells)
{
}

void ABaseActor::Move(FVector Location)
{
	SetActorLocation(Location);
}

void ABaseActor::Dead()
{
	Destroy();
}



