const gchar*
epan_get_version(void) {
return VERSION;
}
void
epan_register_plugin_types(void)
{
#ifdef HAVE_PLUGINS
register_dissector_plugin_type();
register_tap_plugin_type();
#endif
}
gboolean
epan_init(void (*register_all_protocols_func)(register_cb cb, gpointer client_data),
void (*register_all_handoffs_func)(register_cb cb, gpointer client_data),
register_cb cb,
gpointer client_data)
{
volatile gboolean status = TRUE;
wmem_init();
guids_init();
addr_resolv_init();
except_init();
#ifdef HAVE_LIBGCRYPT
gcry_check_version(NULL);
gcry_control (GCRYCTL_DISABLE_SECMEM, 0);
gcry_control (GCRYCTL_INITIALIZATION_FINISHED, 0);
#endif
#ifdef HAVE_LIBGNUTLS
gnutls_global_init();
#endif
TRY {
tap_init();
prefs_init();
expert_init();
packet_init();
capture_dissector_init();
proto_init(register_all_protocols_func, register_all_handoffs_func,
cb, client_data);
packet_cache_proto_handles();
dfilter_init();
final_registration_all_protocols();
print_cache_field_handles();
expert_packet_init();
#ifdef HAVE_LUA
wslua_init(cb, client_data);
#endif
}
CATCH(DissectorError) {
const char *exception_message = GET_MESSAGE;
static const char dissector_error_nomsg[] =
"Dissector writer didn't bother saying what the error was";
report_failure("Dissector bug: %s",
exception_message == NULL ?
dissector_error_nomsg : exception_message);
if (getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != NULL)
abort();
status = FALSE;
}
ENDTRY;
return status;
}
void
epan_cleanup(void)
{
dfilter_cleanup();
proto_cleanup();
prefs_cleanup();
packet_cleanup();
expert_cleanup();
capture_dissector_cleanup();
#ifdef HAVE_LUA
wslua_cleanup();
#endif
#ifdef HAVE_LIBGNUTLS
gnutls_global_deinit();
#endif
except_deinit();
addr_resolv_cleanup();
if (pinfo_pool_cache != NULL) {
wmem_destroy_allocator(pinfo_pool_cache);
pinfo_pool_cache = NULL;
}
wmem_cleanup();
}
epan_t *
epan_new(void)
{
epan_t *session = g_slice_new(epan_t);
init_dissection();
return session;
}
const char *
epan_get_user_comment(const epan_t *session, const frame_data *fd)
{
if (session->get_user_comment)
return session->get_user_comment(session->data, fd);
return NULL;
}
const char *
epan_get_interface_name(const epan_t *session, guint32 interface_id)
{
if (session->get_interface_name)
return session->get_interface_name(session->data, interface_id);
return NULL;
}
const nstime_t *
epan_get_frame_ts(const epan_t *session, guint32 frame_num)
{
const nstime_t *abs_ts = NULL;
if (session->get_frame_ts)
abs_ts = session->get_frame_ts(session->data, frame_num);
if (!abs_ts)
g_warning("!!! couldn't get frame ts for %u !!!\n", frame_num);
return abs_ts;
}
void
epan_free(epan_t *session)
{
if (session) {
cleanup_dissection();
g_slice_free(epan_t, session);
}
}
void
epan_conversation_init(void)
{
conversation_init();
}
void
epan_conversation_cleanup(void)
{
conversation_cleanup();
}
void
epan_circuit_init(void)
{
circuit_init();
}
void
epan_circuit_cleanup(void)
{
circuit_cleanup();
}
void
epan_set_always_visible(gboolean force)
{
if (force)
always_visible_refcount++;
else if (always_visible_refcount > 0)
always_visible_refcount--;
}
epan_dissect_t*
epan_dissect_init(epan_dissect_t *edt, epan_t *session, const gboolean create_proto_tree, const gboolean proto_tree_visible)
{
g_assert(edt);
edt->session = session;
memset(&edt->pi, 0, sizeof(edt->pi));
if (pinfo_pool_cache != NULL) {
edt->pi.pool = pinfo_pool_cache;
pinfo_pool_cache = NULL;
}
else {
edt->pi.pool = wmem_allocator_new(WMEM_ALLOCATOR_BLOCK_FAST);
}
if (create_proto_tree) {
edt->tree = proto_tree_create_root(&edt->pi);
proto_tree_set_visible(edt->tree, (always_visible_refcount > 0) ? TRUE : proto_tree_visible);
}
else {
edt->tree = NULL;
}
edt->tvb = NULL;
return edt;
}
void
epan_dissect_reset(epan_dissect_t *edt)
{
wmem_allocator_t *tmp;
g_assert(edt);
g_slist_free(edt->pi.proto_data);
g_slist_free(edt->pi.dependent_frames);
free_data_sources(&edt->pi);
if (edt->tvb) {
tvb_free_chain(edt->tvb);
edt->tvb = NULL;
}
if (edt->tree)
proto_tree_reset(edt->tree);
tmp = edt->pi.pool;
wmem_free_all(tmp);
memset(&edt->pi, 0, sizeof(edt->pi));
edt->pi.pool = tmp;
}
epan_dissect_t*
epan_dissect_new(epan_t *session, const gboolean create_proto_tree, const gboolean proto_tree_visible)
{
epan_dissect_t *edt;
edt = g_new0(epan_dissect_t, 1);
return epan_dissect_init(edt, session, create_proto_tree, proto_tree_visible);
}
void
epan_dissect_fake_protocols(epan_dissect_t *edt, const gboolean fake_protocols)
{
if (edt)
proto_tree_set_fake_protocols(edt->tree, fake_protocols);
}
void
epan_dissect_run(epan_dissect_t *edt, int file_type_subtype,
struct wtap_pkthdr *phdr, tvbuff_t *tvb, frame_data *fd,
column_info *cinfo)
{
#ifdef HAVE_LUA
wslua_prime_dfilter(edt);
#endif
wmem_enter_packet_scope();
dissect_record(edt, file_type_subtype, phdr, tvb, fd, cinfo);
wmem_leave_packet_scope();
}
void
epan_dissect_run_with_taps(epan_dissect_t *edt, int file_type_subtype,
struct wtap_pkthdr *phdr, tvbuff_t *tvb, frame_data *fd,
column_info *cinfo)
{
wmem_enter_packet_scope();
tap_queue_init(edt);
dissect_record(edt, file_type_subtype, phdr, tvb, fd, cinfo);
tap_push_tapped_queue(edt);
wmem_leave_packet_scope();
}
void
epan_dissect_file_run(epan_dissect_t *edt, struct wtap_pkthdr *phdr,
tvbuff_t *tvb, frame_data *fd, column_info *cinfo)
{
#ifdef HAVE_LUA
wslua_prime_dfilter(edt);
#endif
wmem_enter_packet_scope();
dissect_file(edt, phdr, tvb, fd, cinfo);
wmem_leave_packet_scope();
}
void
epan_dissect_file_run_with_taps(epan_dissect_t *edt, struct wtap_pkthdr *phdr,
tvbuff_t *tvb, frame_data *fd, column_info *cinfo)
{
wmem_enter_packet_scope();
tap_queue_init(edt);
dissect_file(edt, phdr, tvb, fd, cinfo);
tap_push_tapped_queue(edt);
wmem_leave_packet_scope();
}
void
epan_dissect_cleanup(epan_dissect_t* edt)
{
g_assert(edt);
g_slist_free(edt->pi.proto_data);
g_slist_free(edt->pi.dependent_frames);
free_data_sources(&edt->pi);
if (edt->tvb) {
tvb_free_chain(edt->tvb);
}
if (edt->tree) {
proto_tree_free(edt->tree);
}
if (pinfo_pool_cache == NULL) {
wmem_free_all(edt->pi.pool);
pinfo_pool_cache = edt->pi.pool;
}
else {
wmem_destroy_allocator(edt->pi.pool);
}
}
void
epan_dissect_free(epan_dissect_t* edt)
{
epan_dissect_cleanup(edt);
g_free(edt);
}
void
epan_dissect_prime_dfilter(epan_dissect_t *edt, const dfilter_t* dfcode)
{
dfilter_prime_proto_tree(dfcode, edt->tree);
}
void
epan_dissect_prime_hfid(epan_dissect_t *edt, int hfid)
{
proto_tree_prime_hfid(edt->tree, hfid);
}
const gchar *
epan_custom_set(epan_dissect_t *edt, GSList *field_ids,
gint occurrence,
gchar *result,
gchar *expr, const int size )
{
return proto_custom_set(edt->tree, field_ids, occurrence, result, expr, size);
}
void
epan_dissect_fill_in_columns(epan_dissect_t *edt, const gboolean fill_col_exprs, const gboolean fill_fd_colums)
{
col_custom_set_edt(edt, edt->pi.cinfo);
col_fill_in(&edt->pi, fill_col_exprs, fill_fd_colums);
}
gboolean
epan_dissect_packet_contains_field(epan_dissect_t* edt,
const char *field_name)
{
GPtrArray* array;
int field_id;
gboolean contains_field;
if (!edt || !edt->tree)
return FALSE;
field_id = proto_get_id_by_filter_name(field_name);
if (field_id < 0)
return FALSE;
array = proto_find_finfo(edt->tree, field_id);
contains_field = (array->len > 0) ? TRUE : FALSE;
g_ptr_array_free(array, TRUE);
return contains_field;
}
void
epan_get_compiled_version_info(GString *str)
{
g_string_append(str, ", ");
#ifdef HAVE_LIBSMI
g_string_append(str, "with SMI " SMI_VERSION_STRING);
#else
g_string_append(str, "without SMI");
#endif
g_string_append(str, ", ");
#ifdef HAVE_C_ARES
g_string_append(str, "with c-ares " ARES_VERSION_STR);
#else
g_string_append(str, "without c-ares");
#endif
g_string_append(str, ", ");
#ifdef HAVE_LUA
g_string_append(str, "with ");
g_string_append(str, LUA_VERSION);
#else
g_string_append(str, "without Lua");
#endif
g_string_append(str, ", ");
#ifdef HAVE_LIBGNUTLS
g_string_append(str, "with GnuTLS " LIBGNUTLS_VERSION);
#else
g_string_append(str, "without GnuTLS");
#endif
g_string_append(str, ", ");
#ifdef HAVE_LIBGCRYPT
g_string_append(str, "with Gcrypt " GCRYPT_VERSION);
#else
g_string_append(str, "without Gcrypt");
#endif
g_string_append(str, ", ");
#ifdef HAVE_KERBEROS
#ifdef HAVE_MIT_KERBEROS
g_string_append(str, "with MIT Kerberos");
#else
g_string_append(str, "with Heimdal Kerberos");
#endif
#else
g_string_append(str, "without Kerberos");
#endif
g_string_append(str, ", ");
#ifdef HAVE_GEOIP
g_string_append(str, "with GeoIP");
#else
g_string_append(str, "without GeoIP");
#endif
}
void
epan_get_runtime_version_info(GString *str
#if !defined(HAVE_LIBGNUTLS) && !defined(HAVE_LIBGCRYPT)
_U_
#endif
)
{
#ifdef HAVE_LIBGNUTLS
g_string_append_printf(str, ", with GnuTLS %s", gnutls_check_version(NULL));
#endif
#ifdef HAVE_LIBGCRYPT
g_string_append_printf(str, ", with Gcrypt %s", gcry_check_version(NULL));
#endif
}
