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

## Extracting icons

The Extract tool can be found in the directory build/Extract/src/. It takes a screenshot (PNG) file as input and extracts the icons from the home screen and the dock, and stores it in the destination folder.

```sh
# from the build directry
cd Extract/src

./Extract -n 16     # number of icons on the home screen page (default 24)
          -d 4      # number of icons in dock (default 4)
          -o page1/ # path to output folder (default current directory)
          path/to/screenshot.png
```

Expected icon locations are defined in Extract/src/IconCenters.h. Currently, only iPhones with screen size 2532 x 1170 (e.g. iPhone 13 etc.) are supported.
