static gboolean
higher_priority_status_level(int level)
{
int i;
for (i = level + 1; i < NUM_STATUS_LEVELS; i++) {
if (status_levels[i])
return TRUE;
}
return FALSE;
}
static void
statusbar_push_file_msg(const gchar *msg_format, ...)
{
va_list ap;
gchar *msg;
if (higher_priority_status_level(STATUS_LEVEL_FILE))
return;
status_levels[STATUS_LEVEL_FILE]++;
va_start(ap, msg_format);
msg = g_strdup_vprintf(msg_format, ap);
va_end(ap);
gtk_statusbar_push(GTK_STATUSBAR(info_bar), file_ctx, msg);
g_free(msg);
}
static void
statusbar_pop_file_msg(void)
{
if (status_levels[STATUS_LEVEL_FILE] > 0) {
status_levels[STATUS_LEVEL_FILE]--;
}
gtk_statusbar_pop(GTK_STATUSBAR(info_bar), file_ctx);
}
void
statusbar_push_field_msg(const gchar *msg_format, ...)
{
va_list ap;
gchar *msg;
if (higher_priority_status_level(STATUS_LEVEL_HELP))
return;
status_levels[STATUS_LEVEL_HELP]++;
va_start(ap, msg_format);
msg = g_strdup_vprintf(msg_format, ap);
va_end(ap);
gtk_statusbar_push(GTK_STATUSBAR(info_bar), help_ctx, msg);
g_free(msg);
}
void
statusbar_pop_field_msg(void)
{
if (status_levels[STATUS_LEVEL_HELP] > 0) {
status_levels[STATUS_LEVEL_HELP]--;
}
gtk_statusbar_pop(GTK_STATUSBAR(info_bar), help_ctx);
}
void
statusbar_push_filter_msg(const gchar *msg_format, ...)
{
va_list ap;
gchar *msg;
if (higher_priority_status_level(STATUS_LEVEL_FILTER))
return;
status_levels[STATUS_LEVEL_FILTER]++;
va_start(ap, msg_format);
msg = g_strdup_vprintf(msg_format, ap);
va_end(ap);
gtk_statusbar_push(GTK_STATUSBAR(info_bar), filter_ctx, msg);
g_free(msg);
}
void
statusbar_pop_filter_msg(void)
{
if (status_levels[STATUS_LEVEL_FILTER] > 0) {
status_levels[STATUS_LEVEL_FILTER]--;
}
gtk_statusbar_pop(GTK_STATUSBAR(info_bar), filter_ctx);
}
static gboolean
statusbar_remove_temporary_msg(gpointer data)
{
guint msg_id = GPOINTER_TO_UINT(data);
gtk_statusbar_remove(GTK_STATUSBAR(info_bar), main_ctx, msg_id);
return FALSE;
}
static gboolean
statusbar_flash_temporary_msg(gpointer data _U_)
{
gboolean retval = TRUE;
if (flash_time > 0) {
flash_highlight = !flash_highlight;
} else {
flash_highlight = FALSE;
retval = FALSE;
}
if (flash_highlight) {
gtk_drag_highlight(info_bar);
} else {
gtk_drag_unhighlight(info_bar);
}
flash_time -= TEMPORARY_FLASH_INTERVAL;
return retval;
}
void
statusbar_push_temporary_msg(const gchar *msg_format, ...)
{
va_list ap;
gchar *msg;
guint msg_id;
va_start(ap, msg_format);
msg = g_strdup_vprintf(msg_format, ap);
va_end(ap);
msg_id = gtk_statusbar_push(GTK_STATUSBAR(info_bar), main_ctx, msg);
g_free(msg);
flash_time = TEMPORARY_FLASH_TIMEOUT - 1;
g_timeout_add(TEMPORARY_FLASH_INTERVAL, statusbar_flash_temporary_msg, NULL);
g_timeout_add(TEMPORARY_MSG_TIMEOUT, statusbar_remove_temporary_msg, GUINT_TO_POINTER(msg_id));
}
GtkWidget *
statusbar_new(void)
{
GtkWidget *status_hbox;
status_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(status_hbox), 0);
info_bar_new();
packets_bar_new();
profile_bar_new();
status_expert_new();
status_capture_comment_new();
status_pane_left = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
gtk_widget_show(status_pane_left);
status_pane_right = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
gtk_widget_show(status_pane_right);
return status_hbox;
}
void
statusbar_load_window_geometry(void)
{
if (recent.has_gui_geometry_status_pane && recent.gui_geometry_status_pane_left)
gtk_paned_set_position(GTK_PANED(status_pane_left), recent.gui_geometry_status_pane_left);
if (recent.has_gui_geometry_status_pane && recent.gui_geometry_status_pane_right)
gtk_paned_set_position(GTK_PANED(status_pane_right), recent.gui_geometry_status_pane_right);
}
void
statusbar_save_window_geometry(void)
{
recent.gui_geometry_status_pane_left = gtk_paned_get_position(GTK_PANED(status_pane_left));
recent.gui_geometry_status_pane_right = gtk_paned_get_position(GTK_PANED(status_pane_right));
}
static void
foreach_remove_a_child(GtkWidget *widget, gpointer data) {
gtk_container_remove(GTK_CONTAINER(data), widget);
}
void
statusbar_widgets_emptying(GtkWidget *statusbar)
{
g_object_ref(G_OBJECT(info_bar));
g_object_ref(G_OBJECT(info_bar_event));
g_object_ref(G_OBJECT(packets_bar));
g_object_ref(G_OBJECT(profile_bar));
g_object_ref(G_OBJECT(profile_bar_event));
g_object_ref(G_OBJECT(status_pane_left));
g_object_ref(G_OBJECT(status_pane_right));
g_object_ref(G_OBJECT(expert_info_error));
g_object_ref(G_OBJECT(expert_info_warn));
g_object_ref(G_OBJECT(expert_info_note));
g_object_ref(G_OBJECT(expert_info_chat));
g_object_ref(G_OBJECT(expert_info_comment));
g_object_ref(G_OBJECT(expert_info_none));
g_object_ref(G_OBJECT(capture_comment));
g_object_ref(G_OBJECT(capture_comment_none));
gtk_container_foreach(GTK_CONTAINER(statusbar), foreach_remove_a_child, statusbar);
gtk_container_foreach(GTK_CONTAINER(status_pane_left), foreach_remove_a_child, status_pane_left);
gtk_container_foreach(GTK_CONTAINER(status_pane_right), foreach_remove_a_child, status_pane_right);
}
void
statusbar_widgets_pack(GtkWidget *statusbar)
{
gtk_box_pack_start(GTK_BOX(statusbar), expert_info_error, FALSE, FALSE, 2);
gtk_box_pack_start(GTK_BOX(statusbar), expert_info_warn, FALSE, FALSE, 2);
gtk_box_pack_start(GTK_BOX(statusbar), expert_info_note, FALSE, FALSE, 2);
gtk_box_pack_start(GTK_BOX(statusbar), expert_info_chat, FALSE, FALSE, 2);
gtk_box_pack_start(GTK_BOX(statusbar), expert_info_comment, FALSE, FALSE, 2);
gtk_box_pack_start(GTK_BOX(statusbar), expert_info_none, FALSE, FALSE, 2);
gtk_box_pack_start(GTK_BOX(statusbar), capture_comment, FALSE, FALSE, 2);
gtk_box_pack_start(GTK_BOX(statusbar), capture_comment_none, FALSE, FALSE, 2);
gtk_box_pack_start(GTK_BOX(statusbar), status_pane_left, TRUE, TRUE, 0);
gtk_paned_pack1(GTK_PANED(status_pane_left), info_bar_event, FALSE, FALSE);
gtk_paned_pack2(GTK_PANED(status_pane_left), status_pane_right, TRUE, FALSE);
gtk_paned_pack1(GTK_PANED(status_pane_right), packets_bar, TRUE, FALSE);
gtk_paned_pack2(GTK_PANED(status_pane_right), profile_bar_event, FALSE, FALSE);
}
void
statusbar_widgets_show_or_hide(GtkWidget *statusbar)
{
if ((recent.filter_toolbar_show && prefs.filter_toolbar_show_in_statusbar) ||
recent.statusbar_show) {
gtk_widget_show(statusbar);
} else {
gtk_widget_hide(statusbar);
}
if (recent.statusbar_show) {
gtk_widget_show(status_pane_left);
} else {
gtk_widget_hide(status_pane_left);
}
}
static void
info_bar_new(void)
{
info_bar_event = gtk_event_box_new();
info_bar = gtk_statusbar_new();
gtk_container_add(GTK_CONTAINER(info_bar_event), info_bar);
main_ctx = gtk_statusbar_get_context_id(GTK_STATUSBAR(info_bar), "main");
file_ctx = gtk_statusbar_get_context_id(GTK_STATUSBAR(info_bar), "file");
help_ctx = gtk_statusbar_get_context_id(GTK_STATUSBAR(info_bar), "help");
filter_ctx = gtk_statusbar_get_context_id(GTK_STATUSBAR(info_bar), "filter");
#if !GTK_CHECK_VERSION(3,0,0)
gtk_statusbar_set_has_resize_grip(GTK_STATUSBAR(info_bar), FALSE);
#endif
gtk_statusbar_push(GTK_STATUSBAR(info_bar), main_ctx, DEF_READY_MESSAGE);
memset(status_levels, 0, sizeof(status_levels));
gtk_widget_show(info_bar);
gtk_widget_show(info_bar_event);
}
static void
packets_bar_new(void)
{
packets_bar = gtk_statusbar_new();
packets_ctx = gtk_statusbar_get_context_id(GTK_STATUSBAR(packets_bar), "packets");
packets_bar_update();
#if !GTK_CHECK_VERSION(3,0,0)
gtk_statusbar_set_has_resize_grip(GTK_STATUSBAR(packets_bar), FALSE);
#endif
gtk_widget_show(packets_bar);
}
static void
profile_bar_new(void)
{
profile_bar_event = gtk_event_box_new();
profile_bar = gtk_statusbar_new();
gtk_container_add(GTK_CONTAINER(profile_bar_event), profile_bar);
g_signal_connect(profile_bar_event, "button_press_event", G_CALLBACK(profile_show_popup_cb), NULL);
g_signal_connect(profile_bar_event, "button_press_event", G_CALLBACK(popup_menu_handler),
g_object_get_data(G_OBJECT(popup_menu_object), PM_STATUSBAR_PROFILES_KEY));
profile_ctx = gtk_statusbar_get_context_id(GTK_STATUSBAR(profile_bar), "profile");
gtk_widget_set_tooltip_text(profile_bar_event, "Click to change configuration profile");
profile_bar_update();
#if !GTK_CHECK_VERSION(3,0,0)
gtk_statusbar_set_has_resize_grip(GTK_STATUSBAR(profile_bar), FALSE);
#endif
gtk_widget_show(profile_bar);
gtk_widget_show(profile_bar_event);
}
void
packets_bar_update(void)
{
if(packets_bar) {
if(packets_str) {
gtk_statusbar_pop(GTK_STATUSBAR(packets_bar), packets_ctx);
} else {
packets_str = g_string_new ("");
}
if(cfile.count) {
g_string_printf(packets_str, " Packets: %u " UTF8_MIDDLE_DOT
" Displayed: %u (%.1f%%) ",
cfile.count,
cfile.displayed_count,
(100.0 * cfile.displayed_count)/cfile.count);
if(cfile.marked_count) {
g_string_append_printf(packets_str, " " UTF8_MIDDLE_DOT " Marked: %u (%.1f%%)",
cfile.marked_count, (100.0 * cfile.marked_count)/cfile.count);
}
if(cfile.drops_known) {
g_string_append_printf(packets_str, " " UTF8_MIDDLE_DOT " Dropped: %u (%.1f%%)",
cfile.drops, (100.0 * cfile.drops)/cfile.count);
}
if(cfile.ignored_count) {
g_string_append_printf(packets_str, " " UTF8_MIDDLE_DOT " Ignored: %u (%.1f%%)",
cfile.ignored_count, (100.0 * cfile.ignored_count)/cfile.count);
}
if(!cfile.is_tempfile){
gulong computed_elapsed = cf_get_computed_elapsed();
g_string_append_printf(packets_str, " " UTF8_MIDDLE_DOT " Load time: %lu:%02lu.%03lu",
computed_elapsed/60000,
computed_elapsed%60000/1000,
computed_elapsed%1000);
}
} else {
g_string_printf(packets_str, " No Packets");
}
gtk_statusbar_push(GTK_STATUSBAR(packets_bar), packets_ctx, packets_str->str);
}
}
void
profile_bar_update(void)
{
if (profile_bar) {
if(profile_str) {
g_free(profile_str);
gtk_statusbar_pop(GTK_STATUSBAR(profile_bar), profile_ctx);
}
profile_str = g_strdup_printf (" Profile: %s", get_profile_name ());
gtk_statusbar_push(GTK_STATUSBAR(profile_bar), profile_ctx, profile_str);
set_menus_for_profiles(is_default_profile());
}
}
static gboolean
expert_comp_dlg_event_cb(GtkWidget *w _U_, GdkEventButton *event _U_, gpointer user_data _U_)
{
expert_comp_dlg_launch();
return TRUE;
}
static gboolean
edit_capture_comment_dlg_event_cb(GtkWidget *w _U_, GdkEventButton *event _U_, gpointer user_data _U_)
{
edit_capture_comment_dlg_launch();
return TRUE;
}
static void
status_expert_new(void)
{
GtkWidget *expert_image;
expert_image = pixbuf_to_widget(expert_error_pb_data);
gtk_widget_set_tooltip_text(expert_image, "ERROR is the highest expert info level");
gtk_widget_show(expert_image);
expert_info_error = gtk_event_box_new();
gtk_container_add(GTK_CONTAINER(expert_info_error), expert_image);
g_signal_connect(expert_info_error, "button_press_event", G_CALLBACK(expert_comp_dlg_event_cb), NULL);
expert_image = pixbuf_to_widget(expert_warn_pb_data);
gtk_widget_set_tooltip_text(expert_image, "WARNING is the highest expert info level");
gtk_widget_show(expert_image);
expert_info_warn = gtk_event_box_new();
gtk_container_add(GTK_CONTAINER(expert_info_warn), expert_image);
g_signal_connect(expert_info_warn, "button_press_event", G_CALLBACK(expert_comp_dlg_event_cb), NULL);
expert_image = pixbuf_to_widget(expert_note_pb_data);
gtk_widget_set_tooltip_text(expert_image, "NOTE is the highest expert info level");
gtk_widget_show(expert_image);
expert_info_note = gtk_event_box_new();
gtk_container_add(GTK_CONTAINER(expert_info_note), expert_image);
g_signal_connect(expert_info_note, "button_press_event", G_CALLBACK(expert_comp_dlg_event_cb), NULL);
expert_image = pixbuf_to_widget(expert_chat_pb_data);
gtk_widget_set_tooltip_text(expert_image, "CHAT is the highest expert info level");
gtk_widget_show(expert_image);
expert_info_chat = gtk_event_box_new();
gtk_container_add(GTK_CONTAINER(expert_info_chat), expert_image);
g_signal_connect(expert_info_chat, "button_press_event", G_CALLBACK(expert_comp_dlg_event_cb), NULL);
expert_image = gtk_image_new_from_stock(GTK_STOCK_YES, GTK_ICON_SIZE_MENU);
gtk_widget_set_tooltip_text(expert_image, "COMMENT is the highest expert info level");
gtk_widget_show(expert_image);
expert_info_comment = gtk_event_box_new();
gtk_container_add(GTK_CONTAINER(expert_info_comment), expert_image);
g_signal_connect(expert_info_comment, "button_press_event", G_CALLBACK(expert_comp_dlg_event_cb), NULL);
expert_image = pixbuf_to_widget(expert_none_pb_data);
gtk_widget_set_tooltip_text(expert_image, "No expert info");
gtk_widget_show(expert_image);
expert_info_none = gtk_event_box_new();
gtk_container_add(GTK_CONTAINER(expert_info_none), expert_image);
g_signal_connect(expert_info_none, "button_press_event", G_CALLBACK(expert_comp_dlg_event_cb), NULL);
}
static void
status_expert_hide(void)
{
gtk_widget_hide(expert_info_error);
gtk_widget_hide(expert_info_warn);
gtk_widget_hide(expert_info_note);
gtk_widget_hide(expert_info_chat);
gtk_widget_hide(expert_info_comment);
gtk_widget_hide(expert_info_none);
}
void
status_expert_update(void)
{
status_expert_hide();
switch(expert_get_highest_severity()) {
case(PI_ERROR):
gtk_widget_show(expert_info_error);
break;
case(PI_WARN):
gtk_widget_show(expert_info_warn);
break;
case(PI_NOTE):
gtk_widget_show(expert_info_note);
break;
case(PI_CHAT):
gtk_widget_show(expert_info_chat);
break;
case(PI_COMMENT):
gtk_widget_show(expert_info_comment);
break;
default:
gtk_widget_show(expert_info_none);
break;
}
}
static void
status_capture_comment_new(void)
{
GtkWidget *comment_image;
comment_image = pixbuf_to_widget(capture_comment_update_pb_data);
gtk_widget_set_tooltip_text(comment_image, "Read or edit the comment for this capture file");
gtk_widget_show(comment_image);
capture_comment = gtk_event_box_new();
gtk_container_add(GTK_CONTAINER(capture_comment), comment_image);
g_signal_connect(capture_comment, "button_press_event", G_CALLBACK(edit_capture_comment_dlg_event_cb), NULL);
comment_image = pixbuf_to_widget(capture_comment_add_pb_data);
gtk_widget_set_tooltip_text(comment_image, "Add a comment to this capture file");
gtk_widget_show(comment_image);
capture_comment_none = gtk_event_box_new();
gtk_container_add(GTK_CONTAINER(capture_comment_none), comment_image);
g_signal_connect(capture_comment_none, "button_press_event", G_CALLBACK(edit_capture_comment_dlg_event_cb), NULL);
}
static void
status_capture_comment_hide(void)
{
edit_capture_comment_dlg_hide();
gtk_widget_hide(capture_comment);
gtk_widget_hide(capture_comment_none);
}
void
status_capture_comment_update(void)
{
const gchar *comment_str;
status_capture_comment_hide();
comment_str = cf_read_shb_comment(&cfile);
if(comment_str!=NULL && *comment_str!=0x0){
gtk_widget_show(capture_comment);
}else{
gtk_widget_show(capture_comment_none);
}
}
static void
statusbar_set_filename(const char *file_name, gint64 file_length, nstime_t *file_elapsed_time)
{
gchar *size_str;
status_expert_update();
size_str = format_size(file_length, (format_size_flags_e)(format_size_unit_bytes|format_size_prefix_si));
statusbar_push_file_msg(" File: \"%s\" %s %02lu:%02lu:%02lu",
(file_name) ? file_name : "", size_str,
(long)file_elapsed_time->secs/3600,
(long)file_elapsed_time->secs%3600/60,
(long)file_elapsed_time->secs%60);
g_free(size_str);
}
static void
statusbar_cf_file_closing_cb(capture_file *cf _U_)
{
statusbar_pop_file_msg();
status_expert_hide();
gtk_widget_show(expert_info_none);
}
static void
statusbar_cf_file_closed_cb(capture_file *cf _U_)
{
packets_bar_update();
status_capture_comment_hide();
status_expert_hide();
}
static void
statusbar_cf_file_read_started_cb(capture_file *cf, const char *action)
{
gchar *name_ptr;
statusbar_pop_file_msg();
name_ptr = g_filename_display_basename(cf->filename);
statusbar_push_file_msg(" %s: %s", action, name_ptr);
g_free(name_ptr);
}
static void
statusbar_cf_file_read_finished_cb(capture_file *cf)
{
statusbar_pop_file_msg();
statusbar_set_filename(cf->filename, cf->f_datalen, &(cf->elapsed_time));
status_capture_comment_update();
}
static void
statusbar_capture_prepared_cb(capture_session *cap_session _U_)
{
static const gchar msg[] = " Waiting for capture input data ...";
statusbar_push_file_msg(msg);
welcome_header_push_msg(msg);
}
static void
statusbar_capture_update_started_cb(capture_session *cap_session)
{
capture_options *capture_opts = cap_session->capture_opts;
GString *interface_names;
statusbar_pop_file_msg();
welcome_header_pop_msg();
interface_names = statusbar_get_interface_names(capture_opts);
statusbar_push_file_msg("%s<live capture in progress> to file: %s",
interface_names->str,
(capture_opts->save_file) ? capture_opts->save_file : "");
g_string_free(interface_names, TRUE);
status_capture_comment_update();
}
static void
statusbar_capture_update_continue_cb(capture_session *cap_session)
{
GString *interface_names;
capture_options *capture_opts = cap_session->capture_opts;
capture_file *cf = (capture_file *)cap_session->cf;
status_expert_update();
statusbar_pop_file_msg();
interface_names = statusbar_get_interface_names(capture_opts);
if (cf->f_datalen/1024/1024 > 10) {
statusbar_push_file_msg("%s<live capture in progress> File: %s %" G_GINT64_MODIFIER "d MB",
interface_names->str,
capture_opts->save_file,
cf->f_datalen/1024/1024);
} else if (cf->f_datalen/1024 > 10) {
statusbar_push_file_msg("%s<live capture in progress> File: %s %" G_GINT64_MODIFIER "d KB",
interface_names->str,
capture_opts->save_file,
cf->f_datalen/1024);
} else {
statusbar_push_file_msg("%s<live capture in progress> File: %s %" G_GINT64_MODIFIER "d Bytes",
interface_names->str,
capture_opts->save_file,
cf->f_datalen);
}
g_string_free(interface_names, TRUE);
}
static void
statusbar_capture_update_finished_cb(capture_session *cap_session)
{
capture_file *cf = (capture_file *)cap_session->cf;
statusbar_pop_file_msg();
statusbar_set_filename(cf->filename, cf->f_datalen, &(cf->elapsed_time));
packets_bar_update();
}
static void
statusbar_capture_fixed_started_cb(capture_session *cap_session)
{
capture_options *capture_opts = cap_session->capture_opts;
GString *interface_names;
statusbar_pop_file_msg();
interface_names = statusbar_get_interface_names(capture_opts);
statusbar_push_file_msg("%s<live capture in progress> to file: %s",
interface_names->str,
(capture_opts->save_file) ? capture_opts->save_file : "");
gtk_statusbar_push(GTK_STATUSBAR(packets_bar), packets_ctx, " Packets: 0");
g_string_free(interface_names, TRUE);
}
static void
statusbar_capture_fixed_continue_cb(capture_session *cap_session)
{
capture_file *cf = (capture_file *)cap_session->cf;
gchar *capture_msg;
gtk_statusbar_pop(GTK_STATUSBAR(packets_bar), packets_ctx);
capture_msg = g_strdup_printf(" Packets: %u", cf_get_packet_count(cf));
gtk_statusbar_push(GTK_STATUSBAR(packets_bar), packets_ctx, capture_msg);
g_free(capture_msg);
}
static void
statusbar_capture_fixed_finished_cb(capture_session *cap_session _U_)
{
#if 0
capture_file *cf = (capture_file *)cap_session->cf;
#endif
statusbar_pop_file_msg();
welcome_header_pop_msg();
gtk_statusbar_pop(GTK_STATUSBAR(packets_bar), packets_ctx);
}
static void
statusbar_capture_failed_cb(capture_session *cap_session _U_)
{
#if 0
capture_file *cf = (capture_file *)cap_session->cf;
#endif
statusbar_pop_file_msg();
welcome_header_pop_msg();
gtk_statusbar_pop(GTK_STATUSBAR(packets_bar), packets_ctx);
}
static void
statusbar_cf_field_unselected_cb(capture_file *cf _U_)
{
statusbar_pop_field_msg();
}
static void
statusbar_cf_file_save_started_cb(gchar *filename)
{
statusbar_pop_file_msg();
statusbar_push_file_msg(" Saving: %s...", g_filename_display_basename(filename));
}
static void
statusbar_cf_file_save_finished_cb(gpointer data _U_)
{
statusbar_pop_file_msg();
}
static void
statusbar_cf_file_save_failed_cb(gpointer data _U_)
{
statusbar_pop_file_msg();
}
static void
statusbar_cf_file_save_stopped_cb(gpointer data _U_)
{
statusbar_pop_file_msg();
}
static void
statusbar_cf_file_export_specified_packets_started_cb(gchar *filename)
{
statusbar_pop_file_msg();
statusbar_push_file_msg(" Exporting to: %s...", g_filename_display_basename(filename));
}
static void
statusbar_cf_file_export_specified_packets_finished_cb(gpointer data _U_)
{
statusbar_pop_file_msg();
}
static void
statusbar_cf_file_export_specified_packets_failed_cb(gpointer data _U_)
{
statusbar_pop_file_msg();
}
static void
statusbar_cf_file_export_specified_packets_stopped_cb(gpointer data _U_)
{
statusbar_pop_file_msg();
}
void
statusbar_cf_callback(gint event, gpointer data, gpointer user_data _U_)
{
switch(event) {
case(cf_cb_file_opened):
break;
case(cf_cb_file_closing):
statusbar_cf_file_closing_cb((capture_file *)data);
break;
case(cf_cb_file_closed):
statusbar_cf_file_closed_cb((capture_file *)data);
break;
case(cf_cb_file_read_started):
statusbar_cf_file_read_started_cb((capture_file *)data, "Loading");
break;
case(cf_cb_file_read_finished):
statusbar_cf_file_read_finished_cb((capture_file *)data);
break;
case(cf_cb_file_reload_started):
statusbar_cf_file_read_started_cb((capture_file *)data, "Reloading");
break;
case(cf_cb_file_reload_finished):
statusbar_cf_file_read_finished_cb((capture_file *)data);
break;
case(cf_cb_file_rescan_started):
statusbar_cf_file_read_started_cb((capture_file *)data, "Rescanning");
break;
case(cf_cb_file_rescan_finished):
statusbar_cf_file_read_finished_cb((capture_file *)data);
break;
case(cf_cb_file_fast_save_finished):
break;
case(cf_cb_packet_selected):
break;
case(cf_cb_packet_unselected):
break;
case(cf_cb_field_unselected):
statusbar_cf_field_unselected_cb((capture_file *)data);
break;
case(cf_cb_file_save_started):
statusbar_cf_file_save_started_cb((gchar *)data);
break;
case(cf_cb_file_save_finished):
statusbar_cf_file_save_finished_cb(data);
break;
case(cf_cb_file_save_failed):
statusbar_cf_file_save_failed_cb(data);
break;
case(cf_cb_file_save_stopped):
statusbar_cf_file_save_stopped_cb(data);
break;
case(cf_cb_file_export_specified_packets_started):
statusbar_cf_file_export_specified_packets_started_cb((gchar *)data);
break;
case(cf_cb_file_export_specified_packets_finished):
statusbar_cf_file_export_specified_packets_finished_cb(data);
break;
case(cf_cb_file_export_specified_packets_failed):
statusbar_cf_file_export_specified_packets_failed_cb(data);
break;
case(cf_cb_file_export_specified_packets_stopped):
statusbar_cf_file_export_specified_packets_stopped_cb(data);
break;
default:
g_warning("statusbar_cf_callback: event %u unknown", event);
g_assert_not_reached();
}
}
void
statusbar_capture_callback(gint event, capture_session *cap_session,
gpointer user_data _U_)
{
switch(event) {
case(capture_cb_capture_prepared):
statusbar_capture_prepared_cb(cap_session);
break;
case(capture_cb_capture_update_started):
statusbar_capture_update_started_cb(cap_session);
break;
case(capture_cb_capture_update_continue):
statusbar_capture_update_continue_cb(cap_session);
break;
case(capture_cb_capture_update_finished):
statusbar_capture_update_finished_cb(cap_session);
break;
case(capture_cb_capture_fixed_started):
statusbar_capture_fixed_started_cb(cap_session);
break;
case(capture_cb_capture_fixed_continue):
statusbar_capture_fixed_continue_cb(cap_session);
break;
case(capture_cb_capture_fixed_finished):
statusbar_capture_fixed_finished_cb(cap_session);
break;
case(capture_cb_capture_stopping):
break;
case(capture_cb_capture_failed):
statusbar_capture_failed_cb(cap_session);
break;
default:
g_warning("statusbar_capture_callback: event %u unknown", event);
g_assert_not_reached();
}
}
