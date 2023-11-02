import Foundation
import earcut

let indices = earcut(polygons: [[[0, 0], [100, 0], [100, 100], [0, 100]]])
print(indices)
