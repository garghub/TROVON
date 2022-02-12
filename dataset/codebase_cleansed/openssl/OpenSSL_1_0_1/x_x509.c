static int x509_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
X509 *ret = (X509 *)*pval;
switch(operation) {
case ASN1_OP_NEW_POST:
ret->valid=0;
ret->name = NULL;
ret->ex_flags = 0;
ret->ex_pathlen = -1;
ret->skid = NULL;
ret->akid = NULL;
#ifndef OPENSSL_NO_RFC3779
ret->rfc3779_addr = NULL;
ret->rfc3779_asid = NULL;
#endif
ret->aux = NULL;
ret->crldp = NULL;
CRYPTO_new_ex_data(CRYPTO_EX_INDEX_X509, ret, &ret->ex_data);
break;
case ASN1_OP_D2I_POST:
if (ret->name != NULL) OPENSSL_free(ret->name);
ret->name=X509_NAME_oneline(ret->cert_info->subject,NULL,0);
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
if (ret->name != NULL) OPENSSL_free(ret->name);
break;
}
return 1;
}
int X509_set_ex_data(X509 *r, int idx, void *arg)
{
return(CRYPTO_set_ex_data(&r->ex_data,idx,arg));
}
void *X509_get_ex_data(X509 *r, int idx)
{
return(CRYPTO_get_ex_data(&r->ex_data,idx));
}
X509 *d2i_X509_AUX(X509 **a, const unsigned char **pp, long length)
{
const unsigned char *q;
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
