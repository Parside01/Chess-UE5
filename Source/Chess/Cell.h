// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cell.generated.h"

class UMaterial;

UCLASS()
class CHESS_API ACell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACell();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell StaticMesh")
		class UStaticMesh* StaticMesh;

public:

	UFUNCTION()
		void SetMaterial(UMaterial* Material) { StaticMesh->SetMaterial(0, Material); }

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Variebles")
		bool bIsEmploy;
};
