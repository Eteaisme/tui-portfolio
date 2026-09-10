#include <ftxui/component/component.hpp>
#include "ftxui/component/screen_interactive.hpp"  
#include "ftxui/dom/elements.hpp"  
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/deprecated.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <string>
#include <vector>

using namespace ftxui;
Component Project_Menu (std::vector<std::string>* entries, int* selected);

int main() {
    std::string current_page = "home";

    std::vector<int> project_selected{0, 1, 2, 3, 4};
    std::vector<std::string> project_entries{
        "Foo", "Bar", "Quux", "Baz" 
    };
    auto project_menu = Project_Menu(&project_entries, &project_selected[0]);

    auto renderer = Renderer([&] {
            Element content;
            if (current_page == "home")          content = vbox({
                        text("Hello, my name is Elliot. I'm a second-year Computer Science student at the"),
                        text("University of guelph. I enjoy specialty coffe, reading, music,"),
                        text("math and computers. Currently looking for W27 work.")
                    }) | center;
            if (current_page == "projects")      content = hbox({
                    project_menu->Render(),                         
                    //text("Under construction...") | dim,
                    }) | center;
            if (current_page == "blog")      content = hbox({
                    text("Under construction...") | dim,
                    }) | center;
            if (current_page == "contact")       content = vbox({
                    hbox({text("email me at: "), text(" tame@uoguelph.ca") | bold}),
                    hbox({text("follow me at: "), text("Github.com/Eteaisme") | bold}),
                    }) | center;


            Element navbar = hbox({
                    (current_page == "home") ? text("h") | bold : text("h"), 
                    text("ome | "),
                    (current_page == "projects") ? text("p") | bold : text("p"), 
                    text("rojects | "),
                    (current_page == "blog") ? text("b") | bold : text("b"), 
                    text("log | "),
                    (current_page == "contact") ? text("c") | bold : text("c"), 
                    text("ontact"),
                    }) | center;

            Element footer = hbox({
                    text("Made with  &  in 🇨🇦 "),
                    text("q: quit") | dim,
                    }) | center;
            return vbox({
                    navbar,
                    separator(),
                    content | border | size(WIDTH, EQUAL, 80) | size(HEIGHT, EQUAL, 15),
                    separator(),
                    footer,
                    }) | center;
            });

    auto screen = ScreenInteractive::Fullscreen();
    auto app = CatchEvent(renderer, [&](Event event) {
            if (event == Event::Character('h')) { current_page = "home";     return true; }
            if (event == Event::Character('p')) { current_page = "projects"; return true; }
            if (event == Event::Character('c')) { current_page = "contact";  return true; }
            if (event == Event::Character('b')) { current_page = "blog";  return true; }
            if (event == Event::Character('q')) { screen.Exit();  }
            return false;
            });
    screen.Loop(app);
}

Component Project_Menu(std::vector<std::string>* entries, int* selected) {
  auto option = MenuOption::Vertical();
  option.entries_option.transform = [](EntryState state) {
    state.label = (state.active ? "> " : "  ") + state.label;
    Element e = text(state.label);
    if (state.focused) {
      e = e | bgcolor(Color::Blue);
    }
    if (state.active) {
      e = e | bold;
    }
    return e;
  };
  return Menu(entries, selected, option);
}
 
