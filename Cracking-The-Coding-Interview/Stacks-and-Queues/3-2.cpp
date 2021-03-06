// How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop
// and min should all operate in O(1) time.

#include<iostream>
#include<stack>
#include<climits>
using namespace std;

class stackWithMin {
private:
  stack<int> s1, s2;

public:
  int min() {
    if(s2.empty()) {
      return INT_MAX;
    }
    return s2.top();
  }

  void push(int x) {
    s1.push(x);
    if(min() >= x) {
      s2.push(x);
    }
  }

  void pop() {
    if(min() == s1.top()) {
      s2.pop();
    }
    s1.pop();
  }

  int top() {
    return s1.top();
  }
};

int main(){
	stackWithMin myStack;
	int arr[] = {6, 3, 5, 2, 2, 9, 2, 8, 1, 1};
	for(int i=0; i<10; i++){
		myStack.push(arr[i]);
		cout<<arr[i]<<" "<<myStack.min()<<'\n';
	}
	for(int i=0; i<10; i++){
		myStack.pop();
		cout<<i<<" "<<myStack.min()<<'\n';
	}
	return 0;
}
