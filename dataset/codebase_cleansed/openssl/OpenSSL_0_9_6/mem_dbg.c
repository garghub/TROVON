int CRYPTO_mem_ctrl(int mode)
{
int ret=mh_mode;
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
switch (mode)
{
case CRYPTO_MEM_CHECK_ON:
mh_mode = CRYPTO_MEM_CHECK_ON|CRYPTO_MEM_CHECK_ENABLE;
disabling_thread = 0;
break;
case CRYPTO_MEM_CHECK_OFF:
mh_mode = 0;
disabling_thread = 0;
break;
case CRYPTO_MEM_CHECK_DISABLE:
if (mh_mode & CRYPTO_MEM_CHECK_ON)
{
mh_mode&= ~CRYPTO_MEM_CHECK_ENABLE;
if (disabling_thread != CRYPTO_thread_id())
{
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC2);
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
disabling_thread=CRYPTO_thread_id();
}
}
break;
case CRYPTO_MEM_CHECK_ENABLE:
if (mh_mode & CRYPTO_MEM_CHECK_ON)
{
mh_mode|=CRYPTO_MEM_CHECK_ENABLE;
if (disabling_thread != 0)
{
disabling_thread=0;
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC2);
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
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
ret = (mh_mode & CRYPTO_MEM_CHECK_ENABLE)
&& disabling_thread != CRYPTO_thread_id();
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
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
static int mem_cmp(MEM *a, MEM *b)
{
return((char *)a->addr - (char *)b->addr);
}
static unsigned long mem_hash(MEM *a)
{
unsigned long ret;
ret=(unsigned long)a->addr;
ret=ret*17851+(ret>>14)*7+(ret>>4)*251;
return(ret);
}
static int app_info_cmp(APP_INFO *a, APP_INFO *b)
{
return(a->thread != b->thread);
}
static unsigned long app_info_hash(APP_INFO *a)
{
unsigned long ret;
ret=(unsigned long)a->thread;
ret=ret*17851+(ret>>14)*7+(ret>>4)*251;
return(ret);
}
static APP_INFO *pop_info()
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
#ifdef LEVITTE_DEBUG
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
if ((amih=lh_new(app_info_hash,app_info_cmp)) == NULL)
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
#ifdef LEVITTE_DEBUG
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
if ((mh=lh_new(mem_hash,mem_cmp)) == NULL)
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
#ifdef LEVITTE_DEBUG
fprintf(stderr, "LEVITTE_DEBUG: [%5d] %c 0x%p (%d)\n",
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
#ifdef LEVITTE_DEBUG
fprintf(stderr, "LEVITTE_DEBUG: [%5d] - 0x%p (%d)\n",
mp->order, mp->addr, mp->num);
#endif
if (mp->app_info != NULL)
{
mp->app_info->references--;
}
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
#ifdef LEVITTE_DEBUG
fprintf(stderr, "LEVITTE_DEBUG: --> CRYPTO_dbg_malloc(addr1 = %p, addr2 = %p, num = %d, file = \"%s\", line = %d, before_p = %d)\n",
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
#ifdef LEVITTE_DEBUG
fprintf(stderr, "LEVITTE_DEBUG: [%5d] * 0x%p (%d) -> 0x%p (%d)\n",
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
static void print_leak(MEM *m, MEM_LEAK *l)
{
char buf[1024];
char *bufp = buf;
APP_INFO *amip;
int ami_cnt;
struct tm *lcl = NULL;
unsigned long ti;
if(m->addr == (char *)l->bio)
return;
if (options & V_CRYPTO_MDEBUG_TIME)
{
lcl = localtime(&m->time);
sprintf(bufp, "[%02d:%02d:%02d] ",
lcl->tm_hour,lcl->tm_min,lcl->tm_sec);
bufp += strlen(bufp);
}
sprintf(bufp, "%5lu file=%s, line=%d, ",
m->order,m->file,m->line);
bufp += strlen(bufp);
if (options & V_CRYPTO_MDEBUG_THREAD)
{
sprintf(bufp, "thread=%lu, ", m->thread);
bufp += strlen(bufp);
}
sprintf(bufp, "number=%d, address=%08lX\n",
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
sprintf(buf + ami_cnt,
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
strcpy(buf + buf_len, amip->info);
buf_len = strlen(buf);
}
sprintf(buf + buf_len, "\"\n");
BIO_puts(l->bio,buf);
amip = amip->next;
}
while(amip && amip->thread == ti);
#ifdef LEVITTE_DEBUG
if (amip)
{
fprintf(stderr, "Thread switch detected in backtrace!!!!\n");
abort();
}
#endif
}
void CRYPTO_mem_leaks(BIO *b)
{
MEM_LEAK ml;
char buf[80];
if (mh == NULL && amih == NULL)
return;
ml.bio=b;
ml.bytes=0;
ml.chunks=0;
MemCheck_off();
if (mh != NULL)
lh_doall_arg(mh,(void (*)())print_leak,(char *)&ml);
if (ml.chunks != 0)
{
sprintf(buf,"%ld bytes leaked in %d chunks\n",
ml.bytes,ml.chunks);
BIO_puts(b,buf);
}
else
{
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
if (mh != NULL)
{
lh_free(mh);
mh = NULL;
}
if (amih != NULL)
{
if (lh_num_items(amih) == 0)
{
lh_free(amih);
amih = NULL;
}
}
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
}
MemCheck_on();
#if 0
lh_stats_bio(mh,b);
lh_node_stats_bio(mh,b);
lh_node_usage_stats_bio(mh,b);
#endif
}
void CRYPTO_mem_leaks_fp(FILE *fp)
{
BIO *b;
if (mh == NULL) return;
if ((b=BIO_new(BIO_s_file())) == NULL)
return;
BIO_set_fp(b,fp,BIO_NOCLOSE);
CRYPTO_mem_leaks(b);
BIO_free(b);
}
static void cb_leak(MEM *m,
void (**cb)(unsigned long, const char *, int, int, void *))
{
(**cb)(m->order,m->file,m->line,m->num,m->addr);
}
void CRYPTO_mem_leaks_cb(void (*cb)(unsigned long, const char *, int, int, void *))
{
if (mh == NULL) return;
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC2);
lh_doall_arg(mh,(void (*)())cb_leak,(void *)&cb);
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC2);
}
