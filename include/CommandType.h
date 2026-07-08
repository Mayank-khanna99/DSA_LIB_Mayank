#pragma once

enum class CommandType
{
    SET,
    GET,
    DEL,
    EXISTS,
    CLEAR,
    PRINT,
    STATS,
    SIZE,
    KEYS,
    EXIT,
    INVALID
};