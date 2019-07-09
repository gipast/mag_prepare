#include <stdio.h>

// int my_strlen(char *line){
//   int len = 0;
//   while (line[len] != '\0')
//     len++;
//   return len;
// }

void reduce_string(char *line){
  int i = 0;
  int k = 0;
  int j;
  char c;
  while (line[i] != '\0'){
    c = line[i];
    // printf("c: %s k: %d, char: %c\n", line, k, c);
    for(j = 0; j < k; j++){
      if (line[j] == c)
        break;
    }
    if (j == k){
      line[k] = c;
      k++;
    }
    i++;
  }
  line[k] = '\0';
}

int myfunk(char *line1, char *line2){
  int cnt = 0;
  int j, i = 0;

  char c;
  reduce_string(line2);

  while (line1[i] != '\0'){
    c = line1[i];
    j = 0;
    while (line2[j] != '\0') {
      if (c == line2[j]){
        break;
      }
      j++;
    }
    if (line2[j] == '\0'){
      printf("not in line %c\n", c);
      cnt++;
    }
    i++;
  }
  printf("line1 %s\n", line1);
  printf("line2 %s\n", line2);
  return cnt;
}


int main(int argc, char **argv) {
  char in_line[] = "abcd\0";
  char in_line2[] = "abwllefejlgrljlgjjlbeljbleljtljrl\0";

  printf("line2 %s\n", in_line2);

  int count = myfunk(in_line, in_line2);
  printf("res = %d\n", count);
  return 0;
}
