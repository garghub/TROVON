int EVP_SealInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type, unsigned char **ek,
int *ekl, unsigned char *iv, EVP_PKEY **pubk, int npubk)
{
unsigned char key[EVP_MAX_KEY_LENGTH];
int i;
if(type) {
EVP_CIPHER_CTX_init(ctx);
if(!EVP_EncryptInit_ex(ctx,type,NULL,NULL,NULL)) return 0;
}
if ((npubk <= 0) || !pubk)
return 1;
if (RAND_bytes(key,EVP_MAX_KEY_LENGTH) <= 0)
return 0;
if (EVP_CIPHER_CTX_iv_length(ctx))
RAND_pseudo_bytes(iv,EVP_CIPHER_CTX_iv_length(ctx));
if(!EVP_EncryptInit_ex(ctx,NULL,NULL,key,iv)) return 0;
for (i=0; i<npubk; i++)
{
ekl[i]=EVP_PKEY_encrypt(ek[i],key,EVP_CIPHER_CTX_key_length(ctx),
pubk[i]);
if (ekl[i] <= 0) return(-1);
}
return(npubk);
}
int EVP_SealFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl)
{
int i;
i = EVP_EncryptFinal_ex(ctx,out,outl);
EVP_EncryptInit_ex(ctx,NULL,NULL,NULL,NULL);
return i;
}
