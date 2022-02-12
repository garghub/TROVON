ECDSA_SIG *ECDSA_do_sign(const unsigned char *dgst, int dlen, EC_KEY *eckey)
{
return ECDSA_do_sign_ex(dgst, dlen, NULL, NULL, eckey);
}
ECDSA_SIG *ECDSA_do_sign_ex(const unsigned char *dgst, int dlen,
const BIGNUM *kinv, const BIGNUM *rp, EC_KEY *eckey)
{
ECDSA_DATA *ecdsa = ecdsa_check(eckey);
if (ecdsa == NULL)
return NULL;
return ecdsa->meth->ecdsa_do_sign(dgst, dlen, NULL, NULL, eckey);
}
int ECDSA_sign(int type, const unsigned char *dgst, int dlen, unsigned char
*sig, unsigned int *siglen, EC_KEY *eckey)
{
return ECDSA_sign_ex(type, dgst, dlen, sig, siglen, NULL, NULL, eckey);
}
int ECDSA_sign_ex(int type, const unsigned char *dgst, int dlen, unsigned char
*sig, unsigned int *siglen, const BIGNUM *kinv, const BIGNUM *r,
EC_KEY *eckey)
{
ECDSA_SIG *s;
s = ECDSA_do_sign_ex(dgst, dlen, kinv, r, eckey);
if (s == NULL)
{
*siglen=0;
return 0;
}
*siglen = i2d_ECDSA_SIG(s, &sig);
ECDSA_SIG_free(s);
return 1;
}
int ECDSA_sign_setup(EC_KEY *eckey, BN_CTX *ctx_in, BIGNUM **kinvp,
BIGNUM **rp)
{
ECDSA_DATA *ecdsa = ecdsa_check(eckey);
if (ecdsa == NULL)
return 0;
return ecdsa->meth->ecdsa_sign_setup(eckey, ctx_in, kinvp, rp);
}
