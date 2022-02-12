static void err_fns_check(void)
{
if (err_fns)
return;
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
if (!err_fns)
err_fns = &err_defaults;
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
}
const ERR_FNS *ERR_get_implementation(void)
{
err_fns_check();
return err_fns;
}
int ERR_set_implementation(const ERR_FNS *fns)
{
int ret = 0;
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
if (!err_fns) {
err_fns = fns;
ret = 1;
}
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
return ret;
}
static unsigned long err_string_data_hash(const ERR_STRING_DATA *a)
{
unsigned long ret, l;
l = a->error;
ret = l ^ ERR_GET_LIB(l) ^ ERR_GET_FUNC(l);
return (ret ^ ret % 19 * 13);
}
void int_err_del(void)
{
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
if (int_error_hash) {
lh_ERR_STRING_DATA_free(int_error_hash);
int_error_hash = NULL;
}
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
}
static ERR_STRING_DATA *int_err_get_item(const ERR_STRING_DATA *d)
{
ERR_STRING_DATA *p;
LHASH_OF(ERR_STRING_DATA) *hash;
err_fns_check();
hash = ERRFN(err_get) (0);
if (!hash)
return NULL;
CRYPTO_r_lock(CRYPTO_LOCK_ERR);
p = lh_ERR_STRING_DATA_retrieve(hash, d);
CRYPTO_r_unlock(CRYPTO_LOCK_ERR);
return p;
}
static ERR_STRING_DATA *int_err_set_item(ERR_STRING_DATA *d)
{
ERR_STRING_DATA *p;
LHASH_OF(ERR_STRING_DATA) *hash;
err_fns_check();
hash = ERRFN(err_get) (1);
if (!hash)
return NULL;
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
p = lh_ERR_STRING_DATA_insert(hash, d);
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
return p;
}
static ERR_STRING_DATA *int_err_del_item(ERR_STRING_DATA *d)
{
ERR_STRING_DATA *p;
LHASH_OF(ERR_STRING_DATA) *hash;
err_fns_check();
hash = ERRFN(err_get) (0);
if (!hash)
return NULL;
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
p = lh_ERR_STRING_DATA_delete(hash, d);
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
return p;
}
static unsigned long err_state_hash(const ERR_STATE *a)
{
return CRYPTO_THREADID_hash(&a->tid) * 13;
}
static ERR_STATE *int_thread_get_item(const ERR_STATE *d)
{
ERR_STATE *p;
LHASH_OF(ERR_STATE) *hash;
err_fns_check();
hash = ERRFN(thread_get) (0);
if (!hash)
return NULL;
CRYPTO_r_lock(CRYPTO_LOCK_ERR);
p = lh_ERR_STATE_retrieve(hash, d);
CRYPTO_r_unlock(CRYPTO_LOCK_ERR);
ERRFN(thread_release) (&hash);
return p;
}
static ERR_STATE *int_thread_set_item(ERR_STATE *d)
{
ERR_STATE *p;
LHASH_OF(ERR_STATE) *hash;
err_fns_check();
hash = ERRFN(thread_get) (1);
if (!hash)
return NULL;
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
p = lh_ERR_STATE_insert(hash, d);
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
ERRFN(thread_release) (&hash);
return p;
}
static void int_thread_del_item(const ERR_STATE *d)
{
ERR_STATE *p;
LHASH_OF(ERR_STATE) *hash;
err_fns_check();
hash = ERRFN(thread_get) (0);
if (!hash)
return;
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
p = lh_ERR_STATE_delete(hash, d);
if (int_thread_hash_references == 1
&& int_thread_hash && lh_ERR_STATE_num_items(int_thread_hash) == 0) {
lh_ERR_STATE_free(int_thread_hash);
int_thread_hash = NULL;
}
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
ERRFN(thread_release) (&hash);
if (p)
ERR_STATE_free(p);
}
static int int_err_get_next_lib(void)
{
int ret;
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
ret = int_err_library_number++;
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
return ret;
}
static void build_SYS_str_reasons(void)
{
static char strerror_tab[NUM_SYS_STR_REASONS][LEN_SYS_STR_REASON];
int i;
static int init = 1;
CRYPTO_r_lock(CRYPTO_LOCK_ERR);
if (!init) {
CRYPTO_r_unlock(CRYPTO_LOCK_ERR);
return;
}
CRYPTO_r_unlock(CRYPTO_LOCK_ERR);
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
if (!init) {
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
return;
}
for (i = 1; i <= NUM_SYS_STR_REASONS; i++) {
ERR_STRING_DATA *str = &SYS_str_reasons[i - 1];
str->error = (unsigned long)i;
if (str->string == NULL) {
char (*dest)[LEN_SYS_STR_REASON] = &(strerror_tab[i - 1]);
char *src = strerror(i);
if (src != NULL) {
strncpy(*dest, src, sizeof *dest);
(*dest)[sizeof *dest - 1] = '\0';
str->string = *dest;
}
}
if (str->string == NULL)
str->string = "unknown";
}
init = 0;
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
}
static void ERR_STATE_free(ERR_STATE *s)
{
int i;
if (s == NULL)
return;
for (i = 0; i < ERR_NUM_ERRORS; i++) {
err_clear_data(s, i);
}
OPENSSL_free(s);
}
void ERR_load_ERR_strings(void)
{
err_fns_check();
#ifndef OPENSSL_NO_ERR
err_load_strings(0, ERR_str_libraries);
err_load_strings(0, ERR_str_reasons);
err_load_strings(ERR_LIB_SYS, ERR_str_functs);
build_SYS_str_reasons();
err_load_strings(ERR_LIB_SYS, SYS_str_reasons);
#endif
}
static void err_load_strings(int lib, ERR_STRING_DATA *str)
{
while (str->error) {
if (lib)
str->error |= ERR_PACK(lib, 0, 0);
ERRFN(err_set_item) (str);
str++;
}
}
void ERR_load_strings(int lib, ERR_STRING_DATA *str)
{
ERR_load_ERR_strings();
err_load_strings(lib, str);
}
void ERR_unload_strings(int lib, ERR_STRING_DATA *str)
{
while (str->error) {
if (lib)
str->error |= ERR_PACK(lib, 0, 0);
ERRFN(err_del_item) (str);
str++;
}
}
void ERR_free_strings(void)
{
err_fns_check();
ERRFN(err_del) ();
}
void ERR_put_error(int lib, int func, int reason, const char *file, int line)
{
ERR_STATE *es;
#ifdef _OSD_POSIX
if (strncmp(file, "*POSIX(", sizeof("*POSIX(") - 1) == 0) {
char *end;
file += sizeof("*POSIX(") - 1;
end = &file[strlen(file) - 1];
if (*end == ')')
*end = '\0';
if ((end = strrchr(file, '/')) != NULL)
file = &end[1];
}
#endif
es = ERR_get_state();
es->top = (es->top + 1) % ERR_NUM_ERRORS;
if (es->top == es->bottom)
es->bottom = (es->bottom + 1) % ERR_NUM_ERRORS;
es->err_flags[es->top] = 0;
es->err_buffer[es->top] = ERR_PACK(lib, func, reason);
es->err_file[es->top] = file;
es->err_line[es->top] = line;
err_clear_data(es, es->top);
}
void ERR_clear_error(void)
{
int i;
ERR_STATE *es;
es = ERR_get_state();
for (i = 0; i < ERR_NUM_ERRORS; i++) {
err_clear(es, i);
}
es->top = es->bottom = 0;
}
unsigned long ERR_get_error(void)
{
return (get_error_values(1, 0, NULL, NULL, NULL, NULL));
}
unsigned long ERR_get_error_line(const char **file, int *line)
{
return (get_error_values(1, 0, file, line, NULL, NULL));
}
unsigned long ERR_get_error_line_data(const char **file, int *line,
const char **data, int *flags)
{
return (get_error_values(1, 0, file, line, data, flags));
}
unsigned long ERR_peek_error(void)
{
return (get_error_values(0, 0, NULL, NULL, NULL, NULL));
}
unsigned long ERR_peek_error_line(const char **file, int *line)
{
return (get_error_values(0, 0, file, line, NULL, NULL));
}
unsigned long ERR_peek_error_line_data(const char **file, int *line,
const char **data, int *flags)
{
return (get_error_values(0, 0, file, line, data, flags));
}
unsigned long ERR_peek_last_error(void)
{
return (get_error_values(0, 1, NULL, NULL, NULL, NULL));
}
unsigned long ERR_peek_last_error_line(const char **file, int *line)
{
return (get_error_values(0, 1, file, line, NULL, NULL));
}
unsigned long ERR_peek_last_error_line_data(const char **file, int *line,
const char **data, int *flags)
{
return (get_error_values(0, 1, file, line, data, flags));
}
static unsigned long get_error_values(int inc, int top, const char **file,
int *line, const char **data,
int *flags)
{
int i = 0;
ERR_STATE *es;
unsigned long ret;
es = ERR_get_state();
if (inc && top) {
if (file)
*file = "";
if (line)
*line = 0;
if (data)
*data = "";
if (flags)
*flags = 0;
return ERR_R_INTERNAL_ERROR;
}
if (es->bottom == es->top)
return 0;
if (top)
i = es->top;
else
i = (es->bottom + 1) % ERR_NUM_ERRORS;
ret = es->err_buffer[i];
if (inc) {
es->bottom = i;
es->err_buffer[i] = 0;
}
if ((file != NULL) && (line != NULL)) {
if (es->err_file[i] == NULL) {
*file = "NA";
if (line != NULL)
*line = 0;
} else {
*file = es->err_file[i];
if (line != NULL)
*line = es->err_line[i];
}
}
if (data == NULL) {
if (inc) {
err_clear_data(es, i);
}
} else {
if (es->err_data[i] == NULL) {
*data = "";
if (flags != NULL)
*flags = 0;
} else {
*data = es->err_data[i];
if (flags != NULL)
*flags = es->err_data_flags[i];
}
}
return ret;
}
void ERR_error_string_n(unsigned long e, char *buf, size_t len)
{
char lsbuf[64], fsbuf[64], rsbuf[64];
const char *ls, *fs, *rs;
unsigned long l, f, r;
l = ERR_GET_LIB(e);
f = ERR_GET_FUNC(e);
r = ERR_GET_REASON(e);
ls = ERR_lib_error_string(e);
fs = ERR_func_error_string(e);
rs = ERR_reason_error_string(e);
if (ls == NULL)
BIO_snprintf(lsbuf, sizeof(lsbuf), "lib(%lu)", l);
if (fs == NULL)
BIO_snprintf(fsbuf, sizeof(fsbuf), "func(%lu)", f);
if (rs == NULL)
BIO_snprintf(rsbuf, sizeof(rsbuf), "reason(%lu)", r);
BIO_snprintf(buf, len, "error:%08lX:%s:%s:%s", e, ls ? ls : lsbuf,
fs ? fs : fsbuf, rs ? rs : rsbuf);
if (strlen(buf) == len - 1) {
#define NUM_COLONS 4
if (len > NUM_COLONS) {
int i;
char *s = buf;
for (i = 0; i < NUM_COLONS; i++) {
char *colon = strchr(s, ':');
if (colon == NULL || colon > &buf[len - 1] - NUM_COLONS + i) {
colon = &buf[len - 1] - NUM_COLONS + i;
*colon = ':';
}
s = colon + 1;
}
}
}
}
char *ERR_error_string(unsigned long e, char *ret)
{
static char buf[256];
if (ret == NULL)
ret = buf;
ERR_error_string_n(e, ret, 256);
return ret;
}
const char *ERR_lib_error_string(unsigned long e)
{
ERR_STRING_DATA d, *p;
unsigned long l;
err_fns_check();
l = ERR_GET_LIB(e);
d.error = ERR_PACK(l, 0, 0);
p = ERRFN(err_get_item) (&d);
return ((p == NULL) ? NULL : p->string);
}
const char *ERR_func_error_string(unsigned long e)
{
ERR_STRING_DATA d, *p;
unsigned long l, f;
err_fns_check();
l = ERR_GET_LIB(e);
f = ERR_GET_FUNC(e);
d.error = ERR_PACK(l, f, 0);
p = ERRFN(err_get_item) (&d);
return ((p == NULL) ? NULL : p->string);
}
const char *ERR_reason_error_string(unsigned long e)
{
ERR_STRING_DATA d, *p = NULL;
unsigned long l, r;
err_fns_check();
l = ERR_GET_LIB(e);
r = ERR_GET_REASON(e);
d.error = ERR_PACK(l, 0, r);
p = ERRFN(err_get_item) (&d);
if (!p) {
d.error = ERR_PACK(0, 0, r);
p = ERRFN(err_get_item) (&d);
}
return ((p == NULL) ? NULL : p->string);
}
void ERR_remove_thread_state(const CRYPTO_THREADID *id)
{
ERR_STATE tmp;
if (id)
CRYPTO_THREADID_cpy(&tmp.tid, id);
else
CRYPTO_THREADID_current(&tmp.tid);
err_fns_check();
ERRFN(thread_del_item) (&tmp);
}
void ERR_remove_state(unsigned long pid)
{
ERR_remove_thread_state(NULL);
}
ERR_STATE *ERR_get_state(void)
{
static ERR_STATE fallback;
ERR_STATE *ret, tmp, *tmpp = NULL;
int i;
CRYPTO_THREADID tid;
err_fns_check();
CRYPTO_THREADID_current(&tid);
CRYPTO_THREADID_cpy(&tmp.tid, &tid);
ret = ERRFN(thread_get_item) (&tmp);
if (ret == NULL) {
ret = (ERR_STATE *)OPENSSL_malloc(sizeof(ERR_STATE));
if (ret == NULL)
return (&fallback);
CRYPTO_THREADID_cpy(&ret->tid, &tid);
ret->top = 0;
ret->bottom = 0;
for (i = 0; i < ERR_NUM_ERRORS; i++) {
ret->err_data[i] = NULL;
ret->err_data_flags[i] = 0;
}
tmpp = ERRFN(thread_set_item) (ret);
if (ERRFN(thread_get_item) (ret) != ret) {
ERR_STATE_free(ret);
return (&fallback);
}
if (tmpp)
ERR_STATE_free(tmpp);
}
return ret;
}
int ERR_get_next_error_library(void)
{
err_fns_check();
return ERRFN(get_next_lib) ();
}
void ERR_set_error_data(char *data, int flags)
{
ERR_STATE *es;
int i;
es = ERR_get_state();
i = es->top;
if (i == 0)
i = ERR_NUM_ERRORS - 1;
err_clear_data(es, i);
es->err_data[i] = data;
es->err_data_flags[i] = flags;
}
void ERR_add_error_data(int num, ...)
{
va_list args;
va_start(args, num);
ERR_add_error_vdata(num, args);
va_end(args);
}
void ERR_add_error_vdata(int num, va_list args)
{
int i, n, s;
char *str, *p, *a;
s = 80;
str = OPENSSL_malloc(s + 1);
if (str == NULL)
return;
str[0] = '\0';
n = 0;
for (i = 0; i < num; i++) {
a = va_arg(args, char *);
if (a != NULL) {
n += strlen(a);
if (n > s) {
s = n + 20;
p = OPENSSL_realloc(str, s + 1);
if (p == NULL) {
OPENSSL_free(str);
return;
} else
str = p;
}
BUF_strlcat(str, a, (size_t)s + 1);
}
}
ERR_set_error_data(str, ERR_TXT_MALLOCED | ERR_TXT_STRING);
}
int ERR_set_mark(void)
{
ERR_STATE *es;
es = ERR_get_state();
if (es->bottom == es->top)
return 0;
es->err_flags[es->top] |= ERR_FLAG_MARK;
return 1;
}
int ERR_pop_to_mark(void)
{
ERR_STATE *es;
es = ERR_get_state();
while (es->bottom != es->top
&& (es->err_flags[es->top] & ERR_FLAG_MARK) == 0) {
err_clear(es, es->top);
es->top -= 1;
if (es->top == -1)
es->top = ERR_NUM_ERRORS - 1;
}
if (es->bottom == es->top)
return 0;
es->err_flags[es->top] &= ~ERR_FLAG_MARK;
return 1;
}
