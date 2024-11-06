import os
import subprocess
import sys

def main():
    # Warning message
    print("Warning: You must have a valid GNU C++ compiler (g++) installed and in your PATH.")

    # Ask the user if they want to continue
    proceed = input("Do you want to continue? (y/n): ").strip().lower()
    if proceed != 'y':
      print("Aborting compilation.")
      sys.exit(0)

    # Constants
    SOURCE_DIR = 'logger'
    TEST_DIR = 'tests'
    OUTPUT_DIR = 'build'
    OUTPUT_EXECUTABLE = 'logger_test'

    # Add .exe extension for Windows
    if os.name == 'nt':
        OUTPUT_EXECUTABLE += '.exe'

    OUTPUT_EXECUTABLE = os.path.join(OUTPUT_DIR, OUTPUT_EXECUTABLE)

    # Source files to compile
    source_files = [os.path.join(TEST_DIR, 'main.cpp'), os.path.join(SOURCE_DIR, 'logger.cpp')]

    # Ensure the output directory exists
    os.makedirs(OUTPUT_DIR, exist_ok=True)

    # Compilation command
    compile_command = [compiler, '-o', OUTPUT_EXECUTABLE] + source_files + ['-I', TEST_DIR, '-I', SOURCE_DIR]

    # Print the compilation command for debugging purposes
    print('Compiling with command:', ' '.join(compile_command))

    # Run the compilation command
    result = subprocess.run(compile_command, capture_output=True, text=True)

    # Check if the compilation was successful
    if result.returncode == 0:
        print('Compilation successful.')
    else:
        print('Compilation failed.')
        print('Error message:', result.stderr)
        sys.exit(result.returncode)

if __name__ == '__main__':
    main()