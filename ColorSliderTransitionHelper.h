#pragma once
#include <winrt/Windows.Foundation.Numerics.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <chrono>
class ColorSliderTransitionHelper
{
	winrt::Windows::UI::Xaml::UIElement m_hostForVisual{ nullptr };
	winrt::Windows::UI::Composition::Compositor m_compositor{ nullptr };
	winrt::Windows::UI::Composition::ContainerVisual m_containerForVisuals{ nullptr };
	winrt::Windows::UI::Composition::ScalarKeyFrameAnimation m_slideAnimation{ nullptr };

	void initializeSlideAnimation()
	{
		m_slideAnimation = m_compositor.CreateScalarKeyFrameAnimation();

	}

	winrt::Windows::UI::Composition::SpriteVisual createVisualWithColorAndPosition(winrt::Windows::UI::Color color, winrt::Windows::Foundation::Rect finalBounds)
	{
		winrt::Windows::Foundation::Numerics::float3 offset{ 0, finalBounds.Y, 0 };
		winrt::Windows::Foundation::Numerics::float2 size{ 0, finalBounds.Height };
		auto coloredRect = m_compositor.CreateSpriteVisual();
		auto brush = m_compositor.CreateLinearGradientBrush();
		brush.StartPoint({ 0,0 });
		brush.EndPoint({ 0, 1 });

		coloredRect.Brush(brush);
		coloredRect.Offset(offset);
		coloredRect.Size(size);
		return coloredRect;
	}

	void triggerSlideAnimation(winrt::Windows::UI::Composition::SpriteVisual colorVisual)
	{
		auto batchTransaction = m_compositor.CreateScopedBatch(winrt::Windows::UI::Composition::CompositionBatchTypes::Animation);
		colorVisual.StartAnimation(L"Size.X", m_slideAnimation);
		batchTransaction.End();
	}
public:
	ColorSliderTransitionHelper() = default;
	ColorSliderTransitionHelper(winrt::Windows::UI::Xaml::UIElement hostVisual) : m_hostForVisual{ hostVisual }
	{
		auto visual = winrt::Windows::UI::Xaml::Hosting::ElementCompositionPreview::GetElementVisual(hostVisual);
		m_compositor = visual.Compositor();
		m_containerForVisuals = m_compositor.CreateContainerVisual();
		initializeSlideAnimation();
		winrt::Windows::UI::Xaml::Hosting::ElementCompositionPreview::SetElementChildVisual(m_hostForVisual, m_containerForVisuals);
	}
	
	void Start(winrt::Windows::UI::Color color, winrt::Windows::Foundation::Rect finalBounds)
	{
		auto colorVisual = createVisualWithColorAndPosition(color, finalBounds);
		m_slideAnimation.InsertKeyFrame(1.0f, finalBounds.Width); //easing function
		m_slideAnimation.Duration(std::chrono::milliseconds{ 800 });
		m_containerForVisuals.Children().InsertAtTop(colorVisual);
		triggerSlideAnimation(colorVisual);
	}
};

