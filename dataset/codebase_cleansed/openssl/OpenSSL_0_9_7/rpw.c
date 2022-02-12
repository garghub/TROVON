int main(int argc, char *argv[])
{
DES_cblock k,k1;
int i;
printf("read passwd\n");
if ((i=des_read_password(&k,"Enter password:",0)) == 0)
{
printf("password = ");
for (i=0; i<8; i++)
printf("%02x ",k[i]);
}
else
printf("error %d\n",i);
printf("\n");
printf("read 2passwds and verify\n");
if ((i=des_read_2passwords(&k,&k1,
"Enter verified password:",1)) == 0)
{
printf("password1 = ");
for (i=0; i<8; i++)
printf("%02x ",k[i]);
printf("\n");
printf("password2 = ");
for (i=0; i<8; i++)
printf("%02x ",k1[i]);
printf("\n");
exit(1);
}
else
{
printf("error %d\n",i);
exit(0);
}
#ifdef LINT
return(0);
#endif
}
