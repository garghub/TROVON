idb_merge_mode
merge_string_to_idb_merge_mode(const char *name)
{
int i;
for (i = 0; i < IDB_MERGE_MODE_MAX; i++) {
if (g_strcmp0(name, idb_merge_mode_strings[i]) == 0) {
return (idb_merge_mode) i;
}
}
return IDB_MERGE_MODE_MAX;
}
const char *
merge_idb_merge_mode_to_string(const int mode)
{
if (mode >= 0 && mode < IDB_MERGE_MODE_MAX) {
return idb_merge_mode_strings[mode];
}
return idb_merge_mode_strings[(int)IDB_MERGE_MODE_MAX];
}
static void
cleanup_in_file(merge_in_file_t *in_file)
{
g_assert(in_file != NULL);
wtap_close(in_file->wth);
in_file->wth = NULL;
g_array_free(in_file->idb_index_map, TRUE);
in_file->idb_index_map = NULL;
}
static void
add_idb_index_map(merge_in_file_t *in_file, const guint orig_index, const guint found_index)
{
g_assert(in_file != NULL);
g_assert(in_file->idb_index_map != NULL);
g_assert(orig_index == in_file->idb_index_map->len);
g_array_append_val(in_file->idb_index_map, found_index);
}
static gboolean
merge_open_in_files(guint in_file_count, const char *const *in_file_names,
merge_in_file_t **in_files, int *err, gchar **err_info,
guint *err_fileno)
{
guint i;
guint j;
size_t files_size = in_file_count * sizeof(merge_in_file_t);
merge_in_file_t *files;
gint64 size;
files = (merge_in_file_t *)g_malloc0(files_size);
*in_files = files;
for (i = 0; i < in_file_count; i++) {
files[i].filename = in_file_names[i];
files[i].wth = wtap_open_offline(in_file_names[i], WTAP_TYPE_AUTO, err, err_info, FALSE);
files[i].data_offset = 0;
files[i].state = PACKET_NOT_PRESENT;
files[i].packet_num = 0;
if (!files[i].wth) {
for (j = 0; j < i; j++)
cleanup_in_file(&files[j]);
*err_fileno = i;
return FALSE;
}
size = wtap_file_size(files[i].wth, err);
if (size == -1) {
for (j = 0; j != G_MAXUINT && j <= i; j++)
cleanup_in_file(&files[j]);
*err_fileno = i;
return FALSE;
}
files[i].size = size;
files[i].idb_index_map = g_array_new(FALSE, FALSE, sizeof(guint));
}
return TRUE;
}
static void
merge_close_in_files(int in_file_count, merge_in_file_t in_files[])
{
int i;
for (i = 0; i < in_file_count; i++) {
cleanup_in_file(&in_files[i]);
}
}
static int
merge_select_frame_type(int in_file_count, merge_in_file_t in_files[])
{
int i;
int selected_frame_type;
selected_frame_type = wtap_file_encap(in_files[0].wth);
for (i = 1; i < in_file_count; i++) {
int this_frame_type = wtap_file_encap(in_files[i].wth);
if (selected_frame_type != this_frame_type) {
selected_frame_type = WTAP_ENCAP_PER_PACKET;
break;
}
}
return selected_frame_type;
}
static gboolean
is_earlier(nstime_t *l, nstime_t *r)
{
if (l->secs > r->secs) {
return FALSE;
} else if (l->secs < r->secs) {
return TRUE;
} else if (l->nsecs > r->nsecs) {
return FALSE;
}
return TRUE;
}
static merge_in_file_t *
merge_read_packet(int in_file_count, merge_in_file_t in_files[],
int *err, gchar **err_info)
{
int i;
int ei = -1;
nstime_t tv = { sizeof(time_t) > sizeof(int) ? LONG_MAX : INT_MAX, INT_MAX };
struct wtap_pkthdr *phdr;
for (i = 0; i < in_file_count; i++) {
if (in_files[i].state == PACKET_NOT_PRESENT) {
if (!wtap_read(in_files[i].wth, err, err_info, &in_files[i].data_offset)) {
if (*err != 0) {
in_files[i].state = GOT_ERROR;
return &in_files[i];
}
in_files[i].state = AT_EOF;
} else
in_files[i].state = PACKET_PRESENT;
}
if (in_files[i].state == PACKET_PRESENT) {
phdr = wtap_phdr(in_files[i].wth);
if (is_earlier(&phdr->ts, &tv)) {
tv = phdr->ts;
ei = i;
}
}
}
if (ei == -1) {
*err = 0;
return NULL;
}
in_files[ei].state = PACKET_NOT_PRESENT;
in_files[ei].packet_num++;
*err = 0;
return &in_files[ei];
}
static merge_in_file_t *
merge_append_read_packet(int in_file_count, merge_in_file_t in_files[],
int *err, gchar **err_info)
{
int i;
for (i = 0; i < in_file_count; i++) {
if (in_files[i].state == AT_EOF)
continue;
if (wtap_read(in_files[i].wth, err, err_info, &in_files[i].data_offset))
break;
if (*err != 0) {
in_files[i].state = GOT_ERROR;
return &in_files[i];
}
in_files[i].state = AT_EOF;
}
if (i == in_file_count) {
*err = 0;
return NULL;
}
*err = 0;
return &in_files[i];
}
static GArray*
create_shb_header(const merge_in_file_t *in_files, const guint in_file_count,
const gchar *app_name)
{
GArray *shb_hdrs;
wtap_optionblock_t shb_hdr;
GString *comment_gstr;
GString *os_info_str;
guint i;
char* shb_comment = NULL;
wtapng_mandatory_section_t* shb_data;
gsize opt_len;
shb_hdrs = wtap_file_get_shb_for_new_file(in_files[0].wth);
shb_hdr = g_array_index(shb_hdrs, wtap_optionblock_t, 0);
comment_gstr = g_string_new("");
wtap_optionblock_get_option_string(shb_hdr, OPT_COMMENT, &shb_comment);
if (shb_comment && strlen(shb_comment) > 0) {
g_string_append_printf(comment_gstr, "%s \n",shb_comment);
}
g_string_append_printf(comment_gstr, "File created by merging: \n");
for (i = 0; i < in_file_count; i++) {
g_string_append_printf(comment_gstr, "File%d: %s \n",i+1,in_files[i].filename);
}
os_info_str = g_string_new("");
get_os_version_info(os_info_str);
shb_data = (wtapng_mandatory_section_t*)wtap_optionblock_get_mandatory_data(shb_hdr);
shb_data->section_length = -1;
opt_len = comment_gstr->len;
wtap_optionblock_set_option_string(shb_hdr, OPT_COMMENT, g_string_free(comment_gstr, TRUE), opt_len);
wtap_optionblock_set_option_string(shb_hdr, OPT_SHB_HARDWARE, NULL, 0 );
opt_len = os_info_str->len;
wtap_optionblock_set_option_string(shb_hdr, OPT_SHB_OS, g_string_free(os_info_str, TRUE), opt_len);
wtap_optionblock_set_option_string(shb_hdr, OPT_SHB_USERAPPL, (char*)app_name, app_name ? strlen(app_name): 0 );
return shb_hdrs;
}
static gboolean
is_duplicate_idb(const wtap_optionblock_t idb1, const wtap_optionblock_t idb2)
{
wtapng_if_descr_mandatory_t *idb1_mand, *idb2_mand;
guint64 idb1_if_speed, idb2_if_speed;
guint8 idb1_if_tsresol, idb2_if_tsresol;
guint8 idb1_if_fcslen, idb2_if_fcslen;
char *idb1_opt_comment, *idb2_opt_comment, *idb1_if_name, *idb2_if_name,
*idb1_if_description, *idb2_if_description, *idb1_if_os, *idb2_if_os;
g_assert(idb1 && idb2);
idb1_mand = (wtapng_if_descr_mandatory_t*)wtap_optionblock_get_mandatory_data(idb1);
idb2_mand = (wtapng_if_descr_mandatory_t*)wtap_optionblock_get_mandatory_data(idb2);
merge_debug("merge::is_duplicate_idb() called");
merge_debug("idb1_mand->wtap_encap == idb2_mand->wtap_encap: %s",
(idb1_mand->wtap_encap == idb2_mand->wtap_encap) ? "TRUE":"FALSE");
merge_debug("idb1_mand->time_units_per_second == idb2_mand->time_units_per_second: %s",
(idb1_mand->time_units_per_second == idb2_mand->time_units_per_second) ? "TRUE":"FALSE");
merge_debug("idb1_mand->tsprecision == idb2_mand->tsprecision: %s",
(idb1_mand->tsprecision == idb2_mand->tsprecision) ? "TRUE":"FALSE");
merge_debug("idb1_mand->link_type == idb2_mand->link_type: %s",
(idb1_mand->link_type == idb2_mand->link_type) ? "TRUE":"FALSE");
merge_debug("idb1_mand->snap_len == idb2_mand->snap_len: %s",
(idb1_mand->snap_len == idb2_mand->snap_len) ? "TRUE":"FALSE");
wtap_optionblock_get_option_uint64(idb1, OPT_IDB_SPEED, &idb1_if_speed);
wtap_optionblock_get_option_uint64(idb2, OPT_IDB_SPEED, &idb2_if_speed);
merge_debug("idb1_if_speed == idb2_if_speed: %s",
(idb1_if_speed == idb2_if_speed) ? "TRUE":"FALSE");
wtap_optionblock_get_option_uint8(idb1, OPT_IDB_TSRESOL, &idb1_if_tsresol);
wtap_optionblock_get_option_uint8(idb2, OPT_IDB_TSRESOL, &idb2_if_tsresol);
merge_debug("idb1_if_tsresol == idb2_if_tsresol: %s",
(idb1_if_tsresol == idb2_if_tsresol) ? "TRUE":"FALSE");
wtap_optionblock_get_option_uint8(idb1, OPT_IDB_FCSLEN, &idb1_if_fcslen);
wtap_optionblock_get_option_uint8(idb2, OPT_IDB_FCSLEN, &idb2_if_fcslen);
merge_debug("idb1_if_fcslen == idb2_if_fcslen: %s",
(idb1_if_fcslen == idb2_if_fcslen) ? "TRUE":"FALSE");
wtap_optionblock_get_option_string(idb1, OPT_COMMENT, &idb1_opt_comment);
wtap_optionblock_get_option_string(idb2, OPT_COMMENT, &idb2_opt_comment);
merge_debug("g_strcmp0(idb1_opt_comment, idb2_opt_comment) == 0: %s",
(g_strcmp0(idb1_opt_comment, idb2_opt_comment) == 0) ? "TRUE":"FALSE");
wtap_optionblock_get_option_string(idb1, OPT_IDB_NAME, &idb1_if_name);
wtap_optionblock_get_option_string(idb2, OPT_IDB_NAME, &idb2_if_name);
merge_debug("g_strcmp0(idb1_if_name, idb2_if_name) == 0: %s",
(g_strcmp0(idb1_if_name, idb2_if_name) == 0) ? "TRUE":"FALSE");
wtap_optionblock_get_option_string(idb1, OPT_IDB_DESCR, &idb1_if_description);
wtap_optionblock_get_option_string(idb2, OPT_IDB_DESCR, &idb2_if_description);
merge_debug("g_strcmp0(idb1_if_description, idb2_if_description) == 0: %s",
(g_strcmp0(idb1_if_description, idb2_if_description) == 0) ? "TRUE":"FALSE");
wtap_optionblock_get_option_string(idb1, OPT_IDB_OS, &idb1_if_os);
wtap_optionblock_get_option_string(idb2, OPT_IDB_OS, &idb2_if_os);
merge_debug("g_strcmp0(idb1_if_os, idb2_if_os) == 0: %s",
(g_strcmp0(idb1_if_os, idb2_if_os) == 0) ? "TRUE":"FALSE");
merge_debug("merge::is_duplicate_idb() returning");
return (idb1_mand->wtap_encap == idb2_mand->wtap_encap &&
idb1_mand->time_units_per_second == idb2_mand->time_units_per_second &&
idb1_mand->tsprecision == idb2_mand->tsprecision &&
idb1_mand->link_type == idb2_mand->link_type &&
idb1_mand->snap_len == idb2_mand->snap_len &&
idb1_if_speed == idb2_if_speed &&
idb1_if_tsresol == idb2_if_tsresol &&
idb1_if_fcslen == idb2_if_fcslen &&
g_strcmp0(idb1_opt_comment, idb2_opt_comment) == 0 &&
g_strcmp0(idb1_if_name, idb2_if_name) == 0 &&
g_strcmp0(idb1_if_description, idb2_if_description) == 0 &&
g_strcmp0(idb1_if_os, idb2_if_os) == 0);
}
static gboolean
all_idbs_are_duplicates(const merge_in_file_t *in_files, const guint in_file_count)
{
wtapng_iface_descriptions_t *first_idb_list = NULL;
wtapng_iface_descriptions_t *other_idb_list = NULL;
guint first_idb_list_size, other_idb_list_size;
wtap_optionblock_t first_file_idb, other_file_idb;
guint i, j;
g_assert(in_files != NULL);
first_idb_list = wtap_file_get_idb_info(in_files[0].wth);
g_assert(first_idb_list->interface_data);
first_idb_list_size = first_idb_list->interface_data->len;
for (i = 1; i < in_file_count; i++) {
other_idb_list = wtap_file_get_idb_info(in_files[i].wth);
g_assert(other_idb_list->interface_data);
other_idb_list_size = other_idb_list->interface_data->len;
if (other_idb_list_size != first_idb_list_size) {
merge_debug("merge::all_idbs_are_duplicates: sizes of IDB lists don't match: first=%u, other=%u",
first_idb_list_size, other_idb_list_size);
g_free(other_idb_list);
g_free(first_idb_list);
return FALSE;
}
for (j = 0; j < other_idb_list_size; j++) {
first_file_idb = g_array_index(first_idb_list->interface_data, wtap_optionblock_t, j);
other_file_idb = g_array_index(other_idb_list->interface_data, wtap_optionblock_t, j);
if (!is_duplicate_idb(first_file_idb, other_file_idb)) {
merge_debug("merge::all_idbs_are_duplicates: IDBs at index %d do not match, returning FALSE", j);
g_free(other_idb_list);
g_free(first_idb_list);
return FALSE;
}
}
g_free(other_idb_list);
}
merge_debug("merge::all_idbs_are_duplicates: returning TRUE");
g_free(first_idb_list);
return TRUE;
}
static gboolean
find_duplicate_idb(const wtap_optionblock_t input_file_idb,
const wtapng_iface_descriptions_t *merged_idb_list,
guint *found_index)
{
wtap_optionblock_t merged_idb;
guint i;
g_assert(input_file_idb != NULL);
g_assert(merged_idb_list != NULL);
g_assert(merged_idb_list->interface_data != NULL);
g_assert(found_index != NULL);
for (i = 0; i < merged_idb_list->interface_data->len; i++) {
merged_idb = g_array_index(merged_idb_list->interface_data, wtap_optionblock_t, i);
if (is_duplicate_idb(input_file_idb, merged_idb)) {
*found_index = i;
return TRUE;
}
}
return FALSE;
}
static guint
add_idb_to_merged_file(wtapng_iface_descriptions_t *merged_idb_list,
const wtap_optionblock_t input_file_idb)
{
wtap_optionblock_t idb = wtap_optionblock_create(WTAP_OPTION_BLOCK_IF_DESCR);
wtapng_if_descr_mandatory_t* idb_mand;
wtapng_if_descr_filter_t if_filter;
g_assert(merged_idb_list != NULL);
g_assert(merged_idb_list->interface_data != NULL);
g_assert(input_file_idb != NULL);
wtap_optionblock_copy_options(idb, input_file_idb);
idb_mand = (wtapng_if_descr_mandatory_t*)wtap_optionblock_get_mandatory_data(idb);
memset(&if_filter, 0, sizeof(if_filter));
wtap_optionblock_set_option_custom(idb, OPT_IDB_FILTER, &if_filter);
idb_mand->num_stat_entries = 0;
idb_mand->interface_statistics = NULL;
g_array_append_val(merged_idb_list->interface_data, idb);
return merged_idb_list->interface_data->len - 1;
}
static wtapng_iface_descriptions_t *
generate_merged_idb(merge_in_file_t *in_files, const guint in_file_count, const idb_merge_mode mode)
{
wtapng_iface_descriptions_t *merged_idb_list = NULL;
wtapng_iface_descriptions_t *input_file_idb_list = NULL;
wtap_optionblock_t input_file_idb;
guint itf_count, merged_index;
guint i;
merged_idb_list = g_new(wtapng_iface_descriptions_t,1);
merged_idb_list->interface_data = g_array_new(FALSE, FALSE, sizeof(wtap_optionblock_t));
if (mode == IDB_MERGE_MODE_ALL_SAME && all_idbs_are_duplicates(in_files, in_file_count)) {
guint num_idbs;
merge_debug("merge::generate_merged_idb: mode ALL set and all IDBs are duplicates");
input_file_idb_list = wtap_file_get_idb_info(in_files[0].wth);
num_idbs = input_file_idb_list->interface_data->len;
for (itf_count = 0; itf_count < num_idbs; itf_count++) {
input_file_idb = g_array_index(input_file_idb_list->interface_data,
wtap_optionblock_t, itf_count);
merged_index = add_idb_to_merged_file(merged_idb_list, input_file_idb);
add_idb_index_map(&in_files[0], itf_count, merged_index);
}
for (i = 1; i < in_file_count; i++) {
for (itf_count = 0; itf_count < num_idbs; itf_count++) {
add_idb_index_map(&in_files[i], itf_count, itf_count);
}
}
g_free(input_file_idb_list);
}
else {
for (i = 0; i < in_file_count; i++) {
input_file_idb_list = wtap_file_get_idb_info(in_files[i].wth);
for (itf_count = 0; itf_count < input_file_idb_list->interface_data->len; itf_count++) {
input_file_idb = g_array_index(input_file_idb_list->interface_data,
wtap_optionblock_t, itf_count);
if (mode == IDB_MERGE_MODE_ANY_SAME &&
find_duplicate_idb(input_file_idb, merged_idb_list, &merged_index))
{
merge_debug("merge::generate_merged_idb: mode ANY set and found a duplicate");
add_idb_index_map(&in_files[i], itf_count, merged_index);
}
else {
merge_debug("merge::generate_merged_idb: mode NONE set or did not find a duplicate");
merged_index = add_idb_to_merged_file(merged_idb_list, input_file_idb);
add_idb_index_map(&in_files[i], itf_count, merged_index);
}
}
g_free(input_file_idb_list);
}
}
return merged_idb_list;
}
static gboolean
map_phdr_interface_id(struct wtap_pkthdr *phdr, const merge_in_file_t *in_file)
{
guint current_interface_id = 0;
g_assert(phdr != NULL);
g_assert(in_file != NULL);
g_assert(in_file->idb_index_map != NULL);
if (phdr->presence_flags & WTAP_HAS_INTERFACE_ID) {
current_interface_id = phdr->interface_id;
}
if (current_interface_id >= in_file->idb_index_map->len) {
merge_debug("merge::map_phdr_interface_id: current_interface_id >= in_file->idb_index_map->len (ERROR?)");
return FALSE;
}
phdr->interface_id = g_array_index(in_file->idb_index_map, guint, current_interface_id);
phdr->presence_flags |= WTAP_HAS_INTERFACE_ID;
return TRUE;
}
static gchar*
get_read_error_string(const merge_in_file_t *in_files, const guint in_file_count,
const int *err, gchar **err_info)
{
GString *err_message = g_string_new("");
gchar *display_basename = NULL;
guint i;
g_assert(in_files != NULL);
g_assert(err != NULL);
g_assert(err_info != NULL);
if (*err_info == NULL) {
*err_info = g_strdup("no information supplied");
}
for (i = 0; i < in_file_count; i++) {
if (in_files[i].state == GOT_ERROR) {
display_basename = g_filename_display_basename(in_files[i].filename);
switch (*err) {
case WTAP_ERR_SHORT_READ:
g_string_printf(err_message,
"The capture file %s appears to have been cut short"
" in the middle of a packet.", display_basename);
break;
case WTAP_ERR_BAD_FILE:
g_string_printf(err_message,
"The capture file %s appears to be damaged or corrupt.\n(%s)",
display_basename, *err_info);
break;
case WTAP_ERR_DECOMPRESS:
g_string_printf(err_message,
"The compressed capture file %s appears to be damaged or corrupt.\n"
"(%s)", display_basename, *err_info);
break;
default:
g_string_printf(err_message,
"An error occurred while reading the"
" capture file %s: %s.",
display_basename, wtap_strerror(*err));
break;
}
g_free(display_basename);
break;
}
}
g_free(*err_info);
*err_info = g_string_free(err_message, FALSE);
return *err_info;
}
static gchar*
get_write_error_string(const merge_in_file_t *in_file, const int file_type,
const gchar* out_filename, const int *err, gchar **err_info)
{
GString *err_message = g_string_new("");
gchar *display_basename = NULL;
int write_err;
g_assert(err != NULL);
g_assert(err_info != NULL);
if (*err_info == NULL) {
*err_info = g_strdup("no information supplied");
}
write_err = *err;
display_basename = g_filename_display_basename(in_file ? in_file->filename : "UNKNOWN");
if (write_err < 0) {
switch (write_err) {
case WTAP_ERR_UNWRITABLE_ENCAP:
g_string_printf(err_message,
"Frame %u of \"%s\" has a network type that can't be saved in a \"%s\" file.\n",
in_file ? in_file->packet_num : 0, display_basename,
wtap_file_type_subtype_string(file_type));
break;
case WTAP_ERR_PACKET_TOO_LARGE:
g_string_printf(err_message,
"Frame %u of \"%s\" is too large for a \"%s\" file.",
in_file ? in_file->packet_num : 0, display_basename,
wtap_file_type_subtype_string(file_type));
break;
case WTAP_ERR_UNWRITABLE_REC_TYPE:
g_string_printf(err_message,
"Record %u of \"%s\" has a record type that can't be saved in a \"%s\" file.",
in_file ? in_file->packet_num : 0, display_basename,
wtap_file_type_subtype_string(file_type));
break;
case WTAP_ERR_UNWRITABLE_REC_DATA:
g_string_printf(err_message,
"Record %u of \"%s\" has data that can't be saved in a \"%s\" file.\n(%s)",
in_file ? in_file->packet_num : 0, display_basename,
wtap_file_type_subtype_string(file_type), *err_info);
break;
default:
g_string_printf(err_message,
"An error occurred while writing to the file \"%s\": %s.",
out_filename, wtap_strerror(write_err));
break;
}
}
else {
g_string_printf(err_message, file_write_error_message(write_err), out_filename);
}
g_free(display_basename);
g_free(*err_info);
*err_info = g_string_free(err_message, FALSE);
return *err_info;
}
merge_result
merge_files(int out_fd, const gchar* out_filename, const int file_type,
const char *const *in_filenames, const guint in_file_count,
const gboolean do_append, const idb_merge_mode mode,
guint snaplen, const gchar *app_name, merge_progress_callback_t* cb,
int *err, gchar **err_info, guint *err_fileno)
{
merge_in_file_t *in_files = NULL, *in_file = NULL;
int frame_type = WTAP_ENCAP_PER_PACKET;
merge_result status = MERGE_OK;
wtap_dumper *pdh;
struct wtap_pkthdr *phdr, snap_phdr;
int count = 0;
gboolean stop_flag = FALSE;
GArray *shb_hdrs = NULL;
wtapng_iface_descriptions_t *idb_inf = NULL;
g_assert(out_fd > 0);
g_assert(in_file_count > 0);
g_assert(in_filenames != NULL);
g_assert(err != NULL);
g_assert(err_info != NULL);
g_assert(err_fileno != NULL);
g_assert((cb != NULL) ? (cb->callback_func != NULL) : TRUE);
merge_debug("merge_files: begin");
if (!merge_open_in_files(in_file_count, in_filenames, &in_files,
err, err_info, err_fileno)) {
merge_debug("merge_files: merge_open_in_files() failed with err=%d", *err);
return MERGE_ERR_CANT_OPEN_INFILE;
}
if (cb)
cb->callback_func(MERGE_EVENT_INPUT_FILES_OPENED, 0, in_files, in_file_count, cb->data);
if (snaplen == 0) {
snaplen = WTAP_MAX_PACKET_SIZE;
}
frame_type = merge_select_frame_type(in_file_count, in_files);
merge_debug("merge_files: got frame_type=%d", frame_type);
if (cb)
cb->callback_func(MERGE_EVENT_FRAME_TYPE_SELECTED, frame_type, in_files, in_file_count, cb->data);
if (file_type == WTAP_FILE_TYPE_SUBTYPE_PCAPNG) {
shb_hdrs = create_shb_header(in_files, in_file_count, app_name);
merge_debug("merge_files: SHB created");
idb_inf = generate_merged_idb(in_files, in_file_count, mode);
merge_debug("merge_files: IDB merge operation complete, got %u IDBs", idb_inf ? idb_inf->interface_data->len : 0);
pdh = wtap_dump_fdopen_ng(out_fd, file_type, frame_type, snaplen,
FALSE , shb_hdrs, idb_inf,
NULL, err);
}
else {
pdh = wtap_dump_fdopen(out_fd, file_type, frame_type, snaplen, FALSE , err);
}
if (pdh == NULL) {
merge_close_in_files(in_file_count, in_files);
g_free(in_files);
wtap_optionblock_array_free(shb_hdrs);
wtap_free_idb_info(idb_inf);
return MERGE_ERR_CANT_OPEN_OUTFILE;
}
if (cb)
cb->callback_func(MERGE_EVENT_READY_TO_MERGE, 0, in_files, in_file_count, cb->data);
for (;;) {
*err = 0;
if (do_append) {
in_file = merge_append_read_packet(in_file_count, in_files, err,
err_info);
}
else {
in_file = merge_read_packet(in_file_count, in_files, err,
err_info);
}
if (in_file == NULL) {
break;
}
if (*err != 0) {
status = MERGE_ERR_CANT_READ_INFILE;
break;
}
count++;
if (cb)
stop_flag = cb->callback_func(MERGE_EVENT_PACKET_WAS_READ, count, in_files, in_file_count, cb->data);
if (stop_flag) {
status = MERGE_USER_ABORTED;
break;
}
phdr = wtap_phdr(in_file->wth);
if (snaplen != 0 && phdr->caplen > snaplen) {
snap_phdr = *phdr;
snap_phdr.caplen = snaplen;
phdr = &snap_phdr;
}
if (file_type == WTAP_FILE_TYPE_SUBTYPE_PCAPNG) {
if (!map_phdr_interface_id(phdr, in_file)) {
status = MERGE_ERR_BAD_PHDR_INTERFACE_ID;
break;
}
}
if (!wtap_dump(pdh, phdr, wtap_buf_ptr(in_file->wth), err, err_info)) {
status = MERGE_ERR_CANT_WRITE_OUTFILE;
break;
}
}
if (cb)
cb->callback_func(MERGE_EVENT_DONE, count, in_files, in_file_count, cb->data);
merge_close_in_files(in_file_count, in_files);
if (status == MERGE_OK || status == MERGE_USER_ABORTED) {
if (!wtap_dump_close(pdh, err))
status = MERGE_ERR_CANT_CLOSE_OUTFILE;
} else {
int close_err = 0;
(void)wtap_dump_close(pdh, &close_err);
}
if (status != MERGE_OK) {
GString *err_message = NULL;
gchar *display_basename = NULL;
switch(status) {
case MERGE_ERR_CANT_READ_INFILE:
*err_info = get_read_error_string(in_files, in_file_count, err, err_info);
break;
case MERGE_ERR_CANT_WRITE_OUTFILE:
case MERGE_ERR_CANT_CLOSE_OUTFILE:
*err_info = get_write_error_string(in_file, file_type, out_filename, err, err_info);
break;
case MERGE_ERR_BAD_PHDR_INTERFACE_ID:
display_basename = g_filename_display_basename(in_file ? in_file->filename : "UNKNOWN");
if (*err_info != NULL)
g_free(*err_info);
err_message = g_string_new("");
g_string_printf(err_message,
"Record %u of \"%s\" has an interface ID which does not match any IDB in its file.",
in_file ? in_file->packet_num : 0, display_basename);
g_free(display_basename);
*err_info = g_string_free(err_message, FALSE);
break;
case MERGE_USER_ABORTED:
default:
break;
}
}
g_free(in_files);
wtap_optionblock_array_free(shb_hdrs);
wtap_free_idb_info(idb_inf);
return status;
}
