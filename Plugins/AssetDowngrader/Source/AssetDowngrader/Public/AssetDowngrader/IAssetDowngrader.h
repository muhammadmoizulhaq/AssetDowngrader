// Copyright 2023 Naotsun. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

namespace AssetDowngrader
{
	/**
	 * The public interface to the GraphMinimap module.
	 */
	class IAssetDowngrader : public IModuleInterface
	{
	public:
		// The name of the module for this plugin.
		ASSETDOWNGRADER_API static const FName ModuleName;
		
	public:
		// Returns singleton instance, loading the module on demand if needed.
		static IAssetDowngrader& Get()
		{
			return FModuleManager::LoadModuleChecked<IAssetDowngrader>(ModuleName);
		}

		// Returns whether the module is loaded and ready to use.
		static bool IsAvailable()
		{
			return FModuleManager::Get().IsModuleLoaded(ModuleName);
		}
	};
}
