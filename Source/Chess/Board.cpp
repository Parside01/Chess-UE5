
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
	if (M_Hightlight.Object)  HightlightedMaterial = M_Hightlight.Object;


	for (int32 i{ 0 }; i < 8; i++)
	{
		for (int32 j{ 0 }; j < 8; j++)
		{
			TCHAR Char = 'A' + i;
			FString Letter = FString(FString::Chr(Char) + FString::FromInt(j));

			int32 k = i * j;
			int32 X = (k / 8) * 400;
			int32 Y = (k % 8) * 400;

			Board.Add(Letter, CreateDefaultSubobject<ACell>(*Letter));

			ACell* Cell = Board[Letter];
			Cell->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
		}
	}
}


void ABoard::BeginPlay()
{
	Super::BeginPlay();
}

