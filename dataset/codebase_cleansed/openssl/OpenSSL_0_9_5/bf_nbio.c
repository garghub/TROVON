BIO_METHOD *BIO_f_nbio_test(void)
{
return(&methods_nbiof);
}
static int nbiof_new(BIO *bi)
{
NBIO_TEST *nt;
nt=(NBIO_TEST *)Malloc(sizeof(NBIO_TEST));
nt->lrn= -1;
nt->lwn= -1;
bi->ptr=(char *)nt;
bi->init=1;
bi->flags=0;
return(1);
}
static int nbiof_free(BIO *a)
{
if (a == NULL) return(0);
if (a->ptr != NULL)
Free(a->ptr);
a->ptr=NULL;
a->init=0;
a->flags=0;
return(1);
}
static int nbiof_read(BIO *b, char *out, int outl)
{
NBIO_TEST *nt;
int ret=0;
#if 0
int num;
unsigned char n;
#endif
if (out == NULL) return(0);
if (b->next_bio == NULL) return(0);
nt=(NBIO_TEST *)b->ptr;
BIO_clear_retry_flags(b);
#if 0
RAND_pseudo_bytes(&n,1);
num=(n&0x07);
if (outl > num) outl=num;
if (num == 0)
{
ret= -1;
BIO_set_retry_read(b);
}
else
#endif
{
ret=BIO_read(b->next_bio,out,outl);
if (ret < 0)
BIO_copy_next_retry(b);
}
return(ret);
}
static int nbiof_write(BIO *b, char *in, int inl)
{
NBIO_TEST *nt;
int ret=0;
int num;
unsigned char n;
if ((in == NULL) || (inl <= 0)) return(0);
if (b->next_bio == NULL) return(0);
nt=(NBIO_TEST *)b->ptr;
BIO_clear_retry_flags(b);
#if 1
if (nt->lwn > 0)
{
num=nt->lwn;
nt->lwn=0;
}
else
{
RAND_pseudo_bytes(&n,1);
num=(n&7);
}
if (inl > num) inl=num;
if (num == 0)
{
ret= -1;
BIO_set_retry_write(b);
}
else
#endif
{
ret=BIO_write(b->next_bio,in,inl);
if (ret < 0)
{
BIO_copy_next_retry(b);
nt->lwn=inl;
}
}
return(ret);
}
static long nbiof_ctrl(BIO *b, int cmd, long num, char *ptr)
{
long ret;
if (b->next_bio == NULL) return(0);
switch (cmd)
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
break;
}
return(ret);
}
static long nbiof_callback_ctrl(BIO *b, int cmd, void (*fp)())
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
static int nbiof_gets(BIO *bp, char *buf, int size)
{
if (bp->next_bio == NULL) return(0);
return(BIO_gets(bp->next_bio,buf,size));
}
static int nbiof_puts(BIO *bp, char *str)
{
if (bp->next_bio == NULL) return(0);
return(BIO_puts(bp->next_bio,str));
}
