int i2d_PKCS7_ISSUER_AND_SERIAL(PKCS7_ISSUER_AND_SERIAL *a,
unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->issuer,i2d_X509_NAME);
M_ASN1_I2D_len(a->serial,i2d_ASN1_INTEGER);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->issuer,i2d_X509_NAME);
M_ASN1_I2D_put(a->serial,i2d_ASN1_INTEGER);
M_ASN1_I2D_finish();
}
PKCS7_ISSUER_AND_SERIAL *d2i_PKCS7_ISSUER_AND_SERIAL(PKCS7_ISSUER_AND_SERIAL **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,PKCS7_ISSUER_AND_SERIAL *,PKCS7_ISSUER_AND_SERIAL_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->issuer,d2i_X509_NAME);
M_ASN1_D2I_get(ret->serial,d2i_ASN1_INTEGER);
M_ASN1_D2I_Finish(a,PKCS7_ISSUER_AND_SERIAL_free,
ASN1_F_D2I_PKCS7_ISSUER_AND_SERIAL);
}
PKCS7_ISSUER_AND_SERIAL *PKCS7_ISSUER_AND_SERIAL_new(void)
{
PKCS7_ISSUER_AND_SERIAL *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,PKCS7_ISSUER_AND_SERIAL);
M_ASN1_New(ret->issuer,X509_NAME_new);
M_ASN1_New(ret->serial,ASN1_INTEGER_new);
return(ret);
M_ASN1_New_Error(ASN1_F_PKCS7_ISSUER_AND_SERIAL_NEW);
}
void PKCS7_ISSUER_AND_SERIAL_free(PKCS7_ISSUER_AND_SERIAL *a)
{
if (a == NULL) return;
X509_NAME_free(a->issuer);
ASN1_INTEGER_free(a->serial);
Free((char *)a);
}
