

archive:
    xcodebuild archive -project earcut.xcodeproj -scheme earcut -destination "generic/platform=macOS" -archivePath "/tmp/earcut-macOS"

xcframework:
    xcodebuild -create-xcframework -archive /tmp/earcut-macOS-iOS.xcarchive -framework earcut.framework -output xcframeworks/MyFramework.xcframework
