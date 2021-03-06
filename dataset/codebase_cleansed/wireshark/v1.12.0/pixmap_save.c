void
pixmap_save_cb(GtkWidget *w, gpointer pixmap_ptr _U_)
{
GtkWidget *save_as_w;
#if GTK_CHECK_VERSION(2,22,0)
surface_info_t *surface_info = (surface_info_t *)g_object_get_data(G_OBJECT(w), "surface-info");
#else
GdkPixmap *pixmap = (GdkPixmap *)g_object_get_data(G_OBJECT(w), "pixmap");
#endif
GdkPixbuf *pixbuf;
GdkPixbufFormat *pixbuf_format;
GtkWidget *main_vb, *save_as_type_hb, *type_lb, *type_cm;
GSList *file_formats,*ffp;
GtkWidget *parent;
gchar *format_name;
guint format_index = 0;
guint default_index = 0;
gchar *filename, *file_type;
GError *error = NULL;
gboolean ret;
GtkWidget *msg_dialog;
#if GTK_CHECK_VERSION(2,22,0)
pixbuf = gdk_pixbuf_get_from_surface (surface_info->surface,
0, 0, surface_info->width, surface_info->height);
#else
pixbuf = gdk_pixbuf_get_from_drawable(NULL, pixmap, NULL,
0, 0, 0, 0, -1, -1);
#endif
if(!pixbuf) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%sCould not get image from graph%s",
simple_dialog_primary_start(),
simple_dialog_primary_end());
return;
}
parent = gtk_widget_get_toplevel(w);
save_as_w = file_selection_new("Wireshark: Save Graph As ...",
GTK_WINDOW(parent),
FILE_SELECTION_SAVE);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
file_selection_set_extra_widget(save_as_w, main_vb);
gtk_widget_show(main_vb);
save_as_type_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start(GTK_BOX(main_vb), save_as_type_hb, FALSE, FALSE, 0);
gtk_widget_show(save_as_type_hb);
type_lb = gtk_label_new("File type: ");
gtk_box_pack_start(GTK_BOX(save_as_type_hb), type_lb, FALSE, FALSE, 0);
gtk_widget_show(type_lb);
type_cm = gtk_combo_box_text_new();
gtk_box_pack_start(GTK_BOX(save_as_type_hb), type_cm, FALSE, FALSE, 0);
file_formats = gdk_pixbuf_get_formats();
ffp = file_formats;
while(ffp) {
pixbuf_format = (GdkPixbufFormat *)ffp->data;
if (gdk_pixbuf_format_is_writable(pixbuf_format)) {
format_name = gdk_pixbuf_format_get_name(pixbuf_format);
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(type_cm),
format_name);
if (!(g_ascii_strcasecmp(format_name, "png")))
default_index = format_index;
format_index++;
}
ffp = g_slist_next(ffp);
}
g_slist_free(file_formats);
gtk_combo_box_set_active(GTK_COMBO_BOX(type_cm), default_index);
gtk_widget_show(type_cm);
gtk_widget_show(save_as_w);
window_present(save_as_w);
for (;;) {
if (gtk_dialog_run(GTK_DIALOG(save_as_w)) != GTK_RESPONSE_ACCEPT) {
window_destroy(save_as_w);
return;
}
filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(save_as_w));
if (test_for_directory(filename) == EISDIR) {
set_last_open_dir(filename);
g_free(filename);
file_selection_set_current_folder(save_as_w,
get_last_open_dir());
gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(save_as_w), "");
continue;
}
file_type = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(type_cm));
ret = gdk_pixbuf_save(pixbuf, filename, file_type, &error, NULL);
g_free(filename);
g_free(file_type);
if (!ret) {
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(save_as_w),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_ERROR,
GTK_BUTTONS_OK,
"%s", error->message);
gtk_dialog_run(GTK_DIALOG(msg_dialog));
gtk_widget_destroy(msg_dialog);
continue;
}
window_destroy(save_as_w);
return;
}
}
