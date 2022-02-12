BIO *BIO_new_file(const char *filename, const char *mode)
{
BIO *ret;
FILE *file;
if ((file=fopen(filename,mode)) == NULL)
{
SYSerr(SYS_F_FOPEN,get_last_sys_error());
ERR_add_error_data(5,"fopen('",filename,"','",mode,"')");
BIOerr(BIO_F_BIO_NEW_FILE,ERR_R_SYS_LIB);
return(NULL);
}
if ((ret=BIO_new(BIO_s_file_internal())) == NULL)
return(NULL);
BIO_set_fp(ret,file,BIO_CLOSE);
return(ret);
}
BIO *BIO_new_fp(FILE *stream, int close_flag)
{
BIO *ret;
if ((ret=BIO_new(BIO_s_file())) == NULL)
return(NULL);
BIO_set_fp(ret,stream,close_flag);
return(ret);
}
BIO_METHOD *BIO_s_file(void)
{
return(&methods_filep);
}
static int MS_CALLBACK file_new(BIO *bi)
{
bi->init=0;
bi->num=0;
bi->ptr=NULL;
return(1);
}
static int MS_CALLBACK file_free(BIO *a)
{
if (a == NULL) return(0);
if (a->shutdown)
{
if ((a->init) && (a->ptr != NULL))
{
fclose((FILE *)a->ptr);
a->ptr=NULL;
}
a->init=0;
}
return(1);
}
static int MS_CALLBACK file_read(BIO *b, char *out, int outl)
{
int ret=0;
if (b->init && (out != NULL))
{
ret=fread(out,1,(int)outl,(FILE *)b->ptr);
}
return(ret);
}
static int MS_CALLBACK file_write(BIO *b, const char *in, int inl)
{
int ret=0;
if (b->init && (in != NULL))
{
if (fwrite(in,(int)inl,1,(FILE *)b->ptr))
ret=inl;
}
return(ret);
}
static long MS_CALLBACK file_ctrl(BIO *b, int cmd, long num, void *ptr)
{
long ret=1;
FILE *fp=(FILE *)b->ptr;
FILE **fpp;
char p[4];
switch (cmd)
{
case BIO_C_FILE_SEEK:
case BIO_CTRL_RESET:
ret=(long)fseek(fp,num,0);
break;
case BIO_CTRL_EOF:
ret=(long)feof(fp);
break;
case BIO_C_FILE_TELL:
case BIO_CTRL_INFO:
ret=ftell(fp);
break;
case BIO_C_SET_FILE_PTR:
file_free(b);
b->shutdown=(int)num&BIO_CLOSE;
b->ptr=(char *)ptr;
b->init=1;
#if defined(MSDOS) || defined(WINDOWS)
if (num & BIO_FP_TEXT)
_setmode(fileno((FILE *)ptr),_O_TEXT);
else
_setmode(fileno((FILE *)ptr),_O_BINARY);
#endif
break;
case BIO_C_SET_FILENAME:
file_free(b);
b->shutdown=(int)num&BIO_CLOSE;
if (num & BIO_FP_APPEND)
{
if (num & BIO_FP_READ)
strcpy(p,"a+");
else strcpy(p,"a");
}
else if ((num & BIO_FP_READ) && (num & BIO_FP_WRITE))
strcpy(p,"r+");
else if (num & BIO_FP_WRITE)
strcpy(p,"w");
else if (num & BIO_FP_READ)
strcpy(p,"r");
else
{
BIOerr(BIO_F_FILE_CTRL,BIO_R_BAD_FOPEN_MODE);
ret=0;
break;
}
#if defined(MSDOS) || defined(WINDOWS)
if (!(num & BIO_FP_TEXT))
strcat(p,"b");
else
strcat(p,"t");
#endif
fp=fopen(ptr,p);
if (fp == NULL)
{
SYSerr(SYS_F_FOPEN,get_last_sys_error());
ERR_add_error_data(5,"fopen('",ptr,"','",p,"')");
BIOerr(BIO_F_FILE_CTRL,ERR_R_SYS_LIB);
ret=0;
break;
}
b->ptr=(char *)fp;
b->init=1;
break;
case BIO_C_GET_FILE_PTR:
if (ptr != NULL)
{
fpp=(FILE **)ptr;
*fpp=(FILE *)b->ptr;
}
break;
case BIO_CTRL_GET_CLOSE:
ret=(long)b->shutdown;
break;
case BIO_CTRL_SET_CLOSE:
b->shutdown=(int)num;
break;
case BIO_CTRL_FLUSH:
fflush((FILE *)b->ptr);
break;
case BIO_CTRL_DUP:
ret=1;
break;
case BIO_CTRL_WPENDING:
case BIO_CTRL_PENDING:
case BIO_CTRL_PUSH:
case BIO_CTRL_POP:
default:
ret=0;
break;
}
return(ret);
}
static int MS_CALLBACK file_gets(BIO *bp, char *buf, int size)
{
int ret=0;
buf[0]='\0';
fgets(buf,size,(FILE *)bp->ptr);
if (buf[0] != '\0')
ret=strlen(buf);
return(ret);
}
static int MS_CALLBACK file_puts(BIO *bp, const char *str)
{
int n,ret;
n=strlen(str);
ret=file_write(bp,str,n);
return(ret);
}
