#pragma once
#include <list>
#include <ctime>
#include <cassert>

template<class Money>
class Paper {
private:
    std::list<Money> annotations;
public:
    Paper();
    Money betAmount();
    void lose();
    void win();
    void restart();
};
