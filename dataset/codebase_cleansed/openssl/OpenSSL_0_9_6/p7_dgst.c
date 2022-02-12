int i2d_PKCS7_DIGEST(PKCS7_DIGEST *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->version,i2d_ASN1_INTEGER);
M_ASN1_I2D_len(a->md,i2d_X509_ALGOR);
M_ASN1_I2D_len(a->contents,i2d_PKCS7);
M_ASN1_I2D_len(a->digest,i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->version,i2d_ASN1_INTEGER);
M_ASN1_I2D_put(a->md,i2d_X509_ALGOR);
M_ASN1_I2D_put(a->contents,i2d_PKCS7);
M_ASN1_I2D_put(a->digest,i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_finish();
}
PKCS7_DIGEST *d2i_PKCS7_DIGEST(PKCS7_DIGEST **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,PKCS7_DIGEST *,PKCS7_DIGEST_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->version,d2i_ASN1_INTEGER);
M_ASN1_D2I_get(ret->md,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->contents,d2i_PKCS7);
M_ASN1_D2I_get(ret->digest,d2i_ASN1_OCTET_STRING);
M_ASN1_D2I_Finish(a,PKCS7_DIGEST_free,ASN1_F_D2I_PKCS7_DIGEST);
}
PKCS7_DIGEST *PKCS7_DIGEST_new(void)
{
PKCS7_DIGEST *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,PKCS7_DIGEST);
M_ASN1_New(ret->version,M_ASN1_INTEGER_new);
M_ASN1_New(ret->md,X509_ALGOR_new);
M_ASN1_New(ret->contents,PKCS7_new);
M_ASN1_New(ret->digest,M_ASN1_OCTET_STRING_new);
return(ret);
M_ASN1_New_Error(ASN1_F_PKCS7_DIGEST_NEW);
}
void PKCS7_DIGEST_free(PKCS7_DIGEST *a)
{
if (a == NULL) return;
M_ASN1_INTEGER_free(a->version);
X509_ALGOR_free(a->md);
PKCS7_free(a->contents);
M_ASN1_OCTET_STRING_free(a->digest);
OPENSSL_free(a);
}
