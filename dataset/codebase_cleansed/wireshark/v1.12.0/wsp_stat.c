static void
wsp_reset_hash(gchar *key _U_ , wsp_status_code_t *data, gpointer ptr _U_)
{
data->packets = 0;
}
static void
wsp_draw_statuscode(gchar *key _U_, wsp_status_code_t *data, gchar *unused _U_)
{
char string_buff[256];
if ((data == NULL) || (data->packets == 0))
return;
if (data->widget == NULL) {
GtkWidget *tmp;
int x = 2 * ((data->sp->index) % 2);
int y = (data->sp->index) / 2;
tmp = gtk_label_new(data->name );
ws_gtk_grid_attach_defaults(GTK_GRID(data->sp->grid_status_code), tmp, x, y, 1, 1);
gtk_label_set_justify(GTK_LABEL(tmp), GTK_JUSTIFY_LEFT);
gtk_widget_show(tmp);
g_snprintf(string_buff, sizeof(string_buff), "%9d", data->packets);
data->widget = gtk_label_new(string_buff);
ws_gtk_grid_attach_defaults(GTK_GRID(data->sp->grid_status_code), data->widget, x+1, y, 1, 1);
gtk_label_set_justify(GTK_LABEL(data->widget), GTK_JUSTIFY_LEFT);
gtk_widget_show(data->widget);
data->sp->index++;
} else {
g_snprintf(string_buff, sizeof(string_buff), "%9d", data->packets);
gtk_label_set_text(GTK_LABEL(data->widget), string_buff);
}
}
static void
wspstat_reset(void *psp)
{
wspstat_t *sp = (wspstat_t *)psp;
guint32 i;
for(i=1; i<=sp->num_pdus; i++)
{
sp->pdu_stats[i].packets = 0;
}
g_hash_table_foreach(sp->hash, (GHFunc)wsp_reset_hash, NULL);
}
static gint
pdut2index(gint pdut)
{
if (pdut <= 0x09)
return pdut;
if (pdut >= 0x40) {
if (pdut <= 0x44) {
return pdut-54;
} else if ((pdut == 0x60) || (pdut == 0x61)) {
return pdut-81;
}
}
return 0;
}
static gint
index2pdut(gint pdut)
{
if (pdut <= 9)
return pdut;
if (pdut <= 14)
return pdut+54;
if (pdut <= 16)
return pdut+81;
return 0;
}
static int
wspstat_packet(void *psp, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *pri)
{
wspstat_t *sp = (wspstat_t *)psp;
const wsp_info_value_t *value = (const wsp_info_value_t *)pri;
gint idx = pdut2index(value->pdut);
gboolean retour = FALSE;
if (value->status_code != 0) {
wsp_status_code_t *sc;
sc = (wsp_status_code_t *)g_hash_table_lookup(
sp->hash,
GINT_TO_POINTER(value->status_code));
if (!sc) {
g_warning("%s:%d What's Wrong, doc ?\n", __FILE__, __LINE__);
sc = (wsp_status_code_t *)g_malloc(sizeof(wsp_status_code_t));
sc -> packets = 1;
sc -> name = NULL;
sc -> widget = NULL;
sc -> sp = sp;
g_hash_table_insert(
sp->hash,
GINT_TO_POINTER(value->status_code),
sc);
} else {
sc->packets++;
}
retour = TRUE;
}
if (idx != 0) {
sp->pdu_stats[idx].packets++;
retour = TRUE;
}
return retour;
}
static void
wspstat_draw(void *psp)
{
wspstat_t *sp = (wspstat_t *)psp;
guint32 i;
char str[256];
for(i=1; i<=sp->num_pdus; i++)
{
g_snprintf(str, sizeof(str), "%9d", sp->pdu_stats[i].packets);
gtk_label_set_text(GTK_LABEL(sp->pdu_stats[i].widget), str);
}
g_hash_table_foreach(sp->hash, (GHFunc)wsp_draw_statuscode, NULL);
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
wspstat_t *sp = (wspstat_t *)data;
remove_tap_listener(sp);
g_free(sp->pdu_stats);
g_free(sp->filter);
g_hash_table_destroy(sp->hash);
g_free(sp);
}
static void
add_table_entry(wspstat_t *sp, const char *str, int x, int y, int idx)
{
GtkWidget *tmp;
tmp = gtk_label_new(str);
ws_gtk_grid_attach_defaults(GTK_GRID(sp->grid_pdu_types), tmp, x, y, 1, 1);
gtk_label_set_justify(GTK_LABEL(tmp), GTK_JUSTIFY_LEFT);
gtk_widget_show(tmp);
if (idx != 0) {
sp->pdu_stats[idx].widget = GTK_LABEL(tmp);
}
}
static void
wsp_init_table(wspstat_t *sp)
{
int pos = 0;
guint32 i;
add_table_entry(sp, "PDU Type ", 0, pos, 0);
add_table_entry(sp, "packets " , 1, pos, 0);
add_table_entry(sp, "PDU Type ", 2, pos, 0);
add_table_entry(sp, "packets " , 3, pos, 0);
pos++;
for (i=1; i<=sp->num_pdus ;i++)
{
int x = 0;
if (i > (sp->num_pdus+1) / 2) {
x = 2;
}
#if 0
g_snprintf(buffer, sizeof(buffer), "%s (0X%x)",
try_val_to_str_ext(index2pdut(i), &wsp_vals_pdu_type_ext), index2pdut(i));
#endif
add_table_entry(sp,
try_val_to_str_ext(index2pdut(i), &wsp_vals_pdu_type_ext),
x,
pos,
0
);
add_table_entry(sp,
"0",
x+1,
pos,
i
);
pos++;
if (i == (sp->num_pdus+1) / 2) {
pos = 1;
}
}
}
static void
gtk_wspstat_init(const char *opt_arg, void *userdata _U_)
{
wspstat_t *sp;
const char *filter;
char *title;
GString *error_string;
GtkWidget *main_vb, *pdutypes_fr, *statuscode_fr ;
GtkWidget *bt_close;
GtkWidget *bbox;
guint32 i;
wsp_status_code_t *sc;
const value_string *wsp_vals_status_p;
if (strncmp(opt_arg, "wsp,stat,", 9) == 0) {
filter = opt_arg+9;
} else {
filter = NULL;
}
sp = (wspstat_t *)g_malloc(sizeof(wspstat_t));
sp->win = dlg_window_new("wsp-stat");
gtk_window_set_destroy_with_parent(GTK_WINDOW(sp->win), TRUE);
sp->hash = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, g_free);
wsp_vals_status_p = VALUE_STRING_EXT_VS_P(&wsp_vals_status_ext);
for (i=0; wsp_vals_status_p[i].strptr; i++)
{
sc = (wsp_status_code_t *)g_malloc(sizeof(wsp_status_code_t));
sc->name = wsp_vals_status_p[i].strptr;
sc->packets = 0;
sc->widget = NULL;
sc->sp = sp;
g_hash_table_insert(
sp->hash,
GINT_TO_POINTER(wsp_vals_status_p[i].value),
sc);
}
sp->num_pdus = 16;
sp->pdu_stats = (wsp_pdu_t *)g_malloc((sp->num_pdus+1) * sizeof(wsp_pdu_t));
if (filter) {
sp->filter = g_strdup(filter);
title = g_strdup_printf("Wireshark: WAP-WSP statistics with filter: %s", filter);
} else {
sp->filter = NULL;
title = g_strdup("Wireshark: WAP-WSP statistics");
}
for (i=0; i<=sp->num_pdus; i++)
{
sp->pdu_stats[i].packets = 0;
}
gtk_window_set_title(GTK_WINDOW(sp->win), title);
g_free(title);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 12);
gtk_container_add(GTK_CONTAINER(sp->win), main_vb);
pdutypes_fr = gtk_frame_new("Summary of PDU Types (wsp.pdu_type)");
gtk_box_pack_start(GTK_BOX(main_vb), pdutypes_fr, TRUE, TRUE, 0);
sp->grid_pdu_types = ws_gtk_grid_new();
gtk_container_add(GTK_CONTAINER(pdutypes_fr), sp->grid_pdu_types);
gtk_container_set_border_width(GTK_CONTAINER(sp->grid_pdu_types), 10);
wsp_init_table(sp);
statuscode_fr = gtk_frame_new("Summary of Status Code (wsp.reply.status)");
gtk_box_pack_start(GTK_BOX(main_vb), statuscode_fr, FALSE, FALSE, 0);
sp->grid_status_code = ws_gtk_grid_new();
gtk_container_add(GTK_CONTAINER(statuscode_fr), sp->grid_status_code);
gtk_container_set_border_width(GTK_CONTAINER(sp->grid_status_code), 10);
sp->index = 0;
error_string = register_tap_listener(
"wsp",
sp,
filter,
0,
wspstat_reset,
wspstat_packet,
wspstat_draw);
if (error_string) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_free(sp->pdu_stats);
g_free(sp->filter);
g_free(sp);
g_string_free(error_string, TRUE);
return ;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
bt_close = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(sp->win, bt_close, window_cancel_button_cb);
g_signal_connect(sp->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(sp->win, "destroy", G_CALLBACK(win_destroy_cb), sp);
gtk_widget_show_all(sp->win);
window_present(sp->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(sp->win));
}
void
register_tap_listener_gtkwspstat(void)
{
register_param_stat(&wsp_stat_dlg, "_WAP-WSP",
REGISTER_STAT_GROUP_TELEPHONY);
}
