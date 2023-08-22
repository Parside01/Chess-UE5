// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cell.generated.h"

class UMaterial;

static int NumCell{ 0 };

UCLASS()
class CHESS_API ACell : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ACell();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell StaticMesh")
		class UStaticMeshComponent* StaticMeshComponent;
	
	
public:

	UFUNCTION()
		void SetMaterial(UMaterial* Material) { StaticMeshComponent->SetMaterial(0, Material); }

	UFUNCTION()
		UStaticMeshComponent* GetMesh() { return StaticMeshComponent; }

	UFUNCTION()
		void SetStaticMesh(UStaticMesh* StaticMesh);

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Variebles")
		bool bIsEmploy;

	
};
