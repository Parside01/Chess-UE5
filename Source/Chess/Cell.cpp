// Fill out your copyright notice in the Description page of Project Settings.


#include "Cell.h"


ACell::ACell()
{
 
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Game/Meshes/Floor.Floor'"));
	if (StaticMeshAsset.Object) StaticMesh = StaticMeshAsset.Object;
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CEll"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	if(StaticMesh)
		StaticMeshComponent->SetStaticMesh(StaticMesh);

	NumCell++;
}


// Called when the game starts or when spawned
void ACell::BeginPlay()
{
	Super::BeginPlay();

	//for (int32 i{ 0 }; i < 64; i++)
	//{
	//	bool Result = XOR((((i / 8) % 2) == 0 ? false : true), (((i % 8) % 2) == 0 ? false : true));
	//	
	//	if (Result)
	//	{
	//		StaticMeshes[i]->SetMaterial(0, LightMaterial);
	//		DefaultMaterial = LightMaterial;
	//	}
	//	else
	//	{
	//		StaticMeshes[i]->SetMaterial(0, DarkMaterial);
	//		DefaultMaterial = DarkMaterial;
	//	}
	//}
}

void ACell::SetStaticMesh(UStaticMesh* NewMesh)
{
	StaticMeshComponent->SetStaticMesh(NewMesh);
}

