# Dynamic libs for WiiU homebrew.
[![Build Status](https://travis-ci.org/Maschell/dynamic_libs.svg?branch=master)](https://travis-ci.org/Maschell/dynamic_libs)

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

# Credits

- Based on the dynamic_libs from dimok.
- Various other
