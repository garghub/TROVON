unsigned char *asc2uni (const char *asc, unsigned char **uni, int *unilen)
{
int ulen, i;
unsigned char *unitmp;
ulen = strlen(asc)*2 + 2;
if (!(unitmp = OPENSSL_malloc (ulen))) return NULL;
for (i = 0; i < ulen; i+=2) {
unitmp[i] = 0;
unitmp[i + 1] = asc[i>>1];
}
if (unilen) *unilen = ulen;
if (uni) *uni = unitmp;
return unitmp;
}
char *uni2asc (unsigned char *uni, int unilen)
{
int asclen, i;
char *asctmp;
asclen = unilen / 2;
if (uni[unilen - 1]) asclen++;
uni++;
if (!(asctmp = OPENSSL_malloc (asclen))) return NULL;
for (i = 0; i < unilen; i+=2) asctmp[i>>1] = uni[i];
asctmp[asclen - 1] = 0;
return asctmp;
}
int i2d_PKCS12_bio(BIO *bp, PKCS12 *p12)
{
return ASN1_i2d_bio((int(*)())i2d_PKCS12, bp, (unsigned char *)p12);
}
int i2d_PKCS12_fp(FILE *fp, PKCS12 *p12)
{
return ASN1_i2d_fp((int(*)())i2d_PKCS12, fp, (unsigned char *)p12);
}
PKCS12 *d2i_PKCS12_bio(BIO *bp, PKCS12 **p12)
{
return (PKCS12 *)ASN1_d2i_bio((char *(*)())PKCS12_new,
(char *(*)())d2i_PKCS12, bp, (unsigned char **)p12);
}
PKCS12 *d2i_PKCS12_fp(FILE *fp, PKCS12 **p12)
{
return (PKCS12 *)ASN1_d2i_fp((char *(*)())PKCS12_new,
(char *(*)())d2i_PKCS12, fp, (unsigned char **)(p12));
}
