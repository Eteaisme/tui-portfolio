#include <ftxui/component/component.hpp>
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for operator|, Element, text, bold, border, center, color
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/deprecated.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>

//Dev log(03/03/2026): 
// Going to try to go for itneractive by the end of the week.
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
using namespace ftxui;

int main() {
    std::vector<std::string> menu_items = {"Home", "Settings", "About"};
    int selected = 0;
    std::string search;

    auto menu = Menu(&menu_items, &selected);
    auto input = Input(&search, "Search...");
    auto layout = Container::Vertical({ input, menu });

    auto renderer = Renderer(layout, [&] {
        return vbox({
            text("My App") | bold | hcenter,
            separator(),
            hbox({
                vbox({ text("Menu"), separator(), menu->Render() })
                    | border | size(WIDTH, EQUAL, 20),
                vbox({
                    input->Render() | border,
                    text("Selected: " + menu_items[selected]),
                }) | flex,
            }),
        }) | border;
    });

    auto screen = ScreenInteractive::TerminalOutput();
    screen.Loop(renderer);
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
