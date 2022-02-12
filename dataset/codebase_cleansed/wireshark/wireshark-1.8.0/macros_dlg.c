void macros_post_update(void) {
g_free (cfile.dfilter);
cfile.dfilter = NULL;
g_signal_emit_by_name(main_display_filter_widget, "changed");
}
void macros_init (void) {
void* dfmuat;
dfilter_macro_get_uat(&dfmuat);
((uat_t*)dfmuat)->post_update_cb = macros_post_update;
}
void macros_dialog_cb(GtkWidget *w _U_, gpointer data _U_) {
void* dfmuat;
dfilter_macro_get_uat(&dfmuat);
uat_window_cb(NULL,dfmuat);
}
