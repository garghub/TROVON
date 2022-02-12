unsigned char *SHA1(const unsigned char *d, unsigned long n, unsigned char *md)
{
SHA_CTX c;
static unsigned char m[SHA_DIGEST_LENGTH];
if (md == NULL) md=m;
SHA1_Init(&c);
SHA1_Update(&c,d,n);
SHA1_Final(md,&c);
memset(&c,0,sizeof(c));
return(md);
}
