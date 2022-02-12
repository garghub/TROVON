int MAIN(int argc, char **argv)
{
unsigned char *buf=NULL;
int i,err=0;
const EVP_MD *md=NULL,*m;
BIO *in=NULL,*inp;
BIO *bmd=NULL;
const char *name;
#define PROG_NAME_SIZE 16
char pname[PROG_NAME_SIZE];
int separator=0;
int debug=0;
apps_startup();
if ((buf=(unsigned char *)Malloc(BUFSIZE)) == NULL)
{
BIO_printf(bio_err,"out of memory\n");
goto end;
}
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
program_name(argv[0],pname,PROG_NAME_SIZE);
md=EVP_get_digestbyname(pname);
argc--;
argv++;
while (argc > 0)
{
if ((*argv)[0] != '-') break;
if (strcmp(*argv,"-c") == 0)
separator=1;
else if (strcmp(*argv,"-d") == 0)
debug=1;
else if ((m=EVP_get_digestbyname(&((*argv)[1]))) != NULL)
md=m;
else
break;
argc--;
argv++;
}
if (md == NULL)
md=EVP_md5();
if ((argc > 0) && (argv[0][0] == '-'))
{
BIO_printf(bio_err,"unknown option '%s'\n",*argv);
BIO_printf(bio_err,"options are\n");
BIO_printf(bio_err,"-c to output the digest with separating colons\n");
BIO_printf(bio_err,"-d to output debug info\n");
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm (default)\n",
LN_md5,LN_md5);
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm\n",
LN_md2,LN_md2);
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm\n",
LN_sha1,LN_sha1);
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm\n",
LN_sha,LN_sha);
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm\n",
LN_mdc2,LN_mdc2);
BIO_printf(bio_err,"-%3s to use the %s message digest algorithm\n",
LN_ripemd160,LN_ripemd160);
err=1;
goto end;
}
in=BIO_new(BIO_s_file());
bmd=BIO_new(BIO_f_md());
if (debug)
{
BIO_set_callback(in,BIO_debug_callback);
BIO_set_callback_arg(in,bio_err);
}
if ((in == NULL) || (bmd == NULL))
{
ERR_print_errors(bio_err);
goto end;
}
BIO_set_md(bmd,md);
inp=BIO_push(bmd,in);
if (argc == 0)
{
BIO_set_fp(in,stdin,BIO_NOCLOSE);
do_fp(buf,inp,separator);
}
else
{
name=OBJ_nid2sn(md->type);
for (i=0; i<argc; i++)
{
if (BIO_read_filename(in,argv[i]) <= 0)
{
perror(argv[i]);
err++;
continue;
}
printf("%s(%s)= ",name,argv[i]);
do_fp(buf,inp,separator);
BIO_reset(bmd);
}
}
end:
if (buf != NULL)
{
memset(buf,0,BUFSIZE);
Free(buf);
}
if (in != NULL) BIO_free(in);
if (bmd != NULL) BIO_free(bmd);
EXIT(err);
}
void do_fp(unsigned char *buf, BIO *bp, int sep)
{
int len;
int i;
for (;;)
{
i=BIO_read(bp,(char *)buf,BUFSIZE);
if (i <= 0) break;
}
len=BIO_gets(bp,(char *)buf,BUFSIZE);
for (i=0; i<len; i++)
{
if (sep && (i != 0))
putc(':',stdout);
printf("%02x",buf[i]);
}
printf("\n");
}
