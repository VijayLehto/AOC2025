#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>


std::array<long long int,3> process(std::string t){
	std::array<long long int,3> arr;
	std::stringstream ss(t);
	std::string temp;
	std::getline(ss,temp,',');
	arr[0] = stoll(temp);
	std::getline(ss,temp,',');
	arr[1] = stoll(temp);
	std::getline(ss,temp,',');
	arr[2] = stoll(temp);
	
	return arr;
}

long long int square_dist(std::array<long long int,3> vec1, std::array<long long int,3> vec2){
	long long int ans = 0;
	for (int i = 0; i < 3; ++i){
		ans += (vec1[i]-vec2[i]) * (vec1[i] - vec2[i]);
	}
	return ans;
}

std::set<long long int> removeSet(std::vector<std::set<long long int>>& sets,int val){
	for(int i = 0; i < sets.size(); ++i){
		if (sets[i].find(val) != sets[i].end()){
			std::set<long long int> returnVal = sets[i];
			sets.erase(sets.begin()+i);
			return returnVal;
		}
	}
	return {val};
}

bool comp(std::array<long long int,3> vec1, std::array<long long int,3> vec2){ return (vec1[0] < vec2[0]);}
bool compSet(std::set<long long int> set1, std::set<long long int> set2){return set1.size() > set2.size();}


int main(){
	std::ifstream file("input08.txt");
	std::string t;
	std::vector<std::array<long long int,3>> points;
	
	while (std::getline(file, t)){
		points.emplace_back(process(t));
	}
	
	std::vector<std::set<long long int>> circuits;
	for(int i = 0; i < points.size(); ++i){
		circuits.push_back({i});
	}
	std::vector<std::array<long long int,3>> connections;
	for(int i = 0; i < points.size() - 1; ++i){
		for(int j = i+1; j < points.size(); ++j){
			connections.push_back({square_dist(points[i],points[j]),i,j});
		}
	}
	
	std::sort(connections.begin(), connections.end(), comp);
	int node1;
	int node2;
	int i = 0;
	while (circuits.size() != 1){
		std::array<long long int,3> connection = connections[i];
		std::cout << connection[0] << " " << connection[1] << " " << connection [2] << "\n";
		node1 = connection[1];
		node2 = connection[2];
		
		std::set<long long int> set1 = removeSet(circuits,node1);
		std::set<long long int> set2 = removeSet(circuits,node2);
		std::set<long long int> setUnion;
		std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(setUnion, setUnion.begin()));
		std::cout << set1.size() << " " << set2.size() << " " <<  setUnion.size() << "\n";
		circuits.push_back(setUnion);
		++i;
	}

	std::sort(circuits.begin(),circuits.end(), compSet);
	int k = 0;
	for(auto i : circuits){
		std::cout << i.size() << "\n";
		for(auto j : i){
			++k;
			std::cout << j << " ";
		}
		std::cout << "\n";
	}
	std::cout << points[node1][0]*points[node2][0];
	
	return 0;
}
