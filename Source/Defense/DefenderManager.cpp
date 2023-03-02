#include "DefenderManager.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

ADefenderManager::ADefenderManager() {
	PrimaryActorTick.bCanEverTick = true;

	DefenderTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Defender Trigger"));
	DefenderTrigger->SetCollisionProfileName(TEXT("OverlapAll"));
	DefenderTrigger->SetGenerateOverlapEvents(true);
	DefenderTrigger->OnComponentBeginOverlap.AddDynamic(this, &ADefenderManager::DefenderOverlap);
	DefenderTrigger->SetupAttachment(RootComponent);
}

void ADefenderManager::BeginPlay() {
	Super::BeginPlay();

	Enemy = nullptr;
}

void ADefenderManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if(Enemy != nullptr) UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Enemy->GetActorLocation());
}

void ADefenderManager::DefenderOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if(OtherActor->GetName().Contains("Enemy") && Enemy == nullptr) {
		Enemy = OtherActor;
	}
}

void ADefenderManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}