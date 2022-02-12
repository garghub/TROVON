int ECDSA_do_verify(const unsigned char *dgst, int dgst_len,
const ECDSA_SIG *sig, EC_KEY *eckey)
{
if (eckey->meth->verify_sig != NULL)
return eckey->meth->verify_sig(dgst, dgst_len, sig, eckey);
ECerr(EC_F_ECDSA_DO_VERIFY, EC_R_OPERATION_NOT_SUPPORTED);
return 0;
}
int ECDSA_verify(int type, const unsigned char *dgst, int dgst_len,
const unsigned char *sigbuf, int sig_len, EC_KEY *eckey)
{
if (eckey->meth->verify != NULL)
return eckey->meth->verify(type, dgst, dgst_len, sigbuf, sig_len,
eckey);
ECerr(EC_F_ECDSA_VERIFY, EC_R_OPERATION_NOT_SUPPORTED);
return 0;
}
