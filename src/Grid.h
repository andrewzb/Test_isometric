#ifndef GRID_H
#define GRID_H

#include <raylib.h>
#include <vector>
#include <iostream>
#include <string>


class Grid {
    private:
        int width;
        int height;
        Texture2D texture;
        std::vector<int> map;

    public:
        Grid(int width, int height);
        ~Grid();

        int GetFlatIndex(int width, int height);
        std::pair<int, int> GetDementionalIndex(int flatIndex);

        int GetValue(int width, int height);
        int GetValue(int flatIndex);

        void SetValue(int width, int height, int value);
        void SetValue(int flatIndex, int value);

        int GetSize();

        void DrawGrid(int direction, int offX, int offY);

        std::pair<int, int> GetGridRect();

        std::pair<int, int> GetIsometric(std::pair<int, int>  coords2D);
        void DrawIso();

};

#endif