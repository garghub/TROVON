static const gchar* port_type_to_str (port_type type) {
switch (type) {
case PT_NONE: return "NONE";
case PT_SCTP: return "SCTP";
case PT_TCP: return "TCP";
case PT_UDP: return "UDP";
case PT_IPX: return "IPX";
case PT_NCP: return "NCP";
case PT_EXCHG: return "FC EXCHG";
case PT_DDP: return "DDP";
case PT_SBCCS: return "FICON SBCCS";
case PT_IDP: return "IDP";
default: return "[Unknown]";
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
st_node_plen = stats_tree_create_range_node(st, st_str_plen, 0, "0-19","20-39","40-79","80-159","160-319","320-639","640-1279","1280-2559","2560-5119","5120-",NULL);
}
static int plen_stats_tree_packet(stats_tree* st, packet_info* pinfo, epan_dissect_t *edt _U_, const void *p _U_) {
tick_stat_node(st, st_str_plen, 0, FALSE);
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
stats_tree_register("ip","ip_hosts",st_str_ip, 0, ip_hosts_stats_tree_packet, ip_hosts_stats_tree_init, NULL );
stats_tree_register("ip","ptype",st_str_ptype, 0, ptype_stats_tree_packet, ptype_stats_tree_init, NULL );
stats_tree_register_with_group("frame","plen",st_str_plen, 0, plen_stats_tree_packet, plen_stats_tree_init, NULL, REGISTER_STAT_GROUP_GENERIC );
stats_tree_register("ip","dests",st_str_dsts, 0, dsts_stats_tree_packet, dsts_stats_tree_init, NULL );
}
