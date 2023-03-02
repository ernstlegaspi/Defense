#include "EnemyAIManager.h"
#include "FinishLineManager.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"

void AEnemyAIManager::BeginPlay() {
	Super::BeginPlay();

	FinishLineManager = (AFinishLineManager*)UGameplayStatics::GetActorOfClass(GetWorld(), AFinishLineManager::StaticClass());
}

void AEnemyAIManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	MoveToLocation(FinishLineManager->GetActorLocation());
}