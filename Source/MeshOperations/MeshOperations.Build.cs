// Some copyright should be here...

using UnrealBuildTool;

public class MeshOperations : ModuleRules
{
	public MeshOperations(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		PublicDependencyModuleNames.AddRange(
            new string[]
            {
                // ... add other public dependencies that you statically link with here ...
				"Core",
				"ProceduralMeshComponent",
				"RHI",						// GetVertexLocations (FPositionVertexBuffer)
				"RenderCore",				// GetVertexLocations (FPositionVertexBuffer)
				"EditableMesh",
				"MeshDescription",
				//"GeometricObjects",
				//"DynamicMesh",
				//"ModelingComponents"
			}
			);
			
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				//"StaticMeshDescription",
				//"GeometryAlgorithms",
				//"MeshConversion",
				// ... add private dependencies that you statically link with here ...	
			}
			);
			
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
