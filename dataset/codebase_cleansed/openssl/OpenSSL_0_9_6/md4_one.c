unsigned char *MD4(const unsigned char *d, unsigned long n, unsigned char *md)
{
MD4_CTX c;
static unsigned char m[MD4_DIGEST_LENGTH];
if (md == NULL) md=m;
MD4_Init(&c);
#ifndef CHARSET_EBCDIC
MD4_Update(&c,d,n);
#else
{
char temp[1024];
unsigned long chunk;
while (n > 0)
{
chunk = (n > sizeof(temp)) ? sizeof(temp) : n;
ebcdic2ascii(temp, d, chunk);
MD4_Update(&c,temp,chunk);
n -= chunk;
d += chunk;
}
}
#endif
MD4_Final(md,&c);
memset(&c,0,sizeof(c));
return(md);
}
