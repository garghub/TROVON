int MAIN(int argc, char **argv)
{
int ret=1;
DSA *dsa=NULL;
int i,badops=0;
const EVP_CIPHER *enc=NULL;
BIO *in=NULL,*out=NULL;
int informat,outformat,text=0,noout=0;
char *infile,*outfile,*prog;
int modulus=0;
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
else if (strcmp(*argv,"-noout") == 0)
noout=1;
else if (strcmp(*argv,"-text") == 0)
text=1;
else if (strcmp(*argv,"-modulus") == 0)
modulus=1;
else if ((enc=EVP_get_cipherbyname(&(argv[0][1]))) == NULL)
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
BIO_printf(bio_err," -inform arg input format - one of DER NET PEM\n");
BIO_printf(bio_err," -outform arg output format - one of DER NET PEM\n");
BIO_printf(bio_err," -in arg input file\n");
BIO_printf(bio_err," -out arg output file\n");
BIO_printf(bio_err," -des encrypt PEM output with cbc des\n");
BIO_printf(bio_err," -des3 encrypt PEM output with ede cbc des using 168 bit key\n");
#ifndef NO_IDEA
BIO_printf(bio_err," -idea encrypt PEM output with cbc idea\n");
#endif
BIO_printf(bio_err," -text print the key in text\n");
BIO_printf(bio_err," -noout don't print key out\n");
BIO_printf(bio_err," -modulus print the DSA public value\n");
goto end;
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
{
perror(infile);
goto end;
}
}
BIO_printf(bio_err,"read DSA private key\n");
if (informat == FORMAT_ASN1)
dsa=d2i_DSAPrivateKey_bio(in,NULL);
else if (informat == FORMAT_PEM)
dsa=PEM_read_bio_DSAPrivateKey(in,NULL,NULL);
else
{
BIO_printf(bio_err,"bad input format specified for key\n");
goto end;
}
if (dsa == NULL)
{
BIO_printf(bio_err,"unable to load Private Key\n");
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
if (text)
if (!DSA_print(out,dsa,0))
{
perror(outfile);
ERR_print_errors(bio_err);
goto end;
}
if (modulus)
{
fprintf(stdout,"Public Key=");
BN_print(out,dsa->pub_key);
fprintf(stdout,"\n");
}
if (noout) goto end;
BIO_printf(bio_err,"writing DSA private key\n");
if (outformat == FORMAT_ASN1)
i=i2d_DSAPrivateKey_bio(out,dsa);
else if (outformat == FORMAT_PEM)
i=PEM_write_bio_DSAPrivateKey(out,dsa,enc,NULL,0,NULL);
else {
BIO_printf(bio_err,"bad output format specified for outfile\n");
goto end;
}
if (!i)
{
BIO_printf(bio_err,"unable to write private key\n");
ERR_print_errors(bio_err);
}
else
ret=0;
end:
if (in != NULL) BIO_free(in);
if (out != NULL) BIO_free(out);
if (dsa != NULL) DSA_free(dsa);
EXIT(ret);
}
