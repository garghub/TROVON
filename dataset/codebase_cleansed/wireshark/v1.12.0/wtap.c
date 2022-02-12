static gboolean
check_for_wtap_plugin(GModule *handle)
{
gpointer gp;
void (*register_wtap_module)(void);
wtap_plugin *plugin;
if (!g_module_symbol(handle, "register_wtap_module", &gp)) {
return FALSE;
}
register_wtap_module = (void (*)(void))gp;
plugin = (wtap_plugin *)g_malloc(sizeof (wtap_plugin));
plugin->register_wtap_module = register_wtap_module;
wtap_plugins = g_slist_append(wtap_plugins, plugin);
return TRUE;
}
void
wtap_register_plugin_types(void)
{
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
wtap_file_tsprecision(wtap *wth)
{
return wth->tsprecision;
}
wtapng_section_t *
wtap_file_get_shb_info(wtap *wth)
{
wtapng_section_t *shb_hdr;
if(wth == NULL)
return NULL;
shb_hdr = g_new(wtapng_section_t,1);
shb_hdr->section_length = wth->shb_hdr.section_length;
shb_hdr->opt_comment = wth->shb_hdr.opt_comment;
shb_hdr->shb_hardware = wth->shb_hdr.shb_hardware;
shb_hdr->shb_os = wth->shb_hdr.shb_os;
shb_hdr->shb_user_appl = wth->shb_hdr.shb_user_appl;
return shb_hdr;
}
void
wtap_write_shb_comment(wtap *wth, gchar *comment)
{
g_free(wth->shb_hdr.opt_comment);
wth->shb_hdr.opt_comment = comment;
}
wtapng_iface_descriptions_t *
wtap_file_get_idb_info(wtap *wth)
{
wtapng_iface_descriptions_t *idb_info;
idb_info = g_new(wtapng_iface_descriptions_t,1);
idb_info->interface_data = wth->interface_data;
return idb_info;
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
buffer_free(wth->frame_buffer);
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
guint i, j;
wtapng_if_descr_t *wtapng_if_descr;
wtapng_if_stats_t *if_stats;
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
for(i = 0; i < wth->interface_data->len; i++) {
wtapng_if_descr = &g_array_index(wth->interface_data, wtapng_if_descr_t, i);
if(wtapng_if_descr->opt_comment != NULL){
g_free(wtapng_if_descr->opt_comment);
}
if(wtapng_if_descr->if_name != NULL){
g_free(wtapng_if_descr->if_name);
}
if(wtapng_if_descr->if_description != NULL){
g_free(wtapng_if_descr->if_description);
}
if(wtapng_if_descr->if_filter_str != NULL){
g_free(wtapng_if_descr->if_filter_str);
}
if(wtapng_if_descr->if_filter_bpf_bytes != NULL){
g_free(wtapng_if_descr->if_filter_bpf_bytes);
}
if(wtapng_if_descr->if_os != NULL){
g_free(wtapng_if_descr->if_os);
}
for(j = 0; j < wtapng_if_descr->num_stat_entries; j++) {
if_stats = &g_array_index(wtapng_if_descr->interface_statistics, wtapng_if_stats_t, j);
if(if_stats->opt_comment != NULL){
g_free(if_stats->opt_comment);
}
}
if(wtapng_if_descr->num_stat_entries != 0){
g_array_free(wtapng_if_descr->interface_statistics, TRUE);
}
}
g_array_free(wth->interface_data, TRUE);
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
wtap_read_packet_bytes(FILE_T fh, Buffer *buf, guint length, int *err,
gchar **err_info)
{
int bytes_read;
buffer_assure_space(buf, length);
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(buffer_start_ptr(buf), length, fh);
if (bytes_read < 0 || (guint)bytes_read != length) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
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
return buffer_start_ptr(wth->frame_buffer);
}
gboolean
wtap_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (!wth->subtype_seek_read(wth, seek_off, phdr, buf, err, err_info))
return FALSE;
if (phdr->caplen > phdr->len)
phdr->caplen = phdr->len;
g_assert(phdr->pkt_encap != WTAP_ENCAP_PER_PACKET);
return TRUE;
}
