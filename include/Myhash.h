#pragma once

#include <string>

class MyHash {
public:

    static size_t hash(int key) {
        return key;
    }

    static size_t hash(long key) {
        return key;
    }

    static size_t hash(char key) {
        return key;
    }

    static size_t hash(float key) {
        return static_cast<size_t>(key * 1000);
    }

    static size_t hash(double key) {
        return static_cast<size_t>(key * 1000000);
    }

    static size_t hash(const std::string& key) {
        size_t h = 0;

        for(char c : key)
            h = h * 31 + c;

        return h;
    }
};