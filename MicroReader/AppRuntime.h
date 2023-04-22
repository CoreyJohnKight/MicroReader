#pragma once
#include <memory>
#include <vector>
#include "Abstract_Page.h"

namespace MicroLab
{
	class AppRuntime
	{
	public:

		static AppRuntime& getInstance();
		static std::vector<std::unique_ptr<Abstract_Page>> pages;

		bool p_open;
		static void OpenPage(std::unique_ptr<Abstract_Page> page);
		static Abstract_Page& GetCurrentPage();

	private:
		AppRuntime();
		static std::unique_ptr<AppRuntime> instance;
		static int currentPageIndex;
	};
}

