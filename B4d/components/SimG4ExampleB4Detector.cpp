
#include "B4dDetectorConstruction.hh"

#include "SimG4ExampleB4Detector.h"


// Geant4
#include "G4VUserDetectorConstruction.hh"

DECLARE_TOOL_FACTORY(SimG4ExampleB4Detector)

SimG4ExampleB4Detector::SimG4ExampleB4Detector(const std::string& aType, const std::string& aName, const IInterface* aParent)
    : GaudiTool(aType, aName, aParent) {
  declareInterface<ISimG4DetectorConstruction>(this);
}

SimG4ExampleB4Detector::~SimG4ExampleB4Detector() {}

StatusCode SimG4ExampleB4Detector::initialize() {
  if (GaudiTool::initialize().isFailure()) {
    return StatusCode::FAILURE;
  }
  return StatusCode::SUCCESS;
}

StatusCode SimG4ExampleB4Detector::finalize() { return GaudiTool::finalize(); }

G4VUserDetectorConstruction* SimG4ExampleB4Detector::detectorConstruction() { 
  
  
  
  return new B4dDetectorConstruction();
  
   }
