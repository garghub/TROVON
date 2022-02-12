static void
flow_graph_data_init(void) {
graph_analysis = (seq_analysis_info_t *)g_malloc0(sizeof(seq_analysis_info_t));
graph_analysis->type = SEQ_ANALYSIS_ANY;
graph_analysis->all_packets = TRUE;
graph_analysis->items = g_queue_new();
}
static void
flow_graph_on_destroy(GObject *object _U_, gpointer user_data _U_)
{
sequence_analysis_list_free(graph_analysis);
g_assert(graph_analysis != NULL);
g_assert(graph_analysis_data != NULL);
g_free(graph_analysis);
graph_analysis = NULL;
g_free(graph_analysis_data);
graph_analysis_data = NULL;
flow_graph_dlg = NULL;
}
static void
toggle_select_all(GtkWidget *widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(select_all_rb))) {
graph_analysis->all_packets = TRUE;
}
}
static void
toggle_select_displayed(GtkWidget *widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(select_displayed_rb))) {
graph_analysis->all_packets = FALSE;
}
}
static void
toggle_select_general(GtkWidget *widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(select_general_rb))) {
graph_analysis->type = SEQ_ANALYSIS_ANY;
}
}
static void
toggle_select_tcp(GtkWidget *widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(select_tcp_rb))) {
graph_analysis->type = SEQ_ANALYSIS_TCP;
}
}
static void
toggle_select_srcdst(GtkWidget *widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(src_dst_rb))) {
graph_analysis->any_addr = TRUE;
}
}
static void
toggle_select_netsrcdst(GtkWidget *widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(net_src_dst_rb))) {
graph_analysis->any_addr = TRUE;
}
}
static void
flow_graph_on_ok(GtkButton *button _U_,
gpointer user_data)
{
sequence_analysis_list_free(graph_analysis);
sequence_analysis_list_get(&cfile, graph_analysis);
if (graph_analysis_data->dlg.window != NULL){
graph_analysis_update(graph_analysis_data);
}
else{
graph_analysis_data->dlg.parent_w = (GtkWidget *)user_data;
graph_analysis_create(graph_analysis_data);
}
}
static void
flow_graph_on_cancel(GtkButton *button _U_,
gpointer user_data)
{
if (graph_analysis_data->dlg.window) {
window_destroy(graph_analysis_data->dlg.window);
}
window_destroy(GTK_WIDGET(user_data));
}
static gboolean
flow_graph_on_delete(GtkButton *button _U_,
gpointer user_data _U_)
{
if (graph_analysis_data->dlg.window) {
window_destroy(graph_analysis_data->dlg.window);
}
return FALSE;
}
static void
flow_graph_dlg_create(void)
{
GtkWidget *flow_graph_dlg_w;
GtkWidget *main_vb;
GtkWidget *hbuttonbox;
GtkWidget *bt_cancel, *bt_ok;
#if 0
GtkWidget *top_label = NULL;
#endif
GtkWidget *flow_type_fr, *range_fr, *range_grid, *flow_type_grid, *node_addr_fr, *node_addr_grid;
flow_graph_dlg_w = dlg_window_new("Wireshark: Flow Graph");
gtk_window_set_destroy_with_parent (GTK_WINDOW(flow_graph_dlg_w), TRUE);
gtk_window_set_default_size(GTK_WINDOW(flow_graph_dlg_w), 250, 150);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(flow_graph_dlg_w), main_vb);
gtk_container_set_border_width (GTK_CONTAINER (main_vb), 7);
#if 0
top_label = gtk_label_new ("Choose packets to include in the graph");
gtk_box_pack_start (GTK_BOX (main_vb), top_label, FALSE, FALSE, 8);
#endif
gtk_widget_show(flow_graph_dlg_w);
range_fr = gtk_frame_new("Choose packets");
gtk_box_pack_start(GTK_BOX(main_vb), range_fr, FALSE, FALSE, 5);
range_grid = ws_gtk_grid_new();
gtk_container_set_border_width(GTK_CONTAINER(range_grid), 5);
gtk_container_add(GTK_CONTAINER(range_fr), range_grid);
select_all_rb = gtk_radio_button_new_with_mnemonic_from_widget(NULL, "_All packets");
gtk_widget_set_tooltip_text (select_all_rb, ("Process all packets"));
g_signal_connect(select_all_rb, "toggled", G_CALLBACK(toggle_select_all), NULL);
ws_gtk_grid_attach_extended(GTK_GRID(range_grid), select_all_rb, 0, 0, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
if (graph_analysis->all_packets) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_all_rb),TRUE);
}
gtk_widget_show(select_all_rb);
select_displayed_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(select_all_rb),
"_Displayed packets");
gtk_widget_set_tooltip_text (select_displayed_rb, ("Process displayed packets"));
g_signal_connect(select_displayed_rb, "toggled", G_CALLBACK(toggle_select_displayed), NULL);
ws_gtk_grid_attach_extended(GTK_GRID(range_grid), select_displayed_rb, 0, 1, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
if (!graph_analysis->all_packets) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_displayed_rb),TRUE);
}
gtk_widget_show(select_displayed_rb);
gtk_widget_show(range_grid);
gtk_widget_show(range_fr);
flow_type_fr = gtk_frame_new("Choose flow type");
gtk_box_pack_start(GTK_BOX(main_vb), flow_type_fr, FALSE, FALSE, 5);
flow_type_grid = ws_gtk_grid_new();
gtk_container_set_border_width(GTK_CONTAINER(flow_type_grid), 5);
gtk_container_add(GTK_CONTAINER(flow_type_fr), flow_type_grid);
select_general_rb = gtk_radio_button_new_with_mnemonic_from_widget(NULL, "_General flow");
gtk_widget_set_tooltip_text (select_general_rb, ("Show all packets, with general information"));
g_signal_connect(select_general_rb, "toggled", G_CALLBACK(toggle_select_general), NULL);
ws_gtk_grid_attach_extended(GTK_GRID(flow_type_grid), select_general_rb, 0, 0, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
if (graph_analysis->type == SEQ_ANALYSIS_ANY) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_general_rb),TRUE);
}
gtk_widget_show(select_general_rb);
select_tcp_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(select_general_rb),
"_TCP flow");
gtk_widget_set_tooltip_text (select_tcp_rb, ("Show only TCP packets, with TCP specific information"));
g_signal_connect(select_tcp_rb, "toggled", G_CALLBACK(toggle_select_tcp), NULL);
ws_gtk_grid_attach_extended(GTK_GRID(flow_type_grid), select_tcp_rb, 0, 1, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
if (graph_analysis->type == SEQ_ANALYSIS_TCP) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_tcp_rb),TRUE);
}
gtk_widget_show(select_tcp_rb);
gtk_widget_show(flow_type_grid);
gtk_widget_show(flow_type_fr);
node_addr_fr = gtk_frame_new("Choose node address type");
gtk_box_pack_start(GTK_BOX(main_vb), node_addr_fr, FALSE, FALSE, 5);
node_addr_grid = ws_gtk_grid_new();
gtk_container_set_border_width(GTK_CONTAINER(node_addr_grid), 5);
gtk_container_add(GTK_CONTAINER(node_addr_fr), node_addr_grid);
src_dst_rb = gtk_radio_button_new_with_mnemonic_from_widget(NULL, "_Standard source/destination addresses");
gtk_widget_set_tooltip_text (src_dst_rb,
("Nodes in the diagram are identified with source and destination addresses"));
g_signal_connect(src_dst_rb, "toggled", G_CALLBACK(toggle_select_srcdst), NULL);
ws_gtk_grid_attach_extended(GTK_GRID(node_addr_grid), src_dst_rb, 0, 0, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
if (graph_analysis->any_addr) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(src_dst_rb),TRUE);
}
gtk_widget_show(src_dst_rb);
net_src_dst_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(src_dst_rb),
"_Network source/destination addresses");
gtk_widget_set_tooltip_text (net_src_dst_rb,
("Nodes in the diagram are identified with network source and destination addresses"));
g_signal_connect(net_src_dst_rb, "toggled", G_CALLBACK(toggle_select_netsrcdst), NULL);
ws_gtk_grid_attach_extended(GTK_GRID(node_addr_grid), net_src_dst_rb, 0, 1, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
if (!graph_analysis->any_addr) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(net_src_dst_rb),TRUE);
}
gtk_widget_show(net_src_dst_rb);
gtk_widget_show(node_addr_grid);
gtk_widget_show(node_addr_fr);
hbuttonbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start (GTK_BOX (main_vb), hbuttonbox, FALSE, FALSE, 5);
gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox), GTK_BUTTONBOX_SPREAD);
gtk_box_set_spacing (GTK_BOX (hbuttonbox), 30);
bt_ok = ws_gtk_button_new_from_stock(GTK_STOCK_OK);
gtk_box_pack_start(GTK_BOX(hbuttonbox), bt_ok, TRUE, TRUE, 0);
gtk_widget_set_tooltip_text (bt_ok, "Show the flow graph");
g_signal_connect(bt_ok, "clicked", G_CALLBACK(flow_graph_on_ok), flow_graph_dlg_w);
gtk_widget_show(bt_ok);
bt_cancel = ws_gtk_button_new_from_stock(GTK_STOCK_CANCEL);
gtk_box_pack_start(GTK_BOX(hbuttonbox), bt_cancel, TRUE, TRUE, 0);
gtk_widget_set_can_default(bt_cancel, TRUE);
gtk_widget_set_tooltip_text (bt_cancel, "Cancel this dialog");
g_signal_connect(bt_cancel, "clicked", G_CALLBACK(flow_graph_on_cancel), flow_graph_dlg_w);
g_signal_connect(flow_graph_dlg_w, "delete_event", G_CALLBACK(flow_graph_on_delete), NULL);
g_signal_connect(flow_graph_dlg_w, "destroy", G_CALLBACK(flow_graph_on_destroy), NULL);
gtk_widget_show_all(flow_graph_dlg_w);
window_present(flow_graph_dlg_w);
flow_graph_dlg = flow_graph_dlg_w;
}
static void
flow_graph_init_tap(const char *dummy _U_, void *userdata _U_)
{
if (flow_graph_dlg != NULL) {
g_assert(graph_analysis != NULL);
g_assert(graph_analysis_data != NULL);
reactivate_window(flow_graph_dlg);
} else {
g_assert(graph_analysis == NULL);
g_assert(graph_analysis_data == NULL);
flow_graph_data_init();
graph_analysis_data = graph_analysis_init(graph_analysis);
flow_graph_dlg_create();
}
}
void
flow_graph_launch(GtkAction *action _U_, gpointer user_data _U_)
{
flow_graph_init_tap("",NULL);
}
void
register_tap_listener_flow_graph(void)
{
register_stat_cmd_arg("flow_graph",flow_graph_init_tap,NULL);
}
