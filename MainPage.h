#pragma once

#include "MainPage.g.h"
#include "PropertyChangeHelper.h"

namespace winrt::Win2dUwp::implementation
{
    struct MainPage : MainPageT<MainPage>, PropertyChangeHelper<MainPage>
    {
        MainPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
        void CanvasControl_Draw(winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender, winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args);
        void StartButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);

        void FadeButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void MoveButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void ScaleButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void ColorButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);

        int LayerIndex() { return m_layerIndex; }
        void LayerIndex(int value)
        {
            if (value != m_layerIndex)
            {
                m_layerIndex = value;
                raisePropertyChange(L"LayerIndex");
            }
        }

        int OriginIndex() { return m_originIndex; }
        void OriginIndex(int value) 
        {
            if (m_originIndex != value)
            {
                m_originIndex = value;
                raisePropertyChange(L"CenterX");
                raisePropertyChange(L"CenterY");
            }
        }

        

        int EasingIndex() { return m_easingIndex; }
        void EasingIndex(int value)
        {
            if (value != m_easingIndex)
            {
                m_easingIndex = value;

                switch (value)
                {
                    case 3:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseIn;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::QuadraticEase{};
                        break;
                    case 4:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::QuadraticEase{};
                        break;
                    case 5:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseInOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::QuadraticEase{};
                        break;
                    case 6:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseIn;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::CubicEase{};
                        break;
                    case 7:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::CubicEase{};
                        break;
                    case 8:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseInOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::CubicEase{};
                        break;
                    case 9:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseIn;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::QuarticEase{};
                        break;
                    case 10:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::QuarticEase{};
                        break;
                    case 11:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseInOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::QuarticEase{};
                        break;
                    case 12:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseIn;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::QuinticEase{};
                        break;
                    case 13:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::QuinticEase{};
                        break;
                    case 14:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseInOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::QuinticEase{};
                        break;
                    case 15:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseIn;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::SineEase{};
                        break;
                    case 16:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::SineEase{};
                        break;
                    case 17:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseInOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::SineEase{};
                        break;
                    case 18:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseIn;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::ExponentialEase{};
                        break;
                    case 19:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::ExponentialEase{};
                        break;
                    case 20:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseInOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::ExponentialEase{};
                        break;
                    case 21:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseIn;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::CircleEase{};
                        break;
                    case 22:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::CircleEase{};
                        break;
                    case 23:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseInOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::CircleEase{};
                        break;
                    case 24:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseIn;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::ElasticEase{};
                        break;
                    case 25:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::ElasticEase{};
                        break;
                    case 26:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseInOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::ElasticEase{};
                        break;
                    case 27:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseIn;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::BackEase{};
                        break;
                    case 28:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::BackEase{};
                        break;
                    case 29:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseInOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::BackEase{};
                        break;
                    case 32:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseIn;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::BounceEase{};
                        break;
                    case 33:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::BounceEase{};
                        break;
                    case 34:
                        m_easingMode = winrt::Windows::UI::Xaml::Media::Animation::EasingMode::EaseInOut;
                        m_easingFunction = winrt::Windows::UI::Xaml::Media::Animation::BounceEase{};
                        break;

                    default:
                        m_easingFunction = nullptr;
                }

                raisePropertyChange(L"EasingIndex");
            }
        }

        winrt::Windows::UI::Xaml::Media::Animation::EasingMode EasingMode()
        {
            return m_easingMode;
        }

        winrt::Windows::UI::Xaml::Media::Animation::EasingFunctionBase EasingFunction()
        {
            return m_easingFunction;
        }


        double FadeStart() { return m_fadeStart; }
        void FadeStart(double value) 
        { 
            if (m_fadeStart != value)
            {
                m_fadeStart = value;
                raisePropertyChange(L"FadeStart");
            }
        }


        double FadeEnd() { return m_fadeEnd; }
        void FadeEnd(double value) 
        {
            if (m_fadeEnd != value)
            {
                m_fadeEnd = value;
                raisePropertyChange(L"FadeEnd");
            }
        }

        winrt::Windows::UI::Color ColorStart() { return m_colorStart; }
        void ColorStart(winrt::Windows::UI::Color value)
        {
            if (m_colorStart != value)
            {
                m_colorStart = value;
                raisePropertyChange(L"ColorStart");
            }
        }

        winrt::Windows::UI::Color ColorEnd() { return m_colorEnd; }
        void ColorEnd(winrt::Windows::UI::Color value)
        {
            if (m_colorEnd != value)
            {
                m_colorEnd = value;
                raisePropertyChange(L"ColorEnd");
            }
        }

        double MoveStartX() { return m_moveStartX; }
        void MoveStartX(double value)
        {
            if (m_moveStartX != value)
            {
                m_moveStartX = value;
                raisePropertyChange(L"MoveStartX");
            }
        }

        double MoveStartY() { return m_moveStartY; }
        void MoveStartY(double value)
        {
            if (m_moveStartY != value)
            {
                m_moveStartY = value;
                raisePropertyChange(L"MoveStartY");
            }
        }

        double MoveEndX() { return m_moveEndX; }
        void MoveEndX(double value)
        {
            if (m_moveEndX != value)
            {
                m_moveEndX = value;
                raisePropertyChange(L"MoveEndX");
            }
        }

        double MoveEndY() { return m_moveEndY; }
        void MoveEndY(double value)
        {
            if (m_moveEndY != value)
            {
                m_moveEndY = value;
                raisePropertyChange(L"MoveEndY");
            }
        }

        double ScaleStart() { return m_scaleStart; }
        void ScaleStart(double value)
        {
            if (m_scaleStart != value)
            {
                m_scaleStart = value;
                raisePropertyChange(L"ScaleStart");
            }
        }

        double ScaleEnd() { return m_scaleEnd; }
        void ScaleEnd(double value)
        {
            if (m_scaleEnd != value)
            {
                m_scaleEnd = value;
                raisePropertyChange(L"ScaleEnd");
            }
        }

        double RotateStart() { return m_rotateStart; }
        void RotateStart(double value)
        {
            if (m_rotateStart != value)
            {
                m_rotateStart = value;
                raisePropertyChange(L"RotateStart");
            }
        }

        double RotateEnd() { return m_rotateEnd; }
        void RotateEnd(double value)
        {
            if (m_rotateEnd != value)
            {
                m_rotateEnd = value;
                raisePropertyChange(L"RotateEnd");
            }
        }

        double CenterX()
        {
            auto spriteSize = Sprite().Width();
            auto const currentTopLeft = Sprite().TransformToVisual(Canvas()).TransformPoint({ 0,0 }).X;
            double offset{};
            switch (m_originIndex)
            {
                case 0: break;
                case 1: offset = 
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                default:
                    throw std::runtime_error{"Unknown origin"};
            }
        }

        double CenterY()
        {
            auto spriteSize = Sprite().Width();
            switch (m_originIndex)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                default:
                    throw std::runtime_error{ "Unknown origin" };
            }
        }
    private:
        winrt::Windows::UI::Xaml::Media::Animation::EasingMode m_easingMode;
        winrt::Windows::UI::Xaml::Media::Animation::EasingFunctionBase m_easingFunction{ nullptr };
        int m_layerIndex{};
        int m_originIndex{};
        int m_easingIndex{ };
        
        double m_fadeStart{};
        double m_fadeEnd{};

        double m_moveStartX = 100.0;
        double m_moveEndX = 200.0;
        double m_moveStartY = 300.0;
        double m_moveEndY = 400.0;

        double m_scaleStart{};
        double m_scaleEnd{};

        double m_rotateStart{};
        double m_rotateEnd = 3.14;

        winrt::Windows::UI::Color m_colorStart{};
        winrt::Windows::UI::Color m_colorEnd{};
    public:
        void RotateButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
};
}

namespace winrt::Win2dUwp::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
