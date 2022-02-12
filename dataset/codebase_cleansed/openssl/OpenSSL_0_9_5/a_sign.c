int ASN1_sign(int (*i2d)(), X509_ALGOR *algor1, X509_ALGOR *algor2,
ASN1_BIT_STRING *signature, char *data, EVP_PKEY *pkey,
const EVP_MD *type)
{
EVP_MD_CTX ctx;
unsigned char *p,*buf_in=NULL,*buf_out=NULL;
int i,inl=0,outl=0,outll=0;
X509_ALGOR *a;
for (i=0; i<2; i++)
{
if (i == 0)
a=algor1;
else
a=algor2;
if (a == NULL) continue;
if ( (a->parameter == NULL) ||
(a->parameter->type != V_ASN1_NULL))
{
ASN1_TYPE_free(a->parameter);
if ((a->parameter=ASN1_TYPE_new()) == NULL) goto err;
a->parameter->type=V_ASN1_NULL;
}
ASN1_OBJECT_free(a->algorithm);
a->algorithm=OBJ_nid2obj(type->pkey_type);
if (a->algorithm == NULL)
{
ASN1err(ASN1_F_ASN1_SIGN,ASN1_R_UNKNOWN_OBJECT_TYPE);
goto err;
}
if (a->algorithm->length == 0)
{
ASN1err(ASN1_F_ASN1_SIGN,ASN1_R_THE_ASN1_OBJECT_IDENTIFIER_IS_NOT_KNOWN_FOR_THIS_MD);
goto err;
}
}
inl=i2d(data,NULL);
buf_in=(unsigned char *)Malloc((unsigned int)inl);
outll=outl=EVP_PKEY_size(pkey);
buf_out=(unsigned char *)Malloc((unsigned int)outl);
if ((buf_in == NULL) || (buf_out == NULL))
{
outl=0;
ASN1err(ASN1_F_ASN1_SIGN,ERR_R_MALLOC_FAILURE);
goto err;
}
p=buf_in;
i2d(data,&p);
EVP_SignInit(&ctx,type);
EVP_SignUpdate(&ctx,(unsigned char *)buf_in,inl);
if (!EVP_SignFinal(&ctx,(unsigned char *)buf_out,
(unsigned int *)&outl,pkey))
{
outl=0;
ASN1err(ASN1_F_ASN1_SIGN,ERR_R_EVP_LIB);
goto err;
}
if (signature->data != NULL) Free(signature->data);
signature->data=buf_out;
buf_out=NULL;
signature->length=outl;
signature->flags&= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07);
signature->flags|=ASN1_STRING_FLAG_BITS_LEFT;
err:
memset(&ctx,0,sizeof(ctx));
if (buf_in != NULL)
{ memset((char *)buf_in,0,(unsigned int)inl); Free(buf_in); }
if (buf_out != NULL)
{ memset((char *)buf_out,0,outll); Free(buf_out); }
return(outl);
}
