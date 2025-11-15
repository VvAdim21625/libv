set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required(VERSION 3.15)
project(libv VERSION 1.0 LANGUAGES CXX)

# Создание динамической библиотеки
add_library(libv SHARED
    src/vNode.cpp
    src/vList.cpp
)

# Указываем, где искать заголовочные файлы
target_include_directories(libv
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}include>
        $<INSTALL_INTERFACE:include>
)

# Определяем макрос для экспорта на Windows
target_compile_definitions(libv PRIVATE LIBV_EXPORTS)

# Пример программы
add_executable(example examples/main.cpp)
target_link_libraries(example PRIVATE libv)

# Копируем DLL рядом с exe на Windows для удобства запуска
if(WIN32)
  add_custom_command(TARGET example POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:libv>
            $<TARGET_FILE_DIR:example>
    )
endif()
