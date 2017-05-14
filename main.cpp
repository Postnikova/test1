#include <QCoreApplication>
#include <windows.h>
#include <iostream>
#include <thread>

using namespace std;
 void foo(int n)
 {
     for (int i = 0; i < 5; i++)
     {
         cout << "Is foo " << n << " = " << this_thread::get_id() << endl;
         Sleep(700);
     }
 }
 void bar(int n)
 {
     for (int i = 0; i < 5; i++)
     {
         cout << "Is bar " << n << " = " << this_thread::get_id() << endl;
         Sleep(700);
     }
 }

int main(int argc, char *argv[])
{
    cout << "max count of threads " << thread::hardware_concurrency() << endl;

    thread t1 (foo, 1);
    thread t2 (bar, 2);
    //присоединяет к основному потоку
    //если поток еще не завершился или не присоединен к main
    //если поток уже завершился или не присоединен к main , то вернет false
    if (t1.joinable())
        t1.join();
    //теряем контрооль над t2
    t2.detach();
    system("pause");
    QCoreApplication a(argc, argv);

    return a.exec();
}
