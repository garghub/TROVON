static gboolean
local_eo_save_entry(const gchar *save_as_filename, export_object_entry_t *entry)
{
int to_fd;
gint64 bytes_left;
int bytes_to_write;
ssize_t bytes_written;
guint8 *ptr;
to_fd = ws_open(save_as_filename, O_WRONLY | O_CREAT | O_EXCL | O_BINARY, 0644);
if(to_fd == -1) {
return FALSE;
}
ptr = entry->payload_data;
bytes_left = entry->payload_len;
while (bytes_left != 0) {
if (bytes_left > 0x40000000)
bytes_to_write = 0x40000000;
else
bytes_to_write = (int)bytes_left;
bytes_written = ws_write(to_fd, ptr, bytes_to_write);
if(bytes_written <= 0) {
ws_close(to_fd);
return FALSE;
}
bytes_left -= bytes_written;
ptr += bytes_written;
}
if (ws_close(to_fd) < 0) {
return FALSE;
}
return TRUE;
}
static gboolean
list_exportobject_protocol(const void *key, void *value _U_, void *userdata _U_)
{
fprintf(stderr, " %s\n", (gchar*)key);
return FALSE;
}
void eo_list_object_types(void)
{
eo_iterate_tables(list_exportobject_protocol, NULL);
}
gboolean eo_tap_opt_add(const char *option_string)
{
gchar** splitted;
if (!eo_opts)
eo_opts = g_hash_table_new(g_str_hash,g_str_equal);
splitted = g_strsplit(option_string, ",", 2);
if ((splitted[0] == NULL) || (splitted[1] == NULL) || (get_eo_by_name(splitted[0]) == NULL))
{
fprintf(stderr, "tshark: \"--export-objects\" are specified as: <protocol>,<destdir>\n");
fprintf(stderr, "tshark: The available export object types for the \"--export-objects\" option are:\n");
eo_list_object_types();
}
else
{
gchar* dir = (gchar*)g_hash_table_lookup(eo_opts, splitted[0]);
if (dir == NULL) {
g_hash_table_insert(eo_opts, splitted[0], splitted[1]);
g_free(splitted);
return TRUE;
}
else
{
fprintf(stderr, "tshark: \"--export-objects\" already specified protocol '%s'\n", splitted[0]);
}
}
g_strfreev(splitted);
return FALSE;
}
static void
object_list_add_entry(void *gui_data, export_object_entry_t *entry)
{
export_object_list_gui_t *object_list = (export_object_list_gui_t*)gui_data;
object_list->entries = g_slist_append(object_list->entries, entry);
}
static export_object_entry_t*
object_list_get_entry(void *gui_data, int row) {
export_object_list_gui_t *object_list = (export_object_list_gui_t*)gui_data;
return (export_object_entry_t *)g_slist_nth_data(object_list->entries, row);
}
static void
eo_draw(void *tapdata)
{
export_object_list_t *tap_object = (export_object_list_t *)tapdata;
export_object_list_gui_t *object_list = (export_object_list_gui_t*)tap_object->gui_data;
GSList *slist = object_list->entries;
export_object_entry_t *entry;
gboolean all_saved = TRUE;
gchar* save_in_path = (gchar*)g_hash_table_lookup(eo_opts, proto_get_protocol_filter_name(get_eo_proto_id(object_list->eo)));
GString *safe_filename = NULL;
gchar *save_as_fullpath = NULL;
int count = 0;
if (!g_file_test(save_in_path, G_FILE_TEST_IS_DIR)) {
if (g_mkdir_with_parents(save_in_path, 0755) == -1) {
fprintf(stderr, "Failed to create export objects output directory \"%s\": %s\n",
save_in_path, g_strerror(errno));
return;
}
}
if ((strlen(save_in_path) < EXPORT_OBJECT_MAXFILELEN)) {
while (slist) {
entry = (export_object_entry_t *)slist->data;
do {
g_free(save_as_fullpath);
if (entry->filename) {
safe_filename = eo_massage_str(entry->filename,
EXPORT_OBJECT_MAXFILELEN - strlen(save_in_path), count);
} else {
char generic_name[EXPORT_OBJECT_MAXFILELEN+1];
const char *ext;
ext = eo_ct2ext(entry->content_type);
g_snprintf(generic_name, sizeof(generic_name),
"object%u%s%s", entry->pkt_num, ext ? "." : "", ext ? ext : "");
safe_filename = eo_massage_str(generic_name,
EXPORT_OBJECT_MAXFILELEN - strlen(save_in_path), count);
}
save_as_fullpath = g_build_filename(save_in_path, safe_filename->str, NULL);
g_string_free(safe_filename, TRUE);
} while (g_file_test(save_as_fullpath, G_FILE_TEST_EXISTS) && ++count < 1000);
count = 0;
if (!local_eo_save_entry(save_as_fullpath, entry))
all_saved = FALSE;
g_free(save_as_fullpath);
save_as_fullpath = NULL;
slist = slist->next;
}
}
else
{
all_saved = FALSE;
}
if (!all_saved)
fprintf(stderr, "Export objects (%s): Some files could not be saved.\n",
proto_get_protocol_filter_name(get_eo_proto_id(object_list->eo)));
}
static void
exportobject_handler(gpointer key, gpointer value _U_, gpointer user_data _U_)
{
GString *error_msg;
export_object_list_t *tap_data;
export_object_list_gui_t *object_list;
register_eo_t* eo;
eo = get_eo_by_name((const char*)key);
if (eo == NULL)
{
fprintf(stderr, "tshark: \"--export-objects\" INTERNAL ERROR '%s' protocol not found\n", (const char*)key);
return;
}
tap_data = g_new0(export_object_list_t,1);
object_list = g_new0(export_object_list_gui_t,1);
tap_data->add_entry = object_list_add_entry;
tap_data->get_entry = object_list_get_entry;
tap_data->gui_data = (void*)object_list;
object_list->eo = eo;
error_msg = register_tap_listener(get_eo_tap_listener_name(eo), tap_data, NULL, 0,
NULL, get_eo_packet_func(eo), eo_draw);
if (error_msg) {
fprintf(stderr, "tshark: Can't register %s tap: %s\n", (const char*)key, error_msg->str);
g_string_free(error_msg, TRUE);
g_free(tap_data);
g_free(object_list);
return;
}
}
void start_exportobjects(void)
{
if (eo_opts != NULL)
g_hash_table_foreach(eo_opts, exportobject_handler, NULL);
}
