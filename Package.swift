// swift-tools-version: 5.9

import PackageDescription

let package = Package(
    name: "earcut-swift",
    products: [
        .library(name: "earcut", targets: ["earcut"]),
    ],
    targets: [
        .executableTarget(name: "demo"),
        .target(name: "earcut",
            dependencies: ["earcut_cpp"],
            swiftSettings: [.interoperabilityMode(.Cxx)]),
        .target(name: "earcut_cpp",
            dependencies: ["earcut_bridge"],
            exclude: ["earcut.hpp/test", "earcut.hpp/glfw"]
            ),
        .target(name: "earcut_bridge",
            swiftSettings: [.interoperabilityMode(.Cxx)]),
    ]
)
