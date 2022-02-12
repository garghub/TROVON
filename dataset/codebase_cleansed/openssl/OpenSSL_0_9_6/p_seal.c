int EVP_SealInit(EVP_CIPHER_CTX *ctx, EVP_CIPHER *type, unsigned char **ek,
int *ekl, unsigned char *iv, EVP_PKEY **pubk, int npubk)
{
unsigned char key[EVP_MAX_KEY_LENGTH];
int i;
if(type) {
EVP_CIPHER_CTX_init(ctx);
if(!EVP_EncryptInit(ctx,type,NULL,NULL)) return 0;
}
if (npubk <= 0) return(0);
if (RAND_bytes(key,EVP_MAX_KEY_LENGTH) <= 0)
return(0);
if (EVP_CIPHER_CTX_iv_length(ctx))
RAND_pseudo_bytes(iv,EVP_CIPHER_CTX_iv_length(ctx));
if(!EVP_EncryptInit(ctx,NULL,key,iv)) return 0;
for (i=0; i<npubk; i++)
{
ekl[i]=EVP_PKEY_encrypt(ek[i],key,EVP_CIPHER_CTX_key_length(ctx),
pubk[i]);
if (ekl[i] <= 0) return(-1);
}
return(npubk);
}
void EVP_SealFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl)
{
EVP_EncryptFinal(ctx,out,outl);
EVP_EncryptInit(ctx,NULL,NULL,NULL);
}
