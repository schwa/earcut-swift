// swift-tools-version: 5.9

import PackageDescription

let package = Package(
    name: "earcut-swift",
    platforms: [
        .macOS(.v14),
    ],
    products: [
        .library(name: "earcut", targets: ["earcut"]),
    ],
    targets: [
        .executableTarget(name: "demo",
            dependencies: ["earcut"],
            swiftSettings: [.interoperabilityMode(.Cxx)]
        ),
        .target(name: "earcut",
            dependencies: ["earcut_cpp"],
            swiftSettings: [.interoperabilityMode(.Cxx)]
        ),
        .target(name: "earcut_cpp",
            exclude: ["earcut.hpp/test", "earcut.hpp/glfw"]
        ),
    ]
)
