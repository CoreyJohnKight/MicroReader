#include <imgui.h>

#include "AppRuntime.h"
#include "Abstract_Page.h"

namespace MicroLab
{
    //Constructor
    Page_HomePage::Page_HomePage()
    {
        Page_HomePage::ResizeComponents();
    }

    void Page_HomePage::RenderPage()
	{
        static bool use_work_area = true;
        static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings;

        // We demonstrate using the full viewport area or the work area (without menu-bars, task-bars etc.)
        // Based on your use case you may want one or the other.
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(use_work_area ? viewport->WorkPos : viewport->Pos);
        ImGui::SetNextWindowSize(use_work_area ? viewport->WorkSize : viewport->Size);

        if (ImGui::Begin("Example: Fullscreen window", NULL, flags))
        {
            ImGui::NewLine();
            ImGui::NewLine();
            ImGui::NewLine();
            ImGui::NewLine();
            ImGui::NewLine();
            ImGui::NewLine();
            ImGui::SameLine(openButton.position.x);
            if (ImGui::Button("Open Heightmap Generator", openButton.size))
            {
                AppRuntime::getInstance().PushEvent([this]() {this->OnButtonClicked(); });
            }
        }
        ImGui::End();
	}

    void Page_HomePage::ResizeComponents()
    {
        openButton.size = {(Abstract_Page::viewport->WorkSize.x / 3) * 2, Abstract_Page::viewport->WorkSize.y  / 4};
        openButton.position = { (Abstract_Page::viewport->WorkSize.x / 2) - (openButton.size.x / 2), 0 };
    }

    void Page_HomePage::OnButtonClicked(void)
    {
        AppRuntime::OpenPage<Page_HeightmapPage>();
    }
}
