#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <limits>
#include <memory>
#include <utility>
#include <vector>

#include <simd/simd.h>
#include "../earcut.hpp/include/mapbox/earcut.hpp"

#include <earcut_bridge/earcut_bridge-Swift.h>

namespace mapbox {
namespace util {

template <>
struct nth<0, simd_float2> {
    inline static auto get(const simd_float2 &t) {
        return t.x;
    };
};
template <>
struct nth<1, simd_float2> {
    inline static auto get(const simd_float2 &t) {
        return t.y;
    };
};

template <typename N = uint32_t>
std::vector<N> earcut_std_simd(const std::vector<std::vector<simd_float2>>& poly) {
    return earcut(poly);
}

template <typename N = uint32_t>
std::vector<N> earcut_swift_simd(const swift::array<swift::array<simd_float2>>& poly) {
    return earcut(poly);
}


} // namespace util
} // namespace mapbox
