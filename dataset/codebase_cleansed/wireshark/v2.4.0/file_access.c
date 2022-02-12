static GSList *
add_extensions(GSList *extensions, const gchar *extension,
const char **compressed_file_extensions)
{
const char **compressed_file_extensionp;
extensions = g_slist_prepend(extensions, g_strdup(extension));
for (compressed_file_extensionp = compressed_file_extensions;
*compressed_file_extensionp != NULL;
compressed_file_extensionp++) {
extensions = g_slist_prepend(extensions,
g_strdup_printf("%s.%s", extension,
*compressed_file_extensionp));
}
return extensions;
}
static void
init_file_type_extensions(void)
{
if (file_type_extensions_arr) return;
file_type_extensions_arr = g_array_new(FALSE,TRUE,sizeof(struct file_extension_info));
g_array_append_vals(file_type_extensions_arr,file_type_extensions_base,N_FILE_TYPE_EXTENSIONS);
file_type_extensions = (struct file_extension_info*)(void *)file_type_extensions_arr->data;
}
void
wtap_register_file_type_extension(const struct file_extension_info *ei)
{
init_file_type_extensions();
g_array_append_val(file_type_extensions_arr,*ei);
file_type_extensions = (const struct file_extension_info*)(void *)file_type_extensions_arr->data;
}
int
wtap_get_num_file_type_extensions(void)
{
return file_type_extensions_arr->len;
}
const char *
wtap_get_file_extension_type_name(int extension_type)
{
return file_type_extensions[extension_type].name;
}
static GSList *
add_extensions_for_file_extensions_type(int extension_type,
GSList *extensions, const char **compressed_file_extensions)
{
gchar **extensions_set, **extensionp, *extension;
extensions_set = g_strsplit(file_type_extensions[extension_type].extensions,
";", 0);
for (extensionp = extensions_set; *extensionp != NULL; extensionp++) {
extension = *extensionp;
extensions = add_extensions(extensions, extension,
compressed_file_extensions);
}
g_strfreev(extensions_set);
return extensions;
}
GSList *
wtap_get_file_extension_type_extensions(guint extension_type)
{
GSList *extensions;
if (extension_type >= file_type_extensions_arr->len)
return NULL;
extensions = NULL;
extensions = add_extensions_for_file_extensions_type(extension_type,
extensions, compressed_file_extension_table);
return extensions;
}
GSList *
wtap_get_all_capture_file_extensions_list(void)
{
GSList *extensions;
unsigned int i;
init_file_type_extensions();
extensions = NULL;
for (i = 0; i < file_type_extensions_arr->len; i++) {
if (file_type_extensions[i].is_capture_file) {
extensions = add_extensions_for_file_extensions_type(i,
extensions, compressed_file_extension_table);
}
}
return extensions;
}
static void
set_heuristic_routine(void)
{
guint i;
g_assert(open_info_arr != NULL);
for (i = 0; i < open_info_arr->len; i++) {
if (open_routines[i].type == OPEN_INFO_HEURISTIC) {
heuristic_open_routine_idx = i;
break;
}
g_assert(open_routines[i].type == OPEN_INFO_MAGIC);
}
g_assert(heuristic_open_routine_idx > 0);
}
void
init_open_routines(void)
{
unsigned int i;
struct open_info *i_open;
if (open_info_arr)
return;
open_info_arr = g_array_new(TRUE,TRUE,sizeof(struct open_info));
g_array_append_vals(open_info_arr, open_info_base, N_OPEN_INFO_ROUTINES);
open_routines = (struct open_info *)(void*) open_info_arr->data;
for (i = 0, i_open = open_routines; i < open_info_arr->len; i++, i_open++) {
if (i_open->extensions != NULL)
i_open->extensions_set = g_strsplit(i_open->extensions, ";", 0);
}
set_heuristic_routine();
}
void
wtap_register_open_info(struct open_info *oi, const gboolean first_routine)
{
if (!oi || !oi->name) {
g_error("No open_info name given to register");
return;
}
if (wtap_has_open_info(oi->name)) {
g_error("Name given to register_open_info already exists");
return;
}
if (oi->extensions != NULL)
oi->extensions_set = g_strsplit(oi->extensions, ";", 0);
if (first_routine && oi->type == OPEN_INFO_MAGIC) {
g_array_prepend_val(open_info_arr, *oi);
} else if (!first_routine && oi->type == OPEN_INFO_HEURISTIC) {
g_array_append_val(open_info_arr, *oi);
} else {
g_array_insert_val(open_info_arr, heuristic_open_routine_idx, *oi);
}
open_routines = (struct open_info *)(void*) open_info_arr->data;
set_heuristic_routine();
}
void
wtap_deregister_open_info(const gchar *name)
{
guint i;
if (!name) {
g_error("Missing open_info name to de-register");
return;
}
for (i = 0; i < open_info_arr->len; i++) {
if (open_routines[i].name && strcmp(open_routines[i].name, name) == 0) {
if (open_routines[i].extensions_set != NULL)
g_strfreev(open_routines[i].extensions_set);
open_info_arr = g_array_remove_index(open_info_arr, i);
set_heuristic_routine();
return;
}
}
g_error("deregister_open_info: name not found");
}
gboolean
wtap_has_open_info(const gchar *name)
{
guint i;
if (!name) {
g_error("No name given to wtap_has_open_info!");
return FALSE;
}
for (i = 0; i < open_info_arr->len; i++) {
if (open_routines[i].name && strcmp(open_routines[i].name, name) == 0) {
return TRUE;
}
}
return FALSE;
}
unsigned int
open_info_name_to_type(const char *name)
{
unsigned int i;
if (!name)
return WTAP_TYPE_AUTO;
for (i = 0; i < open_info_arr->len; i++) {
if (open_routines[i].name != NULL &&
strcmp(name, open_routines[i].name) == 0)
return i+1;
}
return WTAP_TYPE_AUTO;
}
static char *
get_file_extension(const char *pathname)
{
gchar *filename;
gchar **components;
size_t ncomponents;
const char **compressed_file_extensionp;
gchar *extensionp;
if (strcmp(pathname, "") == 0)
return NULL;
filename = g_path_get_basename(pathname);
if (strchr(filename, '.') == NULL) {
g_free(filename);
return NULL;
}
components = g_strsplit(filename, ".", 0);
g_free(filename);
for (ncomponents = 0; components[ncomponents] != NULL; ncomponents++)
;
if (ncomponents == 0) {
g_strfreev(components);
return NULL;
}
if (ncomponents == 1) {
g_strfreev(components);
return NULL;
}
extensionp = components[ncomponents - 1];
for (compressed_file_extensionp = compressed_file_extension_table;
*compressed_file_extensionp != NULL;
compressed_file_extensionp++) {
if (strcmp(extensionp, *compressed_file_extensionp) == 0) {
if (ncomponents == 2) {
g_strfreev(components);
return NULL;
}
extensionp = g_strdup(components[ncomponents - 2]);
g_strfreev(components);
return extensionp;
}
}
extensionp = g_strdup(extensionp);
g_strfreev(components);
return extensionp;
}
static gboolean
heuristic_uses_extension(unsigned int i, const char *extension)
{
gchar **extensionp;
if (open_routines[i].extensions == NULL)
return FALSE;
for (extensionp = open_routines[i].extensions_set; *extensionp != NULL;
extensionp++) {
if (strcmp(extension, *extensionp) == 0) {
return TRUE;
}
}
return FALSE;
}
wtap *
wtap_open_offline(const char *filename, unsigned int type, int *err, char **err_info,
gboolean do_random)
{
int fd;
ws_statb64 statb;
wtap *wth;
unsigned int i;
gboolean use_stdin = FALSE;
gchar *extension;
wtap_block_t shb;
*err = 0;
*err_info = NULL;
if (strcmp(filename, "-") == 0)
use_stdin = TRUE;
if (use_stdin) {
if (ws_fstat64(0, &statb) < 0) {
*err = errno;
return NULL;
}
} else {
if (ws_stat64(filename, &statb) < 0) {
*err = errno;
return NULL;
}
}
if (S_ISFIFO(statb.st_mode)) {
if (do_random) {
*err = WTAP_ERR_RANDOM_OPEN_PIPE;
return NULL;
}
} else if (S_ISDIR(statb.st_mode)) {
*err = EISDIR;
return NULL;
} else if (! S_ISREG(statb.st_mode)) {
*err = WTAP_ERR_NOT_REGULAR_FILE;
return NULL;
}
if (use_stdin && do_random) {
*err = WTAP_ERR_RANDOM_OPEN_STDIN;
return NULL;
}
errno = ENOMEM;
wth = (wtap *)g_malloc0(sizeof(wtap));
errno = WTAP_ERR_CANT_OPEN;
if (use_stdin) {
fd = ws_dup(0);
if (fd < 0) {
*err = errno;
g_free(wth);
return NULL;
}
#ifdef _WIN32
if (_setmode(fd, O_BINARY) == -1) {
*err = errno;
g_free(wth);
return NULL;
}
#endif
if (!(wth->fh = file_fdopen(fd))) {
*err = errno;
ws_close(fd);
g_free(wth);
return NULL;
}
} else {
if (!(wth->fh = file_open(filename))) {
*err = errno;
g_free(wth);
return NULL;
}
}
if (do_random) {
if (!(wth->random_fh = file_open(filename))) {
*err = errno;
file_close(wth->fh);
g_free(wth);
return NULL;
}
} else
wth->random_fh = NULL;
wth->file_encap = WTAP_ENCAP_UNKNOWN;
wth->subtype_sequential_close = NULL;
wth->subtype_close = NULL;
wth->file_tsprec = WTAP_TSPREC_USEC;
wth->priv = NULL;
wth->wslua_data = NULL;
wth->shb_hdrs = g_array_new(FALSE, FALSE, sizeof(wtap_block_t));
shb = wtap_block_create(WTAP_BLOCK_NG_SECTION);
if (shb)
g_array_append_val(wth->shb_hdrs, shb);
wth->interface_data = g_array_new(FALSE, FALSE, sizeof(wtap_block_t));
if (wth->random_fh) {
wth->fast_seek = g_ptr_array_new();
file_set_random_access(wth->fh, FALSE, wth->fast_seek);
file_set_random_access(wth->random_fh, TRUE, wth->fast_seek);
}
if (type != WTAP_TYPE_AUTO && type <= open_info_arr->len) {
int result;
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1) {
wtap_close(wth);
return NULL;
}
wth->wslua_data = open_routines[type - 1].wslua_data;
result = (*open_routines[type - 1].open_routine)(wth, err, err_info);
switch (result) {
case WTAP_OPEN_ERROR:
wtap_close(wth);
return NULL;
case WTAP_OPEN_NOT_MINE:
goto fail;
case WTAP_OPEN_MINE:
goto success;
}
}
for (i = 0; i < heuristic_open_routine_idx; i++) {
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1) {
wtap_close(wth);
return NULL;
}
wth->wslua_data = open_routines[i].wslua_data;
switch ((*open_routines[i].open_routine)(wth, err, err_info)) {
case WTAP_OPEN_ERROR:
wtap_close(wth);
return NULL;
case WTAP_OPEN_NOT_MINE:
break;
case WTAP_OPEN_MINE:
goto success;
}
}
extension = get_file_extension(filename);
if (extension != NULL) {
for (i = heuristic_open_routine_idx; i < open_info_arr->len; i++) {
if (heuristic_uses_extension(i, extension)) {
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1) {
g_free(extension);
wtap_close(wth);
return NULL;
}
wth->wslua_data = open_routines[i].wslua_data;
switch ((*open_routines[i].open_routine)(wth,
err, err_info)) {
case WTAP_OPEN_ERROR:
g_free(extension);
wtap_close(wth);
return NULL;
case WTAP_OPEN_NOT_MINE:
break;
case WTAP_OPEN_MINE:
g_free(extension);
goto success;
}
}
}
for (i = heuristic_open_routine_idx; i < open_info_arr->len; i++) {
if (open_routines[i].extensions == NULL) {
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1) {
g_free(extension);
wtap_close(wth);
return NULL;
}
wth->wslua_data = open_routines[i].wslua_data;
switch ((*open_routines[i].open_routine)(wth,
err, err_info)) {
case WTAP_OPEN_ERROR:
g_free(extension);
wtap_close(wth);
return NULL;
case WTAP_OPEN_NOT_MINE:
break;
case WTAP_OPEN_MINE:
g_free(extension);
goto success;
}
}
}
for (i = heuristic_open_routine_idx; i < open_info_arr->len; i++) {
if (open_routines[i].extensions != NULL &&
!heuristic_uses_extension(i, extension)) {
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1) {
g_free(extension);
wtap_close(wth);
return NULL;
}
wth->wslua_data = open_routines[i].wslua_data;
switch ((*open_routines[i].open_routine)(wth,
err, err_info)) {
case WTAP_OPEN_ERROR:
g_free(extension);
wtap_close(wth);
return NULL;
case WTAP_OPEN_NOT_MINE:
break;
case WTAP_OPEN_MINE:
g_free(extension);
goto success;
}
}
}
g_free(extension);
} else {
for (i = heuristic_open_routine_idx; i < open_info_arr->len; i++) {
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1) {
wtap_close(wth);
return NULL;
}
wth->wslua_data = open_routines[i].wslua_data;
switch ((*open_routines[i].open_routine)(wth, err, err_info)) {
case WTAP_OPEN_ERROR:
wtap_close(wth);
return NULL;
case WTAP_OPEN_NOT_MINE:
break;
case WTAP_OPEN_MINE:
goto success;
}
}
}
fail:
wtap_close(wth);
*err = WTAP_ERR_FILE_UNKNOWN_FORMAT;
return NULL;
success:
wth->frame_buffer = (struct Buffer *)g_malloc(sizeof(struct Buffer));
ws_buffer_init(wth->frame_buffer, 1500);
if ((wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_PCAP) ||
(wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_PCAP_NSEC)) {
wtap_block_t descr = wtap_block_create(WTAP_BLOCK_IF_DESCR);
wtapng_if_descr_mandatory_t* descr_mand = (wtapng_if_descr_mandatory_t*)wtap_block_get_mandatory_data(descr);
descr_mand->wtap_encap = wth->file_encap;
if (wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_PCAP_NSEC) {
descr_mand->time_units_per_second = 1000000000;
wtap_block_add_uint8_option(descr, OPT_IDB_TSRESOL, 9);
descr_mand->tsprecision = WTAP_TSPREC_NSEC;
} else {
descr_mand->time_units_per_second = 1000000;
descr_mand->tsprecision = WTAP_TSPREC_USEC;
}
descr_mand->snap_len = wth->snapshot_length;
descr_mand->num_stat_entries = 0;
descr_mand->interface_statistics = NULL;
g_array_append_val(wth->interface_data, descr);
}
return wth;
}
gboolean
wtap_fdreopen(wtap *wth, const char *filename, int *err)
{
ws_statb64 statb;
if (strcmp(filename, "-") == 0) {
*err = WTAP_ERR_RANDOM_OPEN_STDIN;
return FALSE;
}
if (ws_stat64(filename, &statb) < 0) {
*err = errno;
return FALSE;
}
if (S_ISFIFO(statb.st_mode)) {
*err = WTAP_ERR_RANDOM_OPEN_PIPE;
return FALSE;
} else if (S_ISDIR(statb.st_mode)) {
*err = EISDIR;
return FALSE;
} else if (! S_ISREG(statb.st_mode)) {
*err = WTAP_ERR_NOT_REGULAR_FILE;
return FALSE;
}
errno = WTAP_ERR_CANT_OPEN;
if (!file_fdreopen(wth->random_fh, filename)) {
*err = errno;
return FALSE;
}
return TRUE;
}
static void
init_file_types_subtypes_garray(void)
{
if (dump_open_table_arr) return;
dump_open_table_arr = g_array_new(FALSE,TRUE,sizeof(struct file_type_subtype_info));
g_array_append_vals(dump_open_table_arr,dump_open_table_base,wtap_num_file_types_subtypes);
dump_open_table = (const struct file_type_subtype_info*)(void *)dump_open_table_arr->data;
}
int
wtap_register_file_type_subtypes(const struct file_type_subtype_info* fi, const int subtype)
{
struct file_type_subtype_info* finfo;
if (!fi || !fi->name || !fi->short_name || subtype > wtap_num_file_types_subtypes) {
g_error("no file type info or invalid file type to register");
return subtype;
}
if (subtype == WTAP_FILE_TYPE_SUBTYPE_UNKNOWN) {
if (wtap_short_string_to_file_type_subtype(fi->short_name) > -1 ) {
g_error("file type short name already exists");
return subtype;
}
init_file_types_subtypes_garray();
g_array_append_val(dump_open_table_arr,*fi);
dump_open_table = (const struct file_type_subtype_info*)(void *)dump_open_table_arr->data;
return wtap_num_file_types_subtypes++;
}
if (!dump_open_table[subtype].short_name || strcmp(dump_open_table[subtype].short_name,fi->short_name) != 0) {
g_error("invalid file type name given to register");
return subtype;
}
init_file_types_subtypes_garray();
finfo = &g_array_index(dump_open_table_arr, struct file_type_subtype_info, subtype);
finfo->default_file_extension = fi->default_file_extension;
finfo->additional_file_extensions = fi->additional_file_extensions;
finfo->writing_must_seek = fi->writing_must_seek;
finfo->has_name_resolution = fi->has_name_resolution;
finfo->supported_comment_types = fi->supported_comment_types;
finfo->can_write_encap = fi->can_write_encap;
finfo->dump_open = fi->dump_open;
finfo->wslua_info = fi->wslua_info;
return subtype;
}
void
wtap_deregister_file_type_subtype(const int subtype)
{
struct file_type_subtype_info* finfo;
if (subtype < 0 || subtype >= wtap_num_file_types_subtypes) {
g_error("invalid file type to de-register");
return;
}
init_file_types_subtypes_garray();
finfo = &g_array_index(dump_open_table_arr, struct file_type_subtype_info, subtype);
finfo->default_file_extension = NULL;
finfo->additional_file_extensions = NULL;
finfo->writing_must_seek = FALSE;
finfo->has_name_resolution = FALSE;
finfo->supported_comment_types = 0;
finfo->can_write_encap = NULL;
finfo->dump_open = NULL;
finfo->wslua_info = NULL;
}
int
wtap_get_num_file_types_subtypes(void)
{
return wtap_num_file_types_subtypes;
}
int
wtap_dump_file_encap_type(const GArray *file_encaps)
{
int encap;
encap = WTAP_ENCAP_PER_PACKET;
if (file_encaps->len == 1) {
encap = g_array_index(file_encaps, gint, 0);
}
return encap;
}
static gboolean
wtap_dump_can_write_encap(int filetype, int encap)
{
int result = 0;
if (filetype < 0 || filetype >= wtap_num_file_types_subtypes
|| dump_open_table[filetype].can_write_encap == NULL)
return FALSE;
result = (*dump_open_table[filetype].can_write_encap)(encap);
if (result != 0) {
if (result == WTAP_ERR_CHECK_WSLUA
&& dump_open_table[filetype].wslua_info != NULL
&& dump_open_table[filetype].wslua_info->wslua_can_write_encap != NULL) {
result = (*dump_open_table[filetype].wslua_info->wslua_can_write_encap)(encap, dump_open_table[filetype].wslua_info->wslua_data);
}
if (result != 0)
return FALSE;
}
return TRUE;
}
static gboolean
wtap_dump_can_write_format(int ft, const GArray *file_encaps,
guint32 required_comment_types)
{
guint i;
if (!wtap_dump_can_open(ft)) {
return FALSE;
}
if (!wtap_dump_supports_comment_types(ft, required_comment_types)) {
return FALSE;
}
if (!wtap_dump_can_write_encap(ft, wtap_dump_file_encap_type(file_encaps))) {
return FALSE;
}
for (i = 0; i < file_encaps->len; i++) {
if (!wtap_dump_can_write_encap(ft,
g_array_index(file_encaps, int, i))) {
return FALSE;
}
}
return TRUE;
}
gboolean
wtap_dump_can_write(const GArray *file_encaps, guint32 required_comment_types)
{
int ft;
for (ft = 0; ft < WTAP_NUM_FILE_TYPES_SUBTYPES; ft++) {
if (wtap_dump_can_write_format(ft, file_encaps, required_comment_types)) {
return TRUE;
}
}
return FALSE;
}
GArray *
wtap_get_savable_file_types_subtypes(int file_type_subtype,
const GArray *file_encaps, guint32 required_comment_types)
{
GArray *savable_file_types_subtypes;
int ft;
int default_file_type_subtype = -1;
int other_file_type_subtype = -1;
if (wtap_dump_can_write_format(file_type_subtype, file_encaps,
required_comment_types)) {
default_file_type_subtype = file_type_subtype;
} else {
default_file_type_subtype = -1;
for (ft = 0; ft < WTAP_NUM_FILE_TYPES_SUBTYPES; ft++) {
if (wtap_dump_can_write_format(ft, file_encaps,
required_comment_types)) {
default_file_type_subtype = ft;
}
}
}
if (default_file_type_subtype == -1) {
return NULL;
}
savable_file_types_subtypes = g_array_new(FALSE, FALSE, (guint)sizeof (int));
g_array_append_val(savable_file_types_subtypes, default_file_type_subtype);
if (default_file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_PCAP) {
if (wtap_dump_can_write_format(WTAP_FILE_TYPE_SUBTYPE_PCAPNG, file_encaps,
required_comment_types))
other_file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_PCAPNG;
} else if (default_file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_PCAPNG) {
if (wtap_dump_can_write_format(WTAP_FILE_TYPE_SUBTYPE_PCAP, file_encaps,
required_comment_types))
other_file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_PCAP;
}
if (other_file_type_subtype != -1)
g_array_append_val(savable_file_types_subtypes, other_file_type_subtype);
for (ft = 0; ft < WTAP_NUM_FILE_TYPES_SUBTYPES; ft++) {
if (ft == WTAP_FILE_TYPE_SUBTYPE_UNKNOWN)
continue;
if (ft == default_file_type_subtype || ft == other_file_type_subtype)
continue;
if (wtap_dump_can_write_format(ft, file_encaps,
required_comment_types)) {
g_array_append_val(savable_file_types_subtypes, ft);
}
}
return savable_file_types_subtypes;
}
const char *
wtap_file_type_subtype_string(int file_type_subtype)
{
if (file_type_subtype < 0 || file_type_subtype >= wtap_num_file_types_subtypes) {
g_error("Unknown capture file type %d", file_type_subtype);
return "";
} else
return dump_open_table[file_type_subtype].name;
}
const char *
wtap_file_type_subtype_short_string(int file_type_subtype)
{
if (file_type_subtype < 0 || file_type_subtype >= wtap_num_file_types_subtypes)
return NULL;
else
return dump_open_table[file_type_subtype].short_name;
}
int
wtap_short_string_to_file_type_subtype(const char *short_name)
{
int file_type_subtype;
for (file_type_subtype = 0; file_type_subtype < wtap_num_file_types_subtypes; file_type_subtype++) {
if (dump_open_table[file_type_subtype].short_name != NULL &&
strcmp(short_name, dump_open_table[file_type_subtype].short_name) == 0)
return file_type_subtype;
}
if (strcmp(short_name, "libpcap") == 0)
return WTAP_FILE_TYPE_SUBTYPE_PCAP;
else if (strcmp(short_name, "nseclibpcap") == 0)
return WTAP_FILE_TYPE_SUBTYPE_PCAP_NSEC;
else if (strcmp(short_name, "aixlibpcap") == 0)
return WTAP_FILE_TYPE_SUBTYPE_PCAP_AIX;
else if (strcmp(short_name, "modlibpcap") == 0)
return WTAP_FILE_TYPE_SUBTYPE_PCAP_SS991029;
else if (strcmp(short_name, "nokialibpcap") == 0)
return WTAP_FILE_TYPE_SUBTYPE_PCAP_NOKIA;
else if (strcmp(short_name, "rh6_1libpcap") == 0)
return WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990417;
else if (strcmp(short_name, "suse6_3libpcap") == 0)
return WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990915;
return -1;
}
static GSList *
add_extensions_for_file_type_subtype(int file_type_subtype, GSList *extensions,
const char **compressed_file_extensions)
{
gchar **extensions_set, **extensionp;
gchar *extension;
extensions = add_extensions(extensions,
dump_open_table[file_type_subtype].default_file_extension,
compressed_file_extensions);
if (dump_open_table[file_type_subtype].additional_file_extensions != NULL) {
extensions_set = g_strsplit(dump_open_table[file_type_subtype].additional_file_extensions,
";", 0);
for (extensionp = extensions_set; *extensionp != NULL;
extensionp++) {
extension = *extensionp;
extensions = add_extensions(extensions, extension,
compressed_file_extensions);
}
g_strfreev(extensions_set);
}
return extensions;
}
GSList *
wtap_get_file_extensions_list(int file_type_subtype, gboolean include_compressed)
{
GSList *extensions;
static const char *no_compressed_extensions[] = {
NULL
};
if (file_type_subtype < 0 || file_type_subtype >= wtap_num_file_types_subtypes)
return NULL;
if (dump_open_table[file_type_subtype].default_file_extension == NULL)
return NULL;
extensions = NULL;
extensions = add_extensions_for_file_type_subtype(file_type_subtype, extensions,
include_compressed ? compressed_file_extension_table : no_compressed_extensions);
return extensions;
}
void
wtap_free_extensions_list(GSList *extensions)
{
GSList *extension;
for (extension = extensions; extension != NULL;
extension = g_slist_next(extension)) {
g_free(extension->data);
}
g_slist_free(extensions);
}
const char *
wtap_default_file_extension(int file_type_subtype)
{
if (file_type_subtype < 0 || file_type_subtype >= wtap_num_file_types_subtypes)
return NULL;
else
return dump_open_table[file_type_subtype].default_file_extension;
}
gboolean
wtap_dump_can_open(int file_type_subtype)
{
if (file_type_subtype < 0 || file_type_subtype >= wtap_num_file_types_subtypes
|| dump_open_table[file_type_subtype].dump_open == NULL)
return FALSE;
return TRUE;
}
gboolean
wtap_dump_can_compress(int file_type_subtype)
{
if (file_type_subtype < 0 || file_type_subtype >= wtap_num_file_types_subtypes
|| dump_open_table[file_type_subtype].writing_must_seek)
return FALSE;
return TRUE;
}
gboolean
wtap_dump_can_compress(int file_type_subtype _U_)
{
return FALSE;
}
gboolean
wtap_dump_has_name_resolution(int file_type_subtype)
{
if (file_type_subtype < 0 || file_type_subtype >= wtap_num_file_types_subtypes
|| dump_open_table[file_type_subtype].has_name_resolution == FALSE)
return FALSE;
return TRUE;
}
gboolean
wtap_dump_supports_comment_types(int file_type_subtype, guint32 comment_types)
{
guint32 supported_comment_types;
if (file_type_subtype < 0 || file_type_subtype >= wtap_num_file_types_subtypes)
return FALSE;
supported_comment_types = dump_open_table[file_type_subtype].supported_comment_types;
if ((comment_types & supported_comment_types) == comment_types)
return TRUE;
return FALSE;
}
static wtap_dumper *
wtap_dump_init_dumper(int file_type_subtype, int encap, int snaplen, gboolean compressed,
GArray* shb_hdrs, wtapng_iface_descriptions_t *idb_inf,
GArray* nrb_hdrs, int *err)
{
wtap_dumper *wdh;
wtap_block_t descr, file_int_data;
wtapng_if_descr_mandatory_t *descr_mand, *file_int_data_mand;
if (!wtap_dump_open_check(file_type_subtype, encap, compressed, err))
return NULL;
wdh = wtap_dump_alloc_wdh(file_type_subtype, encap, snaplen, compressed, err);
if (wdh == NULL)
return NULL;
wdh->shb_hdrs = shb_hdrs;
wdh->nrb_hdrs = nrb_hdrs;
if ((idb_inf != NULL) && (idb_inf->interface_data->len > 0)) {
guint itf_count;
wdh->interface_data = g_array_new(FALSE, FALSE, sizeof(wtap_block_t));
for (itf_count = 0; itf_count < idb_inf->interface_data->len; itf_count++) {
file_int_data = g_array_index(idb_inf->interface_data, wtap_block_t, itf_count);
file_int_data_mand = (wtapng_if_descr_mandatory_t*)wtap_block_get_mandatory_data(file_int_data);
descr = wtap_block_create(WTAP_BLOCK_IF_DESCR);
wtap_block_copy(descr, file_int_data);
if ((encap != WTAP_ENCAP_PER_PACKET) && (encap != file_int_data_mand->wtap_encap)) {
descr_mand = (wtapng_if_descr_mandatory_t*)wtap_block_get_mandatory_data(descr);
descr_mand->wtap_encap = encap;
}
g_array_append_val(wdh->interface_data, descr);
}
} else {
descr = wtap_block_create(WTAP_BLOCK_IF_DESCR);
descr_mand = (wtapng_if_descr_mandatory_t*)wtap_block_get_mandatory_data(descr);
descr_mand->wtap_encap = encap;
descr_mand->time_units_per_second = 1000000;
if (snaplen == 0) {
if (encap == WTAP_ENCAP_DBUS)
snaplen = 128*1024*1024;
else
snaplen = WTAP_MAX_PACKET_SIZE_STANDARD;
}
descr_mand->snap_len = snaplen;
descr_mand->num_stat_entries = 0;
descr_mand->interface_statistics = NULL;
wdh->interface_data = g_array_new(FALSE, FALSE, sizeof(wtap_block_t));
g_array_append_val(wdh->interface_data, descr);
}
return wdh;
}
wtap_dumper *
wtap_dump_open(const char *filename, int file_type_subtype, int encap,
int snaplen, gboolean compressed, int *err)
{
return wtap_dump_open_ng(filename, file_type_subtype, encap,snaplen, compressed, NULL, NULL, NULL, err);
}
wtap_dumper *
wtap_dump_open_ng(const char *filename, int file_type_subtype, int encap,
int snaplen, gboolean compressed, GArray* shb_hdrs, wtapng_iface_descriptions_t *idb_inf,
GArray* nrb_hdrs, int *err)
{
wtap_dumper *wdh;
WFILE_T fh;
wdh = wtap_dump_init_dumper(file_type_subtype, encap, snaplen, compressed,
shb_hdrs, idb_inf, nrb_hdrs, err);
if (wdh == NULL)
return NULL;
errno = WTAP_ERR_CANT_OPEN;
fh = wtap_dump_file_open(wdh, filename);
if (fh == NULL) {
*err = errno;
g_free(wdh);
return NULL;
}
wdh->fh = fh;
if (!wtap_dump_open_finish(wdh, file_type_subtype, compressed, err)) {
wtap_dump_file_close(wdh);
ws_unlink(filename);
g_free(wdh);
return NULL;
}
return wdh;
}
wtap_dumper *
wtap_dump_open_tempfile(char **filenamep, const char *pfx,
int file_type_subtype, int encap,
int snaplen, gboolean compressed, int *err)
{
return wtap_dump_open_tempfile_ng(filenamep, pfx, file_type_subtype, encap,snaplen, compressed, NULL, NULL, NULL, err);
}
wtap_dumper *
wtap_dump_open_tempfile_ng(char **filenamep, const char *pfx,
int file_type_subtype, int encap,
int snaplen, gboolean compressed,
GArray* shb_hdrs,
wtapng_iface_descriptions_t *idb_inf,
GArray* nrb_hdrs, int *err)
{
int fd;
char *tmpname;
wtap_dumper *wdh;
WFILE_T fh;
*filenamep = NULL;
wdh = wtap_dump_init_dumper(file_type_subtype, encap, snaplen, compressed,
shb_hdrs, idb_inf, nrb_hdrs, err);
if (wdh == NULL)
return NULL;
fd = create_tempfile(&tmpname, pfx, ".pcapng");
if (fd == -1) {
*err = errno;
g_free(wdh);
return NULL;
}
*filenamep = tmpname;
errno = WTAP_ERR_CANT_OPEN;
fh = wtap_dump_file_fdopen(wdh, fd);
if (fh == NULL) {
*err = errno;
ws_close(fd);
g_free(wdh);
return NULL;
}
wdh->fh = fh;
if (!wtap_dump_open_finish(wdh, file_type_subtype, compressed, err)) {
wtap_dump_file_close(wdh);
ws_unlink(tmpname);
g_free(wdh);
return NULL;
}
return wdh;
}
wtap_dumper *
wtap_dump_fdopen(int fd, int file_type_subtype, int encap, int snaplen,
gboolean compressed, int *err)
{
return wtap_dump_fdopen_ng(fd, file_type_subtype, encap, snaplen, compressed, NULL, NULL, NULL, err);
}
wtap_dumper *
wtap_dump_fdopen_ng(int fd, int file_type_subtype, int encap, int snaplen,
gboolean compressed, GArray* shb_hdrs, wtapng_iface_descriptions_t *idb_inf,
GArray* nrb_hdrs, int *err)
{
wtap_dumper *wdh;
WFILE_T fh;
wdh = wtap_dump_init_dumper(file_type_subtype, encap, snaplen, compressed,
shb_hdrs, idb_inf, nrb_hdrs, err);
if (wdh == NULL)
return NULL;
errno = WTAP_ERR_CANT_OPEN;
fh = wtap_dump_file_fdopen(wdh, fd);
if (fh == NULL) {
*err = errno;
g_free(wdh);
return NULL;
}
wdh->fh = fh;
if (!wtap_dump_open_finish(wdh, file_type_subtype, compressed, err)) {
wtap_dump_file_close(wdh);
g_free(wdh);
return NULL;
}
return wdh;
}
wtap_dumper *
wtap_dump_open_stdout(int file_type_subtype, int encap, int snaplen,
gboolean compressed, int *err)
{
return wtap_dump_open_stdout_ng(file_type_subtype, encap, snaplen, compressed, NULL, NULL, NULL, err);
}
wtap_dumper *
wtap_dump_open_stdout_ng(int file_type_subtype, int encap, int snaplen,
gboolean compressed, GArray* shb_hdrs,
wtapng_iface_descriptions_t *idb_inf,
GArray* nrb_hdrs, int *err)
{
int new_fd;
wtap_dumper *wdh;
new_fd = ws_dup(1);
if (new_fd == -1) {
*err = errno;
return NULL;
}
#ifdef _WIN32
if (_setmode(new_fd, O_BINARY) == -1) {
*err = errno;
ws_close(new_fd);
return NULL;
}
#endif
wdh = wtap_dump_fdopen_ng(new_fd, file_type_subtype, encap, snaplen,
compressed, shb_hdrs, idb_inf, nrb_hdrs, err);
if (wdh == NULL) {
ws_close(new_fd);
return NULL;
}
return wdh;
}
static gboolean
wtap_dump_open_check(int file_type_subtype, int encap, gboolean compressed, int *err)
{
if (!wtap_dump_can_open(file_type_subtype)) {
*err = WTAP_ERR_UNWRITABLE_FILE_TYPE;
return FALSE;
}
*err = (*dump_open_table[file_type_subtype].can_write_encap)(encap);
if (*err == WTAP_ERR_CHECK_WSLUA
&& dump_open_table[file_type_subtype].wslua_info != NULL
&& dump_open_table[file_type_subtype].wslua_info->wslua_can_write_encap != NULL) {
*err = (*dump_open_table[file_type_subtype].wslua_info->wslua_can_write_encap)(encap, dump_open_table[file_type_subtype].wslua_info->wslua_data);
}
if (*err != 0)
return FALSE;
if(compressed && !wtap_dump_can_compress(file_type_subtype)) {
*err = WTAP_ERR_COMPRESSION_NOT_SUPPORTED;
return FALSE;
}
return TRUE;
}
static wtap_dumper *
wtap_dump_alloc_wdh(int file_type_subtype, int encap, int snaplen, gboolean compressed, int *err)
{
wtap_dumper *wdh;
wdh = (wtap_dumper *)g_malloc0(sizeof (wtap_dumper));
if (wdh == NULL) {
*err = errno;
return NULL;
}
wdh->file_type_subtype = file_type_subtype;
wdh->snaplen = snaplen;
wdh->encap = encap;
wdh->compressed = compressed;
wdh->wslua_data = NULL;
return wdh;
}
static gboolean
wtap_dump_open_finish(wtap_dumper *wdh, int file_type_subtype, gboolean compressed, int *err)
{
int fd;
gboolean cant_seek;
if(compressed) {
cant_seek = TRUE;
} else {
fd = ws_fileno((FILE *)wdh->fh);
if (ws_lseek64(fd, 1, SEEK_CUR) == (off_t) -1)
cant_seek = TRUE;
else {
ws_lseek64(fd, 0, SEEK_SET);
cant_seek = FALSE;
}
}
if (dump_open_table[file_type_subtype].writing_must_seek && cant_seek) {
*err = WTAP_ERR_CANT_WRITE_TO_PIPE;
return FALSE;
}
if (dump_open_table[file_type_subtype].wslua_info)
wdh->wslua_data = dump_open_table[file_type_subtype].wslua_info->wslua_data;
if (!(*dump_open_table[file_type_subtype].dump_open)(wdh, err)) {
return FALSE;
}
return TRUE;
}
gboolean
wtap_dump(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err, gchar **err_info)
{
*err = 0;
*err_info = NULL;
return (wdh->subtype_write)(wdh, phdr, pd, err, err_info);
}
void
wtap_dump_flush(wtap_dumper *wdh)
{
#ifdef HAVE_ZLIB
if(wdh->compressed) {
gzwfile_flush((GZWFILE_T)wdh->fh);
} else
#endif
{
fflush((FILE *)wdh->fh);
}
}
gboolean
wtap_dump_close(wtap_dumper *wdh, int *err)
{
gboolean ret = TRUE;
if (wdh->subtype_finish != NULL) {
if (!(wdh->subtype_finish)(wdh, err))
ret = FALSE;
}
errno = WTAP_ERR_CANT_CLOSE;
if (wtap_dump_file_close(wdh) == EOF) {
if (ret) {
if (err != NULL)
*err = errno;
}
ret = FALSE;
}
if (wdh->priv != NULL)
g_free(wdh->priv);
wtap_block_array_free(wdh->interface_data);
g_free(wdh);
return ret;
}
gint64
wtap_get_bytes_dumped(wtap_dumper *wdh)
{
return wdh->bytes_dumped;
}
void
wtap_set_bytes_dumped(wtap_dumper *wdh, gint64 bytes_dumped)
{
wdh->bytes_dumped = bytes_dumped;
}
gboolean
wtap_dump_set_addrinfo_list(wtap_dumper *wdh, addrinfo_lists_t *addrinfo_lists)
{
if (!wdh || wdh->file_type_subtype < 0 || wdh->file_type_subtype >= wtap_num_file_types_subtypes
|| dump_open_table[wdh->file_type_subtype].has_name_resolution == FALSE)
return FALSE;
wdh->addrinfo_lists = addrinfo_lists;
return TRUE;
}
gboolean wtap_dump_get_needs_reload(wtap_dumper *wdh) {
return wdh->needs_reload;
}
static WFILE_T
wtap_dump_file_open(wtap_dumper *wdh, const char *filename)
{
if(wdh->compressed) {
return gzwfile_open(filename);
} else {
return ws_fopen(filename, "wb");
}
}
static WFILE_T
wtap_dump_file_open(wtap_dumper *wdh _U_, const char *filename)
{
return ws_fopen(filename, "wb");
}
static WFILE_T
wtap_dump_file_fdopen(wtap_dumper *wdh, int fd)
{
if(wdh->compressed) {
return gzwfile_fdopen(fd);
} else {
return ws_fdopen(fd, "wb");
}
}
static WFILE_T
wtap_dump_file_fdopen(wtap_dumper *wdh _U_, int fd)
{
return ws_fdopen(fd, "wb");
}
gboolean
wtap_dump_file_write(wtap_dumper *wdh, const void *buf, size_t bufsize, int *err)
{
size_t nwritten;
#ifdef HAVE_ZLIB
if (wdh->compressed) {
nwritten = gzwfile_write((GZWFILE_T)wdh->fh, buf, (unsigned int) bufsize);
if (nwritten == 0) {
*err = gzwfile_geterr((GZWFILE_T)wdh->fh);
return FALSE;
}
} else
#endif
{
errno = WTAP_ERR_CANT_WRITE;
nwritten = fwrite(buf, 1, bufsize, (FILE *)wdh->fh);
if (nwritten != bufsize) {
if (ferror((FILE *)wdh->fh))
*err = errno;
else
*err = WTAP_ERR_SHORT_WRITE;
return FALSE;
}
}
return TRUE;
}
static int
wtap_dump_file_close(wtap_dumper *wdh)
{
#ifdef HAVE_ZLIB
if(wdh->compressed)
return gzwfile_close((GZWFILE_T)wdh->fh);
else
#endif
return fclose((FILE *)wdh->fh);
}
gint64
wtap_dump_file_seek(wtap_dumper *wdh, gint64 offset, int whence, int *err)
{
#ifdef HAVE_ZLIB
if(wdh->compressed) {
*err = WTAP_ERR_CANT_SEEK_COMPRESSED;
return -1;
} else
#endif
{
if (-1 == fseek((FILE *)wdh->fh, (long)offset, whence)) {
*err = errno;
return -1;
} else
{
return 0;
}
}
}
gint64
wtap_dump_file_tell(wtap_dumper *wdh, int *err)
{
gint64 rval;
#ifdef HAVE_ZLIB
if(wdh->compressed) {
*err = WTAP_ERR_CANT_SEEK_COMPRESSED;
return -1;
} else
#endif
{
if (-1 == (rval = ftell((FILE *)wdh->fh))) {
*err = errno;
return -1;
} else
{
return rval;
}
}
}
void
cleanup_open_routines(void)
{
guint i;
struct open_info *i_open;
if (open_routines != NULL && open_info_arr) {
for (i = 0, i_open = open_routines; i < open_info_arr->len; i++, i_open++) {
if (i_open->extensions != NULL)
g_strfreev(i_open->extensions_set);
}
g_array_free(open_info_arr, TRUE);
open_info_arr = NULL;
}
}
