// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyAIController.h"

#include "HorrorGame/HorrorGameCharacter.h"
#include "Perception/AIPerceptionComponent.h"

AEnemyAIController::AEnemyAIController()
{
	TeamId = FGenericTeamId(2);

	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("AIPerception");

}
void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();


	if (ensureAlwaysMsgf(BehaviorTree, TEXT("Behaviour Tree is Nullptr!. Please assign BehaviorTree in EnemyAIController")))
	{
		RunBehaviorTree(BehaviorTree);
	}
}



FGenericTeamId AEnemyAIController::GetGenericTeamId() const
{
	return TeamId;
}

ETeamAttitude::Type AEnemyAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	UE_LOG(LogTemp, Warning, TEXT("GetTeamAttitudeTowards"));
	if (const IGenericTeamAgentInterface* Player = Cast<IGenericTeamAgentInterface>(&Other))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player"));
		if (Player->GetGenericTeamId() != TeamId)
		{
			return ETeamAttitude::Hostile;
		}
	}
	return ETeamAttitude::Neutral;
}
