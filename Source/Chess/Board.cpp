
#include "Board.h"

#include "Cell.h"

ABoard::ABoard()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial> M_Light(TEXT("Material'/Game/Materials/M_Wood_Pine.M_Wood_Pine'"));
	if (M_Light.Object) LightMaterial = M_Light.Object;

	static ConstructorHelpers::FObjectFinder<UMaterial> M_Dark(TEXT("Material'/Game/Materials/M_Wood_Walnut.M_Wood_Walnut'"));
	if (M_Dark.Object) DarkMaterial = M_Dark.Object;

	static ConstructorHelpers::FObjectFinder<UMaterial> M_Hightlight(TEXT("Material'/Game/Materials/M_SelectedMaterial.M_SelectedMaterial'"));
	if (M_Hightlight.Object) DefaultHightlightMaterial = M_Hightlight.Object;
}


void ABoard::BeginPlay()
{
	Super::BeginPlay();
	InitBoard();
}

void ABoard::InitBoard()
{
	for (int32 i{ 0 }; i < 8; i++)
	{
		for (int32 j{ 0 }; j < 8; j++)
		{
			TCHAR Char = 'A' + i;
			FString Letter = FString(FString::Chr(Char) + FString::FromInt(j));

			int32 k = (i * 8) + j;
			int32 X = (k / 8) * 400;
			int32 Y = (k % 8) * 400;

			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			ACell* Cell = GetWorld()->SpawnActor<ACell>(ACell::StaticClass(), FVector(X, Y, 0), FRotator(0), SpawnParams);

			if (Cell)
			{
				Board.Add(Letter, Cell);
				Cell->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);

				Cell->SetActorRelativeLocation(FVector(X, Y, 0));

				bool Result = XOR((((k / 8) % 2) == 0 ? false : true), (((k % 8) % 2) == 0 ? false : true));

				if (Result)
				{
					Cell->SetMaterial(LightMaterial);
					Cell->bIsWhite = true;
				}
				else
				{
					Cell->bIsWhite = false;
					Cell->SetMaterial(DarkMaterial);
				}
			}
		}
	}
}

void ABoard::HightlightCells(TArray<ACell*> HightlightCells)
{
	if (HightlightCells.IsEmpty()) return;
	for (int32 i{ 0 }; i < HightlightCells.Num(); i++)
	{
		if (LightHightlightMaterial && DarkHightlightMaterial)
		{
			HightlightCells[i]->GetCurrentMaterial() == DarkMaterial ? HightlightCells[i]->SetMaterial(LightHightlightMaterial)
				: HightlightCells[i]->SetMaterial(DarkHightlightMaterial);
		}
		else
		{
			HightlightCells[i]->SetMaterial(DefaultHightlightMaterial);
		}
	}
}

void ABoard::RemoveHightlightCells(TArray<ACell*> RemoveHightlightCells)
{
	if (RemoveHightlightCells.IsEmpty()) return;
	for (int32 i{ 0 }; i < RemoveHightlightCells.Num(); i++)
	{
		RemoveHightlightCells[i]->bIsWhite ? RemoveHightlightCells[i]->SetMaterial(LightMaterial) : RemoveHightlightCells[i]->SetMaterial(DarkMaterial);
	}
}

void ABoard::RemoveAllHightlightCells()
{
	for (int32 i{ 0 }; i < 8; i++)
	{
		for (int32 j{ 0 }; j < 8; j++)
		{
			int32 k = (i * 8) + j;
			TCHAR Char = 'A' + i;
			FString Letter = FString(FString::Chr(Char) + FString::FromInt(j));
			ACell* Cell = Board[Letter];
			
			if (!Cell) break;
			bool Result = XOR((((k / 8) % 2) == 0 ? false : true), (((k % 8) % 2) == 0 ? false : true));

			if (Result)
			{
				Cell->SetMaterial(LightMaterial);
			}
			else
			{
				Cell->SetMaterial(DarkMaterial);
			}
		}
	}
}

