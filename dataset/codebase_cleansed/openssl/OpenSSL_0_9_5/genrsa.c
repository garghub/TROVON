int MAIN(int argc, char **argv)
{
int ret=1;
RSA *rsa=NULL;
int i,num=DEFBITS;
long l;
EVP_CIPHER *enc=NULL;
unsigned long f4=RSA_F4;
char *outfile=NULL;
char *passargout = NULL, *passout = NULL;
char *inrand=NULL;
BIO *out=NULL;
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
if ((out=BIO_new(BIO_s_file())) == NULL)
{
BIO_printf(bio_err,"unable to create BIO for output\n");
goto err;
}
argv++;
argc--;
for (;;)
{
if (argc <= 0) break;
if (strcmp(*argv,"-out") == 0)
{
if (--argc < 1) goto bad;
outfile= *(++argv);
}
else if (strcmp(*argv,"-3") == 0)
f4=3;
else if (strcmp(*argv,"-F4") == 0)
f4=RSA_F4;
else if (strcmp(*argv,"-rand") == 0)
{
if (--argc < 1) goto bad;
inrand= *(++argv);
}
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
else if (strcmp(*argv,"-passout") == 0)
{
if (--argc < 1) goto bad;
passargout= *(++argv);
}
else
break;
argv++;
argc--;
}
if ((argc >= 1) && ((sscanf(*argv,"%d",&num) == 0) || (num < 0)))
{
bad:
BIO_printf(bio_err,"usage: genrsa [args] [numbits]\n");
BIO_printf(bio_err," -des encrypt the generated key with DES in cbc mode\n");
BIO_printf(bio_err," -des3 encrypt the generated key with DES in ede cbc mode (168 bit key)\n");
#ifndef NO_IDEA
BIO_printf(bio_err," -idea encrypt the generated key with IDEA in cbc mode\n");
#endif
BIO_printf(bio_err," -out file output the key to 'file\n");
BIO_printf(bio_err," -passout arg output file pass phrase source\n");
BIO_printf(bio_err," -f4 use F4 (0x10001) for the E value\n");
BIO_printf(bio_err," -3 use 3 for the E value\n");
BIO_printf(bio_err," -rand file:file:...\n");
BIO_printf(bio_err," load the file (or the files in the directory) into\n");
BIO_printf(bio_err," the random number generator\n");
goto err;
}
ERR_load_crypto_strings();
if(!app_passwd(bio_err, NULL, passargout, NULL, &passout)) {
BIO_printf(bio_err, "Error getting password\n");
goto err;
}
if (outfile == NULL)
BIO_set_fp(out,stdout,BIO_NOCLOSE);
else
{
if (BIO_write_filename(out,outfile) <= 0)
{
perror(outfile);
goto err;
}
}
if (!app_RAND_load_file(NULL, bio_err, 1) && inrand == NULL)
{
BIO_printf(bio_err,"warning, not much extra random data, consider using the -rand option\n");
}
if (inrand != NULL)
BIO_printf(bio_err,"%ld semi-random bytes loaded\n",
app_RAND_load_files(inrand));
BIO_printf(bio_err,"Generating RSA private key, %d bit long modulus\n",
num);
rsa=RSA_generate_key(num,f4,genrsa_cb,bio_err);
app_RAND_write_file(NULL, bio_err);
if (rsa == NULL) goto err;
l=0L;
for (i=0; i<rsa->e->top; i++)
{
#ifndef SIXTY_FOUR_BIT
l<<=BN_BITS4;
l<<=BN_BITS4;
#endif
l+=rsa->e->d[i];
}
BIO_printf(bio_err,"e is %ld (0x%lX)\n",l,l);
if (!PEM_write_bio_RSAPrivateKey(out,rsa,enc,NULL,0,NULL, passout))
goto err;
ret=0;
err:
if (rsa != NULL) RSA_free(rsa);
if (out != NULL) BIO_free(out);
if(passout) Free(passout);
if (ret != 0)
ERR_print_errors(bio_err);
EXIT(ret);
}
static void MS_CALLBACK genrsa_cb(int p, int n, void *arg)
{
char c='*';
if (p == 0) c='.';
if (p == 1) c='+';
if (p == 2) c='*';
if (p == 3) c='\n';
BIO_write((BIO *)arg,&c,1);
(void)BIO_flush((BIO *)arg);
#ifdef LINT
p=n;
#endif
}
