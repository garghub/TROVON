unsigned char *MD2(unsigned char *d, unsigned long n, unsigned char *md)
{
MD2_CTX c;
static unsigned char m[MD2_DIGEST_LENGTH];
if (md == NULL) md=m;
MD2_Init(&c);
MD2_Update(&c,d,n);
MD2_Final(md,&c);
memset(&c,0,sizeof(c));
return(md);
}
