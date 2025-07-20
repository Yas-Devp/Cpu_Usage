<h1 align="center">
  🖥️ Cpu_Usage  
</h1>
<p align="center">
  A minimal and lightweight graphical tool to monitor CPU usage using SDL2.  
  Clean interface, simple setup, and zero bloat.
</p>

---

📑 Table of Contents

- [Features](#-features)
- [Screenshots](#-screenshots)
- [Installation](#-installation)
- [Usage](#-usage)
- [Dependencies](#-dependencies)
- [Contributing](#-contributing)
- [License](#-license)

---

✨ Features

- Real-time CPU usage display
- Graphical UI with SDL2
- Lightweight and fast
- Simple compilation and usage
- Extensible for future system metrics

---

🖼️ Screenshots

*(Add a screenshot of the running app here if possible)*

---

⚙️ Installation

Make sure you have GCC or Clang, and SDL2 with TTF support installed.

Install GCC / Clang:
```bash
sudo apt install gcc         # or
sudo apt install clang
```

Install SDL2 & SDL2_ttf:
```bash
sudo apt install libsdl2-dev libsdl2-ttf-dev
```

Clone the Repository:
```bash
git clone https://github.com/Yas-Devp/Cpu_Usage
cd Cpu_Usage
```

---

🚀 Usage

To compile the project:

```bash
gcc cpu_info.c -o cpu_info $(sdl2-config --cflags --libs) -lSDL2_ttf
```
Then run:

```bash
./cpu_info
```

---

📦 Dependencies

- [SDL2](https://libsdl.org/)
- [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)
- GCC or Clang

---

🤝 Contributing

Feel free to fork, open issues or suggest improvements. Contributions are always welcome!

---

📄 License

This project is licensed under the MIT License.

---
