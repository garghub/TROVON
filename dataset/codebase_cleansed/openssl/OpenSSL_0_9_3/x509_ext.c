int X509_CRL_get_ext_count(X509_CRL *x)
{
return(X509v3_get_ext_count(x->crl->extensions));
}
int X509_CRL_get_ext_by_NID(X509_CRL *x, int nid, int lastpos)
{
return(X509v3_get_ext_by_NID(x->crl->extensions,nid,lastpos));
}
int X509_CRL_get_ext_by_OBJ(X509_CRL *x, ASN1_OBJECT *obj, int lastpos)
{
return(X509v3_get_ext_by_OBJ(x->crl->extensions,obj,lastpos));
}
int X509_CRL_get_ext_by_critical(X509_CRL *x, int crit, int lastpos)
{
return(X509v3_get_ext_by_critical(x->crl->extensions,crit,lastpos));
}
X509_EXTENSION *X509_CRL_get_ext(X509_CRL *x, int loc)
{
return(X509v3_get_ext(x->crl->extensions,loc));
}
X509_EXTENSION *X509_CRL_delete_ext(X509_CRL *x, int loc)
{
return(X509v3_delete_ext(x->crl->extensions,loc));
}
int X509_CRL_add_ext(X509_CRL *x, X509_EXTENSION *ex, int loc)
{
return(X509v3_add_ext(&(x->crl->extensions),ex,loc) != NULL);
}
int X509_get_ext_count(X509 *x)
{
return(X509v3_get_ext_count(x->cert_info->extensions));
}
int X509_get_ext_by_NID(X509 *x, int nid, int lastpos)
{
return(X509v3_get_ext_by_NID(x->cert_info->extensions,nid,lastpos));
}
int X509_get_ext_by_OBJ(X509 *x, ASN1_OBJECT *obj, int lastpos)
{
return(X509v3_get_ext_by_OBJ(x->cert_info->extensions,obj,lastpos));
}
int X509_get_ext_by_critical(X509 *x, int crit, int lastpos)
{
return(X509v3_get_ext_by_critical(x->cert_info->extensions,crit,lastpos));
}
X509_EXTENSION *X509_get_ext(X509 *x, int loc)
{
return(X509v3_get_ext(x->cert_info->extensions,loc));
}
X509_EXTENSION *X509_delete_ext(X509 *x, int loc)
{
return(X509v3_delete_ext(x->cert_info->extensions,loc));
}
int X509_add_ext(X509 *x, X509_EXTENSION *ex, int loc)
{
return(X509v3_add_ext(&(x->cert_info->extensions),ex,loc) != NULL);
}
int X509_REVOKED_get_ext_count(X509_REVOKED *x)
{
return(X509v3_get_ext_count(x->extensions));
}
int X509_REVOKED_get_ext_by_NID(X509_REVOKED *x, int nid, int lastpos)
{
return(X509v3_get_ext_by_NID(x->extensions,nid,lastpos));
}
int X509_REVOKED_get_ext_by_OBJ(X509_REVOKED *x, ASN1_OBJECT *obj,
int lastpos)
{
return(X509v3_get_ext_by_OBJ(x->extensions,obj,lastpos));
}
int X509_REVOKED_get_ext_by_critical(X509_REVOKED *x, int crit, int lastpos)
{
return(X509v3_get_ext_by_critical(x->extensions,crit,lastpos));
}
X509_EXTENSION *X509_REVOKED_get_ext(X509_REVOKED *x, int loc)
{
return(X509v3_get_ext(x->extensions,loc));
}
X509_EXTENSION *X509_REVOKED_delete_ext(X509_REVOKED *x, int loc)
{
return(X509v3_delete_ext(x->extensions,loc));
}
int X509_REVOKED_add_ext(X509_REVOKED *x, X509_EXTENSION *ex, int loc)
{
return(X509v3_add_ext(&(x->extensions),ex,loc) != NULL);
}
