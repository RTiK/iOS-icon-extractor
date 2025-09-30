# iOS Icon Extractor

This tool extracts iOS home screen icons from a screenshot.

## Prerequisites

There are a few things we need to do before taking a screenshot.

### Disable Parallax

Maybe you haven't noticed it, but the icons on your home screen move depending on the tilt of your device. Apple calls it the Parallax effect. The Extractor tool, however, needs to have the icons in their expected spot. Therefore, we need to disable this effect before we take the screenshot. To do that enable the Reduce Motion option found under

`> Settings > Accessibility > Motion > Reduce Motion`

### Clear all notifications bubbles

Another thing you need to make sure is that no icon has a red notification bubble because, of course, it will persist on the extracted icon.

## Make the screenshot

When you have finished all steps above, you can take the screenshots of all your home screens and transfer them to your computer.

## Building the tool

Clone this repository to your computer and navigate to the root of the cloned repository.

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

## Extracting icons

The tool takes a screenshot (PNG) file as input and extracts the icons from the home screen and the dock, and stores it in the destination folder.

```sh
# from the build directry
./ios-icon-extractor -n 16     # number of icons on the home screen page (default 24)
                     -d 4      # number of icons in dock (default 4)
                     -o page1/ # path to output folder (default current directory)
                     path/to/screenshot.png
```

Expected icon locations are defined in `/src/IconCenters.h`. They are currently set for iPhone 16 Pro with iOS 26.

## Nice to have code snippets

- Use CMake to generate _clangd_ compile commands into the `build` folder: `cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S . -B build`
