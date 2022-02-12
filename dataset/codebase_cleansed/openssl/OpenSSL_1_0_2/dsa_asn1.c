static int sig_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
if (operation == ASN1_OP_NEW_PRE) {
DSA_SIG *sig;
sig = OPENSSL_malloc(sizeof(DSA_SIG));
if (!sig) {
DSAerr(DSA_F_SIG_CB, ERR_R_MALLOC_FAILURE);
return 0;
}
sig->r = NULL;
sig->s = NULL;
*pval = (ASN1_VALUE *)sig;
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
if (derlen > 0) {
OPENSSL_cleanse(der, derlen);
OPENSSL_free(der);
}
DSA_SIG_free(s);
return (ret);
}
