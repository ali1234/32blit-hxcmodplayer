# HxCModPlayer example for 32blit

![Build](https://github.com/ali1234/32blit-hxcmodplayer/workflows/Build/badge.svg)

A simple example of using [HxCModPlayer](https://github.com/jfdelnero/HxCModPlayer) to
play Protracker modules.

## Notes

There isn't much to this. hxcmod.c/hxcmod.h are used unmodified from the upstream repo. 
A definition is added in the CMake to set mono output. And the mod file is compiled as
a raw binary asset.

The demo song is [11th Hour by TDK](https://modarchive.org/module.php?67104).