#pragma once

class VMClassRegistry;

class TESWaterForm;

namespace papyrusWaterType
{
	bool GetIsDangerous(TESWaterForm* thisWaterType);
	void SetIsDangerous(TESWaterForm* thisWaterType, bool dangerous);

	void RegisterFuncs(VMClassRegistry* registry);
}
