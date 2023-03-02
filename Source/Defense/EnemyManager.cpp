#include "EnemyManager.h"
#include "Components/CapsuleComponent.h"

AEnemyManager::AEnemyManager() {
	PrimaryActorTick.bCanEverTick = true;

	EnemyTrigger = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Enemy Trigger"));
	EnemyTrigger->SetCollisionProfileName(TEXT("OverlapAll"));
	EnemyTrigger->SetGenerateOverlapEvents(true);
	EnemyTrigger->OnComponentBeginOverlap.AddDynamic(this, &AEnemyManager::EnemyOverlap);
	EnemyTrigger->SetupAttachment(RootComponent);
}

void AEnemyManager::BeginPlay() {
	Super::BeginPlay();
}

void AEnemyManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AEnemyManager::EnemyOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

}

void AEnemyManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
