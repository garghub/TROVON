int EVP_OpenInit(EVP_CIPHER_CTX *ctx, EVP_CIPHER *type, unsigned char *ek,
int ekl, unsigned char *iv, EVP_PKEY *priv)
{
unsigned char *key=NULL;
int i,size=0,ret=0;
if (priv->type != EVP_PKEY_RSA)
{
EVPerr(EVP_F_EVP_OPENINIT,EVP_R_PUBLIC_KEY_NOT_RSA);
ret= -1;
goto err;
}
size=RSA_size(priv->pkey.rsa);
key=(unsigned char *)Malloc(size+2);
if (key == NULL)
{
EVPerr(EVP_F_EVP_OPENINIT,ERR_R_MALLOC_FAILURE);
ret= -1;
goto err;
}
i=EVP_PKEY_decrypt(key,ek,ekl,priv);
if (i != type->key_len)
{
goto err;
}
EVP_CIPHER_CTX_init(ctx);
EVP_DecryptInit(ctx,type,key,iv);
ret=1;
err:
if (key != NULL) memset(key,0,size);
Free(key);
return(ret);
}
int EVP_OpenFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl)
{
int i;
i=EVP_DecryptFinal(ctx,out,outl);
EVP_DecryptInit(ctx,NULL,NULL,NULL);
return(i);
}
