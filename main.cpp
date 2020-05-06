#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include <string>
using matrix = std::vector<std::vector<int>>;
matrix Matrix_creator(int n){
    std::vector<std::vector<int>> v(n, std::vector<int>(n,0));
    for(auto &line:v){
        for(int &i:line){
            i=rand()%9+1;
        }
    }
    return v;
}
matrix Matrix_multiplier(matrix v1,matrix v2,int n){
    matrix finished_matrix(n, std::vector<int>(n,0));
    for (int i = 0; i<n; i++){
        for (int j=0; j < n; j++){
            for (int k=0; k<n;k++)
                finished_matrix[i][j]+=v1[i][k]*v2[k][j];
        }
    }
    return finished_matrix;
}
void print_matrix(matrix vec){
    for(auto line:vec){
            std::cout<<"\t";
        for(int i:line){
            std::cout<<i<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}
void process(int n){
    srand(time(NULL));
    matrix v1=Matrix_creator(n);
    matrix v2=Matrix_creator(n);
    matrix final_matrix=Matrix_multiplier(v1,v2,n);
    std::cout<<"Matrix #1:"<<std::endl;
    print_matrix(v1);
    std::cout<<"Matrix #2:"<<std::endl;
    print_matrix(v2);
    std::cout<<"Matrix #1 X Matrix #2:"<<std::endl;
    print_matrix(final_matrix);
}
void choice(){
    int n;
    std::string runagain;
    std::cout<<"Please enter the size you want your nXn matrix:\n";
    if(!(std::cin>>n)||n==0||n<1){
        std::cout<<"Please enter a valid positive number\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        choice();
    }
    else{
        process(n);
        std::cout<<"enter 1 if you want to run this program again\nenter anything else to quit\n";
        std::cin>>runagain;
        if(runagain=="1"){choice();}
    }
}
int main(){choice();}
