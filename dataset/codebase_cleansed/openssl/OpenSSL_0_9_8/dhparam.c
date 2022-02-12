int MAIN(int argc, char **argv)
{
#ifndef OPENSSL_NO_ENGINE
ENGINE *e = NULL;
#endif
DH *dh=NULL;
int i,badops=0,text=0;
#ifndef OPENSSL_NO_DSA
int dsaparam=0;
#endif
BIO *in=NULL,*out=NULL;
int informat,outformat,check=0,noout=0,C=0,ret=1;
char *infile,*outfile,*prog;
char *inrand=NULL;
#ifndef OPENSSL_NO_ENGINE
char *engine=NULL;
#endif
int num = 0, g = 0;
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
if (!load_config(bio_err, NULL))
goto end;
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
#ifndef OPENSSL_NO_ENGINE
else if (strcmp(*argv,"-engine") == 0)
{
if (--argc < 1) goto bad;
engine= *(++argv);
}
#endif
else if (strcmp(*argv,"-check") == 0)
check=1;
else if (strcmp(*argv,"-text") == 0)
text=1;
#ifndef OPENSSL_NO_DSA
else if (strcmp(*argv,"-dsaparam") == 0)
dsaparam=1;
#endif
else if (strcmp(*argv,"-C") == 0)
C=1;
else if (strcmp(*argv,"-noout") == 0)
noout=1;
else if (strcmp(*argv,"-2") == 0)
g=2;
else if (strcmp(*argv,"-5") == 0)
g=5;
else if (strcmp(*argv,"-rand") == 0)
{
if (--argc < 1) goto bad;
inrand= *(++argv);
}
else if (((sscanf(*argv,"%d",&num) == 0) || (num <= 0)))
goto bad;
argv++;
argc--;
}
if (badops)
{
bad:
BIO_printf(bio_err,"%s [options] [numbits]\n",prog);
BIO_printf(bio_err,"where options are\n");
BIO_printf(bio_err," -inform arg input format - one of DER PEM\n");
BIO_printf(bio_err," -outform arg output format - one of DER PEM\n");
BIO_printf(bio_err," -in arg input file\n");
BIO_printf(bio_err," -out arg output file\n");
#ifndef OPENSSL_NO_DSA
BIO_printf(bio_err," -dsaparam read or generate DSA parameters, convert to DH\n");
#endif
BIO_printf(bio_err," -check check the DH parameters\n");
BIO_printf(bio_err," -text print a text form of the DH parameters\n");
BIO_printf(bio_err," -C Output C code\n");
BIO_printf(bio_err," -2 generate parameters using 2 as the generator value\n");
BIO_printf(bio_err," -5 generate parameters using 5 as the generator value\n");
BIO_printf(bio_err," numbits number of bits in to generate (default 512)\n");
#ifndef OPENSSL_NO_ENGINE
BIO_printf(bio_err," -engine e use engine e, possibly a hardware device.\n");
#endif
BIO_printf(bio_err," -rand file%cfile%c...\n", LIST_SEPARATOR_CHAR, LIST_SEPARATOR_CHAR);
BIO_printf(bio_err," - load the file (or the files in the directory) into\n");
BIO_printf(bio_err," the random number generator\n");
BIO_printf(bio_err," -noout no output\n");
goto end;
}
ERR_load_crypto_strings();
#ifndef OPENSSL_NO_ENGINE
e = setup_engine(bio_err, engine, 0);
#endif
if (g && !num)
num = DEFBITS;
#ifndef OPENSSL_NO_DSA
if (dsaparam)
{
if (g)
{
BIO_printf(bio_err, "generator may not be chosen for DSA parameters\n");
goto end;
}
}
else
#endif
{
if (num && !g)
g = 2;
}
if(num) {
BN_GENCB cb;
BN_GENCB_set(&cb, dh_cb, bio_err);
if (!app_RAND_load_file(NULL, bio_err, 1) && inrand == NULL)
{
BIO_printf(bio_err,"warning, not much extra random data, consider using the -rand option\n");
}
if (inrand != NULL)
BIO_printf(bio_err,"%ld semi-random bytes loaded\n",
app_RAND_load_files(inrand));
#ifndef OPENSSL_NO_DSA
if (dsaparam)
{
DSA *dsa = DSA_new();
BIO_printf(bio_err,"Generating DSA parameters, %d bit long prime\n",num);
if(!dsa || !DSA_generate_parameters_ex(dsa, num,
NULL, 0, NULL, NULL, &cb))
{
if(dsa) DSA_free(dsa);
ERR_print_errors(bio_err);
goto end;
}
dh = DSA_dup_DH(dsa);
DSA_free(dsa);
if (dh == NULL)
{
ERR_print_errors(bio_err);
goto end;
}
}
else
#endif
{
dh = DH_new();
BIO_printf(bio_err,"Generating DH parameters, %d bit long safe prime, generator %d\n",num,g);
BIO_printf(bio_err,"This is going to take a long time\n");
if(!dh || !DH_generate_parameters_ex(dh, num, g, &cb))
{
if(dh) DH_free(dh);
ERR_print_errors(bio_err);
goto end;
}
}
app_RAND_write_file(NULL, bio_err);
} else {
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
if (informat != FORMAT_ASN1 && informat != FORMAT_PEM)
{
BIO_printf(bio_err,"bad input format specified\n");
goto end;
}
#ifndef OPENSSL_NO_DSA
if (dsaparam)
{
DSA *dsa;
if (informat == FORMAT_ASN1)
dsa=d2i_DSAparams_bio(in,NULL);
else
dsa=PEM_read_bio_DSAparams(in,NULL,NULL,NULL);
if (dsa == NULL)
{
BIO_printf(bio_err,"unable to load DSA parameters\n");
ERR_print_errors(bio_err);
goto end;
}
dh = DSA_dup_DH(dsa);
DSA_free(dsa);
if (dh == NULL)
{
ERR_print_errors(bio_err);
goto end;
}
}
else
#endif
{
if (informat == FORMAT_ASN1)
dh=d2i_DHparams_bio(in,NULL);
else
dh=PEM_read_bio_DHparams(in,NULL,NULL,NULL);
if (dh == NULL)
{
BIO_printf(bio_err,"unable to load DH parameters\n");
ERR_print_errors(bio_err);
goto end;
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
{
DHparams_print(out,dh);
}
if (check)
{
if (!DH_check(dh,&i))
{
ERR_print_errors(bio_err);
goto end;
}
if (i & DH_CHECK_P_NOT_PRIME)
printf("p value is not prime\n");
if (i & DH_CHECK_P_NOT_SAFE_PRIME)
printf("p value is not a safe prime\n");
if (i & DH_UNABLE_TO_CHECK_GENERATOR)
printf("unable to check the generator value\n");
if (i & DH_NOT_SUITABLE_GENERATOR)
printf("the g value is not a generator\n");
if (i == 0)
printf("DH parameters appear to be ok.\n");
}
if (C)
{
unsigned char *data;
int len,l,bits;
len=BN_num_bytes(dh->p);
bits=BN_num_bits(dh->p);
data=(unsigned char *)OPENSSL_malloc(len);
if (data == NULL)
{
perror("OPENSSL_malloc");
goto end;
}
printf("#ifndef HEADER_DH_H\n"
"#include <openssl/dh.h>\n"
"#endif\n");
printf("DH *get_dh%d()\n\t{\n",bits);
l=BN_bn2bin(dh->p,data);
printf("\tstatic unsigned char dh%d_p[]={",bits);
for (i=0; i<l; i++)
{
if ((i%12) == 0) printf("\n\t\t");
printf("0x%02X,",data[i]);
}
printf("\n\t\t};\n");
l=BN_bn2bin(dh->g,data);
printf("\tstatic unsigned char dh%d_g[]={",bits);
for (i=0; i<l; i++)
{
if ((i%12) == 0) printf("\n\t\t");
printf("0x%02X,",data[i]);
}
printf("\n\t\t};\n");
printf("\tDH *dh;\n\n");
printf("\tif ((dh=DH_new()) == NULL) return(NULL);\n");
printf("\tdh->p=BN_bin2bn(dh%d_p,sizeof(dh%d_p),NULL);\n",
bits,bits);
printf("\tdh->g=BN_bin2bn(dh%d_g,sizeof(dh%d_g),NULL);\n",
bits,bits);
printf("\tif ((dh->p == NULL) || (dh->g == NULL))\n");
printf("\t\t{ DH_free(dh); return(NULL); }\n");
if (dh->length)
printf("\tdh->length = %ld;\n", dh->length);
printf("\treturn(dh);\n\t}\n");
OPENSSL_free(data);
}
if (!noout)
{
if (outformat == FORMAT_ASN1)
i=i2d_DHparams_bio(out,dh);
else if (outformat == FORMAT_PEM)
i=PEM_write_bio_DHparams(out,dh);
else {
BIO_printf(bio_err,"bad output format specified for outfile\n");
goto end;
}
if (!i)
{
BIO_printf(bio_err,"unable to write DH parameters\n");
ERR_print_errors(bio_err);
goto end;
}
}
ret=0;
end:
if (in != NULL) BIO_free(in);
if (out != NULL) BIO_free_all(out);
if (dh != NULL) DH_free(dh);
apps_shutdown();
OPENSSL_EXIT(ret);
}
static int MS_CALLBACK dh_cb(int p, int n, BN_GENCB *cb)
{
char c='*';
if (p == 0) c='.';
if (p == 1) c='+';
if (p == 2) c='*';
if (p == 3) c='\n';
BIO_write(cb->arg,&c,1);
(void)BIO_flush(cb->arg);
#ifdef LINT
p=n;
#endif
return 1;
}
