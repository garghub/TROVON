BIO_METHOD *BIO_s_log(void)
{
return(&methods_slg);
}
static int MS_CALLBACK slg_new(BIO *bi)
{
bi->init=1;
bi->num=0;
bi->ptr=NULL;
#ifndef WIN32
xopenlog(bi, "application", LOG_DAEMON);
#else
xopenlog(bi, "application", 0);
#endif
return(1);
}
static int MS_CALLBACK slg_free(BIO *a)
{
if (a == NULL) return(0);
xcloselog(a);
return(1);
}
static int MS_CALLBACK slg_write(BIO *b, char *in, int inl)
{
int ret= inl;
char* buf= in;
char* pp;
#if defined(WIN32)
LPCSTR lpszStrings[2];
WORD evtype= EVENTLOG_ERROR_TYPE;
int pid = _getpid();
char pidbuf[20];
#else
int priority;
#endif
if((buf= (char *)Malloc(inl+ 1)) == NULL){
return(0);
}
strncpy(buf, in, inl);
buf[inl]= '\0';
#if defined(WIN32)
if(strncmp(buf, "ERR ", 4) == 0){
evtype= EVENTLOG_ERROR_TYPE;
pp= buf+ 4;
}else if(strncmp(buf, "WAR ", 4) == 0){
evtype= EVENTLOG_WARNING_TYPE;
pp= buf+ 4;
}else if(strncmp(buf, "INF ", 4) == 0){
evtype= EVENTLOG_INFORMATION_TYPE;
pp= buf+ 4;
}else{
evtype= EVENTLOG_ERROR_TYPE;
pp= buf;
}
sprintf(pidbuf, "[%d] ", pid);
lpszStrings[0] = pidbuf;
lpszStrings[1] = pp;
if(b->ptr)
ReportEvent(b->ptr, evtype, 0, 1024, NULL, 2, 0,
lpszStrings, NULL);
#else
if(strncmp(buf, "ERR ", 4) == 0){
priority= LOG_ERR;
pp= buf+ 4;
}else if(strncmp(buf, "WAR ", 4) == 0){
priority= LOG_WARNING;
pp= buf+ 4;
}else if(strncmp(buf, "INF ", 4) == 0){
priority= LOG_INFO;
pp= buf+ 4;
}else{
priority= LOG_ERR;
pp= buf;
}
syslog(priority, "%s", pp);
#endif
Free(buf);
return(ret);
}
static long MS_CALLBACK slg_ctrl(BIO *b, int cmd, long num, char *ptr)
{
switch (cmd)
{
case BIO_CTRL_SET:
xcloselog(b);
xopenlog(b, ptr, num);
break;
default:
break;
}
return(0);
}
static int MS_CALLBACK slg_puts(BIO *bp, char *str)
{
int n,ret;
n=strlen(str);
ret=slg_write(bp,str,n);
return(ret);
}
static int xopenlog(BIO* bp, const char* name, int level)
{
#if defined(WIN32)
if((bp->ptr= (char *)RegisterEventSource(NULL, name)) == NULL){
return(0);
}
#else
openlog(name, LOG_PID|LOG_CONS, level);
#endif
return(1);
}
static int xcloselog(BIO* bp)
{
#if defined(WIN32)
if(bp->ptr)
DeregisterEventSource((HANDLE)(bp->ptr));
bp->ptr= NULL;
#else
closelog();
#endif
return(1);
}
