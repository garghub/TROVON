ACCESS_DESCRIPTION *ACCESS_DESCRIPTION_new(void)
{
ACCESS_DESCRIPTION *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, ACCESS_DESCRIPTION);
ret->method = OBJ_nid2obj(NID_undef);
ret->location = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_ACCESS_DESCRIPTION_NEW);
}
ACCESS_DESCRIPTION *d2i_ACCESS_DESCRIPTION(ACCESS_DESCRIPTION **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,ACCESS_DESCRIPTION *,ACCESS_DESCRIPTION_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->method, d2i_ASN1_OBJECT);
M_ASN1_D2I_get(ret->location, d2i_GENERAL_NAME);
M_ASN1_D2I_Finish(a, ACCESS_DESCRIPTION_free, ASN1_F_D2I_ACCESS_DESCRIPTION);
}
void ACCESS_DESCRIPTION_free(ACCESS_DESCRIPTION *a)
{
if (a == NULL) return;
ASN1_OBJECT_free(a->method);
GENERAL_NAME_free(a->location);
OPENSSL_free (a);
}
