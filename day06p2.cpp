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
	return ans;
}


int main(){
	std::ifstream file("input06.txt");
	std::string t;
	std::vector<std::string> lines;
	
	while (std::getline(file,t)){
		lines.push_back(t);
	}

	std::vector<std::string> ops = lineToVec(lines.back());
	lines.pop_back();
	
	long long int answer = 0;
	int size = ops.size();
	int numLines = lines.size();
	
	int i = 0;
	std::vector<int> numbers;
	while (lines[0].size() != 0){
		int num = 0;
		for(int j = 0; j < numLines; ++j){
			if (lines[j][0] != ' '){
				num *= 10;
				num += char(lines[j][0]) - '0';
			}
			lines[j].erase(0,1);
		}
		std::cout << num << "\n";
		if (num == 0 || lines[0].size() == 0){
			if (lines[0].size() == 0){
				numbers.push_back(num);
			}
			std::cout << ops[i] << "\n";	
			if (ops[i] == "*"){
				long long int val = 1;
				for (int values : numbers){
					val *= values;
				}
				std::cout << val << "\n";
				answer += val;
			}
			else{
				long long int val = 0;
				for (int values : numbers){
					val += values;
				}
				std::cout << val << "\n";
				answer += val;
			}
			numbers = {};
			++i;
		}
		else{
			numbers.push_back(num);
		}
	}
	std::cout << answer << "\n";
}
