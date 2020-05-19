# discord-bot

Discord bot made in C++ using [sleepy-discord](https://github.com/yourWaifu/sleepy-discord).

## Setup

Clone this repo, and follow [this](https://yourwaifu.dev/sleepy-discord/setup.html).

## Build

You can just open it as a normal project in CLion or compile it from CLI like every other CMake project.

## How it works

This bot uses modules to run commands (dynamic libraries loading).  
Create your custom module using the header in `modules/include` and compile it as a shared library (example in `modules/moduleHello`).  
Use the command `{prefix}load {modulename}` to load a module and `{prefix}unload {modulename}` to unload it.  
To execute your module use the command `{prefix}{modulename}`.  
For example, my `moduleHello`'s name is `hello` (in `CMakeLists.txt` -> `add_library`'s first argument is the module's name), so I can load it with `?load hello` (assuming `?` is the prefix) and run it with `?hello`.