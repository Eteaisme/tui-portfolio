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
using namespace ftxui;

int main() {
    std::string current_page = "home";

    auto renderer = Renderer([&] {
            Element content;
            if (current_page == "home")          content = text("home");
            if (current_page == "projects")      content = text("projects");
            if (current_page == "contact")       content = text("contacts");

            Element navbar = hbox({
                    (current_page == "home") ? text("h") | bold : text("h"), 
                    text("ome | "),
                    (current_page == "projects") ? text("p") | bold : text("p"), 
                    text("rojects | "),
                    (current_page == "contact") ? text("c") | bold : text("c"), 
                    text("ontact"),
                    });

            return vbox({
                    navbar,
                    separator(),
                    content
                    });
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
