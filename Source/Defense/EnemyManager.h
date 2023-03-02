#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyManager.generated.h"

UCLASS()
class DEFENSE_API AEnemyManager : public ACharacter {
	GENERATED_BODY()

public:
	AEnemyManager();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* EnemyTrigger;

	UFUNCTION()
	void EnemyOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
