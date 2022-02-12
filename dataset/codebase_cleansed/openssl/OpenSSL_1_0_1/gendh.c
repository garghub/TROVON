int MAIN(int argc, char **argv)
{
BN_GENCB cb;
DH *dh=NULL;
int ret=1,num=DEFBITS;
int g=2;
char *outfile=NULL;
char *inrand=NULL;
#ifndef OPENSSL_NO_ENGINE
char *engine=NULL;
#endif
BIO *out=NULL;
apps_startup();
BN_GENCB_set(&cb, dh_cb, bio_err);
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
if (!load_config(bio_err, NULL))
goto end;
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
#ifndef OPENSSL_NO_ENGINE
else if (strcmp(*argv,"-engine") == 0)
{
if (--argc < 1) goto bad;
engine= *(++argv);
}
#endif
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
BIO_printf(bio_err," -2 - use 2 as the generator value\n");
BIO_printf(bio_err," -5 - use 5 as the generator value\n");
#ifndef OPENSSL_NO_ENGINE
BIO_printf(bio_err," -engine e - use engine e, possibly a hardware device.\n");
#endif
BIO_printf(bio_err," -rand file%cfile%c...\n", LIST_SEPARATOR_CHAR, LIST_SEPARATOR_CHAR);
BIO_printf(bio_err," - load the file (or the files in the directory) into\n");
BIO_printf(bio_err," the random number generator\n");
goto end;
}
#ifndef OPENSSL_NO_ENGINE
setup_engine(bio_err, engine, 0);
#endif
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
if (!app_RAND_load_file(NULL, bio_err, 1) && inrand == NULL)
{
BIO_printf(bio_err,"warning, not much extra random data, consider using the -rand option\n");
}
if (inrand != NULL)
BIO_printf(bio_err,"%ld semi-random bytes loaded\n",
app_RAND_load_files(inrand));
BIO_printf(bio_err,"Generating DH parameters, %d bit long safe prime, generator %d\n",num,g);
BIO_printf(bio_err,"This is going to take a long time\n");
if(((dh = DH_new()) == NULL) || !DH_generate_parameters_ex(dh, num, g, &cb))
goto end;
app_RAND_write_file(NULL, bio_err);
if (!PEM_write_bio_DHparams(out,dh))
goto end;
ret=0;
end:
if (ret != 0)
ERR_print_errors(bio_err);
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
