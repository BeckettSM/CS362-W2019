#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
  // TODO: rewrite this function
  switch (rand() % 9)
  {
    case 0:
      return '[';
    case 1:
      return '(';
    case 2:
      return '{';
    case 3:
      return ' ';
    case 4:
      return 'a';
    case 5:
      return 'x';
    case 6:
      return '}';
    case 7:
      return ')';
    case 8:
      return ']';
  }
}

char *inputString()
{
  // TODO: rewrite this function
  char domain[6] = {'r','e','s','e','t','\0'};
  char str[6];
  int i;
  int num;

  for (i = 0; i < 5; i++)
  {
    num = (rand() % 6);

    if (num == 1)
    {  str[i] = domain[0];  }
    if (num == 2)
    {  str[i] = domain[1];  }
    if (num == 3)
    {  str[i] = domain[2];  }
    if (num == 4)
    {  str[i] = domain[3];  }
    if (num == 5)
    {  str[i] = domain[4];  }
  }

  str[5] = domain[5];
  return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0)
    {  state = 1;  }
    if (c == '(' && state == 1)
    {  state = 2;  }
    if (c == '{' && state == 2)
    {  state = 3;  }
    if (c == ' '&& state == 3)
    {  state = 4;  }
    if (c == 'a' && state == 4)
    {  state = 5;  }
    if (c == 'x' && state == 5)
    {  state = 6;  }
    if (c == '}' && state == 6)
    {  state = 7;  }
    if (c == ')' && state == 7)
    {  state = 8;  }
    if (c == ']' && state == 8)
    {  state = 9;  }
    if (s[0]  == 'r'  &&
        s[1]  == 'e'  &&
        s[2]  == 's'  &&
        s[3]  == 'e'  &&
        s[4]  == 't'  &&
        s[5]  == '\0' &&
        state == 9)
        {
          printf("error ");
          exit(200);
        }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
