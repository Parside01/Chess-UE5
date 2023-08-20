// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChessGameMode.h"
#include "ChessPlayerController.h"
#include "ChessCharacter.h"
#include "UObject/ConstructorHelpers.h"

AChessGameMode::AChessGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AChessPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}