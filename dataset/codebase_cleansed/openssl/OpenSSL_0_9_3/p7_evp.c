int i2d_PKCS7_ENVELOPE(PKCS7_ENVELOPE *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->version,i2d_ASN1_INTEGER);
M_ASN1_I2D_len_SET(a->recipientinfo,i2d_PKCS7_RECIP_INFO);
M_ASN1_I2D_len(a->enc_data,i2d_PKCS7_ENC_CONTENT);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->version,i2d_ASN1_INTEGER);
M_ASN1_I2D_put_SET(a->recipientinfo,i2d_PKCS7_RECIP_INFO);
M_ASN1_I2D_put(a->enc_data,i2d_PKCS7_ENC_CONTENT);
M_ASN1_I2D_finish();
}
PKCS7_ENVELOPE *d2i_PKCS7_ENVELOPE(PKCS7_ENVELOPE **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,PKCS7_ENVELOPE *,PKCS7_ENVELOPE_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->version,d2i_ASN1_INTEGER);
M_ASN1_D2I_get_set(ret->recipientinfo,d2i_PKCS7_RECIP_INFO,
PKCS7_RECIP_INFO_free);
M_ASN1_D2I_get(ret->enc_data,d2i_PKCS7_ENC_CONTENT);
M_ASN1_D2I_Finish(a,PKCS7_ENVELOPE_free,ASN1_F_D2I_PKCS7_ENVELOPE);
}
PKCS7_ENVELOPE *PKCS7_ENVELOPE_new(void)
{
PKCS7_ENVELOPE *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,PKCS7_ENVELOPE);
M_ASN1_New(ret->version,ASN1_INTEGER_new);
M_ASN1_New(ret->recipientinfo,sk_new_null);
M_ASN1_New(ret->enc_data,PKCS7_ENC_CONTENT_new);
return(ret);
M_ASN1_New_Error(ASN1_F_PKCS7_ENVELOPE_NEW);
}
void PKCS7_ENVELOPE_free(PKCS7_ENVELOPE *a)
{
if (a == NULL) return;
ASN1_INTEGER_free(a->version);
sk_pop_free(a->recipientinfo,PKCS7_RECIP_INFO_free);
PKCS7_ENC_CONTENT_free(a->enc_data);
Free((char *)a);
}
