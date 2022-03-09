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
- Delete Empty Parents (It will create New StaticMeshComp with -N suffix and attachs it to it's original grandparent.
It can process all static meshes but it's not recursive. So, if there are more than one middle parent for a static mesh, it does not delete other ones.
--------------------------------------------------------------------------------------------
Expriment:
- PositionVertexBuffer requires GameThread for RHI based reasons.
- Right now, when we change Recursive's AsyncTask thread to any other thread than GameThread, editor crashes.
- Because GetVertexLocations use PositionVertexBuffer.
- So, we will convert PositionVertexBuffer to GetNumberOfSections > For Loop > GetSectionFromStaticMesh.
- If it and EditableMesh support other threads, we will continue to use it.
--------------------------------------------------------------------------------------------
ROADMAP:
- Async DeleteEmpotyRoots
- Async DeleteEmptyParents

NOTICE !
- This plugins created for internal CAD based simulation projects.
- When UE5 is publised we will update it. Especially MovePivotToCenter (Because it is one of the most important part for us.)
- Also we can create new features when we saw Geometry Scripting and other native plugins.
