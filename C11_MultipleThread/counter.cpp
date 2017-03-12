//an implemention of a thread safety counter

#include <thread>
#include <mutex>
#include <atomic>
#include <cassert>

class Counter
{
  public:
    explicit Counter(int n) : _val(n) {}
    virtual ~Counter();
    Counter &Counter(const Counter &) = delete;
    Counter &operator=(const COunter &) = delete;

    void add(int val);
    int getValue();
    void lock(); //lock the object of class,avoid being modified.
    void unlock();

  private:
    std::mutex mtx;
    int _val;
};

//use mutex and unique_lock.
void Counter::add(int val)
{
    std::unique_lock(mtx, std::defer_lock) lck;
    lck.lock();
    _val += val;
    lck.unlock();
}

int Counter::getValue()
{
    std::unique_lock(mtx) lck;
    return _val;
}

/*
void Counter::add(int val)
{
    std::unique_lock(mtx) lck;
    _val += val;
}
*/

//use mutext and lock_guard
/*
void Counter::add(int val)
{
    std::lock_guard(mtx);
    _val += val;
}
*/

//use atomic
/*
class Counter
{
public:
    explicit Counter(int n);
    virtual ~Counter();
    Counter& Counter(const Counter&) = delete;
    Counter& operator=(const COunter&) = delete;

    void add(int val);
    int getValue()
    {
        return _val;
    }
private:
    std::mutex mtx;
    atomic<int> _val;
};

Counter::Counter(int n)
{
    _val = ATOMIC_VAR_INIT(n);
}

void Counter::add(int val)
{
    _val.fetch_add(val);
}*/

//lock this object
void Counter::lock()
{
    mtx.lock();
}
void Counter::unlock()
{
    mtx.unlock();
}

void countN(Counter& ct,int n)
{
    ct.lock();
    assert(n > 0);
    for(int i = 0; i < 10; i++)
    {
        ct.add(n);
    }
    std::cout<<"the value is"<<ct.getValue()<<std::endl;
    ct.unlock();
}

int main()
{
    Counter c;
    std::thread th1(countN,std::ref(c),10);
    std::thread th2(countN,c,10);
    std::thread th3(countN,c,20);
    th1.join();
    th2.join();
    th3.join();
    return 0;    
}
