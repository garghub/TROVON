int des_read_pw_string(char *buf, int length, const char *prompt, int verify)
{
char buff[BUFSIZ];
int ret;
ret =
des_read_pw(buf, buff, (length > BUFSIZ) ? BUFSIZ : length, prompt,
verify);
OPENSSL_cleanse(buff, BUFSIZ);
return (ret);
}
int des_read_pw(char *buf, char *buff, int size, const char *prompt,
int verify)
{
memset(buf, 0, size);
memset(buff, 0, size);
return (0);
}
int des_read_pw(char *buf, char *buff, int size, char *prompt, int verify)
{
memset(buf, 0, size);
memset(buff, 0, size);
return (0);
}
static void read_till_nl(FILE *in)
{
# define SIZE 4
char buf[SIZE + 1];
do {
fgets(buf, SIZE, in);
} while (strchr(buf, '\n') == NULL);
}
int des_read_pw(char *buf, char *buff, int size, const char *prompt,
int verify)
{
# ifdef OPENSSL_SYS_VMS
struct IOSB iosb;
$DESCRIPTOR(terminal, "TT");
long tty_orig[3], tty_new[3];
long status;
unsigned short channel = 0;
# else
# if !defined(OPENSSL_SYS_MSDOS) || defined(__DJGPP__)
TTY_STRUCT tty_orig, tty_new;
# endif
# endif
int number;
int ok;
static int ps;
int is_a_tty;
static FILE *tty;
char *p;
if (setjmp(save)) {
ok = 0;
goto error;
}
number = 5;
ok = 0;
ps = 0;
is_a_tty = 1;
tty = NULL;
# ifdef OPENSSL_SYS_MSDOS
if ((tty = fopen("con", "r")) == NULL)
tty = stdin;
# elif defined(MAC_OS_pre_X) || defined(OPENSSL_SYS_VXWORKS)
tty = stdin;
# else
# ifndef OPENSSL_SYS_MPE
if ((tty = fopen("/dev/tty", "r")) == NULL)
# endif
tty = stdin;
# endif
# if defined(TTY_get) && !defined(OPENSSL_SYS_VMS)
if (TTY_get(fileno(tty), &tty_orig) == -1) {
# ifdef ENOTTY
if (errno == ENOTTY)
is_a_tty = 0;
else
# endif
# ifdef EINVAL
if (errno == EINVAL)
is_a_tty = 0;
else
# endif
return (-1);
}
memcpy(&(tty_new), &(tty_orig), sizeof(tty_orig));
# endif
# ifdef OPENSSL_SYS_VMS
status = sys$assign(&terminal, &channel, 0, 0);
if (status != SS$_NORMAL)
return (-1);
status =
sys$qiow(0, channel, IO$_SENSEMODE, &iosb, 0, 0, tty_orig, 12, 0, 0,
0, 0);
if ((status != SS$_NORMAL) || (iosb.iosb$w_value != SS$_NORMAL))
return (-1);
# endif
pushsig();
ps = 1;
# ifdef TTY_FLAGS
tty_new.TTY_FLAGS &= ~ECHO;
# endif
# if defined(TTY_set) && !defined(OPENSSL_SYS_VMS)
if (is_a_tty && (TTY_set(fileno(tty), &tty_new) == -1))
# ifdef OPENSSL_SYS_MPE
;
# else
return (-1);
# endif
# endif
# ifdef OPENSSL_SYS_VMS
tty_new[0] = tty_orig[0];
tty_new[1] = tty_orig[1] | TT$M_NOECHO;
tty_new[2] = tty_orig[2];
status =
sys$qiow(0, channel, IO$_SETMODE, &iosb, 0, 0, tty_new, 12, 0, 0, 0,
0);
if ((status != SS$_NORMAL) || (iosb.iosb$w_value != SS$_NORMAL))
return (-1);
# endif
ps = 2;
while ((!ok) && (number--)) {
fputs(prompt, stderr);
fflush(stderr);
buf[0] = '\0';
fgets(buf, size, tty);
if (feof(tty))
goto error;
if (ferror(tty))
goto error;
if ((p = (char *)strchr(buf, '\n')) != NULL)
*p = '\0';
else
read_till_nl(tty);
if (verify) {
fprintf(stderr, "\nVerifying password - %s", prompt);
fflush(stderr);
buff[0] = '\0';
fgets(buff, size, tty);
if (feof(tty))
goto error;
if ((p = (char *)strchr(buff, '\n')) != NULL)
*p = '\0';
else
read_till_nl(tty);
if (strcmp(buf, buff) != 0) {
fprintf(stderr, "\nVerify failure");
fflush(stderr);
break;
}
}
ok = 1;
}
error:
fprintf(stderr, "\n");
# if 0
perror("fgets(tty)");
# endif
# if defined(TTY_set) && !defined(OPENSSL_SYS_VMS)
if (ps >= 2)
TTY_set(fileno(tty), &tty_orig);
# endif
# ifdef OPENSSL_SYS_VMS
if (ps >= 2)
status =
sys$qiow(0, channel, IO$_SETMODE, &iosb, 0, 0, tty_orig, 12, 0, 0,
0, 0);
# endif
if (ps >= 1)
popsig();
if (stdin != tty)
fclose(tty);
# ifdef OPENSSL_SYS_VMS
status = sys$dassgn(channel);
# endif
return (!ok);
}
static void pushsig(void)
{
int i;
# ifdef SIGACTION
struct sigaction sa;
memset(&sa, 0, sizeof sa);
sa.sa_handler = recsig;
# endif
for (i = 1; i < NX509_SIG; i++) {
# ifdef SIGUSR1
if (i == SIGUSR1)
continue;
# endif
# ifdef SIGUSR2
if (i == SIGUSR2)
continue;
# endif
# ifdef SIGACTION
sigaction(i, &sa, &savsig[i]);
# else
savsig[i] = signal(i, recsig);
# endif
}
# ifdef SIGWINCH
signal(SIGWINCH, SIG_DFL);
# endif
}
static void popsig(void)
{
int i;
for (i = 1; i < NX509_SIG; i++) {
# ifdef SIGUSR1
if (i == SIGUSR1)
continue;
# endif
# ifdef SIGUSR2
if (i == SIGUSR2)
continue;
# endif
# ifdef SIGACTION
sigaction(i, &savsig[i], NULL);
# else
signal(i, savsig[i]);
# endif
}
}
static void recsig(int i)
{
longjmp(save, 1);
# ifdef LINT
i = i;
# endif
}
static int noecho_fgets(char *buf, int size, FILE *tty)
{
int i;
char *p;
p = buf;
for (;;) {
if (size == 0) {
*p = '\0';
break;
}
size--;
# ifdef WIN16TTY
i = _inchar();
# else
i = getch();
# endif
if (i == '\r')
i = '\n';
*(p++) = i;
if (i == '\n') {
*p = '\0';
break;
}
}
# ifdef WIN_CONSOLE_BUG
{
HANDLE inh;
inh = GetStdHandle(STD_INPUT_HANDLE);
FlushConsoleInputBuffer(inh);
}
# endif
return (strlen(buf));
}
