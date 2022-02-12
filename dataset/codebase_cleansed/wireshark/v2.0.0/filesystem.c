char *
find_last_pathname_separator(const char *path)
{
char *separator;
#ifdef _WIN32
char c;
separator = strchr(path, '\0');
while (separator > path) {
c = *--separator;
if (c == '\\' || c == '/')
return separator;
}
return strchr(path, ':');
#else
separator = strrchr(path, '/');
return separator;
#endif
}
const char *
get_basename(const char *path)
{
const char *filename;
g_assert(path != NULL);
filename = find_last_pathname_separator(path);
if (filename == NULL) {
filename = path;
} else {
filename++;
}
return filename;
}
char *
get_dirname(char *path)
{
char *separator;
g_assert(path != NULL);
separator = find_last_pathname_separator(path);
if (separator == NULL) {
return NULL;
}
*separator = '\0';
return path;
}
int
test_for_directory(const char *path)
{
ws_statb64 statb;
if (ws_stat64(path, &statb) < 0)
return errno;
if (S_ISDIR(statb.st_mode))
return EISDIR;
else
return 0;
}
int
test_for_fifo(const char *path)
{
ws_statb64 statb;
if (ws_stat64(path, &statb) < 0)
return errno;
if (S_ISFIFO(statb.st_mode))
return ESPIPE;
else
return 0;
}
static const char *
get_executable_path(void)
{
#if defined(__APPLE__)
char *executable_path;
uint32_t path_buf_size;
path_buf_size = PATH_MAX;
executable_path = (char *)g_malloc(path_buf_size);
if (_NSGetExecutablePath(executable_path, &path_buf_size) == -1) {
executable_path = (char *)g_realloc(executable_path, path_buf_size);
if (_NSGetExecutablePath(executable_path, &path_buf_size) == -1)
return NULL;
}
return executable_path;
#elif defined(__linux__)
struct utsname name;
static char executable_path[PATH_MAX + 1];
ssize_t r;
if (uname(&name) == -1)
return NULL;
if (strncmp(name.release, "1.", 2) == 0)
return NULL;
if (strcmp(name.release, "2.0") == 0 ||
strncmp(name.release, "2.0.", 4) == 0 ||
strcmp(name.release, "2.1") == 0 ||
strncmp(name.release, "2.1.", 4) == 0)
return NULL;
if ((r = readlink("/proc/self/exe", executable_path, PATH_MAX)) == -1)
return NULL;
executable_path[r] = '\0';
return executable_path;
#elif defined(__FreeBSD__) && defined(KERN_PROC_PATHNAME)
int mib[4];
char *executable_path;
size_t path_buf_size;
mib[0] = CTL_KERN;
mib[1] = KERN_PROC;
mib[2] = KERN_PROC_PATHNAME;
mib[3] = -1;
path_buf_size = PATH_MAX;
executable_path = (char *)g_malloc(path_buf_size);
if (sysctl(mib, 4, executable_path, &path_buf_size, NULL, 0) == -1) {
if (errno != ENOMEM)
return NULL;
executable_path = (char *)g_realloc(executable_path, path_buf_size);
if (sysctl(mib, 4, executable_path, &path_buf_size, NULL, 0) == -1)
return NULL;
}
return executable_path;
#elif defined(__NetBSD__)
static char executable_path[PATH_MAX + 1];
ssize_t r;
if ((r = readlink("/proc/curproc/exe", executable_path, PATH_MAX)) == -1)
return NULL;
executable_path[r] = '\0';
return executable_path;
#elif defined(__DragonFly__)
static char executable_path[PATH_MAX + 1];
ssize_t r;
if ((r = readlink("/proc/curproc/file", executable_path, PATH_MAX)) == -1)
return NULL;
executable_path[r] = '\0';
return executable_path;
#elif (defined(sun) || defined(__sun)) && defined(HAVE_GETEXECNAME)
return getexecname();
#else
return NULL;
#endif
}
char *
init_progfile_dir(const char *arg0
#ifdef _WIN32
_U_
#endif
, void *function_addr
#if defined(_WIN32) || !defined(HAVE_DLADDR)
_U_
#endif
)
{
#ifdef _WIN32
TCHAR prog_pathname_w[_MAX_PATH+2];
char *prog_pathname;
DWORD error;
TCHAR *msg_w;
guchar *msg;
size_t msglen;
if (GetModuleFileName(NULL, prog_pathname_w, G_N_ELEMENTS(prog_pathname_w)) != 0 && GetLastError() != ERROR_INSUFFICIENT_BUFFER) {
prog_pathname = utf_16to8(prog_pathname_w);
progfile_dir = g_path_get_dirname(prog_pathname);
if (progfile_dir != NULL) {
return NULL;
} else {
return g_strdup_printf("No \\ in executable pathname \"%s\"",
prog_pathname);
}
} else {
error = GetLastError();
if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS,
NULL, error, 0, (LPTSTR) &msg_w, 0, NULL) == 0) {
return g_strdup_printf("GetModuleFileName failed: %u (FormatMessage failed: %u)",
error, GetLastError());
}
msg = utf_16to8(msg_w);
LocalFree(msg_w);
msglen = strlen(msg);
if (msglen >= 2) {
msg[msglen - 1] = '\0';
msg[msglen - 2] = '\0';
}
return g_strdup_printf("GetModuleFileName failed: %s (%u)",
msg, error);
}
#else
#ifdef HAVE_DLADDR
Dl_info info;
#endif
const char *execname;
char *prog_pathname;
char *curdir;
long path_max;
char *pathstr;
char *path_start, *path_end;
size_t path_component_len, path_len;
char *retstr;
char *path;
char *dir_end;
if (getenv("WIRESHARK_RUN_FROM_BUILD_DIRECTORY") != NULL
&& !started_with_special_privs())
running_in_build_directory_flag = TRUE;
execname = get_executable_path();
#ifdef HAVE_DLADDR
if (function_addr != NULL && execname == NULL) {
if (dladdr(function_addr, &info))
execname = info.dli_fname;
}
#endif
if (execname == NULL) {
execname = arg0;
}
if (execname[0] == '/') {
prog_pathname = g_strdup(execname);
} else if (strchr(execname, '/') != NULL) {
path_max = pathconf(".", _PC_PATH_MAX);
if (path_max == -1) {
return g_strdup_printf("pathconf failed: %s\n",
g_strerror(errno));
}
curdir = (char *)g_malloc(path_max);
if (getcwd(curdir, path_max) == NULL) {
g_free(curdir);
return g_strdup_printf("getcwd failed: %s\n",
g_strerror(errno));
}
path = g_strdup_printf("%s/%s", curdir, execname);
g_free(curdir);
prog_pathname = path;
} else {
prog_pathname = NULL;
pathstr = getenv("PATH");
path_start = pathstr;
if (path_start != NULL) {
while (*path_start != '\0') {
path_end = strchr(path_start, ':');
if (path_end == NULL)
path_end = path_start + strlen(path_start);
path_component_len = path_end - path_start;
path_len = path_component_len + 1
+ strlen(execname) + 1;
path = (char *)g_malloc(path_len);
memcpy(path, path_start, path_component_len);
path[path_component_len] = '\0';
g_strlcat(path, "/", path_len);
g_strlcat(path, execname, path_len);
if (access(path, X_OK) == 0) {
prog_pathname = path;
break;
}
if (*path_end == '\0') {
break;
}
if (*path_end == ':')
path_end++;
path_start = path_end;
g_free(path);
}
if (prog_pathname == NULL) {
return g_strdup_printf("\"%s\" not found in \"%s\"",
execname, pathstr);
}
} else {
return g_strdup("PATH isn't set");
}
}
dir_end = strrchr(prog_pathname, '/');
if (dir_end != NULL) {
*dir_end = '\0';
dir_end = strrchr(prog_pathname, '/');
if (dir_end != NULL) {
if (strcmp(dir_end, "/.libs") == 0) {
*dir_end = '\0';
if (!started_with_special_privs())
running_in_build_directory_flag = TRUE;
}
#ifdef __APPLE__
else {
if (!started_with_special_privs()) {
char *component_end, *p;
component_end = strchr(prog_pathname, '\0');
p = component_end;
for (;;) {
while (p >= prog_pathname && *p != '/')
p--;
if (p == prog_pathname) {
break;
}
if (strncmp(p, "/Contents", component_end - p) == 0) {
appbundle_dir = (char *)g_malloc(p - prog_pathname + 1);
memcpy(appbundle_dir, prog_pathname, p - prog_pathname);
appbundle_dir[p - prog_pathname] = '\0';
break;
}
component_end = p;
p--;
}
}
}
#endif
}
progfile_dir = prog_pathname;
return NULL;
} else {
retstr = g_strdup_printf("No / found in \"%s\"", prog_pathname);
g_free(prog_pathname);
return retstr;
}
#endif
}
const char *
get_progfile_dir(void)
{
return progfile_dir;
}
const char *
get_datafile_dir(void)
{
#ifdef _WIN32
char *u3deviceexecpath;
#endif
static const char *datafile_dir = NULL;
if (datafile_dir != NULL)
return datafile_dir;
#ifdef _WIN32
u3deviceexecpath = getenv_utf8("U3_DEVICE_EXEC_PATH");
if (u3deviceexecpath != NULL) {
datafile_dir = u3deviceexecpath;
} else {
if (progfile_dir != NULL) {
datafile_dir = progfile_dir;
} else {
datafile_dir = "C:\\Program Files\\Wireshark\\";
}
}
#else
if (running_in_build_directory_flag) {
datafile_dir = g_strdup(TOP_SRCDIR);
return datafile_dir;
} else {
if (getenv("WIRESHARK_DATA_DIR") && !started_with_special_privs()) {
datafile_dir = g_strdup(getenv("WIRESHARK_DATA_DIR"));
}
#ifdef __APPLE__
else if (appbundle_dir != NULL) {
datafile_dir = g_strdup_printf("%s/Contents/Resources/share/wireshark",
appbundle_dir);
}
#endif
else {
datafile_dir = DATAFILE_DIR;
}
}
#endif
return datafile_dir;
}
static void
init_plugin_dir(void)
{
#ifdef _WIN32
plugin_dir = g_strdup_printf("%s\\plugins\\%s", get_datafile_dir(),
VERSION);
if (test_for_directory(plugin_dir) != EISDIR) {
g_free( (gpointer) plugin_dir);
plugin_dir = g_strdup_printf("%s\\plugins", get_datafile_dir());
running_in_build_directory_flag = TRUE;
}
#else
if (running_in_build_directory_flag) {
plugin_dir = g_strdup_printf("%s/plugins", get_progfile_dir());
} else {
if (getenv("WIRESHARK_PLUGIN_DIR") && !started_with_special_privs()) {
plugin_dir = g_strdup(getenv("WIRESHARK_PLUGIN_DIR"));
}
#ifdef __APPLE__
else if (appbundle_dir != NULL) {
plugin_dir = g_strdup_printf("%s/Contents/PlugIns/wireshark",
appbundle_dir);
}
#endif
else {
plugin_dir = PLUGIN_INSTALL_DIR;
}
}
#endif
}
const char *
get_plugin_dir(void)
{
#if defined(HAVE_PLUGINS) || defined(HAVE_LUA)
if (!plugin_dir) init_plugin_dir();
return plugin_dir;
#else
return NULL;
#endif
}
static void init_extcap_dir(void) {
#ifdef _WIN32
char *alt_extcap_path;
alt_extcap_path = getenv_utf8("WIRESHARK_EXTCAP_DIR");
if (alt_extcap_path) {
extcap_dir = g_strdup(alt_extcap_path);
} else {
extcap_dir = g_strdup_printf("%s\\extcap", get_datafile_dir());
}
#else
if (running_in_build_directory_flag) {
extcap_dir = g_strdup_printf("%s/extcap", get_progfile_dir());
} else {
if (getenv("WIRESHARK_EXTCAP_DIR") && !started_with_special_privs()) {
extcap_dir = g_strdup(getenv("WIRESHARK_EXTCAP_DIR"));
}
#ifdef __APPLE__
else if (appbundle_dir != NULL) {
extcap_dir = g_strdup_printf("%s/Contents/MacOS/extcap",
appbundle_dir);
}
#endif
else {
extcap_dir = EXTCAP_DIR;
}
}
#endif
}
const char *
get_extcap_dir(void) {
#if defined(HAVE_EXTCAP)
if (!extcap_dir)
init_extcap_dir();
return extcap_dir;
#else
return NULL;
#endif
}
gboolean
running_in_build_directory(void)
{
return running_in_build_directory_flag;
}
const char *
get_systemfile_dir(void)
{
#ifdef _WIN32
return get_datafile_dir();
#else
return "/etc";
#endif
}
void
set_profile_name(const gchar *profilename)
{
g_free (persconfprofile);
if (profilename && strlen(profilename) > 0 &&
strcmp(profilename, DEFAULT_PROFILE) != 0) {
persconfprofile = g_strdup (profilename);
} else {
persconfprofile = NULL;
}
}
const char *
get_profile_name(void)
{
if (persconfprofile) {
return persconfprofile;
} else {
return DEFAULT_PROFILE;
}
}
gboolean
is_default_profile(void)
{
return (!persconfprofile || strcmp(persconfprofile, DEFAULT_PROFILE) == 0) ? TRUE : FALSE;
}
gboolean
has_global_profiles(void)
{
WS_DIR *dir;
WS_DIRENT *file;
const gchar *global_dir = get_global_profiles_dir();
gchar *filename;
gboolean has_global = FALSE;
if ((test_for_directory(global_dir) == EISDIR) &&
((dir = ws_dir_open(global_dir, 0, NULL)) != NULL))
{
while ((file = ws_dir_read_name(dir)) != NULL) {
filename = g_strdup_printf ("%s%s%s", global_dir, G_DIR_SEPARATOR_S,
ws_dir_get_name(file));
if (test_for_directory(filename) == EISDIR) {
has_global = TRUE;
g_free (filename);
break;
}
g_free (filename);
}
ws_dir_close(dir);
}
return has_global;
}
void
profile_store_persconffiles(gboolean store)
{
if (store) {
profile_files = g_hash_table_new (g_str_hash, g_str_equal);
}
do_store_persconffiles = store;
}
static const char *
get_persconffile_dir_no_profile(void)
{
#ifdef _WIN32
const char *env;
#else
char *xdg_path, *path;
struct passwd *pwd;
const char *homedir;
#endif
if (persconffile_dir != NULL)
return persconffile_dir;
#ifdef _WIN32
env = getenv_utf8("WIRESHARK_APPDATA");
if (env != NULL) {
persconffile_dir = g_strdup(env);
return persconffile_dir;
}
env = getenv_utf8("U3_APP_DATA_PATH");
if (env != NULL) {
persconffile_dir = g_strdup(env);
return persconffile_dir;
}
env = getenv_utf8("APPDATA");
if (env != NULL) {
persconffile_dir = g_build_filename(env, "Wireshark", NULL);
return persconffile_dir;
}
env = getenv_utf8("USERPROFILE");
if (env != NULL) {
persconffile_dir = g_build_filename(env, "Application Data", "Wireshark", NULL);
return persconffile_dir;
}
persconffile_dir = g_build_filename("C:", "Wireshark", NULL);
return persconffile_dir;
#else
xdg_path = g_build_filename(g_get_user_config_dir(), "wireshark", NULL);
if (g_file_test(xdg_path, G_FILE_TEST_IS_DIR)) {
persconffile_dir = xdg_path;
return persconffile_dir;
}
homedir = getenv("HOME");
if (homedir == NULL) {
pwd = getpwuid(getuid());
if (pwd != NULL) {
homedir = pwd->pw_dir;
} else {
homedir = "/tmp";
}
}
path = g_build_filename(homedir, ".wireshark", NULL);
if (g_file_test(path, G_FILE_TEST_IS_DIR)) {
g_free(xdg_path);
persconffile_dir = path;
return persconffile_dir;
}
g_free(path);
persconffile_dir = xdg_path;
return persconffile_dir;
#endif
}
void
set_persconffile_dir(const char *p)
{
g_free(persconffile_dir);
persconffile_dir = g_strdup(p);
}
const char *
get_profiles_dir(void)
{
static char *profiles_dir = NULL;
g_free (profiles_dir);
profiles_dir = g_strdup_printf ("%s%s%s", get_persconffile_dir_no_profile (),
G_DIR_SEPARATOR_S, PROFILES_DIR);
return profiles_dir;
}
const char *
get_global_profiles_dir(void)
{
static char *global_profiles_dir = NULL;
if (!global_profiles_dir) {
global_profiles_dir = g_strdup_printf ("%s%s%s", get_datafile_dir(),
G_DIR_SEPARATOR_S, PROFILES_DIR);
}
return global_profiles_dir;
}
static const char *
get_persconffile_dir(const gchar *profilename)
{
static char *persconffile_profile_dir = NULL;
g_free (persconffile_profile_dir);
if (profilename && strlen(profilename) > 0 &&
strcmp(profilename, DEFAULT_PROFILE) != 0) {
persconffile_profile_dir = g_strdup_printf ("%s%s%s", get_profiles_dir (),
G_DIR_SEPARATOR_S, profilename);
} else {
persconffile_profile_dir = g_strdup (get_persconffile_dir_no_profile ());
}
return persconffile_profile_dir;
}
gboolean
profile_exists(const gchar *profilename, gboolean global)
{
if (global) {
gchar *path = g_strdup_printf ("%s%s%s", get_global_profiles_dir(),
G_DIR_SEPARATOR_S, profilename);
if (test_for_directory (path) == EISDIR) {
g_free (path);
return TRUE;
}
g_free (path);
} else {
if (test_for_directory (get_persconffile_dir (profilename)) == EISDIR) {
return TRUE;
}
}
return FALSE;
}
static int
delete_directory (const char *directory, char **pf_dir_path_return)
{
WS_DIR *dir;
WS_DIRENT *file;
gchar *filename;
int ret = 0;
if ((dir = ws_dir_open(directory, 0, NULL)) != NULL) {
while ((file = ws_dir_read_name(dir)) != NULL) {
filename = g_strdup_printf ("%s%s%s", directory, G_DIR_SEPARATOR_S,
ws_dir_get_name(file));
if (test_for_directory(filename) != EISDIR) {
ret = ws_remove(filename);
#if 0
} else {
ret = delete_directory (filename, pf_dir_path_return);
#endif
}
if (ret != 0) {
*pf_dir_path_return = filename;
break;
}
g_free (filename);
}
ws_dir_close(dir);
}
if (ret == 0 && (ret = ws_remove(directory)) != 0) {
*pf_dir_path_return = g_strdup (directory);
}
return ret;
}
int
delete_persconffile_profile(const char *profilename, char **pf_dir_path_return)
{
const char *profile_dir = get_persconffile_dir(profilename);
int ret = 0;
if (test_for_directory (profile_dir) == EISDIR) {
ret = delete_directory (profile_dir, pf_dir_path_return);
}
return ret;
}
int
rename_persconffile_profile(const char *fromname, const char *toname,
char **pf_from_dir_path_return, char **pf_to_dir_path_return)
{
char *from_dir = g_strdup (get_persconffile_dir(fromname));
char *to_dir = g_strdup (get_persconffile_dir(toname));
int ret = 0;
ret = ws_rename (from_dir, to_dir);
if (ret != 0) {
*pf_from_dir_path_return = g_strdup (from_dir);
*pf_to_dir_path_return = g_strdup (to_dir);
}
g_free (from_dir);
g_free (to_dir);
return ret;
}
int
create_persconffile_profile(const char *profilename, char **pf_dir_path_return)
{
const char *pf_dir_path;
#ifdef _WIN32
char *pf_dir_path_copy, *pf_dir_parent_path;
size_t pf_dir_parent_path_len;
#endif
ws_statb64 s_buf;
int ret;
if (profilename) {
if (create_persconffile_profile (NULL, pf_dir_path_return) == -1) {
return -1;
}
pf_dir_path = get_profiles_dir ();
if (ws_stat64(pf_dir_path, &s_buf) != 0 && errno == ENOENT) {
ret = ws_mkdir(pf_dir_path, 0755);
if (ret == -1) {
*pf_dir_path_return = g_strdup(pf_dir_path);
return ret;
}
}
}
pf_dir_path = get_persconffile_dir(profilename);
if (ws_stat64(pf_dir_path, &s_buf) != 0 && errno == ENOENT) {
#ifdef _WIN32
pf_dir_path_copy = g_strdup(pf_dir_path);
pf_dir_parent_path = get_dirname(pf_dir_path_copy);
pf_dir_parent_path_len = strlen(pf_dir_parent_path);
if (pf_dir_parent_path_len > 0
&& pf_dir_parent_path[pf_dir_parent_path_len - 1] != ':'
&& ws_stat64(pf_dir_parent_path, &s_buf) != 0) {
ret = ws_mkdir(pf_dir_parent_path, 0755);
if (ret == -1) {
*pf_dir_path_return = pf_dir_parent_path;
return -1;
}
}
g_free(pf_dir_path_copy);
ret = ws_mkdir(pf_dir_path, 0755);
#else
ret = g_mkdir_with_parents(pf_dir_path, 0755);
#endif
} else {
ret = 0;
}
if (ret == -1)
*pf_dir_path_return = g_strdup(pf_dir_path);
return ret;
}
int
create_persconffile_dir(char **pf_dir_path_return)
{
return create_persconffile_profile(persconfprofile, pf_dir_path_return);
}
int
copy_persconffile_profile(const char *toname, const char *fromname, gboolean from_global,
char **pf_filename_return, char **pf_to_dir_path_return, char **pf_from_dir_path_return)
{
gchar *from_dir;
gchar *to_dir = g_strdup (get_persconffile_dir(toname));
gchar *filename, *from_file, *to_file;
GList *files, *file;
if (from_global) {
if (strcmp(fromname, DEFAULT_PROFILE) == 0) {
from_dir = g_strdup (get_global_profiles_dir());
} else {
from_dir = g_strdup_printf ("%s%s%s", get_global_profiles_dir(), G_DIR_SEPARATOR_S, fromname);
}
} else {
from_dir = g_strdup (get_persconffile_dir(fromname));
}
files = g_hash_table_get_keys(profile_files);
file = g_list_first(files);
while (file) {
filename = (gchar *)file->data;
from_file = g_strdup_printf ("%s%s%s", from_dir, G_DIR_SEPARATOR_S, filename);
to_file = g_strdup_printf ("%s%s%s", to_dir, G_DIR_SEPARATOR_S, filename);
if (file_exists(from_file) && !copy_file_binary_mode(from_file, to_file)) {
*pf_filename_return = g_strdup(filename);
*pf_to_dir_path_return = to_dir;
*pf_from_dir_path_return = from_dir;
g_free (from_file);
g_free (to_file);
return -1;
}
g_free (from_file);
g_free (to_file);
file = g_list_next(file);
}
g_list_free (files);
g_free (from_dir);
g_free (to_dir);
return 0;
}
extern const char *
get_persdatafile_dir(void)
{
#ifdef _WIN32
char *u3devicedocumentpath;
TCHAR tszPath[MAX_PATH];
if (persdatafile_dir != NULL)
return persdatafile_dir;
u3devicedocumentpath = getenv_utf8("U3_DEVICE_DOCUMENT_PATH");
if (u3devicedocumentpath != NULL) {
persdatafile_dir = g_strdup_printf("%s%s", u3devicedocumentpath, U3_MY_CAPTURES);
return persdatafile_dir;
} else {
if (SHGetSpecialFolderPath(NULL, tszPath, CSIDL_PERSONAL, FALSE)) {
persdatafile_dir = g_utf16_to_utf8(tszPath, -1, NULL, NULL, NULL);
return persdatafile_dir;
} else {
return "";
}
}
#else
return "";
#endif
}
void
set_persdatafile_dir(const char *p)
{
g_free(persdatafile_dir);
persdatafile_dir = g_strdup(p);
}
static const char *
get_home_dir(void)
{
static const char *home = NULL;
char *homedrive, *homepath;
char *homestring;
char *lastsep;
if (home)
return home;
homedrive = getenv_utf8("HOMEDRIVE");
if (homedrive != NULL) {
homepath = getenv_utf8("HOMEPATH");
if (homepath != NULL) {
homestring = g_strdup_printf("%s%s", homedrive, homepath);
lastsep = find_last_pathname_separator(homestring);
if (lastsep != NULL && *(lastsep + 1) == '\0') {
*lastsep = '\0';
}
home = homestring;
} else
home = homedrive;
} else {
home = "C:";
}
return home;
}
char *
get_persconffile_path(const char *filename, gboolean from_profile)
{
char *path;
if (do_store_persconffiles && from_profile && !g_hash_table_lookup (profile_files, filename)) {
g_hash_table_insert (profile_files, g_strdup(filename), g_strdup(filename));
}
if (from_profile) {
path = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s",
get_persconffile_dir(persconfprofile), filename);
} else {
path = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s",
get_persconffile_dir(NULL), filename);
}
return path;
}
char *
get_datafile_path(const char *filename)
{
if (running_in_build_directory_flag &&
(!strcmp(filename, "AUTHORS-SHORT") ||
!strcmp(filename, "hosts"))) {
return g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s", get_progfile_dir(), filename);
} else {
return g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s", get_datafile_dir(), filename);
}
}
char *
get_plugins_pers_dir(void)
{
return get_persconffile_path(PLUGINS_DIR_NAME, FALSE);
}
const char *
file_open_error_message(int err, gboolean for_writing)
{
const char *errmsg;
static char errmsg_errno[1024+1];
switch (err) {
case ENOENT:
if (for_writing)
errmsg = "The path to the file \"%s\" doesn't exist.";
else
errmsg = "The file \"%s\" doesn't exist.";
break;
case EACCES:
if (for_writing)
errmsg = "You don't have permission to create or write to the file \"%s\".";
else
errmsg = "You don't have permission to read the file \"%s\".";
break;
case EISDIR:
errmsg = "\"%s\" is a directory (folder), not a file.";
break;
case ENOSPC:
errmsg = "The file \"%s\" could not be created because there is no space left on the file system.";
break;
#ifdef EDQUOT
case EDQUOT:
errmsg = "The file \"%s\" could not be created because you are too close to, or over, your disk quota.";
break;
#endif
case EINVAL:
errmsg = "The file \"%s\" could not be created because an invalid filename was specified.";
break;
case ENOMEM:
#if GLIB_SIZEOF_VOID_P == 4
#define ENOMEM_REASON "it can't be handled by a 32-bit application"
#else
#if defined(_WIN32)
#define ENOMEM_REASON "the pagefile is too small"
#elif defined(__APPLE__)
#define ENOMEM_REASON "your system ran out of swap file space"
#else
#define ENOMEM_REASON "your system is out of swap space"
#endif
#endif
if (for_writing)
errmsg = "The file \"%s\" could not be created because " ENOMEM_REASON ".";
else
errmsg = "The file \"%s\" could not be opened because " ENOMEM_REASON ".";
break;
default:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" could not be %s: %s.",
for_writing ? "created" : "opened",
g_strerror(err));
errmsg = errmsg_errno;
break;
}
return errmsg;
}
const char *
file_write_error_message(int err)
{
const char *errmsg;
static char errmsg_errno[1024+1];
switch (err) {
case ENOSPC:
errmsg = "The file \"%s\" could not be saved because there is no space left on the file system.";
break;
#ifdef EDQUOT
case EDQUOT:
errmsg = "The file \"%s\" could not be saved because you are too close to, or over, your disk quota.";
break;
#endif
default:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"An error occurred while writing to the file \"%%s\": %s.",
g_strerror(err));
errmsg = errmsg_errno;
break;
}
return errmsg;
}
gboolean
file_exists(const char *fname)
{
ws_statb64 file_stat;
if (!fname) {
return FALSE;
}
#if defined(_MSC_VER) && _MSC_VER < 1900
file_stat.st_ino = 1;
ws_stat64(fname, &file_stat);
if (file_stat.st_ino == 0) {
return TRUE;
} else {
return FALSE;
}
#else
if (ws_stat64(fname, &file_stat) != 0 && errno == ENOENT) {
return FALSE;
} else {
return TRUE;
}
#endif
}
gboolean
files_identical(const char *fname1, const char *fname2)
{
#ifdef _WIN32
char full1[MAX_PATH], full2[MAX_PATH];
if( _fullpath( full1, fname1, MAX_PATH ) == NULL ) {
return FALSE;
}
if( _fullpath( full2, fname2, MAX_PATH ) == NULL ) {
return FALSE;
}
if(strcmp(full1, full2) == 0) {
return TRUE;
} else {
return FALSE;
}
#else
ws_statb64 filestat1, filestat2;
if (ws_stat64(fname1, &filestat1) == -1)
return FALSE;
if (ws_stat64(fname2, &filestat2) == -1)
return FALSE;
return (filestat1.st_dev == filestat2.st_dev &&
filestat1.st_ino == filestat2.st_ino);
#endif
}
gboolean
copy_file_binary_mode(const char *from_filename, const char *to_filename)
{
int from_fd, to_fd, err;
ssize_t nread, nwritten;
guint8 *pd = NULL;
from_fd = ws_open(from_filename, O_RDONLY | O_BINARY, 0000 );
if (from_fd < 0) {
report_open_failure(from_filename, errno, FALSE);
goto done;
}
to_fd = ws_open(to_filename, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, 0644);
if (to_fd < 0) {
report_open_failure(to_filename, errno, TRUE);
ws_close(from_fd);
goto done;
}
#define FS_READ_SIZE 65536
pd = (guint8 *)g_malloc(FS_READ_SIZE);
while ((nread = ws_read(from_fd, pd, FS_READ_SIZE)) > 0) {
nwritten = ws_write(to_fd, pd, nread);
if (nwritten < nread) {
if (nwritten < 0)
err = errno;
else
err = WTAP_ERR_SHORT_WRITE;
report_write_failure(to_filename, err);
ws_close(from_fd);
ws_close(to_fd);
goto done;
}
}
if (nread < 0) {
err = errno;
report_read_failure(from_filename, err);
ws_close(from_fd);
ws_close(to_fd);
goto done;
}
ws_close(from_fd);
if (ws_close(to_fd) < 0) {
report_write_failure(to_filename, errno);
goto done;
}
g_free(pd);
pd = NULL;
return TRUE;
done:
g_free(pd);
return FALSE;
}
