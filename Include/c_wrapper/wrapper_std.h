#pragma once

#include <iostream>
#include <string>
#include <cstring>

namespace Wrappers
{
    class String_Wrap {
        char refOrChars[0x10];
        uint32_t len;
        char padding[0x10];

    public:
        operator std::string() const {
            return std::string(toCStr());
        }

        friend std::ostream& operator<<(std::ostream& os, const String_Wrap& fs) {
            os.write(fs.c_str(), fs.size());
            return os;
        }

        const char* c_str() const { return toCStr(); }
        size_t size() const { return len; }

    private:
        char* toCStr() const
        {
            if (padding[4] == '\x1f')
                return (char*)*(void**)refOrChars;
            else
                return (char*)refOrChars;
        }
    };

}