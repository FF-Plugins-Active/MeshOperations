# MeshOperations

- Get Vertices Locations 1 (From FPositionVertexBuffer)
- Get Vertices Locations 2 (From EditableMesh->GetMeshDescription()->VertexAttributes)
- Set Vertex Locations (Derivative from MoveVertices without Array for VerticesToMove ForLoop)
- Move Pivot To New Location (with EditableMesh -> It will be converted to Dynamic Mesh from Geometry Scripting when UE5 is ready)
- Recursive Move Pivot To Center (It uses Move Pivot To New Location)
--------------------------------------------------------------------------------------------
- Add Scene Component with Name
- Add Static Mesh Component with Name
- Add Procedural Mesh Component with Name
- Create Procedural Mesh from Static Mesh (Helper function)
--------------------------------------------------------------------------------------------
- Get Class Name
- Get Object Name of Packaged Build
--------------------------------------------------------------------------------------------
- Delete Empty Roots
- Delete Empty Parents Recursive (AC_Rename)
- Rename Object (AC_Rename)
--------------------------------------------------------------------------------------------
STATE:
- Beta but you can use it with projects.
- Look at "Issues" before using it !

USED PLUGINS and DEPENDENCIES:
- Procedural Mesh Component
- KismetProceduralMeshLibrary
- EditableMesh
- EditableMeshFactory.h
- MeshDescription
- StaticMeshAttributes
- RHI
- RenderCore
- Kismet/KismetMathLibrary
- Math/Vector

ROADMAP:
- BUGFIX: Correct static mesh offset calculations for retaining original transforms. (Move Pivot Functions)

PURPOSE:
- This plugin created for "our" startup's internal "CAD" projects !
- So, we will update it with "our needs" and rightnow we have other project priorities.

UPDATES:
- UE5 doesn't have "EditableMesh" native plugin. It has DynamicMesh, Geometry Scripting and Geometry Process plugins.
- When UE5 finally (not preview ones) out, we are going to update and improve it after figuring out new plugins.

PLATFORM SUPPORT:
- We didn't use any 3rd party plugins.
- So, it should work on any platform other than HTML5 (Deprecated at 4.24). But some plugins (for example Datasmith Runtime and USDZ Runtime) don't support other than Windows. If that happens, plugin won't work and we can't help.
- Our startup's primary operating system is Microsoft Windows and secondary one is Android (Oculus Quest 2). So we can't help for other than these.  

CONTRIBUTIONS:
- If you know better approaches feel free to give pull requests. We will appreciate (or even pay) for your contributions.