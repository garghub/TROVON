int i2d_PKCS12(PKCS12 *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->version, i2d_ASN1_INTEGER);
M_ASN1_I2D_len (a->authsafes, i2d_PKCS7);
M_ASN1_I2D_len (a->mac, i2d_PKCS12_MAC_DATA);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put (a->version, i2d_ASN1_INTEGER);
M_ASN1_I2D_put (a->authsafes, i2d_PKCS7);
M_ASN1_I2D_put (a->mac, i2d_PKCS12_MAC_DATA);
M_ASN1_I2D_finish();
}
PKCS12 *d2i_PKCS12(PKCS12 **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,PKCS12 *,PKCS12_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get (ret->version, d2i_ASN1_INTEGER);
M_ASN1_D2I_get (ret->authsafes, d2i_PKCS7);
M_ASN1_D2I_get_opt (ret->mac, d2i_PKCS12_MAC_DATA, V_ASN1_SEQUENCE);
M_ASN1_D2I_Finish(a, PKCS12_free, ASN1_F_D2I_PKCS12);
}
PKCS12 *PKCS12_new(void)
{
PKCS12 *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, PKCS12);
ret->version=NULL;
ret->mac=NULL;
ret->authsafes=NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_PKCS12_NEW);
}
void PKCS12_free (PKCS12 *a)
{
if (a == NULL) return;
M_ASN1_INTEGER_free(a->version);
PKCS12_MAC_DATA_free (a->mac);
PKCS7_free (a->authsafes);
OPENSSL_free (a);
}
