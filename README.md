# stb_image_example

This repo serves as personal point of reference for:

1. Working with images in C, specifically with `stb_image.h`. Using `libpng` was really overkill, especially comparing how much code was necessary, even with the Simplified API released in 1.6x.
    * In addition is a `get_pixel()` function I found [here](https://redd.it/8gyyb6) that illuminates how the data returned by `stbi_load_image()` is structured.
2. Working with single-header libraries in CMake projects. Getting all of the options right was quite tricky. The `CMakeLists.txt`, though probably scuffed, is worth saving on its own.
    * Worth noting as well is the necessity to create a corresponding `stb_image.c` file in order to [appease different toolchains in a portable way](https://stackoverflow.com/q/52927351/5655711).
