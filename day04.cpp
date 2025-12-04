#include <iostream>
#include <fstream>
#include <string>
#include "2darray.h"

int neighbours(Array<int>& arr, int x, int y);

int main(){
	std::ifstream file("day04.txt");
	std::string line;
	std::vector<std::string> lines;
	while (std::getline(file,line)) {
		lines.push_back(line);
	}

	int n = lines[0].length();
	int m = lines.size();
	Array<int> department(n,m);

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			char currChar = lines[i][j];
			int val = (currChar == '@') ? 1 : 0;

			department.getRef({i,j}) = val;
		}
	}
	int answer = 0;
	for(int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (neighbours(department,i,j) < 4){
				++answer;
			}
		}
	}

	std::cout << answer;

	return 0;
}

int neighbours(Array<int>& arr, int x, int y){
	int neighbours = 0;
	for(int i = -1; i < 2; ++i){
		for(int j = -1; j < 2; ++j){
			if(i == 0 && j == 0){
				continue;
			}
			neighbours += arr[{x+i,y+j}];
		}
	}
	return neighbours;
}
