# JSON Mapping Database

This directory contains the community-driven JSON database used by **defin** to resolve missing C++ dependencies into actual system packages.

These files power the detection and installation logic by mapping headers, libraries, and packages across different Linux package managers.

---

## 📦 JSON Files

| File                         | Description |
|-----------------------------|-------------|
| `header-to-llib.json`       | Maps C++ header files (`.h`, `.hpp`) to logical libraries (e.g. `"SDL.h" → "sdl2"`). |
| `llib-to-pkg_apt.json`      | Maps logical libraries to APT (Debian/Ubuntu) package names (e.g. `"sdl2" → "libsdl2-dev"`). |
| `llib-to-pkg_pacman.json`   | Maps logical libraries to Pacman (Arch/Manjaro) package names. |
| `llib-to-pkg_dnf.json`      | Maps logical libraries to DNF (Fedora) package names. |
| `pm-to-cmd.json`            | Maps package manager names (`apt`, `pacman`, `dnf`) to install commands (e.g. `"apt" → "sudo apt install -y"`). |

---

## 🧑‍🤝‍🧑 Contribution Guidelines

We welcome contributions to any of these files!

### ✅ General Rules:
- Keep JSON valid and sorted alphabetically if possible.
- Avoid duplicating entries unless truly needed.
- Use lowercase logical library names consistently (`sdl2`, `sfml`, etc.).

### 💡 About Logical Libraries (`llib`)
- These are distro-agnostic names we use as a bridge between headers and package names.
- Examples: `"sdl2"`, `"sfml_window"`, `"boost_filesystem"`

### 🧪 Test Locally
If you add mappings, test `defin` against a small project using the relevant includes to ensure resolution works.

---

## 📄 License

These mapping files are licensed under the MIT License.  
See [LICENSE-json.txt](./LICENSE-json.txt).