//
// Created by anique on 6/16/18.
//

#ifndef MAZE_MAIN_H
#define MAZE_MAIN_H
class Maze{
    const char EMPTY_CHAR = '0';
    const char WALL_CHAR = '1';



private:
    char* getMaze();

public:
    void printMaze();
    int mazeWidth=100;
    int mazeHeight=100;
    float wallDensity = 0.5;
};


#endif //MAZE_MAIN_H
