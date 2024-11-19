cmake_minimum_required(VERSION 3.24)
project(TermPlayer)

find_package(TagLib REQUIRED)
find_package(SFML 2.5 REQUIRED audio)
find_package(ftxui REQUIRED)
message("All Required packages have been found by cmake")

add_executable(${PROJECT_NAME}
    main.cpp
    metadata.cpp
    metadata.h
)
target_link_libraries(${PROJECT_NAME} 
    PRIVATE
    TagLib::TagLib 
    sfml-audio 
    ftxui::screen 
    ftxui::component
)