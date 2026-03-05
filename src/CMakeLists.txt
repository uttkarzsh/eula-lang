add_library(lexer
    lexer/lexer.cpp
)

add_executable(kalell
    main.cpp
)

target_link_libraries(kalell
    lexer    
)

target_include_directories(lexer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})