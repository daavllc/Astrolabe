import os
import subprocess
import platform

from SetupPython import PythonConfiguration as PythonRequirements

# Make sure everything we need for the setup is installed
PythonRequirements.Validate(['requests'])

from SetupPremake import PremakeConfiguration as PremakeRequirements

os.chdir('./../..')

premakeInstalled = PremakeRequirements.Validate()

print("\nUpdating submodules...")
subprocess.call(['git', 'submodule', 'update', '--init', '--recursive', '--remote'])

if premakeInstalled:
    if platform.system() == "Windows":
        print('\nRunning premake...')
        subprocess.call([os.path.abspath("./scripts/src/Windows-GenProjects.bat"), "nopause"])

        print("\nSetup completed <premake>!")
    else:
        print("ERR: Currently only Windows is supported")
else:
    print("ERR: Astrolabe requires Premake to generate project files.")

print("\nSetup completed <done>!")