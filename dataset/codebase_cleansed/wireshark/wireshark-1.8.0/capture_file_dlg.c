static wtap *
preview_set_filename(GtkWidget *prev, const gchar *cf_name)
{
GtkWidget *label;
gchar *display_basename;
wtap *wth;
int err = 0;
gchar *err_info;
gchar string_buff[PREVIEW_STR_MAX];
gint64 filesize;
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_FILENAME_KEY);
gtk_label_set_text(GTK_LABEL(label), "-");
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_FORMAT_KEY);
gtk_label_set_text(GTK_LABEL(label), "-");
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_SIZE_KEY);
gtk_label_set_text(GTK_LABEL(label), "-");
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_ELAPSED_KEY);
gtk_label_set_text(GTK_LABEL(label), "-");
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_PACKETS_KEY);
gtk_label_set_text(GTK_LABEL(label), "-");
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_FIRST_KEY);
gtk_label_set_text(GTK_LABEL(label), "-");
if(!cf_name) {
return NULL;
}
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_FILENAME_KEY);
display_basename = g_filename_display_basename(cf_name);
gtk_label_set_text(GTK_LABEL(label), display_basename);
g_free(display_basename);
if (test_for_directory(cf_name) == EISDIR) {
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_FORMAT_KEY);
gtk_label_set_text(GTK_LABEL(label), "directory");
return NULL;
}
wth = wtap_open_offline(cf_name, &err, &err_info, TRUE);
if (wth == NULL) {
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_FORMAT_KEY);
if(err == WTAP_ERR_FILE_UNKNOWN_FORMAT) {
gtk_label_set_text(GTK_LABEL(label), "unknown file format");
} else {
gtk_label_set_text(GTK_LABEL(label), "error opening file");
}
return NULL;
}
filesize = wtap_file_size(wth, &err);
if (filesize == -1) {
gtk_label_set_text(GTK_LABEL(label), "error getting file size");
wtap_close(wth);
return NULL;
}
g_snprintf(string_buff, PREVIEW_STR_MAX, "%" G_GINT64_MODIFIER "d bytes", filesize);
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_SIZE_KEY);
gtk_label_set_text(GTK_LABEL(label), string_buff);
g_strlcpy(string_buff, wtap_file_type_string(wtap_file_type(wth)), PREVIEW_STR_MAX);
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_FORMAT_KEY);
gtk_label_set_text(GTK_LABEL(label), string_buff);
return wth;
}
static void
preview_do(GtkWidget *prev, wtap *wth)
{
GtkWidget *label;
unsigned int elapsed_time;
time_t time_preview;
time_t time_current;
int err = 0;
gchar *err_info;
gint64 data_offset;
const struct wtap_pkthdr *phdr;
double start_time = 0;
double stop_time = 0;
double cur_time;
unsigned int packets = 0;
gboolean is_breaked = FALSE;
gchar string_buff[PREVIEW_STR_MAX];
time_t ti_time;
struct tm *ti_tm;
time(&time_preview);
while ( (wtap_read(wth, &err, &err_info, &data_offset)) ) {
phdr = wtap_phdr(wth);
cur_time = wtap_nstime_to_sec(&phdr->ts);
if(packets == 0) {
start_time = cur_time;
stop_time = cur_time;
}
if (cur_time < start_time) {
start_time = cur_time;
}
if (cur_time > stop_time){
stop_time = cur_time;
}
packets++;
if(packets%1000 == 0) {
time(&time_current);
if(time_current-time_preview >= (time_t) prefs.gui_fileopen_preview) {
is_breaked = TRUE;
break;
}
}
}
if(err != 0) {
g_snprintf(string_buff, PREVIEW_STR_MAX, "error after reading %u packets", packets);
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_PACKETS_KEY);
gtk_label_set_text(GTK_LABEL(label), string_buff);
wtap_close(wth);
return;
}
if(is_breaked) {
g_snprintf(string_buff, PREVIEW_STR_MAX, "more than %u packets (preview timeout)", packets);
} else {
g_snprintf(string_buff, PREVIEW_STR_MAX, "%u", packets);
}
label = g_object_get_data(G_OBJECT(prev), PREVIEW_PACKETS_KEY);
gtk_label_set_text(GTK_LABEL(label), string_buff);
ti_time = (long)start_time;
ti_tm = localtime( &ti_time );
if(ti_tm) {
g_snprintf(string_buff, PREVIEW_STR_MAX,
"%04d-%02d-%02d %02d:%02d:%02d",
ti_tm->tm_year + 1900,
ti_tm->tm_mon + 1,
ti_tm->tm_mday,
ti_tm->tm_hour,
ti_tm->tm_min,
ti_tm->tm_sec);
} else {
g_snprintf(string_buff, PREVIEW_STR_MAX, "?");
}
label = g_object_get_data(G_OBJECT(prev), PREVIEW_FIRST_KEY);
gtk_label_set_text(GTK_LABEL(label), string_buff);
elapsed_time = (unsigned int)(stop_time-start_time);
if(elapsed_time/86400) {
g_snprintf(string_buff, PREVIEW_STR_MAX, "%02u days %02u:%02u:%02u",
elapsed_time/86400, elapsed_time%86400/3600, elapsed_time%3600/60, elapsed_time%60);
} else {
g_snprintf(string_buff, PREVIEW_STR_MAX, "%02u:%02u:%02u",
elapsed_time%86400/3600, elapsed_time%3600/60, elapsed_time%60);
}
if(is_breaked) {
g_snprintf(string_buff, PREVIEW_STR_MAX, "unknown");
}
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_ELAPSED_KEY);
gtk_label_set_text(GTK_LABEL(label), string_buff);
wtap_close(wth);
}
static void
file_open_entry_changed(GtkWidget *w _U_, gpointer file_sel)
{
GtkWidget *prev = (GtkWidget *)g_object_get_data(G_OBJECT(file_sel), PREVIEW_TABLE_KEY);
gchar *cf_name;
gboolean have_preview;
wtap *wth;
cf_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_sel));
wth = preview_set_filename(prev, cf_name);
have_preview = (wth != NULL);
g_free(cf_name);
gtk_widget_set_sensitive(prev, have_preview);
#if 0
gtk_dialog_set_response_sensitive(file_sel, GTK_RESPONSE_ACCEPT, have_preview);
#endif
if(have_preview)
preview_do(prev, wth);
}
static GtkWidget *
add_string_to_table_sensitive(GtkWidget *list, guint *row, const gchar *title, const gchar *value, gboolean sensitive)
{
GtkWidget *label;
gchar *indent;
if(strlen(value) != 0) {
indent = g_strdup_printf(" %s", title);
} else {
indent = g_strdup(title);
}
label = gtk_label_new(indent);
g_free(indent);
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
gtk_widget_set_sensitive(label, sensitive);
gtk_table_attach_defaults(GTK_TABLE(list), label, 0, 1, *row, *row+1);
label = gtk_label_new(value);
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
gtk_widget_set_sensitive(label, sensitive);
gtk_table_attach_defaults(GTK_TABLE(list), label, 1, 2, *row, *row+1);
*row = *row + 1;
return label;
}
static GtkWidget *
add_string_to_table(GtkWidget *list, guint *row, const gchar *title, const gchar *value)
{
return add_string_to_table_sensitive(list, row, title, value, TRUE);
}
static GtkWidget *
preview_new(void)
{
GtkWidget *table, *label;
guint row;
table = gtk_table_new(1, 2, FALSE);
gtk_table_set_col_spacings(GTK_TABLE(table), 6);
gtk_table_set_row_spacings(GTK_TABLE(table), 3);
row = 0;
label = add_string_to_table(table, &row, "Filename:", "-");
gtk_widget_set_size_request(label, DEF_WIDTH/3, -1);
g_object_set_data(G_OBJECT(table), PREVIEW_FILENAME_KEY, label);
label = add_string_to_table(table, &row, "Format:", "-");
g_object_set_data(G_OBJECT(table), PREVIEW_FORMAT_KEY, label);
label = add_string_to_table(table, &row, "Size:", "-");
g_object_set_data(G_OBJECT(table), PREVIEW_SIZE_KEY, label);
label = add_string_to_table(table, &row, "Packets:", "-");
g_object_set_data(G_OBJECT(table), PREVIEW_PACKETS_KEY, label);
label = add_string_to_table(table, &row, "First Packet:", "-");
g_object_set_data(G_OBJECT(table), PREVIEW_FIRST_KEY, label);
label = add_string_to_table(table, &row, "Elapsed time:", "-");
g_object_set_data(G_OBJECT(table), PREVIEW_ELAPSED_KEY, label);
return table;
}
static void
file_open_cmd(GtkWidget *w)
{
#if _WIN32
win32_open_file(GDK_WINDOW_HWND(gtk_widget_get_window(top_level)));
#else
GtkWidget *file_open_w;
GtkWidget *main_hb, *main_vb, *filter_hbox, *filter_bt, *filter_te,
*m_resolv_cb, *n_resolv_cb, *t_resolv_cb, *prev;
static construct_args_t args = {
"Wireshark: Read Filter",
FALSE,
FALSE,
TRUE
};
gchar *cf_name, *s;
const gchar *rfilter;
dfilter_t *rfcode = NULL;
int err;
file_open_w = file_selection_new("Wireshark: Open Capture File",
FILE_SELECTION_OPEN);
gtk_widget_set_size_request(file_open_w, DEF_WIDTH, DEF_HEIGHT);
switch (prefs.gui_fileopen_style) {
case FO_STYLE_LAST_OPENED:
break;
case FO_STYLE_SPECIFIED:
if (prefs.gui_fileopen_dir[0] != '\0')
file_selection_set_current_folder(file_open_w, prefs.gui_fileopen_dir);
break;
}
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
file_selection_set_extra_widget(file_open_w, main_hb);
gtk_widget_show(main_hb);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_box_pack_start(GTK_BOX(main_hb), main_vb, FALSE, FALSE, 0);
gtk_widget_show(main_vb);
filter_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(filter_hbox), 0);
gtk_box_pack_start(GTK_BOX(main_vb), filter_hbox, FALSE, FALSE, 0);
gtk_widget_show(filter_hbox);
filter_bt = gtk_button_new_from_stock(WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY);
g_signal_connect(filter_bt, "clicked",
G_CALLBACK(display_filter_construct_cb), &args);
g_signal_connect(filter_bt, "destroy",
G_CALLBACK(filter_button_destroy_cb), NULL);
gtk_box_pack_start(GTK_BOX(filter_hbox), filter_bt, FALSE, TRUE, 0);
gtk_widget_show(filter_bt);
gtk_widget_set_tooltip_text(filter_bt, "Open the \"Display Filter\" dialog, to edit/apply filters");
filter_te = gtk_entry_new();
g_object_set_data(G_OBJECT(filter_bt), E_FILT_TE_PTR_KEY, filter_te);
gtk_box_pack_start(GTK_BOX(filter_hbox), filter_te, TRUE, TRUE, 3);
g_signal_connect(filter_te, "changed",
G_CALLBACK(filter_te_syntax_check_cb), NULL);
g_object_set_data(G_OBJECT(filter_hbox), E_FILT_AUTOCOMP_PTR_KEY, NULL);
g_signal_connect(filter_te, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
g_signal_connect(file_open_w, "key-press-event", G_CALLBACK (filter_parent_dlg_key_pressed_cb), NULL);
colorize_filter_te_as_empty(filter_te);
gtk_widget_show(filter_te);
gtk_widget_set_tooltip_text(filter_te, "Enter a display filter.");
g_object_set_data(G_OBJECT(file_open_w), E_RFILTER_TE_KEY, filter_te);
m_resolv_cb = gtk_check_button_new_with_mnemonic("Enable _MAC name resolution");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(m_resolv_cb),
gbl_resolv_flags & RESOLV_MAC);
gtk_box_pack_start(GTK_BOX(main_vb), m_resolv_cb, FALSE, FALSE, 0);
gtk_widget_show(m_resolv_cb);
n_resolv_cb = gtk_check_button_new_with_mnemonic("Enable _network name resolution");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(n_resolv_cb),
gbl_resolv_flags & RESOLV_NETWORK);
gtk_box_pack_start(GTK_BOX(main_vb), n_resolv_cb, FALSE, FALSE, 0);
gtk_widget_show(n_resolv_cb);
t_resolv_cb = gtk_check_button_new_with_mnemonic("Enable _transport name resolution");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(t_resolv_cb),
gbl_resolv_flags & RESOLV_TRANSPORT);
gtk_box_pack_start(GTK_BOX(main_vb), t_resolv_cb, FALSE, FALSE, 0);
gtk_widget_show(t_resolv_cb);
prev = preview_new();
g_object_set_data(G_OBJECT(file_open_w), PREVIEW_TABLE_KEY, prev);
gtk_widget_show_all(prev);
gtk_box_pack_start(GTK_BOX(main_hb), prev, TRUE, TRUE, 0);
g_signal_connect(GTK_FILE_CHOOSER(file_open_w), "selection-changed",
G_CALLBACK(file_open_entry_changed), file_open_w);
file_open_entry_changed(file_open_w, file_open_w);
g_object_set_data(G_OBJECT(file_open_w), E_DFILTER_TE_KEY,
g_object_get_data(G_OBJECT(w), E_DFILTER_TE_KEY));
for (;;) {
if (gtk_dialog_run(GTK_DIALOG(file_open_w)) != GTK_RESPONSE_ACCEPT) {
window_destroy(file_open_w);
return;
}
cf_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_open_w));
if (test_for_directory(cf_name) == EISDIR) {
set_last_open_dir(cf_name);
g_free(cf_name);
file_selection_set_current_folder(file_open_w, get_last_open_dir());
continue;
}
rfilter = gtk_entry_get_text(GTK_ENTRY(filter_te));
if (!dfilter_compile(rfilter, &rfcode)) {
bad_dfilter_alert_box(file_open_w, rfilter);
g_free(cf_name);
continue;
}
if (cf_open(&cfile, cf_name, FALSE, &err) != CF_OK) {
if (rfcode != NULL)
dfilter_free(rfcode);
g_free(cf_name);
continue;
}
cfile.rfcode = rfcode;
gbl_resolv_flags = prefs.name_resolve;
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(m_resolv_cb)))
gbl_resolv_flags |= RESOLV_MAC;
else
gbl_resolv_flags &= ~RESOLV_MAC;
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(n_resolv_cb)))
gbl_resolv_flags |= RESOLV_NETWORK;
else
gbl_resolv_flags &= ~RESOLV_NETWORK;
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(t_resolv_cb)))
gbl_resolv_flags |= RESOLV_TRANSPORT;
else
gbl_resolv_flags &= ~RESOLV_TRANSPORT;
window_destroy(GTK_WIDGET(file_open_w));
switch (cf_read(&cfile, FALSE)) {
case CF_READ_OK:
case CF_READ_ERROR:
break;
case CF_READ_ABORTED:
g_free(cf_name);
return;
}
s = get_dirname(cf_name);
set_last_open_dir(s);
g_free(cf_name);
return;
}
#endif
}
void
file_open_cmd_cb(GtkWidget *widget, gpointer data _U_) {
if (do_file_close(&cfile, FALSE, " before opening a new capture file"))
file_open_cmd(widget);
}
static void
file_merge_cmd(GtkWidget *w)
{
#if _WIN32
win32_merge_file(GDK_WINDOW_HWND(gtk_widget_get_window(top_level)));
new_packet_list_freeze();
new_packet_list_thaw();
#else
GtkWidget *file_merge_w;
GtkWidget *main_hb, *main_vb, *ft_hb, *ft_lb, *ft_combo_box, *filter_hbox,
*filter_bt, *filter_te, *prepend_rb, *chrono_rb,
*append_rb, *prev;
static construct_args_t args = {
"Wireshark: Read Filter",
FALSE,
FALSE,
TRUE
};
gchar *cf_name, *s;
const gchar *rfilter;
dfilter_t *rfcode = NULL;
gpointer ptr;
int file_type;
int err;
cf_status_t merge_status;
char *in_filenames[2];
char *tmpname;
file_merge_w = file_selection_new("Wireshark: Merge with Capture File",
FILE_SELECTION_OPEN);
gtk_widget_set_size_request(file_merge_w, DEF_WIDTH, DEF_HEIGHT);
switch (prefs.gui_fileopen_style) {
case FO_STYLE_LAST_OPENED:
break;
case FO_STYLE_SPECIFIED:
if (prefs.gui_fileopen_dir[0] != '\0')
file_selection_set_current_folder(file_merge_w, prefs.gui_fileopen_dir);
break;
}
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
file_selection_set_extra_widget(file_merge_w, main_hb);
gtk_widget_show(main_hb);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_box_pack_start(GTK_BOX(main_hb), main_vb, FALSE, FALSE, 0);
gtk_widget_show(main_vb);
ft_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(main_vb), ft_hb);
gtk_widget_show(ft_hb);
ft_lb = gtk_label_new("Merged output file type:");
gtk_box_pack_start(GTK_BOX(ft_hb), ft_lb, FALSE, FALSE, 0);
gtk_widget_show(ft_lb);
ft_combo_box = ws_combo_box_new_text_and_pointer();
set_file_type_list(ft_combo_box, &cfile, FALSE);
gtk_box_pack_start(GTK_BOX(ft_hb), ft_combo_box, FALSE, FALSE, 0);
gtk_widget_show(ft_combo_box);
g_object_set_data(G_OBJECT(file_merge_w), E_FILE_TYPE_COMBO_BOX_KEY, ft_combo_box);
ws_combo_box_set_active(GTK_COMBO_BOX(ft_combo_box), 0);
filter_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(filter_hbox), 0);
gtk_box_pack_start(GTK_BOX(main_vb), filter_hbox, FALSE, FALSE, 0);
gtk_widget_show(filter_hbox);
filter_bt = gtk_button_new_from_stock(WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY);
g_signal_connect(filter_bt, "clicked",
G_CALLBACK(display_filter_construct_cb), &args);
g_signal_connect(filter_bt, "destroy",
G_CALLBACK(filter_button_destroy_cb), NULL);
gtk_box_pack_start(GTK_BOX(filter_hbox), filter_bt, FALSE, TRUE, 0);
gtk_widget_show(filter_bt);
gtk_widget_set_tooltip_text(filter_bt, "Open the \"Display Filter\" dialog, to edit/apply filters");
filter_te = gtk_entry_new();
g_object_set_data(G_OBJECT(filter_bt), E_FILT_TE_PTR_KEY, filter_te);
gtk_box_pack_start(GTK_BOX(filter_hbox), filter_te, TRUE, TRUE, 3);
g_signal_connect(filter_te, "changed",
G_CALLBACK(filter_te_syntax_check_cb), NULL);
g_object_set_data(G_OBJECT(filter_hbox), E_FILT_AUTOCOMP_PTR_KEY, NULL);
g_signal_connect(filter_te, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
g_signal_connect(file_merge_w, "key-press-event", G_CALLBACK (filter_parent_dlg_key_pressed_cb), NULL);
colorize_filter_te_as_empty(filter_te);
gtk_widget_show(filter_te);
gtk_widget_set_tooltip_text(filter_te, "Enter a display filter.");
g_object_set_data(G_OBJECT(file_merge_w), E_RFILTER_TE_KEY, filter_te);
prepend_rb = gtk_radio_button_new_with_mnemonic_from_widget(NULL,
"Prepend packets to existing file");
gtk_widget_set_tooltip_text(prepend_rb, "The resulting file contains the packets from the selected, followed by the packets from the currently loaded file, the packet timestamps will be ignored.");
gtk_box_pack_start(GTK_BOX(main_vb), prepend_rb, FALSE, FALSE, 0);
gtk_widget_show(prepend_rb);
chrono_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(prepend_rb), "Merge packets chronologically");
gtk_widget_set_tooltip_text(chrono_rb, "The resulting file contains all the packets from the currently loaded and the selected file, sorted by the packet timestamps.");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(chrono_rb), TRUE);
gtk_box_pack_start(GTK_BOX(main_vb), chrono_rb, FALSE, FALSE, 0);
gtk_widget_show(chrono_rb);
append_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(prepend_rb), "Append packets to existing file");
gtk_widget_set_tooltip_text(append_rb, "The resulting file contains the packets from the currently loaded, followed by the packets from the selected file, the packet timestamps will be ignored.");
gtk_box_pack_start(GTK_BOX(main_vb), append_rb, FALSE, FALSE, 0);
gtk_widget_show(append_rb);
prev = preview_new();
g_object_set_data(G_OBJECT(file_merge_w), PREVIEW_TABLE_KEY, prev);
gtk_widget_show_all(prev);
gtk_box_pack_start(GTK_BOX(main_hb), prev, TRUE, TRUE, 0);
g_signal_connect(GTK_FILE_CHOOSER(file_merge_w), "selection-changed",
G_CALLBACK(file_open_entry_changed), file_merge_w);
file_open_entry_changed(file_merge_w, file_merge_w);
g_object_set_data(G_OBJECT(file_merge_w), E_DFILTER_TE_KEY,
g_object_get_data(G_OBJECT(w), E_DFILTER_TE_KEY));
for (;;) {
if (gtk_dialog_run(GTK_DIALOG(file_merge_w)) != GTK_RESPONSE_ACCEPT) {
window_destroy(file_merge_w);
return;
}
cf_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_merge_w));
if (test_for_directory(cf_name) == EISDIR) {
set_last_open_dir(cf_name);
g_free(cf_name);
file_selection_set_current_folder(file_merge_w, get_last_open_dir());
continue;
}
rfilter = gtk_entry_get_text(GTK_ENTRY(filter_te));
if (!dfilter_compile(rfilter, &rfcode)) {
bad_dfilter_alert_box(file_merge_w, rfilter);
g_free(cf_name);
continue;
}
if (! ws_combo_box_get_active_pointer(GTK_COMBO_BOX(ft_combo_box), &ptr)) {
g_assert_not_reached();
}
file_type = GPOINTER_TO_INT(ptr);
tmpname = NULL;
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chrono_rb))) {
in_filenames[0] = cfile.filename;
in_filenames[1] = cf_name;
merge_status = cf_merge_files(&tmpname, 2, in_filenames, file_type, FALSE);
} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(prepend_rb))) {
in_filenames[0] = cf_name;
in_filenames[1] = cfile.filename;
merge_status = cf_merge_files(&tmpname, 2, in_filenames, file_type,
TRUE);
} else {
in_filenames[0] = cfile.filename;
in_filenames[1] = cf_name;
merge_status = cf_merge_files(&tmpname, 2, in_filenames, file_type,
TRUE);
}
g_free(cf_name);
if (merge_status != CF_OK) {
if (rfcode != NULL)
dfilter_free(rfcode);
g_free(tmpname);
continue;
}
cf_close(&cfile);
window_destroy(GTK_WIDGET(file_merge_w));
if (cf_open(&cfile, tmpname, TRUE , &err) != CF_OK) {
if (rfcode != NULL)
dfilter_free(rfcode);
g_free(tmpname);
return;
}
g_free(tmpname);
cfile.rfcode = rfcode;
switch (cf_read(&cfile, FALSE)) {
case CF_READ_OK:
case CF_READ_ERROR:
break;
case CF_READ_ABORTED:
return;
}
s = get_dirname(tmpname);
set_last_open_dir(s);
return;
}
#endif
}
void
file_merge_cmd_cb(GtkWidget *widget, gpointer data _U_) {
GtkWidget *msg_dialog;
gchar *display_basename;
gint response;
if (prefs.gui_ask_unsaved) {
if (cfile.is_tempfile || cfile.unsaved_changes) {
if (cfile.is_tempfile) {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"Do you want to save the captured packets before merging another capture file into it?");
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
"A temporary capture file can't be merged.");
} else {
display_basename = g_filename_display_basename(cfile.filename);
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"Do you want to save the changes you've made "
"to the capture file \"%s\" before merging another capture file into it?",
display_basename);
g_free(display_basename);
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
"The changes must be saved before the files are merged.");
}
#ifndef _WIN32
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT);
#else
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT);
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);
#endif
gtk_dialog_set_default_response(GTK_DIALOG(msg_dialog), GTK_RESPONSE_ACCEPT);
response = gtk_dialog_run(GTK_DIALOG(msg_dialog));
gtk_widget_destroy(msg_dialog);
switch (response) {
case GTK_RESPONSE_ACCEPT:
do_file_save(&cfile, FALSE);
break;
case GTK_RESPONSE_CANCEL:
case GTK_RESPONSE_NONE:
case GTK_RESPONSE_DELETE_EVENT:
default:
return;
}
}
}
file_merge_cmd(widget);
}
static void
do_capture_stop(capture_file *cf)
{
capture_stop_cb(NULL, NULL);
while (cf->state == FILE_READ_IN_PROGRESS)
gtk_main_iteration();
}
gboolean
do_file_close(capture_file *cf, gboolean from_quit, const char *before_what)
{
GtkWidget *msg_dialog;
gchar *display_basename;
gint response;
gboolean capture_in_progress;
if (cf->state == FILE_CLOSED)
return TRUE;
#ifdef HAVE_LIBPCAP
if (cf->state == FILE_READ_IN_PROGRESS) {
capture_in_progress = TRUE;
} else
#endif
capture_in_progress = FALSE;
if (prefs.gui_ask_unsaved) {
if (cf->is_tempfile || capture_in_progress || cf->unsaved_changes) {
if (cf->is_tempfile) {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
capture_in_progress ?
"Do you want to stop the capture and save the captured packets%s?" :
"Do you want to save the captured packets%s?",
before_what);
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
"Your captured packets will be lost if you don't save them.");
} else {
display_basename = g_filename_display_basename(cf->filename);
if (capture_in_progress) {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"Do you want to stop the capture and save the captured packets%s?",
before_what);
} else {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"Do you want to save the changes you've made "
"to the capture file \"%s\"%s?",
display_basename, before_what);
}
g_free(display_basename);
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
capture_in_progress ?
"Your captured packets will be lost if you don't save them." :
"Your changes will be lost if you don't save them.");
}
#ifndef _WIN32
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
(from_quit ?
(cf->state == FILE_READ_IN_PROGRESS ?
WIRESHARK_STOCK_STOP_QUIT_DONT_SAVE :
WIRESHARK_STOCK_QUIT_DONT_SAVE) :
(capture_in_progress ?
WIRESHARK_STOCK_STOP_DONT_SAVE :
WIRESHARK_STOCK_DONT_SAVE)),
GTK_RESPONSE_REJECT);
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
(capture_in_progress ?
WIRESHARK_STOCK_STOP_SAVE :
GTK_STOCK_SAVE),
GTK_RESPONSE_ACCEPT);
#else
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
(capture_in_progress ?
WIRESHARK_STOCK_STOP_SAVE :
GTK_STOCK_SAVE),
GTK_RESPONSE_ACCEPT);
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
(from_quit ?
(capture_in_progress ?
WIRESHARK_STOCK_STOP_QUIT_DONT_SAVE :
WIRESHARK_STOCK_QUIT_DONT_SAVE) :
(capture_in_progress ?
WIRESHARK_STOCK_STOP_DONT_SAVE :
WIRESHARK_STOCK_DONT_SAVE)),
GTK_RESPONSE_REJECT);
#endif
gtk_dialog_set_default_response(GTK_DIALOG(msg_dialog), GTK_RESPONSE_ACCEPT);
response = gtk_dialog_run(GTK_DIALOG(msg_dialog));
gtk_widget_destroy(msg_dialog);
switch (response) {
case GTK_RESPONSE_ACCEPT:
#ifdef HAVE_LIBPCAP
if (capture_in_progress)
do_capture_stop(cf);
#endif
do_file_save(cf, TRUE);
break;
case GTK_RESPONSE_REJECT:
#ifdef HAVE_LIBPCAP
if (capture_in_progress)
do_capture_stop(cf);
#endif
cf_close(cf);
break;
case GTK_RESPONSE_CANCEL:
case GTK_RESPONSE_NONE:
case GTK_RESPONSE_DELETE_EVENT:
default:
return FALSE;
break;
}
} else {
cf_close(cf);
}
} else {
#ifdef HAVE_LIBPCAP
if (capture_in_progress)
do_capture_stop(cf);
#endif
cf_close(cf);
}
return TRUE;
}
void
file_close_cmd_cb(GtkWidget *widget _U_, gpointer data _U_) {
do_file_close(&cfile, FALSE, "");
}
static check_savability_t
check_save_with_comments(capture_file *cf)
{
GtkWidget *msg_dialog;
gint response;
if (!cf_has_comments(cf)) {
return SAVE;
}
if (cf->cd_t == WTAP_FILE_PCAPNG) {
return SAVE;
}
if (wtap_dump_can_write_encaps(WTAP_FILE_PCAPNG, cf->linktypes)) {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"The capture has comments, but the file's format "
"doesn't support comments. Do you want to save the capture "
"in a format that supports comments, or discard the comments "
"and save in the file's format?");
#ifndef _WIN32
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
"Discard comments and save",
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
GTK_STOCK_CANCEL,
GTK_RESPONSE_CANCEL,
"Save in another format",
RESPONSE_SAVE_IN_ANOTHER_FORMAT,
NULL);
#else
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
"Save in another format",
RESPONSE_SAVE_IN_ANOTHER_FORMAT,
GTK_STOCK_CANCEL,
GTK_RESPONSE_CANCEL,
"Discard comments and save",
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
NULL);
#endif
gtk_dialog_set_default_response(GTK_DIALOG(msg_dialog),
RESPONSE_SAVE_IN_ANOTHER_FORMAT);
} else {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"The capture has comments, but no file format in which it "
"can be saved supports comments. Do you want to discard "
"the comments and save in the file's format?");
#ifndef _WIN32
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
"Discard comments and save",
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
GTK_STOCK_CANCEL,
GTK_RESPONSE_CANCEL,
NULL);
#else
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
GTK_STOCK_CANCEL,
GTK_RESPONSE_CANCEL,
"Discard comments and save",
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
NULL);
#endif
gtk_dialog_set_default_response(GTK_DIALOG(msg_dialog),
GTK_RESPONSE_CANCEL);
}
response = gtk_dialog_run(GTK_DIALOG(msg_dialog));
gtk_widget_destroy(msg_dialog);
switch (response) {
case RESPONSE_SAVE_IN_ANOTHER_FORMAT:
return SAVE_IN_ANOTHER_FORMAT;
case RESPONSE_DISCARD_COMMENTS_AND_SAVE:
return SAVE_WITHOUT_COMMENTS;
case GTK_RESPONSE_CANCEL:
case GTK_RESPONSE_NONE:
case GTK_RESPONSE_DELETE_EVENT:
default:
return CANCELLED;
}
}
static void
do_file_save(capture_file *cf, gboolean dont_reopen)
{
char *fname;
gboolean discard_comments;
cf_write_status_t status;
if (cf->is_tempfile) {
do_file_save_as(cf, FALSE, dont_reopen);
} else {
if (cf->unsaved_changes) {
switch (check_save_with_comments(cf)) {
case SAVE:
discard_comments = FALSE;
break;
case SAVE_WITHOUT_COMMENTS:
discard_comments = TRUE;
break;
case SAVE_IN_ANOTHER_FORMAT:
do_file_save_as(cf, TRUE, dont_reopen);
return;
case CANCELLED:
return;
default:
g_assert_not_reached();
return;
}
fname = g_strdup(cf->filename);
status = cf_save_packets(cf, fname, cf->cd_t, cf->iscompressed,
discard_comments, dont_reopen);
switch (status) {
case CF_WRITE_OK:
if (discard_comments)
new_packet_list_queue_draw();
break;
case CF_WRITE_ERROR:
break;
case CF_WRITE_ABORTED:
break;
}
g_free(fname);
}
}
}
void
file_save_cmd_cb(GtkWidget *w _U_, gpointer data _U_) {
do_file_save(&cfile, FALSE);
}
static void
set_file_type_list(GtkWidget *combo_box, capture_file *cf,
gboolean must_support_comments)
{
GArray *savable_file_types;
guint i;
int ft;
savable_file_types = wtap_get_savable_file_types(cf->cd_t, cf->linktypes);
if (savable_file_types != NULL) {
for (i = 0; i < savable_file_types->len; i++) {
ft = g_array_index(savable_file_types, int, i);
if (must_support_comments) {
if (ft != WTAP_FILE_PCAPNG)
continue;
}
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(combo_box),
wtap_file_type_string(ft),
GINT_TO_POINTER(ft));
}
g_array_free(savable_file_types, TRUE);
}
}
static void
file_select_file_type_cb(GtkWidget *w, gpointer parent_arg)
{
GtkWidget *parent = parent_arg;
int new_file_type;
gpointer ptr;
GtkWidget *compressed_cb;
compressed_cb = (GtkWidget *)g_object_get_data(G_OBJECT(parent), E_COMPRESSED_CB_KEY);
if (! ws_combo_box_get_active_pointer(GTK_COMBO_BOX(w), &ptr)) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(compressed_cb), FALSE);
gtk_widget_set_sensitive(compressed_cb, FALSE);
return;
}
new_file_type = GPOINTER_TO_INT(ptr);
if (!wtap_dump_can_compress(new_file_type)) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(compressed_cb), FALSE);
gtk_widget_set_sensitive(compressed_cb, FALSE);
} else
gtk_widget_set_sensitive(compressed_cb, TRUE);
}
static check_savability_t
check_save_as_with_comments(capture_file *cf, GtkWidget *file_chooser_w,
GtkWidget *ft_combo_box)
{
gpointer ptr;
int selected_file_type;
GtkWidget *msg_dialog;
gint response;
GtkWidget *compressed_cb;
gboolean compressed;
if (!cf_has_comments(cf)) {
return SAVE;
}
if (! ws_combo_box_get_active_pointer(GTK_COMBO_BOX(ft_combo_box), &ptr)) {
g_assert_not_reached();
}
selected_file_type = GPOINTER_TO_INT(ptr);
if (selected_file_type == WTAP_FILE_PCAPNG) {
return SAVE;
}
if (wtap_dump_can_write_encaps(WTAP_FILE_PCAPNG, cf->linktypes)) {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(file_chooser_w),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"The capture has comments, but the file format you chose "
"doesn't support comments. Do you want to save the capture "
"in a format that supports comments, or discard the comments "
"and save in the format you chose?");
#ifndef _WIN32
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
"Discard comments and save",
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
GTK_STOCK_CANCEL,
GTK_RESPONSE_CANCEL,
"Save in another format",
RESPONSE_SAVE_IN_ANOTHER_FORMAT,
NULL);
#else
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
"Save in another format",
RESPONSE_SAVE_IN_ANOTHER_FORMAT,
GTK_STOCK_CANCEL,
GTK_RESPONSE_CANCEL,
"Discard comments and save",
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
NULL);
#endif
gtk_dialog_set_default_response(GTK_DIALOG(msg_dialog),
RESPONSE_SAVE_IN_ANOTHER_FORMAT);
} else {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(file_chooser_w),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"The capture has comments, but no file format in which it "
"can be saved supports comments. Do you want to discard "
"the comments and save in the format you chose?");
#ifndef _WIN32
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
"Discard comments and save",
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
GTK_STOCK_CANCEL,
GTK_RESPONSE_CANCEL,
NULL);
#else
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
GTK_STOCK_CANCEL,
GTK_RESPONSE_CANCEL,
"Discard comments and save",
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
NULL);
#endif
gtk_dialog_set_default_response(GTK_DIALOG(msg_dialog),
GTK_RESPONSE_CANCEL);
}
response = gtk_dialog_run(GTK_DIALOG(msg_dialog));
gtk_widget_destroy(msg_dialog);
switch (response) {
case RESPONSE_SAVE_IN_ANOTHER_FORMAT:
compressed_cb = (GtkWidget *)g_object_get_data(G_OBJECT(file_chooser_w),
E_COMPRESSED_CB_KEY);
compressed = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(compressed_cb));
ws_combo_box_clear_text_and_pointer(GTK_COMBO_BOX(ft_combo_box));
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(ft_combo_box),
wtap_file_type_string(WTAP_FILE_PCAPNG),
GINT_TO_POINTER(WTAP_FILE_PCAPNG));
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(compressed_cb), compressed);
ws_combo_box_set_active(GTK_COMBO_BOX(ft_combo_box), 0);
return SAVE_IN_ANOTHER_FORMAT;
case RESPONSE_DISCARD_COMMENTS_AND_SAVE:
return SAVE_WITHOUT_COMMENTS;
case GTK_RESPONSE_CANCEL:
case GTK_RESPONSE_NONE:
case GTK_RESPONSE_DELETE_EVENT:
default:
return CANCELLED;
}
}
static void
do_file_save_as(capture_file *cf, gboolean must_support_comments,
gboolean dont_reopen)
{
#if _WIN32
win32_save_as_file(GDK_WINDOW_HWND(gtk_widget_get_window(top_level)));
#else
GtkWidget *file_save_as_w;
GtkWidget *main_vb, *ft_hb, *ft_lb, *ft_combo_box, *compressed_cb;
char *cf_name;
gboolean discard_comments;
file_save_as_w = file_selection_new("Wireshark: Save Capture File As",
FILE_SELECTION_SAVE);
gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(file_save_as_w),
TRUE);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
file_selection_set_extra_widget(file_save_as_w, main_vb);
gtk_widget_show(main_vb);
ft_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(main_vb), ft_hb);
gtk_widget_show(ft_hb);
ft_lb = gtk_label_new("File type:");
gtk_box_pack_start(GTK_BOX(ft_hb), ft_lb, FALSE, FALSE, 0);
gtk_widget_show(ft_lb);
ft_combo_box = ws_combo_box_new_text_and_pointer();
set_file_type_list(ft_combo_box, cf, must_support_comments);
gtk_box_pack_start(GTK_BOX(ft_hb), ft_combo_box, FALSE, FALSE, 0);
gtk_widget_show(ft_combo_box);
g_object_set_data(G_OBJECT(file_save_as_w), E_FILE_TYPE_COMBO_BOX_KEY, ft_combo_box);
compressed_cb = gtk_check_button_new_with_label("Compress with gzip");
gtk_container_add(GTK_CONTAINER(ft_hb), compressed_cb);
gtk_widget_show(compressed_cb);
g_object_set_data(G_OBJECT(file_save_as_w), E_COMPRESSED_CB_KEY, compressed_cb);
g_signal_connect(ft_combo_box, "changed", G_CALLBACK(file_select_file_type_cb), file_save_as_w);
ws_combo_box_set_active(GTK_COMBO_BOX(ft_combo_box), 0);
for (;;) {
if (gtk_dialog_run(GTK_DIALOG(file_save_as_w)) != GTK_RESPONSE_ACCEPT) {
window_destroy(file_save_as_w);
return;
}
cf_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_save_as_w));
if (test_for_directory(cf_name) == EISDIR) {
set_last_open_dir(cf_name);
g_free(cf_name);
file_selection_set_current_folder(file_save_as_w, get_last_open_dir());
continue;
}
switch (check_save_as_with_comments(cf, file_save_as_w, ft_combo_box)) {
case SAVE:
discard_comments = FALSE;
break;
case SAVE_WITHOUT_COMMENTS:
discard_comments = TRUE;
break;
case SAVE_IN_ANOTHER_FORMAT:
g_free(cf_name);
continue;
case CANCELLED:
window_destroy(file_save_as_w);
return;
}
if (!file_target_unwritable_ui(file_save_as_w, cf_name)) {
g_free(cf_name);
continue;
}
g_free(cf_name);
switch (file_save_as_cb(file_save_as_w, discard_comments, dont_reopen)) {
case CF_WRITE_OK:
if (discard_comments)
new_packet_list_queue_draw();
return;
case CF_WRITE_ERROR:
continue;
case CF_WRITE_ABORTED:
return;
}
}
#endif
}
void
file_save_as_cmd_cb(GtkWidget *w _U_, gpointer data _U_)
{
do_file_save_as(&cfile, FALSE, FALSE);
}
static cf_write_status_t
file_save_as_cb(GtkWidget *fs, gboolean discard_comments,
gboolean dont_reopen)
{
GtkWidget *ft_combo_box;
GtkWidget *compressed_cb;
gchar *cf_name;
gchar *dirname;
gpointer ptr;
int file_type;
gboolean compressed;
cf_write_status_t status;
gtk_widget_hide(fs);
cf_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fs));
compressed_cb = (GtkWidget *)g_object_get_data(G_OBJECT(fs), E_COMPRESSED_CB_KEY);
ft_combo_box = (GtkWidget *)g_object_get_data(G_OBJECT(fs), E_FILE_TYPE_COMBO_BOX_KEY);
if (! ws_combo_box_get_active_pointer(GTK_COMBO_BOX(ft_combo_box), &ptr)) {
g_assert_not_reached();
}
file_type = GPOINTER_TO_INT(ptr);
compressed = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(compressed_cb));
status = cf_save_packets(&cfile, cf_name, file_type, compressed,
discard_comments, dont_reopen);
switch (status) {
case CF_WRITE_OK:
window_destroy(fs);
dirname = get_dirname(cf_name);
set_last_open_dir(dirname);
break;
case CF_WRITE_ERROR:
break;
case CF_WRITE_ABORTED:
window_destroy(fs);
break;
}
g_free(cf_name);
return status;
}
void
file_export_specified_packets_cmd_cb(GtkWidget *widget _U_, gpointer data _U_)
{
#if _WIN32
win32_export_specified_packets_file(GDK_WINDOW_HWND(gtk_widget_get_window(top_level)));
#else
GtkWidget *file_export_specified_packets_w;
GtkWidget *main_vb, *ft_hb, *ft_lb, *ft_combo_box, *range_fr, *range_tb,
*compressed_cb;
packet_range_t range;
char *cf_name;
gchar *display_basename;
GtkWidget *msg_dialog;
packet_range_init(&range);
range.process_filtered = TRUE;
range.include_dependents = TRUE;
file_export_specified_packets_w = file_selection_new("Wireshark: Export Specified Packets",
FILE_SELECTION_SAVE);
gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(file_export_specified_packets_w),
TRUE);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
file_selection_set_extra_widget(file_export_specified_packets_w, main_vb);
gtk_widget_show(main_vb);
range_fr = gtk_frame_new("Packet Range");
gtk_box_pack_start(GTK_BOX(main_vb), range_fr, FALSE, FALSE, 0);
gtk_widget_show(range_fr);
range_tb = range_new(&range, TRUE);
gtk_container_add(GTK_CONTAINER(range_fr), range_tb);
gtk_widget_show(range_tb);
ft_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(main_vb), ft_hb);
gtk_widget_show(ft_hb);
ft_lb = gtk_label_new("File type:");
gtk_box_pack_start(GTK_BOX(ft_hb), ft_lb, FALSE, FALSE, 0);
gtk_widget_show(ft_lb);
ft_combo_box = ws_combo_box_new_text_and_pointer();
set_file_type_list(ft_combo_box, &cfile, FALSE);
gtk_box_pack_start(GTK_BOX(ft_hb), ft_combo_box, FALSE, FALSE, 0);
gtk_widget_show(ft_combo_box);
g_object_set_data(G_OBJECT(file_export_specified_packets_w), E_FILE_TYPE_COMBO_BOX_KEY, ft_combo_box);
range_update_dynamics(range_tb);
compressed_cb = gtk_check_button_new_with_label("Compress with gzip");
gtk_container_add(GTK_CONTAINER(ft_hb), compressed_cb);
gtk_widget_show(compressed_cb);
g_object_set_data(G_OBJECT(file_export_specified_packets_w), E_COMPRESSED_CB_KEY, compressed_cb);
g_signal_connect(ft_combo_box, "changed", G_CALLBACK(file_select_file_type_cb), file_export_specified_packets_w);
ws_combo_box_set_active(GTK_COMBO_BOX(ft_combo_box), 0);
for (;;) {
if (gtk_dialog_run(GTK_DIALOG(file_export_specified_packets_w)) != GTK_RESPONSE_ACCEPT) {
window_destroy(file_export_specified_packets_w);
return;
}
cf_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_export_specified_packets_w));
if (test_for_directory(cf_name) == EISDIR) {
set_last_open_dir(cf_name);
g_free(cf_name);
file_selection_set_current_folder(file_export_specified_packets_w, get_last_open_dir());
continue;
}
if (!range_check_validity_modal(file_export_specified_packets_w, &range)) {
g_free(cf_name);
continue;
}
if (files_identical(cfile.filename, cf_name)) {
display_basename = g_filename_display_basename(cf_name);
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(file_export_specified_packets_w),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_ERROR,
GTK_BUTTONS_OK,
"The file \"%s\" is the capture file from which you're exporting the packets.",
display_basename);
g_free(display_basename);
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
"You cannot export packets on top of the current capture file.");
gtk_dialog_run(GTK_DIALOG(msg_dialog));
gtk_widget_destroy(msg_dialog);
g_free(cf_name);
continue;
}
if (!file_target_unwritable_ui(file_export_specified_packets_w, cf_name)) {
g_free(cf_name);
continue;
}
g_free(cf_name);
switch (file_export_specified_packets_cb(file_export_specified_packets_w,
&range)) {
case CF_WRITE_OK:
return;
case CF_WRITE_ERROR:
continue;
case CF_WRITE_ABORTED:
return;
}
}
#endif
}
static cf_write_status_t
file_export_specified_packets_cb(GtkWidget *fs, packet_range_t *range)
{
GtkWidget *ft_combo_box;
GtkWidget *compressed_cb;
gchar *cf_name;
gchar *dirname;
gpointer ptr;
int file_type;
gboolean compressed;
cf_write_status_t status;
gtk_widget_hide(fs);
cf_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fs));
compressed_cb = (GtkWidget *)g_object_get_data(G_OBJECT(fs), E_COMPRESSED_CB_KEY);
ft_combo_box = (GtkWidget *)g_object_get_data(G_OBJECT(fs), E_FILE_TYPE_COMBO_BOX_KEY);
if (! ws_combo_box_get_active_pointer(GTK_COMBO_BOX(ft_combo_box), &ptr)) {
g_assert_not_reached();
}
file_type = GPOINTER_TO_INT(ptr);
compressed = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(compressed_cb));
status = cf_export_specified_packets(&cfile, cf_name, range, file_type,
compressed);
switch (status) {
case CF_WRITE_OK:
window_destroy(GTK_WIDGET(fs));
dirname = get_dirname(cf_name);
set_last_open_dir(dirname);
break;
case CF_WRITE_ERROR:
break;
case CF_WRITE_ABORTED:
window_destroy(fs);
break;
}
g_free(cf_name);
return status;
}
void
file_reload_cmd_cb(GtkWidget *w _U_, gpointer data _U_) {
cf_reload(&cfile);
}
static void
color_global_cb(GtkWidget *widget _U_, gpointer data)
{
GtkWidget *fs_widget = (GtkWidget *)data;
gchar *path;
path = get_datafile_path("colorfilters");
gtk_file_chooser_select_filename(GTK_FILE_CHOOSER(fs_widget), path);
g_free(path);
}
void
file_color_import_cmd_cb(GtkWidget *color_filters, gpointer filter_list _U_)
{
#if _WIN32
win32_import_color_file(GDK_WINDOW_HWND(gtk_widget_get_window(top_level)), color_filters);
#else
GtkWidget *main_vb, *cfglobal_but;
gchar *cf_name, *s;
file_color_import_w = file_selection_new("Wireshark: Import Color Filters",
FILE_SELECTION_OPEN);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
file_selection_set_extra_widget(file_color_import_w, main_vb);
gtk_widget_show(main_vb);
cfglobal_but = gtk_button_new_with_label("Global Color Filter File");
gtk_container_add(GTK_CONTAINER(main_vb), cfglobal_but);
g_signal_connect(cfglobal_but, "clicked",
G_CALLBACK(color_global_cb), file_color_import_w);
gtk_widget_show(cfglobal_but);
for (;;) {
if (gtk_dialog_run(GTK_DIALOG(file_color_import_w)) != GTK_RESPONSE_ACCEPT) {
window_destroy(file_color_import_w);
return;
}
cf_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_color_import_w));
if (test_for_directory(cf_name) == EISDIR) {
set_last_open_dir(cf_name);
g_free(cf_name);
file_selection_set_current_folder(file_color_import_w, get_last_open_dir());
continue;
}
if (!color_filters_import(cf_name, color_filters)) {
g_free(cf_name);
continue;
}
window_destroy(GTK_WIDGET(file_color_import_w));
s = get_dirname(cf_name);
set_last_open_dir(s);
g_free(cf_name);
return;
}
#endif
}
static void
color_set_export_selected_sensitive(GtkWidget * cfselect_cb)
{
if (color_selected_count() != 0)
gtk_widget_set_sensitive(cfselect_cb, TRUE);
else {
color_selected = FALSE;
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cfselect_cb), FALSE);
gtk_widget_set_sensitive(cfselect_cb, FALSE);
}
}
static void
color_toggle_selected_cb(GtkWidget *widget, gpointer data _U_)
{
color_selected = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget));
}
void
file_color_export_cmd_cb(GtkWidget *w _U_, gpointer filter_list)
{
#if _WIN32
win32_export_color_file(GDK_WINDOW_HWND(gtk_widget_get_window(top_level)), filter_list);
#else
GtkWidget *file_color_export_w;
GtkWidget *main_vb, *cfglobal_but;
GtkWidget *cfselect_cb;
gchar *cf_name;
gchar *dirname;
color_selected = FALSE;
file_color_export_w = file_selection_new("Wireshark: Export Color Filters",
FILE_SELECTION_SAVE);
gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(file_color_export_w),
TRUE);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
file_selection_set_extra_widget(file_color_export_w, main_vb);
gtk_widget_show(main_vb);
cfselect_cb = gtk_check_button_new_with_label("Export only selected filters");
gtk_container_add(GTK_CONTAINER(main_vb), cfselect_cb);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cfselect_cb), FALSE);
g_signal_connect(cfselect_cb, "toggled",
G_CALLBACK(color_toggle_selected_cb), NULL);
gtk_widget_show(cfselect_cb);
color_set_export_selected_sensitive(cfselect_cb);
cfglobal_but = gtk_button_new_with_label("Global Color Filter File");
gtk_container_add(GTK_CONTAINER(main_vb), cfglobal_but);
g_signal_connect(cfglobal_but, "clicked",
G_CALLBACK(color_global_cb), file_color_export_w);
gtk_widget_show(cfglobal_but);
for (;;) {
if (gtk_dialog_run(GTK_DIALOG(file_color_export_w)) != GTK_RESPONSE_ACCEPT) {
window_destroy(file_color_export_w);
return;
}
cf_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_color_export_w));
if (test_for_directory(cf_name) == EISDIR) {
set_last_open_dir(cf_name);
g_free(cf_name);
file_selection_set_current_folder(file_color_export_w, get_last_open_dir());
continue;
}
if (!file_target_unwritable_ui(file_color_export_w, cf_name)) {
g_free(cf_name);
continue;
}
if (!color_filters_export(cf_name, filter_list, color_selected)) {
g_free(cf_name);
continue;
}
window_destroy(GTK_WIDGET(file_color_export_w));
dirname = get_dirname(cf_name);
set_last_open_dir(dirname);
g_free(cf_name);
}
#endif
}
