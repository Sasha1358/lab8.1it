#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

#include <iostream>
#include <cstring>
using namespace std;

int Count(const char* str)
{
    int count = 0;                         // ˳������� ���� ������ ����
    int length = strlen(str);              // ������� �������� �����

    bool hasGroups = false;                // ���������, �� �������, �� � ����� ������ ����

    for (int i = 0; i < length - 1; i++)    // ��������� �� ����� ������ �� ��������, ��������� ������� ������
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') ||     // ����������, �� � �������� ������ �� ��������� ������ 'aa'
            (str[i] == 'b' && str[i + 1] == 'b') ||     // ����������, �� � �������� ������ �� ��������� ������ 'bb'
            (str[i] == 'c' && str[i + 1] == 'c'))       // ����������, �� � �������� ������ �� ��������� ������ 'cc'
        {
            hasGroups = true;               // ���� �������� �����, ������������ ��������� �� true
            count++;                        // �������� �������� �� �������
            break;                          // ���������� ����, ������� �������� ���� � ���� �����
        }
    }

    if (!hasGroups) {
        cout << "���� ���� ������ ����." << endl;
    }

    return count;                           // ��������� ������� ��������� ����
}

char* Change(const char* str)
{
    int length = strlen(str);              // ������� �������� �����
    char* result = new char[length * 3 + 1];         // �����, � ����� �������������� ������� �����
    int resultIndex = 0;                    // ������ ��� �������� �����

    for (int i = 0; i < length - 1; i++)    // ��������� �� ����� ������ �� ��������, ��������� ������� ������
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') ||     // ����������, �� � �������� ������ �� ��������� ������ 'aa'
            (str[i] == 'b' && str[i + 1] == 'b') ||     // ����������, �� � �������� ������ �� ��������� ������ 'bb'
            (str[i] == 'c' && str[i + 1] == 'c'))       // ����������, �� � �������� ������ �� ��������� ������ 'cc'
        {
            result[resultIndex++] = '*';        // ������ '*' �� �������� �����
            result[resultIndex++] = '*';        // ������ '*' �� �������� �����
            result[resultIndex++] = '*';        // ������ '*' �� �������� �����
            i++;                                // ���������� ��������� ������ � �������� �����
        }
        else
        {
            result[resultIndex++] = str[i];     // ���� ����� �� ��������, ������ �������� ������ �� �������� �����
        }
    }

    if (length > 0)
    {
        result[resultIndex++] = str[length - 1];    // ������ ������� ������ � ������� �����
    }

    result[resultIndex] = '\0';              // ������ �������������� ������ '\0' �� �������� �����

    return result;                          // ��������� ������������ "Count" ������ ������� `Count`, ��� �������� ������� ���� ������ ���� "aa", "bb" ��� "cc" � �������� �����. ����� "Change" ������ ������� `Change`, ��� ����� ����� ����� ������ ���� "aa", "bb" ��� "cc" �� ����� ������ "***" � �������� �����. 

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