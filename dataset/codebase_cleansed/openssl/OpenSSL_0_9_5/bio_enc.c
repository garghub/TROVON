BIO_METHOD *BIO_f_cipher(void)
{
return(&methods_enc);
}
static int enc_new(BIO *bi)
{
BIO_ENC_CTX *ctx;
ctx=(BIO_ENC_CTX *)Malloc(sizeof(BIO_ENC_CTX));
EVP_CIPHER_CTX_init(&ctx->cipher);
if (ctx == NULL) return(0);
ctx->buf_len=0;
ctx->buf_off=0;
ctx->cont=1;
ctx->finished=0;
ctx->ok=1;
bi->init=0;
bi->ptr=(char *)ctx;
bi->flags=0;
return(1);
}
static int enc_free(BIO *a)
{
BIO_ENC_CTX *b;
if (a == NULL) return(0);
b=(BIO_ENC_CTX *)a->ptr;
EVP_CIPHER_CTX_cleanup(&(b->cipher));
memset(a->ptr,0,sizeof(BIO_ENC_CTX));
Free(a->ptr);
a->ptr=NULL;
a->init=0;
a->flags=0;
return(1);
}
static int enc_read(BIO *b, char *out, int outl)
{
int ret=0,i;
BIO_ENC_CTX *ctx;
if (out == NULL) return(0);
ctx=(BIO_ENC_CTX *)b->ptr;
if ((ctx == NULL) || (b->next_bio == NULL)) return(0);
if (ctx->buf_len > 0)
{
i=ctx->buf_len-ctx->buf_off;
if (i > outl) i=outl;
memcpy(out,&(ctx->buf[ctx->buf_off]),i);
ret=i;
out+=i;
outl-=i;
ctx->buf_off+=i;
if (ctx->buf_len == ctx->buf_off)
{
ctx->buf_len=0;
ctx->buf_off=0;
}
}
while (outl > 0)
{
if (ctx->cont <= 0) break;
i=BIO_read(b->next_bio,&(ctx->buf[8]),ENC_BLOCK_SIZE);
if (i <= 0)
{
if (!BIO_should_retry(b->next_bio))
{
ctx->cont=i;
i=EVP_CipherFinal(&(ctx->cipher),
(unsigned char *)ctx->buf,
&(ctx->buf_len));
ctx->ok=i;
ctx->buf_off=0;
}
else
{
ret=(ret == 0)?i:ret;
break;
}
}
else
{
EVP_CipherUpdate(&(ctx->cipher),
(unsigned char *)ctx->buf,&ctx->buf_len,
(unsigned char *)&(ctx->buf[8]),i);
ctx->cont=1;
if(ctx->buf_len == 0) continue;
}
if (ctx->buf_len <= outl)
i=ctx->buf_len;
else
i=outl;
if (i <= 0) break;
memcpy(out,ctx->buf,i);
ret+=i;
ctx->buf_off=i;
outl-=i;
out+=i;
}
BIO_clear_retry_flags(b);
BIO_copy_next_retry(b);
return((ret == 0)?ctx->cont:ret);
}
static int enc_write(BIO *b, char *in, int inl)
{
int ret=0,n,i;
BIO_ENC_CTX *ctx;
ctx=(BIO_ENC_CTX *)b->ptr;
ret=inl;
BIO_clear_retry_flags(b);
n=ctx->buf_len-ctx->buf_off;
while (n > 0)
{
i=BIO_write(b->next_bio,&(ctx->buf[ctx->buf_off]),n);
if (i <= 0)
{
BIO_copy_next_retry(b);
return(i);
}
ctx->buf_off+=i;
n-=i;
}
if ((in == NULL) || (inl <= 0)) return(0);
ctx->buf_off=0;
while (inl > 0)
{
n=(inl > ENC_BLOCK_SIZE)?ENC_BLOCK_SIZE:inl;
EVP_CipherUpdate(&(ctx->cipher),
(unsigned char *)ctx->buf,&ctx->buf_len,
(unsigned char *)in,n);
inl-=n;
in+=n;
ctx->buf_off=0;
n=ctx->buf_len;
while (n > 0)
{
i=BIO_write(b->next_bio,&(ctx->buf[ctx->buf_off]),n);
if (i <= 0)
{
BIO_copy_next_retry(b);
return(i);
}
n-=i;
ctx->buf_off+=i;
}
ctx->buf_len=0;
ctx->buf_off=0;
}
BIO_copy_next_retry(b);
return(ret);
}
static long enc_ctrl(BIO *b, int cmd, long num, char *ptr)
{
BIO *dbio;
BIO_ENC_CTX *ctx,*dctx;
long ret=1;
int i;
EVP_CIPHER_CTX **c_ctx;
ctx=(BIO_ENC_CTX *)b->ptr;
switch (cmd)
{
case BIO_CTRL_RESET:
ctx->ok=1;
ctx->finished=0;
EVP_CipherInit(&(ctx->cipher),NULL,NULL,NULL,
ctx->cipher.encrypt);
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
break;
case BIO_CTRL_EOF:
if (ctx->cont <= 0)
ret=1;
else
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
break;
case BIO_CTRL_WPENDING:
ret=ctx->buf_len-ctx->buf_off;
if (ret <= 0)
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
break;
case BIO_CTRL_PENDING:
ret=ctx->buf_len-ctx->buf_off;
if (ret <= 0)
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
break;
case BIO_CTRL_FLUSH:
again:
while (ctx->buf_len != ctx->buf_off)
{
i=enc_write(b,NULL,0);
if (i < 0)
{
ret=i;
break;
}
}
if (!ctx->finished)
{
ctx->finished=1;
ctx->buf_off=0;
ret=EVP_CipherFinal(&(ctx->cipher),
(unsigned char *)ctx->buf,
&(ctx->buf_len));
ctx->ok=(int)ret;
if (ret <= 0) break;
goto again;
}
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
break;
case BIO_C_GET_CIPHER_STATUS:
ret=(long)ctx->ok;
break;
case BIO_C_DO_STATE_MACHINE:
BIO_clear_retry_flags(b);
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
BIO_copy_next_retry(b);
break;
case BIO_C_GET_CIPHER_CTX:
c_ctx=(EVP_CIPHER_CTX **)ptr;
(*c_ctx)= &(ctx->cipher);
b->init=1;
break;
case BIO_CTRL_DUP:
dbio=(BIO *)ptr;
dctx=(BIO_ENC_CTX *)dbio->ptr;
memcpy(&(dctx->cipher),&(ctx->cipher),sizeof(ctx->cipher));
dbio->init=1;
break;
default:
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
break;
}
return(ret);
}
static long enc_callback_ctrl(BIO *b, int cmd, void (*fp)())
{
long ret=1;
if (b->next_bio == NULL) return(0);
switch (cmd)
{
default:
ret=BIO_callback_ctrl(b->next_bio,cmd,fp);
break;
}
return(ret);
}
void BIO_set_cipher(BIO *b, const EVP_CIPHER *c, unsigned char *k,
unsigned char *i, int e)
{
BIO_ENC_CTX *ctx;
if (b == NULL) return;
if ((b->callback != NULL) &&
(b->callback(b,BIO_CB_CTRL,(const char *)c,BIO_CTRL_SET,e,0L) <= 0))
return;
b->init=1;
ctx=(BIO_ENC_CTX *)b->ptr;
EVP_CipherInit(&(ctx->cipher),c,k,i,e);
if (b->callback != NULL)
b->callback(b,BIO_CB_CTRL,(const char *)c,BIO_CTRL_SET,e,1L);
}
