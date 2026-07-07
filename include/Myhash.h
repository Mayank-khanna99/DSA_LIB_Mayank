#pragma once

#include <string>
#include<cstring>

template<typename T>
class MyHash;

template<>
class MyHash<int>
{
public:
    size_t operator()(const int& key) const
    {
        return key;
    }
};

template<>
class MyHash<long>
{
public:
    size_t operator()(const long& key) const
    {
        return key;
    }
};


template<>
class MyHash<char>
{
public:
    size_t operator()(const char& key) const
    {
        return key;
    }
};

template<>
class MyHash<float>
{
public:
    size_t operator()(const float& key) const
    {
        uint32_t bits;
        std::memcpy(&bits, &key, sizeof(bits));

        bits ^= bits >> 16;
        bits *= 0x7feb352d;
        bits ^= bits >> 15;
        bits *= 0x846ca68b;
        bits ^= bits >> 16;

        return bits;
    }
};

template<>
class MyHash<double>
{
public:
    size_t operator()(const double& key) const
    {
        uint64_t bits;
        std::memcpy(&bits, &key, sizeof(bits));

        bits ^= bits >> 33;
        bits *= 0xff51afd7ed558ccdULL;
        bits ^= bits >> 33;
        bits *= 0xc4ceb9fe1a85ec53ULL;
        bits ^= bits >> 33;

        return static_cast<size_t>(bits);
    }
};



template<>
class MyHash<std::string>
{
public:
    size_t operator()(const std::string& key) const
    {
        size_t h = 0;

        for(char c : key)
            h = h * 31 + c;

        return h;
    }
};