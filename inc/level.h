//----------------------------------------------------------------------------//
//                   ______________________________________                   //
//         ________|                                      |_______            //
//         \       |       This file is a part of         |      /            //
//          \      |           Scharfschütze              |     /             //
//          /      |______________________________________|     \             //
//         /__________)                                (_________\            //
//                                                                            //
//                     Copyright(c) 2017 Thomas Steinholz                     //
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

#ifdef LSS_LEVEL_H
#define LSS_LEVEL_H

#include <entityx/entityx.h>

using namespace entityx;

//----------------------------------------------------------------------------//
// Purpose: TODO
//----------------------------------------------------------------------------//
struct PositionComponent {
    explicit PositionComponent(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
    float x, y;
};

//----------------------------------------------------------------------------//
// Purpose: TODO
//----------------------------------------------------------------------------//
struct DirectionComponent {
    DirectionComponent(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
    float x, y;
};

//----------------------------------------------------------------------------//
// Purpose: TODO
//----------------------------------------------------------------------------//
struct ParallaxComponent {
    ParallaxComponent(int layer = 0, int hspeed = 0) : layer(layer), hspeed(hspeed) {}
    int layer;
    int hspeed;
};

//----------------------------------------------------------------------------//
// Purpose: TODO
//----------------------------------------------------------------------------//
struct DrawableComponent {
    sf::Sprite sprite;
    DrawableComponent(sf::Sprite sprite) : window(window), sprite(sprite) {}
    sf::RenderWindow *window;
};

//----------------------------------------------------------------------------//
// Purpose: TODO
//----------------------------------------------------------------------------//
struct MovementSystem : public entityx::System<MovementSystem> {
    void update(EntityManager &es, EventManager &events, TimeDelta dt) override;
};

//----------------------------------------------------------------------------//
// Purpose: TODO
//----------------------------------------------------------------------------//
struct RenderSystem : public entityx::System<RenderSystem> {
    RenderSystem(sf::RenderTarget *renderTarget);

    void update(EntityManager &es, EventManager &events, TimeDelta dt) override;

private:
    sf::RenderTarget *renderTarget;
};

//----------------------------------------------------------------------------//
// Purpose: Redirects SFML events into the Component Entity System.
//----------------------------------------------------------------------------//
struct SFMLEventSystem : public entityx::System<SFMLEventSystem> {
    SFMLEventSystem();

    void update(EntityManager &es, EventManager &events, TimeDelta dt) override;

    void triggerEvent(sf::Event ev);
};

//----------------------------------------------------------------------------//
// Purpose: This class represents the base class of any plaforming level.
//----------------------------------------------------------------------------//
class Platformer : public EntityX
{
    explicit Platformer();

    void update(TimeDelta dt);
};

#endif // LSS_LEVEL_H
