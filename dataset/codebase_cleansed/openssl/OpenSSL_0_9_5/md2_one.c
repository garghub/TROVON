unsigned char *MD2(const unsigned char *d, unsigned long n, unsigned char *md)
{
MD2_CTX c;
static unsigned char m[MD2_DIGEST_LENGTH];
if (md == NULL) md=m;
MD2_Init(&c);
#ifndef CHARSET_EBCDIC
MD2_Update(&c,d,n);
#else
{
char temp[1024];
unsigned long chunk;
while (n > 0)
{
chunk = (n > sizeof(temp)) ? sizeof(temp) : n;
ebcdic2ascii(temp, d, chunk);
MD2_Update(&c,temp,chunk);
n -= chunk;
d += chunk;
}
}
#endif
MD2_Final(md,&c);
memset(&c,0,sizeof(c));
return(md);
}
