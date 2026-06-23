function(add_project subdir option_name)
  option(${option_name} "Build ${option_name}")
  set(project_exe_name ${PROJECT_NAME}_${option_name})
  if (${option_name})
    add_subdirectory(${subdir})
  endif()
endfunction()

add_project("delta_time" delta_time)
