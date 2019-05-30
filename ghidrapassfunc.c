unsigned long find_password(char *argv1)

{
  int iVar1;
  unsigned long returnValue;
  unsigned long uVar3;
  char charcpy;
  long lVar5;
  char *argv1cpy;
  char bVar7;
  
  lVar5 = -1;
  //copy adress of argv1 in argv1cpy
  argv1cpy = argv1;
  do {
    if (lVar5 == 0) break;
    lVar5 = lVar5 + -1;
    charcpy = *argv1cpy;
    argv1cpy = argv1cpy + 1;
  } while (charcpy != 0); //while charcpy != '\0'
  returnValue = 0;
  if (lVar5 == -0x20) { //checks if strlen(argv1) == 32
    charcpy = *argv1;
    if (charcpy != 0) {
      argv1cpy = &DAT_004898c0;
      argv1 = argv1 + 1;
      uVar3 = 1;
      bVar7 = 0x33; //3 in ascii
      do {
        iVar1 = (int)uVar3;
        uVar3 = 0;
        if (iVar1 != 0) {
          uVar3 = (ulong)((charcpy ^ bVar7) == *argv1cpy);
        }
        bVar7 = *argv1cpy;
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
  uint uVar1;
  ulong var_return;
  
  if (argc < 2) {
    printf("usage : %s <mot de passe>\n", argv[0]);
    var_return = 2;
  }
  else {
    uVar1 = find_password(argv[1]); //"returnvalue" in find_password func
    var_return = (ulong)uVar1;
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
