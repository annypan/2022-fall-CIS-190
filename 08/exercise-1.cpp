 #include <future> 
 #include <iostream> 
 #include <chrono> 

using namespace std;

unsigned int f()
{
    unsigned int sum = 0;
    for (int i = 0; i < 50000000; ++i)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    auto res1 {async(f)};
    auto res2 {f()};
    cout << res1.get() + res2 << endl;
}