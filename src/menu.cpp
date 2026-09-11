#include <ftxui/component/component.hpp>
#include "ftxui/component/screen_interactive.hpp"  
#include "ftxui/dom/elements.hpp"  
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/deprecated.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <string>
#include <vector>

using namespace ftxui;
Component Project_Menu(std::vector<std::string>* entries, int* selected) {
  auto option = MenuOption::Vertical();
  option.entries_option.transform = [](EntryState state) {
    state.label = (state.active ? "> " : "  ") + state.label;
    Element e = text(state.label);
    if (state.active) {
      e = e | bold;
    }
    return e;
  };
  return Menu(entries, selected, option);
}
 
Component Blog_Menu(std::vector<std::string>* entries, int* selected) {
  auto option = MenuOption::Vertical();
  option.entries_option.transform = [](EntryState state) {
    state.label = (state.active ? "> " : "  ") + state.label;
    Element e = text(state.label);
    if (state.active) {
      e = e | bold;
    }
    return e;
  };
  return Menu(entries, selected, option);
}
