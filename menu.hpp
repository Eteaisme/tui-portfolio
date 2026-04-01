#pragma once
#include <ftxui/dom/elements.hpp>
#include <functional>
#include <string>
#include <vector>

using namespace ftxui;

struct Menu_Item {
    std::string item_name; 
    std::function<Element()> item_content; 
};

class Custom_Menu{
    Custom_Menu(std::vector<Menu_Item> items, int width = 24);
};
