#include "common/IDebugLog.h"  // IDebugLog
#include "skse64_common/skse_version.h"  // RUNTIME_VERSION
#include "skse64/PluginAPI.h"  // SKSEInterface, PluginInfo

#include <ShlObj.h>  // CSIDL_MYDOCUMENTS

#include "version.h"  // VERSION_VERSTRING, VERSION_MAJOR
#include "papyrusWaterType.h"

extern "C"
{
	static bool RegisterFunctions(VMClassRegistry* registry)
	{
		papyrusWaterType::RegisterFuncs(registry);
		return true;
	}

	bool SKSEPlugin_Query(const SKSEInterface* a_skse, PluginInfo* a_info)
	{
		gLog.OpenRelative(CSIDL_MYDOCUMENTS, "\\My Games\\Skyrim Special Edition\\SKSE\\watertype.log");
		gLog.SetPrintLevel(IDebugLog::kLevel_DebugMessage);
		gLog.SetLogLevel(IDebugLog::kLevel_DebugMessage);

		_MESSAGE("watertype v%s", WTYP_VERSION_VERSTRING);

		a_info->infoVersion = PluginInfo::kInfoVersion;
		a_info->name = "watertype";
		a_info->version = WTYP_VERSION_MAJOR;

		if (a_skse->isEditor)
		{
			_FATALERROR("Loaded in editor, marking as incompatible!\n");
			return false;
		}

		if (a_skse->runtimeVersion < RUNTIME_VERSION_1_5_97)
		{
			_FATALERROR("Unsupported runtime version %08X!\n", a_skse->runtimeVersion);
			return false;
		}

		return true;
	}

	bool SKSEPlugin_Load(const SKSEInterface* a_skse)
	{
		auto papyrusInterface = static_cast<SKSEPapyrusInterface*>(a_skse->QueryInterface(kInterface_Papyrus));

		papyrusInterface->Register(RegisterFunctions);

		_MESSAGE("loaded");

		return true;
	}
};
