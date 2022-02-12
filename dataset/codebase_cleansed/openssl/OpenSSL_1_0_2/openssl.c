static void lock_dbg_cb(int mode, int type, const char *file, int line)
{
static int modes[CRYPTO_NUM_LOCKS];
const char *errstr = NULL;
int rw;
rw = mode & (CRYPTO_READ | CRYPTO_WRITE);
if (!((rw == CRYPTO_READ) || (rw == CRYPTO_WRITE))) {
errstr = "invalid mode";
goto err;
}
if (type < 0 || type >= CRYPTO_NUM_LOCKS) {
errstr = "type out of bounds";
goto err;
}
if (mode & CRYPTO_LOCK) {
if (modes[type]) {
errstr = "already locked";
goto err;
}
modes[type] = rw;
} else if (mode & CRYPTO_UNLOCK) {
if (!modes[type]) {
errstr = "not locked";
goto err;
}
if (modes[type] != rw) {
errstr = (rw == CRYPTO_READ) ?
"CRYPTO_r_unlock on write lock" :
"CRYPTO_w_unlock on read lock";
}
modes[type] = 0;
} else {
errstr = "invalid mode";
goto err;
}
err:
if (errstr) {
fprintf(stderr,
"openssl (lock_dbg_cb): %s (mode=%d, type=%d) at %s:%d\n",
errstr, mode, type, file, line);
}
}
int main(int Argc, char *ARGV[])
{
ARGS arg;
#define PROG_NAME_SIZE 39
char pname[PROG_NAME_SIZE + 1];
FUNCTION f, *fp;
MS_STATIC const char *prompt;
MS_STATIC char buf[1024];
char *to_free = NULL;
int n, i, ret = 0;
int argc;
char **argv, *p;
LHASH_OF(FUNCTION) *prog = NULL;
long errline;
#if defined( OPENSSL_SYS_VMS) && (__INITIAL_POINTER_SIZE == 64)
char **Argv = NULL;
int free_Argv = 0;
if ((sizeof(_Argv) < 8)
# if !defined( VMS_TRUST_ARGV)
|| (_Argv[Argc] != NULL)
# endif
) {
int i;
Argv = OPENSSL_malloc((Argc + 1) * sizeof(char *));
if (Argv == NULL) {
ret = -1;
goto end;
}
for (i = 0; i < Argc; i++)
Argv[i] = _Argv[i];
Argv[Argc] = NULL;
free_Argv = 1;
} else {
Argv = (char **)_Argv;
}
#endif
arg.data = NULL;
arg.count = 0;
if (bio_err == NULL)
if ((bio_err = BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err, stderr, BIO_NOCLOSE | BIO_FP_TEXT);
if (getenv("OPENSSL_DEBUG_MEMORY") != NULL) {
if (!(0 == strcmp(getenv("OPENSSL_DEBUG_MEMORY"), "off"))) {
CRYPTO_malloc_debug_init();
CRYPTO_set_mem_debug_options(V_CRYPTO_MDEBUG_ALL);
} else {
CRYPTO_set_mem_debug_functions(0, 0, 0, 0, 0);
}
}
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ON);
#if 0
if (getenv("OPENSSL_DEBUG_LOCKING") != NULL)
#endif
{
CRYPTO_set_locking_callback(lock_dbg_cb);
}
if (getenv("OPENSSL_FIPS")) {
#ifdef OPENSSL_FIPS
if (!FIPS_mode_set(1)) {
ERR_load_crypto_strings();
ERR_print_errors(BIO_new_fp(stderr, BIO_NOCLOSE));
EXIT(1);
}
#else
fprintf(stderr, "FIPS mode not supported.\n");
EXIT(1);
#endif
}
apps_startup();
p = getenv("OPENSSL_CONF");
if (p == NULL)
p = getenv("SSLEAY_CONF");
if (p == NULL)
p = to_free = make_config_name();
default_config_file = p;
config = NCONF_new(NULL);
i = NCONF_load(config, p, &errline);
if (i == 0) {
if (ERR_GET_REASON(ERR_peek_last_error())
== CONF_R_NO_SUCH_FILE) {
BIO_printf(bio_err, "WARNING: can't open config file: %s\n", p);
ERR_clear_error();
NCONF_free(config);
config = NULL;
} else {
ERR_print_errors(bio_err);
NCONF_free(config);
exit(1);
}
}
prog = prog_init();
program_name(Argv[0], pname, sizeof pname);
f.name = pname;
fp = lh_FUNCTION_retrieve(prog, &f);
if (fp != NULL) {
Argv[0] = pname;
ret = fp->func(Argc, Argv);
goto end;
}
if (Argc != 1) {
Argc--;
Argv++;
ret = do_cmd(prog, Argc, Argv);
if (ret < 0)
ret = 0;
goto end;
}
for (;;) {
ret = 0;
p = buf;
n = sizeof buf;
i = 0;
for (;;) {
p[0] = '\0';
if (i++)
prompt = ">";
else
prompt = "OpenSSL> ";
fputs(prompt, stdout);
fflush(stdout);
if (!fgets(p, n, stdin))
goto end;
if (p[0] == '\0')
goto end;
i = strlen(p);
if (i <= 1)
break;
if (p[i - 2] != '\\')
break;
i -= 2;
p += i;
n -= i;
}
if (!chopup_args(&arg, buf, &argc, &argv))
break;
ret = do_cmd(prog, argc, argv);
if (ret < 0) {
ret = 0;
goto end;
}
if (ret != 0)
BIO_printf(bio_err, "error in %s\n", argv[0]);
(void)BIO_flush(bio_err);
}
BIO_printf(bio_err, "bad exit\n");
ret = 1;
end:
if (to_free)
OPENSSL_free(to_free);
if (config != NULL) {
NCONF_free(config);
config = NULL;
}
if (prog != NULL)
lh_FUNCTION_free(prog);
if (arg.data != NULL)
OPENSSL_free(arg.data);
if (bio_err != NULL) {
BIO_free(bio_err);
bio_err = NULL;
}
#if defined( OPENSSL_SYS_VMS) && (__INITIAL_POINTER_SIZE == 64)
if (free_Argv) {
OPENSSL_free(Argv);
}
#endif
apps_shutdown();
CRYPTO_mem_leaks(bio_err);
OPENSSL_EXIT(ret);
}
static int SortFnByName(const void *_f1, const void *_f2)
{
const FUNCTION *f1 = _f1;
const FUNCTION *f2 = _f2;
if (f1->type != f2->type)
return f1->type - f2->type;
return strcmp(f1->name, f2->name);
}
static void list_pkey(BIO *out)
{
int i;
for (i = 0; i < EVP_PKEY_asn1_get_count(); i++) {
const EVP_PKEY_ASN1_METHOD *ameth;
int pkey_id, pkey_base_id, pkey_flags;
const char *pinfo, *pem_str;
ameth = EVP_PKEY_asn1_get0(i);
EVP_PKEY_asn1_get0_info(&pkey_id, &pkey_base_id, &pkey_flags,
&pinfo, &pem_str, ameth);
if (pkey_flags & ASN1_PKEY_ALIAS) {
BIO_printf(out, "Name: %s\n", OBJ_nid2ln(pkey_id));
BIO_printf(out, "\tType: Alias to %s\n",
OBJ_nid2ln(pkey_base_id));
} else {
BIO_printf(out, "Name: %s\n", pinfo);
BIO_printf(out, "\tType: %s Algorithm\n",
pkey_flags & ASN1_PKEY_DYNAMIC ?
"External" : "Builtin");
BIO_printf(out, "\tOID: %s\n", OBJ_nid2ln(pkey_id));
if (pem_str == NULL)
pem_str = "(none)";
BIO_printf(out, "\tPEM string: %s\n", pem_str);
}
}
}
static void list_cipher_fn(const EVP_CIPHER *c,
const char *from, const char *to, void *arg)
{
if (c)
BIO_printf(arg, "%s\n", EVP_CIPHER_name(c));
else {
if (!from)
from = "<undefined>";
if (!to)
to = "<undefined>";
BIO_printf(arg, "%s => %s\n", from, to);
}
}
static void list_cipher(BIO *out)
{
EVP_CIPHER_do_all_sorted(list_cipher_fn, out);
}
static void list_md_fn(const EVP_MD *m,
const char *from, const char *to, void *arg)
{
if (m)
BIO_printf(arg, "%s\n", EVP_MD_name(m));
else {
if (!from)
from = "<undefined>";
if (!to)
to = "<undefined>";
BIO_printf(arg, "%s => %s\n", from, to);
}
}
static void list_md(BIO *out)
{
EVP_MD_do_all_sorted(list_md_fn, out);
}
static int MS_CALLBACK function_cmp(const FUNCTION * a, const FUNCTION * b)
{
return strncmp(a->name, b->name, 8);
}
