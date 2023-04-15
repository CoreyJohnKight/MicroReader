#pragma once
#include <memory>
#include "Abstract_Page.h"

namespace MicroLab
{
	class AppRuntime
	{
	public:

		static AppRuntime& getInstance();
		static std::unique_ptr<Abstract_Page> currentPage;

		bool p_open;

	private:
		AppRuntime();
		static std::unique_ptr<AppRuntime> instance;

	};
}

