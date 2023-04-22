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
            static int clicked = 0;
            ImGui::NewLine();
            ImGui::NewLine();
            ImGui::NewLine();
            ImGui::NewLine();
            ImGui::NewLine();
            ImGui::NewLine();
            ImGui::SameLine(openButton.position.x);
            if (ImGui::Button("Open Heightmap Generator", openButton.size ))
                clicked++;
            if (clicked & 1)
            {
                ImGui::Text("Thanks for clicking me!");
            }
        }
        ImGui::End();
	}

    void Page_HomePage::ResizeComponents()
    {
        const ImGuiViewport* viewport = ImGui::GetMainViewport();

        openButton.size = {(viewport->WorkSize.x / 3) * 2, viewport->WorkSize.y  / 4};
        openButton.position = { (viewport->WorkSize.x / 2) - (openButton.size.x / 2), 0 };
    }
}
