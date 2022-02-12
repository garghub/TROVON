main()
{
int i, j;
for (i = 0; i < 256; i++) {
for (j = 0; j < 256; j++)
if (ebits_to_num[j] == i) {
printf("0x%02x,", j);
break;
}
}
}
