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

	void setVal(std::array<int,2> v,T x){
		mFlatVec[idx(v)] = x;
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
		if (v[0] < 0 || v[0] >= mN || v[1] < 0 || v[1] >=mM){
			return -1;
		}
		return v[0]+mN*v[1];
	}

};

#endif
