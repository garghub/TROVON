static void
sctpstat_reset(void *phs)
{
sctpstat_t* sctp_stat = (sctpstat_t *)phs;
sctp_ep_t* list = (sctp_ep_t*)sctp_stat->ep_list;
sctp_ep_t* tmp = NULL;
guint16 chunk_type;
if(!list)
return;
for(tmp = list; tmp ; tmp=tmp->next)
for(chunk_type = 0; chunk_type < 256; chunk_type++)
tmp->chunk_count[chunk_type] = 0;
sctp_stat->number_of_packets = 0;
}
static sctp_ep_t* alloc_sctp_ep(struct _sctp_info *si)
{
sctp_ep_t* ep;
guint16 chunk_type;
if(!si)
return NULL;
if (!(ep = (sctp_ep_t *)g_malloc(sizeof(sctp_ep_t))))
return NULL;
copy_address(&ep->src,&si->ip_src);
copy_address(&ep->dst,&si->ip_dst);
ep->sport = si->sport;
ep->dport = si->dport;
ep->next = NULL;
for(chunk_type = 0; chunk_type < 256; chunk_type++)
ep->chunk_count[chunk_type] = 0;
return ep;
}
static int
sctpstat_packet(void *phs, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *phi)
{
sctpstat_t *hs=(sctpstat_t *)phs;
sctp_ep_t *tmp = NULL, *te = NULL;
struct _sctp_info *si = (struct _sctp_info *) phi;
guint32 tvb_number;
if (!hs)
return (0);
hs->number_of_packets++;
if(!hs->ep_list) {
hs->ep_list = alloc_sctp_ep(si);
te = hs->ep_list;
} else {
for(tmp=hs->ep_list ; tmp ; tmp=tmp->next) {
if((!cmp_address(&tmp->src,&si->ip_src)) &&
(!cmp_address(&tmp->dst,&si->ip_dst)) &&
(tmp->sport == si->sport) &&
(tmp->dport == si->dport)) {
te = tmp;
break;
}
}
if(!te) {
if ((te = alloc_sctp_ep(si))) {
te->next = hs->ep_list;
hs->ep_list = te;
}
}
}
if(!te)
return (0);
if (si->number_of_tvbs > 0) {
for(tvb_number = 0; tvb_number < si->number_of_tvbs; tvb_number++) {
if (IS_SCTP_CHUNK_TYPE(CHUNK_TYPE(si->tvb[tvb_number])))
(te->chunk_count[CHUNK_TYPE(si->tvb[tvb_number])])++;
else
(te->chunk_count[OTHER_CHUNKS_INDEX])++;
}
}
return (1);
}
static void
sctpstat_draw(void *phs)
{
sctpstat_t *hs=(sctpstat_t *)phs;
sctp_ep_t* list = hs->ep_list, *tmp;
GtkListStore *store;
GtkTreeIter iter;
char *src_addr, *dst_addr;
store = GTK_LIST_STORE(gtk_tree_view_get_model(hs->table));
gtk_list_store_clear(store);
for(tmp = list ; tmp ; tmp=tmp->next) {
src_addr = (char*)address_to_str(NULL, &tmp->src);
dst_addr = (char*)address_to_str(NULL, &tmp->dst);
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, src_addr,
1, tmp->sport,
2, dst_addr,
3, tmp->dport,
4, tmp->chunk_count[SCTP_DATA_CHUNK_ID],
5, tmp->chunk_count[SCTP_SACK_CHUNK_ID],
6, tmp->chunk_count[SCTP_HEARTBEAT_CHUNK_ID],
7, tmp->chunk_count[SCTP_HEARTBEAT_ACK_CHUNK_ID],
8, tmp->chunk_count[SCTP_INIT_CHUNK_ID],
9, tmp->chunk_count[SCTP_INIT_ACK_CHUNK_ID],
10, tmp->chunk_count[SCTP_COOKIE_ECHO_CHUNK_ID],
11, tmp->chunk_count[SCTP_COOKIE_ACK_CHUNK_ID],
12, tmp->chunk_count[SCTP_ABORT_CHUNK_ID],
13, tmp->chunk_count[SCTP_ERROR_CHUNK_ID],
14, tmp->chunk_count[SCTP_NR_SACK_CHUNK_ID],
15, tmp->chunk_count[SCTP_I_DATA_CHUNK_ID],
16, tmp->chunk_count[SCTP_ASCONF_ACK_CHUNK_ID],
17, tmp->chunk_count[SCTP_PKTDROP_CHUNK_ID],
18, tmp->chunk_count[SCTP_FORWARD_TSN_CHUNK_ID],
19, tmp->chunk_count[SCTP_ASCONF_CHUNK_ID],
20, tmp->chunk_count[OTHER_CHUNKS_INDEX],
-1
);
wmem_free(NULL, src_addr);
wmem_free(NULL, dst_addr);
}
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
sctpstat_t *hs=(sctpstat_t *)data;
remove_tap_listener(hs);
if(hs->filter){
g_free(hs->filter);
hs->filter=NULL;
}
g_free(hs);
}
static void
sctpstat_init(const char *opt_arg, void *userdata _U_)
{
sctpstat_t *hs;
GString *error_string;
GtkWidget *bbox;
GtkWidget *close_bt;
hs=(sctpstat_t *)g_malloc(sizeof(sctpstat_t));
if(strncmp(opt_arg,"sctp,stat,",10) == 0){
hs->filter=g_strdup(opt_arg+10);
} else {
hs->filter=NULL;
}
hs->ep_list = NULL;
hs->number_of_packets = 0;
sctpstat_reset(hs);
hs->win = dlg_window_new("Wireshark: SCTP Chunk Statistics");
gtk_window_set_destroy_with_parent (GTK_WINDOW(hs->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(hs->win), 700, 250);
hs->vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(hs->vbox), 12);
init_main_stat_window(hs->win, hs->vbox, "SCTP Chunk Counter", hs->filter);
hs->scrolled_window = scrolled_window_new(NULL, NULL);
hs->table = create_stat_table(hs->scrolled_window, hs->vbox, 20, titles);
error_string=register_tap_listener("sctp", hs, hs->filter, 0,
sctpstat_reset,
sctpstat_packet,
sctpstat_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
g_free(hs->filter);
g_free(hs);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(hs->vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(hs->win, close_bt, window_cancel_button_cb);
g_signal_connect(hs->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(hs->win, "destroy", G_CALLBACK(win_destroy_cb), hs);
gtk_widget_show_all(hs->win);
window_present(hs->win);
cf_retap_packets(&cfile);
}
void
register_tap_listener_sctpstat(void)
{
register_param_stat(&sctp_stat_dlg, "Chunk Counter",
REGISTER_STAT_GROUP_TELEPHONY_SCTP);
}
