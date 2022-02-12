int
ws_stdio_open (const gchar *filename,
int flags,
int mode)
{
wchar_t *wfilename = g_utf8_to_utf16 (filename, -1, NULL, NULL, NULL);
int retval;
int save_errno;
if (wfilename == NULL)
{
errno = EINVAL;
return -1;
}
retval = _wopen (wfilename, flags, mode);
save_errno = errno;
g_free (wfilename);
errno = save_errno;
return retval;
}
int
ws_stdio_rename (const gchar *oldfilename,
const gchar *newfilename)
{
wchar_t *woldfilename = g_utf8_to_utf16 (oldfilename, -1, NULL, NULL, NULL);
wchar_t *wnewfilename;
int retval;
int save_errno = 0;
if (woldfilename == NULL)
{
errno = EINVAL;
return -1;
}
wnewfilename = g_utf8_to_utf16 (newfilename, -1, NULL, NULL, NULL);
if (wnewfilename == NULL)
{
g_free (woldfilename);
errno = EINVAL;
return -1;
}
if (MoveFileExW (woldfilename, wnewfilename, MOVEFILE_REPLACE_EXISTING))
retval = 0;
else
{
retval = -1;
switch (GetLastError ())
{
#define CASE(a,b) case ERROR_##a: save_errno = b; break
CASE (FILE_NOT_FOUND, ENOENT);
CASE (PATH_NOT_FOUND, ENOENT);
CASE (ACCESS_DENIED, EACCES);
CASE (NOT_SAME_DEVICE, EXDEV);
CASE (LOCK_VIOLATION, EACCES);
CASE (SHARING_VIOLATION, EACCES);
CASE (FILE_EXISTS, EEXIST);
CASE (ALREADY_EXISTS, EEXIST);
#undef CASE
default: save_errno = EIO;
}
}
g_free (woldfilename);
g_free (wnewfilename);
errno = save_errno;
return retval;
}
int
ws_stdio_mkdir (const gchar *filename,
int mode)
{
wchar_t *wfilename = g_utf8_to_utf16 (filename, -1, NULL, NULL, NULL);
int retval;
int save_errno;
if (wfilename == NULL)
{
errno = EINVAL;
return -1;
}
retval = _wmkdir (wfilename);
save_errno = errno;
g_free (wfilename);
errno = save_errno;
return retval;
}
int
ws_stdio_stat64 (const gchar *filename,
ws_statb64 *buf)
{
wchar_t *wfilename = g_utf8_to_utf16 (filename, -1, NULL, NULL, NULL);
int retval;
int save_errno;
size_t len;
if (wfilename == NULL)
{
errno = EINVAL;
return -1;
}
len = wcslen (wfilename);
while (len > 0 && G_IS_DIR_SEPARATOR (wfilename[len-1]))
len--;
if (len > 0 &&
(!g_path_is_absolute (filename) || len > (size_t) (g_path_skip_root (filename) - filename)))
wfilename[len] = '\0';
retval = _wstati64 (wfilename, buf);
save_errno = errno;
g_free (wfilename);
errno = save_errno;
return retval;
}
int
ws_stdio_unlink (const gchar *filename)
{
wchar_t *wfilename = g_utf8_to_utf16 (filename, -1, NULL, NULL, NULL);
int retval;
int save_errno;
if (wfilename == NULL)
{
errno = EINVAL;
return -1;
}
retval = _wunlink (wfilename);
save_errno = errno;
g_free (wfilename);
errno = save_errno;
return retval;
}
int
ws_stdio_remove (const gchar *filename)
{
wchar_t *wfilename = g_utf8_to_utf16 (filename, -1, NULL, NULL, NULL);
int retval;
int save_errno;
if (wfilename == NULL)
{
errno = EINVAL;
return -1;
}
retval = _wremove (wfilename);
if (retval == -1)
retval = _wrmdir (wfilename);
save_errno = errno;
g_free (wfilename);
errno = save_errno;
return retval;
}
FILE *
ws_stdio_fopen (const gchar *filename,
const gchar *mode)
{
wchar_t *wfilename = g_utf8_to_utf16 (filename, -1, NULL, NULL, NULL);
wchar_t *wmode;
FILE *retval;
int save_errno;
if (wfilename == NULL)
{
errno = EINVAL;
return NULL;
}
wmode = g_utf8_to_utf16 (mode, -1, NULL, NULL, NULL);
if (wmode == NULL)
{
g_free (wfilename);
errno = EINVAL;
return NULL;
}
retval = _wfopen (wfilename, wmode);
save_errno = errno;
g_free (wfilename);
g_free (wmode);
errno = save_errno;
return retval;
}
FILE *
ws_stdio_freopen (const gchar *filename,
const gchar *mode,
FILE *stream)
{
wchar_t *wfilename = g_utf8_to_utf16 (filename, -1, NULL, NULL, NULL);
wchar_t *wmode;
FILE *retval;
int save_errno;
if (wfilename == NULL)
{
errno = EINVAL;
return NULL;
}
wmode = g_utf8_to_utf16 (mode, -1, NULL, NULL, NULL);
if (wmode == NULL)
{
g_free (wfilename);
errno = EINVAL;
return NULL;
}
retval = _wfreopen (wfilename, wmode, stream);
save_errno = errno;
g_free (wfilename);
g_free (wmode);
errno = save_errno;
return retval;
}
static gboolean
init_dll_load_paths()
{
TCHAR path_w[MAX_PATH];
if (program_path && system_path)
return TRUE;
if (GetModuleFileName(NULL, path_w, MAX_PATH) == 0 || GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
return FALSE;
}
if (!program_path) {
gchar *app_path;
app_path = g_utf16_to_utf8(path_w, -1, NULL, NULL, NULL);
program_path = g_path_get_dirname(app_path);
g_free(app_path);
}
if (GetSystemDirectory(path_w, MAX_PATH) == 0) {
return FALSE;
}
if (!system_path) {
system_path = g_utf16_to_utf8(path_w, -1, NULL, NULL, NULL);
}
if (program_path && system_path)
return TRUE;
return FALSE;
}
gboolean
ws_init_dll_search_path()
{
gboolean dll_dir_set = FALSE;
wchar_t *program_path_w;
typedef BOOL (WINAPI *SetDllDirectoryHandler)(LPCTSTR);
SetDllDirectoryHandler PSetDllDirectory;
PSetDllDirectory = (SetDllDirectoryHandler) GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "SetDllDirectoryW");
if (PSetDllDirectory) {
dll_dir_set = PSetDllDirectory(_T(""));
}
if (!dll_dir_set && init_dll_load_paths()) {
program_path_w = g_utf8_to_utf16(program_path, -1, NULL, NULL, NULL);
SetCurrentDirectory(program_path_w);
g_free(program_path_w);
}
return dll_dir_set;
}
void *
ws_load_library(gchar *library_name)
{
gchar *full_path;
wchar_t *full_path_w;
HMODULE dll_h;
if (!init_dll_load_paths() || !library_name)
return NULL;
full_path = g_module_build_path(program_path, library_name);
full_path_w = g_utf8_to_utf16(full_path, -1, NULL, NULL, NULL);
if (full_path && full_path_w) {
dll_h = LoadLibraryW(full_path_w);
if (dll_h) {
g_free(full_path);
g_free(full_path_w);
return dll_h;
}
}
full_path = g_module_build_path(system_path, library_name);
full_path_w = g_utf8_to_utf16(full_path, -1, NULL, NULL, NULL);
if (full_path && full_path_w) {
dll_h = LoadLibraryW(full_path_w);
if (dll_h) {
g_free(full_path);
g_free(full_path_w);
return dll_h;
}
}
return NULL;
}
GModule *
ws_module_open(gchar *module_name, GModuleFlags flags)
{
gchar *full_path;
GModule *mod;
if (!init_dll_load_paths() || !module_name)
return NULL;
full_path = g_module_build_path(program_path, module_name);
if (full_path) {
mod = g_module_open(full_path, flags);
if (mod) {
g_free(full_path);
return mod;
}
}
full_path = g_module_build_path(system_path, module_name);
if (full_path) {
mod = g_module_open(full_path, flags);
if (mod) {
g_free(full_path);
return mod;
}
}
return NULL;
}
char *
getenv_utf8(const char *varname)
{
char *envvar;
wchar_t *envvarw;
wchar_t *varnamew;
envvar = getenv(varname);
varnamew = g_utf8_to_utf16(varname, -1, NULL, NULL, NULL);
if (varnamew == NULL) {
return envvar;
}
envvarw = _wgetenv(varnamew);
g_free(varnamew);
if (envvarw == NULL) {
return envvar;
}
envvar = g_utf16_to_utf8(envvarw, -1, NULL, NULL, NULL);
return envvar;
}
