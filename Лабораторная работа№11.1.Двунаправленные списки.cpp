#include <iostream>
#include <list>
#include <iterator>
using namespace std;
list <double> List2;
list<double> ListSTL;

struct List1
{
    double info;
    List1* next;
    List1* prev;
};

List1* Vvod1(int n1)
{
    List1* first,*a;
    a = new List1;
    first = NULL;
    cout << "Введите 1 элемент: ";
    cin >> a->info;
    first = a;
    a->next = NULL;
    a->prev = NULL;
    for (int i = 2; i <= n1; i++)
    {
        List1* b = new List1;
        List1* c = a;
        a->next = b;
        a = a->next;
        cout << "Введите " << i << " элемент: ";
        cin >> a->info;
        a->next = NULL;
        a->prev = c;
    }
    return first;
}

void Print1(List1*first)
{
    if (first == NULL)
    {
        cout << "Список пустой.";
    }
    else
    {
        List1* a = first;
        while (a != NULL)
        {
            cout << a->info<<"\t";
            a = a->next;
        }
        cout << endl;
    }
}


void Deleting1(List1*&first,int n1)
{
    List1* a = first;
    while (a!= NULL)
    {
        if (a->info < 0 )
        {            
            if (a->prev != NULL)
                a->prev->next = a->next;
            if (a->next != NULL)
                a->next->prev = a->prev;
            if (a->prev == NULL) 
                first = a->next;
        }
        a = a->next;
    }
}

void Vvod2(int n2)
{
    double a;
    for (int i = 0; i < n2; i++)
    {
        cout << "Введите " << i + 1 << " элемент: ";
        cin >> a;
        List2.push_back(a);
    }
}

void Deleting2(int n2)
{
    for (int i = 0; i < n2; i++)
    {
        if (List2.front() >= 0)
        {
            ListSTL.push_back(List2.front());
        }
        List2.pop_front();
    }
}

int main()
{
    setlocale(0, "");
    system("color F0");

    cout << "РЕАЛИЗАЦИЯ ЧЕРЕЗ СТРУКТУРЫ: "<<endl;

    int n1 = 0;
    while (n1 <= 0)
    {
        cout << "Введите размер списка: ";
        cin >> n1;
    }

    List1*list= Vvod1(n1);

    cout << "Начальный список: ";
    Print1(list);

    Deleting1(list,n1);

    cout << "Итоговый список: ";
    Print1(list);


    /////////////////////////////////////////////////////////////////


    cout << "РЕАЛИЗАЦИИ ЧЕРЕЗ БИБЛИОТЕКИ STL: " << endl;

    int n2 = 0;
    while (n2 <= 0)
    {
        cout << "Введите размер списка: ";
        cin >> n2;
    }

    Vvod2(n2);

    cout << "Начальный список: ";
    copy(List2.begin(),List2.end(),ostream_iterator<double>(cout,"\t"));
    cout << endl;

    Deleting2(n2);

    cout << "Итоговый список: ";
    copy(ListSTL.begin(), ListSTL.end(), ostream_iterator<double>(cout, "\t"));

    return 0;
}
