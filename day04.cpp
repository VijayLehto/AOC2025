#include <iostream>
#include <fstream>
#include <string>
#include "2darray.h"

int neighbours(Array<int>& arr, int x, int y);
bool validRoll(Array<int>& arr, int i, int j);
int update(Array<int>& arr, int x, int y);
int main(){

	std::ifstream file("input04.txt");
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

			department.setVal({i,j},val);
		}
	}
	int answer = 0;
	for(int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			answer += update(department, i, j);
		}
	}

	std::cout << answer << "\n";
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

bool validRoll(Array<int>& arr, int i, int j){
	return (arr[{i,j}] == 1 && neighbours(arr,i,j) < 4);
}

int update(Array<int>& arr, int x, int y){
	if (!validRoll(arr,x,y)){
		return 0;
	}
	int answer = 1;
	arr.setVal({x,y},0);
        for(int i = -1; i < 2; ++i){
                for(int j = -1; j < 2; ++j){
                        if(i == 0 && j == 0){
                                continue;
                        }
                        answer += update(arr,x+i,y+j);
                }
        }
	return answer;
}
