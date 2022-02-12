void X509_ALGOR_set_md(X509_ALGOR *alg, const EVP_MD *md)
{
int param_type;
if (md->flags & EVP_MD_FLAG_DIGALGID_ABSENT)
param_type = V_ASN1_UNDEF;
else
param_type = V_ASN1_NULL;
X509_ALGOR_set0(alg, OBJ_nid2obj(EVP_MD_type(md)), param_type, NULL);
}
