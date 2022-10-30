# SPDX-License-Identifier: BSD-3-Clause
# Copyright 2016 Blender Foundation.

# - Find Cling library
# Find the native Cling includes and libraries
# This module defines
#  CLING_INCLUDE_DIRS, where to find Cling headers, Set when
#                        CLING_INCLUDE_DIR is found.
#  CLING_LIBRARIES, libraries to link against to use Cling.
#  CLING_ROOT_DIR, The base directory to search for Cling.
#                    This can also be an environment variable.
#  CLING_FOUND, If false, do not try to use Cling.
#

# If CLING_ROOT_DIR was defined in the environment, use it.
# IF(NOT CLING_ROOT_DIR AND NOT $ENV{CLING_ROOT_DIR} STREQUAL "")
#   SET(CLING_ROOT_DIR $ENV{CLING_ROOT_DIR})
# ENDIF()

SET(_cling_SEARCH_DIRS
#   ${CLING_ROOT_DIR}
    /home/malik446644/blender-git/lib/linux_centos7_x86_64/cling
)

FIND_PATH(CLING_INCLUDE_DIR
  NAMES
    cling/Interpreter/Interpreter.h
  HINTS
    ${_cling_SEARCH_DIRS}
  PATH_SUFFIXES
    include
)

FIND_LIBRARY(CLING_LIBRARY
  NAMES
    clingInterpreter
  HINTS
    ${_cling_SEARCH_DIRS}
  PATH_SUFFIXES
    lib
)

# handle the QUIETLY and REQUIRED arguments and set CLING_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Cling DEFAULT_MSG CLING_LIBRARY CLING_INCLUDE_DIR)

# IF(CLING_FOUND)
  SET(CLING_LIBRARIES ${CLING_LIBRARY})
  SET(CLING_INCLUDE_DIRS ${CLING_INCLUDE_DIR})
# ENDIF()

MARK_AS_ADVANCED(
  CLING_INCLUDE_DIR
  CLING_LIBRARY
)

UNSET(_cling_SEARCH_DIRS)
