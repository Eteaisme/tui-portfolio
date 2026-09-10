#include <ftxui/component/component.hpp>
#include "ftxui/component/screen_interactive.hpp"  
#include "ftxui/dom/elements.hpp"  
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/deprecated.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include "ftxui/component/mouse.hpp"
#include <ftxui/component/screen_interactive.hpp>
#include <string>
#include <vector>

using namespace ftxui;
Component Project_Menu (std::vector<std::string>* entries, int* selected);
Component Blog_Menu    (std::vector<std::string>* entries, int* selected);

int main() {

    std::string current_page = "home";
    std::vector<std::string> pages {"home", "projects", "contact", "blog" };
    int page_selected {0};

    int entry_selected {0};
    std::vector<std::string> project_entries{
        "project 1               ", "project 2", "project 3", "project 4" 
    };
    std::vector<std::string> blog_entries{
        "blog entry 1            ", "blog entry 2", "blog entry 3", "blog entry 4" 
    };

    std::vector<std::string> project_descriptions {
        "project 1 desc.",  //tui portfolio
        "project 2 desc.",  //linux conf
        "project 3 desc.",  //personal site
        "project 4 desc. ", 
    };

    std::vector<std::string> blog_content{
        "article 1 content",  
        "article 2 content",  
        "article 3 content",  
        "article 4 content", 
    };



    auto project_menu = Project_Menu(&project_entries, &entry_selected);
    auto blog_menu    = Blog_Menu(&blog_entries, &entry_selected);

    auto renderer = Renderer([&] {
            Element content;
            if (current_page == "home")          content = vbox({
                        text("Hello, my name is Elliot. I'm a second-year Computer Science student at the"),
                        text("University of guelph. I enjoy specialty coffe, reading, music,"),
                        text("math and computers. Currently looking for W27 work.")
                    }) | center;
            if (current_page == "projects") content = hbox({
                    project_menu->Render(),                         
                    separator(),
                    vbox({
                            text(project_entries[entry_selected]) | bold, 
                            text(project_descriptions[entry_selected]), 
                            })
                    });
            if (current_page == "blog")  content = hbox({
                    blog_menu->Render(),                         
                    separator(),
                    vbox({
                    text(blog_entries[entry_selected]) | bold, 
                    text(blog_content[entry_selected]), 
                            })
                    });
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
            if (event == Event::Character('p')) { current_page = "projects"; entry_selected = 0; return true; }
            if (event == Event::Character('c')) { current_page = "contact";  entry_selected = 0; return true; }
            if (event == Event::Character('b')) { current_page = "blog";     return true; }

            if (event == Event::ArrowUp)        {--entry_selected; return true; }
            if (event == Event::ArrowDown)      {++entry_selected; return true;}

            //if (event == Event::ArrowLeft)      {--page_selected; current_page = pages[page_selected]; return true;}
            //if (event == Event::ArrowRight)     {++page_selected; current_page = pages[page_selected]; return true;}

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
 
