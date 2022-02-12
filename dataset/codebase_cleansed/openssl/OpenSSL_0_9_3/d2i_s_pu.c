DSA *d2i_DSAPublicKey(DSA **a, unsigned char **pp, long length)
{
int i=ASN1_R_PARSING;
ASN1_INTEGER *bs=NULL;
M_ASN1_D2I_vars(a,DSA *,DSA_new);
M_ASN1_D2I_Init();
if ((length != 0) && ((M_ASN1_next & (~V_ASN1_CONSTRUCTED))
== (V_ASN1_UNIVERSAL|(V_ASN1_INTEGER))))
{
c.slen=length;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->pub_key=BN_bin2bn(bs->data,bs->length,ret->pub_key))
== NULL)
goto err_bn;
ret->write_params=0;
}
else
{
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->pub_key=BN_bin2bn(bs->data,bs->length,ret->pub_key))
== NULL)
goto err_bn;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->p=BN_bin2bn(bs->data,bs->length,ret->p)) == NULL)
goto err_bn;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->q=BN_bin2bn(bs->data,bs->length,ret->q)) == NULL)
goto err_bn;
M_ASN1_D2I_get(bs,d2i_ASN1_INTEGER);
if ((ret->g=BN_bin2bn(bs->data,bs->length,ret->g)) == NULL)
goto err_bn;
ret->write_params=1;
}
ASN1_INTEGER_free(bs);
bs=NULL;
M_ASN1_D2I_Finish_2(a);
err_bn:
i=ERR_R_BN_LIB;
err:
ASN1err(ASN1_F_D2I_DSAPUBLICKEY,i);
if ((ret != NULL) && ((a == NULL) || (*a != ret))) DSA_free(ret);
if (bs != NULL) ASN1_INTEGER_free(bs);
return(NULL);
}
