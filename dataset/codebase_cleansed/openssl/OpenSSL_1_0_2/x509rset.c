int X509_REQ_set_version(X509_REQ *x, long version)
{
if (x == NULL)
return (0);
return (ASN1_INTEGER_set(x->req_info->version, version));
}
int X509_REQ_set_subject_name(X509_REQ *x, X509_NAME *name)
{
if ((x == NULL) || (x->req_info == NULL))
return (0);
return (X509_NAME_set(&x->req_info->subject, name));
}
int X509_REQ_set_pubkey(X509_REQ *x, EVP_PKEY *pkey)
{
if ((x == NULL) || (x->req_info == NULL))
return (0);
return (X509_PUBKEY_set(&x->req_info->pubkey, pkey));
}
