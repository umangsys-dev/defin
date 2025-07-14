# JSON Mapping Database

This directory contains the community-driven JSON database used by **defin** to resolve missing C++ dependencies into actual system packages.

These files power the detection and installation logic by mapping headers, libraries, and packages across different Linux package managers.

---

## 📦 JSON Files

| File                         | Description |
|-----------------------------|-------------|
| `header-llibs.json`     | Maps headers to logical library groups       |
| `llibs-pkg_apt.json`    | Maps groups to APT packages (Debian/Ubuntu)  |
| `llibs-pkg_dnf.json`    | Maps groups to DNF packages (Fedora/RHEL)    |
| `llibs-pkg_pacman.json` | Maps groups to Pacman packages (Arch Linux)  |
| `pm-to-cmd.json`            | Maps package manager names (`apt`, `pacman`, `dnf`) to install commands (e.g. `"apt" → "sudo apt install -y"`). |

---

## 🧑‍🤝‍🧑 Contribution Guidelines

We welcome contributions to any of these files!

Steps to contribute new header-to-library mappings for **`defin`** are as follows:

---

## ✅ Step 1: Add Headers to `header-llibs.json`

Map one or more headers to a logical group name:

```json
{
  "curl/curl.h": "_curl",
  "zip.h": "_zip",
  "Eigen/Dense": "_eigen"
}
```

✅ Follow:
- Use double quotes
- No trailing commas
- Group similar headers under the same logical key (e.g. all `boost/...` → `_boost`)
- Try to keep entries alphabetically sorted if possible

---

## ✅ Step 2: Add Package Mapping to All Distros

Each group in `header-llibs.json` must also be added to:

- `llibs-pkg_apt.json`
- `llibs-pkg_dnf.json`
- `llibs-pkg_pacman.json`

### Example:

#### `llibs-pkg_apt.json`
```json
{
  "_curl": "libcurl4-openssl-dev",
  "_zip": "libzip-dev",
  "_eigen": "libeigen3-dev"
}
```

#### `llibs-pkg_dnf.json`
```json
{
  "_curl": "libcurl-devel",
  "_zip": "libzip-devel",
  "_eigen": "eigen3-devel"
}
```

#### `llibs-pkg_pacman.json`
```json
{
  "_curl": "curl",
  "_zip": "libzip",
  "_eigen": "eigen"
}
```

---

## 🔤 Naming Conventions

| Header Family        | Logical Group |
|----------------------|----------------|
| Standard C++         | `_cpp_std`     |
| Boost                | `_boost`       |
| SDL2 & extensions    | `_sdl2`        |
| SFML                 | `_sfml`        |
| fmt                  | `_fmt`         |
| nlohmann/json        | `_json`        |
| yaml-cpp             | `_yaml`        |
| cereal               | `_cereal`      |
| Dear ImGui           | `_imgui`       |
| Qt5 / Qt6            | `_qt`          |
| raylib               | `_raylib`      |
| OpenGL stack         | `_opengl`      |
| curl                 | `_curl`        |
| zip                  | `_zip`         |
| archive              | `_archive`     |
| Eigen                | `_eigen`       |
| OpenCV               | `_opencv`      |

- Logical group names **start with `_`**
- Use lowercase + underscores only
- Keep them short, meaningful, and consistent

---

## 🧪 Optional: Test Your Mappings

To test your changes locally:

```bash
sudo defin fix /path/to/your/project
```

Ensure the headers you added now resolve to the correct installable packages.

---

## 🧠 Keep in mind

- If you're unsure which package provides a header:
  - On Debian/Ubuntu: `dpkg -S <header>`
  - On Fedora: `dnf provides */<header>`
  - On Arch: `pacman -F <header>`
- If a library is header-only (like `cereal`), use its group anyway, and point to the package if it exists — otherwise just leave a placeholder or note.

---


## 📄 License

These mapping files are licensed under the MIT License.  
See [LICENSE-json.txt](./LICENSE-json.txt).