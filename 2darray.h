#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <array>

template <typename T>
class Array {
public:


	Array(int n, int m){
		mFlatVec.resize(n*m);
		mN = n;
		mM = m;
		mLen = m*n;
		mDefaultVal = T();
	}

	T& getRef(std::array<int,2> v){
		return &mFlatVec[idx(v)];
	}
	
	T operator[](std::array<int,2> v){
		int index = idx(v);
		if (index >= 0 && index < mN*mM){
			return mFlatVec[index];
		}
		else{
			return T();
		}
	}
private:
	std::vector<T> mFlatVec;
	int mN;
	int mM;
	int mLen;
	T mDefaultVal;
	int idx(std::array<int,2> v){
		return v[0]+mN*v[1];
	}

};

#endif
