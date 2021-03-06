static void lbmc_uim_flow_graph_data_init(void)
{
dialog_data.graph_analysis = (seq_analysis_info_t *)g_malloc0(sizeof(seq_analysis_info_t));
dialog_data.graph_analysis->type = SEQ_ANALYSIS_ANY;
dialog_data.graph_analysis->all_packets = TRUE;
dialog_data.graph_analysis->any_addr = TRUE;
dialog_data.graph_analysis->nconv = 0;
dialog_data.graph_analysis->list = NULL;
dialog_data.graph_analysis->ht = NULL;
dialog_data.graph_analysis->num_nodes = 0;
}
static void lbmc_uim_flow_toggle_select_all_cb(GtkWidget * widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(dialog_data.select_all_radio_button)))
{
dialog_data.packet_select_type = select_all_packets;
}
}
static void lbmc_uim_flow_toggle_select_displayed_cb(GtkWidget * widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(dialog_data.select_displayed_radio_button)))
{
dialog_data.packet_select_type = select_displayed_packets;
}
}
static void lbmc_uim_flow_tap_reset(void * tap_data _U_)
{
seq_analysis_item_t * graph_item;
GList * list;
if (dialog_data.graph_analysis != NULL)
{
list = g_list_first(dialog_data.graph_analysis->list);
while (list)
{
graph_item = (seq_analysis_item_t *)list->data;
g_free(graph_item->frame_label);
g_free(graph_item->time_str);
g_free(graph_item->comment);
g_free(list->data);
list = g_list_next(list);
}
g_list_free(dialog_data.graph_analysis->list);
dialog_data.graph_analysis->nconv = 0;
dialog_data.graph_analysis->list = NULL;
}
}
static int lbmc_uim_flow_graph_add_to_graph(packet_info * pinfo, const lbm_uim_stream_info_t * stream_info)
{
lbm_uim_stream_endpoint_t epa;
lbm_uim_stream_endpoint_t epb;
seq_analysis_item_t * item;
gchar * ctxinst1 = NULL;
gchar * ctxinst2 = NULL;
gboolean swap_endpoints = FALSE;
int rc;
if (stream_info->endpoint_a.type != stream_info->endpoint_b.type)
{
return (1);
}
if (stream_info->endpoint_a.type == lbm_uim_instance_stream)
{
rc = memcmp((void *)stream_info->endpoint_a.stream_info.ctxinst.ctxinst,
(void *)stream_info->endpoint_b.stream_info.ctxinst.ctxinst,
LBM_CONTEXT_INSTANCE_BLOCK_SZ);
if (rc <= 0)
{
swap_endpoints = FALSE;
}
else
{
swap_endpoints = TRUE;
}
}
else
{
if (stream_info->endpoint_a.stream_info.dest.domain < stream_info->endpoint_b.stream_info.dest.domain)
{
swap_endpoints = FALSE;
}
else if (stream_info->endpoint_a.stream_info.dest.domain > stream_info->endpoint_b.stream_info.dest.domain)
{
swap_endpoints = TRUE;
}
else
{
int compare;
compare = CMP_ADDRESS(&(stream_info->endpoint_a.stream_info.dest.addr), &(stream_info->endpoint_b.stream_info.dest.addr));
if (compare < 0)
{
swap_endpoints = FALSE;
}
else if (compare > 0)
{
swap_endpoints = TRUE;
}
else
{
if (stream_info->endpoint_a.stream_info.dest.port <= stream_info->endpoint_b.stream_info.dest.port)
{
swap_endpoints = FALSE;
}
else
{
swap_endpoints = TRUE;
}
}
}
}
if (swap_endpoints == FALSE)
{
epa = stream_info->endpoint_a;
epb = stream_info->endpoint_b;
}
else
{
epb = stream_info->endpoint_a;
epa = stream_info->endpoint_b;
}
item = (seq_analysis_item_t *)g_malloc(sizeof(seq_analysis_item_t));
COPY_ADDRESS(&(item->src_addr), &(pinfo->src));
COPY_ADDRESS(&(item->dst_addr), &(pinfo->dst));
item->fd = pinfo->fd;
item->port_src = pinfo->srcport;
item->port_dst = pinfo->destport;
if (stream_info->description == NULL)
{
item->frame_label = g_strdup_printf("(%" G_GUINT32_FORMAT ")", stream_info->sqn);
}
else
{
item->frame_label = g_strdup_printf("%s (%" G_GUINT32_FORMAT ")", stream_info->description, stream_info->sqn);
}
if (epa.type == lbm_uim_instance_stream)
{
ctxinst1 = bytes_to_ep_str(epa.stream_info.ctxinst.ctxinst, sizeof(epa.stream_info.ctxinst.ctxinst));
ctxinst2 = bytes_to_ep_str(epb.stream_info.ctxinst.ctxinst, sizeof(epb.stream_info.ctxinst.ctxinst));
item->comment = g_strdup_printf("%s <-> %s [%" G_GUINT64_FORMAT "]",
ctxinst1,
ctxinst2,
stream_info->channel);
}
else
{
item->comment = g_strdup_printf("%" G_GUINT32_FORMAT ":%s:%" G_GUINT16_FORMAT " <-> %" G_GUINT32_FORMAT ":%s:%" G_GUINT16_FORMAT " [%" G_GUINT64_FORMAT "]",
epa.stream_info.dest.domain,
address_to_str(wmem_packet_scope(), &(epa.stream_info.dest.addr)),
epa.stream_info.dest.port,
epb.stream_info.dest.domain,
address_to_str(wmem_packet_scope(), &(epb.stream_info.dest.addr)),
epb.stream_info.dest.port,
stream_info->channel);
}
item->conv_num = (guint16)LBM_CHANNEL_ID(stream_info->channel);
item->display = TRUE;
item->line_style = 1;
dialog_data.graph_analysis->list = g_list_prepend(dialog_data.graph_analysis->list, (gpointer)item);
return (1);
}
static gboolean lbmc_uim_flow_tap_packet(void * tap_data _U_, packet_info * pinfo, epan_dissect_t * edt _U_, const void * stream_info)
{
const lbm_uim_stream_info_t * info = (const lbm_uim_stream_info_t *)stream_info;
if ((dialog_data.packet_select_type == select_all_packets) || (pinfo->fd->flags.passed_dfilter == 1))
{
lbmc_uim_flow_graph_add_to_graph(pinfo, info);
return (TRUE);
}
return (FALSE);
}
static void lbmc_uim_flow_tap_draw(void * tap_data _U_)
{
return;
}
static void lbmc_uim_flow_remove_tap_listener(void)
{
remove_tap_listener(&(dialog_data.tap_identifier));
dialog_data.have_tap_listener = FALSE;
}
static void lbmc_uim_flow_graph_on_ok_cb(GtkButton * button _U_, gpointer user_data)
{
GList * list = NULL;
gchar time_str[COL_MAX_LEN];
if (dialog_data.have_tap_listener == TRUE)
{
lbmc_uim_flow_remove_tap_listener();
}
if (dialog_data.have_tap_listener == FALSE)
{
GString * err_msg;
err_msg = register_tap_listener("lbm_uim",
&(dialog_data.tap_identifier),
NULL,
TL_REQUIRES_COLUMNS,
lbmc_uim_flow_tap_reset,
lbmc_uim_flow_tap_packet,
lbmc_uim_flow_tap_draw);
if (err_msg != NULL)
{
fprintf(stderr, "register_tap_listener: %s\n", err_msg->str);
g_string_free(err_msg, TRUE);
}
dialog_data.have_tap_listener = TRUE;
}
cf_retap_packets(&cfile);
dialog_data.graph_analysis->list = g_list_reverse(dialog_data.graph_analysis->list);
list = g_list_first(dialog_data.graph_analysis->list);
while (list != NULL)
{
seq_analysis_item_t * seq_item = (seq_analysis_item_t *)list->data;
set_fd_time(cfile.epan, seq_item->fd, time_str);
seq_item->time_str = g_strdup(time_str);
list = g_list_next(list);
}
if (dialog_data.graph_analysis_data->dlg.window != NULL)
{
graph_analysis_update(dialog_data.graph_analysis_data);
}
else
{
dialog_data.graph_analysis_data->dlg.parent_w = (GtkWidget *)user_data;
graph_analysis_create(dialog_data.graph_analysis_data);
}
}
static void lbmc_uim_flow_graph_on_destroy_cb(GtkWidget * widget _U_, gpointer user_data _U_)
{
lbmc_uim_flow_remove_tap_listener();
lbmc_uim_flow_tap_reset(NULL);
g_assert(dialog_data.graph_analysis != NULL);
g_assert(dialog_data.graph_analysis_data != NULL);
g_free(dialog_data.graph_analysis);
dialog_data.graph_analysis = NULL;
g_free(dialog_data.graph_analysis_data);
dialog_data.graph_analysis_data = NULL;
dialog_data.flow_graph_dialog = NULL;
}
static void lbmc_uim_flow_graph_dlg_create(void)
{
GtkWidget * flow_graph_dlg_w = NULL;
GtkWidget * main_vb = NULL;
GtkWidget * hbuttonbox = NULL;
GtkWidget * bt_cancel = NULL;
GtkWidget * bt_ok = NULL;
GtkWidget * range_fr = NULL;
GtkWidget * range_grid = NULL;
flow_graph_dlg_w = dlg_window_new("Wireshark: UIM Flow Graph");
gtk_window_set_destroy_with_parent(GTK_WINDOW(flow_graph_dlg_w), TRUE);
gtk_window_set_default_size(GTK_WINDOW(flow_graph_dlg_w), 250, 150);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(flow_graph_dlg_w), main_vb);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 7);
gtk_widget_show(flow_graph_dlg_w);
range_fr = gtk_frame_new("Choose packets");
gtk_box_pack_start(GTK_BOX(main_vb), range_fr, FALSE, FALSE, 5);
range_grid = ws_gtk_grid_new();
gtk_container_set_border_width(GTK_CONTAINER(range_grid), 5);
gtk_container_add(GTK_CONTAINER(range_fr), range_grid);
dialog_data.select_all_radio_button = gtk_radio_button_new_with_mnemonic_from_widget(NULL, "_All packets");
gtk_widget_set_tooltip_text(dialog_data.select_all_radio_button, ("Process all packets"));
g_signal_connect(dialog_data.select_all_radio_button, "toggled", G_CALLBACK(lbmc_uim_flow_toggle_select_all_cb), NULL);
ws_gtk_grid_attach_extended(GTK_GRID(range_grid), dialog_data.select_all_radio_button, 0, 0, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
if (dialog_data.packet_select_type == select_all_packets)
{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(dialog_data.select_all_radio_button), TRUE);
}
gtk_widget_show(dialog_data.select_all_radio_button);
dialog_data.select_displayed_radio_button =
gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(dialog_data.select_all_radio_button), "_Displayed packets");
gtk_widget_set_tooltip_text(dialog_data.select_displayed_radio_button, ("Process displayed packets"));
g_signal_connect(dialog_data.select_displayed_radio_button, "toggled", G_CALLBACK(lbmc_uim_flow_toggle_select_displayed_cb), NULL);
ws_gtk_grid_attach_extended(GTK_GRID(range_grid), dialog_data.select_displayed_radio_button, 0, 1, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
if (dialog_data.packet_select_type == select_displayed_packets)
{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(dialog_data.select_displayed_radio_button), TRUE);
}
gtk_widget_show(dialog_data.select_displayed_radio_button);
gtk_widget_show(range_grid);
gtk_widget_show(range_fr);
hbuttonbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start(GTK_BOX(main_vb), hbuttonbox, FALSE, FALSE, 5);
gtk_button_box_set_layout(GTK_BUTTON_BOX(hbuttonbox), GTK_BUTTONBOX_SPREAD);
gtk_box_set_spacing(GTK_BOX(hbuttonbox), 30);
bt_ok = gtk_button_new_from_stock(GTK_STOCK_OK);
gtk_container_add(GTK_CONTAINER(hbuttonbox), bt_ok);
gtk_widget_set_tooltip_text(bt_ok, "Show the flow graph");
g_signal_connect(bt_ok, "clicked", G_CALLBACK(lbmc_uim_flow_graph_on_ok_cb), flow_graph_dlg_w);
gtk_widget_show(bt_ok);
bt_cancel = gtk_button_new_from_stock(GTK_STOCK_CANCEL);
gtk_container_add(GTK_CONTAINER(hbuttonbox), bt_cancel);
#if GTK_CHECK_VERSION(2,18,0)
gtk_widget_set_can_default(bt_cancel, TRUE);
#else
GTK_WIDGET_SET_FLAGS(bt_cancel, GTK_CAN_DEFAULT);
#endif
gtk_widget_set_tooltip_text(bt_cancel, "Cancel this dialog");
window_set_cancel_button(flow_graph_dlg_w, bt_cancel, window_cancel_button_cb);
g_signal_connect(flow_graph_dlg_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(flow_graph_dlg_w, "destroy", G_CALLBACK(lbmc_uim_flow_graph_on_destroy_cb), NULL);
gtk_widget_show_all(flow_graph_dlg_w);
window_present(flow_graph_dlg_w);
dialog_data.flow_graph_dialog = flow_graph_dlg_w;
}
static void lbmc_uim_flow_graph_init_tap(const char * dummy _U_, void * user_data _U_)
{
if (dialog_data.flow_graph_dialog != NULL)
{
g_assert(dialog_data.graph_analysis != NULL);
g_assert(dialog_data.graph_analysis_data != NULL);
reactivate_window(dialog_data.flow_graph_dialog);
}
else
{
g_assert(dialog_data.graph_analysis == NULL);
g_assert(dialog_data.graph_analysis_data == NULL);
lbmc_uim_flow_graph_data_init();
dialog_data.graph_analysis_data = graph_analysis_init(dialog_data.graph_analysis);
lbmc_uim_flow_graph_dlg_create();
}
}
void lbmc_uim_flow_menu_cb(gpointer arg _U_)
{
lbmc_uim_flow_graph_init_tap("", NULL);
}
