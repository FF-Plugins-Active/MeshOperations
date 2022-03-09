# MeshOperations

- Get Vertex Locations (From FPositionVertexBuffer)
- Move Pivot To New Location (with EditableMesh -> It will be converted to Dynamic Mesh from Geometry Scripting when UE5 is ready)
- Recursive Move Pivot To Center (It uses Move Pivot To New Location inside an AsyncTask for loop)
--------------------------------------------------------------------------------------------
- Add Scene Component with Name
- Add Static Mesh Component with Name
- Add Procedural Mesh Component with Name
--------------------------------------------------------------------------------------------
- Get Class Name
- Get Object Name of Packaged Build
--------------------------------------------------------------------------------------------
- Delete Empty Roots
- Delete Empty Parents
--------------------------------------------------------------------------------------------
Expriment:
PositionVertexBuffer requires gamethread for RHI reasons.
So we will convert it to GetNumberOfSections >For Loop > GetSectionFromStaticMesh
If it and EditableMesh supports other threads, we will use it for RecursiveMethod

--------------------------------------------------------------------------------------------
ROADMAP:
Async DeleteEmpotyRoots
Async DeleteEmptyParents

This plugins created for internal CAD based simulation projects. When UE5 is publised we will update it.
Especially MovePivotToCenter (because it is one of the most important part for us.)
