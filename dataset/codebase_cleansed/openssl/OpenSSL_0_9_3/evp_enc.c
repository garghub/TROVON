void EVP_CIPHER_CTX_init(EVP_CIPHER_CTX *ctx)
{
memset(ctx,0,sizeof(EVP_CIPHER_CTX));
}
void EVP_CipherInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *data,
unsigned char *key, unsigned char *iv, int enc)
{
if (enc)
EVP_EncryptInit(ctx,data,key,iv);
else
EVP_DecryptInit(ctx,data,key,iv);
}
void EVP_CipherUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl,
unsigned char *in, int inl)
{
if (ctx->encrypt)
EVP_EncryptUpdate(ctx,out,outl,in,inl);
else EVP_DecryptUpdate(ctx,out,outl,in,inl);
}
int EVP_CipherFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl)
{
if (ctx->encrypt)
{
EVP_EncryptFinal(ctx,out,outl);
return(1);
}
else return(EVP_DecryptFinal(ctx,out,outl));
}
void EVP_EncryptInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
unsigned char *key, unsigned char *iv)
{
if (cipher != NULL)
ctx->cipher=cipher;
ctx->cipher->init(ctx,key,iv,1);
ctx->encrypt=1;
ctx->buf_len=0;
}
void EVP_DecryptInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
unsigned char *key, unsigned char *iv)
{
if (cipher != NULL)
ctx->cipher=cipher;
ctx->cipher->init(ctx,key,iv,0);
ctx->encrypt=0;
ctx->buf_len=0;
}
void EVP_EncryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl,
unsigned char *in, int inl)
{
int i,j,bl;
i=ctx->buf_len;
bl=ctx->cipher->block_size;
*outl=0;
if ((inl == 0) && (i != bl)) return;
if (i != 0)
{
if (i+inl < bl)
{
memcpy(&(ctx->buf[i]),in,inl);
ctx->buf_len+=inl;
return;
}
else
{
j=bl-i;
if (j != 0) memcpy(&(ctx->buf[i]),in,j);
ctx->cipher->do_cipher(ctx,out,ctx->buf,bl);
inl-=j;
in+=j;
out+=bl;
*outl+=bl;
}
}
i=inl%bl;
inl-=i;
if (inl > 0)
{
ctx->cipher->do_cipher(ctx,out,in,inl);
*outl+=inl;
}
if (i != 0)
memcpy(ctx->buf,&(in[inl]),i);
ctx->buf_len=i;
}
void EVP_EncryptFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl)
{
int i,n,b,bl;
b=ctx->cipher->block_size;
if (b == 1)
{
*outl=0;
return;
}
bl=ctx->buf_len;
n=b-bl;
for (i=bl; i<b; i++)
ctx->buf[i]=n;
ctx->cipher->do_cipher(ctx,out,ctx->buf,b);
*outl=b;
}
void EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl,
unsigned char *in, int inl)
{
int b,bl,n;
int keep_last=0;
*outl=0;
if (inl == 0) return;
b=ctx->cipher->block_size;
if (b > 1)
{
bl=ctx->buf_len;
n=inl+bl;
if (n%b == 0)
{
if (inl < b)
{
memcpy(&(ctx->buf[bl]),in,inl);
ctx->buf_len=b;
*outl=0;
return;
}
keep_last=1;
inl-=b;
}
}
EVP_EncryptUpdate(ctx,out,outl,in,inl);
if (keep_last)
{
memcpy(&(ctx->buf[0]),&(in[inl]),b);
#ifdef DEBUG
if (ctx->buf_len != 0)
{
abort();
}
#endif
ctx->buf_len=b;
}
}
int EVP_DecryptFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl)
{
int i,b;
int n;
*outl=0;
b=ctx->cipher->block_size;
if (b > 1)
{
if (ctx->buf_len != b)
{
EVPerr(EVP_F_EVP_DECRYPTFINAL,EVP_R_WRONG_FINAL_BLOCK_LENGTH);
return(0);
}
EVP_EncryptUpdate(ctx,ctx->buf,&n,ctx->buf,0);
if (n != b)
return(0);
n=ctx->buf[b-1];
if (n > b)
{
EVPerr(EVP_F_EVP_DECRYPTFINAL,EVP_R_BAD_DECRYPT);
return(0);
}
for (i=0; i<n; i++)
{
if (ctx->buf[--b] != n)
{
EVPerr(EVP_F_EVP_DECRYPTFINAL,EVP_R_BAD_DECRYPT);
return(0);
}
}
n=ctx->cipher->block_size-n;
for (i=0; i<n; i++)
out[i]=ctx->buf[i];
*outl=n;
}
else
*outl=0;
return(1);
}
void EVP_CIPHER_CTX_cleanup(EVP_CIPHER_CTX *c)
{
if ((c->cipher != NULL) && (c->cipher->cleanup != NULL))
c->cipher->cleanup(c);
memset(c,0,sizeof(EVP_CIPHER_CTX));
}
