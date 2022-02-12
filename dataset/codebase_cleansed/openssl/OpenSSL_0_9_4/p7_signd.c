int i2d_PKCS7_SIGNED(PKCS7_SIGNED *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->version,i2d_ASN1_INTEGER);
M_ASN1_I2D_len_SET_type(X509_ALGOR,a->md_algs,i2d_X509_ALGOR);
M_ASN1_I2D_len(a->contents,i2d_PKCS7);
M_ASN1_I2D_len_IMP_SEQUENCE_opt_type(X509,a->cert,i2d_X509,0);
M_ASN1_I2D_len_IMP_SET_opt_type(X509_CRL,a->crl,i2d_X509_CRL,1);
M_ASN1_I2D_len_SET_type(PKCS7_SIGNER_INFO,a->signer_info,
i2d_PKCS7_SIGNER_INFO);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->version,i2d_ASN1_INTEGER);
M_ASN1_I2D_put_SET_type(X509_ALGOR,a->md_algs,i2d_X509_ALGOR);
M_ASN1_I2D_put(a->contents,i2d_PKCS7);
M_ASN1_I2D_put_IMP_SEQUENCE_opt_type(X509,a->cert,i2d_X509,0);
M_ASN1_I2D_put_IMP_SET_opt_type(X509_CRL,a->crl,i2d_X509_CRL,1);
M_ASN1_I2D_put_SET_type(PKCS7_SIGNER_INFO,a->signer_info,
i2d_PKCS7_SIGNER_INFO);
M_ASN1_I2D_finish();
}
PKCS7_SIGNED *d2i_PKCS7_SIGNED(PKCS7_SIGNED **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,PKCS7_SIGNED *,PKCS7_SIGNED_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->version,d2i_ASN1_INTEGER);
M_ASN1_D2I_get_set_type(X509_ALGOR,ret->md_algs,d2i_X509_ALGOR,
X509_ALGOR_free);
M_ASN1_D2I_get(ret->contents,d2i_PKCS7);
M_ASN1_D2I_get_IMP_set_opt_type(X509,ret->cert,d2i_X509,X509_free,0);
M_ASN1_D2I_get_IMP_set_opt_type(X509_CRL,ret->crl,d2i_X509_CRL,
X509_CRL_free,1);
M_ASN1_D2I_get_set_type(PKCS7_SIGNER_INFO,ret->signer_info,
d2i_PKCS7_SIGNER_INFO,PKCS7_SIGNER_INFO_free);
M_ASN1_D2I_Finish(a,PKCS7_SIGNED_free,ASN1_F_D2I_PKCS7_SIGNED);
}
PKCS7_SIGNED *PKCS7_SIGNED_new(void)
{
PKCS7_SIGNED *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,PKCS7_SIGNED);
M_ASN1_New(ret->version,ASN1_INTEGER_new);
M_ASN1_New(ret->md_algs,sk_X509_ALGOR_new_null);
M_ASN1_New(ret->contents,PKCS7_new);
ret->cert=NULL;
ret->crl=NULL;
M_ASN1_New(ret->signer_info,sk_PKCS7_SIGNER_INFO_new_null);
return(ret);
M_ASN1_New_Error(ASN1_F_PKCS7_SIGNED_NEW);
}
void PKCS7_SIGNED_free(PKCS7_SIGNED *a)
{
if (a == NULL) return;
ASN1_INTEGER_free(a->version);
sk_X509_ALGOR_pop_free(a->md_algs,X509_ALGOR_free);
PKCS7_free(a->contents);
sk_X509_pop_free(a->cert,X509_free);
sk_X509_CRL_pop_free(a->crl,X509_CRL_free);
sk_PKCS7_SIGNER_INFO_pop_free(a->signer_info,PKCS7_SIGNER_INFO_free);
Free(a);
}
