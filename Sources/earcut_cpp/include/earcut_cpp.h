#pragma once

#include <Foundation/Foundation.h>
#include <earcut_cpp/earcut.hpp>

//! Project version number for earcut_cpp.
FOUNDATION_EXPORT double earcut_cppVersionNumber;

//! Project version string for earcut_cpp.
FOUNDATION_EXPORT const unsigned char earcut_cppVersionString[];


#ifdef __cplusplus

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <limits>
#include <memory>
#include <utility>
#include <vector>

#include <simd/simd.h>
//#include "../earcut.hpp/include/mapbox/earcut.hpp"

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

} // namespace util

using Polygon = std::vector<simd_float2>;
using Polygons = std::vector<Polygon>;
using Indices = std::vector<uint32_t>;

Indices earcut_simd(const Polygons& poly) {
    return earcut(poly);
}//
//  earcut_cpp.h
//  earcut_cpp
//
//  Created by Jonathan Wight on 11/2/23.
//

// In this header, you should import all the public headers of your framework using statements like #import <earcut_cpp/PublicHeader.h>




} // namespace mapbox

#endif // __cplusplus
