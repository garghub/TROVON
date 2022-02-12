int i2d_X509_VAL(X509_VAL *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->notBefore,i2d_ASN1_TIME);
M_ASN1_I2D_len(a->notAfter,i2d_ASN1_TIME);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->notBefore,i2d_ASN1_TIME);
M_ASN1_I2D_put(a->notAfter,i2d_ASN1_TIME);
M_ASN1_I2D_finish();
}
X509_VAL *d2i_X509_VAL(X509_VAL **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,X509_VAL *,X509_VAL_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->notBefore,d2i_ASN1_TIME);
M_ASN1_D2I_get(ret->notAfter,d2i_ASN1_TIME);
M_ASN1_D2I_Finish(a,X509_VAL_free,ASN1_F_D2I_X509_VAL);
}
X509_VAL *X509_VAL_new(void)
{
X509_VAL *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_VAL);
M_ASN1_New(ret->notBefore,M_ASN1_TIME_new);
M_ASN1_New(ret->notAfter,M_ASN1_TIME_new);
return(ret);
M_ASN1_New_Error(ASN1_F_X509_VAL_NEW);
}
void X509_VAL_free(X509_VAL *a)
{
if (a == NULL) return;
M_ASN1_TIME_free(a->notBefore);
M_ASN1_TIME_free(a->notAfter);
Free(a);
}
