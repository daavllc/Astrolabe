import subprocess
import pkg_resources

def install(package):
    print(f"Installing {package} module...")
    subprocess.check_call(['python', '-m', 'pip', 'install', package])

def ValidatePackage(package):
    required = { package }
    installed = {pkg.key for pkg in pkg_resources.working_set}
    missing = required - installed

    if missing:
        install(package)

def ValidatePackages(packages: list):
    for package in packages:
        ValidatePackage(package)
    ValidatePackage('requests')
    ValidatePackage('fake-useragent')
