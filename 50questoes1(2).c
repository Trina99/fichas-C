#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

void menu()
{
    printf("01. maior numero\n02. media da sequencia\n03. segundo maior\n04. bits a um\n05. ultimos bits a 0\n06. digitos necesarios\n07. concatena 2 strings\n08. copia string\n09. string compare\n10. string contida noutra\n11. string invertida\n12. string sem vogais\n13. string truncada\n14. char mais frequente\n15. iguais consecutivos\n16. diferentes consecutivos\n17. maior prefixo\n18. maior sufixo\n19.sufixo prefixo\n20. conta palavras\n");
}
//1.
int maior()
{
    int read, maior;
    printf("numeros:\n");
    scanf("%d", &read);
    maior = read;
    while (read != 0)
    {
        if (read > maior)
            maior = read;
        scanf("%d", &read);
    }
    printf("maior: %d\n", maior);
    return 0;
}

//2.
int media()
{
    int read, soma = 0, n = 0;
    float media;
    printf("numeros:\n");
    scanf("%d", &read);
    while (read != 0)
    {
        soma += read;
        n++;
        scanf("%d", &read);
    }
    media = (float)soma / n;
    printf("media: %f\n", media);
    return 0;
}

//3.
int segundoM()
{
    int read, fst, snd;
    printf("numeros:\n");
    scanf("%d", &read);
    fst = snd = read;
    while (read != 0)
    {
        if (read > fst)
        {
            snd = fst;
            fst = read;
        }

        else if (read > snd || snd == fst)
            snd = read;

        scanf("%d", &read);
    }
    printf("segundo maior: %d\n", snd);
    return 0;
}

//4.
int bitsUm(unsigned int n)
{
    int total;
    total = 0;
    while (n != 0)
    {
        if (n % 2 == 1)
            total++;
        n /= 2;
    }
    return total;
}

//5.
int trailingZ(unsigned int n)
{
    int bit = 0, stop = 0;
    while (stop == 0)
    {
        if (n % 2 == 1 || n == 0)
            stop = 1;
        else
            bit++;
        n /= 2;
    }
    return bit;
}

//6.
int qDig(unsigned int n)
{
    int d;
    for (d = 0; n != 0; d++)
        n /= 10;
    return d;
}

//7.
char *mystrcat(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i]; i++)
        ;
    for (j = 0; s2[j]; j++)
        s1[i + j] = s2[j];
    s1[i + j] = '\0';
    return s1;
}

//8.
char *mystrcpy(char *dest, char source[])
{
    int i;
    for (i = 0; source[i]; i++)
        *(dest + i) = source[i];
    *(dest + i) = '\0';
    return dest;
}

//9.
int mystrcmp(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] && s1[i] == s2[i]; i++)
        ;
    return s1[i] - s2[i];
}

//10.
char *mystrstr(char s1[], char s2[])
{
    int i, j;
    char *pos;
    pos = s1;
    for (i = 0, j = 0; s1[i] && s2[j]; i++)
    {
        if (s1[i] == s2[j++])
        {
            if (pos == NULL)
                pos = s1 + i;
        }
        else
        {
            j = 0;
            pos = NULL;
        }
    }
    if (s2[j])
        pos = NULL;
    return pos;
}

//11.
void strrev(char s[])
{
    int i, j;
    char tmp;
    for (j = 0; s[j]; j++)
        ;
    for (i = 0, j--; i < j; i++, j--)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

//12.
int isvowel(char a)
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
        return 1;
    return 0;
}

void strnoV(char s[])
{
    int i, j;
    for (i = 0, j = 0; s[i]; i++)
        if (!isvowel(s[i]))
            s[j++] = s[i];
    s[j] = '\0';
}

//13.
void truncW(char t[], int n)
{
    int i, j, x = 0;
    for (i = 0, j = 0; t[i]; i++)
    {
        if (t[i] == ' ')
        {
            x = 0;
            t[j++] = t[i];
        }
        else if (x < n)
        {
            t[j++] = t[i];
            x++;
        }
    }
    t[j] = '\0';
}

//14.
char charMaisfreq(char s[])
{
    int i, j, x = 0, n = 0;
    char ch = 0;
    for (i = 0; s[i]; i++)
    {
        for (j = i; s[j]; j++)
        {
            if (s[j] == s[i])
                n++;
        }
        if (n > x)
        {
            x = n;
            ch = s[i];
        }
        n = 0;
    }
    return ch;
}

//15.
int iguaisConsecutivos(char s[])
{
    int i, num = 1, max = 0;
    for (i = 0; s[i]; i++)
    {
        if (s[i] == s[i + 1])
            num++;
        else
        {
            if (num > max)
                max = num;
            num = 1;
        }
    }
    return max;
}

//16.
int difConsecutivos(char s[])
{
    int i, j, x, sum, sumA, sumB, ctr;
    sum = 0;
    for (x = 0; s[x]; x++)
    {
        ctr = 1;
        sumA = 0;
        for (i = x; s[i] && ctr; i++)
        {
            sumB = 1;
            for (j = x; j < i && ctr; j++)
            {
                if (s[j] == s[i])
                    ctr = 0;
                else
                    sumB++;
            }
            if (sumB > sumA)
                sumA = sumB;
        }
        if (sumA > sum)
            sum = sumA;
    }
    return sum;
}

//17.
int maiorPrefixo(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] && s1[i] == s2[i]; i++)
        ;
    return i;
}

//18.
int maiorSufixo(char s1[], char s2[])
{
    int i, j, r;
    for (i = 0; s1[i]; i++)
        ;
    for (j = 0; s2[j]; j++)
        ;
    for (r = -1; s1[i] == s2[j]; i--, j--)
        r++;
    return r;
}

//19.
int sufPref(char s1[], char s2[])
{
    int i, j = 0, s = 0;
    for (i = 0; s1[i]; i++)
    {
        if (s1[i] == s2[j++])
            s++;
        else
            s = j = 0;
    }
    return s;
}

//20.
int contaPal(char s[])
{
    int i, pal = 0, n = 0;
    for (i = 0; s[i]; i++)
    {
        if (s[i] == ' ' || s[i] == '\n')
            pal = 0;
        else
        {
            if (pal == 0)
            {
                n++;
                pal = 1;
            }
        }
    }
    return n;
}

//main
int main()
{
    int x;
    printf("pergunta: ");
    scanf("%d", &x);
    switch (x)
    {
    case 0:
    {
        menu();
        break;
    }
    case 1:
    {
        maior();
        break;
    }
    case 2:
    {
        media();
        break;
    }
    case 3:
    {
        segundoM();
        break;
    }
    case 4:
    {
        int bits, n;
        printf("escolhe um número: ");
        scanf("%d", &n);
        bits = bitsUm(n);
        printf("%d tem %d bits a um\n", n, bits);
        break;
    }
    case 5:
    {
        int bits, n;
        printf("escolhe um número: ");
        scanf("%d", &n);
        bits = trailingZ(n);
        printf("%d tem %d bits a 0 no final\n", n, bits);
        break;
    }
    case 6:
    {
        int dig, n;
        printf("escolhe um número: ");
        scanf("%d", &n);
        dig = qDig(n);
        printf("%d necessita de %d digitos\n", n, dig);
        break;
    }
    case 7:
    {
        char s1[30], s2[30];
        printf("string1: ");
        scanf("%s", s1);
        printf("+\nstrings2: ");
        scanf("%s", s2);
        *s1 = *mystrcat(s1, s2);
        printf("=\n%s\n", s1);
        break;
    }
    case 8:
    {
        char s1[30], s2[30];
        printf("string: ");
        scanf("%s", s1);
        *s2 = *mystrcpy(s2, s1);
        printf("string copy: %s\n", s2);
        break;
    }
    case 9:
    {
        int cmp;
        char s1[30], s2[30];
        printf("palavra1: ");
        scanf("%s", s1);
        printf("palavra2: ");
        scanf("%s", s2);
        cmp = mystrcmp(s1, s2);
        printf("%s - %s = %d\n", s1, s2, cmp);
        break;
    }
    case 10:
    {
        char s1[30], s2[30], s3[30];
        printf("string1: ");
        scanf("%s", s1);
        printf("string2: ");
        scanf("%s", s2);
        *s3 = *mystrstr(s1, s2);
        printf("%s ocorre em %s: %s\n", s2, s1, s3);
        break;
    }
    case 11:
    {
        char s[100];
        printf("string (espaços): ");
        getchar();
        fgets(s, 100, stdin);
        strrev(s);
        printf("string invertida: %s\n", s);
        break;
    }
    case 12:
    {
        char s[100];
        printf("string (espaços): ");
        getchar();
        fgets(s, 100, stdin);
        strnoV(s);
        printf("string sem vogais: %s", s);
        break;
    }
    case 13:
    {
        int lim;
        char s[100];
        printf("string (espaços): ");
        getchar();
        fgets(s, 100, stdin);
        printf("limite (numero): ");
        scanf("%d", &lim);
        truncW(s, lim);
        printf("string truncada: %s\n", s);
        break;
    }
    case 14:
    {
        char s[100], ch;
        printf("string (espaços): ");
        getchar();
        fgets(s, 100, stdin);
        ch = charMaisfreq(s);
        printf("char mais frequente: %c\n", ch);
        break;
    }
    case 15:
    {
        int ig;
        char s[100];
        printf("string (espaços): ");
        getchar();
        fgets(s, 100, stdin);
        ig = iguaisConsecutivos(s);
        printf("ha %d iguais consecutivos\n", ig);
        break;
    }
    case 16:
    {
        int dif;
        char s[100];
        printf("string (espaços): ");
        getchar();
        fgets(s, 100, stdin);
        dif = difConsecutivos(s);
        printf("ha %d diferentes consecutivos\n", dif);
        break;
    }
    case 17:
    {
        int m;
        char s1[30], s2[30];
        printf("string1: ");
        scanf("%s", s1);
        printf("string2: ");
        scanf("%s", s2);
        m = maiorPrefixo(s1, s2);
        printf("maior prefixo: %d\n", m);
        break;
    }
    case 18:
    {
        int m;
        char s1[30], s2[30];
        printf("string1: ");
        scanf("%s", s1);
        printf("string2: ");
        scanf("%s", s2);
        m = maiorSufixo(s1, s2);
        printf("maior sufixo: %d\n", m);
        break;
    }
    case 19:
    {
        int m;
        char s1[30], s2[30];
        printf("string1: ");
        scanf("%s", s1);
        printf("string2: ");
        scanf("%s", s2);
        m = sufPref(s1, s2);
        printf("sufixo do primeiro, prefixo do segundo: %d\n", m);
        break;
    }
    case 20:
    {
        int n;
        char s[100];
        printf("string (espaços): ");
        getchar();
        fgets(s, 100, stdin);
        n = contaPal(s);
        printf("tem %d palavras\n", n);
        break;
    }
    }
    return 0;
}
