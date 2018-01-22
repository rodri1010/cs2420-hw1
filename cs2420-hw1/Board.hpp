//
//  board.hpp
//  cs2420-hw1
//
//  Created by rodrigo on 1/16/18.
//  Copyright © 2018 rodrigo. All rights reserved.
//

#ifndef Board_h
#define Board_h
#include <vector>
class Board {
public:
    Board();
    Board(std::vector<int> input);
    bool checkRepeated(std::vector<std::vector<int> > numbers,int random);
    void printBoard();
    Board* firstRowRight(Board* board);
    Board* secondRowRight(Board* board);
    Board* thirdRowRight(Board* board);
    Board* firstRowLeft(Board* board);
    Board* secondRowLeft(Board* board);
    Board* thirdRowLeft(Board* board);
    Board* firstColDown(Board* board);
    Board* secondColDown(Board* board);
    Board* thirdColDown(Board* board);
    Board* firstColUp(Board* board);
    Board* secondColUp(Board* board);
    Board* thirdColUp(Board* board);
    int similarity(Board rhs);
    void createFuncArray();
    Board& operator=(Board& rhs);
    
    typedef Board* (Board::*function)(Board* board);
    constexpr static function functions[12]={
        &Board::firstRowRight,
        &Board::secondRowRight,
        &Board::thirdRowRight,
        &Board::firstRowLeft,
        &Board::secondRowLeft,
        &Board::thirdRowLeft,
        &Board::firstColDown,
        &Board::secondColDown,
        &Board::thirdColDown,
        &Board::firstColUp,
        &Board::secondColUp,
        &Board::thirdColUp
    };
    
private:
    std::vector<std::vector<int>> numbers;
    
};
Board* inputBoard();




#endif /* Board_h */
