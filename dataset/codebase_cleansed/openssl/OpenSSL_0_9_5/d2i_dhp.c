DH *d2i_DHparams(DH **a, unsigned char **pp, long length)
{
int i=ERR_R_NESTED_ASN1_ERROR;
ASN1_INTEGER *bs=NULL;
long v=0;
M_ASN1_D2I_vars(a,DH *,DH_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->p=BN_bin2bn(bs->data,bs->length,ret->p)) == NULL) goto err_bn;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->g=BN_bin2bn(bs->data,bs->length,ret->g)) == NULL) goto err_bn;
if (!M_ASN1_D2I_end_sequence())
{
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
for (i=0; i<bs->length; i++)
v=(v<<8)|(bs->data[i]);
ret->length=(int)v;
}
M_ASN1_BIT_STRING_free(bs);
M_ASN1_D2I_Finish_2(a);
err_bn:
i=ERR_R_BN_LIB;
err:
ASN1err(ASN1_F_D2I_DHPARAMS,i);
if ((ret != NULL) && ((a == NULL) || (*a != ret))) DH_free(ret);
if (bs != NULL) M_ASN1_BIT_STRING_free(bs);
return(NULL);
}
