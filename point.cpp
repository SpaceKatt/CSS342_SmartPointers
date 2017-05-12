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

  Object operator*() {
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
  cout << "Overloaded ouput operator prints pointer address: " << point << endl;
  cout << "Overloaded dereference operator returns object: " << *point << endl;
  cout << endl << "At the end of a method, SmartPtr deconstructor "
       << "deallocates object pointed to by ptr." << endl;

  return 0;
}
