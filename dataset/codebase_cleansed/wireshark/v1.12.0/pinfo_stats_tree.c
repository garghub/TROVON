static void* uat_plen_record_copy_cb(void* n, const void* o, size_t siz _U_) {
const uat_plen_record_t *r = (const uat_plen_record_t *)o;
uat_plen_record_t *rn = (uat_plen_record_t *)n;
if (r->packet_range)
rn->packet_range = range_copy(r->packet_range);
return n;
}
static void
uat_plen_record_update_cb(void *r, const char **err)
{
uat_plen_record_t *rec = (uat_plen_record_t*)r;
if (rec->packet_range->nranges < 1) {
*err = g_strdup("Invalid range string");
return;
}
*err = NULL;
}
static void uat_plen_record_free_cb(void*r) {
uat_plen_record_t* record = (uat_plen_record_t*)r;
if (record->packet_range)
g_free(record->packet_range);
}
static void uat_plen_record_post_update_cb(void) {
guint i, num_default;
uat_plen_record_t rec;
if (num_plen_uat == 0) {
num_default = sizeof(default_range)/sizeof(range_t);
for (i = 0; i < num_default; i++)
{
rec.packet_range = &default_range[i];
uat_add_record(plen_uat, &rec, TRUE);
}
}
}
static void ip_hosts_stats_tree_init(stats_tree* st) {
st_node_ip = stats_tree_create_node(st, st_str_ip, 0, TRUE);
}
static int ip_hosts_stats_tree_packet(stats_tree *st , packet_info *pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
tick_stat_node(st, st_str_ip, 0, FALSE);
tick_stat_node(st, ep_address_to_str(&pinfo->net_src), st_node_ip, FALSE);
tick_stat_node(st, ep_address_to_str(&pinfo->net_dst), st_node_ip, FALSE);
return 1;
}
static void ip_srcdst_stats_tree_init(stats_tree* st) {
st_node_ip_src = stats_tree_create_node(st, st_str_ip_src, 0, TRUE);
stat_node_set_flags(st, st_str_ip_src, 0, FALSE, ST_FLG_SORT_TOP);
st_node_ip_dst = stats_tree_create_node(st, st_str_ip_dst, 0, TRUE);
stat_node_set_flags(st, st_str_ip_dst, 0, FALSE, ST_FLG_DEF_NOEXPAND);
}
static int ip_srcdst_stats_tree_packet(stats_tree *st , packet_info *pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
tick_stat_node(st, st_str_ip_src, 0, FALSE);
tick_stat_node(st, ep_address_to_str(&pinfo->net_src), st_node_ip_src, FALSE);
tick_stat_node(st, st_str_ip_dst, 0, FALSE);
tick_stat_node(st, ep_address_to_str(&pinfo->net_dst), st_node_ip_dst, FALSE);
return 1;
}
static void ptype_stats_tree_init(stats_tree* st) {
st_node_ptype = stats_tree_create_pivot(st, st_str_ptype, 0);
}
static int ptype_stats_tree_packet(stats_tree* st, packet_info* pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
const gchar* ptype;
ptype = port_type_to_str(pinfo->ptype);
stats_tree_tick_pivot(st,st_node_ptype,ptype);
return 1;
}
static void plen_stats_tree_init(stats_tree* st) {
guint i;
char **str_range_array = (char **)ep_alloc(num_plen_uat*sizeof(char*));
for (i = 0; i < num_plen_uat; i++) {
str_range_array[i] = range_convert_range(uat_plen_records[i].packet_range);
}
st_node_plen = stats_tree_create_range_node_string(st, st_str_plen, 0, num_plen_uat, str_range_array);
}
static int plen_stats_tree_packet(stats_tree* st, packet_info* pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
tick_stat_node(st, st_str_plen, 0, FALSE);
avg_stat_node_add_value_notick(st, st_str_plen, 0, FALSE, pinfo->fd->pkt_len);
stats_tree_tick_range(st, st_str_plen, 0, pinfo->fd->pkt_len);
return 1;
}
static void dsts_stats_tree_init(stats_tree* st) {
st_node_dsts = stats_tree_create_node(st, st_str_dsts, 0, TRUE);
}
static int dsts_stats_tree_packet(stats_tree* st, packet_info* pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
static gchar str[128];
int ip_dst_node;
int protocol_node;
tick_stat_node(st, st_str_dsts, 0, FALSE);
ip_dst_node = tick_stat_node(st, ep_address_to_str(&pinfo->net_src), st_node_dsts, TRUE);
protocol_node = tick_stat_node(st,port_type_to_str(pinfo->ptype),ip_dst_node,TRUE);
g_snprintf(str, sizeof(str),"%u",pinfo->destport);
tick_stat_node(st,str,protocol_node,TRUE);
return 1;
}
void register_pinfo_stat_trees(void) {
module_t *stat_module;
static uat_field_t plen_uat_flds[] = {
UAT_FLD_RANGE(uat_plen_records, packet_range, "Packet Range", 0xFFFFFFFF, "Range of packet sizes to count"),
UAT_END_FIELDS
};
stats_tree_register_plugin("ip","ip_hosts",st_str_ip, 0, ip_hosts_stats_tree_packet, ip_hosts_stats_tree_init, NULL );
stats_tree_register_plugin("ip","ip_srcdst",st_str_ip_srcdst, 0, ip_srcdst_stats_tree_packet, ip_srcdst_stats_tree_init, NULL );
stats_tree_register_plugin("ip","ptype",st_str_ptype, 0, ptype_stats_tree_packet, ptype_stats_tree_init, NULL );
stats_tree_register_with_group("frame","plen",st_str_plen, 0, plen_stats_tree_packet, plen_stats_tree_init, NULL, REGISTER_STAT_GROUP_GENERIC );
stats_tree_register_plugin("ip","dests",st_str_dsts, 0, dsts_stats_tree_packet, dsts_stats_tree_init, NULL );
stat_module = prefs_register_stat("stat_tree", "Stats Tree", "Stats Tree", NULL);
plen_uat = uat_new("Packet Lengths",
sizeof(uat_plen_record_t),
"packet_lengths",
TRUE,
&uat_plen_records,
&num_plen_uat,
0,
NULL,
uat_plen_record_copy_cb,
uat_plen_record_update_cb,
uat_plen_record_free_cb,
uat_plen_record_post_update_cb,
plen_uat_flds);
prefs_register_uat_preference(stat_module, "packet_lengths",
"Packet Lengths", "Delineated packet sizes to count", plen_uat);
}
