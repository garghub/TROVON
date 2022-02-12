int MAIN(int argc, char **argv)
{
char buffer[200];
DH *dh=NULL;
int ret=1,num=DEFBITS;
int g=2;
char *outfile=NULL;
char *inrand=NULL,*randfile;
BIO *out=NULL;
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
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
else if (strcmp(*argv,"-2") == 0)
g=2;
else if (strcmp(*argv,"-5") == 0)
g=5;
else if (strcmp(*argv,"-rand") == 0)
{
if (--argc < 1) goto bad;
inrand= *(++argv);
}
else
break;
argv++;
argc--;
}
if ((argc >= 1) && ((sscanf(*argv,"%d",&num) == 0) || (num < 0)))
{
bad:
BIO_printf(bio_err,"usage: gendh [args] [numbits]\n");
BIO_printf(bio_err," -out file - output the key to 'file\n");
BIO_printf(bio_err," -2 use 2 as the generator value\n");
BIO_printf(bio_err," -5 use 5 as the generator value\n");
BIO_printf(bio_err," -rand file:file:...\n");
BIO_printf(bio_err," - load the file (or the files in the directory) into\n");
BIO_printf(bio_err," the random number generator\n");
goto end;
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
randfile=RAND_file_name(buffer,200);
if ((randfile == NULL)|| !RAND_load_file(randfile,1024L*1024L))
BIO_printf(bio_err,"unable to load 'random state'\n");
if (inrand == NULL)
BIO_printf(bio_err,"warning, not much extra random data, consider using the -rand option\n");
else
{
BIO_printf(bio_err,"%ld semi-random bytes loaded\n",
dh_load_rand(inrand));
}
BIO_printf(bio_err,"Generating DH parameters, %d bit long strong prime, generator of %d\n",num,g);
BIO_printf(bio_err,"This is going to take a long time\n");
dh=DH_generate_parameters(num,g,dh_cb,bio_err);
if (dh == NULL) goto end;
if (randfile == NULL)
BIO_printf(bio_err,"unable to write 'random state'\n");
else
RAND_write_file(randfile);
if (!PEM_write_bio_DHparams(out,dh))
goto end;
ret=0;
end:
if (ret != 0)
ERR_print_errors(bio_err);
if (out != NULL) BIO_free(out);
if (dh != NULL) DH_free(dh);
EXIT(ret);
}
static void MS_CALLBACK dh_cb(int p, int n, void *arg)
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
static long dh_load_rand(char *name)
{
char *p,*n;
int last;
long tot=0;
for (;;)
{
last=0;
for (p=name; ((*p != '\0') && (*p != LIST_SEPARATOR_CHAR)); p++);
if (*p == '\0') last=1;
*p='\0';
n=name;
name=p+1;
if (*n == '\0') break;
tot+=RAND_load_file(n,1);
if (last) break;
}
return(tot);
}
