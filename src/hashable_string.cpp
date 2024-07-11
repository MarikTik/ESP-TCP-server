#include "hashable_string.h"
#include <cstring>
#include "extern.h"

hashable_string::hashable_string(const char *str)
     : _str(str), _length(std::strlen(str))
{
}

bool hashable_string::operator==(const hashable_string &other) const
{
     return !std::strcmp(_str, other._str);
}

const char *hashable_string::c_str() const
{
     return _str;
}

inline size_t hashable_string::length() const
{
     return _length;
}

size_t hashable_string_hash::operator()(const hashable_string &str) const
{
     return MurmurOAAT(str.c_str(), str.length(), 0x9747b28c); //number picked at random
}
