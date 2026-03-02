#include <ftxui/component/component.hpp>
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for operator|, Element, text, bold, border, center, color
#include <ftxui/dom/deprecated.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>

//Dev log(01/03/2026): 
// Add about me, footer and navbar. (static for now)
//Catching up, haven't contribed for a couple days.
//


// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
 
int main() {
  using namespace ftxui;

  auto foo = Container::Vertical({});
  auto document = Renderer(foo, [&]{
          return vbox({
                  hbox({
                        text("home"),
                        text("projects"),
                        text("contact")
                          }) | border

                  //size here returns terminal size, not exactly sure what I'm piping to...
                  }) | size(HEIGHT, GREATER_THAN, 50);
          });
 
  //Fullscreen makes the program fullscreened, while terminal makes it inside the terminal, for our purposes we'll need fullscreen
  //auto screen = ScreenInteractive::TerminalOutput();
  auto screen = ScreenInteractive::Fullscreen();
  screen.Loop(document);
}
