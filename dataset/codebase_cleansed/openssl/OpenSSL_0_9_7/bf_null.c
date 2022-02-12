BIO_METHOD *BIO_f_null(void)
{
return(&methods_nullf);
}
static int nullf_new(BIO *bi)
{
bi->init=1;
bi->ptr=NULL;
bi->flags=0;
return(1);
}
static int nullf_free(BIO *a)
{
if (a == NULL) return(0);
return(1);
}
static int nullf_read(BIO *b, char *out, int outl)
{
int ret=0;
if (out == NULL) return(0);
if (b->next_bio == NULL) return(0);
ret=BIO_read(b->next_bio,out,outl);
BIO_clear_retry_flags(b);
BIO_copy_next_retry(b);
return(ret);
}
static int nullf_write(BIO *b, const char *in, int inl)
{
int ret=0;
if ((in == NULL) || (inl <= 0)) return(0);
if (b->next_bio == NULL) return(0);
ret=BIO_write(b->next_bio,in,inl);
BIO_clear_retry_flags(b);
BIO_copy_next_retry(b);
return(ret);
}
static long nullf_ctrl(BIO *b, int cmd, long num, void *ptr)
{
long ret;
if (b->next_bio == NULL) return(0);
switch(cmd)
{
case BIO_C_DO_STATE_MACHINE:
BIO_clear_retry_flags(b);
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
BIO_copy_next_retry(b);
break;
case BIO_CTRL_DUP:
ret=0L;
break;
default:
ret=BIO_ctrl(b->next_bio,cmd,num,ptr);
}
return(ret);
}
static long nullf_callback_ctrl(BIO *b, int cmd, bio_info_cb *fp)
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
static int nullf_gets(BIO *bp, char *buf, int size)
{
if (bp->next_bio == NULL) return(0);
return(BIO_gets(bp->next_bio,buf,size));
}
static int nullf_puts(BIO *bp, const char *str)
{
if (bp->next_bio == NULL) return(0);
return(BIO_puts(bp->next_bio,str));
}
