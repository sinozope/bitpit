#---------------------------------------------------------------------------
#
#  bitpit
#
#  Copyright (C) 2015-2016 OPTIMAD engineering Srl
#
#  -------------------------------------------------------------------------
#  License
#  This file is part of bitbit.
#
#  bitpit is free software: you can redistribute it and/or modify it
#  under the terms of the GNU Lesser General Public License v3 (LGPL)
#  as published by the Free Software Foundation.
#
#  bitpit is distributed in the hope that it will be useful, but WITHOUT
#  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
#  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
#  License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with bitpit. If not, see <http://www.gnu.org/licenses/>.
#
#---------------------------------------------------------------------------*/

# CMake settings
cmake_minimum_required(VERSION 2.8)

# Add library to targets
include_directories("${PROJECT_SOURCE_DIR}/src/common")
include_directories("${PROJECT_SOURCE_DIR}/src/operators")
include_directories("${PROJECT_SOURCE_DIR}/src/containers")
include_directories("${PROJECT_SOURCE_DIR}/src/IO")
include_directories("${PROJECT_SOURCE_DIR}/src/patchkernel")

file(GLOB SOURCE_FILES "*.cpp")
set(VOLUNSTRUCTURED_SOURCES "${SOURCE_FILES}" CACHE INTERNAL "Sources of volunstructured module" FORCE)
unset(SOURCE_FILES)

file(GLOB HEADER_FILES "*.hpp" "*.tpp")
set(VOLUNSTRUCTURED_HEADERS "${HEADER_FILES}" CACHE INTERNAL "Headers of volunstructured module" FORCE)
unset(HEADER_FILES)

if (NOT "${VOLUNSTRUCTURED_SOURCES}" STREQUAL "")
    add_library(VOLUNSTRUCTURED_TARGET_OBJECT OBJECT ${VOLUNSTRUCTURED_SOURCES})
endif ()

install(FILES ${VOLUNSTRUCTURED_HEADERS} DESTINATION include/${CMAKE_PROJECT_NAME})
