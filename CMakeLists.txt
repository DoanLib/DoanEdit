cmake_minimum_required(VERSION 4.1)

# ============================================================================ #
#   Project                                                                    #
# ============================================================================ #

project(DoanEdit
  VERSION 0.1.0
  DESCRIPTION "Personal text editor for programming"
  LANGUAGES C
)

# ============================================================================ #
#   Configuration                                                              #
# ============================================================================ #

add_subdirectory(external/DoanLib)

# ============================================================================ #
#   Executable                                                                 #
# ============================================================================ #

set(SOURCE_FILES
  "src/main.c"
)

add_executable(DoanEdit ${SOURCE_FILES})
target_include_directories(DoanEdit PRIVATE "src/")
target_link_libraries(DoanEdit PRIVATE DoanLib)
dn_target_setup(DoanEdit)
