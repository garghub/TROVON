unsigned char *RIPEMD160(const unsigned char *d, size_t n,
unsigned char *md)
{
RIPEMD160_CTX c;
static unsigned char m[RIPEMD160_DIGEST_LENGTH];
if (md == NULL) md=m;
if (!RIPEMD160_Init(&c))
return NULL;
RIPEMD160_Update(&c,d,n);
RIPEMD160_Final(md,&c);
OPENSSL_cleanse(&c,sizeof(c));
return(md);
}
