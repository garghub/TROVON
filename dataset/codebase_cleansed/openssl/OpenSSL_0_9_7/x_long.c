static void long_free(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
*(long *)pval = it->size;
}
static int long_i2c(ASN1_VALUE **pval, unsigned char *cont, int *putype, const ASN1_ITEM *it)
{
long ltmp;
unsigned long utmp;
int clen, pad, i;
ltmp = *(long *)pval;
if(ltmp == it->size) return -1;
if(ltmp < 0) utmp = -ltmp - 1;
else utmp = ltmp;
clen = BN_num_bits_word(utmp);
if(!(clen & 0x7)) pad = 1;
else pad = 0;
clen = (clen + 7) >> 3;
if(cont) {
if(pad) *cont++ = (ltmp < 0) ? 0xff : 0;
for(i = clen - 1; i >= 0; i--) {
cont[i] = (unsigned char)(utmp & 0xff);
if(ltmp < 0) cont[i] ^= 0xff;
utmp >>= 8;
}
}
return clen + pad;
}
static int long_c2i(ASN1_VALUE **pval, unsigned char *cont, int len, int utype, char *free_cont, const ASN1_ITEM *it)
{
int neg, i;
long ltmp;
unsigned long utmp = 0;
if(len > sizeof(long)) {
ASN1err(ASN1_F_LONG_C2I, ASN1_R_INTEGER_TOO_LARGE_FOR_LONG);
return 0;
}
if(len && (cont[0] & 0x80)) neg = 1;
else neg = 0;
utmp = 0;
for(i = 0; i < len; i++) {
utmp <<= 8;
if(neg) utmp |= cont[i] ^ 0xff;
else utmp |= cont[i];
}
ltmp = (long)utmp;
if(neg) {
ltmp++;
ltmp = -ltmp;
}
if(ltmp == it->size) {
ASN1err(ASN1_F_LONG_C2I, ASN1_R_INTEGER_TOO_LARGE_FOR_LONG);
return 0;
}
*(long *)pval = ltmp;
return 1;
}
