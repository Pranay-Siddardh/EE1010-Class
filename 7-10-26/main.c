#include <stdio.h>

char s[6];
int count = 0;

void generate(int pos, int has_pair)
{
    if (pos == 5) {
        if (has_pair) {
            s[5] = '\0';
            printf("%s\n", s);
            count++;
        }
        return;
    }

    for (char ch = 'a'; ch <= 'c'; ch++) {
        s[pos] = ch;
        int pair = has_pair || (pos > 0 && s[pos - 1] == ch);
        generate(pos + 1, pair);
    }
}

int main(void)
{
    generate(0, 0);
    printf("Total = %d\n", count);
    return 0;
}
