#ifndef RANGES_H
#define RANGES_H

#include <algorithm>


template <typename T>
class Ranges{
public:
        T mL;
        T mR;
        Ranges<T>* mLeft;
        Ranges<T>* mRight;

	Ranges(T l, T r,Ranges<T>* leftChild = nullptr,Ranges<T>* rightChild = nullptr) : mL {l}, mR {r}, mLeft {leftChild}, mRight {rightChild} {
	std::cout << mL << " " << mR << "\n";
	}
	Ranges(std::array<T,2> a) : mL{a[0]}, mR {a[1]} {
std::cout << mL << " " << mR << "\n";
	}
	void insert(T l, T r){
		if (l > mR +1){
			if (mRight == nullptr){
				mRight = new Ranges(l,r);		
			}
			else{
				mRight->insert(l, r);
			}
		}
		else if (r < mL -1){
			if (mLeft == nullptr){
				mLeft = new Ranges(l,r);
			}
			else{
				mLeft->insert(l, r);
			}
		}
		
		else{
			mL = std::min(l,mL);
			mR = std::max(r,mR);
			rectify();
		}
	}
	void insert(std::array<T,2> a){
		insert(a[0],a[1]);
	}
	void rectify(){
		if (mLeft != nullptr){
			if (mLeft->mR >= mL -1){
				mL = std::min(mL,mLeft->mL);
				mLeft = mLeft->mLeft;
				if (mLeft != nullptr){
					mLeft->rectify();
				}
			}
		}
	
               if (mRight != nullptr){
                        if (mRight->mL <= mR +1){
                                mR = std::max(mR,mRight->mR);
				mRight = mRight->mRight;
				if (mRight != nullptr){
					mRight->rectify();
				}
                        }
                }
	}
	
	bool contains(T x){
		if (x >= mL && x <= mR){
			return true;
		}
		else if (x < mL){
			if (mLeft == nullptr){
				return false;
			}
			else{
				return mLeft->contains(x);
			}
		}
		else if (x > mR){
			if (mRight == nullptr){
				return false;
			}
			else{
				return mRight->contains(x);
			}
		}
	}

	T size(){
		T num = mR - mL + 1;
		if (mRight != nullptr){
			num += mRight->size();
		}
		if (mLeft != nullptr){
			num += mLeft->size();
		}
		return num;
	}

};

#endif
