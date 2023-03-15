#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"


using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Win2dUwp::implementation
{

	void MainPage::StartButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		//Progress().Value(50);
	}


	void MainPage::FadeButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		FadeAnimation().Begin();
	}


	void MainPage::MoveButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		MoveAnimation().Begin();
	}


	void MainPage::ScaleButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		ScaleAnimation().Begin();
	}

	void MainPage::RotateButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		RotateAnimation().Begin();
	}


	void MainPage::ColorButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		
	}

}


//画一个正弦波
static void DrawSineWave(
	winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender,
	winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args)
{
	static int t = 0;
	auto session = args.DrawingSession();

	winrt::Microsoft::Graphics::Canvas::Geometry::CanvasPathBuilder builder{ sender };
	builder.BeginFigure({ 0, (float)sender.ActualHeight() / 2 });

	auto const width = sender.ActualWidth();
	auto const height = sender.ActualHeight();
	auto const y = height / 2;
	for (int i = 0; i < width; ++i)
	{
		builder.AddLine({ (float)i, (float)(y + 50 * std::sinf(0.05 * i + 0.1 * t)) });
	}
	builder.EndFigure(winrt::Microsoft::Graphics::Canvas::Geometry::CanvasFigureLoop::Open);
	session.DrawGeometry(winrt::Microsoft::Graphics::Canvas::Geometry::CanvasGeometry::CreatePath(builder), winrt::Windows::UI::Colors::Yellow());
	++t;
}

//画随机噪点
static void DrawNoise(
	winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender,
	winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args)
{
	static std::vector<uint8_t> bytes(sender.ActualWidth() * sender.ActualHeight() * 4);
	std::generate_n(bytes.begin(), sender.ActualWidth() * sender.ActualHeight() * 4, [] {
		return std::rand() % 255;
		});

	auto bitmap = winrt::Microsoft::Graphics::Canvas::CanvasBitmap::CreateFromBytes(sender, winrt::array_view<uint8_t>{bytes}, sender.ActualWidth(), sender.ActualHeight(), winrt::Windows::Graphics::DirectX::DirectXPixelFormat::B8G8R8A8UIntNormalized);

	args.DrawingSession().DrawImage(bitmap);
}

//http://microsoft.github.io/Win2D/WinUI2/html/T_Microsoft_Graphics_Canvas_CanvasDrawingSession.htm
//https://learn.microsoft.com/en-us/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format
void winrt::Win2dUwp::implementation::MainPage::CanvasControl_Draw(winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender, winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args)
{

	sender.Invalidate();
}



