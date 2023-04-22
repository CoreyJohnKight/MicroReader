#include "AppRuntime.h"

namespace MicroLab
{
	// Static forward declarations
	std::unique_ptr<AppRuntime> AppRuntime::instance = nullptr;
	std::vector<std::unique_ptr<Abstract_Page>> AppRuntime::pages;
	int AppRuntime::currentPageIndex = 0;
	std::queue<AppRuntime::Event> eventQueue;

	// Singleton Instance 
	AppRuntime& AppRuntime::getInstance()
	{
		if (!instance)
		{
			instance = std::unique_ptr<AppRuntime>(new AppRuntime);
		}

		return *instance;

	}

	void AppRuntime::OpenPage(std::unique_ptr<Abstract_Page> page)
	{
	}

	Abstract_Page& AppRuntime::GetCurrentPage()
	{
		return *(pages.at(currentPageIndex));
	}

	void AppRuntime::PushEvent(const Event &e)
	{
		eventQueue.push(e);
	}

	// Construction/Initialization
	AppRuntime::AppRuntime()
	{
		// Close Program bool
		p_open = true;

		// Pointer to active page, initialized to home page
		// Push homepage to index 0
		pages.push_back(std::unique_ptr<Abstract_Page>(new Page_HomePage));
		currentPageIndex = 0;
	}
	void AppRuntime::ProcessEvents()
	{
		while (!eventQueue.empty())
		{
			Event event = eventQueue.front();
			event();
			eventQueue.pop();
		}
	}
}