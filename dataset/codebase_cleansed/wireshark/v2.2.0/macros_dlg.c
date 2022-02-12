void macros_post_update(void) {
dfilter_t *dfp;
if (!dfilter_compile(cfile.dfilter, &dfp, NULL)) {
g_free(cfile.dfilter);
cfile.dfilter = NULL;
} else if (dfp) {
g_free(dfp);
}
g_signal_emit_by_name(main_display_filter_widget, "changed");
}
void macros_init (void) {
uat_t* dfmuat;
dfilter_macro_get_uat(&dfmuat);
dfmuat->post_update_cb = macros_post_update;
}
void macros_dialog_cb(GtkWidget *w _U_, gpointer data _U_) {
uat_t* dfmuat;
dfilter_macro_get_uat(&dfmuat);
uat_window_cb(NULL,dfmuat);
}
