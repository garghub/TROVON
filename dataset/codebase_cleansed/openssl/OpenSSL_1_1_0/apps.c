int chopup_args(ARGS *arg, char *buf)
{
int quoted;
char c = '\0', *p = NULL;
arg->argc = 0;
if (arg->size == 0) {
arg->size = 20;
arg->argv = app_malloc(sizeof(*arg->argv) * arg->size, "argv space");
}
for (p = buf;;) {
while (*p && isspace(_UC(*p)))
p++;
if (!*p)
break;
if (arg->argc >= arg->size) {
char **tmp;
arg->size += 20;
tmp = OPENSSL_realloc(arg->argv, sizeof(*arg->argv) * arg->size);
if (tmp == NULL)
return 0;
arg->argv = tmp;
}
quoted = *p == '\'' || *p == '"';
if (quoted)
c = *p++;
arg->argv[arg->argc++] = p;
if (quoted) {
while (*p && *p != c)
p++;
*p++ = '\0';
} else {
while (*p && !isspace(_UC(*p)))
p++;
if (*p)
*p++ = '\0';
}
}
arg->argv[arg->argc] = NULL;
return (1);
}
int app_init(long mesgwin)
{
return (1);
}
int ctx_set_verify_locations(SSL_CTX *ctx, const char *CAfile,
const char *CApath, int noCAfile, int noCApath)
{
if (CAfile == NULL && CApath == NULL) {
if (!noCAfile && SSL_CTX_set_default_verify_file(ctx) <= 0)
return 0;
if (!noCApath && SSL_CTX_set_default_verify_dir(ctx) <= 0)
return 0;
return 1;
}
return SSL_CTX_load_verify_locations(ctx, CAfile, CApath);
}
int ctx_set_ctlog_list_file(SSL_CTX *ctx, const char *path)
{
if (path == NULL) {
return SSL_CTX_set_default_ctlog_list_file(ctx);
}
return SSL_CTX_set_ctlog_list_file(ctx, path);
}
int dump_cert_text(BIO *out, X509 *x)
{
char *p;
p = X509_NAME_oneline(X509_get_subject_name(x), NULL, 0);
BIO_puts(out, "subject=");
BIO_puts(out, p);
OPENSSL_free(p);
p = X509_NAME_oneline(X509_get_issuer_name(x), NULL, 0);
BIO_puts(out, "\nissuer=");
BIO_puts(out, p);
BIO_puts(out, "\n");
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
&& UI_get0_user_data(ui)) {
switch (UI_get_string_type(uis)) {
case UIT_PROMPT:
case UIT_VERIFY:
{
const char *password =
((PW_CB_DATA *)UI_get0_user_data(ui))->password;
if (password && password[0] != '\0') {
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
&& UI_get0_user_data(ui)) {
switch (UI_get_string_type(uis)) {
case UIT_PROMPT:
case UIT_VERIFY:
{
const char *password =
((PW_CB_DATA *)UI_get0_user_data(ui))->password;
if (password && password[0] != '\0')
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
if (ui_method) {
UI_destroy_method(ui_method);
ui_method = NULL;
}
}
int password_callback(char *buf, int bufsiz, int verify, PW_CB_DATA *cb_tmp)
{
int res = 0;
#ifndef OPENSSL_NO_UI
UI *ui = NULL;
const char *prompt_info = NULL;
#endif
const char *password = NULL;
PW_CB_DATA *cb_data = (PW_CB_DATA *)cb_tmp;
if (cb_data) {
if (cb_data->password)
password = cb_data->password;
#ifndef OPENSSL_NO_UI
if (cb_data->prompt_info)
prompt_info = cb_data->prompt_info;
#endif
}
if (password) {
res = strlen(password);
if (res > bufsiz)
res = bufsiz;
memcpy(buf, password, res);
return res;
}
#ifndef OPENSSL_NO_UI
ui = UI_new_method(ui_method);
if (ui) {
int ok = 0;
char *buff = NULL;
int ui_flags = 0;
char *prompt;
prompt = UI_construct_prompt(ui, "pass phrase", prompt_info);
if (!prompt) {
BIO_printf(bio_err, "Out of memory\n");
UI_free(ui);
return 0;
}
ui_flags |= UI_INPUT_FLAG_DEFAULT_PWD;
UI_ctrl(ui, UI_CTRL_PRINT_ERRORS, 1, 0, 0);
if (ok >= 0)
ok = UI_add_input_string(ui, prompt, ui_flags, buf,
PW_MIN_LENGTH, bufsiz - 1);
if (ok >= 0 && verify) {
buff = app_malloc(bufsiz, "password buffer");
ok = UI_add_verify_string(ui, prompt, ui_flags, buff,
PW_MIN_LENGTH, bufsiz - 1, buf);
}
if (ok >= 0)
do {
ok = UI_process(ui);
}
while (ok < 0 && UI_ctrl(ui, UI_CTRL_IS_REDOABLE, 0, 0, 0));
OPENSSL_clear_free(buff, (unsigned int)bufsiz);
if (ok >= 0)
res = strlen(buf);
if (ok == -1) {
BIO_printf(bio_err, "User interface error\n");
ERR_print_errors(bio_err);
OPENSSL_cleanse(buf, (unsigned int)bufsiz);
res = 0;
}
if (ok == -2) {
BIO_printf(bio_err, "aborted!\n");
OPENSSL_cleanse(buf, (unsigned int)bufsiz);
res = 0;
}
UI_free(ui);
OPENSSL_free(prompt);
}
#endif
return res;
}
int app_passwd(const char *arg1, const char *arg2, char **pass1, char **pass2)
{
int same;
if (!arg2 || !arg1 || strcmp(arg1, arg2))
same = 0;
else
same = 1;
if (arg1) {
*pass1 = app_get_pass(arg1, same);
if (!*pass1)
return 0;
} else if (pass1)
*pass1 = NULL;
if (arg2) {
*pass2 = app_get_pass(arg2, same ? 2 : 0);
if (!*pass2)
return 0;
} else if (pass2)
*pass2 = NULL;
return 1;
}
static char *app_get_pass(const char *arg, int keepbio)
{
char *tmp, tpass[APP_PASS_LEN];
static BIO *pwdbio = NULL;
int i;
if (strncmp(arg, "pass:", 5) == 0)
return OPENSSL_strdup(arg + 5);
if (strncmp(arg, "env:", 4) == 0) {
tmp = getenv(arg + 4);
if (!tmp) {
BIO_printf(bio_err, "Can't read environment variable %s\n", arg + 4);
return NULL;
}
return OPENSSL_strdup(tmp);
}
if (!keepbio || !pwdbio) {
if (strncmp(arg, "file:", 5) == 0) {
pwdbio = BIO_new_file(arg + 5, "r");
if (!pwdbio) {
BIO_printf(bio_err, "Can't open file %s\n", arg + 5);
return NULL;
}
#if !defined(_WIN32)
} else if (strncmp(arg, "fd:", 3) == 0) {
BIO *btmp;
i = atoi(arg + 3);
if (i >= 0)
pwdbio = BIO_new_fd(i, BIO_NOCLOSE);
if ((i < 0) || !pwdbio) {
BIO_printf(bio_err, "Can't access file descriptor %s\n", arg + 3);
return NULL;
}
btmp = BIO_new(BIO_f_buffer());
pwdbio = BIO_push(btmp, pwdbio);
#endif
} else if (strcmp(arg, "stdin") == 0) {
pwdbio = dup_bio_in(FORMAT_TEXT);
if (!pwdbio) {
BIO_printf(bio_err, "Can't open BIO for stdin\n");
return NULL;
}
} else {
BIO_printf(bio_err, "Invalid password argument \"%s\"\n", arg);
return NULL;
}
}
i = BIO_gets(pwdbio, tpass, APP_PASS_LEN);
if (keepbio != 1) {
BIO_free_all(pwdbio);
pwdbio = NULL;
}
if (i <= 0) {
BIO_printf(bio_err, "Error reading password from BIO\n");
return NULL;
}
tmp = strchr(tpass, '\n');
if (tmp)
*tmp = 0;
return OPENSSL_strdup(tpass);
}
static CONF *app_load_config_(BIO *in, const char *filename)
{
long errorline = -1;
CONF *conf;
int i;
conf = NCONF_new(NULL);
i = NCONF_load_bio(conf, in, &errorline);
if (i > 0)
return conf;
if (errorline <= 0)
BIO_printf(bio_err, "%s: Can't load config file \"%s\"\n",
opt_getprog(), filename);
else
BIO_printf(bio_err, "%s: Error on line %ld of config file \"%s\"\n",
opt_getprog(), errorline, filename);
NCONF_free(conf);
return NULL;
}
CONF *app_load_config(const char *filename)
{
BIO *in;
CONF *conf;
in = bio_open_default(filename, 'r', FORMAT_TEXT);
if (in == NULL)
return NULL;
conf = app_load_config_(in, filename);
BIO_free(in);
return conf;
}
CONF *app_load_config_quiet(const char *filename)
{
BIO *in;
CONF *conf;
in = bio_open_default_quiet(filename, 'r', FORMAT_TEXT);
if (in == NULL)
return NULL;
conf = app_load_config_(in, filename);
BIO_free(in);
return conf;
}
int app_load_modules(const CONF *config)
{
CONF *to_free = NULL;
if (config == NULL)
config = to_free = app_load_config_quiet(default_config_file);
if (config == NULL)
return 1;
if (CONF_modules_load(config, NULL, 0) <= 0) {
BIO_printf(bio_err, "Error configuring OpenSSL modules\n");
ERR_print_errors(bio_err);
NCONF_free(to_free);
return 0;
}
NCONF_free(to_free);
return 1;
}
int add_oid_section(CONF *conf)
{
char *p;
STACK_OF(CONF_VALUE) *sktmp;
CONF_VALUE *cnf;
int i;
if ((p = NCONF_get_string(conf, NULL, "oid_section")) == NULL) {
ERR_clear_error();
return 1;
}
if ((sktmp = NCONF_get_section(conf, p)) == NULL) {
BIO_printf(bio_err, "problem loading oid section %s\n", p);
return 0;
}
for (i = 0; i < sk_CONF_VALUE_num(sktmp); i++) {
cnf = sk_CONF_VALUE_value(sktmp, i);
if (OBJ_create(cnf->value, cnf->name, cnf->name) == NID_undef) {
BIO_printf(bio_err, "problem creating object %s=%s\n",
cnf->name, cnf->value);
return 0;
}
}
return 1;
}
static int load_cert_crl_http(const char *url, X509 **pcert, X509_CRL **pcrl)
{
char *host = NULL, *port = NULL, *path = NULL;
BIO *bio = NULL;
OCSP_REQ_CTX *rctx = NULL;
int use_ssl, rv = 0;
if (!OCSP_parse_url(url, &host, &port, &path, &use_ssl))
goto err;
if (use_ssl) {
BIO_puts(bio_err, "https not supported\n");
goto err;
}
bio = BIO_new_connect(host);
if (!bio || !BIO_set_conn_port(bio, port))
goto err;
rctx = OCSP_REQ_CTX_new(bio, 1024);
if (rctx == NULL)
goto err;
if (!OCSP_REQ_CTX_http(rctx, "GET", path))
goto err;
if (!OCSP_REQ_CTX_add1_header(rctx, "Host", host))
goto err;
if (pcert) {
do {
rv = X509_http_nbio(rctx, pcert);
} while (rv == -1);
} else {
do {
rv = X509_CRL_http_nbio(rctx, pcrl);
} while (rv == -1);
}
err:
OPENSSL_free(host);
OPENSSL_free(path);
OPENSSL_free(port);
if (bio)
BIO_free_all(bio);
OCSP_REQ_CTX_free(rctx);
if (rv != 1) {
BIO_printf(bio_err, "Error loading %s from %s\n",
pcert ? "certificate" : "CRL", url);
ERR_print_errors(bio_err);
}
return rv;
}
X509 *load_cert(const char *file, int format, const char *cert_descrip)
{
X509 *x = NULL;
BIO *cert;
if (format == FORMAT_HTTP) {
#if !defined(OPENSSL_NO_OCSP) && !defined(OPENSSL_NO_SOCK)
load_cert_crl_http(file, &x, NULL);
#endif
return x;
}
if (file == NULL) {
unbuffer(stdin);
cert = dup_bio_in(format);
} else
cert = bio_open_default(file, 'r', format);
if (cert == NULL)
goto end;
if (format == FORMAT_ASN1)
x = d2i_X509_bio(cert, NULL);
else if (format == FORMAT_PEM)
x = PEM_read_bio_X509_AUX(cert, NULL,
(pem_password_cb *)password_callback, NULL);
else if (format == FORMAT_PKCS12) {
if (!load_pkcs12(cert, cert_descrip, NULL, NULL, NULL, &x, NULL))
goto end;
} else {
BIO_printf(bio_err, "bad input format specified for %s\n", cert_descrip);
goto end;
}
end:
if (x == NULL) {
BIO_printf(bio_err, "unable to load certificate\n");
ERR_print_errors(bio_err);
}
BIO_free(cert);
return (x);
}
X509_CRL *load_crl(const char *infile, int format)
{
X509_CRL *x = NULL;
BIO *in = NULL;
if (format == FORMAT_HTTP) {
#if !defined(OPENSSL_NO_OCSP) && !defined(OPENSSL_NO_SOCK)
load_cert_crl_http(infile, NULL, &x);
#endif
return x;
}
in = bio_open_default(infile, 'r', format);
if (in == NULL)
goto end;
if (format == FORMAT_ASN1)
x = d2i_X509_CRL_bio(in, NULL);
else if (format == FORMAT_PEM)
x = PEM_read_bio_X509_CRL(in, NULL, NULL, NULL);
else {
BIO_printf(bio_err, "bad input format specified for input crl\n");
goto end;
}
if (x == NULL) {
BIO_printf(bio_err, "unable to load CRL\n");
ERR_print_errors(bio_err);
goto end;
}
end:
BIO_free(in);
return (x);
}
EVP_PKEY *load_key(const char *file, int format, int maybe_stdin,
const char *pass, ENGINE *e, const char *key_descrip)
{
BIO *key = NULL;
EVP_PKEY *pkey = NULL;
PW_CB_DATA cb_data;
cb_data.password = pass;
cb_data.prompt_info = file;
if (file == NULL && (!maybe_stdin || format == FORMAT_ENGINE)) {
BIO_printf(bio_err, "no keyfile specified\n");
goto end;
}
if (format == FORMAT_ENGINE) {
if (e == NULL)
BIO_printf(bio_err, "no engine specified\n");
else {
#ifndef OPENSSL_NO_ENGINE
pkey = ENGINE_load_private_key(e, file, ui_method, &cb_data);
if (pkey == NULL) {
BIO_printf(bio_err, "cannot load %s from engine\n", key_descrip);
ERR_print_errors(bio_err);
}
#else
BIO_printf(bio_err, "engines not supported\n");
#endif
}
goto end;
}
if (file == NULL && maybe_stdin) {
unbuffer(stdin);
key = dup_bio_in(format);
} else
key = bio_open_default(file, 'r', format);
if (key == NULL)
goto end;
if (format == FORMAT_ASN1) {
pkey = d2i_PrivateKey_bio(key, NULL);
} else if (format == FORMAT_PEM) {
pkey = PEM_read_bio_PrivateKey(key, NULL,
(pem_password_cb *)password_callback,
&cb_data);
}
else if (format == FORMAT_PKCS12) {
if (!load_pkcs12(key, key_descrip,
(pem_password_cb *)password_callback, &cb_data,
&pkey, NULL, NULL))
goto end;
}
#if !defined(OPENSSL_NO_RSA) && !defined(OPENSSL_NO_DSA) && !defined (OPENSSL_NO_RC4)
else if (format == FORMAT_MSBLOB)
pkey = b2i_PrivateKey_bio(key);
else if (format == FORMAT_PVK)
pkey = b2i_PVK_bio(key, (pem_password_cb *)password_callback,
&cb_data);
#endif
else {
BIO_printf(bio_err, "bad input format specified for key file\n");
goto end;
}
end:
BIO_free(key);
if (pkey == NULL) {
BIO_printf(bio_err, "unable to load %s\n", key_descrip);
ERR_print_errors(bio_err);
}
return (pkey);
}
EVP_PKEY *load_pubkey(const char *file, int format, int maybe_stdin,
const char *pass, ENGINE *e, const char *key_descrip)
{
BIO *key = NULL;
EVP_PKEY *pkey = NULL;
PW_CB_DATA cb_data;
cb_data.password = pass;
cb_data.prompt_info = file;
if (file == NULL && (!maybe_stdin || format == FORMAT_ENGINE)) {
BIO_printf(bio_err, "no keyfile specified\n");
goto end;
}
if (format == FORMAT_ENGINE) {
if (e == NULL)
BIO_printf(bio_err, "no engine specified\n");
else {
#ifndef OPENSSL_NO_ENGINE
pkey = ENGINE_load_public_key(e, file, ui_method, &cb_data);
if (pkey == NULL) {
BIO_printf(bio_err, "cannot load %s from engine\n", key_descrip);
ERR_print_errors(bio_err);
}
#else
BIO_printf(bio_err, "engines not supported\n");
#endif
}
goto end;
}
if (file == NULL && maybe_stdin) {
unbuffer(stdin);
key = dup_bio_in(format);
} else
key = bio_open_default(file, 'r', format);
if (key == NULL)
goto end;
if (format == FORMAT_ASN1) {
pkey = d2i_PUBKEY_bio(key, NULL);
}
else if (format == FORMAT_ASN1RSA) {
#ifndef OPENSSL_NO_RSA
RSA *rsa;
rsa = d2i_RSAPublicKey_bio(key, NULL);
if (rsa) {
pkey = EVP_PKEY_new();
if (pkey != NULL)
EVP_PKEY_set1_RSA(pkey, rsa);
RSA_free(rsa);
} else
#else
BIO_printf(bio_err, "RSA keys not supported\n");
#endif
pkey = NULL;
} else if (format == FORMAT_PEMRSA) {
#ifndef OPENSSL_NO_RSA
RSA *rsa;
rsa = PEM_read_bio_RSAPublicKey(key, NULL,
(pem_password_cb *)password_callback,
&cb_data);
if (rsa != NULL) {
pkey = EVP_PKEY_new();
if (pkey != NULL)
EVP_PKEY_set1_RSA(pkey, rsa);
RSA_free(rsa);
} else
#else
BIO_printf(bio_err, "RSA keys not supported\n");
#endif
pkey = NULL;
}
else if (format == FORMAT_PEM) {
pkey = PEM_read_bio_PUBKEY(key, NULL,
(pem_password_cb *)password_callback,
&cb_data);
}
#if !defined(OPENSSL_NO_RSA) && !defined(OPENSSL_NO_DSA)
else if (format == FORMAT_MSBLOB)
pkey = b2i_PublicKey_bio(key);
#endif
end:
BIO_free(key);
if (pkey == NULL)
BIO_printf(bio_err, "unable to load %s\n", key_descrip);
return (pkey);
}
void* app_malloc(int sz, const char *what)
{
void *vp = OPENSSL_malloc(sz);
if (vp == NULL) {
BIO_printf(bio_err, "%s: Could not allocate %d bytes for %s\n",
opt_getprog(), sz, what);
ERR_print_errors(bio_err);
exit(1);
}
return vp;
}
int set_cert_ex(unsigned long *flags, const char *arg)
{
static const NAME_EX_TBL cert_tbl[] = {
{"compatible", X509_FLAG_COMPAT, 0xffffffffl},
{"ca_default", X509_FLAG_CA, 0xffffffffl},
{"no_header", X509_FLAG_NO_HEADER, 0},
{"no_version", X509_FLAG_NO_VERSION, 0},
{"no_serial", X509_FLAG_NO_SERIAL, 0},
{"no_signame", X509_FLAG_NO_SIGNAME, 0},
{"no_validity", X509_FLAG_NO_VALIDITY, 0},
{"no_subject", X509_FLAG_NO_SUBJECT, 0},
{"no_issuer", X509_FLAG_NO_ISSUER, 0},
{"no_pubkey", X509_FLAG_NO_PUBKEY, 0},
{"no_extensions", X509_FLAG_NO_EXTENSIONS, 0},
{"no_sigdump", X509_FLAG_NO_SIGDUMP, 0},
{"no_aux", X509_FLAG_NO_AUX, 0},
{"no_attributes", X509_FLAG_NO_ATTRIBUTES, 0},
{"ext_default", X509V3_EXT_DEFAULT, X509V3_EXT_UNKNOWN_MASK},
{"ext_error", X509V3_EXT_ERROR_UNKNOWN, X509V3_EXT_UNKNOWN_MASK},
{"ext_parse", X509V3_EXT_PARSE_UNKNOWN, X509V3_EXT_UNKNOWN_MASK},
{"ext_dump", X509V3_EXT_DUMP_UNKNOWN, X509V3_EXT_UNKNOWN_MASK},
{NULL, 0, 0}
};
return set_multi_opts(flags, arg, cert_tbl);
}
int set_name_ex(unsigned long *flags, const char *arg)
{
static const NAME_EX_TBL ex_tbl[] = {
{"esc_2253", ASN1_STRFLGS_ESC_2253, 0},
{"esc_2254", ASN1_STRFLGS_ESC_2254, 0},
{"esc_ctrl", ASN1_STRFLGS_ESC_CTRL, 0},
{"esc_msb", ASN1_STRFLGS_ESC_MSB, 0},
{"use_quote", ASN1_STRFLGS_ESC_QUOTE, 0},
{"utf8", ASN1_STRFLGS_UTF8_CONVERT, 0},
{"ignore_type", ASN1_STRFLGS_IGNORE_TYPE, 0},
{"show_type", ASN1_STRFLGS_SHOW_TYPE, 0},
{"dump_all", ASN1_STRFLGS_DUMP_ALL, 0},
{"dump_nostr", ASN1_STRFLGS_DUMP_UNKNOWN, 0},
{"dump_der", ASN1_STRFLGS_DUMP_DER, 0},
{"compat", XN_FLAG_COMPAT, 0xffffffffL},
{"sep_comma_plus", XN_FLAG_SEP_COMMA_PLUS, XN_FLAG_SEP_MASK},
{"sep_comma_plus_space", XN_FLAG_SEP_CPLUS_SPC, XN_FLAG_SEP_MASK},
{"sep_semi_plus_space", XN_FLAG_SEP_SPLUS_SPC, XN_FLAG_SEP_MASK},
{"sep_multiline", XN_FLAG_SEP_MULTILINE, XN_FLAG_SEP_MASK},
{"dn_rev", XN_FLAG_DN_REV, 0},
{"nofname", XN_FLAG_FN_NONE, XN_FLAG_FN_MASK},
{"sname", XN_FLAG_FN_SN, XN_FLAG_FN_MASK},
{"lname", XN_FLAG_FN_LN, XN_FLAG_FN_MASK},
{"align", XN_FLAG_FN_ALIGN, 0},
{"oid", XN_FLAG_FN_OID, XN_FLAG_FN_MASK},
{"space_eq", XN_FLAG_SPC_EQ, 0},
{"dump_unknown", XN_FLAG_DUMP_UNKNOWN_FIELDS, 0},
{"RFC2253", XN_FLAG_RFC2253, 0xffffffffL},
{"oneline", XN_FLAG_ONELINE, 0xffffffffL},
{"multiline", XN_FLAG_MULTILINE, 0xffffffffL},
{"ca_default", XN_FLAG_MULTILINE, 0xffffffffL},
{NULL, 0, 0}
};
if (set_multi_opts(flags, arg, ex_tbl) == 0)
return 0;
if ((*flags & XN_FLAG_SEP_MASK) == 0)
*flags |= XN_FLAG_SEP_CPLUS_SPC;
return 1;
}
int set_ext_copy(int *copy_type, const char *arg)
{
if (strcasecmp(arg, "none") == 0)
*copy_type = EXT_COPY_NONE;
else if (strcasecmp(arg, "copy") == 0)
*copy_type = EXT_COPY_ADD;
else if (strcasecmp(arg, "copyall") == 0)
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
for (i = 0; i < sk_X509_EXTENSION_num(exts); i++) {
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
static int set_multi_opts(unsigned long *flags, const char *arg,
const NAME_EX_TBL * in_tbl)
{
STACK_OF(CONF_VALUE) *vals;
CONF_VALUE *val;
int i, ret = 1;
if (!arg)
return 0;
vals = X509V3_parse_list(arg);
for (i = 0; i < sk_CONF_VALUE_num(vals); i++) {
val = sk_CONF_VALUE_value(vals, i);
if (!set_table_opts(flags, val->name, in_tbl))
ret = 0;
}
sk_CONF_VALUE_pop_free(vals, X509V3_conf_free);
return ret;
}
static int set_table_opts(unsigned long *flags, const char *arg,
const NAME_EX_TBL * in_tbl)
{
char c;
const NAME_EX_TBL *ptbl;
c = arg[0];
if (c == '-') {
c = 0;
arg++;
} else if (c == '+') {
c = 1;
arg++;
} else
c = 1;
for (ptbl = in_tbl; ptbl->name; ptbl++) {
if (strcasecmp(arg, ptbl->name) == 0) {
*flags &= ~ptbl->mask;
if (c)
*flags |= ptbl->flag;
else
*flags &= ~ptbl->flag;
return 1;
}
}
return 0;
}
void print_name(BIO *out, const char *title, X509_NAME *nm,
unsigned long lflags)
{
char *buf;
char mline = 0;
int indent = 0;
if (title)
BIO_puts(out, title);
if ((lflags & XN_FLAG_SEP_MASK) == XN_FLAG_SEP_MULTILINE) {
mline = 1;
indent = 4;
}
if (lflags == XN_FLAG_COMPAT) {
buf = X509_NAME_oneline(nm, 0, 0);
BIO_puts(out, buf);
BIO_puts(out, "\n");
OPENSSL_free(buf);
} else {
if (mline)
BIO_puts(out, "\n");
X509_NAME_print_ex(out, nm, indent, lflags);
BIO_puts(out, "\n");
}
}
void print_bignum_var(BIO *out, const BIGNUM *in, const char *var,
int len, unsigned char *buffer)
{
BIO_printf(out, " static unsigned char %s_%d[] = {", var, len);
if (BN_is_zero(in))
BIO_printf(out, "\n\t0x00");
else {
int i, l;
l = BN_bn2bin(in, buffer);
for (i = 0; i < l; i++) {
if ((i % 10) == 0)
BIO_printf(out, "\n\t");
if (i < l - 1)
BIO_printf(out, "0x%02X, ", buffer[i]);
else
BIO_printf(out, "0x%02X", buffer[i]);
}
}
BIO_printf(out, "\n };\n");
}
void print_array(BIO *out, const char* title, int len, const unsigned char* d)
{
int i;
BIO_printf(out, "unsigned char %s[%d] = {", title, len);
for (i = 0; i < len; i++) {
if ((i % 10) == 0)
BIO_printf(out, "\n ");
if (i < len - 1)
BIO_printf(out, "0x%02X, ", d[i]);
else
BIO_printf(out, "0x%02X", d[i]);
}
BIO_printf(out, "\n};\n");
}
X509_STORE *setup_verify(const char *CAfile, const char *CApath, int noCAfile, int noCApath)
{
X509_STORE *store = X509_STORE_new();
X509_LOOKUP *lookup;
if (store == NULL)
goto end;
if (CAfile != NULL || !noCAfile) {
lookup = X509_STORE_add_lookup(store, X509_LOOKUP_file());
if (lookup == NULL)
goto end;
if (CAfile) {
if (!X509_LOOKUP_load_file(lookup, CAfile, X509_FILETYPE_PEM)) {
BIO_printf(bio_err, "Error loading file %s\n", CAfile);
goto end;
}
} else
X509_LOOKUP_load_file(lookup, NULL, X509_FILETYPE_DEFAULT);
}
if (CApath != NULL || !noCApath) {
lookup = X509_STORE_add_lookup(store, X509_LOOKUP_hash_dir());
if (lookup == NULL)
goto end;
if (CApath) {
if (!X509_LOOKUP_add_dir(lookup, CApath, X509_FILETYPE_PEM)) {
BIO_printf(bio_err, "Error loading directory %s\n", CApath);
goto end;
}
} else
X509_LOOKUP_add_dir(lookup, NULL, X509_FILETYPE_DEFAULT);
}
ERR_clear_error();
return store;
end:
X509_STORE_free(store);
return NULL;
}
static ENGINE *try_load_engine(const char *engine)
{
ENGINE *e = ENGINE_by_id("dynamic");
if (e) {
if (!ENGINE_ctrl_cmd_string(e, "SO_PATH", engine, 0)
|| !ENGINE_ctrl_cmd_string(e, "LOAD", NULL, 0)) {
ENGINE_free(e);
e = NULL;
}
}
return e;
}
ENGINE *setup_engine(const char *engine, int debug)
{
ENGINE *e = NULL;
if (engine) {
if (strcmp(engine, "auto") == 0) {
BIO_printf(bio_err, "enabling auto ENGINE support\n");
ENGINE_register_all_complete();
return NULL;
}
if ((e = ENGINE_by_id(engine)) == NULL
&& (e = try_load_engine(engine)) == NULL) {
BIO_printf(bio_err, "invalid engine \"%s\"\n", engine);
ERR_print_errors(bio_err);
return NULL;
}
if (debug) {
ENGINE_ctrl(e, ENGINE_CTRL_SET_LOGSTREAM, 0, bio_err, 0);
}
ENGINE_ctrl_cmd(e, "SET_USER_INTERFACE", 0, ui_method, 0, 1);
if (!ENGINE_set_default(e, ENGINE_METHOD_ALL)) {
BIO_printf(bio_err, "can't use that engine\n");
ERR_print_errors(bio_err);
ENGINE_free(e);
return NULL;
}
BIO_printf(bio_err, "engine \"%s\" set.\n", ENGINE_get_id(e));
ENGINE_free(e);
}
return e;
}
static unsigned long index_serial_hash(const OPENSSL_CSTRING *a)
{
const char *n;
n = a[DB_serial];
while (*n == '0')
n++;
return OPENSSL_LH_strhash(n);
}
static int index_serial_cmp(const OPENSSL_CSTRING *a,
const OPENSSL_CSTRING *b)
{
const char *aa, *bb;
for (aa = a[DB_serial]; *aa == '0'; aa++) ;
for (bb = b[DB_serial]; *bb == '0'; bb++) ;
return (strcmp(aa, bb));
}
static int index_name_qual(char **a)
{
return (a[0][0] == 'V');
}
static unsigned long index_name_hash(const OPENSSL_CSTRING *a)
{
return OPENSSL_LH_strhash(a[DB_name]);
}
int index_name_cmp(const OPENSSL_CSTRING *a, const OPENSSL_CSTRING *b)
{
return (strcmp(a[DB_name], b[DB_name]));
}
int rotate_serial(const char *serialfile, const char *new_suffix,
const char *old_suffix)
{
char buf[2][BSIZE];
int i, j;
i = strlen(serialfile) + strlen(old_suffix);
j = strlen(serialfile) + strlen(new_suffix);
if (i > j)
j = i;
if (j + 1 >= BSIZE) {
BIO_printf(bio_err, "file name too long\n");
goto err;
}
#ifndef OPENSSL_SYS_VMS
j = BIO_snprintf(buf[0], sizeof buf[0], "%s.%s", serialfile, new_suffix);
j = BIO_snprintf(buf[1], sizeof buf[1], "%s.%s", serialfile, old_suffix);
#else
j = BIO_snprintf(buf[0], sizeof buf[0], "%s-%s", serialfile, new_suffix);
j = BIO_snprintf(buf[1], sizeof buf[1], "%s-%s", serialfile, old_suffix);
#endif
if (rename(serialfile, buf[1]) < 0 && errno != ENOENT
#ifdef ENOTDIR
&& errno != ENOTDIR
#endif
) {
BIO_printf(bio_err,
"unable to rename %s to %s\n", serialfile, buf[1]);
perror("reason");
goto err;
}
if (rename(buf[0], serialfile) < 0) {
BIO_printf(bio_err,
"unable to rename %s to %s\n", buf[0], serialfile);
perror("reason");
rename(buf[1], serialfile);
goto err;
}
return 1;
err:
return 0;
}
int rand_serial(BIGNUM *b, ASN1_INTEGER *ai)
{
BIGNUM *btmp;
int ret = 0;
if (b)
btmp = b;
else
btmp = BN_new();
if (btmp == NULL)
return 0;
if (!BN_pseudo_rand(btmp, SERIAL_RAND_BITS, 0, 0))
goto error;
if (ai && !BN_to_ASN1_INTEGER(btmp, ai))
goto error;
ret = 1;
error:
if (btmp != b)
BN_free(btmp);
return ret;
}
CA_DB *load_index(const char *dbfile, DB_ATTR *db_attr)
{
CA_DB *retdb = NULL;
TXT_DB *tmpdb = NULL;
BIO *in;
CONF *dbattr_conf = NULL;
char buf[BSIZE];
in = BIO_new_file(dbfile, "r");
if (in == NULL) {
ERR_print_errors(bio_err);
goto err;
}
if ((tmpdb = TXT_DB_read(in, DB_NUMBER)) == NULL)
goto err;
#ifndef OPENSSL_SYS_VMS
BIO_snprintf(buf, sizeof buf, "%s.attr", dbfile);
#else
BIO_snprintf(buf, sizeof buf, "%s-attr", dbfile);
#endif
dbattr_conf = app_load_config(buf);
retdb = app_malloc(sizeof(*retdb), "new DB");
retdb->db = tmpdb;
tmpdb = NULL;
if (db_attr)
retdb->attributes = *db_attr;
else {
retdb->attributes.unique_subject = 1;
}
if (dbattr_conf) {
char *p = NCONF_get_string(dbattr_conf, NULL, "unique_subject");
if (p) {
retdb->attributes.unique_subject = parse_yesno(p, 1);
}
}
err:
NCONF_free(dbattr_conf);
TXT_DB_free(tmpdb);
BIO_free_all(in);
return retdb;
}
int index_index(CA_DB *db)
{
if (!TXT_DB_create_index(db->db, DB_serial, NULL,
LHASH_HASH_FN(index_serial),
LHASH_COMP_FN(index_serial))) {
BIO_printf(bio_err,
"error creating serial number index:(%ld,%ld,%ld)\n",
db->db->error, db->db->arg1, db->db->arg2);
return 0;
}
if (db->attributes.unique_subject
&& !TXT_DB_create_index(db->db, DB_name, index_name_qual,
LHASH_HASH_FN(index_name),
LHASH_COMP_FN(index_name))) {
BIO_printf(bio_err, "error creating name index:(%ld,%ld,%ld)\n",
db->db->error, db->db->arg1, db->db->arg2);
return 0;
}
return 1;
}
int save_index(const char *dbfile, const char *suffix, CA_DB *db)
{
char buf[3][BSIZE];
BIO *out;
int j;
j = strlen(dbfile) + strlen(suffix);
if (j + 6 >= BSIZE) {
BIO_printf(bio_err, "file name too long\n");
goto err;
}
#ifndef OPENSSL_SYS_VMS
j = BIO_snprintf(buf[2], sizeof buf[2], "%s.attr", dbfile);
j = BIO_snprintf(buf[1], sizeof buf[1], "%s.attr.%s", dbfile, suffix);
j = BIO_snprintf(buf[0], sizeof buf[0], "%s.%s", dbfile, suffix);
#else
j = BIO_snprintf(buf[2], sizeof buf[2], "%s-attr", dbfile);
j = BIO_snprintf(buf[1], sizeof buf[1], "%s-attr-%s", dbfile, suffix);
j = BIO_snprintf(buf[0], sizeof buf[0], "%s-%s", dbfile, suffix);
#endif
out = BIO_new_file(buf[0], "w");
if (out == NULL) {
perror(dbfile);
BIO_printf(bio_err, "unable to open '%s'\n", dbfile);
goto err;
}
j = TXT_DB_write(out, db->db);
BIO_free(out);
if (j <= 0)
goto err;
out = BIO_new_file(buf[1], "w");
if (out == NULL) {
perror(buf[2]);
BIO_printf(bio_err, "unable to open '%s'\n", buf[2]);
goto err;
}
BIO_printf(out, "unique_subject = %s\n",
db->attributes.unique_subject ? "yes" : "no");
BIO_free(out);
return 1;
err:
return 0;
}
int rotate_index(const char *dbfile, const char *new_suffix,
const char *old_suffix)
{
char buf[5][BSIZE];
int i, j;
i = strlen(dbfile) + strlen(old_suffix);
j = strlen(dbfile) + strlen(new_suffix);
if (i > j)
j = i;
if (j + 6 >= BSIZE) {
BIO_printf(bio_err, "file name too long\n");
goto err;
}
#ifndef OPENSSL_SYS_VMS
j = BIO_snprintf(buf[4], sizeof buf[4], "%s.attr", dbfile);
j = BIO_snprintf(buf[3], sizeof buf[3], "%s.attr.%s", dbfile, old_suffix);
j = BIO_snprintf(buf[2], sizeof buf[2], "%s.attr.%s", dbfile, new_suffix);
j = BIO_snprintf(buf[1], sizeof buf[1], "%s.%s", dbfile, old_suffix);
j = BIO_snprintf(buf[0], sizeof buf[0], "%s.%s", dbfile, new_suffix);
#else
j = BIO_snprintf(buf[4], sizeof buf[4], "%s-attr", dbfile);
j = BIO_snprintf(buf[3], sizeof buf[3], "%s-attr-%s", dbfile, old_suffix);
j = BIO_snprintf(buf[2], sizeof buf[2], "%s-attr-%s", dbfile, new_suffix);
j = BIO_snprintf(buf[1], sizeof buf[1], "%s-%s", dbfile, old_suffix);
j = BIO_snprintf(buf[0], sizeof buf[0], "%s-%s", dbfile, new_suffix);
#endif
if (rename(dbfile, buf[1]) < 0 && errno != ENOENT
#ifdef ENOTDIR
&& errno != ENOTDIR
#endif
) {
BIO_printf(bio_err, "unable to rename %s to %s\n", dbfile, buf[1]);
perror("reason");
goto err;
}
if (rename(buf[0], dbfile) < 0) {
BIO_printf(bio_err, "unable to rename %s to %s\n", buf[0], dbfile);
perror("reason");
rename(buf[1], dbfile);
goto err;
}
if (rename(buf[4], buf[3]) < 0 && errno != ENOENT
#ifdef ENOTDIR
&& errno != ENOTDIR
#endif
) {
BIO_printf(bio_err, "unable to rename %s to %s\n", buf[4], buf[3]);
perror("reason");
rename(dbfile, buf[0]);
rename(buf[1], dbfile);
goto err;
}
if (rename(buf[2], buf[4]) < 0) {
BIO_printf(bio_err, "unable to rename %s to %s\n", buf[2], buf[4]);
perror("reason");
rename(buf[3], buf[4]);
rename(dbfile, buf[0]);
rename(buf[1], dbfile);
goto err;
}
return 1;
err:
return 0;
}
void free_index(CA_DB *db)
{
if (db) {
TXT_DB_free(db->db);
OPENSSL_free(db);
}
}
int parse_yesno(const char *str, int def)
{
if (str) {
switch (*str) {
case 'f':
case 'F':
case 'n':
case 'N':
case '0':
return 0;
case 't':
case 'T':
case 'y':
case 'Y':
case '1':
return 1;
}
}
return def;
}
X509_NAME *parse_name(const char *cp, long chtype, int canmulti)
{
int nextismulti = 0;
char *work;
X509_NAME *n;
if (*cp++ != '/')
return NULL;
n = X509_NAME_new();
if (n == NULL)
return NULL;
work = OPENSSL_strdup(cp);
if (work == NULL)
goto err;
while (*cp) {
char *bp = work;
char *typestr = bp;
unsigned char *valstr;
int nid;
int ismulti = nextismulti;
nextismulti = 0;
while (*cp && *cp != '=')
*bp++ = *cp++;
if (*cp == '\0') {
BIO_printf(bio_err,
"%s: Hit end of string before finding the equals.\n",
opt_getprog());
goto err;
}
*bp++ = '\0';
++cp;
valstr = (unsigned char *)bp;
for (; *cp && *cp != '/'; *bp++ = *cp++) {
if (canmulti && *cp == '+') {
nextismulti = 1;
break;
}
if (*cp == '\\' && *++cp == '\0') {
BIO_printf(bio_err,
"%s: escape character at end of string\n",
opt_getprog());
goto err;
}
}
*bp++ = '\0';
if (*cp)
++cp;
nid = OBJ_txt2nid(typestr);
if (nid == NID_undef) {
BIO_printf(bio_err, "%s: Skipping unknown attribute \"%s\"\n",
opt_getprog(), typestr);
continue;
}
if (!X509_NAME_add_entry_by_NID(n, nid, chtype,
valstr, strlen((char *)valstr),
-1, ismulti ? -1 : 0))
goto err;
}
OPENSSL_free(work);
return n;
err:
X509_NAME_free(n);
OPENSSL_free(work);
return NULL;
}
int bio_to_mem(unsigned char **out, int maxlen, BIO *in)
{
BIO *mem;
int len, ret;
unsigned char tbuf[1024];
mem = BIO_new(BIO_s_mem());
if (mem == NULL)
return -1;
for (;;) {
if ((maxlen != -1) && maxlen < 1024)
len = maxlen;
else
len = 1024;
len = BIO_read(in, tbuf, len);
if (len < 0) {
BIO_free(mem);
return -1;
}
if (len == 0)
break;
if (BIO_write(mem, tbuf, len) != len) {
BIO_free(mem);
return -1;
}
maxlen -= len;
if (maxlen == 0)
break;
}
ret = BIO_get_mem_data(mem, (char **)out);
BIO_set_flags(mem, BIO_FLAGS_MEM_RDONLY);
BIO_free(mem);
return ret;
}
int pkey_ctrl_string(EVP_PKEY_CTX *ctx, const char *value)
{
int rv;
char *stmp, *vtmp = NULL;
stmp = OPENSSL_strdup(value);
if (!stmp)
return -1;
vtmp = strchr(stmp, ':');
if (vtmp) {
*vtmp = 0;
vtmp++;
}
rv = EVP_PKEY_CTX_ctrl_str(ctx, stmp, vtmp);
OPENSSL_free(stmp);
return rv;
}
void policies_print(X509_STORE_CTX *ctx)
{
X509_POLICY_TREE *tree;
int explicit_policy;
tree = X509_STORE_CTX_get0_policy_tree(ctx);
explicit_policy = X509_STORE_CTX_get_explicit_policy(ctx);
BIO_printf(bio_err, "Require explicit Policy: %s\n",
explicit_policy ? "True" : "False");
nodes_print("Authority", X509_policy_tree_get0_policies(tree));
nodes_print("User", X509_policy_tree_get0_user_policies(tree));
}
unsigned char *next_protos_parse(size_t *outlen, const char *in)
{
size_t len;
unsigned char *out;
size_t i, start = 0;
len = strlen(in);
if (len >= 65535)
return NULL;
out = app_malloc(strlen(in) + 1, "NPN buffer");
for (i = 0; i <= len; ++i) {
if (i == len || in[i] == ',') {
if (i - start > 255) {
OPENSSL_free(out);
return NULL;
}
out[start] = i - start;
start = i + 1;
} else
out[i + 1] = in[i];
}
*outlen = len + 1;
return out;
}
void print_cert_checks(BIO *bio, X509 *x,
const char *checkhost,
const char *checkemail, const char *checkip)
{
if (x == NULL)
return;
if (checkhost) {
BIO_printf(bio, "Hostname %s does%s match certificate\n",
checkhost,
X509_check_host(x, checkhost, 0, 0, NULL) == 1
? "" : " NOT");
}
if (checkemail) {
BIO_printf(bio, "Email %s does%s match certificate\n",
checkemail, X509_check_email(x, checkemail, 0, 0)
? "" : " NOT");
}
if (checkip) {
BIO_printf(bio, "IP %s does%s match certificate\n",
checkip, X509_check_ip_asc(x, checkip, 0) ? "" : " NOT");
}
}
static const char *get_dp_url(DIST_POINT *dp)
{
GENERAL_NAMES *gens;
GENERAL_NAME *gen;
int i, gtype;
ASN1_STRING *uri;
if (!dp->distpoint || dp->distpoint->type != 0)
return NULL;
gens = dp->distpoint->name.fullname;
for (i = 0; i < sk_GENERAL_NAME_num(gens); i++) {
gen = sk_GENERAL_NAME_value(gens, i);
uri = GENERAL_NAME_get0_value(gen, &gtype);
if (gtype == GEN_URI && ASN1_STRING_length(uri) > 6) {
const char *uptr = (const char *)ASN1_STRING_get0_data(uri);
if (strncmp(uptr, "http://", 7) == 0)
return uptr;
}
}
return NULL;
}
static int WIN32_rename(const char *from, const char *to)
{
TCHAR *tfrom = NULL, *tto;
DWORD err;
int ret = 0;
if (sizeof(TCHAR) == 1) {
tfrom = (TCHAR *)from;
tto = (TCHAR *)to;
} else {
size_t i, flen = strlen(from) + 1, tlen = strlen(to) + 1;
tfrom = malloc(sizeof(*tfrom) * (flen + tlen));
if (tfrom == NULL)
goto err;
tto = tfrom + flen;
# if !defined(_WIN32_WCE) || _WIN32_WCE>=101
if (!MultiByteToWideChar(CP_ACP, 0, from, flen, (WCHAR *)tfrom, flen))
# endif
for (i = 0; i < flen; i++)
tfrom[i] = (TCHAR)from[i];
# if !defined(_WIN32_WCE) || _WIN32_WCE>=101
if (!MultiByteToWideChar(CP_ACP, 0, to, tlen, (WCHAR *)tto, tlen))
# endif
for (i = 0; i < tlen; i++)
tto[i] = (TCHAR)to[i];
}
if (MoveFile(tfrom, tto))
goto ok;
err = GetLastError();
if (err == ERROR_ALREADY_EXISTS || err == ERROR_FILE_EXISTS) {
if (DeleteFile(tto) && MoveFile(tfrom, tto))
goto ok;
err = GetLastError();
}
if (err == ERROR_FILE_NOT_FOUND || err == ERROR_PATH_NOT_FOUND)
errno = ENOENT;
else if (err == ERROR_ACCESS_DENIED)
errno = EACCES;
else
errno = EINVAL;
err:
ret = -1;
ok:
if (tfrom != NULL && tfrom != (TCHAR *)from)
free(tfrom);
return ret;
}
double app_tminterval(int stop, int usertime)
{
FILETIME now;
double ret = 0;
static ULARGE_INTEGER tmstart;
static int warning = 1;
# ifdef _WIN32_WINNT
static HANDLE proc = NULL;
if (proc == NULL) {
if (check_winnt())
proc = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE,
GetCurrentProcessId());
if (proc == NULL)
proc = (HANDLE) - 1;
}
if (usertime && proc != (HANDLE) - 1) {
FILETIME junk;
GetProcessTimes(proc, &junk, &junk, &junk, &now);
} else
# endif
{
SYSTEMTIME systime;
if (usertime && warning) {
BIO_printf(bio_err, "To get meaningful results, run "
"this program on idle system.\n");
warning = 0;
}
GetSystemTime(&systime);
SystemTimeToFileTime(&systime, &now);
}
if (stop == TM_START) {
tmstart.u.LowPart = now.dwLowDateTime;
tmstart.u.HighPart = now.dwHighDateTime;
} else {
ULARGE_INTEGER tmstop;
tmstop.u.LowPart = now.dwLowDateTime;
tmstop.u.HighPart = now.dwHighDateTime;
ret = (__int64)(tmstop.QuadPart - tmstart.QuadPart) * 1e-7;
}
return (ret);
}
double app_tminterval(int stop, int usertime)
{
double ret = 0;
# ifdef CLOCK_REALTIME
static struct timespec tmstart;
struct timespec now;
# else
static unsigned long tmstart;
unsigned long now;
# endif
static int warning = 1;
if (usertime && warning) {
BIO_printf(bio_err, "To get meaningful results, run "
"this program on idle system.\n");
warning = 0;
}
# ifdef CLOCK_REALTIME
clock_gettime(CLOCK_REALTIME, &now);
if (stop == TM_START)
tmstart = now;
else
ret = ((now.tv_sec + now.tv_nsec * 1e-9)
- (tmstart.tv_sec + tmstart.tv_nsec * 1e-9));
# else
now = tickGet();
if (stop == TM_START)
tmstart = now;
else
ret = (now - tmstart) / (double)sysClkRateGet();
# endif
return (ret);
}
double app_tminterval(int stop, int usertime)
{
static clock_t tmstart;
double ret = 0;
clock_t now;
# ifdef __TMS
struct tms rus;
now = times(&rus);
if (usertime)
now = rus.tms_utime;
# else
if (usertime)
now = clock();
else {
struct timeval tv;
gettimeofday(&tv, NULL);
now = (clock_t)((unsigned long long)tv.tv_sec * CLK_TCK +
(unsigned long long)tv.tv_usec * (1000000 / CLK_TCK)
);
}
# endif
if (stop == TM_START)
tmstart = now;
else
ret = (now - tmstart) / (double)(CLK_TCK);
return (ret);
}
double app_tminterval(int stop, int usertime)
{
double ret = 0;
struct tms rus;
clock_t now = times(&rus);
static clock_t tmstart;
if (usertime)
now = rus.tms_utime;
if (stop == TM_START)
tmstart = now;
else {
long int tck = sysconf(_SC_CLK_TCK);
ret = (now - tmstart) / (double)tck;
}
return (ret);
}
double app_tminterval(int stop, int usertime)
{
double ret = 0;
struct rusage rus;
struct timeval now;
static struct timeval tmstart;
if (usertime)
getrusage(RUSAGE_SELF, &rus), now = rus.ru_utime;
else
gettimeofday(&now, NULL);
if (stop == TM_START)
tmstart = now;
else
ret = ((now.tv_sec + now.tv_usec * 1e-6)
- (tmstart.tv_sec + tmstart.tv_usec * 1e-6));
return ret;
}
int app_access(const char* name, int flag)
{
#ifdef _WIN32
return _access(name, flag);
#else
return access(name, flag);
#endif
}
int app_isdir(const char *name)
{
HANDLE hList;
WIN32_FIND_DATA FileData;
# if defined(UNICODE) || defined(_UNICODE)
size_t i, len_0 = strlen(name) + 1;
if (len_0 > OSSL_NELEM(FileData.cFileName))
return -1;
# if !defined(_WIN32_WCE) || _WIN32_WCE>=101
if (!MultiByteToWideChar
(CP_ACP, 0, name, len_0, FileData.cFileName, len_0))
# endif
for (i = 0; i < len_0; i++)
FileData.cFileName[i] = (WCHAR)name[i];
hList = FindFirstFile(FileData.cFileName, &FileData);
# else
hList = FindFirstFile(name, &FileData);
# endif
if (hList == INVALID_HANDLE_VALUE)
return -1;
FindClose(hList);
return ((FileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0);
}
int app_isdir(const char *name)
{
# if defined(S_ISDIR)
struct stat st;
if (stat(name, &st) == 0)
return S_ISDIR(st.st_mode);
else
return -1;
# else
return -1;
# endif
}
int raw_read_stdin(void *buf, int siz)
{
DWORD n;
if (ReadFile(GetStdHandle(STD_INPUT_HANDLE), buf, siz, &n, NULL))
return (n);
else
return (-1);
}
int raw_read_stdin(void *buf, int siz)
{
return read(fileno(stdin), buf, siz);
}
int raw_write_stdout(const void *buf, int siz)
{
DWORD n;
if (WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), buf, siz, &n, NULL))
return (n);
else
return (-1);
}
int raw_write_stdout(const void *buf, int siz)
{
return write(fileno(stdout), buf, siz);
}
static int istext(int format)
{
return (format & B_FORMAT_TEXT) == B_FORMAT_TEXT;
}
BIO *dup_bio_in(int format)
{
return BIO_new_fp(stdin,
BIO_NOCLOSE | (istext(format) ? BIO_FP_TEXT : 0));
}
BIO *dup_bio_out(int format)
{
BIO *b = BIO_new_fp(stdout,
BIO_NOCLOSE | (istext(format) ? BIO_FP_TEXT : 0));
#ifdef OPENSSL_SYS_VMS
if (istext(format))
b = BIO_push(BIO_new(BIO_f_linebuffer()), b);
#endif
return b;
}
BIO *dup_bio_err(int format)
{
BIO *b = BIO_new_fp(stderr,
BIO_NOCLOSE | (istext(format) ? BIO_FP_TEXT : 0));
#ifdef OPENSSL_SYS_VMS
if (istext(format))
b = BIO_push(BIO_new(BIO_f_linebuffer()), b);
#endif
return b;
}
void unbuffer(FILE *fp)
{
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma environment save
# pragma message disable maylosedata2
#endif
setbuf(fp, NULL);
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma environment restore
#endif
}
static const char *modestr(char mode, int format)
{
OPENSSL_assert(mode == 'a' || mode == 'r' || mode == 'w');
switch (mode) {
case 'a':
return istext(format) ? "a" : "ab";
case 'r':
return istext(format) ? "r" : "rb";
case 'w':
return istext(format) ? "w" : "wb";
}
return NULL;
}
static const char *modeverb(char mode)
{
switch (mode) {
case 'a':
return "appending";
case 'r':
return "reading";
case 'w':
return "writing";
}
return "(doing something)";
}
BIO *bio_open_owner(const char *filename, int format, int private)
{
FILE *fp = NULL;
BIO *b = NULL;
int fd = -1, bflags, mode, textmode;
if (!private || filename == NULL || strcmp(filename, "-") == 0)
return bio_open_default(filename, 'w', format);
mode = O_WRONLY;
#ifdef O_CREAT
mode |= O_CREAT;
#endif
#ifdef O_TRUNC
mode |= O_TRUNC;
#endif
textmode = istext(format);
if (!textmode) {
#ifdef O_BINARY
mode |= O_BINARY;
#elif defined(_O_BINARY)
mode |= _O_BINARY;
#endif
}
#ifdef OPENSSL_SYS_VMS
if (!textmode)
fd = open(filename, mode, 0600, "ctx=bin");
else
#endif
fd = open(filename, mode, 0600);
if (fd < 0)
goto err;
fp = fdopen(fd, modestr('w', format));
if (fp == NULL)
goto err;
bflags = BIO_CLOSE;
if (textmode)
bflags |= BIO_FP_TEXT;
b = BIO_new_fp(fp, bflags);
if (b)
return b;
err:
BIO_printf(bio_err, "%s: Can't open \"%s\" for writing, %s\n",
opt_getprog(), filename, strerror(errno));
ERR_print_errors(bio_err);
if (fp)
fclose(fp);
else if (fd >= 0)
close(fd);
return NULL;
}
static BIO *bio_open_default_(const char *filename, char mode, int format,
int quiet)
{
BIO *ret;
if (filename == NULL || strcmp(filename, "-") == 0) {
ret = mode == 'r' ? dup_bio_in(format) : dup_bio_out(format);
if (quiet) {
ERR_clear_error();
return ret;
}
if (ret != NULL)
return ret;
BIO_printf(bio_err,
"Can't open %s, %s\n",
mode == 'r' ? "stdin" : "stdout", strerror(errno));
} else {
ret = BIO_new_file(filename, modestr(mode, format));
if (quiet) {
ERR_clear_error();
return ret;
}
if (ret != NULL)
return ret;
BIO_printf(bio_err,
"Can't open %s for %s, %s\n",
filename, modeverb(mode), strerror(errno));
}
ERR_print_errors(bio_err);
return NULL;
}
BIO *bio_open_default(const char *filename, char mode, int format)
{
return bio_open_default_(filename, mode, format, 0);
}
BIO *bio_open_default_quiet(const char *filename, char mode, int format)
{
return bio_open_default_(filename, mode, format, 1);
}
void wait_for_async(SSL *s)
{
#ifndef OPENSSL_SYS_WINDOWS
int width = 0;
fd_set asyncfds;
OSSL_ASYNC_FD *fds;
size_t numfds;
if (!SSL_get_all_async_fds(s, NULL, &numfds))
return;
if (numfds == 0)
return;
fds = app_malloc(sizeof(OSSL_ASYNC_FD) * numfds, "allocate async fds");
if (!SSL_get_all_async_fds(s, fds, &numfds)) {
OPENSSL_free(fds);
}
FD_ZERO(&asyncfds);
while (numfds > 0) {
if (width <= (int)*fds)
width = (int)*fds + 1;
openssl_fdset((int)*fds, &asyncfds);
numfds--;
fds++;
}
select(width, (void *)&asyncfds, NULL, NULL, NULL);
#endif
}
int has_stdin_waiting(void)
{
# if defined(OPENSSL_SYS_WINDOWS)
HANDLE inhand = GetStdHandle(STD_INPUT_HANDLE);
DWORD events = 0;
INPUT_RECORD inputrec;
DWORD insize = 1;
BOOL peeked;
if (inhand == INVALID_HANDLE_VALUE) {
return 0;
}
peeked = PeekConsoleInput(inhand, &inputrec, insize, &events);
if (!peeked) {
if (!feof(stdin)) {
return 1;
}
return 0;
}
# endif
return _kbhit();
}
void corrupt_signature(const ASN1_STRING *signature)
{
unsigned char *s = signature->data;
s[signature->length - 1] ^= 0x1;
}
int set_cert_times(X509 *x, const char *startdate, const char *enddate,
int days)
{
if (startdate == NULL || strcmp(startdate, "today") == 0) {
if (X509_gmtime_adj(X509_getm_notBefore(x), 0) == NULL)
return 0;
} else {
if (!ASN1_TIME_set_string(X509_getm_notBefore(x), startdate))
return 0;
}
if (enddate == NULL) {
if (X509_time_adj_ex(X509_getm_notAfter(x), days, 0, NULL)
== NULL)
return 0;
} else if (!ASN1_TIME_set_string(X509_getm_notAfter(x), enddate)) {
return 0;
}
return 1;
}
