#import <iostream>
#import <fstream>
#import <vector>
#import <string>
#import <sstream>
#import "ranges.h"

std::array<long long int,2> toPair(std::string range){
	std::stringstream ss(range);
	std::string string1;
	std::string string2;
	std::getline(ss,string1,'-');
	std::getline(ss,string2, '-');
	return {std::stoll(string1),std::stoll(string2)};
}

int main(){


	std::ifstream file("test.txt");
	std::string temp;
	std::getline(file,temp);
	
	
	Ranges<long long int> interval(toPair(temp));
	while (std::getline(file,temp)){
		if (temp == ""){
			break;	
		}
		interval.insert(toPair(temp));
	}
	int answer = 0;
	while(std::getline(file,temp)){
		std::cout << temp << " " << interval.contains(std::stoll(temp)) << "\n";
		answer += interval.contains(std::stoll(temp));
	}
	std::cout << answer << " " << interval.size();
	return 0;
}
