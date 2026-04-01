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

//dev log: began working on server, add md file for build instructions
using namespace ftxui;

int main() {
    std::string current_page = "home";

    auto renderer = Renderer([&] {
            Element content;
            if (current_page == "home")          content = vbox({
                        text("Hi, my name is Elliot. I'm a first-year Computer Science student at the"),
                        text("University of guelph. I enjoy specialty coffe, reading, music"),
                        text("math and computers. Currently looking for S26 work.")
                    }) | center;
            if (current_page == "projects")      content = hbox({
                    text("under construction...") | dim,
                    }) | center;
            if (current_page == "blog")      content = hbox({
                    text("under construction...") | dim,
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
                    text("Made with  &  in 🇨🇦")
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
