void ERR_print_errors_fp(FILE *fp)
{
unsigned long l;
char buf[200];
const char *file,*data;
int line,flags;
unsigned long es;
es=CRYPTO_thread_id();
while ((l=ERR_get_error_line_data(&file,&line,&data,&flags)) != 0)
{
fprintf(fp,"%lu:%s:%s:%d:%s\n",es,ERR_error_string(l,buf),
file,line,(flags&ERR_TXT_STRING)?data:"");
}
}
void ERR_print_errors(BIO *bp)
{
unsigned long l;
char buf[256];
char buf2[256];
const char *file,*data;
int line,flags;
unsigned long es;
es=CRYPTO_thread_id();
while ((l=ERR_get_error_line_data(&file,&line,&data,&flags)) != 0)
{
sprintf(buf2,"%lu:%s:%s:%d:",es,ERR_error_string(l,buf),
file,line);
BIO_write(bp,buf2,strlen(buf2));
if (flags & ERR_TXT_STRING)
BIO_write(bp,data,strlen(data));
BIO_write(bp,"\n",1);
}
}
