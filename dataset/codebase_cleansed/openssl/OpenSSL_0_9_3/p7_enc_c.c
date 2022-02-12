int i2d_PKCS7_ENC_CONTENT(PKCS7_ENC_CONTENT *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->content_type,i2d_ASN1_OBJECT);
M_ASN1_I2D_len(a->algorithm,i2d_X509_ALGOR);
M_ASN1_I2D_len_IMP_opt(a->enc_data,i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->content_type,i2d_ASN1_OBJECT);
M_ASN1_I2D_put(a->algorithm,i2d_X509_ALGOR);
M_ASN1_I2D_put_IMP_opt(a->enc_data,i2d_ASN1_OCTET_STRING,0);
M_ASN1_I2D_finish();
}
PKCS7_ENC_CONTENT *d2i_PKCS7_ENC_CONTENT(PKCS7_ENC_CONTENT **a,
unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,PKCS7_ENC_CONTENT *,PKCS7_ENC_CONTENT_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->content_type,d2i_ASN1_OBJECT);
M_ASN1_D2I_get(ret->algorithm,d2i_X509_ALGOR);
M_ASN1_D2I_get_IMP_opt(ret->enc_data,d2i_ASN1_OCTET_STRING,0,
V_ASN1_OCTET_STRING);
M_ASN1_D2I_Finish(a,PKCS7_ENC_CONTENT_free,
ASN1_F_D2I_PKCS7_ENC_CONTENT);
}
PKCS7_ENC_CONTENT *PKCS7_ENC_CONTENT_new(void)
{
PKCS7_ENC_CONTENT *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,PKCS7_ENC_CONTENT);
ret->content_type=OBJ_nid2obj(NID_pkcs7_encrypted);
M_ASN1_New(ret->algorithm,X509_ALGOR_new);
ret->enc_data=NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_PKCS7_ENC_CONTENT_NEW);
}
void PKCS7_ENC_CONTENT_free(PKCS7_ENC_CONTENT *a)
{
if (a == NULL) return;
ASN1_OBJECT_free(a->content_type);
X509_ALGOR_free(a->algorithm);
ASN1_OCTET_STRING_free(a->enc_data);
Free((char *)a);
}
