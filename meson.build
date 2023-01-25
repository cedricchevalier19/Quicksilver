project('quicksilver', 'cpp',
  version : '1.0',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

conf_data = configuration_data()

vcs_dep=vcs_tag(command: ['git', 'log', '-1', '--format=%aI'],
                input:'src/git_vers.hh.in', output: 'git_vers.hh',
                replace_string: '@GIT_VERS@')
vcs_dep=vcs_tag(command: ['git', 'log', '-1', '--format=%H'],
                input:'src/git_hash.hh.in', output: 'git_hash.hh',
                replace_string: '@GIT_HASH@')

incdirs = include_directories('src', '.')

openmp = dependency('OpenMP', language: 'cpp', required: get_option('use_openmp'))

mpi = dependency('MPI', language: 'c', required: get_option('use_mpi'))

conf_data.set('HAVE_OPENMP', openmp.found(), description: 'Enable OpenMP pragmas')
conf_data.set('HAVE_OPENMP_TARGET', get_option('use_openmp_target'), description:'Use OpenMP target pragmas')
conf_data.set('USE_OPENMP_NO_GPU', get_option('use_openmp_target_nogpu'), description: 'Use OpenMP target without GPU offloading')
conf_data.set('HAVE_MPI', mpi.found(), description: 'Enable distributed memory parallelism')
conf_data.set('DHAVE_ASYNC_MPI', get_option('use_async_mpi'), description: 'Use MPI_Iallreduce to check termination')
conf_data.set('EXPONENTIAL_TALLY', get_option('exponential_tally'), description: 'Tally looks like photonic')

configure_file(output: 'qs_config.h', configuration: conf_data)

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
