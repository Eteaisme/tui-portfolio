#include <ftxui/component/component.hpp>
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for operator|, Element, text, bold, border, center, color
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/deprecated.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>

//Dev log(0403/2026): 
// Going to try to go for itneractive by the end of the week.
// Okay so it seems like render is only concerred with components, but for this, at least for now, all should be static ()
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <string>
using namespace ftxui;

int main() {
    //Horizontal & vertical containers can only hold components, what about elements?
    //Wait maybe I dont even need to...
    // ---NOTES FROM FTXUI DOCS---
    // --> Renderer() takes in two paramaters, 1. A component & 2. a lamda that returns an element
    // --> The component is what concens per. inputs, 
    // --> The labda function returns the element tree, note the sytax [&]{...} --> Return vbox...
    // --> Without compoenets, the component paramater can be ommited, and change can be handeled via CatchEvent. For example: 
    //          auto app = renderer([&]{return text("foobar")}); <-- No component passed in

    std::string current_page = "home";

    auto renderer = Renderer([&] {
            Element content;
            if      (current_page == "home")     content = text("foo");
            if (current_page == "projects") content = text("bar");
            if (current_page == "about")    content = text("chow");

            return vbox({
                    text("home | projects | contact") | border,
                    separator(),
                    content
                    });
            });

    auto app = CatchEvent(renderer, [&](Event event) {
            if (event == Event::Character('h')) { current_page = "home";     return true; }
            if (event == Event::Character('p')) { current_page = "projects"; return true; }
            if (event == Event::Character('a')) { current_page = "about";    return true; }
            return false;
            });

    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(app);
}
  
 //   int main() {
 //     using namespace ftxui;
 //
 //
 //     Element navbar = hbox({
 //             text("home"),
 //             separator(),
 //             text("projects"),
 //             separator(),
 //             text("contact")
 //             }) 
 //     | border | center;
 //
 //     Element about_me = vbox({
 //             text("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor"),
 //             text("ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation"),
 //             text("ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in"),
 //             }) 
 //     | border | center;
 //
 //     auto foo = Container::Vertical({});
 //     auto document = Renderer(foo, [&]{
 //             return vbox({
 //                     navbar,
 //                     about_me
 //                     //size here returns terminal size, not exactly sure what I'm piping to...
 //                     }) | size(HEIGHT, GREATER_THAN, 50);
 //             });
 //    
 //     //Fullscreen makes the program fullscreened, while terminal makes it inside the terminal, for our purposes we'll need fullscreen
 //     //auto screen = ScreenInteractive::TerminalOutput();
 //     auto screen = ScreenInteractive::Fullscreen();
//     screen.Loop(document);
//   }
