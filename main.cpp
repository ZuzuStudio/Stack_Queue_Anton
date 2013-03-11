#include <iostream>
#include <termios.h>
#include <stdlib.h>
#include <fstream>
#include "my_queue.h"
#include "my_stack.h"
#include "stack_class.h"

using namespace std;

char getch(){
    struct termios oldt,newt;
    char ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

void Check_Queue(){
	Node_int *begin = NULL, *end = NULL;
	ifstream fin ("begin.txt");
	ofstream fout ("end.txt");
	char ch;
	int num;
	fin >> ch;
	while(!fin.eof()){
        switch(ch){
        case 'i':
            fin >> num;
			Enqueue(begin, end, num);
			break;
		case 'o':
			fout << Dequeue(begin,end) << ' ';
			break;
		}
		fin >> ch;
	}
	Clear(begin, end);
}

void Check_Stack(){
	Node_int *top = NULL;
	ifstream fin ("begin.txt");
	ofstream fout ("end.txt");
	char ch;
	int num;
	fin >> ch;
	while(!fin.eof()){
        switch(ch){
        case 'i':
            fin >> num;
			Push(top, num);
			break;
		case 'o':
			fout << Pop(top) << ' ';
			break;
		}
		fin >> ch;
	}
	Clear(top);
}

int main(){
    bool fl = false, cry = true;
    cout << "If you want to check my stack press 1 if queue press 2. To end press 0 \n";
    while(!fl){
        switch(getch()){
        case '1':
            Check_Stack();
            fl = true;
            cry = false;
            break;
        case '2':
            Check_Queue();
            fl = true;
            cry = false;
            break;
        case '0':
            fl = true;
            break;
        }
    }
    system("clear");
	if(!cry) cout << "All done!! The result of my work you can see in end.txt";
	else cout << "Why you didn't use me!!!!!!!!!!!!";
}
