cmake_minimum_required( VERSION 2.8 )
project( Lab_0 )

# Add libraries.
find_package(OpenCV 3 REQUIRED)

add_executable( Lab_0
  main.cpp
)

target_link_libraries( Lab_0 
  ${OpenCV_LIBS}
)
