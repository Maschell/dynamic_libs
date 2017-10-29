# Dynamic libs for WiiU homebrew.

## Compiling

Install this static library into your portlibs folder via: 

```
make && make install
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

# Credits

- Based on the dynamic_libs from dimok.
- Various other