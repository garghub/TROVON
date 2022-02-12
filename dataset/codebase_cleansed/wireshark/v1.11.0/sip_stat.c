static void
sip_init_hash(sipstat_t *sp)
{
int i;
sp->hash_responses = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, g_free);
for (i=0; vals_status_code[i].strptr; i++)
{
sip_response_code_t *sc = (sip_response_code_t *)g_malloc(sizeof(sip_response_code_t));
sc->packets = 0;
sc->response_code = vals_status_code[i].value;
sc->name = vals_status_code[i].strptr;
sc->widget = NULL;
sc->table_info = NULL;
sc->sp = sp;
g_hash_table_insert(sc->sp->hash_responses, GUINT_TO_POINTER(vals_status_code[i].value), sc);
}
sp->hash_requests = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
}
static void
sip_draw_hash_requests(gchar *key _U_, sip_request_method_t *data, gchar *unused _U_)
{
gchar string_buff[SUM_STR_MAX];
g_assert(data != NULL);
if (data->packets == 0)
{
return;
}
g_snprintf(string_buff, sizeof(string_buff),
" %-11s : %3d packets", data->response, data->packets);
if (data->widget == NULL)
{
data->widget = gtk_label_new(string_buff);
gtk_misc_set_alignment(GTK_MISC(data->widget), 0.0f, 0.5f);
gtk_box_pack_start(GTK_BOX(data->sp->request_box), data->widget, FALSE, FALSE, 0);
gtk_widget_show(data->widget);
}
else
{
gtk_label_set_text(GTK_LABEL(data->widget), string_buff);
}
}
static void
sip_draw_hash_responses(gint *key _U_ , sip_response_code_t *data, gchar *unused _U_)
{
gchar string_buff[SUM_STR_MAX];
g_assert(data != NULL);
if (data->packets == 0)
{
return;
}
if (data->widget == NULL)
{
guint x;
GtkWidget *tmp;
guint i = data->response_code;
if ((i < 100) || (i >= 700))
{
return;
}
if (i < 200)
{
data->table_info = &(data->sp->informational_table_info);
}
else if (i < 300)
{
data->table_info = &(data->sp->success_table_info);
}
else if (i < 400)
{
data->table_info = &(data->sp->redirection_table_info);
}
else if (i < 500)
{
data->table_info = &(data->sp->client_error_table_info);
}
else if (i < 600)
{
data->table_info = &(data->sp->server_errors_table_info);
}
else
{
data->table_info = &(data->sp->global_failures_table_info);
}
x = data->table_info->row_count;
g_snprintf(string_buff, sizeof(string_buff),
"SIP %3d %s ", data->response_code, data->name);
tmp = gtk_label_new(string_buff);
ws_gtk_grid_attach_defaults(GTK_GRID(data->table_info->grid), tmp, 0, x, 1, 1);
gtk_label_set_justify(GTK_LABEL(tmp), GTK_JUSTIFY_LEFT);
gtk_widget_show(tmp);
g_snprintf(string_buff, sizeof(string_buff), "%9d", data->packets);
data->widget = gtk_label_new(string_buff);
ws_gtk_grid_attach_defaults(GTK_GRID(data->table_info->grid), data->widget, 1, x, 1, 1);
gtk_label_set_justify(GTK_LABEL(data->widget), GTK_JUSTIFY_RIGHT);
gtk_widget_show(data->widget);
data->table_info->row_count += 1;
} else
{
g_snprintf(string_buff, sizeof(string_buff), "%9d", data->packets);
gtk_label_set_text(GTK_LABEL(data->widget), string_buff);
}
}
static void
sip_reset_hash_responses(gchar *key _U_, sip_response_code_t *data, gpointer ptr _U_)
{
data->packets = 0;
}
static void
sip_reset_hash_requests(gchar *key _U_ , sip_request_method_t *data, gpointer ptr _U_)
{
data->packets = 0;
}
static void
sipstat_reset(void *psp)
{
sipstat_t *sp = (sipstat_t *)psp;
if (sp)
{
sp->packets = 0;
sp->resent_packets = 0;
sp->average_setup_time = 0;
sp->max_setup_time = 0;
sp->max_setup_time = 0;
sp->no_of_completed_calls = 0;
sp->total_setup_time = 0;
g_hash_table_foreach(sp->hash_responses, (GHFunc)sip_reset_hash_responses, NULL);
g_hash_table_foreach(sp->hash_requests, (GHFunc)sip_reset_hash_requests, NULL);
}
}
static int
sipstat_packet(void *psp, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *pri)
{
const sip_info_value_t *value = (sip_info_value_t *)pri;
sipstat_t *sp = (sipstat_t *)psp;
sp->packets++;
if (value->resend)
{
sp->resent_packets++;
}
if (value->setup_time)
{
sp->no_of_completed_calls++;
if ( sp->total_setup_time == 0 )
{
sp->average_setup_time = value->setup_time;
sp->total_setup_time = value->setup_time;
sp->max_setup_time = value->setup_time;
sp->min_setup_time = value->setup_time;
} else
{
sp->total_setup_time = sp->total_setup_time + value->setup_time;
if (sp->max_setup_time < value->setup_time)
{
sp->max_setup_time = value->setup_time;
}
if (sp->min_setup_time > value->setup_time)
{
sp->min_setup_time = value->setup_time;
}
sp->average_setup_time = (guint32)(sp->total_setup_time / sp->no_of_completed_calls);
}
}
if (value->response_code != 0)
{
sip_response_code_t *sc;
sc = (sip_response_code_t *)g_hash_table_lookup(sp->hash_responses, GUINT_TO_POINTER(value->response_code));
if (sc == NULL)
{
guint key;
guint i = value->response_code;
if ((i < 100) || (i >= 700))
{
return 0;
}
else if (i < 200)
{
key = 199;
}
else if (i < 300)
{
key = 299;
}
else if (i < 400)
{
key = 399;
}
else if (i < 500)
{
key = 499;
}
else if (i < 600)
{
key = 599;
}
else
{
key = 699;
}
sc = (sip_response_code_t *)g_hash_table_lookup(sp->hash_responses, GUINT_TO_POINTER(key));
if (sc == NULL)
{
return 0;
}
}
sc->packets++;
}
else if (value->request_method)
{
sip_request_method_t *sc;
sc = (sip_request_method_t *)g_hash_table_lookup(sp->hash_requests, value->request_method);
if (sc == NULL)
{
sc = (sip_request_method_t *)g_malloc(sizeof(sip_request_method_t));
sc->response = g_strdup(value->request_method);
sc->packets = 1;
sc->widget = NULL;
sc->sp = sp;
g_hash_table_insert(sp->hash_requests, sc->response, sc);
}
else
{
sc->packets++;
}
}
else
{
return 0;
}
return 1;
}
static void
sipstat_draw(void *psp)
{
gchar string_buff[SUM_STR_MAX];
sipstat_t *sp = (sipstat_t *)psp;
g_snprintf(string_buff, sizeof(string_buff),
"SIP stats (%d packets)", sp->packets);
gtk_label_set_text(GTK_LABEL(sp->packets_label), string_buff);
g_snprintf(string_buff, sizeof(string_buff),
"(%d resent packets)", sp->resent_packets);
gtk_label_set_text(GTK_LABEL(sp->resent_label), string_buff);
g_hash_table_foreach(sp->hash_responses, (GHFunc)sip_draw_hash_responses, NULL);
g_hash_table_foreach(sp->hash_requests, (GHFunc)sip_draw_hash_requests, NULL);
g_snprintf(string_buff, sizeof(string_buff),
"Average setup time %d ms\n Min %d ms\n Max %d ms",
sp->average_setup_time, sp->min_setup_time, sp->max_setup_time);
gtk_label_set_text(GTK_LABEL(sp->average_setup_time_label), string_buff);
gtk_widget_show_all(sp->win);
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
sipstat_t *sp = (sipstat_t *)data;
remove_tap_listener(sp);
g_hash_table_destroy(sp->hash_responses);
g_hash_table_destroy(sp->hash_requests);
g_free(sp->filter);
g_free(sp);
}
static void
init_table(GtkWidget *main_vb, const gchar *title, grid_info_t *tbl_info)
{
GtkWidget *fr;
fr = gtk_frame_new(title);
gtk_box_pack_start(GTK_BOX(main_vb), fr, TRUE, TRUE, 0);
(*tbl_info).grid = ws_gtk_grid_new();
gtk_container_add(GTK_CONTAINER(fr), (*tbl_info).grid);
(*tbl_info).row_count = 0;
}
static void
gtk_sipstat_init(const char *opt_arg, void *userdata _U_)
{
sipstat_t *sp;
const char *filter;
GString *error_string;
char *title;
GtkWidget *main_vb, *separator, *request_fr;
GtkWidget *bt_close;
GtkWidget *bbox;
if (strncmp(opt_arg, "sip,stat,", 9) == 0)
{
filter = opt_arg + 9;
}
else
{
filter = NULL;
}
sp = (sipstat_t *)g_malloc(sizeof(sipstat_t));
sp->win = dlg_window_new("sip-stat");
gtk_window_set_destroy_with_parent(GTK_WINDOW(sp->win), TRUE);
if (filter)
{
sp->filter = g_strdup(filter);
title = g_strdup_printf("SIP statistics with filter: %s", filter);
}
else
{
sp->filter = NULL;
title = g_strdup("SIP statistics");
}
gtk_window_set_title(GTK_WINDOW(sp->win), title);
g_free(title);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 12, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 12);
gtk_container_add(GTK_CONTAINER(sp->win), main_vb);
sp->packets = 0;
sp->packets_label = gtk_label_new("SIP stats (0 SIP packets)");
gtk_box_pack_start(GTK_BOX(main_vb), sp->packets_label, TRUE, TRUE, 0);
sp->resent_packets = 0;
sp->resent_label = gtk_label_new("(0 resent packets)");
gtk_box_pack_start(GTK_BOX(main_vb), sp->resent_label, TRUE, TRUE, 0);
gtk_widget_show(sp->resent_label);
init_table(main_vb, "Informational SIP 1xx", &(sp->informational_table_info));
init_table(main_vb, "Success SIP 2xx", &(sp->success_table_info));
init_table(main_vb, "Redirection SIP 3xx", &(sp->redirection_table_info));
init_table(main_vb, "Client errors SIP 4xx", &(sp->client_error_table_info));
init_table(main_vb, "Server errors SIP 5xx", &(sp->server_errors_table_info));
init_table(main_vb, "Global failures SIP 6xx", &(sp->global_failures_table_info));
separator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start(GTK_BOX(main_vb), separator, TRUE, TRUE, 0);
request_fr = gtk_frame_new("List of request methods");
gtk_box_pack_start(GTK_BOX(main_vb), request_fr, TRUE, TRUE, 0);
gtk_container_set_border_width(GTK_CONTAINER(request_fr), 0);
sp->request_box = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 10, FALSE);
gtk_container_add(GTK_CONTAINER(request_fr), sp->request_box);
sp->average_setup_time = 0;
sp->max_setup_time = 0;
sp->min_setup_time = 0;
sp->average_setup_time_label = gtk_label_new("(Not calculated)");
gtk_box_pack_start(GTK_BOX(main_vb), sp->average_setup_time_label, TRUE, TRUE, 0);
gtk_widget_show(sp->average_setup_time_label);
error_string = register_tap_listener("sip",
sp,
filter,
0,
sipstat_reset,
sipstat_packet,
sipstat_draw);
if (error_string)
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_free(sp->filter);
g_free(sp);
g_string_free(error_string, TRUE);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
bt_close = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(sp->win, bt_close, window_cancel_button_cb);
g_signal_connect(sp->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(sp->win, "destroy", G_CALLBACK(win_destroy_cb), sp);
gtk_widget_show_all(sp->win);
window_present(sp->win);
sip_init_hash(sp);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(sp->win));
}
void
register_tap_listener_gtksipstat(void)
{
register_param_stat(&sip_stat_dlg, "_SIP", REGISTER_STAT_GROUP_TELEPHONY);
}
