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
#include <entityx/entityx.h>
#include <physfs.h>
#include <chipmunk.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    sf::Texture texture;
    if (!texture.loadFromFile("scope.png"))
    {
        return EXIT_FAILURE;
    }

    sf::Sprite sprite(texture);

    sf::Font font;
    if (!font.loadFromFile("Roboto-Regular.ttf"))
    {
        return EXIT_FAILURE;
    }

    sf::Text text("Hello SFML", font, 50);

    // Load a music to play
    //sf::Music music;
    //if (!music.openFromFile("nice_music.ogg"))
    //    return EXIT_FAILURE;
    // Play the music
    //music.play();

    // Start the game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.display();
    }
    return EXIT_SUCCESS;
}
