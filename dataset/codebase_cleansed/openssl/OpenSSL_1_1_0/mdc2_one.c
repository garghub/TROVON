unsigned char *MDC2(const unsigned char *d, size_t n, unsigned char *md)
{
MDC2_CTX c;
static unsigned char m[MDC2_DIGEST_LENGTH];
if (md == NULL)
md = m;
if (!MDC2_Init(&c))
return NULL;
MDC2_Update(&c, d, n);
MDC2_Final(md, &c);
OPENSSL_cleanse(&c, sizeof(c));
return (md);
}
