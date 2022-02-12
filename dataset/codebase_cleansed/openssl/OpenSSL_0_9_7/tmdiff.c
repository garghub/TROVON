char *ms_time_new(void)
{
MS_TM *ret;
ret=(MS_TM *)OPENSSL_malloc(sizeof(MS_TM));
if (ret == NULL)
return(NULL);
memset(ret,0,sizeof(MS_TM));
#ifdef OPENSSL_SYS_WIN32
ret->thread_id=GetCurrentThread();
#endif
return((char *)ret);
}
void ms_time_free(char *a)
{
if (a != NULL)
OPENSSL_free(a);
}
void ms_time_get(char *a)
{
MS_TM *tm=(MS_TM *)a;
#ifdef OPENSSL_SYS_WIN32
FILETIME tmpa,tmpb,tmpc;
#endif
#ifdef TIMES
times(&tm->ms_tms);
#else
# ifdef OPENSSL_SYS_WIN32
GetThreadTimes(tm->thread_id,&tmpa,&tmpb,&tmpc,&(tm->ms_win32));
# else
# ifdef OPENSSL_SYS_VXWORKS
tm->ticks = tickGet();
# else
ftime(&tm->ms_timeb);
# endif
# endif
#endif
}
double ms_time_diff(char *ap, char *bp)
{
MS_TM *a=(MS_TM *)ap;
MS_TM *b=(MS_TM *)bp;
double ret;
#ifdef TIMES
ret=(b->ms_tms.tms_utime-a->ms_tms.tms_utime)/HZ;
#else
# ifdef OPENSSL_SYS_WIN32
{
#ifdef __GNUC__
signed long long la,lb;
#else
signed _int64 la,lb;
#endif
la=a->ms_win32.dwHighDateTime;
lb=b->ms_win32.dwHighDateTime;
la<<=32;
lb<<=32;
la+=a->ms_win32.dwLowDateTime;
lb+=b->ms_win32.dwLowDateTime;
ret=((double)(lb-la))/1e7;
}
# else
# ifdef OPENSSL_SYS_VXWORKS
ret = (double)(b->ticks - a->ticks) / (double)sysClkRateGet();
# else
ret= (double)(b->ms_timeb.time-a->ms_timeb.time)+
(((double)b->ms_timeb.millitm)-
((double)a->ms_timeb.millitm))/1000.0;
# endif
# endif
#endif
return((ret < 0.0000001)?0.0000001:ret);
}
int ms_time_cmp(char *ap, char *bp)
{
MS_TM *a=(MS_TM *)ap,*b=(MS_TM *)bp;
double d;
int ret;
#ifdef TIMES
d=(b->ms_tms.tms_utime-a->ms_tms.tms_utime)/HZ;
#else
# ifdef OPENSSL_SYS_WIN32
d =(b->ms_win32.dwHighDateTime&0x000fffff)*10+b->ms_win32.dwLowDateTime/1e7;
d-=(a->ms_win32.dwHighDateTime&0x000fffff)*10+a->ms_win32.dwLowDateTime/1e7;
# else
# ifdef OPENSSL_SYS_VXWORKS
d = (b->ticks - a->ticks);
# else
d= (double)(b->ms_timeb.time-a->ms_timeb.time)+
(((double)b->ms_timeb.millitm)-(double)a->ms_timeb.millitm)/1000.0;
# endif
# endif
#endif
if (d == 0.0)
ret=0;
else if (d < 0)
ret= -1;
else
ret=1;
return(ret);
}
