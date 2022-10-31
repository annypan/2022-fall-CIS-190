#include <iostream>
#include <thread>
#include <queue>
#include <condition_variable> 
#include <semaphore>
#include <mutex> 

using namespace std;

queue<int> q;
mutex m;
condition_variable cond;


void producer(int initial)
{ 
    for (int i {initial};; ++i)
    {
        this_thread::sleep_for(1s);
        // unique_lock lock {sm};
        q.push(i);
        if (q.size() >= 2) 
        {
            cond.notify_all();
        }
    }
}

void adder()
{
    while (true)
    {
        unique_lock lock {m};
        while (q.size() < 2)
        {
            cond.wait(lock);
        }
        int a {q.front()};
        q.pop();
        int b {q.front()};
        q.pop();
        cerr << a + b << "\n";
    }
}

int main()
{
    thread p1 {producer, 0};
    thread p2 {producer, 2};

    thread c1 {adder};
    thread c2 {adder};
}
