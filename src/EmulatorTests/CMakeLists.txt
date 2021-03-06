cmake_minimum_required (VERSION 2.8)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON) 
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost COMPONENTS unit_test_framework)

include_directories("${CMAKE_SOURCE_DIR}/src/EmulatorLib")
include_directories("${CMAKE_SOURCE_DIR}/src/Utils")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

if(WIN32)
    set( SOURCES 
        main.cpp 
        interpreter_tests.cpp 
        interpreter_tests.h 
        gpu_tests.cpp 
        gpu_tests.h
        utils_tests.cpp
        )

    set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

    # Boost
    include_directories("${Boost_INCLUDE_DIR}")
    link_directories("${Boost_LIBRARY_DIRS}")
    
    # Emulator 
    link_directories("${CMAKE_BINARY_DIR}/lib")
    
    add_executable(EmulatorTests ${SOURCES}) 
    target_link_libraries(EmulatorTests ${Boost_LIBRARIES} ${SDL2_LIBRARY} ${SDL2MAIN_LIBRARY} EmulatorLib)
	
    add_custom_command(TARGET EmulatorTests
               POST_BUILD 
    		   COMMAND ${CMAKE_COMMAND} -E copy_directory
    			   "${PROJECT_SOURCE_DIR}/Chip16 Program Pack"
    			   $<TARGET_FILE_DIR:EmulatorTests>
    			   COMMENT "Copying test pack")
else()
    include(${PROJECT_SOURCE_DIR}/cmake/BoostTestHelpers.cmake)

    list(APPEND LIBS EmulatorLib ${SDL2_LIBRARY} ${SDL2MAIN_LIBRARY})
    add_boost_test(interpreter_tests.cpp "${LIBS}")
    add_boost_test(gpu_tests.cpp "${LIBS}")
    add_boost_test(utils_tests.cpp EmulatorLib)
endif()
