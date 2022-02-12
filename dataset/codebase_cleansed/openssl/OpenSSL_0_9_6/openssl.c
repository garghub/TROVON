int main(int Argc, char *Argv[])
{
ARGS arg;
#define PROG_NAME_SIZE 16
char pname[PROG_NAME_SIZE];
FUNCTION f,*fp;
MS_STATIC char *prompt,buf[1024],config_name[256];
int n,i,ret=0;
int argc;
char **argv,*p;
LHASH *prog=NULL;
long errline;
arg.data=NULL;
arg.count=0;
if (getenv("OPENSSL_DEBUG_MEMORY") != NULL)
CRYPTO_malloc_debug_init();
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ON);
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
ERR_load_crypto_strings();
p=getenv("OPENSSL_CONF");
if (p == NULL)
p=getenv("SSLEAY_CONF");
if (p == NULL)
{
strcpy(config_name,X509_get_default_cert_area());
#ifndef VMS
strcat(config_name,"/");
#endif
strcat(config_name,OPENSSL_CONF);
p=config_name;
}
default_config_file=p;
config=CONF_load(config,p,&errline);
if (config == NULL) ERR_clear_error();
prog=prog_init();
program_name(Argv[0],pname,PROG_NAME_SIZE);
f.name=pname;
fp=(FUNCTION *)lh_retrieve(prog,&f);
if (fp != NULL)
{
Argv[0]=pname;
ret=fp->func(Argc,Argv);
goto end;
}
if (Argc != 1)
{
Argc--;
Argv++;
ret=do_cmd(prog,Argc,Argv);
if (ret < 0) ret=0;
goto end;
}
for (;;)
{
ret=0;
p=buf;
n=1024;
i=0;
for (;;)
{
p[0]='\0';
if (i++)
prompt=">";
else prompt="OpenSSL> ";
fputs(prompt,stdout);
fflush(stdout);
fgets(p,n,stdin);
if (p[0] == '\0') goto end;
i=strlen(p);
if (i <= 1) break;
if (p[i-2] != '\\') break;
i-=2;
p+=i;
n-=i;
}
if (!chopup_args(&arg,buf,&argc,&argv)) break;
ret=do_cmd(prog,argc,argv);
if (ret < 0)
{
ret=0;
goto end;
}
if (ret != 0)
BIO_printf(bio_err,"error in %s\n",argv[0]);
(void)BIO_flush(bio_err);
}
BIO_printf(bio_err,"bad exit\n");
ret=1;
end:
if (config != NULL)
{
CONF_free(config);
config=NULL;
}
if (prog != NULL) lh_free(prog);
if (arg.data != NULL) OPENSSL_free(arg.data);
ERR_remove_state(0);
EVP_cleanup();
ERR_free_strings();
CRYPTO_mem_leaks(bio_err);
if (bio_err != NULL)
{
BIO_free(bio_err);
bio_err=NULL;
}
EXIT(ret);
}
static int do_cmd(LHASH *prog, int argc, char *argv[])
{
FUNCTION f,*fp;
int i,ret=1,tp,nl;
if ((argc <= 0) || (argv[0] == NULL))
{ ret=0; goto end; }
f.name=argv[0];
fp=(FUNCTION *)lh_retrieve(prog,&f);
if (fp != NULL)
{
ret=fp->func(argc,argv);
}
else if ((strncmp(argv[0],"no-",3)) == 0)
{
BIO *bio_stdout = BIO_new_fp(stdout,BIO_NOCLOSE);
#ifdef VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
bio_stdout = BIO_push(tmpbio, bio_stdout);
}
#endif
f.name=argv[0]+3;
ret = (lh_retrieve(prog,&f) != NULL);
if (!ret)
BIO_printf(bio_stdout, "%s\n", argv[0]);
else
BIO_printf(bio_stdout, "%s\n", argv[0]+3);
BIO_free_all(bio_stdout);
goto end;
}
else if ((strcmp(argv[0],"quit") == 0) ||
(strcmp(argv[0],"q") == 0) ||
(strcmp(argv[0],"exit") == 0) ||
(strcmp(argv[0],"bye") == 0))
{
ret= -1;
goto end;
}
else if ((strcmp(argv[0],LIST_STANDARD_COMMANDS) == 0) ||
(strcmp(argv[0],LIST_MESSAGE_DIGEST_COMMANDS) == 0) ||
(strcmp(argv[0],LIST_CIPHER_COMMANDS) == 0))
{
int list_type;
BIO *bio_stdout;
if (strcmp(argv[0],LIST_STANDARD_COMMANDS) == 0)
list_type = FUNC_TYPE_GENERAL;
else if (strcmp(argv[0],LIST_MESSAGE_DIGEST_COMMANDS) == 0)
list_type = FUNC_TYPE_MD;
else
list_type = FUNC_TYPE_CIPHER;
bio_stdout = BIO_new_fp(stdout,BIO_NOCLOSE);
#ifdef VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
bio_stdout = BIO_push(tmpbio, bio_stdout);
}
#endif
for (fp=functions; fp->name != NULL; fp++)
if (fp->type == list_type)
BIO_printf(bio_stdout, "%s\n", fp->name);
BIO_free_all(bio_stdout);
ret=0;
goto end;
}
else
{
BIO_printf(bio_err,"openssl:Error: '%s' is an invalid command.\n",
argv[0]);
BIO_printf(bio_err, "\nStandard commands");
i=0;
tp=0;
for (fp=functions; fp->name != NULL; fp++)
{
nl=0;
if (((i++) % 5) == 0)
{
BIO_printf(bio_err,"\n");
nl=1;
}
if (fp->type != tp)
{
tp=fp->type;
if (!nl) BIO_printf(bio_err,"\n");
if (tp == FUNC_TYPE_MD)
{
i=1;
BIO_printf(bio_err,
"\nMessage Digest commands (see the `dgst' command for more details)\n");
}
else if (tp == FUNC_TYPE_CIPHER)
{
i=1;
BIO_printf(bio_err,"\nCipher commands (see the `enc' command for more details)\n");
}
}
BIO_printf(bio_err,"%-15s",fp->name);
}
BIO_printf(bio_err,"\n\n");
ret=0;
}
end:
return(ret);
}
static int SortFnByName(const void *_f1,const void *_f2)
{
const FUNCTION *f1=_f1;
const FUNCTION *f2=_f2;
if(f1->type != f2->type)
return f1->type-f2->type;
return strcmp(f1->name,f2->name);
}
static LHASH *prog_init(void)
{
LHASH *ret;
FUNCTION *f;
int i;
for(i=0,f=functions ; f->name != NULL ; ++f,++i)
;
qsort(functions,i,sizeof *functions,SortFnByName);
if ((ret=lh_new(hash,cmp)) == NULL) return(NULL);
for (f=functions; f->name != NULL; f++)
lh_insert(ret,f);
return(ret);
}
static int MS_CALLBACK cmp(FUNCTION *a, FUNCTION *b)
{
return(strncmp(a->name,b->name,8));
}
static unsigned long MS_CALLBACK hash(FUNCTION *a)
{
return(lh_strhash(a->name));
}
