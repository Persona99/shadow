#include "random.h"

namespace Shadow {
std::mt19937 Random::sRandomEngine;
std::uniform_int_distribution<std::mt19937::result_type> Random::sDistribution;
}