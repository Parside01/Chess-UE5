// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.generated.h"

class UMaterial;
class UStaticMeshComponent;
class ACell;

UCLASS()
class CHESS_API ABaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

//variables dir

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticMeshComponent")
		UStaticMeshComponent* StaticMeshComponent;

	//The actor's material if we play for black
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		UMaterial* BlackMaterial; 

	//The actor's material if we play for white
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		UMaterial* WhiteMaterial; 

	//Material when clicking on a white actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		UMaterial* ChooseWhiteMaterial;

	//Material when clicking on a black actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		UMaterial* ChooseBlackMaterial;

	//the first move
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		bool bIsWhite;



//function dir

	//functions that are activated at the moment when the player clicks on the figure
	UFUNCTION()
		void StartChoose();
	UFUNCTION()
		void StopChoose();


	UFUNCTION()
		virtual void ActorPathFinder(TMap<FString, ACell*>& Cells);

	UFUNCTION()
		virtual void Move(FVector Location);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
