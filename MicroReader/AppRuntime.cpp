#include "AppRuntime.h"

namespace MicroLab
{
	std::unique_ptr<AppRuntime> AppRuntime::instance = nullptr;
	AppRuntime& AppRuntime::getInstance()
	{
		if (!instance)
		{
			instance = std::unique_ptr<AppRuntime>(new AppRuntime);
		}

		return *instance;

	}

	AppRuntime::AppRuntime()
	{
		p_open = true;
	}
}