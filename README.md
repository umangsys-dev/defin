# defin

**defin** is a system tool that detects and installs missing dependencies for C++ projects by analyzing `#include` directives.


## 📄 License

- **Core code** is under a custom non-redistributable license. See [LICENSE.txt](./LICENSE.txt)
- **JSON database** (`json-db/`) is licensed under the MIT License. See [json-db/LICENSE-json.txt](./json-db/LICENSE-json.txt)
- Includes [TinyProcessLibrary](https://gitlab.com/eidheim/tiny-process-library), under the MIT License. See [tiny-process-library/LICENSE-tinyprocess.txt](./tiny-process-library/LICENSE-tinyprocess.txt)


## Features

- Parses source code for missing headers
- Maps includes to system packages via JSON
- Installs packages using apt, pacman, and more
- CLI-first, scriptable


## 🐧 Compatibility

- Supported OS: **Linux** only  
- Tested on: Arch, Debian, Fedora (others may work)
- Requires: CMake 3.10+, a C++17-compatible compiler, and a working package manager (e.g. apt, pacman, dnf)


## Build and Install

```bash
git clone https://github.com/umangsys-dev/defin
cd defin
cmake -B build
cmake --build build
sudo cmake --install build