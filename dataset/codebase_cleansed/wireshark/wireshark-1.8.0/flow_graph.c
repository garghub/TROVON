static void
flow_graph_reset(void *ptr _U_)
{
graph_analysis_item_t *graph_item;
GList* list;
if (graph_analysis !=NULL){
list = g_list_first(graph_analysis->list);
while (list)
{
graph_item = list->data;
g_free(graph_item->frame_label);
g_free(graph_item->comment);
g_free(list->data);
list = g_list_next(list);
}
g_list_free(graph_analysis->list);
graph_analysis->nconv = 0;
graph_analysis->list = NULL;
}
}
static void
flow_graph_data_init(void) {
graph_analysis = g_malloc(sizeof(graph_analysis_info_t));
graph_analysis->nconv = 0;
graph_analysis->list = NULL;
}
static void
remove_tap_listener_flow_graph(void)
{
protect_thread_critical_region();
remove_tap_listener(&(tap_identifier));
unprotect_thread_critical_region();
have_frame_tap_listener=FALSE;
have_tcp_tap_listener=FALSE;
}
static void
flow_graph_on_destroy(GObject *object _U_, gpointer user_data _U_)
{
remove_tap_listener_flow_graph();
flow_graph_reset(NULL);
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
type_of_packets = TYPE_OF_PACKETS_ALL;
}
}
static void
toggle_select_displayed(GtkWidget *widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(select_displayed_rb))) {
type_of_packets = TYPE_OF_PACKETS_DISPLAYED;
}
}
static void
toggle_select_general(GtkWidget *widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(select_general_rb))) {
type_of_flow = TYPE_OF_FLOW_GENERAL;
}
}
static void
toggle_select_tcp(GtkWidget *widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(select_tcp_rb))) {
type_of_flow = TYPE_OF_FLOW_TCP;
}
}
static void
toggle_select_srcdst(GtkWidget *widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(src_dst_rb))) {
node_addr_type = NODE_ADDR_TYPE_SRCDST;
}
}
static void
toggle_select_netsrcdst(GtkWidget *widget _U_, gpointer user_data _U_)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(net_src_dst_rb))) {
node_addr_type = NODE_ADDR_TYPE_NET_SRCDST;
}
}
static int
flow_graph_frame_add_to_graph(packet_info *pinfo)
{
graph_analysis_item_t *gai;
int i;
gchar *protocol;
gchar *colinfo;
protocol=NULL;
colinfo=NULL;
if (node_addr_type == NODE_ADDR_TYPE_NET_SRCDST) {
if (pinfo->net_src.type!=AT_NONE && pinfo->net_dst.type!=AT_NONE) {
gai = g_malloc(sizeof(graph_analysis_item_t));
COPY_ADDRESS(&(gai->src_addr),&(pinfo->net_src));
COPY_ADDRESS(&(gai->dst_addr),&(pinfo->net_dst));
}
else return 0;
} else {
if (pinfo->src.type!=AT_NONE && pinfo->dst.type!=AT_NONE) {
gai = g_malloc(sizeof(graph_analysis_item_t));
COPY_ADDRESS(&(gai->src_addr),&(pinfo->src));
COPY_ADDRESS(&(gai->dst_addr),&(pinfo->dst));
}
else return 0;
}
gai->fd = pinfo->fd;
gai->port_src=pinfo->srcport;
gai->port_dst=pinfo->destport;
gai->comment=NULL;
gai->frame_label=NULL;
if(pinfo->cinfo) {
if (pinfo->cinfo->col_first[COL_INFO]>=0){
for (i = pinfo->cinfo->col_first[COL_INFO]; i <= pinfo->cinfo->col_last[COL_INFO]; i++) {
if (pinfo->cinfo->fmt_matx[i][COL_INFO]) {
colinfo = g_strdup(pinfo->cinfo->col_data[i]);
}
}
}
if (pinfo->cinfo->col_first[COL_PROTOCOL]>=0){
for (i = pinfo->cinfo->col_first[COL_PROTOCOL]; i <= pinfo->cinfo->col_last[COL_PROTOCOL]; i++) {
if (pinfo->cinfo->fmt_matx[i][COL_PROTOCOL]) {
protocol = g_strdup(pinfo->cinfo->col_data[i]);
}
}
}
}
if (colinfo != NULL) {
if (protocol != NULL) {
gai->frame_label = g_strdup_printf("%.19s", colinfo);
gai->comment = g_strdup_printf("%s: %s", protocol, colinfo);
} else {
gai->frame_label = g_strdup_printf("%.19s", colinfo);
gai->comment = g_strdup_printf("%s", colinfo);
}
} else {
if (protocol != NULL) {
gai->frame_label = g_strdup_printf("%.19s", protocol);
gai->comment = g_strdup_printf("%s", protocol);
}
}
g_free(protocol);
g_free(colinfo);
gai->line_style=1;
gai->conv_num=0;
gai->display=TRUE;
graph_analysis->list = g_list_append(graph_analysis->list, gai);
return 1;
}
static int
flow_graph_tcp_add_to_graph(packet_info *pinfo, const struct tcpheader *tcph)
{
graph_analysis_item_t *gai;
const gchar *fstr[] = {"FIN", "SYN", "RST", "PSH", "ACK", "URG", "ECN", "CWR" };
guint i, bpos;
gboolean flags_found = FALSE;
gchar flags[64];
gai = g_malloc(sizeof(graph_analysis_item_t));
gai->fd = pinfo->fd;
if (node_addr_type == NODE_ADDR_TYPE_NET_SRCDST) {
COPY_ADDRESS(&(gai->src_addr),&(pinfo->net_src));
COPY_ADDRESS(&(gai->dst_addr),&(pinfo->net_dst));
} else {
COPY_ADDRESS(&(gai->src_addr),&(pinfo->src));
COPY_ADDRESS(&(gai->dst_addr),&(pinfo->dst));
}
gai->port_src=pinfo->srcport;
gai->port_dst=pinfo->destport;
flags[0] = '\0';
for (i = 0; i < 8; i++) {
bpos = 1 << i;
if (tcph->th_flags & bpos) {
if (flags_found) {
g_strlcat(flags, ", ", sizeof(flags));
}
g_strlcat(flags, fstr[i], sizeof(flags));
flags_found = TRUE;
}
}
if (flags[0] == '\0') {
g_snprintf (flags, sizeof(flags), "<None>");
}
if ((tcph->th_have_seglen)&&(tcph->th_seglen!=0)){
gai->frame_label = g_strdup_printf("%s - Len: %u",flags, tcph->th_seglen);
}
else{
gai->frame_label = g_strdup(flags);
}
if (tcph->th_flags & TH_ACK)
gai->comment = g_strdup_printf("Seq = %u Ack = %u",tcph->th_seq, tcph->th_ack);
else
gai->comment = g_strdup_printf("Seq = %u",tcph->th_seq);
gai->line_style=1;
gai->conv_num=0;
gai->display=TRUE;
graph_analysis->list = g_list_append(graph_analysis->list, gai);
return 1;
}
static gboolean
flow_graph_frame_packet( void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *dummy _U_)
{
if ((type_of_packets == TYPE_OF_PACKETS_ALL)||(pinfo->fd->flags.passed_dfilter==1)){
flow_graph_frame_add_to_graph(pinfo);
}
return TRUE;
}
static gboolean
flow_graph_tcp_packet( void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *tcp_info)
{
const struct tcpheader *tcph = tcp_info;
if ((type_of_packets == TYPE_OF_PACKETS_ALL)||(pinfo->fd->flags.passed_dfilter==1)){
flow_graph_tcp_add_to_graph(pinfo,tcph);
}
return TRUE;
}
static void
flow_graph_packet_draw(void *prs _U_)
{
return;
}
static void
flow_graph_on_ok (GtkButton *button _U_,
gpointer user_data)
{
if ((have_frame_tap_listener==TRUE)
||(have_tcp_tap_listener==TRUE))
{
remove_tap_listener_flow_graph();
}
if (type_of_flow == TYPE_OF_FLOW_GENERAL){
if(have_frame_tap_listener==FALSE)
{
register_tap_listener("frame", &tap_identifier, NULL,
TL_REQUIRES_COLUMNS,
flow_graph_reset,
flow_graph_frame_packet,
flow_graph_packet_draw
);
have_frame_tap_listener=TRUE;
}
cf_retap_packets(&cfile);
}
else if (type_of_flow == TYPE_OF_FLOW_TCP){
if(have_tcp_tap_listener==FALSE)
{
register_tap_listener("tcp", &tap_identifier, NULL,
0,
flow_graph_reset,
flow_graph_tcp_packet,
flow_graph_packet_draw
);
have_tcp_tap_listener=TRUE;
}
cf_retap_packets(&cfile);
}
if (graph_analysis_data->dlg.window != NULL){
graph_analysis_update(graph_analysis_data);
}
else{
graph_analysis_data->dlg.parent_w = user_data;
graph_analysis_create(graph_analysis_data);
}
}
static void
flow_graph_dlg_create (void)
{
GtkWidget *flow_graph_dlg_w;
GtkWidget *main_vb;
GtkWidget *hbuttonbox;
GtkWidget *bt_cancel, *bt_ok;
#if 0
GtkWidget *top_label = NULL;
#endif
GtkWidget *flow_type_fr, *range_fr, *range_tb, *flow_type_tb, *node_addr_fr, *node_addr_tb;
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
range_tb = gtk_table_new(4, 4, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(range_tb), 5);
gtk_container_add(GTK_CONTAINER(range_fr), range_tb);
select_all_rb = gtk_radio_button_new_with_mnemonic_from_widget(NULL, "_All packets");
gtk_widget_set_tooltip_text (select_all_rb, ("Process all packets"));
g_signal_connect(select_all_rb, "toggled", G_CALLBACK(toggle_select_all), NULL);
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_all_rb, 0, 1, 0, 1);
if (type_of_packets == TYPE_OF_PACKETS_ALL) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_all_rb),TRUE);
}
gtk_widget_show(select_all_rb);
select_displayed_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(select_all_rb),
"_Displayed packets");
gtk_widget_set_tooltip_text (select_displayed_rb, ("Process displayed packets"));
g_signal_connect(select_displayed_rb, "toggled", G_CALLBACK(toggle_select_displayed), NULL);
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_displayed_rb, 0, 1, 1, 2);
if (type_of_packets == TYPE_OF_PACKETS_DISPLAYED) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_displayed_rb),TRUE);
}
gtk_widget_show(select_displayed_rb);
gtk_widget_show(range_tb);
gtk_widget_show(range_fr);
flow_type_fr = gtk_frame_new("Choose flow type");
gtk_box_pack_start(GTK_BOX(main_vb), flow_type_fr, FALSE, FALSE, 5);
flow_type_tb = gtk_table_new(4, 4, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(flow_type_tb), 5);
gtk_container_add(GTK_CONTAINER(flow_type_fr), flow_type_tb);
select_general_rb = gtk_radio_button_new_with_mnemonic_from_widget(NULL, "_General flow");
gtk_widget_set_tooltip_text (select_general_rb, ("Show all packets, with general information"));
g_signal_connect(select_general_rb, "toggled", G_CALLBACK(toggle_select_general), NULL);
gtk_table_attach_defaults(GTK_TABLE(flow_type_tb), select_general_rb, 0, 1, 0, 1);
if (type_of_flow == TYPE_OF_FLOW_GENERAL) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_general_rb),TRUE);
}
gtk_widget_show(select_general_rb);
select_tcp_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(select_general_rb),
"_TCP flow");
gtk_widget_set_tooltip_text (select_tcp_rb, ("Show only TCP packets, with TCP specific information"));
g_signal_connect(select_tcp_rb, "toggled", G_CALLBACK(toggle_select_tcp), NULL);
gtk_table_attach_defaults(GTK_TABLE(flow_type_tb), select_tcp_rb, 0, 1, 1, 2);
if (type_of_flow == TYPE_OF_FLOW_TCP) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_tcp_rb),TRUE);
}
gtk_widget_show(select_tcp_rb);
gtk_widget_show(flow_type_tb);
gtk_widget_show(flow_type_fr);
node_addr_fr = gtk_frame_new("Choose node address type");
gtk_box_pack_start(GTK_BOX(main_vb), node_addr_fr, FALSE, FALSE, 5);
node_addr_tb = gtk_table_new(4, 4, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(node_addr_tb), 5);
gtk_container_add(GTK_CONTAINER(node_addr_fr), node_addr_tb);
src_dst_rb = gtk_radio_button_new_with_mnemonic_from_widget(NULL, "_Standard source/destination addresses");
gtk_widget_set_tooltip_text (src_dst_rb,
("Nodes in the diagram are identified with source and destination addresses"));
g_signal_connect(src_dst_rb, "toggled", G_CALLBACK(toggle_select_srcdst), NULL);
gtk_table_attach_defaults(GTK_TABLE(node_addr_tb), src_dst_rb, 0, 1, 0, 1);
if (node_addr_type == NODE_ADDR_TYPE_SRCDST) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(src_dst_rb),TRUE);
}
gtk_widget_show(src_dst_rb);
net_src_dst_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(src_dst_rb),
"_Network source/destination addresses");
gtk_widget_set_tooltip_text (net_src_dst_rb,
("Nodes in the diagram are identified with network source and destination addresses"));
g_signal_connect(net_src_dst_rb, "toggled", G_CALLBACK(toggle_select_netsrcdst), NULL);
gtk_table_attach_defaults(GTK_TABLE(node_addr_tb), net_src_dst_rb, 0, 1, 1, 2);
if (node_addr_type == NODE_ADDR_TYPE_NET_SRCDST) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(net_src_dst_rb),TRUE);
}
gtk_widget_show(net_src_dst_rb);
gtk_widget_show(node_addr_tb);
gtk_widget_show(node_addr_fr);
hbuttonbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start (GTK_BOX (main_vb), hbuttonbox, FALSE, FALSE, 5);
gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox), GTK_BUTTONBOX_SPREAD);
gtk_box_set_spacing (GTK_BOX (hbuttonbox), 30);
bt_ok = gtk_button_new_from_stock(GTK_STOCK_OK);
gtk_container_add(GTK_CONTAINER(hbuttonbox), bt_ok);
gtk_widget_set_tooltip_text (bt_ok, "Show the flow graph");
g_signal_connect(bt_ok, "clicked", G_CALLBACK(flow_graph_on_ok), flow_graph_dlg_w);
gtk_widget_show(bt_ok);
bt_cancel = gtk_button_new_from_stock(GTK_STOCK_CANCEL);
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_cancel);
#if GTK_CHECK_VERSION(2,18,0)
gtk_widget_set_can_default(bt_cancel, TRUE);
#else
GTK_WIDGET_SET_FLAGS(bt_cancel, GTK_CAN_DEFAULT);
#endif
gtk_widget_set_tooltip_text (bt_cancel, "Cancel this dialog");
window_set_cancel_button(flow_graph_dlg_w, bt_cancel, window_cancel_button_cb);
g_signal_connect(flow_graph_dlg_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(flow_graph_dlg_w, "destroy", G_CALLBACK(flow_graph_on_destroy), NULL);
gtk_widget_show_all(flow_graph_dlg_w);
window_present(flow_graph_dlg_w);
flow_graph_dlg = flow_graph_dlg_w;
}
static void
flow_graph_init_tap(const char *dummy _U_, void* userdata _U_)
{
if (flow_graph_dlg != NULL) {
g_assert(graph_analysis != NULL);
g_assert(graph_analysis_data != NULL);
reactivate_window(flow_graph_dlg);
} else {
g_assert(graph_analysis == NULL);
g_assert(graph_analysis_data == NULL);
flow_graph_data_init();
graph_analysis_data = graph_analysis_init();
graph_analysis_data->graph_info = graph_analysis;
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
