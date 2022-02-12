static GNode*
find_stat_node(GNode *parent_stat_node, header_field_info *needle_hfinfo)
{
GNode *needle_stat_node;
header_field_info *hfinfo;
ph_stats_node_t *stats;
needle_stat_node = g_node_first_child(parent_stat_node);
while (needle_stat_node) {
hfinfo = STAT_NODE_HFINFO(needle_stat_node);
if (hfinfo && hfinfo->id == needle_hfinfo->id) {
return needle_stat_node;
}
needle_stat_node = g_node_next_sibling(needle_stat_node);
}
stats = g_new(ph_stats_node_t, 1);
stats->hfinfo = needle_hfinfo;
stats->num_pkts_total = 0;
stats->num_pkts_last = 0;
stats->num_bytes_total = 0;
stats->num_bytes_last = 0;
needle_stat_node = g_node_new(stats);
g_node_append(parent_stat_node, needle_stat_node);
return needle_stat_node;
}
static void
process_node(proto_node *ptree_node, GNode *parent_stat_node, ph_stats_t *ps, guint pkt_len)
{
field_info *finfo;
ph_stats_node_t *stats;
proto_node *proto_sibling_node;
GNode *stat_node;
finfo = PNODE_FINFO(ptree_node);
g_assert(finfo && "dissection with faked proto tree?");
if (finfo->hfinfo->parent != -1) {
stat_node = parent_stat_node;
stats = STAT_NODE_STATS(stat_node);
} else {
stat_node = find_stat_node(parent_stat_node, finfo->hfinfo);
stats = STAT_NODE_STATS(stat_node);
stats->num_pkts_total++;
stats->num_bytes_total += pkt_len;
}
proto_sibling_node = ptree_node->next;
if (proto_sibling_node) {
if(strlen(PNODE_FINFO(proto_sibling_node)->hfinfo->name) == 0 && ptree_node->next)
proto_sibling_node = proto_sibling_node->next;
process_node(proto_sibling_node, stat_node, ps, pkt_len);
} else {
stats->num_pkts_last++;
stats->num_bytes_last += pkt_len;
}
}
static void
process_tree(proto_tree *protocol_tree, ph_stats_t* ps, guint pkt_len)
{
proto_node *ptree_node;
ptree_node = ((proto_node *)protocol_tree)->first_child;
if (!ptree_node) {
return;
}
process_node(ptree_node, ps->stats_tree, ps, pkt_len);
}
static gboolean
process_frame(frame_data *frame, column_info *cinfo, ph_stats_t* ps)
{
epan_dissect_t edt;
union wtap_pseudo_header phdr;
guint8 pd[WTAP_MAX_PACKET_SIZE];
double cur_time;
if (!cf_read_frame_r(&cfile, frame, &phdr, pd))
return FALSE;
epan_dissect_init(&edt, TRUE, FALSE);
epan_dissect_fake_protocols(&edt, FALSE);
epan_dissect_run(&edt, &phdr, pd, frame, cinfo);
process_tree(edt.tree, ps, frame->pkt_len);
cur_time = nstime_to_sec(&frame->abs_ts);
if (cur_time < ps->first_time) {
ps->first_time = cur_time;
}
if (cur_time > ps->last_time){
ps->last_time = cur_time;
}
epan_dissect_cleanup(&edt);
return TRUE;
}
ph_stats_t*
ph_stats_new(void)
{
ph_stats_t *ps;
guint32 framenum;
frame_data *frame;
guint tot_packets, tot_bytes;
progdlg_t *progbar = NULL;
gboolean stop_flag;
int count;
float progbar_val;
GTimeVal start_time;
gchar status_str[100];
int progbar_nextstep;
int progbar_quantum;
ps = g_new(ph_stats_t, 1);
ps->tot_packets = 0;
ps->tot_bytes = 0;
ps->stats_tree = g_node_new(NULL);
ps->first_time = 0.0;
ps->last_time = 0.0;
progbar_nextstep = 0;
progbar_quantum = cfile.count/N_PROGBAR_UPDATES;
count = 0;
progbar_val = 0.0f;
stop_flag = FALSE;
g_get_current_time(&start_time);
tot_packets = 0;
tot_bytes = 0;
for (framenum = 1; framenum <= cfile.count; framenum++) {
frame = frame_data_sequence_find(cfile.frames, framenum);
if (progbar == NULL)
progbar = delayed_create_progress_dlg(
"Computing", "protocol hierarchy statistics",
TRUE, &stop_flag, &start_time, progbar_val);
if (count >= progbar_nextstep) {
g_assert(cfile.count > 0);
progbar_val = (gfloat) count / cfile.count;
if (progbar != NULL) {
g_snprintf(status_str, sizeof(status_str),
"%4u of %u frames", count, cfile.count);
update_progress_dlg(progbar, progbar_val, status_str);
}
progbar_nextstep += progbar_quantum;
}
if (stop_flag) {
break;
}
if (frame->flags.passed_dfilter) {
if (tot_packets == 0) {
double cur_time = nstime_to_sec(&frame->abs_ts);
ps->first_time = cur_time;
ps->last_time = cur_time;
}
if (!process_frame(frame, NULL, ps)) {
stop_flag = TRUE;
break;
}
tot_packets++;
tot_bytes += frame->pkt_len;
}
count++;
}
if (progbar != NULL)
destroy_progress_dlg(progbar);
if (stop_flag) {
ph_stats_free(ps);
return NULL;
}
ps->tot_packets = tot_packets;
ps->tot_bytes = tot_bytes;
return ps;
}
static gboolean
stat_node_free(GNode *node, gpointer data _U_)
{
ph_stats_node_t *stats = (ph_stats_node_t *)node->data;
if (stats) {
g_free(stats);
}
return FALSE;
}
void
ph_stats_free(ph_stats_t *ps)
{
if (ps->stats_tree) {
g_node_traverse(ps->stats_tree, G_IN_ORDER,
G_TRAVERSE_ALL, -1,
stat_node_free, NULL);
g_node_destroy(ps->stats_tree);
}
g_free(ps);
}
