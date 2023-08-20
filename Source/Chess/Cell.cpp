// Fill out your copyright notice in the Description page of Project Settings.


#include "Cell.h"

// Sets default values
ACell::ACell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	for (int32 i{ 0 }; i < 64; i++)
	{
		int32 X = (i / 8) * 400;
		int32 Y = (i % 8) * 400;

		StaticMeshes.Add(CreateDefaultSubobject<UStaticMeshComponent>(*FString("Mesh" + FString::FromInt(i))));
		StaticMeshes[i]->SetupAttachment(RootComponent);

		StaticMeshes[i]->SetStaticMesh(StaticMesh);

		StaticMeshes[i]->SetRelativeLocation(FVector(X, Y, 0));
	}
}

// Called when the game starts or when spawned
void ACell::BeginPlay()
{
	Super::BeginPlay();

	//check(StatickMesh);
	//check(LightMaterial);
	//check(DarkMaterial);
	//check(HightlightedMaterial);

	for (int32 i{ 0 }; i < 64; i++)
	{
		bool Result = XOR((((i / 8) % 2) == 0 ? false : true), (((i % 8) % 2) == 0 ? false : true));
		
		if (Result)
		{
			StaticMeshes[i]->SetMaterial(0, LightMaterial);
			DefaultMaterial = LightMaterial;
		}
		else
		{
			StaticMeshes[i]->SetMaterial(0, DarkMaterial);
			DefaultMaterial = DarkMaterial;
		}
	}
}

// Called every frame
void ACell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

