#include "c_wrapper/wrapper_kenshilib.h"

#include "mygui/MyGUI.h"
#include "kenshi/Character.h"
#include "kenshi/GameWorld.h"
#include "kenshi/PlayerInterface.h"

const char* Wrappers::ValidateOffsets()
{
    std::string output = "";

    output += ValidateOffset("GameDataContainer::gamedataID", offsetof(Kenshi::GameDataContainer, gamedataID), 0x50);
    output += ValidateOffset("GameWorld::player", offsetof(Kenshi::GameWorld, player), 0x580);


    output += ValidateOffset("PlayerInterface::selectBox", offsetof(Kenshi::PlayerInterface, selectBox), 0xA8);
    output += ValidateOffset("PlayerInterface::mRightDown", offsetof(Kenshi::PlayerInterface, mRightDown), 0x2F4);

    output += ValidateOffset("Character::naturalWeapon", offsetof(Kenshi::Character, naturalWeapon), 0x6D0);

    output += ValidateOffset("MyGUI::Widget::mName", offsetof(MyGUI::Widget, mName), 0x428);

    return output.c_str();
}

std::string Wrappers::ValidateOffset(const char* name, size_t actual, size_t expected) {
    if (actual != expected) {
        std::stringstream ss;
        ss << "[!] Offset mismatch for " << name
            << ". Expected 0x" << std::hex << expected
            << ", Actual 0x" << actual << "\n";
        return ss.str();
    }

    return std::string(name) + " was found in the right location.\n";
}