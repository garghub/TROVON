int ASN1_verify(int (*i2d)(), X509_ALGOR *a, ASN1_BIT_STRING *signature,
char *data, EVP_PKEY *pkey)
{
EVP_MD_CTX ctx;
const EVP_MD *type;
unsigned char *p,*buf_in=NULL;
int ret= -1,i,inl;
EVP_MD_CTX_init(&ctx);
i=OBJ_obj2nid(a->algorithm);
type=EVP_get_digestbyname(OBJ_nid2sn(i));
if (type == NULL)
{
ASN1err(ASN1_F_ASN1_VERIFY,ASN1_R_UNKNOWN_MESSAGE_DIGEST_ALGORITHM);
goto err;
}
inl=i2d(data,NULL);
buf_in=OPENSSL_malloc((unsigned int)inl);
if (buf_in == NULL)
{
ASN1err(ASN1_F_ASN1_VERIFY,ERR_R_MALLOC_FAILURE);
goto err;
}
p=buf_in;
i2d(data,&p);
EVP_VerifyInit_ex(&ctx,type, NULL);
EVP_VerifyUpdate(&ctx,(unsigned char *)buf_in,inl);
OPENSSL_cleanse(buf_in,(unsigned int)inl);
OPENSSL_free(buf_in);
if (EVP_VerifyFinal(&ctx,(unsigned char *)signature->data,
(unsigned int)signature->length,pkey) <= 0)
{
ASN1err(ASN1_F_ASN1_VERIFY,ERR_R_EVP_LIB);
ret=0;
goto err;
}
ret=1;
err:
EVP_MD_CTX_cleanup(&ctx);
return(ret);
}
int ASN1_item_verify(const ASN1_ITEM *it, X509_ALGOR *a, ASN1_BIT_STRING *signature,
void *asn, EVP_PKEY *pkey)
{
EVP_MD_CTX ctx;
const EVP_MD *type;
unsigned char *buf_in=NULL;
int ret= -1,i,inl;
EVP_MD_CTX_init(&ctx);
i=OBJ_obj2nid(a->algorithm);
type=EVP_get_digestbyname(OBJ_nid2sn(i));
if (type == NULL)
{
ASN1err(ASN1_F_ASN1_VERIFY,ASN1_R_UNKNOWN_MESSAGE_DIGEST_ALGORITHM);
goto err;
}
inl = ASN1_item_i2d(asn, &buf_in, it);
if (buf_in == NULL)
{
ASN1err(ASN1_F_ASN1_VERIFY,ERR_R_MALLOC_FAILURE);
goto err;
}
EVP_VerifyInit_ex(&ctx,type, NULL);
EVP_VerifyUpdate(&ctx,(unsigned char *)buf_in,inl);
OPENSSL_cleanse(buf_in,(unsigned int)inl);
OPENSSL_free(buf_in);
if (EVP_VerifyFinal(&ctx,(unsigned char *)signature->data,
(unsigned int)signature->length,pkey) <= 0)
{
ASN1err(ASN1_F_ASN1_VERIFY,ERR_R_EVP_LIB);
ret=0;
goto err;
}
ret=1;
err:
EVP_MD_CTX_cleanup(&ctx);
return(ret);
}
