GtkWidget*
nameres_prefs_show(void)
{
guint table_row;
GtkWidget *main_tb, *main_vb;
GtkWidget *m_resolv_cb, *n_resolv_cb, *t_resolv_cb;
#if defined(HAVE_C_ARES) || defined(HAVE_GNU_ADNS)
GtkWidget *c_resolv_cb;
GtkWidget *resolv_concurrency_te;
char concur_str[10+1];
#endif
#ifdef HAVE_LIBSMI
GtkWidget *load_smi_modules_cb, *suppress_smi_errors_cb;
uat_t *smi_paths_uat;
uat_t *smi_modules_uat;
#endif
#ifdef HAVE_GEOIP
uat_t *geoip_db_paths_uat;
#endif
prefs.name_resolve = gbl_resolv_flags;
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 7, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
main_tb = gtk_table_new(RESOLV_TABLE_ROWS, 3, FALSE);
gtk_box_pack_start(GTK_BOX(main_vb), main_tb, FALSE, FALSE, 0);
gtk_table_set_row_spacings(GTK_TABLE(main_tb), 10);
gtk_table_set_col_spacings(GTK_TABLE(main_tb), 15);
gtk_widget_show(main_tb);
table_row = 0;
m_resolv_cb = create_preference_check_button(main_tb, table_row,
"Enable MAC name resolution:", "e.g. Ethernet address to manufacturer name",
prefs.name_resolve & RESOLV_MAC);
g_object_set_data(G_OBJECT(main_vb), M_RESOLVE_KEY, m_resolv_cb);
table_row++;
n_resolv_cb = create_preference_check_button(main_tb, table_row,
"Enable network name resolution:", "e.g. IP address to DNS name (hostname)",
prefs.name_resolve & RESOLV_NETWORK);
g_object_set_data(G_OBJECT(main_vb), N_RESOLVE_KEY, n_resolv_cb);
table_row++;
t_resolv_cb = create_preference_check_button(main_tb, table_row,
"Enable transport name resolution:", "e.g. TCP/UDP port to service name",
prefs.name_resolve & RESOLV_TRANSPORT);
g_object_set_data(G_OBJECT(main_vb), T_RESOLVE_KEY, t_resolv_cb);
#if defined(HAVE_C_ARES) || defined(HAVE_GNU_ADNS)
table_row++;
c_resolv_cb = create_preference_check_button(main_tb, table_row,
"Enable concurrent DNS name resolution:", "be sure to enable network name resolution",
prefs.name_resolve & RESOLV_CONCURRENT);
g_object_set_data(G_OBJECT(main_vb), C_RESOLVE_KEY, c_resolv_cb);
table_row++;
g_snprintf(concur_str, sizeof(concur_str), "%d", prefs.name_resolve_concurrency);
resolv_concurrency_te = create_preference_entry(main_tb, table_row,
"Maximum concurrent requests:", "maximum parallel running DNS requests", concur_str);
g_object_set_data(G_OBJECT(main_vb), RESOLVE_CONCURRENCY_KEY, resolv_concurrency_te);
#else
table_row++;
create_preference_static_text(main_tb, table_row,
"Enable concurrent DNS name resolution: N/A",
"Support for this feature was not compiled into this version of Wireshark");
#endif
#ifdef HAVE_LIBSMI
table_row++;
load_smi_modules_cb = create_preference_check_button(main_tb, table_row,
"Enable OID resolution:", "You must restart Wireshark for this change to"
" take effect. [If True the 'SMI paths' and 'SMI modules' preferences will be shown].",
prefs.load_smi_modules);
g_object_set_data(G_OBJECT(main_vb), LOAD_SMI_MODULES_KEY, load_smi_modules_cb);
table_row++;
suppress_smi_errors_cb = create_preference_check_button(main_tb, table_row,
"Suppress SMI errors:", "Some errors can be ignored. If unsure, set to false.",
prefs.suppress_smi_errors);
g_object_set_data(G_OBJECT(main_vb), SUPPRESS_SMI_ERRORS_KEY, suppress_smi_errors_cb);
smi_paths_uat = uat_get_table_by_name("SMI Paths");
if (smi_paths_uat) {
table_row++;
create_preference_uat(main_tb, table_row,
"SMI (MIB and PIB) paths",
"Search paths for SMI (MIB and PIB) modules. You must\n"
"restart Wireshark for these changes to take effect.",
smi_paths_uat);
}
smi_modules_uat = uat_get_table_by_name("SMI Modules");
if (smi_modules_uat) {
table_row++;
create_preference_uat(main_tb, table_row,
"SMI (MIB and PIB) modules",
"List of enabled SMI (MIB and PIB) modules. You must\n"
"restart Wireshark for these changes to take effect.",
smi_modules_uat);
}
#else
table_row++;
create_preference_static_text(main_tb, table_row,
"SMI (MIB and PIB) modules and paths: N/A",
"Support for this feature was not compiled into this version of Wireshark");
table_row++;
create_preference_static_text(main_tb, table_row,
"Enable OID resolution: N/A",
"Support for this feature was not compiled into this version of Wireshark");
table_row++;
create_preference_static_text(main_tb, table_row,
"Suppress SMI errors: N/A",
"Support for this feature was not compiled into this version of Wireshark");
#endif
#ifdef HAVE_GEOIP
geoip_db_paths_uat = uat_get_table_by_name("GeoIP Database Paths");
if (geoip_db_paths_uat) {
table_row++;
create_preference_uat(main_tb, table_row,
"GeoIP database directories",
"Search paths for GeoIP address mapping databases.\n"
"Wireshark will look in each directory for files beginning\n"
"with \"Geo\" and ending with \".dat\".\n"
"You must restart Wireshark for these changes to take\n"
"effect.",
geoip_db_paths_uat);
}
#else
table_row++;
create_preference_static_text(main_tb, table_row,
"GeoIP database search paths: N/A",
"Support for this feature was not compiled into this version of Wireshark");
#endif
gtk_widget_show_all(main_vb);
return(main_vb);
}
void
nameres_prefs_fetch(GtkWidget *w)
{
GtkWidget *m_resolv_cb, *n_resolv_cb, *t_resolv_cb;
#if defined(HAVE_C_ARES) || defined(HAVE_GNU_ADNS)
GtkWidget *c_resolv_cb, *resolv_concurrency_te;
#endif
#ifdef HAVE_LIBSMI
GtkWidget *load_smi_modules_cb, *suppress_smi_errors_cb;
gboolean load_smi_modules_orig;
#endif
m_resolv_cb = (GtkWidget *)g_object_get_data(G_OBJECT(w), M_RESOLVE_KEY);
n_resolv_cb = (GtkWidget *)g_object_get_data(G_OBJECT(w), N_RESOLVE_KEY);
t_resolv_cb = (GtkWidget *)g_object_get_data(G_OBJECT(w), T_RESOLVE_KEY);
#if defined(HAVE_C_ARES) || defined(HAVE_GNU_ADNS)
c_resolv_cb = (GtkWidget *)g_object_get_data(G_OBJECT(w), C_RESOLVE_KEY);
resolv_concurrency_te = (GtkWidget *)g_object_get_data(G_OBJECT(w), RESOLVE_CONCURRENCY_KEY);
#endif
prefs.name_resolve = RESOLV_NONE;
prefs.name_resolve |= (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (m_resolv_cb)) ? RESOLV_MAC : RESOLV_NONE);
prefs.name_resolve |= (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (n_resolv_cb)) ? RESOLV_NETWORK : RESOLV_NONE);
prefs.name_resolve |= (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (t_resolv_cb)) ? RESOLV_TRANSPORT : RESOLV_NONE);
#if defined(HAVE_C_ARES) || defined(HAVE_GNU_ADNS)
prefs.name_resolve |= (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (c_resolv_cb)) ? RESOLV_CONCURRENT : RESOLV_NONE);
prefs.name_resolve_concurrency = strtol (gtk_entry_get_text(
GTK_ENTRY(resolv_concurrency_te)), NULL, 10);
#endif
#ifdef HAVE_LIBSMI
load_smi_modules_orig = prefs.load_smi_modules;
load_smi_modules_cb = (GtkWidget *)g_object_get_data(G_OBJECT(w), LOAD_SMI_MODULES_KEY);
prefs.load_smi_modules = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (load_smi_modules_cb));
suppress_smi_errors_cb = (GtkWidget *)g_object_get_data(G_OBJECT(w), SUPPRESS_SMI_ERRORS_KEY);
prefs.suppress_smi_errors = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (suppress_smi_errors_cb));
if (load_smi_modules_orig && !prefs.load_smi_modules) {
prefs.load_smi_modules = TRUE;
oids_cleanup();
prefs.load_smi_modules = FALSE;
} else if (!load_smi_modules_orig && prefs.load_smi_modules) {
oids_init();
}
#endif
}
void
nameres_prefs_apply(GtkWidget *w _U_)
{
gbl_resolv_flags = prefs.name_resolve;
menu_name_resolution_changed();
}
void
nameres_prefs_destroy(GtkWidget *w _U_)
{
}
