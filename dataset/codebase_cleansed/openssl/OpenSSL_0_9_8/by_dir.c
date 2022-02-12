X509_LOOKUP_METHOD *X509_LOOKUP_hash_dir(void)
{
return(&x509_dir_lookup);
}
static int dir_ctrl(X509_LOOKUP *ctx, int cmd, const char *argp, long argl,
char **retp)
{
int ret=0;
BY_DIR *ld;
char *dir = NULL;
ld=(BY_DIR *)ctx->method_data;
switch (cmd)
{
case X509_L_ADD_DIR:
if (argl == X509_FILETYPE_DEFAULT)
{
dir=(char *)Getenv(X509_get_default_cert_dir_env());
if (dir)
ret=add_cert_dir(ld,dir,X509_FILETYPE_PEM);
else
ret=add_cert_dir(ld,X509_get_default_cert_dir(),
X509_FILETYPE_PEM);
if (!ret)
{
X509err(X509_F_DIR_CTRL,X509_R_LOADING_CERT_DIR);
}
}
else
ret=add_cert_dir(ld,argp,(int)argl);
break;
}
return(ret);
}
static int new_dir(X509_LOOKUP *lu)
{
BY_DIR *a;
if ((a=(BY_DIR *)OPENSSL_malloc(sizeof(BY_DIR))) == NULL)
return(0);
if ((a->buffer=BUF_MEM_new()) == NULL)
{
OPENSSL_free(a);
return(0);
}
a->num_dirs=0;
a->dirs=NULL;
a->dirs_type=NULL;
a->num_dirs_alloced=0;
lu->method_data=(char *)a;
return(1);
}
static void free_dir(X509_LOOKUP *lu)
{
BY_DIR *a;
int i;
a=(BY_DIR *)lu->method_data;
for (i=0; i<a->num_dirs; i++)
if (a->dirs[i] != NULL) OPENSSL_free(a->dirs[i]);
if (a->dirs != NULL) OPENSSL_free(a->dirs);
if (a->dirs_type != NULL) OPENSSL_free(a->dirs_type);
if (a->buffer != NULL) BUF_MEM_free(a->buffer);
OPENSSL_free(a);
}
static int add_cert_dir(BY_DIR *ctx, const char *dir, int type)
{
int j,len;
int *ip;
const char *s,*ss,*p;
char **pp;
if (dir == NULL || !*dir)
{
X509err(X509_F_ADD_CERT_DIR,X509_R_INVALID_DIRECTORY);
return 0;
}
s=dir;
p=s;
for (;;)
{
if ((*p == LIST_SEPARATOR_CHAR) || (*p == '\0'))
{
ss=s;
s=p+1;
len=(int)(p-ss);
if (len == 0) continue;
for (j=0; j<ctx->num_dirs; j++)
if (strncmp(ctx->dirs[j],ss,(unsigned int)len) == 0)
continue;
if (ctx->num_dirs_alloced < (ctx->num_dirs+1))
{
ctx->num_dirs_alloced+=10;
pp=(char **)OPENSSL_malloc(ctx->num_dirs_alloced*
sizeof(char *));
ip=(int *)OPENSSL_malloc(ctx->num_dirs_alloced*
sizeof(int));
if ((pp == NULL) || (ip == NULL))
{
X509err(X509_F_ADD_CERT_DIR,ERR_R_MALLOC_FAILURE);
return(0);
}
memcpy(pp,ctx->dirs,(ctx->num_dirs_alloced-10)*
sizeof(char *));
memcpy(ip,ctx->dirs_type,(ctx->num_dirs_alloced-10)*
sizeof(int));
if (ctx->dirs != NULL)
OPENSSL_free(ctx->dirs);
if (ctx->dirs_type != NULL)
OPENSSL_free(ctx->dirs_type);
ctx->dirs=pp;
ctx->dirs_type=ip;
}
ctx->dirs_type[ctx->num_dirs]=type;
ctx->dirs[ctx->num_dirs]=(char *)OPENSSL_malloc((unsigned int)len+1);
if (ctx->dirs[ctx->num_dirs] == NULL) return(0);
strncpy(ctx->dirs[ctx->num_dirs],ss,(unsigned int)len);
ctx->dirs[ctx->num_dirs][len]='\0';
ctx->num_dirs++;
}
if (*p == '\0') break;
p++;
}
return(1);
}
static int get_cert_by_subject(X509_LOOKUP *xl, int type, X509_NAME *name,
X509_OBJECT *ret)
{
BY_DIR *ctx;
union {
struct {
X509 st_x509;
X509_CINF st_x509_cinf;
} x509;
struct {
X509_CRL st_crl;
X509_CRL_INFO st_crl_info;
} crl;
} data;
int ok=0;
int i,j,k;
unsigned long h;
BUF_MEM *b=NULL;
struct stat st;
X509_OBJECT stmp,*tmp;
const char *postfix="";
if (name == NULL) return(0);
stmp.type=type;
if (type == X509_LU_X509)
{
data.x509.st_x509.cert_info= &data.x509.st_x509_cinf;
data.x509.st_x509_cinf.subject=name;
stmp.data.x509= &data.x509.st_x509;
postfix="";
}
else if (type == X509_LU_CRL)
{
data.crl.st_crl.crl= &data.crl.st_crl_info;
data.crl.st_crl_info.issuer=name;
stmp.data.crl= &data.crl.st_crl;
postfix="r";
}
else
{
X509err(X509_F_GET_CERT_BY_SUBJECT,X509_R_WRONG_LOOKUP_TYPE);
goto finish;
}
if ((b=BUF_MEM_new()) == NULL)
{
X509err(X509_F_GET_CERT_BY_SUBJECT,ERR_R_BUF_LIB);
goto finish;
}
ctx=(BY_DIR *)xl->method_data;
h=X509_NAME_hash(name);
for (i=0; i<ctx->num_dirs; i++)
{
j=strlen(ctx->dirs[i])+1+8+6+1+1;
if (!BUF_MEM_grow(b,j))
{
X509err(X509_F_GET_CERT_BY_SUBJECT,ERR_R_MALLOC_FAILURE);
goto finish;
}
k=0;
for (;;)
{
char c = '/';
#ifdef OPENSSL_SYS_VMS
c = ctx->dirs[i][strlen(ctx->dirs[i])-1];
if (c != ':' && c != '>' && c != ']')
{
c = ':';
}
else
{
c = '\0';
}
#endif
if (c == '\0')
{
BIO_snprintf(b->data,b->max,
"%s%08lx.%s%d",ctx->dirs[i],h,
postfix,k);
}
else
{
BIO_snprintf(b->data,b->max,
"%s%c%08lx.%s%d",ctx->dirs[i],c,h,
postfix,k);
}
k++;
if (stat(b->data,&st) < 0)
break;
if (type == X509_LU_X509)
{
if ((X509_load_cert_file(xl,b->data,
ctx->dirs_type[i])) == 0)
break;
}
else if (type == X509_LU_CRL)
{
if ((X509_load_crl_file(xl,b->data,
ctx->dirs_type[i])) == 0)
break;
}
}
CRYPTO_r_lock(CRYPTO_LOCK_X509_STORE);
j = sk_X509_OBJECT_find(xl->store_ctx->objs,&stmp);
if(j != -1) tmp=sk_X509_OBJECT_value(xl->store_ctx->objs,j);
else tmp = NULL;
CRYPTO_r_unlock(CRYPTO_LOCK_X509_STORE);
if (tmp != NULL)
{
ok=1;
ret->type=tmp->type;
memcpy(&ret->data,&tmp->data,sizeof(ret->data));
goto finish;
}
}
finish:
if (b != NULL) BUF_MEM_free(b);
return(ok);
}
