//
//  GameState.hpp
//  cs2420-hw1
//
//  Created by rodrigo on 1/17/18.
//  Copyright © 2018 rodrigo. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <vector>
#include <iostream>
#include "Board.hpp"
#include <queue>

class Game{
    
public:
    Game();
    void solve();
    
    
    
    
private:
    std::vector<int> solNums = {1,2,3,4,5,6,7,8,9};
    Board* current;
    int currentBoardNumber;
    int prevBoardNumber;
    Board solution = Board(solNums);
    std::queue<Board*> m_queue;
    int currentSim;
    friend class Board;
    
};




#endif /* Game_hpp */
