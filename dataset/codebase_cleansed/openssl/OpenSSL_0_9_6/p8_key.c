int i2d_X509_KEY(X509 *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->cert_info, i2d_X509_CINF);
M_ASN1_I2D_len(a->sig_alg, i2d_X509_ALGOR);
M_ASN1_I2D_len(a->signature, i2d_ASN1_BIT_STRING);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->cert_info, i2d_X509_CINF);
M_ASN1_I2D_put(a->sig_alg, i2d_X509_ALGOR);
M_ASN1_I2D_put(a->signature, i2d_ASN1_BIT_STRING);
M_ASN1_I2D_finish();
}
X509 *d2i_X509_KEY(X509 **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,X509 *,X509_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->cert_info,d2i_X509_CINF);
M_ASN1_D2I_get(ret->sig_alg,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->signature,d2i_ASN1_BIT_STRING);
M_ASN1_D2I_Finish(a,X509_free,ASN1_F_D2I_X509);
}
X509 *X509_KEY_new(void)
{
X509_KEY *ret=NULL;
M_ASN1_New_OPENSSL_malloc(ret,X509_KEY);
ret->references=1;
ret->type=NID
M_ASN1_New(ret->cert_info,X509_CINF_new);
M_ASN1_New(ret->sig_alg,X509_ALGOR_new);
M_ASN1_New(ret->signature,ASN1_BIT_STRING_new);
return(ret);
M_ASN1_New_Error(ASN1_F_X509_NEW);
}
void X509_KEY_free(X509 *a)
{
int i;
if (a == NULL) return;
i=CRYPTO_add_lock(&a->references,-1,CRYPTO_LOCK_X509_KEY);
#ifdef REF_PRINT
REF_PRINT("X509_KEY",a);
#endif
if (i > 0) return;
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"X509_KEY_free, bad reference count\n");
abort();
}
#endif
X509_CINF_free(a->cert_info);
X509_ALGOR_free(a->sig_alg);
ASN1_BIT_STRING_free(a->signature);
OPENSSL_free(a);
}
