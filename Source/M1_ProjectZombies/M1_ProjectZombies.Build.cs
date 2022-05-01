// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class M1_ProjectZombies : ModuleRules
{
	public M1_ProjectZombies(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "AIModule" });
	}
}
