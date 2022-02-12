int i2d_X509_SIG(X509_SIG *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->algor, i2d_X509_ALGOR);
M_ASN1_I2D_len(a->digest, i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->algor, i2d_X509_ALGOR);
M_ASN1_I2D_put(a->digest, i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_finish();
}
X509_SIG *d2i_X509_SIG(X509_SIG **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,X509_SIG *,X509_SIG_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->algor,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->digest,d2i_ASN1_OCTET_STRING);
M_ASN1_D2I_Finish(a,X509_SIG_free,ASN1_F_D2I_X509_SIG);
}
X509_SIG *X509_SIG_new(void)
{
X509_SIG *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_SIG);
M_ASN1_New(ret->algor,X509_ALGOR_new);
M_ASN1_New(ret->digest,M_ASN1_OCTET_STRING_new);
return(ret);
M_ASN1_New_Error(ASN1_F_X509_SIG_NEW);
}
void X509_SIG_free(X509_SIG *a)
{
if (a == NULL) return;
X509_ALGOR_free(a->algor);
M_ASN1_OCTET_STRING_free(a->digest);
OPENSSL_free(a);
}
