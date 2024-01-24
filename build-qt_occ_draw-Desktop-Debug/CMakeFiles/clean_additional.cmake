# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/cad_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/cad_autogen.dir/ParseCache.txt"
  "cad_autogen"
  )
endif()
