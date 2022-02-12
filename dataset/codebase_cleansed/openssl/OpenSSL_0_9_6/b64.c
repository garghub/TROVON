int main(argc,argv)
int argc;
char **argv;
{
char *strbuf=NULL;
unsigned char *buff=NULL,*bufsize=NULL;
int bsize=BSIZE,verbose=0;
int ret=1,inl;
unsigned char key[24],iv[MD5_DIGEST_LENGTH];
char *str=NULL;
char *hkey=NULL,*hiv=NULL;
int enc=1,printkey=0,i,base64=0;
int debug=0;
EVP_CIPHER *cipher=NULL,*c;
char *inf=NULL,*outf=NULL;
BIO *in=NULL,*out=NULL,*b64=NULL,*benc=NULL,*rbio=NULL,*wbio=NULL;
#define PROG_NAME_SIZE 16
char pname[PROG_NAME_SIZE];
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE);
base64=1;
argc--;
argv++;
while (argc >= 1)
{
if (strcmp(*argv,"-e") == 0)
enc=1;
if (strcmp(*argv,"-in") == 0)
{
if (--argc < 1) goto bad;
inf= *(++argv);
}
else if (strcmp(*argv,"-out") == 0)
{
if (--argc < 1) goto bad;
outf= *(++argv);
}
else if (strcmp(*argv,"-d") == 0)
enc=0;
else if (strcmp(*argv,"-v") == 0)
verbose=1;
else if (strcmp(*argv,"-debug") == 0)
debug=1;
else if (strcmp(*argv,"-bufsize") == 0)
{
if (--argc < 1) goto bad;
bufsize=(unsigned char *)*(++argv);
}
else
{
BIO_printf(bio_err,"unknown option '%s'\n",*argv);
bad:
BIO_printf(bio_err,"options are\n");
BIO_printf(bio_err,"%-14s input file\n","-in <file>");
BIO_printf(bio_err,"%-14s output file\n","-out <file>");
BIO_printf(bio_err,"%-14s encode\n","-e");
BIO_printf(bio_err,"%-14s decode\n","-d");
BIO_printf(bio_err,"%-14s buffer size\n","-bufsize <n>");
goto end;
}
argc--;
argv++;
}
if (bufsize != NULL)
{
int i;
unsigned long n;
for (n=0; *bufsize; bufsize++)
{
i= *bufsize;
if ((i <= '9') && (i >= '0'))
n=n*10+i-'0';
else if (i == 'k')
{
n*=1024;
bufsize++;
break;
}
}
if (*bufsize != '\0')
{
BIO_printf(bio_err,"invalid 'bufsize' specified.\n");
goto end;
}
if (n < 80) n=80;
bsize=(int)n;
if (verbose) BIO_printf(bio_err,"bufsize=%d\n",bsize);
}
strbuf=OPENSSL_malloc(SIZE);
buff=(unsigned char *)OPENSSL_malloc(EVP_ENCODE_LENGTH(bsize));
if ((buff == NULL) || (strbuf == NULL))
{
BIO_printf(bio_err,"OPENSSL_malloc failure\n");
goto end;
}
in=BIO_new(BIO_s_file());
out=BIO_new(BIO_s_file());
if ((in == NULL) || (out == NULL))
{
ERR_print_errors(bio_err);
goto end;
}
if (debug)
{
BIO_set_callback(in,BIO_debug_callback);
BIO_set_callback(out,BIO_debug_callback);
BIO_set_callback_arg(in,bio_err);
BIO_set_callback_arg(out,bio_err);
}
if (inf == NULL)
BIO_set_fp(in,stdin,BIO_NOCLOSE);
else
{
if (BIO_read_filename(in,inf) <= 0)
{
perror(inf);
goto end;
}
}
if (outf == NULL)
BIO_set_fp(out,stdout,BIO_NOCLOSE);
else
{
if (BIO_write_filename(out,outf) <= 0)
{
perror(outf);
goto end;
}
}
rbio=in;
wbio=out;
if (base64)
{
if ((b64=BIO_new(BIO_f_base64())) == NULL)
goto end;
if (debug)
{
BIO_set_callback(b64,BIO_debug_callback);
BIO_set_callback_arg(b64,bio_err);
}
if (enc)
wbio=BIO_push(b64,wbio);
else
rbio=BIO_push(b64,rbio);
}
for (;;)
{
inl=BIO_read(rbio,(char *)buff,bsize);
if (inl <= 0) break;
if (BIO_write(wbio,(char *)buff,inl) != inl)
{
BIO_printf(bio_err,"error writing output file\n");
goto end;
}
}
BIO_flush(wbio);
ret=0;
if (verbose)
{
BIO_printf(bio_err,"bytes read :%8ld\n",BIO_number_read(in));
BIO_printf(bio_err,"bytes written:%8ld\n",BIO_number_written(out));
}
end:
if (strbuf != NULL) OPENSSL_free(strbuf);
if (buff != NULL) OPENSSL_free(buff);
if (in != NULL) BIO_free(in);
if (out != NULL) BIO_free(out);
if (benc != NULL) BIO_free(benc);
if (b64 != NULL) BIO_free(b64);
EXIT(ret);
}
