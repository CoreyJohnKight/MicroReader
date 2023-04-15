#pragma once
#include "imgui.h"
namespace MicroLab
{
	class Abstract_Page
	{
	public:
		virtual void RenderPage() = 0;
		virtual void ResizeComponents() = 0;
	};

	typedef struct
	{
		ImVec2 position;
		ImVec2 size;
	
	}t_FixedComponent;

	class Page_HomePage : public Abstract_Page
	{
	public:
		Page_HomePage();
		void RenderPage() override;
		void ResizeComponents() override;

	
	private:
		t_FixedComponent openButton;
	};
}

