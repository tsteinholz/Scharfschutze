# Scharfschütze

## Building
We use [cmake](https://www.cs.swarthmore.edu/~adanner/tips/cmake.php) as our build system.

### Required Libraries
This game uses SFML2 for handling with the low-level systems like graphical windows, system access, audio, graphical rendering and has the potential for networking. For overall project architecture we use EntityX to give us a good platform for an Component based Entity System within our game. We use Chipmunk2d for fast and accurate 2d physics within our Component based Entity System, for more about how this is architected check out the wiki. Finally we use PhysFS as a faster and more robust alternative to SFML2's file system library, this library also allows for loading compressed and uncompress data with ease.


* [SFML 2](https://github.com/SFML/SFML) || [Documentation](https://www.sfml-dev.org/documentation/2.4.2/)
* [Entity X](https://github.com/alecthomas/entityx) || [Documentation](https://github.com/alecthomas/entityx/blob/master/README.md)
* [Chipmunk 2D](https://chipmunk-physics.net) || [Documentation](https://chipmunk-physics.net/release/ChipmunkLatest-API-Reference/)
* [PhysFS](https://icculus.org/physfs/) || [Documentation](https://icculus.org/physfs/docs/html/)
