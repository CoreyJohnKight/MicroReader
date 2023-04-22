#pragma once
#include "Abstract_Page.h"

namespace MicroLab
{
	class Page_HeightmapPage : Abstract_Page
	{
	public:
		Page_HeightmapPage();
		void RenderPage() override;
		void ResizeComponents() override;
	};
}