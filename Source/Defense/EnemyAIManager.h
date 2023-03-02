#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIManager.generated.h"

UCLASS()
class DEFENSE_API AEnemyAIManager : public AAIController {
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	class AActor* FinishLineManager;

};
