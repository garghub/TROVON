int i2d_X509_REVOKED(X509_REVOKED *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->serialNumber,i2d_ASN1_INTEGER);
M_ASN1_I2D_len(a->revocationDate,i2d_ASN1_TIME);
M_ASN1_I2D_len_SEQUENCE_opt_type(X509_EXTENSION,a->extensions,
i2d_X509_EXTENSION);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->serialNumber,i2d_ASN1_INTEGER);
M_ASN1_I2D_put(a->revocationDate,i2d_ASN1_TIME);
M_ASN1_I2D_put_SEQUENCE_opt_type(X509_EXTENSION,a->extensions,
i2d_X509_EXTENSION);
M_ASN1_I2D_finish();
}
X509_REVOKED *d2i_X509_REVOKED(X509_REVOKED **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,X509_REVOKED *,X509_REVOKED_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->serialNumber,d2i_ASN1_INTEGER);
M_ASN1_D2I_get(ret->revocationDate,d2i_ASN1_TIME);
M_ASN1_D2I_get_seq_opt_type(X509_EXTENSION,ret->extensions,
d2i_X509_EXTENSION,X509_EXTENSION_free);
M_ASN1_D2I_Finish(a,X509_REVOKED_free,ASN1_F_D2I_X509_REVOKED);
}
int i2d_X509_CRL_INFO(X509_CRL_INFO *a, unsigned char **pp)
{
int v1=0;
long l=0;
M_ASN1_I2D_vars(a);
if (sk_num(a->revoked) != 0)
qsort((char *)a->revoked->data,sk_num(a->revoked),
sizeof(X509_REVOKED *),(int (*)(const void *,const void *))X509_REVOKED_seq_cmp);
if ((a->version != NULL) && ((l=ASN1_INTEGER_get(a->version)) != 0))
{
M_ASN1_I2D_len(a->version,i2d_ASN1_INTEGER);
}
M_ASN1_I2D_len(a->sig_alg,i2d_X509_ALGOR);
M_ASN1_I2D_len(a->issuer,i2d_X509_NAME);
M_ASN1_I2D_len(a->lastUpdate,i2d_ASN1_TIME);
if (a->nextUpdate != NULL)
{ M_ASN1_I2D_len(a->nextUpdate,i2d_ASN1_TIME); }
M_ASN1_I2D_len_SEQUENCE_opt(a->revoked,i2d_X509_REVOKED);
M_ASN1_I2D_len_EXP_SEQUENCE_opt_type(X509_EXTENSION,a->extensions,
i2d_X509_EXTENSION,0,
V_ASN1_SEQUENCE,v1);
M_ASN1_I2D_seq_total();
if ((a->version != NULL) && (l != 0))
{
M_ASN1_I2D_put(a->version,i2d_ASN1_INTEGER);
}
M_ASN1_I2D_put(a->sig_alg,i2d_X509_ALGOR);
M_ASN1_I2D_put(a->issuer,i2d_X509_NAME);
M_ASN1_I2D_put(a->lastUpdate,i2d_ASN1_UTCTIME);
if (a->nextUpdate != NULL)
{ M_ASN1_I2D_put(a->nextUpdate,i2d_ASN1_UTCTIME); }
M_ASN1_I2D_put_SEQUENCE_opt(a->revoked,i2d_X509_REVOKED);
M_ASN1_I2D_put_EXP_SEQUENCE_opt_type(X509_EXTENSION,a->extensions,
i2d_X509_EXTENSION,0,
V_ASN1_SEQUENCE,v1);
M_ASN1_I2D_finish();
}
X509_CRL_INFO *d2i_X509_CRL_INFO(X509_CRL_INFO **a, unsigned char **pp,
long length)
{
int i,ver=0;
M_ASN1_D2I_vars(a,X509_CRL_INFO *,X509_CRL_INFO_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get_opt(ret->version,d2i_ASN1_INTEGER,V_ASN1_INTEGER);
if (ret->version != NULL)
ver=ret->version->data[0];
if ((ver == 0) && (ret->version != NULL))
{
ASN1_INTEGER_free(ret->version);
ret->version=NULL;
}
M_ASN1_D2I_get(ret->sig_alg,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->issuer,d2i_X509_NAME);
M_ASN1_D2I_get(ret->lastUpdate,d2i_ASN1_TIME);
if(c.slen != 0
&& ( (M_ASN1_next & ~V_ASN1_CONSTRUCTED) ==
(V_ASN1_UNIVERSAL|V_ASN1_UTCTIME)
|| (M_ASN1_next & ~V_ASN1_CONSTRUCTED) ==
(V_ASN1_UNIVERSAL|V_ASN1_GENERALIZEDTIME) ) ) {
M_ASN1_D2I_get(ret->nextUpdate,d2i_ASN1_TIME);
}
if(!ret->nextUpdate)
M_ASN1_D2I_get_opt(ret->nextUpdate,d2i_ASN1_GENERALIZEDTIME,
V_ASN1_GENERALIZEDTIME);
if (ret->revoked != NULL)
{
while (sk_num(ret->revoked))
X509_REVOKED_free((X509_REVOKED *)sk_pop(ret->revoked));
}
M_ASN1_D2I_get_seq_opt(ret->revoked,d2i_X509_REVOKED,X509_REVOKED_free);
if (ret->revoked != NULL)
{
for (i=0; i<sk_num(ret->revoked); i++)
{
((X509_REVOKED *)sk_value(ret->revoked,i))->sequence=i;
}
}
if (ver >= 1)
{
if (ret->extensions != NULL)
{
while (sk_X509_EXTENSION_num(ret->extensions))
X509_EXTENSION_free(
sk_X509_EXTENSION_pop(ret->extensions));
}
M_ASN1_D2I_get_EXP_set_opt_type(X509_EXTENSION,ret->extensions,
d2i_X509_EXTENSION,
X509_EXTENSION_free,0,
V_ASN1_SEQUENCE);
}
M_ASN1_D2I_Finish(a,X509_CRL_INFO_free,ASN1_F_D2I_X509_CRL_INFO);
}
int i2d_X509_CRL(X509_CRL *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->crl,i2d_X509_CRL_INFO);
M_ASN1_I2D_len(a->sig_alg,i2d_X509_ALGOR);
M_ASN1_I2D_len(a->signature,i2d_ASN1_BIT_STRING);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->crl,i2d_X509_CRL_INFO);
M_ASN1_I2D_put(a->sig_alg,i2d_X509_ALGOR);
M_ASN1_I2D_put(a->signature,i2d_ASN1_BIT_STRING);
M_ASN1_I2D_finish();
}
X509_CRL *d2i_X509_CRL(X509_CRL **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,X509_CRL *,X509_CRL_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->crl,d2i_X509_CRL_INFO);
M_ASN1_D2I_get(ret->sig_alg,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->signature,d2i_ASN1_BIT_STRING);
M_ASN1_D2I_Finish(a,X509_CRL_free,ASN1_F_D2I_X509_CRL);
}
X509_REVOKED *X509_REVOKED_new(void)
{
X509_REVOKED *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_REVOKED);
M_ASN1_New(ret->serialNumber,ASN1_INTEGER_new);
M_ASN1_New(ret->revocationDate,ASN1_UTCTIME_new);
ret->extensions=NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_X509_REVOKED_NEW);
}
X509_CRL_INFO *X509_CRL_INFO_new(void)
{
X509_CRL_INFO *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_CRL_INFO);
ret->version=NULL;
M_ASN1_New(ret->sig_alg,X509_ALGOR_new);
M_ASN1_New(ret->issuer,X509_NAME_new);
M_ASN1_New(ret->lastUpdate,ASN1_UTCTIME_new);
ret->nextUpdate=NULL;
M_ASN1_New(ret->revoked,sk_new_null);
M_ASN1_New(ret->extensions,sk_X509_EXTENSION_new_null);
ret->revoked->comp=(int (*)())X509_REVOKED_cmp;
return(ret);
M_ASN1_New_Error(ASN1_F_X509_CRL_INFO_NEW);
}
X509_CRL *X509_CRL_new(void)
{
X509_CRL *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_CRL);
ret->references=1;
M_ASN1_New(ret->crl,X509_CRL_INFO_new);
M_ASN1_New(ret->sig_alg,X509_ALGOR_new);
M_ASN1_New(ret->signature,ASN1_BIT_STRING_new);
return(ret);
M_ASN1_New_Error(ASN1_F_X509_CRL_NEW);
}
void X509_REVOKED_free(X509_REVOKED *a)
{
if (a == NULL) return;
ASN1_INTEGER_free(a->serialNumber);
ASN1_UTCTIME_free(a->revocationDate);
sk_X509_EXTENSION_pop_free(a->extensions,X509_EXTENSION_free);
Free(a);
}
void X509_CRL_INFO_free(X509_CRL_INFO *a)
{
if (a == NULL) return;
ASN1_INTEGER_free(a->version);
X509_ALGOR_free(a->sig_alg);
X509_NAME_free(a->issuer);
ASN1_UTCTIME_free(a->lastUpdate);
if (a->nextUpdate)
ASN1_UTCTIME_free(a->nextUpdate);
sk_pop_free(a->revoked,X509_REVOKED_free);
sk_X509_EXTENSION_pop_free(a->extensions,X509_EXTENSION_free);
Free(a);
}
void X509_CRL_free(X509_CRL *a)
{
int i;
if (a == NULL) return;
i=CRYPTO_add(&a->references,-1,CRYPTO_LOCK_X509_CRL);
#ifdef REF_PRINT
REF_PRINT("X509_CRL",a);
#endif
if (i > 0) return;
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"X509_CRL_free, bad reference count\n");
abort();
}
#endif
X509_CRL_INFO_free(a->crl);
X509_ALGOR_free(a->sig_alg);
ASN1_BIT_STRING_free(a->signature);
Free(a);
}
static int X509_REVOKED_cmp(X509_REVOKED **a, X509_REVOKED **b)
{
return(ASN1_STRING_cmp(
(ASN1_STRING *)(*a)->serialNumber,
(ASN1_STRING *)(*b)->serialNumber));
}
static int X509_REVOKED_seq_cmp(X509_REVOKED **a, X509_REVOKED **b)
{
return((*a)->sequence-(*b)->sequence);
}
