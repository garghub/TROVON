int i2d_PKCS7_RECIP_INFO(PKCS7_RECIP_INFO *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->version,i2d_ASN1_INTEGER);
M_ASN1_I2D_len(a->issuer_and_serial,i2d_PKCS7_ISSUER_AND_SERIAL);
M_ASN1_I2D_len(a->key_enc_algor,i2d_X509_ALGOR);
M_ASN1_I2D_len(a->enc_key,i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->version,i2d_ASN1_INTEGER);
M_ASN1_I2D_put(a->issuer_and_serial,i2d_PKCS7_ISSUER_AND_SERIAL);
M_ASN1_I2D_put(a->key_enc_algor,i2d_X509_ALGOR);
M_ASN1_I2D_put(a->enc_key,i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_finish();
}
PKCS7_RECIP_INFO *d2i_PKCS7_RECIP_INFO(PKCS7_RECIP_INFO **a,
unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,PKCS7_RECIP_INFO *,PKCS7_RECIP_INFO_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->version,d2i_ASN1_INTEGER);
M_ASN1_D2I_get(ret->issuer_and_serial,d2i_PKCS7_ISSUER_AND_SERIAL);
M_ASN1_D2I_get(ret->key_enc_algor,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->enc_key,d2i_ASN1_OCTET_STRING);
M_ASN1_D2I_Finish(a,PKCS7_RECIP_INFO_free,ASN1_F_D2I_PKCS7_RECIP_INFO);
}
PKCS7_RECIP_INFO *PKCS7_RECIP_INFO_new(void)
{
PKCS7_RECIP_INFO *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,PKCS7_RECIP_INFO);
M_ASN1_New(ret->version,ASN1_INTEGER_new);
M_ASN1_New(ret->issuer_and_serial,PKCS7_ISSUER_AND_SERIAL_new);
M_ASN1_New(ret->key_enc_algor,X509_ALGOR_new);
M_ASN1_New(ret->enc_key,ASN1_OCTET_STRING_new);
ret->cert=NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_PKCS7_RECIP_INFO_NEW);
}
void PKCS7_RECIP_INFO_free(PKCS7_RECIP_INFO *a)
{
if (a == NULL) return;
ASN1_INTEGER_free(a->version);
PKCS7_ISSUER_AND_SERIAL_free(a->issuer_and_serial);
X509_ALGOR_free(a->key_enc_algor);
ASN1_OCTET_STRING_free(a->enc_key);
if (a->cert != NULL) X509_free(a->cert);
Free(a);
}
