// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Mantle/Library/CharacterEnumLibrary.h"
#include "MantleCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FJumpActionDelegate);

UCLASS(config=Game)
class AMantleCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	//Mantle Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UMantleComponent* MantleComponent;


public:
	AMantleCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	FJumpActionDelegate JumpPressedDelegate;

	//Character state
	UFUNCTION(BlueprintGetter, Category = "Character States")
	EMovementAction GetMovementAction() const { return MovementAction; }

	UFUNCTION(BlueprintGetter, Category = "Character States")
	EMovementState GetCurrentState() const { return CurrentState; }

	UFUNCTION(BlueprintGetter, Category = "Character States")
	EMovementState GetPrevState() const { return PrevState; }

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);


	void JumpPressedAction();

	void JumpReleasedAction();

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	UPROPERTY(BlueprintReadOnly, Category = "State Values")
	EMovementState CurrentState = EMovementState::None;
	UPROPERTY(BlueprintReadOnly, Category = "State Values")
	EMovementState PrevState = EMovementState::None;
	UPROPERTY(BlueprintReadOnly, Category = "State Values")
	EMovementAction MovementAction = EMovementAction::None;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

