static int
mkstemps(char *path_template, int suffixlen)
{
static const char letters[]
= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char uniqueness[6];
size_t len;
size_t i;
len = strlen (path_template);
if (len < 6 || strncmp (&path_template[len - 6 - suffixlen], TMP_FILE_SUFFIX, 6))
{
__set_errno (EINVAL);
return -1;
}
if (g_snprintf (uniqueness, 6, "%.5u",
(unsigned int) ws_getpid () % 100000) != 5)
return -1;
memcpy(&path_template[len - 5 - suffixlen], uniqueness, 5);
for (i = 0; i < sizeof (letters); ++i)
{
int fd;
path_template[len - 6 - suffixlen] = letters[i];
fd = ws_open (path_template, O_RDWR|O_BINARY|O_CREAT|O_EXCL, 0600);
if (fd >= 0)
return fd;
}
path_template[0] = '\0';
return -1;
}
char *
mkdtemp (char *path_template)
{
static const char letters[]
= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
size_t len;
size_t i;
len = strlen (path_template);
if (len < 6 || strcmp (&path_template[len - 6], TMP_FILE_SUFFIX))
{
__set_errno (EINVAL);
return NULL;
}
if (g_snprintf (&path_template[len - 5], 6, "%.5u",
(unsigned int) ws_getpid () % 100000) != 5)
return NULL;
for (i = 0; i < sizeof (letters); ++i)
{
int ret;
path_template[len - 6] = letters[i];
ret = ws_mkdir(path_template, 0700);
if (ret >= 0)
return path_template;
}
path_template[0] = '\0';
return NULL;
}
char *get_tempfile_path(const char *filename)
{
return g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s", g_get_tmp_dir(), filename);
}
int
create_tempfile(char **namebuf, const char *pfx, const char *sfx)
{
static struct _tf {
char *path;
size_t len;
} tf[MAX_TEMPFILES];
static int idx;
const char *tmp_dir;
int old_umask;
int fd;
time_t current_time;
char timestr[14 + 1];
gchar *tmp_file;
gchar *safe_pfx;
gchar sep[2] = {0, 0};
const gchar *delimiters = "<>:\"/\\|?*"
"\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a"
"\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13\x14"
"\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f";
safe_pfx = g_strdup(pfx);
safe_pfx = g_strdelimit(safe_pfx, delimiters, '-');
idx = (idx + 1) % MAX_TEMPFILES;
if (tf[idx].path == NULL) {
tf[idx].len = INITIAL_PATH_SIZE;
tf[idx].path = (char *)g_malloc(tf[idx].len);
}
tmp_dir = g_get_tmp_dir();
#ifdef _WIN32
_tzset();
#endif
current_time = time(NULL);
strftime(timestr, sizeof(timestr), "%Y%m%d%H%M%S", localtime(&current_time));
sep[0] = G_DIR_SEPARATOR;
tmp_file = g_strconcat(tmp_dir, sep, safe_pfx, "_", timestr, "_", TMP_FILE_SUFFIX, sfx, NULL);
g_free(safe_pfx);
if (strlen(tmp_file) > tf[idx].len) {
tf[idx].len = strlen(tmp_file) + 1;
tf[idx].path = (char *)g_realloc(tf[idx].path, tf[idx].len);
}
g_strlcpy(tf[idx].path, tmp_file, tf[idx].len);
g_free(tmp_file);
if (namebuf) {
*namebuf = tf[idx].path;
}
old_umask = ws_umask(0077);
fd = mkstemps(tf[idx].path, sfx ? (int) strlen(sfx) : 0);
ws_umask(old_umask);
return fd;
}
const char *
create_tempdir(char **namebuf, const char *pfx)
{
static char *td_path[3];
static int td_path_len[3];
static int idx;
const char *tmp_dir;
idx = (idx + 1) % 3;
if (td_path[idx] == NULL) {
td_path_len[idx] = INITIAL_PATH_SIZE;
td_path[idx] = (char *)g_malloc(td_path_len[idx]);
}
tmp_dir = g_get_tmp_dir();
while (g_snprintf(td_path[idx], td_path_len[idx], "%s%c%s" TMP_FILE_SUFFIX, tmp_dir, G_DIR_SEPARATOR, pfx) > td_path_len[idx]) {
td_path_len[idx] *= 2;
td_path[idx] = (char *)g_realloc(td_path[idx], td_path_len[idx]);
}
if (namebuf) {
*namebuf = td_path[idx];
}
return mkdtemp(td_path[idx]);
}
