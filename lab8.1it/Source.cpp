#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

#include <iostream>
#include <cstring>
using namespace std;

int Count(const char* str)
{
    int count = 0;                         // Лічильник груп сусідніх букв
    int length = strlen(str);              // Довжина вхідного рядка

    bool hasGroups = false;                // Прапорець, що позначає, чи є групи сусідніх букв

    for (int i = 0; i < length - 1; i++)    // Проходимо по рядку символ за символом, залишаючи останній символ
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') ||     // Перевіряємо, чи є поточний символ та наступний символ 'aa'
            (str[i] == 'b' && str[i + 1] == 'b') ||     // Перевіряємо, чи є поточний символ та наступний символ 'bb'
            (str[i] == 'c' && str[i + 1] == 'c'))       // Перевіряємо, чи є поточний символ та наступний символ 'cc'
        {
            hasGroups = true;               // Якщо знайдена група, встановлюємо прапорець на true
            count++;                        // Збільшуємо лічильник на одиницю
            break;                          // Перериваємо цикл, оскільки знайдена хоча б одна група
        }
    }

    if (!hasGroups) {
        cout << "Немає груп сусідніх букв." << endl;
    }

    return count;                           // Повертаємо кількість знайдених груп
}

char* Change(const char* str)
{
    int length = strlen(str);              // Довжина вхідного рядка
    char* result = new char[length * 3 + 1];         // Рядок, в якому зберігатиметься змінений рядок
    int resultIndex = 0;                    // Індекс для зміненого рядка

    for (int i = 0; i < length - 1; i++)    // Проходимо по рядку символ за символом, залишаючи останній символ
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') ||     // Перевіряємо, чи є поточний символ та наступний символ 'aa'
            (str[i] == 'b' && str[i + 1] == 'b') ||     // Перевіряємо, чи є поточний символ та наступний символ 'bb'
            (str[i] == 'c' && str[i + 1] == 'c'))       // Перевіряємо, чи є поточний символ та наступний символ 'cc'
        {
            result[resultIndex++] = '*';        // Додаємо '*' до зміненого рядка
            result[resultIndex++] = '*';        // Додаємо '*' до зміненого рядка
            result[resultIndex++] = '*';        // Додаємо '*' до зміненого рядка
            i++;                                // Пропускаємо наступний символ у вхідному рядку
        }
        else
        {
            result[resultIndex++] = str[i];     // Якщо групи не знайдено, додаємо поточний символ до зміненого рядка
        }
    }

    if (length > 0)
    {
        result[resultIndex++] = str[length - 1];    // Додаємо останній символ у змінений рядок
    }

    result[resultIndex] = '\0';              // Додаємо завершувальний символ '\0' до зміненого рядка

    return result;                          // Повертаємо зміненийРядок "Count" містить функцію `Count`, яка підраховує кількість груп сусідніх букв "aa", "bb" або "cc" у вхідному рядку. Рядок "Change" містить функцію `Change`, яка змінює кожну групу сусідніх букв "aa", "bb" або "cc" на трійку зірочок "***" у вхідному рядку. 

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_LENGTH = 101;
    char str[MAX_LENGTH];
    cout << "Enter string:" << endl;
    cin.getline(str, MAX_LENGTH);

    cout << "String contains " << Count(str) << " groups of 'aa', 'bb', or 'cc'" << endl;

    char* modifiedStr = Change(str);
    cout << "Modified string: " << modifiedStr << endl;

    delete[] modifiedStr;

    return 0;
}