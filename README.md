# About

**defin** is a system tool that detects and installs missing dependencies for C++ projects by analyzing `#include` directives.


## License

- **Core code** is under a custom non-redistributable license. See [LICENSE.txt](./LICENSE.txt)
- **JSON database** (`json-db/`) is licensed under the MIT License. See [json-db/LICENSE-json.txt](./json-db/LICENSE-json.txt)
- Includes [TinyProcessLibrary](https://gitlab.com/eidheim/tiny-process-library), under the MIT License. See [tiny-process-library/LICENSE-tinyprocess.txt](./tiny-process-library/LICENSE-tinyprocess.txt)


## Features

- Parses source code for missing headers
- Maps includes to system packages via JSON
- Installs packages using apt, pacman, and more
- CLI-first, scriptable


## Compatibility

- Supported OS: **Linux** only  
- Tested on: Arch, Debian, Fedora (others may work)
- Requires: CMake 3.10+, a C++17-compatible compiler, and a working package manager (e.g. apt, pacman, dnf)


## Build and Install

```bash
git clone https://github.com/umangsys-dev/defin
cd defin
mkdir build
cmake -S . -B build/
cmake --build build
sudo cmake --install build
```

## Usage

### Commands

#### `sudo defin fix /path/to/project/`

- Recursively scans all `.cpp`, `.hpp`, `.c`, and `.h` files in the given directory
- Detects used `#include` headers
- Maps them to logical libraries and installable packages
- Installs missing packages automatically using your system's package manager

> This is the main command for resolving and fixing missing dependencies.

---

#### `sudo defin enlist -m /path/to/project/`

- Lists **missing** packages (headers used in the source but packages not installed)
- Does not perform any installation
- Ideal for dry runs or CI integration

---

#### `sudo defin enlist -p /path/to/project/`

- Lists **present** packages (headers used and already available on your system)
- Useful for auditing project dependencies

---

### Make Sure

The directory you pass contains C++ source code:
- Any combination of `.cpp`, `.hpp`, `.c`, or `.h` files
- No need for a compiled binary

  (depin directly parses your source code to extract `#include` directives.)

- Use `sudo` since actual package installation requires root
- Supported package managers: `apt`, `pacman`, and `dnf`

---

### Want to contribute header mappings?

- Check out [json-db/Contributing.md](./json-db/Contributing.md).