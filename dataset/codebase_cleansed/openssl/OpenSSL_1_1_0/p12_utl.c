unsigned char *OPENSSL_asc2uni(const char *asc, int asclen,
unsigned char **uni, int *unilen)
{
int ulen, i;
unsigned char *unitmp;
if (asclen == -1)
asclen = strlen(asc);
ulen = asclen * 2 + 2;
if ((unitmp = OPENSSL_malloc(ulen)) == NULL)
return NULL;
for (i = 0; i < ulen - 2; i += 2) {
unitmp[i] = 0;
unitmp[i + 1] = asc[i >> 1];
}
unitmp[ulen - 2] = 0;
unitmp[ulen - 1] = 0;
if (unilen)
*unilen = ulen;
if (uni)
*uni = unitmp;
return unitmp;
}
char *OPENSSL_uni2asc(const unsigned char *uni, int unilen)
{
int asclen, i;
char *asctmp;
if (unilen & 1)
return NULL;
asclen = unilen / 2;
if (!unilen || uni[unilen - 1])
asclen++;
uni++;
if ((asctmp = OPENSSL_malloc(asclen)) == NULL)
return NULL;
for (i = 0; i < unilen; i += 2)
asctmp[i >> 1] = uni[i];
asctmp[asclen - 1] = 0;
return asctmp;
}
unsigned char *OPENSSL_utf82uni(const char *asc, int asclen,
unsigned char **uni, int *unilen)
{
int ulen, i, j;
unsigned char *unitmp, *ret;
unsigned long utf32chr = 0;
if (asclen == -1)
asclen = strlen(asc);
for (ulen = 0, i = 0; i < asclen; i += j) {
j = UTF8_getc((const unsigned char *)asc+i, asclen-i, &utf32chr);
if (j < 0)
return OPENSSL_asc2uni(asc, asclen, uni, unilen);
if (utf32chr > 0x10FFFF)
return NULL;
if (utf32chr >= 0x10000)
ulen += 2*2;
else
ulen += 2;
}
ulen += 2;
if ((ret = OPENSSL_malloc(ulen)) == NULL)
return NULL;
for (unitmp = ret, i = 0; i < asclen; i += j) {
j = UTF8_getc((const unsigned char *)asc+i, asclen-i, &utf32chr);
if (utf32chr >= 0x10000) {
unsigned int hi, lo;
utf32chr -= 0x10000;
hi = 0xD800 + (utf32chr>>10);
lo = 0xDC00 + (utf32chr&0x3ff);
*unitmp++ = (unsigned char)(hi>>8);
*unitmp++ = (unsigned char)(hi);
*unitmp++ = (unsigned char)(lo>>8);
*unitmp++ = (unsigned char)(lo);
} else {
*unitmp++ = (unsigned char)(utf32chr>>8);
*unitmp++ = (unsigned char)(utf32chr);
}
}
*unitmp++ = 0;
*unitmp++ = 0;
if (unilen)
*unilen = ulen;
if (uni)
*uni = ret;
return ret;
}
static int bmp_to_utf8(char *str, const unsigned char *utf16, int len)
{
unsigned long utf32chr;
if (len == 0) return 0;
if (len < 2) return -1;
utf32chr = (utf16[0]<<8) | utf16[1];
if (utf32chr >= 0xD800 && utf32chr < 0xE000) {
unsigned int lo;
if (len < 4) return -1;
utf32chr -= 0xD800;
utf32chr <<= 10;
lo = (utf16[2]<<8) | utf16[3];
if (lo < 0xDC00 || lo >= 0xE000) return -1;
utf32chr |= lo-0xDC00;
utf32chr += 0x10000;
}
return UTF8_putc((unsigned char *)str, len > 4 ? 4 : len, utf32chr);
}
char *OPENSSL_uni2utf8(const unsigned char *uni, int unilen)
{
int asclen, i, j;
char *asctmp;
if (unilen & 1)
return NULL;
for (asclen = 0, i = 0; i < unilen; ) {
j = bmp_to_utf8(NULL, uni+i, unilen-i);
if (j < 0) return OPENSSL_uni2asc(uni, unilen);
if (j == 4) i += 4;
else i += 2;
asclen += j;
}
if (!unilen || (uni[unilen-2]||uni[unilen - 1]))
asclen++;
if ((asctmp = OPENSSL_malloc(asclen)) == NULL)
return NULL;
for (asclen = 0, i = 0; i < unilen; ) {
j = bmp_to_utf8(asctmp+asclen, uni+i, unilen-i);
if (j == 4) i += 4;
else i += 2;
asclen += j;
}
if (!unilen || (uni[unilen-2]||uni[unilen - 1]))
asctmp[asclen] = '\0';
return asctmp;
}
int i2d_PKCS12_bio(BIO *bp, PKCS12 *p12)
{
return ASN1_item_i2d_bio(ASN1_ITEM_rptr(PKCS12), bp, p12);
}
int i2d_PKCS12_fp(FILE *fp, PKCS12 *p12)
{
return ASN1_item_i2d_fp(ASN1_ITEM_rptr(PKCS12), fp, p12);
}
PKCS12 *d2i_PKCS12_bio(BIO *bp, PKCS12 **p12)
{
return ASN1_item_d2i_bio(ASN1_ITEM_rptr(PKCS12), bp, p12);
}
PKCS12 *d2i_PKCS12_fp(FILE *fp, PKCS12 **p12)
{
return ASN1_item_d2i_fp(ASN1_ITEM_rptr(PKCS12), fp, p12);
}
