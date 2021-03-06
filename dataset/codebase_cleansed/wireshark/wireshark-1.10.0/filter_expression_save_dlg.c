void
filter_expression_save_dlg_init(gpointer filter_tb, gpointer filter_te)
{
struct filter_expression *fe;
_filter_tb = (GtkWidget *)filter_tb;
_filter_te = (GtkWidget *)filter_te;
fe = *pfilter_expression_head;
while (fe != NULL) {
filter_button_add(NULL, NULL, fe);
fe = fe->next;
}
}
void
filter_expression_nuke(struct filter_expression *fe)
{
if (fe == NULL)
return;
filter_expression_nuke(fe->next);
g_free(fe->label);
g_free(fe->expression);
}
void
filter_expression_reinit(int what)
{
struct filter_expression *fe, *prevhead;
if ((what & FILTER_EXPRESSION_REINIT_DESTROY) != 0) {
fe = *pfilter_expression_head;
while (fe != NULL) {
if (fe->button != NULL) {
gtk_widget_destroy((GtkWidget *)fe->button);
fe->button = NULL;
}
fe = fe->next;
}
}
if (what == FILTER_EXPRESSION_REINIT_DESTROY) {
filter_expression_nuke(*pfilter_expression_head);
*pfilter_expression_head = NULL;
return;
}
if ((what & FILTER_EXPRESSION_REINIT_CREATE) != 0) {
gint maxindx = -1, indx;
fe = *pfilter_expression_head;
while (fe != NULL) {
maxindx = MAX(maxindx, fe->index);
fe = fe->next;
}
prevhead = *pfilter_expression_head;
*pfilter_expression_head = NULL;
for (indx = 0; indx <= maxindx; indx++) {
if (prevhead != NULL) {
fe = prevhead;
while (fe != NULL && fe->index != indx)
fe = fe->next;
}
if (fe == NULL)
continue;
if (fe->deleted)
continue;
filter_expression_new(fe->label, fe->expression,
fe->enabled);
}
filter_expression_nuke(prevhead);
fe = *pfilter_expression_head;
while (fe != NULL) {
if (fe->enabled && !fe->deleted)
filter_button_add(NULL, NULL, fe);
fe = fe->next;
}
}
}
static int
filter_button_add(const char *label, const char *expr, struct filter_expression *newfe)
{
struct filter_expression *fe;
if (newfe == NULL)
fe = filter_expression_new(label, expr, TRUE);
else
fe = newfe;
if (fe->enabled == FALSE)
return(0);
fe->button = gtk_tool_button_new(NULL, fe->label);
g_signal_connect(fe->button, "clicked", G_CALLBACK(filter_button_cb),
NULL);
gtk_widget_set_sensitive(GTK_WIDGET(fe->button), FALSE);
gtk_widget_show(GTK_WIDGET(fe->button));
gtk_toolbar_insert(GTK_TOOLBAR(_filter_tb), (GtkToolItem *)fe->button, -1);
gtk_widget_set_sensitive(GTK_WIDGET(fe->button), TRUE);
gtk_widget_set_tooltip_text(GTK_WIDGET(fe->button), fe->expression);
return(0);
}
static void
filter_button_cb(GtkWidget *this_button, gpointer parent_w _U_)
{
struct filter_expression *fe;
fe = *pfilter_expression_head;
while (fe != NULL) {
if ((void *)fe->button == (void *)this_button) {
gtk_entry_set_text(GTK_ENTRY(_filter_te),
fe->expression);
main_filter_packets(&cfile, fe->expression, FALSE);
return;
}
fe = fe->next;
}
printf("No Callback\n");
}
void
filter_expression_save_dlg(gpointer data)
{
GtkWidget *main_vb, *main_filter_save_hb, *filter_save_frame,
*filter_save_type_vb, *filter_save_type_hb, *entry_hb,
*bbox, *ok_bt, *cancel_bt, *help_bt, *filter_text_box,
*label_text_box;
const char *expr;
expr = gtk_entry_get_text(GTK_ENTRY(data));
if (filter_save_frame_w != NULL) {
reactivate_window(filter_save_frame_w);
return;
}
filter_save_frame_w = dlg_window_new("Wireshark: Save Filter");
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(filter_save_frame_w), main_vb);
gtk_widget_show(main_vb);
main_filter_save_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX (main_vb), main_filter_save_hb, TRUE, TRUE, 0);
gtk_widget_show(main_filter_save_hb);
filter_save_frame = gtk_frame_new("Save Filter as...");
gtk_box_pack_start(GTK_BOX(main_filter_save_hb), filter_save_frame,
TRUE, TRUE, 0);
gtk_widget_show(filter_save_frame);
filter_save_type_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(filter_save_type_vb), 3);
gtk_container_add(GTK_CONTAINER(filter_save_frame),
filter_save_type_vb);
gtk_widget_show(filter_save_type_vb);
filter_save_type_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX (filter_save_type_vb), filter_save_type_hb, TRUE, TRUE, 0);
gtk_widget_show(filter_save_type_hb);
entry_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(filter_save_type_vb), entry_hb, FALSE,
FALSE, 0);
gtk_widget_show(entry_hb);
filter_text_box = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(entry_hb), filter_text_box, TRUE, TRUE, 0);
g_signal_connect(filter_text_box, "changed", G_CALLBACK(filter_te_syntax_check_cb), NULL);
g_signal_connect(filter_text_box, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
g_signal_connect(filter_save_frame_w, "key-press-event", G_CALLBACK (filter_parent_dlg_key_pressed_cb), NULL);
gtk_entry_set_text(GTK_ENTRY(filter_text_box), expr);
gtk_widget_show(filter_text_box);
label_text_box = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(entry_hb), label_text_box, TRUE, TRUE, 0);
gtk_entry_set_text(GTK_ENTRY(label_text_box), "Filter");
gtk_widget_show(label_text_box);
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_CANCEL,
GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(filter_save_ok_cb),
filter_save_frame_w);
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
g_signal_connect(cancel_bt, "clicked", G_CALLBACK(filter_save_close_cb),
filter_save_frame_w);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb),
(gpointer)HELP_FILTER_SAVE_DIALOG);
g_object_set_data(G_OBJECT(filter_save_frame_w),
E_FILTER_SAVE_EXPR_KEY, filter_text_box);
g_object_set_data(G_OBJECT(filter_save_frame_w),
E_FILTER_SAVE_LABEL_KEY, label_text_box);
dlg_set_activate(label_text_box, ok_bt);
gtk_widget_grab_focus(label_text_box);
g_signal_connect(filter_save_frame_w, "delete_event",
G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(filter_save_frame_w, "destroy",
G_CALLBACK(filter_save_frame_destroy_cb), NULL);
gtk_widget_show(filter_save_frame_w);
window_present(filter_save_frame_w);
}
static void
filter_save_ok_cb(GtkWidget *ok_bt _U_, GtkWindow *parent_w)
{
GtkWidget *expr_te, *label_te;
const char *expr, *label;
expr_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_FILTER_SAVE_EXPR_KEY);
label_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_FILTER_SAVE_LABEL_KEY);
expr = gtk_entry_get_text(GTK_ENTRY(expr_te));
label = gtk_entry_get_text(GTK_ENTRY(label_te));
if (filter_button_add(label, expr, NULL) == 0) {
prefs_main_write();
filter_save_close_cb(NULL, parent_w);
}
}
static void
filter_save_close_cb(GtkWidget *close_bt _U_, gpointer parent_w)
{
gtk_grab_remove(GTK_WIDGET(parent_w));
window_destroy(GTK_WIDGET(parent_w));
}
static void
filter_save_frame_destroy_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
filter_save_frame_w = NULL;
}
