static void
fs_open_entry(fileset_entry *entry)
{
char *fname;
int err;
fname = g_strdup(entry->fullname);
cf_close(&cfile);
if (cf_open(&cfile, fname, FALSE, &err) == CF_OK) {
cf_read(&cfile, FALSE);
}
g_free(fname);
}
static void
fs_rb_cb(GtkWidget *open_bt, gpointer fs_data)
{
fileset_entry *entry = fs_data;
if(!gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON(open_bt) )) {
return;
}
fs_open_entry(entry);
}
static void
fs_destroy_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
fs_w = NULL;
}
static char *
fileset_dlg_name2date_dup(const char * name) {
char *pfx;
char *filename;
size_t pos;
if(!fileset_filename_match_pattern(name)) {
return NULL;
}
pfx = strrchr(name, '_');
pfx++;
pos = pfx - name;
filename = g_strdup_printf("%c%c%c%c.%c%c.%c%c %c%c:%c%c:%c%c",
name[pos] , name[pos+1], name[pos+2], name[pos+3],
name[pos+4], name[pos+5],
name[pos+6], name[pos+7],
name[pos+8], name[pos+9],
name[pos+10], name[pos+11],
name[pos+12], name[pos+13]);
return filename;
}
void
fileset_dlg_add_file(fileset_entry *entry) {
char *created;
char *modified;
char *size;
struct tm *local;
GtkWidget *fs_lb;
GtkWidget *fs_rb;
gchar *title;
if (fs_w == NULL) {
return;
}
created = fileset_dlg_name2date_dup(entry->name);
if(!created) {
local = localtime(&entry->ctime);
created = g_strdup_printf("%04u.%02u.%02u %02u:%02u:%02u",
local->tm_year+1900, local->tm_mon+1, local->tm_mday,
local->tm_hour, local->tm_min, local->tm_sec);
}
local = localtime(&entry->mtime);
modified = g_strdup_printf("%04u.%02u.%02u %02u:%02u:%02u",
local->tm_year+1900, local->tm_mon+1, local->tm_mday,
local->tm_hour, local->tm_min, local->tm_sec);
size = g_strdup_printf("%" G_GINT64_MODIFIER "d Bytes", entry->size);
fs_rb = gtk_radio_button_new_with_label_from_widget(
fs_first_rb ? GTK_RADIO_BUTTON(fs_first_rb) : NULL, entry->name);
if(row == 1) {
fs_first_rb = fs_rb;
}
if(entry->current) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (fs_rb), entry->current);
}
gtk_widget_set_tooltip_text(fs_rb, "Open this capture file");
gtk_table_attach_defaults(GTK_TABLE(fs_tb), fs_rb, 0, 1, row, row+1);
g_signal_connect(fs_rb, "toggled", G_CALLBACK(fs_rb_cb), entry);
gtk_widget_show(fs_rb);
fs_lb = gtk_label_new(created);
gtk_table_attach_defaults(GTK_TABLE(fs_tb), fs_lb, 1, 2, row, row+1);
gtk_widget_set_sensitive(fs_lb, entry->current);
gtk_widget_show(fs_lb);
fs_lb = gtk_label_new(modified);
gtk_table_attach_defaults(GTK_TABLE(fs_tb), fs_lb, 2, 3, row, row+1);
gtk_widget_set_sensitive(fs_lb, entry->current);
gtk_widget_show(fs_lb);
fs_lb = gtk_label_new(size);
gtk_table_attach_defaults(GTK_TABLE(fs_tb), fs_lb, 3, 4, row, row+1);
gtk_widget_set_sensitive(fs_lb, entry->current);
gtk_widget_show(fs_lb);
title = g_strdup_printf("Wireshark: %u File%s in Set", row, plurality(row, "", "s"));
gtk_window_set_title(GTK_WINDOW(fs_w), title);
g_free(title);
title = g_strdup_printf("... in directory: %s", fileset_get_dirname());
gtk_label_set_text(GTK_LABEL(fs_dir_lb), title);
g_free(title);
gtk_widget_show_all(fs_tb);
if(row <= 18) {
GtkRequisition requisition;
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_get_preferred_size(fs_tb, &requisition, NULL);
#else
gtk_widget_size_request(fs_tb, &requisition);
#endif
gtk_widget_set_size_request(fs_sw, -1, requisition.height);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(fs_sw), GTK_POLICY_NEVER, GTK_POLICY_NEVER);
}
if(row == 18) {
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(fs_sw), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
}
row++;
g_free(created);
g_free(modified);
g_free(size);
}
static void
fileset_init_table(GtkWidget *parent)
{
GtkWidget *fs_lb;
fs_tb = gtk_table_new(6,1, FALSE);
gtk_table_set_row_spacings(GTK_TABLE(fs_tb), 1);
gtk_table_set_col_spacings(GTK_TABLE(fs_tb), 12);
gtk_container_add(GTK_CONTAINER(parent), fs_tb);
row = 0;
fs_first_rb = NULL;
fs_lb = gtk_label_new("Filename");
gtk_table_attach(GTK_TABLE(fs_tb), fs_lb, 0, 1, row, row+1, GTK_EXPAND|GTK_FILL, 0, 0,0);
fs_lb = gtk_label_new("Created");
gtk_table_attach(GTK_TABLE(fs_tb), fs_lb, 1, 2, row, row+1, GTK_EXPAND|GTK_FILL, 0, 0,0);
fs_lb = gtk_label_new("Last Modified");
gtk_table_attach(GTK_TABLE(fs_tb), fs_lb, 2, 3, row, row+1, GTK_EXPAND|GTK_FILL, 0, 0,0);
fs_lb = gtk_label_new("Size");
gtk_table_attach(GTK_TABLE(fs_tb), fs_lb, 3, 4, row, row+1, GTK_EXPAND|GTK_FILL, 0, 0,0);
gtk_widget_hide(fs_tb);
gtk_window_set_title(GTK_WINDOW(fs_w), "Wireshark: 0 Files in Set");
gtk_label_set_text(GTK_LABEL(fs_dir_lb), "No capture file loaded!");
row++;
}
void
fileset_cb(GtkWidget *w _U_, gpointer d _U_)
{
GtkWidget *main_vb, *bbox, *close_bt, *help_bt;
if (fs_w != NULL) {
reactivate_window(fs_w);
return;
}
fs_w = dlg_window_new("");
gtk_window_set_destroy_with_parent (GTK_WINDOW(fs_w), TRUE);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(fs_w), main_vb);
fs_sw = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(fs_sw), GTK_POLICY_NEVER, GTK_POLICY_NEVER);
gtk_box_pack_start(GTK_BOX(main_vb), fs_sw, TRUE, TRUE, 0);
fs_tb_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(fs_sw), fs_tb_vb);
fs_dir_lb = gtk_label_new("");
gtk_box_pack_start(GTK_BOX(main_vb), fs_dir_lb, FALSE, FALSE, 0);
fileset_init_table(fs_tb_vb);
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 5);
close_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(fs_w, close_bt, window_cancel_button_cb);
gtk_widget_set_tooltip_text(close_bt, "Close this window.");
help_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_FILESET_DIALOG);
gtk_widget_grab_default(close_bt);
g_signal_connect(fs_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(fs_w, "destroy", G_CALLBACK(fs_destroy_cb), NULL);
fileset_update_dlg();
gtk_widget_show_all(fs_w);
window_present(fs_w);
}
void
fileset_next_cb(GtkWidget *w _U_, gpointer d _U_)
{
fileset_entry *entry;
entry = fileset_get_next();
if(entry) {
fs_open_entry(entry);
}
}
void
fileset_previous_cb(GtkWidget *w _U_, gpointer d _U_)
{
fileset_entry *entry;
entry = fileset_get_previous();
if(entry) {
fs_open_entry(entry);
}
}
void
fileset_file_opened(const char *fname) {
fileset_add_dir(fname);
if(fs_w) {
window_present(fs_w);
}
set_menus_for_file_set(TRUE ,
fileset_get_previous() != NULL, fileset_get_next() != NULL );
}
void
fileset_file_closed(void)
{
if(fs_w) {
g_object_ref(G_OBJECT(fs_tb_vb));
gtk_widget_destroy(fs_tb);
fileset_delete();
fileset_init_table(fs_tb_vb);
window_present(fs_w);
} else {
fileset_delete();
}
set_menus_for_file_set(FALSE ,
fileset_get_previous() != NULL,
fileset_get_next() != NULL );
}
