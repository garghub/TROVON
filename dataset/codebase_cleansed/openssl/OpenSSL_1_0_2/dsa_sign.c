DSA_SIG *DSA_do_sign(const unsigned char *dgst, int dlen, DSA *dsa)
{
#ifdef OPENSSL_FIPS
if (FIPS_mode() && !(dsa->meth->flags & DSA_FLAG_FIPS_METHOD)
&& !(dsa->flags & DSA_FLAG_NON_FIPS_ALLOW)) {
DSAerr(DSA_F_DSA_DO_SIGN, DSA_R_NON_FIPS_DSA_METHOD);
return NULL;
}
#endif
return dsa->meth->dsa_do_sign(dgst, dlen, dsa);
}
int DSA_sign_setup(DSA *dsa, BN_CTX *ctx_in, BIGNUM **kinvp, BIGNUM **rp)
{
#ifdef OPENSSL_FIPS
if (FIPS_mode() && !(dsa->meth->flags & DSA_FLAG_FIPS_METHOD)
&& !(dsa->flags & DSA_FLAG_NON_FIPS_ALLOW)) {
DSAerr(DSA_F_DSA_SIGN_SETUP, DSA_R_NON_FIPS_DSA_METHOD);
return 0;
}
#endif
return dsa->meth->dsa_sign_setup(dsa, ctx_in, kinvp, rp);
}
DSA_SIG *DSA_SIG_new(void)
{
DSA_SIG *sig;
sig = OPENSSL_malloc(sizeof(DSA_SIG));
if (!sig)
return NULL;
sig->r = NULL;
sig->s = NULL;
return sig;
}
void DSA_SIG_free(DSA_SIG *sig)
{
if (sig) {
if (sig->r)
BN_free(sig->r);
if (sig->s)
BN_free(sig->s);
OPENSSL_free(sig);
}
}
