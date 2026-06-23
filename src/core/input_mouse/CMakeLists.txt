add_executable(${project_exe_name})
target_sources(${project_exe_name} PRIVATE main.c)
target_link_libraries(${project_exe_name} PRIVATE raylib)
