int CRYPTO_mem_ctrl(int mode)
{
int ret=mh_mode;
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
switch (mode)
{
case CRYPTO_MEM_CHECK_ON:
mh_mode = CRYPTO_MEM_CHECK_ON|CRYPTO_MEM_CHECK_ENABLE;
break;
case CRYPTO_MEM_CHECK_OFF:
mh_mode = 0;
break;
case CRYPTO_MEM_CHECK_DISABLE:
mh_mode&= ~CRYPTO_MEM_CHECK_ENABLE;
break;
case CRYPTO_MEM_CHECK_ENABLE:
if (mh_mode&CRYPTO_MEM_CHECK_ON)
mh_mode|=CRYPTO_MEM_CHECK_ENABLE;
break;
default:
break;
}
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
return(ret);
}
static int mem_cmp(MEM *a, MEM *b)
{
return(a->addr - b->addr);
}
static unsigned long mem_hash(MEM *a)
{
unsigned long ret;
ret=(unsigned long)a->addr;
ret=ret*17851+(ret>>14)*7+(ret>>4)*251;
return(ret);
}
void CRYPTO_set_mem_functions(char *(*m)(), char *(*r)(), void (*f)())
{
if ((m == NULL) || (r == NULL) || (f == NULL)) return;
malloc_func=m;
realloc_func=r;
free_func=f;
malloc_locked_func=m;
free_locked_func=f;
}
void CRYPTO_set_locked_mem_functions(char *(*m)(), void (*f)())
{
if ((m == NULL) || (f == NULL)) return;
malloc_locked_func=m;
free_locked_func=f;
}
void CRYPTO_get_mem_functions(char *(**m)(), char *(**r)(), void (**f)())
{
if (m != NULL) *m=malloc_func;
if (r != NULL) *r=realloc_func;
if (f != NULL) *f=free_func;
}
void CRYPTO_get_locked_mem_functions(char *(**m)(), void (**f)())
{
if (m != NULL) *m=malloc_locked_func;
if (f != NULL) *f=free_locked_func;
}
void *CRYPTO_malloc_locked(int num)
{
return(malloc_locked_func(num));
}
void CRYPTO_free_locked(void *str)
{
free_locked_func(str);
}
void *CRYPTO_malloc(int num)
{
return(malloc_func(num));
}
void *CRYPTO_realloc(void *str, int num)
{
return(realloc_func(str,num));
}
void CRYPTO_free(void *str)
{
free_func(str);
}
void *CRYPTO_dbg_malloc(int num, const char *file, int line)
{
char *ret;
MEM *m,*mm;
if ((ret=malloc_func(num)) == NULL)
return(NULL);
if (mh_mode & CRYPTO_MEM_CHECK_ENABLE)
{
MemCheck_off();
if ((m=(MEM *)Malloc(sizeof(MEM))) == NULL)
{
Free(ret);
MemCheck_on();
return(NULL);
}
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
if (mh == NULL)
{
if ((mh=lh_new(mem_hash,mem_cmp)) == NULL)
{
Free(ret);
Free(m);
ret=NULL;
goto err;
}
}
m->addr=ret;
m->file=file;
m->line=line;
m->num=num;
#ifdef CRYPTO_MDEBUG_THREAD
m->thread=CRYPTO_thread_id();
#endif
if (order == break_order_num)
{
m->order=order;
}
m->order=order++;
#ifdef CRYPTO_MDEBUG_TIME
m->time=time(NULL);
#endif
if ((mm=(MEM *)lh_insert(mh,(char *)m)) != NULL)
{
Free(mm);
}
err:
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
MemCheck_on();
}
return(ret);
}
void CRYPTO_dbg_free(void *addr)
{
MEM m,*mp;
if ((mh_mode & CRYPTO_MEM_CHECK_ENABLE) && (mh != NULL))
{
MemCheck_off();
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
m.addr=addr;
mp=(MEM *)lh_delete(mh,(char *)&m);
if (mp != NULL)
Free(mp);
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
MemCheck_on();
}
free_func(addr);
}
void *CRYPTO_dbg_realloc(void *addr, int num, const char *file, int line)
{
char *ret;
MEM m,*mp;
ret=realloc_func(addr,num);
if (ret == addr) return(ret);
if (mh_mode & CRYPTO_MEM_CHECK_ENABLE)
{
MemCheck_off();
if (ret == NULL) return(NULL);
m.addr=addr;
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
mp=(MEM *)lh_delete(mh,(char *)&m);
if (mp != NULL)
{
mp->addr=ret;
lh_insert(mh,(char *)mp);
}
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
MemCheck_on();
}
return(ret);
}
void *CRYPTO_remalloc(void *a, int n)
{
if (a != NULL) Free(a);
a=(char *)Malloc(n);
return(a);
}
void *CRYPTO_dbg_remalloc(void *a, int n, const char *file, int line)
{
if (a != NULL) CRYPTO_dbg_free(a);
a=(char *)CRYPTO_dbg_malloc(n,file,line);
return(a);
}
static void print_leak(MEM *m, MEM_LEAK *l)
{
char buf[128];
#ifdef CRYPTO_MDEBUG_TIME
struct tm *lcl;
#endif
if(m->addr == (char *)l->bio)
return;
#ifdef CRYPTO_MDEBUG_TIME
lcl = localtime(&m->time);
#endif
sprintf(buf,
#ifdef CRYPTO_MDEBUG_TIME
"[%02d:%02d:%02d] "
#endif
"%5lu file=%s, line=%d, "
#ifdef CRYPTO_MDEBUG_THREAD
"thread=%lu, "
#endif
"number=%d, address=%08lX\n",
#ifdef CRYPTO_MDEBUG_TIME
lcl->tm_hour,lcl->tm_min,lcl->tm_sec,
#endif
m->order,m->file,m->line,
#ifdef CRYPTO_MDEBUG_THREAD
m->thread,
#endif
m->num,(unsigned long)m->addr);
BIO_puts(l->bio,buf);
l->chunks++;
l->bytes+=m->num;
}
void CRYPTO_mem_leaks(BIO *b)
{
MEM_LEAK ml;
char buf[80];
if (mh == NULL) return;
ml.bio=b;
ml.bytes=0;
ml.chunks=0;
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
lh_doall_arg(mh,(void (*)())print_leak,(char *)&ml);
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
if (ml.chunks != 0)
{
sprintf(buf,"%ld bytes leaked in %d chunks\n",
ml.bytes,ml.chunks);
BIO_puts(b,buf);
}
#if 0
lh_stats_bio(mh,b);
lh_node_stats_bio(mh,b);
lh_node_usage_stats_bio(mh,b);
#endif
}
static void cb_leak(MEM *m, char *cb)
{
void (*mem_callback)()=(void (*)())cb;
mem_callback(m->order,m->file,m->line,m->num,m->addr);
}
void CRYPTO_mem_leaks_cb(void (*cb)())
{
if (mh == NULL) return;
CRYPTO_w_lock(CRYPTO_LOCK_MALLOC);
mem_cb=cb;
lh_doall_arg(mh,(void (*)())cb_leak,(char *)mem_cb);
mem_cb=NULL;
CRYPTO_w_unlock(CRYPTO_LOCK_MALLOC);
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
