
gaudi_subdir(B4d v1r0)

gaudi_depends_on_subdirs(GaudiAlg)
#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
include(${Geant4_USE_FILE})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hh)

message("sources:" ${sources})

#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries

add_library(libGeant4ExampleB4d ${sources} ${headers})
target_link_libraries(libGeant4ExampleB4d ${Geant4_LIBRARIES})

#
# the exampleB4d executable is replaced by the SimG4Alg/SimG4Svc in FCCSW
#gaudi_add_executable(exampleB4d exampleB4d.cc  ${headers} LINK_LIBRARIES Geant4 )
#target_link_libraries(exampleB4d libGeant4ExampleB4d)

gaudi_add_module(exampleB4dGaudiComponents
                 components/*.cpp ${headers}
                 INCLUDE_DIRS Geant4 
                 LINK_LIBRARIES GaudiAlgLib Geant4 libGeant4ExampleB4d)

