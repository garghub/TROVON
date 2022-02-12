static wtap *
preview_set_filename(GtkWidget *prev, const gchar *cf_name)
{
GtkWidget *label;
wtap *wth;
int err = 0;
gchar *err_info;
gchar string_buff[PREVIEW_STR_MAX];
gint64 filesize;
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_FORMAT_KEY);
gtk_label_set_text(GTK_LABEL(label), "-");
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_SIZE_KEY);
gtk_label_set_text(GTK_LABEL(label), "-");
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_PACKETS_KEY);
gtk_label_set_text(GTK_LABEL(label), "-");
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_FIRST_ELAPSED_KEY);
gtk_label_set_text(GTK_LABEL(label), "-");
if (!cf_name) {
return NULL;
}
if (test_for_directory(cf_name) == EISDIR) {
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_FORMAT_KEY);
gtk_label_set_text(GTK_LABEL(label), "directory");
return NULL;
}
wth = wtap_open_offline(cf_name, WTAP_TYPE_AUTO, &err, &err_info, TRUE);
if (wth == NULL) {
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_FORMAT_KEY);
if (err == WTAP_ERR_FILE_UNKNOWN_FORMAT) {
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
g_strlcpy(string_buff, wtap_file_type_subtype_string(wtap_file_type_subtype(wth)), PREVIEW_STR_MAX);
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
double start_time = 0;
double stop_time = 0;
double cur_time;
unsigned int packets = 0;
gboolean is_breaked = FALSE;
gchar string_buff[PREVIEW_STR_MAX];
gchar first_buff[PREVIEW_STR_MAX];
time_t ti_time;
struct tm *ti_tm;
const struct wtap_pkthdr *phdr;
time(&time_preview);
while ( (wtap_read(wth, &err, &err_info, &data_offset)) ) {
phdr = wtap_phdr(wth);
cur_time = nstime_to_sec(&phdr->ts);
if (packets == 0) {
start_time = cur_time;
stop_time = cur_time;
}
if (cur_time < start_time) {
start_time = cur_time;
}
if (cur_time > stop_time) {
stop_time = cur_time;
}
packets++;
if (packets%1000 == 0) {
time(&time_current);
if (time_current-time_preview >= (time_t) prefs.gui_fileopen_preview) {
is_breaked = TRUE;
break;
}
}
}
if (err != 0) {
g_snprintf(string_buff, PREVIEW_STR_MAX, "error after reading %u packets", packets);
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_PACKETS_KEY);
gtk_label_set_text(GTK_LABEL(label), string_buff);
wtap_close(wth);
return;
}
if (is_breaked) {
g_snprintf(string_buff, PREVIEW_STR_MAX, "more than %u packets (preview timeout)", packets);
} else {
g_snprintf(string_buff, PREVIEW_STR_MAX, "%u", packets);
}
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_PACKETS_KEY);
gtk_label_set_text(GTK_LABEL(label), string_buff);
ti_time = (long)start_time;
ti_tm = localtime( &ti_time );
if (ti_tm) {
g_snprintf(first_buff, PREVIEW_STR_MAX,
"%04d-%02d-%02d %02d:%02d:%02d",
ti_tm->tm_year + 1900,
ti_tm->tm_mon + 1,
ti_tm->tm_mday,
ti_tm->tm_hour,
ti_tm->tm_min,
ti_tm->tm_sec);
} else {
g_snprintf(first_buff, PREVIEW_STR_MAX, "?");
}
elapsed_time = (unsigned int)(stop_time-start_time);
if (elapsed_time/86400) {
g_snprintf(string_buff, PREVIEW_STR_MAX, "%s / %02u days %02u:%02u:%02u",
first_buff, elapsed_time/86400, elapsed_time%86400/3600, elapsed_time%3600/60, elapsed_time%60);
} else {
g_snprintf(string_buff, PREVIEW_STR_MAX, "%s / %02u:%02u:%02u",
first_buff, elapsed_time%86400/3600, elapsed_time%3600/60, elapsed_time%60);
}
if (is_breaked) {
g_snprintf(string_buff, PREVIEW_STR_MAX, "%s / unknown", first_buff);
}
label = (GtkWidget *)g_object_get_data(G_OBJECT(prev), PREVIEW_FIRST_ELAPSED_KEY);
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
if (have_preview)
preview_do(prev, wth);
}
static GtkWidget *
add_string_to_grid_sensitive(GtkWidget *grid, guint *row, const gchar *title, const gchar *value, gboolean sensitive)
{
GtkWidget *label;
gchar *indent;
if (strlen(value) != 0) {
indent = g_strdup_printf(" %s", title);
} else {
indent = g_strdup(title);
}
label = gtk_label_new(indent);
g_free(indent);
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
gtk_widget_set_sensitive(label, sensitive);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 0, *row, 1, 1);
label = gtk_label_new(value);
gtk_misc_set_alignment(GTK_MISC(label), 0.0f, 0.5f);
gtk_widget_set_sensitive(label, sensitive);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 1, *row, 1, 1);
*row = *row + 1;
return label;
}
static GtkWidget *
add_string_to_grid(GtkWidget *grid, guint *row, const gchar *title, const gchar *value)
{
return add_string_to_grid_sensitive(grid, row, title, value, TRUE);
}
static GtkWidget *
preview_new(void)
{
GtkWidget *grid, *label;
guint row;
grid = ws_gtk_grid_new();
ws_gtk_grid_set_column_spacing(GTK_GRID(grid), 6);
ws_gtk_grid_set_row_spacing(GTK_GRID(grid), 3);
row = 0;
label = add_string_to_grid(grid, &row, "Format:", "-");
g_object_set_data(G_OBJECT(grid), PREVIEW_FORMAT_KEY, label);
label = add_string_to_grid(grid, &row, "Size:", "-");
g_object_set_data(G_OBJECT(grid), PREVIEW_SIZE_KEY, label);
label = add_string_to_grid(grid, &row, "Packets:", "-");
g_object_set_data(G_OBJECT(grid), PREVIEW_PACKETS_KEY, label);
label = add_string_to_grid(grid, &row, "Start / elapsed:", "-");
g_object_set_data(G_OBJECT(grid), PREVIEW_FIRST_ELAPSED_KEY, label);
return grid;
}
static gboolean
gtk_open_file(GtkWidget *w, GString *file_name, gint *type, GString *display_filter)
{
GtkWidget *file_open_w;
GtkWidget *main_hb, *main_vb, *filter_hbox, *filter_bt, *filter_te;
GtkWidget *prev;
GtkWidget *format_type_co;
GtkCellRenderer *cell;
gint i;
static construct_args_t args = {
"Wireshark: Display Filter",
FALSE,
FALSE,
TRUE
};
gchar *cf_name;
if (!file_name || !display_filter)
return FALSE;
file_open_w = file_selection_new("Wireshark: Open Capture File",
GTK_WINDOW(top_level),
FILE_SELECTION_OPEN);
gtk_widget_set_size_request(file_open_w, DEF_WIDTH, DEF_HEIGHT);
if (file_name->len > 0) {
gchar *dirname = g_path_get_dirname(file_name->str);
file_selection_set_current_folder(file_open_w, dirname);
g_free(dirname);
} else {
switch (prefs.gui_fileopen_style) {
case FO_STYLE_LAST_OPENED:
break;
case FO_STYLE_SPECIFIED:
if (prefs.gui_fileopen_dir[0] != '\0')
file_selection_set_current_folder(file_open_w, prefs.gui_fileopen_dir);
break;
}
}
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_set_vexpand(main_hb, FALSE);
#endif
file_selection_set_extra_widget(file_open_w, main_hb);
gtk_widget_show(main_hb);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_box_pack_start(GTK_BOX(main_hb), main_vb, FALSE, FALSE, 0);
gtk_widget_show(main_vb);
format_type_co = gtk_combo_box_text_new();
cell = gtk_cell_renderer_text_new();
gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(format_type_co), cell, TRUE);
gtk_widget_set_tooltip_text(format_type_co, "Format type of capture file");
gtk_box_pack_start(GTK_BOX(main_vb), format_type_co, FALSE, FALSE, 0);
gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(format_type_co), (const gchar *) "Automatically detect file type");
for (i = 0; open_routines[i].name != NULL; i += 1) {
gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(format_type_co), open_routines[i].name);
}
gtk_combo_box_set_active(GTK_COMBO_BOX(format_type_co), 0);
gtk_widget_show(format_type_co);
filter_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(filter_hbox), 0);
gtk_box_pack_start(GTK_BOX(main_vb), filter_hbox, FALSE, FALSE, 0);
gtk_widget_show(filter_hbox);
filter_bt = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY);
g_signal_connect(filter_bt, "clicked",
G_CALLBACK(display_filter_construct_cb), &args);
g_signal_connect(filter_bt, "destroy",
G_CALLBACK(filter_button_destroy_cb), NULL);
gtk_box_pack_start(GTK_BOX(filter_hbox), filter_bt, FALSE, FALSE, 0);
gtk_widget_show(filter_bt);
gtk_widget_set_tooltip_text(filter_bt, "Open the \"Display Filter\" dialog to edit/apply filters");
filter_te = gtk_entry_new();
g_object_set_data(G_OBJECT(filter_bt), E_FILT_TE_PTR_KEY, filter_te);
gtk_box_pack_start(GTK_BOX(filter_hbox), filter_te, TRUE, TRUE, 3);
g_signal_connect(filter_te, "changed",
G_CALLBACK(filter_te_syntax_check_cb), NULL);
g_object_set_data(G_OBJECT(filter_hbox), E_FILT_AUTOCOMP_PTR_KEY, NULL);
g_signal_connect(filter_te, "key-press-event", G_CALLBACK(filter_string_te_key_pressed_cb), NULL);
g_signal_connect(file_open_w, "key-press-event", G_CALLBACK(filter_parent_dlg_key_pressed_cb), NULL);
colorize_filter_te_as_empty(filter_te);
gtk_entry_set_text(GTK_ENTRY(filter_te), display_filter->str);
gtk_widget_show(filter_te);
gtk_widget_set_tooltip_text(filter_te, "Enter a display filter.");
g_object_set_data(G_OBJECT(file_open_w), E_RFILTER_TE_KEY, filter_te);
prev = preview_new();
g_object_set_data(G_OBJECT(file_open_w), PREVIEW_TABLE_KEY, prev);
gtk_widget_show_all(prev);
gtk_box_pack_start(GTK_BOX(main_hb), prev, FALSE, FALSE, 0);
g_signal_connect(GTK_FILE_CHOOSER(file_open_w), "selection-changed",
G_CALLBACK(file_open_entry_changed), file_open_w);
file_open_entry_changed(file_open_w, file_open_w);
g_object_set_data(G_OBJECT(file_open_w), E_DFILTER_TE_KEY,
g_object_get_data(G_OBJECT(w), E_DFILTER_TE_KEY));
cf_name = file_selection_run(file_open_w);
if (cf_name == NULL) {
return FALSE;
}
g_string_printf(file_name, "%s", cf_name);
g_free(cf_name);
g_string_printf(display_filter, "%s", gtk_entry_get_text(GTK_ENTRY(filter_te)));
*type = gtk_combo_box_get_active((GtkComboBox *) format_type_co);
window_destroy(GTK_WIDGET(file_open_w));
return TRUE;
}
void
file_open_cmd_cb(GtkWidget *widget, gpointer data _U_) {
if (test_file_close(&cfile, FALSE, " before opening a new capture file"))
file_open_cmd(&cfile, widget);
}
static gboolean
gtk_merge_file(GtkWidget *w, GString *file_name, GString *display_filter, int *merge_type)
{
GtkWidget *file_merge_w;
GtkWidget *main_hb, *main_vb, *filter_hbox, *filter_bt, *filter_te;
GtkWidget *prepend_rb, *chrono_rb, *append_rb, *prev;
static construct_args_t args = {
"Wireshark: Display Filter",
FALSE,
FALSE,
TRUE
};
gchar *cf_name;
if (!file_name || !display_filter || !merge_type)
return FALSE;
file_merge_w = file_selection_new("Wireshark: Merge with Capture File",
GTK_WINDOW(top_level),
FILE_SELECTION_OPEN);
gtk_widget_set_size_request(file_merge_w, DEF_WIDTH, DEF_HEIGHT);
if (file_name->len > 0) {
gchar *dirname = g_path_get_dirname(file_name->str);
file_selection_set_current_folder(file_merge_w, dirname);
g_free(dirname);
} else {
switch (prefs.gui_fileopen_style) {
case FO_STYLE_LAST_OPENED:
break;
case FO_STYLE_SPECIFIED:
if (prefs.gui_fileopen_dir[0] != '\0')
file_selection_set_current_folder(file_merge_w, prefs.gui_fileopen_dir);
break;
}
}
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_set_vexpand(main_hb, FALSE);
#endif
file_selection_set_extra_widget(file_merge_w, main_hb);
gtk_widget_show(main_hb);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_box_pack_start(GTK_BOX(main_hb), main_vb, FALSE, FALSE, 0);
gtk_widget_show(main_vb);
filter_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(filter_hbox), 0);
gtk_box_pack_start(GTK_BOX(main_vb), filter_hbox, FALSE, FALSE, 0);
gtk_widget_show(filter_hbox);
filter_bt = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY);
g_signal_connect(filter_bt, "clicked",
G_CALLBACK(display_filter_construct_cb), &args);
g_signal_connect(filter_bt, "destroy",
G_CALLBACK(filter_button_destroy_cb), NULL);
gtk_box_pack_start(GTK_BOX(filter_hbox), filter_bt, FALSE, TRUE, 0);
gtk_widget_show(filter_bt);
gtk_widget_set_tooltip_text(filter_bt, "Open the \"Display Filter\" dialog to edit/apply filters");
filter_te = gtk_entry_new();
g_object_set_data(G_OBJECT(filter_bt), E_FILT_TE_PTR_KEY, filter_te);
gtk_box_pack_start(GTK_BOX(filter_hbox), filter_te, TRUE, TRUE, 3);
g_signal_connect(filter_te, "changed",
G_CALLBACK(filter_te_syntax_check_cb), NULL);
g_object_set_data(G_OBJECT(filter_hbox), E_FILT_AUTOCOMP_PTR_KEY, NULL);
g_signal_connect(filter_te, "key-press-event", G_CALLBACK(filter_string_te_key_pressed_cb), NULL);
g_signal_connect(file_merge_w, "key-press-event", G_CALLBACK(filter_parent_dlg_key_pressed_cb), NULL);
colorize_filter_te_as_empty(filter_te);
gtk_entry_set_text(GTK_ENTRY(filter_te), display_filter->str);
gtk_widget_show(filter_te);
gtk_widget_set_tooltip_text(filter_te, "Enter a display filter.");
g_object_set_data(G_OBJECT(file_merge_w), E_RFILTER_TE_KEY, filter_te);
prepend_rb = gtk_radio_button_new_with_mnemonic_from_widget(NULL,
"Prepend packets");
gtk_widget_set_tooltip_text(prepend_rb, "Insert packets from the selected file before the current file. Packet timestamps will be ignored.");
gtk_box_pack_start(GTK_BOX(main_vb), prepend_rb, FALSE, FALSE, 0);
gtk_widget_show(prepend_rb);
chrono_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(prepend_rb), "Merge chronologically");
gtk_widget_set_tooltip_text(chrono_rb, "Insert packets in chronological order.");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(chrono_rb), TRUE);
gtk_box_pack_start(GTK_BOX(main_vb), chrono_rb, FALSE, FALSE, 0);
gtk_widget_show(chrono_rb);
append_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(prepend_rb), "Append packets");
gtk_widget_set_tooltip_text(append_rb, "Insert packets from the selected file after the current file. Packet timestamps will be ignored.");
gtk_box_pack_start(GTK_BOX(main_vb), append_rb, FALSE, FALSE, 0);
gtk_widget_show(append_rb);
prev = preview_new();
g_object_set_data(G_OBJECT(file_merge_w), PREVIEW_TABLE_KEY, prev);
gtk_widget_show_all(prev);
gtk_box_pack_start(GTK_BOX(main_hb), prev, FALSE, FALSE, 0);
g_signal_connect(GTK_FILE_CHOOSER(file_merge_w), "selection-changed",
G_CALLBACK(file_open_entry_changed), file_merge_w);
file_open_entry_changed(file_merge_w, file_merge_w);
g_object_set_data(G_OBJECT(file_merge_w), E_DFILTER_TE_KEY,
g_object_get_data(G_OBJECT(w), E_DFILTER_TE_KEY));
cf_name = file_selection_run(file_merge_w);
if (cf_name == NULL) {
return FALSE;
}
g_string_printf(file_name, "%s", cf_name);
g_free(cf_name);
g_string_printf(display_filter, "%s", gtk_entry_get_text(GTK_ENTRY(filter_te)));
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chrono_rb))) {
*merge_type = 0;
} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(prepend_rb))) {
*merge_type = -1;
} else {
*merge_type = 1;
}
window_destroy(GTK_WIDGET(file_merge_w));
return TRUE;
}
void
file_merge_cmd_cb(GtkWidget *widget, gpointer data _U_) {
GtkWidget *msg_dialog;
gchar *display_basename;
gint response;
if (prefs.gui_ask_unsaved) {
if (cf_has_unsaved_data(&cfile)) {
if (cfile.is_tempfile) {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
(GtkDialogFlags)(GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT),
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"Do you want to save the captured packets before merging another capture file into it?");
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
"A temporary capture file can't be merged.");
} else {
display_basename = g_filename_display_basename(cfile.filename);
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
(GtkDialogFlags)(GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT),
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"Do you want to save the changes you've made "
"to the capture file \"%s\" before merging another capture file into it?",
display_basename);
g_free(display_basename);
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
"The changes must be saved before the files are merged.");
}
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
WIRESHARK_STOCK_SAVE, GTK_RESPONSE_ACCEPT);
gtk_dialog_set_alternative_button_order(GTK_DIALOG(msg_dialog),
GTK_RESPONSE_ACCEPT,
GTK_RESPONSE_CANCEL,
-1);
gtk_dialog_set_default_response(GTK_DIALOG(msg_dialog),
GTK_RESPONSE_ACCEPT);
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
test_file_close(capture_file *cf, gboolean from_quit, const char *before_what)
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
if (cf_has_unsaved_data(cf) || capture_in_progress) {
if (cf->is_tempfile) {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
(GtkDialogFlags)(GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT),
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
(GtkDialogFlags)(GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT),
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"Do you want to stop the capture and save the captured packets%s?",
before_what);
} else {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
(GtkDialogFlags)(GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT),
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
WIRESHARK_STOCK_SAVE),
GTK_RESPONSE_ACCEPT);
gtk_dialog_set_alternative_button_order(GTK_DIALOG(msg_dialog),
GTK_RESPONSE_ACCEPT,
GTK_RESPONSE_CANCEL,
GTK_RESPONSE_REJECT,
-1);
gtk_dialog_set_default_response(GTK_DIALOG(msg_dialog),
GTK_RESPONSE_ACCEPT);
response = gtk_dialog_run(GTK_DIALOG(msg_dialog));
gtk_widget_destroy(msg_dialog);
switch (response) {
case GTK_RESPONSE_ACCEPT:
#ifdef HAVE_LIBPCAP
if (capture_in_progress)
do_capture_stop(cf);
#endif
if (do_file_save(cf, TRUE) == FALSE)
return FALSE;
break;
case GTK_RESPONSE_REJECT:
#ifdef HAVE_LIBPCAP
if (capture_in_progress)
do_capture_stop(cf);
#endif
break;
case GTK_RESPONSE_CANCEL:
case GTK_RESPONSE_NONE:
case GTK_RESPONSE_DELETE_EVENT:
default:
return FALSE;
}
} else {
return TRUE;
}
} else {
#ifdef HAVE_LIBPCAP
if (capture_in_progress)
do_capture_stop(cf);
#endif
return TRUE;
}
return TRUE;
}
gboolean
do_file_close(capture_file *cf, gboolean from_quit, const char *before_what)
{
if (test_file_close(cf, from_quit, before_what)) {
cf_close(cf);
return TRUE;
}
return FALSE;
}
void
file_close_cmd_cb(GtkWidget *widget _U_, gpointer data _U_) {
(void)do_file_close(&cfile, FALSE, "");
}
static check_savability_t
check_save_with_comments(capture_file *cf)
{
guint32 comment_types;
GtkWidget *msg_dialog;
gint response;
comment_types = cf_comment_types(cf);
if (wtap_dump_supports_comment_types(cf->cd_t, comment_types)) {
return SAVE;
}
if (wtap_dump_can_write(cf->linktypes, comment_types)) {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"The capture has comments, but the file's format "
"doesn't support comments. Do you want to save the capture "
"in a format that supports comments, or discard the comments "
"and save in the file's format?");
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
"Discard comments and save",
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
GTK_STOCK_CANCEL,
GTK_RESPONSE_CANCEL,
"Save in another format",
RESPONSE_SAVE_IN_ANOTHER_FORMAT,
NULL);
gtk_dialog_set_alternative_button_order(GTK_DIALOG(msg_dialog),
RESPONSE_SAVE_IN_ANOTHER_FORMAT,
GTK_RESPONSE_CANCEL,
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
-1);
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
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
GTK_STOCK_CANCEL,
GTK_RESPONSE_CANCEL,
"Discard comments and save",
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
NULL);
gtk_dialog_set_alternative_button_order(GTK_DIALOG(msg_dialog),
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
GTK_RESPONSE_CANCEL,
-1);
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
static gboolean
do_file_save(capture_file *cf, gboolean dont_reopen)
{
char *fname;
gboolean discard_comments;
cf_write_status_t status;
if (cf->is_tempfile) {
return file_save_as_cmd(cf, FALSE, dont_reopen);
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
return file_save_as_cmd(cf, TRUE, dont_reopen);
case CANCELLED:
return FALSE;
default:
g_assert_not_reached();
return TRUE;
}
fname = g_strdup(cf->filename);
status = cf_save_records(cf, fname, cf->cd_t, cf->iscompressed,
discard_comments, dont_reopen);
switch (status) {
case CF_WRITE_OK:
if (discard_comments)
packet_list_queue_draw();
break;
case CF_WRITE_ERROR:
break;
case CF_WRITE_ABORTED:
break;
}
g_free(fname);
}
}
return TRUE;
}
void
file_save_cmd_cb(GtkWidget *w _U_, gpointer data _U_) {
do_file_save(&cfile, FALSE);
}
static int
set_file_type_list(GtkWidget *combo_box, capture_file *cf,
gboolean must_support_all_comments)
{
guint32 required_comment_types;
GArray *savable_file_types_subtypes;
guint i;
int ft;
int default_ft = -1;
if (must_support_all_comments)
required_comment_types = cf_comment_types(cf);
else
required_comment_types = 0;
savable_file_types_subtypes = wtap_get_savable_file_types_subtypes(cf->cd_t,
cf->linktypes,
required_comment_types);
if (savable_file_types_subtypes != NULL) {
for (i = 0; i < savable_file_types_subtypes->len; i++) {
ft = g_array_index(savable_file_types_subtypes, int, i);
if (default_ft == -1)
default_ft = ft;
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(combo_box),
wtap_file_type_subtype_string(ft),
GINT_TO_POINTER(ft));
}
g_array_free(savable_file_types_subtypes, TRUE);
}
return default_ft;
}
static void
file_select_file_type_cb(GtkWidget *w, gpointer parent_arg)
{
GtkWidget *parent = (GtkWidget *)parent_arg;
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
gtk_check_save_as_with_comments(GtkWidget *w, capture_file *cf, int file_type)
{
guint32 comment_types;
GtkWidget *msg_dialog;
gint response;
comment_types = cf_comment_types(cf);
if (wtap_dump_supports_comment_types(file_type, comment_types)) {
return SAVE;
}
if (wtap_dump_can_write(cf->linktypes, comment_types)) {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(w),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"The capture has comments, but the file format you chose "
"doesn't support comments. Do you want to save the capture "
"in a format that supports comments, or discard the comments "
"and save in the format you chose?");
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
"Discard comments and save",
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
GTK_STOCK_CANCEL,
GTK_RESPONSE_CANCEL,
"Save in another format",
RESPONSE_SAVE_IN_ANOTHER_FORMAT,
NULL);
gtk_dialog_set_alternative_button_order(GTK_DIALOG(msg_dialog),
RESPONSE_SAVE_IN_ANOTHER_FORMAT,
GTK_RESPONSE_CANCEL,
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
-1);
gtk_dialog_set_default_response(GTK_DIALOG(msg_dialog),
RESPONSE_SAVE_IN_ANOTHER_FORMAT);
} else {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(w),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"The capture has comments, but no file format in which it "
"can be saved supports comments. Do you want to discard "
"the comments and save in the format you chose?");
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
GTK_STOCK_CANCEL,
GTK_RESPONSE_CANCEL,
"Discard comments and save",
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
NULL);
gtk_dialog_set_alternative_button_order(GTK_DIALOG(msg_dialog),
RESPONSE_DISCARD_COMMENTS_AND_SAVE,
GTK_RESPONSE_CANCEL,
-1);
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
static gboolean
gtk_save_as_file(GtkWidget *w _U_, capture_file *cf, GString *file_name, int *file_type,
gboolean *compressed, gboolean must_support_all_comments)
{
GtkWidget *file_save_as_w;
GtkWidget *main_vb, *ft_hb, *ft_lb, *ft_combo_box, *compressed_cb;
int default_ft;
char *cf_name;
gpointer ptr;
if (!file_name || !file_type || !compressed)
return FALSE;
file_save_as_w = file_selection_new("Wireshark: Save Capture File As",
GTK_WINDOW(top_level),
FILE_SELECTION_SAVE);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
file_selection_set_extra_widget(file_save_as_w, main_vb);
gtk_widget_show(main_vb);
ft_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(main_vb), ft_hb, FALSE, FALSE, 0);
gtk_widget_show(ft_hb);
ft_lb = gtk_label_new("File type:");
gtk_box_pack_start(GTK_BOX(ft_hb), ft_lb, FALSE, FALSE, 0);
gtk_widget_show(ft_lb);
ft_combo_box = ws_combo_box_new_text_and_pointer();
default_ft = set_file_type_list(ft_combo_box, cf, must_support_all_comments);
gtk_box_pack_start(GTK_BOX(ft_hb), ft_combo_box, FALSE, FALSE, 0);
gtk_widget_show(ft_combo_box);
g_object_set_data(G_OBJECT(file_save_as_w), E_FILE_TYPE_COMBO_BOX_KEY, ft_combo_box);
compressed_cb = gtk_check_button_new_with_label("Compress with gzip");
gtk_box_pack_start(GTK_BOX(ft_hb), compressed_cb, FALSE, FALSE, 0);
if (cf->iscompressed && wtap_dump_can_compress(default_ft))
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(compressed_cb), TRUE);
gtk_widget_show(compressed_cb);
g_object_set_data(G_OBJECT(file_save_as_w), E_COMPRESSED_CB_KEY, compressed_cb);
g_signal_connect(ft_combo_box, "changed", G_CALLBACK(file_select_file_type_cb), file_save_as_w);
ws_combo_box_set_active(GTK_COMBO_BOX(ft_combo_box), 0);
cf_name = file_selection_run(file_save_as_w);
if (cf_name == NULL) {
return FALSE;
}
if (! ws_combo_box_get_active_pointer(GTK_COMBO_BOX(ft_combo_box), &ptr)) {
g_assert_not_reached();
}
*file_type = GPOINTER_TO_INT(ptr);
*compressed = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(compressed_cb));
window_destroy(GTK_WIDGET(file_save_as_w));
g_string_printf(file_name, "%s", cf_name);
g_free(cf_name);
return TRUE;
}
static void
file_add_extension(GString *file_name, int file_type, gboolean compressed) {
gchar *file_name_lower;
GString *file_suffix;
GSList *extensions_list, *extension;
gboolean add_extension;
file_name_lower = g_utf8_strdown(file_name->str, -1);
file_suffix = g_string_new("");
extensions_list = wtap_get_file_extensions_list(file_type, FALSE);
if (extensions_list != NULL) {
add_extension = TRUE;
for (extension = extensions_list; extension != NULL;
extension = g_slist_next(extension)) {
g_string_printf(file_suffix, ".%s", (char *)extension->data);
if (g_str_has_suffix(file_name_lower, file_suffix->str)) {
add_extension = FALSE;
break;
}
g_string_append(file_suffix, ".gz");
if (g_str_has_suffix(file_name_lower, file_suffix->str)) {
add_extension = FALSE;
break;
}
}
} else {
add_extension = FALSE;
}
g_free(file_name_lower);
g_string_free(file_suffix, TRUE);
if (add_extension) {
if (wtap_default_file_extension(file_type) != NULL) {
g_string_append_printf(file_name, ".%s",
wtap_default_file_extension(file_type));
if (compressed) {
g_string_append(file_name, ".gz");
}
}
}
}
void
file_save_as_cmd_cb(GtkWidget *w _U_, gpointer data _U_)
{
file_save_as_cmd(&cfile, FALSE, FALSE);
}
static gboolean
gtk_export_specified_packets_file(GtkWidget *w _U_, GString *file_name, int *file_type,
gboolean *compressed, packet_range_t *range)
{
GtkWidget *file_export_specified_packets_w;
GtkWidget *main_vb, *ft_hb, *ft_lb, *ft_combo_box, *range_fr, *range_grid,
*compressed_cb;
char *cf_name;
gpointer ptr;
if (!file_name || !file_type || !compressed || !range)
return FALSE;
file_export_specified_packets_w = file_selection_new("Wireshark: Export Specified Packets",
GTK_WINDOW(top_level),
FILE_SELECTION_SAVE);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
file_selection_set_extra_widget(file_export_specified_packets_w, main_vb);
gtk_widget_show(main_vb);
range_fr = gtk_frame_new("Packet Range");
gtk_box_pack_start(GTK_BOX(main_vb), range_fr, FALSE, FALSE, 0);
gtk_widget_show(range_fr);
range_grid = range_new(range, TRUE);
gtk_container_add(GTK_CONTAINER(range_fr), range_grid);
gtk_widget_show(range_grid);
ft_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(main_vb), ft_hb, FALSE, FALSE, 0);
gtk_widget_show(ft_hb);
ft_lb = gtk_label_new("File type:");
gtk_box_pack_start(GTK_BOX(ft_hb), ft_lb, FALSE, FALSE, 0);
gtk_widget_show(ft_lb);
ft_combo_box = ws_combo_box_new_text_and_pointer();
set_file_type_list(ft_combo_box, &cfile, FALSE);
gtk_box_pack_start(GTK_BOX(ft_hb), ft_combo_box, FALSE, FALSE, 0);
gtk_widget_show(ft_combo_box);
g_object_set_data(G_OBJECT(file_export_specified_packets_w), E_FILE_TYPE_COMBO_BOX_KEY, ft_combo_box);
range_update_dynamics(range_grid);
compressed_cb = gtk_check_button_new_with_label("Compress with gzip");
gtk_box_pack_start(GTK_BOX(ft_hb), compressed_cb, FALSE, FALSE, 0);
gtk_widget_show(compressed_cb);
g_object_set_data(G_OBJECT(file_export_specified_packets_w), E_COMPRESSED_CB_KEY, compressed_cb);
g_signal_connect(ft_combo_box, "changed", G_CALLBACK(file_select_file_type_cb), file_export_specified_packets_w);
ws_combo_box_set_active(GTK_COMBO_BOX(ft_combo_box), 0);
cf_name = file_selection_run(file_export_specified_packets_w);
if (cf_name == NULL) {
return FALSE;
}
if (! ws_combo_box_get_active_pointer(GTK_COMBO_BOX(ft_combo_box), &ptr)) {
g_assert_not_reached();
}
*file_type = GPOINTER_TO_INT(ptr);
*compressed = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(compressed_cb));
window_destroy(GTK_WIDGET(file_export_specified_packets_w));
g_string_printf(file_name, "%s", cf_name);
g_free(cf_name);
return TRUE;
}
void
file_export_pdu_ok_cb(GtkWidget *widget _U_, gpointer data)
{
GtkWidget *msg_dialog;
gchar *display_basename;
gint response;
if (prefs.gui_ask_unsaved && cf_has_unsaved_data(&cfile)) {
if (cfile.is_tempfile) {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
(GtkDialogFlags)(GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT),
GTK_MESSAGE_QUESTION, GTK_BUTTONS_NONE,
"Do you want to save the captured packets before exporting PDUs?");
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
"After the export, the captured packets will no longer be accessible.");
}
else {
display_basename = g_filename_display_basename(cfile.filename);
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
(GtkDialogFlags)(GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT),
GTK_MESSAGE_QUESTION, GTK_BUTTONS_NONE,
"Do you want to save the changes you've made "
"to the capture file \"%s\" before exporting PDUs from it?",
display_basename);
g_free(display_basename);
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
"Unsaved changes will be discarded when PDUs are exported.");
}
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
WIRESHARK_STOCK_DONT_SAVE, GTK_RESPONSE_CLOSE);
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
WIRESHARK_STOCK_SAVE, GTK_RESPONSE_ACCEPT);
gtk_dialog_set_alternative_button_order(GTK_DIALOG(msg_dialog),
GTK_RESPONSE_ACCEPT,
GTK_RESPONSE_CANCEL,
GTK_RESPONSE_CLOSE,
-1);
gtk_dialog_set_default_response(GTK_DIALOG(msg_dialog), GTK_RESPONSE_ACCEPT);
response = gtk_dialog_run(GTK_DIALOG(msg_dialog));
gtk_widget_destroy(msg_dialog);
switch (response) {
case GTK_RESPONSE_CLOSE:
break;
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
export_pdu_action(data);
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
#ifdef USE_WIN32_FILE_DIALOGS
win32_import_color_file(GDK_WINDOW_HWND(gtk_widget_get_window(top_level)), color_filters);
#else
GtkWidget *main_vb, *cfglobal_but;
gchar *cf_name, *s, *err_msg = NULL;
file_color_import_w = file_selection_new("Wireshark: Import Color Filters",
GTK_WINDOW(top_level),
FILE_SELECTION_OPEN);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
file_selection_set_extra_widget(file_color_import_w, main_vb);
gtk_widget_show(main_vb);
cfglobal_but = gtk_button_new_with_label("Global Color Filter File");
gtk_box_pack_start(GTK_BOX(main_vb), cfglobal_but, FALSE, FALSE, 0);
g_signal_connect(cfglobal_but, "clicked",
G_CALLBACK(color_global_cb), file_color_import_w);
gtk_widget_show(cfglobal_but);
for (;;) {
cf_name = file_selection_run(file_color_import_w);
if (cf_name == NULL) {
return;
}
if (!color_filters_import(cf_name, color_filters, &err_msg, color_filter_add_cb)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_msg);
g_free(err_msg);
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
color_selected = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
}
void
file_color_export_cmd_cb(GtkWidget *w _U_, gpointer filter_list)
{
#ifdef USE_WIN32_FILE_DIALOGS
win32_export_color_file(GDK_WINDOW_HWND(gtk_widget_get_window(top_level)), &cfile, filter_list);
#else
GtkWidget *file_color_export_w;
GtkWidget *main_vb, *cfglobal_but;
GtkWidget *cfselect_cb;
gchar *cf_name;
gchar *dirname;
gchar *err_msg = NULL;
color_selected = FALSE;
file_color_export_w = file_selection_new("Wireshark: Export Color Filters",
GTK_WINDOW(top_level),
FILE_SELECTION_SAVE);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
file_selection_set_extra_widget(file_color_export_w, main_vb);
gtk_widget_show(main_vb);
cfselect_cb = gtk_check_button_new_with_label("Export only selected filters");
gtk_box_pack_start(GTK_BOX(main_vb), cfselect_cb, FALSE, FALSE, 0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cfselect_cb), FALSE);
g_signal_connect(cfselect_cb, "toggled",
G_CALLBACK(color_toggle_selected_cb), NULL);
gtk_widget_show(cfselect_cb);
color_set_export_selected_sensitive(cfselect_cb);
cfglobal_but = gtk_button_new_with_label("Global Color Filter File");
gtk_box_pack_start(GTK_BOX(main_vb), cfglobal_but, FALSE, FALSE, 0);
g_signal_connect(cfglobal_but, "clicked",
G_CALLBACK(color_global_cb), file_color_export_w);
gtk_widget_show(cfglobal_but);
for (;;) {
cf_name = file_selection_run(file_color_export_w);
if (cf_name == NULL) {
return;
}
#ifndef _WIN32
if (!file_target_unwritable_ui(file_color_export_w, cf_name)) {
g_free(cf_name);
continue;
}
#endif
if (!color_filters_export(cf_name, (GSList *)filter_list, color_selected, &err_msg)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_msg);
g_free(err_msg);
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
