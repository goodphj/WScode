import os
import sys
import subprocess
import json

# Configuration
REQUIRED_DIRS = ["generated", "custom", "source", "board", "sdk"]
VSCODE_DIR = ".vscode"
CPP_PROPS_FILE = "c_cpp_properties.json"

def print_status(msg, status):
    symbol = "✅" if status else "❌"
    print(f"{symbol} {msg}")

def check_structure():
    print("\n[1] Checking Directory Structure...")
    cwd = os.getcwd()
    print(f"Current Root: {cwd}")
    
    missing = []
    for d in REQUIRED_DIRS:
        if not os.path.exists(os.path.join(cwd, d)):
            missing.append(d)
    
    if missing:
        print_status(f"Missing directories: {', '.join(missing)}", False)
        
        # Check parent directory for hints
        parent_dir = os.path.dirname(cwd)
        if all(os.path.exists(os.path.join(parent_dir, d)) for d in missing):
            print(f"   -> 💡 Hint: Found these directories in '{parent_dir}'.")
            print("      You might be running this script inside a subfolder.")
            
        print("   -> Warning: Proceeding with incomplete structure.")
        return False
    
    print_status("All required directories found.", True)
    return True

def check_compiler():
    print("\n[2] Checking Toolchain (arm-none-eabi-gcc)...")
    try:
        # Check if compiler is in PATH
        result = subprocess.run(["arm-none-eabi-gcc", "--version"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if result.returncode == 0:
            version_line = result.stdout.splitlines()[0]
            print_status(f"Found: {version_line}", True)
            return True
        else:
            print_status("Compiler command failed to run.", False)
            return False
    except FileNotFoundError:
        print_status("arm-none-eabi-gcc not found in PATH.", False)
        return False

def update_vscode_config():
    print("\n[3] Updating VS Code Configuration...")
    if not os.path.exists(VSCODE_DIR):
        os.makedirs(VSCODE_DIR)
        print(f"   Created {VSCODE_DIR} directory.")

    config_path = os.path.join(VSCODE_DIR, CPP_PROPS_FILE)
    
    # Define include paths dynamically based on current location
    include_paths = [
        "${workspaceFolder}/**",
        "${workspaceFolder}/generated",
        "${workspaceFolder}/custom",
        "${workspaceFolder}/source",
        "${workspaceFolder}/board",
        "${workspaceFolder}/sdk"
    ]

    config_data = {
        "configurations": [
            {
                "name": "NXP i.MX RT700",
                "includePath": include_paths,
                "defines": [
                    "CPU_MIMXRT798SGFOA",
                    "CPU_MIMXRT798SGFOA_cm33",
                    "CPU_MIMXRT798SGFOA_cm33_core0",
                    "MCUXPRESSO_SDK",
                    "SDK_DEBUGCONSOLE=1",
                    "MCUX_META_BUILD",
                    "MIMXRT798S_cm33_core0_SERIES",
                    "BOOT_HEADER_ENABLE=1",
                    "LV_CONF_INCLUDE_SIMPLE=1",
                    "SDK_OS_FREE_RTOS",
                    "__MCUXPRESSO",
                    "__USE_CMSIS",
                    "DEBUG",
                    "__NEWLIB__"
                ],
                "forcedInclude": [
                    "${workspaceFolder}/source/mcux_config.h"
                ],
                "compilerPath": "arm-none-eabi-gcc",
                "cStandard": "c99",
                "cppStandard": "c++11",
                "intelliSenseMode": "gcc-arm"
            }
        ],
        "version": 4
    }

    try:
        with open(config_path, 'w') as f:
            json.dump(config_data, f, indent=4)
        print_status(f"Updated {CPP_PROPS_FILE} with correct paths.", True)
    except Exception as e:
        print_status(f"Failed to write config: {e}", False)

def check_build_artifacts():
    print("\n[4] Checking Stale Build Artifacts...")
    build_dirs = ["build", "cmake-build-debug", "Debug", "Release"]
    found_dirs = [d for d in build_dirs if os.path.exists(d)]
    
    if found_dirs:
        print("⚠️  Warning: Build directories found containing potential absolute paths.")
        print(f"   Directories: {', '.join(found_dirs)}")
        print("   -> Recommendation: Delete these folders to force a clean rebuild.")
    else:
        print_status("No stale build directories found.", True)

def main():
    print("=== NXP i.MX RT700 Project Environment Doctor ===")
    
    check_structure()
        
    check_compiler()
    update_vscode_config()
    check_build_artifacts()
    
    print("\n=== Environment Check Complete ===")

if __name__ == "__main__":
    main()