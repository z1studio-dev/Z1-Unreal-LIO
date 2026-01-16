using UnrealBuildTool;

[SupportedTargetTypes(TargetType.Game, TargetType.Editor)]

public class LioCore : ModuleRules
{
    public LioCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "Slate",
                "InputCore",
                "InputDevice",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {

            }
        );
    }
}