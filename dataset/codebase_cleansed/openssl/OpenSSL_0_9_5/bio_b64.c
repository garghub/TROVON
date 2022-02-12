BIO_METHOD *BIO_f_base64(void)
{
return(&methods_b64);
}
static int b64_new(BIO *bi)
{
BIO_B64_CTX *ctx;
ctx=(BIO_B64_CTX *)Malloc(sizeof(BIO_B64_CTX));
if (ctx == NULL) return(0);
ctx->buf_len=0;
ctx->tmp_len=0;
ctx->tmp_nl=0;
ctx->buf_off=0;
ctx->cont=1;
ctx->start=1;
ctx->encode=0;
bi->init=1;
bi->ptr=(char *)ctx;
bi->flags=0;
return(1);
}
static int b64_free(BIO *a)
{
if (a == NULL) return(0);
Free(a->ptr);
a->ptr=NULL;
a->init=0;
a->flags=0;
return(1);
}
static int b64_read(BIO *b, char *out, int outl)
{
int ret=0,i,ii,j,k,x,n,num,ret_code=0;
BIO_B64_CTX *ctx;
unsigned char *p,*q;
if (out == NULL) return(0);
ctx=(BIO_B64_CTX *)b->ptr;
if ((ctx == NULL) || (b->next_bio == NULL)) return(0);
if (ctx->encode != B64_DECODE)
{
ctx->encode=B64_DECODE;
ctx->buf_len=0;
ctx->buf_off=0;
ctx->tmp_len=0;
EVP_DecodeInit(&(ctx->base64));
}
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
ret_code=0;
while (outl > 0)
{
if (ctx->cont <= 0) break;
i=BIO_read(b->next_bio,&(ctx->tmp[ctx->tmp_len]),
B64_BLOCK_SIZE-ctx->tmp_len);
if (i <= 0)
{
ret_code=i;
if (!BIO_should_retry(b->next_bio))
ctx->cont=i;
break;
}
i+=ctx->tmp_len;
if (ctx->start && (BIO_get_flags(b) & BIO_FLAGS_BASE64_NO_NL))
{
ctx->tmp_len=0;
}
else if (ctx->start)
{
q=p=(unsigned char *)ctx->tmp;
for (j=0; j<i; j++)
{
if (*(q++) != '\n') continue;
if (ctx->tmp_nl)
{
p=q;
ctx->tmp_nl=0;
continue;
}
k=EVP_DecodeUpdate(&(ctx->base64),
(unsigned char *)ctx->buf,
&num,p,q-p);
if ((k <= 0) && (num == 0) && (ctx->start))
EVP_DecodeInit(&ctx->base64);
else
{
if (p != (unsigned char *)
&(ctx->tmp[0]))
{
i-=(p- (unsigned char *)
&(ctx->tmp[0]));
for (x=0; x < i; x++)
ctx->tmp[x]=p[x];
}
EVP_DecodeInit(&ctx->base64);
ctx->start=0;
break;
}
p=q;
}
if (j == i)
{
if (p == (unsigned char *)&(ctx->tmp[0]))
{
ctx->tmp_nl=1;
ctx->tmp_len=0;
}
else if (p != q)
{
n=q-p;
for (ii=0; ii<n; ii++)
ctx->tmp[ii]=p[ii];
ctx->tmp_len=n;
}
continue;
}
else
ctx->tmp_len=0;
}
if (BIO_get_flags(b) & BIO_FLAGS_BASE64_NO_NL)
{
int z,jj;
jj=(i>>2)<<2;
z=EVP_DecodeBlock((unsigned char *)ctx->buf,
(unsigned char *)ctx->tmp,jj);
if (jj > 2)
{
if (ctx->tmp[jj-1] == '=')
{
z--;
if (ctx->tmp[jj-2] == '=')
z--;
}
}
if (jj != i)
{
memcpy((unsigned char *)ctx->tmp,
(unsigned char *)&(ctx->tmp[jj]),i-jj);
ctx->tmp_len=i-jj;
}
ctx->buf_len=0;
if (z > 0)
{
ctx->buf_len=z;
i=1;
}
else
i=z;
}
else
{
i=EVP_DecodeUpdate(&(ctx->base64),
(unsigned char *)ctx->buf,&ctx->buf_len,
(unsigned char *)ctx->tmp,i);
}
ctx->cont=i;
ctx->buf_off=0;
if (i < 0)
{
ret_code=0;
ctx->buf_len=0;
break;
}
if (ctx->buf_len <= outl)
i=ctx->buf_len;
else
i=outl;
memcpy(out,ctx->buf,i);
ret+=i;
ctx->buf_off=i;
if (ctx->buf_off == ctx->buf_len)
{
ctx->buf_len=0;
ctx->buf_off=0;
}
outl-=i;
out+=i;
}
BIO_clear_retry_flags(b);
BIO_copy_next_retry(b);
return((ret == 0)?ret_code:ret);
}
static int b64_write(BIO *b, char *in, int inl)
{
int ret=inl,n,i;
BIO_B64_CTX *ctx;
ctx=(BIO_B64_CTX *)b->ptr;
BIO_clear_retry_flags(b);
if (ctx->encode != B64_ENCODE)
{
ctx->encode=B64_ENCODE;
ctx->buf_len=0;
ctx->buf_off=0;
ctx->tmp_len=0;
EVP_EncodeInit(&(ctx->base64));
}
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
n=(inl > B64_BLOCK_SIZE)?B64_BLOCK_SIZE:inl;
if (BIO_get_flags(b) & BIO_FLAGS_BASE64_NO_NL)
{
if (ctx->tmp_len > 0)
{
n=3-ctx->tmp_len;
memcpy(&(ctx->tmp[ctx->tmp_len]),in,n);
ctx->tmp_len+=n;
n=ctx->tmp_len;
if (n < 3)
break;
ctx->buf_len=EVP_EncodeBlock(
(unsigned char *)ctx->buf,
(unsigned char *)ctx->tmp,n);
}
else
{
if (n < 3)
{
memcpy(&(ctx->tmp[0]),in,n);
ctx->tmp_len=n;
break;
}
n-=n%3;
ctx->buf_len=EVP_EncodeBlock(
(unsigned char *)ctx->buf,
(unsigned char *)in,n);
}
}
else
{
EVP_EncodeUpdate(&(ctx->base64),
(unsigned char *)ctx->buf,&ctx->buf_len,
(unsigned char *)in,n);
}
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
return((ret == 0)?i:ret);
}
n-=i;
ctx->buf_off+=i;
}
ctx->buf_len=0;
ctx->buf_off=0;
}
return(ret);
}
static long b64_ctrl(BIO *b, int cmd, long num, char *ptr)
{
BIO_B64_CTX *ctx;
long ret=1;
int i;
ctx=(BIO_B64_CTX *)b->ptr;
switch (cmd)
{
case BIO_CTRL_RESET:
ctx->cont=1;
ctx->start=1;
ctx->encode=B64_NONE;
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
if ((ret == 0) && (ctx->base64.num != 0))
ret=1;
else if (ret <= 0)
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
i=b64_write(b,NULL,0);
if (i < 0)
{
ret=i;
break;
}
}
if (BIO_get_flags(b) & BIO_FLAGS_BASE64_NO_NL)
{
if (ctx->tmp_len != 0)
{
ctx->buf_len=EVP_EncodeBlock(
(unsigned char *)ctx->buf,
(unsigned char *)ctx->tmp,
ctx->tmp_len);
ctx->buf_off=0;
ctx->tmp_len=0;
goto again;
}
}
else if (ctx->base64.num != 0)
{
ctx->buf_off=0;
EVP_EncodeFinal(&(ctx->base64),
(unsigned char *)ctx->buf,
&(ctx->buf_len));
goto again;
}
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
break;
case BIO_C_DO_STATE_MACHINE:
BIO_clear_retry_flags(b);
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
BIO_copy_next_retry(b);
break;
case BIO_CTRL_DUP:
break;
case BIO_CTRL_INFO:
case BIO_CTRL_GET:
case BIO_CTRL_SET:
default:
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
break;
}
return(ret);
}
static long b64_callback_ctrl(BIO *b, int cmd, void (*fp)())
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
