int i2d_PKCS7_ENCRYPT(PKCS7_ENCRYPT *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->version,i2d_ASN1_INTEGER);
M_ASN1_I2D_len(a->enc_data,i2d_PKCS7_ENC_CONTENT);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->version,i2d_ASN1_INTEGER);
M_ASN1_I2D_put(a->enc_data,i2d_PKCS7_ENC_CONTENT);
M_ASN1_I2D_finish();
}
PKCS7_ENCRYPT *d2i_PKCS7_ENCRYPT(PKCS7_ENCRYPT **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,PKCS7_ENCRYPT *,PKCS7_ENCRYPT_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->version,d2i_ASN1_INTEGER);
M_ASN1_D2I_get(ret->enc_data,d2i_PKCS7_ENC_CONTENT);
M_ASN1_D2I_Finish(a,PKCS7_ENCRYPT_free,ASN1_F_D2I_PKCS7_ENCRYPT);
}
PKCS7_ENCRYPT *PKCS7_ENCRYPT_new(void)
{
PKCS7_ENCRYPT *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,PKCS7_ENCRYPT);
M_ASN1_New(ret->version,M_ASN1_INTEGER_new);
M_ASN1_New(ret->enc_data,PKCS7_ENC_CONTENT_new);
return(ret);
M_ASN1_New_Error(ASN1_F_PKCS7_ENCRYPT_NEW);
}
void PKCS7_ENCRYPT_free(PKCS7_ENCRYPT *a)
{
if (a == NULL) return;
M_ASN1_INTEGER_free(a->version);
PKCS7_ENC_CONTENT_free(a->enc_data);
OPENSSL_free(a);
}
