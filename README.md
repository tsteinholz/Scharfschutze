# [:hearts:]]] [:clubs:]]] Scharfschütze [:spades:]]] [:diamonds:]]]
```
                                                      (                               ----o-   
                                                     )               _____________   %%% , ,%__________
                                                    '               (___________,,)  %c    >) ,________)
                                                      . )              (_________,,)  )   =  ,______)
                                                    )                      (_____,,)/ _/__,,____)
     _  __)\____________________________________/7_  (                         / \   \__/ /\
    (//   )))))                                   `\||   ◉       ◉            /\ |        \/\
     /   (((((                                      )`                       /__\|'   ,   /  \,
    (______________________________________________/                        < -  '====o==,  /_\
     \   ________ ______________________________//                         /    /`       |\ __ \
      ) /#######/ )\  /     )//                                           /__,_/    |  _/, \____\
     / /##(\)##/ /  \(     //                                                //   |     \/  \    \\
    / /#######( (\______.ad`                                               _( \   \      \  \   _/ \
   / /#########) )------``                                                   //|    \     \  \    |/|
  / /#########/ /                                                                    < `  _\ -)
 / /###(/)###/ //                                                                      |_/ |
( (#########/ (                                                                     |    / |_/
 \____/_______\)                                                                  /-_,  ' /|
                                                                                     \/ \_,--.,
                                                                                   '(    )'
                         aten sagen mehr als Worte.                               / |    | \
                                                                                  |,/    \,/
```
![Game Rendering](https://raw.githubusercontent.com/tsteinholz/Scharfschutze/master/res/screenshots/render.png)

## Building
We use [cmake](https://www.cs.swarthmore.edu/~adanner/tips/cmake.php) (3.2+) as our build system.

### Required Libraries
This game uses SFML2 for handling with the low-level systems like graphical windows, system access, audio, graphical rendering and has the potential for networking. For overall project architecture we use EntityX to give us a good platform for an Component based Entity System within our game. We use Chipmunk2d for fast and accurate 2d physics within our Component based Entity System, for more about how this is architected check out the wiki. Finally we use PhysFS as a faster and more robust alternative to SFML2's file system library, this library also allows for loading compressed and uncompress data with ease.


* [SFML 2](https://github.com/SFML/SFML) :arrow_right: [Documentation](https://www.sfml-dev.org/documentation/2.4.2/)
* [Entity X](https://github.com/alecthomas/entityx) :arrow_right: [Documentation](https://github.com/alecthomas/entityx/blob/master/README.md)
* [Chipmunk 2D](https://chipmunk-physics.net) :arrow_right: [Documentation](https://chipmunk-physics.net/release/ChipmunkLatest-API-Reference/)
* [PhysFS](https://icculus.org/physfs/) :arrow_right: [Documentation](https://icculus.org/physfs/docs/html/)
* [PThreads](https://computing.llnl.gov/tutorials/pthreads/) :arrow_right: [Documentation](https://computing.llnl.gov/tutorials/pthreads/)
* [JSONcpp](https://github.com/open-source-parsers/jsoncpp) :arrow_right: [Documentation](http://open-source-parsers.github.io/jsoncpp-docs/doxygen/index.html)
