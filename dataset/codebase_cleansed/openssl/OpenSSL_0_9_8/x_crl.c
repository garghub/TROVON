int X509_CRL_add0_revoked(X509_CRL *crl, X509_REVOKED *rev)
{
X509_CRL_INFO *inf;
inf = crl->crl;
if(!inf->revoked)
inf->revoked = sk_X509_REVOKED_new(X509_REVOKED_cmp);
if(!inf->revoked || !sk_X509_REVOKED_push(inf->revoked, rev)) {
ASN1err(ASN1_F_X509_CRL_ADD0_REVOKED, ERR_R_MALLOC_FAILURE);
return 0;
}
inf->enc.modified = 1;
return 1;
}
