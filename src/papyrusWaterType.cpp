#include "papyrusWaterType.h"

#include "skse64/GameForms.h"

#include "skse64/PapyrusVM.h"
#include "skse64/PapyrusNativeFunctions.h"

#define flags unk0B9

constexpr auto flagDangerous = 1;

namespace papyrusWaterType
{
	bool GetIsDangerous(TESWaterForm* thisWaterType)
	{
		return thisWaterType ? (thisWaterType->flags & flagDangerous) != 0 : false;
	}

	void SetIsDangerous(TESWaterForm* thisWaterType, bool dangerous)
	{
		if (!thisWaterType)
			return;
		if (dangerous)
			thisWaterType->flags |= flagDangerous;
		else
			thisWaterType->flags &= ~flagDangerous;
	}

	void RegisterFuncs(VMClassRegistry* registry)
	{
		registry->RegisterForm(TESWaterForm::kTypeID, "WaterType");

		registry->RegisterFunction(
			new NativeFunction0<TESWaterForm, bool>("GetIsDangerous", "WaterType", papyrusWaterType::GetIsDangerous, registry));

		registry->RegisterFunction(
			new NativeFunction1<TESWaterForm, void, bool>("SetIsDangerous", "WaterType", papyrusWaterType::SetIsDangerous, registry));

		registry->SetFunctionFlags("WaterType", "GetIsDangerous", VMClassRegistry::kFunctionFlag_NoWait);
	}
}
