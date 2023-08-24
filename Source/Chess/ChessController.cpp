// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessController.h"
#include "ChessPlayer.h"
#include "BaseActor.h"
#include "Board.h"


AChessController::AChessController()
{
}

void AChessController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetWorld()) return;

	Board = GetWorld()->SpawnActor<ABoard>(FVector(0), FRotator(0));

	FirstPlayer = GetWorld()->SpawnActor<AChessPlayer>(FVector(1600.0, 3700.0, 1500), FRotator(20.0f, -90.0f, 0.0f));
	FirstPlayer->bIsWhite = true;
	CurrentPlayer = FirstPlayer;

	SecondPlayer = GetWorld()->SpawnActor<AChessPlayer>(FVector(1600.0, -500.0, 1500), FRotator(20.0f, 90.0f, 0.0f));
	SecondPlayer->bIsWhite = false;
	PrevPlayer = SecondPlayer;

	SpawnWhiteShapes();
	SpawnBlackShapes();
}

void AChessController::LeftMouseClick()
{
	if (SelectedShapes) SelectedShapes->StopChoose();

	SelectShapes();
}

void AChessController::SpawnWhiteShapes()
{
}

void AChessController::SpawnBlackShapes()
{
}

void AChessController::SelectShapes()
{
	FHitResult HitResult(ForceInit);
	GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, HitResult);

	if (!HitResult.GetActor()) return;
	if (!HitResult.GetActor()->IsA(ABaseActor::StaticClass())) return;

	SelectedShapes = Cast<ABaseActor>(HitResult.GetActor());

	if (!SelectedShapes) return;

	if(SelectedShapes->bIsWhite != )
}