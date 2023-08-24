// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ChessController.generated.h"

/**
 * 
 */
class AChessPlayer;
class ABoard;

UCLASS()
class CHESS_API AChessController : public APlayerController
{
	GENERATED_BODY()

public:

	AChessController();

	virtual void BeginPlay() override;


						//FUNCTION//
	UFUNCTION()
		void LeftMouseClick();

	UFUNCTION()
		void SpawnWhiteShapes();

	UFUNCTION()
		void SpawnBlackShapes();

	UFUNCTION()
		void SelectShapes();

						//FUNCTION//

						//VARIABLES//
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Players")
		AChessPlayer* FirstPlayer;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Players")
		AChessPlayer* SecondPlayer;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Players")
		AChessPlayer* CurrentPlayer;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Players")
		AChessPlayer* PrevPlayer;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Board")
		ABoard* Board;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "BOOL")
		bool bIsAnythingSelected = false;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "SHAPES")
		ABaseActor* SelectedShapes;
						//VARIABLES//
};
