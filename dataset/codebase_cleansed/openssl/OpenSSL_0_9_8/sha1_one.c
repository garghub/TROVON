unsigned char *SHA1(const unsigned char *d, size_t n, unsigned char *md)
{
SHA_CTX c;
static unsigned char m[SHA_DIGEST_LENGTH];
if (md == NULL) md=m;
if (!SHA1_Init(&c))
return NULL;
SHA1_Update(&c,d,n);
SHA1_Final(md,&c);
OPENSSL_cleanse(&c,sizeof(c));
return(md);
}
