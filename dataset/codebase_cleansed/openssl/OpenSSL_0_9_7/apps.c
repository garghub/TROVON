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
if (buf != NULL) OPENSSL_free(buf);
buf=(char *)OPENSSL_malloc(len+1);
if (buf == NULL) return(0);
len=fread(buf,1,len,fp);
if (len <= 1) return(0);
buf[len]='\0';
i=0;
for (p=buf; *p; p++)
if (*p == '\n') i++;
if (arg != NULL) OPENSSL_free(arg);
arg=(char **)OPENSSL_malloc(sizeof(char *)*(i*2));
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
else if ((*s == 'S') || (*s == 's'))
return(FORMAT_SMIME);
else if ((*s == '1')
|| (strcmp(s,"PKCS12") == 0) || (strcmp(s,"pkcs12") == 0)
|| (strcmp(s,"P12") == 0) || (strcmp(s,"p12") == 0))
return(FORMAT_PKCS12);
else if ((*s == 'E') || (*s == 'e'))
return(FORMAT_ENGINE);
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
q = p + strlen(p);
strncpy(out,p,size-1);
if (q-p >= size)
{
out[size-1]='\0';
}
else
{
out[q-p]='\0';
}
}
void program_name(char *in, char *out, int size)
{
char *p;
p=strrchr(in,'/');
if (p != NULL)
p++;
else
p=in;
BUF_strlcpy(out,p,size);
}
int WIN32_rename(char *from, char *to)
{
#ifndef OPENSSL_SYS_WINCE
if((remove(to) != 0) && (errno != ENOENT))
return -1;
#undef rename
return rename(from, to);
#else
{
BOOL result = FALSE;
WCHAR* wfrom;
WCHAR* wto;
int i;
wfrom = malloc((strlen(from)+1)*2);
wto = malloc((strlen(to)+1)*2);
if (wfrom != NULL && wto != NULL)
{
for (i=0; i<(int)strlen(from)+1; i++)
wfrom[i] = (short)from[i];
for (i=0; i<(int)strlen(to)+1; i++)
wto[i] = (short)to[i];
result = MoveFile(wfrom, wto);
}
if (wfrom != NULL)
free(wfrom);
if (wto != NULL)
free(wto);
return result;
}
#endif
}
int VMS_strcasecmp(const char *str1, const char *str2)
{
while (*str1 && *str2)
{
int res = toupper(*str1) - toupper(*str2);
if (res) return res < 0 ? -1 : 1;
}
if (*str1)
return 1;
if (*str2)
return -1;
return 0;
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
arg->data=(char **)OPENSSL_malloc(sizeof(char *)*arg->count);
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
arg->data=(char **)OPENSSL_realloc(arg->data,
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
char *p;
p=X509_NAME_oneline(X509_get_subject_name(x),NULL,0);
BIO_puts(out,"subject=");
BIO_puts(out,p);
OPENSSL_free(p);
p=X509_NAME_oneline(X509_get_issuer_name(x),NULL,0);
BIO_puts(out,"\nissuer=");
BIO_puts(out,p);
BIO_puts(out,"\n");
OPENSSL_free(p);
return 0;
}
static int ui_open(UI *ui)
{
return UI_method_get_opener(UI_OpenSSL())(ui);
}
static int ui_read(UI *ui, UI_STRING *uis)
{
if (UI_get_input_flags(uis) & UI_INPUT_FLAG_DEFAULT_PWD
&& UI_get0_user_data(ui))
{
switch(UI_get_string_type(uis))
{
case UIT_PROMPT:
case UIT_VERIFY:
{
const char *password =
((PW_CB_DATA *)UI_get0_user_data(ui))->password;
if (password[0] != '\0')
{
UI_set_result(ui, uis, password);
return 1;
}
}
default:
break;
}
}
return UI_method_get_reader(UI_OpenSSL())(ui, uis);
}
static int ui_write(UI *ui, UI_STRING *uis)
{
if (UI_get_input_flags(uis) & UI_INPUT_FLAG_DEFAULT_PWD
&& UI_get0_user_data(ui))
{
switch(UI_get_string_type(uis))
{
case UIT_PROMPT:
case UIT_VERIFY:
{
const char *password =
((PW_CB_DATA *)UI_get0_user_data(ui))->password;
if (password[0] != '\0')
return 1;
}
default:
break;
}
}
return UI_method_get_writer(UI_OpenSSL())(ui, uis);
}
static int ui_close(UI *ui)
{
return UI_method_get_closer(UI_OpenSSL())(ui);
}
int setup_ui_method(void)
{
ui_method = UI_create_method("OpenSSL application user interface");
UI_method_set_opener(ui_method, ui_open);
UI_method_set_reader(ui_method, ui_read);
UI_method_set_writer(ui_method, ui_write);
UI_method_set_closer(ui_method, ui_close);
return 0;
}
void destroy_ui_method(void)
{
if(ui_method)
{
UI_destroy_method(ui_method);
ui_method = NULL;
}
}
int password_callback(char *buf, int bufsiz, int verify,
PW_CB_DATA *cb_tmp)
{
UI *ui = NULL;
int res = 0;
const char *prompt_info = NULL;
const char *password = NULL;
PW_CB_DATA *cb_data = (PW_CB_DATA *)cb_tmp;
if (cb_data)
{
if (cb_data->password)
password = cb_data->password;
if (cb_data->prompt_info)
prompt_info = cb_data->prompt_info;
}
if (password)
{
res = strlen(password);
if (res > bufsiz)
res = bufsiz;
memcpy(buf, password, res);
return res;
}
ui = UI_new_method(ui_method);
if (ui)
{
int ok = 0;
char *buff = NULL;
int ui_flags = 0;
char *prompt = NULL;
prompt = UI_construct_prompt(ui, "pass phrase",
cb_data->prompt_info);
ui_flags |= UI_INPUT_FLAG_DEFAULT_PWD;
UI_ctrl(ui, UI_CTRL_PRINT_ERRORS, 1, 0, 0);
if (ok >= 0)
ok = UI_add_input_string(ui,prompt,ui_flags,buf,
PW_MIN_LENGTH,BUFSIZ-1);
if (ok >= 0 && verify)
{
buff = (char *)OPENSSL_malloc(bufsiz);
ok = UI_add_verify_string(ui,prompt,ui_flags,buff,
PW_MIN_LENGTH,BUFSIZ-1, buf);
}
if (ok >= 0)
do
{
ok = UI_process(ui);
}
while (ok < 0 && UI_ctrl(ui, UI_CTRL_IS_REDOABLE, 0, 0, 0));
if (buff)
{
OPENSSL_cleanse(buff,(unsigned int)bufsiz);
OPENSSL_free(buff);
}
if (ok >= 0)
res = strlen(buf);
if (ok == -1)
{
BIO_printf(bio_err, "User interface error\n");
ERR_print_errors(bio_err);
OPENSSL_cleanse(buf,(unsigned int)bufsiz);
res = 0;
}
if (ok == -2)
{
BIO_printf(bio_err,"aborted!\n");
OPENSSL_cleanse(buf,(unsigned int)bufsiz);
res = 0;
}
UI_free(ui);
OPENSSL_free(prompt);
}
return res;
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
int add_oid_section(BIO *err, CONF *conf)
{
char *p;
STACK_OF(CONF_VALUE) *sktmp;
CONF_VALUE *cnf;
int i;
if(!(p=NCONF_get_string(conf,NULL,"oid_section")))
{
ERR_clear_error();
return 1;
}
if(!(sktmp = NCONF_get_section(conf, p))) {
BIO_printf(err, "problem loading oid section %s\n", p);
return 0;
}
for(i = 0; i < sk_CONF_VALUE_num(sktmp); i++) {
cnf = sk_CONF_VALUE_value(sktmp, i);
if(OBJ_create(cnf->value, cnf->name, cnf->name) == NID_undef) {
BIO_printf(err, "problem creating object %s=%s\n",
cnf->name, cnf->value);
return 0;
}
}
return 1;
}
X509 *load_cert(BIO *err, const char *file, int format,
const char *pass, ENGINE *e, const char *cert_descrip)
{
ASN1_HEADER *ah=NULL;
BUF_MEM *buf=NULL;
X509 *x=NULL;
BIO *cert;
if ((cert=BIO_new(BIO_s_file())) == NULL)
{
ERR_print_errors(err);
goto end;
}
if (file == NULL)
{
setvbuf(stdin, NULL, _IONBF, 0);
BIO_set_fp(cert,stdin,BIO_NOCLOSE);
}
else
{
if (BIO_read_filename(cert,file) <= 0)
{
BIO_printf(err, "Error opening %s %s\n",
cert_descrip, file);
ERR_print_errors(err);
goto end;
}
}
if (format == FORMAT_ASN1)
x=d2i_X509_bio(cert,NULL);
else if (format == FORMAT_NETSCAPE)
{
unsigned char *p,*op;
int size=0,i;
buf=BUF_MEM_new();
for (;;)
{
if ((buf == NULL) || (!BUF_MEM_grow(buf,size+1024*10)))
goto end;
i=BIO_read(cert,&(buf->data[size]),1024*10);
size+=i;
if (i == 0) break;
if (i < 0)
{
perror("reading certificate");
goto end;
}
}
p=(unsigned char *)buf->data;
op=p;
if ((ah=d2i_ASN1_HEADER(NULL,&p,(long)size)) == NULL)
goto end;
if ((ah->header == NULL) || (ah->header->data == NULL) ||
(strncmp(NETSCAPE_CERT_HDR,(char *)ah->header->data,
ah->header->length) != 0))
{
BIO_printf(err,"Error reading header on certificate\n");
goto end;
}
p=op;
ah->meth=X509_asn1_meth();
if ((ah=d2i_ASN1_HEADER(&ah,&p,(long)size)) == NULL)
goto end;
x=(X509 *)ah->data;
ah->data=NULL;
}
else if (format == FORMAT_PEM)
x=PEM_read_bio_X509_AUX(cert,NULL,
(pem_password_cb *)password_callback, NULL);
else if (format == FORMAT_PKCS12)
{
PKCS12 *p12 = d2i_PKCS12_bio(cert, NULL);
PKCS12_parse(p12, NULL, NULL, &x, NULL);
PKCS12_free(p12);
p12 = NULL;
}
else {
BIO_printf(err,"bad input format specified for %s\n",
cert_descrip);
goto end;
}
end:
if (x == NULL)
{
BIO_printf(err,"unable to load certificate\n");
ERR_print_errors(err);
}
if (ah != NULL) ASN1_HEADER_free(ah);
if (cert != NULL) BIO_free(cert);
if (buf != NULL) BUF_MEM_free(buf);
return(x);
}
EVP_PKEY *load_key(BIO *err, const char *file, int format, int maybe_stdin,
const char *pass, ENGINE *e, const char *key_descrip)
{
BIO *key=NULL;
EVP_PKEY *pkey=NULL;
PW_CB_DATA cb_data;
cb_data.password = pass;
cb_data.prompt_info = file;
if (file == NULL && (!maybe_stdin || format == FORMAT_ENGINE))
{
BIO_printf(err,"no keyfile specified\n");
goto end;
}
if (format == FORMAT_ENGINE)
{
if (!e)
BIO_printf(bio_err,"no engine specified\n");
else
pkey = ENGINE_load_private_key(e, file,
ui_method, &cb_data);
goto end;
}
key=BIO_new(BIO_s_file());
if (key == NULL)
{
ERR_print_errors(err);
goto end;
}
if (file == NULL && maybe_stdin)
{
setvbuf(stdin, NULL, _IONBF, 0);
BIO_set_fp(key,stdin,BIO_NOCLOSE);
}
else
if (BIO_read_filename(key,file) <= 0)
{
BIO_printf(err, "Error opening %s %s\n",
key_descrip, file);
ERR_print_errors(err);
goto end;
}
if (format == FORMAT_ASN1)
{
pkey=d2i_PrivateKey_bio(key, NULL);
}
else if (format == FORMAT_PEM)
{
pkey=PEM_read_bio_PrivateKey(key,NULL,
(pem_password_cb *)password_callback, &cb_data);
}
#if !defined(OPENSSL_NO_RC4) && !defined(OPENSSL_NO_RSA)
else if (format == FORMAT_NETSCAPE || format == FORMAT_IISSGC)
pkey = load_netscape_key(err, key, file, key_descrip, format);
#endif
else if (format == FORMAT_PKCS12)
{
PKCS12 *p12 = d2i_PKCS12_bio(key, NULL);
PKCS12_parse(p12, pass, &pkey, NULL, NULL);
PKCS12_free(p12);
p12 = NULL;
}
else
{
BIO_printf(err,"bad input format specified for key file\n");
goto end;
}
end:
if (key != NULL) BIO_free(key);
if (pkey == NULL)
BIO_printf(err,"unable to load %s\n", key_descrip);
return(pkey);
}
EVP_PKEY *load_pubkey(BIO *err, const char *file, int format, int maybe_stdin,
const char *pass, ENGINE *e, const char *key_descrip)
{
BIO *key=NULL;
EVP_PKEY *pkey=NULL;
PW_CB_DATA cb_data;
cb_data.password = pass;
cb_data.prompt_info = file;
if (file == NULL && (!maybe_stdin || format == FORMAT_ENGINE))
{
BIO_printf(err,"no keyfile specified\n");
goto end;
}
if (format == FORMAT_ENGINE)
{
if (!e)
BIO_printf(bio_err,"no engine specified\n");
else
pkey = ENGINE_load_public_key(e, file,
ui_method, &cb_data);
goto end;
}
key=BIO_new(BIO_s_file());
if (key == NULL)
{
ERR_print_errors(err);
goto end;
}
if (file == NULL && maybe_stdin)
{
setvbuf(stdin, NULL, _IONBF, 0);
BIO_set_fp(key,stdin,BIO_NOCLOSE);
}
else
if (BIO_read_filename(key,file) <= 0)
{
BIO_printf(err, "Error opening %s %s\n",
key_descrip, file);
ERR_print_errors(err);
goto end;
}
if (format == FORMAT_ASN1)
{
pkey=d2i_PUBKEY_bio(key, NULL);
}
else if (format == FORMAT_PEM)
{
pkey=PEM_read_bio_PUBKEY(key,NULL,
(pem_password_cb *)password_callback, &cb_data);
}
#if !defined(OPENSSL_NO_RC4) && !defined(OPENSSL_NO_RSA)
else if (format == FORMAT_NETSCAPE || format == FORMAT_IISSGC)
pkey = load_netscape_key(err, key, file, key_descrip, format);
#endif
else
{
BIO_printf(err,"bad input format specified for key file\n");
goto end;
}
end:
if (key != NULL) BIO_free(key);
if (pkey == NULL)
BIO_printf(err,"unable to load %s\n", key_descrip);
return(pkey);
}
static EVP_PKEY *
load_netscape_key(BIO *err, BIO *key, const char *file,
const char *key_descrip, int format)
{
EVP_PKEY *pkey;
BUF_MEM *buf;
RSA *rsa;
const unsigned char *p;
int size, i;
buf=BUF_MEM_new();
pkey = EVP_PKEY_new();
size = 0;
if (buf == NULL || pkey == NULL)
goto error;
for (;;)
{
if (!BUF_MEM_grow_clean(buf,size+1024*10))
goto error;
i = BIO_read(key, &(buf->data[size]), 1024*10);
size += i;
if (i == 0)
break;
if (i < 0)
{
BIO_printf(err, "Error reading %s %s",
key_descrip, file);
goto error;
}
}
p=(unsigned char *)buf->data;
rsa = d2i_RSA_NET(NULL,&p,(long)size,NULL,
(format == FORMAT_IISSGC ? 1 : 0));
if (rsa == NULL)
goto error;
BUF_MEM_free(buf);
EVP_PKEY_set1_RSA(pkey, rsa);
return pkey;
error:
BUF_MEM_free(buf);
EVP_PKEY_free(pkey);
return NULL;
}
int set_name_ex(unsigned long *flags, const char *arg)
{
static const NAME_EX_TBL ex_tbl[] = {
{ "esc_2253", ASN1_STRFLGS_ESC_2253, 0},
{ "esc_ctrl", ASN1_STRFLGS_ESC_CTRL, 0},
{ "esc_msb", ASN1_STRFLGS_ESC_MSB, 0},
{ "use_quote", ASN1_STRFLGS_ESC_QUOTE, 0},
{ "utf8", ASN1_STRFLGS_UTF8_CONVERT, 0},
{ "ignore_type", ASN1_STRFLGS_IGNORE_TYPE, 0},
{ "show_type", ASN1_STRFLGS_SHOW_TYPE, 0},
{ "dump_all", ASN1_STRFLGS_DUMP_ALL, 0},
{ "dump_nostr", ASN1_STRFLGS_DUMP_UNKNOWN, 0},
{ "dump_der", ASN1_STRFLGS_DUMP_DER, 0},
{ "compat", XN_FLAG_COMPAT, 0xffffffffL},
{ "sep_comma_plus", XN_FLAG_SEP_COMMA_PLUS, XN_FLAG_SEP_MASK},
{ "sep_comma_plus_space", XN_FLAG_SEP_CPLUS_SPC, XN_FLAG_SEP_MASK},
{ "sep_semi_plus_space", XN_FLAG_SEP_SPLUS_SPC, XN_FLAG_SEP_MASK},
{ "sep_multiline", XN_FLAG_SEP_MULTILINE, XN_FLAG_SEP_MASK},
{ "dn_rev", XN_FLAG_DN_REV, 0},
{ "nofname", XN_FLAG_FN_NONE, XN_FLAG_FN_MASK},
{ "sname", XN_FLAG_FN_SN, XN_FLAG_FN_MASK},
{ "lname", XN_FLAG_FN_LN, XN_FLAG_FN_MASK},
{ "align", XN_FLAG_FN_ALIGN, 0},
{ "oid", XN_FLAG_FN_OID, XN_FLAG_FN_MASK},
{ "space_eq", XN_FLAG_SPC_EQ, 0},
{ "dump_unknown", XN_FLAG_DUMP_UNKNOWN_FIELDS, 0},
{ "RFC2253", XN_FLAG_RFC2253, 0xffffffffL},
{ "oneline", XN_FLAG_ONELINE, 0xffffffffL},
{ "multiline", XN_FLAG_MULTILINE, 0xffffffffL},
{ "ca_default", XN_FLAG_MULTILINE, 0xffffffffL},
{ NULL, 0, 0}
};
return set_multi_opts(flags, arg, ex_tbl);
}
int set_ext_copy(int *copy_type, const char *arg)
{
if (!strcasecmp(arg, "none"))
*copy_type = EXT_COPY_NONE;
else if (!strcasecmp(arg, "copy"))
*copy_type = EXT_COPY_ADD;
else if (!strcasecmp(arg, "copyall"))
*copy_type = EXT_COPY_ALL;
else
return 0;
return 1;
}
int copy_extensions(X509 *x, X509_REQ *req, int copy_type)
{
STACK_OF(X509_EXTENSION) *exts = NULL;
X509_EXTENSION *ext, *tmpext;
ASN1_OBJECT *obj;
int i, idx, ret = 0;
if (!x || !req || (copy_type == EXT_COPY_NONE))
return 1;
exts = X509_REQ_get_extensions(req);
for(i = 0; i < sk_X509_EXTENSION_num(exts); i++) {
ext = sk_X509_EXTENSION_value(exts, i);
obj = X509_EXTENSION_get_object(ext);
idx = X509_get_ext_by_OBJ(x, obj, -1);
if (idx != -1) {
if (copy_type == EXT_COPY_ADD)
continue;
do {
tmpext = X509_get_ext(x, idx);
X509_delete_ext(x, idx);
X509_EXTENSION_free(tmpext);
idx = X509_get_ext_by_OBJ(x, obj, -1);
} while (idx != -1);
}
if (!X509_add_ext(x, ext, -1))
goto end;
}
ret = 1;
end:
sk_X509_EXTENSION_pop_free(exts, X509_EXTENSION_free);
return ret;
}
static int set_multi_opts(unsigned long *flags, const char *arg, const NAME_EX_TBL *in_tbl)
{
STACK_OF(CONF_VALUE) *vals;
CONF_VALUE *val;
int i, ret = 1;
if(!arg) return 0;
vals = X509V3_parse_list(arg);
for (i = 0; i < sk_CONF_VALUE_num(vals); i++) {
val = sk_CONF_VALUE_value(vals, i);
if (!set_table_opts(flags, val->name, in_tbl))
ret = 0;
}
sk_CONF_VALUE_pop_free(vals, X509V3_conf_free);
return ret;
}
static int set_table_opts(unsigned long *flags, const char *arg, const NAME_EX_TBL *in_tbl)
{
char c;
const NAME_EX_TBL *ptbl;
c = arg[0];
if(c == '-') {
c = 0;
arg++;
} else if (c == '+') {
c = 1;
arg++;
} else c = 1;
for(ptbl = in_tbl; ptbl->name; ptbl++) {
if(!strcasecmp(arg, ptbl->name)) {
*flags &= ~ptbl->mask;
if(c) *flags |= ptbl->flag;
else *flags &= ~ptbl->flag;
return 1;
}
}
return 0;
}
void print_name(BIO *out, char *title, X509_NAME *nm, unsigned long lflags)
{
char *buf;
char mline = 0;
int indent = 0;
if(title) BIO_puts(out, title);
if((lflags & XN_FLAG_SEP_MASK) == XN_FLAG_SEP_MULTILINE) {
mline = 1;
indent = 4;
}
if(lflags == XN_FLAG_COMPAT) {
buf = X509_NAME_oneline(nm, 0, 0);
BIO_puts(out, buf);
BIO_puts(out, "\n");
OPENSSL_free(buf);
} else {
if(mline) BIO_puts(out, "\n");
X509_NAME_print_ex(out, nm, indent, lflags);
BIO_puts(out, "\n");
}
}
X509_STORE *setup_verify(BIO *bp, char *CAfile, char *CApath)
{
X509_STORE *store;
X509_LOOKUP *lookup;
if(!(store = X509_STORE_new())) goto end;
lookup=X509_STORE_add_lookup(store,X509_LOOKUP_file());
if (lookup == NULL) goto end;
if (CAfile) {
if(!X509_LOOKUP_load_file(lookup,CAfile,X509_FILETYPE_PEM)) {
BIO_printf(bp, "Error loading file %s\n", CAfile);
goto end;
}
} else X509_LOOKUP_load_file(lookup,NULL,X509_FILETYPE_DEFAULT);
lookup=X509_STORE_add_lookup(store,X509_LOOKUP_hash_dir());
if (lookup == NULL) goto end;
if (CApath) {
if(!X509_LOOKUP_add_dir(lookup,CApath,X509_FILETYPE_PEM)) {
BIO_printf(bp, "Error loading directory %s\n", CApath);
goto end;
}
} else X509_LOOKUP_add_dir(lookup,NULL,X509_FILETYPE_DEFAULT);
ERR_clear_error();
return store;
end:
X509_STORE_free(store);
return NULL;
}
static ENGINE *try_load_engine(BIO *err, const char *engine, int debug)
{
ENGINE *e = ENGINE_by_id("dynamic");
if (e)
{
if (!ENGINE_ctrl_cmd_string(e, "SO_PATH", engine, 0)
|| !ENGINE_ctrl_cmd_string(e, "LOAD", NULL, 0))
{
ENGINE_free(e);
e = NULL;
}
}
return e;
}
ENGINE *setup_engine(BIO *err, const char *engine, int debug)
{
ENGINE *e = NULL;
if (engine)
{
if(strcmp(engine, "auto") == 0)
{
BIO_printf(err,"enabling auto ENGINE support\n");
ENGINE_register_all_complete();
return NULL;
}
if((e = ENGINE_by_id(engine)) == NULL
&& (e = try_load_engine(err, engine, debug)) == NULL)
{
BIO_printf(err,"invalid engine \"%s\"\n", engine);
ERR_print_errors(err);
return NULL;
}
if (debug)
{
ENGINE_ctrl(e, ENGINE_CTRL_SET_LOGSTREAM,
0, err, 0);
}
ENGINE_ctrl_cmd(e, "SET_USER_INTERFACE", 0, ui_method, 0, 1);
if(!ENGINE_set_default(e, ENGINE_METHOD_ALL))
{
BIO_printf(err,"can't use that engine\n");
ERR_print_errors(err);
ENGINE_free(e);
return NULL;
}
BIO_printf(err,"engine \"%s\" set.\n", ENGINE_get_id(e));
ENGINE_free(e);
}
return e;
}
int load_config(BIO *err, CONF *cnf)
{
if (!cnf)
cnf = config;
if (!cnf)
return 1;
OPENSSL_load_builtin_modules();
if (CONF_modules_load(cnf, NULL, 0) <= 0)
{
BIO_printf(err, "Error configuring OpenSSL\n");
ERR_print_errors(err);
return 0;
}
return 1;
}
char *make_config_name()
{
const char *t=X509_get_default_cert_area();
char *p;
p=OPENSSL_malloc(strlen(t)+strlen(OPENSSL_CONF)+2);
strcpy(p,t);
#ifndef OPENSSL_SYS_VMS
strcat(p,"/");
#endif
strcat(p,OPENSSL_CONF);
return p;
}
