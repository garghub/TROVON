main()
{
ASN1_TYPE *at;
char buf[512];
int n;
long l;
at=ASN1_TYPE_new();
n=ASN1_TYPE_set_int_octetstring(at,98736,"01234567",8);
printf("%d\n",n);
n=ASN1_TYPE_get_int_octetstring(at,&l,buf,8);
buf[8]='\0';
printf("%ld %d %d\n",l,n,buf[8]);
buf[8]='\0';
printf("%s\n",buf);
ERR_load_crypto_strings();
ERR_print_errors_fp(stderr);
}
