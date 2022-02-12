int MAIN(int argc, char **argv)
{
PKCS7 *p7=NULL;
int i,badops=0;
#if !defined(NO_DES) || !defined(NO_IDEA)
EVP_CIPHER *enc=NULL;
#endif
BIO *in=NULL,*out=NULL;
int informat,outformat;
char *infile,*outfile,*prog,buf[256];
int print_certs=0;
int ret=0;
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
infile=NULL;
outfile=NULL;
informat=FORMAT_PEM;
outformat=FORMAT_PEM;
prog=argv[0];
argc--;
argv++;
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
else if (strcmp(*argv,"-print_certs") == 0)
print_certs=1;
#ifndef NO_DES
else if (strcmp(*argv,"-des") == 0)
enc=EVP_des_cbc();
else if (strcmp(*argv,"-des3") == 0)
enc=EVP_des_ede3_cbc();
#endif
#ifndef NO_IDEA
else if (strcmp(*argv,"-idea") == 0)
enc=EVP_idea_cbc();
#endif
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
BIO_printf(bio_err,"%s [options] <infile >outfile\n",prog);
BIO_printf(bio_err,"where options are\n");
BIO_printf(bio_err," -inform arg input format - one of DER TXT PEM\n");
BIO_printf(bio_err," -outform arg output format - one of DER TXT PEM\n");
BIO_printf(bio_err," -in arg input file\n");
BIO_printf(bio_err," -out arg output file\n");
BIO_printf(bio_err," -print_certs print any certs or crl in the input\n");
BIO_printf(bio_err," -des encrypt PEM output with cbc des\n");
BIO_printf(bio_err," -des3 encrypt PEM output with ede cbc des using 168 bit key\n");
#ifndef NO_IDEA
BIO_printf(bio_err," -idea encrypt PEM output with cbc idea\n");
#endif
EXIT(1);
}
ERR_load_crypto_strings();
in=BIO_new(BIO_s_file());
out=BIO_new(BIO_s_file());
if ((in == NULL) || (out == NULL))
{
ERR_print_errors(bio_err);
goto end;
}
if (infile == NULL)
BIO_set_fp(in,stdin,BIO_NOCLOSE);
else
{
if (BIO_read_filename(in,infile) <= 0)
if (in == NULL)
{
perror(infile);
goto end;
}
}
if (informat == FORMAT_ASN1)
p7=d2i_PKCS7_bio(in,NULL);
else if (informat == FORMAT_PEM)
p7=PEM_read_bio_PKCS7(in,NULL,NULL,NULL);
else
{
BIO_printf(bio_err,"bad input format specified for pkcs7 object\n");
goto end;
}
if (p7 == NULL)
{
BIO_printf(bio_err,"unable to load PKCS7 object\n");
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
if (print_certs)
{
STACK_OF(X509) *certs=NULL;
STACK_OF(X509_CRL) *crls=NULL;
i=OBJ_obj2nid(p7->type);
switch (i)
{
case NID_pkcs7_signed:
certs=p7->d.sign->cert;
crls=p7->d.sign->crl;
break;
case NID_pkcs7_signedAndEnveloped:
certs=p7->d.signed_and_enveloped->cert;
crls=p7->d.signed_and_enveloped->crl;
break;
default:
break;
}
if (certs != NULL)
{
X509 *x;
for (i=0; i<sk_X509_num(certs); i++)
{
x=sk_X509_value(certs,i);
X509_NAME_oneline(X509_get_subject_name(x),
buf,256);
BIO_puts(out,"subject=");
BIO_puts(out,buf);
X509_NAME_oneline(X509_get_issuer_name(x),
buf,256);
BIO_puts(out,"\nissuer= ");
BIO_puts(out,buf);
BIO_puts(out,"\n");
PEM_write_bio_X509(out,x);
BIO_puts(out,"\n");
}
}
if (crls != NULL)
{
X509_CRL *crl;
for (i=0; i<sk_X509_CRL_num(crls); i++)
{
crl=sk_X509_CRL_value(crls,i);
X509_NAME_oneline(crl->crl->issuer,buf,256);
BIO_puts(out,"issuer= ");
BIO_puts(out,buf);
BIO_puts(out,"\nlast update=");
ASN1_TIME_print(out,crl->crl->lastUpdate);
BIO_puts(out,"\nnext update=");
ASN1_TIME_print(out,crl->crl->nextUpdate);
BIO_puts(out,"\n");
PEM_write_bio_X509_CRL(out,crl);
BIO_puts(out,"\n");
}
}
ret=0;
goto end;
}
if (outformat == FORMAT_ASN1)
i=i2d_PKCS7_bio(out,p7);
else if (outformat == FORMAT_PEM)
i=PEM_write_bio_PKCS7(out,p7);
else {
BIO_printf(bio_err,"bad output format specified for outfile\n");
goto end;
}
if (!i)
{
BIO_printf(bio_err,"unable to write pkcs7 object\n");
ERR_print_errors(bio_err);
goto end;
}
ret=0;
end:
if (p7 != NULL) PKCS7_free(p7);
if (in != NULL) BIO_free(in);
if (out != NULL) BIO_free(out);
EXIT(ret);
}
