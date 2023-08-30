
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

							//VARIABLES//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
		UMaterial* LightMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
		UMaterial* DarkMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
		UMaterial* DarkHightlightMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
		UMaterial* LightHightlightMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
		UMaterial* DefaultHightlightMaterial;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Material")
		UMaterial* DefaultMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		TMap<FString, ACell*> Board;

							//VARIABLES//

	virtual void BeginPlay() override;

	void InitBoard();

public:	


							//FUNCTION//
	UFUNCTION()
		FORCEINLINE TMap<FString, ACell*> GetBoard() { return Board; }

	UFUNCTION()
		void HightlightCells(TArray<ACell*> HightlightCells);

	UFUNCTION()
		void RemoveHightlightCells(TArray<ACell*> HightlightCells);

	UFUNCTION()
		void RemoveAllHightlightCells();
							//FUNCTION//
};
