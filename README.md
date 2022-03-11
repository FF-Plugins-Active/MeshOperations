# MeshOperations

- Get Vertex Locations (From FPositionVertexBuffer)
- Move Pivot To New Location (with EditableMesh -> It will be converted to Dynamic Mesh from Geometry Scripting when UE5 is ready)
- Recursive Move Pivot To Center (It uses Move Pivot To New Location inside an AsyncTask for loop)
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
NOTICE !
- This plugins created for internal CAD based simulation projects.
- When UE5 is publised we will update it. Especially MovePivotToCenter (Because it is one of the most important part for us.)
- Also we can create new features when we saw Geometry Scripting and other native plugins.
