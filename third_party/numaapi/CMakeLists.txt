# ***** BEGIN GPL LICENSE BLOCK *****
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#
# ***** END GPL LICENSE BLOCK *****

add_library(extern_numaapi STATIC
	source/numaapi.c
	source/numaapi_linux.c
	source/numaapi_stub.c
	source/numaapi_win32.c

	include/numaapi.h
	source/build_config.h
)
target_include_directories(extern_numaapi PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_compile_definitions(extern_numaapi PRIVATE -DWITH_DYNLOAD)
