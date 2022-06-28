# MeshOperations

Editable mesh component deprecated at UE5 and most of geometry script functions are editor only.
For this reason, we created a new plugin for vertex operations with "Position Vertex Buffer".
Rightnow render result is correct but we need to work on collisions. So it is not production ready.

Vertex Operations Plugin
https://github.com/FF-Projects-UE/VertexOperations

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

PLATFORM SUPPORT:
- Plugin is for UE5 and Windows platform. We didn't try other platforms.

CONTRIBUTIONS:
- If you know better approaches feel free to give pull requests. We will appreciate (or even pay) for your contributions.
