#include <iostream>
#include <vector>
#include <cassert>


int main() {
    bool winX= false;
    bool winO=false;

    char cell[3][3];
    
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            cell[i][j]=' ';
        }
    }



    for (int k=0;k<9 && !winX && !winO;k++) {
        // put X
        if (k % 2==0) {
            bool rightPos=false;
            int x=-1;
            int y=-1;
            while (!rightPos) {
                std::cout<<"Input coordinates of X (0..2; 0..2): ";
                std::cin>>x>>y;

                if (cell[x][y]==' ' 
                    && x>=0 && x<3 
                    && y>=0 && y<3
                    && !std::cin.fail()) {
                    cell[x][y]='X';
                    rightPos=true;
                } else {
                    std::cout<<"wrong coordinates\n";
                }
            }
        }
        //put O
        else {
            bool rightPos=false;
            int x=-1;
            int y=-1;
            while (!rightPos) {
                std::cout<<"Input coordinates of O (0..2; 0..2): ";
                std::cin>>x>>y;
                if (cell[x][y]==' ' 
                    && x>=0 && x<3 
                    && y>=0 && y<3
                    && !std::cin.fail()) {
                    cell[x][y]='O';
                    rightPos=true;
                } else {
                    std::cout<<"wrong coordinates\n";
                }
            }
        }


        // output table
        std::cout<<std::endl;
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                std::cout<<cell[i][j];
            }
            std::cout<<std::endl;
        }

        // win determine
        
        //win X
        if (cell[0][0]=='X' && cell[0][1]=='X' && cell[0][2]=='X' ||
            cell[1][0]=='X' && cell[1][1]=='X' && cell[1][2]=='X' ||
            cell[2][0]=='X' && cell[2][1]=='X' && cell[2][2]=='X' ||

            cell[0][0]=='X' && cell[1][0]=='X' && cell[2][0]=='X' ||
            cell[0][1]=='X' && cell[1][1]=='X' && cell[2][1]=='X' ||
            cell[0][2]=='X' && cell[1][2]=='X' && cell[2][2]=='X' ||

            cell[0][0]=='X' && cell[1][1]=='X' && cell[2][2]=='X' ||
            cell[0][2]=='X' && cell[1][1]=='X' && cell[2][0]=='X' ) {
                winX=true;
        }

        //win O
        if (cell[0][0]=='O' && cell[0][1]=='O' && cell[0][2]=='O' ||
            cell[1][0]=='O' && cell[1][1]=='O' && cell[1][2]=='O' ||
            cell[2][0]=='O' && cell[2][1]=='O' && cell[2][2]=='O' ||

            cell[0][0]=='O' && cell[1][0]=='O' && cell[2][0]=='O' ||
            cell[0][1]=='O' && cell[1][1]=='O' && cell[2][1]=='O' ||
            cell[0][2]=='O' && cell[1][2]=='O' && cell[2][2]=='O' ||

            cell[0][0]=='O' && cell[1][1]=='O' && cell[2][2]=='O' ||
            cell[0][2]=='O' && cell[1][1]=='O' && cell[2][0]=='O' ) {
                winO=true;
        }
    }
    if (winX) {
        std::cout<<"X win";
    } else if (winO) {
        std::cout<<"O win";
    } else {
        std::cout<<"Draw";
    }




}