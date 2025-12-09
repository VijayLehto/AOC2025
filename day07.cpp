#include <iostream>
#include <fstream>
#include <string>
#include "2darray.h"

int neighbours(Array<int>& arr, int x, int y);
bool validRoll(Array<int>& arr, int i, int j);
int update(Array<int>& arr, int x, int y);
int main(){

        std::ifstream file("input07.txt");
        std::string line;
        std::vector<std::string> lines;
        while (std::getline(file,line)) {
                lines.push_back(line);
        }
        int n = lines[0].length();
        int m = lines.size();
        Array<char> compactor(n,m);

        for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                        char currChar = lines[i][j];
                        compactor.setVal({i,j},currChar);
                }
        }
	
	std::vector<long long int> beams;
	for(int i = 0; i < n; ++i){
		beams.push_back((compactor[{0,i}] == 'S') ? 1 : 0);
	}
	long long int answer = 1;
	for(int i = 1; i < m; ++i){

		for(long long int j : beams){
			std::cout << j << " ";
		}
		std::cout << "\n";
		
		for (int j = 0; j < n; ++j){
			if (beams[j] != 0 && compactor[{i,j}] == '^'){
				beams[j-1] += beams[j];
				beams[j+1] += beams[j];
				answer += beams[j];
				beams[j] = 0;
			}
		}
	}
	std::cout << n << " " << answer;	
	return 0;
}
