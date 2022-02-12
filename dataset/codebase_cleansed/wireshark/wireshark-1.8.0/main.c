static void
match_selected_cb_do(gpointer data, int action, gchar *text)
{
GtkWidget *filter_te;
char *cur_filter, *new_filter;
if ((!text) || (0 == strlen(text))) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Could not acquire information to build a filter!\nTry expanding or choosing another item.");
return;
}
g_assert(data);
filter_te = g_object_get_data(G_OBJECT(data), E_DFILTER_TE_KEY);
g_assert(filter_te);
cur_filter = gtk_editable_get_chars(GTK_EDITABLE(filter_te), 0, -1);
switch (action&MATCH_SELECTED_MASK) {
case MATCH_SELECTED_REPLACE:
new_filter = g_strdup(text);
break;
case MATCH_SELECTED_AND:
if ((!cur_filter) || (0 == strlen(cur_filter)))
new_filter = g_strdup(text);
else
new_filter = g_strconcat("(", cur_filter, ") && (", text, ")", NULL);
break;
case MATCH_SELECTED_OR:
if ((!cur_filter) || (0 == strlen(cur_filter)))
new_filter = g_strdup(text);
else
new_filter = g_strconcat("(", cur_filter, ") || (", text, ")", NULL);
break;
case MATCH_SELECTED_NOT:
new_filter = g_strconcat("!(", text, ")", NULL);
break;
case MATCH_SELECTED_AND_NOT:
if ((!cur_filter) || (0 == strlen(cur_filter)))
new_filter = g_strconcat("!(", text, ")", NULL);
else
new_filter = g_strconcat("(", cur_filter, ") && !(", text, ")", NULL);
break;
case MATCH_SELECTED_OR_NOT:
if ((!cur_filter) || (0 == strlen(cur_filter)))
new_filter = g_strconcat("!(", text, ")", NULL);
else
new_filter = g_strconcat("(", cur_filter, ") || !(", text, ")", NULL);
break;
default:
g_assert_not_reached();
new_filter = NULL;
break;
}
g_free(cur_filter);
if (action&MATCH_SELECTED_COPY_ONLY) {
GString *gtk_text_str = g_string_new("");
g_string_append(gtk_text_str, new_filter);
copy_to_clipboard(gtk_text_str);
g_string_free(gtk_text_str, TRUE);
} else {
gtk_entry_set_text(GTK_ENTRY(filter_te), new_filter);
if (action&MATCH_SELECTED_APPLY_NOW)
main_filter_packets(&cfile, new_filter, FALSE);
}
g_free(new_filter);
}
void
match_selected_ptree_cb(GtkWidget *w, gpointer data, MATCH_SELECTED_E action)
{
char *filter = NULL;
if (cfile.finfo_selected) {
filter = proto_construct_match_selected_string(cfile.finfo_selected,
cfile.edt);
match_selected_cb_do((data ? data : w), action, filter);
}
}
void
colorize_selected_ptree_cb(GtkWidget *w _U_, gpointer data _U_, guint8 filt_nr)
{
char *filter = NULL;
if (cfile.finfo_selected) {
filter = proto_construct_match_selected_string(cfile.finfo_selected,
cfile.edt);
if ((!filter) || (0 == strlen(filter))) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not acquire information to build a filter!\n"
"Try expanding or choosing another item.");
return;
}
if (filt_nr==0) {
color_display_with_filter(filter);
} else {
if (filt_nr==255) {
color_filters_reset_tmp();
} else {
color_filters_set_tmp(filt_nr,filter, FALSE);
}
new_packet_list_colorize_packets();
}
}
}
static void selected_ptree_info_answered_cb(gpointer dialog _U_, gint btn, gpointer data)
{
gchar *selected_proto_url;
gchar *proto_abbrev = data;
switch(btn) {
case(ESD_BTN_OK):
if (cfile.finfo_selected) {
selected_proto_url = g_strdup_printf("http://wiki.wireshark.org/Protocols/%s", proto_abbrev);
browser_open_url(selected_proto_url);
g_free(selected_proto_url);
}
break;
case(ESD_BTN_CANCEL):
break;
default:
g_assert_not_reached();
}
}
void
selected_ptree_info_cb(GtkWidget *widget _U_, gpointer data _U_)
{
int field_id;
const gchar *proto_abbrev;
gpointer dialog;
if (cfile.finfo_selected) {
field_id = cfile.finfo_selected->hfinfo->id;
if(!proto_registrar_is_protocol(field_id)) {
field_id = proto_registrar_get_parent(cfile.finfo_selected->hfinfo->id);
}
proto_abbrev = proto_registrar_get_abbrev(field_id);
if (!proto_is_private(field_id)) {
dialog = simple_dialog(ESD_TYPE_CONFIRMATION, ESD_BTNS_OK_CANCEL,
"%sOpen Wireshark Wiki page of protocol \"%s\"?%s\n"
"\n"
"This will open the \"%s\" related Wireshark Wiki page in your Web browser.\n"
"\n"
"The Wireshark Wiki is a collaborative approach to provide information "
"about Wireshark in several ways (not limited to protocol specifics).\n"
"\n"
"This Wiki is new, so the page of the selected protocol "
"may not exist and/or may not contain valuable information.\n"
"\n"
"As everyone can edit the Wiki and add new content (or extend existing), "
"you are encouraged to add information if you can.\n"
"\n"
"Hint 1: If you are new to wiki editing, try out editing the Sandbox first!\n"
"\n"
"Hint 2: If you want to add a new protocol page, you should use the ProtocolTemplate, "
"which will save you a lot of editing and will give a consistent look over the pages.",
simple_dialog_primary_start(), proto_abbrev, simple_dialog_primary_end(), proto_abbrev);
simple_dialog_set_cb(dialog, selected_ptree_info_answered_cb, (gpointer)proto_abbrev);
} else {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"%sCan't open Wireshark Wiki page of protocol \"%s\"%s\n"
"\n"
"This would open the \"%s\" related Wireshark Wiki page in your Web browser.\n"
"\n"
"Since this is a private protocol, such information is not available in "
"a public wiki. Therefore this wiki entry is blocked.\n"
"\n"
"Sorry for the inconvenience.\n",
simple_dialog_primary_start(), proto_abbrev, simple_dialog_primary_end(), proto_abbrev);
}
}
}
static void selected_ptree_ref_answered_cb(gpointer dialog _U_, gint btn, gpointer data)
{
gchar *selected_proto_url;
gchar *proto_abbrev = data;
switch(btn) {
case(ESD_BTN_OK):
if (cfile.finfo_selected) {
selected_proto_url = g_strdup_printf("http://www.wireshark.org/docs/dfref/%c/%s", proto_abbrev[0], proto_abbrev);
browser_open_url(selected_proto_url);
g_free(selected_proto_url);
}
break;
case(ESD_BTN_CANCEL):
break;
default:
g_assert_not_reached();
}
}
void
selected_ptree_ref_cb(GtkWidget *widget _U_, gpointer data _U_)
{
int field_id;
const gchar *proto_abbrev;
gpointer dialog;
if (cfile.finfo_selected) {
field_id = cfile.finfo_selected->hfinfo->id;
if(!proto_registrar_is_protocol(field_id)) {
field_id = proto_registrar_get_parent(cfile.finfo_selected->hfinfo->id);
}
proto_abbrev = proto_registrar_get_abbrev(field_id);
if (!proto_is_private(field_id)) {
dialog = simple_dialog(ESD_TYPE_CONFIRMATION, ESD_BTNS_OK_CANCEL,
"%sOpen Wireshark filter reference page of protocol \"%s\"?%s\n"
"\n"
"This will open the \"%s\" related Wireshark filter reference page in your Web browser.\n"
"\n",
simple_dialog_primary_start(), proto_abbrev, simple_dialog_primary_end(), proto_abbrev);
simple_dialog_set_cb(dialog, selected_ptree_ref_answered_cb, (gpointer)proto_abbrev);
} else {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"%sCan't open Wireshark filter reference page of protocol \"%s\"%s\n"
"\n"
"This would open the \"%s\" related Wireshark filter reference page in your Web browser.\n"
"\n"
"Since this is a private protocol, such information is not available on "
"a public website. Therefore this filter entry is blocked.\n"
"\n"
"Sorry for the inconvenience.\n",
simple_dialog_primary_start(), proto_abbrev, simple_dialog_primary_end(), proto_abbrev);
}
}
}
static gboolean
is_address_column (gint column)
{
if (((cfile.cinfo.col_fmt[column] == COL_DEF_SRC) ||
(cfile.cinfo.col_fmt[column] == COL_RES_SRC) ||
(cfile.cinfo.col_fmt[column] == COL_DEF_DST) ||
(cfile.cinfo.col_fmt[column] == COL_RES_DST)) &&
strlen(cfile.cinfo.col_expr.col_expr_val[column]))
{
return TRUE;
}
return FALSE;
}
GList *
get_ip_address_list_from_packet_list_row(gpointer data)
{
gint row = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(data), E_MPACKET_LIST_ROW_KEY));
gint column = new_packet_list_get_column_id (GPOINTER_TO_INT(g_object_get_data(G_OBJECT(data), E_MPACKET_LIST_COL_KEY)));
gint col;
frame_data *fdata;
GList *addr_list = NULL;
fdata = (frame_data *) new_packet_list_get_row_data(row);
if (fdata != NULL) {
epan_dissect_t edt;
if (!cf_read_frame (&cfile, fdata))
return NULL;
epan_dissect_init(&edt, FALSE, FALSE);
col_custom_prime_edt(&edt, &cfile.cinfo);
epan_dissect_run(&edt, &cfile.pseudo_header, cfile.pd, fdata, &cfile.cinfo);
epan_dissect_fill_in_columns(&edt, TRUE, TRUE);
if (is_address_column (column)) {
addr_list = g_list_append (addr_list, se_strdup_printf("%s", cfile.cinfo.col_expr.col_expr_val[column]));
}
for (col = 0; col < cfile.cinfo.num_cols; col++) {
if ((col != column) && (is_address_column (col))) {
addr_list = g_list_append (addr_list, se_strdup_printf("%s", cfile.cinfo.col_expr.col_expr_val[col]));
}
}
epan_dissect_cleanup(&edt);
}
return addr_list;
}
static gchar *
get_filter_from_packet_list_row_and_column(gpointer data)
{
gint row = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(data), E_MPACKET_LIST_ROW_KEY));
gint column = new_packet_list_get_column_id (GPOINTER_TO_INT(g_object_get_data(G_OBJECT(data), E_MPACKET_LIST_COL_KEY)));
frame_data *fdata;
gchar *buf=NULL;
fdata = (frame_data *) new_packet_list_get_row_data(row);
if (fdata != NULL) {
epan_dissect_t edt;
if (!cf_read_frame(&cfile, fdata))
return NULL;
epan_dissect_init(&edt, have_custom_cols(&cfile.cinfo), FALSE);
col_custom_prime_edt(&edt, &cfile.cinfo);
epan_dissect_run(&edt, &cfile.pseudo_header, cfile.pd, fdata,
&cfile.cinfo);
epan_dissect_fill_in_columns(&edt, TRUE, TRUE);
if ((cfile.cinfo.col_custom_occurrence[column]) ||
(strchr (cfile.cinfo.col_expr.col_expr_val[column], ',') == NULL))
{
if (strlen(cfile.cinfo.col_expr.col_expr[column]) != 0 &&
strlen(cfile.cinfo.col_expr.col_expr_val[column]) != 0) {
if (cfile.cinfo.col_fmt[column] == COL_CUSTOM) {
header_field_info *hfi = proto_registrar_get_byname(cfile.cinfo.col_custom_field[column]);
if (hfi->parent == -1) {
buf = se_strdup(cfile.cinfo.col_expr.col_expr[column]);
} else if (hfi->type == FT_STRING) {
buf = se_strdup_printf("%s == \"%s\"", cfile.cinfo.col_expr.col_expr[column],
cfile.cinfo.col_expr.col_expr_val[column]);
}
}
if (buf == NULL) {
buf = se_strdup_printf("%s == %s", cfile.cinfo.col_expr.col_expr[column],
cfile.cinfo.col_expr.col_expr_val[column]);
}
}
}
epan_dissect_cleanup(&edt);
}
return buf;
}
void
match_selected_plist_cb(GtkWidget *w _U_, gpointer data, MATCH_SELECTED_E action)
{
match_selected_cb_do(data,
action,
get_filter_from_packet_list_row_and_column(data));
}
void
copy_selected_plist_cb(GtkWidget *w _U_, gpointer data _U_, COPY_SELECTED_E action)
{
GString *gtk_text_str = g_string_new("");
char labelstring[256];
char *stringpointer = labelstring;
switch(action)
{
case COPY_SELECTED_DESCRIPTION:
if (cfile.finfo_selected->rep &&
strlen (cfile.finfo_selected->rep->representation) > 0) {
g_string_append(gtk_text_str, cfile.finfo_selected->rep->representation);
}
break;
case COPY_SELECTED_FIELDNAME:
if (cfile.finfo_selected->hfinfo->abbrev != 0) {
g_string_append(gtk_text_str, cfile.finfo_selected->hfinfo->abbrev);
}
break;
case COPY_SELECTED_VALUE:
if (cfile.edt !=0 ) {
g_string_append(gtk_text_str,
get_node_field_value(cfile.finfo_selected, cfile.edt));
}
break;
default:
break;
}
if (gtk_text_str->len == 0) {
proto_item_fill_label(cfile.finfo_selected, stringpointer);
g_string_append(gtk_text_str, stringpointer);
}
if (gtk_text_str->len == 0) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Could not acquire information to copy, try expanding or choosing another item");
} else {
copy_to_clipboard(gtk_text_str);
}
g_string_free(gtk_text_str, TRUE);
}
void
set_frame_reftime(gboolean set, frame_data *frame, gint row) {
if (row == -1)
return;
if (set) {
frame->flags.ref_time=1;
cfile.ref_time_count++;
} else {
frame->flags.ref_time=0;
cfile.ref_time_count--;
}
cf_reftime_packets(&cfile);
if (!frame->flags.ref_time && !frame->flags.passed_dfilter) {
new_packet_list_freeze();
cfile.displayed_count--;
new_packet_list_recreate_visible_rows();
new_packet_list_thaw();
}
new_packet_list_queue_draw();
}
static void reftime_answered_cb(gpointer dialog _U_, gint btn, gpointer data _U_)
{
switch(btn) {
case(ESD_BTN_YES):
timestamp_set_type(TS_RELATIVE);
recent.gui_time_format = TS_RELATIVE;
cf_timestamp_auto_precision(&cfile);
new_packet_list_queue_draw();
break;
case(ESD_BTN_NO):
break;
default:
g_assert_not_reached();
}
if (cfile.current_frame) {
set_frame_reftime(!cfile.current_frame->flags.ref_time,
cfile.current_frame, cfile.current_row);
}
}
void
reftime_frame_cb(GtkWidget *w _U_, gpointer data _U_, REFTIME_ACTION_E action)
{
static GtkWidget *reftime_dialog = NULL;
switch(action){
case REFTIME_TOGGLE:
if (cfile.current_frame) {
if(recent.gui_time_format != TS_RELATIVE && cfile.current_frame->flags.ref_time==0) {
reftime_dialog = simple_dialog(ESD_TYPE_CONFIRMATION, ESD_BTNS_YES_NO,
"%sSwitch to the appropriate Time Display Format?%s\n\n"
"Time References don't work well with the currently selected Time Display Format.\n\n"
"Do you want to switch to \"Seconds Since Beginning of Capture\" now?",
simple_dialog_primary_start(), simple_dialog_primary_end());
simple_dialog_set_cb(reftime_dialog, reftime_answered_cb, NULL);
} else {
set_frame_reftime(!cfile.current_frame->flags.ref_time,
cfile.current_frame, cfile.current_row);
}
}
break;
case REFTIME_FIND_NEXT:
cf_find_packet_time_reference(&cfile, SD_FORWARD);
break;
case REFTIME_FIND_PREV:
cf_find_packet_time_reference(&cfile, SD_BACKWARD);
break;
}
}
void
find_next_mark_cb(GtkWidget *w _U_, gpointer data _U_, int action _U_)
{
cf_find_packet_marked(&cfile, SD_FORWARD);
}
void
find_prev_mark_cb(GtkWidget *w _U_, gpointer data _U_, int action _U_)
{
cf_find_packet_marked(&cfile, SD_BACKWARD);
}
static void
tree_view_selection_changed_cb(GtkTreeSelection *sel, gpointer user_data _U_)
{
field_info *finfo;
gchar len_str[2+10+1+5+1];
gboolean has_blurb = FALSE;
guint length = 0, byte_len;
GtkWidget *byte_view;
const guint8 *byte_data;
gint finfo_length;
GtkTreeModel *model;
GtkTreeIter iter;
if (!gtk_tree_selection_get_selected(sel, &model, &iter))
{
byte_view = get_notebook_bv_ptr(byte_nb_ptr_gbl);
if (byte_view == NULL)
return;
byte_data = get_byte_view_data_and_length(byte_view, &byte_len);
if (byte_data == NULL)
return;
cf_unselect_field(&cfile);
packet_hex_print(byte_view, byte_data,
cfile.current_frame, NULL, byte_len);
proto_help_menu_modify(sel, &cfile);
return;
}
gtk_tree_model_get(model, &iter, 1, &finfo, -1);
if (!finfo) return;
set_notebook_page(byte_nb_ptr_gbl, finfo->ds_tvb);
byte_view = get_notebook_bv_ptr(byte_nb_ptr_gbl);
byte_data = get_byte_view_data_and_length(byte_view, &byte_len);
g_assert(byte_data != NULL);
cfile.finfo_selected = finfo;
set_menus_for_selected_tree_row(&cfile);
if (finfo->hfinfo) {
if (finfo->hfinfo->blurb != NULL &&
finfo->hfinfo->blurb[0] != '\0') {
has_blurb = TRUE;
length = (guint) strlen(finfo->hfinfo->blurb);
} else {
length = (guint) strlen(finfo->hfinfo->name);
}
finfo_length = finfo->length + finfo->appendix_length;
if (finfo_length == 0) {
len_str[0] = '\0';
} else if (finfo_length == 1) {
g_strlcpy (len_str, ", 1 byte", sizeof len_str);
} else {
g_snprintf (len_str, sizeof len_str, ", %d bytes", finfo_length);
}
statusbar_pop_field_msg();
if (length) {
statusbar_push_field_msg(" %s (%s)%s",
(has_blurb) ? finfo->hfinfo->blurb : finfo->hfinfo->name,
finfo->hfinfo->abbrev, len_str);
} else {
statusbar_push_field_msg("%s", "");
}
}
packet_hex_print(byte_view, byte_data, cfile.current_frame, finfo,
byte_len);
proto_help_menu_modify(sel, &cfile);
}
void collapse_all_cb(GtkWidget *widget _U_, gpointer data _U_) {
if (cfile.edt->tree)
collapse_all_tree(cfile.edt->tree, tree_view_gbl);
}
void expand_all_cb(GtkWidget *widget _U_, gpointer data _U_) {
if (cfile.edt->tree)
expand_all_tree(cfile.edt->tree, tree_view_gbl);
}
void apply_as_custom_column_cb (GtkWidget *widget _U_, gpointer data _U_)
{
if (cfile.finfo_selected) {
column_prefs_add_custom(COL_CUSTOM, cfile.finfo_selected->hfinfo->name,
cfile.finfo_selected->hfinfo->abbrev,0);
new_packet_list_recreate ();
if (!prefs.gui_use_pref_save) {
prefs_main_write();
}
cfile.cinfo.columns_changed = FALSE;
}
}
void expand_tree_cb(GtkWidget *widget _U_, gpointer data _U_) {
GtkTreePath *path;
path = tree_find_by_field_info(GTK_TREE_VIEW(tree_view_gbl), cfile.finfo_selected);
if(path) {
gtk_tree_view_expand_row(GTK_TREE_VIEW(tree_view_gbl), path, TRUE);
gtk_tree_path_free(path);
}
}
void resolve_name_cb(GtkWidget *widget _U_, gpointer data _U_) {
if (cfile.edt->tree) {
guint32 tmp = gbl_resolv_flags;
gbl_resolv_flags = RESOLV_ALL;
proto_tree_draw(cfile.edt->tree, tree_view_gbl);
gbl_resolv_flags = tmp;
}
}
static void
main_set_for_capture_file(gboolean have_capture_file_in)
{
have_capture_file = have_capture_file_in;
main_widgets_show_or_hide();
}
gboolean
main_do_quit(void)
{
main_save_window_geometry(top_level);
write_profile_recent();
write_recent();
#ifdef HAVE_LIBPCAP
capture_kill_child(&global_capture_opts);
#endif
if (cfile.state == FILE_READ_IN_PROGRESS) {
cfile.state = FILE_READ_ABORTED;
return TRUE;
} else {
cf_close(&cfile);
gtk_main_quit();
return FALSE;
}
}
static gboolean
main_window_delete_event_cb(GtkWidget *widget _U_, GdkEvent *event _U_, gpointer data _U_)
{
if (capture_stopping)
return TRUE;
if (do_file_close(&cfile, TRUE, " before quitting"))
return main_do_quit();
else
return TRUE;
}
static void
main_pane_load_window_geometry(void)
{
if (recent.has_gui_geometry_main_upper_pane && recent.gui_geometry_main_upper_pane)
gtk_paned_set_position(GTK_PANED(main_first_pane), recent.gui_geometry_main_upper_pane);
if (recent.has_gui_geometry_main_lower_pane && recent.gui_geometry_main_lower_pane) {
gtk_paned_set_position(GTK_PANED(main_second_pane), recent.gui_geometry_main_lower_pane);
}
}
static void
main_load_window_geometry(GtkWidget *widget)
{
window_geometry_t geom;
geom.set_pos = prefs.gui_geometry_save_position;
geom.x = recent.gui_geometry_main_x;
geom.y = recent.gui_geometry_main_y;
geom.set_size = prefs.gui_geometry_save_size;
if (recent.gui_geometry_main_width > 0 &&
recent.gui_geometry_main_height > 0) {
geom.width = recent.gui_geometry_main_width;
geom.height = recent.gui_geometry_main_height;
geom.set_maximized = prefs.gui_geometry_save_maximized;
} else {
geom.set_size = FALSE;
}
geom.maximized = recent.gui_geometry_main_maximized;
window_set_geometry(widget, &geom);
main_pane_load_window_geometry();
statusbar_load_window_geometry();
}
static void
main_save_window_geometry(GtkWidget *widget)
{
window_geometry_t geom;
window_get_geometry(widget, &geom);
if (prefs.gui_geometry_save_position) {
recent.gui_geometry_main_x = geom.x;
recent.gui_geometry_main_y = geom.y;
}
if (prefs.gui_geometry_save_size) {
recent.gui_geometry_main_width = geom.width;
recent.gui_geometry_main_height = geom.height;
}
if(prefs.gui_geometry_save_maximized) {
recent.gui_geometry_main_maximized = geom.maximized;
}
recent.gui_geometry_main_upper_pane = gtk_paned_get_position(GTK_PANED(main_first_pane));
recent.gui_geometry_main_lower_pane = gtk_paned_get_position(GTK_PANED(main_second_pane));
statusbar_save_window_geometry();
}
void
file_quit_cmd_cb(GtkWidget *widget _U_, gpointer data _U_)
{
if (do_file_close(&cfile, TRUE, " before quitting"))
main_do_quit();
}
static void
print_usage(gboolean print_ver) {
FILE *output;
#ifdef _WIN32
create_console();
#endif
if (print_ver) {
output = stdout;
fprintf(output, "Wireshark " VERSION "%s\n"
"Interactively dump and analyze network traffic.\n"
"See http://www.wireshark.org for more information.\n"
"\n"
"%s",
wireshark_svnversion, get_copyright_info());
} else {
output = stderr;
}
fprintf(output, "\n");
fprintf(output, "Usage: wireshark [options] ... [ <infile> ]\n");
fprintf(output, "\n");
#ifdef HAVE_LIBPCAP
fprintf(output, "Capture interface:\n");
fprintf(output, " -i <interface> name or idx of interface (def: first non-loopback)\n");
fprintf(output, " -f <capture filter> packet filter in libpcap filter syntax\n");
fprintf(output, " -s <snaplen> packet snapshot length (def: 65535)\n");
fprintf(output, " -p don't capture in promiscuous mode\n");
fprintf(output, " -k start capturing immediately (def: do nothing)\n");
fprintf(output, " -S update packet display when new packets are captured\n");
fprintf(output, " -l turn on automatic scrolling while -S is in use\n");
#ifdef HAVE_PCAP_CREATE
fprintf(output, " -I capture in monitor mode, if available\n");
#endif
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
fprintf(output, " -B <buffer size> size of kernel buffer (def: 1MB)\n");
#endif
fprintf(output, " -y <link type> link layer type (def: first appropriate)\n");
fprintf(output, " -D print list of interfaces and exit\n");
fprintf(output, " -L print list of link-layer types of iface and exit\n");
fprintf(output, "\n");
fprintf(output, "Capture stop conditions:\n");
fprintf(output, " -c <packet count> stop after n packets (def: infinite)\n");
fprintf(output, " -a <autostop cond.> ... duration:NUM - stop after NUM seconds\n");
fprintf(output, " filesize:NUM - stop this file after NUM KB\n");
fprintf(output, " files:NUM - stop after NUM files\n");
fprintf(output, "Capture output:\n");
fprintf(output, " -b <ringbuffer opt.> ... duration:NUM - switch to next file after NUM secs\n");
fprintf(output, " filesize:NUM - switch to next file after NUM KB\n");
fprintf(output, " files:NUM - ringbuffer: replace after NUM files\n");
#endif
fprintf(output, "Input file:\n");
fprintf(output, " -r <infile> set the filename to read from (no pipes or stdin!)\n");
fprintf(output, "\n");
fprintf(output, "Processing:\n");
fprintf(output, " -R <read filter> packet filter in Wireshark display filter syntax\n");
fprintf(output, " -n disable all name resolutions (def: all enabled)\n");
fprintf(output, " -N <name resolve flags> enable specific name resolution(s): \"mntC\"\n");
fprintf(output, "\n");
fprintf(output, "User interface:\n");
fprintf(output, " -C <config profile> start with specified configuration profile\n");
fprintf(output, " -d <display filter> start with the given display filter\n");
fprintf(output, " -g <packet number> go to specified packet number after \"-r\"\n");
fprintf(output, " -J <jump filter> jump to the first packet matching the (display)\n");
fprintf(output, " filter\n");
fprintf(output, " -j search backwards for a matching packet after \"-J\"\n");
fprintf(output, " -m <font> set the font name used for most text\n");
fprintf(output, " -t ad|a|r|d|dd|e output format of time stamps (def: r: rel. to first)\n");
fprintf(output, " -u s|hms output format of seconds (def: s: seconds)\n");
fprintf(output, " -X <key>:<value> eXtension options, see man page for details\n");
fprintf(output, " -z <statistics> show various statistics, see man page for details\n");
fprintf(output, "\n");
fprintf(output, "Output:\n");
fprintf(output, " -w <outfile|-> set the output filename (or '-' for stdout)\n");
fprintf(output, "\n");
fprintf(output, "Miscellaneous:\n");
fprintf(output, " -h display this help and exit\n");
fprintf(output, " -v display version info and exit\n");
fprintf(output, " -P <key>:<path> persconf:path - personal configuration files\n");
fprintf(output, " persdata:path - personal data files\n");
fprintf(output, " -o <name>:<value> ... override preference or recent setting\n");
fprintf(output, " -K <keytab> keytab file to use for kerberos decryption\n");
#ifndef _WIN32
fprintf(output, " --display=DISPLAY X display to use\n");
#endif
#ifdef _WIN32
destroy_console();
#endif
}
static void
show_version(void)
{
#ifdef _WIN32
create_console();
#endif
printf(PACKAGE " " VERSION "%s\n"
"\n"
"%s"
"\n"
"%s"
"\n"
"%s",
wireshark_svnversion, get_copyright_info(), comp_info_str->str,
runtime_info_str->str);
#ifdef _WIN32
destroy_console();
#endif
}
void
vfprintf_stderr(const char *fmt, va_list ap)
{
#ifdef _WIN32
create_console();
#endif
vfprintf(stderr, fmt, ap);
}
void
fprintf_stderr(const char *fmt, ...)
{
va_list ap;
va_start(ap, fmt);
vfprintf_stderr(fmt, ap);
va_end(ap);
}
void
cmdarg_err(const char *fmt, ...)
{
va_list ap;
fprintf_stderr("wireshark: ");
va_start(ap, fmt);
vfprintf_stderr(fmt, ap);
va_end(ap);
fprintf_stderr("\n");
}
void
cmdarg_err_cont(const char *fmt, ...)
{
va_list ap;
va_start(ap, fmt);
vfprintf_stderr(fmt, ap);
fprintf_stderr("\n");
va_end(ap);
}
static gboolean
tap_update_cb(gpointer data _U_)
{
draw_tap_listeners(FALSE);
return TRUE;
}
void reset_tap_update_timer(void)
{
g_source_remove(tap_update_timer_id);
tap_update_timer_id = g_timeout_add(prefs.tap_update_interval, tap_update_cb, NULL);
}
void
protect_thread_critical_region(void)
{
}
void
unprotect_thread_critical_region(void)
{
}
static gboolean
resolv_update_cb(gpointer data _U_)
{
if (host_name_lookup_process(NULL)) {
if (gtk_widget_get_window(pkt_scrollw))
gdk_window_invalidate_rect(gtk_widget_get_window(pkt_scrollw), NULL, TRUE);
if (gtk_widget_get_window(tv_scrollw))
gdk_window_invalidate_rect(gtk_widget_get_window(tv_scrollw), NULL, TRUE);
}
return TRUE;
}
static void
set_display_filename(capture_file *cf)
{
gchar *display_name;
gchar *window_name;
if (cf->filename) {
display_name = cf_get_display_name(cf);
window_name = g_strdup_printf("%s%s", cf->unsaved_changes ? "*" : "",
display_name);
g_free(display_name);
main_set_window_name(window_name);
g_free(window_name);
} else {
main_set_window_name("The Wireshark Network Analyzer");
}
}
void
main_update_for_unsaved_changes(capture_file *cf)
{
set_display_filename(cf);
set_menus_for_capture_file(cf);
set_toolbar_for_capture_file(cf);
}
void
main_auto_scroll_live_changed(gboolean auto_scroll_live_in)
{
menu_auto_scroll_live_changed(auto_scroll_live_in);
toolbar_auto_scroll_live_changed(auto_scroll_live_in);
auto_scroll_live = auto_scroll_live_in;
}
void
main_colorize_changed(gboolean packet_list_colorize)
{
menu_colorize_changed(packet_list_colorize);
toolbar_colorize_changed(packet_list_colorize);
if(packet_list_colorize != recent.packet_list_colorize) {
recent.packet_list_colorize = packet_list_colorize;
color_filters_enable(packet_list_colorize);
new_packet_list_colorize_packets();
}
}
static void
priv_warning_dialog_cb(gpointer dialog, gint btn _U_, gpointer data _U_)
{
recent.privs_warn_if_elevated = !simple_dialog_check_get(dialog);
}
static void
npf_warning_dialog_cb(gpointer dialog, gint btn _U_, gpointer data _U_)
{
recent.privs_warn_if_no_npf = !simple_dialog_check_get(dialog);
}
static void
main_cf_cb_file_closing(capture_file *cf)
{
if(cf->count > 10000) {
close_dlg = simple_dialog(ESD_TYPE_STOP, ESD_BTN_NONE,
"%sClosing file!%s\n\nPlease wait ...",
simple_dialog_primary_start(),
simple_dialog_primary_end());
gtk_window_set_position(GTK_WINDOW(close_dlg), GTK_WIN_POS_CENTER_ON_PARENT);
}
destroy_packet_wins();
main_set_window_name("The Wireshark Network Analyzer");
set_menus_for_capture_file(NULL);
set_toolbar_for_capture_file(NULL);
set_menus_for_captured_packets(FALSE);
set_menus_for_selected_packet(cf);
set_menus_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
set_menus_for_selected_tree_row(cf);
main_set_for_capture_file(FALSE);
main_window_update();
}
static void
main_cf_cb_file_closed(capture_file *cf _U_)
{
if(close_dlg != NULL) {
splash_destroy(close_dlg);
close_dlg = NULL;
}
}
static void
main_cf_cb_file_read_started(capture_file *cf _U_)
{
tap_param_dlg_update();
main_set_for_capture_file(TRUE);
}
static void
main_cf_cb_file_read_finished(capture_file *cf)
{
gchar *dir_path;
if (!cf->is_tempfile && cf->filename) {
add_menu_recent_capture_file(cf->filename);
dir_path = get_dirname(g_strdup(cf->filename));
set_last_open_dir(dir_path);
g_free(dir_path);
}
main_update_for_unsaved_changes(cf);
set_menus_for_captured_packets(TRUE);
}
static void
main_cf_cb_file_rescan_finished(capture_file *cf)
{
gchar *dir_path;
if (!cf->is_tempfile && cf->filename) {
add_menu_recent_capture_file(cf->filename);
dir_path = get_dirname(g_strdup(cf->filename));
set_last_open_dir(dir_path);
g_free(dir_path);
}
main_update_for_unsaved_changes(cf);
}
static GList *icon_list_create(
const char **icon16_xpm,
const char **icon32_xpm,
const char **icon48_xpm,
const char **icon64_xpm)
{
GList *icon_list = NULL;
GdkPixbuf * pixbuf16;
GdkPixbuf * pixbuf32;
GdkPixbuf * pixbuf48;
GdkPixbuf * pixbuf64;
if(icon16_xpm != NULL) {
pixbuf16 = gdk_pixbuf_new_from_xpm_data(icon16_xpm);
g_assert(pixbuf16);
icon_list = g_list_append(icon_list, pixbuf16);
}
if(icon32_xpm != NULL) {
pixbuf32 = gdk_pixbuf_new_from_xpm_data(icon32_xpm);
g_assert(pixbuf32);
icon_list = g_list_append(icon_list, pixbuf32);
}
if(icon48_xpm != NULL) {
pixbuf48 = gdk_pixbuf_new_from_xpm_data(icon48_xpm);
g_assert(pixbuf48);
icon_list = g_list_append(icon_list, pixbuf48);
}
if(icon64_xpm != NULL) {
pixbuf64 = gdk_pixbuf_new_from_xpm_data(icon64_xpm);
g_assert(pixbuf64);
icon_list = g_list_append(icon_list, pixbuf64);
}
return icon_list;
}
static void
main_capture_set_main_window_title(capture_options *capture_opts)
{
GString *title = g_string_new("");
g_string_append(title, "Capturing ");
g_string_append_printf(title, "from %s ", cf_get_tempfile_source(capture_opts->cf));
main_set_window_name(title->str);
g_string_free(title, TRUE);
}
static void
main_capture_cb_capture_prepared(capture_options *capture_opts)
{
static GList *icon_list = NULL;
main_capture_set_main_window_title(capture_opts);
if(icon_list == NULL) {
icon_list = icon_list_create(wsiconcap16_xpm, wsiconcap32_xpm, wsiconcap48_xpm, NULL);
}
gtk_window_set_icon_list(GTK_WINDOW(top_level), icon_list);
set_menus_for_capture_in_progress(TRUE);
set_capture_if_dialog_for_capture_in_progress(TRUE);
main_set_for_capture_file(FALSE);
}
static void
main_capture_cb_capture_update_started(capture_options *capture_opts)
{
main_capture_set_main_window_title(capture_opts);
set_menus_for_capture_in_progress(TRUE);
set_capture_if_dialog_for_capture_in_progress(TRUE);
set_menus_for_captured_packets(TRUE);
main_set_for_capture_file(TRUE);
}
static void
main_capture_cb_capture_update_finished(capture_options *capture_opts)
{
capture_file *cf = capture_opts->cf;
static GList *icon_list = NULL;
capture_stopping = FALSE;
if (!cf->is_tempfile && cf->filename) {
add_menu_recent_capture_file(cf->filename);
}
main_update_for_unsaved_changes(cf);
set_menus_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
main_set_for_capture_file(TRUE);
if(icon_list == NULL) {
icon_list = icon_list_create(wsicon16_xpm, wsicon32_xpm, wsicon48_xpm, wsicon64_xpm);
}
gtk_window_set_icon_list(GTK_WINDOW(top_level), icon_list);
if(global_capture_opts.quit_after_cap) {
main_do_quit();
}
}
static void
main_capture_cb_capture_fixed_started(capture_options *capture_opts _U_)
{
main_set_for_capture_file(FALSE);
}
static void
main_capture_cb_capture_fixed_finished(capture_options *capture_opts _U_)
{
#if 0
capture_file *cf = capture_opts->cf;
#endif
static GList *icon_list = NULL;
capture_stopping = FALSE;
set_menus_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
main_set_window_name("The Wireshark Network Analyzer");
if(icon_list == NULL) {
icon_list = icon_list_create(wsicon16_xpm, wsicon32_xpm, wsicon48_xpm, wsicon64_xpm);
}
gtk_window_set_icon_list(GTK_WINDOW(top_level), icon_list);
if(global_capture_opts.quit_after_cap) {
main_do_quit();
}
}
static void
main_capture_cb_capture_stopping(capture_options *capture_opts _U_)
{
capture_stopping = TRUE;
set_menus_for_capture_stopping();
}
static void
main_capture_cb_capture_failed(capture_options *capture_opts _U_)
{
static GList *icon_list = NULL;
capture_stopping = FALSE;
main_set_window_name("The Wireshark Network Analyzer");
set_menus_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
main_set_for_capture_file(FALSE);
if(icon_list == NULL) {
icon_list = icon_list_create(wsicon16_xpm, wsicon32_xpm, wsicon48_xpm, wsicon64_xpm);
}
gtk_window_set_icon_list(GTK_WINDOW(top_level), icon_list);
if(global_capture_opts.quit_after_cap) {
main_do_quit();
}
}
static void
main_cf_cb_packet_selected(gpointer data)
{
capture_file *cf = data;
add_main_byte_views(cf->edt);
main_proto_tree_draw(cf->edt->tree);
if(cf->search_in_progress &&
(cf->search_pos != 0 || (cf->string && cf->decode_data))) {
highlight_field(cf->edt->tvb, cf->search_pos,
(GtkTreeView *)tree_view_gbl, cf->edt->tree);
}
set_menus_for_selected_packet(cf);
}
static void
main_cf_cb_packet_unselected(capture_file *cf)
{
clear_tree_and_hex_views();
set_menus_for_selected_packet(cf);
}
static void
main_cf_cb_field_unselected(capture_file *cf)
{
set_menus_for_selected_tree_row(cf);
}
static void
main_cf_callback(gint event, gpointer data, gpointer user_data _U_)
{
switch(event) {
case(cf_cb_file_closing):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Closing");
main_cf_cb_file_closing(data);
break;
case(cf_cb_file_closed):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Closed");
main_cf_cb_file_closed(data);
break;
case(cf_cb_file_read_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Read started");
main_cf_cb_file_read_started(data);
break;
case(cf_cb_file_read_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Read finished");
main_cf_cb_file_read_finished(data);
break;
case(cf_cb_file_reload_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Reload started");
main_cf_cb_file_read_started(data);
break;
case(cf_cb_file_reload_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Reload finished");
main_cf_cb_file_read_finished(data);
break;
case(cf_cb_file_rescan_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Rescan started");
break;
case(cf_cb_file_rescan_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Rescan finished");
main_cf_cb_file_rescan_finished(data);
break;
case(cf_cb_file_fast_save_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Fast save finished");
main_cf_cb_file_rescan_finished(data);
break;
case(cf_cb_packet_selected):
main_cf_cb_packet_selected(data);
break;
case(cf_cb_packet_unselected):
main_cf_cb_packet_unselected(data);
break;
case(cf_cb_field_unselected):
main_cf_cb_field_unselected(data);
break;
case(cf_cb_file_save_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Save started");
break;
case(cf_cb_file_save_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Save finished");
break;
case(cf_cb_file_save_failed):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Save failed");
break;
case(cf_cb_file_save_stopped):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Save stopped");
break;
case(cf_cb_file_export_specified_packets_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Export specified packets started");
break;
case(cf_cb_file_export_specified_packets_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Export specified packets finished");
break;
case(cf_cb_file_export_specified_packets_failed):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Export specified packets failed");
break;
case(cf_cb_file_export_specified_packets_stopped):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Export specified packets stopped");
break;
default:
g_warning("main_cf_callback: event %u unknown", event);
g_assert_not_reached();
}
}
static void
main_capture_callback(gint event, capture_options *capture_opts, gpointer user_data _U_)
{
#ifdef HAVE_GTKOSXAPPLICATION
GtkOSXApplication *theApp;
#endif
switch(event) {
case(capture_cb_capture_prepared):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture prepared");
main_capture_cb_capture_prepared(capture_opts);
break;
case(capture_cb_capture_update_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture update started");
main_capture_cb_capture_update_started(capture_opts);
#ifdef HAVE_GTKOSXAPPLICATION
theApp = g_object_new(GTK_TYPE_OSX_APPLICATION, NULL);
gtk_osxapplication_set_dock_icon_pixbuf(theApp,gdk_pixbuf_new_from_xpm_data(wsiconcap48_xpm));
#endif
break;
case(capture_cb_capture_update_continue):
break;
case(capture_cb_capture_update_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture update finished");
main_capture_cb_capture_update_finished(capture_opts);
break;
case(capture_cb_capture_fixed_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture fixed started");
main_capture_cb_capture_fixed_started(capture_opts);
break;
case(capture_cb_capture_fixed_continue):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture fixed continue");
break;
case(capture_cb_capture_fixed_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture fixed finished");
main_capture_cb_capture_fixed_finished(capture_opts);
break;
case(capture_cb_capture_stopping):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture stopping");
#ifdef HAVE_GTKOSXAPPLICATION
theApp = g_object_new(GTK_TYPE_OSX_APPLICATION, NULL);
gtk_osxapplication_set_dock_icon_pixbuf(theApp,gdk_pixbuf_new_from_xpm_data(wsicon64_xpm));
#endif
main_capture_cb_capture_stopping(capture_opts);
break;
case(capture_cb_capture_failed):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture failed");
main_capture_cb_capture_failed(capture_opts);
break;
default:
g_warning("main_capture_callback: event %u unknown", event);
g_assert_not_reached();
}
}
static void
get_gtk_compiled_info(GString *str)
{
g_string_append(str, "with ");
g_string_append_printf(str,
#ifdef GTK_MAJOR_VERSION
"GTK+ %d.%d.%d", GTK_MAJOR_VERSION, GTK_MINOR_VERSION,
GTK_MICRO_VERSION);
#else
"GTK+ (version unknown)");
void
get_gui_compiled_info(GString *str)
{
epan_get_compiled_version_info(str);
g_string_append(str, ", ");
#ifdef HAVE_LIBPORTAUDIO
#ifdef PORTAUDIO_API_1
g_string_append(str, "with PortAudio <= V18");
#else
g_string_append(str, "with ");
g_string_append(str, Pa_GetVersionText());
#endif
#else
g_string_append(str, "without PortAudio");
#endif
g_string_append(str, ", ");
#ifdef HAVE_AIRPCAP
get_compiled_airpcap_version(str);
#else
g_string_append(str, "without AirPcap");
#endif
}
static void
get_gui_runtime_info(GString *str)
{
epan_get_runtime_version_info(str);
#ifdef HAVE_AIRPCAP
g_string_append(str, ", ");
get_runtime_airpcap_version(str);
#endif
if(u3_active()) {
g_string_append(str, ", ");
u3_runtime_info(str);
}
}
static e_prefs *
read_configuration_files(char **gdp_path, char **dp_path)
{
int gpf_open_errno, gpf_read_errno;
int cf_open_errno, df_open_errno;
int gdp_open_errno, gdp_read_errno;
int dp_open_errno, dp_read_errno;
char *gpf_path, *pf_path;
char *cf_path, *df_path;
int pf_open_errno, pf_read_errno;
e_prefs *prefs_p;
load_decode_as_entries();
prefs_p = read_prefs(&gpf_open_errno, &gpf_read_errno, &gpf_path,
&pf_open_errno, &pf_read_errno, &pf_path);
if (gpf_path != NULL) {
if (gpf_open_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open global preferences file\n\"%s\": %s.", gpf_path,
g_strerror(gpf_open_errno));
}
if (gpf_read_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"I/O error reading global preferences file\n\"%s\": %s.", gpf_path,
g_strerror(gpf_read_errno));
}
}
if (pf_path != NULL) {
if (pf_open_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open your preferences file\n\"%s\": %s.", pf_path,
g_strerror(pf_open_errno));
}
if (pf_read_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"I/O error reading your preferences file\n\"%s\": %s.", pf_path,
g_strerror(pf_read_errno));
}
g_free(pf_path);
pf_path = NULL;
}
#ifdef _WIN32
if (prefs_p->gui_console_open == console_open_always) {
create_console();
}
#endif
read_filter_list(CFILTER_LIST, &cf_path, &cf_open_errno);
if (cf_path != NULL) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open your capture filter file\n\"%s\": %s.", cf_path,
g_strerror(cf_open_errno));
g_free(cf_path);
}
read_filter_list(DFILTER_LIST, &df_path, &df_open_errno);
if (df_path != NULL) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open your display filter file\n\"%s\": %s.", df_path,
g_strerror(df_open_errno));
g_free(df_path);
}
read_disabled_protos_list(gdp_path, &gdp_open_errno, &gdp_read_errno,
dp_path, &dp_open_errno, &dp_read_errno);
if (*gdp_path != NULL) {
if (gdp_open_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open global disabled protocols file\n\"%s\": %s.",
*gdp_path, g_strerror(gdp_open_errno));
}
if (gdp_read_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"I/O error reading global disabled protocols file\n\"%s\": %s.",
*gdp_path, g_strerror(gdp_read_errno));
}
g_free(*gdp_path);
*gdp_path = NULL;
}
if (*dp_path != NULL) {
if (dp_open_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open your disabled protocols file\n\"%s\": %s.", *dp_path,
g_strerror(dp_open_errno));
}
if (dp_read_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"I/O error reading your disabled protocols file\n\"%s\": %s.", *dp_path,
g_strerror(dp_read_errno));
}
g_free(*dp_path);
*dp_path = NULL;
}
return prefs_p;
}
static void
#ifdef _WIN32
check_and_warn_user_startup(gchar *cf_name)
#else
check_and_warn_user_startup(gchar *cf_name _U_)
#endif
{
gchar *cur_user, *cur_group;
gpointer priv_warning_dialog;
if (running_with_special_privs() && recent.privs_warn_if_elevated) {
cur_user = get_cur_username();
cur_group = get_cur_groupname();
priv_warning_dialog = simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Running as user \"%s\" and group \"%s\".\n"
"This could be dangerous.\n\n"
"If you're running Wireshark this way in order to perform live capture, "
"you may want to be aware that there is a better way documented at\n"
"http://wiki.wireshark.org/CaptureSetup/CapturePrivileges", cur_user, cur_group);
g_free(cur_user);
g_free(cur_group);
simple_dialog_check_set(priv_warning_dialog, "Don't show this message again.");
simple_dialog_set_cb(priv_warning_dialog, priv_warning_dialog_cb, NULL);
}
#ifdef _WIN32
if (!stdin_capture && !cf_name && !npf_sys_is_running() && recent.privs_warn_if_no_npf && get_os_major_version() >= 6) {
priv_warning_dialog = simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"The NPF driver isn't running. You may have trouble\n"
"capturing or listing interfaces.");
simple_dialog_check_set(priv_warning_dialog, "Don't show this message again.");
simple_dialog_set_cb(priv_warning_dialog, npf_warning_dialog_cb, NULL);
}
#endif
}
int
main(int argc, char *argv[])
{
char *init_progfile_dir_error;
char *s;
int opt;
gboolean arg_error = FALSE;
extern int info_update_freq;
const gchar *filter;
#ifdef _WIN32
WSADATA wsaData;
#endif
char *rf_path;
int rf_open_errno;
char *gdp_path, *dp_path;
int err;
#ifdef HAVE_LIBPCAP
gboolean start_capture = FALSE;
gboolean list_link_layer_types = FALSE;
GList *if_list;
gchar *err_str;
#else
gboolean capture_option_specified = FALSE;
#ifdef _WIN32
#ifdef HAVE_AIRPCAP
gchar *err_str;
#endif
#endif
#endif
gint pl_size = 280, tv_size = 95, bv_size = 75;
gchar *rc_file, *cf_name = NULL, *rfilter = NULL, *dfilter = NULL, *jfilter = NULL;
dfilter_t *rfcode = NULL;
gboolean rfilter_parse_failed = FALSE;
e_prefs *prefs_p;
char badopt;
GtkWidget *splash_win = NULL;
GLogLevelFlags log_flags;
guint go_to_packet = 0;
gboolean jump_backwards = FALSE;
dfilter_t *jump_to_filter = NULL;
int optind_initial;
int status;
#ifdef HAVE_GTKOSXAPPLICATION
GtkOSXApplication *theApp;
#endif
#ifdef HAVE_LIBPCAP
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
#define OPTSTRING_B "B:"
#else
#define OPTSTRING_B ""
#endif
#else
#define OPTSTRING_B ""
#endif
#ifdef HAVE_PCAP_CREATE
#define OPTSTRING_I "I"
#else
#define OPTSTRING_I ""
#endif
#define OPTSTRING "a:b:" OPTSTRING_B "c:C:d:Df:g:Hhi:" OPTSTRING_I "jJ:kK:lLm:nN:o:P:pr:R:Ss:t:u:vw:X:y:z:"
static const char optstring[] = OPTSTRING;
setlocale(LC_ALL, "");
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
#endif
init_process_policies();
relinquish_special_privs_perm();
init_progfile_dir_error = init_progfile_dir(argv[0], main);
initialize_funnel_ops();
AirPDcapInitContext(&airpdcap_ctx);
#ifdef _WIN32
load_wpcap();
wpcap_packet_load();
#ifdef HAVE_AIRPCAP
airpcap_dll_ret_val = load_airpcap();
switch (airpcap_dll_ret_val) {
case AIRPCAP_DLL_OK:
airpcap_if_list = get_airpcap_interface_list(&err, &err_str);
if (airpcap_if_list == NULL || g_list_length(airpcap_if_list) == 0){
if (err == CANT_GET_AIRPCAP_INTERFACE_LIST && err_str != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", "Failed to open Airpcap Adapters!");
g_free(err_str);
}
airpcap_if_active = NULL;
} else {
airpcap_if_active = airpcap_get_default_if(airpcap_if_list);
}
break;
#if 0
case AIRPCAP_DLL_OLD:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s","AIRPCAP_DLL_OLD\n");
break;
case AIRPCAP_DLL_ERROR:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s","AIRPCAP_DLL_ERROR\n");
break;
case AIRPCAP_DLL_NOT_FOUND:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s","AIRPCAP_DDL_NOT_FOUND\n");
break;
#endif
}
#endif
WSAStartup( MAKEWORD( 1, 1 ), &wsaData );
#endif
profile_store_persconffiles (TRUE);
comp_info_str = g_string_new("Compiled ");
get_compiled_version_info(comp_info_str, get_gtk_compiled_info, get_gui_compiled_info);
runtime_info_str = g_string_new("Running ");
get_runtime_version_info(runtime_info_str, get_gui_runtime_info);
recent_read_static(&rf_path, &rf_open_errno);
if (rf_path != NULL && rf_open_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open common recent file\n\"%s\": %s.",
rf_path, g_strerror(rf_open_errno));
}
opterr = 0;
optind_initial = optind;
while ((opt = getopt(argc, argv, optstring)) != -1) {
switch (opt) {
case 'C':
if (profile_exists (optarg, FALSE)) {
set_profile_name (optarg);
} else {
cmdarg_err("Configuration Profile \"%s\" does not exist", optarg);
exit(1);
}
break;
case 'D':
#ifdef HAVE_LIBPCAP
if_list = capture_interface_list(&err, &err_str);
if (if_list == NULL) {
switch (err) {
case CANT_GET_INTERFACE_LIST:
case DONT_HAVE_PCAP:
cmdarg_err("%s", err_str);
g_free(err_str);
break;
case NO_INTERFACES_FOUND:
cmdarg_err("There are no interfaces on which a capture can be done");
break;
}
exit(2);
}
capture_opts_print_interfaces(if_list);
free_interface_list(if_list);
exit(0);
#else
capture_option_specified = TRUE;
arg_error = TRUE;
#endif
break;
case 'h':
print_usage(TRUE);
exit(0);
break;
#ifdef _WIN32
case 'i':
if (strcmp(optarg, "-") == 0)
stdin_capture = TRUE;
break;
#endif
case 'P':
status = filesystem_opt(opt, optarg);
if(status != 0) {
cmdarg_err("-P flag \"%s\" failed (hint: is it quoted and existing?)", optarg);
exit(status);
}
break;
case 'v':
show_version();
exit(0);
break;
case 'X':
ex_opt_add(optarg);
break;
case '?':
break;
}
}
recent_read_profile_static(&rf_path, &rf_open_errno);
if (rf_path != NULL && rf_open_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open recent file\n\"%s\": %s.",
rf_path, g_strerror(rf_open_errno));
}
if (recent.gui_fileopen_remembered_dir &&
test_for_directory(recent.gui_fileopen_remembered_dir) == EISDIR) {
set_last_open_dir(recent.gui_fileopen_remembered_dir);
} else {
set_last_open_dir(get_persdatafile_dir());
}
optind = optind_initial;
opterr = 1;
#if !GLIB_CHECK_VERSION(2,31,0)
g_thread_init(NULL);
#endif
setlocale (LC_ALL, "");
gtk_init (&argc, &argv);
cf_callback_add(main_cf_callback, NULL);
#ifdef HAVE_LIBPCAP
capture_callback_add(main_capture_callback, NULL);
#endif
cf_callback_add(statusbar_cf_callback, NULL);
#ifdef HAVE_LIBPCAP
capture_callback_add(statusbar_capture_callback, NULL);
#endif
log_flags =
G_LOG_LEVEL_ERROR|
G_LOG_LEVEL_CRITICAL|
G_LOG_LEVEL_WARNING|
G_LOG_LEVEL_MESSAGE|
G_LOG_LEVEL_INFO|
G_LOG_LEVEL_DEBUG|
G_LOG_FLAG_FATAL|G_LOG_FLAG_RECURSION;
g_log_set_handler(NULL,
log_flags,
console_log_handler, NULL );
g_log_set_handler(LOG_DOMAIN_MAIN,
log_flags,
console_log_handler, NULL );
#ifdef HAVE_LIBPCAP
g_log_set_handler(LOG_DOMAIN_CAPTURE,
log_flags,
console_log_handler, NULL );
g_log_set_handler(LOG_DOMAIN_CAPTURE_CHILD,
log_flags,
console_log_handler, NULL );
capture_opts_init(&global_capture_opts, &cfile);
#endif
colors_init();
filter = get_conn_cfilter();
if ( *filter != '\0' ) {
info_update_freq = 1000;
}
splash_win = splash_new("Loading Wireshark ...");
if (init_progfile_dir_error != NULL) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Can't get pathname of Wireshark: %s.\n"
"It won't be possible to capture traffic.\n"
"Report this to the Wireshark developers.",
init_progfile_dir_error);
g_free(init_progfile_dir_error);
}
splash_update(RA_DISSECTORS, NULL, (gpointer)splash_win);
epan_init(register_all_protocols,register_all_protocol_handoffs,
splash_update, (gpointer) splash_win,
failure_alert_box,open_failure_alert_box,read_failure_alert_box,
write_failure_alert_box);
splash_update(RA_LISTENERS, NULL, (gpointer)splash_win);
#ifdef HAVE_PLUGINS
register_all_plugin_tap_listeners();
#endif
register_all_tap_listeners();
splash_update(RA_PREFERENCES, NULL, (gpointer)splash_win);
prefs_register_modules();
prefs_p = read_configuration_files (&gdp_path, &dp_path);
tap_update_timer_id = g_timeout_add(prefs_p->tap_update_interval, tap_update_cb, NULL);
splash_update(RA_CONFIGURATION, NULL, (gpointer)splash_win);
proto_help_init();
cap_file_init(&cfile);
prefs_to_capture_opts();
while ((opt = getopt(argc, argv, optstring)) != -1) {
switch (opt) {
case 'a':
case 'b':
case 'c':
case 'f':
case 'k':
case 'H':
case 'p':
case 'i':
#ifdef HAVE_PCAP_CREATE
case 'I':
#endif
case 's':
case 'S':
case 'w':
case 'y':
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
case 'B':
#endif
#ifdef HAVE_LIBPCAP
status = capture_opts_add_opt(&global_capture_opts, opt, optarg,
&start_capture);
if(status != 0) {
exit(status);
}
#else
capture_option_specified = TRUE;
arg_error = TRUE;
#endif
break;
#if defined(HAVE_HEIMDAL_KERBEROS) || defined(HAVE_MIT_KERBEROS)
case 'K':
read_keytab_file(optarg);
break;
#endif
case 'C':
break;
case 'd':
dfilter = optarg;
break;
case 'j':
jump_backwards = TRUE;
break;
case 'g':
go_to_packet = get_positive_int(optarg, "go to packet");
break;
case 'J':
jfilter = optarg;
break;
case 'l':
#ifdef HAVE_LIBPCAP
auto_scroll_live = TRUE;
#else
capture_option_specified = TRUE;
arg_error = TRUE;
#endif
break;
case 'L':
#ifdef HAVE_LIBPCAP
list_link_layer_types = TRUE;
#else
capture_option_specified = TRUE;
arg_error = TRUE;
#endif
break;
case 'm':
g_free(prefs_p->gui_font_name);
prefs_p->gui_font_name = g_strdup(optarg);
break;
case 'n':
gbl_resolv_flags = RESOLV_NONE;
break;
case 'N':
if (gbl_resolv_flags == RESOLV_ALL)
gbl_resolv_flags = RESOLV_NONE;
badopt = string_to_name_resolve(optarg, &gbl_resolv_flags);
if (badopt != '\0') {
cmdarg_err("-N specifies unknown resolving option '%c'; valid options are 'm', 'n', and 't'",
badopt);
exit(1);
}
break;
case 'o':
switch (prefs_set_pref(optarg)) {
case PREFS_SET_OK:
break;
case PREFS_SET_SYNTAX_ERR:
cmdarg_err("Invalid -o flag \"%s\"", optarg);
exit(1);
break;
case PREFS_SET_NO_SUCH_PREF:
switch (recent_set_arg(optarg)) {
case PREFS_SET_OK:
break;
case PREFS_SET_SYNTAX_ERR:
cmdarg_err("Invalid -o flag \"%s\"", optarg);
exit(1);
break;
case PREFS_SET_NO_SUCH_PREF:
case PREFS_SET_OBSOLETE:
cmdarg_err("-o flag \"%s\" specifies unknown preference/recent value",
optarg);
exit(1);
break;
default:
g_assert_not_reached();
}
break;
case PREFS_SET_OBSOLETE:
cmdarg_err("-o flag \"%s\" specifies obsolete preference",
optarg);
exit(1);
break;
default:
g_assert_not_reached();
}
break;
case 'P':
break;
case 'r':
cf_name = g_strdup(optarg);
break;
case 'R':
rfilter = optarg;
break;
case 't':
if (strcmp(optarg, "r") == 0)
timestamp_set_type(TS_RELATIVE);
else if (strcmp(optarg, "a") == 0)
timestamp_set_type(TS_ABSOLUTE);
else if (strcmp(optarg, "ad") == 0)
timestamp_set_type(TS_ABSOLUTE_WITH_DATE);
else if (strcmp(optarg, "d") == 0)
timestamp_set_type(TS_DELTA);
else if (strcmp(optarg, "dd") == 0)
timestamp_set_type(TS_DELTA_DIS);
else if (strcmp(optarg, "e") == 0)
timestamp_set_type(TS_EPOCH);
else if (strcmp(optarg, "u") == 0)
timestamp_set_type(TS_UTC);
else if (strcmp(optarg, "ud") == 0)
timestamp_set_type(TS_UTC_WITH_DATE);
else {
cmdarg_err("Invalid time stamp type \"%s\"", optarg);
cmdarg_err_cont("It must be \"r\" for relative, \"a\" for absolute,");
cmdarg_err_cont("\"ad\" for absolute with date, or \"d\" for delta.");
exit(1);
}
break;
case 'u':
if (strcmp(optarg, "s") == 0)
timestamp_set_seconds_type(TS_SECONDS_DEFAULT);
else if (strcmp(optarg, "hms") == 0)
timestamp_set_seconds_type(TS_SECONDS_HOUR_MIN_SEC);
else {
cmdarg_err("Invalid seconds type \"%s\"", optarg);
cmdarg_err_cont("It must be \"s\" for seconds or \"hms\" for hours, minutes and seconds.");
exit(1);
}
break;
case 'X':
break;
case 'z':
if (!process_stat_cmd_arg(optarg)) {
cmdarg_err("Invalid -z argument.");
cmdarg_err_cont(" -z argument must be one of :");
list_stat_cmd_args();
exit(1);
}
break;
default:
case '?':
arg_error = TRUE;
break;
}
}
if (!arg_error) {
argc -= optind;
argv += optind;
if (argc >= 1) {
if (cf_name != NULL) {
cmdarg_err("File name specified both with -r and regular argument");
arg_error = TRUE;
} else {
cf_name = g_strdup(argv[0]);
}
argc--;
argv++;
}
if (argc != 0) {
cmdarg_err("Invalid argument: %s", argv[0]);
arg_error = TRUE;
}
}
if (arg_error) {
#ifndef HAVE_LIBPCAP
if (capture_option_specified) {
cmdarg_err("This version of Wireshark was not built with support for capturing packets.");
}
#endif
print_usage(FALSE);
exit(1);
}
#ifdef HAVE_LIBPCAP
if (global_capture_opts.all_ifaces->len == 0) {
scan_local_interfaces(&global_capture_opts);
}
#endif
#ifdef HAVE_LIBPCAP
if (start_capture && list_link_layer_types) {
cmdarg_err("You can't specify both -L and a live capture.");
exit(1);
}
if (list_link_layer_types) {
if (cf_name) {
cmdarg_err("You can't specify -L and a capture file to be read.");
exit(1);
}
if (global_capture_opts.multi_files_on) {
cmdarg_err("Ring buffer requested, but a capture isn't being done.");
exit(1);
}
} else {
if (start_capture && cf_name) {
cmdarg_err("You can't specify both a live capture and a capture file to be read.");
exit(1);
}
if (global_capture_opts.multi_files_on) {
if (global_capture_opts.save_file == NULL) {
cmdarg_err("Ring buffer requested, but capture isn't being saved to a permanent file.");
global_capture_opts.multi_files_on = FALSE;
}
if (!global_capture_opts.has_autostop_filesize && !global_capture_opts.has_file_duration) {
cmdarg_err("Ring buffer requested, but no maximum capture file size or duration were specified.");
}
}
}
if (start_capture || list_link_layer_types) {
if (!capture_opts_trim_iface(&global_capture_opts,
(prefs_p->capture_device) ? get_if_name(prefs_p->capture_device) : NULL)) {
exit(2);
}
}
if (list_link_layer_types) {
if_capabilities_t *caps;
guint i;
interface_t device;
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (device.selected) {
#if defined(HAVE_PCAP_CREATE)
caps = capture_get_if_capabilities(device.name, device.monitor_mode_supported, &err_str);
#else
caps = capture_get_if_capabilities(device.name, FALSE, &err_str);
#endif
if (caps == NULL) {
cmdarg_err("%s", err_str);
g_free(err_str);
exit(2);
}
if (caps->data_link_types == NULL) {
cmdarg_err("The capture device \"%s\" has no data link types.", device.name);
exit(2);
}
#if defined(HAVE_PCAP_CREATE)
capture_opts_print_if_capabilities(caps, device.name, device.monitor_mode_supported);
#else
capture_opts_print_if_capabilities(caps, device.name, FALSE);
#endif
free_if_capabilities(caps);
}
}
exit(0);
}
capture_opts_trim_snaplen(&global_capture_opts, MIN_PACKET_SIZE);
capture_opts_trim_ring_num_files(&global_capture_opts);
#endif
prefs_apply_all();
#ifdef HAVE_LIBPCAP
if ((global_capture_opts.num_selected == 0) &&
(prefs.capture_device != NULL)) {
guint i;
interface_t device;
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (!device.hidden && strcmp(device.display_name, prefs.capture_device) == 0) {
device.selected = TRUE;
global_capture_opts.num_selected++;
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, i);
g_array_insert_val(global_capture_opts.all_ifaces, i, device);
break;
}
}
}
#endif
if (gdp_path == NULL && dp_path == NULL) {
set_disabled_protos_list();
}
build_column_format_array(&cfile.cinfo, prefs_p->num_cols, TRUE);
rc_file = get_datafile_path(RC_FILE);
#if GTK_CHECK_VERSION(3,0,0)
#else
gtk_rc_parse(rc_file);
g_free(rc_file);
rc_file = get_persconffile_path(RC_FILE, FALSE, FALSE);
gtk_rc_parse(rc_file);
#endif
g_free(rc_file);
font_init();
macros_init();
stock_icons_init();
splash_destroy(splash_win);
create_main_window(pl_size, tv_size, bv_size, prefs_p);
recent_read_dynamic(&rf_path, &rf_open_errno);
if (rf_path != NULL && rf_open_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open recent file\n\"%s\": %s.",
rf_path, g_strerror(rf_open_errno));
}
color_filters_enable(recent.packet_list_colorize);
main_widgets_rearrange();
menu_recent_read_finished();
#ifdef HAVE_LIBPCAP
main_auto_scroll_live_changed(auto_scroll_live);
#endif
switch (user_font_apply()) {
case FA_SUCCESS:
break;
case FA_FONT_NOT_RESIZEABLE:
case FA_FONT_NOT_AVAILABLE:
default:
recent.gui_zoom_level = 0;
}
dnd_init(top_level);
color_filters_init();
decode_as_init();
#ifdef HAVE_LIBPCAP
capture_filter_init();
#endif
main_load_window_geometry(top_level);
g_timeout_add(info_update_freq, resolv_update_cb, NULL);
if (dfilter) {
GtkWidget *filter_te;
filter_te = gtk_bin_get_child(GTK_BIN(g_object_get_data(G_OBJECT(top_level), E_DFILTER_CM_KEY)));
gtk_entry_set_text(GTK_ENTRY(filter_te), dfilter);
main_filter_packets(&cfile, dfilter, FALSE);
}
if (cf_name) {
show_main_window(TRUE);
check_and_warn_user_startup(cf_name);
if (rfilter != NULL) {
if (!dfilter_compile(rfilter, &rfcode)) {
bad_dfilter_alert_box(top_level, rfilter);
rfilter_parse_failed = TRUE;
}
}
if (!rfilter_parse_failed) {
if (cf_open(&cfile, cf_name, FALSE, &err) == CF_OK) {
cfile.rfcode = rfcode;
start_requested_stats();
switch (cf_read(&cfile, FALSE)) {
case CF_READ_OK:
case CF_READ_ERROR:
if(go_to_packet != 0) {
cf_goto_frame(&cfile, go_to_packet);
} else if (jfilter != NULL) {
if (!dfilter_compile(jfilter, &jump_to_filter)) {
bad_dfilter_alert_box(top_level, jfilter);
} else {
cf_find_packet_dfilter(&cfile, jump_to_filter, jump_backwards);
}
}
break;
case CF_READ_ABORTED:
exit(0);
break;
}
if (!g_path_is_absolute(cf_name)) {
char *old_cf_name = cf_name;
char *pwd = g_get_current_dir();
cf_name = g_strdup_printf("%s%s%s", pwd, G_DIR_SEPARATOR_S, cf_name);
g_free(old_cf_name);
g_free(pwd);
}
s = get_dirname(cf_name);
set_last_open_dir(s);
g_free(cf_name);
cf_name = NULL;
} else {
if (rfcode != NULL)
dfilter_free(rfcode);
cfile.rfcode = NULL;
show_main_window(FALSE);
set_menus_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
}
}
} else {
#ifdef HAVE_LIBPCAP
if (start_capture) {
if (global_capture_opts.save_file != NULL) {
s = get_dirname(g_strdup(global_capture_opts.save_file));
set_last_open_dir(s);
g_free(s);
}
show_main_window(FALSE);
check_and_warn_user_startup(cf_name);
if (global_capture_opts.ifaces->len == 0)
collect_ifaces(&global_capture_opts);
if (capture_start(&global_capture_opts)) {
start_requested_stats();
}
} else {
show_main_window(FALSE);
check_and_warn_user_startup(cf_name);
set_menus_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
}
if (!start_capture && !global_capture_opts.default_options.cfilter) {
global_capture_opts.default_options.cfilter = g_strdup(get_conn_cfilter());
}
#else
show_main_window(FALSE);
check_and_warn_user_startup(cf_name);
set_menus_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
#endif
}
u3_register_pid();
profile_store_persconffiles (FALSE);
#ifdef HAVE_GTKOSXAPPLICATION
theApp = g_object_new(GTK_TYPE_OSX_APPLICATION, NULL);
gtk_osxapplication_set_dock_icon_pixbuf(theApp,gdk_pixbuf_new_from_xpm_data(wsicon64_xpm));
gtk_osxapplication_ready(theApp);
#endif
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_INFO, "Wireshark is up and ready to go");
gtk_main();
u3_deregister_pid();
epan_cleanup();
AirPDcapDestroyContext(&airpdcap_ctx);
#ifdef _WIN32
gtk_widget_hide(top_level);
#ifdef HAVE_GTKOSXAPPLICATION
g_object_unref(theApp);
#endif
WSACleanup();
destroy_console();
#endif
exit(0);
}
int _stdcall
WinMain (struct HINSTANCE__ *hInstance,
struct HINSTANCE__ *hPrevInstance,
char *lpszCmdLine,
int nCmdShow)
{
INITCOMMONCONTROLSEX comm_ctrl;
ws_init_dll_search_path();
memset (&comm_ctrl, 0, sizeof(comm_ctrl));
comm_ctrl.dwSize = sizeof(comm_ctrl);
comm_ctrl.dwICC = ICC_WIN95_CLASSES;
InitCommonControlsEx(&comm_ctrl);
ws_load_library("riched20.dll");
has_console = FALSE;
console_wait = FALSE;
return main (__argc, __argv);
}
void
create_console(void)
{
if (stdin_capture) {
return;
}
if (!has_console) {
if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
if (AllocConsole()) {
console_wait = TRUE;
SetConsoleTitle(_T("Wireshark Debug Console"));
} else {
return;
}
}
ws_freopen("CONIN$", "r", stdin);
ws_freopen("CONOUT$", "w", stdout);
ws_freopen("CONOUT$", "w", stderr);
fprintf(stdout, "\n");
fprintf(stderr, "\n");
atexit(destroy_console);
has_console = TRUE;
}
}
static void
destroy_console(void)
{
if (console_wait) {
printf("\n\nPress any key to exit\n");
_getch();
}
FreeConsole();
}
static void
console_log_handler(const char *log_domain, GLogLevelFlags log_level,
const char *message, gpointer user_data _U_)
{
time_t curr;
struct tm *today;
const char *level;
if((log_level & G_LOG_LEVEL_MASK & prefs.console_log_level) == 0 &&
prefs.console_log_level != 0) {
return;
}
#ifdef _WIN32
if (prefs.gui_console_open != console_open_never || log_level & G_LOG_LEVEL_ERROR) {
create_console();
}
if (has_console) {
#endif
switch(log_level & G_LOG_LEVEL_MASK) {
case G_LOG_LEVEL_ERROR:
level = "Err ";
break;
case G_LOG_LEVEL_CRITICAL:
level = "Crit";
break;
case G_LOG_LEVEL_WARNING:
level = "Warn";
break;
case G_LOG_LEVEL_MESSAGE:
level = "Msg ";
break;
case G_LOG_LEVEL_INFO:
level = "Info";
break;
case G_LOG_LEVEL_DEBUG:
level = "Dbg ";
break;
default:
fprintf(stderr, "unknown log_level %u\n", log_level);
level = NULL;
g_assert_not_reached();
}
time(&curr);
today = localtime(&curr);
fprintf(stderr, "%02u:%02u:%02u %8s %s %s\n",
today->tm_hour, today->tm_min, today->tm_sec,
log_domain != NULL ? log_domain : "",
level, message);
#ifdef _WIN32
if(log_level & G_LOG_LEVEL_ERROR) {
printf("\n\nPress any key to exit\n");
_getch();
}
} else {
g_log_default_handler(log_domain, log_level, message, user_data);
}
#endif
}
static void foreach_remove_a_child(GtkWidget *widget, gpointer data) {
gtk_container_remove(GTK_CONTAINER(data), widget);
}
static GtkWidget *main_widget_layout(gint layout_content)
{
switch(layout_content) {
case(layout_pane_content_none):
return NULL;
case(layout_pane_content_plist):
return pkt_scrollw;
case(layout_pane_content_pdetails):
return tv_scrollw;
case(layout_pane_content_pbytes):
return byte_nb_ptr_gbl;
default:
g_assert_not_reached();
return NULL;
}
}
void main_widgets_rearrange(void) {
GtkWidget *first_pane_widget1, *first_pane_widget2;
GtkWidget *second_pane_widget1, *second_pane_widget2;
gboolean split_top_left = FALSE;
gtk_widget_hide(main_vbox);
g_object_ref(G_OBJECT(menubar));
g_object_ref(G_OBJECT(main_tb));
g_object_ref(G_OBJECT(filter_tb));
#ifdef HAVE_AIRPCAP
g_object_ref(G_OBJECT(airpcap_tb));
#endif
g_object_ref(G_OBJECT(pkt_scrollw));
g_object_ref(G_OBJECT(tv_scrollw));
g_object_ref(G_OBJECT(byte_nb_ptr_gbl));
g_object_ref(G_OBJECT(statusbar));
g_object_ref(G_OBJECT(main_pane_v1));
g_object_ref(G_OBJECT(main_pane_v2));
g_object_ref(G_OBJECT(main_pane_h1));
g_object_ref(G_OBJECT(main_pane_h2));
g_object_ref(G_OBJECT(welcome_pane));
gtk_container_foreach(GTK_CONTAINER(main_vbox), foreach_remove_a_child, main_vbox);
gtk_container_foreach(GTK_CONTAINER(main_pane_v1), foreach_remove_a_child, main_pane_v1);
gtk_container_foreach(GTK_CONTAINER(main_pane_v2), foreach_remove_a_child, main_pane_v2);
gtk_container_foreach(GTK_CONTAINER(main_pane_h1), foreach_remove_a_child, main_pane_h1);
gtk_container_foreach(GTK_CONTAINER(main_pane_h2), foreach_remove_a_child, main_pane_h2);
statusbar_widgets_emptying(statusbar);
gtk_box_pack_start(GTK_BOX(main_vbox), menubar, FALSE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(main_vbox), main_tb, FALSE, TRUE, 0);
if (!prefs.filter_toolbar_show_in_statusbar) {
gtk_box_pack_start(GTK_BOX(main_vbox), filter_tb, FALSE, TRUE, 1);
}
#ifdef HAVE_AIRPCAP
gtk_box_pack_start(GTK_BOX(main_vbox), airpcap_tb, FALSE, TRUE, 1);
#endif
switch(prefs.gui_layout_type) {
case(layout_type_5):
main_first_pane = main_pane_v1;
main_second_pane = main_pane_v2;
split_top_left = FALSE;
break;
case(layout_type_2):
main_first_pane = main_pane_v1;
main_second_pane = main_pane_h1;
split_top_left = FALSE;
break;
case(layout_type_1):
main_first_pane = main_pane_v1;
main_second_pane = main_pane_h1;
split_top_left = TRUE;
break;
case(layout_type_4):
main_first_pane = main_pane_h1;
main_second_pane = main_pane_v1;
split_top_left = FALSE;
break;
case(layout_type_3):
main_first_pane = main_pane_h1;
main_second_pane = main_pane_v1;
split_top_left = TRUE;
break;
case(layout_type_6):
main_first_pane = main_pane_h1;
main_second_pane = main_pane_h2;
split_top_left = FALSE;
break;
default:
main_first_pane = NULL;
main_second_pane = NULL;
g_assert_not_reached();
}
if (split_top_left) {
first_pane_widget1 = main_second_pane;
second_pane_widget1 = main_widget_layout(prefs.gui_layout_content_1);
second_pane_widget2 = main_widget_layout(prefs.gui_layout_content_2);
first_pane_widget2 = main_widget_layout(prefs.gui_layout_content_3);
} else {
first_pane_widget1 = main_widget_layout(prefs.gui_layout_content_1);
first_pane_widget2 = main_second_pane;
second_pane_widget1 = main_widget_layout(prefs.gui_layout_content_2);
second_pane_widget2 = main_widget_layout(prefs.gui_layout_content_3);
}
if (first_pane_widget1 != NULL)
gtk_paned_add1(GTK_PANED(main_first_pane), first_pane_widget1);
if (first_pane_widget2 != NULL)
gtk_paned_add2(GTK_PANED(main_first_pane), first_pane_widget2);
if (second_pane_widget1 != NULL)
gtk_paned_pack1(GTK_PANED(main_second_pane), second_pane_widget1, TRUE, TRUE);
if (second_pane_widget2 != NULL)
gtk_paned_pack2(GTK_PANED(main_second_pane), second_pane_widget2, FALSE, FALSE);
gtk_container_add(GTK_CONTAINER(main_vbox), main_first_pane);
gtk_box_pack_start(GTK_BOX(main_vbox), welcome_pane, TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(main_vbox), statusbar, FALSE, TRUE, 0);
if (prefs.filter_toolbar_show_in_statusbar) {
gtk_box_pack_start(GTK_BOX(statusbar), filter_tb, FALSE, TRUE, 1);
}
statusbar_widgets_pack(statusbar);
main_widgets_show_or_hide();
gtk_widget_show(main_vbox);
}
static void
is_widget_visible(GtkWidget *widget, gpointer data)
{
gboolean *is_visible = data;
if (!*is_visible) {
if (gtk_widget_get_visible(widget))
*is_visible = TRUE;
}
}
void
main_widgets_show_or_hide(void)
{
gboolean main_second_pane_show;
if (recent.main_toolbar_show) {
gtk_widget_show(main_tb);
} else {
gtk_widget_hide(main_tb);
}
statusbar_widgets_show_or_hide(statusbar);
if (recent.filter_toolbar_show) {
gtk_widget_show(filter_tb);
} else {
gtk_widget_hide(filter_tb);
}
#ifdef HAVE_AIRPCAP
if (recent.airpcap_toolbar_show) {
gtk_widget_show(airpcap_tb);
} else {
gtk_widget_hide(airpcap_tb);
}
#endif
if (recent.packet_list_show && have_capture_file) {
gtk_widget_show(pkt_scrollw);
} else {
gtk_widget_hide(pkt_scrollw);
}
if (recent.tree_view_show && have_capture_file) {
gtk_widget_show(tv_scrollw);
} else {
gtk_widget_hide(tv_scrollw);
}
if (recent.byte_view_show && have_capture_file) {
gtk_widget_show(byte_nb_ptr_gbl);
} else {
gtk_widget_hide(byte_nb_ptr_gbl);
}
if (have_capture_file) {
gtk_widget_show(main_first_pane);
} else {
gtk_widget_hide(main_first_pane);
}
main_second_pane_show = FALSE;
gtk_container_foreach(GTK_CONTAINER(main_second_pane), is_widget_visible,
&main_second_pane_show);
if (main_second_pane_show) {
gtk_widget_show(main_second_pane);
} else {
gtk_widget_hide(main_second_pane);
}
if (!have_capture_file) {
if(welcome_pane) {
gtk_widget_show(welcome_pane);
}
} else {
gtk_widget_hide(welcome_pane);
}
}
static gboolean
window_state_event_cb (GtkWidget *widget _U_,
GdkEvent *event,
gpointer data _U_)
{
GdkWindowState new_window_state = ((GdkEventWindowState*)event)->new_window_state;
if( (event->type) == (GDK_WINDOW_STATE)) {
if(!(new_window_state & GDK_WINDOW_STATE_ICONIFIED)) {
display_queued_messages();
}
}
return FALSE;
}
static gboolean
top_level_key_pressed_cb(GtkWidget *w _U_, GdkEventKey *event, gpointer user_data _U_)
{
if (event->keyval == GDK_F8) {
new_packet_list_next();
return TRUE;
} else if (event->keyval == GDK_F7) {
new_packet_list_prev();
return TRUE;
} else if (event->state & NO_SHIFT_MOD_MASK) {
return FALSE;
} else if (isascii(event->keyval) && isprint(event->keyval)) {
if (main_display_filter_widget && !gtk_widget_is_focus(main_display_filter_widget)) {
gtk_window_set_focus(GTK_WINDOW(top_level), main_display_filter_widget);
gtk_editable_set_position(GTK_EDITABLE(main_display_filter_widget), -1);
}
return FALSE;
}
return FALSE;
}
static void
create_main_window (gint pl_size, gint tv_size, gint bv_size, e_prefs *prefs_p)
{
GtkAccelGroup *accel;
top_level = window_new(GTK_WINDOW_TOPLEVEL, "");
main_set_window_name("The Wireshark Network Analyzer");
gtk_widget_set_name(top_level, "main window");
g_signal_connect(top_level, "delete_event", G_CALLBACK(main_window_delete_event_cb),
NULL);
g_signal_connect(G_OBJECT(top_level), "window_state_event",
G_CALLBACK(window_state_event_cb), NULL);
g_signal_connect(G_OBJECT(top_level), "key-press-event",
G_CALLBACK(top_level_key_pressed_cb), NULL );
main_vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 1, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vbox), 0);
gtk_container_add(GTK_CONTAINER(top_level), main_vbox);
gtk_widget_show(main_vbox);
menubar = main_menu_new(&accel);
#if defined(HAVE_IGE_MAC_INTEGRATION) || defined (HAVE_GTKOSXAPPLICATION)
if(!prefs_p->gui_macosx_style) {
#endif
gtk_window_add_accel_group(GTK_WINDOW(top_level), accel);
gtk_widget_show(menubar);
#if defined(HAVE_IGE_MAC_INTEGRATION) || defined(HAVE_GTKOSXAPPLICATION)
}
#endif
main_tb = toolbar_new();
gtk_widget_show (main_tb);
filter_tb = filter_toolbar_new();
pkt_scrollw = new_packet_list_create();
gtk_widget_set_size_request(pkt_scrollw, -1, pl_size);
gtk_widget_show_all(pkt_scrollw);
tv_scrollw = main_tree_view_new(prefs_p, &tree_view_gbl);
gtk_widget_set_size_request(tv_scrollw, -1, tv_size);
gtk_widget_show(tv_scrollw);
g_signal_connect(gtk_tree_view_get_selection(GTK_TREE_VIEW(tree_view_gbl)),
"changed", G_CALLBACK(tree_view_selection_changed_cb), NULL);
g_signal_connect(tree_view_gbl, "button_press_event", G_CALLBACK(popup_menu_handler),
g_object_get_data(G_OBJECT(popup_menu_object), PM_TREE_VIEW_KEY));
gtk_widget_show(tree_view_gbl);
byte_nb_ptr_gbl = byte_view_new();
gtk_widget_set_size_request(byte_nb_ptr_gbl, -1, bv_size);
gtk_widget_show(byte_nb_ptr_gbl);
g_signal_connect(byte_nb_ptr_gbl, "button_press_event", G_CALLBACK(popup_menu_handler),
g_object_get_data(G_OBJECT(popup_menu_object), PM_BYTES_VIEW_KEY));
main_pane_v1 = gtk_paned_new(GTK_ORIENTATION_VERTICAL);
gtk_widget_show(main_pane_v1);
main_pane_v2 = gtk_paned_new(GTK_ORIENTATION_VERTICAL);
gtk_widget_show(main_pane_v2);
main_pane_h1 = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
gtk_widget_show(main_pane_h1);
main_pane_h2 = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
gtk_widget_show(main_pane_h2);
#ifdef HAVE_AIRPCAP
airpcap_tb = airpcap_toolbar_new();
gtk_widget_show(airpcap_tb);
#endif
statusbar = statusbar_new();
gtk_widget_show(statusbar);
welcome_pane = welcome_new();
gtk_widget_show(welcome_pane);
}
static void
show_main_window(gboolean doing_work)
{
main_set_for_capture_file(doing_work);
gtk_widget_show(top_level);
main_load_window_geometry(top_level);
while (gtk_events_pending()) gtk_main_iteration();
display_queued_messages();
gdk_window_raise(gtk_widget_get_window(top_level));
#ifdef HAVE_AIRPCAP
airpcap_toolbar_show(airpcap_tb);
#endif
}
void
prefs_to_capture_opts(void)
{
#ifdef HAVE_LIBPCAP
global_capture_opts.default_options.promisc_mode = prefs.capture_prom_mode;
global_capture_opts.use_pcapng = prefs.capture_pcap_ng;
global_capture_opts.show_info = prefs.capture_show_info;
global_capture_opts.real_time_mode = prefs.capture_real_time;
auto_scroll_live = prefs.capture_auto_scroll;
#endif
gbl_resolv_flags = prefs.name_resolve;
}
static void copy_global_profile (const gchar *profile_name)
{
char *pf_dir_path, *pf_dir_path2, *pf_filename;
if (create_persconffile_profile(profile_name, &pf_dir_path) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't create directory\n\"%s\":\n%s.",
pf_dir_path, g_strerror(errno));
g_free(pf_dir_path);
}
if (copy_persconffile_profile(profile_name, profile_name, TRUE, &pf_filename,
&pf_dir_path, &pf_dir_path2) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't copy file \"%s\" in directory\n\"%s\" to\n\"%s\":\n%s.",
pf_filename, pf_dir_path2, pf_dir_path, g_strerror(errno));
g_free(pf_filename);
g_free(pf_dir_path);
g_free(pf_dir_path2);
}
}
void change_configuration_profile (const gchar *profile_name)
{
char *gdp_path, *dp_path;
char *rf_path;
int rf_open_errno;
if (!profile_exists(profile_name, FALSE)) {
if (profile_exists(profile_name, TRUE)) {
copy_global_profile (profile_name);
} else {
return;
}
}
if (profile_name && strcmp (profile_name, get_profile_name()) == 0) {
return;
}
main_save_window_geometry(top_level);
if (profile_exists(get_profile_name(), FALSE)) {
write_profile_recent();
}
set_profile_name (profile_name);
profile_bar_update ();
filter_expression_reinit(FILTER_EXPRESSION_REINIT_DESTROY);
prefs_reset();
menu_prefs_reset();
(void) read_configuration_files (&gdp_path, &dp_path);
recent_read_profile_static(&rf_path, &rf_open_errno);
if (rf_path != NULL && rf_open_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open common recent file\n\"%s\": %s.",
rf_path, g_strerror(rf_open_errno));
}
if (recent.gui_fileopen_remembered_dir &&
test_for_directory(recent.gui_fileopen_remembered_dir) == EISDIR) {
set_last_open_dir(recent.gui_fileopen_remembered_dir);
}
timestamp_set_type (recent.gui_time_format);
timestamp_set_seconds_type (recent.gui_seconds_format);
color_filters_enable(recent.packet_list_colorize);
prefs_to_capture_opts();
prefs_apply_all();
macros_post_update();
main_titlebar_update();
filter_expression_reinit(FILTER_EXPRESSION_REINIT_CREATE);
toolbar_redraw_all();
proto_enable_all();
if (gdp_path == NULL && dp_path == NULL) {
set_disabled_protos_list();
}
color_filters_reload();
welcome_if_panel_reload();
new_packet_list_recreate ();
cfile.cinfo.columns_changed = FALSE;
user_font_apply();
menu_recent_read_finished();
main_pane_load_window_geometry();
}
void redissect_packets(void)
{
cf_redissect_packets(&cfile);
status_expert_update();
}
guint get_interface_type(gchar *name, gchar *description)
{
#if defined(__linux__)
ws_statb64 statb;
char *wireless_path;
#endif
#if defined(_WIN32)
if (description && (strstr(description,"generic dialup") != NULL ||
strstr(description,"PPP/SLIP") != NULL )) {
return IF_DIALUP;
} else if (description && (strstr(description,"Wireless") != NULL ||
strstr(description,"802.11") != NULL)) {
return IF_WIRELESS;
} else if (description && strstr(description,"AirPcap") != NULL ||
strstr(name,"airpcap")) {
return IF_AIRPCAP;
} else if (description && strstr(description, "Bluetooth") != NULL ) {
return IF_BLUETOOTH;
}
#elif defined(__APPLE__)
if (strcmp(name, "en1") == 0) {
return IF_WIRELESS;
}
#elif defined(__linux__)
wireless_path = g_strdup_printf("/sys/class/net/%s/wireless", name);
if (wireless_path != NULL) {
if (ws_stat64(wireless_path, &statb) == 0) {
g_free(wireless_path);
return IF_WIRELESS;
}
}
if ( strstr(name,"bluetooth") != NULL) {
return IF_BLUETOOTH;
}
if ( strstr(name,"usbmon") != NULL ) {
return IF_USB;
}
#endif
if ( g_ascii_strncasecmp(name, "vmnet", 5) == 0) {
return IF_VIRTUAL;
}
if ( g_ascii_strncasecmp(name, "vmxnet", 6) == 0) {
return IF_VIRTUAL;
}
if (description && strstr(description, "VMware") != NULL ) {
return IF_VIRTUAL;
}
return IF_WIRED;
}
void
scan_local_interfaces(capture_options* capture_opts)
{
GList *if_entry, *lt_entry, *if_list;
if_info_t *if_info, *temp;
char *if_string;
gchar *descr;
if_capabilities_t *caps=NULL;
gint linktype_count;
cap_settings_t cap_settings;
GSList *curr_addr;
int ips = 0, i, err;
guint count = 0, j;
if_addr_t *addr, *temp_addr;
link_row *link = NULL;
data_link_info_t *data_link_info;
interface_t device;
GString *ip_str;
interface_options interface_opts;
gboolean found = FALSE;
if (capture_opts->all_ifaces->len > 0) {
for (i = (int)capture_opts->all_ifaces->len-1; i >= 0; i--) {
device = g_array_index(capture_opts->all_ifaces, interface_t, i);
if (device.local) {
capture_opts->all_ifaces = g_array_remove_index(capture_opts->all_ifaces, i);
}
}
}
if_list = capture_interface_list(&err, NULL);
count = 0;
for (if_entry = if_list; if_entry != NULL; if_entry = g_list_next(if_entry)) {
if_info = if_entry->data;
ip_str = g_string_new("");
ips = 0;
if (strstr(if_info->name, "rpcap:")) {
continue;
}
device.name = g_strdup(if_info->name);
device.hidden = FALSE;
device.locked = FALSE;
temp = g_malloc0(sizeof(if_info_t));
temp->name = g_strdup(if_info->name);
temp->description = g_strdup(if_info->description);
temp->loopback = if_info->loopback;
descr = capture_dev_user_descr_find(if_info->name);
if (descr != NULL) {
if_string = g_strdup_printf("%s: %s", descr, if_info->name);
g_free(descr);
} else {
if (if_info->description != NULL) {
if_string = g_strdup_printf("%s: %s", if_info->description, if_info->name);
} else {
if_string = g_strdup(if_info->name);
}
}
if (if_info->loopback) {
device.display_name = g_strdup_printf("%s (loopback)", if_string);
} else {
device.display_name = g_strdup(if_string);
}
g_free(if_string);
device.selected = FALSE;
if (prefs_is_capture_device_hidden(if_info->name)) {
device.hidden = TRUE;
}
device.type = get_interface_type(if_info->name, if_info->description);
cap_settings = capture_get_cap_settings(if_info->name);
caps = capture_get_if_capabilities(if_info->name, cap_settings.monitor_mode, NULL);
for (; (curr_addr = g_slist_nth(if_info->addrs, ips)) != NULL; ips++) {
temp_addr = g_malloc0(sizeof(if_addr_t));
if (ips != 0) {
g_string_append(ip_str, "\n");
}
addr = (if_addr_t *)curr_addr->data;
if (addr) {
temp_addr->ifat_type = addr->ifat_type;
switch (addr->ifat_type) {
case IF_AT_IPv4:
temp_addr->addr.ip4_addr = addr->addr.ip4_addr;
g_string_append(ip_str, ip_to_str((guint8 *)&addr->addr.ip4_addr));
break;
case IF_AT_IPv6:
memcpy(temp_addr->addr.ip6_addr, addr->addr.ip6_addr, sizeof(addr->addr));
g_string_append(ip_str, ip6_to_str((struct e_in6_addr *)&addr->addr.ip6_addr));
break;
default:
break;
}
} else {
g_free(temp_addr);
temp_addr = NULL;
}
if (temp_addr) {
temp->addrs = g_slist_append(temp->addrs, temp_addr);
}
}
#ifdef HAVE_PCAP_REMOTE
device.local = TRUE;
device.remote_opts.src_type = CAPTURE_IFLOCAL;
device.remote_opts.remote_host_opts.remote_host = g_strdup(capture_opts->default_options.remote_host);
device.remote_opts.remote_host_opts.remote_port = g_strdup(capture_opts->default_options.remote_port);
device.remote_opts.remote_host_opts.auth_type = capture_opts->default_options.auth_type;
device.remote_opts.remote_host_opts.auth_username = g_strdup(capture_opts->default_options.auth_username);
device.remote_opts.remote_host_opts.auth_password = g_strdup(capture_opts->default_options.auth_password);
device.remote_opts.remote_host_opts.datatx_udp = capture_opts->default_options.datatx_udp;
device.remote_opts.remote_host_opts.nocap_rpcap = capture_opts->default_options.nocap_rpcap;
device.remote_opts.remote_host_opts.nocap_local = capture_opts->default_options.nocap_local;
#endif
#ifdef HAVE_PCAP_SETSAMPLING
device.remote_opts.sampling_method = capture_opts->default_options.sampling_method;
device.remote_opts.sampling_param = capture_opts->default_options.sampling_param;
#endif
linktype_count = 0;
device.links = NULL;
if (caps != NULL) {
#if defined(HAVE_PCAP_CREATE)
device.monitor_mode_enabled = cap_settings.monitor_mode;
device.monitor_mode_supported = caps->can_set_rfmon;
#endif
for (lt_entry = caps->data_link_types; lt_entry != NULL; lt_entry = g_list_next(lt_entry)) {
data_link_info = lt_entry->data;
if (linktype_count == 0) {
device.active_dlt = data_link_info->dlt;
}
link = (link_row *)g_malloc(sizeof(link_row));
if (data_link_info->description != NULL) {
link->dlt = data_link_info->dlt;
link->name = g_strdup_printf("%s", data_link_info->description);
} else {
link->dlt = -1;
link->name = g_strdup_printf("%s (not supported)", data_link_info->name);
}
device.links = g_list_append(device.links, link);
linktype_count++;
}
} else {
cap_settings.monitor_mode = FALSE;
#if defined(HAVE_PCAP_CREATE)
device.monitor_mode_enabled = FALSE;
device.monitor_mode_supported = FALSE;
#endif
device.active_dlt = -1;
}
device.addresses = g_strdup(ip_str->str);
device.no_addresses = ips;
device.local = TRUE;
device.if_info = *temp;
device.last_packets = 0;
device.pmode = capture_opts->default_options.promisc_mode;
device.has_snaplen = capture_opts->default_options.has_snaplen;
device.snaplen = capture_opts->default_options.snaplen;
device.cfilter = g_strdup(capture_opts->default_options.cfilter);
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
device.buffer = 1;
#endif
if (capture_opts->ifaces->len > 0) {
for (j = 0; j < capture_opts->ifaces->len; j++) {
interface_opts = g_array_index(capture_opts->ifaces, interface_options, j);
if (strcmp(interface_opts.name, device.name) == 0) {
#if defined(HAVE_PCAP_CREATE)
device.buffer = interface_opts.buffer_size;
device.monitor_mode_enabled = interface_opts.monitor_mode;
#endif
device.pmode = interface_opts.promisc_mode;
device.has_snaplen = interface_opts.has_snaplen;
device.snaplen = interface_opts.snaplen;
device.cfilter = g_strdup(interface_opts.cfilter);
device.active_dlt = interface_opts.linktype;
device.selected = TRUE;
capture_opts->num_selected++;
break;
}
}
}
if (capture_opts->all_ifaces->len <= count) {
g_array_append_val(capture_opts->all_ifaces, device);
count = capture_opts->all_ifaces->len;
} else {
g_array_insert_val(capture_opts->all_ifaces, count, device);
}
if (caps != NULL) {
free_if_capabilities(caps);
}
g_string_free(ip_str, TRUE);
count++;
}
free_interface_list(if_list);
for (j = 0; j < capture_opts->ifaces->len; j++) {
interface_opts = g_array_index(capture_opts->ifaces, interface_options, j);
found = FALSE;
for (i = 0; i < (int)capture_opts->all_ifaces->len; i++) {
device = g_array_index(capture_opts->all_ifaces, interface_t, i);
if (strcmp(device.name, interface_opts.name) == 0) {
found = TRUE;
break;
}
}
if (!found) {
device.name = g_strdup(interface_opts.name);
device.display_name = g_strdup_printf("%s", device.name);
device.hidden = FALSE;
device.selected = TRUE;
device.type = IF_PIPE;
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
device.buffer = interface_opts.buffer_size;
#endif
#if defined(HAVE_PCAP_CREATE)
device.monitor_mode_enabled = interface_opts.monitor_mode;
device.monitor_mode_supported = FALSE;
#endif
device.pmode = interface_opts.promisc_mode;
device.has_snaplen = interface_opts.has_snaplen;
device.snaplen = interface_opts.snaplen;
device.cfilter = g_strdup(interface_opts.cfilter);
device.active_dlt = interface_opts.linktype;
device.addresses = NULL;
device.no_addresses = 0;
device.last_packets = 0;
device.links = NULL;
device.local = TRUE;
device.locked = FALSE;
g_array_append_val(capture_opts->all_ifaces, device);
capture_opts->num_selected++;
}
}
}
void hide_interface(gchar* new_hide)
{
gchar *tok;
guint i;
interface_t device;
gboolean found = FALSE;
GList *hidden_devices = NULL, *entry;
if (new_hide != NULL) {
for (tok = strtok (new_hide, ","); tok; tok = strtok(NULL, ",")) {
hidden_devices = g_list_append(hidden_devices, tok);
}
}
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
found = FALSE;
for (entry = hidden_devices; entry != NULL; entry = g_list_next(entry)) {
if (strcmp(entry->data, device.name)==0) {
device.hidden = TRUE;
if (device.selected) {
device.selected = FALSE;
global_capture_opts.num_selected--;
}
found = TRUE;
break;
}
}
if (!found) {
device.hidden = FALSE;
}
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, i);
g_array_insert_val(global_capture_opts.all_ifaces, i, device);
}
}
