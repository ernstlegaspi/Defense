#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Defender.generated.h"

UCLASS()
class DEFENSE_API ADefender : public ACharacter {
	GENERATED_BODY()

public:
	ADefender();

	UPROPERTY()
	class AActor* AEnemy;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> FireballToSpawn;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* AM_Idle;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* AM_Attack;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* DefenderTrigger;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Staff;

	UPROPERTY()
	class AActor* Enemy;

	UPROPERTY()
	class UAnimInstance* AnimInstance;

	UFUNCTION()
	void DefenderEnterOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void DefenderExitOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};