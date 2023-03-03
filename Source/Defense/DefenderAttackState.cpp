#include "DefenderAttackState.h"
#include "Defender.h"

void UDefenderAttackState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) {
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if(ADefender* Defender = Cast<ADefender>(MeshComp->GetOwner())) {
		Defender->World->SpawnActor<AActor>(Defender->Fireball, Defender->GetActorTransform());
	}
}

void UDefenderAttackState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) {
	Super::NotifyEnd(MeshComp, Animation, EventReference);
}