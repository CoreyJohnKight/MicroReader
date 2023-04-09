#include "Application.h"
#include "AppRuntime.h"

#include "imgui.h"

namespace MicroLab
{
    void Init()
    {
        //Enforce construction
        AppRuntime::getInstance();
    }
    void RenderUI()
	{
        bool* open = &AppRuntime::getInstance().p_open;
        static bool use_work_area = true;
        static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings;

        // We demonstrate using the full viewport area or the work area (without menu-bars, task-bars etc.)
        // Based on your use case you may want one or the other.
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(use_work_area ? viewport->WorkPos : viewport->Pos);
        ImGui::SetNextWindowSize(use_work_area ? viewport->WorkSize : viewport->Size);

        if (ImGui::Begin("Example: Fullscreen window", open, flags))
        {
            ImGui::Checkbox("Use work area instead of main area", &use_work_area);
            ImGui::SameLine();

            ImGui::CheckboxFlags("ImGuiWindowFlags_NoBackground", &flags, ImGuiWindowFlags_NoBackground);
            ImGui::CheckboxFlags("ImGuiWindowFlags_NoDecoration", &flags, ImGuiWindowFlags_NoDecoration);
            ImGui::Indent();
            ImGui::CheckboxFlags("ImGuiWindowFlags_NoTitleBar", &flags, ImGuiWindowFlags_NoTitleBar);
            ImGui::CheckboxFlags("ImGuiWindowFlags_NoCollapse", &flags, ImGuiWindowFlags_NoCollapse);
            ImGui::CheckboxFlags("ImGuiWindowFlags_NoScrollbar", &flags, ImGuiWindowFlags_NoScrollbar);
            ImGui::Unindent();

            if (*open && ImGui::Button("Close this window"))
                *open = false;
        }
        ImGui::End();

		//ImGui::ShowDemoWindow();
	}

}
