progdlg_t *
create_progress_dlg(const gpointer top_level_window _U_, const gchar *task_title, const gchar *item_title,
gboolean terminate_is_stop, gboolean *stop_flag)
{
progdlg_t *dlg;
GtkWidget *dlg_w, *main_vb, *title_lb, *status_lb, *elapsed_lb, *time_left_lb, *percentage_lb;
GtkWidget *prog_bar, *bbox, *cancel_bt;
GtkWidget *static_vb, *tmp_lb, *main_hb, *dynamic_vb, *percentage_hb;
gchar *task_title_dup;
gchar *item_title_dup;
dlg = (progdlg_t *)g_malloc(sizeof (progdlg_t));
item_title_dup = g_strdup(item_title);
if (strlen(item_title_dup) > 110) {
g_strlcpy(&item_title_dup[100], "...", 4);
}
dlg->title = g_strdup_printf("%s: %s", task_title, item_title_dup);
dlg_w = dlg_window_new(dlg->title);
gtk_window_set_modal(GTK_WINDOW(dlg_w), TRUE);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 1, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(dlg_w), main_vb);
static_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 1, FALSE);
task_title_dup = g_strdup_printf ("%s:", task_title);
tmp_lb = gtk_label_new(task_title_dup);
gtk_misc_set_alignment(GTK_MISC(tmp_lb), 1.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(static_vb), tmp_lb, FALSE, TRUE, 3);
tmp_lb = gtk_label_new("Status:");
gtk_misc_set_alignment(GTK_MISC(tmp_lb), 1.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(static_vb), tmp_lb, FALSE, TRUE, 3);
tmp_lb = gtk_label_new("Elapsed Time:");
gtk_misc_set_alignment(GTK_MISC(tmp_lb), 1.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(static_vb), tmp_lb, FALSE, TRUE, 3);
tmp_lb = gtk_label_new("Time Left:");
gtk_misc_set_alignment(GTK_MISC(tmp_lb), 1.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(static_vb), tmp_lb, FALSE, TRUE, 3);
tmp_lb = gtk_label_new("Progress:");
gtk_misc_set_alignment(GTK_MISC(tmp_lb), 1.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(static_vb), tmp_lb, FALSE, TRUE, 3);
dynamic_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 1, FALSE);
title_lb = gtk_label_new(item_title_dup);
gtk_box_pack_start(GTK_BOX(dynamic_vb), title_lb, FALSE, TRUE, 3);
gtk_misc_set_alignment(GTK_MISC(title_lb), 0.0f, 0.0f);
gtk_misc_set_padding(GTK_MISC(title_lb), 0, 0);
status_lb = gtk_label_new("");
gtk_box_pack_start(GTK_BOX(dynamic_vb), status_lb, FALSE, TRUE, 3);
gtk_misc_set_alignment(GTK_MISC(status_lb), 0.0f, 0.0f);
gtk_misc_set_padding(GTK_MISC(status_lb), 0, 0);
dlg->status_lb = (GtkLabel *) status_lb;
elapsed_lb = gtk_label_new("00:00");
gtk_box_pack_start(GTK_BOX(dynamic_vb), elapsed_lb, FALSE, TRUE, 3);
gtk_misc_set_alignment(GTK_MISC(elapsed_lb), 0.0f, 0.0f);
gtk_misc_set_padding(GTK_MISC(elapsed_lb), 0, 0);
dlg->elapsed_lb = (GtkLabel *) elapsed_lb;
time_left_lb = gtk_label_new("--:--");
gtk_box_pack_start(GTK_BOX(dynamic_vb), time_left_lb, FALSE, TRUE, 3);
gtk_misc_set_alignment(GTK_MISC(time_left_lb), 0.0f, 0.0f);
gtk_misc_set_padding(GTK_MISC(time_left_lb), 0, 0);
dlg->time_left_lb = (GtkLabel *) time_left_lb;
percentage_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1, FALSE);
gtk_box_pack_start(GTK_BOX(dynamic_vb), percentage_hb, FALSE, TRUE, 3);
prog_bar = gtk_progress_bar_new();
gtk_box_pack_start(GTK_BOX(percentage_hb), prog_bar, FALSE, TRUE, 3);
percentage_lb = gtk_label_new(" 0%");
gtk_misc_set_alignment(GTK_MISC(percentage_lb), 0.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(percentage_hb), percentage_lb, FALSE, TRUE, 3);
dlg->percentage_lb = (GtkLabel *) percentage_lb;
g_object_set_data(G_OBJECT(dlg_w), PROG_BAR_KEY, prog_bar);
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1, FALSE);
gtk_box_pack_start(GTK_BOX(main_hb), static_vb, FALSE, TRUE, 3);
gtk_box_pack_start(GTK_BOX(main_hb), dynamic_vb, FALSE, TRUE, 3);
gtk_box_pack_start(GTK_BOX(main_vb), main_hb, FALSE, TRUE, 3);
bbox = dlg_button_row_new(terminate_is_stop ? GTK_STOCK_STOP :
GTK_STOCK_CANCEL, NULL);
gtk_container_add(GTK_CONTAINER(main_vb), bbox);
gtk_widget_show(bbox);
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), terminate_is_stop ? GTK_STOCK_STOP :
GTK_STOCK_CANCEL);
gtk_widget_grab_default(cancel_bt);
g_signal_connect(cancel_bt, "clicked", G_CALLBACK(stop_cb), stop_flag);
g_signal_connect(dlg_w, "delete_event", G_CALLBACK(delete_event_cb), stop_flag);
gtk_widget_show_all(dlg_w);
dlg->dlg_w = dlg_w;
g_get_current_time(&dlg->start_time);
memset(&dlg->last_time, 0, sizeof(dlg->last_time));
g_free(task_title_dup);
g_free(item_title_dup);
return dlg;
}
progdlg_t *
delayed_create_progress_dlg(const gpointer top_level_window, const gchar *task_title,
const gchar *item_title, gboolean terminate_is_stop,
gboolean *stop_flag, const GTimeVal *start_time, gfloat progress)
{
GTimeVal time_now;
gdouble delta_time;
gdouble min_display;
progdlg_t *dlg;
#define INIT_DELAY 0.1 * 1e6
#define MIN_DISPLAY_DEFAULT 2.0 * 1e6
g_get_current_time(&time_now);
delta_time = (time_now.tv_sec - start_time->tv_sec) * 1e6 +
time_now.tv_usec - start_time->tv_usec;
if (delta_time < INIT_DELAY)
return NULL;
if (delta_time <= INIT_DELAY + MIN_DISPLAY_DEFAULT)
min_display = MIN_DISPLAY_DEFAULT;
else
min_display = 2 * MIN_DISPLAY_DEFAULT - delta_time;
if (progress >= (delta_time / (delta_time + min_display)))
return NULL;
dlg = create_progress_dlg(top_level_window, task_title, item_title, terminate_is_stop,
stop_flag);
while (gtk_events_pending())
gtk_main_iteration();
dlg->start_time = *start_time;
return dlg;
}
static gboolean
delete_event_cb(GtkWidget *w _U_, GdkEvent *event _U_, gpointer data)
{
gboolean *stop_flag = (gboolean *) data;
*stop_flag = TRUE;
return TRUE;
}
static void
stop_cb(GtkWidget *w _U_, gpointer data)
{
gboolean *stop_flag = (gboolean *) data;
*stop_flag = TRUE;
}
void
update_progress_dlg(progdlg_t *dlg, gfloat percentage, const gchar *status)
{
GtkWidget *dlg_w = dlg->dlg_w;
GtkWidget *prog_bar;
GTimeVal time_now;
gdouble delta_time;
gulong ul_left;
gulong ul_elapsed;
gulong ul_percentage;
gchar tmp[100];
g_get_current_time(&time_now);
delta_time = (time_now.tv_sec - dlg->last_time.tv_sec) * 1e6 +
time_now.tv_usec - dlg->last_time.tv_usec;
if (dlg->last_time.tv_sec && delta_time < 100*1000)
return;
dlg->last_time = time_now;
delta_time = (time_now.tv_sec - dlg->start_time.tv_sec) * 1e6 +
time_now.tv_usec - dlg->start_time.tv_usec;
ul_percentage = (gulong) (percentage * 100);
ul_elapsed = (gulong) (delta_time / 1000 / 1000);
g_snprintf(tmp, sizeof(tmp), "%lu%% of %s", ul_percentage, dlg->title);
gtk_window_set_title(GTK_WINDOW(dlg_w), tmp);
gtk_label_set_text(dlg->status_lb, status);
g_snprintf(tmp, sizeof(tmp), "%lu%%", ul_percentage);
gtk_label_set_text(dlg->percentage_lb, tmp);
g_snprintf(tmp, sizeof(tmp), "%02lu:%02lu", ul_elapsed / 60,
ul_elapsed % 60);
gtk_label_set_text(dlg->elapsed_lb, tmp);
if (ul_percentage >= 5 && delta_time >= 3 * 1e6) {
ul_left = (gulong) ((delta_time / percentage - delta_time) / 1000 / 1000);
g_snprintf(tmp, sizeof(tmp), "%02lu:%02lu", ul_left / 60,
ul_left % 60);
gtk_label_set_text(dlg->time_left_lb, tmp);
}
prog_bar = (GtkWidget *)g_object_get_data(G_OBJECT(dlg_w), PROG_BAR_KEY);
gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(prog_bar), percentage);
while (gtk_events_pending())
gtk_main_iteration();
}
void
destroy_progress_dlg(progdlg_t *dlg)
{
GtkWidget *dlg_w = dlg->dlg_w;
window_destroy(GTK_WIDGET(dlg_w));
g_free(dlg->title);
g_free(dlg);
}
