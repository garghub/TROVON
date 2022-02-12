static gboolean
check_for_ftap_plugin(GModule *handle)
{
gpointer gp;
void (*register_ftap_module)(void);
ftap_plugin *plugin;
if (!g_module_symbol(handle, "register_ftap_module", &gp)) {
return FALSE;
}
register_ftap_module = (void (*)(void))gp;
plugin = (ftap_plugin *)g_malloc(sizeof (ftap_plugin));
plugin->register_ftap_module = register_ftap_module;
ftap_plugins = g_slist_append(ftap_plugins, plugin);
return TRUE;
}
void
ftap_register_plugin_types(void)
{
add_plugin_type("file format", check_for_ftap_plugin);
}
static void
register_ftap_module_plugin(gpointer data, gpointer user_data _U_)
{
ftap_plugin *plugin = (ftap_plugin *)data;
(plugin->register_ftap_module)();
}
void
register_all_filetap_modules(void)
{
g_slist_foreach(ftap_plugins, register_ftap_module_plugin, NULL);
}
gint64
ftap_file_size(ftap *fth, int *err)
{
ws_statb64 statb;
if (file_fstat((fth->fh == NULL) ? fth->random_fh : fth->fh,
&statb, err) == -1)
return -1;
return statb.st_size;
}
int
ftap_fstat(ftap *fth, ws_statb64 *statb, int *err)
{
if (file_fstat((fth->fh == NULL) ? fth->random_fh : fth->fh,
statb, err) == -1)
return -1;
return 0;
}
int
ftap_file_type_subtype(ftap *fth)
{
return fth->file_type_subtype;
}
gboolean
ftap_iscompressed(ftap *fth)
{
return file_iscompressed((fth->fh == NULL) ? fth->random_fh : fth->fh);
}
guint
ftap_snapshot_length(ftap *fth)
{
return fth->snapshot_length;
}
int
ftap_file_encap(ftap *fth)
{
return fth->file_encap;
}
static void ftap_init_encap_types(void) {
if (encap_table_arr) return;
encap_table_arr = g_array_new(FALSE,TRUE,sizeof(struct encap_type_info));
g_array_append_vals(encap_table_arr,encap_table_base,ftap_num_encap_types);
}
int ftap_get_num_encap_types(void) {
ftap_init_encap_types();
return ftap_num_encap_types;
}
int ftap_register_encap_type(const char* name, const char* short_name) {
struct encap_type_info e;
ftap_init_encap_types();
e.name = g_strdup(name);
e.short_name = g_strdup(short_name);
g_array_append_val(encap_table_arr,e);
return ftap_num_encap_types++;
}
const char *
ftap_encap_string(int encap)
{
if (encap < FTAP_ENCAP_PER_RECORD || encap >= FTAP_NUM_ENCAP_TYPES)
return "Illegal";
else if (encap == FTAP_ENCAP_PER_RECORD)
return "Per record";
else
return encap_table_entry(encap).name;
}
const char *
ftap_encap_short_string(int encap)
{
if (encap < FTAP_ENCAP_PER_RECORD || encap >= FTAP_NUM_ENCAP_TYPES)
return "illegal";
else if (encap == FTAP_ENCAP_PER_RECORD)
return "per-record";
else
return encap_table_entry(encap).short_name;
}
int
ftap_short_string_to_encap(const char *short_name)
{
int encap;
for (encap = 0; encap < FTAP_NUM_ENCAP_TYPES; encap++) {
if (encap_table_entry(encap).short_name != NULL &&
strcmp(short_name, encap_table_entry(encap).short_name) == 0)
return encap;
}
return -1;
}
const char *
ftap_strerror(int err)
{
static char errbuf[128];
unsigned int ftap_errlist_index;
if (err < 0) {
ftap_errlist_index = -1 - err;
if (ftap_errlist_index >= FTAP_ERRLIST_SIZE) {
g_snprintf(errbuf, 128, "Error %d", err);
return errbuf;
}
if (ftap_errlist[ftap_errlist_index] == NULL)
return "Unknown reason";
return ftap_errlist[ftap_errlist_index];
} else
return g_strerror(err);
}
void
ftap_sequential_close(ftap *fth)
{
if (fth->subtype_sequential_close != NULL)
(*fth->subtype_sequential_close)(fth);
if (fth->fh != NULL) {
file_close(fth->fh);
fth->fh = NULL;
}
if (fth->frame_buffer) {
buffer_free(fth->frame_buffer);
g_free(fth->frame_buffer);
fth->frame_buffer = NULL;
}
}
static void
g_fast_seek_item_free(gpointer data, gpointer user_data _U_)
{
g_free(data);
}
void
ftap_fdclose(ftap *fth)
{
if (fth->fh != NULL)
file_fdclose(fth->fh);
if (fth->random_fh != NULL)
file_fdclose(fth->random_fh);
}
void
ftap_close(ftap *fth)
{
ftap_sequential_close(fth);
if (fth->subtype_close != NULL)
(*fth->subtype_close)(fth);
if (fth->random_fh != NULL)
file_close(fth->random_fh);
if (fth->priv != NULL)
g_free(fth->priv);
if (fth->fast_seek != NULL) {
g_ptr_array_foreach(fth->fast_seek, g_fast_seek_item_free, NULL);
g_ptr_array_free(fth->fast_seek, TRUE);
}
g_free(fth);
}
void
ftap_cleareof(ftap *fth) {
file_clearerr(fth->fh);
}
gboolean
ftap_read(ftap *fth, int *err, gchar **err_info, gint64 *data_offset)
{
#if 0
wth->phdr.pkt_encap = wth->file_encap;
#endif
if (!fth->subtype_read(fth, err, err_info, data_offset)) {
if (*err == 0)
*err = file_error(fth->fh, err_info);
return FALSE;
}
#if 0
if (wth->phdr.caplen > wth->phdr.len)
wth->phdr.caplen = wth->phdr.len;
g_assert(wth->phdr.pkt_encap != FTAP_ENCAP_PER_RECORD);
#endif
return TRUE;
}
gboolean
ftap_read_packet_bytes(FILE_F fh, Buffer *buf, guint length, int *err,
gchar **err_info)
{
int bytes_read;
buffer_assure_space(buf, length);
errno = FTAP_ERR_CANT_READ;
bytes_read = file_read(buffer_start_ptr(buf), length, fh);
if (bytes_read < 0 || (guint)bytes_read != length) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = FTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
gint64
ftap_read_so_far(ftap *fth)
{
return file_tell_raw(fth->fh);
}
gboolean
ftap_seek_read(ftap *fth, gint64 seek_off,
Buffer *buf, int len,
int *err, gchar **err_info)
{
return fth->subtype_seek_read(fth, seek_off, buf, len,
err, err_info);
}
