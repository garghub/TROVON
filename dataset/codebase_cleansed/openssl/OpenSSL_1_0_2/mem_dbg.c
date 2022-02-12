static void app_info_free(APP_INFO *inf)
{
if (--(inf->references) <= 0) {
if (inf->next != NULL) {
app_info_free(inf->next);
}
OPENSSL_free(inf);
}
}
int CRYPTO_mem_ctrl(int mode)
{
int ret = mh_mode;
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
switch (mode) {
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
CRYPTO_THREADID cur;
CRYPTO_THREADID_current(&cur);
if (!num_disable
|| CRYPTO_THREADID_cmp(&disabling_threadid, &cur)) {
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC2);
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
mh_mode &= ~CRYPTO_MEM_CHECK_ENABLE;
CRYPTO_THREADID_cpy(&disabling_threadid, &cur);
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
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC2);
}
}
}
break;
default:
break;
}
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
return (ret);
}
int CRYPTO_is_mem_check_on(void)
{
int ret = 0;
if (mh_mode & CRYPTO_MEM_CHECK_ON) {
CRYPTO_THREADID cur;
CRYPTO_THREADID_current(&cur);
CRYPTO_r_lock(CRYPTO_LOCK_MALLOC);
ret = (mh_mode & CRYPTO_MEM_CHECK_ENABLE)
|| CRYPTO_THREADID_cmp(&disabling_threadid, &cur);
CRYPTO_r_unlock(CRYPTO_LOCK_MALLOC);
}
return (ret);
}
void CRYPTO_dbg_set_options(long bits)
{
options = bits;
}
long CRYPTO_dbg_get_options(void)
{
return options;
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
int CRYPTO_pop_info(void)
{
int ret = 0;
if (is_MemCheck_on()) {
MemCheck_off();
ret = (pop_info() != NULL);
MemCheck_on();
}
return (ret);
}
int CRYPTO_remove_all_info(void)
{
int ret = 0;
if (is_MemCheck_on()) {
MemCheck_off();
while (pop_info() != NULL)
ret++;
MemCheck_on();
}
return (ret);
}
void CRYPTO_dbg_malloc(void *addr, int num, const char *file, int line,
int before_p)
{
MEM *m, *mm;
APP_INFO tmp, *amim;
switch (before_p & 127) {
case 0:
break;
case 1:
if (addr == NULL)
break;
if (is_MemCheck_on()) {
MemCheck_off();
if ((m = (MEM *)OPENSSL_malloc(sizeof(MEM))) == NULL) {
OPENSSL_free(addr);
MemCheck_on();
return;
}
if (mh == NULL) {
if ((mh = lh_MEM_new()) == NULL) {
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
if (options & V_CRYPTO_MDEBUG_THREAD)
CRYPTO_THREADID_current(&m->threadid);
else
memset(&m->threadid, 0, sizeof(m->threadid));
if (order == break_order_num) {
m->order = order;
}
m->order = order++;
#ifdef LEVITTE_DEBUG_MEM
fprintf(stderr, "LEVITTE_DEBUG_MEM: [%5ld] %c 0x%p (%d)\n",
m->order, (before_p & 128) ? '*' : '+', m->addr, m->num);
#endif
if (options & V_CRYPTO_MDEBUG_TIME)
m->time = time(NULL);
else
m->time = 0;
CRYPTO_THREADID_current(&tmp.threadid);
m->app_info = NULL;
if (amih != NULL
&& (amim = lh_APP_INFO_retrieve(amih, &tmp)) != NULL) {
m->app_info = amim;
amim->references++;
}
if ((mm = lh_MEM_insert(mh, m)) != NULL) {
if (mm->app_info != NULL) {
mm->app_info->references--;
}
OPENSSL_free(mm);
}
err:
MemCheck_on();
}
break;
}
return;
}
void CRYPTO_dbg_free(void *addr, int before_p)
{
MEM m, *mp;
switch (before_p) {
case 0:
if (addr == NULL)
break;
if (is_MemCheck_on() && (mh != NULL)) {
MemCheck_off();
m.addr = addr;
mp = lh_MEM_delete(mh, &m);
if (mp != NULL) {
#ifdef LEVITTE_DEBUG_MEM
fprintf(stderr, "LEVITTE_DEBUG_MEM: [%5ld] - 0x%p (%d)\n",
mp->order, mp->addr, mp->num);
#endif
if (mp->app_info != NULL)
app_info_free(mp->app_info);
OPENSSL_free(mp);
}
MemCheck_on();
}
break;
case 1:
break;
}
}
void CRYPTO_dbg_realloc(void *addr1, void *addr2, int num,
const char *file, int line, int before_p)
{
MEM m, *mp;
#ifdef LEVITTE_DEBUG_MEM
fprintf(stderr,
"LEVITTE_DEBUG_MEM: --> CRYPTO_dbg_malloc(addr1 = %p, addr2 = %p, num = %d, file = \"%s\", line = %d, before_p = %d)\n",
addr1, addr2, num, file, line, before_p);
#endif
switch (before_p) {
case 0:
break;
case 1:
if (addr2 == NULL)
break;
if (addr1 == NULL) {
CRYPTO_dbg_malloc(addr2, num, file, line, 128 | before_p);
break;
}
if (is_MemCheck_on()) {
MemCheck_off();
m.addr = addr1;
mp = lh_MEM_delete(mh, &m);
if (mp != NULL) {
#ifdef LEVITTE_DEBUG_MEM
fprintf(stderr,
"LEVITTE_DEBUG_MEM: [%5ld] * 0x%p (%d) -> 0x%p (%d)\n",
mp->order, mp->addr, mp->num, addr2, num);
#endif
mp->addr = addr2;
mp->num = num;
(void)lh_MEM_insert(mh, mp);
}
MemCheck_on();
}
break;
}
return;
}
static void print_leak_doall_arg(const MEM *m, MEM_LEAK *l)
{
char buf[1024];
char *bufp = buf;
APP_INFO *amip;
int ami_cnt;
struct tm *lcl = NULL;
CRYPTO_THREADID ti;
#define BUF_REMAIN (sizeof buf - (size_t)(bufp - buf))
if (m->addr == (char *)l->bio)
return;
if (options & V_CRYPTO_MDEBUG_TIME) {
lcl = localtime(&m->time);
BIO_snprintf(bufp, BUF_REMAIN, "[%02d:%02d:%02d] ",
lcl->tm_hour, lcl->tm_min, lcl->tm_sec);
bufp += strlen(bufp);
}
BIO_snprintf(bufp, BUF_REMAIN, "%5lu file=%s, line=%d, ",
m->order, m->file, m->line);
bufp += strlen(bufp);
if (options & V_CRYPTO_MDEBUG_THREAD) {
BIO_snprintf(bufp, BUF_REMAIN, "thread=%lu, ",
CRYPTO_THREADID_hash(&m->threadid));
bufp += strlen(bufp);
}
BIO_snprintf(bufp, BUF_REMAIN, "number=%d, address=%08lX\n",
m->num, (unsigned long)m->addr);
bufp += strlen(bufp);
BIO_puts(l->bio, buf);
l->chunks++;
l->bytes += m->num;
amip = m->app_info;
ami_cnt = 0;
if (!amip)
return;
CRYPTO_THREADID_cpy(&ti, &amip->threadid);
do {
int buf_len;
int info_len;
ami_cnt++;
memset(buf, '>', ami_cnt);
BIO_snprintf(buf + ami_cnt, sizeof buf - ami_cnt,
" thread=%lu, file=%s, line=%d, info=\"",
CRYPTO_THREADID_hash(&amip->threadid), amip->file,
amip->line);
buf_len = strlen(buf);
info_len = strlen(amip->info);
if (128 - buf_len - 3 < info_len) {
memcpy(buf + buf_len, amip->info, 128 - buf_len - 3);
buf_len = 128 - 3;
} else {
BUF_strlcpy(buf + buf_len, amip->info, sizeof buf - buf_len);
buf_len = strlen(buf);
}
BIO_snprintf(buf + buf_len, sizeof buf - buf_len, "\"\n");
BIO_puts(l->bio, buf);
amip = amip->next;
}
while (amip && !CRYPTO_THREADID_cmp(&amip->threadid, &ti));
#ifdef LEVITTE_DEBUG_MEM
if (amip) {
fprintf(stderr, "Thread switch detected in backtrace!!!!\n");
abort();
}
#endif
}
static void cb_leak_doall_arg(const MEM *m, PCRYPTO_MEM_LEAK_CB *cb)
{
(*cb) (m->order, m->file, m->line, m->num, m->addr);
}
