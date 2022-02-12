static void cleanup(void)
{
int i;
SetConsoleOutputCP(saved_cp);
for (i = 0; i < newargc; i++)
free(newargv[i]);
free(newargv);
}
static int validate_argv(int argc)
{
static int size = 0;
if (argc >= size) {
char **ptr;
while (argc >= size)
size += 64;
ptr = realloc(newargv, size * sizeof(newargv[0]));
if (ptr == NULL)
return 0;
(newargv = ptr)[argc] = NULL;
} else {
newargv[argc] = NULL;
}
return 1;
}
static int process_glob(WCHAR *wstr, int wlen)
{
int i, slash, udlen;
WCHAR saved_char;
WIN32_FIND_DATAW data;
HANDLE h;
for (slash = 0, i = 0; i < wlen; i++)
if (wstr[i] == L'/' || wstr[i] == L'\\')
slash = i + 1;
for (i = slash; i < wlen; i++)
if (wstr[i] == L'*' || wstr[i] == L'?')
break;
if (i == wlen)
return 0;
saved_char = wstr[wlen];
wstr[wlen] = L'\0';
h = FindFirstFileW(wstr, &data);
wstr[wlen] = saved_char;
if (h == INVALID_HANDLE_VALUE)
return 0;
if (slash)
udlen = WideCharToMultiByte(CP_UTF8, 0, wstr, slash,
NULL, 0, NULL, NULL);
else
udlen = 0;
do {
int uflen;
char *arg;
if (data.cFileName[0] == L'.') {
if ((data.cFileName[1] == L'\0') ||
(data.cFileName[1] == L'.' && data.cFileName[2] == L'\0'))
continue;
}
if (!validate_argv(newargc + 1))
break;
uflen = WideCharToMultiByte(CP_UTF8, 0, data.cFileName, -1,
NULL, 0, NULL, NULL);
arg = malloc(udlen + uflen);
if (arg == NULL)
break;
if (udlen)
WideCharToMultiByte(CP_UTF8, 0, wstr, slash,
arg, udlen, NULL, NULL);
WideCharToMultiByte(CP_UTF8, 0, data.cFileName, -1,
arg + udlen, uflen, NULL, NULL);
newargv[newargc++] = arg;
} while (FindNextFileW(h, &data));
CloseHandle(h);
return 1;
}
void win32_utf8argv(int *argc, char **argv[])
{
const WCHAR *wcmdline;
WCHAR *warg, *wend, *p;
int wlen, ulen, valid = 1;
char *arg;
if (GetEnvironmentVariableW(L"OPENSSL_WIN32_UTF8", NULL, 0) == 0)
return;
newargc = 0;
newargv = NULL;
if (!validate_argv(newargc))
return;
wcmdline = GetCommandLineW();
if (wcmdline == NULL) return;
wlen = wcslen(wcmdline);
p = _alloca((wlen + 1) * sizeof(WCHAR));
wcscpy(p, wcmdline);
while (*p != L'\0') {
int in_quote = 0;
if (*p == L' ' || *p == L'\t') {
p++;
continue;
}
warg = wend = p;
while (*p != L'\0'
&& (in_quote || (*p != L' ' && *p != L'\t'))) {
switch (*p) {
case L'\\':
{
const WCHAR *q = p;
int i;
while (*p == L'\\')
p++;
if (*p == L'"') {
int i;
for (i = (p - q) / 2; i > 0; i--)
*wend++ = L'\\';
if ((p - q) % 2 == 1)
*wend++ = *p++;
} else {
for (i = p - q; i > 0; i--)
*wend++ = L'\\';
}
}
break;
case L'"':
if (in_quote && p[1] == L'"')
*wend++ = *p++;
else
in_quote = !in_quote;
p++;
break;
default:
*wend++ = *p++;
}
}
wlen = wend - warg;
if (wlen == 0 || !process_glob(warg, wlen)) {
if (!validate_argv(newargc + 1)) {
valid = 0;
break;
}
ulen = 0;
if (wlen > 0) {
ulen = WideCharToMultiByte(CP_UTF8, 0, warg, wlen,
NULL, 0, NULL, NULL);
if (ulen <= 0)
continue;
}
arg = malloc(ulen + 1);
if (arg == NULL) {
valid = 0;
break;
}
if (wlen > 0)
WideCharToMultiByte(CP_UTF8, 0, warg, wlen,
arg, ulen, NULL, NULL);
arg[ulen] = '\0';
newargv[newargc++] = arg;
}
}
if (valid) {
saved_cp = GetConsoleOutputCP();
SetConsoleOutputCP(CP_UTF8);
*argc = newargc;
*argv = newargv;
atexit(cleanup);
} else if (newargv != NULL) {
int i;
for (i = 0; i < newargc; i++)
free(newargv[i]);
free(newargv);
newargc = 0;
newargv = NULL;
}
return;
}
void win32_utf8argv(int &argc, char **argv[])
{ return; }
