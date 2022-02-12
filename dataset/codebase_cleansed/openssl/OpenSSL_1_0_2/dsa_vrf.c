int DSA_do_verify(const unsigned char *dgst, int dgst_len, DSA_SIG *sig,
DSA *dsa)
{
#ifdef OPENSSL_FIPS
if (FIPS_mode() && !(dsa->meth->flags & DSA_FLAG_FIPS_METHOD)
&& !(dsa->flags & DSA_FLAG_NON_FIPS_ALLOW)) {
DSAerr(DSA_F_DSA_DO_VERIFY, DSA_R_NON_FIPS_DSA_METHOD);
return -1;
}
#endif
return dsa->meth->dsa_do_verify(dgst, dgst_len, sig, dsa);
}
