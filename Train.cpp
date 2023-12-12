#include <string>
#include <iostream>
#include "Train.h"

using namespace std;

// конструктор по умолчанию
Train::Train()
{
    this->destination = "None";
    this->train_number = "None";
    this->departure_time = "None";

    cout << "Vizvan konstructor po umolchaniyu classa Train" << endl;
}

// конструктор с параметром
Train::Train(string destination, string train_number, string departure_time)
{
    this->destination = destination;
    this->train_number = train_number;
    this->departure_time = departure_time;

    cout << "Vizvan konstructor s parametrom classa Train" << endl;
}

// конструктор копирования
Train::Train(const Train &t)
{
    this->destination = t.destination;
    this->train_number = t.train_number;
    this->departure_time = t.departure_time;

    cout << "Vizvan konstructor kopirovaniya classa Train" << endl;
}

// деструктор
Train::~Train()
{
    cout << "Vizvan destructor classa Train" << endl;
}

// метод извлечения полей
void Train::Extract()
{
    cout << *this;
}

// метод получения полей
void Train::Get()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice; // переменная выбора поля
    cout << "\nChto hotite poluchit\n" <<
                "1 - Punkt naznacheniya\n" <<
                "2 - Nomer poezda\n" <<
                "3 - Vremya otpravleniya\n" <<
                "4 - Vse polya" << endl;
    cout << "Choice: ";
    cin >> choice; // ввод

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Neverniy vvod" << endl;
    }

    if (choice == "1") cout << "Punct naznacheniya: " << this->destination << endl;
    else if (choice == "2") cout << "Nomer poezda: " << this->train_number << endl;
    else if (choice == "3") cout << "Vremya otpravleniya: " << this->departure_time << endl;
    else if (choice == "4") cout << "Punct naznacheniya: " << this->destination << " | Номер поезда: " << this->train_number << " | Время отправления: " << this->departure_time << endl;
    else
    {
        cout << "Oshibka vibora" << endl;
        exit(0);
    }
}

// метод получения поля времени (для сортировки)
string Train::GetTime()
{
    return this->departure_time;
}

// метод получения пункта назначения
string Train::GetDestination()
{
    return this->destination;
}

// метод получения номера поезда
string Train::GetTrainNumber()
{
    return this->train_number;
}

// метод установки значения
void Train::Set()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    cin >> *this;
}

void Train::Change()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nChto hotite izmenit\n" <<
                "1 - Punct naznacheniya\n" <<
                "2 - Nomer poezda\n" <<
                "3 - Vremya otpravleniya" << endl;
    cout << "Choice: ";
    cin >> choice;

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Neverniy vvod" << endl;
    }

    if (choice == "1")
    {
        getline(cin, choice);

        cout << "Punct naznacheniya: ";
        getline(cin, this->destination);
    }

    else if (choice == "2")
    {
        getline(cin, choice);

        cout << "Nomer poezda: ";
        getline(cin, this->train_number);
    }

    else if (choice == "3")
    {
        getline(cin, choice);

        cout << "Vremya otpravleniya: ";
        getline(cin, this->departure_time);
    }

    else
    {
        cout << "Oshibka vibora" << endl;
        exit(0);
    }
}

// перегрузка оператора вывода
std::ostream &operator<< (std::ostream &stream, Train &t) // перегрузка оператора извлеченния
{
    stream << "\nVse polya classa:" << endl;
    stream << t.destination << endl;
    stream << t.train_number << endl;
    stream << t.departure_time << endl;

    return stream;
}

// перегрузка оператора ввода
std::istream &operator>> (std::istream &stream, Train &t) // перегрузка оператора вставки
{
    string buf;

    cout << "\nVstavka znacheniy:" << endl;
    cout << "Punct naznacheniya: ";
    getline(stream, buf);
    t.destination = buf;

    cout << "Nomer poezda: ";
    getline(stream, buf);
    t.train_number = buf;

    cout << "Vremya otpravleniya: ";
    getline(stream, buf);
    t.departure_time = buf;

    return stream;
}
