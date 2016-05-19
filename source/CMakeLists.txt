# Build example
add_executable(beispielprogramm
  beispielprogramm.cpp
  )
  
target_link_libraries(beispielprogramm
  glfw
  ${GLFW_LIBRARIES}
  m)
add_dependencies(beispielprogramm glfw ${COPY_BINARY})






# Build 2-4
add_executable(aufgabe2bis4
  aufgabe2bis4.cpp
  )
  
target_link_libraries(aufgabe2bis4
  glfw
  ${GLFW_LIBRARIES}
  m)
add_dependencies(aufgabe2bis4 glfw ${COPY_BINARY})





# Build 5
add_executable(aufgabe5und7
  aufgabe5und7.cpp
  circle.cpp
  )
  
target_link_libraries(aufgabe5und7
  glfw
  ${GLFW_LIBRARIES}
  m)
add_dependencies(aufgabe5und7 glfw ${COPY_BINARY})


