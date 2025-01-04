# WindowsKeys
/*****************************************************************/ /**

    author:  João Rocha
    date:    4 January 2025
    version: 0.0.1

 *********************************************************************/

## Project Description

WindowsKeys is a utility program designed to provide users with the ability to remap the Windows key on their keyboard to another key. This can be particularly useful in several scenarios:

1. **Keyboards Without a Windows Key**: Some keyboards, especially those designed for specific purposes or regions, may lack a dedicated Windows key. This program allows users to assign the Windows key functionality to another key on their keyboard, ensuring they can still access Windows-specific shortcuts and features.

2. **Custom Key Mapping**: Users who prefer a different keyboard layout or have specific ergonomic needs might want to remap the Windows key to a more convenient location. This program provides the flexibility to customize key mappings according to individual preferences.

3. **Accessibility**: For users with disabilities or those who find it difficult to reach the Windows key, remapping it to a more accessible key can improve their overall computing experience.

## Features

- **Simple Interface**: The program offers an easy-to-use interface for selecting and remapping keys.
- **Customizable Mappings**: Users can choose any key on their keyboard to act as the Windows key.
- **Persistent Settings**: Once configured, the key mappings persist across system reboots.
- **Lightweight**: The program is designed to be lightweight and efficient, ensuring minimal impact on system performance.

## Usage

1. **Launch the Program**: Open the WindowsKeys application.
2. **Select Key to Remap**: Choose the key you want to remap to the Windows key.
3. **Apply Changes**: Save the configuration and apply the changes.
4. **Enjoy**: Use your newly remapped key as the Windows key.

## Installation

Prerequisites
Ensure you have the following installed on your system:
•	CMake
•	A C++ compiler (e.g., GCC, Clang, MSVC)

Steps to Compile
    
    1. Clone the repository:

        git clone <https://github.com/JoaoRoch4/WindowsKeys>
        cd WindowsKeys

    2. Create a build directory:
        mkdir build
        cd build

    3. Generate build files using CMake:
        cmake ..

    4. Compile the project:
        cmake --build .

    5. Run the executable:
        WindowsKeys.exe
        
  ## Example Commands
  Here is a summary of the commands you will run:

    git clone <https://github.com/JoaoRoch4/WindowsKeys>
    cd WindowsKeys
    mkdir build
    cd build
    cmake ..
    cmake --build .
    WindowsKeys.exe


## Contributing

Contributions are welcome! If you have suggestions for improvements or have found a bug, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](#) file for details.