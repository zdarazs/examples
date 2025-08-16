cmake_minimum_required( VERSION 3.20 )

project( small_codes VERSION 1.0.0 LANGUAGES CXX )

set( CXX_STANDARD 20 )
set( CXX_STANDARD_REQUIRED ON )
add_compile_options( -Wall -Wextra -pedantic -O3 )

#add_executable( rule_five.exe rule_five.cpp )
#add_executable( class_rational.exe class_rational.cpp )
#add_executable( virt_fn_ctor.exe virt_fn_ctor.cpp )
#add_executable( this_type_function.exe this_type_function.cpp )
add_executable( class_pointers.exe class_pointers.cpp )