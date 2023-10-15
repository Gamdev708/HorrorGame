// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"


class UAIPerceptionComponent;


/**
 * 
 */
UCLASS()
class HORRORGAME_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, Category = "AI") UBehaviorTree* BehaviorTree;
	FGenericTeamId TeamId;

public:
	AEnemyAIController();
	virtual FGenericTeamId GetGenericTeamId() const override ;
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
};
