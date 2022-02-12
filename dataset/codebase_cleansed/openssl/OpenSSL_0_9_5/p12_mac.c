int i2d_PKCS12_MAC_DATA(PKCS12_MAC_DATA *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->dinfo, i2d_X509_SIG);
M_ASN1_I2D_len (a->salt, i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_len (a->iter, i2d_ASN1_INTEGER);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put (a->dinfo, i2d_X509_SIG);
M_ASN1_I2D_put (a->salt, i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_put (a->iter, i2d_ASN1_INTEGER);
M_ASN1_I2D_finish();
}
PKCS12_MAC_DATA *PKCS12_MAC_DATA_new(void)
{
PKCS12_MAC_DATA *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, PKCS12_MAC_DATA);
ret->dinfo = X509_SIG_new();
ret->salt = M_ASN1_OCTET_STRING_new();
ret->iter = NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_PKCS12_MAC_DATA_NEW);
}
PKCS12_MAC_DATA *d2i_PKCS12_MAC_DATA(PKCS12_MAC_DATA **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,PKCS12_MAC_DATA *,PKCS12_MAC_DATA_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->dinfo, d2i_X509_SIG);
M_ASN1_D2I_get(ret->salt, d2i_ASN1_OCTET_STRING);
M_ASN1_D2I_get_opt(ret->iter, d2i_ASN1_INTEGER, V_ASN1_INTEGER);
M_ASN1_D2I_Finish(a, PKCS12_MAC_DATA_free, ASN1_F_D2I_PKCS12_MAC_DATA);
}
void PKCS12_MAC_DATA_free (PKCS12_MAC_DATA *a)
{
if (a == NULL) return;
X509_SIG_free (a->dinfo);
M_ASN1_OCTET_STRING_free(a->salt);
M_ASN1_INTEGER_free(a->iter);
Free (a);
}
