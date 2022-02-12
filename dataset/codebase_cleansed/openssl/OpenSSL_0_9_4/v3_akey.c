int i2d_AUTHORITY_KEYID(AUTHORITY_KEYID *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len_IMP_opt (a->keyid, i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_len_IMP_opt (a->issuer, i2d_GENERAL_NAMES);
M_ASN1_I2D_len_IMP_opt (a->serial, i2d_ASN1_INTEGER);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put_IMP_opt (a->keyid, i2d_ASN1_OCTET_STRING, 0);
M_ASN1_I2D_put_IMP_opt (a->issuer, i2d_GENERAL_NAMES, 1);
M_ASN1_I2D_put_IMP_opt (a->serial, i2d_ASN1_INTEGER, 2);
M_ASN1_I2D_finish();
}
AUTHORITY_KEYID *AUTHORITY_KEYID_new(void)
{
AUTHORITY_KEYID *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, AUTHORITY_KEYID);
ret->keyid = NULL;
ret->issuer = NULL;
ret->serial = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_AUTHORITY_KEYID_NEW);
}
AUTHORITY_KEYID *d2i_AUTHORITY_KEYID(AUTHORITY_KEYID **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,AUTHORITY_KEYID *,AUTHORITY_KEYID_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get_IMP_opt (ret->keyid, d2i_ASN1_OCTET_STRING, 0,
V_ASN1_OCTET_STRING);
M_ASN1_D2I_get_IMP_opt (ret->issuer, d2i_GENERAL_NAMES, 1,
V_ASN1_SEQUENCE);
M_ASN1_D2I_get_IMP_opt (ret->serial, d2i_ASN1_INTEGER, 2,
V_ASN1_INTEGER);
M_ASN1_D2I_Finish(a, AUTHORITY_KEYID_free, ASN1_F_D2I_AUTHORITY_KEYID);
}
void AUTHORITY_KEYID_free(AUTHORITY_KEYID *a)
{
if (a == NULL) return;
ASN1_OCTET_STRING_free(a->keyid);
sk_GENERAL_NAME_pop_free(a->issuer, GENERAL_NAME_free);
ASN1_INTEGER_free (a->serial);
Free ((char *)a);
}
