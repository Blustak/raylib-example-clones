function(add_project subdir)
  cmake_dependent_option(BUILD_${subdir} "Build ${subdir}" ON ${mod_name} OFF)
  set(project_exe_name ${PROJECT_NAME}_${subdir})
  if (BUILD_${subdir})
    add_subdirectory(${subdir})
  endif()
endfunction()

add_module(core core_mod)
