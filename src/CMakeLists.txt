add_library(lexer
    lexer/lexer.cpp
)

add_library(ast
    ast/ast.cpp
)

add_library(parser
    parser/parser.cpp
)

add_library(logger
    logger/logger.cpp
)

add_executable(kalell
    main.cpp
)

target_link_libraries(kalell
    lexer  
    ast  
    parser
    logger
)

target_include_directories(lexer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ast PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})