#include <iostream>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;

template<class Object>
class SmartPtr {
public:
  /*
   * Constructor sets ptr to NULL
   */
  SmartPtr () {
    ptr = NULL;
  }

  /*
   * Constructor sets ptr to pointer argument, which may be a
   * dynamically allocated object.
   */
  SmartPtr (Object *obj) {
    ptr = obj;
  }

  /*
   * Deconstructor deallocates pointer
   */
  ~SmartPtr() {
    delete ptr;
    ptr = NULL;
  }

  /*
   * Method which performs pointer deletion.
   */
  void deletePtr() {
    delete ptr;
    ptr = NULL;
  }

  const SmartPtr& operator=(const SmartPtr &rhs) {
    deletePtr();
    ptr = rhs.prt;
  }

  const SmartPtr& operator=(Object *rhs) {
    deletePtr();
    ptr = rhs;
  }

  Object operator*() {
    return *ptr;
  }

  friend std::ostream& operator<<(std::ostream& ost,
                                  const SmartPtr<Object>& rat) {
    ost << rat.ptr;
    return ost;
  }
private:
  Object* ptr;
};

int main(int argc, char const *argv[]) {
  SmartPtr<int> point = SmartPtr<int>(new int(5));

  cout << "Overloaded ouput operator prints pointer address: " << point << endl;
  cout << "Overloaded dereference operator returns object: " << *point << endl;

  cout << endl << "Reassigning SmartPtr takes care of deallocating"
       << " old value..." << endl;

  cout << endl << "Assigning to dynamically allocated int = 7" << endl;
  point = new int(7);

  cout << "New values: " << point << " and " << *point << endl;

  cout << endl << "At the end of a method, SmartPtr deconstructor "
       << "deallocates object pointed to by ptr." << endl;

  return 0;
}
