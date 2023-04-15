#pragma once
namespace MicroLab
{
	class Abstract_Page
	{
	public:
		virtual void RenderPage() = 0;
	};

	class Page_HomePage : public Abstract_Page
	{
	public:
		void RenderPage() override;
	};
}

