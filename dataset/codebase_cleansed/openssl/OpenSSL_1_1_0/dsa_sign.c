DSA_SIG *DSA_do_sign(const unsigned char *dgst, int dlen, DSA *dsa)
{
return dsa->meth->dsa_do_sign(dgst, dlen, dsa);
}
int DSA_sign_setup(DSA *dsa, BN_CTX *ctx_in, BIGNUM **kinvp, BIGNUM **rp)
{
return dsa->meth->dsa_sign_setup(dsa, ctx_in, kinvp, rp);
}
