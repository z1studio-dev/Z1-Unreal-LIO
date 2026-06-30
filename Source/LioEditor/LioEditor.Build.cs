using UnrealBuildTool;

public class LioEditor : ModuleRules
{
    public LioEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "LevelEditor",
                "ToolMenus",
                "UnrealEd",
                "InputCore",
                "Engine",
                "Slate",
                "SlateCore"
            }
        );
    }
}