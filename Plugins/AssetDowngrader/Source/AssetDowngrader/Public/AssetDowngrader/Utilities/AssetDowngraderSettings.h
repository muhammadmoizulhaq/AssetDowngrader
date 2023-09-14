// Copyright 2023 Naotsun. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AssetDowngraderSettings.generated.h"

/**
 * A editor preferences class for this plugin.
 */
UCLASS(Config = Editor, GlobalUserConfig)
class ASSETDOWNGRADER_API UAssetDowngraderSettings : public UObject
{
	GENERATED_BODY()

public:
	// Constructor.
	UAssetDowngraderSettings();
	
	// Registers-Unregisters in the editor setting item.
	static void Register();
	static void Unregister();

	// Returns reference of this settings.
	static UAssetDowngraderSettings& Get();
};
