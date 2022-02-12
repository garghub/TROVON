BIO_METHOD *BIO_f_md(void)
{
return(&methods_md);
}
static int md_new(BIO *bi)
{
EVP_MD_CTX *ctx;
ctx=EVP_MD_CTX_create();
if (ctx == NULL) return(0);
bi->init=0;
bi->ptr=(char *)ctx;
bi->flags=0;
return(1);
}
static int md_free(BIO *a)
{
if (a == NULL) return(0);
EVP_MD_CTX_destroy(a->ptr);
a->ptr=NULL;
a->init=0;
a->flags=0;
return(1);
}
static int md_read(BIO *b, char *out, int outl)
{
int ret=0;
EVP_MD_CTX *ctx;
if (out == NULL) return(0);
ctx=b->ptr;
if ((ctx == NULL) || (b->next_bio == NULL)) return(0);
ret=BIO_read(b->next_bio,out,outl);
if (b->init)
{
if (ret > 0)
{
if (EVP_DigestUpdate(ctx,(unsigned char *)out,
(unsigned int)ret)<=0) return (-1);
}
}
BIO_clear_retry_flags(b);
BIO_copy_next_retry(b);
return(ret);
}
static int md_write(BIO *b, const char *in, int inl)
{
int ret=0;
EVP_MD_CTX *ctx;
if ((in == NULL) || (inl <= 0)) return(0);
ctx=b->ptr;
if ((ctx != NULL) && (b->next_bio != NULL))
ret=BIO_write(b->next_bio,in,inl);
if (b->init)
{
if (ret > 0)
{
if (!EVP_DigestUpdate(ctx,(const unsigned char *)in,
(unsigned int)ret))
{
BIO_clear_retry_flags(b);
return 0;
}
}
}
if(b->next_bio != NULL)
{
BIO_clear_retry_flags(b);
BIO_copy_next_retry(b);
}
return(ret);
}
static long md_ctrl(BIO *b, int cmd, long num, void *ptr)
{
EVP_MD_CTX *ctx,*dctx,**pctx;
const EVP_MD **ppmd;
EVP_MD *md;
long ret=1;
BIO *dbio;
ctx=b->ptr;
switch (cmd)
{
case BIO_CTRL_RESET:
if (b->init)
ret = EVP_DigestInit_ex(ctx,ctx->digest, NULL);
else
ret=0;
if (ret > 0)
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
break;
case BIO_C_GET_MD:
if (b->init)
{
ppmd=ptr;
*ppmd=ctx->digest;
}
else
ret=0;
break;
case BIO_C_GET_MD_CTX:
pctx=ptr;
*pctx=ctx;
b->init = 1;
break;
case BIO_C_SET_MD_CTX:
if (b->init)
b->ptr=ptr;
else
ret=0;
break;
case BIO_C_DO_STATE_MACHINE:
BIO_clear_retry_flags(b);
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
BIO_copy_next_retry(b);
break;
case BIO_C_SET_MD:
md=ptr;
ret = EVP_DigestInit_ex(ctx,md, NULL);
if (ret > 0)
b->init=1;
break;
case BIO_CTRL_DUP:
dbio=ptr;
dctx=dbio->ptr;
if (!EVP_MD_CTX_copy_ex(dctx,ctx))
return 0;
b->init=1;
break;
default:
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
break;
}
return(ret);
}
static long md_callback_ctrl(BIO *b, int cmd, bio_info_cb *fp)
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
static int md_gets(BIO *bp, char *buf, int size)
{
EVP_MD_CTX *ctx;
unsigned int ret;
ctx=bp->ptr;
if (size < ctx->digest->md_size)
return(0);
if (EVP_DigestFinal_ex(ctx,(unsigned char *)buf,&ret)<=0)
return -1;
return((int)ret);
}
