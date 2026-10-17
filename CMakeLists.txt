cmake_minimum_required(VERSION 3.16)
project(programming LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Header-only until the library has implementations in src/ds/.
add_library(ds INTERFACE)
target_include_directories(ds INTERFACE "${PROJECT_SOURCE_DIR}/include")

add_library(leetcode_support INTERFACE)
target_include_directories(leetcode_support INTERFACE "${PROJECT_SOURCE_DIR}/support")

function(add_leetcode_exercise problem)
    set(target "leetcode_${problem}")
    set(source "exercises/leetcode/${problem}/solution.cpp")

    if(ARGV1 STREQUAL "OBJECT")
        # Solutions provided as class Solution have no standalone entry point.
        add_library(${target} OBJECT "${source}")
    else()
        add_executable(${target} "${source}")
    endif()

    target_link_libraries(${target} PRIVATE ds leetcode_support)
endfunction()

add_leetcode_exercise(0001_two_sum)
add_leetcode_exercise(0009_palindrome_number)
add_leetcode_exercise(0013_roman_to_integer)
add_leetcode_exercise(0014_longest_common_prefix)
add_leetcode_exercise(0020_valid_parenthesis)
add_leetcode_exercise(0021_merge_two_sorted_lists OBJECT)
add_leetcode_exercise(0035_search_insert_position)
add_leetcode_exercise(0058_length_of_last_word)
add_leetcode_exercise(0066_plus_one)
add_leetcode_exercise(0067_add_binary)
add_leetcode_exercise(0069_sqrt)
add_leetcode_exercise(0070_climbing_stairs)
add_leetcode_exercise(0083_remove_duplicates_from_sorted_list OBJECT)
