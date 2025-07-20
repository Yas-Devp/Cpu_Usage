<h1 align="center">
  🖥️ Cpu_Usage  
</h1>
**Cpu_Usage** is a simple, yet effective, graphical application that provides a real-time visualization of your CPU usage.  It's designed to be lightweight and easy to use, providing a quick overview of your system's CPU activity.

## Table of Contents

1.  [Features](#features)
2.  [Installation](#installation)
3.  [Usage](#usage)
4.  [Contributing](#contributing)
5.  [License](#license)
6.  [Support](#support)
7.  [Future Enhancements](#future-enhancements)
8.  [Credits](#credits)

## Features

*   **Real-Time CPU Usage:** Displays a live graph of CPU utilization.
*   **Lightweight & Efficient:**  Minimal impact on system resources.
*   **Simple Graphical Interface:** Easy-to-understand visual representation of CPU activity.
*   **Cross-Platform Compatibility:**  Designed to work on various systems with SDL2 support (Linux targeted currently).

## Installation

Before you begin, ensure you have the following prerequisites installed on your system:

*   **GCC or Clang:** A C compiler is required to build the application.
*   **SDL2:** The Simple DirectMedia Layer library is used for window creation, rendering, and event handling.  The SDL2_ttf extension provides font support.

### Prerequisites Installation

**Debian/Ubuntu-based systems (using apt):**

```bash
sudo apt update  # Recommended to update package lists first
sudo apt install gcc libsdl2-dev libsdl2-ttf-dev
```

**Fedora/Red Hat-based systems (using dnf):**

```bash
sudo dnf install gcc SDL2-devel SDL2_ttf-devel
```

**Other Distributions:**

Consult your distribution's package manager for the appropriate packages. The key packages are:

*   `gcc` or `clang` (C compiler)
*   `SDL2` (SDL2 core library)
*   `SDL2_ttf` (SDL2 TrueType Font library)

### Cloning the Repository

Clone the Cpu_Usage repository to your local machine:

```bash
git clone https://github.com/Yas-Devp/Cpu_Usage
cd Cpu_Usage
```

### Building the Application

Navigate to the cloned directory and compile the source code using the following command:

```bash
gcc cpu_info.c -o cpu_info $(sdl2-config --cflags --libs) -lSDL2_ttf
```

**Explanation:**

*   `gcc cpu_info.c`:  Compiles the `cpu_info.c` source file.
*   `-o cpu_info`: Specifies the name of the output executable file as `cpu_info`.
*   `$(sdl2-config --cflags --libs)`:  Uses the `sdl2-config` utility to automatically include the necessary compiler flags and linker libraries for SDL2.  This simplifies the compilation process and ensures compatibility.
*   `-lSDL2_ttf`: Links the SDL2_ttf library for font rendering support.

## Usage

After successful compilation, you can run the application with the following command:

```bash
./cpu_info
```

This will launch the CPU usage visualizer, displaying a graphical representation of your CPU activity.

## Contributing

Contributions are welcome! If you have any ideas for improvements, bug fixes, or new features, please feel free to submit a pull request.

1.  Fork the repository.
2.  Create a new branch for your feature or bug fix.
3.  Make your changes and commit them with descriptive messages.
4.  Submit a pull request to the main branch.

## License

This project is licensed under the [MIT License](LICENSE) - see the [LICENSE](LICENSE) file for details. (Replace `LICENSE` with the actual license file if you have one.)

## Support

If you encounter any issues or have questions, please open an issue on the GitHub repository.

## Future Enhancements

*   **Cross-Platform Support:** Expanding support to Windows and macOS.
*   **Customizable Graph:** Allowing users to customize the appearance of the CPU usage graph (colors, scaling, etc.).
*   **Detailed CPU Information:** Displaying more detailed CPU information, such as CPU temperature, clock speed, and individual core usage.
*   **Command-Line Arguments:** Adding command-line arguments for configuration options.
*   **Process Monitoring:** Show the processes that consume the most CPU.

## Credits

*   Developed by [Your Name/Yas-Devp](https://github.com/Yas-Devp).
*   Uses the [SDL2](https://www.libsdl.org/) library.
