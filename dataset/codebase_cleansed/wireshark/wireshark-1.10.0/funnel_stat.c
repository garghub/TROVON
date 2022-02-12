static void text_window_cancel_button_cb(GtkWidget *bt _U_, gpointer data) {
funnel_text_window_t* tw = (funnel_text_window_t *)data;
window_destroy(GTK_WIDGET(tw->win));
tw->win = NULL;
if (tw->close_cb)
tw->close_cb(tw->close_data);
}
static void unref_text_win_cancel_bt_cb(GtkWidget *bt _U_, gpointer data) {
funnel_text_window_t* tw = (funnel_text_window_t *)data;
guint i;
window_destroy(GTK_WIDGET(tw->win));
tw->win = NULL;
if (tw->close_cb)
tw->close_cb(tw->close_data);
for (i = 0; i < tw->buttons->len; i++) {
funnel_bt_t* cbd = (funnel_bt_t *)g_ptr_array_index(tw->buttons,i);
if (cbd->data && cbd->free_data_fcn) cbd->free_data_fcn(cbd->data);
if (cbd->free_fcn) cbd->free_fcn(cbd);
}
g_ptr_array_free(tw->buttons,TRUE);
g_free(tw);
}
static gboolean text_window_unref_del_event_cb(GtkWidget *win _U_, GdkEvent *event _U_, gpointer user_data) {
funnel_text_window_t* tw = (funnel_text_window_t *)user_data;
guint i;
window_destroy(GTK_WIDGET(tw->win));
tw->win = NULL;
if (tw->close_cb)
tw->close_cb(tw->close_data);
for (i = 0; i < tw->buttons->len; i++) {
funnel_bt_t* cbd = (funnel_bt_t *)g_ptr_array_index(tw->buttons,i);
if (cbd->data && cbd->free_data_fcn) cbd->free_data_fcn(cbd->data);
if (cbd->free_fcn) cbd->free_fcn(cbd);
}
g_ptr_array_free(tw->buttons,TRUE);
g_free(tw);
return TRUE;
}
static gboolean text_window_delete_event_cb(GtkWidget *win _U_, GdkEvent *event _U_, gpointer user_data)
{
funnel_text_window_t* tw = (funnel_text_window_t *)user_data;
window_destroy(GTK_WIDGET(tw->win));
tw->win = NULL;
if (tw->close_cb)
tw->close_cb(tw->close_data);
return TRUE;
}
static funnel_text_window_t* new_text_window(const gchar* title) {
funnel_text_window_t* tw = (funnel_text_window_t *)g_malloc(sizeof(funnel_text_window_t));
GtkWidget *txt_scrollw, *main_vb, *hbox;
tw->close_cb = NULL;
tw->close_data = NULL;
tw->buttons = g_ptr_array_new();
tw->win = dlg_window_new(title);
gtk_window_set_destroy_with_parent (GTK_WINDOW(tw->win), TRUE);
g_signal_connect(tw->win, "delete-event", G_CALLBACK(text_window_delete_event_cb), tw);
txt_scrollw = scrolled_window_new(NULL, NULL);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 6);
gtk_container_add(GTK_CONTAINER(tw->win), main_vb);
gtk_box_pack_start(GTK_BOX (main_vb), txt_scrollw, TRUE, TRUE, 0);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(txt_scrollw),
GTK_SHADOW_IN);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(txt_scrollw),
GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
tw->txt = gtk_text_view_new();
gtk_text_view_set_editable(GTK_TEXT_VIEW(tw->txt), FALSE);
gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(tw->txt), GTK_WRAP_WORD);
gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(tw->txt), FALSE);
gtk_text_view_set_left_margin(GTK_TEXT_VIEW(tw->txt), 4);
gtk_text_view_set_right_margin(GTK_TEXT_VIEW(tw->txt), 4);
hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_widget_show(hbox);
tw->button_hbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_button_box_set_layout(GTK_BUTTON_BOX(tw->button_hbox), GTK_BUTTONBOX_START);
gtk_box_pack_start(GTK_BOX(hbox), tw->button_hbox, TRUE, TRUE, 0);
gtk_widget_show(tw->button_hbox);
gtk_box_pack_start(GTK_BOX(main_vb), hbox, FALSE, FALSE, 0);
tw->bt_close = gtk_button_new_with_label("Close");
gtk_widget_set_can_default(tw->bt_close, TRUE);
g_object_set_data(G_OBJECT(hbox), "Close", tw->bt_close);
gtk_box_pack_end(GTK_BOX(hbox), tw->bt_close, FALSE, FALSE, 0);
gtk_widget_show(tw->bt_close);
g_signal_connect(tw->bt_close, "clicked", G_CALLBACK(text_window_cancel_button_cb), tw);
gtk_widget_grab_default(tw->bt_close);
gtk_container_add(GTK_CONTAINER(txt_scrollw), tw->txt);
gtk_window_resize(GTK_WINDOW(tw->win),400,300);
gtk_widget_show_all(tw->win);
return tw;
}
static void text_window_clear(funnel_text_window_t* tw)
{
GtkTextBuffer *buf;
if (! tw->win) return;
buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tw->txt));
gtk_text_buffer_set_text(buf, "", 0);
}
static void text_window_append(funnel_text_window_t* tw, const char *str)
{
GtkWidget *txt;
int nchars;
GtkTextBuffer *buf;
GtkTextIter iter;
if (! tw->win) return;
txt = tw->txt;
nchars = (int) strlen(str);
buf= gtk_text_view_get_buffer(GTK_TEXT_VIEW(txt));
gtk_text_buffer_get_end_iter(buf, &iter);
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_override_font(GTK_WIDGET(txt), user_font_get_regular());
#else
gtk_widget_modify_font(GTK_WIDGET(txt), user_font_get_regular());
#endif
if (!g_utf8_validate(str, -1, NULL))
printf("Invalid utf8 encoding: %s\n", str);
gtk_text_buffer_insert(buf, &iter, str, nchars);
}
static void text_window_set_text(funnel_text_window_t* tw, const gchar* text)
{
if (! tw->win) return;
text_window_clear(tw);
text_window_append(tw, text);
}
static void text_window_prepend(funnel_text_window_t* tw, const char *str _U_) {
GtkWidget *txt;
int nchars;
GtkTextBuffer *buf;
GtkTextIter iter;
if (! tw->win) return;
txt = tw->txt;
nchars = (int) strlen(str);
buf= gtk_text_view_get_buffer(GTK_TEXT_VIEW(txt));
gtk_text_buffer_get_start_iter(buf, &iter);
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_override_font(GTK_WIDGET(txt), user_font_get_regular());
#else
gtk_widget_modify_font(GTK_WIDGET(txt), user_font_get_regular());
#endif
if (!g_utf8_validate(str, -1, NULL))
printf("Invalid utf8 encoding: %s\n", str);
gtk_text_buffer_insert(buf, &iter, str, nchars);
}
static const gchar* text_window_get_text(funnel_text_window_t* tw) {
GtkWidget *txt;
GtkTextBuffer *buf;
GtkTextIter start;
GtkTextIter end;
if (! tw->win) return "";
txt = tw->txt;
buf= gtk_text_view_get_buffer(GTK_TEXT_VIEW(txt));
gtk_text_buffer_get_start_iter(buf, &start);
gtk_text_buffer_get_end_iter(buf, &end);
return gtk_text_buffer_get_text(buf, &start, &end, FALSE);
}
static void text_window_set_close_cb(funnel_text_window_t* tw, text_win_close_cb_t cb, void* data) {
tw->close_cb = cb;
tw->close_data = data;
}
static void text_window_destroy(funnel_text_window_t* tw) {
if (tw->win) {
g_signal_connect(tw->bt_close, "clicked", G_CALLBACK(unref_text_win_cancel_bt_cb), tw);
g_signal_connect(tw->win, "delete-event", G_CALLBACK(text_window_unref_del_event_cb), tw);
} else {
guint i;
for (i = 0; i < tw->buttons->len; i++) {
funnel_bt_t* cbd = (funnel_bt_t *)g_ptr_array_index(tw->buttons,i);
if (cbd->data && cbd->free_data_fcn) cbd->free_data_fcn(cbd->data);
if (cbd->free_fcn) cbd->free_fcn(cbd);
}
g_ptr_array_free(tw->buttons,TRUE);
g_free(tw);
}
}
static void text_window_set_editable(funnel_text_window_t* tw, gboolean editable){
gtk_text_view_set_editable(GTK_TEXT_VIEW(tw->txt), editable);
gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(tw->txt), editable);
}
static gboolean text_window_button_cb(GtkWidget *bt _U_, gpointer user_data)
{
funnel_bt_t* cbd = (funnel_bt_t *)user_data;
if (cbd->func) {
return cbd->func(cbd->tw,cbd->data);
} else {
return TRUE;
}
}
static void text_window_add_button(funnel_text_window_t* tw, funnel_bt_t* cbd, const gchar* label) {
GtkWidget *button;
cbd->tw = tw;
g_ptr_array_add(tw->buttons,cbd);
button = gtk_button_new_with_label(label);
gtk_widget_set_can_default(button, TRUE);
gtk_box_pack_start(GTK_BOX(tw->button_hbox), button, FALSE, FALSE, 0);
gtk_widget_show(button);
g_signal_connect(button, "clicked", G_CALLBACK(text_window_button_cb), cbd);
}
static gboolean funnel_dlg_cb(GtkWidget *win _U_, gpointer user_data)
{
struct _funnel_dlg_data* dd = (struct _funnel_dlg_data *)user_data;
guint i;
guint len = dd->entries->len;
GPtrArray* returns = g_ptr_array_new();
for(i=0; i<len; i++) {
GtkEntry* entry = (GtkEntry *)g_ptr_array_index(dd->entries,i);
g_ptr_array_add(returns,g_strdup(gtk_entry_get_text(entry)));
}
g_ptr_array_add(returns,NULL);
if (dd->dlg_cb)
dd->dlg_cb((gchar**)returns->pdata,dd->data);
window_destroy(GTK_WIDGET(dd->win));
g_ptr_array_free(returns,FALSE);
return TRUE;
}
static void funnel_cancel_btn_cb(GtkWidget *bt _U_, gpointer data) {
GtkWidget* win = (GtkWidget *)data;
window_destroy(GTK_WIDGET(win));
}
static void funnel_new_dialog(const gchar* title,
const gchar** fieldnames,
funnel_dlg_cb_t dlg_cb,
void* data) {
GtkWidget *win, *main_grid, *main_vb, *bbox, *bt_cancel, *bt_ok;
guint i;
const gchar* fieldname;
struct _funnel_dlg_data* dd = (struct _funnel_dlg_data *)g_malloc(sizeof(struct _funnel_dlg_data));
dd->entries = g_ptr_array_new();
dd->dlg_cb = dlg_cb;
dd->data = data;
for (i=0; fieldnames[i]; i++);
win = dlg_window_new(title);
dd->win = win;
gtk_window_resize(GTK_WINDOW(win),400,10*(i+2));
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_add(GTK_CONTAINER(win), main_vb);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 6);
main_grid = ws_gtk_grid_new();
gtk_box_pack_start(GTK_BOX(main_vb), main_grid, FALSE, FALSE, 0);
ws_gtk_grid_set_row_spacing(GTK_GRID(main_grid), 10);
ws_gtk_grid_set_column_spacing(GTK_GRID(main_grid), 15);
for (i = 0; (fieldname = fieldnames[i]) ; i++) {
GtkWidget *entry, *label;
label = gtk_label_new(fieldname);
gtk_misc_set_alignment(GTK_MISC(label), 1.0f, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), label, 0, i+1, 1, 1);
gtk_widget_show(label);
entry = gtk_entry_new();
g_ptr_array_add(dd->entries,entry);
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), entry, 1, i+1, 1, 1);
gtk_widget_show(entry);
}
bbox = dlg_button_row_new(GTK_STOCK_CANCEL,GTK_STOCK_OK, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
bt_ok = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(bt_ok, "clicked", G_CALLBACK(funnel_dlg_cb), dd);
gtk_widget_grab_default(bt_ok);
bt_cancel = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
g_signal_connect(bt_cancel, "clicked", G_CALLBACK(funnel_cancel_btn_cb), win);
gtk_widget_grab_default(bt_cancel);
gtk_widget_show(main_grid);
gtk_widget_show(main_vb);
gtk_widget_show(win);
}
static gchar * funnel_get_filter(void) {
return (gchar *)gtk_entry_get_text(GTK_ENTRY(main_display_filter_widget));
}
static void funnel_set_filter(const char* filter_string) {
gtk_entry_set_text(GTK_ENTRY(main_display_filter_widget), filter_string);
}
static void funnel_set_color_filter_slot(guint8 filt_nr, const gchar* filter_string) {
color_filters_set_tmp(filt_nr, (gchar *)filter_string, FALSE);
}
static void funnel_apply_filter(void) {
const char* filter_string = gtk_entry_get_text(GTK_ENTRY(main_display_filter_widget));
main_filter_packets(&cfile, filter_string, FALSE);
}
static void funnel_logger(const gchar *log_domain _U_,
GLogLevelFlags log_level _U_,
const gchar *message,
gpointer user_data _U_) {
fputs(message,stderr);
}
static void funnel_retap_packets(void) {
cf_retap_packets(&cfile);
}
static gboolean funnel_open_file(const char* fname, const char* filter, const char** err_str) {
int err = 0;
dfilter_t *rfcode = NULL;
*err_str = "no error";
switch (cfile.state) {
case FILE_CLOSED:
case FILE_READ_DONE:
case FILE_READ_ABORTED:
break;
case FILE_READ_IN_PROGRESS:
*err_str = "file read in progress";
return FALSE;
}
if (filter) {
if (!dfilter_compile(filter, &rfcode)) {
*err_str = dfilter_error_msg ? dfilter_error_msg : "cannot compile filter";
return FALSE;
}
}
if (cf_open(&cfile, fname, FALSE, &err) != CF_OK) {
*err_str = g_strerror(err);
if (rfcode != NULL) dfilter_free(rfcode);
return FALSE;
}
cfile.rfcode = rfcode;
switch (cf_read(&cfile, FALSE)) {
case CF_READ_OK:
case CF_READ_ERROR:
break;
default:
*err_str = "problem while reading file";
return FALSE;
}
return TRUE;
}
static funnel_progress_window_t* funnel_new_progress_window(const gchar* label, const gchar* task, gboolean terminate_is_stop, gboolean *stop_flag) {
return (funnel_progress_window_t*)create_progress_dlg(top_level, label, task, terminate_is_stop, stop_flag);
}
static void funnel_update_progress(funnel_progress_window_t* win, float pr, const gchar* task) {
update_progress_dlg((progdlg_t*)win, pr, task);
}
static void funnel_destroy_progress_window(funnel_progress_window_t* win) {
destroy_progress_dlg((progdlg_t*)win);
}
static void funnel_reload(void) {
if (cfile.state == FILE_READ_DONE) cf_reload(&cfile);
}
static void our_menu_callback(void* unused _U_, gpointer data) {
menu_cb_t* mcb = (menu_cb_t *)data;
mcb->callback(mcb->callback_data);
if (mcb->retap) cf_retap_packets(&cfile);
}
static const char* stat_group_name(register_stat_group_t group) {
static const value_string group_name_vals[] = {
{REGISTER_ANALYZE_GROUP_UNSORTED, "/Menubar/AnalyzeMenu|Analyze"},
{REGISTER_ANALYZE_GROUP_CONVERSATION_FILTER, "/Menubar/AnalyzeMenu|Analyze/ConversationFilterMenu|Analyze#ConversationFilter"},
{REGISTER_STAT_GROUP_UNSORTED, "/Menubar/StatisticsMenu|Statistics"},
{REGISTER_STAT_GROUP_GENERIC, "/Menubar/StatisticsMenu|Statistics"},
{REGISTER_STAT_GROUP_CONVERSATION_LIST, "/Menubar/StatisticsMenu|Statistics/ConversationListMenu|Statistics#ConversationList"},
{REGISTER_STAT_GROUP_ENDPOINT_LIST, "/Menubar/StatisticsMenu|Statistics/EndpointListMenu|Statistics#EndpointList"},
{REGISTER_STAT_GROUP_RESPONSE_TIME, "/Menubar/StatisticsMenu|Statistics/ServiceResponseTimeMenu|Statistics#ServiceResponseTime"},
{REGISTER_STAT_GROUP_TELEPHONY, "/Menubar/TelephonyMenu|Telephony"},
{REGISTER_TOOLS_GROUP_UNSORTED, "/Menubar/ToolsMenu|Tools"},
{0, NULL}
};
return val_to_str_const(group, group_name_vals, "/Menubar/ToolsMenu|Tools");
}
static void register_menu_cb(const char *name,
register_stat_group_t group,
void (*callback)(gpointer),
gpointer callback_data,
gboolean retap) {
menu_cb_t* mcb = (menu_cb_t *)g_malloc(sizeof(menu_cb_t));
const char *label = NULL, *str = NULL;
mcb->callback = callback;
mcb->callback_data = callback_data;
mcb->retap = retap;
str = strrchr(name,'/');
if(str){
label = str+1;
}else{
label = name;
}
register_lua_menu_bar_menu_items(
stat_group_name(group),
name,
NULL,
label,
NULL,
NULL,
our_menu_callback,
mcb,
TRUE,
NULL,
NULL);
}
void initialize_funnel_ops(void) {
funnel_set_funnel_ops(&funnel_ops);
}
void
register_tap_listener_gtkfunnel(void)
{
funnel_register_all_menus(register_menu_cb);
}
