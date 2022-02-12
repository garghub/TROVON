static void bn_free(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
if(!*pval) return;
if(it->size & BN_SENSITIVE) BN_clear_free((BIGNUM *)*pval);
else BN_free((BIGNUM *)*pval);
*pval = NULL;
}
static int bn_i2c(ASN1_VALUE **pval, unsigned char *cont, int *putype, const ASN1_ITEM *it)
{
BIGNUM *bn;
int pad;
if(!*pval) return -1;
bn = (BIGNUM *)*pval;
if(BN_num_bits(bn) & 0x7) pad = 0;
else pad = 1;
if(cont) {
if(pad) *cont++ = 0;
BN_bn2bin(bn, cont);
}
return pad + BN_num_bytes(bn);
}
static int bn_c2i(ASN1_VALUE **pval, const unsigned char *cont, int len,
int utype, char *free_cont, const ASN1_ITEM *it)
{
BIGNUM *bn;
if(!*pval) bn_new(pval, it);
bn = (BIGNUM *)*pval;
if(!BN_bin2bn(cont, len, bn)) {
bn_free(pval, it);
return 0;
}
return 1;
}
