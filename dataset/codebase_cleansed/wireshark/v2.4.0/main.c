static void
match_selected_cb_do(GtkWidget *filter_te, int action, gchar *text)
{
char *cur_filter, *new_filter;
if ((!text) || (0 == strlen(text))) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Could not acquire information to build a filter.\nTry expanding or choosing another item.");
return;
}
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
match_selected_ptree_cb(gpointer data, MATCH_SELECTED_E action)
{
char *filter = NULL;
if (cfile.finfo_selected) {
filter = proto_construct_match_selected_string(cfile.finfo_selected,
cfile.edt);
match_selected_cb_do((GtkWidget *)g_object_get_data(G_OBJECT(data), E_DFILTER_TE_KEY), action, filter);
wmem_free(NULL, filter);
}
}
void
colorize_selected_ptree_cb(GtkWidget *w _U_, gpointer data _U_, guint8 filt_nr)
{
char *filter = NULL;
gchar *err_msg = NULL;
if (cfile.finfo_selected) {
filter = proto_construct_match_selected_string(cfile.finfo_selected,
cfile.edt);
if ((!filter) || (0 == strlen(filter))) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not acquire information to build a filter.\n"
"Try expanding or choosing another item.");
return;
}
if (filt_nr==0) {
color_display_with_filter(filter);
} else {
if (filt_nr==255) {
if (!color_filters_reset_tmp(&err_msg)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_msg);
g_free(err_msg);
}
} else {
if (!color_filters_set_tmp(filt_nr,filter, FALSE, &err_msg)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_msg);
g_free(err_msg);
}
}
packet_list_colorize_packets();
}
wmem_free(NULL, filter);
}
}
static void selected_ptree_info_answered_cb(gpointer dialog _U_, gint btn, gpointer data)
{
gchar *selected_proto_url;
gchar *proto_abbrev = (gchar *)data;
switch(btn) {
case(ESD_BTN_OK):
if (cfile.finfo_selected) {
selected_proto_url = g_strdup_printf("https://wiki.wireshark.org/Protocols/%s", proto_abbrev);
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
"Hint 1: If you are new to wiki editing, try out editing the Sandbox first.\n"
"\n"
"Hint 2: If you want to add a new protocol page, you should use the ProtocolTemplate, "
"which will save you a lot of editing and will give a consistent look over the pages.",
simple_dialog_primary_start(), proto_abbrev, simple_dialog_primary_end(), proto_abbrev);
simple_dialog_set_cb(dialog, selected_ptree_info_answered_cb, (gpointer)proto_abbrev);
}
}
static void selected_ptree_ref_answered_cb(gpointer dialog _U_, gint btn, gpointer data)
{
gchar *selected_proto_url;
gchar *proto_abbrev = (gchar *)data;
switch(btn) {
case(ESD_BTN_OK):
if (cfile.finfo_selected) {
selected_proto_url = g_strdup_printf("https://www.wireshark.org/docs/dfref/%c/%s", proto_abbrev[0], proto_abbrev);
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
dialog = simple_dialog(ESD_TYPE_CONFIRMATION, ESD_BTNS_OK_CANCEL,
"%sOpen Wireshark filter reference page of protocol \"%s\"?%s\n"
"\n"
"This will open the \"%s\" related Wireshark filter reference page in your Web browser.\n"
"\n",
simple_dialog_primary_start(), proto_abbrev, simple_dialog_primary_end(), proto_abbrev);
simple_dialog_set_cb(dialog, selected_ptree_ref_answered_cb, (gpointer)proto_abbrev);
}
}
static gboolean
is_address_column (gint column)
{
if (((cfile.cinfo.columns[column].col_fmt == COL_DEF_SRC) ||
(cfile.cinfo.columns[column].col_fmt == COL_RES_SRC) ||
(cfile.cinfo.columns[column].col_fmt == COL_DEF_DST) ||
(cfile.cinfo.columns[column].col_fmt == COL_RES_DST)) &&
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
gint column = packet_list_get_column_id (GPOINTER_TO_INT(g_object_get_data(G_OBJECT(data), E_MPACKET_LIST_COL_KEY)));
gint col;
frame_data *fdata;
GList *addr_list = NULL;
fdata = (frame_data *) packet_list_get_row_data(row);
if (fdata != NULL) {
epan_dissect_t edt;
if (!cf_read_record(&cfile, fdata))
return NULL;
epan_dissect_init(&edt, cfile.epan, FALSE, FALSE);
col_custom_prime_edt(&edt, &cfile.cinfo);
epan_dissect_run(&edt, cfile.cd_t, &cfile.phdr,
frame_tvbuff_new_buffer(fdata, &cfile.buf), fdata, &cfile.cinfo);
epan_dissect_fill_in_columns(&edt, TRUE, TRUE);
if (is_address_column (column)) {
addr_list = g_list_append (addr_list, g_strdup(cfile.cinfo.col_expr.col_expr_val[column]));
}
for (col = 0; col < cfile.cinfo.num_cols; col++) {
if ((col != column) && (is_address_column (col))) {
addr_list = g_list_append (addr_list, g_strdup(cfile.cinfo.col_expr.col_expr_val[col]));
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
gint column = packet_list_get_column_id (GPOINTER_TO_INT(g_object_get_data(G_OBJECT(data), E_MPACKET_LIST_COL_KEY)));
frame_data *fdata;
gchar *buf=NULL;
fdata = (frame_data *) packet_list_get_row_data(row);
if (fdata != NULL) {
epan_dissect_t edt;
if (!cf_read_record(&cfile, fdata))
return NULL;
epan_dissect_init(&edt, cfile.epan, have_custom_cols(&cfile.cinfo), FALSE);
col_custom_prime_edt(&edt, &cfile.cinfo);
epan_dissect_run(&edt, cfile.cd_t, &cfile.phdr,
frame_tvbuff_new_buffer(fdata, &cfile.buf),
fdata, &cfile.cinfo);
epan_dissect_fill_in_columns(&edt, TRUE, TRUE);
if ((cfile.cinfo.columns[column].col_custom_occurrence) ||
(strchr (cfile.cinfo.col_expr.col_expr_val[column], ',') == NULL))
{
if (strlen(cfile.cinfo.col_expr.col_expr[column]) != 0 &&
strlen(cfile.cinfo.col_expr.col_expr_val[column]) != 0) {
if (cfile.cinfo.columns[column].col_fmt == COL_CUSTOM) {
header_field_info *hfi = proto_registrar_get_byname(cfile.cinfo.columns[column].col_custom_fields);
if (hfi && hfi->parent == -1) {
buf = g_strdup(cfile.cinfo.col_expr.col_expr[column]);
} else if (hfi && IS_FT_STRING(hfi->type)) {
buf = g_strdup_printf("%s == \"%s\"", cfile.cinfo.col_expr.col_expr[column],
cfile.cinfo.col_expr.col_expr_val[column]);
}
}
if (buf == NULL) {
buf = g_strdup_printf("%s == %s", cfile.cinfo.col_expr.col_expr[column],
cfile.cinfo.col_expr.col_expr_val[column]);
}
}
}
epan_dissect_cleanup(&edt);
}
return buf;
}
void
match_selected_plist_cb(gpointer data, MATCH_SELECTED_E action)
{
char *filter;
filter = get_filter_from_packet_list_row_and_column((GtkWidget *)data);
match_selected_cb_do((GtkWidget *)g_object_get_data(G_OBJECT(data), E_DFILTER_TE_KEY),
action, filter);
g_free(filter);
}
void
copy_selected_plist_cb(GtkWidget *w _U_, gpointer data _U_, COPY_SELECTED_E action)
{
GString *gtk_text_str = g_string_new("");
char labelstring[ITEM_LABEL_LENGTH];
char *stringpointer = labelstring;
switch(action)
{
case COPY_SELECTED_DESCRIPTION:
if (cfile.finfo_selected->rep &&
strlen(cfile.finfo_selected->rep->representation) > 0) {
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
gchar* field_str = get_node_field_value(cfile.finfo_selected, cfile.edt);
g_string_append(gtk_text_str, field_str);
g_free(field_str);
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
packet_list_freeze();
cfile.displayed_count--;
packet_list_recreate_visible_rows();
packet_list_thaw();
}
packet_list_queue_draw();
}
static void reftime_answered_cb(gpointer dialog _U_, gint btn, gpointer data _U_)
{
switch(btn) {
case(ESD_BTN_YES):
timestamp_set_type(TS_RELATIVE);
recent.gui_time_format = TS_RELATIVE;
cf_timestamp_auto_precision(&cfile);
packet_list_queue_draw();
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
reftime_dialog = (GtkWidget *)simple_dialog(ESD_TYPE_CONFIRMATION, ESD_BTNS_YES_NO,
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
}
void collapse_all_cb(GtkWidget *widget _U_, gpointer data _U_)
{
if (cfile.edt->tree)
collapse_all_tree(cfile.edt->tree, tree_view_gbl);
}
void expand_all_cb(GtkWidget *widget _U_, gpointer data _U_)
{
if (cfile.edt->tree)
expand_all_tree(cfile.edt->tree, tree_view_gbl);
}
void apply_as_custom_column_cb (GtkWidget *widget _U_, gpointer data _U_)
{
if (cfile.finfo_selected) {
column_prefs_add_custom(COL_CUSTOM, cfile.finfo_selected->hfinfo->name,
cfile.finfo_selected->hfinfo->abbrev,0);
packet_list_recreate ();
if (!prefs.gui_use_pref_save) {
prefs_main_write();
}
cfile.columns_changed = FALSE;
}
}
void expand_tree_cb(GtkWidget *widget _U_, gpointer data _U_)
{
GtkTreePath *path;
path = tree_find_by_field_info(GTK_TREE_VIEW(tree_view_gbl), cfile.finfo_selected);
if(path) {
gtk_tree_view_expand_row(GTK_TREE_VIEW(tree_view_gbl), path, TRUE);
gtk_tree_path_free(path);
}
}
void collapse_tree_cb(GtkWidget *widget _U_, gpointer data _U_)
{
GtkTreePath *path;
path = tree_find_by_field_info(GTK_TREE_VIEW(tree_view_gbl), cfile.finfo_selected);
if(path) {
tree_collapse_path_all(GTK_TREE_VIEW(tree_view_gbl), path);
gtk_tree_path_free(path);
}
}
void resolve_name_cb(GtkWidget *widget _U_, gpointer data _U_)
{
static const e_addr_resolve resolv_flags = {
TRUE,
TRUE,
TRUE,
TRUE,
TRUE,
FALSE,
FALSE,
FALSE,
};
if (cfile.edt->tree) {
proto_tree_draw_resolve(cfile.edt->tree, tree_view_gbl, &resolv_flags);
}
}
static void
main_set_for_capture_in_progress(gboolean capture_in_progress)
{
set_menus_for_capture_in_progress(capture_in_progress);
#ifdef HAVE_LIBPCAP
set_toolbar_for_capture_in_progress(capture_in_progress);
set_capture_if_dialog_for_capture_in_progress(capture_in_progress);
#endif
}
static void
main_set_for_capture_file(gboolean have_capture_file_in)
{
have_capture_file = have_capture_file_in;
main_widgets_show_or_hide();
}
static void
main_set_for_captured_packets(gboolean have_captured_packets)
{
set_menus_for_captured_packets(have_captured_packets);
set_toolbar_for_captured_packets(have_captured_packets);
}
void
main_set_for_packet_history(gboolean back_history, gboolean forward_history)
{
set_menus_for_packet_history(back_history, forward_history);
set_toolbar_for_packet_history(back_history, forward_history);
}
gboolean
main_do_quit(void)
{
main_save_window_geometry(top_level);
write_profile_recent();
write_recent();
#ifdef HAVE_LIBPCAP
capture_kill_child(&global_capture_session);
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
geom.x = recent.gui_gtk_geometry_main_x;
geom.y = recent.gui_gtk_geometry_main_y;
geom.set_size = prefs.gui_geometry_save_size;
geom.set_maximized = FALSE;
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
recent.gui_gtk_geometry_main_x = geom.x;
recent.gui_gtk_geometry_main_y = geom.y;
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
wireshark_cmdarg_err(const char *fmt, va_list ap)
{
#ifdef _WIN32
create_console();
#endif
fprintf(stderr, "wireshark: ");
vfprintf(stderr, fmt, ap);
fprintf(stderr, "\n");
}
static void
wireshark_cmdarg_err_cont(const char *fmt, va_list ap)
{
#ifdef _WIN32
create_console();
#endif
vfprintf(stderr, fmt, ap);
fprintf(stderr, "\n");
}
static gboolean
tap_update_cb(gpointer data _U_)
{
draw_tap_listeners(FALSE);
return TRUE;
}
static gboolean
resolv_update_cb(gpointer data _U_)
{
if (host_name_lookup_process()) {
if (gtk_widget_get_window(pkt_scrollw))
gdk_window_invalidate_rect(gtk_widget_get_window(pkt_scrollw), NULL, TRUE);
if (gtk_widget_get_window(tv_scrollw))
gdk_window_invalidate_rect(gtk_widget_get_window(tv_scrollw), NULL, TRUE);
}
return TRUE;
}
void
main_update_for_unsaved_changes(capture_file *cf)
{
set_titlebar_for_capture_file(cf);
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
packet_list_enable_color(packet_list_colorize);
packet_list_colorize_packets();
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
close_dlg = (GtkWidget *)simple_dialog(ESD_TYPE_STOP, ESD_BTN_NONE,
"%sClosing file.%s\n\nPlease wait ...",
simple_dialog_primary_start(),
simple_dialog_primary_end());
gtk_window_set_position(GTK_WINDOW(close_dlg), GTK_WIN_POS_CENTER_ON_PARENT);
}
manually_resolve_cleanup();
destroy_packet_wins();
set_titlebar_for_capture_file(NULL);
set_menus_for_capture_file(NULL);
set_toolbar_for_capture_file(NULL);
main_set_for_captured_packets(FALSE);
set_menus_for_selected_packet(cf);
main_set_for_capture_in_progress(FALSE);
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
dir_path = g_strdup(cf->filename);
set_last_open_dir(get_dirname(dir_path));
g_free(dir_path);
}
main_update_for_unsaved_changes(cf);
main_set_for_captured_packets(TRUE);
}
static void
main_cf_cb_file_rescan_finished(capture_file *cf)
{
gchar *dir_path;
if (!cf->is_tempfile && cf->filename) {
add_menu_recent_capture_file(cf->filename);
dir_path = g_strdup(cf->filename);
set_last_open_dir(get_dirname(dir_path));
g_free(dir_path);
}
main_update_for_unsaved_changes(cf);
}
static void
main_capture_cb_capture_prepared(capture_session *cap_session)
{
static GList *icon_list = NULL;
set_titlebar_for_capture_in_progress((capture_file *)cap_session->cf);
if(icon_list == NULL) {
#ifdef HAVE_GDK_GRESOURCE
icon_list = icon_list_create("/org/wireshark/image/wsiconcap16.png",
"/org/wireshark/image/wsiconcap32.png",
"/org/wireshark/image/wsiconcap48.png",
"/org/wireshark/image/wsiconcap64.png");
#else
icon_list = icon_list_create(wsiconcap_16_pb_data,
wsiconcap_32_pb_data,
wsiconcap_48_pb_data,
wsiconcap_64_pb_data);
#endif
}
gtk_window_set_icon_list(GTK_WINDOW(top_level), icon_list);
main_set_for_capture_in_progress(TRUE);
set_capture_if_dialog_for_capture_in_progress(TRUE);
main_set_for_capture_file(FALSE);
}
static void
main_capture_cb_capture_update_started(capture_session *cap_session)
{
set_titlebar_for_capture_in_progress((capture_file *)cap_session->cf);
main_set_for_capture_in_progress(TRUE);
set_capture_if_dialog_for_capture_in_progress(TRUE);
main_set_for_captured_packets(TRUE);
main_set_for_capture_file(TRUE);
}
static void
main_capture_cb_capture_update_finished(capture_session *cap_session)
{
capture_file *cf = (capture_file *)cap_session->cf;
static GList *icon_list = NULL;
capture_stopping = FALSE;
if (!cf->is_tempfile && cf->filename) {
add_menu_recent_capture_file(cf->filename);
}
main_set_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
main_update_for_unsaved_changes(cf);
main_set_for_capture_file(TRUE);
if(icon_list == NULL) {
#ifdef HAVE_GDK_GRESOURCE
icon_list = icon_list_create("/org/wireshark/image/wsicon16.png",
"/org/wireshark/image/wsicon32.png",
"/org/wireshark/image/wsicon48.png",
"/org/wireshark/image/wsicon64.png");
#else
icon_list = icon_list_create(wsicon_16_pb_data,
wsicon_32_pb_data,
wsicon_48_pb_data,
wsicon_64_pb_data);
#endif
}
gtk_window_set_icon_list(GTK_WINDOW(top_level), icon_list);
if(global_commandline_info.quit_after_cap) {
main_do_quit();
}
}
static void
main_capture_cb_capture_fixed_started(capture_session *cap_session _U_)
{
main_set_for_capture_file(FALSE);
}
static void
main_capture_cb_capture_fixed_finished(capture_session *cap_session _U_)
{
#if 0
capture_file *cf = (capture_file *)cap_session->cf;
#endif
static GList *icon_list = NULL;
capture_stopping = FALSE;
main_set_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
set_titlebar_for_capture_file(NULL);
if(icon_list == NULL) {
#ifdef HAVE_GDK_GRESOURCE
icon_list = icon_list_create("/org/wireshark/image/wsicon16.png",
"/org/wireshark/image/wsicon32.png",
"/org/wireshark/image/wsicon48.png",
"/org/wireshark/image/wsicon64.png");
#else
icon_list = icon_list_create(wsicon_16_pb_data,
wsicon_32_pb_data,
wsicon_48_pb_data,
wsicon_64_pb_data);
#endif
}
gtk_window_set_icon_list(GTK_WINDOW(top_level), icon_list);
if(global_commandline_info.quit_after_cap) {
main_do_quit();
}
}
static void
main_capture_cb_capture_stopping(capture_session *cap_session _U_)
{
capture_stopping = TRUE;
set_menus_for_capture_stopping();
#ifdef HAVE_LIBPCAP
set_toolbar_for_capture_stopping();
set_capture_if_dialog_for_capture_stopping();
#endif
}
static void
main_capture_cb_capture_failed(capture_session *cap_session _U_)
{
static GList *icon_list = NULL;
capture_stopping = FALSE;
set_titlebar_for_capture_file(NULL);
main_set_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
main_set_for_capture_file(FALSE);
if(icon_list == NULL) {
#ifdef HAVE_GDK_GRESOURCE
icon_list = icon_list_create("/org/wireshark/image/wsicon16.png",
"/org/wireshark/image/wsicon32.png",
"/org/wireshark/image/wsicon48.png",
"/org/wireshark/image/wsicon64.png");
#else
icon_list = icon_list_create(wsicon_16_pb_data,
wsicon_32_pb_data,
wsicon_48_pb_data,
wsicon_64_pb_data);
#endif
}
gtk_window_set_icon_list(GTK_WINDOW(top_level), icon_list);
if(global_commandline_info.quit_after_cap) {
main_do_quit();
}
}
static void
main_cf_cb_packet_selected(gpointer data)
{
capture_file *cf = (capture_file *)data;
add_byte_views(cf->edt, tree_view_gbl, byte_nb_ptr_gbl);
proto_tree_draw(cf->edt->tree, tree_view_gbl);
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
while (gtk_notebook_get_nth_page(GTK_NOTEBOOK(byte_nb_ptr_gbl), 0) != NULL)
gtk_notebook_remove_page(GTK_NOTEBOOK(byte_nb_ptr_gbl), 0);
add_byte_tab(byte_nb_ptr_gbl, "", NULL, NULL, tree_view_gbl);
proto_tree_draw(NULL, tree_view_gbl);
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
capture_file *cf = (capture_file *)data;
switch(event) {
case(cf_cb_file_opened):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Opened");
fileset_file_opened(cf);
break;
case(cf_cb_file_closing):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Closing");
main_cf_cb_file_closing(cf);
break;
case(cf_cb_file_closed):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Closed");
main_cf_cb_file_closed(cf);
fileset_file_closed();
break;
case(cf_cb_file_read_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Read started");
main_cf_cb_file_read_started(cf);
break;
case(cf_cb_file_read_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Read finished");
main_cf_cb_file_read_finished(cf);
break;
case(cf_cb_file_reload_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Reload started");
main_cf_cb_file_read_started(cf);
break;
case(cf_cb_file_reload_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Reload finished");
main_cf_cb_file_read_finished(cf);
break;
case(cf_cb_file_rescan_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Rescan started");
break;
case(cf_cb_file_rescan_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Rescan finished");
main_cf_cb_file_rescan_finished(cf);
break;
case(cf_cb_file_retap_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Retap started");
break;
case(cf_cb_file_retap_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Retap finished");
break;
case(cf_cb_file_fast_save_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: Fast save finished");
main_cf_cb_file_rescan_finished(cf);
break;
case(cf_cb_packet_selected):
main_cf_cb_packet_selected(cf);
break;
case(cf_cb_packet_unselected):
main_cf_cb_packet_unselected(cf);
break;
case(cf_cb_field_unselected):
main_cf_cb_field_unselected(cf);
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
main_capture_callback(gint event, capture_session *cap_session, gpointer user_data _U_)
{
#ifdef HAVE_GTKOSXAPPLICATION
GtkosxApplication *theApp;
#endif
switch(event) {
case(capture_cb_capture_prepared):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture prepared");
main_capture_cb_capture_prepared(cap_session);
break;
case(capture_cb_capture_update_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture update started");
main_capture_cb_capture_update_started(cap_session);
#ifdef HAVE_GTKOSXAPPLICATION
theApp = (GtkosxApplication *)g_object_new(GTKOSX_TYPE_APPLICATION, NULL);
#ifdef HAVE_GDK_GRESOURCE
gtkosx_application_set_dock_icon_pixbuf(theApp, ws_gdk_pixbuf_new_from_resource("/org/wireshark/image/wsicon48.png"));
#else
gtkosx_application_set_dock_icon_pixbuf(theApp, gdk_pixbuf_new_from_inline(-1, wsicon_48_pb_data, FALSE, NULL));
#endif
#endif
break;
case(capture_cb_capture_update_continue):
break;
case(capture_cb_capture_update_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture update finished");
main_capture_cb_capture_update_finished(cap_session);
break;
case(capture_cb_capture_fixed_started):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture fixed started");
main_capture_cb_capture_fixed_started(cap_session);
break;
case(capture_cb_capture_fixed_continue):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture fixed continue");
break;
case(capture_cb_capture_fixed_finished):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture fixed finished");
main_capture_cb_capture_fixed_finished(cap_session);
break;
case(capture_cb_capture_stopping):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture stopping");
#ifdef HAVE_GTKOSXAPPLICATION
theApp = (GtkosxApplication *)g_object_new(GTKOSX_TYPE_APPLICATION, NULL);
#ifdef HAVE_GDK_GRESOURCE
gtkosx_application_set_dock_icon_pixbuf(theApp, ws_gdk_pixbuf_new_from_resource("/org/wireshark/image/wsicon64.png"));
#else
gtkosx_application_set_dock_icon_pixbuf(theApp, gdk_pixbuf_new_from_inline(-1, wsicon_64_pb_data, FALSE, NULL));
#endif
#endif
main_capture_cb_capture_stopping(cap_session);
break;
case(capture_cb_capture_failed):
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_DEBUG, "Callback: capture failed");
main_capture_cb_capture_failed(cap_session);
break;
default:
g_warning("main_capture_callback: event %u unknown", event);
g_assert_not_reached();
}
}
void
get_wireshark_gtk_compiled_info(GString *str)
{
g_string_append(str, "with ");
g_string_append_printf(str,
#ifdef GTK_MAJOR_VERSION
"GTK+ %d.%d.%d", GTK_MAJOR_VERSION, GTK_MINOR_VERSION,
GTK_MICRO_VERSION);
#else
"GTK+ (version unknown)");
void
get_wireshark_runtime_info(GString *str)
{
#ifdef HAVE_LIBPCAP
g_string_append(str, ", ");
get_runtime_caplibs_version(str);
#endif
epan_get_runtime_version_info(str);
#ifdef HAVE_AIRPCAP
g_string_append(str, ", ");
get_runtime_airpcap_version(str);
#endif
}
static e_prefs *
read_configuration_files(void)
{
e_prefs *prefs_p;
prefs_p = epan_load_settings();
#ifdef _WIN32
if (prefs_p->gui_console_open == console_open_always) {
create_console();
}
#endif
read_filter_list(CFILTER_LIST);
read_filter_list(DFILTER_LIST);
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
"https://wiki.wireshark.org/CaptureSetup/CapturePrivileges", cur_user, cur_group);
g_free(cur_user);
g_free(cur_group);
simple_dialog_check_set(priv_warning_dialog, "Don't show this message again.");
simple_dialog_set_cb(priv_warning_dialog, priv_warning_dialog_cb, NULL);
}
#ifdef _WIN32
if (!get_stdin_capture() && !cf_name && !npf_sys_is_running() && recent.privs_warn_if_no_npf && get_windows_major_version() >= 6) {
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
int ret = EXIT_SUCCESS;
extern int info_update_freq;
const gchar *filter;
#ifdef _WIN32
WSADATA wsaData;
int result;
#endif
char *rf_path;
int rf_open_errno;
int err;
#ifdef HAVE_LIBPCAP
gchar *err_str;
#else
#ifdef _WIN32
#ifdef HAVE_AIRPCAP
gchar *err_str;
#endif
#endif
#endif
gint pl_size = 280, tv_size = 95, bv_size = 75;
gchar *rc_file;
dfilter_t *rfcode = NULL;
gchar *err_msg = NULL;
gboolean rfilter_parse_failed = FALSE;
GtkWidget *splash_win = NULL;
dfilter_t *jump_to_filter = NULL;
unsigned int in_file_type = WTAP_TYPE_AUTO;
#ifdef HAVE_GTKOSXAPPLICATION
GtkosxApplication *theApp;
#endif
GString *comp_info_str = NULL;
GString *runtime_info_str = NULL;
#ifdef HAVE_GDK_GRESOURCE
main_register_resource();
#endif
cmdarg_err_init(wireshark_cmdarg_err, wireshark_cmdarg_err_cont);
setlocale(LC_ALL, "");
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
create_app_running_mutex();
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
g_airpcap_if_list = get_airpcap_interface_list(&err, &err_str);
if (g_airpcap_if_list == NULL || g_list_length(g_airpcap_if_list) == 0){
if (err == CANT_GET_AIRPCAP_INTERFACE_LIST && err_str != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", "Failed to open Airpcap Adapters.");
g_free(err_str);
}
airpcap_if_active = NULL;
} else {
airpcap_if_active = airpcap_get_default_if(g_airpcap_if_list);
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
#endif
comp_info_str = get_compiled_version_info(get_wireshark_gtk_compiled_info,
get_gui_compiled_info);
runtime_info_str = get_runtime_version_info(get_wireshark_runtime_info);
ws_add_crash_info("Wireshark %s\n"
"\n"
"%s"
"\n"
"%s",
get_ws_vcs_version_info(), comp_info_str->str, runtime_info_str->str);
#ifdef _WIN32
result = WSAStartup( MAKEWORD( 1, 1 ), &wsaData );
if (result != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Error: WSAStartup failed with error: %d", result);
ret = INIT_FAILED;
goto clean_exit;
}
#endif
profile_store_persconffiles (TRUE);
recent_read_static(&rf_path, &rf_open_errno);
if (rf_path != NULL && rf_open_errno != 0) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open common recent file\n\"%s\": %s.",
rf_path, g_strerror(rf_open_errno));
}
commandline_early_options(argc, argv, comp_info_str, runtime_info_str);
if (!recent_read_profile_static(&rf_path, &rf_open_errno)) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open recent file\n\"%s\": %s.",
rf_path, g_strerror(rf_open_errno));
g_free(rf_path);
}
if (recent.gui_fileopen_remembered_dir &&
test_for_directory(recent.gui_fileopen_remembered_dir) == EISDIR) {
set_last_open_dir(recent.gui_fileopen_remembered_dir);
} else {
set_last_open_dir(get_persdatafile_dir());
}
#if !GLIB_CHECK_VERSION(2,31,0)
g_thread_init(NULL);
#endif
#if !GTK_CHECK_VERSION(3,16,0)
if (NULL == g_getenv("LIBOVERLAY_SCROLLBAR")) {
g_setenv("LIBOVERLAY_SCROLLBAR", "0", FALSE);
}
#endif
gtk_init (&argc, &argv);
cf_callback_add(main_cf_callback, NULL);
#ifdef HAVE_LIBPCAP
capture_callback_add(main_capture_callback, NULL);
#endif
cf_callback_add(statusbar_cf_callback, NULL);
#ifdef HAVE_LIBPCAP
capture_callback_add(statusbar_capture_callback, NULL);
#endif
cf_callback_add(welcome_cf_callback, NULL);
#ifdef HAVE_LIBPCAP
capture_callback_add(welcome_capture_callback, NULL);
#endif
set_console_log_handler();
#ifdef HAVE_LIBPCAP
capture_opts_init(&global_capture_opts);
capture_session_init(&global_capture_session, &cfile);
#endif
init_report_message(vfailure_alert_box, vwarning_alert_box,
open_failure_alert_box, read_failure_alert_box,
write_failure_alert_box);
filter = get_conn_cfilter();
if ( *filter != '\0' ) {
info_update_freq = 1000;
}
splash_win = splash_new("Loading Wireshark ...");
if (init_progfile_dir_error != NULL) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Can't get pathname of directory containing Wireshark: %s.\n"
"It won't be possible to capture traffic.\n"
"Report this to the Wireshark developers.",
init_progfile_dir_error);
g_free(init_progfile_dir_error);
}
wtap_init();
#ifdef HAVE_PLUGINS
epan_register_plugin_types();
codec_register_plugin_types();
scan_plugins(REPORT_LOAD_FAILURE);
register_all_wiretap_modules();
#endif
register_all_codecs();
splash_update(RA_DISSECTORS, NULL, (gpointer)splash_win);
if (!epan_init(register_all_protocols,register_all_protocol_handoffs,
splash_update, (gpointer) splash_win)) {
ret = INIT_FAILED;
goto clean_exit;
}
splash_update(RA_LISTENERS, NULL, (gpointer)splash_win);
#ifdef HAVE_PLUGINS
register_all_plugin_tap_listeners();
#endif
register_all_tap_listeners();
conversation_table_set_gui_info(init_conversation_table);
hostlist_table_set_gui_info(init_hostlist_table);
srt_table_iterate_tables(register_service_response_tables, NULL);
rtd_table_iterate_tables(register_response_time_delay_tables, NULL);
new_stat_tap_iterate_tables(register_simple_stat_tables, NULL);
#ifdef HAVE_EXTCAP
splash_update(RA_EXTCAP, NULL, (gpointer)splash_win);
extcap_register_preferences();
#endif
splash_update(RA_PREFERENCES, NULL, (gpointer)splash_win);
global_commandline_info.prefs_p = read_configuration_files();
cap_file_init(&cfile);
prefs_to_capture_opts();
commandline_other_options(argc, argv, TRUE);
#ifdef HAVE_LIBPCAP
splash_update(RA_INTERFACES, NULL, (gpointer)splash_win);
fill_in_local_interfaces(main_window_update);
if (global_commandline_info.start_capture || global_commandline_info.list_link_layer_types) {
ret = capture_opts_default_iface_if_necessary(&global_capture_opts,
((global_commandline_info.prefs_p->capture_device) && (*global_commandline_info.prefs_p->capture_device != '\0')) ? get_if_name(global_commandline_info.prefs_p->capture_device) : NULL);
if (ret != 0) {
goto clean_exit;
}
}
if (global_commandline_info.list_link_layer_types) {
if_capabilities_t *caps;
guint i;
interface_t device;
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (device.selected) {
gchar* auth_str = NULL;
#ifdef HAVE_PCAP_REMOTE
if (device.remote_opts.remote_host_opts.auth_type == CAPTURE_AUTH_PWD) {
auth_str = g_strdup_printf("%s:%s", device.remote_opts.remote_host_opts.auth_username,
device.remote_opts.remote_host_opts.auth_password);
}
#endif
#if defined(HAVE_PCAP_CREATE)
caps = capture_get_if_capabilities(device.name, device.monitor_mode_supported, auth_str, &err_str, main_window_update);
#else
caps = capture_get_if_capabilities(device.name, FALSE, auth_str, &err_str,main_window_update);
#endif
g_free(auth_str);
if (caps == NULL) {
cmdarg_err("%s", err_str);
g_free(err_str);
ret = INVALID_CAPABILITY;
goto clean_exit;
}
if (caps->data_link_types == NULL) {
cmdarg_err("The capture device \"%s\" has no data link types.", device.name);
ret = INVALID_LINK_TYPE;
goto clean_exit;
}
#ifdef _WIN32
create_console();
#endif
#if defined(HAVE_PCAP_CREATE)
capture_opts_print_if_capabilities(caps, device.name, device.monitor_mode_supported);
#else
capture_opts_print_if_capabilities(caps, device.name, FALSE);
#endif
#ifdef _WIN32
destroy_console();
#endif
free_if_capabilities(caps);
}
}
ret = EXIT_SUCCESS;
goto clean_exit;
}
capture_opts_trim_snaplen(&global_capture_opts, MIN_PACKET_SIZE);
capture_opts_trim_ring_num_files(&global_capture_opts);
#endif
prefs_apply_all();
#ifdef HAVE_LIBPCAP
if ((global_capture_opts.num_selected == 0) &&
((prefs.capture_device != NULL) &&
(global_commandline_info.prefs_p != NULL) &&
(*global_commandline_info.prefs_p->capture_device != '\0'))) {
guint i;
interface_t device;
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (!device.hidden && strstr(prefs.capture_device, device.name) != NULL) {
device.selected = TRUE;
global_capture_opts.num_selected++;
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, i);
g_array_insert_val(global_capture_opts.all_ifaces, i, device);
break;
}
}
}
if (global_capture_opts.num_selected == 0 && global_capture_opts.all_ifaces->len == 1) {
interface_t device = g_array_index(global_capture_opts.all_ifaces, interface_t, 0);
device.selected = TRUE;
global_capture_opts.num_selected++;
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, 0);
g_array_insert_val(global_capture_opts.all_ifaces, 0, device);
}
#endif
if (!setup_enabled_and_disabled_protocols()) {
ret = INVALID_OPTION;
goto clean_exit;
}
build_column_format_array(&cfile.cinfo, global_commandline_info.prefs_p->num_cols, TRUE);
rc_file = get_datafile_path(RC_FILE);
#if GTK_CHECK_VERSION(3,0,0)
#else
gtk_rc_parse(rc_file);
g_free(rc_file);
rc_file = get_persconffile_path(RC_FILE, FALSE);
gtk_rc_parse(rc_file);
#endif
g_free(rc_file);
font_init();
macros_init();
stock_icons_init();
splash_destroy(splash_win);
create_main_window(pl_size, tv_size, bv_size, global_commandline_info.prefs_p);
if (!recent_read_dynamic(&rf_path, &rf_open_errno)) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open recent file\n\"%s\": %s.",
rf_path, g_strerror(rf_open_errno));
g_free(rf_path);
}
packet_list_enable_color(recent.packet_list_colorize);
main_widgets_rearrange();
menu_recent_read_finished();
#ifdef HAVE_LIBPCAP
main_auto_scroll_live_changed(auto_scroll_live);
#endif
switch (user_font_apply()) {
case FA_SUCCESS:
break;
case FA_ZOOMED_TOO_FAR:
recent.gui_zoom_level = 0;
break;
case FA_FONT_NOT_AVAILABLE:
default:
recent.gui_zoom_level = 0;
break;
}
dnd_init(top_level);
if (!color_filters_init(&err_msg, color_filter_add_cb)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_msg);
g_free(err_msg);
}
#ifdef HAVE_LIBPCAP
capture_filter_init();
#endif
main_load_window_geometry(top_level);
g_timeout_add(info_update_freq, resolv_update_cb, NULL);
tap_update_timer_id = g_timeout_add(global_commandline_info.prefs_p->tap_update_interval, tap_update_cb, NULL);
if (global_commandline_info.cf_name) {
show_main_window(TRUE);
check_and_warn_user_startup(global_commandline_info.cf_name);
if (global_commandline_info.rfilter != NULL) {
if (!dfilter_compile(global_commandline_info.rfilter, &rfcode, &err_msg)) {
bad_dfilter_alert_box(top_level, global_commandline_info.rfilter, err_msg);
g_free(err_msg);
rfilter_parse_failed = TRUE;
}
}
if (ex_opt_count("read_format") > 0) {
in_file_type = open_info_name_to_type(ex_opt_get_next("read_format"));
}
if (!rfilter_parse_failed) {
if (cf_open(&cfile, global_commandline_info.cf_name, in_file_type, FALSE, &err) == CF_OK) {
cfile.rfcode = rfcode;
start_requested_stats();
switch (cf_read(&cfile, FALSE)) {
case CF_READ_OK:
case CF_READ_ERROR:
if(global_commandline_info.go_to_packet != 0) {
cf_goto_frame(&cfile, global_commandline_info.go_to_packet);
} else if (global_commandline_info.jfilter != NULL) {
if (!dfilter_compile(global_commandline_info.jfilter, &jump_to_filter, &err_msg)) {
bad_dfilter_alert_box(top_level, global_commandline_info.jfilter, err_msg);
g_free(err_msg);
} else {
cf_find_packet_dfilter(&cfile, jump_to_filter, global_commandline_info.jump_backwards);
}
}
break;
case CF_READ_ABORTED:
exit(0);
break;
}
if (!g_path_is_absolute(global_commandline_info.cf_name)) {
char *old_cf_name = global_commandline_info.cf_name;
char *pwd = g_get_current_dir();
global_commandline_info.cf_name = g_strdup_printf("%s%s%s", pwd, G_DIR_SEPARATOR_S, global_commandline_info.cf_name);
g_free(old_cf_name);
g_free(pwd);
}
s = get_dirname(global_commandline_info.cf_name);
set_last_open_dir(s);
g_free(global_commandline_info.cf_name);
global_commandline_info.cf_name = NULL;
} else {
if (rfcode != NULL)
dfilter_free(rfcode);
cfile.rfcode = NULL;
show_main_window(FALSE);
main_set_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
}
}
} else {
#ifdef HAVE_LIBPCAP
if (global_commandline_info.start_capture) {
if (global_capture_opts.save_file != NULL) {
s = g_strdup(global_capture_opts.save_file);
set_last_open_dir(get_dirname(s));
g_free(s);
}
show_main_window(FALSE);
check_and_warn_user_startup(global_commandline_info.cf_name);
if (global_capture_opts.ifaces->len == 0)
collect_ifaces(&global_capture_opts);
if (capture_start(&global_capture_opts, &global_capture_session, &global_info_data,main_window_update)) {
start_requested_stats();
}
} else {
show_main_window(FALSE);
check_and_warn_user_startup(global_commandline_info.cf_name);
main_set_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
}
if (!global_commandline_info.start_capture && !global_capture_opts.default_options.cfilter) {
global_capture_opts.default_options.cfilter = g_strdup(get_conn_cfilter());
}
#else
show_main_window(FALSE);
check_and_warn_user_startup(global_commandline_info.cf_name);
main_set_for_capture_in_progress(FALSE);
set_capture_if_dialog_for_capture_in_progress(FALSE);
#endif
}
if (global_commandline_info.dfilter) {
GtkWidget *filter_te;
filter_te = gtk_bin_get_child(GTK_BIN(g_object_get_data(G_OBJECT(top_level), E_DFILTER_CM_KEY)));
gtk_entry_set_text(GTK_ENTRY(filter_te), global_commandline_info.dfilter);
main_filter_packets(&cfile, global_commandline_info.dfilter, FALSE);
}
profile_store_persconffiles (FALSE);
#ifdef HAVE_GTKOSXAPPLICATION
theApp = (GtkosxApplication *)g_object_new(GTKOSX_TYPE_APPLICATION, NULL);
#ifdef HAVE_GDK_GRESOURCE
gtkosx_application_set_dock_icon_pixbuf(theApp, ws_gdk_pixbuf_new_from_resource("/org/wireshark/image/wsicon64.png"));
#else
gtkosx_application_set_dock_icon_pixbuf(theApp, gdk_pixbuf_new_from_inline(-1, wsicon_64_pb_data, FALSE, NULL));
#endif
gtkosx_application_ready(theApp);
#endif
g_log(LOG_DOMAIN_MAIN, G_LOG_LEVEL_INFO, "Wireshark is up and ready to go");
#ifdef HAVE_LIBPCAP
gtk_iface_mon_start();
#endif
software_update_init();
gtk_main();
#ifdef HAVE_LIBPCAP
gtk_iface_mon_stop();
#endif
epan_cleanup();
#ifdef HAVE_EXTCAP
extcap_cleanup();
#endif
AirPDcapDestroyContext(&airpdcap_ctx);
#ifdef HAVE_GTKOSXAPPLICATION
g_object_unref(theApp);
#endif
#ifdef _WIN32
if (G_IS_OBJECT(top_level))
gtk_widget_hide(top_level);
software_update_cleanup();
WSACleanup();
destroy_console();
#endif
#ifdef HAVE_GDK_GRESOURCE
main_unregister_resource();
#endif
clean_exit:
#ifdef HAVE_LIBPCAP
capture_opts_cleanup(&global_capture_opts);
#endif
col_cleanup(&cfile.cinfo);
free_filter_lists();
wtap_cleanup();
free_progdirs();
#ifdef HAVE_PLUGINS
plugins_cleanup();
#endif
return ret;
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
set_has_console(FALSE);
set_console_wait(FALSE);
return main (__argc, __argv);
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
g_object_ref(G_OBJECT(wireless_tb));
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
gtk_box_pack_start(GTK_BOX(main_vbox), wireless_tb, FALSE, TRUE, 1);
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
gtk_box_pack_start(GTK_BOX(main_vbox), main_first_pane, TRUE, TRUE, 0);
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
gboolean *is_visible = ( gboolean *)data;
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
if (recent.wireless_toolbar_show) {
gtk_widget_show(wireless_tb);
} else {
gtk_widget_hide(wireless_tb);
}
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
packet_list_next();
return TRUE;
} else if (event->keyval == GDK_F7) {
packet_list_prev();
return TRUE;
} else if (event->state & NO_SHIFT_MOD_MASK) {
return FALSE;
} else if (event->keyval < 256 && g_ascii_isprint(event->keyval)) {
if (main_display_filter_widget && !gtk_widget_is_focus(main_display_filter_widget)) {
gtk_window_set_focus(GTK_WINDOW(top_level), main_display_filter_widget);
gtk_editable_set_position(GTK_EDITABLE(main_display_filter_widget), -1);
}
return FALSE;
}
return FALSE;
}
static void
create_main_window (gint pl_size, gint tv_size, gint bv_size, e_prefs *prefs_p
#if !defined(HAVE_IGE_MAC_INTEGRATION) && !defined (HAVE_GTKOSXAPPLICATION)
_U_
#endif
)
{
GtkAccelGroup *accel;
top_level = window_new(GTK_WINDOW_TOPLEVEL, "");
set_titlebar_for_capture_file(NULL);
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
} else {
gtk_widget_hide(menubar);
}
#endif
main_tb = toolbar_new();
gtk_widget_show (main_tb);
filter_tb = filter_toolbar_new();
pkt_scrollw = packet_list_create();
gtk_widget_set_size_request(pkt_scrollw, -1, pl_size);
gtk_widget_show_all(pkt_scrollw);
tv_scrollw = proto_tree_view_new(&tree_view_gbl);
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
wireless_tb = airpcap_toolbar_new();
#else
wireless_tb = ws80211_toolbar_new();
#endif
gtk_widget_show(wireless_tb);
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
airpcap_toolbar_show(wireless_tb);
#endif
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
char *rf_path;
int rf_open_errno;
gchar* err_msg = NULL;
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
prefs_reset();
menu_prefs_reset();
proto_reenable_all();
(void) read_configuration_files();
if (!recent_read_profile_static(&rf_path, &rf_open_errno)) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not open common recent file\n\"%s\": %s.",
rf_path, g_strerror(rf_open_errno));
g_free(rf_path);
}
if (recent.gui_fileopen_remembered_dir &&
test_for_directory(recent.gui_fileopen_remembered_dir) == EISDIR) {
set_last_open_dir(recent.gui_fileopen_remembered_dir);
}
timestamp_set_type (recent.gui_time_format);
timestamp_set_seconds_type (recent.gui_seconds_format);
packet_list_enable_color(recent.packet_list_colorize);
prefs_to_capture_opts();
prefs_apply_all();
#ifdef HAVE_LIBPCAP
update_local_interfaces();
#endif
macros_post_update();
main_titlebar_update();
filter_expression_reinit(FILTER_EXPRESSION_REINIT_CREATE);
toolbar_redraw_all();
if (!color_filters_reload(&err_msg, color_filter_add_cb)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_msg);
g_free(err_msg);
}
welcome_if_panel_reload();
packet_list_recreate ();
cfile.columns_changed = FALSE;
user_font_apply();
menu_recent_read_finished();
main_pane_load_window_geometry();
}
void
main_fields_changed (void)
{
gchar* err_msg = NULL;
if (!color_filters_reload(&err_msg, color_filter_add_cb)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_msg);
g_free(err_msg);
}
filter_te_syntax_check_cb(main_display_filter_widget, NULL);
if (cfile.dfilter) {
dfilter_t *dfp = NULL;
if (!dfilter_compile(cfile.dfilter, &dfp, NULL)) {
g_signal_emit_by_name(G_OBJECT(main_display_filter_widget), "changed");
g_free(cfile.dfilter);
cfile.dfilter = NULL;
}
dfilter_free(dfp);
}
if (have_custom_cols(&cfile.cinfo)) {
packet_list_recreate();
} else if (cfile.state != FILE_CLOSED) {
redissect_packets();
}
destroy_packet_wins();
proto_free_deregistered_fields();
}
void redissect_packets(void)
{
cf_redissect_packets(&cfile);
status_expert_update();
}
int software_update_can_shutdown_callback(void) {
return FALSE;
}
void software_update_shutdown_request_callback(void) {
}
