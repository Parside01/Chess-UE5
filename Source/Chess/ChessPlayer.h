// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ChessPlayer.generated.h"

class 

UCLASS()
class CHESS_API AChessPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	
	AChessPlayer();

protected:
	
	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
