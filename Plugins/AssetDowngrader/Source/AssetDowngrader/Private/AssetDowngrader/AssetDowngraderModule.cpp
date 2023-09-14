// Copyright 2023 Naotsun. All Rights Reserved.

#include "AssetDowngrader/IAssetDowngrader.h"
#include "AssetDowngrader/Utilities/AssetDowngraderSettings.h"

namespace AssetDowngrader
{
	const FName IAssetDowngrader::ModuleName = TEXT("AssetDowngrader");
	
	class FAssetDowngraderModule : public IAssetDowngrader
	{
	public:
		// IModuleInterface interface.
		virtual void StartupModule() override;
		virtual void ShutdownModule() override;
		// End of IModuleInterface interface.

		// IAssetDowngraderr interface.
		
		// End of IAssetDowngrader interface.
	};

	void FAssetDowngraderModule::StartupModule()
	{
		// Register settings.
		UAssetDowngraderSettings::Register();
	}

	void FAssetDowngraderModule::ShutdownModule()
	{
		// Unregister settings.
		UAssetDowngraderSettings::Unregister();
	}
}
	
IMPLEMENT_MODULE(AssetDowngrader::FAssetDowngraderModule, AssetDowngrader)