static void *uat_plen_record_copy_cb(void *n, const void *o, size_t siz _U_) {
const uat_plen_record_t *r = (const uat_plen_record_t *)o;
uat_plen_record_t *rn = (uat_plen_record_t *)n;
if (r->packet_range)
rn->packet_range = range_copy(r->packet_range);
return n;
}
static gboolean
uat_plen_record_update_cb(void *r, char **err)
{
uat_plen_record_t *rec = (uat_plen_record_t*)r;
if (rec->packet_range->nranges < 1) {
*err = g_strdup("Invalid range string");
return FALSE;
}
*err = NULL;
return TRUE;
}
static void uat_plen_record_free_cb(void*r) {
uat_plen_record_t *record = (uat_plen_record_t*)r;
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
static void ipv4_hosts_stats_tree_init(stats_tree *st) {
st_node_ipv4 = stats_tree_create_node(st, st_str_ipv4, 0, TRUE);
}
static void ipv6_hosts_stats_tree_init(stats_tree *st) {
st_node_ipv6 = stats_tree_create_node(st, st_str_ipv6, 0, TRUE);
}
static int ip_hosts_stats_tree_packet(stats_tree *st, packet_info *pinfo, int st_node, const gchar *st_str) {
tick_stat_node(st, st_str, 0, FALSE);
tick_stat_node(st, address_to_str(pinfo->pool, &pinfo->net_src), st_node, FALSE);
tick_stat_node(st, address_to_str(pinfo->pool, &pinfo->net_dst), st_node, FALSE);
return 1;
}
static int ipv4_hosts_stats_tree_packet(stats_tree *st, packet_info *pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
return ip_hosts_stats_tree_packet(st, pinfo, st_node_ipv4, st_str_ipv4);
}
static int ipv6_hosts_stats_tree_packet(stats_tree *st, packet_info *pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
return ip_hosts_stats_tree_packet(st, pinfo, st_node_ipv6, st_str_ipv6);
}
static void ip_srcdst_stats_tree_init(stats_tree *st,
const gchar *st_str_src, int *st_node_src_ptr,
const gchar *st_str_dst, int *st_node_dst_ptr) {
*st_node_src_ptr = stats_tree_create_node(st, st_str_src, 0, TRUE);
stat_node_set_flags(st, st_str_src, 0, FALSE, ST_FLG_SORT_TOP);
*st_node_dst_ptr = stats_tree_create_node(st, st_str_dst, 0, TRUE);
stat_node_set_flags(st, st_str_dst, 0, FALSE, ST_FLG_DEF_NOEXPAND);
}
static void ipv4_srcdst_stats_tree_init(stats_tree *st) {
ip_srcdst_stats_tree_init(st, st_str_ipv4_src, &st_node_ipv4_src, st_str_ipv4_dst, &st_node_ipv4_dst);
}
static void ipv6_srcdst_stats_tree_init(stats_tree *st) {
ip_srcdst_stats_tree_init(st, st_str_ipv6_src, &st_node_ipv6_src, st_str_ipv6_dst, &st_node_ipv6_dst);
}
static int ip_srcdst_stats_tree_packet(stats_tree *st, packet_info *pinfo,
int st_node_src, const gchar *st_str_src,
int st_node_dst, const gchar *st_str_dst) {
tick_stat_node(st, st_str_src, 0, FALSE);
tick_stat_node(st, address_to_str(pinfo->pool, &pinfo->net_src), st_node_src, FALSE);
tick_stat_node(st, st_str_dst, 0, FALSE);
tick_stat_node(st, address_to_str(pinfo->pool, &pinfo->net_dst), st_node_dst, FALSE);
return 1;
}
static int ipv4_srcdst_stats_tree_packet(stats_tree *st, packet_info *pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
return ip_srcdst_stats_tree_packet(st, pinfo, st_node_ipv4_src, st_str_ipv4_src, st_node_ipv4_dst, st_str_ipv4_dst);
}
static int ipv6_srcdst_stats_tree_packet(stats_tree *st, packet_info *pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
return ip_srcdst_stats_tree_packet(st, pinfo, st_node_ipv6_src, st_str_ipv6_src, st_node_ipv6_dst, st_str_ipv6_dst);
}
static void ipv4_ptype_stats_tree_init(stats_tree *st) {
st_node_ipv4_ptype = stats_tree_create_pivot(st, st_str_ipv4_ptype, 0);
}
static void ipv6_ptype_stats_tree_init(stats_tree *st) {
st_node_ipv6_ptype = stats_tree_create_pivot(st, st_str_ipv6_ptype, 0);
}
static int ipv4_ptype_stats_tree_packet(stats_tree *st, packet_info *pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
stats_tree_tick_pivot(st, st_node_ipv4_ptype, port_type_to_str(pinfo->ptype));
return 1;
}
static int ipv6_ptype_stats_tree_packet(stats_tree *st, packet_info *pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
stats_tree_tick_pivot(st, st_node_ipv6_ptype, port_type_to_str(pinfo->ptype));
return 1;
}
static void ipv4_dsts_stats_tree_init(stats_tree *st) {
st_node_ipv4_dsts = stats_tree_create_node(st, st_str_ipv4_dsts, 0, TRUE);
}
static void ipv6_dsts_stats_tree_init(stats_tree *st) {
st_node_ipv6_dsts = stats_tree_create_node(st, st_str_ipv6_dsts, 0, TRUE);
}
static int dsts_stats_tree_packet(stats_tree *st, packet_info *pinfo, int st_node, const gchar *st_str) {
static gchar str[128];
int ip_dst_node;
int protocol_node;
tick_stat_node(st, st_str, 0, FALSE);
ip_dst_node = tick_stat_node(st, address_to_str(pinfo->pool, &pinfo->net_dst), st_node, TRUE);
protocol_node = tick_stat_node(st, port_type_to_str(pinfo->ptype), ip_dst_node, TRUE);
g_snprintf(str, sizeof(str) - 1, "%u", pinfo->destport);
tick_stat_node(st, str, protocol_node, TRUE);
return 1;
}
static int ipv4_dsts_stats_tree_packet(stats_tree *st, packet_info *pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
return dsts_stats_tree_packet(st, pinfo, st_node_ipv4_dsts, st_str_ipv4_dsts);
}
static int ipv6_dsts_stats_tree_packet(stats_tree *st, packet_info *pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
return dsts_stats_tree_packet(st, pinfo, st_node_ipv6_dsts, st_str_ipv6_dsts);
}
static void plen_stats_tree_init(stats_tree *st) {
guint i;
char **str_range_array = (char **)wmem_alloc(NULL, num_plen_uat*sizeof(char*));
for (i = 0; i < num_plen_uat - 1; i++) {
str_range_array[i] = range_convert_range(NULL, uat_plen_records[i].packet_range);
}
str_range_array[num_plen_uat - 1] = g_strdup_printf("%u and greater",
uat_plen_records[num_plen_uat - 1].packet_range->ranges[0].low);
st_node_plen = stats_tree_create_range_node_string(st, st_str_plen, 0, num_plen_uat, str_range_array);
for (i = 0; i < num_plen_uat; i++) {
wmem_free(NULL, str_range_array[i]);
}
}
static int plen_stats_tree_packet(stats_tree *st, packet_info *pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
tick_stat_node(st, st_str_plen, 0, FALSE);
stats_tree_tick_range(st, st_str_plen, 0, pinfo->fd->pkt_len);
return 1;
}
void register_pinfo_stat_trees(void) {
module_t *stat_module;
static uat_field_t plen_uat_flds[] = {
UAT_FLD_RANGE(uat_plen_records, packet_range, "Packet Range", 0xFFFFFFFF, "Range of packet sizes to count"),
UAT_END_FIELDS
};
stats_tree_register_plugin("ip", "ip_hosts", st_str_ipv4, 0, ipv4_hosts_stats_tree_packet, ipv4_hosts_stats_tree_init, NULL );
stats_tree_register_plugin("ip", "ip_srcdst", st_str_ipv4_srcdst, 0, ipv4_srcdst_stats_tree_packet, ipv4_srcdst_stats_tree_init, NULL );
stats_tree_register_plugin("ip", "ptype", st_str_ipv4_ptype, 0, ipv4_ptype_stats_tree_packet, ipv4_ptype_stats_tree_init, NULL );
stats_tree_register_plugin("ip", "dests", st_str_ipv4_dsts, 0, ipv4_dsts_stats_tree_packet, ipv4_dsts_stats_tree_init, NULL );
stats_tree_register_plugin("ipv6", "ipv6_hosts", st_str_ipv6, 0, ipv6_hosts_stats_tree_packet, ipv6_hosts_stats_tree_init, NULL );
stats_tree_register_plugin("ipv6", "ipv6_srcdst", st_str_ipv6_srcdst, 0, ipv6_srcdst_stats_tree_packet, ipv6_srcdst_stats_tree_init, NULL );
stats_tree_register_plugin("ipv6", "ipv6_ptype", st_str_ipv6_ptype, 0, ipv6_ptype_stats_tree_packet, ipv6_ptype_stats_tree_init, NULL );
stats_tree_register_plugin("ipv6", "ipv6_dests", st_str_ipv6_dsts, 0, ipv6_dsts_stats_tree_packet, ipv6_dsts_stats_tree_init, NULL );
stats_tree_register_with_group("frame", "plen", st_str_plen, 0, plen_stats_tree_packet, plen_stats_tree_init, NULL, REGISTER_STAT_GROUP_GENERIC);
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
