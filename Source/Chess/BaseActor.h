// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.generated.h"

class UMaterial;

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

	//The actor's material if we play for black
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		UMaterial* DarkMaterial; 

	//The actor's material if we play for white
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		UMaterial* WhiteMaterial; 

	//Material when clicking on a white actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		UMaterial* ChooseWhiteMaterial;

	//Material when clicking on a black actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		UMaterial* ChooseBlackMaterial;

//function dir

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
