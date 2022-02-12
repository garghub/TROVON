int RAND_load_file(const char *file, long bytes)
{
unsigned char buf[BUFSIZE];
#ifndef OPENSSL_NO_POSIX_IO
struct stat sb;
#endif
int i, ret = 0, n;
FILE *in = NULL;
if (file == NULL)
return 0;
if (bytes == 0)
return ret;
in = openssl_fopen(file, "rb");
if (in == NULL)
goto err;
#ifndef OPENSSL_NO_POSIX_IO
memset(&sb, 0, sizeof(sb));
if (fstat(fileno(in), &sb) < 0)
goto err;
RAND_add(&sb, sizeof(sb), 0.0);
# if defined(S_ISBLK) && defined(S_ISCHR)
if (S_ISBLK(sb.st_mode) || S_ISCHR(sb.st_mode)) {
bytes = (bytes == -1) ? 2048 : bytes;
setbuf(in, NULL);
}
# endif
#endif
for (;;) {
if (bytes > 0)
n = (bytes < BUFSIZE) ? (int)bytes : BUFSIZE;
else
n = BUFSIZE;
i = fread(buf, 1, n, in);
if (i <= 0)
break;
RAND_add(buf, i, (double)i);
ret += i;
if (bytes > 0) {
bytes -= n;
if (bytes <= 0)
break;
}
}
OPENSSL_cleanse(buf, BUFSIZE);
err:
if (in != NULL)
fclose(in);
return ret;
}
int RAND_write_file(const char *file)
{
unsigned char buf[BUFSIZE];
int i, ret = 0, rand_err = 0;
FILE *out = NULL;
int n;
#ifndef OPENSSL_NO_POSIX_IO
struct stat sb;
# if defined(S_ISBLK) && defined(S_ISCHR)
# ifdef _WIN32
# endif
i = stat(file, &sb);
if (i != -1) {
if (S_ISBLK(sb.st_mode) || S_ISCHR(sb.st_mode)) {
return 1;
}
# endif
}
#endif
#if defined(O_CREAT) && !defined(OPENSSL_NO_POSIX_IO) && \
!defined(OPENSSL_SYS_VMS) && !defined(OPENSSL_SYS_WINDOWS)
{
# ifndef O_BINARY
# define O_BINARY 0
# endif
int fd = open(file, O_WRONLY | O_CREAT | O_BINARY, 0600);
if (fd != -1)
out = fdopen(fd, "wb");
}
#endif
#ifdef OPENSSL_SYS_VMS
out = openssl_fopen(file, "rb+");
#endif
if (out == NULL)
out = openssl_fopen(file, "wb");
if (out == NULL)
goto err;
#if !defined(NO_CHMOD) && !defined(OPENSSL_NO_POSIX_IO)
chmod(file, 0600);
#endif
n = RAND_DATA;
for (;;) {
i = (n > BUFSIZE) ? BUFSIZE : n;
n -= BUFSIZE;
if (RAND_bytes(buf, i) <= 0)
rand_err = 1;
i = fwrite(buf, 1, i, out);
if (i <= 0) {
ret = 0;
break;
}
ret += i;
if (n <= 0)
break;
}
fclose(out);
OPENSSL_cleanse(buf, BUFSIZE);
err:
return (rand_err ? -1 : ret);
}
const char *RAND_file_name(char *buf, size_t size)
{
char *s = NULL;
int use_randfile = 1;
#ifdef __OpenBSD__
struct stat sb;
#endif
#if defined(_WIN32) && defined(CP_UTF8)
DWORD len;
WCHAR *var, *val;
if ((var = L"RANDFILE",
len = GetEnvironmentVariableW(var, NULL, 0)) == 0
&& (var = L"HOME", use_randfile = 0,
len = GetEnvironmentVariableW(var, NULL, 0)) == 0
&& (var = L"USERPROFILE",
len = GetEnvironmentVariableW(var, NULL, 0)) == 0) {
var = L"SYSTEMROOT",
len = GetEnvironmentVariableW(var, NULL, 0);
}
if (len != 0) {
int sz;
val = _alloca(len * sizeof(WCHAR));
if (GetEnvironmentVariableW(var, val, len) < len
&& (sz = WideCharToMultiByte(CP_UTF8, 0, val, -1, NULL, 0,
NULL, NULL)) != 0) {
s = _alloca(sz);
if (WideCharToMultiByte(CP_UTF8, 0, val, -1, s, sz,
NULL, NULL) == 0)
s = NULL;
}
}
#else
if (OPENSSL_issetugid() == 0) {
s = getenv("RANDFILE");
} else {
use_randfile = 0;
if (OPENSSL_issetugid() == 0)
s = getenv("HOME");
}
#endif
#ifdef DEFAULT_HOME
if (!use_randfile && s == NULL) {
s = DEFAULT_HOME;
}
#endif
if (s != NULL && *s) {
size_t len = strlen(s);
if (use_randfile && len + 1 < size) {
if (OPENSSL_strlcpy(buf, s, size) >= size)
return NULL;
} else if (len + strlen(RFILE) + 2 < size) {
OPENSSL_strlcpy(buf, s, size);
#ifndef OPENSSL_SYS_VMS
OPENSSL_strlcat(buf, "/", size);
#endif
OPENSSL_strlcat(buf, RFILE, size);
}
} else {
buf[0] = '\0';
}
#ifdef __OpenBSD__
if (!buf[0])
if (OPENSSL_strlcpy(buf, "/dev/arandom", size) >= size) {
return NULL;
}
if (stat(buf, &sb) == -1)
if (OPENSSL_strlcpy(buf, "/dev/arandom", size) >= size) {
return NULL;
}
#endif
return buf;
}
