#include <stdio.h>

unsigned long check_password(char *argv1)
{
  int iVar1;
  unsigned long returnValue;
  unsigned long uVar3;
  char charcpy;
  long argv1len;
  char *argv1cpy;
  char char_three;
	char memorychars[] = "\x77\x30\x63\x26\x5d\x3a\x0e\x3b\x0d\x4d\x2a\x1f\x2e\x1f\x2d\x4f\x28\x51\x37\x7a\x14\x76\x20\x78\x0f\x21\x4d\x21\x6c\x11";
  
  argv1len = -1;
  //copy adress of argv1 in argv1cpy
  argv1cpy = argv1;
  do {
    if (argv1len == 0) break;
    argv1len = argv1len + -1;
    charcpy = *argv1cpy;
    argv1cpy = argv1cpy + 1;
  } while (charcpy != 0); //while charcpy != '\0'

  returnValue = 0;

  if (argv1len == -0x20) //checks if strlen(argv1) == 32
  {
    charcpy = *argv1;
    if (charcpy != 0)
	{
		//memorychars[] = "\x77\x30\x63\x26\x5d\x3a\x0e\x3b\x0d\x4d\x2a\x1f\x2e\x1f\x2d\x4f\x28\x51\x37\x7a\x14\x76\x20\x78\x0f\x21\x4d\x21\x6c";
      //argv1cpy = &DAT_004898c0; //(c0: undef77) | (c1: '0') | (c2: 'c') | (c3: '&') | (c4: ']') | (c5: ':') | (c6: undef0e) | (c7: ';') | (c8: undef0D) | (c9: 'M') | (ca: 2a)
      argv1cpy = memorychars;
      argv1 = argv1 + 1;
      uVar3 = 1;
      char_three = 0x33; //3 in ascii
      do {
        iVar1 = (int)uVar3;
        uVar3 = 0;
        if (iVar1 != 0) 
          uVar3 = (unsigned long)((charcpy ^ char_three) == *argv1cpy);
        char_three = *argv1cpy;
        charcpy = *argv1;
        argv1cpy = argv1cpy + 1;
        argv1 = argv1 + 1;
      } while (charcpy != 0);
      return uVar3;
    }
    returnValue = 1;
  }
  return returnValue;
}

int main(int argc, char *argv[])
{
  unsigned int uVar1;
  unsigned long var_return;
  
  if (argc < 2) {
    printf("usage : %s <mot de passe>\n", argv[0]);
    var_return = 2;
  }
  else {
    uVar1 = check_password(argv[1]); //"returnvalue" in check_password func
    var_return = (unsigned long)uVar1;
    if (uVar1 == 0) {
      printf("Mauvais mot de passe");
    }
    else {
      printf("Bravo ! Vous pouvez utiliser ce mot passe pour la suite ;-)");
      var_return = 0;
    }
  }
  return var_return;
}
