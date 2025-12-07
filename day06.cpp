#import <iostream>
#import <fstream>
#import <string>
#import <vector>
#import <sstream>
std::vector<std::string> lineToVec(std::string t){
	std::vector<std::string> ans;
	std::stringstream ss(t);
	std::string temp;
	while (ss >> temp){
		ans.push_back(temp);
	}
	for (auto i : ans){
		std::cout << i << " ";
	}
	std::cout << "\n";
	return ans;
}


int main(){
	std::ifstream file("input06.txt");
	std::string t;
	std::vector<std::vector<std::string>> lines;
	
	while (std::getline(file,t)){
		lines.push_back(lineToVec(t));
	}
	
	long long int answer = 0;
	int size = lines[0].size();
	int numLines = lines.size()-1;
	
	std::cout << numLines;
	for (int i = 0; i < size; ++i){
		if (lines.back()[i] == "*"){
			long long int val = 1;
			for (int j = 0; j < numLines; ++j){
				val *= stoi(lines[j][i]);
			}
			std::cout << val << "\n";
			answer += val;
		}
		else{
			long long int val = 0;
			for (int j = 0; j < numLines; ++j){
				val += stoi(lines[j][i]);
			}
			std::cout << val << "\n";
			answer += val;
		}
	}
	std::cout << answer << "\n";
}
