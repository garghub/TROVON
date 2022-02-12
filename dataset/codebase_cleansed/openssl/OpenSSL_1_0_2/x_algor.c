void X509_ALGOR_set_md(X509_ALGOR *alg, const EVP_MD *md)
{
int param_type;
if (md->flags & EVP_MD_FLAG_DIGALGID_ABSENT)
param_type = V_ASN1_UNDEF;
else
param_type = V_ASN1_NULL;
X509_ALGOR_set0(alg, OBJ_nid2obj(EVP_MD_type(md)), param_type, NULL);
}
int X509_ALGOR_cmp(const X509_ALGOR *a, const X509_ALGOR *b)
{
int rv;
rv = OBJ_cmp(a->algorithm, b->algorithm);
if (rv)
return rv;
if (!a->parameter && !b->parameter)
return 0;
return ASN1_TYPE_cmp(a->parameter, b->parameter);
}
