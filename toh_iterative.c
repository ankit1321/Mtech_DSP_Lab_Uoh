#include<iostream>
#include<cmath>
#include<cstdlib>
#include<stdio.h>
using namespace std;
void buildBoard(int array[][3], int rows);
void printArray(int array[][3], int rows);
void moveDisk(int disk, int b[][3], int from_column, int to_column, int rows);
void towers(int disks, int b[][3], int from_column, int spare, int to_column, int rows);
/*void checkInput(){
    //cin.clear();
    //cin.ignore(1000, '\n');
    cout<<"I'm Sorry! You did not input a positive integer less than 100.  Please try again!\033[0m\n";
}*/

int main()
{
    int run = 1;
    int x;
    int rows;
    while (run == 1)
        {
        printf("Please enter the number of disks: \n");
        scanf("%d",&x);
        if (x>100 || x<0)
            {
            printf("I'm Sorry! You did not input a positive integer less than 100.  Please try again!\n");
            break;
            }
        rows = x;
        int board[x][3];

        buildBoard(board, rows);
        printArray(board, rows);
        towers(x, board, 0, 1, 2, rows);
        printf("Would you like to play again?\n");
        printf("press 1 to continue or any key to exit.\n");
        scanf("%d",&run);
        }
    return 0;
}

void buildBoard(int array[][3], int rows){
    for (int x = 0; x<rows; x++){
        array[x][0] = x+1;
        for (int y = 1; y<3; y++){
            array[x][y] = 0;
        }
    }
}
void printArray(int array[][3], int rows){
    for (int x = 0; x<rows; x++){
        for (int y = 0; y<3; y++){
            printf("%d  ",array[x][y]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
}

void moveDisk(int disk, int b[][3], int from_column, int to_column, int rows){
    int lowest;
    int i;
    for(i = rows-1; i>=0 && b[i][from_column]!=0; i--){
        disk = i;
    }
    for(i = rows-1; i>=0; i--){
        if (b[i][to_column]!=0){
            ;
        }
        else{
            lowest = i;
            break;
        }
    }
    b[lowest][to_column] = b[disk][from_column];
    b[disk][from_column] = 0;
}

void towers(int disks, int b[][3], int from_column, int spare, int to_column, int rows){
    if(disks!=0){
        towers(disks-1, b, from_column, to_column, spare, rows);
        cout<<"Moving disk "<<disks<<" from "<<from_column<<" to "<<to_column<<endl;
        moveDisk(disks-1, b, from_column, to_column, rows);
        printArray(b, rows);
        towers(disks-1, b, spare, from_column, to_column, rows);
    }
}
