#include "Application.h"
#include "imgui.h"

namespace MircroReader
{
    void RenderUI()
    {
        ImGui::Begin("Test");
        ImGui::Button("Push me, I dare you!");
        static float f = 0.0f;
        ImGui::DragFloat("Test Value", &f);
        ImGui::End();
    }
}
