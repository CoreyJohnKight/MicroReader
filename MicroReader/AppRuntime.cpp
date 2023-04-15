#include "AppRuntime.h"

namespace MicroLab
{
	// Static declarations
	std::unique_ptr<AppRuntime> AppRuntime::instance = nullptr;
	std::unique_ptr<Abstract_Page> MicroLab::AppRuntime::currentPage = nullptr;

	// Singleton Instance 
	AppRuntime& AppRuntime::getInstance()
	{
		if (!instance)
		{
			instance = std::unique_ptr<AppRuntime>(new AppRuntime);
		}

		return *instance;

	}

	// Construction/Initialization
	AppRuntime::AppRuntime()
	{
		// Close Program bool
		p_open = true;

		// Pointer to active page, initialized to home page
		currentPage = std::unique_ptr<Abstract_Page>(new Page_HomePage);
	}
}