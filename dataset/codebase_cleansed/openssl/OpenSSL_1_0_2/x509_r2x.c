X509 *X509_REQ_to_X509(X509_REQ *r, int days, EVP_PKEY *pkey)
{
X509 *ret = NULL;
X509_CINF *xi = NULL;
X509_NAME *xn;
if ((ret = X509_new()) == NULL) {
X509err(X509_F_X509_REQ_TO_X509, ERR_R_MALLOC_FAILURE);
goto err;
}
xi = ret->cert_info;
if (sk_X509_ATTRIBUTE_num(r->req_info->attributes) != 0) {
if ((xi->version = M_ASN1_INTEGER_new()) == NULL)
goto err;
if (!ASN1_INTEGER_set(xi->version, 2))
goto err;
}
xn = X509_REQ_get_subject_name(r);
if (X509_set_subject_name(ret, X509_NAME_dup(xn)) == 0)
goto err;
if (X509_set_issuer_name(ret, X509_NAME_dup(xn)) == 0)
goto err;
if (X509_gmtime_adj(xi->validity->notBefore, 0) == NULL)
goto err;
if (X509_gmtime_adj(xi->validity->notAfter, (long)60 * 60 * 24 * days) ==
NULL)
goto err;
X509_set_pubkey(ret, X509_REQ_get_pubkey(r));
if (!X509_sign(ret, pkey, EVP_md5()))
goto err;
if (0) {
err:
X509_free(ret);
ret = NULL;
}
return (ret);
}
