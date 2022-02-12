unsigned char *SHA(const unsigned char *d, size_t n, unsigned char *md)
{
SHA_CTX c;
static unsigned char m[SHA_DIGEST_LENGTH];
if (md == NULL) md=m;
if (!SHA_Init(&c))
return NULL;
SHA_Update(&c,d,n);
SHA_Final(md,&c);
OPENSSL_cleanse(&c,sizeof(c));
return(md);
}
