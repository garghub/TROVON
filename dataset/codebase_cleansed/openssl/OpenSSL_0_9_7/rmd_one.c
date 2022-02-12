unsigned char *RIPEMD160(const unsigned char *d, unsigned long n,
unsigned char *md)
{
RIPEMD160_CTX c;
static unsigned char m[RIPEMD160_DIGEST_LENGTH];
if (md == NULL) md=m;
RIPEMD160_Init(&c);
RIPEMD160_Update(&c,d,n);
RIPEMD160_Final(md,&c);
OPENSSL_cleanse(&c,sizeof(c));
return(md);
}
