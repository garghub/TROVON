int i2d_X509_ALGOR(X509_ALGOR *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->algorithm,i2d_ASN1_OBJECT);
if (a->parameter != NULL)
{ M_ASN1_I2D_len(a->parameter,i2d_ASN1_TYPE); }
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->algorithm,i2d_ASN1_OBJECT);
if (a->parameter != NULL)
{ M_ASN1_I2D_put(a->parameter,i2d_ASN1_TYPE); }
M_ASN1_I2D_finish();
}
X509_ALGOR *d2i_X509_ALGOR(X509_ALGOR **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,X509_ALGOR *,X509_ALGOR_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->algorithm,d2i_ASN1_OBJECT);
if (!M_ASN1_D2I_end_sequence())
{ M_ASN1_D2I_get(ret->parameter,d2i_ASN1_TYPE); }
else
{
ASN1_TYPE_free(ret->parameter);
ret->parameter=NULL;
}
M_ASN1_D2I_Finish(a,X509_ALGOR_free,ASN1_F_D2I_X509_ALGOR);
}
X509_ALGOR *X509_ALGOR_new(void)
{
X509_ALGOR *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_ALGOR);
ret->algorithm=OBJ_nid2obj(NID_undef);
ret->parameter=NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_X509_ALGOR_NEW);
}
void X509_ALGOR_free(X509_ALGOR *a)
{
if (a == NULL) return;
ASN1_OBJECT_free(a->algorithm);
ASN1_TYPE_free(a->parameter);
OPENSSL_free(a);
}
