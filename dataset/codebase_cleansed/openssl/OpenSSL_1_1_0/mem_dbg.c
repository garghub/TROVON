static void app_info_free(APP_INFO *inf)
{
if (!inf)
return;
if (--(inf->references) <= 0) {
app_info_free(inf->next);
OPENSSL_free(inf);
}
}
int CRYPTO_mem_ctrl(int mode)
{
#ifdef OPENSSL_NO_CRYPTO_MDEBUG
return mode - mode;
#else
int ret = mh_mode;
if (!RUN_ONCE(&memdbg_init, do_memdbg_init))
return -1;
CRYPTO_THREAD_write_lock(malloc_lock);
switch (mode) {
default:
break;
case CRYPTO_MEM_CHECK_ON:
mh_mode = CRYPTO_MEM_CHECK_ON | CRYPTO_MEM_CHECK_ENABLE;
num_disable = 0;
break;
case CRYPTO_MEM_CHECK_OFF:
mh_mode = 0;
num_disable = 0;
break;
case CRYPTO_MEM_CHECK_DISABLE:
if (mh_mode & CRYPTO_MEM_CHECK_ON) {
CRYPTO_THREAD_ID cur = CRYPTO_THREAD_get_current_id();
if (!num_disable
|| !CRYPTO_THREAD_compare_id(disabling_threadid, cur)) {
CRYPTO_THREAD_unlock(malloc_lock);
CRYPTO_THREAD_write_lock(long_malloc_lock);
CRYPTO_THREAD_write_lock(malloc_lock);
mh_mode &= ~CRYPTO_MEM_CHECK_ENABLE;
disabling_threadid = cur;
}
num_disable++;
}
break;
case CRYPTO_MEM_CHECK_ENABLE:
if (mh_mode & CRYPTO_MEM_CHECK_ON) {
if (num_disable) {
num_disable--;
if (num_disable == 0) {
mh_mode |= CRYPTO_MEM_CHECK_ENABLE;
CRYPTO_THREAD_unlock(long_malloc_lock);
}
}
}
break;
}
CRYPTO_THREAD_unlock(malloc_lock);
return (ret);
#endif
}
static int mem_check_on(void)
{
int ret = 0;
CRYPTO_THREAD_ID cur;
if (mh_mode & CRYPTO_MEM_CHECK_ON) {
if (!RUN_ONCE(&memdbg_init, do_memdbg_init))
return 0;
cur = CRYPTO_THREAD_get_current_id();
CRYPTO_THREAD_read_lock(malloc_lock);
ret = (mh_mode & CRYPTO_MEM_CHECK_ENABLE)
|| !CRYPTO_THREAD_compare_id(disabling_threadid, cur);
CRYPTO_THREAD_unlock(malloc_lock);
}
return (ret);
}
static int mem_cmp(const MEM *a, const MEM *b)
{
#ifdef _WIN64
const char *ap = (const char *)a->addr, *bp = (const char *)b->addr;
if (ap == bp)
return 0;
else if (ap > bp)
return 1;
else
return -1;
#else
return (const char *)a->addr - (const char *)b->addr;
#endif
}
static unsigned long mem_hash(const MEM *a)
{
size_t ret;
ret = (size_t)a->addr;
ret = ret * 17851 + (ret >> 14) * 7 + (ret >> 4) * 251;
return (ret);
}
static int pop_info(void)
{
APP_INFO *current = NULL;
if (!RUN_ONCE(&memdbg_init, do_memdbg_init))
return 0;
current = (APP_INFO *)CRYPTO_THREAD_get_local(&appinfokey);
if (current != NULL) {
APP_INFO *next = current->next;
if (next != NULL) {
next->references++;
CRYPTO_THREAD_set_local(&appinfokey, next);
} else {
CRYPTO_THREAD_set_local(&appinfokey, NULL);
}
if (--(current->references) <= 0) {
current->next = NULL;
if (next != NULL)
next->references--;
OPENSSL_free(current);
}
return 1;
}
return 0;
}
int CRYPTO_mem_debug_push(const char *info, const char *file, int line)
{
APP_INFO *ami, *amim;
int ret = 0;
if (mem_check_on()) {
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_DISABLE);
if (!RUN_ONCE(&memdbg_init, do_memdbg_init)
|| (ami = OPENSSL_malloc(sizeof(*ami))) == NULL)
goto err;
ami->threadid = CRYPTO_THREAD_get_current_id();
ami->file = file;
ami->line = line;
ami->info = info;
ami->references = 1;
ami->next = NULL;
amim = (APP_INFO *)CRYPTO_THREAD_get_local(&appinfokey);
CRYPTO_THREAD_set_local(&appinfokey, ami);
if (amim != NULL)
ami->next = amim;
ret = 1;
err:
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
}
return (ret);
}
int CRYPTO_mem_debug_pop(void)
{
int ret = 0;
if (mem_check_on()) {
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_DISABLE);
ret = pop_info();
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
}
return (ret);
}
void CRYPTO_mem_debug_malloc(void *addr, size_t num, int before_p,
const char *file, int line)
{
MEM *m, *mm;
APP_INFO *amim;
switch (before_p & 127) {
case 0:
break;
case 1:
if (addr == NULL)
break;
if (mem_check_on()) {
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_DISABLE);
if (!RUN_ONCE(&memdbg_init, do_memdbg_init)
|| (m = OPENSSL_malloc(sizeof(*m))) == NULL) {
OPENSSL_free(addr);
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
return;
}
if (mh == NULL) {
if ((mh = lh_MEM_new(mem_hash, mem_cmp)) == NULL) {
OPENSSL_free(addr);
OPENSSL_free(m);
addr = NULL;
goto err;
}
}
m->addr = addr;
m->file = file;
m->line = line;
m->num = num;
m->threadid = CRYPTO_THREAD_get_current_id();
if (order == break_order_num) {
m->order = order;
}
m->order = order++;
# ifndef OPENSSL_NO_CRYPTO_MDEBUG_BACKTRACE
m->array_siz = backtrace(m->array, OSSL_NELEM(m->array));
# endif
m->time = time(NULL);
amim = (APP_INFO *)CRYPTO_THREAD_get_local(&appinfokey);
m->app_info = amim;
if (amim != NULL)
amim->references++;
if ((mm = lh_MEM_insert(mh, m)) != NULL) {
if (mm->app_info != NULL) {
mm->app_info->references--;
}
OPENSSL_free(mm);
}
err:
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
}
break;
}
return;
}
void CRYPTO_mem_debug_free(void *addr, int before_p,
const char *file, int line)
{
MEM m, *mp;
switch (before_p) {
case 0:
if (addr == NULL)
break;
if (mem_check_on() && (mh != NULL)) {
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_DISABLE);
m.addr = addr;
mp = lh_MEM_delete(mh, &m);
if (mp != NULL) {
app_info_free(mp->app_info);
OPENSSL_free(mp);
}
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
}
break;
case 1:
break;
}
}
void CRYPTO_mem_debug_realloc(void *addr1, void *addr2, size_t num,
int before_p, const char *file, int line)
{
MEM m, *mp;
switch (before_p) {
case 0:
break;
case 1:
if (addr2 == NULL)
break;
if (addr1 == NULL) {
CRYPTO_mem_debug_malloc(addr2, num, 128 | before_p, file, line);
break;
}
if (mem_check_on()) {
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_DISABLE);
m.addr = addr1;
mp = lh_MEM_delete(mh, &m);
if (mp != NULL) {
mp->addr = addr2;
mp->num = num;
#ifndef OPENSSL_NO_CRYPTO_MDEBUG_BACKTRACE
mp->array_siz = backtrace(mp->array, OSSL_NELEM(mp->array));
#endif
(void)lh_MEM_insert(mh, mp);
}
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
}
break;
}
return;
}
static void print_leak(const MEM *m, MEM_LEAK *l)
{
char buf[1024];
char *bufp = buf;
APP_INFO *amip;
int ami_cnt;
struct tm *lcl = NULL;
union {
CRYPTO_THREAD_ID tid;
unsigned long ltid;
} tid;
CRYPTO_THREAD_ID ti;
#define BUF_REMAIN (sizeof buf - (size_t)(bufp - buf))
lcl = localtime(&m->time);
BIO_snprintf(bufp, BUF_REMAIN, "[%02d:%02d:%02d] ",
lcl->tm_hour, lcl->tm_min, lcl->tm_sec);
bufp += strlen(bufp);
BIO_snprintf(bufp, BUF_REMAIN, "%5lu file=%s, line=%d, ",
m->order, m->file, m->line);
bufp += strlen(bufp);
tid.ltid = 0;
tid.tid = m->threadid;
BIO_snprintf(bufp, BUF_REMAIN, "thread=%lu, ", tid.ltid);
bufp += strlen(bufp);
BIO_snprintf(bufp, BUF_REMAIN, "number=%d, address=%p\n",
m->num, m->addr);
bufp += strlen(bufp);
BIO_puts(l->bio, buf);
l->chunks++;
l->bytes += m->num;
amip = m->app_info;
ami_cnt = 0;
if (amip) {
ti = amip->threadid;
do {
int buf_len;
int info_len;
ami_cnt++;
memset(buf, '>', ami_cnt);
tid.ltid = 0;
tid.tid = amip->threadid;
BIO_snprintf(buf + ami_cnt, sizeof buf - ami_cnt,
" thread=%lu, file=%s, line=%d, info=\"",
tid.ltid, amip->file,
amip->line);
buf_len = strlen(buf);
info_len = strlen(amip->info);
if (128 - buf_len - 3 < info_len) {
memcpy(buf + buf_len, amip->info, 128 - buf_len - 3);
buf_len = 128 - 3;
} else {
OPENSSL_strlcpy(buf + buf_len, amip->info, sizeof buf - buf_len);
buf_len = strlen(buf);
}
BIO_snprintf(buf + buf_len, sizeof buf - buf_len, "\"\n");
BIO_puts(l->bio, buf);
amip = amip->next;
}
while (amip && CRYPTO_THREAD_compare_id(amip->threadid, ti));
}
#ifndef OPENSSL_NO_CRYPTO_MDEBUG_BACKTRACE
{
size_t i;
char **strings = backtrace_symbols(m->array, m->array_siz);
for (i = 0; i < m->array_siz; i++)
fprintf(stderr, "##> %s\n", strings[i]);
free(strings);
}
#endif
}
int CRYPTO_mem_leaks(BIO *b)
{
MEM_LEAK ml;
bio_free_ex_data(b);
OPENSSL_cleanup();
if (!RUN_ONCE(&memdbg_init, do_memdbg_init))
return -1;
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_DISABLE);
ml.bio = b;
ml.bytes = 0;
ml.chunks = 0;
if (mh != NULL)
lh_MEM_doall_MEM_LEAK(mh, print_leak, &ml);
if (ml.chunks != 0) {
BIO_printf(b, "%ld bytes leaked in %d chunks\n", ml.bytes, ml.chunks);
} else {
int old_mh_mode;
CRYPTO_THREAD_write_lock(malloc_lock);
old_mh_mode = mh_mode;
mh_mode = CRYPTO_MEM_CHECK_OFF;
lh_MEM_free(mh);
mh = NULL;
mh_mode = old_mh_mode;
CRYPTO_THREAD_unlock(malloc_lock);
}
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_OFF);
CRYPTO_THREAD_cleanup_local(&appinfokey);
CRYPTO_THREAD_lock_free(malloc_lock);
CRYPTO_THREAD_lock_free(long_malloc_lock);
malloc_lock = NULL;
long_malloc_lock = NULL;
return ml.chunks == 0 ? 1 : 0;
}
int CRYPTO_mem_leaks_fp(FILE *fp)
{
BIO *b;
int ret;
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_DISABLE);
b = BIO_new(BIO_s_file());
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
if (b == NULL)
return -1;
BIO_set_fp(b, fp, BIO_NOCLOSE);
ret = CRYPTO_mem_leaks(b);
BIO_free(b);
return ret;
}
