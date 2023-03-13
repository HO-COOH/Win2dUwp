#include "pch.h"
#include "Bar.h"
#if __has_include("Bar.g.cpp")
#include "Bar.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Win2dUwp::implementation
{
    winrt::Windows::UI::Xaml::DependencyProperty Bar::m_valueProperty = winrt::Windows::UI::Xaml::DependencyProperty::Register(
        L"Value",
        winrt::xaml_typename<double>(),
        winrt::xaml_typename<winrt::Win2dUwp::Bar>(),
        winrt::Windows::UI::Xaml::PropertyMetadata{ winrt::box_value(0.0) }
    );

    void Bar::Value(double value)
    {
        if (m_value == value)
            return;

        winrt::Windows::Foundation::Rect finalBounds
        {
            0, //X
            0,
            (float)(ActualWidth() * value / 100.0f),
            (float)ActualHeight(),

        };
        m_helper.Start(winrt::Windows::UI::Colors::Red(), finalBounds);
        m_value = value;
    }



    void Bar::HostForVisual_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
    {
        m_helper = ColorSliderTransitionHelper{ HostForVisual() };
    }

}
