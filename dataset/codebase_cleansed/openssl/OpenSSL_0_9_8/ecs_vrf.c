int ECDSA_do_verify(const unsigned char *dgst, int dgst_len,
const ECDSA_SIG *sig, EC_KEY *eckey)
{
ECDSA_DATA *ecdsa = ecdsa_check(eckey);
if (ecdsa == NULL)
return 0;
return ecdsa->meth->ecdsa_do_verify(dgst, dgst_len, sig, eckey);
}
int ECDSA_verify(int type, const unsigned char *dgst, int dgst_len,
const unsigned char *sigbuf, int sig_len, EC_KEY *eckey)
{
ECDSA_SIG *s;
int ret=-1;
s = ECDSA_SIG_new();
if (s == NULL) return(ret);
if (d2i_ECDSA_SIG(&s, &sigbuf, sig_len) == NULL) goto err;
ret=ECDSA_do_verify(dgst, dgst_len, s, eckey);
err:
ECDSA_SIG_free(s);
return(ret);
}
