#include <stdio.h>
#include <string.h>
 
int WordCount(char str[], int length)
{
	int a=0, b=1;
    int word = (str[0]!= ' ');
    for (int i = 0; i < length - 1; i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ')
        {
            word++;
        }
    }
    return word;
}
 
void Correct(char str[], int length)
{
    int first = 0, last = length - 1;
    // X�a d?u tr?ng d?u chu?i
    while (first < last && str[first] == ' ')
        first++;
    // X�a d?u tr?ng cu?i chu?i
    while (last > first && str[last] == ' ')
        last--;
 
    // Vi?t hoa ch? c�i d?u ti�n
    if (str[first] >= 'a' && str[first] <= 'z'){
        str[first] -= 32;
	}
    for (int i = first; i <= last; i++)
    {
        // �ua h?t v? ch? thu?ng
        if (i!=0 && str[i-1] != ' ' && str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 32;
        }
        if (i + 1 <= last)
        {
            // B? d?u tr?ng th?a ? gi?a
            if (str[i] == str[i + 1] && str[i] == ' ')
            {
                continue;
            }
            // N?u l� ch? c�i d?u m?i t? th� vi?t hoa
            if (str[i] == ' ' && str[i + 1] >= 'a' && str[i + 1] <= 'z')
            {
                str[i + 1] -= 32;
            }
        }
        printf("%c", str[i]);
    }
}
 
int main()
{
    char str[100];
    // Nh?p chu?i
    printf("\nNhap chuoi: ");
    fgets(str, sizeof str, stdin);
    // Do s? d?ng fgets n�n chu?i c?a ch�ng ta s? d?c c? k� t? '\n'.
    // X�a b? n� di.
    int length = strlen(str) - 1; 
    str[length] = '\0';
    printf("So tu cua \"%s\" la %d", str, WordCount(str, length));
    printf("\nXau chuan hoa la: ");
    Correct(str, length);
}
