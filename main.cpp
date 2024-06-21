#include <iostream>
#include <cmath>
#include <gcem.hpp>

#define ANKERL_NANOBENCH_IMPLEMENT
#include <nanobench.h>

using namespace ankerl::nanobench;

namespace mmath {
using gcem::return_t;

template<typename T>
constexpr return_t<T> log10(T x) {
    if (std::is_constant_evaluated()) { return gcem::log10(x); }
    return std::log10(x);
}
}   // namespace mmath

int main() {
    constexpr int n = 1024;
    Bench()
        // log10
        .run(
            "gcem log10",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(gcem::log10(static_cast<float>(i)));
                }
            }
        )
        .run(
            "cmath log10",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(std::log10(static_cast<float>(i)));
                }
            }
        )
        .run(
            "mmath log10",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(mmath::log10(static_cast<float>(i)));
                }
            }
        )
        // log2
        .run(
            "gcem log2",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(gcem::log2(static_cast<float>(i)));
                }
            }
        )
        .run(
            "cmath log2",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(std::log2(static_cast<float>(i)));
                }
            }
        )
        // exp
        .run(
            "gcem exp",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(gcem::exp(static_cast<float>(i % 16)));
                }
            }
        )
        .run(
            "cmath exp",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(std::exp(static_cast<float>(i % 16)));
                }
            }
        )
        // pow
        .run(
            "gcem pow",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(gcem::pow(static_cast<float>(i), 3.0f));
                }
            }
        )
        .run(
            "cmath pow",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(std::pow(static_cast<float>(i), 3.0f));
                }
            }
        )
        // sqrt
        .run(
            "gcem sqrt",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(gcem::sqrt(static_cast<float>(i)));
                }
            }
        )
        .run(
            "cmath sqrt",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(std::sqrt(static_cast<float>(i)));
                }
            }
        )
        // sin
        .run(
            "gcem sin",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(gcem::sin(static_cast<float>(i)));
                }
            }
        )
        .run(
            "cmath sin",
            [&] {
                for (int i = 1; i <= n; i++) { doNotOptimizeAway(std::sin(static_cast<float>(i))); }
            }
        )
        // cos
        .run(
            "gcem cos",
            [&] {
                for (int i = 1; i <= n; i++) {
                    doNotOptimizeAway(gcem::cos(static_cast<float>(i)));
                }
            }
        )
        .run("cmath cos", [&] {
            for (int i = 1; i <= n; i++) { doNotOptimizeAway(std::cos(static_cast<float>(i))); }
        });
}
