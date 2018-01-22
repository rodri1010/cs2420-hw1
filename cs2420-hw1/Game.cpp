//
//  GameState.cpp
//  cs2420-hw1
//
//  Created by rodrigo on 1/17/18.
//  Copyright © 2018 rodrigo. All rights reserved.
//

#include "Game.hpp"

Game::Game(){
    char answer;
    std::cout<<"For a random board press R, if you want to input the numbers press I"<<std::endl;
    std::cin>>answer;
    if(answer=='R' or answer=='r'){
        current = new Board();
    }
    else if(answer=='I' or answer=='i'){
        current= inputBoard();
    }
    else{
        std::cout<<"Please enter a valid choice"<<std::endl;
        Game();
    }
    std::cout<<"This is your Board"<<std::endl;
    current->printBoard();
    std::cout<<"Do you want to solve it? y/n"<<std::endl;
    char solAns;
    std::cin>>solAns;
    if(solAns=='Y' or solAns=='y'){
        solve();
    }
    else if(solAns=='N' or solAns=='n'){
        std::cout<<"Good bye"<<std::endl;
        
    }
    
    
}


void Game::solve(){
    currentSim=current->similarity(solution);
    for(int i=0;i<12;i++){
        //Board* board = Board::functions[i](current);
        
    }
}
        

