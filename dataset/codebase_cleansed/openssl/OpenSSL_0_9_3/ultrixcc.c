main()
{
f(5);
f(0);
}
int f(a)
int a;
{
switch(a&7)
{
case 7:
printf("7\n");
case 6:
printf("6\n");
case 5:
printf("5\n");
case 4:
printf("4\n");
case 3:
printf("3\n");
case 2:
printf("2\n");
case 1:
printf("1\n");
#ifdef FIX_BUG
case 0:
;
#endif
}
}
