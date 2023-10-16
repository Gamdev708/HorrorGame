// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTaskNode_Attack.h"

#include "AIController.h"
#include "GameFramework/Character.h"


EBTNodeResult::Type UBTTaskNode_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* MyController = OwnerComp.GetAIOwner();
	if (ensure(MyController))
	{
		ACharacter* MyPawn = Cast<ACharacter>(MyController->GetPawn());

		if (MyPawn == nullptr) { return EBTNodeResult::Failed; }

		UAnimInstance* AnimInstance = MyPawn->GetMesh()->GetAnimInstance();
		UE_LOG(LogTemp, Warning, TEXT("Attacking"));
		if (AnimInstance && Monatge)
		{
			AnimInstance->Montage_JumpToSection("Attack", Monatge);
			AnimInstance->Montage_Play(Monatge, 2.f);

			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
