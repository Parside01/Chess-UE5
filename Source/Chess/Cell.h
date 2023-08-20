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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell StaticMesh")
		class UStaticMesh* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
		UMaterial* LightMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
		UMaterial* DarkMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
		UMaterial* HightlightedMaterial;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Material")
		UMaterial* DefaultMaterial;

	UPROPERTY(VisibleDefaultsOnly, Category = "All Cell")
		TArray<class UStaticMeshComponent*> StaticMeshes;

	UFUNCTION()
		void Hightlight(UStaticMeshComponent* Mesh) { Mesh->SetMaterial(0, HightlightedMaterial); }

private:



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
