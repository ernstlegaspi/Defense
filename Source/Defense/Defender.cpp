#include "Defender.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

ADefender::ADefender() {
	PrimaryActorTick.bCanEverTick = true;

	DefenderTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Defender Trigger"));
	DefenderTrigger->SetCollisionProfileName(TEXT("OverlapAll"));
	DefenderTrigger->SetGenerateOverlapEvents(true);
	DefenderTrigger->OnComponentBeginOverlap.AddDynamic(this, &ADefender::DefenderEnterOverlap);
	DefenderTrigger->OnComponentEndOverlap.AddDynamic(this, &ADefender::DefenderExitOverlap);
	DefenderTrigger->SetupAttachment(RootComponent);

	Staff = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Staff"));
	Staff->SetupAttachment(GetMesh(), FName("WeaponSocket"));
}

void ADefender::BeginPlay() {
	Super::BeginPlay();

	Enemy = nullptr;
	AnimInstance = GetMesh()->GetAnimInstance();
}

void ADefender::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if(Enemy != nullptr) {
		if(AnimInstance->Montage_IsPlaying(AM_Idle)) AnimInstance->Montage_Stop(0, AM_Idle);

		if(!AnimInstance->Montage_IsPlaying(AM_Attack)) {
			AnimInstance->Montage_Play(AM_Attack);
		}

		SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Enemy->GetActorLocation()));
	}
	else {
		if(AnimInstance->Montage_IsPlaying(AM_Attack)) AnimInstance->Montage_Stop(0, AM_Attack);

		if(!AnimInstance->Montage_IsPlaying(AM_Idle)) {
			AnimInstance->Montage_Play(AM_Idle);
		}
	}
}

void ADefender::DefenderEnterOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if(OtherActor->GetName().Contains("Enemy") && Enemy == nullptr) {
		Enemy = OtherActor;
		AEnemy = Enemy;
	}
}

void ADefender::DefenderExitOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	if(OtherActor->GetName().Contains("Enemy") && Enemy != nullptr) {
		// Enemy = nullptr;
	}
}


void ADefender::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}