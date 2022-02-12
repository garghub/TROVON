static GtkWidget *
display_simple_dialog(gint type, gint btn_mask, char *message)
{
GtkWidget *win, *main_vb, *top_hb, *msg_vb, *type_pm, *msg_label, *ask_cb,
*bbox, *ok_bt, *yes_bt, *bt, *save_bt, *dont_save_bt;
switch (type) {
case ESD_TYPE_WARN :
type_pm = gtk_image_new_from_stock( GTK_STOCK_DIALOG_INFO, GTK_ICON_SIZE_DIALOG);
break;
case ESD_TYPE_CONFIRMATION:
type_pm = gtk_image_new_from_stock( GTK_STOCK_DIALOG_WARNING, GTK_ICON_SIZE_DIALOG);
break;
case ESD_TYPE_ERROR:
type_pm = gtk_image_new_from_stock( GTK_STOCK_DIALOG_ERROR, GTK_ICON_SIZE_DIALOG);
break;
case ESD_TYPE_STOP :
type_pm = gtk_image_new_from_stock( GTK_STOCK_STOP, GTK_ICON_SIZE_DIALOG);
break;
case ESD_TYPE_INFO :
default :
type_pm = gtk_image_new_from_stock( GTK_STOCK_DIALOG_INFO, GTK_ICON_SIZE_DIALOG);
break;
}
if(btn_mask == ESD_BTN_NONE) {
win = splash_window_new();
} else {
#ifdef _WIN32
win = dlg_window_new("Wireshark");
#else
win = dlg_window_new("");
#endif
}
gtk_window_set_modal(GTK_WINDOW(win), TRUE);
gtk_container_set_border_width(GTK_CONTAINER(win), 6);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 12, FALSE);
gtk_container_add(GTK_CONTAINER(win), main_vb);
gtk_widget_show(main_vb);
top_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 12, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 6);
gtk_container_add(GTK_CONTAINER(main_vb), top_hb);
gtk_widget_show(top_hb);
gtk_misc_set_alignment (GTK_MISC (type_pm), 0.5f, 0.0f);
gtk_container_add(GTK_CONTAINER(top_hb), type_pm);
gtk_widget_show(type_pm);
msg_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
gtk_box_set_spacing(GTK_BOX(msg_vb), 24);
gtk_container_add(GTK_CONTAINER(top_hb), msg_vb);
gtk_widget_show(msg_vb);
msg_label = gtk_label_new(message);
gtk_label_set_markup(GTK_LABEL(msg_label), message);
gtk_label_set_selectable(GTK_LABEL(msg_label), TRUE);
g_object_set(gtk_widget_get_settings(msg_label),
"gtk-label-select-on-focus", FALSE, NULL);
gtk_label_set_justify(GTK_LABEL(msg_label), GTK_JUSTIFY_FILL);
gtk_misc_set_alignment (GTK_MISC (type_pm), 0.5f, 0.0f);
gtk_container_add(GTK_CONTAINER(msg_vb), msg_label);
gtk_label_set_line_wrap(GTK_LABEL(msg_label), TRUE);
gtk_widget_show(msg_label);
if(btn_mask == ESD_BTN_NONE) {
gtk_widget_show(win);
return win;
}
ask_cb = gtk_check_button_new_with_label("replace with text...");
gtk_container_add(GTK_CONTAINER(msg_vb), ask_cb);
g_object_set_data(G_OBJECT(win), CHECK_BUTTON, ask_cb);
switch(btn_mask) {
case(ESD_BTN_OK):
bbox = dlg_button_row_new(GTK_STOCK_OK, NULL);
break;
case(ESD_BTN_OK | ESD_BTN_CANCEL):
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_CANCEL, NULL);
break;
case(ESD_BTN_CLEAR | ESD_BTN_CANCEL):
bbox = dlg_button_row_new(GTK_STOCK_CLEAR, GTK_STOCK_CANCEL, NULL);
break;
case(ESD_BTNS_YES_NO_CANCEL):
bbox = dlg_button_row_new(GTK_STOCK_YES, GTK_STOCK_NO, GTK_STOCK_CANCEL, NULL);
break;
case(ESD_BTNS_SAVE_DONTSAVE_CANCEL):
bbox = dlg_button_row_new(GTK_STOCK_SAVE, WIRESHARK_STOCK_DONT_SAVE, GTK_STOCK_CANCEL, NULL);
break;
case(ESD_BTNS_SAVE_QUIT_DONTSAVE_CANCEL):
bbox = dlg_button_row_new(GTK_STOCK_SAVE, WIRESHARK_STOCK_QUIT_DONT_SAVE, GTK_STOCK_CANCEL, NULL);
break;
case (ESD_BTNS_QUIT_DONTSAVE_CANCEL):
bbox = dlg_button_row_new(WIRESHARK_STOCK_QUIT_DONT_SAVE, GTK_STOCK_CANCEL, NULL);
break;
case(ESD_BTNS_YES_NO):
bbox = dlg_button_row_new(GTK_STOCK_YES, GTK_STOCK_NO, NULL);
break;
default:
g_assert_not_reached();
bbox = NULL;
break;
}
gtk_container_add(GTK_CONTAINER(main_vb), bbox);
gtk_widget_show(bbox);
ok_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
if(ok_bt) {
g_object_set_data(G_OBJECT(ok_bt), CALLBACK_BTN_KEY, GINT_TO_POINTER(ESD_BTN_OK));
g_signal_connect(ok_bt, "clicked", G_CALLBACK(simple_dialog_cancel_cb), win);
}
save_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_SAVE);
if (save_bt) {
g_object_set_data(G_OBJECT(save_bt), CALLBACK_BTN_KEY, GINT_TO_POINTER(ESD_BTN_SAVE));
g_signal_connect(save_bt, "clicked", G_CALLBACK(simple_dialog_cancel_cb), win);
}
dont_save_bt = g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_DONT_SAVE);
if (dont_save_bt) {
g_object_set_data(G_OBJECT(dont_save_bt), CALLBACK_BTN_KEY, GINT_TO_POINTER(ESD_BTN_DONT_SAVE));
g_signal_connect(dont_save_bt, "clicked", G_CALLBACK(simple_dialog_cancel_cb), win);
}
dont_save_bt = g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_QUIT_DONT_SAVE);
if (dont_save_bt) {
g_object_set_data(G_OBJECT(dont_save_bt), CALLBACK_BTN_KEY, GINT_TO_POINTER(ESD_BTN_QUIT_DONT_SAVE));
g_signal_connect(dont_save_bt, "clicked", G_CALLBACK(simple_dialog_cancel_cb), win);
}
bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLEAR);
if(bt) {
g_object_set_data(G_OBJECT(bt), CALLBACK_BTN_KEY, GINT_TO_POINTER(ESD_BTN_CLEAR));
g_signal_connect(bt, "clicked", G_CALLBACK(simple_dialog_cancel_cb), win);
}
yes_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_YES);
if(yes_bt) {
g_object_set_data(G_OBJECT(yes_bt), CALLBACK_BTN_KEY, GINT_TO_POINTER(ESD_BTN_YES));
g_signal_connect(yes_bt, "clicked", G_CALLBACK(simple_dialog_cancel_cb), win);
}
bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_NO);
if(bt) {
g_object_set_data(G_OBJECT(bt), CALLBACK_BTN_KEY, GINT_TO_POINTER(ESD_BTN_NO));
g_signal_connect(bt, "clicked", G_CALLBACK(simple_dialog_cancel_cb), win);
}
bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
if(bt) {
g_object_set_data(G_OBJECT(bt), CALLBACK_BTN_KEY, GINT_TO_POINTER(ESD_BTN_CANCEL));
window_set_cancel_button(win, bt, simple_dialog_cancel_cb);
}
if(!bt) {
if(yes_bt) {
window_set_cancel_button(win, yes_bt, simple_dialog_cancel_cb);
} else {
window_set_cancel_button(win, ok_bt, simple_dialog_cancel_cb);
}
}
dlg_button_focus_nth(bbox, 0);
gtk_widget_show(win);
return win;
}
void
display_queued_messages(void)
{
queued_message_t *queued_message;
while (message_queue != NULL) {
queued_message = message_queue->data;
message_queue = g_slist_remove(message_queue, queued_message);
display_simple_dialog(queued_message->type, queued_message->btn_mask,
queued_message->message);
g_free(queued_message->message);
g_free(queued_message);
}
}
gpointer
vsimple_dialog(ESD_TYPE_E type, gint btn_mask, const gchar *msg_format, va_list ap)
{
gchar *message;
queued_message_t *queued_message;
GtkWidget *win;
GdkWindowState state = 0;
message = g_strdup_vprintf(msg_format, ap);
if (top_level != NULL) {
state = gdk_window_get_state(gtk_widget_get_window(top_level));
}
if (top_level == NULL || state & GDK_WINDOW_STATE_ICONIFIED
|| state & GDK_WINDOW_STATE_WITHDRAWN) {
queued_message = g_malloc(sizeof (queued_message_t));
queued_message->type = type;
queued_message->btn_mask = btn_mask;
queued_message->message = message;
message_queue = g_slist_append(message_queue, queued_message);
return NULL;
}
display_queued_messages();
win = display_simple_dialog(type, btn_mask, message);
g_free(message);
return win;
}
gpointer
simple_dialog(ESD_TYPE_E type, gint btn_mask, const gchar *msg_format, ...)
{
va_list ap;
gpointer ret;
va_start(ap, msg_format);
ret = vsimple_dialog(type, btn_mask, msg_format, ap);
va_end(ap);
return ret;
}
static void
simple_dialog_cancel_cb(GtkWidget *w, gpointer win) {
gint button = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(w), CALLBACK_BTN_KEY));
simple_dialog_cb_t callback_fct = g_object_get_data(G_OBJECT(win), CALLBACK_FCT_KEY);
gpointer data = g_object_get_data(G_OBJECT(win), CALLBACK_DATA_KEY);
if (callback_fct)
(callback_fct) (win, button, data);
window_destroy(GTK_WIDGET(win));
}
void
simple_dialog_close(gpointer dialog)
{
window_destroy(GTK_WIDGET(dialog));
}
void simple_dialog_set_cb(gpointer dialog, simple_dialog_cb_t callback_fct, gpointer data)
{
g_object_set_data(G_OBJECT(GTK_WIDGET(dialog)), CALLBACK_FCT_KEY, callback_fct);
g_object_set_data(G_OBJECT(GTK_WIDGET(dialog)), CALLBACK_DATA_KEY, data);
}
void simple_dialog_check_set(gpointer dialog, gchar *text _U_) {
GtkWidget *ask_cb = g_object_get_data(G_OBJECT(dialog), CHECK_BUTTON);
gtk_button_set_label(GTK_BUTTON(ask_cb), text);
gtk_widget_show(ask_cb);
}
gboolean simple_dialog_check_get(gpointer dialog) {
GtkWidget *ask_cb = g_object_get_data(G_OBJECT(GTK_WIDGET(dialog)), CHECK_BUTTON);
return gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ask_cb));
}
char *
simple_dialog_primary_start(void) {
return "<span weight=\"bold\" size=\"larger\">";
}
char *
simple_dialog_primary_end(void) {
return "</span>";
}
char *
simple_dialog_format_message(const char *msg)
{
char *str;
if (msg) {
str = xml_escape(msg);
} else {
str = NULL;
}
return str;
}
static void
do_simple_message_box(ESD_TYPE_E type, gboolean *notagain,
const char *secondary_msg, const char *msg_format,
va_list ap)
{
GtkMessageType gtk_message_type;
gchar *message;
GtkWidget *msg_dialog;
GtkWidget *checkbox = NULL;
if (notagain != NULL) {
if (*notagain) {
return;
}
}
switch (type) {
case ESD_TYPE_INFO:
gtk_message_type = GTK_MESSAGE_INFO;
break;
case ESD_TYPE_WARN:
gtk_message_type = GTK_MESSAGE_WARNING;
break;
case ESD_TYPE_ERROR:
gtk_message_type = GTK_MESSAGE_ERROR;
break;
default:
g_assert_not_reached();
gtk_message_type = GTK_MESSAGE_INFO;
break;
}
message = g_strdup_vprintf(msg_format, ap);
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(top_level),
GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,
gtk_message_type,
GTK_BUTTONS_OK,
"%s", message);
g_free(message);
if (secondary_msg != NULL)
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
"%s", secondary_msg);
if (notagain != NULL) {
checkbox = gtk_check_button_new_with_label("Don't show this message again.");
gtk_container_set_border_width(GTK_CONTAINER(checkbox), 12);
gtk_box_pack_start(GTK_BOX(gtk_dialog_get_content_area(GTK_DIALOG(msg_dialog))),
checkbox, TRUE, TRUE, 0);
gtk_widget_show(checkbox);
}
gtk_dialog_run(GTK_DIALOG(msg_dialog));
if (notagain != NULL) {
*notagain = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbox));
}
gtk_widget_destroy(msg_dialog);
}
void
simple_message_box(ESD_TYPE_E type, gboolean *notagain,
const char *secondary_msg, const char *msg_format, ...)
{
va_list ap;
va_start(ap, msg_format);
do_simple_message_box(type, notagain, secondary_msg, msg_format, ap);
va_end(ap);
}
void
vsimple_error_message_box(const char *msg_format, va_list ap)
{
do_simple_message_box(ESD_TYPE_ERROR, NULL, NULL, msg_format, ap);
}
void
simple_error_message_box(const char *msg_format, ...)
{
va_list ap;
va_start(ap, msg_format);
do_simple_message_box(ESD_TYPE_ERROR, NULL, NULL, msg_format, ap);
va_end(ap);
}
