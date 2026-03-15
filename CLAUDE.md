# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build

```sh
mkdir build && cd build
cmake ..
cmake --build .
```

For IDE/clangd integration:
```sh
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S . -B build
```

## Run

```sh
./iOS-icon-extractor [options] <screenshot.png>
  -o <output_dir>   # Output directory (default: current directory)
  -n <num_icons>    # Icons on home screen (default: 24)
  -d <num_dock>     # Icons in dock (default: 4)
```

## Lint

clang-tidy is configured via `.clang-tidy` (Google style). VS Code runs it automatically via `settings.json`.

## Commands

- `/extract-icons` — interactive guide that walks the user through the full icon extraction workflow (disable parallax, screenshot, transfer, extract per page, extract dock).

## Architecture

**C++23 CLI tool** that extracts iOS home screen icons from iPhone screenshots using OpenCV.

**Data flow:**
```
Screenshot PNG → Config (parse args) → cv::imread()
    → IconIO::ReadIcon() (squircle crop per icon)
    → cv::imwrite() → icon_N.png / dock_N.png
```

### Key modules

- **`include/iOS-icon-extractor/IconCenters.hpp`** — Hardcoded pixel coordinates for icon centers. Currently calibrated for iPhone 16 Pro (2622×1206). Two arrays: `kIphone16Pro` (24 home screen icons, 6 rows × 4 columns) and `kIphone16ProDock` (dock icons, varies by dock count). This is where device-specific calibration lives.

- **`src/IconIO.cpp`** — Core extraction logic. Each icon is read at 192×192px (radius 96). Pixels are masked to the iOS squircle shape using the quartic formula `|x/r|⁴ + |y/r|⁴ ≤ 0.97` (cutting 3% from edge to avoid translucent border artifacts). All methods are static.

- **`src/config.cpp`** — CLI argument parsing and output directory creation.

- **`src/extract.cpp`** — Entry point: wires Config → cv::imread → IconIO.

### Coding conventions (enforced by clang-tidy)

- Classes/structs: `CamelCase`
- Namespaces/variables: `lower_case`
- Constants: `kPrefixed` (e.g., `kSquircleRadius`)
- Member variables: trailing underscore (e.g., `input_path_`)
