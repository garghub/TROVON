int i2d_X509_CINF(X509_CINF *a, unsigned char **pp)
{
int v1=0,v2=0;
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len_EXP_opt(a->version,i2d_ASN1_INTEGER,0,v1);
M_ASN1_I2D_len(a->serialNumber, i2d_ASN1_INTEGER);
M_ASN1_I2D_len(a->signature, i2d_X509_ALGOR);
M_ASN1_I2D_len(a->issuer, i2d_X509_NAME);
M_ASN1_I2D_len(a->validity, i2d_X509_VAL);
M_ASN1_I2D_len(a->subject, i2d_X509_NAME);
M_ASN1_I2D_len(a->key, i2d_X509_PUBKEY);
M_ASN1_I2D_len_IMP_opt(a->issuerUID, i2d_ASN1_BIT_STRING);
M_ASN1_I2D_len_IMP_opt(a->subjectUID, i2d_ASN1_BIT_STRING);
M_ASN1_I2D_len_EXP_SEQUENCE_opt_type(X509_EXTENSION,a->extensions,
i2d_X509_EXTENSION,3,
V_ASN1_SEQUENCE,v2);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put_EXP_opt(a->version,i2d_ASN1_INTEGER,0,v1);
M_ASN1_I2D_put(a->serialNumber, i2d_ASN1_INTEGER);
M_ASN1_I2D_put(a->signature, i2d_X509_ALGOR);
M_ASN1_I2D_put(a->issuer, i2d_X509_NAME);
M_ASN1_I2D_put(a->validity, i2d_X509_VAL);
M_ASN1_I2D_put(a->subject, i2d_X509_NAME);
M_ASN1_I2D_put(a->key, i2d_X509_PUBKEY);
M_ASN1_I2D_put_IMP_opt(a->issuerUID, i2d_ASN1_BIT_STRING,1);
M_ASN1_I2D_put_IMP_opt(a->subjectUID, i2d_ASN1_BIT_STRING,2);
M_ASN1_I2D_put_EXP_SEQUENCE_opt_type(X509_EXTENSION,a->extensions,
i2d_X509_EXTENSION,3,
V_ASN1_SEQUENCE,v2);
M_ASN1_I2D_finish();
}
X509_CINF *d2i_X509_CINF(X509_CINF **a, unsigned char **pp, long length)
{
int ver=0;
M_ASN1_D2I_vars(a,X509_CINF *,X509_CINF_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
if (M_ASN1_next == (V_ASN1_CONTEXT_SPECIFIC | V_ASN1_CONSTRUCTED | 0))
{
M_ASN1_D2I_get_EXP_opt(ret->version,d2i_ASN1_INTEGER,0);
if (ret->version->data != NULL)
ver=ret->version->data[0];
}
else
{
if (ret->version != NULL)
{
ASN1_INTEGER_free(ret->version);
ret->version=NULL;
}
}
M_ASN1_D2I_get(ret->serialNumber,d2i_ASN1_INTEGER);
M_ASN1_D2I_get(ret->signature,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->issuer,d2i_X509_NAME);
M_ASN1_D2I_get(ret->validity,d2i_X509_VAL);
M_ASN1_D2I_get(ret->subject,d2i_X509_NAME);
M_ASN1_D2I_get(ret->key,d2i_X509_PUBKEY);
if (ver >= 1)
{
if (ret->issuerUID != NULL)
{
ASN1_BIT_STRING_free(ret->issuerUID);
ret->issuerUID=NULL;
}
if (ret->subjectUID != NULL)
{
ASN1_BIT_STRING_free(ret->subjectUID);
ret->subjectUID=NULL;
}
M_ASN1_D2I_get_IMP_opt(ret->issuerUID,d2i_ASN1_BIT_STRING, 1,
V_ASN1_BIT_STRING);
M_ASN1_D2I_get_IMP_opt(ret->subjectUID,d2i_ASN1_BIT_STRING, 2,
V_ASN1_BIT_STRING);
}
#ifdef VERSION_EXT_CHECK
if (ver >= 2)
#endif
{
if (ret->extensions != NULL)
while (sk_X509_EXTENSION_num(ret->extensions))
X509_EXTENSION_free(
sk_X509_EXTENSION_pop(ret->extensions));
M_ASN1_D2I_get_EXP_set_opt_type(X509_EXTENSION,ret->extensions,
d2i_X509_EXTENSION,
X509_EXTENSION_free,3,
V_ASN1_SEQUENCE);
}
M_ASN1_D2I_Finish(a,X509_CINF_free,ASN1_F_D2I_X509_CINF);
}
X509_CINF *X509_CINF_new(void)
{
X509_CINF *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_CINF);
ret->version=NULL;
M_ASN1_New(ret->serialNumber,ASN1_INTEGER_new);
M_ASN1_New(ret->signature,X509_ALGOR_new);
M_ASN1_New(ret->issuer,X509_NAME_new);
M_ASN1_New(ret->validity,X509_VAL_new);
M_ASN1_New(ret->subject,X509_NAME_new);
M_ASN1_New(ret->key,X509_PUBKEY_new);
ret->issuerUID=NULL;
ret->subjectUID=NULL;
ret->extensions=NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_X509_CINF_NEW);
}
void X509_CINF_free(X509_CINF *a)
{
if (a == NULL) return;
ASN1_INTEGER_free(a->version);
ASN1_INTEGER_free(a->serialNumber);
X509_ALGOR_free(a->signature);
X509_NAME_free(a->issuer);
X509_VAL_free(a->validity);
X509_NAME_free(a->subject);
X509_PUBKEY_free(a->key);
ASN1_BIT_STRING_free(a->issuerUID);
ASN1_BIT_STRING_free(a->subjectUID);
sk_X509_EXTENSION_pop_free(a->extensions,X509_EXTENSION_free);
Free(a);
}
