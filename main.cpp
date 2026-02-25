#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
 
int main() {
 
  auto screen = ftxui::Screen::Create(
    ftxui::Dimension:: Full(),
    ftxui::Dimension::Full()
  );

  auto &pixel = screen.PixelAt(10, 5); 
 
  pixel.character = U'@';
  pixel.background_color = ftxui::Color::Red;
  pixel.foreground_color = ftxui::Color::Blue;
  
 
  screen.Print();
}
