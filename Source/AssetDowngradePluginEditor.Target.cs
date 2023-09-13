// Copyright 2023 Naotsun. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class AssetDowngradePluginEditorTarget : TargetRules
{
	public AssetDowngradePluginEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
#if UE_5_2_OR_LATER
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
#endif
		ExtraModuleNames.Add("AssetDowngradePlugin");
	}
}
