// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Cell.h"
#include "Board.h"


ABaseActor::ABaseActor()
{
 
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	Board = nullptr;
}

void ABaseActor::BeginPlay()
{
	Super::BeginPlay();
	
	Board = InitBoard();
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

void ABaseActor::ActorPathFinder(TMap<FString, ACell*> Cells)
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

ABoard* ABaseActor::InitBoard()
{
	if (!GetWorld()) return nullptr;
	TArray<AActor*> Actors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoard::StaticClass(), Actors);

	if (Actors.IsEmpty()) return nullptr;
	ABoard* Result = Cast<ABoard>(Actors[0]);
	return Result;
}



