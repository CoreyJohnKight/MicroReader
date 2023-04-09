#pragma once
#include <memory>

namespace MicroLab
{
	class AppRuntime
	{
	public:

		static AppRuntime& getInstance();

		bool p_open;

	private:
		AppRuntime();
		static std::unique_ptr<AppRuntime> instance;

	};
}

