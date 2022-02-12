int i2d_PKCS8_PRIV_KEY_INFO (PKCS8_PRIV_KEY_INFO *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->version, i2d_ASN1_INTEGER);
M_ASN1_I2D_len (a->pkeyalg, i2d_X509_ALGOR);
M_ASN1_I2D_len (a->pkey, i2d_ASN1_TYPE);
M_ASN1_I2D_len_IMP_SET_opt (a->attributes, i2d_X509_ATTRIBUTE, 0);
M_ASN1_I2D_seq_total ();
M_ASN1_I2D_put (a->version, i2d_ASN1_INTEGER);
M_ASN1_I2D_put (a->pkeyalg, i2d_X509_ALGOR);
M_ASN1_I2D_put (a->pkey, i2d_ASN1_TYPE);
M_ASN1_I2D_put_IMP_SET_opt (a->attributes, i2d_X509_ATTRIBUTE, 0);
M_ASN1_I2D_finish();
}
PKCS8_PRIV_KEY_INFO *PKCS8_PRIV_KEY_INFO_new(void)
{
PKCS8_PRIV_KEY_INFO *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, PKCS8_PRIV_KEY_INFO);
M_ASN1_New (ret->version, ASN1_INTEGER_new);
M_ASN1_New (ret->pkeyalg, X509_ALGOR_new);
M_ASN1_New (ret->pkey, ASN1_TYPE_new);
ret->attributes = NULL;
ret->broken = PKCS8_OK;
return (ret);
M_ASN1_New_Error(ASN1_F_PKCS8_PRIV_KEY_INFO_NEW);
}
PKCS8_PRIV_KEY_INFO *d2i_PKCS8_PRIV_KEY_INFO(PKCS8_PRIV_KEY_INFO **a,
unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,PKCS8_PRIV_KEY_INFO *,PKCS8_PRIV_KEY_INFO_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get (ret->version, d2i_ASN1_INTEGER);
M_ASN1_D2I_get (ret->pkeyalg, d2i_X509_ALGOR);
M_ASN1_D2I_get (ret->pkey, d2i_ASN1_TYPE);
M_ASN1_D2I_get_IMP_set_opt(ret->attributes, d2i_X509_ATTRIBUTE,
X509_ATTRIBUTE_free, 0);
if (ASN1_TYPE_get(ret->pkey) == V_ASN1_SEQUENCE)
ret->broken = PKCS8_NO_OCTET;
M_ASN1_D2I_Finish(a, PKCS8_PRIV_KEY_INFO_free, ASN1_F_D2I_PKCS8_PRIV_KEY_INFO);
}
void PKCS8_PRIV_KEY_INFO_free (PKCS8_PRIV_KEY_INFO *a)
{
if (a == NULL) return;
ASN1_INTEGER_free (a->version);
X509_ALGOR_free(a->pkeyalg);
if (a->pkey->value.octet_string)
memset (a->pkey->value.octet_string->data,
0, a->pkey->value.octet_string->length);
ASN1_TYPE_free (a->pkey);
sk_pop_free (a->attributes, X509_ATTRIBUTE_free);
Free ((char *)a);
}
