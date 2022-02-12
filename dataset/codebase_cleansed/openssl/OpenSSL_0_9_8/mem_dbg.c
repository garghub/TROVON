static void app_info_free(APP_INFO *inf)
{
if (--(inf->references) <= 0)
{
if (inf->next != NULL)
{
app_info_free(inf->next);
}
OPENSSL_free(inf);
}
}
int CRYPTO_mem_ctrl(int mode)
{
int ret=mh_mode;
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
switch (mode)
{
case CRYPTO_MEM_CHECK_ON:
mh_mode = CRYPTO_MEM_CHECK_ON|CRYPTO_MEM_CHECK_ENABLE;
num_disable = 0;
break;
case CRYPTO_MEM_CHECK_OFF:
mh_mode = 0;
num_disable = 0;
break;
case CRYPTO_MEM_CHECK_DISABLE:
if (mh_mode & CRYPTO_MEM_CHECK_ON)
{
if (!num_disable || (disabling_thread != CRYPTO_thread_id()))
{
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC2);
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
mh_mode &= ~CRYPTO_MEM_CHECK_ENABLE;
disabling_thread=CRYPTO_thread_id();
}
num_disable++;
}
break;
case CRYPTO_MEM_CHECK_ENABLE:
if (mh_mode & CRYPTO_MEM_CHECK_ON)
{
if (num_disable)
{
num_disable--;
if (num_disable == 0)
{
mh_mode|=CRYPTO_MEM_CHECK_ENABLE;
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC2);
}
}
}
break;
default:
break;
}
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
return(ret);
}
int CRYPTO_is_mem_check_on(void)
{
int ret = 0;
if (mh_mode & CRYPTO_MEM_CHECK_ON)
{
CRYPTO_r_lock(CRYPTO_LOCK_MALLOC);
ret = (mh_mode & CRYPTO_MEM_CHECK_ENABLE)
|| (disabling_thread != CRYPTO_thread_id());
CRYPTO_r_unlock(CRYPTO_LOCK_MALLOC);
}
return(ret);
}
void CRYPTO_dbg_set_options(long bits)
{
options = bits;
}
long CRYPTO_dbg_get_options(void)
{
return options;
}
static int mem_cmp(const void *a_void, const void *b_void)
{
#ifdef _WIN64
const char *a=(const char *)((const MEM *)a_void)->addr,
*b=(const char *)((const MEM *)b_void)->addr;
if (a==b) return 0;
else if (a>b) return 1;
else return -1;
#else
return((const char *)((const MEM *)a_void)->addr
- (const char *)((const MEM *)b_void)->addr);
#endif
}
static unsigned long mem_hash(const void *a_void)
{
unsigned long ret;
ret=(unsigned long)((const MEM *)a_void)->addr;
ret=ret*17851+(ret>>14)*7+(ret>>4)*251;
return(ret);
}
static int app_info_cmp(const void *a_void, const void *b_void)
{
return(((const APP_INFO *)a_void)->thread
!= ((const APP_INFO *)b_void)->thread);
}
static unsigned long app_info_hash(const void *a_void)
{
unsigned long ret;
ret=(unsigned long)((const APP_INFO *)a_void)->thread;
ret=ret*17851+(ret>>14)*7+(ret>>4)*251;
return(ret);
}
static APP_INFO *pop_info(void)
{
APP_INFO tmp;
APP_INFO *ret = NULL;
if (amih != NULL)
{
tmp.thread=CRYPTO_thread_id();
if ((ret=(APP_INFO *)lh_delete(amih,&tmp)) != NULL)
{
APP_INFO *next=ret->next;
if (next != NULL)
{
next->references++;
lh_insert(amih,(char *)next);
}
#ifdef LEVITTE_DEBUG_MEM
if (ret->thread != tmp.thread)
{
fprintf(stderr, "pop_info(): deleted info has other thread ID (%lu) than the current thread (%lu)!!!!\n",
ret->thread, tmp.thread);
abort();
}
#endif
if (--(ret->references) <= 0)
{
ret->next = NULL;
if (next != NULL)
next->references--;
OPENSSL_free(ret);
}
}
}
return(ret);
}
int CRYPTO_push_info_(const char *info, const char *file, int line)
{
APP_INFO *ami, *amim;
int ret=0;
if (is_MemCheck_on())
{
MemCheck_off();
if ((ami = (APP_INFO *)OPENSSL_malloc(sizeof(APP_INFO))) == NULL)
{
ret=0;
goto err;
}
if (amih == NULL)
{
if ((amih=lh_new(app_info_hash, app_info_cmp)) == NULL)
{
OPENSSL_free(ami);
ret=0;
goto err;
}
}
ami->thread=CRYPTO_thread_id();
ami->file=file;
ami->line=line;
ami->info=info;
ami->references=1;
ami->next=NULL;
if ((amim=(APP_INFO *)lh_insert(amih,(char *)ami)) != NULL)
{
#ifdef LEVITTE_DEBUG_MEM
if (ami->thread != amim->thread)
{
fprintf(stderr, "CRYPTO_push_info(): previous info has other thread ID (%lu) than the current thread (%lu)!!!!\n",
amim->thread, ami->thread);
abort();
}
#endif
ami->next=amim;
}
err:
MemCheck_on();
}
return(ret);
}
int CRYPTO_pop_info(void)
{
int ret=0;
if (is_MemCheck_on())
{
MemCheck_off();
ret=(pop_info() != NULL);
MemCheck_on();
}
return(ret);
}
int CRYPTO_remove_all_info(void)
{
int ret=0;
if (is_MemCheck_on())
{
MemCheck_off();
while(pop_info() != NULL)
ret++;
MemCheck_on();
}
return(ret);
}
void CRYPTO_dbg_malloc(void *addr, int num, const char *file, int line,
int before_p)
{
MEM *m,*mm;
APP_INFO tmp,*amim;
switch(before_p & 127)
{
case 0:
break;
case 1:
if (addr == NULL)
break;
if (is_MemCheck_on())
{
MemCheck_off();
if ((m=(MEM *)OPENSSL_malloc(sizeof(MEM))) == NULL)
{
OPENSSL_free(addr);
MemCheck_on();
return;
}
if (mh == NULL)
{
if ((mh=lh_new(mem_hash, mem_cmp)) == NULL)
{
OPENSSL_free(addr);
OPENSSL_free(m);
addr=NULL;
goto err;
}
}
m->addr=addr;
m->file=file;
m->line=line;
m->num=num;
if (options & V_CRYPTO_MDEBUG_THREAD)
m->thread=CRYPTO_thread_id();
else
m->thread=0;
if (order == break_order_num)
{
m->order=order;
}
m->order=order++;
#ifdef LEVITTE_DEBUG_MEM
fprintf(stderr, "LEVITTE_DEBUG_MEM: [%5d] %c 0x%p (%d)\n",
m->order,
(before_p & 128) ? '*' : '+',
m->addr, m->num);
#endif
if (options & V_CRYPTO_MDEBUG_TIME)
m->time=time(NULL);
else
m->time=0;
tmp.thread=CRYPTO_thread_id();
m->app_info=NULL;
if (amih != NULL
&& (amim=(APP_INFO *)lh_retrieve(amih,(char *)&tmp)) != NULL)
{
m->app_info = amim;
amim->references++;
}
if ((mm=(MEM *)lh_insert(mh,(char *)m)) != NULL)
{
if (mm->app_info != NULL)
{
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
MEM m,*mp;
switch(before_p)
{
case 0:
if (addr == NULL)
break;
if (is_MemCheck_on() && (mh != NULL))
{
MemCheck_off();
m.addr=addr;
mp=(MEM *)lh_delete(mh,(char *)&m);
if (mp != NULL)
{
#ifdef LEVITTE_DEBUG_MEM
fprintf(stderr, "LEVITTE_DEBUG_MEM: [%5d] - 0x%p (%d)\n",
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
MEM m,*mp;
#ifdef LEVITTE_DEBUG_MEM
fprintf(stderr, "LEVITTE_DEBUG_MEM: --> CRYPTO_dbg_malloc(addr1 = %p, addr2 = %p, num = %d, file = \"%s\", line = %d, before_p = %d)\n",
addr1, addr2, num, file, line, before_p);
#endif
switch(before_p)
{
case 0:
break;
case 1:
if (addr2 == NULL)
break;
if (addr1 == NULL)
{
CRYPTO_dbg_malloc(addr2, num, file, line, 128 | before_p);
break;
}
if (is_MemCheck_on())
{
MemCheck_off();
m.addr=addr1;
mp=(MEM *)lh_delete(mh,(char *)&m);
if (mp != NULL)
{
#ifdef LEVITTE_DEBUG_MEM
fprintf(stderr, "LEVITTE_DEBUG_MEM: [%5d] * 0x%p (%d) -> 0x%p (%d)\n",
mp->order,
mp->addr, mp->num,
addr2, num);
#endif
mp->addr=addr2;
mp->num=num;
lh_insert(mh,(char *)mp);
}
MemCheck_on();
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
unsigned long ti;
#define BUF_REMAIN (sizeof buf - (size_t)(bufp - buf))
if(m->addr == (char *)l->bio)
return;
if (options & V_CRYPTO_MDEBUG_TIME)
{
lcl = localtime(&m->time);
BIO_snprintf(bufp, BUF_REMAIN, "[%02d:%02d:%02d] ",
lcl->tm_hour,lcl->tm_min,lcl->tm_sec);
bufp += strlen(bufp);
}
BIO_snprintf(bufp, BUF_REMAIN, "%5lu file=%s, line=%d, ",
m->order,m->file,m->line);
bufp += strlen(bufp);
if (options & V_CRYPTO_MDEBUG_THREAD)
{
BIO_snprintf(bufp, BUF_REMAIN, "thread=%lu, ", m->thread);
bufp += strlen(bufp);
}
BIO_snprintf(bufp, BUF_REMAIN, "number=%d, address=%08lX\n",
m->num,(unsigned long)m->addr);
bufp += strlen(bufp);
BIO_puts(l->bio,buf);
l->chunks++;
l->bytes+=m->num;
amip=m->app_info;
ami_cnt=0;
if (!amip)
return;
ti=amip->thread;
do
{
int buf_len;
int info_len;
ami_cnt++;
memset(buf,'>',ami_cnt);
BIO_snprintf(buf + ami_cnt, sizeof buf - ami_cnt,
" thread=%lu, file=%s, line=%d, info=\"",
amip->thread, amip->file, amip->line);
buf_len=strlen(buf);
info_len=strlen(amip->info);
if (128 - buf_len - 3 < info_len)
{
memcpy(buf + buf_len, amip->info, 128 - buf_len - 3);
buf_len = 128 - 3;
}
else
{
BUF_strlcpy(buf + buf_len, amip->info,
sizeof buf - buf_len);
buf_len = strlen(buf);
}
BIO_snprintf(buf + buf_len, sizeof buf - buf_len, "\"\n");
BIO_puts(l->bio,buf);
amip = amip->next;
}
while(amip && amip->thread == ti);
#ifdef LEVITTE_DEBUG_MEM
if (amip)
{
fprintf(stderr, "Thread switch detected in backtrace!!!!\n");
abort();
}
#endif
}
static void cb_leak(const MEM *m, CRYPTO_MEM_LEAK_CB **cb)
{
(**cb)(m->order,m->file,m->line,m->num,m->addr);
}
