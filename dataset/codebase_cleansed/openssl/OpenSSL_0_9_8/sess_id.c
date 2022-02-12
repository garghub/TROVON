int MAIN(int argc, char **argv)
{
SSL_SESSION *x=NULL;
int ret=1,i,num,badops=0;
BIO *out=NULL;
int informat,outformat;
char *infile=NULL,*outfile=NULL,*context=NULL;
int cert=0,noout=0,text=0;
const char **pp;
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
informat=FORMAT_PEM;
outformat=FORMAT_PEM;
argc--;
argv++;
num=0;
while (argc >= 1)
{
if (strcmp(*argv,"-inform") == 0)
{
if (--argc < 1) goto bad;
informat=str2fmt(*(++argv));
}
else if (strcmp(*argv,"-outform") == 0)
{
if (--argc < 1) goto bad;
outformat=str2fmt(*(++argv));
}
else if (strcmp(*argv,"-in") == 0)
{
if (--argc < 1) goto bad;
infile= *(++argv);
}
else if (strcmp(*argv,"-out") == 0)
{
if (--argc < 1) goto bad;
outfile= *(++argv);
}
else if (strcmp(*argv,"-text") == 0)
text= ++num;
else if (strcmp(*argv,"-cert") == 0)
cert= ++num;
else if (strcmp(*argv,"-noout") == 0)
noout= ++num;
else if (strcmp(*argv,"-context") == 0)
{
if(--argc < 1) goto bad;
context=*++argv;
}
else
{
BIO_printf(bio_err,"unknown option %s\n",*argv);
badops=1;
break;
}
argc--;
argv++;
}
if (badops)
{
bad:
for (pp=sess_id_usage; (*pp != NULL); pp++)
BIO_printf(bio_err,"%s",*pp);
goto end;
}
ERR_load_crypto_strings();
x=load_sess_id(infile,informat);
if (x == NULL) { goto end; }
if(context)
{
x->sid_ctx_length=strlen(context);
if(x->sid_ctx_length > SSL_MAX_SID_CTX_LENGTH)
{
BIO_printf(bio_err,"Context too long\n");
goto end;
}
memcpy(x->sid_ctx,context,x->sid_ctx_length);
}
#ifdef undef
{
SSL_SESSION *s;
char buf[1024*10],*p;
int i;
s=SSL_SESSION_new();
p= &buf;
i=i2d_SSL_SESSION(x,&p);
p= &buf;
d2i_SSL_SESSION(&s,&p,(long)i);
p= &buf;
d2i_SSL_SESSION(&s,&p,(long)i);
p= &buf;
d2i_SSL_SESSION(&s,&p,(long)i);
SSL_SESSION_free(s);
}
#endif
if (!noout || text)
{
out=BIO_new(BIO_s_file());
if (out == NULL)
{
ERR_print_errors(bio_err);
goto end;
}
if (outfile == NULL)
{
BIO_set_fp(out,stdout,BIO_NOCLOSE);
#ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
}
else
{
if (BIO_write_filename(out,outfile) <= 0)
{
perror(outfile);
goto end;
}
}
}
if (text)
{
SSL_SESSION_print(out,x);
if (cert)
{
if (x->peer == NULL)
BIO_puts(out,"No certificate present\n");
else
X509_print(out,x->peer);
}
}
if (!noout && !cert)
{
if (outformat == FORMAT_ASN1)
i=i2d_SSL_SESSION_bio(out,x);
else if (outformat == FORMAT_PEM)
i=PEM_write_bio_SSL_SESSION(out,x);
else {
BIO_printf(bio_err,"bad output format specified for outfile\n");
goto end;
}
if (!i) {
BIO_printf(bio_err,"unable to write SSL_SESSION\n");
goto end;
}
}
else if (!noout && (x->peer != NULL))
{
if (outformat == FORMAT_ASN1)
i=(int)i2d_X509_bio(out,x->peer);
else if (outformat == FORMAT_PEM)
i=PEM_write_bio_X509(out,x->peer);
else {
BIO_printf(bio_err,"bad output format specified for outfile\n");
goto end;
}
if (!i) {
BIO_printf(bio_err,"unable to write X509\n");
goto end;
}
}
ret=0;
end:
if (out != NULL) BIO_free_all(out);
if (x != NULL) SSL_SESSION_free(x);
apps_shutdown();
OPENSSL_EXIT(ret);
}
static SSL_SESSION *load_sess_id(char *infile, int format)
{
SSL_SESSION *x=NULL;
BIO *in=NULL;
in=BIO_new(BIO_s_file());
if (in == NULL)
{
ERR_print_errors(bio_err);
goto end;
}
if (infile == NULL)
BIO_set_fp(in,stdin,BIO_NOCLOSE);
else
{
if (BIO_read_filename(in,infile) <= 0)
{
perror(infile);
goto end;
}
}
if (format == FORMAT_ASN1)
x=d2i_SSL_SESSION_bio(in,NULL);
else if (format == FORMAT_PEM)
x=PEM_read_bio_SSL_SESSION(in,NULL,NULL,NULL);
else {
BIO_printf(bio_err,"bad input format specified for input crl\n");
goto end;
}
if (x == NULL)
{
BIO_printf(bio_err,"unable to load SSL_SESSION\n");
ERR_print_errors(bio_err);
goto end;
}
end:
if (in != NULL) BIO_free(in);
return(x);
}
