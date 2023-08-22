
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Board.generated.h"

UCLASS()
class CHESS_API ABoard : public AActor
{
	GENERATED_BODY()
	
public:	

	ABoard();

protected:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
		UMaterial* LightMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
		UMaterial* DarkMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
		UMaterial* HightlightedMaterial;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Material")
		UMaterial* DefaultMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		TMap<FString, ACell*> Board;

	virtual void BeginPlay() override;

	void InitBoard();

public:	

	UFUNCTION()
		FORCEINLINE TMap<FString, ACell*> GetBoard() { return Board; }

};
