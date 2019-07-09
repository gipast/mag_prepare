#include <stdio.h>

int is_num(char c){
  return ((c >= '0') && (c <= '9'));
}

int myfunk(char *line1, char *line2){
  int cnt = 0;
  int i, j;
  char c;

  char exists[10];
  for (i = 0; i < 10; i++){
    exists[i] = 0;
  }
  printf("line1 %s\n", line1);
  printf("line2 %s\n", line2);

  i = 0;
  while (line2[i] != '\0'){
    if (is_num(line2[i]))
      exists[line2[i] - '0'] = 1;
    i++;
  }
  i = 0;
  while (line1[i] != '\0'){
    c = line1[i];
    if (is_num(c)){
      if (exists[c - '0'] == 0){
        exists[c - '0'] = 255;
        cnt++;
      }
    }
    i++;
  }
  return cnt;
}


int main(int argc, char **argv) {
  char in_line[] = "a   11 22 33 44 55 666 000    d\0";
  char in_line2[] = "asdfgh 123 \0";

  int count = myfunk(in_line, in_line2);
  printf("res = %d\n", count);
  return 0;
}
