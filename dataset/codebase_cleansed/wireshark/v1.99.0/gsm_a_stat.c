static
GtkWidget* create_list(void)
{
GtkListStore *list_store;
GtkWidget *list;
GtkTreeViewColumn *column;
GtkCellRenderer *renderer;
GtkTreeSortable *sortable;
GtkTreeView *list_view;
GtkTreeSelection *selection;
list_store = gtk_list_store_new(N_COLUMN,
G_TYPE_UINT,
G_TYPE_STRING,
G_TYPE_UINT);
list = gtk_tree_view_new_with_model (GTK_TREE_MODEL (list_store));
list_view = GTK_TREE_VIEW(list);
sortable = GTK_TREE_SORTABLE(list_store);
gtk_tree_view_set_fixed_height_mode(list_view, TRUE);
gtk_tree_sortable_set_sort_column_id(sortable, IEI_COLUMN, GTK_SORT_ASCENDING);
gtk_tree_view_set_headers_clickable(list_view, FALSE);
g_object_unref (G_OBJECT (list_store));
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("IEI", renderer,
"text", IEI_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, IEI_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 50);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Message Name", renderer,
"text", MSG_NAME_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MSG_NAME_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 280);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Count", renderer,
"text", COUNT_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, COUNT_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 50);
gtk_tree_view_append_column (list_view, column);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(list_view), TRUE);
gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(list_view), TRUE);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
return list;
}
static void
gsm_a_stat_reset(
void *tapdata)
{
gsm_a_stat_t *stat_p = (gsm_a_stat_t *)tapdata;
memset(stat_p, 0, sizeof(gsm_a_stat_t));
}
static gboolean
gsm_a_stat_packet(
void *tapdata,
packet_info *pinfo _U_,
epan_dissect_t *edt _U_,
const void *data)
{
gsm_a_stat_t *stat_p = (gsm_a_stat_t *)tapdata;
const gsm_a_tap_rec_t *data_p = (const gsm_a_tap_rec_t *)data;
switch (data_p->pdu_type)
{
case BSSAP_PDU_TYPE_BSSMAP:
stat_p->bssmap_message_type[data_p->message_type]++;
break;
case BSSAP_PDU_TYPE_DTAP:
switch (data_p->protocol_disc)
{
case PD_CC:
stat_p->dtap_cc_message_type[data_p->message_type]++;
break;
case PD_MM:
stat_p->dtap_mm_message_type[data_p->message_type]++;
break;
case PD_RR:
stat_p->dtap_rr_message_type[data_p->message_type]++;
break;
case PD_GMM:
stat_p->dtap_gmm_message_type[data_p->message_type]++;
break;
case PD_SMS:
stat_p->dtap_sms_message_type[data_p->message_type]++;
break;
case PD_SM:
stat_p->dtap_sm_message_type[data_p->message_type]++;
break;
case PD_SS:
stat_p->dtap_ss_message_type[data_p->message_type]++;
break;
case PD_TP:
stat_p->dtap_tp_message_type[data_p->message_type]++;
break;
default:
return(FALSE);
}
break;
case GSM_A_PDU_TYPE_SACCH:
switch (data_p->protocol_disc)
{
case 0:
stat_p->sacch_rr_message_type[data_p->message_type]++;
break;
default:
break;
}
break;
default:
return(FALSE);
}
return(TRUE);
}
static void
gsm_a_stat_draw_aux(
gsm_a_stat_dlg_t *dlg_p,
int *message_count,
const value_string *msg_strings)
{
GtkListStore *list_store;
GtkTreeIter iter;
int i;
if (dlg_p->win != NULL){
i = 0;
list_store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW (dlg_p->table)));
while (msg_strings[i].strptr){
gtk_list_store_insert_with_values( list_store , &iter, G_MAXINT,
IEI_COLUMN, msg_strings[i].value,
MSG_NAME_COLUMN, (char *)msg_strings[i].strptr,
COUNT_COLUMN, message_count[msg_strings[i].value],
-1);
i++;
}
}
}
static void
gsm_a_stat_draw(
void *tapdata)
{
gsm_a_stat_t *stat_p = (gsm_a_stat_t *)tapdata;
if (!tapdata) return;
if (dlg_bssmap.win != NULL)
{
gsm_a_stat_draw_aux(&dlg_bssmap,
stat_p->bssmap_message_type,
gsm_a_bssmap_msg_strings);
}
if (dlg_dtap_mm.win != NULL)
{
gsm_a_stat_draw_aux(&dlg_dtap_mm,
stat_p->dtap_mm_message_type,
gsm_a_dtap_msg_mm_strings);
}
if (dlg_dtap_rr.win != NULL)
{
gsm_a_stat_draw_aux(&dlg_dtap_rr,
stat_p->dtap_rr_message_type,
gsm_a_dtap_msg_rr_strings);
}
if (dlg_dtap_cc.win != NULL)
{
gsm_a_stat_draw_aux(&dlg_dtap_cc,
stat_p->dtap_cc_message_type,
gsm_a_dtap_msg_cc_strings);
}
if (dlg_dtap_gmm.win != NULL)
{
gsm_a_stat_draw_aux(&dlg_dtap_gmm,
stat_p->dtap_gmm_message_type,
gsm_a_dtap_msg_gmm_strings);
}
if (dlg_dtap_sms.win != NULL)
{
gsm_a_stat_draw_aux(&dlg_dtap_sms,
stat_p->dtap_sms_message_type,
gsm_a_dtap_msg_sms_strings);
}
if (dlg_dtap_sm.win != NULL)
{
gsm_a_stat_draw_aux(&dlg_dtap_sm,
stat_p->dtap_sm_message_type,
gsm_a_dtap_msg_sm_strings);
}
if (dlg_dtap_ss.win != NULL)
{
gsm_a_stat_draw_aux(&dlg_dtap_ss,
stat_p->dtap_ss_message_type,
gsm_a_dtap_msg_ss_strings);
}
if (dlg_dtap_tp.win != NULL)
{
gsm_a_stat_draw_aux(&dlg_dtap_tp,
stat_p->dtap_tp_message_type,
gsm_a_dtap_msg_tp_strings);
}
if (dlg_sacch_rr.win != NULL)
{
gsm_a_stat_draw_aux(&dlg_sacch_rr,
stat_p->sacch_rr_message_type,
gsm_a_rr_short_pd_msg_strings);
}
}
static void
gsm_a_stat_gtk_win_destroy_cb(
GtkWindow *win _U_,
gpointer user_data)
{
memset((void *) user_data, 0, sizeof(gsm_a_stat_dlg_t));
}
static void
gsm_a_stat_gtk_win_create(
gsm_a_stat_dlg_t *dlg_p,
const char *title)
{
GtkWidget *vbox;
GtkWidget *bt_close;
GtkWidget *bbox;
dlg_p->win = dlg_window_new(title);
gtk_window_set_destroy_with_parent (GTK_WINDOW(dlg_p->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(dlg_p->win), 490, 500);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(dlg_p->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
dlg_p->scrolled_win = scrolled_window_new(NULL, NULL);
gtk_box_pack_start(GTK_BOX(vbox), dlg_p->scrolled_win, TRUE, TRUE, 0);
dlg_p->table = create_list();
gtk_container_add(GTK_CONTAINER(dlg_p->scrolled_win), dlg_p->table);
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_start(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
bt_close = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(dlg_p->win, bt_close, window_cancel_button_cb);
g_signal_connect(dlg_p->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(dlg_p->win, "destroy", G_CALLBACK(gsm_a_stat_gtk_win_destroy_cb), dlg_p);
gtk_widget_show_all(dlg_p->win);
window_present(dlg_p->win);
}
void gsm_a_stat_gtk_bssmap_cb(GtkAction *action _U_, gpointer user_data _U_ )
{
if (dlg_bssmap.win)
{
gdk_window_raise(gtk_widget_get_window(dlg_bssmap.win));
return;
}
gsm_a_stat_gtk_win_create(&dlg_bssmap, "GSM A-I/F BSSMAP Statistics");
gsm_a_stat_draw(&gsm_a_stat);
}
static void
gsm_a_stat_gtk_bssmap_init(
const char *opt_arg _U_,
void* userdata _U_)
{
gsm_a_stat_gtk_bssmap_cb(NULL, NULL);
}
static void
gsm_a_stat_gtk_dtap_cb(
GtkAction *action _U_,
gpointer user_data _U_,
gsm_a_stat_dlg_t *dlg_dtap_p,
const char *title,
const value_string *dtap_msg_strings _U_)
{
if (dlg_dtap_p->win)
{
gdk_window_raise(gtk_widget_get_window(dlg_dtap_p->win));
return;
}
gsm_a_stat_gtk_win_create(dlg_dtap_p, title);
gsm_a_stat_draw(&gsm_a_stat);
}
void
gsm_a_stat_gtk_dtap_mm_cb(GtkAction *action, gpointer user_data )
{
gsm_a_stat_gtk_dtap_cb(action, user_data, &dlg_dtap_mm,
"GSM A-I/F DTAP Mobility Management Statistics",
gsm_a_dtap_msg_mm_strings);
}
static void
gsm_a_stat_gtk_dtap_mm_init(const char *opt_arg _U_,
void* userdata _U_)
{
gsm_a_stat_gtk_dtap_mm_cb(NULL, NULL);
}
void
gsm_a_stat_gtk_dtap_rr_cb(GtkAction *action, gpointer user_data )
{
gsm_a_stat_gtk_dtap_cb(action, user_data, &dlg_dtap_rr,
"GSM A-I/F DTAP Radio Resource Management Statistics",
gsm_a_dtap_msg_rr_strings);
}
static void
gsm_a_stat_gtk_dtap_rr_init(const char *opt_arg _U_,
void* userdata _U_)
{
gsm_a_stat_gtk_dtap_rr_cb(NULL, NULL);
}
void
gsm_a_stat_gtk_dtap_cc_cb(GtkAction *action, gpointer user_data )
{
gsm_a_stat_gtk_dtap_cb(action, user_data, &dlg_dtap_cc,
"GSM A-I/F DTAP Call Control Statistics",
gsm_a_dtap_msg_cc_strings);
}
static void
gsm_a_stat_gtk_dtap_cc_init(const char *opt_arg _U_,
void* userdata _U_)
{
gsm_a_stat_gtk_dtap_cc_cb(NULL, NULL);
}
void
gsm_a_stat_gtk_dtap_gmm_cb(GtkAction *action, gpointer user_data )
{
gsm_a_stat_gtk_dtap_cb(action, user_data, &dlg_dtap_gmm,
"GSM A-I/F DTAP GPRS Mobility Management Statistics",
gsm_a_dtap_msg_gmm_strings);
}
static void
gsm_a_stat_gtk_dtap_gmm_init(const char *opt_arg _U_,
void* userdata _U_)
{
gsm_a_stat_gtk_dtap_gmm_cb(NULL, NULL);
}
void
gsm_a_stat_gtk_dtap_sms_cb(GtkAction *action, gpointer user_data )
{
gsm_a_stat_gtk_dtap_cb(action, user_data, &dlg_dtap_sms,
"GSM A-I/F DTAP Short Message Service Statistics",
gsm_a_dtap_msg_sms_strings);
}
static void
gsm_a_stat_gtk_dtap_sms_init(const char *opt_arg _U_,
void* userdata _U_)
{
gsm_a_stat_gtk_dtap_sms_cb(NULL, NULL);
}
void
gsm_a_stat_gtk_dtap_sm_cb(GtkAction *action, gpointer user_data )
{
gsm_a_stat_gtk_dtap_cb(action, user_data, &dlg_dtap_sm,
"GSM A-I/F DTAP GPRS Session Management Statistics",
gsm_a_dtap_msg_sm_strings);
}
static void
gsm_a_stat_gtk_dtap_sm_init(const char *opt_arg _U_,
void* userdata _U_)
{
gsm_a_stat_gtk_dtap_sm_cb(NULL, NULL);
}
void
gsm_a_stat_gtk_dtap_ss_cb(GtkAction *action, gpointer user_data )
{
gsm_a_stat_gtk_dtap_cb(action, user_data, &dlg_dtap_ss,
"GSM A-I/F DTAP Supplementary Services Statistics",
gsm_a_dtap_msg_ss_strings);
}
static void
gsm_a_stat_gtk_dtap_ss_init(
const char *opt_arg _U_,
void *userdata _U_)
{
gsm_a_stat_gtk_dtap_ss_cb(NULL, NULL);
}
void
gsm_a_stat_gtk_dtap_tp_cb(GtkAction *action, gpointer user_data )
{
gsm_a_stat_gtk_dtap_cb(action, user_data, &dlg_dtap_tp,
"GSM A-I/F DTAP Special Conformance Testing Functions Statistics",
gsm_a_dtap_msg_tp_strings);
}
static void
gsm_a_stat_gtk_dtap_tp_init(
const char *opt_arg _U_,
void *userdata _U_)
{
gsm_a_stat_gtk_dtap_tp_cb(NULL, NULL);
}
void
gsm_a_stat_gtk_sacch_rr_cb(GtkAction *action _U_, gpointer user_data _U_ )
{
if (dlg_sacch_rr.win)
{
gdk_window_raise(gtk_widget_get_window(dlg_sacch_rr.win));
return;
}
gsm_a_stat_gtk_win_create(&dlg_sacch_rr, "GSM A-I/F SACCH Statistics");
gsm_a_stat_draw(&gsm_a_stat);
}
static void
gsm_a_stat_gtk_sacch_rr_init(
const char *opt_arg _U_,
void* userdata _U_)
{
gsm_a_stat_gtk_sacch_rr_cb(NULL, NULL);
}
void
register_tap_listener_gtkgsm_a_stat(void)
{
GString *err_p;
memset((void *) &gsm_a_stat, 0, sizeof(gsm_a_stat_t));
err_p =
register_tap_listener("gsm_a", &gsm_a_stat, NULL, 0,
gsm_a_stat_reset,
gsm_a_stat_packet,
gsm_a_stat_draw);
if (err_p != NULL)
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_p->str);
g_string_free(err_p, TRUE);
exit(1);
}
register_stat_cmd_arg("gsm_a,bssmap", gsm_a_stat_gtk_bssmap_init,NULL);
register_stat_cmd_arg("gsm_a,dtap_mm", gsm_a_stat_gtk_dtap_mm_init,NULL);
register_stat_cmd_arg("gsm_a,dtap_rr", gsm_a_stat_gtk_dtap_rr_init,NULL);
register_stat_cmd_arg("gsm_a,dtap_cc", gsm_a_stat_gtk_dtap_cc_init,NULL);
register_stat_cmd_arg("gsm_a,dtap_gmm", gsm_a_stat_gtk_dtap_gmm_init,NULL);
register_stat_cmd_arg("gsm_a,dtap_sms", gsm_a_stat_gtk_dtap_sms_init,NULL);
register_stat_cmd_arg("gsm_a,dtap_sm", gsm_a_stat_gtk_dtap_sm_init,NULL);
register_stat_cmd_arg("gsm_a,dtap_ss", gsm_a_stat_gtk_dtap_ss_init,NULL);
register_stat_cmd_arg("gsm_a,dtap_tp", gsm_a_stat_gtk_dtap_tp_init,NULL);
register_stat_cmd_arg("gsm_a,sacch", gsm_a_stat_gtk_sacch_rr_init,NULL);
}
