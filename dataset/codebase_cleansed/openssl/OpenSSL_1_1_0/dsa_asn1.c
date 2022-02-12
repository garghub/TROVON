void DSA_SIG_get0(const DSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps)
{
if (pr != NULL)
*pr = sig->r;
if (ps != NULL)
*ps = sig->s;
}
int DSA_SIG_set0(DSA_SIG *sig, BIGNUM *r, BIGNUM *s)
{
if (r == NULL || s == NULL)
return 0;
BN_clear_free(sig->r);
BN_clear_free(sig->s);
sig->r = r;
sig->s = s;
return 1;
}
static int dsa_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
if (operation == ASN1_OP_NEW_PRE) {
*pval = (ASN1_VALUE *)DSA_new();
if (*pval != NULL)
return 2;
return 0;
} else if (operation == ASN1_OP_FREE_PRE) {
DSA_free((DSA *)*pval);
*pval = NULL;
return 2;
}
return 1;
}
int DSA_sign(int type, const unsigned char *dgst, int dlen,
unsigned char *sig, unsigned int *siglen, DSA *dsa)
{
DSA_SIG *s;
RAND_seed(dgst, dlen);
s = DSA_do_sign(dgst, dlen, dsa);
if (s == NULL) {
*siglen = 0;
return (0);
}
*siglen = i2d_DSA_SIG(s, &sig);
DSA_SIG_free(s);
return (1);
}
int DSA_verify(int type, const unsigned char *dgst, int dgst_len,
const unsigned char *sigbuf, int siglen, DSA *dsa)
{
DSA_SIG *s;
const unsigned char *p = sigbuf;
unsigned char *der = NULL;
int derlen = -1;
int ret = -1;
s = DSA_SIG_new();
if (s == NULL)
return (ret);
if (d2i_DSA_SIG(&s, &p, siglen) == NULL)
goto err;
derlen = i2d_DSA_SIG(s, &der);
if (derlen != siglen || memcmp(sigbuf, der, derlen))
goto err;
ret = DSA_do_verify(dgst, dgst_len, s, dsa);
err:
OPENSSL_clear_free(der, derlen);
DSA_SIG_free(s);
return (ret);
}
