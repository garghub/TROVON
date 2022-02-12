DSA_SIG * DSA_do_sign(const unsigned char *dgst, int dlen, DSA *dsa)
{
return dsa->meth->dsa_do_sign(dgst, dlen, dsa);
}
int DSA_sign(int type, const unsigned char *dgst, int dlen, unsigned char *sig,
unsigned int *siglen, DSA *dsa)
{
DSA_SIG *s;
RAND_seed(dgst, dlen);
s=DSA_do_sign(dgst,dlen,dsa);
if (s == NULL)
{
*siglen=0;
return(0);
}
*siglen=i2d_DSA_SIG(s,&sig);
DSA_SIG_free(s);
return(1);
}
int DSA_sign_setup(DSA *dsa, BN_CTX *ctx_in, BIGNUM **kinvp, BIGNUM **rp)
{
return dsa->meth->dsa_sign_setup(dsa, ctx_in, kinvp, rp);
}
