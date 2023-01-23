project('quicksilver', 'cpp',
  version : '1.0',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

conf_data = configuration_data()
conf_data.set('version', '1.0')

vcs_dep=vcs_tag(command: ['git', 'log', '-1', '--format=%aI'],
                input:'src/git_vers.hh.in', output: 'git_vers.hh',
                replace_string: '@GIT_VERS@')
vcs_dep=vcs_tag(command: ['git', 'log', '-1', '--format=%H'],
                input:'src/git_hash.hh.in', output: 'git_hash.hh',
                replace_string: '@GIT_HASH@')

incdirs = include_directories('src', '.')

openmp = dependency('OpenMP', language: 'cpp')
#tbb = dependency('TBB', method: 'cmake', modules: ['TBB::tbb'])

executable('quicksilver',
           'src/CollisionEvent.cc',
           'src/CoralBenchmark.cc',
           'src/CycleTracking.cc',
           'src/DecompositionObject.cc',
           'src/DirectionCosine.cc',
           'src/EnergySpectrum.cc',
           'src/GlobalFccGrid.cc',
           'src/GlobalFccGrid.hh',
           'src/GridAssignmentObject.cc',
           'src/InputBlock.cc',
           'src/MCT.cc',
           'src/MC_Adjacent_Facet.cc',
           'src/MC_Base_Particle.cc',
           'src/MC_Domain.cc',
           'src/MC_Facet_Crossing_Event.cc',
           'src/MC_Fast_Timer.cc',
           'src/MC_Load_Particle.cc',
           'src/MC_Location.cc',
           'src/MC_Particle_Buffer.cc',
           'src/MC_RNG_State.cc',
           'src/MC_Segment_Outcome.cc',
           'src/MC_SourceNow.cc',
           'src/MacroscopicCrossSection.cc',
           'src/MacroscopicCrossSection.hh',
           'src/MeshPartition.cc',
           'src/MonteCarlo.cc',
           'src/MpiCommObject.cc',
           'src/NuclearData.cc',
           'src/Parameters.cc',
           'src/ParticleVault.cc',
           'src/ParticleVaultContainer.cc',
           'src/PhysicalConstants.cc',
           'src/PopulationControl.cc',
           'src/SendQueue.cc',
           'src/SharedMemoryCommObject.cc',
           'src/Tallies.cc',
           'src/cmdLineParser.cc',
           'src/cudaFunctions.cc',
           'src/initMC.cc',
           'src/main.cc',
           'src/parseUtils.cc',
           'src/utils.cc',
           'src/utilsMpi.cc',
           include_directories: incdirs,
           dependencies: [openmp],
           install : true)
