static void ERR_STATE_free(ERR_STATE *s)
{
int i;
if(s == NULL)
return;
for (i=0; i<ERR_NUM_ERRORS; i++)
{
err_clear_data(s,i);
}
Free(s);
}
void ERR_load_ERR_strings(void)
{
static int init=1;
if (init)
{
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
if (init == 0)
{
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
return;
}
init=0;
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
#ifndef NO_ERR
ERR_load_strings(0,ERR_str_libraries);
ERR_load_strings(0,ERR_str_reasons);
ERR_load_strings(ERR_LIB_SYS,ERR_str_functs);
#endif
}
}
void ERR_load_strings(int lib, ERR_STRING_DATA *str)
{
if (error_hash == NULL)
{
CRYPTO_w_lock(CRYPTO_LOCK_ERR_HASH);
error_hash=lh_new(err_hash,err_cmp);
if (error_hash == NULL)
{
CRYPTO_w_unlock(CRYPTO_LOCK_ERR_HASH);
return;
}
CRYPTO_w_unlock(CRYPTO_LOCK_ERR_HASH);
ERR_load_ERR_strings();
}
CRYPTO_w_lock(CRYPTO_LOCK_ERR_HASH);
while (str->error)
{
str->error|=ERR_PACK(lib,0,0);
lh_insert(error_hash,(char *)str);
str++;
}
CRYPTO_w_unlock(CRYPTO_LOCK_ERR_HASH);
}
void ERR_free_strings(void)
{
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
if (error_hash != NULL)
{
lh_free(error_hash);
error_hash=NULL;
}
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
}
void ERR_put_error(int lib, int func, int reason, const char *file,
int line)
{
ERR_STATE *es;
es=ERR_get_state();
es->top=(es->top+1)%ERR_NUM_ERRORS;
if (es->top == es->bottom)
es->bottom=(es->bottom+1)%ERR_NUM_ERRORS;
es->err_buffer[es->top]=ERR_PACK(lib,func,reason);
es->err_file[es->top]=file;
es->err_line[es->top]=line;
err_clear_data(es,es->top);
}
void ERR_clear_error(void)
{
ERR_STATE *es;
es=ERR_get_state();
#if 0
for (i=0; i<ERR_NUM_ERRORS; i++)
{
es->err_buffer[i]=0;
es->err_file[i]=NULL;
es->err_line[i]= -1;
err_clear_data(es,i);
}
#endif
es->top=es->bottom=0;
}
unsigned long ERR_get_error(void)
{ return(get_error_values(1,NULL,NULL,NULL,NULL)); }
unsigned long ERR_get_error_line(const char **file,
int *line)
{ return(get_error_values(1,file,line,NULL,NULL)); }
unsigned long ERR_get_error_line_data(const char **file, int *line,
const char **data, int *flags)
{ return(get_error_values(1,file,line,
data,flags)); }
unsigned long ERR_peek_error(void)
{ return(get_error_values(0,NULL,NULL,NULL,NULL)); }
unsigned long ERR_peek_error_line(const char **file,
int *line)
{ return(get_error_values(0,file,line,NULL,NULL)); }
unsigned long ERR_peek_error_line_data(const char **file, int *line,
const char **data, int *flags)
{ return(get_error_values(0,file,line,
data,flags)); }
static unsigned long get_error_values(int inc, const char **file, int *line,
const char **data, int *flags)
{
int i=0;
ERR_STATE *es;
unsigned long ret;
es=ERR_get_state();
if (es->bottom == es->top) return(0);
i=(es->bottom+1)%ERR_NUM_ERRORS;
ret=es->err_buffer[i];
if (inc)
{
es->bottom=i;
es->err_buffer[i]=0;
}
if ((file != NULL) && (line != NULL))
{
if (es->err_file[i] == NULL)
{
*file="NA";
if (line != NULL) *line=0;
}
else
{
*file=es->err_file[i];
if (line != NULL) *line=es->err_line[i];
}
}
if (data != NULL)
{
if (es->err_data[i] == NULL)
{
*data="";
if (flags != NULL) *flags=0;
}
else
{
*data=es->err_data[i];
if (flags != NULL) *flags=es->err_data_flags[i];
}
}
return(ret);
}
char *ERR_error_string(unsigned long e, char *ret)
{
static char buf[256];
const char *ls,*fs,*rs;
unsigned long l,f,r;
int i;
l=ERR_GET_LIB(e);
f=ERR_GET_FUNC(e);
r=ERR_GET_REASON(e);
ls=ERR_lib_error_string(e);
fs=ERR_func_error_string(e);
rs=ERR_reason_error_string(e);
if (ret == NULL) ret=buf;
sprintf(&(ret[0]),"error:%08lX:",e);
i=strlen(ret);
if (ls == NULL)
sprintf(&(ret[i]),":lib(%lu) ",l);
else sprintf(&(ret[i]),"%s",ls);
i=strlen(ret);
if (fs == NULL)
sprintf(&(ret[i]),":func(%lu) ",f);
else sprintf(&(ret[i]),":%s",fs);
i=strlen(ret);
if (rs == NULL)
sprintf(&(ret[i]),":reason(%lu)",r);
else sprintf(&(ret[i]),":%s",rs);
return(ret);
}
LHASH *ERR_get_string_table(void)
{
return(error_hash);
}
LHASH *ERR_get_err_state_table(void)
{
return(thread_hash);
}
const char *ERR_lib_error_string(unsigned long e)
{
ERR_STRING_DATA d,*p=NULL;
unsigned long l;
l=ERR_GET_LIB(e);
CRYPTO_r_lock(CRYPTO_LOCK_ERR_HASH);
if (error_hash != NULL)
{
d.error=ERR_PACK(l,0,0);
p=(ERR_STRING_DATA *)lh_retrieve(error_hash,(char *)&d);
}
CRYPTO_r_unlock(CRYPTO_LOCK_ERR_HASH);
return((p == NULL)?NULL:p->string);
}
const char *ERR_func_error_string(unsigned long e)
{
ERR_STRING_DATA d,*p=NULL;
unsigned long l,f;
l=ERR_GET_LIB(e);
f=ERR_GET_FUNC(e);
CRYPTO_r_lock(CRYPTO_LOCK_ERR_HASH);
if (error_hash != NULL)
{
d.error=ERR_PACK(l,f,0);
p=(ERR_STRING_DATA *)lh_retrieve(error_hash,(char *)&d);
}
CRYPTO_r_unlock(CRYPTO_LOCK_ERR_HASH);
return((p == NULL)?NULL:p->string);
}
const char *ERR_reason_error_string(unsigned long e)
{
ERR_STRING_DATA d,*p=NULL;
unsigned long l,r;
l=ERR_GET_LIB(e);
r=ERR_GET_REASON(e);
CRYPTO_r_lock(CRYPTO_LOCK_ERR_HASH);
if (error_hash != NULL)
{
d.error=ERR_PACK(l,0,r);
p=(ERR_STRING_DATA *)lh_retrieve(error_hash,(char *)&d);
if (p == NULL)
{
d.error=ERR_PACK(0,0,r);
p=(ERR_STRING_DATA *)lh_retrieve(error_hash,
(char *)&d);
}
}
CRYPTO_r_unlock(CRYPTO_LOCK_ERR_HASH);
return((p == NULL)?NULL:p->string);
}
static unsigned long err_hash(ERR_STRING_DATA *a)
{
unsigned long ret,l;
l=a->error;
ret=l^ERR_GET_LIB(l)^ERR_GET_FUNC(l);
return(ret^ret%19*13);
}
static int err_cmp(ERR_STRING_DATA *a, ERR_STRING_DATA *b)
{
return((int)(a->error-b->error));
}
static unsigned long pid_hash(ERR_STATE *a)
{
return(a->pid*13);
}
static int pid_cmp(ERR_STATE *a, ERR_STATE *b)
{
return((int)((long)a->pid - (long)b->pid));
}
void ERR_remove_state(unsigned long pid)
{
ERR_STATE *p,tmp;
if (thread_hash == NULL)
return;
if (pid == 0)
pid=(unsigned long)CRYPTO_thread_id();
tmp.pid=pid;
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
p=(ERR_STATE *)lh_delete(thread_hash,(char *)&tmp);
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
if (p != NULL) ERR_STATE_free(p);
}
ERR_STATE *ERR_get_state(void)
{
static ERR_STATE fallback;
ERR_STATE *ret=NULL,tmp,*tmpp;
int i;
unsigned long pid;
pid=(unsigned long)CRYPTO_thread_id();
CRYPTO_r_lock(CRYPTO_LOCK_ERR);
if (thread_hash == NULL)
{
CRYPTO_r_unlock(CRYPTO_LOCK_ERR);
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
if (thread_hash == NULL)
{
MemCheck_off();
thread_hash=lh_new(pid_hash,pid_cmp);
MemCheck_on();
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
if (thread_hash == NULL) return(&fallback);
}
else
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
}
else
{
tmp.pid=pid;
ret=(ERR_STATE *)lh_retrieve(thread_hash,(char *)&tmp);
CRYPTO_r_unlock(CRYPTO_LOCK_ERR);
}
if (ret == NULL)
{
ret=(ERR_STATE *)Malloc(sizeof(ERR_STATE));
if (ret == NULL) return(&fallback);
ret->pid=pid;
ret->top=0;
ret->bottom=0;
for (i=0; i<ERR_NUM_ERRORS; i++)
{
ret->err_data[i]=NULL;
ret->err_data_flags[i]=0;
}
CRYPTO_w_lock(CRYPTO_LOCK_ERR);
tmpp=(ERR_STATE *)lh_insert(thread_hash,(char *)ret);
CRYPTO_w_unlock(CRYPTO_LOCK_ERR);
if (tmpp != NULL)
{
ERR_STATE_free(tmpp);
}
}
return(ret);
}
int ERR_get_next_error_library(void)
{
static int value=ERR_LIB_USER;
return(value++);
}
void ERR_set_error_data(char *data, int flags)
{
ERR_STATE *es;
int i;
es=ERR_get_state();
i=es->top;
if (i == 0)
i=ERR_NUM_ERRORS-1;
es->err_data[i]=data;
es->err_data_flags[es->top]=flags;
}
void ERR_add_error_data(int num, ...)
{
va_list args;
int i,n,s;
char *str,*p,*a;
s=64;
str=Malloc(s+1);
if (str == NULL) return;
str[0]='\0';
va_start(args, num);
n=0;
for (i=0; i<num; i++)
{
a=va_arg(args, char*);
if (a != NULL)
{
n+=strlen(a);
if (n > s)
{
s=n+20;
p=Realloc(str,s+1);
if (p == NULL)
{
Free(str);
return;
}
else
str=p;
}
strcat(str,a);
}
}
ERR_set_error_data(str,ERR_TXT_MALLOCED|ERR_TXT_STRING);
va_end(args);
}
