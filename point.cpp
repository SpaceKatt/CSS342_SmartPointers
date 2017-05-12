#include <iostream>
#include <ostream>
#include <string>

using std::string;
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
   * Deconstructor deallocates pointer.
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

  /*
   * Assigns new pointer, deallocates old one.
   */
  SmartPtr& reset(Object *rhs) {
    deletePtr();
    ptr = rhs;
  }

  /*
   * Overloads dereference operator, returns value pointed to by ptr.
   */
  Object operator*() {
    return *ptr;
  }

  /*
   * Overloads -> operator, allows use of referenced Object's methods.
   */
  Object* operator->() {
    return ptr;
  }

  /*
   * Overloads output operator, outputs memory address of Object
   */
  friend std::ostream& operator<<(std::ostream& ost,
                                  const SmartPtr<Object>& rat) {
    ost << rat.ptr;
    return ost;
  }
private:
  /* Normal pointer which becomes smart by wrapping it in class. */
  Object* ptr;
};

int main(int argc, char const *argv[]) {
  SmartPtr<int> point = SmartPtr<int>(new int(5));

  cout << "Overloaded ouput operator prints pointer address: " << point
       << endl;
  cout << "Overloaded dereference operator returns object: " << *point << endl;

  cout << endl << "Reassigning SmartPtr takes care of deallocating"
       << " old value..." << endl;

  cout << endl << "Assigning to dynamically allocated int = 7" << endl;

  point.reset(new int(7));
  cout << "New values: " << point << " and " << *point << endl;


  cout << endl << "Assigning to dynamically allocated string "
       << "= `Hello, Pointer`" << endl;

  SmartPtr<string> point2 = SmartPtr<string>(new string("Hello, Pointer!"));
  cout << "String address and value: " << point2 << " and " << *point2 << endl;

  cout << endl << "Using -> operator to grab replace `Pointer` with `World`..."
       << endl << "Output string: "
       << point2->replace(7, point2->length(), "World!") << endl;

  cout << endl << "At the end of a method, SmartPtr's deconstructor "
       << "deallocates object pointed to by ptr." << endl;

  return 0;
}
