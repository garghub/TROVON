GtkWidget*
stats_prefs_show(void)
{
GtkWidget *main_tb, *main_vb;
GtkWidget *tap_update_interval_te;
#ifdef HAVE_LIBPORTAUDIO
GtkWidget *rtp_player_max_visible_te;
#endif
int pos = 0;
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 7, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
main_tb = gtk_table_new(RTP_PLAYER_TABLE_ROWS, 2, FALSE);
gtk_box_pack_start(GTK_BOX(main_vb), main_tb, FALSE, FALSE, 0);
gtk_table_set_row_spacings(GTK_TABLE(main_tb), 10);
gtk_table_set_col_spacings(GTK_TABLE(main_tb), 15);
gtk_widget_show(main_tb);
tap_update_interval_te = create_preference_entry(main_tb, pos++,
"Tap update interval in ms:",
"Determines time between tap updates.", max_visible_str);
g_snprintf(update_interval_str, sizeof(update_interval_str), "%d", prefs.tap_update_interval);
gtk_entry_set_text(GTK_ENTRY(tap_update_interval_te), update_interval_str);
gtk_widget_set_tooltip_text(tap_update_interval_te, "Gap in milliseconds between updates to taps is defined here");
g_object_set_data(G_OBJECT(main_vb), TAP_UPDATE_INTERVAL_KEY, tap_update_interval_te);
#ifdef HAVE_LIBPORTAUDIO
rtp_player_max_visible_te = create_preference_entry(main_tb, pos++,
"Max visible channels in RTP Player:",
"Determines maximum height of RTP Player window.", max_visible_str);
g_snprintf(max_visible_str, sizeof(max_visible_str), "%d", prefs.rtp_player_max_visible);
gtk_entry_set_text(GTK_ENTRY(rtp_player_max_visible_te), max_visible_str);
gtk_widget_set_tooltip_text(rtp_player_max_visible_te, "Maximum height of RTP Player window is defined here.");
g_object_set_data(G_OBJECT(main_vb), RTP_PLAYER_MAX_VISIBLE_KEY, rtp_player_max_visible_te);
#endif
gtk_widget_show_all(main_vb);
return main_vb;
}
void
stats_prefs_fetch(GtkWidget *w _U_)
{
GtkWidget *tap_update_interval_te;
#ifdef HAVE_LIBPORTAUDIO
GtkWidget *rtp_player_max_visible_te;
#endif
tap_update_interval_te = (GtkWidget *)g_object_get_data(G_OBJECT(w), TAP_UPDATE_INTERVAL_KEY);
prefs.tap_update_interval = strtol(gtk_entry_get_text(
GTK_ENTRY(tap_update_interval_te)), NULL, 10);
if (prefs.tap_update_interval < 100 || prefs.tap_update_interval > 10000) {
prefs.tap_update_interval = 3000;
}
#ifdef HAVE_LIBPORTAUDIO
rtp_player_max_visible_te = (GtkWidget *)g_object_get_data(G_OBJECT(w), RTP_PLAYER_MAX_VISIBLE_KEY);
prefs.rtp_player_max_visible = strtol(gtk_entry_get_text(
GTK_ENTRY(rtp_player_max_visible_te)), NULL, 10);
if (prefs.rtp_player_max_visible < 1 || prefs.rtp_player_max_visible > 10)
prefs.rtp_player_max_visible = RTP_PLAYER_DEFAULT_VISIBLE;
#endif
}
void
stats_prefs_apply(GtkWidget *w _U_)
{
#if defined(_WIN32)
reset_tap_update_timer();
#endif
}
void
stats_prefs_destroy(GtkWidget *w _U_)
{
}
