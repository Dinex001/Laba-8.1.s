#include <iostream>
#include <string>

using namespace std;

// Визначає довжину групи однакових символів, що починається з позиції pos.
//   s   - рядок, що аналізується
//   pos - позиція першого символу групи (pos < s.length())
// Повертає кількість однакових символів поспіль, починаючи з s[pos].
size_t CountSameChars(const string& s, size_t pos)
{
    size_t end = s.find_first_not_of(s[pos], pos);   // перший символ, відмінний від s[pos]

    if (end == string::npos)                         // група дійшла до кінця рядка
        end = s.length();

    return end - pos;
}

// Виясняє, чи є в рядку четвірка сусідніх однакових символів.
//   s - рядок, що аналізується
// Повертає true, якщо така четвірка є, інакше - false.
bool ContainsFourSame(const string& s)
{
    size_t pos = 0;                                  // pos - початок чергової групи
    while (pos < s.length())
    {
        size_t count = CountSameChars(s, pos);

        if (count >= 4)
            return true;

        pos += count;                                // переходимо до наступної групи
    }

    return false;
}

// Замінює кожну четвірку сусідніх однакових символів парою зірочок "**".
//   s - рядок, який змінюється (параметр-посилання)
// Повертає змінений рядок.
// Група з count однакових символів дає count / 4 пар "**" та count % 4 символів,
// що залишилися (з "aaaaa" буде "**a").
string Change(string& s)
{
    size_t pos = 0;
    while (pos < s.length())
    {
        size_t count = CountSameChars(s, pos);
        size_t pairs = count / 4;                    // кількість четвірок у групі
        size_t rest = count % 4;                     // символи, що не склали четвірку

        if (pairs > 0)
            s.replace(pos, pairs * 4, pairs * 2, '*');   // чотири символи -> "**"

        pos += pairs * 2 + rest;                     // переходимо до наступної групи
    }

    return s;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    if (ContainsFourSame(str))
        cout << "String contains four identical adjacent characters" << endl;
    else
        cout << "String does not contain four identical adjacent characters" << endl;

    string dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}