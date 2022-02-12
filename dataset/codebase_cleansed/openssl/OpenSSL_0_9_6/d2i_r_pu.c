RSA *d2i_RSAPublicKey(RSA **a, unsigned char **pp, long length)
{
int i=ASN1_R_PARSING;
ASN1_INTEGER *bs=NULL;
M_ASN1_D2I_vars(a,RSA *,RSA_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->n=BN_bin2bn(bs->data,bs->length,ret->n)) == NULL) goto err_bn;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->e=BN_bin2bn(bs->data,bs->length,ret->e)) == NULL) goto err_bn;
M_ASN1_INTEGER_free(bs);
bs=NULL;
M_ASN1_D2I_Finish_2(a);
err_bn:
i=ERR_R_BN_LIB;
err:
ASN1err(ASN1_F_D2I_RSAPUBLICKEY,i);
if ((ret != NULL) && ((a == NULL) || (*a != ret))) RSA_free(ret);
if (bs != NULL) M_ASN1_INTEGER_free(bs);
return(NULL);
}
