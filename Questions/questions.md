- What is the purpose of a forward declaration?

The purpose of a forward declaration is to be able to use a script methods and variables without the issue of circular dependencies, in the case that both script need each other

- What are the differences between the stack and the heap?

The stack is where the code is executed, with every function being added on top and removed when fully executed.
The heap is where all the address are stocked.

- What is the difference between a variable passed by copy, by reference or by pointer?

A variable passed by a copy will create a copy that will exist only in the function, every modification on it will not apply to the original.
The one passed by a reference will keep every modification on it that is made in the function, it create a local variable for the function and apply it at the end.
And the one passed by a pointer access the base variable with it address, so every modification made is apply to the base variable.

- What is a pure virtual class?

A pure virtual class is a class that contain virtual methods, mainly use to be able to override the class and it's function 

- What are the different phases of the compilation process?


- What is a smart-pointer? What problem do they solve? What problem do they bring?

A smart pointer is a pointer that automatically clean itself when it is no longer use, the issue is that if we need it again later, we can have a nullptr

- What is the problem that multi-threading try to solve?

The problem multi threading try to solve is to have the full program run on one thread, which is not the most optimize way.
Multi threading allow to do multiple computation at the same time on other thread, synchronous or asynchronously.

- Give at least two synchronization types that are used by multi-threading programs? What are their purpose?

There are asynchronous one, that run parallel to the main thread and can be use to load texture for example.
And synchronize one, that run parallel to the main thread, but are dependant from the execution, like to compute physics in the update part and only in the update.

- What is a Spin Lock?

A spin lock is a case where the thread enter an infinite loop and can't exit it.

- What is a Dead Lock?

A dead lock is when a variable is locked behind a mutex, and the thread wait for it to be unlock, but in the case it is never unlock.

- What does the following code display?
```cpp
int x = 10;
int* p = &x;
*p = 20;
std::cout << x << std::endl;
```



- What is the following code output?
```cpp
int* p = nullptr;
*p = 5;
std::cout << p << std::endl;
```


- What does the following code display?
```cpp
class A {
public:
    virtual void f() { std::cout << "A"; }
};

class B : public A {
public:
    void f() override { std::cout << "B"; }
};

A* obj = new B();
obj->f();
``` 

The code display : B

- Does that code works?
```cpp
class A {
public:
    virtual void f() = 0
};

class B : public A {
public:
    void f() override { std::cout << "B"; }
};

A a;
a->f();

A* b = new B;
b->f();
``` 
The code don't work, A is made as an interface, it can't run code on it's own with 'A a; a->f()', and for 'A* b = new B' it should be 'B* b = new B()'

- What is the number of loop that program will execute?
``` cpp
unsigned char nbHalfLoop = 200;
for (unsigned char id = 0; id < 2 * nbHalfLoop; id++)
{
cout << id;
}
```

It will run infinitely because unsigned char maximum capacity is 255, when it reaches 256 it reset to 0

- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data;

for (int i = 0; i < 100000; i++) {
    data.Add(i);
}

bool exists(int value) {
    for (int x : data) {
        if (x == value) return true;
    }
    return false;
}
```
An std::vector, so it can contain every int, and then we check if a value exist in it by iterating every int in the vector.

- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data = { 1, 2, 3, 4, 5 };

// ...

data.Insert(data.begin(), 0);
```

an array should be use, because we define a small amount of data

- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data;

void add(int x) {
    for (int v : data) {
        if (v == x) return;
    }
    data.Add(x);
}
```

