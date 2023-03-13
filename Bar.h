#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "Bar.g.h"
#include "ColorSliderTransitionHelper.h"

namespace winrt::Win2dUwp::implementation
{
    struct Bar : BarT<Bar>
    {
        Bar() = default;

        double Value() { return m_value; }
        void Value(double value);

        static winrt::Windows::UI::Xaml::DependencyProperty ValueProperty()
        {
            return m_valueProperty;
        }
    private:
        double m_value{};
        static winrt::Windows::UI::Xaml::DependencyProperty m_valueProperty;
        ColorSliderTransitionHelper m_helper;
    public:
        void HostForVisual_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::Win2dUwp::factory_implementation
{
    struct Bar : BarT<Bar, implementation::Bar>
    {
    };
}
