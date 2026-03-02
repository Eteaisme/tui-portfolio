cmake_minimum_required(VERSION 4.2.3)
project(tui-portfolio)
find_package(ftxui REQUIRED)
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
