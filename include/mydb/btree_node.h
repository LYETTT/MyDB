#pragma once

#include <cstdint>

class BNode {
public:
    std::uint16_t btype() const;
    std::uint16_t nkeys() const;
};
