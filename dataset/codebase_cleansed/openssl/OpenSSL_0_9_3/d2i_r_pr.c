ASN1_METHOD *RSAPrivateKey_asn1_meth(void)
{
return(&method);
}
RSA *d2i_RSAPrivateKey(RSA **a, unsigned char **pp, long length)
{
int i=ASN1_R_PARSING;
ASN1_INTEGER *bs=NULL;
M_ASN1_D2I_vars(a,RSA *,RSA_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if (bs->length == 0)
ret->version=0;
else ret->version=bs->data[0];
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->n=BN_bin2bn(bs->data,bs->length,ret->n)) == NULL) goto err_bn;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->e=BN_bin2bn(bs->data,bs->length,ret->e)) == NULL) goto err_bn;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->d=BN_bin2bn(bs->data,bs->length,ret->d)) == NULL) goto err_bn;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->p=BN_bin2bn(bs->data,bs->length,ret->p)) == NULL) goto err_bn;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->q=BN_bin2bn(bs->data,bs->length,ret->q)) == NULL) goto err_bn;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->dmp1=BN_bin2bn(bs->data,bs->length,ret->dmp1)) == NULL)
goto err_bn;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->dmq1=BN_bin2bn(bs->data,bs->length,ret->dmq1)) == NULL)
goto err_bn;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->iqmp=BN_bin2bn(bs->data,bs->length,ret->iqmp)) == NULL)
goto err_bn;
ASN1_INTEGER_free(bs);
M_ASN1_D2I_Finish_2(a);
err_bn:
i=ERR_R_BN_LIB;
err:
ASN1err(ASN1_F_D2I_RSAPRIVATEKEY,i);
if ((ret != NULL) && ((a == NULL) || (*a != ret))) RSA_free(ret);
if (bs != NULL) ASN1_INTEGER_free(bs);
return(NULL);
}
