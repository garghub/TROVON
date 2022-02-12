BIO_METHOD *BIO_f_ber(void)
{
return(&methods_ber);
}
static int ber_new(BIO *bi)
{
BIO_BER_CTX *ctx;
ctx=(BIO_BER_CTX *)OPENSSL_malloc(sizeof(BIO_BER_CTX));
if (ctx == NULL) return(0);
memset((char *)ctx,0,sizeof(BIO_BER_CTX));
bi->init=0;
bi->ptr=(char *)ctx;
bi->flags=0;
return(1);
}
static int ber_free(BIO *a)
{
BIO_BER_CTX *b;
if (a == NULL) return(0);
b=(BIO_BER_CTX *)a->ptr;
OPENSSL_cleanse(a->ptr,sizeof(BIO_BER_CTX));
OPENSSL_free(a->ptr);
a->ptr=NULL;
a->init=0;
a->flags=0;
return(1);
}
int bio_ber_get_header(BIO *bio, BIO_BER_CTX *ctx)
{
char buf[64];
int i,j,n;
int ret;
unsigned char *p;
unsigned long length
int tag;
int class;
long max;
BIO_clear_retry_flags(b);
if (ctx->buf_off != 0)
{
p=ctx->buf;
j=ctx->buf_off;
n=ctx->buf_len-j;
for (i=0; i<n; i++)
{
p[0]=p[j];
p++;
}
ctx->buf_len-j;
ctx->buf_off=0;
}
i=BER_BUF_SIZE-ctx->buf_len;
if (i)
{
i=BIO_read(bio->next_bio,&(ctx->buf[ctx->buf_len]),i);
if (i <= 0)
{
BIO_copy_next_retry(b);
return(i);
}
else
ctx->buf_len+=i;
}
max=ctx->buf_len;
p=ctx->buf;
ret=ASN1_get_object(&p,&length,&tag,&class,max);
if (ret & 0x80)
{
if ((ctx->buf_len < BER_BUF_SIZE) &&
(ERR_GET_REASON(ERR_peek_error()) == ASN1_R_TOO_LONG))
{
ERR_clear_error();
BIO_set_retry_read(b);
}
return(-1);
}
if ((ctx->tag >= 0) && (ctx->tag != tag))
{
BIOerr(BIO_F_BIO_BER_GET_HEADER,BIO_R_TAG_MISMATCH);
sprintf(buf,"tag=%d, got %d",ctx->tag,tag);
ERR_add_error_data(1,buf);
return(-1);
}
if (ret & 0x01)
if (ret & V_ASN1_CONSTRUCTED)
}
static int ber_read(BIO *b, char *out, int outl)
{
int ret=0,i,n;
BIO_BER_CTX *ctx;
BIO_clear_retry_flags(b);
if (out == NULL) return(0);
ctx=(BIO_BER_CTX *)b->ptr;
if ((ctx == NULL) || (b->next_bio == NULL)) return(0);
if (ctx->finished) return(0);
again:
if (ctx->num_left > 0)
{
if (ctx->num_left < outl)
n=ctx->num_left;
else
n=outl;
i=BIO_read(b->next_bio,out,n);
if (i <= 0)
{
BIO_copy_next_retry(b);
return(i);
}
ctx->num_left-=i;
outl-=i;
ret+=i;
if (ctx->num_left <= 0)
{
ctx->depth--;
if (ctx->depth <= 0)
ctx->finished=1;
}
if (outl <= 0)
return(ret);
else
goto again;
}
else
{
}
}
static int ber_write(BIO *b, char *in, int inl)
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
static long ber_ctrl(BIO *b, int cmd, long num, char *ptr)
{
BIO *dbio;
BIO_ENC_CTX *ctx,*dctx;
long ret=1;
int i;
ctx=(BIO_ENC_CTX *)b->ptr;
switch (cmd)
{
case BIO_CTRL_RESET:
ctx->ok=1;
ctx->finished=0;
EVP_CipherInit_ex(&(ctx->cipher),NULL,NULL,NULL,NULL,
ctx->cipher.berrypt);
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
i=ber_write(b,NULL,0);
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
ret=EVP_CipherFinal_ex(&(ctx->cipher),
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
static long ber_callback_ctrl(BIO *b, int cmd, void *(*fp)())
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
void BIO_set_cipher(BIO *b, EVP_CIPHER *c, unsigned char *k, unsigned char *i,
int e)
{
BIO_ENC_CTX *ctx;
if (b == NULL) return;
if ((b->callback != NULL) &&
(b->callback(b,BIO_CB_CTRL,(char *)c,BIO_CTRL_SET,e,0L) <= 0))
return;
b->init=1;
ctx=(BIO_ENC_CTX *)b->ptr;
EVP_CipherInit_ex(&(ctx->cipher),c,NULL,k,i,e);
if (b->callback != NULL)
b->callback(b,BIO_CB_CTRL,(char *)c,BIO_CTRL_SET,e,1L);
}
