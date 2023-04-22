#pragma once
#include "imgui.h"
#include <string>
namespace MicroLab
{
	class Abstract_Page
	{
	protected:
		const ImGuiViewport* viewport = ImGui::GetMainViewport();
	public:
		virtual void RenderPage() = 0;
		virtual void ResizeComponents() = 0;
	};

	typedef struct
	{
		ImVec2 position;
		ImVec2 size;
		bool clickedThisFrame;
	
	}t_FixedComponent;

	class Page_HomePage : public Abstract_Page
	{
	public:
		Page_HomePage();
		void RenderPage() override;
		void ResizeComponents() override;
		void OnButtonClicked(void);
	
	private:
		t_FixedComponent openButton;
	};
}

