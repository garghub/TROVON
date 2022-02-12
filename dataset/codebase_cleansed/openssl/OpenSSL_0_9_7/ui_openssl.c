UI_METHOD *UI_OpenSSL(void)
{
return &ui_openssl;
}
static int write_string(UI *ui, UI_STRING *uis)
{
switch (UI_get_string_type(uis))
{
case UIT_ERROR:
case UIT_INFO:
fputs(UI_get0_output_string(uis), tty_out);
fflush(tty_out);
break;
default:
break;
}
return 1;
}
static int read_string(UI *ui, UI_STRING *uis)
{
int ok = 0;
switch (UI_get_string_type(uis))
{
case UIT_BOOLEAN:
fputs(UI_get0_output_string(uis), tty_out);
fputs(UI_get0_action_string(uis), tty_out);
fflush(tty_out);
return read_string_inner(ui, uis,
UI_get_input_flags(uis) & UI_INPUT_FLAG_ECHO, 0);
case UIT_PROMPT:
fputs(UI_get0_output_string(uis), tty_out);
fflush(tty_out);
return read_string_inner(ui, uis,
UI_get_input_flags(uis) & UI_INPUT_FLAG_ECHO, 1);
case UIT_VERIFY:
fprintf(tty_out,"Verifying - %s",
UI_get0_output_string(uis));
fflush(tty_out);
if ((ok = read_string_inner(ui, uis,
UI_get_input_flags(uis) & UI_INPUT_FLAG_ECHO, 1)) <= 0)
return ok;
if (strcmp(UI_get0_result_string(uis),
UI_get0_test_string(uis)) != 0)
{
fprintf(tty_out,"Verify failure\n");
fflush(tty_out);
return 0;
}
break;
default:
break;
}
return 1;
}
static void read_till_nl(FILE *in)
{
#define SIZE 4
char buf[SIZE+1];
do {
fgets(buf,SIZE,in);
} while (strchr(buf,'\n') == NULL);
}
static int read_string_inner(UI *ui, UI_STRING *uis, int echo, int strip_nl)
{
static int ps;
int ok;
char result[BUFSIZ];
int maxsize = BUFSIZ-1;
#if !defined(OPENSSL_SYS_WIN16) && !defined(OPENSSL_SYS_WINCE)
char *p;
intr_signal=0;
ok=0;
ps=0;
pushsig();
ps=1;
if (!echo && !noecho_console(ui))
goto error;
ps=2;
result[0]='\0';
#ifdef OPENSSL_SYS_MSDOS
if (!echo)
{
noecho_fgets(result,maxsize,tty_in);
p=result;
}
else
p=fgets(result,maxsize,tty_in);
#else
p=fgets(result,maxsize,tty_in);
#endif
if(!p)
goto error;
if (feof(tty_in)) goto error;
if (ferror(tty_in)) goto error;
if ((p=(char *)strchr(result,'\n')) != NULL)
{
if (strip_nl)
*p='\0';
}
else
read_till_nl(tty_in);
if (UI_set_result(ui, uis, result) >= 0)
ok=1;
error:
if (intr_signal == SIGINT)
ok=-1;
if (!echo) fprintf(tty_out,"\n");
if (ps >= 2 && !echo && !echo_console(ui))
ok=0;
if (ps >= 1)
popsig();
#else
ok=1;
#endif
OPENSSL_cleanse(result,BUFSIZ);
return ok;
}
static int open_console(UI *ui)
{
CRYPTO_w_lock(CRYPTO_LOCK_UI);
is_a_tty = 1;
#if defined(OPENSSL_SYS_MACINTOSH_CLASSIC) || defined(OPENSSL_SYS_VXWORKS)
tty_in=stdin;
tty_out=stderr;
#else
# ifdef OPENSSL_SYS_MSDOS
# define DEV_TTY "con"
# else
# define DEV_TTY "/dev/tty"
# endif
if ((tty_in=fopen(DEV_TTY,"r")) == NULL)
tty_in=stdin;
if ((tty_out=fopen(DEV_TTY,"w")) == NULL)
tty_out=stderr;
#endif
#if defined(TTY_get) && !defined(OPENSSL_SYS_VMS)
if (TTY_get(fileno(tty_in),&tty_orig) == -1)
{
#ifdef ENOTTY
if (errno == ENOTTY)
is_a_tty=0;
else
#endif
#ifdef EINVAL
if (errno == EINVAL)
is_a_tty=0;
else
#endif
return 0;
}
#endif
#ifdef OPENSSL_SYS_VMS
status = sys$assign(&terminal,&channel,0,0);
if (status != SS$_NORMAL)
return 0;
status=sys$qiow(0,channel,IO$_SENSEMODE,&iosb,0,0,tty_orig,12,0,0,0,0);
if ((status != SS$_NORMAL) || (iosb.iosb$w_value != SS$_NORMAL))
return 0;
#endif
return 1;
}
static int noecho_console(UI *ui)
{
#ifdef TTY_FLAGS
memcpy(&(tty_new),&(tty_orig),sizeof(tty_orig));
tty_new.TTY_FLAGS &= ~ECHO;
#endif
#if defined(TTY_set) && !defined(OPENSSL_SYS_VMS)
if (is_a_tty && (TTY_set(fileno(tty_in),&tty_new) == -1))
return 0;
#endif
#ifdef OPENSSL_SYS_VMS
tty_new[0] = tty_orig[0];
tty_new[1] = tty_orig[1] | TT$M_NOECHO;
tty_new[2] = tty_orig[2];
status = sys$qiow(0,channel,IO$_SETMODE,&iosb,0,0,tty_new,12,0,0,0,0);
if ((status != SS$_NORMAL) || (iosb.iosb$w_value != SS$_NORMAL))
return 0;
#endif
return 1;
}
static int echo_console(UI *ui)
{
#if defined(TTY_set) && !defined(OPENSSL_SYS_VMS)
memcpy(&(tty_new),&(tty_orig),sizeof(tty_orig));
tty_new.TTY_FLAGS |= ECHO;
#endif
#if defined(TTY_set) && !defined(OPENSSL_SYS_VMS)
if (is_a_tty && (TTY_set(fileno(tty_in),&tty_new) == -1))
return 0;
#endif
#ifdef OPENSSL_SYS_VMS
tty_new[0] = tty_orig[0];
tty_new[1] = tty_orig[1] & ~TT$M_NOECHO;
tty_new[2] = tty_orig[2];
status = sys$qiow(0,channel,IO$_SETMODE,&iosb,0,0,tty_new,12,0,0,0,0);
if ((status != SS$_NORMAL) || (iosb.iosb$w_value != SS$_NORMAL))
return 0;
#endif
return 1;
}
static int close_console(UI *ui)
{
if (tty_in != stderr) fclose(tty_in);
if (tty_out != stderr) fclose(tty_out);
#ifdef OPENSSL_SYS_VMS
status = sys$dassgn(channel);
#endif
CRYPTO_w_unlock(CRYPTO_LOCK_UI);
return 1;
}
static void pushsig(void)
{
int i;
#ifdef SIGACTION
struct sigaction sa;
memset(&sa,0,sizeof sa);
sa.sa_handler=recsig;
#endif
for (i=1; i<NX509_SIG; i++)
{
#ifdef SIGUSR1
if (i == SIGUSR1)
continue;
#endif
#ifdef SIGUSR2
if (i == SIGUSR2)
continue;
#endif
#ifdef SIGKILL
if (i == SIGKILL)
continue;
#endif
#ifdef SIGACTION
sigaction(i,&sa,&savsig[i]);
#else
savsig[i]=signal(i,recsig);
#endif
}
#ifdef SIGWINCH
signal(SIGWINCH,SIG_DFL);
#endif
}
static void popsig(void)
{
int i;
for (i=1; i<NX509_SIG; i++)
{
#ifdef SIGUSR1
if (i == SIGUSR1)
continue;
#endif
#ifdef SIGUSR2
if (i == SIGUSR2)
continue;
#endif
#ifdef SIGACTION
sigaction(i,&savsig[i],NULL);
#else
signal(i,savsig[i]);
#endif
}
}
static void recsig(int i)
{
intr_signal=i;
}
static int noecho_fgets(char *buf, int size, FILE *tty)
{
int i;
char *p;
p=buf;
for (;;)
{
if (size == 0)
{
*p='\0';
break;
}
size--;
#ifdef WIN16TTY
i=_inchar();
#else
i=getch();
#endif
if (i == '\r') i='\n';
*(p++)=i;
if (i == '\n')
{
*p='\0';
break;
}
}
#ifdef WIN_CONSOLE_BUG
{
HANDLE inh;
inh = GetStdHandle(STD_INPUT_HANDLE);
FlushConsoleInputBuffer(inh);
}
#endif
return(strlen(buf));
}
