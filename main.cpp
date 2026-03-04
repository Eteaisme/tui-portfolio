#include <ftxui/component/component.hpp>
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for operator|, Element, text, bold, border, center, color
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/deprecated.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>

//Dev log(03/03/2026): 

 
int main() {
  using namespace ftxui;


  Element navbar = hbox({
          text("home"),
          separator(),
          text("projects"),
          separator(),
          text("contact")
          }) 
  | border | center;

  Element about_me = vbox({
          text("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor"),
          text("ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation"),
          text("ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in"),
          }) 
  | border | center;

  auto foo = Container::Vertical({});
  auto document = Renderer(foo, [&]{
          return vbox({
                  navbar,
                  about_me
                  //size here returns terminal size, not exactly sure what I'm piping to...
                  }) | size(HEIGHT, GREATER_THAN, 50);
          });
 
  //Fullscreen makes the program fullscreened, while terminal makes it inside the terminal, for our purposes we'll need fullscreen
  //auto screen = ScreenInteractive::TerminalOutput();
  auto screen = ScreenInteractive::Fullscreen();
  screen.Loop(document);
}
