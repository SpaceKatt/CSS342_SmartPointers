#include <iostream>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;

template<class Object>
class SmartPtr {
public:
  SmartPtr () {
    ptr = NULL;
  }

  ~SmartPtr() {
    delete ptr;
    ptr = NULL;
  }

  const SmartPtr& operator=(const SmartPtr &rhs) {
    ptr = rhs.prt;
  }

  const SmartPtr& operator=(Object *rhs) {
    ptr = rhs;
  }

  Object operator*() { //const SmartPtr<object>& rhs) {
    return *ptr;
  }

  friend std::ostream& operator<<(std::ostream& ost, const SmartPtr<Object>& rat) {
    ost << rat.ptr;
    return ost;
  }
private:
  Object* ptr;
};

int main(int argc, char const *argv[]) {
  SmartPtr<int> point;
  point = new int(5);
  cout << point << " " << *point << endl;

  return 0;
}
