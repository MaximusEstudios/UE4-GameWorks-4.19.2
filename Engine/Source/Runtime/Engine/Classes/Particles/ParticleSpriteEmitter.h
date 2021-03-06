// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.


#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Particles/ParticleEmitter.h"
#include "ParticleSpriteEmitter.generated.h"

class UParticleSystemComponent;

UENUM()
enum EParticleScreenAlignment
{
	PSA_FacingCameraPosition,
	PSA_Square,
	PSA_Rectangle,
	PSA_Velocity,
	PSA_AwayFromCenter,
	PSA_TypeSpecific,
	PSA_FacingCameraDistanceBlend,
	PSA_MAX,
};

UCLASS(collapsecategories, hidecategories=Object, editinlinenew, MinimalAPI)
class UParticleSpriteEmitter : public UParticleEmitter
{
	GENERATED_UCLASS_BODY()


	//~ Begin UObject Interface
	ENGINE_API virtual void PostLoad() override;
	//~ End UObject Interface

	//~ Begin UParticleEmitter Interface
	ENGINE_API virtual FParticleEmitterInstance* CreateInstance(UParticleSystemComponent* InComponent) override;
	ENGINE_API virtual void SetToSensibleDefaults() override;
	//~ End UParticleEmitter Interface
};

