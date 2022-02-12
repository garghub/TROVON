int i2d_ASN1_HEADER(ASN1_HEADER *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->header, i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_len(a->data, a->meth->i2d);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->header, i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_put(a->data, a->meth->i2d);
M_ASN1_I2D_finish();
}
ASN1_HEADER *d2i_ASN1_HEADER(ASN1_HEADER **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,ASN1_HEADER *,ASN1_HEADER_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->header,d2i_ASN1_OCTET_STRING);
if (ret->meth != NULL)
{
M_ASN1_D2I_get(ret->data,ret->meth->d2i);
}
else
{
if (a != NULL) (*a)=ret;
return(ret);
}
M_ASN1_D2I_Finish(a,ASN1_HEADER_free,ASN1_F_D2I_ASN1_HEADER);
}
ASN1_HEADER *ASN1_HEADER_new(void)
{
ASN1_HEADER *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,ASN1_HEADER);
M_ASN1_New(ret->header,ASN1_OCTET_STRING_new);
ret->meth=NULL;
ret->data=NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_ASN1_HEADER_NEW);
}
void ASN1_HEADER_free(ASN1_HEADER *a)
{
if (a == NULL) return;
ASN1_OCTET_STRING_free(a->header);
if (a->meth != NULL)
a->meth->destroy(a->data);
Free((char *)a);
}
