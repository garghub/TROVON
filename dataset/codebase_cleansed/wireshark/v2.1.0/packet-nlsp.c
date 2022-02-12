static void
nlsp_dissect_clvs(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
const nlsp_clv_handle_t *opts, int len, int unknown_tree_id _U_)
{
guint8 code;
guint8 length;
int q;
proto_tree *clv_tree;
while ( len > 0 ) {
code = tvb_get_guint8(tvb, offset);
offset += 1;
len -= 1;
if (len == 0)
break;
length = tvb_get_guint8(tvb, offset);
offset += 1;
len -= 1;
if (len == 0)
break;
if ( len < length ) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short CLV header (%d vs %d)", length, len );
return;
}
q = 0;
while ((opts[q].dissect != NULL )&&( opts[q].optcode != code )){
q++;
}
if ( opts[q].dissect ) {
clv_tree = proto_tree_add_subtree_format(tree, tvb, offset - 2,
length + 2, *opts[q].tree_id, NULL, "%s (%u)",
opts[q].tree_text, length );
opts[q].dissect(tvb, pinfo, clv_tree, offset,
length);
} else {
proto_item* ti;
ti = proto_tree_add_uint_format_value(tree, hf_nlsp_unknown_code, tvb, offset - 2,
1, code, "%u (%u)", code, length);
proto_item_set_len(ti, length + 2);
}
offset += length;
len -= length;
}
}
static void
dissect_area_address_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int length)
{
while (length > 0) {
if (length < 4) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short area address entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_area_address_network_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
if (length < 4) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short area address entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_area_address_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
}
}
static void
dissect_neighbor_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int length)
{
while (length > 0) {
if (length < 6) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet,
tvb, offset, -1, "Short neighbor entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_neighbor, tvb, offset, 6, ENC_NA);
offset += 6;
length -= 6;
}
}
static void
dissect_hello_local_mtu_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int length)
{
if (length < 4) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short link info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_hello_local_mtu_mtu_size, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
nlsp_dissect_nlsp_hello(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, int hello_type, int header_length)
{
guint16 packet_length;
int len;
guint16 holding_timer;
if (hello_type == NLSP_TYPE_WAN_HELLO) {
proto_tree_add_item(tree, hf_nlsp_hello_state, tvb,
offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_nlsp_hello_multicast, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tree, hf_nlsp_hello_circuit_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_nlsp_hello_sending_router_system_id, tvb, offset, 6, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, ", System ID: %s",
tvb_ether_to_str(tvb, offset));
offset += 6;
holding_timer = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_nlsp_hello_holding_timer,
tvb, offset, 2, holding_timer, "%us", holding_timer);
offset += 2;
packet_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_nlsp_packet_length, tvb, offset, 2, packet_length);
offset += 2;
proto_tree_add_item(tree, hf_nlsp_hello_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (hello_type == NLSP_TYPE_WAN_HELLO) {
proto_tree_add_item(tree, hf_nlsp_hello_local_wan_circuit_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
} else {
proto_tree_add_item(tree, hf_nlsp_hello_designated_router_system_id, tvb, offset, 6, ENC_NA);
proto_tree_add_item(tree, hf_nlsp_hello_designated_router_pseudonode_id, tvb, offset+6, 1, ENC_BIG_ENDIAN);
offset += 7;
}
len = packet_length - header_length;
if (len < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_long_packet, tvb, offset, -1,
"packet header length %d went beyond packet",
header_length);
return;
}
nlsp_dissect_clvs(tvb, pinfo, tree, offset,
clv_hello_opts, len, ett_nlsp_hello_clv_unknown);
}
static void
dissect_lsp_mgt_info_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int length)
{
guint8 name_length;
if (length < 4) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short management info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_mgt_info_network_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
if (length < 6) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short management info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_mgt_info_node_number, tvb, offset, 6, ENC_NA);
offset += 6;
length -= 6;
if (length < 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short management info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_mgt_info_ipx_version_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
if (length < 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short management info entry");
return;
}
name_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_nlsp_mgt_info_name_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
if (name_length != 0) {
if (length < name_length) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short management info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_mgt_info_name, tvb, offset, name_length, ENC_NA|ENC_ASCII);
}
}
static void
dissect_lsp_link_info_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int length)
{
guint8 flags_cost;
if (length < 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short link info entry");
return;
}
if (tree) {
flags_cost = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_nlsp_lsp_link_info_clv_flags_cost_present, tvb, offset, 1, ENC_BIG_ENDIAN);
if (!(flags_cost & 0x80)) {
proto_tree_add_item(tree, hf_nlsp_lsp_link_info_clv_flags_cost_metric, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nlsp_lsp_link_info_clv_flags_cost, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
offset += 1;
length -= 1;
if (length < 3) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short link info entry");
return;
}
offset += 3;
length -= 3;
if (length < 7) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short link info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_link_info_router_system_id, tvb, offset, 6, ENC_NA);
proto_tree_add_item(tree, hf_nlsp_link_info_router_pseudonode_id, tvb, offset+6, 1, ENC_BIG_ENDIAN);
offset += 7;
length -= 7;
if (length < 4) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short link info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_link_info_mtu_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
if (length < 4) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short link info entry");
return;
}
proto_tree_add_uint_format_value(tree, hf_nlsp_link_info_delay, tvb, offset, 4,
tvb_get_ntohl(tvb, offset), "%uus", tvb_get_ntohl(tvb, offset));
offset += 4;
length -= 4;
if (length < 4) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short link info entry");
return;
}
proto_tree_add_uint_format_value(tree, hf_nlsp_link_info_throughput, tvb, offset, 4,
tvb_get_ntohl(tvb, offset), "%u bits/s", tvb_get_ntohl(tvb, offset));
offset += 4;
length -= 4;
if (length < 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short link info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_link_info_media_type, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_lsp_svcs_info_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int length)
{
if (length < 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short services info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_svcs_info_hops_to_reach_the_service, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
if (length < 4) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short services info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_svcs_info_network_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
if (length < 6) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short services info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_svcs_info_node_number, tvb, offset, 6, ENC_NA);
offset += 6;
length -= 6;
if (length < 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short services info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_svcs_info_socket, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
if (length < 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short services info entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_svcs_info_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
if (length > 0) {
proto_tree_add_item(tree, hf_nlsp_svcs_info_service_name, tvb, offset, length, ENC_NA|ENC_ASCII);
}
}
static void
dissect_lsp_ext_routes_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int length)
{
while (length > 0) {
if (length < 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short external routes entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_ext_routes_hops, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
if (length < 4) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short external routes entry");
return;
}
proto_tree_add_item(tree, hf_nlsp_ext_routes_network_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
if (length < 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short external routes entry");
return;
}
proto_tree_add_uint_format_value(tree, hf_nlsp_ext_routes_rip_delay, tvb, offset, 2,
tvb_get_ntohs(tvb, offset), "%u ticks", tvb_get_ntohs(tvb, offset));
offset += 2;
length -= 2;
}
}
static void
nlsp_dissect_nlsp_lsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, int header_length)
{
guint16 packet_length;
guint16 remaining_lifetime;
guint32 sequence_number;
int len;
packet_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_nlsp_packet_length, tvb,
offset, 2, packet_length);
offset += 2;
remaining_lifetime = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_nlsp_remaining_lifetime, tvb, offset, 2,
remaining_lifetime, "%us", remaining_lifetime);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, ", LSP ID: %s",
tvb_ether_to_str(tvb, offset));
proto_tree_add_item(tree, hf_nlsp_lsp_id_system_id, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_nlsp_lsp_id_pseudonode_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_nlsp_lsp_id_lsp_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
sequence_number = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO,
", Sequence: 0x%08x, Lifetime: %us",
sequence_number, remaining_lifetime);
proto_tree_add_uint(tree, hf_nlsp_lsp_sequence_number, tvb,
offset, 4, sequence_number);
offset += 4;
proto_tree_add_item(tree, hf_nlsp_lsp_checksum, tvb,
offset, 2, ENC_BIG_ENDIAN );
offset += 2;
if (tree) {
proto_tree_add_item(tree, hf_nlsp_lsp_p, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nlsp_lsp_attached_flag, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nlsp_lsp_lspdbol, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nlsp_lsp_router_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
len = packet_length - header_length;
if (len < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_long_packet, tvb, offset, -1,
"packet header length %d went beyond packet",
header_length);
return;
}
nlsp_dissect_clvs(tvb, pinfo, tree, offset,
clv_l1_lsp_opts, len, ett_nlsp_lsp_clv_unknown);
}
static void
dissect_csnp_lsp_entries(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int length)
{
proto_tree *subtree;
while (length > 0) {
if (length < 16) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short CSNP header entry");
return;
}
subtree = proto_tree_add_subtree_format(tree, tvb, offset, 16,
ett_nlsp_csnp_lsp_entry, NULL, "LSP-ID: %s, Sequence: 0x%08x, Lifetime: %5us, Checksum: 0x%04x",
tvb_ether_to_str(tvb, offset+2),
tvb_get_ntohl(tvb, offset+10),
tvb_get_ntohs(tvb, offset),
tvb_get_ntohs(tvb, offset+14));
proto_tree_add_item(subtree, hf_nlsp_csnp_lsp_id_source_id, tvb, offset+2, 6, ENC_NA);
proto_tree_add_item(subtree, hf_nlsp_csnp_lsp_id_pseudonode_id, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_nlsp_csnp_lsp_id_lsp_number, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_nlsp_csnp_lsp_sequence_number, tvb, offset+10, 4, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(subtree, hf_nlsp_csnp_remaining_lifetime, tvb, offset, 2,
tvb_get_ntohs(tvb, offset), "%us", tvb_get_ntohs(tvb, offset));
proto_tree_add_item(subtree, hf_nlsp_csnp_lsp_checksum, tvb, offset+14, 2, ENC_BIG_ENDIAN);
length -= 16;
offset += 16;
}
}
static void
dissect_psnp_lsp_entries(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int length)
{
proto_tree *subtree;
while (length > 0) {
if (length < 16) {
proto_tree_add_expert_format(tree, pinfo, &ei_nlsp_short_packet, tvb, offset, -1,
"Short PSNP header entry");
return;
}
subtree = proto_tree_add_subtree_format(tree, tvb, offset, 16,
ett_nlsp_psnp_lsp_entry, NULL, "LSP-ID: %s, Sequence: 0x%08x, Lifetime: %5us, Checksum: 0x%04x",
tvb_ether_to_str(tvb, offset+2),
tvb_get_ntohl(tvb, offset+10),
tvb_get_ntohs(tvb, offset),
tvb_get_ntohs(tvb, offset+14));
proto_tree_add_item(subtree, hf_nlsp_psnp_lsp_id_source_id, tvb, offset+2, 6, ENC_NA);
proto_tree_add_item(subtree, hf_nlsp_psnp_lsp_id_pseudonode_id, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_nlsp_psnp_lsp_id_lsp_number, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_nlsp_psnp_lsp_sequence_number, tvb, offset+10, 4, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(subtree, hf_nlsp_psnp_remaining_lifetime, tvb, offset, 2,
tvb_get_ntohs(tvb, offset), "%us", tvb_get_ntohs(tvb, offset));
proto_tree_add_item(subtree, hf_nlsp_psnp_lsp_checksum, tvb, offset+14, 2, ENC_BIG_ENDIAN);
length -= 16;
offset += 16;
}
}
static void
nlsp_dissect_nlsp_csnp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, int header_length)
{
guint16 packet_length;
int len;
packet_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_nlsp_packet_length, tvb, offset, 2, packet_length);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Source ID: %s",
tvb_ether_to_str(tvb, offset));
proto_tree_add_item(tree, hf_nlsp_csnp_source_id_system_id, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_nlsp_csnp_source_id_pseudonode_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Start LSP ID: %s",
tvb_ether_to_str(tvb, offset));
proto_tree_add_item(tree, hf_nlsp_csnp_start_lsp_id_source_id, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_nlsp_csnp_start_lsp_id_pseudonode_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_nlsp_csnp_start_lsp_id_lsp_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, ", End LSP ID: %s",
tvb_ether_to_str(tvb, offset));
proto_tree_add_item(tree, hf_nlsp_csnp_end_lsp_id_source_id, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_nlsp_csnp_end_lsp_id_pseudonode_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_nlsp_csnp_end_lsp_id_lsp_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len = packet_length - header_length;
if (len < 0) {
return;
}
nlsp_dissect_clvs(tvb, pinfo, tree, offset,
clv_l1_csnp_opts, len, ett_nlsp_csnp_clv_unknown);
}
static void
nlsp_dissect_nlsp_psnp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, int header_length)
{
guint16 packet_length;
int len;
packet_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_nlsp_packet_length, tvb,
offset, 2, packet_length);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Source ID: %s",
tvb_ether_to_str(tvb, offset));
proto_tree_add_item(tree, hf_nlsp_psnp_source_id_system_id, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_nlsp_psnp_source_id_pseudonode_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len = packet_length - header_length;
if (len < 0) {
return;
}
nlsp_dissect_clvs(tvb, pinfo, tree, offset,
clv_l1_psnp_opts, len, ett_nlsp_psnp_clv_unknown);
}
static int
dissect_nlsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti, *type_item;
proto_tree *nlsp_tree;
int offset = 0;
guint8 nlsp_major_version;
guint8 nlsp_header_length;
guint8 packet_type_flags;
guint8 packet_type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NLSP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_nlsp, tvb, 0, -1, ENC_NA);
nlsp_tree = proto_item_add_subtree(ti, ett_nlsp);
proto_tree_add_item(nlsp_tree, hf_nlsp_irpd, tvb, offset, 1,
ENC_BIG_ENDIAN );
offset += 1;
nlsp_header_length = tvb_get_guint8(tvb, 1);
proto_tree_add_uint(nlsp_tree, hf_nlsp_header_length, tvb,
offset, 1, nlsp_header_length );
offset += 1;
proto_tree_add_item(nlsp_tree, hf_nlsp_minor_version, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
offset += 1;
packet_type_flags = tvb_get_guint8(tvb, offset);
packet_type = packet_type_flags & PACKET_TYPE_MASK;
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(packet_type, nlsp_packet_type_vals, "Unknown (%u)"));
if (packet_type == NLSP_TYPE_L1_LSP) {
proto_tree_add_boolean(nlsp_tree, hf_nlsp_nr, tvb, offset, 1, packet_type_flags );
}
type_item = proto_tree_add_uint(nlsp_tree, hf_nlsp_type, tvb, offset, 1, packet_type_flags );
offset += 1;
nlsp_major_version = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(nlsp_tree, hf_nlsp_major_version, tvb,
offset, 1, ENC_BIG_ENDIAN );
if (nlsp_major_version != 1){
expert_add_info_format(pinfo, ti, &ei_nlsp_major_version,
"Unknown NLSP version (%d vs 1)",
nlsp_major_version);
}
offset += 1;
offset += 2;
switch (packet_type) {
case NLSP_TYPE_L1_HELLO:
case NLSP_TYPE_WAN_HELLO:
nlsp_dissect_nlsp_hello(tvb, pinfo, nlsp_tree, offset,
packet_type, nlsp_header_length);
break;
case NLSP_TYPE_L1_LSP:
nlsp_dissect_nlsp_lsp(tvb, pinfo, nlsp_tree, offset,
nlsp_header_length);
break;
case NLSP_TYPE_L1_CSNP:
nlsp_dissect_nlsp_csnp(tvb, pinfo, nlsp_tree, offset,
nlsp_header_length);
break;
case NLSP_TYPE_L1_PSNP:
nlsp_dissect_nlsp_psnp(tvb, pinfo, nlsp_tree, offset,
nlsp_header_length);
break;
default:
expert_add_info(pinfo, type_item, &ei_nlsp_type);
}
return tvb_captured_length(tvb);
}
void
proto_register_nlsp(void)
{
static hf_register_info hf[] = {
{ &hf_nlsp_irpd,
{ "NetWare Link Services Protocol Discriminator", "nlsp.irpd",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_header_length,
{ "PDU Header Length", "nlsp.header_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_minor_version,
{ "Minor Version", "nlsp.minor_version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_nr,
{ "Multi-homed Non-routing Server", "nlsp.nr",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_nlsp_type,
{ "Packet Type", "nlsp.type",
FT_UINT8, BASE_DEC, VALS(nlsp_packet_type_vals), PACKET_TYPE_MASK,
NULL, HFILL }
},
{ &hf_nlsp_major_version,
{ "Major Version", "nlsp.major_version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_packet_length,
{ "Packet Length", "nlsp.packet_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_hello_state,
{ "State", "nlsp.hello.state",
FT_UINT8, BASE_DEC, VALS(nlsp_hello_state_vals), NLSP_HELLO_STATE_MASK,
NULL, HFILL }
},
{ &hf_nlsp_hello_multicast,
{ "Multicast Routing", "nlsp.hello.multicast",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), NLSP_HELLO_MULTICAST_MASK,
"If set, this router supports multicast routing", HFILL }
},
{ &hf_nlsp_hello_circuit_type,
{ "Circuit Type", "nlsp.hello.circuit_type",
FT_UINT8, BASE_DEC, VALS(nlsp_hello_circuit_type_vals), NLSP_HELLO_CTYPE_MASK,
NULL, HFILL }
},
{ &hf_nlsp_hello_holding_timer,
{ "Holding Timer", "nlsp.hello.holding_timer",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_hello_priority,
{ "Priority", "nlsp.hello.priority",
FT_UINT8, BASE_DEC, NULL, NLSP_HELLO_PRIORITY_MASK,
NULL, HFILL }
},
{ &hf_nlsp_lsp_sequence_number,
{ "Sequence Number", "nlsp.sequence_number",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_lsp_checksum,
{ "Checksum", "nlsp.lsp.checksum",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_lsp_p,
{ "Partition Repair", "nlsp.lsp.partition_repair",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), NLSP_LSP_PARTITION_MASK,
"If set, this router supports the optional Partition Repair function", HFILL }
},
{ &hf_nlsp_lsp_attached_flag,
{ "Attached Flag", "nlsp.lsp.attached_flag",
FT_UINT8, BASE_DEC, VALS(nlsp_attached_flag_vals), NLSP_LSP_ATT_MASK,
NULL, HFILL }
},
{ &hf_nlsp_lsp_lspdbol,
{ "LSP Database Overloaded", "nlsp.lsp.lspdbol",
FT_BOOLEAN, 8, NULL, NLSP_LSP_OVERFLOW_MASK,
NULL, HFILL }
},
{ &hf_nlsp_lsp_router_type,
{ "Router Type", "nlsp.lsp.router_type",
FT_UINT8, BASE_DEC, VALS(nlsp_router_type_vals), NLSP_LSP_ROUTER_TYPE_MASK,
NULL, HFILL }
},
{ &hf_nlsp_lsp_link_info_clv_flags_cost_present,
{ "Cost present", "nlsp.lsp.link_info_clv.flags.cost_present",
FT_BOOLEAN, 8, TFS(&tfs_no_yes), 0x80,
NULL, HFILL }
},
{ &hf_nlsp_lsp_link_info_clv_flags_cost_metric,
{ "Cost metric", "nlsp.lsp.link_info_clv.flags.cost_metric",
FT_BOOLEAN, 8, TFS(&tfs_internal_external), 0x40,
NULL, HFILL }
},
{ &hf_nlsp_lsp_link_info_clv_flags_cost,
{ "Cost", "nlsp.lsp.link_info_clv.flags.cost",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_nlsp_unknown_code,
{ "Unknown code", "nlsp.unknown_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_area_address_network_number,
{ "Area address network number", "nlsp.area_address.network_number",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_area_address_mask,
{ "Area address mask", "nlsp.area_address.mask",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_neighbor,
{ "Neighbor", "nlsp.neighbor",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_hello_local_mtu_mtu_size,
{ "MTU Size", "nlsp.hello_local_mtu.mtu_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_hello_sending_router_system_id,
{ "Sending Router System ID", "nlsp.hello.sending_router_system_id",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_hello_local_wan_circuit_id,
{ "Local WAN Circuit ID", "nlsp.hello.local_wan_circuit_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_hello_designated_router_system_id,
{ "Designated Router System ID", "nlsp.hello.designated_router_system_id",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_hello_designated_router_pseudonode_id,
{ "Designated Router Pseudonode ID", "nlsp.hello.designated_router_pseudonode_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_mgt_info_network_number,
{ "Network number", "nlsp.mgt_info.network_number",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_mgt_info_node_number,
{ "Node number", "nlsp.mgt_info.node_number",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_mgt_info_ipx_version_number,
{ "IPX version number", "nlsp.mgt_info.ipx_version_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_mgt_info_name_length,
{ "Name length", "nlsp.mgt_info.name_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_mgt_info_name,
{ "Name", "nlsp.mgt_info.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_link_info_router_system_id,
{ "Router System ID", "nlsp.link_info.router_system_id",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_link_info_router_pseudonode_id,
{ "Router Pseudonode ID", "nlsp.link_info.router_pseudonode_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_link_info_mtu_size,
{ "MTU Size", "nlsp.link_info.mtu_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_link_info_delay,
{ "Delay", "nlsp.link_info.delay",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_link_info_throughput,
{ "Throughput", "nlsp.link_info.throughput",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_link_info_media_type,
{ "Media type", "nlsp.link_info.media_type",
FT_UINT16, BASE_DEC, VALS(media_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_nlsp_svcs_info_hops_to_reach_the_service,
{ "Hops to reach the service", "nlsp.svcs_info.hops_to_reach_the_service",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_svcs_info_network_number,
{ "Network number", "nlsp.svcs_info.network_number",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_svcs_info_node_number,
{ "Node number", "nlsp.svcs_info.node_number",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_svcs_info_socket,
{ "Socket", "nlsp.svcs_info.socket",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &ipx_socket_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_svcs_info_type,
{ "Type", "nlsp.svcs_info.type",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &novell_server_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_svcs_info_service_name,
{ "Service Name", "nlsp.svcs_info.service_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_ext_routes_hops,
{ "Hops", "nlsp.ext_routes.hops",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_ext_routes_network_number,
{ "Network number", "nlsp.ext_routes.network_number",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_ext_routes_rip_delay,
{ "RIP delay", "nlsp.ext_routes.rip_delay",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_remaining_lifetime,
{ "Remaining Lifetime", "nlsp.remaining_lifetime",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_lsp_id_system_id,
{ "LSP ID system ID", "nlsp.lsp_id_system_id",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_lsp_id_pseudonode_id,
{ "LSP ID pseudonode ID", "nlsp.lsp_id_pseudonode_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_lsp_id_lsp_number,
{ "LSP ID LSP number", "nlsp.lsp_id_lsp_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_lsp_id_source_id,
{ "LSP ID source ID", "nlsp.csnp.lsp_id_source_id",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_lsp_id_pseudonode_id,
{ "LSP ID pseudonode ID", "nlsp.csnp.lsp_id_pseudonode_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_lsp_id_lsp_number,
{ "LSP ID LSP number", "nlsp.csnp.lsp_id_lsp_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_lsp_sequence_number,
{ "LSP Sequence Number", "nlsp.csnp.lsp_sequence_number",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_remaining_lifetime,
{ "Remaining Lifetime", "nlsp.csnp.remaining_lifetime",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_lsp_checksum,
{ "LSP checksum", "nlsp.csnp.lsp_checksum",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_psnp_lsp_id_source_id,
{ "LSP ID source ID", "nlsp.psnp.lsp_id_source_id",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_psnp_lsp_id_pseudonode_id,
{ "LSP ID pseudonode ID", "nlsp.psnp.lsp_id_pseudonode_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_psnp_lsp_id_lsp_number,
{ "LSP ID LSP number", "nlsp.psnp.lsp_id_lsp_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_psnp_lsp_sequence_number,
{ "LSP Sequence Number", "nlsp.psnp.lsp_sequence_number",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_psnp_remaining_lifetime,
{ "Remaining Lifetime", "nlsp.psnp.remaining_lifetime",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_psnp_lsp_checksum,
{ "LSP checksum", "nlsp.psnp.lsp_checksum",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_source_id_system_id,
{ "Source ID system ID", "nlsp.csnp.source_id_system_id",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_source_id_pseudonode_id,
{ "Source ID pseudonode ID", "nlsp.csnp.source_id_pseudonode_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_start_lsp_id_source_id,
{ "Start LSP ID source ID", "nlsp.csnp.start_lsp_id_source_id",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_start_lsp_id_pseudonode_id,
{ "Start LSP ID pseudonode ID", "nlsp.csnp.start_lsp_id_pseudonode_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_start_lsp_id_lsp_number,
{ "Start LSP ID LSP number", "nlsp.csnp.start_lsp_id_lsp_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_end_lsp_id_source_id,
{ "End LSP ID source ID", "nlsp.csnp.end_lsp_id_source_id",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_end_lsp_id_pseudonode_id,
{ "End LSP ID pseudonode ID", "nlsp.csnp.end_lsp_id_pseudonode_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_csnp_end_lsp_id_lsp_number,
{ "End LSP ID LSP number", "nlsp.csnp.end_lsp_id_lsp_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_psnp_source_id_system_id,
{ "Source ID system ID", "nlsp.psnp.source_id_system_id",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nlsp_psnp_source_id_pseudonode_id,
{ "Source ID pseudonode ID", "nlsp.psnp.source_id_pseudonode_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_nlsp,
&ett_nlsp_hello_clv_area_addr,
&ett_nlsp_hello_clv_neighbors,
&ett_nlsp_hello_local_mtu,
&ett_nlsp_hello_clv_unknown,
&ett_nlsp_lsp_info,
&ett_nlsp_lsp_clv_area_addr,
&ett_nlsp_lsp_clv_mgt_info,
&ett_nlsp_lsp_clv_link_info,
&ett_nlsp_lsp_clv_svcs_info,
&ett_nlsp_lsp_clv_ext_routes,
&ett_nlsp_lsp_clv_unknown,
&ett_nlsp_csnp_lsp_entries,
&ett_nlsp_csnp_lsp_entry,
&ett_nlsp_csnp_clv_unknown,
&ett_nlsp_psnp_lsp_entries,
&ett_nlsp_psnp_lsp_entry,
&ett_nlsp_psnp_clv_unknown,
};
static ei_register_info ei[] = {
{ &ei_nlsp_short_packet, { "nlsp.short_packet", PI_MALFORMED, PI_ERROR, "Short packet", EXPFILL }},
{ &ei_nlsp_long_packet, { "nlsp.long_packet", PI_MALFORMED, PI_ERROR, "Long packet", EXPFILL }},
{ &ei_nlsp_major_version, { "nlsp.major_version.unknown", PI_PROTOCOL, PI_WARN, "Unknown NLSP version", EXPFILL }},
{ &ei_nlsp_type, { "nlsp.type.unknown", PI_PROTOCOL, PI_WARN, "Unknown NLSP packet type", EXPFILL }},
};
expert_module_t* expert_nlsp;
proto_nlsp = proto_register_protocol("NetWare Link Services Protocol",
"NLSP", "nlsp");
proto_register_field_array(proto_nlsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_nlsp = expert_register_protocol(proto_nlsp);
expert_register_field_array(expert_nlsp, ei, array_length(ei));
}
void
proto_reg_handoff_nlsp(void)
{
dissector_handle_t nlsp_handle;
nlsp_handle = create_dissector_handle(dissect_nlsp, proto_nlsp);
dissector_add_uint("ipx.socket", IPX_SOCKET_NLSP, nlsp_handle);
}
