# WaterType - SKSE64 Plugin

This plugin exposes the WaterType form to Papyrus. WaterType has two methods to get and set the `dangerous` flag:

	bool Function GetIsDangerous() native
	Function SetIsDangerous(bool dangerous) native

The `dangerous` flag does nothing by itself is used by the `IsInDangerousWater` condition function.
This function returns TRUE whenever an actor sets foot in `dangerous` water, even when not swimming.
The related condition function `IsSwimming` only detects actors who are swimming in water. This small distinction opens up new game play possibilities.

Although the flag can be set in the Creation Kit, this introduces incompatibilities with every single plugin that also modifies waters (for instance, Realistic Water Two SE).
The `SetIsDangerous` method allows a plugin to be completely compatible by setting the flag by script instead.
The script must run every time a game is loaded because changes to the WaterType forms are not persisted in the save file.

This plugin only works with SKSE64 for Skyrim Special Edition.

## Acknowledgements

* Clarification by mzinchaleft on how he made a similar SKSE plugin for Oldrim. [Link](http://www.mzin.moe/?p=132)
* Ryan's tutorial on how to make an SKSE64 plugin. [Link](https://github.com/Ryan-rsm-McKenzie/CommonLibSSE/wiki/Getting-Started)
