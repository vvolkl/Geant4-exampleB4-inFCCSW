
from Gaudi.Configuration import *
from GaudiKernel import SystemOfUnits as units

from Configurables import ApplicationMgr
main = ApplicationMgr()
main.EvtSel = 'NONE'
main.EvtMax = 10
main.TopAlg = []
main.ExtSvc = []

from Configurables import GaussSmearVertex
smeartool = GaussSmearVertex()
smeartool.xVertexSigma =   0.5*units.mm
smeartool.yVertexSigma =   0.5*units.mm
smeartool.zVertexSigma =  40.0*units.mm
smeartool.tVertexSigma = 180.0*units.picosecond

from Configurables import  ConstPtParticleGun
pgun_tool = ConstPtParticleGun()
pgun_tool.PdgCodes = [211]

from Configurables import GenAlg
genalg_pgun = GenAlg()
genalg_pgun.SignalProvider =  ConstPtParticleGun('ToolSvc.ConstPtParticleGun')
genalg_pgun.VertexSmearingTool = smeartool
genalg_pgun.hepmc.Path = "hepmc"
ApplicationMgr().TopAlg += [genalg_pgun]

from Configurables import HepMCToEDMConverter
hepmc_converter = HepMCToEDMConverter()
hepmc_converter.hepmc.Path="hepmc"
hepmc_converter.genparticles.Path="GenParticles"
hepmc_converter.genvertices.Path="GenVertices"
ApplicationMgr().TopAlg += [hepmc_converter]



from Configurables import SimG4ExampleB4Actions
actions = SimG4ExampleB4Actions()

from Configurables import SimG4ConstantMagneticFieldTool
field = SimG4ConstantMagneticFieldTool("bField")
field.FieldOn = True
field.FieldZMax = 20*units.m
field.IntegratorStepper = "ClassicalRK4"

from Configurables import SimG4ExampleB4Detector
geant_detector_tool = SimG4ExampleB4Detector()

from Configurables import SimG4FtfpBert
geant_physics_list = SimG4FtfpBert("PhysicsList")

from Configurables import SimG4Svc
geantservice = SimG4Svc()
geantservice.detector = geant_detector_tool
geantservice.physicslist = geant_physics_list
geantservice.actions = actions
geantservice.magneticField = field
# range cut
geantservice.g4PostInitCommands += ["/run/setCut 0.1 mm"]
ApplicationMgr().ExtSvc +=  [geantservice]




from Configurables import SimG4PrimariesFromEdmTool
particle_converter = SimG4PrimariesFromEdmTool("EdmConverter")
particle_converter.genParticles.Path = "GenParticles"



from Configurables import SimG4Alg
geantsim = SimG4Alg("SimG4Alg")
geantsim.outputs = []
geantsim.eventProvider = particle_converter
main.TopAlg += [geantsim]
