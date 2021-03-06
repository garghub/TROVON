int MAIN(int argc, char **argv)
{
ENGINE *e = NULL;
int ret=1;
DSA *dsa=NULL;
int i,badops=0;
const EVP_CIPHER *enc=NULL;
BIO *in=NULL,*out=NULL;
int informat,outformat,text=0,noout=0;
int pubin = 0, pubout = 0;
char *infile,*outfile,*prog,*engine;
char *passargin = NULL, *passargout = NULL;
char *passin = NULL, *passout = NULL;
int modulus=0;
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
if (!load_config(bio_err, NULL))
goto end;
engine=NULL;
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
else if (strcmp(*argv,"-passin") == 0)
{
if (--argc < 1) goto bad;
passargin= *(++argv);
}
else if (strcmp(*argv,"-passout") == 0)
{
if (--argc < 1) goto bad;
passargout= *(++argv);
}
else if (strcmp(*argv,"-engine") == 0)
{
if (--argc < 1) goto bad;
engine= *(++argv);
}
else if (strcmp(*argv,"-noout") == 0)
noout=1;
else if (strcmp(*argv,"-text") == 0)
text=1;
else if (strcmp(*argv,"-modulus") == 0)
modulus=1;
else if (strcmp(*argv,"-pubin") == 0)
pubin=1;
else if (strcmp(*argv,"-pubout") == 0)
pubout=1;
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
BIO_printf(bio_err," -inform arg input format - DER or PEM\n");
BIO_printf(bio_err," -outform arg output format - DER or PEM\n");
BIO_printf(bio_err," -in arg input file\n");
BIO_printf(bio_err," -passin arg input file pass phrase source\n");
BIO_printf(bio_err," -out arg output file\n");
BIO_printf(bio_err," -passout arg output file pass phrase source\n");
BIO_printf(bio_err," -engine e use engine e, possibly a hardware device.\n");
BIO_printf(bio_err," -des encrypt PEM output with cbc des\n");
BIO_printf(bio_err," -des3 encrypt PEM output with ede cbc des using 168 bit key\n");
#ifndef OPENSSL_NO_IDEA
BIO_printf(bio_err," -idea encrypt PEM output with cbc idea\n");
#endif
#ifndef OPENSSL_NO_AES
BIO_printf(bio_err," -aes128, -aes192, -aes256\n");
BIO_printf(bio_err," encrypt PEM output with cbc aes\n");
#endif
BIO_printf(bio_err," -text print the key in text\n");
BIO_printf(bio_err," -noout don't print key out\n");
BIO_printf(bio_err," -modulus print the DSA public value\n");
goto end;
}
ERR_load_crypto_strings();
e = setup_engine(bio_err, engine, 0);
if(!app_passwd(bio_err, passargin, passargout, &passin, &passout)) {
BIO_printf(bio_err, "Error getting passwords\n");
goto end;
}
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
BIO_printf(bio_err,"read DSA key\n");
if (informat == FORMAT_ASN1) {
if(pubin) dsa=d2i_DSA_PUBKEY_bio(in,NULL);
else dsa=d2i_DSAPrivateKey_bio(in,NULL);
} else if (informat == FORMAT_PEM) {
if(pubin) dsa=PEM_read_bio_DSA_PUBKEY(in,NULL, NULL, NULL);
else dsa=PEM_read_bio_DSAPrivateKey(in,NULL,NULL,passin);
} else
{
BIO_printf(bio_err,"bad input format specified for key\n");
goto end;
}
if (dsa == NULL)
{
BIO_printf(bio_err,"unable to load Key\n");
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
BIO_printf(bio_err,"writing DSA key\n");
if (outformat == FORMAT_ASN1) {
if(pubin || pubout) i=i2d_DSA_PUBKEY_bio(out,dsa);
else i=i2d_DSAPrivateKey_bio(out,dsa);
} else if (outformat == FORMAT_PEM) {
if(pubin || pubout)
i=PEM_write_bio_DSA_PUBKEY(out,dsa);
else i=PEM_write_bio_DSAPrivateKey(out,dsa,enc,
NULL,0,NULL, passout);
} else {
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
if(in != NULL) BIO_free(in);
if(out != NULL) BIO_free_all(out);
if(dsa != NULL) DSA_free(dsa);
if(passin) OPENSSL_free(passin);
if(passout) OPENSSL_free(passout);
apps_shutdown();
OPENSSL_EXIT(ret);
}
