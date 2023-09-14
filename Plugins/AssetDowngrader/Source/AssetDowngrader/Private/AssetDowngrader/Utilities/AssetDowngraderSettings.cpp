// Copyright 2023 Naotsun. All Rights Reserved.

#include "AssetDowngrader/Utilities/AssetDowngraderSettings.h"
#include "Modules/ModuleManager.h"
#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "AssetDowngraderSettings"

namespace AssetDowngrader
{
	namespace Settings
	{
		static const FName ContainerName			= TEXT("Editor");
		static const FName CategoryName				= TEXT("Plugins");
		static const FName SectionName				= TEXT("AssetDowngraderSettings");

		ISettingsModule* GetSettingsModule()
		{
			return FModuleManager::GetModulePtr<ISettingsModule>(TEXT("Settings"));
		}
	}
}

UAssetDowngraderSettings::UAssetDowngraderSettings()
{
}

void UAssetDowngraderSettings::Register()
{
	if (ISettingsModule* SettingsModule = AssetDowngrader::Settings::GetSettingsModule())
	{
		SettingsModule->RegisterSettings(
			AssetDowngrader::Settings::ContainerName,
			AssetDowngrader::Settings::CategoryName,
			AssetDowngrader::Settings::SectionName,
			LOCTEXT("SettingName", "Asset Downgrader"),
			LOCTEXT("SettingDescription", "Editor settings for Asset Downgrader"),
			GetMutableDefault<UAssetDowngraderSettings>()
		);
	}
}

void UAssetDowngraderSettings::Unregister()
{
	if (ISettingsModule* SettingsModule = AssetDowngrader::Settings::GetSettingsModule())
	{
		SettingsModule->UnregisterSettings(
			AssetDowngrader::Settings::ContainerName,
			AssetDowngrader::Settings::CategoryName,
			AssetDowngrader::Settings::SectionName
		);
	}
}

UAssetDowngraderSettings& UAssetDowngraderSettings::Get()
{
	auto* Settings = GetMutableDefault<UAssetDowngraderSettings>();
	check(IsValid(Settings));
	return *Settings;
}

#undef LOCTEXT_NAMESPACE
