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
datafile_dir = getenv("WIRESHARK_SRC_DIR");
if (datafile_dir != NULL)
return datafile_dir;
}
if (running_in_build_directory_flag && progfile_dir != NULL) {
datafile_dir = progfile_dir;
} else {
if (getenv("WIRESHARK_DATA_DIR") && !started_with_special_privs()) {
datafile_dir = g_strdup(getenv("WIRESHARK_DATA_DIR"));
} else {
datafile_dir = DATAFILE_DIR;
}
}
#endif
return datafile_dir;
}
static void
init_wspython_dir(void)
{
#ifdef _WIN32
wspython_dir = g_strdup_printf("%s\\python\\%s", get_datafile_dir(),
VERSION);
if (test_for_directory(wspython_dir) != EISDIR) {
g_free( (gpointer) wspython_dir);
wspython_dir = g_strdup_printf("%s\\python", get_datafile_dir());
running_in_build_directory_flag = TRUE;
}
#else
if (running_in_build_directory_flag) {
wspython_dir = g_strdup_printf("%s/epan/wspython/", get_datafile_dir());
} else {
if (getenv("WIRESHARK_PYTHON_DIR") && !started_with_special_privs()) {
wspython_dir = g_strdup(getenv("WIRESHARK_PYTHON_DIR"));
} else {
wspython_dir = PYTHON_DIR;
}
}
#endif
}
const char *
get_wspython_dir(void)
{
#ifdef HAVE_PYTHON
if (!wspython_dir) init_wspython_dir();
return wspython_dir;
#else
return NULL;
#endif
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
plugin_dir = g_strdup_printf("%s/plugins", get_datafile_dir());
} else {
if (getenv("WIRESHARK_PLUGIN_DIR") && !started_with_special_privs()) {
plugin_dir = g_strdup(getenv("WIRESHARK_PLUGIN_DIR"));
} else {
plugin_dir = PLUGIN_DIR;
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
char *appdatadir;
char *userprofiledir;
char *u3appdatapath;
#else
const char *homedir;
struct passwd *pwd;
#endif
if (persconffile_dir != NULL)
return persconffile_dir;
#ifdef _WIN32
u3appdatapath = getenv_utf8("U3_APP_DATA_PATH");
if (u3appdatapath != NULL) {
persconffile_dir = u3appdatapath;
} else {
appdatadir = getenv_utf8("APPDATA");
if (appdatadir != NULL) {
persconffile_dir = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s",
appdatadir, PF_DIR);
} else {
userprofiledir = getenv_utf8("USERPROFILE");
if (userprofiledir != NULL) {
persconffile_dir = g_strdup_printf(
"%s" G_DIR_SEPARATOR_S "Application Data" G_DIR_SEPARATOR_S "%s",
userprofiledir, PF_DIR);
} else {
persconffile_dir = g_strdup_printf("C:" G_DIR_SEPARATOR_S "%s", PF_DIR);
}
}
}
#else
homedir = getenv("HOME");
if (homedir == NULL) {
pwd = getpwuid(getuid());
if (pwd != NULL) {
homedir = pwd->pw_dir;
} else {
homedir = "/tmp";
}
}
persconffile_dir = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s", homedir, PF_DIR);
#endif
return persconffile_dir;
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
ret = ws_mkdir(pf_dir_path, 0755);
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
char *szPath;
BOOL bRet;
if (persdatafile_dir != NULL)
return persdatafile_dir;
u3devicedocumentpath = getenv_utf8("U3_DEVICE_DOCUMENT_PATH");
if (u3devicedocumentpath != NULL) {
szPath = g_strdup_printf("%s%s", u3devicedocumentpath, U3_MY_CAPTURES);
persdatafile_dir = szPath;
return szPath;
} else {
bRet = SHGetSpecialFolderPath(NULL, tszPath, CSIDL_PERSONAL,
FALSE);
if(bRet == TRUE) {
szPath = utf_16to8(tszPath);
persdatafile_dir = szPath;
return szPath;
} else {
return "";
}
}
#else
return "";
#endif
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
int
filesystem_opt(int opt _U_, const char *optstr)
{
gchar *p, *colonp;
colonp = strchr(optstr, ':');
if (colonp == NULL) {
return 1;
}
p = colonp;
*p++ = '\0';
while (isspace((guchar)*p))
p++;
if (*p == '\0') {
*colonp = ':';
return 1;
}
if(test_for_directory(p) != EISDIR) {
*colonp = ':';
return 1;
}
if (strcmp(optstr,"persconf") == 0) {
persconffile_dir = p;
} else if (strcmp(optstr,"persdata") == 0) {
persdatafile_dir = p;
} else {
return 1;
}
*colonp = ':';
return 0;
}
char *
get_datafile_path(const char *filename)
{
return g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s", get_datafile_dir(), filename);
}
char *
get_plugins_pers_dir(void)
{
return get_persconffile_path(PLUGINS_DIR_NAME, FALSE);
}
gboolean
deletefile(const char *path)
{
return ws_unlink(path) == 0;
}
char *get_tempfile_path(const char *filename)
{
return g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s", g_get_tmp_dir(), filename);
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
#ifdef _WIN32
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
