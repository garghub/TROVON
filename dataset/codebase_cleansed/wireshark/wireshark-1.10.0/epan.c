const gchar*
epan_get_version(void) {
return VERSION;
}
void
epan_init(void (*register_all_protocols_func)(register_cb cb, gpointer client_data),
void (*register_all_handoffs_func)(register_cb cb, gpointer client_data),
register_cb cb,
gpointer client_data,
void (*report_failure_fcn_p)(const char *, va_list),
void (*report_open_failure_fcn_p)(const char *, int, gboolean),
void (*report_read_failure_fcn_p)(const char *, int),
void (*report_write_failure_fcn_p)(const char *, int))
{
init_report_err(report_failure_fcn_p, report_open_failure_fcn_p,
report_read_failure_fcn_p, report_write_failure_fcn_p);
emem_init();
wmem_init();
guids_init();
except_init();
#ifdef HAVE_LIBGCRYPT
gcry_check_version(NULL);
gcry_control (GCRYCTL_DISABLE_SECMEM, 0);
gcry_control (GCRYCTL_INITIALIZATION_FINISHED, 0);
#endif
#ifdef HAVE_LIBGNUTLS
gnutls_global_init();
#endif
tap_init();
prefs_init();
proto_init(register_all_protocols_func, register_all_handoffs_func,
cb, client_data);
packet_init();
dfilter_init();
final_registration_all_protocols();
expert_init();
#ifdef HAVE_LUA
wslua_init(cb, client_data);
#endif
}
void
epan_cleanup(void)
{
cleanup_dissection();
dfilter_cleanup();
proto_cleanup();
prefs_cleanup();
packet_cleanup();
oid_resolv_cleanup();
#ifdef HAVE_LIBGNUTLS
gnutls_global_deinit();
#endif
except_deinit();
host_name_lookup_cleanup();
wmem_cleanup();
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
epan_dissect_t*
epan_dissect_init(epan_dissect_t *edt, const gboolean create_proto_tree, const gboolean proto_tree_visible)
{
g_assert(edt);
edt->pi.pool = wmem_allocator_new(WMEM_ALLOCATOR_SIMPLE);
if (create_proto_tree) {
edt->tree = proto_tree_create_root(&edt->pi);
proto_tree_set_visible(edt->tree, proto_tree_visible);
}
else {
edt->tree = NULL;
}
edt->pi.dependent_frames = NULL;
return edt;
}
epan_dissect_t*
epan_dissect_new(const gboolean create_proto_tree, const gboolean proto_tree_visible)
{
epan_dissect_t *edt;
edt = g_new0(epan_dissect_t, 1);
return epan_dissect_init(edt, create_proto_tree, proto_tree_visible);
}
void
epan_dissect_fake_protocols(epan_dissect_t *edt, const gboolean fake_protocols)
{
if (edt)
proto_tree_set_fake_protocols(edt->tree, fake_protocols);
}
void
epan_dissect_run(epan_dissect_t *edt, struct wtap_pkthdr *phdr,
const guint8* data, frame_data *fd, column_info *cinfo)
{
#ifdef HAVE_LUA
wslua_prime_dfilter(edt);
#endif
wmem_enter_packet_scope();
dissect_packet(edt, phdr, data, fd, cinfo);
ep_free_all();
wmem_leave_packet_scope();
}
void
epan_dissect_run_with_taps(epan_dissect_t *edt, struct wtap_pkthdr *phdr,
const guint8* data, frame_data *fd, column_info *cinfo)
{
wmem_enter_packet_scope();
tap_queue_init(edt);
dissect_packet(edt, phdr, data, fd, cinfo);
tap_push_tapped_queue(edt);
ep_free_all();
wmem_leave_packet_scope();
}
void
epan_dissect_cleanup(epan_dissect_t* edt)
{
g_assert(edt);
g_slist_free(edt->pi.dependent_frames);
free_data_sources(&edt->pi);
tvb_free_chain(edt->tvb);
if (edt->tree) {
proto_tree_free(edt->tree);
}
wmem_destroy_allocator(edt->pi.pool);
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
const gchar *
epan_custom_set(epan_dissect_t *edt, int field_id,
gint occurrence,
gchar *result,
gchar *expr, const int size )
{
return proto_custom_set(edt->tree, field_id, occurrence, result, expr, size);
}
void
epan_dissect_fill_in_columns(epan_dissect_t *edt, const gboolean fill_col_exprs, const gboolean fill_fd_colums)
{
col_custom_set_edt(edt, edt->pi.cinfo);
col_fill_in(&edt->pi, fill_col_exprs, fill_fd_colums);
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
g_string_append(str, ", ");
#ifdef HAVE_GNU_ADNS
g_string_append(str, "with ADNS");
#else
g_string_append(str, "without ADNS");
#endif
#endif
g_string_append(str, ", ");
#ifdef HAVE_LUA
g_string_append(str, "with ");
g_string_append(str, LUA_VERSION);
#else
g_string_append(str, "without Lua");
#endif
g_string_append(str, ", ");
#ifdef HAVE_PYTHON
g_string_append(str, "with Python");
#ifdef PY_VERSION
g_string_append(str, " " PY_VERSION);
#endif
#else
g_string_append(str, "without Python");
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
g_string_append_printf(str, ", GnuTLS %s", gnutls_check_version(NULL));
#endif
#ifdef HAVE_LIBGCRYPT
g_string_append_printf(str, ", Gcrypt %s", gcry_check_version(NULL));
#endif
}
