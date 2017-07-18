//----------------------------------------------------------------------------//
//                   ______________________________________                   //
//         ________|                                      |_______            //
//         \       |       This file is a part of         |      /            //
//          \      |           Scharfschütze              |     /             //
//          /      |______________________________________|     \             //
//         /__________)                                (_________\            //
//                                                                            //
//                     Copyright(C) 2017 Thomas Steinholz                     //
//                                                                            //
//     Permission is hereby granted, free of charge, to any person            //
//     obtaining a copy of this software and associated documentation         //
//     files (the "Software"), to deal in the Software without                //
//     restriction, including without limitation the rights to use, copy,     //
//     modify, merge, publish, distribute, sublicense, and/or sell            //
//     copies of the Software, and to permit persons to whom the              //
//     Software is furnished to do so, subject to the following conditions:   //
//                                                                            //
//     The above copyright notice and this permission notice shall be         //
//     included in all copies or substantial portions of the Software.        //
//                                                                            //
//     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        //
//     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES        //
//     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND               //
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT            //
//     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,           //
//     WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING           //
//     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR          //
//     OTHER DEALINGS IN THE SOFTWARE.                                        //
//----------------------------------------------------------------------------//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <physfs.h>
#include <chipmunk.h>
#include <json/value.h>
#include "third-party/slog.h"
#include "level.h"

#define SCHARFSCHUTZE_VERSION_MAJOR 0
#define SCHARFSCHUTZE_VERSION_MINOR 0
#define SCHARFSCHUTZE_VERSION_PATCH 1

const int focal_point_speed = 5;
const int layer_difference = 1;

void print_versions()
{
    // EntityX does not expose versions.
    slog(1, SLOG_INFO, "=====================================================");
    slog(1, SLOG_INFO, "Scharfschütze v%i.%i.%i!",
        SCHARFSCHUTZE_VERSION_MAJOR,
        SCHARFSCHUTZE_VERSION_MINOR,
        SCHARFSCHUTZE_VERSION_PATCH);
    slog(1, SLOG_INFO, "SFML v%i.%i.%i!",
        SFML_VERSION_MAJOR,
        SFML_VERSION_MINOR,
        SFML_VERSION_PATCH);
    slog(1, SLOG_INFO, "Chipmunk v%i.%i.%i!",
        CP_VERSION_MAJOR,
        CP_VERSION_MINOR,
        CP_VERSION_RELEASE);
    slog(1, SLOG_INFO, "PhysFS v%i.%i.%i!",
        PHYSFS_VER_MAJOR,
        PHYSFS_VER_MINOR,
        PHYSFS_VER_PATCH);
    slog(1, SLOG_INFO, "JSONcpp v%i.%i.%i!",
        JSONCPP_VERSION_MAJOR,
        JSONCPP_VERSION_MINOR,
        JSONCPP_VERSION_PATCH);
    slog(1, SLOG_INFO, "=====================================================");
}

int main()
{
    slog_init("Scharfschütze.log", "Scharfschütze-Log.cfg", 2 ,3, 1);
    print_versions();

    sf::RenderWindow window(sf::VideoMode(1040, 800), "SFML window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.display();
    }
    return EXIT_SUCCESS;
}
