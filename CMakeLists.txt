cmake_minimum_required(VERSION 3.15)
project(tui-portfolio)

include(FetchContent)
FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
    GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

add_executable(main)
target_sources(main
    PRIVATE
        main.cpp
)
target_link_libraries(main
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
)
