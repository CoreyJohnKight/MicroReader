#include "AppRuntime.h"
#include <iostream>
namespace MicroLab
{
	// Static forward declarations
	std::unique_ptr<AppRuntime> AppRuntime::instance = nullptr;
	std::vector<std::unique_ptr<Abstract_Page>> AppRuntime::pages;
	int AppRuntime::currentPageIndex = 0;
	std::queue<AppRuntime::Event> AppRuntime::eventQueue;

	// Singleton Instance 
	AppRuntime& AppRuntime::getInstance()
	{
		if (!instance)
		{
			instance = std::unique_ptr<AppRuntime>(new AppRuntime);
		}

		return *instance;

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

	template <typename T>
	void AppRuntime::OpenPage()
	{
		static_assert(std::is_base_of<Abstract_Page, T>::value, "T must derive from Abstract_Page");
		std::cout << "test" << std::endl;
	}

	template <>
	void AppRuntime::OpenPage<Page_HeightmapPage>() 
	{
		int i = 0;
		for (const auto& ptr : pages)
		{
			if (dynamic_cast<Page_HeightmapPage*>(ptr.get()) != nullptr)
			{
				currentPageIndex = i;
				return;
			}
			i++;
		}
		std::cout << "Page not found, Creating new Page" << std::endl;
		pages.push_back(std::unique_ptr<Abstract_Page>(new Page_HeightmapPage));

		i = 0;
		for (const auto& ptr : pages)
		{
			if (dynamic_cast<Page_HeightmapPage*>(ptr.get()) != nullptr)
			{
				currentPageIndex = i;
				return;
			}
			i++;
		}
	}
}