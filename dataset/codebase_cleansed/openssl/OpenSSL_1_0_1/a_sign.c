int ASN1_sign(i2d_of_void *i2d, X509_ALGOR *algor1, X509_ALGOR *algor2,
ASN1_BIT_STRING *signature, char *data, EVP_PKEY *pkey,
const EVP_MD *type)
{
EVP_MD_CTX ctx;
unsigned char *p,*buf_in=NULL,*buf_out=NULL;
int i,inl=0,outl=0,outll=0;
X509_ALGOR *a;
EVP_MD_CTX_init(&ctx);
for (i=0; i<2; i++)
{
if (i == 0)
a=algor1;
else
a=algor2;
if (a == NULL) continue;
if (type->pkey_type == NID_dsaWithSHA1)
{
ASN1_TYPE_free(a->parameter);
a->parameter = NULL;
}
else if ((a->parameter == NULL) ||
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
buf_in=(unsigned char *)OPENSSL_malloc((unsigned int)inl);
outll=outl=EVP_PKEY_size(pkey);
buf_out=(unsigned char *)OPENSSL_malloc((unsigned int)outl);
if ((buf_in == NULL) || (buf_out == NULL))
{
outl=0;
ASN1err(ASN1_F_ASN1_SIGN,ERR_R_MALLOC_FAILURE);
goto err;
}
p=buf_in;
i2d(data,&p);
if (!EVP_SignInit_ex(&ctx,type, NULL)
|| !EVP_SignUpdate(&ctx,(unsigned char *)buf_in,inl)
|| !EVP_SignFinal(&ctx,(unsigned char *)buf_out,
(unsigned int *)&outl,pkey))
{
outl=0;
ASN1err(ASN1_F_ASN1_SIGN,ERR_R_EVP_LIB);
goto err;
}
if (signature->data != NULL) OPENSSL_free(signature->data);
signature->data=buf_out;
buf_out=NULL;
signature->length=outl;
signature->flags&= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07);
signature->flags|=ASN1_STRING_FLAG_BITS_LEFT;
err:
EVP_MD_CTX_cleanup(&ctx);
if (buf_in != NULL)
{ OPENSSL_cleanse((char *)buf_in,(unsigned int)inl); OPENSSL_free(buf_in); }
if (buf_out != NULL)
{ OPENSSL_cleanse((char *)buf_out,outll); OPENSSL_free(buf_out); }
return(outl);
}
int ASN1_item_sign(const ASN1_ITEM *it, X509_ALGOR *algor1, X509_ALGOR *algor2,
ASN1_BIT_STRING *signature, void *asn, EVP_PKEY *pkey,
const EVP_MD *type)
{
EVP_MD_CTX ctx;
EVP_MD_CTX_init(&ctx);
if (!EVP_DigestSignInit(&ctx, NULL, type, NULL, pkey))
{
EVP_MD_CTX_cleanup(&ctx);
return 0;
}
return ASN1_item_sign_ctx(it, algor1, algor2, signature, asn, &ctx);
}
int ASN1_item_sign_ctx(const ASN1_ITEM *it,
X509_ALGOR *algor1, X509_ALGOR *algor2,
ASN1_BIT_STRING *signature, void *asn, EVP_MD_CTX *ctx)
{
const EVP_MD *type;
EVP_PKEY *pkey;
unsigned char *buf_in=NULL,*buf_out=NULL;
size_t inl=0,outl=0,outll=0;
int signid, paramtype;
int rv;
type = EVP_MD_CTX_md(ctx);
pkey = EVP_PKEY_CTX_get0_pkey(ctx->pctx);
if (!type || !pkey)
{
ASN1err(ASN1_F_ASN1_ITEM_SIGN_CTX, ASN1_R_CONTEXT_NOT_INITIALISED);
return 0;
}
if (pkey->ameth->item_sign)
{
rv = pkey->ameth->item_sign(ctx, it, asn, algor1, algor2,
signature);
if (rv == 1)
outl = signature->length;
if (rv <= 0)
ASN1err(ASN1_F_ASN1_ITEM_SIGN_CTX, ERR_R_EVP_LIB);
if (rv <= 1)
goto err;
}
else
rv = 2;
if (rv == 2)
{
if (type->flags & EVP_MD_FLAG_PKEY_METHOD_SIGNATURE)
{
if (!pkey->ameth ||
!OBJ_find_sigid_by_algs(&signid,
EVP_MD_nid(type),
pkey->ameth->pkey_id))
{
ASN1err(ASN1_F_ASN1_ITEM_SIGN_CTX,
ASN1_R_DIGEST_AND_KEY_TYPE_NOT_SUPPORTED);
return 0;
}
}
else
signid = type->pkey_type;
if (pkey->ameth->pkey_flags & ASN1_PKEY_SIGPARAM_NULL)
paramtype = V_ASN1_NULL;
else
paramtype = V_ASN1_UNDEF;
if (algor1)
X509_ALGOR_set0(algor1, OBJ_nid2obj(signid), paramtype, NULL);
if (algor2)
X509_ALGOR_set0(algor2, OBJ_nid2obj(signid), paramtype, NULL);
}
inl=ASN1_item_i2d(asn,&buf_in, it);
outll=outl=EVP_PKEY_size(pkey);
buf_out=OPENSSL_malloc((unsigned int)outl);
if ((buf_in == NULL) || (buf_out == NULL))
{
outl=0;
ASN1err(ASN1_F_ASN1_ITEM_SIGN_CTX,ERR_R_MALLOC_FAILURE);
goto err;
}
if (!EVP_DigestSignUpdate(ctx, buf_in, inl)
|| !EVP_DigestSignFinal(ctx, buf_out, &outl))
{
outl=0;
ASN1err(ASN1_F_ASN1_ITEM_SIGN_CTX,ERR_R_EVP_LIB);
goto err;
}
if (signature->data != NULL) OPENSSL_free(signature->data);
signature->data=buf_out;
buf_out=NULL;
signature->length=outl;
signature->flags&= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07);
signature->flags|=ASN1_STRING_FLAG_BITS_LEFT;
err:
EVP_MD_CTX_cleanup(ctx);
if (buf_in != NULL)
{ OPENSSL_cleanse((char *)buf_in,(unsigned int)inl); OPENSSL_free(buf_in); }
if (buf_out != NULL)
{ OPENSSL_cleanse((char *)buf_out,outll); OPENSSL_free(buf_out); }
return(outl);
}
