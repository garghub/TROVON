static int x509_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
X509 *ret = (X509 *)*pval;
switch (operation) {
case ASN1_OP_NEW_POST:
ret->ex_flags = 0;
ret->ex_pathlen = -1;
ret->ex_pcpathlen = -1;
ret->skid = NULL;
ret->akid = NULL;
#ifndef OPENSSL_NO_RFC3779
ret->rfc3779_addr = NULL;
ret->rfc3779_asid = NULL;
#endif
ret->aux = NULL;
ret->crldp = NULL;
if (!CRYPTO_new_ex_data(CRYPTO_EX_INDEX_X509, ret, &ret->ex_data))
return 0;
break;
case ASN1_OP_FREE_POST:
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_X509, ret, &ret->ex_data);
X509_CERT_AUX_free(ret->aux);
ASN1_OCTET_STRING_free(ret->skid);
AUTHORITY_KEYID_free(ret->akid);
CRL_DIST_POINTS_free(ret->crldp);
policy_cache_free(ret->policy_cache);
GENERAL_NAMES_free(ret->altname);
NAME_CONSTRAINTS_free(ret->nc);
#ifndef OPENSSL_NO_RFC3779
sk_IPAddressFamily_pop_free(ret->rfc3779_addr, IPAddressFamily_free);
ASIdentifiers_free(ret->rfc3779_asid);
#endif
break;
}
return 1;
}
void *X509_get_ex_data(X509 *r, int idx)
{
return (CRYPTO_get_ex_data(&r->ex_data, idx));
}
X509 *d2i_X509_AUX(X509 **a, const unsigned char **pp, long length)
{
const unsigned char *q;
X509 *ret;
int freeret = 0;
q = *pp;
if (a == NULL || *a == NULL)
freeret = 1;
ret = d2i_X509(a, &q, length);
if (ret == NULL)
return NULL;
length -= q - *pp;
if (length > 0 && !d2i_X509_CERT_AUX(&ret->aux, &q, length))
goto err;
*pp = q;
return ret;
err:
if (freeret) {
X509_free(ret);
if (a)
*a = NULL;
}
return NULL;
}
static int i2d_x509_aux_internal(X509 *a, unsigned char **pp)
{
int length, tmplen;
unsigned char *start = pp != NULL ? *pp : NULL;
OPENSSL_assert(pp == NULL || *pp != NULL);
length = i2d_X509(a, pp);
if (length <= 0 || a == NULL)
return length;
tmplen = i2d_X509_CERT_AUX(a->aux, pp);
if (tmplen < 0) {
if (start != NULL)
*pp = start;
return tmplen;
}
length += tmplen;
return length;
}
int i2d_X509_AUX(X509 *a, unsigned char **pp)
{
int length;
unsigned char *tmp;
if (pp == NULL || *pp != NULL)
return i2d_x509_aux_internal(a, pp);
if ((length = i2d_x509_aux_internal(a, NULL)) <= 0)
return length;
*pp = tmp = OPENSSL_malloc(length);
if (tmp == NULL)
return -1;
length = i2d_x509_aux_internal(a, &tmp);
if (length <= 0) {
OPENSSL_free(*pp);
*pp = NULL;
}
return length;
}
int i2d_re_X509_tbs(X509 *x, unsigned char **pp)
{
x->cert_info.enc.modified = 1;
return i2d_X509_CINF(&x->cert_info, pp);
}
void X509_get0_signature(const ASN1_BIT_STRING **psig,
const X509_ALGOR **palg, const X509 *x)
{
if (psig)
*psig = &x->signature;
if (palg)
*palg = &x->sig_alg;
}
int X509_get_signature_nid(const X509 *x)
{
return OBJ_obj2nid(x->sig_alg.algorithm);
}
