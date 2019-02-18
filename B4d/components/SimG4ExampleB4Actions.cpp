
#include "B4dActionInitialization.hh"

#include "SimG4ExampleB4Actions.h"


DECLARE_COMPONENT(SimG4ExampleB4Actions)

SimG4ExampleB4Actions::SimG4ExampleB4Actions(const std::string& type, const std::string& name, const IInterface* parent)
    : AlgTool(type, name, parent) {
  declareInterface<ISimG4ActionTool>(this);
}

SimG4ExampleB4Actions::~SimG4ExampleB4Actions() {}

StatusCode SimG4ExampleB4Actions::initialize() {
  if (AlgTool::initialize().isFailure()) {
    return StatusCode::FAILURE;
  }
  return StatusCode::SUCCESS;
}

StatusCode SimG4ExampleB4Actions::finalize() { return AlgTool::finalize(); }

G4VUserActionInitialization* SimG4ExampleB4Actions::userActionInitialization() {
  return new B4dActionInitialization();
}
