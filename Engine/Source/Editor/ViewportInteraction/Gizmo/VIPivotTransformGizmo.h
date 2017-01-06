// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "VIBaseTransformGizmo.h"
#include "VIGizmoHandle.h"
#include "VIPivotTransformGizmo.generated.h"

/**
 * A transform gizmo on the pivot that allows you to interact with selected objects by moving, scaling and rotating.
 */
UCLASS()
class APivotTransformGizmo : public ABaseTransformGizmo
{
	GENERATED_BODY()

public:

	/** Default constructor that sets up CDO properties */
	APivotTransformGizmo();

	/** Called by the world interaction system after we've been spawned into the world, to allow
	    us to create components and set everything up nicely for the selected objects that we'll be
		used to manipulate */
	virtual void UpdateGizmo( const EGizmoHandleTypes GizmoType, const ECoordSystem GizmoCoordinateSpace, const FTransform& LocalToWorld, const FBox& LocalBounds, const FVector ViewLocation, const float ScaleMultiplier,
		bool bAllHandlesVisible, const bool bAllowRotationAndScaleHandles, class UActorComponent* DraggingHandle, const TArray< UActorComponent* >& HoveringOverHandles, const float GizmoHoverScale, const float GizmoHoverAnimationDuration ) override;

private:
	/** Uniform scale handle group component */
	UPROPERTY()
	class UUniformScaleGizmoHandleGroup* UniformScaleGizmoHandleGroup;

	/** Translation handle group component */
	UPROPERTY()
	class UPivotTranslationGizmoHandleGroup* TranslationGizmoHandleGroup;
	
	/** Scale handle group component */
	UPROPERTY()
	class UPivotScaleGizmoHandleGroup* ScaleGizmoHandleGroup;
	
	/** Plane translation handle group component */
	UPROPERTY()
	class UPivotPlaneTranslationGizmoHandleGroup* PlaneTranslationGizmoHandleGroup;

	/** Rotation handle group component */
	UPROPERTY()
	class UPivotRotationGizmoHandleGroup* RotationGizmoHandleGroup;

	/** Stretch handle group component */
	UPROPERTY()
	class UStretchGizmoHandleGroup* StretchGizmoHandleGroup;
};

/**
 * Axis Gizmo handle for translating
 */
UCLASS()
class UPivotTranslationGizmoHandleGroup : public UAxisGizmoHandleGroup
{
	GENERATED_BODY()

public:

	/** Default constructor that sets up CDO properties */
	UPivotTranslationGizmoHandleGroup();

	/** Updates the gizmo handles */
	virtual void UpdateGizmoHandleGroup( const FTransform& LocalToWorld, const FBox& LocalBounds, const FVector ViewLocation, class UActorComponent* DraggingHandle, const TArray< UActorComponent* >& HoveringOverHandles, 
		float AnimationAlpha, float GizmoScale, const float GizmoHoverScale, const float GizmoHoverAnimationDuration, bool& bOutIsHoveringOrDraggingThisHandleGroup ) override;

	/** Gets the InteractionType for this Gizmo handle */
	virtual ETransformGizmoInteractionType GetInteractionType() const override;

	/** Gets the GizmoType for this Gizmo handle */
	virtual EGizmoHandleTypes GetHandleType() const override;
};

/**
 * Axis Gizmo handle for scaling
 */
UCLASS()
class UPivotScaleGizmoHandleGroup : public UAxisGizmoHandleGroup
{
	GENERATED_BODY()

public:

	/** Default constructor that sets up CDO properties */
	UPivotScaleGizmoHandleGroup();

	/** Updates the gizmo handles */
	virtual void UpdateGizmoHandleGroup( const FTransform& LocalToWorld, const FBox& LocalBounds,  const FVector ViewLocation, class UActorComponent* DraggingHandle, const TArray< UActorComponent* >& HoveringOverHandles, 
		float AnimationAlpha, float GizmoScale, const float GizmoHoverScale, const float GizmoHoverAnimationDuration, bool& bOutIsHoveringOrDraggingThisHandleGroup ) override;

	/** Gets the InteractionType for this Gizmo handle */
	virtual ETransformGizmoInteractionType GetInteractionType() const override;

	/** Gets the GizmoType for this Gizmo handle */
	virtual EGizmoHandleTypes GetHandleType() const override;

	/** Returns true if this type of handle is allowed with world space gizmos */
	virtual bool SupportsWorldCoordinateSpace() const override;
};

/**
 * Axis Gizmo handle for plane translation
 */
UCLASS()
class UPivotPlaneTranslationGizmoHandleGroup : public UAxisGizmoHandleGroup
{
	GENERATED_BODY()

public:

	/** Default constructor that sets up CDO properties */
	UPivotPlaneTranslationGizmoHandleGroup();

	/** Updates the gizmo handles */
	virtual void UpdateGizmoHandleGroup( const FTransform& LocalToWorld, const FBox& LocalBounds, const FVector ViewLocation, class UActorComponent* DraggingHandle, const TArray< UActorComponent* >& HoveringOverHandles, 
		float AnimationAlpha, float GizmoScale, const float GizmoHoverScale, const float GizmoHoverAnimationDuration, bool& bOutIsHoveringOrDraggingThisHandleGroup ) override;

	/** Gets the InteractionType for this Gizmo handle */
	virtual ETransformGizmoInteractionType GetInteractionType() const override;

	/** Gets the GizmoType for this Gizmo handle */
	virtual EGizmoHandleTypes GetHandleType() const override;
};


/**
 * Axis Gizmo handle for rotation
 */
UCLASS()
class UPivotRotationGizmoHandleGroup : public UAxisGizmoHandleGroup
{
	GENERATED_BODY()

public:

	/** Default constructor that sets up CDO properties */
	UPivotRotationGizmoHandleGroup();

	/** Updates the gizmo handles */
	virtual void UpdateGizmoHandleGroup(const FTransform& LocalToWorld, const FBox& LocalBounds, const FVector ViewLocation, class UActorComponent* DraggingHandle, const TArray< UActorComponent* >& HoveringOverHandles, 
		float AnimationAlpha, float GizmoScale, const float GizmoHoverScale, const float GizmoHoverAnimationDuration, bool& bOutIsHoveringOrDraggingThisHandleGroup ) override;

	/** Gets the InteractionType for this Gizmo handle */
	virtual ETransformGizmoInteractionType GetInteractionType() const override;

	/** Gets the GizmoType for this Gizmo handle */
	virtual EGizmoHandleTypes GetHandleType() const override;

private:

	UPROPERTY()
	UStaticMeshComponent* FullRotationHandleMeshComponent;

	// The rotation of the owning transform gizmo when starting to use a rotation handle
	TOptional<FQuat> StartActorRotation;
};
