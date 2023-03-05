# OpenGL C Template

This is my person configuration for develop OpenGL applications in C.

## Libs

- [cglm-0.8.9](https://github.com/recp/cglm) - Highly optimized 2D|3D math library, also known as OpenGL Mathematics (glm) for `C`
- [glad-5bf3eda](https://github.com/Dav1dde/glad/tree/c) - Vulkan/GL/GLES/EGL/GLX/WGL Loader-Generator based on the official specifications for multiple languages.
- [glew-cmake-2.2.0](https://github.com/Perlmint/glew-cmake/tree/f456deace7b408655109aaeff71421ef2d3858c6) - [GLEW](https://github.com/nigels-com/glew, source updated nightly) with Cmake and pre-generated sources
- [glfw-3.8.8](https://github.com/glfw/glfw) - GLFW is an Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan application development
- [lpg3dmath](https://github.com/lpg2709/lpg3dmath) - Is a header only C 3D mathematics library. My 3d lib.
- [stb-5736b15](https://github.com/nothings/stb) - stb single-file public domain libraries for C/C++.

To load OpenGL function you can chose GLAD or GLEW.

## How use

Clone the repository.

Go to CMakeLists.txt and change the `project()` name to the name of your project.

```sh
mkdir build
cmake ..
cmake --build .
```

## Why not use submodules

Because for this project I preferred to use everything in a single repository, without depending on a submodule. Just a personal choice.

## References

This template is based on [Glitter](https://github.com/Polytonic/Glitter) from [Polytonic](https://github.com/Polytonic).

## License

[MIT](LICENSE)
