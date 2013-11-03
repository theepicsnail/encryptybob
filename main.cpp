#include<stdio.h>
#include<string.h>
using namespace std;

int main(int argc, char** argv) {
  // Check args
  if (argc != 3) {
    printf("Usage:\n");
    printf(" %s [password] [file]\n", argv[0]);
    printf("File may be '-' to receive data through stdin\n");
    return 1;
  }

  // Reopen stdin from given file (if it's not -)
  if (strcmp(argv[2], "-") {
    freopen(argv[2], "rb", stdin);
  }

  //Compute the xor'd password
  //xord_password[i] = xoring all characters of password (except character [i]) together
  //[1^2^3, 0^2^3, 0^1^3, 0^1^2]
  char * password = argv[1];
  int password_length = strlen(password);
  char * xord_password = new char[password_length];
  strcpy(xord_password, password);
  int i;
  char c = 0;
  for(i = 0 ; i < password_length ; i ++) {
    c ^= password[i];
  }
  for(i = 0 ; i < password_length ; i ++) {
    xord_password[i] ^= c;
  }

  i = 0;
  while ((c=fgetc(stdin)) != EOF) {
    c ^= xord_password[(i++) % password_length];
    printf("%c", c);
  }
}

