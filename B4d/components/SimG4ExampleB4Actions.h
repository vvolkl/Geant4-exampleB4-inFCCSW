#ifndef SIMG4EXAMPLEB4_ACTIONS
#define SIMG4EXAMPLEB4_ACTIONS

// Gaudi
#include "GaudiKernel/AlgTool.h"
#include "GaudiKernel/SystemOfUnits.h"


// FCCSW
#include "SimG4Interface/ISimG4ActionTool.h"


class SimG4ExampleB4Actions : public AlgTool, virtual public ISimG4ActionTool {
public:
  explicit SimG4ExampleB4Actions(const std::string& type, const std::string& name, const IInterface* parent);
  virtual ~SimG4ExampleB4Actions();

  /**  Initialize.
   *   @return status code
   */
  virtual StatusCode initialize() final;
  /**  Finalize.
   *   @return status code
   */
  virtual StatusCode finalize();
  /** Get the user action initialization.
   *  @return pointer to G4VUserActionInitialization (ownership is transferred to the caller)
   */
  virtual G4VUserActionInitialization* userActionInitialization() final;

private:
  /// Set to true to save secondary particle info
  Gaudi::Property<bool> m_enableHistory{this, "enableHistory", false, "Set to true to save secondary particle info"};
};

#endif /* SIMG4EXAMPLEB4_ACTIONS */
