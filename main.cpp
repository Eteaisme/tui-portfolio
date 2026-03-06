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

//Dev log(06/03/2026): 
//Now that we have basic func., we can look to start filling out the portfolio. For now, I think this is all
//the util. this will require acutally, besides maybe the project section? idk.
//Ok, now we have to deal w. sizing. That will be next, make template for content and then maybe split up sections?
using namespace ftxui;

int main() {
    std::string current_page = "home";

    auto renderer = Renderer([&] {
            Element content;
            if (current_page == "home")          content = text("Hello, welcome to my tui portfolio.");
            if (current_page == "projects")      content = text("projects");
            if (current_page == "contact")       content = text("contact me at: tame@uoguelph.ca");

            Element navbar = hbox({
                    (current_page == "home") ? text("h") | bold : text("h"), 
                    text("ome | "),
                    (current_page == "projects") ? text("p") | bold : text("p"), 
                    text("rojects | "),
                    (current_page == "contact") ? text("c") | bold : text("c"), 
                    text("ontact"),
                    });

            return vbox({
                    navbar ,
                    separator(),
                    content | border
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
