static funnel_text_window_t* new_text_window(const gchar* title) {
funnel_text_window_t* tw = g_malloc(sizeof(funnel_text_window_t));
tw->title = g_strdup(title);
tw->text = g_string_new("");
if (!text_windows)
text_windows = g_ptr_array_new();
g_ptr_array_add(text_windows,tw);
return tw;
}
static void text_window_clear(funnel_text_window_t* tw) {
g_string_free(tw->text,TRUE);
tw->text = g_string_new("");
}
static void text_window_append(funnel_text_window_t* tw, const char *text ) {
g_string_append(tw->text,text);
}
static void text_window_set_text(funnel_text_window_t* tw, const char* text) {
g_string_free(tw->text,TRUE);
tw->text = g_string_new(text);
}
static void text_window_prepend(funnel_text_window_t* tw, const char *text) {
g_string_prepend(tw->text,text);
}
static const gchar* text_window_get_text(funnel_text_window_t* tw) {
return tw->text->str;
}
static void funnel_logger(const gchar *log_domain _U_,
GLogLevelFlags log_level _U_,
const gchar *message,
gpointer user_data _U_) {
fputs(message,stderr);
}
void initialize_funnel_ops(void) {
funnel_set_funnel_ops(&funnel_ops);
}
void funnel_dump_all_text_windows(void) {
guint i;
if (!text_windows) return;
for ( i = 0 ; i < text_windows->len; i++) {
funnel_text_window_t* tw = g_ptr_array_index(text_windows,i);
printf("\n========================== %s "
"==========================\n%s\n",tw->title,tw->text->str);
g_ptr_array_remove_index(text_windows,i);
g_free(tw->title);
g_string_free(tw->text,TRUE);
g_free(tw);
}
}
void
register_tap_listener_gtkfunnel(void)
{
#if 0
funnel_register_all_menus(register_menu_cb);
#endif
}
