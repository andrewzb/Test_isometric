#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>

#include "./Grid.h"

int main () {
    Color darkBlue = {44,44,127,255};
    Color white = {255,255,255,255};
    int cellSize = 64;

    InitWindow(1200, 800, "isometry test");
    SetTargetFPS(60);

    int x = 2;
    int y = 4;
    Grid grid {x, y};
    // grid.SetValue( 0,0, 0);

    while(WindowShouldClose() == false) {
        BeginDrawing();

        ClearBackground(darkBlue);

        // std::cout <<  "--------------------------" << std::endl;
        // for(int flatIndex = 0; flatIndex < grid.GetSize(); flatIndex++ ) {
        //     std::pair<int, int> dimentionalIndex = grid.GetDementionalIndex(flatIndex);
        //     //DIRECTION 1
        //     {
        //         int offX = 100;
        //         int offY = 50;
        //         int posx = offX + dimentionalIndex.first * cellSize - dimentionalIndex.second * cellSize;
        //         int posy = offY + dimentionalIndex.second * cellSize + (dimentionalIndex.first - dimentionalIndex.second) * cellSize / 2 ;
        //         DrawTexture(texture, posx, posy, darkBlue);
        //         DrawText(std::to_string(flatIndex).c_str(), posx + 24, posy + 8, 14, white);
        //     }

        //     //DIRECTION 2
        //     {
        //         int offX = 600;
        //         int offY = 50;
        //         // int posx = offX - dimentionalIndex.first * cellSize + dimentionalIndex.second * cellSize *2 ;
        //         // int posy = offY - dimentionalIndex.second * cellSize + dimentionalIndex.first * cellSize / 2;
        //         int posx = offX - dimentionalIndex.first * cellSize + dimentionalIndex.second * cellSize ;
        //         int posy = offY - dimentionalIndex.second * cellSize + dimentionalIndex.first * cellSize / 2 + dimentionalIndex.second * cellSize * 3 / 2;
        //         DrawTexture(texture, posx, posy, darkBlue);
        //         DrawText(std::to_string(flatIndex).c_str(), posx + 24, posy + 8, 14, white);
        //     }
        // }


        grid.DrawIso();

        grid.DrawGrid(2, 200, 200);
        grid.DrawGrid(0, 500, 200);
        grid.DrawGrid(1, 100, 400);
        grid.DrawGrid(3, 500,400);
        // int posX = 500;
        // int posY = 250;
        // int width = cellSize * 3;
        // int height = cellSize / 2 * 4;
        // // std::cout <<  width << std::endl;
        // // std::cout <<  height << std::endl;

        // grid.DrawGrid(3, posX, posY);

        // // DrawRectangleLines(posX, posY - 64 + 16 , width, height, white);
        // std::pair<int, int> t = grid.GetGridRect();
        // DrawRectangleLines(posX + 64, posY - 32, -t.first, t.second, white);    
        EndDrawing();


    }

    CloseWindow();
    return 0;
}
