cmake_minimum_required(VERSION 3.16)
project(Wallet VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 REQUIRED COMPONENTS Core Quick Svg)
find_package(Qt6 QUIET COMPONENTS Multimedia)
set(QT_QML_GENERATE_QMLLS_INI ON)
qt_standard_project_setup()
qt_add_executable(Wallet
 src/main.cpp
 src/include/wifimanager.h
 src/wifimanager.cpp
 src/include/systemmanager.h
 src/systemmanager.cpp
)

target_include_directories(Wallet PRIVATE
 src
)

# Mark AppConstants.qml as singleton BEFORE qt_add_qml_module
set_source_files_properties(src/qml/AppConstants.qml
 PROPERTIES QT_QML_SINGLETON_TYPE TRUE
)

# Automatically find all QML files with relative paths
file(GLOB_RECURSE QML_FILES_LIST RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "src/qml/*.qml")

# Find all SVG files in img directory
file(GLOB_RECURSE SVG_FILES_LIST RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "src/img/*.svg")

# Add QML module to the executable
qt_add_qml_module(Wallet
 URI WalletModule
 VERSION 1.0
 NO_GENERATE_QMLTYPES
 NO_CACHEGEN
 NO_LINT
 QML_FILES ${QML_FILES_LIST}
 RESOURCES ${SVG_FILES_LIST}
)
target_link_libraries(Wallet PRIVATE
 Qt6::Core
 Qt6::Quick
 Qt6::Svg
)

# Link Qt6::Multimedia if available
if(TARGET Qt6::Multimedia)
 target_link_libraries(Wallet PRIVATE Qt6::Multimedia)
 target_compile_definitions(Wallet PRIVATE HAVE_QT_MULTIMEDIA)
 message(STATUS "Qt6Multimedia found - camera support enabled")
else()
 message(WARNING "Qt6Multimedia not found - camera support disabled")
endif()
# Platform specific settings
if(WIN32)
 set_property(TARGET Wallet PROPERTY WIN32_EXECUTABLE TRUE)
 set_target_properties(Wallet PROPERTIES OUTPUT_NAME "wallet")
else()
 # Linux/Unix - set output name to lowercase
 set_target_properties(Wallet PROPERTIES OUTPUT_NAME "wallet")
endif()
# Set application properties
set_target_properties(Wallet PROPERTIES
 MACOSX_BUNDLE_GUI_IDENTIFIER org.libersoft.matchbox-wallet
 MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
 MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
 MACOSX_BUNDLE TRUE
 WIN32_EXECUTABLE TRUE
)
