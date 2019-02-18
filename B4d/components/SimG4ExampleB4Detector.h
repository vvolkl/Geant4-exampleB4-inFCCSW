
#ifndef GEANT4B4_DETECTORCONSTRUCTION
#define GEANT4B4_DETECTORCONSTRUCTION

// Gaudi
#include "GaudiAlg/GaudiTool.h"

// FCCSW
#include "SimG4Interface/ISimG4DetectorConstruction.h"

class SimG4ExampleB4Detector : public GaudiTool, virtual public ISimG4DetectorConstruction {
public:
  explicit SimG4ExampleB4Detector(const std::string& aType, const std::string& aName, const IInterface* aParent);
  virtual ~SimG4ExampleB4Detector();
  /**  Initialize.
   *   @return status code
   */
  virtual StatusCode initialize();
  /**  Finalize.
   *   @return status code
   */
  virtual StatusCode finalize();
  /** Get the initilization of the geometry.
   *  @return pointer to G4VUserDetectorConstruction (ownership is transferred to the caller)
   */
  virtual G4VUserDetectorConstruction* detectorConstruction();
};

#endif /* GEANT4B4_DETECTORCONSTRUCTION */
