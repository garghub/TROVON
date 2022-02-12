GtkWidget * text_page_new(const char *absolute_path)
{
GtkWidget *page_vb, *txt_scrollw, *txt;
page_vb =ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(page_vb), 1);
txt_scrollw = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(txt_scrollw),
GTK_SHADOW_IN);
gtk_box_pack_start(GTK_BOX(page_vb), txt_scrollw, TRUE, TRUE, 0);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(txt_scrollw),
GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
txt = gtk_text_view_new();
gtk_text_view_set_editable(GTK_TEXT_VIEW(txt), FALSE);
gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(txt), GTK_WRAP_WORD);
gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(txt), FALSE);
g_object_set_data(G_OBJECT(page_vb), TEXT_KEY, txt);
text_page_set_text(page_vb, absolute_path);
gtk_container_add(GTK_CONTAINER(txt_scrollw), txt);
gtk_widget_show(txt_scrollw);
gtk_widget_show(txt);
return page_vb;
}
static void text_page_insert(GtkWidget *page, const char *buffer, int nchars)
{
GtkWidget *txt = (GtkWidget *)g_object_get_data(G_OBJECT(page), TEXT_KEY);
GtkTextBuffer *buf= gtk_text_view_get_buffer(GTK_TEXT_VIEW(txt));
GtkTextIter iter;
gtk_text_buffer_get_end_iter(buf, &iter);
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_override_font(GTK_WIDGET(txt), user_font_get_regular());
#else
gtk_widget_modify_font(GTK_WIDGET(txt), user_font_get_regular());
#endif
if (!g_utf8_validate(buffer, -1, NULL))
printf("Invalid utf8 encoding: %s\n", buffer);
gtk_text_buffer_insert(buf, &iter, buffer, nchars);
}
static void text_page_set_text(GtkWidget *page, const char *absolute_path)
{
FILE *text_file;
char line[4096+1];
text_file = ws_fopen(absolute_path, "r");
if (text_file != NULL) {
while (fgets(line, sizeof line, text_file) != NULL) {
text_page_insert(page, line, (int) strlen(line));
}
if(ferror(text_file)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Error reading file \"%s\": %s",
absolute_path, g_strerror(errno));
}
fclose(text_file);
} else {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Could not open file \"%s\": %s",
absolute_path, g_strerror(errno));
}
}
static void text_page_clear(GtkWidget *page)
{
GtkTextBuffer *buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(g_object_get_data(G_OBJECT(page), TEXT_KEY)));
gtk_text_buffer_set_text(buf, "", 0);
}
void text_page_redraw(GtkWidget *page, const char *absolute_path)
{
text_page_clear(page);
text_page_set_text(page, absolute_path);
}
