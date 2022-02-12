int MAIN(int argc, char **argv)
{
X509_CRL *x=NULL;
int ret=1,i,num,badops=0;
BIO *out=NULL;
int informat,outformat;
char *infile=NULL,*outfile=NULL;
int hash=0,issuer=0,lastupdate=0,nextupdate=0,noout=0,text=0;
char **pp,buf[256];
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
if (bio_out == NULL)
if ((bio_out=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_out,stdout,BIO_NOCLOSE);
informat=FORMAT_PEM;
outformat=FORMAT_PEM;
argc--;
argv++;
num=0;
while (argc >= 1)
{
#ifdef undef
if (strcmp(*argv,"-p") == 0)
{
if (--argc < 1) goto bad;
if (!args_from_file(++argv,Nargc,Nargv)) { goto end; }*/
}
#endif
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
text = 1;
else if (strcmp(*argv,"-hash") == 0)
hash= ++num;
else if (strcmp(*argv,"-issuer") == 0)
issuer= ++num;
else if (strcmp(*argv,"-lastupdate") == 0)
lastupdate= ++num;
else if (strcmp(*argv,"-nextupdate") == 0)
nextupdate= ++num;
else if (strcmp(*argv,"-noout") == 0)
noout= ++num;
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
for (pp=crl_usage; (*pp != NULL); pp++)
BIO_printf(bio_err,*pp);
goto end;
}
ERR_load_crypto_strings();
X509V3_add_standard_extensions();
x=load_crl(infile,informat);
if (x == NULL) { goto end; }
if (num)
{
for (i=1; i<=num; i++)
{
if (issuer == i)
{
X509_NAME_oneline(x->crl->issuer,buf,256);
BIO_printf(bio_out,"issuer= %s\n",buf);
}
if (hash == i)
{
BIO_printf(bio_out,"%08lx\n",
X509_NAME_hash(x->crl->issuer));
}
if (lastupdate == i)
{
BIO_printf(bio_out,"lastUpdate=");
ASN1_TIME_print(bio_out,x->crl->lastUpdate);
BIO_printf(bio_out,"\n");
}
if (nextupdate == i)
{
BIO_printf(bio_out,"nextUpdate=");
if (x->crl->nextUpdate != NULL)
ASN1_TIME_print(bio_out,x->crl->nextUpdate);
else
BIO_printf(bio_out,"NONE");
BIO_printf(bio_out,"\n");
}
}
}
out=BIO_new(BIO_s_file());
if (out == NULL)
{
ERR_print_errors(bio_err);
goto end;
}
if (outfile == NULL)
BIO_set_fp(out,stdout,BIO_NOCLOSE);
else
{
if (BIO_write_filename(out,outfile) <= 0)
{
perror(outfile);
goto end;
}
}
if (text) X509_CRL_print(out, x);
if (noout) goto end;
if (outformat == FORMAT_ASN1)
i=(int)i2d_X509_CRL_bio(out,x);
else if (outformat == FORMAT_PEM)
i=PEM_write_bio_X509_CRL(out,x);
else
{
BIO_printf(bio_err,"bad output format specified for outfile\n");
goto end;
}
if (!i) { BIO_printf(bio_err,"unable to write CRL\n"); goto end; }
ret=0;
end:
BIO_free(out);
BIO_free(bio_out);
X509_CRL_free(x);
X509V3_EXT_cleanup();
EXIT(ret);
}
static X509_CRL *load_crl(char *infile, int format)
{
X509_CRL *x=NULL;
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
x=d2i_X509_CRL_bio(in,NULL);
else if (format == FORMAT_PEM)
x=PEM_read_bio_X509_CRL(in,NULL,NULL);
else {
BIO_printf(bio_err,"bad input format specified for input crl\n");
goto end;
}
if (x == NULL)
{
BIO_printf(bio_err,"unable to load CRL\n");
ERR_print_errors(bio_err);
goto end;
}
end:
BIO_free(in);
return(x);
}
