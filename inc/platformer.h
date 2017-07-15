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

#ifdef LSS_PLATFORMER_H
#define LSS_PLATFORMER_H

//----------------------------------------------------------------------------//
// Purpose: This class represents the base class of any plaforming level.
//----------------------------------------------------------------------------//
class Platformer : public EntityX
{
public:
  explicit Platformer() {
    //systems.add<DebugSystem>();
    //systems.add<MovementSystem>();
    //systems.add<CollisionSystem>();
    //systems.configure();

    //level.load(filename);

    //for (auto e : level.entity_data()) {
      //entityx::Entity entity = entities.create();
      //entity.assign<Position>(rand() % 100, rand() % 100);
      //entity.assign<Direction>((rand() % 10) - 5, (rand() % 10) - 5);
    }
  }

  void update(/*TimeDelta dt*/) {
    //systems.update<DebugSystem>(dt);
    //systems.update<MovementSystem>(dt);
    //systems.update<CollisionSystem>(dt);
  }
};

#endif // LSS_PLATFORMER_H
