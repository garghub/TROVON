int BIO_printf (BIO *bio, ...)
{
va_list args;
char *format;
int ret;
MS_STATIC char hugebuf[1024*2];
va_start(args, bio);
format=va_arg(args, char *);
hugebuf[0]='\0';
vsprintf(hugebuf,format,args);
ret=BIO_write(bio,hugebuf,strlen(hugebuf));
va_end(args);
return(ret);
}
