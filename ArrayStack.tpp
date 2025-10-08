template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    buffer = new T[i];
    maxSize = i;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    this->length = 0;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    buffer = new T[copyObj.getMaxSize()];
    for (int i = 0; i < copyObj.getLength(); i++) {
        buffer[i] = copyObj.buffer[i];
    }
    maxSize = copyObj.getLength();
    this->length = copyObj.getLength();
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    if (this->length == 0) {
        throw string("peek: error, stack is empty, cannot access the top");
    } else {
        return buffer[this->length - 1];
    }
}

template <typename T>
void ArrayStack<T>::pop() {
    if (this->length == 0) {
        throw string("pop: error, stack is empty, avoiding underflow");
    } else {
        this->length--;
    }
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    if (isFull()) {
        throw string("push: error, stack is full, avoiding overflow");
    } else {
        buffer[this->length] = elem;
        this->length++;
    }
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}

