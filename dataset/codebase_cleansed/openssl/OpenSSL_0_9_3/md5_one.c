unsigned char *MD5(unsigned char *d, unsigned long n, unsigned char *md)
{
MD5_CTX c;
static unsigned char m[MD5_DIGEST_LENGTH];
if (md == NULL) md=m;
MD5_Init(&c);
MD5_Update(&c,d,n);
MD5_Final(md,&c);
memset(&c,0,sizeof(c));
return(md);
}
