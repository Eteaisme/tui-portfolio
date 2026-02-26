#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Renderer, Button, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for operator|, Element, text, bold, border, center, color
#include "ftxui/screen/color.hpp"  // for Color, Color::Red

//Dev log(25/02/2026): 
// Going to make interactive, event loop screen or whatever it's called
// https://arthursonzogni.github.io/FTXUI/module-component-examples.html
//
//Copied exmaple from: 
//https://www.arthursonzogni.com/FTXUI/doc/examples_2component_2renderer_8cpp-example.html
//
int main() {
  using namespace ftxui;
  auto screen = ScreenInteractive::FitComponent();
 
  // A Renderer() is a component using a lambda function as a parameter to
  // render itself.
 
  // 1. Example of focusable renderer:
  auto renderer_focusable = Renderer([](bool focused) {
    if (focused)
      return text("FOCUSABLE RENDERER()") | center | bold | border;
    else
      return text(" Focusable renderer() ") | center | border;
  });
 
  // 2. Examples of a non focusable renderer.
  auto renderer_non_focusable = Renderer([&] {
    return text("~~~~~ Non Focusable renderer() ~~~~~");  //
  });
 
  // 3. Renderer can wrap other components to redefine their Render() function.
  auto button = Button("Wrapped quit button", screen.ExitLoopClosure());
  auto renderer_wrap = Renderer(button, [&] {
    if (button->Focused())
      return button->Render() | bold | color(Color::Red);
    else
      return button->Render();
  });
 
  // Let's renderer everyone:
  screen.Loop(Container::Vertical({
      renderer_focusable,
      renderer_non_focusable,
      renderer_wrap,
  }));
}
