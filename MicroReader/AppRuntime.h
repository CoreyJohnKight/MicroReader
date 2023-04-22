#pragma once
#include <memory>
#include <vector>
#include "Abstract_Page.h"
#include <queue>
#include <functional>

namespace MicroLab
{
	class AppRuntime
	{
	public:
		typedef std::function<void()> Event;

		static AppRuntime& getInstance();
		static std::vector<std::unique_ptr<Abstract_Page>> pages;

		bool p_open;
		static void OpenPage(std::unique_ptr<Abstract_Page> page);
		static Abstract_Page& GetCurrentPage();
		static void PushEvent(const Event &e);
		static void ProcessEvents();

	private:
		AppRuntime();
		static std::unique_ptr<AppRuntime> instance;
		static int currentPageIndex;
		//static std::queue<AppRuntime::Event> eventQueue;
	};
}

