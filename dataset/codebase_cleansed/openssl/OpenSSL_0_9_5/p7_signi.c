int i2d_PKCS7_SIGNER_INFO(PKCS7_SIGNER_INFO *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->version,i2d_ASN1_INTEGER);
M_ASN1_I2D_len(a->issuer_and_serial,i2d_PKCS7_ISSUER_AND_SERIAL);
M_ASN1_I2D_len(a->digest_alg,i2d_X509_ALGOR);
M_ASN1_I2D_len_IMP_SET_opt_type(X509_ATTRIBUTE,a->auth_attr,
i2d_X509_ATTRIBUTE,0);
M_ASN1_I2D_len(a->digest_enc_alg,i2d_X509_ALGOR);
M_ASN1_I2D_len(a->enc_digest,i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_len_IMP_SET_opt_type(X509_ATTRIBUTE,a->unauth_attr,
i2d_X509_ATTRIBUTE,1);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->version,i2d_ASN1_INTEGER);
M_ASN1_I2D_put(a->issuer_and_serial,i2d_PKCS7_ISSUER_AND_SERIAL);
M_ASN1_I2D_put(a->digest_alg,i2d_X509_ALGOR);
M_ASN1_I2D_put_IMP_SET_opt_type(X509_ATTRIBUTE,a->auth_attr,
i2d_X509_ATTRIBUTE,0);
M_ASN1_I2D_put(a->digest_enc_alg,i2d_X509_ALGOR);
M_ASN1_I2D_put(a->enc_digest,i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_put_IMP_SET_opt_type(X509_ATTRIBUTE,a->unauth_attr,
i2d_X509_ATTRIBUTE,1);
M_ASN1_I2D_finish();
}
PKCS7_SIGNER_INFO *d2i_PKCS7_SIGNER_INFO(PKCS7_SIGNER_INFO **a,
unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,PKCS7_SIGNER_INFO *,PKCS7_SIGNER_INFO_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->version,d2i_ASN1_INTEGER);
M_ASN1_D2I_get(ret->issuer_and_serial,d2i_PKCS7_ISSUER_AND_SERIAL);
M_ASN1_D2I_get(ret->digest_alg,d2i_X509_ALGOR);
M_ASN1_D2I_get_IMP_set_opt_type(X509_ATTRIBUTE,ret->auth_attr,
d2i_X509_ATTRIBUTE,X509_ATTRIBUTE_free,
0);
M_ASN1_D2I_get(ret->digest_enc_alg,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->enc_digest,d2i_ASN1_OCTET_STRING);
M_ASN1_D2I_get_IMP_set_opt_type(X509_ATTRIBUTE,ret->unauth_attr,
d2i_X509_ATTRIBUTE,
X509_ATTRIBUTE_free,1);
M_ASN1_D2I_Finish(a,PKCS7_SIGNER_INFO_free,
ASN1_F_D2I_PKCS7_SIGNER_INFO);
}
PKCS7_SIGNER_INFO *PKCS7_SIGNER_INFO_new(void)
{
PKCS7_SIGNER_INFO *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,PKCS7_SIGNER_INFO);
M_ASN1_New(ret->version,M_ASN1_INTEGER_new);
M_ASN1_New(ret->issuer_and_serial,PKCS7_ISSUER_AND_SERIAL_new);
M_ASN1_New(ret->digest_alg,X509_ALGOR_new);
ret->auth_attr=NULL;
M_ASN1_New(ret->digest_enc_alg,X509_ALGOR_new);
M_ASN1_New(ret->enc_digest,M_ASN1_OCTET_STRING_new);
ret->unauth_attr=NULL;
ret->pkey=NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_PKCS7_SIGNER_INFO_NEW);
}
void PKCS7_SIGNER_INFO_free(PKCS7_SIGNER_INFO *a)
{
if (a == NULL) return;
M_ASN1_INTEGER_free(a->version);
PKCS7_ISSUER_AND_SERIAL_free(a->issuer_and_serial);
X509_ALGOR_free(a->digest_alg);
sk_X509_ATTRIBUTE_pop_free(a->auth_attr,X509_ATTRIBUTE_free);
X509_ALGOR_free(a->digest_enc_alg);
M_ASN1_OCTET_STRING_free(a->enc_digest);
sk_X509_ATTRIBUTE_pop_free(a->unauth_attr,X509_ATTRIBUTE_free);
if (a->pkey != NULL)
EVP_PKEY_free(a->pkey);
Free(a);
}
