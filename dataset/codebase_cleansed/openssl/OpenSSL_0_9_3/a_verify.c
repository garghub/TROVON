int ASN1_verify(int (*i2d)(), X509_ALGOR *a, ASN1_BIT_STRING *signature,
char *data, EVP_PKEY *pkey)
{
EVP_MD_CTX ctx;
const EVP_MD *type;
unsigned char *p,*buf_in=NULL;
int ret= -1,i,inl;
i=OBJ_obj2nid(a->algorithm);
type=EVP_get_digestbyname(OBJ_nid2sn(i));
if (type == NULL)
{
ASN1err(ASN1_F_ASN1_VERIFY,ASN1_R_UNKNOWN_MESSAGE_DIGEST_ALGORITHM);
goto err;
}
inl=i2d(data,NULL);
buf_in=Malloc((unsigned int)inl);
if (buf_in == NULL)
{
ASN1err(ASN1_F_ASN1_VERIFY,ERR_R_MALLOC_FAILURE);
goto err;
}
p=buf_in;
i2d(data,&p);
EVP_VerifyInit(&ctx,type);
EVP_VerifyUpdate(&ctx,(unsigned char *)buf_in,inl);
memset(buf_in,0,(unsigned int)inl);
Free((char *)buf_in);
if (EVP_VerifyFinal(&ctx,(unsigned char *)signature->data,
(unsigned int)signature->length,pkey) <= 0)
{
ASN1err(ASN1_F_ASN1_VERIFY,ERR_R_EVP_LIB);
ret=0;
goto err;
}
ret=1;
err:
return(ret);
}
