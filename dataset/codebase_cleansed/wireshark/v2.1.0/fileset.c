gboolean
fileset_filename_match_pattern(const char *fname)
{
char *pfx;
size_t baselen;
size_t minlen = strlen("_00001_20050418010750");
char *filename;
filename = g_strdup(get_basename(fname));
pfx = strrchr(filename, '.');
if(pfx == NULL) {
pfx = filename + strlen(filename);
}
*pfx = '\0';
baselen = strlen(filename);
if(baselen < minlen) {
g_free(filename);
return FALSE;
}
if(filename[baselen-minlen] != '_' || filename[baselen-minlen+6] != '_') {
g_free(filename);
return FALSE;
}
filename[baselen-minlen] = '0';
filename[baselen-minlen+6] = '0';
while(minlen--) {
baselen--;
if(!g_ascii_isdigit( filename[baselen])) {
g_free(filename);
return FALSE;
}
}
g_free(filename);
return TRUE;
}
static gboolean
fileset_is_file_in_set(const char *fname1, const char *fname2)
{
char *pfx1;
char *pfx2;
char *dup_f1;
char *dup_f2;
size_t minlen = strlen("_00001_20050418010750");
g_assert(fileset_filename_match_pattern(fname1));
g_assert(fileset_filename_match_pattern(fname2));
dup_f1 = g_strdup(fname1);
dup_f2 = g_strdup(fname2);
pfx1 = strrchr(dup_f1, '.');
pfx2 = strrchr(dup_f2, '.');
if (!pfx1) pfx1 = dup_f1 + strlen(dup_f1);
if (!pfx2) pfx2 = dup_f2 + strlen(dup_f2);
if(strcmp(pfx1, pfx2) != 0) {
g_free(dup_f1);
g_free(dup_f2);
return FALSE;
}
*(pfx1-minlen) = '\0';
*(pfx2-minlen) = '\0';
if(strcmp(dup_f1, dup_f2) != 0) {
g_free(dup_f1);
g_free(dup_f2);
return FALSE;
}
g_free(dup_f1);
g_free(dup_f2);
return TRUE;
}
static gint
fileset_find_by_path(gconstpointer a, gconstpointer b)
{
const fileset_entry *entry;
const char *path;
entry = (const fileset_entry *) a;
path = (const char *) b;
return g_strcmp0(entry->fullname, path);
}
void
fileset_update_file(const char *path)
{
int fh, result;
ws_statb64 buf;
fileset_entry *entry = NULL;
GList *entry_list;
fh = ws_open( path, O_RDONLY, 0000 );
if(fh != -1) {
result = ws_fstat64( fh, &buf );
if( result == 0 ) {
entry_list = g_list_find_custom(set.entries, path,
fileset_find_by_path);
if (entry_list) {
entry = (fileset_entry *) entry_list->data;
entry->ctime = buf.st_ctime;
entry->mtime = buf.st_mtime;
entry->size = buf.st_size;
}
}
ws_close(fh);
}
}
static fileset_entry *
fileset_add_file(const char *dirname, const char *fname, gboolean current)
{
int fh, result;
ws_statb64 buf;
char *path;
fileset_entry *entry = NULL;
path = g_strdup_printf("%s%s", dirname, fname);
fh = ws_open( path, O_RDONLY, 0000 );
if(fh != -1) {
result = ws_fstat64( fh, &buf );
if( result == 0 ) {
entry = (fileset_entry *)g_malloc(sizeof(fileset_entry));
entry->fullname = g_strdup(path);
entry->name = g_strdup(fname);
entry->ctime = buf.st_ctime;
entry->mtime = buf.st_mtime;
entry->size = buf.st_size;
entry->current = current;
set.entries = g_list_append(set.entries, entry);
}
ws_close(fh);
}
g_free(path);
return entry;
}
static gint
fileset_sort_compare(gconstpointer a, gconstpointer b)
{
const fileset_entry *entry_a = (const fileset_entry *)a;
const fileset_entry *entry_b = (const fileset_entry *)b;
return strcmp(entry_a->name, entry_b->name);
}
void fileset_update_dlg(void *window)
{
GList *le;
le = g_list_first(set.entries);
while(le) {
fileset_dlg_add_file((fileset_entry *)le->data, window);
le = g_list_next(le);
}
}
void
fileset_add_dir(const char *fname, void *window)
{
WS_DIR *dir;
WS_DIRENT *file;
const char *name;
GString *dirname;
gchar *fname_dup;
fname_dup = g_strdup(fname);
dirname = g_string_new(get_dirname(fname_dup));
g_free(fname_dup);
set.dirname = g_strdup(dirname->str);
dirname = g_string_append_c(dirname, G_DIR_SEPARATOR);
if(fileset_filename_match_pattern(fname)) {
if ((dir = ws_dir_open(dirname->str, 0, NULL)) != NULL) {
while ((file = ws_dir_read_name(dir)) != NULL) {
name = ws_dir_get_name(file);
if(fileset_filename_match_pattern(name) && fileset_is_file_in_set(name, get_basename(fname))) {
fileset_add_file(dirname->str, name, strcmp(name, get_basename(fname))== 0 );
}
}
ws_dir_close(dir);
}
} else {
fileset_add_file(dirname->str, get_basename(fname), TRUE );
}
g_string_free(dirname, TRUE );
set.entries = g_list_sort(set.entries, fileset_sort_compare);
fileset_update_dlg(window);
}
const char *
fileset_get_dirname(void)
{
return set.dirname;
}
static GList *
fileset_get_current(void)
{
GList *le;
fileset_entry *entry;
le = g_list_first(set.entries);
while(le) {
entry = (fileset_entry *)le->data;
if(entry->current) {
return le;
}
le = g_list_next(le);
}
return NULL;
}
fileset_entry *
fileset_get_next(void)
{
GList *le;
le = fileset_get_current();
if(le == NULL) {
return NULL;
}
le = g_list_next(le);
if(le == NULL) {
return NULL;
}
return (fileset_entry *)le->data;
}
fileset_entry *
fileset_get_previous(void)
{
GList *le;
le = fileset_get_current();
if(le == NULL) {
return NULL;
}
le = g_list_previous(le);
if(le == NULL) {
return NULL;
}
return (fileset_entry *)le->data;
}
static void fileset_entry_delete(gpointer data, gpointer user_data _U_)
{
fileset_entry *entry = (fileset_entry *)data;
g_free( (gpointer) entry->fullname);
entry->fullname = NULL;
g_free( (gpointer) entry->name);
entry->name = NULL;
g_free(entry);
}
void fileset_delete(void)
{
if(set.entries) {
g_list_foreach(set.entries, fileset_entry_delete, NULL);
g_list_free(set.entries);
set.entries = NULL;
}
if(set.dirname) {
g_free( (gpointer) set.dirname);
set.dirname = NULL;
}
}
