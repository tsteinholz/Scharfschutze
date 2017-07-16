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
#include "slog.h"

#define SCHARFSCHUTZE_VERSION_MAJOR 0
#define SCHARFSCHUTZE_VERSION_MINOR 0
#define SCHARFSCHUTZE_VERSION_PATCH 1

const int focal_point_speed = 5;
const int layer_difference = 1;

struct PositionComponent {
    explicit PositionComponent(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
    float x, y;
};

struct DirectionComponent {
    DirectionComponent(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
    float x, y;
};

struct ParallaxComponent {
    ParallaxComponent(int layer = 0, int hspeed = 0) : layer(layer), hspeed(hspeed) {}
    int layer;
    int hspeed;
};

struct DrawableComponent {
    DrawableComponent(sf::Sprite sprite) : window(window), sprite(sprite) {}
    sf::Sprite sprite;
    sf::RenderWindow *window;
};

struct MovementSystem : public entityx::System<MovementSystem> {
  void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override {
    es.each<PositionComponent, DirectionComponent>
        ([dt](entityx::Entity entity, PositionComponent &position, DirectionComponent &direction) {
            position.x += direction.x * dt;
            position.y += direction.y * dt;
    });
  };
};

struct RenderSystem : public entityx::System<RenderSystem> {
    RenderSystem(sf::RenderTarget *renderTarget) : renderTarget(renderTarget) {}

    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override {
        es.each<DrawableComponent>([dt](entityx::Entity entity, DrawableComponent &drawable) {
            RenderTarget->draw(drawable.sprite);
        });
    };

private:
    sf::RenderTarget *renderTarget;
};

int main()
{
    slog_init("Scharfschütze.log", "Scharfschütze-Log.cfg", 2 ,3, 1);
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
    // EntityX does not expose versions.
    //slog(0, SLOG_INFO, "EntityX Version: %i, %i, %i!");
    slog(1, SLOG_INFO, "PhysFS v%i.%i.%i!",
        PHYSFS_VER_MAJOR,
        PHYSFS_VER_MINOR,
        PHYSFS_VER_PATCH);
    slog(1, SLOG_INFO, "=====================================================");

    sf::RenderWindow window(sf::VideoMode(1040, 800), "SFML window");

    entityx::EntityX ex;

    entityx::Entity parallax_background_layer1 = ex.entities.create();
    parallax_background_layer1.assign<PositionComponent>(1.0f, 2.0f);
    parallax_background_layer1.assign<DirectionComponent>();
    parallax_background_layer1.assign<ParallaxComponent>(1, (focal_point_speed - (2 * layer_difference)));
    sf::Texture layer1_texture;
    layer1_texture.loadFromFile("res/img/background/layer-1.jpg");
    sf::Sprite layer1_sprite(layer1_texture);
    parallax_background_layer1.assign<DrawableComponent>(layer1_sprite);

    entityx::Entity parallax_background_layer2 = ex.entities.create();
    parallax_background_layer2.assign<PositionComponent>(1.0f, 2.0f);
    parallax_background_layer2.assign<DirectionComponent>();
    parallax_background_layer2.assign<ParallaxComponent>(1, focal_point_speed - layer_difference);
    sf::Texture layer2_texture;
    layer2_texture.loadFromFile("res/img/background/layer-2.png");
    sf::Sprite layer2_sprite(layer2_texture);
    parallax_background_layer2.assign<DrawableComponent>(layer2_sprite);

    entityx::Entity parallax_background_layer3 = ex.entities.create();
    parallax_background_layer3.assign<PositionComponent>(1.0f, 2.0f);
    parallax_background_layer3.assign<DirectionComponent>();
    parallax_background_layer3.assign<ParallaxComponent>(1, focal_point_speed);
    sf::Texture layer3_texture;
    layer3_texture.loadFromFile("res/img/background/layer-3.png");
    sf::Sprite layer3_sprite(layer3_texture);
    parallax_background_layer3.assign<DrawableComponent>(layer3_sprite);

    entityx::Entity parallax_background_layer4 = ex.entities.create();
    parallax_background_layer4.assign<PositionComponent>(1.0f, 2.0f);
    parallax_background_layer4.assign<DirectionComponent>();
    parallax_background_layer4.assign<ParallaxComponent>(1, focal_point_speed + layer_difference);
    sf::Texture layer4_texture;
    layer4_texture.loadFromFile("res/img/background/layer-4.png");
    sf::Sprite layer4_sprite(layer4_texture);
    parallax_background_layer4.assign<DrawableComponent>(layer4_sprite);

    sf::Texture texture;
    if (!texture.loadFromFile("res/img/background/nightsky.jpg"))
    {
        return EXIT_FAILURE;
    }

    sf::Font font;
    if (!font.loadFromFile("res/ttf/Roboto-Regular.ttf"))
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
        window.draw(text);
        window.display();
    }
    return EXIT_SUCCESS;
}
