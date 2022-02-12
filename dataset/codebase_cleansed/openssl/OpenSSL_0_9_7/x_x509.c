ASN1_METHOD *X509_asn1_meth(void)
{
return(&meth);
}
int X509_get_ex_new_index(long argl, void *argp, CRYPTO_EX_new *new_func,
CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func)
{
return CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_X509, argl, argp,
new_func, dup_func, free_func);
}
int X509_set_ex_data(X509 *r, int idx, void *arg)
{
return(CRYPTO_set_ex_data(&r->ex_data,idx,arg));
}
void *X509_get_ex_data(X509 *r, int idx)
{
return(CRYPTO_get_ex_data(&r->ex_data,idx));
}
X509 *d2i_X509_AUX(X509 **a, unsigned char **pp, long length)
{
unsigned char *q;
X509 *ret;
q = *pp;
ret = d2i_X509(a, pp, length);
if(!ret) return NULL;
length -= *pp - q;
if(!length) return ret;
if(!d2i_X509_CERT_AUX(&ret->aux, pp, length)) goto err;
return ret;
err:
X509_free(ret);
return NULL;
}
int i2d_X509_AUX(X509 *a, unsigned char **pp)
{
int length;
length = i2d_X509(a, pp);
if(a) length += i2d_X509_CERT_AUX(a->aux, pp);
return length;
}
