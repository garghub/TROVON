ASN1_METHOD *X509_asn1_meth(void)
{
return(&meth);
}
int i2d_X509(X509 *a, unsigned char **pp)
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
X509 *d2i_X509(X509 **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,X509 *,X509_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->cert_info,d2i_X509_CINF);
M_ASN1_D2I_get(ret->sig_alg,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->signature,d2i_ASN1_BIT_STRING);
if (ret->name != NULL) Free(ret->name);
ret->name=X509_NAME_oneline(ret->cert_info->subject,NULL,0);
M_ASN1_D2I_Finish(a,X509_free,ASN1_F_D2I_X509);
}
X509 *X509_new(void)
{
X509 *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509);
ret->references=1;
ret->valid=0;
ret->ex_flags = 0;
ret->name=NULL;
ret->aux=NULL;
M_ASN1_New(ret->cert_info,X509_CINF_new);
M_ASN1_New(ret->sig_alg,X509_ALGOR_new);
M_ASN1_New(ret->signature,M_ASN1_BIT_STRING_new);
CRYPTO_new_ex_data(x509_meth, ret, &ret->ex_data);
return(ret);
M_ASN1_New_Error(ASN1_F_X509_NEW);
}
void X509_free(X509 *a)
{
int i;
if (a == NULL) return;
i=CRYPTO_add(&a->references,-1,CRYPTO_LOCK_X509);
#ifdef REF_PRINT
REF_PRINT("X509",a);
#endif
if (i > 0) return;
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"X509_free, bad reference count\n");
abort();
}
#endif
CRYPTO_free_ex_data(x509_meth,a,&a->ex_data);
X509_CINF_free(a->cert_info);
X509_ALGOR_free(a->sig_alg);
M_ASN1_BIT_STRING_free(a->signature);
X509_CERT_AUX_free(a->aux);
if (a->name != NULL) Free(a->name);
Free(a);
}
int X509_get_ex_new_index(long argl, void *argp, CRYPTO_EX_new *new_func,
CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func)
{
x509_meth_num++;
return(CRYPTO_get_ex_new_index(x509_meth_num-1,
&x509_meth,argl,argp,new_func,dup_func,free_func));
}
int X509_set_ex_data(X509 *r, int idx, void *arg)
{
return(CRYPTO_set_ex_data(&r->ex_data,idx,arg));
}
void *X509_get_ex_data(X509 *r, int idx)
{
return(CRYPTO_get_ex_data(&r->ex_data,idx));
}
X509 *d2i_X509_AUX(X509 **a, unsigned char **pp, long length)
{
unsigned char *q;
X509 *ret;
q = *pp;
ret = d2i_X509(a, pp, length);
if(!ret) return NULL;
length -= *pp - q;
if(!length) return ret;
if(!d2i_X509_CERT_AUX(&ret->aux, pp, length)) goto err;
return ret;
err:
X509_free(ret);
return NULL;
}
int i2d_X509_AUX(X509 *a, unsigned char **pp)
{
int length;
length = i2d_X509(a, pp);
if(a) length += i2d_X509_CERT_AUX(a->aux, pp);
return length;
}
