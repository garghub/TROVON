unsigned char *MDC2(unsigned char *d, unsigned long n, unsigned char *md)
{
MDC2_CTX c;
static unsigned char m[MDC2_DIGEST_LENGTH];
if (md == NULL) md=m;
MDC2_Init(&c);
MDC2_Update(&c,d,n);
MDC2_Final(md,&c);
memset(&c,0,sizeof(c));
return(md);
}
