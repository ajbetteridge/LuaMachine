// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LuaState.h"
#include "LuaValue.h"
#include "LuaComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LUAMACHINE_API ULuaComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULuaComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void InitializeComponent() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ULuaState> LuaState;

	UPROPERTY(EditAnywhere)
	TMap<FString, FLuaValue> Table;

	UPROPERTY(EditAnywhere)
	TMap<FString, FLuaValue> Metatable;

	UPROPERTY(EditAnywhere)
	bool bLazy;

	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "Args"))
	FLuaValue LuaCallFunction(FString FunctionName, TArray<FLuaValue> Args);
	
};
