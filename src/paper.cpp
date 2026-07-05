#include <list>
#include "paper.hpp"

// Implementation of Paper<int>

/* Initial annotations. Used in default constructor
 */
const std::list<int> initialAnnotations = {1,2,3,4};

/* Default constructor. Uses initial annotations
 */
template<>
Paper<int>::Paper():
    annotations(initialAnnotations)
{}

/* Restarts annotations
 */
template<>
void Paper<int>::restart() {
    annotations = initialAnnotations;
}

/* Returns bet amount calculated using annotations
 */
template<>
int Paper<int>::betAmount() {
    if (annotations.size() == 0)
        restart();

    if (annotations.size() == 1)
        return annotations.front();

    return (annotations.front() +
            annotations.back());
}

/* Records a lose
 */
template<>
void Paper<int>::lose() {
    assert(annotations.size() > 0);
    if (annotations.size() == 1)
        annotations.pop_back();
    else {
        annotations.pop_back();
        annotations.pop_front();
    }
}

/* Records a win
 */
template<>
void Paper<int>::win() {
    assert(annotations.size() > 0);
    annotations.push_back(betAmount());
}