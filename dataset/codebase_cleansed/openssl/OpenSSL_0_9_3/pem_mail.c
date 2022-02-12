int main(int argc, char **argv)
{
FILE *in;
RSA *rsa=NULL;
EVP_MD_CTX ctx;
unsigned int mic=0,i,n;
unsigned char buf[1024*15];
char *prog,*infile=NULL,*outfile=NULL,*key=NULL;
int badops=0;
apps_startup();
prog=argv[0];
argc--;
argv++;
while (argc >= 1)
{
if (strcmp(*argv,"-key") == 0)
{
if (--argc < 1) goto bad;
key= *(++argv);
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
else if (strcmp(*argv,"-mic") == 0)
mic=1;
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
EXIT(1);
}
if (key == NULL)
{ BIO_printf(bio_err,"you need to specify a key\n"); EXIT(1); }
in=fopen(key,"r");
if (in == NULL) { perror(key); EXIT(1); }
rsa=PEM_read_RSAPrivateKey(in,NULL,NULL);
if (rsa == NULL)
{
BIO_printf(bio_err,"unable to load Private Key\n");
ERR_print_errors(bio_err);
EXIT(1);
}
fclose(in);
PEM_SignInit(&ctx,EVP_md5());
for (;;)
{
i=fread(buf,1,1024*10,stdin);
if (i <= 0) break;
PEM_SignUpdate(&ctx,buf,i);
}
if (!PEM_SignFinal(&ctx,buf,&n,rsa)) goto err;
BIO_printf(bio_err,"%s\n",buf);
EXIT(0);
err:
ERR_print_errors(bio_err);
EXIT(1);
}
