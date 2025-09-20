#pragma once
#include <string>

namespace Wrappers
{
	extern "C" __declspec(dllexport) const char* ValidateOffsets();
	std::string ValidateOffset(const char* name, size_t actual, size_t expected);
}