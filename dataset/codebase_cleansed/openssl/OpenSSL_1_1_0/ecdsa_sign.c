ECDSA_SIG *ECDSA_do_sign(const unsigned char *dgst, int dlen, EC_KEY *eckey)
{
return ECDSA_do_sign_ex(dgst, dlen, NULL, NULL, eckey);
}
ECDSA_SIG *ECDSA_do_sign_ex(const unsigned char *dgst, int dlen,
const BIGNUM *kinv, const BIGNUM *rp,
EC_KEY *eckey)
{
if (eckey->meth->sign_sig != NULL)
return eckey->meth->sign_sig(dgst, dlen, kinv, rp, eckey);
ECerr(EC_F_ECDSA_DO_SIGN_EX, EC_R_OPERATION_NOT_SUPPORTED);
return NULL;
}
int ECDSA_sign(int type, const unsigned char *dgst, int dlen, unsigned char
*sig, unsigned int *siglen, EC_KEY *eckey)
{
return ECDSA_sign_ex(type, dgst, dlen, sig, siglen, NULL, NULL, eckey);
}
int ECDSA_sign_ex(int type, const unsigned char *dgst, int dlen,
unsigned char *sig, unsigned int *siglen, const BIGNUM *kinv,
const BIGNUM *r, EC_KEY *eckey)
{
if (eckey->meth->sign != NULL)
return eckey->meth->sign(type, dgst, dlen, sig, siglen, kinv, r, eckey);
ECerr(EC_F_ECDSA_SIGN_EX, EC_R_OPERATION_NOT_SUPPORTED);
return 0;
}
int ECDSA_sign_setup(EC_KEY *eckey, BN_CTX *ctx_in, BIGNUM **kinvp,
BIGNUM **rp)
{
if (eckey->meth->sign_setup != NULL)
return eckey->meth->sign_setup(eckey, ctx_in, kinvp, rp);
ECerr(EC_F_ECDSA_SIGN_SETUP, EC_R_OPERATION_NOT_SUPPORTED);
return 0;
}
