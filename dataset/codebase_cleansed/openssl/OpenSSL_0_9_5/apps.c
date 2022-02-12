int args_from_file(char *file, int *argc, char **argv[])
{
FILE *fp;
int num,i;
unsigned int len;
static char *buf=NULL;
static char **arg=NULL;
char *p;
struct stat stbuf;
if (stat(file,&stbuf) < 0) return(0);
fp=fopen(file,"r");
if (fp == NULL)
return(0);
*argc=0;
*argv=NULL;
len=(unsigned int)stbuf.st_size;
if (buf != NULL) Free(buf);
buf=(char *)Malloc(len+1);
if (buf == NULL) return(0);
len=fread(buf,1,len,fp);
if (len <= 1) return(0);
buf[len]='\0';
i=0;
for (p=buf; *p; p++)
if (*p == '\n') i++;
if (arg != NULL) Free(arg);
arg=(char **)Malloc(sizeof(char *)*(i*2));
*argv=arg;
num=0;
p=buf;
for (;;)
{
if (!*p) break;
if (*p == '#')
{
while (*p && (*p != '\n')) p++;
continue;
}
*(arg++)=p;
num++;
while (*p && ((*p != ' ') && (*p != '\t') && (*p != '\n')))
p++;
if (!*p) break;
if (*p == '\n')
{
*(p++)='\0';
continue;
}
p++;
while (*p && ((*p == ' ') || (*p == '\t') || (*p == '\n')))
p++;
if (!*p) break;
if (*p == '\n')
{
p++;
continue;
}
*(arg++)=p++;
num++;
while (*p && (*p != '\n')) p++;
if (!*p) break;
*(p++)='\0';
}
*argc=num;
return(1);
}
int str2fmt(char *s)
{
if ((*s == 'D') || (*s == 'd'))
return(FORMAT_ASN1);
else if ((*s == 'T') || (*s == 't'))
return(FORMAT_TEXT);
else if ((*s == 'P') || (*s == 'p'))
return(FORMAT_PEM);
else if ((*s == 'N') || (*s == 'n'))
return(FORMAT_NETSCAPE);
else
return(FORMAT_UNDEF);
}
void program_name(char *in, char *out, int size)
{
int i,n;
char *p=NULL;
n=strlen(in);
for (i=n-1; i>0; i--)
{
if ((in[i] == '/') || (in[i] == '\\') || (in[i] == ':'))
{
p= &(in[i+1]);
break;
}
}
if (p == NULL)
p=in;
n=strlen(p);
if ((n > 4) && (p[n-4] == '.') &&
((p[n-3] == 'e') || (p[n-3] == 'E')) &&
((p[n-2] == 'x') || (p[n-2] == 'X')) &&
((p[n-1] == 'e') || (p[n-1] == 'E')))
n-=4;
if (n > size-1)
n=size-1;
for (i=0; i<n; i++)
{
if ((p[i] >= 'A') && (p[i] <= 'Z'))
out[i]=p[i]-'A'+'a';
else
out[i]=p[i];
}
out[n]='\0';
}
void program_name(char *in, char *out, int size)
{
char *p=in, *q;
char *chars=":]>";
while(*chars != '\0')
{
q=strrchr(p,*chars);
if (q > p)
p = q + 1;
chars++;
}
q=strrchr(p,'.');
if (q == NULL)
q = in+size;
strncpy(out,p,q-p);
out[q-p]='\0';
}
void program_name(char *in, char *out, int size)
{
char *p;
p=strrchr(in,'/');
if (p != NULL)
p++;
else
p=in;
strncpy(out,p,size-1);
out[size-1]='\0';
}
int WIN32_rename(char *from, char *to)
{
#ifdef WINNT
int ret;
ret=MoveFileEx(from,to,MOVEFILE_REPLACE_EXISTING|MOVEFILE_COPY_ALLOWED);
return(ret?0:-1);
#else
unlink(to);
return MoveFile(from, to);
#endif
}
int chopup_args(ARGS *arg, char *buf, int *argc, char **argv[])
{
int num,len,i;
char *p;
*argc=0;
*argv=NULL;
len=strlen(buf);
i=0;
if (arg->count == 0)
{
arg->count=20;
arg->data=(char **)Malloc(sizeof(char *)*arg->count);
}
for (i=0; i<arg->count; i++)
arg->data[i]=NULL;
num=0;
p=buf;
for (;;)
{
if (!*p) break;
while (*p && ((*p == ' ') || (*p == '\t') || (*p == '\n')))
p++;
if (!*p) break;
if (num >= arg->count)
{
arg->count+=20;
arg->data=(char **)Realloc(arg->data,
sizeof(char *)*arg->count);
if (argc == 0) return(0);
}
arg->data[num++]=p;
if ((*p == '\'') || (*p == '\"'))
{
i= *(p++);
arg->data[num-1]++;
while (*p && (*p != i))
p++;
*p='\0';
}
else
{
while (*p && ((*p != ' ') &&
(*p != '\t') && (*p != '\n')))
p++;
if (*p == '\0')
p--;
else
*p='\0';
}
p++;
}
*argc=num;
*argv=arg->data;
return(1);
}
int app_init(long mesgwin)
{
return(1);
}
int dump_cert_text (BIO *out, X509 *x)
{
char buf[256];
X509_NAME_oneline(X509_get_subject_name(x),buf,256);
BIO_puts(out,"subject=");
BIO_puts(out,buf);
X509_NAME_oneline(X509_get_issuer_name(x),buf,256);
BIO_puts(out,"\nissuer= ");
BIO_puts(out,buf);
BIO_puts(out,"\n");
return 0;
}
int app_passwd(BIO *err, char *arg1, char *arg2, char **pass1, char **pass2)
{
int same;
if(!arg2 || !arg1 || strcmp(arg1, arg2)) same = 0;
else same = 1;
if(arg1) {
*pass1 = app_get_pass(err, arg1, same);
if(!*pass1) return 0;
} else if(pass1) *pass1 = NULL;
if(arg2) {
*pass2 = app_get_pass(err, arg2, same ? 2 : 0);
if(!*pass2) return 0;
} else if(pass2) *pass2 = NULL;
return 1;
}
static char *app_get_pass(BIO *err, char *arg, int keepbio)
{
char *tmp, tpass[APP_PASS_LEN];
static BIO *pwdbio = NULL;
int i;
if(!strncmp(arg, "pass:", 5)) return BUF_strdup(arg + 5);
if(!strncmp(arg, "env:", 4)) {
tmp = getenv(arg + 4);
if(!tmp) {
BIO_printf(err, "Can't read environment variable %s\n", arg + 4);
return NULL;
}
return BUF_strdup(tmp);
}
if(!keepbio || !pwdbio) {
if(!strncmp(arg, "file:", 5)) {
pwdbio = BIO_new_file(arg + 5, "r");
if(!pwdbio) {
BIO_printf(err, "Can't open file %s\n", arg + 5);
return NULL;
}
} else if(!strncmp(arg, "fd:", 3)) {
BIO *btmp;
i = atoi(arg + 3);
if(i >= 0) pwdbio = BIO_new_fd(i, BIO_NOCLOSE);
if((i < 0) || !pwdbio) {
BIO_printf(err, "Can't access file descriptor %s\n", arg + 3);
return NULL;
}
btmp = BIO_new(BIO_f_buffer());
pwdbio = BIO_push(btmp, pwdbio);
} else if(!strcmp(arg, "stdin")) {
pwdbio = BIO_new_fp(stdin, BIO_NOCLOSE);
if(!pwdbio) {
BIO_printf(err, "Can't open BIO for stdin\n");
return NULL;
}
} else {
BIO_printf(err, "Invalid password argument \"%s\"\n", arg);
return NULL;
}
}
i = BIO_gets(pwdbio, tpass, APP_PASS_LEN);
if(keepbio != 1) {
BIO_free_all(pwdbio);
pwdbio = NULL;
}
if(i <= 0) {
BIO_printf(err, "Error reading password from BIO\n");
return NULL;
}
tmp = strchr(tpass, '\n');
if(tmp) *tmp = 0;
return BUF_strdup(tpass);
}
