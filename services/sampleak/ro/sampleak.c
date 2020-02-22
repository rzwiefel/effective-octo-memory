typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned short    ushort;
typedef unsigned short    word;

typedef long __off_t;

typedef longlong __quad_t;
typedef __quad_t __off64_t;

typedef ulong size_t;
typedef int __ssize_t;
typedef __ssize_t ssize_t;

int partial_write(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined auStack28 [8];
  ssize_t local_14;
  int local_10;

  if (param_2 < 0) {
                    // WARNING: Subroutine does not return
    __assert_fail("len <= SSIZE_MAX","utils.h",0x20,"partial_write");
  }
  local_10 = param_1;
  puVar1 = auStack28;
  do {
    do {
      *(int *)(puVar1 + -8) = param_2;
      *(int *)(puVar1 + -0xc) = local_10;
      *(undefined4 *)(puVar1 + -0x10) = 1;
      *(undefined4 *)(puVar1 + -0x14) = 0x10c16;
      local_14 = write(*(int *)(puVar1 + -0x10),*(void **)(puVar1 + -0xc),*(size_t *)(puVar1 + -8));
    } while (local_14 == 4);
    puVar2 = puVar1;
    if (local_14 == -1) {
      *(undefined4 *)(puVar1 + -0xc) = 0x11229;
      puVar2 = puVar1 + -0x10;
      *(undefined4 *)(puVar1 + -0x10) = 0x78;
      *(undefined4 *)(puVar1 + -0x14) = 0x10c37;
      err();
    }
    if (local_14 == 0) break;
    param_2 = param_2 - local_14;
    local_10 = local_10 + local_14;
    puVar1 = puVar2;
  } while (param_2 != 0);
  return local_10 - param_1;
}

void out(int param_1,int param_2)

{
  int iVar1;

  iVar1 = partial_write(param_1,param_2);
  if (iVar1 != param_2) {
    errx(0x78,"Couldn\'t write all the data!");
  }
  return;
}

void string_out(char *param_1)

{
  size_t sVar1;

  sVar1 = strlen(param_1);
  out((int)param_1,sVar1);
  return;
}

uint service_example(uint *param_1)

{
  uint uVar1;
  char local_11 [13];

  printf("Hi! Welcome to our note storage service (execution id %lu)\n",param_1);
  puts("Want to (R)ead or (W)rite a note?");
  fflush(stdout);
  fgets(local_11,3,stdin);
  if (local_11[0] == 'R') {
    uVar1 = read_note();
    *param_1 = uVar1;
  }
  else {
    if (local_11[0] == 'W') {
      uVar1 = write_note();
      *param_1 = uVar1;
    }
    else {
      string_out("What was that??? I don\'t know what that means!\n");
      *param_1 = 0xffffffff;
    }
  }
  return *param_1;
}

undefined4 read_note(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_11c;
  char local_118 [200];
  char local_50 [60];
  char *local_14;
  char *local_10;

  puts("Please send: note_id password");
  fflush(stdout);
  iVar1 = __isoc99_scanf("%u %200s",&local_11c,local_50);
  if (iVar1 == 2) {
    memset(local_118,0,200);
    sprintf(local_118,"%u_password",local_11c);
    local_10 = (char *)read_file(local_118);
    iVar1 = strcmp(local_50,local_10);
    if (iVar1 == 0) {
      sprintf(local_118,"%u",local_11c);
      local_14 = (char *)read_file(local_118);
      printf("Note content: ");
      printf(local_14);
      putchar(10);
      uVar2 = 0;
    }
    else {
      string_out("Errr, Wrong password!\n");
      uVar2 = 1;
    }
  }
  else {
    string_out("Can\'t parse yo stuff!\n");
    uVar2 = 1;
  }
  return uVar2;
}

uint write_note(void)

{
  int iVar1;
  char local_150 [200];
  undefined local_88 [60];
  undefined local_4c [60];
  undefined4 local_10 [3];

  puts("Please send: note_id password content");
  puts("The note_id is a number. No extra whitespace!");
  fflush(stdout);
  iVar1 = __isoc99_scanf("%u %50s %50s",local_10,local_4c,local_88);
  if (iVar1 == 3) {
    sprintf(local_150,"%u",local_10[0]);
    new_file(local_150,local_88);
    sprintf(local_150,"%u_password",local_10[0]);
    new_file(local_150,local_4c);
    string_out("Your note is (hopefully) safe with us! Bye!\n");
  }
  else {
    string_out("Can\'t parse this!\n");
  }
  return (uint)(iVar1 != 3);
}

void new_file(char *param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined auStack28 [12];
  FILE *local_10;

  local_10 = fopen(param_1,"wx");
  puVar2 = auStack28;
  if (local_10 == (FILE *)0x0) {
    puVar2 = &stack0xffffffd4;
    err();
  }
  *(FILE **)(puVar2 + -0xc) = local_10;
  *(undefined4 *)(puVar2 + -0x10) = param_2;
  *(undefined4 *)(puVar2 + -0x14) = 0x10fc2;
  iVar1 = fputs(*(char **)(puVar2 + -0x10),*(FILE **)(puVar2 + -0xc));
  puVar3 = puVar2;
  if (iVar1 == -1) {
    *(undefined4 *)(puVar2 + -0xc) = 0x1140f;
    puVar3 = puVar2 + -0x10;
    *(undefined4 *)(puVar2 + -0x10) = 1;
    *(undefined4 *)(puVar2 + -0x14) = 0x10fd9;
    err();
  }
  *(FILE **)(puVar3 + -0x10) = local_10;
  *(undefined4 *)(puVar3 + -0x14) = 0x10fe4;
  iVar1 = fclose(*(FILE **)(puVar3 + -0x10));
  if (iVar1 == -1) {
    *(undefined4 *)(puVar3 + -0xc) = 0x1141e;
    *(undefined4 *)(puVar3 + -0x10) = 1;
    *(undefined4 *)(puVar3 + -0x14) = 0x10ffb;
    err();
  }
  return;
}

void read_file(char *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined *puVar3;
  undefined auStack284 [13];
  undefined local_10f [255];
  FILE *local_10;

  local_10 = fopen(param_1,"r");
  printf("trying to open file %s\n");
  fflush(stdout);
  puVar3 = auStack284;
  if (local_10 == (FILE *)0x0) {
    puts("what????");
    fflush(stdout);
    err();
    puVar3 = &stack0xfffffed4;
  }
  *(char **)(puVar3 + -0xc) = param_1;
  *(undefined4 *)(puVar3 + -0x10) = 0x11461;
  *(undefined4 *)(puVar3 + -0x14) = 0x11087;
  printf(*(char **)(puVar3 + -0x10));
  *(FILE **)(puVar3 + -0x10) = stdout;
  *(undefined4 *)(puVar3 + -0x14) = 0x11098;
  fflush(*(FILE **)(puVar3 + -0x10));
  *(FILE **)(puVar3 + -8) = local_10;
  *(undefined4 *)(puVar3 + -0xc) = 0xfe;
  *(undefined **)(puVar3 + -0x10) = local_10f;
  *(undefined4 *)(puVar3 + -0x14) = 0x110b2;
  pcVar1 = fgets(*(char **)(puVar3 + -0x10),*(int *)(puVar3 + -0xc),*(FILE **)(puVar3 + -8));
  if (pcVar1 == (char *)0x0) {
    *(undefined4 *)(puVar3 + -0xc) = 0x1147a;
    *(undefined4 *)(puVar3 + -0x10) = 1;
    *(undefined4 *)(puVar3 + -0x14) = 0x110c8;
    err();
    puVar3 = puVar3 + -0x10;
  }
  *(char **)(puVar3 + -0xc) = param_1;
  *(undefined4 *)(puVar3 + -0x10) = 0x1148a;
  *(undefined4 *)(puVar3 + -0x14) = 0x110d8;
  printf(*(char **)(puVar3 + -0x10));
  *(FILE **)(puVar3 + -0x10) = stdout;
  *(undefined4 *)(puVar3 + -0x14) = 0x110e9;
  fflush(*(FILE **)(puVar3 + -0x10));
  *(FILE **)(puVar3 + -0x10) = local_10;
  *(undefined4 *)(puVar3 + -0x14) = 0x110f7;
  iVar2 = fclose(*(FILE **)(puVar3 + -0x10));
  if (iVar2 == -1) {
    *(undefined4 *)(puVar3 + -0xc) = 0x11496;
    *(undefined4 *)(puVar3 + -0x10) = 1;
    *(undefined4 *)(puVar3 + -0x14) = 0x1110e;
    err();
    puVar3 = puVar3 + -0x10;
  }
  *(undefined **)(puVar3 + -0x10) = local_10f;
  *(undefined4 *)(puVar3 + -0x14) = 0x1111d;
  strdup(*(char **)(puVar3 + -0x10));
  return;
}

uint main(void)

{
  uint uVar1;
  uint local_14 [2];
  undefined *local_c;

  local_c = &stack0x00000004;
  puts("bbbbb");
  fflush(stdout);
  local_14[0] = 0;
  chdir("../append/");
  uVar1 = service_example(local_14);
  return uVar1;
}
