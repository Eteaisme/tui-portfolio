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

//Dev log(07/03/2026): 
//I think what we have so far wrt the acutal portfolio is fine at this point. I would
//be content having this up. next steps I think are writing main.go and figuring out
//a hosting plan.
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
            if (current_page == "projects")      content = text("under construction...");
            if (current_page == "contact")       content = vbox({
                    text("email me at: "),
                    hyperlink("mailto:tame@uoguelph.ca", text("tame@uoguelph.ca")) | bold,
                    text("follow me at: "),
                    hyperlink("github.com/Eteaisme", text("github.com/Eteaisme")) | bold,
                    });


            Element navbar = hbox({
                    (current_page == "home") ? text("h") | bold : text("h"), 
                    text("ome | "),
                    (current_page == "projects") ? text("p") | bold : text("p"), 
                    text("rojects | "),
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

    auto app = CatchEvent(renderer, [&](Event event) {
            if (event == Event::Character('h')) { current_page = "home";     return true; }
            if (event == Event::Character('p')) { current_page = "projects"; return true; }
            if (event == Event::Character('c')) { current_page = "contact";  return true; }
            return false;
            });

    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(app);
}
