static gboolean
check_for_wtap_plugin(GModule *handle)
{
gpointer gp;
wtap_plugin *plugin;
if (!g_module_symbol(handle, "register_wtap_module", &gp)) {
return FALSE;
}
plugin = (wtap_plugin *)g_malloc(sizeof (wtap_plugin));
DIAG_OFF(pedantic)
plugin->register_wtap_module = (void (*)(void))gp;
DIAG_ON(pedantic)
wtap_plugins = g_slist_append(wtap_plugins, plugin);
return TRUE;
}
void
wtap_register_plugin_types(void)
{
wtap_opttypes_initialize();
add_plugin_type("libwiretap", check_for_wtap_plugin);
}
static void
register_wtap_module_plugin(gpointer data, gpointer user_data _U_)
{
wtap_plugin *plugin = (wtap_plugin *)data;
(plugin->register_wtap_module)();
}
void
register_all_wiretap_modules(void)
{
g_slist_foreach(wtap_plugins, register_wtap_module_plugin, NULL);
}
gint64
wtap_file_size(wtap *wth, int *err)
{
ws_statb64 statb;
if (file_fstat((wth->fh == NULL) ? wth->random_fh : wth->fh,
&statb, err) == -1)
return -1;
return statb.st_size;
}
int
wtap_fstat(wtap *wth, ws_statb64 *statb, int *err)
{
if (file_fstat((wth->fh == NULL) ? wth->random_fh : wth->fh,
statb, err) == -1)
return -1;
return 0;
}
int
wtap_file_type_subtype(wtap *wth)
{
return wth->file_type_subtype;
}
gboolean
wtap_iscompressed(wtap *wth)
{
return file_iscompressed((wth->fh == NULL) ? wth->random_fh : wth->fh);
}
guint
wtap_snapshot_length(wtap *wth)
{
return wth->snapshot_length;
}
int
wtap_file_encap(wtap *wth)
{
return wth->file_encap;
}
int
wtap_file_tsprec(wtap *wth)
{
return wth->file_tsprec;
}
wtap_block_t
wtap_file_get_shb(wtap *wth)
{
if ((wth == NULL) || (wth->shb_hdrs == NULL) || (wth->shb_hdrs->len == 0))
return NULL;
return g_array_index(wth->shb_hdrs, wtap_block_t, 0);
}
GArray*
wtap_file_get_shb_for_new_file(wtap *wth)
{
guint shb_count;
wtap_block_t shb_hdr_src, shb_hdr_dest;
GArray* shb_hdrs;
if ((wth == NULL) || (wth->shb_hdrs == NULL) || (wth->shb_hdrs->len == 0))
return NULL;
shb_hdrs = g_array_new(FALSE, FALSE, sizeof(wtap_block_t));
for (shb_count = 0; shb_count < wth->shb_hdrs->len; shb_count++) {
shb_hdr_src = g_array_index(wth->shb_hdrs, wtap_block_t, shb_count);
shb_hdr_dest = wtap_block_create(WTAP_BLOCK_NG_SECTION);
wtap_block_copy(shb_hdr_dest, shb_hdr_src);
g_array_append_val(shb_hdrs, shb_hdr_dest);
}
return shb_hdrs;
}
void
wtap_write_shb_comment(wtap *wth, gchar *comment)
{
if ((wth != NULL) && (wth->shb_hdrs != NULL) && (wth->shb_hdrs->len > 0)) {
wtap_block_set_nth_string_option_value(g_array_index(wth->shb_hdrs, wtap_block_t, 0), OPT_COMMENT, 0, comment, (gsize)(comment ? strlen(comment) : 0));
}
}
wtapng_iface_descriptions_t *
wtap_file_get_idb_info(wtap *wth)
{
wtapng_iface_descriptions_t *idb_info;
idb_info = g_new(wtapng_iface_descriptions_t,1);
idb_info->interface_data = wth->interface_data;
return idb_info;
}
void
wtap_free_idb_info(wtapng_iface_descriptions_t *idb_info)
{
if (idb_info == NULL)
return;
wtap_block_array_free(idb_info->interface_data);
g_free(idb_info);
}
gchar *
wtap_get_debug_if_descr(const wtap_block_t if_descr,
const int indent,
const char* line_end)
{
char* tmp_content;
wtapng_if_descr_mandatory_t* if_descr_mand;
GString *info = g_string_new("");
guint64 tmp64;
gint8 itmp8;
guint8 tmp8;
wtapng_if_descr_filter_t* if_filter;
g_assert(if_descr);
if_descr_mand = (wtapng_if_descr_mandatory_t*)wtap_block_get_mandatory_data(if_descr);
if (wtap_block_get_string_option_value(if_descr, OPT_IDB_NAME, &tmp_content) == WTAP_OPTTYPE_SUCCESS) {
g_string_printf(info,
"%*cName = %s%s", indent, ' ',
tmp_content ? tmp_content : "UNKNOWN",
line_end);
}
if (wtap_block_get_string_option_value(if_descr, OPT_IDB_DESCR, &tmp_content) == WTAP_OPTTYPE_SUCCESS) {
g_string_append_printf(info,
"%*cDescription = %s%s", indent, ' ',
tmp_content ? tmp_content : "NONE",
line_end);
}
g_string_append_printf(info,
"%*cEncapsulation = %s (%d/%u - %s)%s", indent, ' ',
wtap_encap_string(if_descr_mand->wtap_encap),
if_descr_mand->wtap_encap,
if_descr_mand->link_type,
wtap_encap_short_string(if_descr_mand->wtap_encap),
line_end);
if (wtap_block_get_uint64_option_value(if_descr, OPT_IDB_SPEED, &tmp64) == WTAP_OPTTYPE_SUCCESS) {
g_string_append_printf(info,
"%*cSpeed = %" G_GINT64_MODIFIER "u%s", indent, ' ',
tmp64,
line_end);
}
g_string_append_printf(info,
"%*cCapture length = %u%s", indent, ' ',
if_descr_mand->snap_len,
line_end);
if (wtap_block_get_uint8_option_value(if_descr, OPT_IDB_FCSLEN, &itmp8) == WTAP_OPTTYPE_SUCCESS) {
g_string_append_printf(info,
"%*cFCS length = %d%s", indent, ' ',
itmp8,
line_end);
}
g_string_append_printf(info,
"%*cTime precision = %s (%d)%s", indent, ' ',
wtap_tsprec_string(if_descr_mand->tsprecision),
if_descr_mand->tsprecision,
line_end);
g_string_append_printf(info,
"%*cTime ticks per second = %" G_GINT64_MODIFIER "u%s", indent, ' ',
if_descr_mand->time_units_per_second,
line_end);
if (wtap_block_get_uint8_option_value(if_descr, OPT_IDB_TSRESOL, &tmp8) == WTAP_OPTTYPE_SUCCESS) {
g_string_append_printf(info,
"%*cTime resolution = 0x%.2x%s", indent, ' ',
tmp8,
line_end);
}
if (wtap_block_get_custom_option_value(if_descr, OPT_IDB_FILTER, (void**)&if_filter) == WTAP_OPTTYPE_SUCCESS) {
g_string_append_printf(info,
"%*cFilter string = %s%s", indent, ' ',
if_filter->if_filter_str ? if_filter->if_filter_str : "NONE",
line_end);
g_string_append_printf(info,
"%*cBPF filter length = %u%s", indent, ' ',
if_filter->bpf_filter_len,
line_end);
}
if (wtap_block_get_string_option_value(if_descr, OPT_IDB_OS, &tmp_content) == WTAP_OPTTYPE_SUCCESS) {
g_string_append_printf(info,
"%*cOperating system = %s%s", indent, ' ',
tmp_content ? tmp_content : "UNKNOWN",
line_end);
}
if (wtap_block_get_nth_string_option_value(if_descr, OPT_COMMENT, 0, &tmp_content) == WTAP_OPTTYPE_SUCCESS) {
g_string_append_printf(info,
"%*cComment = %s%s", indent, ' ',
tmp_content ? tmp_content : "NONE",
line_end);
}
g_string_append_printf(info,
"%*cNumber of stat entries = %u%s", indent, ' ',
if_descr_mand->num_stat_entries,
line_end);
return g_string_free(info, FALSE);
}
wtap_block_t
wtap_file_get_nrb(wtap *wth)
{
if ((wth == NULL) || (wth->nrb_hdrs == NULL) || (wth->nrb_hdrs->len == 0))
return NULL;
return g_array_index(wth->nrb_hdrs, wtap_block_t, 0);
}
GArray*
wtap_file_get_nrb_for_new_file(wtap *wth)
{
guint nrb_count;
wtap_block_t nrb_hdr_src, nrb_hdr_dest;
GArray* nrb_hdrs;
if ((wth == NULL || wth->nrb_hdrs == NULL) || (wth->nrb_hdrs->len == 0))
return NULL;
nrb_hdrs = g_array_new(FALSE, FALSE, sizeof(wtap_block_t));
for (nrb_count = 0; nrb_count < wth->nrb_hdrs->len; nrb_count++) {
nrb_hdr_src = g_array_index(wth->nrb_hdrs, wtap_block_t, nrb_count);
nrb_hdr_dest = wtap_block_create(WTAP_BLOCK_NG_NRB);
wtap_block_copy(nrb_hdr_dest, nrb_hdr_src);
g_array_append_val(nrb_hdrs, nrb_hdr_dest);
}
return nrb_hdrs;
}
static void wtap_init_encap_types(void) {
if (encap_table_arr) return;
encap_table_arr = g_array_new(FALSE,TRUE,sizeof(struct encap_type_info));
g_array_append_vals(encap_table_arr,encap_table_base,wtap_num_encap_types);
}
int wtap_get_num_encap_types(void) {
wtap_init_encap_types();
return wtap_num_encap_types;
}
int wtap_register_encap_type(const char* name, const char* short_name) {
struct encap_type_info e;
wtap_init_encap_types();
e.name = g_strdup(name);
e.short_name = g_strdup(short_name);
g_array_append_val(encap_table_arr,e);
return wtap_num_encap_types++;
}
const char *
wtap_encap_string(int encap)
{
if (encap < WTAP_ENCAP_PER_PACKET || encap >= WTAP_NUM_ENCAP_TYPES)
return "Illegal";
else if (encap == WTAP_ENCAP_PER_PACKET)
return "Per packet";
else
return encap_table_entry(encap).name;
}
const char *
wtap_encap_short_string(int encap)
{
if (encap < WTAP_ENCAP_PER_PACKET || encap >= WTAP_NUM_ENCAP_TYPES)
return "illegal";
else if (encap == WTAP_ENCAP_PER_PACKET)
return "per-packet";
else
return encap_table_entry(encap).short_name;
}
int
wtap_short_string_to_encap(const char *short_name)
{
int encap;
for (encap = 0; encap < WTAP_NUM_ENCAP_TYPES; encap++) {
if (encap_table_entry(encap).short_name != NULL &&
strcmp(short_name, encap_table_entry(encap).short_name) == 0)
return encap;
}
return -1;
}
const char*
wtap_tsprec_string(int tsprec)
{
const char* s;
switch (tsprec) {
case WTAP_TSPREC_PER_PACKET:
s = "per-packet";
break;
case WTAP_TSPREC_SEC:
s = "seconds";
break;
case WTAP_TSPREC_DSEC:
s = "deciseconds";
break;
case WTAP_TSPREC_CSEC:
s = "centiseconds";
break;
case WTAP_TSPREC_MSEC:
s = "milliseconds";
break;
case WTAP_TSPREC_USEC:
s = "microseconds";
break;
case WTAP_TSPREC_NSEC:
s = "nanoseconds";
break;
case WTAP_TSPREC_UNKNOWN:
default:
s = "UNKNOWN";
break;
}
return s;
}
const char *
wtap_strerror(int err)
{
static char errbuf[128];
unsigned int wtap_errlist_index;
if (err < 0) {
wtap_errlist_index = -1 - err;
if (wtap_errlist_index >= WTAP_ERRLIST_SIZE) {
g_snprintf(errbuf, 128, "Error %d", err);
return errbuf;
}
if (wtap_errlist[wtap_errlist_index] == NULL)
return "Unknown reason";
return wtap_errlist[wtap_errlist_index];
} else
return g_strerror(err);
}
void
wtap_sequential_close(wtap *wth)
{
if (wth->subtype_sequential_close != NULL)
(*wth->subtype_sequential_close)(wth);
if (wth->fh != NULL) {
file_close(wth->fh);
wth->fh = NULL;
}
if (wth->frame_buffer) {
ws_buffer_free(wth->frame_buffer);
g_free(wth->frame_buffer);
wth->frame_buffer = NULL;
}
}
static void
g_fast_seek_item_free(gpointer data, gpointer user_data _U_)
{
g_free(data);
}
void
wtap_fdclose(wtap *wth)
{
if (wth->fh != NULL)
file_fdclose(wth->fh);
if (wth->random_fh != NULL)
file_fdclose(wth->random_fh);
}
void
wtap_close(wtap *wth)
{
wtap_sequential_close(wth);
if (wth->subtype_close != NULL)
(*wth->subtype_close)(wth);
if (wth->random_fh != NULL)
file_close(wth->random_fh);
if (wth->priv != NULL)
g_free(wth->priv);
if (wth->fast_seek != NULL) {
g_ptr_array_foreach(wth->fast_seek, g_fast_seek_item_free, NULL);
g_ptr_array_free(wth->fast_seek, TRUE);
}
wtap_block_array_free(wth->shb_hdrs);
wtap_block_array_free(wth->nrb_hdrs);
wtap_block_array_free(wth->interface_data);
g_free(wth);
}
void
wtap_cleareof(wtap *wth) {
file_clearerr(wth->fh);
}
void wtap_set_cb_new_ipv4(wtap *wth, wtap_new_ipv4_callback_t add_new_ipv4) {
if (wth)
wth->add_new_ipv4 = add_new_ipv4;
}
void wtap_set_cb_new_ipv6(wtap *wth, wtap_new_ipv6_callback_t add_new_ipv6) {
if (wth)
wth->add_new_ipv6 = add_new_ipv6;
}
gboolean
wtap_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
wth->phdr.pkt_encap = wth->file_encap;
wth->phdr.pkt_tsprec = wth->file_tsprec;
*err = 0;
*err_info = NULL;
if (!wth->subtype_read(wth, err, err_info, data_offset)) {
if (*err == 0)
*err = file_error(wth->fh, err_info);
return FALSE;
}
if (wth->phdr.caplen > wth->phdr.len)
wth->phdr.caplen = wth->phdr.len;
g_assert(wth->phdr.pkt_encap != WTAP_ENCAP_PER_PACKET);
return TRUE;
}
gboolean
wtap_read_bytes_or_eof(FILE_T fh, void *buf, unsigned int count, int *err,
gchar **err_info)
{
int bytes_read;
bytes_read = file_read(buf, count, fh);
if (bytes_read < 0 || (guint)bytes_read != count) {
*err = file_error(fh, err_info);
if (*err == 0 && bytes_read > 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
gboolean
wtap_read_bytes(FILE_T fh, void *buf, unsigned int count, int *err,
gchar **err_info)
{
int bytes_read;
bytes_read = file_read(buf, count, fh);
if (bytes_read < 0 || (guint)bytes_read != count) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
gboolean
wtap_read_packet_bytes(FILE_T fh, Buffer *buf, guint length, int *err,
gchar **err_info)
{
ws_buffer_assure_space(buf, length);
return wtap_read_bytes(fh, ws_buffer_start_ptr(buf), length, err,
err_info);
}
gint64
wtap_read_so_far(wtap *wth)
{
return file_tell_raw(wth->fh);
}
struct wtap_pkthdr *
wtap_phdr(wtap *wth)
{
return &wth->phdr;
}
guint8 *
wtap_buf_ptr(wtap *wth)
{
return ws_buffer_start_ptr(wth->frame_buffer);
}
void
wtap_phdr_init(struct wtap_pkthdr *phdr)
{
memset(phdr, 0, sizeof(struct wtap_pkthdr));
ws_buffer_init(&phdr->ft_specific_data, 0);
}
void
wtap_phdr_cleanup(struct wtap_pkthdr *phdr)
{
ws_buffer_free(&phdr->ft_specific_data);
}
gboolean
wtap_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
phdr->pkt_encap = wth->file_encap;
phdr->pkt_tsprec = wth->file_tsprec;
if (!wth->subtype_seek_read(wth, seek_off, phdr, buf, err, err_info))
return FALSE;
if (phdr->caplen > phdr->len)
phdr->caplen = phdr->len;
g_assert(phdr->pkt_encap != WTAP_ENCAP_PER_PACKET);
return TRUE;
}
