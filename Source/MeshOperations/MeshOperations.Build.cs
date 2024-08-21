// Some copyright should be here...

using System;
using System.IO;
using UnrealBuildTool;

public class MeshOperations : ModuleRules
{
	public MeshOperations(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        bEnableUndefinedIdentifierWarnings = false;
        bEnableExceptions = true;

        if (UnrealTargetPlatform.Win64 == Target.Platform)
        {
            bUseRTTI = true;

            /*
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "include"));
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKBin.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKBinL.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKBinTObj.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKBinXCAF.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKBO.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKBool.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKBRep.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKCAF.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKCDF.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKD3DHost.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKDCAF.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKDE.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKDECascade.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKDEGLTF.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKDEIGES.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKDEOBJ.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKDEPLY.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKDESTEP.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKDESTL.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKDEVRML.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKDFBrowser.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKDraw.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKernel.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKFeat.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKFillet.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKG2d.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKG3d.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKGeomAlgo.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKGeomBase.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKHLR.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKIVtk.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKIVtkDraw.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKLCAF.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKMath.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKMesh.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKMeshVS.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKMessageModel.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKMessageView.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKOffset.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKPrim.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKQADraw.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKRWMesh.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKService.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKShapeView.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKShHealing.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKStd.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKStdL.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKTInspector.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKTInspectorAPI.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKTObj.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKTObjDRAW.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKToolsDraw.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKTopAlgo.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKTreeModel.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKV3d.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKVCAF.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKView.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKVInspector.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXCAF.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXDEDRAW.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXMesh.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXml.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXmlL.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXmlTObj.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXmlXCAF.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXSBase.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXSDRAW.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXSDRAWDE.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXSDRAWGLTF.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXSDRAWIGES.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXSDRAWOBJ.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXSDRAWPLY.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXSDRAWSTEP.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXSDRAWSTL.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "lib", "TKXSDRAWVRML.lib"));

            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKBin.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKBinL.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKBinTObj.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKBinXCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKBO.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKBool.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKBRep.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKCDF.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKD3DHost.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKDCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKDE.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKDECascade.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKDEGLTF.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKDEIGES.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKDEOBJ.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKDEPLY.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKDESTEP.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKDESTL.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKDEVRML.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKDFBrowser.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKDraw.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKernel.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKFeat.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKFillet.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKG2d.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKG3d.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKGeomAlgo.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKGeomBase.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKHLR.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKIVtk.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKIVtkDraw.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKLCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKMath.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKMesh.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKMeshVS.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKMessageModel.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKMessageView.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKOffset.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKPrim.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKQADraw.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKRWMesh.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKService.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKShapeView.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKShHealing.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKStd.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKStdL.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKTInspector.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKTInspectorAPI.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKTObj.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKTObjDRAW.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKToolsDraw.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKTopAlgo.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKTreeModel.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKV3d.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKVCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKView.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKVInspector.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXDEDRAW.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXMesh.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXml.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXmlL.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXmlTObj.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXmlXCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXSBase.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXSDRAW.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXSDRAWDE.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXSDRAWGLTF.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXSDRAWIGES.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXSDRAWOBJ.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXSDRAWPLY.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXSDRAWSTEP.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXSDRAWSTL.dll"));
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "TKXSDRAWVRML.dll"));

            
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKBin.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKBinL.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKBinTObj.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKBinXCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKBO.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKBool.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKBRep.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKCDF.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKD3DHost.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKDCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKDE.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKDECascade.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKDEGLTF.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKDEIGES.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKDEOBJ.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKDEPLY.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKDESTEP.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKDESTL.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKDEVRML.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKDFBrowser.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKDraw.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKernel.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKFeat.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKFillet.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKG2d.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKG3d.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKGeomAlgo.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKGeomBase.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKHLR.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKIVtk.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKIVtkDraw.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKLCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKMath.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKMesh.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKMeshVS.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKMessageModel.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKMessageView.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKOffset.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKPrim.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKQADraw.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKRWMesh.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKService.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKShapeView.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKShHealing.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKStd.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKStdL.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKTInspector.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKTInspectorAPI.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKTObj.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKTObjDRAW.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKToolsDraw.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKTopAlgo.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKTreeModel.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKV3d.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKVCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKView.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKVInspector.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXDEDRAW.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXMesh.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXml.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXmlL.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXmlTObj.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXmlXCAF.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXSBase.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXSDRAW.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXSDRAWDE.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXSDRAWGLTF.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXSDRAWIGES.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXSDRAWOBJ.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXSDRAWPLY.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXSDRAWSTEP.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXSDRAWSTL.dll"));
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "ThirdParty", "occt", "Win64", "bin", "TKXSDRAWVRML.dll"));

            PublicDelayLoadDLLs.Add("TKBin.dll");
            PublicDelayLoadDLLs.Add("TKBinL.dll");
            PublicDelayLoadDLLs.Add("TKBinTObj.dll");
            PublicDelayLoadDLLs.Add("TKBinXCAF.dll");
            PublicDelayLoadDLLs.Add("TKBO.dll");
            PublicDelayLoadDLLs.Add("TKBool.dll");
            PublicDelayLoadDLLs.Add("TKBRep.dll");
            PublicDelayLoadDLLs.Add("TKCAF.dll");
            PublicDelayLoadDLLs.Add("TKCDF.dll");
            PublicDelayLoadDLLs.Add("TKD3DHost.dll");
            PublicDelayLoadDLLs.Add("TKDCAF.dll");
            PublicDelayLoadDLLs.Add("TKDE.dll");
            PublicDelayLoadDLLs.Add("TKDECascade.dll");
            PublicDelayLoadDLLs.Add("TKDEGLTF.dll");
            PublicDelayLoadDLLs.Add("TKDEIGES.dll");
            PublicDelayLoadDLLs.Add("TKDEOBJ.dll");
            PublicDelayLoadDLLs.Add("TKDEPLY.dll");
            PublicDelayLoadDLLs.Add("TKDESTEP.dll");
            PublicDelayLoadDLLs.Add("TKDESTL.dll");
            PublicDelayLoadDLLs.Add("TKDEVRML.dll");
            PublicDelayLoadDLLs.Add("TKDFBrowser.dll");
            PublicDelayLoadDLLs.Add("TKDraw.dll");
            PublicDelayLoadDLLs.Add("TKernel.dll");
            PublicDelayLoadDLLs.Add("TKFeat.dll");
            PublicDelayLoadDLLs.Add("TKFillet.dll");
            PublicDelayLoadDLLs.Add("TKG2d.dll");
            PublicDelayLoadDLLs.Add("TKG3d.dll");
            PublicDelayLoadDLLs.Add("TKGeomAlgo.dll");
            PublicDelayLoadDLLs.Add("TKGeomBase.dll");
            PublicDelayLoadDLLs.Add("TKHLR.dll");
            PublicDelayLoadDLLs.Add("TKIVtk.dll");
            PublicDelayLoadDLLs.Add("TKIVtkDraw.dll");
            PublicDelayLoadDLLs.Add("TKLCAF.dll");
            PublicDelayLoadDLLs.Add("TKMath.dll");
            PublicDelayLoadDLLs.Add("TKMesh.dll");
            PublicDelayLoadDLLs.Add("TKMeshVS.dll");
            PublicDelayLoadDLLs.Add("TKMessageModel.dll");
            PublicDelayLoadDLLs.Add("TKMessageView.dll");
            PublicDelayLoadDLLs.Add("TKOffset.dll");
            PublicDelayLoadDLLs.Add("TKPrim.dll");
            PublicDelayLoadDLLs.Add("TKQADraw.dll");
            PublicDelayLoadDLLs.Add("TKRWMesh.dll");
            PublicDelayLoadDLLs.Add("TKService.dll");
            PublicDelayLoadDLLs.Add("TKShapeView.dll");
            PublicDelayLoadDLLs.Add("TKShHealing.dll");
            PublicDelayLoadDLLs.Add("TKStd.dll");
            PublicDelayLoadDLLs.Add("TKStdL.dll");
            PublicDelayLoadDLLs.Add("TKTInspector.dll");
            PublicDelayLoadDLLs.Add("TKTInspectorAPI.dll");
            PublicDelayLoadDLLs.Add("TKTObj.dll");
            PublicDelayLoadDLLs.Add("TKTObjDRAW.dll");
            PublicDelayLoadDLLs.Add("TKToolsDraw.dll");
            PublicDelayLoadDLLs.Add("TKTopAlgo.dll");
            PublicDelayLoadDLLs.Add("TKTreeModel.dll");
            PublicDelayLoadDLLs.Add("TKV3d.dll");
            PublicDelayLoadDLLs.Add("TKVCAF.dll");
            PublicDelayLoadDLLs.Add("TKView.dll");
            PublicDelayLoadDLLs.Add("TKVInspector.dll");
            PublicDelayLoadDLLs.Add("TKXCAF.dll");
            PublicDelayLoadDLLs.Add("TKXDEDRAW.dll");
            PublicDelayLoadDLLs.Add("TKXMesh.dll");
            PublicDelayLoadDLLs.Add("TKXml.dll");
            PublicDelayLoadDLLs.Add("TKXmlL.dll");
            PublicDelayLoadDLLs.Add("TKXmlTObj.dll");
            PublicDelayLoadDLLs.Add("TKXmlXCAF.dll");
            PublicDelayLoadDLLs.Add("TKXSBase.dll");
            PublicDelayLoadDLLs.Add("TKXSDRAW.dll");
            PublicDelayLoadDLLs.Add("TKXSDRAWDE.dll");
            PublicDelayLoadDLLs.Add("TKXSDRAWGLTF.dll");
            PublicDelayLoadDLLs.Add("TKXSDRAWIGES.dll");
            PublicDelayLoadDLLs.Add("TKXSDRAWOBJ.dll");
            PublicDelayLoadDLLs.Add("TKXSDRAWPLY.dll");
            PublicDelayLoadDLLs.Add("TKXSDRAWSTEP.dll");
            PublicDelayLoadDLLs.Add("TKXSDRAWSTL.dll");
            PublicDelayLoadDLLs.Add("TKXSDRAWVRML.dll");
            */
        }

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                // ... add other public dependencies that you statically link with here ...
				"Core",
			}
			);
			
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "GLTFExporter",
                "RHI",
                "RenderCore",
                "MeshDescription",
                "StaticMeshDescription",
                "MeshConversion",
                "ProceduralMeshComponent",
				//"Projects",
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
