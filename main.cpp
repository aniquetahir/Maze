#include <iostream>
#include "main.h"
#include <vector>

using namespace std;


int main() {
    // Seed random
    srand(time(NULL));

    Maze maze;
    maze.mazeWidth = 10;
    maze.mazeHeight = 10;
    maze.printMaze();
    return 0;
}

char * Maze::getMaze() {
    int numSquares = this->mazeWidth*this->mazeHeight;
    int numFilled = 0;
    float density = 0;

    vector<int*> walls;

    while(density<this->wallDensity){

        int randX = rand()%mazeWidth;
        int randY = rand()%mazeHeight;
        int coords[] = {randX, randY};

        // TODO Check if coord already exists
        bool coordExists = false;
        ;
        for(vector<int*>::iterator iterator = walls.begin();
                iterator!=walls.end(); iterator++){
            int* mCoords = *iterator;
            if(mCoords[0] == coords[0] && mCoords[1]==coords[1]){
                coordExists = true;
                break;
            }
        }

        // If it doesn't. Add and update density
        if(!coordExists) {
            int* coordsCpy = (int*)malloc(sizeof(int)*2);
            coordsCpy[0] = coords[0];
            coordsCpy[1] = coords[1];
            walls.push_back(coordsCpy);
            numFilled++;
            density = numFilled/(float)numSquares;
        }
    }

    long maze_string_length = numSquares+this->mazeHeight;
    char* maze = (char*)malloc(sizeof(char) * maze_string_length);

    for(long i=0;i<maze_string_length;i++){
        maze[i] = '0';
    }

    // Add newline chars
    for(int i=1; i<=mazeHeight; i++){
        maze[((mazeWidth+1)*i)-1]='\n';
    }

    // Add wall chars
    for(vector<int*>::iterator iterator = walls.begin();
        iterator!=walls.end(); iterator++){
        int* mCoords = *iterator;
        maze[mCoords[0]+(mazeWidth+1)*mCoords[1]] = '1';
    }


    return maze;
}

void Maze::printMaze() {
    cout<<getMaze()<<endl;
}
