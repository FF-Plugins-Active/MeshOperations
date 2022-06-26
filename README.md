# MeshOperations

Editable mesh component deprecated at UE5 and we need to re-create vertex functions with
Position Vertex Buffer. Most of function is ready but we need to create a vector math
to retain original positions and also we need to test it with complex CAD based meshes.

After that we will create a new Github repo as Vertex Operations.
--------------------------------------------------------------------------------------------
- Add Scene Component with Name
- Add Static Mesh Component with Name
- Add Procedural Mesh Component with Name
- Create Procedural Mesh from Static Mesh (Helper function)
--------------------------------------------------------------------------------------------
- Get Class Name
- Get Object Name of Packaged Build
--------------------------------------------------------------------------------------------
- Optimize Assembly Center
- Optimize Assembly Height
- Record Transforms
- Delete Empty Roots
- Delete Empty Parents Recursive (AC_Rename)
- Rename Object (AC_Rename)
--------------------------------------------------------------------------------------------
STATE:
- UE5 Ready

USED PLUGINS and DEPENDENCIES:
- Procedural Mesh Component
- KismetProceduralMeshLibrary

PURPOSE:
- This plugin created for "our" startup's internal "CAD" projects !
- So, we will update it with "our needs" and right now we have other project priorities.

PLATFORM SUPPORT:
- Plugin is for UE5 and Windows platform. We didn't try other platforms.

CONTRIBUTIONS:
- If you know better approaches feel free to give pull requests. We will appreciate (or even pay) for your contributions.
