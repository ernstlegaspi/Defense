#include "DefenderManager.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"

ADefenderManager::ADefenderManager() {
	PrimaryActorTick.bCanEverTick = true;

	DefenderTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Defender Trigger"));
	DefenderTrigger->SetCollisionProfileName(TEXT("OverlapAll"));
	DefenderTrigger->SetGenerateOverlapEvents(true);
	DefenderTrigger->SetupAttachment(RootComponent);
}

void ADefenderManager::BeginPlay() {
	Super::BeginPlay();

	Enemy = nullptr;
	AnimInstance = GetMesh()->GetAnimInstance();

	DefenderTrigger->OnComponentBeginOverlap.AddDynamic(this, &ADefenderManager::DefenderEnterOverlap);
	DefenderTrigger->OnComponentEndOverlap.AddDynamic(this, &ADefenderManager::DefenderExitOverlap);
}

void ADefenderManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if(Enemy != nullptr) {
		if(AnimInstance->Montage_IsPlaying(AM_Idle)) AnimInstance->Montage_Stop(.3f, AM_Idle);

		if(!AnimInstance->Montage_IsPlaying(AM_Attack)) {
			AnimInstance->Montage_Play(AM_Attack);
		}

		SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Enemy->GetActorLocation()));
	}
	else {
		if(!AnimInstance->Montage_IsPlaying(AM_Idle)) {
			AnimInstance->Montage_Play(AM_Idle);
		}
	}
}

void ADefenderManager::DefenderEnterOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if(OtherActor->GetName().Contains("Enemy") && Enemy == nullptr) {
		Enemy = OtherActor;
	}
}

void ADefenderManager::DefenderExitOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	if(OtherActor->GetName().Contains("Enemy") && Enemy != nullptr) {
		Enemy = nullptr;
	}
}

void ADefenderManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}