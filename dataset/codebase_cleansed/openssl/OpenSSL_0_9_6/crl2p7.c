int MAIN(int argc, char **argv)
{
int i,badops=0;
BIO *in=NULL,*out=NULL;
int informat,outformat;
char *infile,*outfile,*prog,*certfile;
PKCS7 *p7 = NULL;
PKCS7_SIGNED *p7s = NULL;
X509_CRL *crl=NULL;
STACK *certflst=NULL;
STACK_OF(X509_CRL) *crl_stack=NULL;
STACK_OF(X509) *cert_stack=NULL;
int ret=1,nocrl=0;
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
else if (strcmp(*argv,"-nocrl") == 0)
{
nocrl=1;
}
else if (strcmp(*argv,"-out") == 0)
{
if (--argc < 1) goto bad;
outfile= *(++argv);
}
else if (strcmp(*argv,"-certfile") == 0)
{
if (--argc < 1) goto bad;
if(!certflst) certflst = sk_new_null();
sk_push(certflst,*(++argv));
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
BIO_printf(bio_err,"%s [options] <infile >outfile\n",prog);
BIO_printf(bio_err,"where options are\n");
BIO_printf(bio_err," -inform arg input format - DER or PEM\n");
BIO_printf(bio_err," -outform arg output format - DER or PEM\n");
BIO_printf(bio_err," -in arg input file\n");
BIO_printf(bio_err," -out arg output file\n");
BIO_printf(bio_err," -certfile arg certificates file of chain to a trusted CA\n");
BIO_printf(bio_err," (can be used more than once)\n");
BIO_printf(bio_err," -nocrl no crl to load, just certs from '-certfile'\n");
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
if (!nocrl)
{
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
if (informat == FORMAT_ASN1)
crl=d2i_X509_CRL_bio(in,NULL);
else if (informat == FORMAT_PEM)
crl=PEM_read_bio_X509_CRL(in,NULL,NULL,NULL);
else {
BIO_printf(bio_err,"bad input format specified for input crl\n");
goto end;
}
if (crl == NULL)
{
BIO_printf(bio_err,"unable to load CRL\n");
ERR_print_errors(bio_err);
goto end;
}
}
if ((p7=PKCS7_new()) == NULL) goto end;
if ((p7s=PKCS7_SIGNED_new()) == NULL) goto end;
p7->type=OBJ_nid2obj(NID_pkcs7_signed);
p7->d.sign=p7s;
p7s->contents->type=OBJ_nid2obj(NID_pkcs7_data);
if (!ASN1_INTEGER_set(p7s->version,1)) goto end;
if ((crl_stack=sk_X509_CRL_new_null()) == NULL) goto end;
p7s->crl=crl_stack;
if (crl != NULL)
{
sk_X509_CRL_push(crl_stack,crl);
crl=NULL;
}
if ((cert_stack=sk_X509_new_null()) == NULL) goto end;
p7s->cert=cert_stack;
if(certflst) for(i = 0; i < sk_num(certflst); i++) {
certfile = sk_value(certflst, i);
if (add_certs_from_file(cert_stack,certfile) < 0)
{
BIO_printf(bio_err, "error loading certificates\n");
ERR_print_errors(bio_err);
goto end;
}
}
sk_free(certflst);
if (outfile == NULL)
{
BIO_set_fp(out,stdout,BIO_NOCLOSE);
#ifdef VMS
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
if (in != NULL) BIO_free(in);
if (out != NULL) BIO_free_all(out);
if (p7 != NULL) PKCS7_free(p7);
if (crl != NULL) X509_CRL_free(crl);
EXIT(ret);
}
