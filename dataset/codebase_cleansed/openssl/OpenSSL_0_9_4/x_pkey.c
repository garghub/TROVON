int i2d_X509_PKEY(X509_PKEY *a, unsigned char **pp)
{
return(0);
}
X509_PKEY *d2i_X509_PKEY(X509_PKEY **a, unsigned char **pp, long length)
{
int i;
M_ASN1_D2I_vars(a,X509_PKEY *,X509_PKEY_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->enc_algor,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->enc_pkey,d2i_ASN1_OCTET_STRING);
ret->cipher.cipher=EVP_get_cipherbyname(
OBJ_nid2ln(OBJ_obj2nid(ret->enc_algor->algorithm)));
if (ret->cipher.cipher == NULL)
{
c.error=ASN1_R_UNSUPPORTED_CIPHER;
c.line=__LINE__;
goto err;
}
if (ret->enc_algor->parameter->type == V_ASN1_OCTET_STRING)
{
i=ret->enc_algor->parameter->value.octet_string->length;
if (i > EVP_MAX_IV_LENGTH)
{
c.error=ASN1_R_IV_TOO_LARGE;
c.line=__LINE__;
goto err;
}
memcpy(ret->cipher.iv,
ret->enc_algor->parameter->value.octet_string->data,i);
}
else
memset(ret->cipher.iv,0,EVP_MAX_IV_LENGTH);
M_ASN1_D2I_Finish(a,X509_PKEY_free,ASN1_F_D2I_X509_PKEY);
}
X509_PKEY *X509_PKEY_new(void)
{
X509_PKEY *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_PKEY);
ret->version=0;
M_ASN1_New(ret->enc_algor,X509_ALGOR_new);
M_ASN1_New(ret->enc_pkey,ASN1_OCTET_STRING_new);
ret->dec_pkey=NULL;
ret->key_length=0;
ret->key_data=NULL;
ret->key_free=0;
ret->cipher.cipher=NULL;
memset(ret->cipher.iv,0,EVP_MAX_IV_LENGTH);
ret->references=1;
return(ret);
M_ASN1_New_Error(ASN1_F_X509_PKEY_NEW);
}
void X509_PKEY_free(X509_PKEY *x)
{
int i;
if (x == NULL) return;
i=CRYPTO_add(&x->references,-1,CRYPTO_LOCK_X509_PKEY);
#ifdef REF_PRINT
REF_PRINT("X509_PKEY",x);
#endif
if (i > 0) return;
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"X509_PKEY_free, bad reference count\n");
abort();
}
#endif
if (x->enc_algor != NULL) X509_ALGOR_free(x->enc_algor);
if (x->enc_pkey != NULL) ASN1_OCTET_STRING_free(x->enc_pkey);
if (x->dec_pkey != NULL)EVP_PKEY_free(x->dec_pkey);
if ((x->key_data != NULL) && (x->key_free)) Free((char *)x->key_data);
Free((char *)(char *)x);
}
