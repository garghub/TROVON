int EVP_SealInit(EVP_CIPHER_CTX *ctx, EVP_CIPHER *type, unsigned char **ek,
int *ekl, unsigned char *iv, EVP_PKEY **pubk, int npubk)
{
unsigned char key[EVP_MAX_KEY_LENGTH];
int i;
if (npubk <= 0) return(0);
RAND_bytes(key,EVP_MAX_KEY_LENGTH);
if (type->iv_len > 0)
RAND_bytes(iv,type->iv_len);
EVP_CIPHER_CTX_init(ctx);
EVP_EncryptInit(ctx,type,key,iv);
for (i=0; i<npubk; i++)
{
ekl[i]=EVP_PKEY_encrypt(ek[i],key,EVP_CIPHER_key_length(type),
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
