// Copyright 2023 Naotsun. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class AssetDowngradePluginTarget : TargetRules
{
	public AssetDowngradePluginTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
#if UE_5_2_OR_LATER
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
#endif
		ExtraModuleNames.Add("AssetDowngradePlugin");
	}
}
