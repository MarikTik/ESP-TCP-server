#ifndef HASHABLE_STRING_H_
#define HASHABLE_STRING_H_
#include <cstddef>

class hashable_string{
     public:
          hashable_string(const char *str);
          inline bool operator==(const hashable_string& other) const;
          inline const char* c_str() const;
          inline size_t length() const;
     private:
          const size_t _length;
          const char *_str;
};

struct hashable_string_hash{
     size_t operator()(const hashable_string &str) const;
};

#endif