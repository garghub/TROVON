void EVP_CIPHER_CTX_init(EVP_CIPHER_CTX *ctx)
{
memset(ctx,0,sizeof(EVP_CIPHER_CTX));
}
int EVP_CipherInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
unsigned char *key, unsigned char *iv, int enc)
{
if(enc && (enc != -1)) enc = 1;
if (cipher) {
ctx->cipher=cipher;
ctx->key_len = cipher->key_len;
if(ctx->cipher->flags & EVP_CIPH_CTRL_INIT) {
if(!EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_INIT, 0, NULL)) {
EVPerr(EVP_F_EVP_CIPHERINIT, EVP_R_INITIALIZATION_ERROR);
return 0;
}
}
} else if(!ctx->cipher) {
EVPerr(EVP_F_EVP_CIPHERINIT, EVP_R_NO_CIPHER_SET);
return 0;
}
if(!(EVP_CIPHER_CTX_flags(ctx) & EVP_CIPH_CUSTOM_IV)) {
switch(EVP_CIPHER_CTX_mode(ctx)) {
case EVP_CIPH_STREAM_CIPHER:
case EVP_CIPH_ECB_MODE:
break;
case EVP_CIPH_CFB_MODE:
case EVP_CIPH_OFB_MODE:
ctx->num = 0;
case EVP_CIPH_CBC_MODE:
if(iv) memcpy(ctx->oiv, iv, EVP_CIPHER_CTX_iv_length(ctx));
memcpy(ctx->iv, ctx->oiv, EVP_CIPHER_CTX_iv_length(ctx));
break;
default:
return 0;
break;
}
}
if(key || (ctx->cipher->flags & EVP_CIPH_ALWAYS_CALL_INIT)) {
if(!ctx->cipher->init(ctx,key,iv,enc)) return 0;
}
if(enc != -1) ctx->encrypt=enc;
ctx->buf_len=0;
return 1;
}
int EVP_CipherUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl,
unsigned char *in, int inl)
{
if (ctx->encrypt)
return EVP_EncryptUpdate(ctx,out,outl,in,inl);
else return EVP_DecryptUpdate(ctx,out,outl,in,inl);
}
int EVP_CipherFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl)
{
if (ctx->encrypt)
return EVP_EncryptFinal(ctx,out,outl);
else return(EVP_DecryptFinal(ctx,out,outl));
}
int EVP_EncryptInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
unsigned char *key, unsigned char *iv)
{
return EVP_CipherInit(ctx, cipher, key, iv, 1);
}
int EVP_DecryptInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
unsigned char *key, unsigned char *iv)
{
return EVP_CipherInit(ctx, cipher, key, iv, 0);
}
int EVP_EncryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl,
unsigned char *in, int inl)
{
int i,j,bl;
i=ctx->buf_len;
bl=ctx->cipher->block_size;
*outl=0;
if ((inl == 0) && (i != bl)) return 1;
if (i != 0)
{
if (i+inl < bl)
{
memcpy(&(ctx->buf[i]),in,inl);
ctx->buf_len+=inl;
return 1;
}
else
{
j=bl-i;
if (j != 0) memcpy(&(ctx->buf[i]),in,j);
if(!ctx->cipher->do_cipher(ctx,out,ctx->buf,bl)) return 0;
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
if(!ctx->cipher->do_cipher(ctx,out,in,inl)) return 0;
*outl+=inl;
}
if (i != 0)
memcpy(ctx->buf,&(in[inl]),i);
ctx->buf_len=i;
return 1;
}
int EVP_EncryptFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl)
{
int i,n,b,bl;
b=ctx->cipher->block_size;
if (b == 1)
{
*outl=0;
return 1;
}
bl=ctx->buf_len;
n=b-bl;
for (i=bl; i<b; i++)
ctx->buf[i]=n;
if(!ctx->cipher->do_cipher(ctx,out,ctx->buf,b)) return 0;
*outl=b;
return 1;
}
int EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl,
unsigned char *in, int inl)
{
int b,bl,n;
int keep_last=0;
*outl=0;
if (inl == 0) return 1;
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
return 1;
}
keep_last=1;
inl-=b;
}
}
if(!EVP_EncryptUpdate(ctx,out,outl,in,inl)) return 0;
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
return 1;
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
if(!EVP_EncryptUpdate(ctx,ctx->buf,&n,ctx->buf,0)) return 0;
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
int EVP_CIPHER_CTX_cleanup(EVP_CIPHER_CTX *c)
{
if ((c->cipher != NULL) && (c->cipher->cleanup != NULL))
{
if(!c->cipher->cleanup(c)) return 0;
}
memset(c,0,sizeof(EVP_CIPHER_CTX));
return 1;
}
int EVP_CIPHER_CTX_set_key_length(EVP_CIPHER_CTX *c, int keylen)
{
if(c->cipher->flags & EVP_CIPH_CUSTOM_KEY_LENGTH)
return EVP_CIPHER_CTX_ctrl(c, EVP_CTRL_SET_KEY_LENGTH, keylen, NULL);
if(c->key_len == keylen) return 1;
if((keylen > 0) && (c->cipher->flags & EVP_CIPH_VARIABLE_LENGTH))
{
c->key_len = keylen;
return 1;
}
EVPerr(EVP_F_EVP_CIPHER_CTX_SET_KEY_LENGTH,EVP_R_INVALID_KEY_LENGTH);
return 0;
}
int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX *ctx, int type, int arg, void *ptr)
{
int ret;
if(!ctx->cipher) {
EVPerr(EVP_F_EVP_CIPHER_CTX_CTRL, EVP_R_NO_CIPHER_SET);
return 0;
}
if(!ctx->cipher->ctrl) {
EVPerr(EVP_F_EVP_CIPHER_CTX_CTRL, EVP_R_CTRL_NOT_IMPLEMENTED);
return 0;
}
ret = ctx->cipher->ctrl(ctx, type, arg, ptr);
if(ret == -1) {
EVPerr(EVP_F_EVP_CIPHER_CTX_CTRL, EVP_R_CTRL_OPERATION_NOT_IMPLEMENTED);
return 0;
}
return ret;
}
