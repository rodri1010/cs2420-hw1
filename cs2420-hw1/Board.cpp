//
//  Board.cpp
//  cs2420-hw1
//
//  Created by rodrigo on 1/16/18.
//  Copyright © 2018 rodrigo. All rights reserved.
//

#include "Board.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>

Board::Board(){
    srand(time(NULL));
    numbers.resize(3,std::vector<int>(3));
    for(int i=0;i<numbers.size();i++){
        for(int j=0;j<numbers.size();j++){
            int random=((rand() % 9)+1);
            if(checkRepeated(numbers,random)){
                numbers[i][j]=random;
            }
            else{
                j--;
            }
        }
    }
}



Board::Board(std::vector<int> input){
    numbers.resize(3,std::vector<int>(3));
    int count=0;
    for(int i=0;i<numbers.size();i++){
        for(int j=0;j<numbers.size();j++){
            int number=input[count];
            numbers[i][j]=number;
            count++;
        }
    }
}


Board& Board::operator=(Board& rhs){
    this->numbers=rhs.numbers;
    return *this;
}


Board* inputBoard(){
    std::cout<<"Please input the numbers of the board from top left corner to bottom right corner and press enter"<<std::endl;
    std::vector<int> numbers(9);
    std::string input;
    std::cin >> input;
    for(int i=0;i<input.length();i++){
        int a=static_cast<int>(input[i]);
        numbers[i]=a-'0';
    }
    Board* board = new Board(numbers);
    return board;
}

bool Board::checkRepeated(std::vector<std::vector<int> > numbers,int random){
    for(int i=0;i<(int)numbers.size();i++){
        for(int j=0;j<(int)numbers[i].size();j++){
            if(numbers[i][j]==random){
                return false;
            }
        }
    }
    return true;
}

void Board::printBoard(){
    for(int i=0;i<(int)numbers[0].size();i++){
        std::cout<<std::setfill('-')<<std::setw(5*(int)numbers.size()+2)<<"\n";
        std::cout<<"|";
        for(int j=0;j<(int)numbers[0].size();j++){
            std::cout<<std::setfill(' ')<<std::setw(3)<<numbers[i][j]<<" |"<<std::setfill(' ')<<std::setw(3);
        }
        std::cout<<std::endl;
    }
    std::cout<<std::setfill('-')<<std::setw(5*(int)numbers.size()+2)<<"\n";
    std::cout<<std::setfill(' ')<<std::setw(0);
    std::cout<<std::endl;
}

Board* Board::firstRowRight(Board* board){
    Board* boardNew= board;
    int temp=boardNew->numbers[0][2];
    int temp1=boardNew->numbers[0][1];
    boardNew->numbers[0][1]=boardNew->numbers[0][0];
    boardNew->numbers[0][2]=temp1;
    boardNew->numbers[0][0]=temp;
    return boardNew;
}

Board* Board::secondRowRight(Board* board){
    Board* boardNew= board;
    int temp=boardNew->numbers[1][2];
    int temp1=boardNew->numbers[1][1];
    boardNew->numbers[1][1]=boardNew->numbers[1][0];
    boardNew->numbers[1][2]=temp1;
    boardNew->numbers[1][0]=temp;
    return boardNew;
}


Board* Board::thirdRowRight(Board* board){
    Board* boardNew = board;
    int temp=boardNew->numbers[2][2];
    int temp1=boardNew->numbers[2][1];
    boardNew->numbers[2][1]=boardNew->numbers[2][0];
    boardNew->numbers[2][2]=temp1;
    boardNew->numbers[2][0]=temp;
    return boardNew;
}

Board* Board::firstRowLeft(Board* board){
    Board* boardNew=board;
    int temp=boardNew->numbers[0][0];
    int temp1=boardNew->numbers[0][2];
    boardNew->numbers[0][0]=boardNew->numbers[0][1];
    boardNew->numbers[0][2]=temp;
    boardNew->numbers[0][1]=temp1;
    return boardNew;
}
Board* Board::secondRowLeft(Board* board){
    Board* boardNew=board;
    int temp=boardNew->numbers[1][0];
    int temp1=boardNew->numbers[1][2];
    boardNew->numbers[1][0]=boardNew->numbers[1][1];
    boardNew->numbers[1][2]=temp;
    boardNew->numbers[1][1]=temp1;
    return boardNew;
    
}
Board* Board::thirdRowLeft(Board* board){
    Board* boardNew=board;
    int temp=boardNew->numbers[2][0];
    int temp1=boardNew->numbers[2][2];
    boardNew->numbers[2][0]=boardNew->numbers[2][1];
    boardNew->numbers[2][2]=temp;
    boardNew->numbers[2][1]=temp1;
    return boardNew;
}

Board* Board::firstColDown(Board* board){
    Board* boardNew=board;
    int temp=boardNew->numbers[2][0];
    int temp1=boardNew->numbers[1][0];
    boardNew->numbers[1][0]=boardNew->numbers[0][0];
    boardNew->numbers[2][0]=temp1;
    boardNew->numbers[0][0]=temp;
    return boardNew;
}
Board* Board::secondColDown(Board* board){
    Board* boardNew=board;
    int temp=boardNew->numbers[2][1];
    int temp1=boardNew->numbers[1][1];
    boardNew->numbers[1][1]=boardNew->numbers[0][1];
    boardNew->numbers[2][1]=temp1;
    boardNew->numbers[0][1]=temp;
    return boardNew;
}
Board* Board::thirdColDown(Board* board){
    Board* boardNew=board;
    int temp=boardNew->numbers[2][2];
    int temp1=boardNew->numbers[1][2];
    boardNew->numbers[1][2]=boardNew->numbers[0][2];
    boardNew->numbers[2][2]=temp1;
    boardNew->numbers[0][2]=temp;
    return boardNew;
}
Board* Board::firstColUp(Board* board){
    Board* boardNew=board;
    int temp=boardNew->numbers[0][0];
    int temp1=boardNew->numbers[2][0];
    boardNew->numbers[0][0]=boardNew->numbers[1][0];
    boardNew->numbers[2][0]=temp;
    boardNew->numbers[1][0]=temp1;
    return boardNew;
}
Board* Board::secondColUp(Board* board){
    Board* boardNew=board;
    int temp=boardNew->numbers[0][1];
    int temp1=boardNew->numbers[2][1];
    boardNew->numbers[0][1]=boardNew->numbers[1][1];
    boardNew->numbers[2][1]=temp;
    boardNew->numbers[1][1]=temp1;
    return boardNew;
}
Board* Board::thirdColUp(Board* board){
    Board* boardNew=board;
    int temp=boardNew->numbers[0][2];
    int temp1=boardNew->numbers[2][2];
    boardNew->numbers[0][2]=boardNew->numbers[1][2];
    boardNew->numbers[2][2]=temp;
    boardNew->numbers[1][2]=temp1;
    return boardNew;
}


int Board::similarity(Board rhs){
    int similarityPercentage=0;
    for(int i=0;i<rhs.numbers[0].size();i++){
        for(int j=0;j<rhs.numbers[0].size();j++){
            if(numbers[i][j] == rhs.numbers[i][j]){
                similarityPercentage++;
            }
        }
    }
    return similarityPercentage;
}



