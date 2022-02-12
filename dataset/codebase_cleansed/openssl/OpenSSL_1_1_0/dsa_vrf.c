int DSA_do_verify(const unsigned char *dgst, int dgst_len, DSA_SIG *sig,
DSA *dsa)
{
return dsa->meth->dsa_do_verify(dgst, dgst_len, sig, dsa);
}
