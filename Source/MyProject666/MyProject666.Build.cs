// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyProject666 : ModuleRules
{
	public MyProject666(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
