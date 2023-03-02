#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DefenderManager.generated.h"

UCLASS()
class DEFENSE_API ADefenderManager : public ACharacter {
	GENERATED_BODY()

public:
	ADefenderManager();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* DefenderTrigger;

	UPROPERTY()
	class AActor* Enemy;

	UFUNCTION()
	void DefenderOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};