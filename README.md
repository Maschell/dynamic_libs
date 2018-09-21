# Dynamic libs for WiiU homebrew.
[![Build Status](https://travis-ci.org/Maschell/dynamic_libs.svg?branch=lib)](https://travis-ci.org/Maschell/dynamic_libs)

## Compiling

Install this static library into your portlibs folder via: 

```
make && make install
```

Link the application with:
```
-ldynamiclibs
```

You also need to add the include path to your Makefile. Example:

```
export INCLUDE	:= [...] -I$(PORTLIBS)/include
```

## Usage

To be able to use this library, you need to include the header initialize the OS functions.

```
InitOSFunctionPointers();
```

After that, you can initialize any lib and use their functions. Example: 

```
InitVPadFunctionPointers();
InitProcUIFunctionPointers();
```

Check out the header for more information.

# Dependencies

All needed dependencies are in the "libs" folder of this repository. Extract the "portlibs.zip" archive into your devkitPro directory.  
The archive includes:

- The "curl" header

# Use the prebuilt files from a Docker image.
The image `wiiulegacy/dynamic_libs` on [Docker Hub](https://hub.docker.com/r/wiiulegacy/dynamic_libs/) provides a prebuilt library in the `/artifacts` directory. Copy it into your DevkitPPC portlibs folder.  

Example:  
```
COPY --from=wiiulegacy/dynamic_libs:0.1 /artifacts $DEVKITPRO/portlibs
```

# Credits

- Based on the dynamic_libs from dimok.
- Various other
