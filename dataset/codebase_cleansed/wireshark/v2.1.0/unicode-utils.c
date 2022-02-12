int
ws_utf8_char_len(guint8 ch)
{
if (ch >= 0xfe) return -1;
if (ch >= 0xfc) return 6;
if (ch >= 0xf8) return 5;
if (ch >= 0xf0) return 4;
if (ch >= 0xe0) return 3;
if (ch >= 0xc0) return 2;
else return 1;
}
const wchar_t *
utf_8to16(const char *utf8str)
{
static wchar_t *utf16buf[3];
static int utf16buf_len[3];
static int idx;
if (utf8str == NULL)
return NULL;
idx = (idx + 1) % 3;
if (utf16buf[idx] == NULL) {
utf16buf_len[idx] = INITIAL_UTFBUF_SIZE;
utf16buf[idx] = g_malloc(utf16buf_len[idx] * sizeof(wchar_t));
}
while (MultiByteToWideChar(CP_UTF8, 0, utf8str,
-1, NULL, 0) >= utf16buf_len[idx]) {
utf16buf_len[idx] *= 2;
utf16buf[idx] = g_realloc(utf16buf[idx], utf16buf_len[idx] * sizeof(wchar_t));
}
if (MultiByteToWideChar(CP_UTF8, 0, utf8str,
-1, utf16buf[idx], utf16buf_len[idx]) == 0)
return NULL;
return utf16buf[idx];
}
void
utf_8to16_snprintf(TCHAR *utf16buf, gint utf16buf_len, const gchar* fmt, ...)
{
va_list ap;
gchar* dst;
va_start(ap,fmt);
dst = g_strdup_vprintf(fmt, ap);
va_end(ap);
StringCchPrintf(utf16buf, utf16buf_len, _T("%s"), utf_8to16(dst));
g_free(dst);
}
gchar *
utf_16to8(const wchar_t *utf16str)
{
static gchar *utf8buf[3];
static int utf8buf_len[3];
static int idx;
if (utf16str == NULL)
return NULL;
idx = (idx + 1) % 3;
if (utf8buf[idx] == NULL) {
utf8buf_len[idx] = INITIAL_UTFBUF_SIZE;
utf8buf[idx] = g_malloc(utf8buf_len[idx]);
}
while (WideCharToMultiByte(CP_UTF8, 0, utf16str, -1,
NULL, 0, NULL, NULL) >= utf8buf_len[idx]) {
utf8buf_len[idx] *= 2;
utf8buf[idx] = g_realloc(utf8buf[idx], utf8buf_len[idx]);
}
if (WideCharToMultiByte(CP_UTF8, 0, utf16str, -1,
utf8buf[idx], utf8buf_len[idx], NULL, NULL) == 0)
return NULL;
return utf8buf[idx];
}
void
arg_list_utf_16to8(int argc, char *argv[]) {
LPWSTR *wc_argv;
int wc_argc, i;
wc_argv = CommandLineToArgvW(GetCommandLineW(), &wc_argc);
if (wc_argv && wc_argc == argc) {
for (i = 0; i < argc; i++) {
argv[i] = g_utf16_to_utf8(wc_argv[i], -1, NULL, NULL, NULL);
}
}
LocalFree(wc_argv);
}
