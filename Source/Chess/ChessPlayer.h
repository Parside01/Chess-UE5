// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ChessPlayer.generated.h"

class AChessController;
class ABaseActor;
class UCameraComponent;
class USpringArmComponent;

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

							//VARIABLES//
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "PlayerController")
		AChessController* PlayerController;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Arrays")
		TArray<ABaseActor*> KilledShapes;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "BOOL")
		bool bIsWhite;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Camera")
		UCameraComponent* Camera;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Camera")
		USpringArmComponent* SpringArm;

							//VARIABLES//
};
