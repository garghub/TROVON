int DSA_do_verify(const unsigned char *dgst, int dgst_len, DSA_SIG *sig,
DSA *dsa)
{
return dsa->meth->dsa_do_verify(dgst, dgst_len, sig, dsa);
}
int DSA_verify(int type, const unsigned char *dgst, int dgst_len,
unsigned char *sigbuf, int siglen, DSA *dsa)
{
DSA_SIG *s;
int ret=-1;
s = DSA_SIG_new();
if (s == NULL) return(ret);
if (d2i_DSA_SIG(&s,&sigbuf,siglen) == NULL) goto err;
ret=DSA_do_verify(dgst,dgst_len,s,dsa);
err:
DSA_SIG_free(s);
return(ret);
}
