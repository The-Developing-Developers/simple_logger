import os
import subprocess
import sys

# ANSI colour codes
class Colour:
    RED = '\033[91m'
    GREEN = '\033[92m'
    CYAN = '\033[96m'
    YELLOW = '\033[93m'
    RESET = '\033[0m'


def is_gpp_available():
    """Check if g++ is available in the system's PATH."""
    result = subprocess.run(['g++', '--version'], capture_output=True, text=True)
    return result.returncode == 0

def main():
    # Warning message
    print(Colour.YELLOW + "\nWARNING" + Colour.RESET + ": You must have a valid GNU C++ compiler (g++) installed and in your system's " + Colour.CYAN + "PATH." + Colour.RESET)

    # Check if g++ is available
    try:
        is_gpp_available()  # Check if g++ is available
    except FileNotFoundError:
        print(Colour.RED + "ERROR" + Colour.RESET + ": GNU C++ compiler (g++) not found in the system's PATH.\n")
        # print in red colour
        sys.exit(1)

    # Ask the user if they want to continue
    proceed = input("Do you want to continue? (y/n): ").strip().lower()
    if proceed != 'y':
      print("Aborting compilation.\n")
      sys.exit(0)

    # Constants
    ROOT_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), '..')) # Assumes the script is in the `scripts` subdirectory
    SOURCE_DIR = os.path.join(ROOT_DIR, 'logger')
    TEST_DIR = os.path.join(ROOT_DIR, 'tests')
    OUTPUT_DIR = os.path.join(ROOT_DIR, 'build')
    OUTPUT_EXECUTABLE = 'logger_test'

    # Add .exe extension for Windows
    if os.name == 'nt':
        OUTPUT_EXECUTABLE += '.exe'

    OUTPUT_EXECUTABLE = os.path.join(OUTPUT_DIR, OUTPUT_EXECUTABLE)

    # Source files to compile
    SOURCE_FILES = [os.path.join(TEST_DIR, 'main.cpp'), os.path.join(SOURCE_DIR, 'logger.cpp')]

    # Ensure the output directory exists
    os.makedirs(OUTPUT_DIR, exist_ok=True)

    COMPILER = 'g++'

    # Compilation command
    compile_command = [COMPILER, '-o', OUTPUT_EXECUTABLE] + SOURCE_FILES + ['-I', TEST_DIR, '-I', SOURCE_DIR]

    # Print the compilation command for debugging purposes
    print(Colour.CYAN + 'Compiling with command:' + Colour.RESET, ' '.join(compile_command))

    # Run the compilation command
    result = subprocess.run(compile_command, capture_output=True, text=True)

    # Check if the compilation was successful
    if result.returncode == 0:
        print(Colour.GREEN + '\nCompilation successful.\n' + Colour.RESET)
    else:
        print(Colour.RED + '\nERROR' + Colour.RESET + ': compilation failed.')
        print('Error message:\n', result.stderr)
        sys.exit(result.returncode)

if __name__ == '__main__':
    main()