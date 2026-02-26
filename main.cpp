#include <ftxui/component/component.hpp>
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for operator|, Element, text, bold, border, center, color
#include "ftxui/screen/color.hpp"  // for Color, Color::Red
#include <cstdlib>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <random>

//Dev log(26/02/2026): 
// Going to make interactive, event loop screen or whatever it's called
// https://arthursonzogni.github.io/FTXUI/module-component-examples.html
//
//Copied exmaple from: 
//https://www.arthursonzogni.com/FTXUI/doc/examples_2component_2renderer_8cpp-example.html
//
//https://www.youtube.com/watch?v=Ml0pl3K6oOk

// 
//


// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <memory>  // for allocator, __shared_ptr_access
#include <string>  // for char_traits, operator+, string, basic_string
 
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Input, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/component_options.hpp"  // for InputOption
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border
#include "ftxui/util/ref.hpp"  // for Ref
 
int main() {
  using namespace ftxui;

  auto foo = Container::Vertical({});
  auto document = Renderer(foo, [&]{
          return vbox({
                  hbox(text("Foobar")) | border
                  }) | size(HEIGHT, GREATER_THAN, 40);
          });
 
  //Fullscreen makes the program fullscreened, while terminal makes it inside the terminal, for our purposes we'll need fullscreen
  //auto screen = ScreenInteractive::TerminalOutput();
  auto screen = ScreenInteractive::Fullscreen();
  screen.Loop(document);
}
