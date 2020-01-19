#ifndef CLASS_SHARED_PTR
#define CLASS_SHARED_PTR

template <class T>
class shared_ptr
{
private:
    T *_value;
    int *_counter;

public:
    shared_ptr(T *value = nullptr)
    {
        _value = value;
        _counter = new int(1);
    }

    ~shared_ptr()
    {
        if (!--*_counter)
        {
            delete _value;
        }
    }

    T *operator->()
    {
        return _value;
    }
};

#endif
