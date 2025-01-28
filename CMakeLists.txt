cmake_minimum_required(VERSION 3.30)
project(c_practice C)

set(CMAKE_C_STANDARD 11)

# 라이브러리 생성
add_library(linked_list linked_list/sll.c
        linked_list/dll.c)

add_executable(c_practice main.c)

# 실행 파일에 라이브러리 연결
target_link_libraries(c_practice linked_list)
