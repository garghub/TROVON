BIO_METHOD *BIO_s_mem(void)
{
return(&mem_method);
}
BIO *BIO_new_mem_buf(void *buf, int len)
{
BIO *ret;
BUF_MEM *b;
if (!buf) {
BIOerr(BIO_F_BIO_NEW_MEM_BUF,BIO_R_NULL_PARAMETER);
return NULL;
}
if(len == -1) len = strlen(buf);
if(!(ret = BIO_new(BIO_s_mem())) ) return NULL;
b = (BUF_MEM *)ret->ptr;
b->data = buf;
b->length = len;
b->max = len;
ret->flags |= BIO_FLAGS_MEM_RDONLY;
ret->num = 0;
return ret;
}
static int mem_new(BIO *bi)
{
BUF_MEM *b;
if ((b=BUF_MEM_new()) == NULL)
return(0);
bi->shutdown=1;
bi->init=1;
bi->num= -1;
bi->ptr=(char *)b;
return(1);
}
static int mem_free(BIO *a)
{
if (a == NULL) return(0);
if (a->shutdown)
{
if ((a->init) && (a->ptr != NULL))
{
BUF_MEM *b;
b = (BUF_MEM *)a->ptr;
if(a->flags & BIO_FLAGS_MEM_RDONLY) b->data = NULL;
BUF_MEM_free(b);
a->ptr=NULL;
}
}
return(1);
}
static int mem_read(BIO *b, char *out, int outl)
{
int ret= -1;
BUF_MEM *bm;
int i;
char *from,*to;
bm=(BUF_MEM *)b->ptr;
BIO_clear_retry_flags(b);
ret=(outl > bm->length)?bm->length:outl;
if ((out != NULL) && (ret > 0)) {
memcpy(out,bm->data,ret);
bm->length-=ret;
if(b->flags & BIO_FLAGS_MEM_RDONLY) bm->data += ret;
else {
from=(char *)&(bm->data[ret]);
to=(char *)&(bm->data[0]);
for (i=0; i<bm->length; i++)
to[i]=from[i];
}
} else if (bm->length == 0)
{
if (b->num != 0)
BIO_set_retry_read(b);
ret= b->num;
}
return(ret);
}
static int mem_write(BIO *b, char *in, int inl)
{
int ret= -1;
int blen;
BUF_MEM *bm;
bm=(BUF_MEM *)b->ptr;
if (in == NULL)
{
BIOerr(BIO_F_MEM_WRITE,BIO_R_NULL_PARAMETER);
goto end;
}
if(b->flags & BIO_FLAGS_MEM_RDONLY) {
BIOerr(BIO_F_MEM_WRITE,BIO_R_WRITE_TO_READ_ONLY_BIO);
goto end;
}
BIO_clear_retry_flags(b);
blen=bm->length;
if (BUF_MEM_grow(bm,blen+inl) != (blen+inl))
goto end;
memcpy(&(bm->data[blen]),in,inl);
ret=inl;
end:
return(ret);
}
static long mem_ctrl(BIO *b, int cmd, long num, char *ptr)
{
long ret=1;
char **pptr;
BUF_MEM *bm=(BUF_MEM *)b->ptr;
switch (cmd)
{
case BIO_CTRL_RESET:
if (bm->data != NULL) {
if(b->flags & BIO_FLAGS_MEM_RDONLY)
bm->data -= bm->max - bm->length;
else {
memset(bm->data,0,bm->max);
bm->length=0;
}
}
break;
case BIO_CTRL_EOF:
ret=(long)(bm->length == 0);
break;
case BIO_C_SET_BUF_MEM_EOF_RETURN:
b->num=(int)num;
break;
case BIO_CTRL_INFO:
ret=(long)bm->length;
if (ptr != NULL)
{
pptr=(char **)ptr;
*pptr=(char *)&(bm->data[0]);
}
break;
case BIO_C_SET_BUF_MEM:
mem_free(b);
b->shutdown=(int)num;
b->ptr=ptr;
break;
case BIO_C_GET_BUF_MEM_PTR:
if (ptr != NULL)
{
pptr=(char **)ptr;
*pptr=(char *)bm;
}
break;
case BIO_CTRL_GET_CLOSE:
ret=(long)b->shutdown;
break;
case BIO_CTRL_SET_CLOSE:
b->shutdown=(int)num;
break;
case BIO_CTRL_WPENDING:
ret=0L;
break;
case BIO_CTRL_PENDING:
ret=(long)bm->length;
break;
case BIO_CTRL_DUP:
case BIO_CTRL_FLUSH:
ret=1;
break;
case BIO_CTRL_PUSH:
case BIO_CTRL_POP:
default:
ret=0;
break;
}
return(ret);
}
static int mem_gets(BIO *bp, char *buf, int size)
{
int i,j;
int ret= -1;
char *p;
BUF_MEM *bm=(BUF_MEM *)bp->ptr;
BIO_clear_retry_flags(bp);
j=bm->length;
if (j <= 0) return(0);
p=bm->data;
for (i=0; i<j; i++)
{
if (p[i] == '\n') break;
}
if (i == j)
{
BIO_set_retry_read(bp);
}
else
i++;
if ((size-1) < i) i=size-1;
i=mem_read(bp,buf,i);
if (i > 0) buf[i]='\0';
ret=i;
return(ret);
}
static int mem_puts(BIO *bp, char *str)
{
int n,ret;
n=strlen(str);
ret=mem_write(bp,str,n);
return(ret);
}
