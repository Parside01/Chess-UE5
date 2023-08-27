

#include "ChessPlayer.h"
#include "ChessController.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AChessPlayer::AChessPlayer()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->TargetArmLength = 500.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}


void AChessPlayer::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<AChessController>(GetController());
	if (PlayerController) GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, TEXT("BEBMLEMB"));
}

void AChessPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AChessPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("LeftClick", IE_Pressed, PlayerController, &AChessController::LeftMouseClick);

}

