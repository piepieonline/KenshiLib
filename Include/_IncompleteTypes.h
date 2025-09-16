#pragma once

#include <cstdint>
#include <MyGUI_Widget.h>
#include "kenshi/Character.h";

namespace Kenshi
{
	namespace wraps
	{
		class BaseLayout
		{
			public:
				BaseLayout();
				virtual void test();

				MyGUI::Widget* widget;
				// std::string prefix;
				char* prefix[16];
		};
	};

	class InventoryIcon : public wraps::BaseLayout
	{

	};

	class GUIWindow
	{

	};

	class ActivePlatoon_PlatoonMembers_DataPtr
	{
	public:
		CharacterHuman* character; //0x0000 

	}; //Size=0x0008

	class ActivePlatoon_PlatoonMembers
	{
	public:
		ActivePlatoon_PlatoonMembers_DataPtr data[5]; //0x0000 

	}; //Size=0x0028

	class ActivePlatoon
	{
	public:
		char pad_0x0000[0x18]; //0x0000
		char* SaveFile; //0x0018 
		char pad_0x0020[0x38]; //0x0020
		__int32 platoonMemberCount; //0x0058 
		char pad_0x005C[0x4]; //0x005C
		ActivePlatoon_PlatoonMembers* platoonMembers; //0x0060 
		char pad_0x0068[0xC58]; //0x0068

	}; //Size=0x0CC0

	class Platoon
	{
	public:
		char pad_0x0000[0x10]; //0x0000
		Faction* ownerFaction; //0x0010 
		char currentName[16]; //0x7EF9E9C0 
		__int32 currentNameLength; //0x0028 
		char pad_0x002C[0x4C]; //0x002C
		char previousNameMaybe[16]; //0x7EF9E9C0 
		__int32 previousNameLength; //0x0088 
		char pad_0x008C[0x7C]; //0x008C
		GameData* platoonTemplate; //0x0108 
		char pad_0x0110[0x38]; //0x0110
		Ownerships* ownerships; //0x0148 
		char pad_0x0150[0x88]; //0x0150
		ActivePlatoon* currentActivePlatoon; //0x01D8 
		char pad_0x01E0[0x2C8]; //0x01E0

	}; //Size=0x04A8

}