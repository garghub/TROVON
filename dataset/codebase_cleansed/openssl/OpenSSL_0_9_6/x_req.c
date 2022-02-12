int i2d_X509_REQ_INFO(X509_REQ_INFO *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
if(a->asn1) {
if(pp) {
memcpy(*pp, a->asn1, a->length);
*pp += a->length;
}
return a->length;
}
M_ASN1_I2D_len(a->version, i2d_ASN1_INTEGER);
M_ASN1_I2D_len(a->subject, i2d_X509_NAME);
M_ASN1_I2D_len(a->pubkey, i2d_X509_PUBKEY);
if (a->req_kludge)
{
M_ASN1_I2D_len_IMP_SET_opt_type(X509_ATTRIBUTE,a->attributes,i2d_X509_ATTRIBUTE,0);
}
else
{
M_ASN1_I2D_len_IMP_SET_type(X509_ATTRIBUTE,a->attributes,
i2d_X509_ATTRIBUTE,0);
}
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->version, i2d_ASN1_INTEGER);
M_ASN1_I2D_put(a->subject, i2d_X509_NAME);
M_ASN1_I2D_put(a->pubkey, i2d_X509_PUBKEY);
if (a->req_kludge)
{
M_ASN1_I2D_put_IMP_SET_opt_type(X509_ATTRIBUTE,a->attributes,
i2d_X509_ATTRIBUTE,0);
}
else
{
M_ASN1_I2D_put_IMP_SET_type(X509_ATTRIBUTE,a->attributes,
i2d_X509_ATTRIBUTE,0);
}
M_ASN1_I2D_finish();
}
X509_REQ_INFO *d2i_X509_REQ_INFO(X509_REQ_INFO **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,X509_REQ_INFO *,X509_REQ_INFO_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->version,d2i_ASN1_INTEGER);
M_ASN1_D2I_get(ret->subject,d2i_X509_NAME);
M_ASN1_D2I_get(ret->pubkey,d2i_X509_PUBKEY);
if (asn1_Finish(&c))
ret->req_kludge=1;
else
{
M_ASN1_D2I_get_IMP_set_type(X509_ATTRIBUTE,ret->attributes,
d2i_X509_ATTRIBUTE,
X509_ATTRIBUTE_free,0);
}
M_ASN1_D2I_Finish(a,X509_REQ_INFO_free,ASN1_F_D2I_X509_REQ_INFO);
}
X509_REQ_INFO *X509_REQ_INFO_new(void)
{
X509_REQ_INFO *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_REQ_INFO);
M_ASN1_New(ret->version,M_ASN1_INTEGER_new);
M_ASN1_New(ret->subject,X509_NAME_new);
M_ASN1_New(ret->pubkey,X509_PUBKEY_new);
M_ASN1_New(ret->attributes,sk_X509_ATTRIBUTE_new_null);
ret->req_kludge=0;
ret->asn1 = NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_X509_REQ_INFO_NEW);
}
void X509_REQ_INFO_free(X509_REQ_INFO *a)
{
if (a == NULL) return;
if(a->asn1) OPENSSL_free(a->asn1);
M_ASN1_INTEGER_free(a->version);
X509_NAME_free(a->subject);
X509_PUBKEY_free(a->pubkey);
sk_X509_ATTRIBUTE_pop_free(a->attributes,X509_ATTRIBUTE_free);
OPENSSL_free(a);
}
int i2d_X509_REQ(X509_REQ *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->req_info, i2d_X509_REQ_INFO);
M_ASN1_I2D_len(a->sig_alg, i2d_X509_ALGOR);
M_ASN1_I2D_len(a->signature, i2d_ASN1_BIT_STRING);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->req_info, i2d_X509_REQ_INFO);
M_ASN1_I2D_put(a->sig_alg, i2d_X509_ALGOR);
M_ASN1_I2D_put(a->signature, i2d_ASN1_BIT_STRING);
M_ASN1_I2D_finish();
}
X509_REQ *d2i_X509_REQ(X509_REQ **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,X509_REQ *,X509_REQ_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->req_info,d2i_X509_REQ_INFO);
ret->req_info->length = c.p - c.q;
if(!(ret->req_info->asn1 = OPENSSL_malloc(ret->req_info->length))) {
c.line=__LINE__;
c.error = ERR_R_MALLOC_FAILURE;
goto err;
}
memcpy(ret->req_info->asn1, c.q, ret->req_info->length);
M_ASN1_D2I_get(ret->sig_alg,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->signature,d2i_ASN1_BIT_STRING);
M_ASN1_D2I_Finish(a,X509_REQ_free,ASN1_F_D2I_X509_REQ);
}
X509_REQ *X509_REQ_new(void)
{
X509_REQ *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_REQ);
ret->references=1;
M_ASN1_New(ret->req_info,X509_REQ_INFO_new);
M_ASN1_New(ret->sig_alg,X509_ALGOR_new);
M_ASN1_New(ret->signature,M_ASN1_BIT_STRING_new);
return(ret);
M_ASN1_New_Error(ASN1_F_X509_REQ_NEW);
}
void X509_REQ_free(X509_REQ *a)
{
int i;
if (a == NULL) return;
i=CRYPTO_add(&a->references,-1,CRYPTO_LOCK_X509_REQ);
#ifdef REF_PRINT
REF_PRINT("X509_REQ",a);
#endif
if (i > 0) return;
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"X509_REQ_free, bad reference count\n");
abort();
}
#endif
X509_REQ_INFO_free(a->req_info);
X509_ALGOR_free(a->sig_alg);
M_ASN1_BIT_STRING_free(a->signature);
OPENSSL_free(a);
}
