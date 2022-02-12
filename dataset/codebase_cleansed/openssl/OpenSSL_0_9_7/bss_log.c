BIO_METHOD *BIO_s_log(void)
{
return(&methods_slg);
}
static int MS_CALLBACK slg_new(BIO *bi)
{
bi->init=1;
bi->num=0;
bi->ptr=NULL;
xopenlog(bi, "application", LOG_DAEMON);
return(1);
}
static int MS_CALLBACK slg_free(BIO *a)
{
if (a == NULL) return(0);
xcloselog(a);
return(1);
}
static int MS_CALLBACK slg_write(BIO *b, const char *in, int inl)
{
int ret= inl;
char* buf;
char* pp;
int priority, i;
static struct
{
int strl;
char str[10];
int log_level;
}
mapping[] =
{
{ 6, "PANIC ", LOG_EMERG },
{ 6, "EMERG ", LOG_EMERG },
{ 4, "EMR ", LOG_EMERG },
{ 6, "ALERT ", LOG_ALERT },
{ 4, "ALR ", LOG_ALERT },
{ 5, "CRIT ", LOG_CRIT },
{ 4, "CRI ", LOG_CRIT },
{ 6, "ERROR ", LOG_ERR },
{ 4, "ERR ", LOG_ERR },
{ 8, "WARNING ", LOG_WARNING },
{ 5, "WARN ", LOG_WARNING },
{ 4, "WAR ", LOG_WARNING },
{ 7, "NOTICE ", LOG_NOTICE },
{ 5, "NOTE ", LOG_NOTICE },
{ 4, "NOT ", LOG_NOTICE },
{ 5, "INFO ", LOG_INFO },
{ 4, "INF ", LOG_INFO },
{ 6, "DEBUG ", LOG_DEBUG },
{ 4, "DBG ", LOG_DEBUG },
{ 0, "", LOG_ERR }
};
if((buf= (char *)OPENSSL_malloc(inl+ 1)) == NULL){
return(0);
}
strncpy(buf, in, inl);
buf[inl]= '\0';
i = 0;
while(strncmp(buf, mapping[i].str, mapping[i].strl) != 0) i++;
priority = mapping[i].log_level;
pp = buf + mapping[i].strl;
xsyslog(b, priority, pp);
OPENSSL_free(buf);
return(ret);
}
static long MS_CALLBACK slg_ctrl(BIO *b, int cmd, long num, void *ptr)
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
static int MS_CALLBACK slg_puts(BIO *bp, const char *str)
{
int n,ret;
n=strlen(str);
ret=slg_write(bp,str,n);
return(ret);
}
static void xopenlog(BIO* bp, char* name, int level)
{
if ( !register_event_source )
{
HANDLE advapi;
if ( !(advapi = GetModuleHandle("advapi32")) )
return;
register_event_source = (HANDLE (WINAPI *)())DL_PROC_X(advapi,
"RegisterEventSource" );
deregister_event_source = (BOOL (WINAPI *)())DL_PROC(advapi,
"DeregisterEventSource");
report_event = (BOOL (WINAPI *)())DL_PROC_X(advapi,
"ReportEvent" );
if ( !(register_event_source && deregister_event_source &&
report_event) )
{
register_event_source = NULL;
deregister_event_source = NULL;
report_event = NULL;
return;
}
}
bp->ptr= (char *)register_event_source(NULL, name);
}
static void xsyslog(BIO *bp, int priority, const char *string)
{
LPCSTR lpszStrings[2];
WORD evtype= EVENTLOG_ERROR_TYPE;
int pid = _getpid();
char pidbuf[DECIMAL_SIZE(pid)+4];
switch (priority)
{
case LOG_EMERG:
case LOG_ALERT:
case LOG_CRIT:
case LOG_ERR:
evtype = EVENTLOG_ERROR_TYPE;
break;
case LOG_WARNING:
evtype = EVENTLOG_WARNING_TYPE;
break;
case LOG_NOTICE:
case LOG_INFO:
case LOG_DEBUG:
evtype = EVENTLOG_INFORMATION_TYPE;
break;
default:
evtype = EVENTLOG_ERROR_TYPE;
break;
}
sprintf(pidbuf, "[%d] ", pid);
lpszStrings[0] = pidbuf;
lpszStrings[1] = string;
if(report_event && bp->ptr)
report_event(bp->ptr, evtype, 0, 1024, NULL, 2, 0,
lpszStrings, NULL);
}
static void xcloselog(BIO* bp)
{
if(deregister_event_source && bp->ptr)
deregister_event_source((HANDLE)(bp->ptr));
bp->ptr= NULL;
}
static void xopenlog(BIO* bp, char* name, int level)
{
VMS_OPC_target = level;
}
static void xsyslog(BIO *bp, int priority, const char *string)
{
struct dsc$descriptor_s opc_dsc;
struct opcdef *opcdef_p;
char buf[10240];
unsigned int len;
struct dsc$descriptor_s buf_dsc;
$DESCRIPTOR(fao_cmd, "!AZ: !AZ");
char *priority_tag;
switch (priority)
{
case LOG_EMERG: priority_tag = "Emergency"; break;
case LOG_ALERT: priority_tag = "Alert"; break;
case LOG_CRIT: priority_tag = "Critical"; break;
case LOG_ERR: priority_tag = "Error"; break;
case LOG_WARNING: priority_tag = "Warning"; break;
case LOG_NOTICE: priority_tag = "Notice"; break;
case LOG_INFO: priority_tag = "Info"; break;
case LOG_DEBUG: priority_tag = "DEBUG"; break;
}
buf_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
buf_dsc.dsc$b_class = DSC$K_CLASS_S;
buf_dsc.dsc$a_pointer = buf;
buf_dsc.dsc$w_length = sizeof(buf) - 1;
lib$sys_fao(&fao_cmd, &len, &buf_dsc, priority_tag, string);
opcdef_p = (struct opcdef *) OPENSSL_malloc(8 + len);
opcdef_p->opc$b_ms_type = OPC$_RQ_RQST;
memcpy(opcdef_p->opc$z_ms_target_classes, &VMS_OPC_target, 3);
opcdef_p->opc$l_ms_rqstid = 0;
memcpy(&opcdef_p->opc$l_ms_text, buf, len);
opc_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
opc_dsc.dsc$b_class = DSC$K_CLASS_S;
opc_dsc.dsc$a_pointer = (char *)opcdef_p;
opc_dsc.dsc$w_length = len + 8;
sys$sndopr(opc_dsc, 0);
OPENSSL_free(opcdef_p);
}
static void xcloselog(BIO* bp)
{
}
static void xopenlog(BIO* bp, char* name, int level)
{
#ifdef WATT32
openlog(name, LOG_PID|LOG_CONS|LOG_NDELAY, level);
#else
openlog(name, LOG_PID|LOG_CONS, level);
#endif
}
static void xsyslog(BIO *bp, int priority, const char *string)
{
syslog(priority, "%s", string);
}
static void xcloselog(BIO* bp)
{
closelog();
}
