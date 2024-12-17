#include "./Grid.h"

Grid::Grid(int width, int height) {
    this->width = width;
    this->height = height;
    this->map = std::vector<int> (width * height);
    Image image = LoadImage("./assets/cube.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Grid::~Grid() {
}

int Grid::GetFlatIndex(int width, int height) {
    return this->width * height + width;
}

int Grid::GetValue(int width, int height) {
    return map[GetFlatIndex(width, height)];
}

int Grid::GetValue(int flatIndex) {
    return map[flatIndex];
}

void Grid::SetValue(int width, int height, int value) {
    map[GetFlatIndex(width, height)] = value;
}

void Grid::SetValue(int flatIndex, int value) {
    map[flatIndex] = value;
}

std::pair<int, int> Grid::GetDementionalIndex(int flatIndex) {
    int x = flatIndex % width;
    int y = flatIndex / width;
    return std::pair<int, int> {x, y};
}

int Grid::GetSize() {
    return width * height;
}

void Grid::DrawGrid(int direction, int offX, int offY) {
    Color white = {255,255,255,255};
    Color black = {0,0,0,255};
    int cellSize = 32;
    if (direction == 0) {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++){
                int posx = offX + i * cellSize - j * cellSize;
                int posy = offY + j * cellSize + (i - j) * cellSize / 2 ;
                DrawTexture(texture, posx, posy, white);
                std::string label = "(" + std::to_string(i) + "," + std::to_string(j) + ")";
                DrawText(label.c_str(), posx + 20, posy + 8, 12, white);
            }
        }
    }
    if (direction == 1) {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++){
                int posx = offX - i * cellSize + j * cellSize ;
                int posy = offY - j * cellSize + i *  cellSize / 2 + j * cellSize * 3 / 2;
                DrawTexture(texture, posx, posy, white);
                std::string label = "(" + std::to_string(i) + "," + std::to_string(j) + ")";
                DrawText(label.c_str(), posx + 20, posy + 8, 12, white);
            }
        }
    }

    if (direction == 2) {
        for (int i = (width - 1); i > -1; i--) {
            for (int j = 0; j < height; j++) {
                int posx = offX + i * cellSize + j * cellSize;
                int posy = offY + j * cellSize - (i + j) * cellSize / 2;
                DrawTexture(texture, posx, posy, white);
                std::string label = "(" + std::to_string(i) + "," + std::to_string(j) + ")";
                DrawText(label.c_str(), posx + 20, posy + 8, 12, white);
            }
        }
    }

    if (direction == 3) {
        for (int i = (width - 1); i > -1; i--) {
            for (int j = 0; j < height; j++) {
                int posx = offX - i * cellSize - j * cellSize;
                int posy = offY + j * cellSize - (i + j) * cellSize / 2;
                DrawTexture(texture, posx, posy, white);
                std::string label = "(" + std::to_string(i) + "," + std::to_string(j) + ")";
                DrawText(label.c_str(), posx + 20, posy + 8, 12, white);
            }
        }
    }

}

std::pair<int, int> Grid::GetGridRect() {
    int hsize = 32;
    int w = (width + height) * hsize;
    int h = (height - width + 1) * hsize;
    return std::pair<int, int> {w,h};
}


std::pair<int, int> Grid::GetIsometric(std::pair<int, int>  coords2D) {
    return std::pair<int, int> {
        coords2D.first - coords2D.second,
        (coords2D.first + coords2D.second) / 2
    };

    // return std::pair<int, int> {
    //     (coords2D.first - coords2D.second),
    //     (coords2D.first + coords2D.second) / 2
    // };
}

void Grid::DrawIso() {
    Color white = {255,255,255,255};
    int tileSize = 64;
    int hsize = 32;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            std::pair<int, int> pos { i * hsize, j * hsize};
            pos = GetIsometric(pos);

            DrawTexture(texture, 600 + pos.first, 600 + pos.second, white);
            std::string label = "(" + std::to_string(i) + "," + std::to_string(j) + ")";
            DrawText(label.c_str(), 600 + pos.first + 20, 600 + pos.second + 8, 12, white);

        }
    }

    std::pair<int, int> qqq = GetGridRect();

        

    DrawRectangleLines(600 - 64 - 32, 600, qqq.first, qqq.second, white);
}
