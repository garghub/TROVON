static gint
dissect_sflow_245_sampled_header(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, volatile gint offset) {
guint32 version, header_proto, frame_length;
guint32 header_length;
tvbuff_t *next_tvb;
proto_tree *sflow_245_header_tree;
proto_item *ti;
gboolean save_writable;
gboolean save_in_error_pkt;
address save_dl_src, save_dl_dst, save_net_src, save_net_dst, save_src, save_dst;
version = tvb_get_ntohl(tvb, 0);
header_proto = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_245_header_protocol, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
frame_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_245_header_frame_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (version == 5) {
proto_tree_add_item(tree, hf_sflow_245_header_payload_removed, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item_ret_uint(tree, hf_sflow_245_original_packet_header_length, tvb, offset, 4, ENC_BIG_ENDIAN, &header_length);
offset += 4;
if (header_length % 4)
header_length += (4 - (header_length % 4));
ti = proto_tree_add_item(tree, hf_sflow_245_header, tvb, offset, header_length, ENC_NA);
sflow_245_header_tree = proto_item_add_subtree(ti, ett_sflow_245_sampled_header);
next_tvb = tvb_new_subset(tvb, offset, header_length, frame_length);
save_writable = col_get_writable(pinfo->cinfo);
save_in_error_pkt = pinfo->flags.in_error_pkt;
if (!global_analyze_samp_ip_headers) {
pinfo->flags.in_error_pkt = TRUE;
}
col_set_writable(pinfo->cinfo, FALSE);
copy_address_shallow(&save_dl_src, &pinfo->dl_src);
copy_address_shallow(&save_dl_dst, &pinfo->dl_dst);
copy_address_shallow(&save_net_src, &pinfo->net_src);
copy_address_shallow(&save_net_dst, &pinfo->net_dst);
copy_address_shallow(&save_src, &pinfo->src);
copy_address_shallow(&save_dst, &pinfo->dst);
TRY
{
if ((global_dissect_samp_headers == FALSE) ||
!dissector_try_uint(header_subdissector_table, header_proto, next_tvb, pinfo, sflow_245_header_tree))
{
call_data_dissector(next_tvb, pinfo, sflow_245_header_tree);
}
}
CATCH_BOUNDS_ERRORS {
}
ENDTRY;
col_set_writable(pinfo->cinfo, save_writable);
pinfo->flags.in_error_pkt = save_in_error_pkt;
copy_address_shallow(&pinfo->dl_src, &save_dl_src);
copy_address_shallow(&pinfo->dl_dst, &save_dl_dst);
copy_address_shallow(&pinfo->net_src, &save_net_src);
copy_address_shallow(&pinfo->net_dst, &save_net_dst);
copy_address_shallow(&pinfo->src, &save_src);
copy_address_shallow(&pinfo->dst, &save_dst);
offset += header_length;
return offset;
}
static gint
dissect_sflow_245_address_type(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, gint offset,
struct sflow_address_type *hf_type,
address *addr) {
guint32 addr_type;
int len;
addr_type = tvb_get_ntohl(tvb, offset);
offset += 4;
switch (addr_type) {
case ADDR_TYPE_UNKNOWN:
len = 0;
break;
case ADDR_TYPE_IPV4:
len = 4;
proto_tree_add_item(tree, hf_type->hf_addr_v4, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case ADDR_TYPE_IPV6:
len = 16;
proto_tree_add_item(tree, hf_type->hf_addr_v6, tvb, offset, 16, ENC_NA);
break;
default:
len = 0;
proto_tree_add_expert_format(tree, pinfo, &ei_sflow_invalid_address_type, tvb,
offset - 4, 4, "Unknown address type (%u)", addr_type);
}
if (addr) {
switch (len) {
case 4:
set_address_tvb(addr, AT_IPv4, len, tvb, offset);
break;
case 16:
set_address_tvb(addr, AT_IPv6, len, tvb, offset);
break;
}
}
return offset + len;
}
static gint
dissect_sflow_245_extended_switch(tvbuff_t *tvb, proto_tree *tree, gint offset) {
proto_tree_add_item(tree, hf_sflow_245_vlan_in, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_pri_in, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_vlan_out, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_pri_out, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_245_extended_router(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset) {
struct sflow_address_type addr_type;
addr_type.hf_addr_v4 = hf_sflow_245_nexthop_v4;
addr_type.hf_addr_v6 = hf_sflow_245_nexthop_v6;
offset = dissect_sflow_245_address_type(tvb, pinfo, tree, offset, &addr_type, NULL);
proto_tree_add_item(tree, hf_sflow_245_nexthop_src_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_nexthop_dst_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_mpls_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset) {
guint32 in_label_count, out_label_count, label, i, j;
proto_tree *in_stack;
proto_tree *out_stack;
struct sflow_address_type addr_type;
addr_type.hf_addr_v4 = hf_sflow_245_nexthop_v4;
addr_type.hf_addr_v6 = hf_sflow_245_nexthop_v6;
offset = dissect_sflow_245_address_type(tvb, pinfo, tree, offset, &addr_type, NULL);
in_label_count = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_245_extended_mpls_in_label_stack_entries, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
in_stack = proto_tree_add_subtree(tree, tvb, offset, -1, ett_sflow_5_mpls_in_label_stack, NULL, "In Label Stack");
for (i = 0, j = 0; i < (in_label_count & 0x000000ff); i++, j += 4) {
label = tvb_get_ntohl(tvb, offset + j);
proto_tree_add_uint_format(in_stack, hf_sflow_245_extended_mpls_in_label, tvb, offset, 4,
label, "Label %u: %u", i + 1, label);
}
offset += (in_label_count * 4);
out_label_count = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_245_extended_mpls_out_label_stack_entries, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
out_stack = proto_tree_add_subtree(tree, tvb, offset, -1, ett_sflow_5_mpls_in_label_stack, NULL, "Out Label Stack");
for (i = 0, j = 0; i < (out_label_count & 0x000000ff); i++, j += 4) {
label = tvb_get_ntohl(tvb, offset + j);
proto_tree_add_uint_format(out_stack, hf_sflow_245_extended_mpls_out_label, tvb, offset, 4,
label, "Label %u: %u", i + 1, label);
}
offset = offset + out_label_count * 4;
return offset;
}
static gint
dissect_sflow_5_extended_nat(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset) {
struct sflow_address_type addr_type;
addr_type.hf_addr_v4 = hf_sflow_245_ipv4_src;
addr_type.hf_addr_v6 = hf_sflow_245_ipv6_src;
offset = dissect_sflow_245_address_type(tvb, pinfo, tree, offset, &addr_type, NULL);
addr_type.hf_addr_v4 = hf_sflow_245_ipv4_dst;
addr_type.hf_addr_v6 = hf_sflow_245_ipv6_dst;
offset = dissect_sflow_245_address_type(tvb, pinfo, tree, offset, &addr_type, NULL);
return offset;
}
static gint
dissect_sflow_245_extended_gateway(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset) {
gint32 len = 0;
gint32 i, j, comm_len, dst_len, dst_seg_len;
guint32 path_type;
gint32 kludge;
guint32 version = tvb_get_ntohl(tvb, 0);
proto_item *ti;
proto_tree *sflow_245_dst_as_tree;
proto_tree *sflow_245_comm_tree;
proto_tree *sflow_245_dst_as_seg_tree;
if (version == 5) {
struct sflow_address_type addr_type;
addr_type.hf_addr_v4 = hf_sflow_245_nexthop_v4;
addr_type.hf_addr_v6 = hf_sflow_245_nexthop_v6;
offset = dissect_sflow_245_address_type(tvb, pinfo, tree, offset, &addr_type, NULL);
}
proto_tree_add_item(tree, hf_sflow_245_as, tvb, offset + len, 4, ENC_BIG_ENDIAN);
len += 4;
proto_tree_add_item(tree, hf_sflow_245_src_as, tvb, offset + len, 4, ENC_BIG_ENDIAN);
len += 4;
proto_tree_add_item(tree, hf_sflow_245_src_peer_as, tvb, offset + len, 4, ENC_BIG_ENDIAN);
len += 4;
dst_len = tvb_get_ntohl(tvb, offset + len);
ti = proto_tree_add_uint(tree, hf_sflow_245_dst_as_entries, tvb, offset + len, 4, dst_len);
sflow_245_dst_as_tree = proto_item_add_subtree(ti, ett_sflow_245_gw_as_dst);
len += 4;
for (i = 0; i < dst_len; i++) {
if (version < 4) {
dst_seg_len = 1;
sflow_245_dst_as_seg_tree = sflow_245_dst_as_tree;
} else {
path_type = tvb_get_ntohl(tvb, offset + len);
len += 4;
dst_seg_len = tvb_get_ntohl(tvb, offset + len);
len += 4;
kludge = 8;
ti = proto_tree_add_uint_format(tree, hf_sflow_245_as_type, tvb, offset + len - kludge, kludge, path_type,
"%s, (%u entries)", val_to_str_const(path_type, sflow_245_as_types, "Unknown AS type"), dst_seg_len);
sflow_245_dst_as_seg_tree = proto_item_add_subtree(ti, ett_sflow_245_gw_as_dst_seg);
}
for (j = 0; j < dst_seg_len; j++) {
proto_tree_add_item(sflow_245_dst_as_seg_tree, hf_sflow_245_dst_as, tvb, offset + len, 4, ENC_BIG_ENDIAN);
len += 4;
}
}
if (version >= 4) {
comm_len = tvb_get_ntohl(tvb, offset + len);
ti = proto_tree_add_uint(tree, hf_sflow_245_community_entries, tvb, offset + len, 4, comm_len);
sflow_245_comm_tree = proto_item_add_subtree(ti, ett_sflow_245_gw_community);
len += 4;
for (i = 0; i < comm_len; i++) {
proto_tree_add_item(sflow_245_comm_tree,
hf_sflow_245_dst_as, tvb, offset + len,
4, ENC_BIG_ENDIAN);
len += 4;
}
proto_tree_add_item(tree, hf_sflow_245_localpref, tvb, offset + len, 4, ENC_BIG_ENDIAN);
len += 4;
}
return offset + len;
}
static gint
dissect_sflow_5_ethernet_frame(tvbuff_t *tvb, proto_tree *tree, gint offset) {
proto_tree_add_item(tree, hf_sflow_245_ethernet_length_of_mac_packet, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ethernet_source_mac_address, tvb, offset, 6, ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_sflow_245_ethernet_destination_mac_address, tvb, offset, 6, ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_sflow_245_ethernet_packet_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_ipv4(tvbuff_t *tvb, proto_tree *tree, gint offset) {
proto_tree_add_item(tree, hf_sflow_245_length_of_ip_packet, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ip_protocol, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ipv4_src, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ipv4_dst, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ip_source_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ip_destination_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_cwr, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_ece, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_urg, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_ack, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_psh, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_rst, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_syn, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_fin, tvb, offset, 1, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ipv4_precedence_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sflow_245_ipv4_delay, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ipv4_throughput, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ipv4_reliability, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ipv4_cost, tvb, offset, 1, ENC_NA);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_ipv6(tvbuff_t *tvb, proto_tree *tree, gint offset) {
proto_tree_add_item(tree, hf_sflow_245_length_of_ip_packet, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ip_protocol, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ipv6_src, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_sflow_245_ipv6_dst, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_sflow_245_ip_source_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ip_destination_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_cwr, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_ece, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_urg, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_ack, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_psh, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_rst, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_syn, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_sflow_245_ip_tcp_flag_fin, tvb, offset, 1, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ipv6_priority, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_user(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 src_length, dest_length;
proto_tree_add_item(tree, hf_sflow_5_extended_user_source_character_set, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
src_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_5_extended_user_source_user_string_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_user_source_user, tvb, offset, src_length, ENC_NA|ENC_ASCII);
offset += src_length;
if (src_length % 4)
offset += (4 - src_length % 4);
proto_tree_add_item(tree, hf_sflow_5_extended_user_destination_character_set, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
dest_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_5_extended_user_destination_user_string_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_user_destination_user, tvb, offset, dest_length, ENC_NA|ENC_ASCII);
offset += dest_length;
if (dest_length % 4)
offset += (4 - dest_length % 4);
return offset;
}
static gint
dissect_sflow_5_extended_url(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 direction, url_length, host_length;
direction = tvb_get_ntohl(tvb, offset);
switch (direction) {
case 1:
proto_tree_add_uint_format(tree, hf_sflow_5_extended_url_direction, tvb, offset, 4, direction,
"Source Address is Server(%u)", direction);
break;
case 2:
proto_tree_add_uint_format(tree, hf_sflow_5_extended_url_direction, tvb, offset, 4, direction,
"Destination Address is Server (%u)", direction);
break;
default:
proto_tree_add_uint_format(tree, hf_sflow_5_extended_url_direction, tvb, offset, 4, direction,
"Server Unspecified (%u)", direction);
break;
}
offset += 4;
url_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_5_extended_url_url_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_url_url, tvb, offset, url_length, ENC_NA|ENC_ASCII);
offset += url_length;
if (url_length % 4)
offset += (4 - url_length % 4);
host_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_5_extended_url_host_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_url_host, tvb, offset, host_length, ENC_NA|ENC_ASCII);
offset += host_length;
if (host_length % 4)
offset += (4 - host_length % 4);
return offset;
}
static gint
dissect_sflow_5_extended_mpls_tunnel(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 name_length;
name_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_5_extended_mpls_tunnel_name_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_mpls_tunnel_name, tvb, offset, name_length, ENC_NA|ENC_ASCII);
offset += name_length;
if (name_length % 4)
offset += (4 - name_length % 4);
proto_tree_add_item(tree, hf_sflow_5_extended_mpls_tunnel_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_mpls_tunnel_cos_value, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_mpls_vc(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 name_length;
name_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_5_extended_mpls_vc_instance_name_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_mpls_vc_instance_name, tvb, offset, name_length, ENC_NA|ENC_ASCII);
offset += name_length;
if (name_length % 4)
offset += (4 - name_length % 4);
proto_tree_add_item(tree, hf_sflow_5_extended_mpls_vc_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_mpls_vc_label_cos_value, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_mpls_fec(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 length;
length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_5_extended_mpls_ftn_description_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_mpls_ftn_description, tvb, offset, length, ENC_NA|ENC_ASCII);
offset += length;
if (length % 4)
offset += (4 - length % 4);
proto_tree_add_item(tree, hf_sflow_5_extended_mpls_ftn_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_mpls_lvp_fec(tvbuff_t *tvb, proto_tree *tree, gint offset) {
proto_tree_add_item(tree, hf_sflow_5_extended_mpls_fec_address_prefix_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_vlan_tunnel(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 num, i;
num = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_5_extended_vlan_tunnel_number_of_layers, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (i = 0; i < num; i++) {
proto_tree_add_item(tree, hf_sflow_5_extended_vlan_tunnel_tpid_tci_pair, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static gint
dissect_sflow_5_extended_80211_payload(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 cipher_suite, OUI, suite_type, length;
cipher_suite = tvb_get_ntohl(tvb, offset);
OUI = cipher_suite >> 8;
suite_type = cipher_suite & 0x000000ff;
if (OUI == 0x000FAC) {
proto_tree_add_uint_format_value(tree, hf_sflow_5_extended_80211_oui, tvb, offset, 3, OUI, "Default (0x%X)", OUI);
offset += 3;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_suite_type, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_uint_format_value(tree, hf_sflow_5_extended_80211_oui, tvb, offset, 3, OUI, "Other vender (0x%X)", OUI);
offset += 3;
proto_tree_add_uint_format_value(tree, hf_sflow_5_extended_80211_suite_type, tvb, offset, 1,
suite_type, "Vender specific (%u)", suite_type);
}
offset++;
length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_5_extended_80211_payload_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_payload, tvb, offset, length, ENC_NA);
offset += length;
if (length % 4)
offset += (4 - length % 4);
return offset;
}
static gint
dissect_sflow_5_extended_80211_rx(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 ssid_length, duration;
ssid_length = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_rx_ssid, tvb, offset, ssid_length, ENC_NA|ENC_ASCII);
offset += ssid_length;
if (ssid_length % 4)
offset += (4 - ssid_length % 4);
proto_tree_add_item(tree, hf_sflow_5_extended_80211_rx_bssid, tvb, offset, 6, ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_rx_version, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_rx_channel, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_rx_speed, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_rx_rsni, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_rx_rcpi, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
duration = tvb_get_ntohl(tvb, offset);
if (duration == 0) {
proto_tree_add_uint_format_value(tree, hf_sflow_5_extended_80211_rx_packet_duration, tvb, offset, 4, duration, "Unknown");
} else {
proto_tree_add_item(tree, hf_sflow_5_extended_80211_rx_packet_duration, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_80211_tx(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 ssid_length, transmissions, packet_duration, retrans_duration;
ssid_length = tvb_get_ntohl(tvb, offset);
if (ssid_length > 32)
ssid_length = 32;
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_tx_ssid, tvb, offset, ssid_length, ENC_NA|ENC_ASCII);
offset += ssid_length;
if (ssid_length % 4)
offset += (4 - ssid_length % 4);
proto_tree_add_item(tree, hf_sflow_5_extended_80211_tx_bssid, tvb, offset, 6, ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_tx_version, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
transmissions = tvb_get_ntohl(tvb, offset);
switch (transmissions) {
case 0:
proto_tree_add_uint_format_value(tree, hf_sflow_5_extended_80211_tx_retransmissions, tvb, offset, 4,
0, "Unknown");
break;
case 1:
proto_tree_add_uint_format_value(tree, hf_sflow_5_extended_80211_tx_retransmissions, tvb, offset, 4,
1, "Packet transmitted successfully on first attempt");
break;
default:
proto_tree_add_uint(tree, hf_sflow_5_extended_80211_tx_retransmissions, tvb, offset, 4, transmissions - 1);
break;
}
offset += 4;
packet_duration = tvb_get_ntohl(tvb, offset);
if (packet_duration == 0) {
proto_tree_add_uint_format_value(tree, hf_sflow_5_extended_80211_tx_packet_duration, tvb, offset, 4, packet_duration, "Unknown");
} else {
proto_tree_add_item(tree, hf_sflow_5_extended_80211_tx_packet_duration, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
retrans_duration = tvb_get_ntohl(tvb, offset);
if (retrans_duration == 0) {
proto_tree_add_uint_format_value(tree, hf_sflow_5_extended_80211_tx_retransmission_duration, tvb, offset, 4, retrans_duration, "Unknown");
} else {
proto_tree_add_item(tree, hf_sflow_5_extended_80211_tx_retransmission_duration, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_tx_channel, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_tx_speed, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_sflow_5_extended_80211_tx_power, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_80211_aggregation(tvbuff_t *tvb _U_, proto_tree *tree _U_, gint offset) {
return offset;
}
static gint
dissect_sflow_24_flow_sample(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, gint offset, proto_item *parent) {
guint32 sequence_number, sampling_rate, sample_pool, output;
proto_tree *extended_data_tree;
proto_item *ti;
guint32 packet_type, extended_data, ext_type, i;
sequence_number = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_flow_sample_sequence_number, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(parent, ", seq %u", sequence_number);
proto_tree_add_item(tree, hf_sflow_flow_sample_source_id_class, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sflow_flow_sample_index, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
sampling_rate = tvb_get_ntohl(tvb, offset + 8);
proto_tree_add_uint_format_value(tree, hf_sflow_flow_sample_sampling_rate, tvb, offset + 8, 4,
sampling_rate, "1 out of %u packets",
sampling_rate);
sample_pool = tvb_get_ntohl(tvb, offset + 12);
proto_tree_add_uint_format_value(tree, hf_sflow_flow_sample_sample_pool, tvb, offset + 12, 4,
sample_pool, "%u total packets",
sample_pool);
proto_tree_add_item(tree, hf_sflow_flow_sample_dropped_packets, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sflow_flow_sample_input_interface, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
output = tvb_get_ntohl(tvb, offset + 24);
if (output & 0x80000000) {
output & 0x7fffffff ?
proto_tree_add_uint_format_value(tree, hf_sflow_flow_sample_multiple_outputs, tvb, offset + 24, 4,
output & 0x7fffffff, "%u interfaces", output & 0x7fffffff) :
proto_tree_add_uint_format_value(tree, hf_sflow_flow_sample_multiple_outputs, tvb, offset + 24, 4,
0x80000000, "unknown number");
} else {
proto_tree_add_item(tree, hf_sflow_flow_sample_output_interface, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
}
offset += 28;
packet_type = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_245_packet_information_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch (packet_type) {
case SFLOW_245_PACKET_DATA_TYPE_HEADER:
offset = dissect_sflow_245_sampled_header(tvb, pinfo, tree, offset);
break;
case SFLOW_245_PACKET_DATA_TYPE_IPV4:
case SFLOW_245_PACKET_DATA_TYPE_IPV6:
default:
break;
}
extended_data = tvb_get_ntohl(tvb, offset);
offset += 4;
for (i = 0; i < extended_data; i++) {
ext_type = tvb_get_ntohl(tvb, offset);
ti = proto_tree_add_uint(tree, hf_sflow_245_extended_information_type, tvb, offset, 4, ext_type);
extended_data_tree = proto_item_add_subtree(ti, ett_sflow_245_extended_data);
offset += 4;
switch (ext_type) {
case SFLOW_245_EXTENDED_SWITCH:
offset = dissect_sflow_245_extended_switch(tvb, extended_data_tree, offset);
break;
case SFLOW_245_EXTENDED_ROUTER:
offset = dissect_sflow_245_extended_router(tvb, pinfo, extended_data_tree, offset);
break;
case SFLOW_245_EXTENDED_GATEWAY:
offset = dissect_sflow_245_extended_gateway(tvb, pinfo, extended_data_tree, offset);
break;
case SFLOW_245_EXTENDED_USER:
break;
case SFLOW_245_EXTENDED_URL:
break;
default:
break;
}
proto_item_set_end(ti, tvb, offset);
}
return offset;
}
static gint
dissect_sflow_5_flow_record(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset) {
proto_tree *flow_data_tree;
proto_item *ti;
guint32 enterprise_format, enterprise, format;
enterprise_format = tvb_get_ntohl(tvb, offset);
enterprise = enterprise_format >> 12;
format = enterprise_format & 0x00000fff;
if (enterprise == ENTERPRISE_DEFAULT) {
flow_data_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_sflow_5_flow_record, &ti,
val_to_str_ext_const(format, &sflow_5_flow_record_type_ext, "Unknown sample format"));
proto_tree_add_uint_format_value(flow_data_tree, hf_sflow_enterprise, tvb, offset, 4,
enterprise, "standard sFlow (%u)", enterprise);
proto_tree_add_item(flow_data_tree, hf_sflow_5_flow_record_format, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(flow_data_tree, hf_sflow_5_flow_data_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch (format) {
case SFLOW_5_RAW_PACKET_HEADER:
offset = dissect_sflow_245_sampled_header(tvb, pinfo, flow_data_tree, offset);
break;
case SFLOW_5_ETHERNET_FRAME:
offset = dissect_sflow_5_ethernet_frame(tvb, flow_data_tree, offset);
break;
case SFLOW_5_IPV4:
offset = dissect_sflow_5_ipv4(tvb, flow_data_tree, offset);
break;
case SFLOW_5_IPV6:
offset = dissect_sflow_5_ipv6(tvb, flow_data_tree, offset);
break;
case SFLOW_5_SWITCH:
offset = dissect_sflow_245_extended_switch(tvb, flow_data_tree, offset);
break;
case SFLOW_5_ROUTER:
offset = dissect_sflow_245_extended_router(tvb, pinfo, flow_data_tree, offset);
break;
case SFLOW_5_GATEWAY:
offset = dissect_sflow_245_extended_gateway(tvb, pinfo, flow_data_tree, offset);
break;
case SFLOW_5_USER:
offset = dissect_sflow_5_extended_user(tvb, flow_data_tree, offset);
break;
case SFLOW_5_URL:
offset = dissect_sflow_5_extended_url(tvb, flow_data_tree, offset);
break;
case SFLOW_5_MPLS_DATA:
offset = dissect_sflow_5_extended_mpls_data(tvb, pinfo, flow_data_tree, offset);
break;
case SFLOW_5_NAT:
offset = dissect_sflow_5_extended_nat(tvb, pinfo, flow_data_tree, offset);
break;
case SFLOW_5_MPLS_TUNNEL:
offset = dissect_sflow_5_extended_mpls_tunnel(tvb, flow_data_tree, offset);
break;
case SFLOW_5_MPLS_VC:
offset = dissect_sflow_5_extended_mpls_vc(tvb, flow_data_tree, offset);
break;
case SFLOW_5_MPLS_FEC:
offset = dissect_sflow_5_extended_mpls_fec(tvb, flow_data_tree, offset);
break;
case SFLOW_5_MPLS_LVP_FEC:
offset = dissect_sflow_5_extended_mpls_lvp_fec(tvb, flow_data_tree, offset);
break;
case SFLOW_5_VLAN_TUNNEL:
offset = dissect_sflow_5_extended_vlan_tunnel(tvb, flow_data_tree, offset);
break;
case SFLOW_5_80211_PAYLOAD:
offset = dissect_sflow_5_extended_80211_payload(tvb, flow_data_tree, offset);
break;
case SFLOW_5_80211_RX:
offset = dissect_sflow_5_extended_80211_rx(tvb, flow_data_tree, offset);
break;
case SFLOW_5_80211_TX:
offset = dissect_sflow_5_extended_80211_tx(tvb, flow_data_tree, offset);
break;
case SFLOW_5_80211_AGGREGATION:
offset = dissect_sflow_5_extended_80211_aggregation(tvb, flow_data_tree, offset);
break;
default:
break;
}
} else {
flow_data_tree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_sflow_5_flow_record, &ti, "Unknown enterprise format");
proto_tree_add_uint_format_value(flow_data_tree, hf_sflow_enterprise, tvb, offset, 4,
enterprise, "Non-standard sFlow (%u)", enterprise);
offset = tvb_captured_length(tvb);
}
proto_item_set_end(ti, tvb, offset);
return offset;
}
static gint
dissect_sflow_5_generic_interface(proto_tree *counter_data_tree, tvbuff_t *tvb, gint offset) {
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifindex, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_iftype, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifspeed, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifdirection, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifadmin_status, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifoper_status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifinoct, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifinpkt, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifinmcast, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifinbcast, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifindisc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifinerr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifinunk, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifoutoct, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifoutpkt, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifoutmcast, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifoutbcast, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifoutdisc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifouterr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifpromisc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_ethernet_interface(proto_tree *counter_data_tree, tvbuff_t *tvb, gint offset) {
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsAlignmentErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsFCSErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsSingleCollisionFrames, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsMultipleCollisionFrames, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsSQETestErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsDeferredTransmissions, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsLateCollisions, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsExcessiveCollisions, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsInternalMacTransmitErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsCarrierSenseErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsFrameTooLongs, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsInternalMacReceiveErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot3StatsSymbolErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_token_ring(proto_tree *counter_data_tree, tvbuff_t *tvb, gint offset) {
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsLineErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsBurstErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsACErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsAbortTransErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsInternalErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsLostFrameErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsReceiveCongestions, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsFrameCopiedErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsTokenErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsSoftErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsHardErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsSignalLoss, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsTransmitBeacons, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsRecoveries, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsLobeWires, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsRemoves, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsSingles, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot5StatsFreqErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_vg_interface(proto_tree *counter_data_tree, tvbuff_t *tvb, gint offset) {
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12InHighPriorityFrames, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12InHighPriorityOctets, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12InNormPriorityFrames, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12InNormPriorityOctets, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12InIPMErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12InOversizeFrameErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12InDataErrors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12InNullAddressedFrames, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12OutHighPriorityFrames, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12OutHighPriorityOctets, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12TransitionIntoTrainings, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12HCInHighPriorityOctets, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12HCInNormPriorityOctets, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(counter_data_tree, hf_sflow_245_dot12HCOutHighPriorityOctets, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static gint
dissect_sflow_5_vlan(proto_tree *counter_data_tree, tvbuff_t *tvb, gint offset) {
proto_tree_add_item(counter_data_tree, hf_sflow_245_vlan_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_octets, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ucastPkts, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_multicastPkts, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_broadcastPkts, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_discards, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_80211_counters(proto_tree *counter_data_tree, tvbuff_t *tvb, gint offset) {
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11TransmittedFragmentCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11MulticastTransmittedFrameCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11FailedCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11RetryCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11MultipleRetryCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11FrameDuplicateCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11RTSSuccessCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11RTSFailureCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11ACKFailureCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11ReceivedFragmentCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11MulticastReceivedFrameCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11FCSErrorCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11TransmittedFrameCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11WEPUndecryptableCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11QoSDiscardedFragmentCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11AssociatedStationCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11QoSCFPollsReceivedCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11QoSCFPollsUnusedCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11QoSCFPollsUnusableCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_dot11QoSCFPollsLostCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_processor_information(proto_tree *counter_data_tree, tvbuff_t *tvb, gint offset) {
proto_tree_add_item(counter_data_tree, hf_sflow_5_cpu_5s, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_cpu_1m, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_cpu_5m, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_total_memory, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(counter_data_tree, hf_sflow_5_free_memory, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static gint
dissect_sflow_5_radio_utilization(proto_tree *counter_data_tree, tvbuff_t *tvb, gint offset) {
proto_tree_add_item(counter_data_tree, hf_sflow_5_elapsed_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_on_channel_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_on_channel_busy_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_counters_record(tvbuff_t *tvb, proto_tree *tree, gint offset) {
proto_tree *counter_data_tree;
proto_item *ti;
guint32 enterprise_format, enterprise, format;
enterprise_format = tvb_get_ntohl(tvb, offset);
enterprise = enterprise_format >> 12;
format = enterprise_format & 0x00000fff;
if (enterprise == ENTERPRISE_DEFAULT) {
counter_data_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_sflow_5_counters_record, &ti,
val_to_str_const(format, sflow_5_counters_record_type, "Unknown sample format"));
proto_tree_add_uint_format_value(counter_data_tree, hf_sflow_enterprise, tvb, offset, 4,
enterprise, "standard sFlow (%u)", enterprise);
proto_tree_add_item(counter_data_tree, hf_sflow_5_counters_record_format, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_5_flow_data_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch (format) {
case SFLOW_5_GENERIC_INTERFACE:
offset = dissect_sflow_5_generic_interface(counter_data_tree, tvb, offset);
break;
case SFLOW_5_ETHERNET_INTERFACE:
offset = dissect_sflow_5_ethernet_interface(counter_data_tree, tvb, offset);
break;
case SFLOW_5_TOKEN_RING:
offset = dissect_sflow_5_token_ring(counter_data_tree, tvb, offset);
break;
case SFLOW_5_100BASE_VG_INTERFACE:
offset = dissect_sflow_5_vg_interface(counter_data_tree, tvb, offset);
break;
case SFLOW_5_VLAN:
offset = dissect_sflow_5_vlan(counter_data_tree, tvb, offset);
break;
case SFLOW_5_80211_COUNTERS:
offset = dissect_sflow_5_80211_counters(counter_data_tree, tvb, offset);
break;
case SFLOW_5_PROCESSOR:
offset = dissect_sflow_5_processor_information(counter_data_tree, tvb, offset);
break;
case SFLOW_5_RADIO_UTILIZATION:
offset = dissect_sflow_5_radio_utilization(counter_data_tree, tvb, offset);
break;
default:
break;
}
} else {
counter_data_tree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_sflow_5_counters_record, &ti, "Unknown enterprise format");
proto_tree_add_uint_format_value(counter_data_tree, hf_sflow_enterprise, tvb, offset, 4,
enterprise, "Non-standard sFlow (%u)", enterprise);
offset = tvb_captured_length(tvb);
}
proto_item_set_end(ti, tvb, offset);
return offset;
}
static void
dissect_sflow_5_flow_sample(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, gint offset, proto_item *parent) {
guint32 sequence_number, sampling_rate, sample_pool,
output, records, i;
sequence_number = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_flow_sample_sequence_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_append_text(parent, ", seq %u", sequence_number);
proto_tree_add_item(tree, hf_sflow_flow_sample_source_id_class, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sflow_flow_sample_index, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
sampling_rate = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_sflow_flow_sample_sampling_rate, tvb, offset, 4,
sampling_rate, "1 out of %u packets", sampling_rate);
offset += 4;
sample_pool = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_sflow_flow_sample_sample_pool, tvb, offset, 4,
sample_pool, "%u total packets", sample_pool);
offset += 4;
proto_tree_add_item(tree, hf_sflow_flow_sample_dropped_packets, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_flow_sample_input_interface, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
output = tvb_get_ntohl(tvb, offset);
if (output & 0x80000000) {
output & 0x7fffffff ?
proto_tree_add_uint_format_value(tree, hf_sflow_flow_sample_multiple_outputs, tvb, offset, 4,
output & 0x7fffffff, "%u interfaces", output & 0x7fffffff) :
proto_tree_add_uint_format_value(tree, hf_sflow_flow_sample_multiple_outputs, tvb, offset, 4,
0x80000000, "unknown number");
} else {
proto_tree_add_item(tree, hf_sflow_flow_sample_output_interface, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
records = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_flow_sample_flow_record, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (i = 0; i < (records&0x000000ff); i++) {
offset = dissect_sflow_5_flow_record(tvb, pinfo, tree, offset);
}
}
static void
dissect_sflow_5_expanded_flow_sample(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, gint offset, proto_item *parent) {
guint32 sequence_number, sampling_rate, sample_pool, records, i;
sequence_number = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_flow_sample_sequence_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_append_text(parent, ", seq %u", sequence_number);
proto_tree_add_item(tree, hf_sflow_flow_sample_source_id_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_flow_sample_source_id_index, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
sampling_rate = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_sflow_flow_sample_sampling_rate, tvb, offset, 4,
sampling_rate, "1 out of %u packets", sampling_rate);
offset += 4;
sample_pool = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_sflow_flow_sample_sample_pool, tvb, offset, 4,
sample_pool, "%u total packets", sample_pool);
offset += 4;
proto_tree_add_item(tree, hf_sflow_flow_sample_dropped_packets, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_flow_sample_input_interface_format, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_flow_sample_input_interface_value, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_flow_sample_output_interface_format, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_flow_sample_output_interface_value, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
records = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_flow_sample_flow_record, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (i = 0; i < (records&0x000000ff); i++) {
offset = dissect_sflow_5_flow_record(tvb, pinfo, tree, offset);
}
}
static gint
dissect_sflow_24_counters_sample(tvbuff_t *tvb, proto_tree *tree, gint offset, proto_item *parent) {
guint32 sequence_number, counters_type;
sequence_number = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_counters_sample_sequence_number, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(parent, ", seq %u", sequence_number);
proto_tree_add_item(tree, hf_sflow_counters_sample_source_id_class, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sflow_counters_sample_index, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sflow_counters_sample_sampling_interval, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
counters_type = tvb_get_ntohl(tvb, offset + 12);
proto_tree_add_item(tree, hf_sflow_counters_sample_counters_type, tvb, offset + 12, 4, ENC_BIG_ENDIAN);
offset += 16;
switch (counters_type) {
case SFLOW_245_COUNTERS_GENERIC:
case SFLOW_245_COUNTERS_ETHERNET:
case SFLOW_245_COUNTERS_TOKENRING:
case SFLOW_245_COUNTERS_FDDI:
case SFLOW_245_COUNTERS_VG:
case SFLOW_245_COUNTERS_WAN:
proto_tree_add_item(tree, hf_sflow_245_ifindex, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(parent, ", ifIndex %u", tvb_get_ntohl(tvb, offset));
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_iftype, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifspeed, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_sflow_245_ifdirection, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifadmin_status, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sflow_245_ifoper_status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifinoct, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_sflow_245_ifinpkt, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifinmcast, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifinbcast, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifindisc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifinerr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifinunk, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifoutoct, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_sflow_245_ifoutpkt, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifoutmcast, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifoutbcast, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifoutdisc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifouterr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifpromisc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
}
switch (counters_type) {
case SFLOW_245_COUNTERS_ETHERNET:
offset += (int)sizeof (struct ethernet_counters);
break;
case SFLOW_245_COUNTERS_TOKENRING:
offset = dissect_sflow_5_token_ring(tree, tvb, offset);
break;
case SFLOW_245_COUNTERS_VG:
offset = dissect_sflow_5_vg_interface(tree, tvb, offset);
break;
case SFLOW_245_COUNTERS_VLAN:
offset = dissect_sflow_5_vlan(tree, tvb, offset);
break;
default:
break;
}
return offset;
}
static void
dissect_sflow_5_counters_sample(tvbuff_t *tvb, proto_tree *tree, gint offset, proto_item *parent) {
guint32 sequence_number, records, i;
sequence_number = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_counters_sample_sequence_number, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(parent, ", seq %u", sequence_number);
offset += 4;
proto_tree_add_item(tree, hf_sflow_counters_sample_source_id_type, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sflow_counters_sample_source_id_index, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
records = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_counters_sample_counters_records, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (i = 0; i < (records&0x000000ff); i++) {
offset = dissect_sflow_5_counters_record(tvb, tree, offset);
}
}
static void
dissect_sflow_5_expanded_counters_sample(tvbuff_t *tvb, proto_tree *tree, gint offset, proto_item *parent) {
guint32 sequence_number, records, i;
sequence_number = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_counters_sample_sequence_number, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(parent, ", seq %u", sequence_number);
offset += 4;
proto_tree_add_item(tree, hf_sflow_counters_sample_expanded_source_id_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_counters_sample_expanded_source_id_index, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
records = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_counters_sample_counters_records, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (i = 0; i < (records&0x000000ff); i++) {
offset = dissect_sflow_5_counters_record(tvb, tree, offset);
}
}
static void
dissect_sflow_5_lag_port_stats(tvbuff_t *tvb, proto_tree *tree, gint offset, proto_item *parent _U_) {
proto_tree_add_item(tree, hf_sflow_lag_port_actorsystemid, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_sflow_lag_port_partneropersystemid, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_sflow_lag_port_attachedaggid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_sflow_lag_port_state, ett_sflow_lag_port_state_flags, sflow_lag_port_state_flags, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_lag_port_stats_lacpdusrx, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_lag_port_stats_markerpdusrx, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_lag_port_stats_markerresponsepdusrx, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_lag_port_stats_unknownrx, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_lag_port_stats_illegalrx, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_lag_port_stats_lacpdustx, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_lag_port_stats_markerpdustx, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_lag_port_stats_markerresponsepdustx, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static gint
dissect_sflow_245_samples(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, guint32 version) {
proto_tree *sflow_245_sample_tree;
proto_item *ti;
guint32 sample_type, enterprise, format, length;
sample_type = tvb_get_ntohl(tvb, offset);
if (version == 5) {
enterprise = sample_type >> 12;
format = sample_type & 0x00000fff;
if (enterprise == ENTERPRISE_DEFAULT) {
sflow_245_sample_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_sflow_245_sample, &ti,
val_to_str_const(format, sflow_245_sampletype, "Unknown sample format"));
proto_tree_add_uint_format_value(sflow_245_sample_tree, hf_sflow_enterprise, tvb, offset, 4, enterprise, "standard sFlow (%u)", enterprise);
proto_tree_add_item(sflow_245_sample_tree, hf_sflow_245_sampletype12, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(sflow_245_sample_tree, hf_sflow_5_sample_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch (format) {
case FLOWSAMPLE:
dissect_sflow_5_flow_sample(tvb, pinfo, sflow_245_sample_tree, offset, ti);
break;
case COUNTERSSAMPLE:
dissect_sflow_5_counters_sample(tvb, sflow_245_sample_tree, offset, ti);
break;
case EXPANDED_FLOWSAMPLE:
dissect_sflow_5_expanded_flow_sample(tvb, pinfo, sflow_245_sample_tree, offset, ti);
break;
case EXPANDED_COUNTERSSAMPLE:
dissect_sflow_5_expanded_counters_sample(tvb, sflow_245_sample_tree, offset, ti);
break;
case LAG_PORT_STATS:
dissect_sflow_5_lag_port_stats(tvb, sflow_245_sample_tree, offset, ti);
break;
default:
break;
}
tvb_ensure_bytes_exist(tvb, offset, length);
offset += length;
} else {
sflow_245_sample_tree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_sflow_245_sample, &ti, "Unknown enterprise format");
proto_tree_add_uint_format_value(sflow_245_sample_tree, hf_sflow_enterprise, tvb, offset, 4,
enterprise, "Non-standard sFlow (%u)", enterprise);
offset = tvb_captured_length(tvb);
}
} else {
sflow_245_sample_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_sflow_245_sample, &ti,
val_to_str_const(sample_type, sflow_245_sampletype, "Unknown sample type"));
proto_tree_add_item(sflow_245_sample_tree, hf_sflow_245_sampletype, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch (sample_type) {
case FLOWSAMPLE:
offset = dissect_sflow_24_flow_sample(tvb, pinfo, sflow_245_sample_tree, offset, ti);
break;
case COUNTERSSAMPLE:
offset = dissect_sflow_24_counters_sample(tvb, sflow_245_sample_tree, offset, ti);
break;
default:
break;
}
}
proto_item_set_end(ti, tvb, offset);
return offset;
}
static int
dissect_sflow_245(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *sflow_245_tree;
guint32 version, sub_agent_id, seqnum;
address addr_details;
int sflow_addr_type;
struct sflow_address_type addr_type;
guint32 numsamples;
guint offset = 0;
guint i = 0;
addr_type.hf_addr_v4 = hf_sflow_agent_address_v4;
addr_type.hf_addr_v6 = hf_sflow_agent_address_v6;
version = tvb_get_ntohl(tvb, offset);
if (version != 2 && version != 4 && version != 5) {
return 0;
}
sflow_addr_type = tvb_get_ntohl(tvb, offset + 4);
switch (sflow_addr_type) {
case ADDR_TYPE_UNKNOWN:
addr_details.type = AT_NONE;
break;
case ADDR_TYPE_IPV4:
addr_details.type = AT_IPv4;
break;
case ADDR_TYPE_IPV6:
addr_details.type = AT_IPv6;
break;
default:
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "sFlow");
ti = proto_tree_add_item(tree, proto_sflow, tvb, 0, -1, ENC_NA);
sflow_245_tree = proto_item_add_subtree(ti, ett_sflow_245);
col_add_fstr(pinfo->cinfo, COL_INFO, "V%u", version);
proto_tree_add_item(sflow_245_tree, hf_sflow_version, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sflow_245_tree, hf_sflow_agent_address_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = dissect_sflow_245_address_type(tvb, pinfo, sflow_245_tree, offset,
&addr_type, &addr_details);
switch (sflow_addr_type) {
case ADDR_TYPE_UNKNOWN:
break;
case ADDR_TYPE_IPV4:
case ADDR_TYPE_IPV6:
col_append_fstr(pinfo->cinfo, COL_INFO, ", agent %s", address_to_str(wmem_packet_scope(), &addr_details));
break;
}
if (version == 5) {
sub_agent_id = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ", sub-agent ID %u", sub_agent_id);
proto_tree_add_uint(sflow_245_tree, hf_sflow_5_sub_agent_id, tvb, offset, 4, sub_agent_id);
offset += 4;
}
seqnum = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ", seq %u", seqnum);
proto_tree_add_uint(sflow_245_tree, hf_sflow_245_seqnum, tvb, offset, 4, seqnum);
offset += 4;
proto_tree_add_item(sflow_245_tree, hf_sflow_245_sysuptime, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numsamples = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %u samples", numsamples);
proto_tree_add_uint(sflow_245_tree, hf_sflow_245_numsamples, tvb, offset, 4, numsamples);
offset += 4;
for (i = 0; i < (numsamples & 0x000000ff); i++) {
offset = dissect_sflow_245_samples(tvb, pinfo, sflow_245_tree, offset, version);
}
return tvb_captured_length(tvb);
}
void
proto_register_sflow(void) {
module_t *sflow_245_module;
static hf_register_info hf[] = {
{ &hf_sflow_version,
{ "Datagram version", "sflow_245.version",
FT_UINT32, BASE_DEC, NULL, 0x0,
"sFlow datagram version", HFILL}},
{ &hf_sflow_agent_address_type,
{ "Agent address type", "sflow_245.agenttype",
FT_UINT32, BASE_DEC, VALS(sflow_agent_address_types), 0x0,
"sFlow agent address type", HFILL}},
{ &hf_sflow_agent_address_v4,
{ "Agent address", "sflow_245.agent",
FT_IPv4, BASE_NONE, NULL, 0x0,
"sFlow Agent IP address", HFILL}},
{ &hf_sflow_agent_address_v6,
{ "Agent address", "sflow_245.agent.v6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"sFlow Agent IPv6 address", HFILL}},
{ &hf_sflow_5_sub_agent_id,
{ "Sub-agent ID", "sflow_245.sub_agent_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"sFlow sub-agent ID", HFILL}},
{ &hf_sflow_5_sample_length,
{ "Sample length (byte)", "sflow_5.sample_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"sFlow sample length", HFILL}},
{ &hf_sflow_5_flow_data_length,
{ "Flow data length (byte)", "sflow_5.flow_data_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"sFlow flow data length", HFILL}},
#if 0
{ &hf_sflow_5_counters_data_length,
{ "Counters data length (byte)", "sflow_5.counter_data_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"sFlow counters data length", HFILL}},
#endif
{ &hf_sflow_245_seqnum,
{ "Sequence number", "sflow_245.sequence_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
"sFlow datagram sequence number", HFILL}},
{ &hf_sflow_245_sysuptime,
{ "SysUptime", "sflow_245.sysuptime",
FT_UINT32, BASE_DEC, NULL, 0x0,
"System Uptime", HFILL}},
{ &hf_sflow_245_numsamples,
{ "NumSamples", "sflow_245.numsamples",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of samples in sFlow datagram", HFILL}},
{ &hf_sflow_245_sampletype,
{ "sFlow sample type", "sflow_245.sampletype",
FT_UINT32, BASE_DEC, VALS(sflow_245_sampletype), 0x0,
"Type of sFlow sample", HFILL}},
{ &hf_sflow_245_sampletype12,
{ "sFlow sample type", "sflow_245.sampletype",
FT_UINT32, BASE_DEC, VALS(sflow_245_sampletype), 0x00000FFF,
"Type of sFlow sample", HFILL}},
#if 0
{ &hf_sflow_5_ieee80211_version,
{ "Version", "sflow_245.ieee80211_version",
FT_UINT32, BASE_DEC, VALS(sflow_5_ieee80211_versions), 0x0,
"IEEE 802.11 Version", HFILL}},
#endif
{ &hf_sflow_245_ipv4_precedence_type,
{ "Precedence", "sflow_245.ipv4_precedence_type",
FT_UINT8, BASE_DEC, VALS(sflow_245_ipv4_precedence_types), 0xE0,
"IPv4 Precedence Type", HFILL}},
{ &hf_sflow_5_flow_record_format,
{ "Format", "sflow_245.flow_record_format",
FT_UINT32, BASE_DEC | BASE_EXT_STRING, &sflow_5_flow_record_type_ext, 0x0,
"Format of sFlow flow record", HFILL}},
{ &hf_sflow_5_counters_record_format,
{ "Format", "sflow_245.counters_record_format",
FT_UINT32, BASE_DEC, VALS(sflow_5_counters_record_type), 0x00000FFF,
"Format of sFlow counters record", HFILL}},
{ &hf_sflow_245_header_protocol,
{ "Header protocol", "sflow_245.header_protocol",
FT_UINT32, BASE_DEC | BASE_EXT_STRING, &sflow_245_header_protocol_ext, 0x0,
"Protocol of sampled header", HFILL}},
{ &hf_sflow_245_header,
{ "Header of sampled packet", "sflow_245.header",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Data from sampled header", HFILL}},
{ &hf_sflow_245_packet_information_type,
{ "Sample type", "sflow_245.packet_information_type",
FT_UINT32, BASE_DEC, VALS(sflow_245_packet_information_type), 0x0,
"Type of sampled information", HFILL}},
{ &hf_sflow_245_extended_information_type,
{ "Extended information type", "sflow_245.extended_information_type",
FT_UINT32, BASE_DEC, VALS(sflow_245_extended_data_types), 0x0,
"Type of extended information", HFILL}},
{ &hf_sflow_245_vlan_in,
{ "Incoming 802.1Q VLAN", "sflow_245.vlan.in",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Incoming VLAN ID", HFILL}},
{ &hf_sflow_245_vlan_out,
{ "Outgoing 802.1Q VLAN", "sflow_245.vlan.out",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Outgoing VLAN ID", HFILL}},
{ &hf_sflow_245_pri_in,
{ "Incoming 802.1p priority", "sflow_245.pri.in",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_pri_out,
{ "Outgoing 802.1p priority", "sflow_245.pri.out",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_nexthop_v4,
{ "Next hop", "sflow_245.nexthop",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Next hop address", HFILL}},
{ &hf_sflow_245_ipv4_src,
{ "Source IP address", "sflow_245.ipv4_src",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Source IPv4 address", HFILL}},
{ &hf_sflow_245_ipv4_dst,
{ "Destination IP address", "sflow_245.ipv4_dst",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Destination IPv4 address", HFILL}},
{ &hf_sflow_245_nexthop_v6,
{ "Next hop", "sflow_245.nexthop.v6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Next hop address", HFILL}},
{ &hf_sflow_245_ipv6_src,
{ "Source IP address", "sflow_245.ipv6_src",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Source IPv6 address", HFILL}},
{ &hf_sflow_245_ipv6_dst,
{ "Destination IP address", "sflow_245.ipv6_dst",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Destination IPv6 address", HFILL}},
{ &hf_sflow_245_nexthop_src_mask,
{ "Next hop source mask", "sflow_245.nexthop.src_mask",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Next hop source mask bits", HFILL}},
{ &hf_sflow_245_nexthop_dst_mask,
{ "Next hop destination mask", "sflow_245.nexthop.dst_mask",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Next hop destination mask bits", HFILL}},
{ &hf_sflow_245_ifindex,
{ "Interface index", "sflow_245.ifindex",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_as,
{ "AS Router", "sflow_245.as",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Autonomous System of Router", HFILL}},
{ &hf_sflow_245_src_as,
{ "AS Source", "sflow_245.srcAS",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Autonomous System of Source", HFILL}},
{ &hf_sflow_245_src_peer_as,
{ "AS Peer", "sflow_245.peerAS",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Autonomous System of Peer", HFILL}},
{ &hf_sflow_245_dst_as_entries,
{ "AS Destinations", "sflow_245.dstASentries",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Autonomous System destinations", HFILL}},
{ &hf_sflow_245_dst_as,
{ "AS Destination", "sflow_245.dstAS",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Autonomous System destination", HFILL}},
{ &hf_sflow_245_community_entries,
{ "Gateway Communities", "sflow_245.communityEntries",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
#if 0
{ &hf_sflow_245_community,
{ "Gateway Community", "sflow_245.community",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Gateway Communities", HFILL}},
#endif
{ &hf_sflow_245_localpref,
{ "localpref", "sflow_245.localpref",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Local preferences of AS route", HFILL}},
{ &hf_sflow_245_iftype,
{ "Interface Type", "sflow_245.iftype",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifspeed,
{ "Interface Speed", "sflow_245.ifspeed",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifdirection,
{ "Interface Direction", "sflow_245.ifdirection",
FT_UINT32, BASE_DEC, VALS(sflow_ifdirection_vals), 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifadmin_status,
{ "IfAdminStatus", "sflow_245.ifadmin_status",
FT_BOOLEAN, 32, TFS(&tfs_up_down), 0x00000001,
NULL, HFILL}},
{ &hf_sflow_245_ifoper_status,
{ "IfOperStatus", "sflow_245.ifoper_status",
FT_BOOLEAN, 32, TFS(&tfs_up_down), 0x00000002,
NULL, HFILL}},
{ &hf_sflow_245_ifinoct,
{ "Input Octets", "sflow_245.ifinoct",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifinpkt,
{ "Input Packets", "sflow_245.ifinpkt",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifinmcast,
{ "Input Multicast Packets", "sflow_245.ifinmcast",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifinbcast,
{ "Input Broadcast Packets", "sflow_245.ifinbcast",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifindisc,
{ "Input Discarded Packets", "sflow_245.ifindisc",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifinerr,
{ "Input Errors", "sflow_245.ifinerr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifinunk,
{ "Input Unknown Protocol Packets", "sflow_245.ifinunk",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifoutoct,
{ "Output Octets", "sflow_245.ifoutoct",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifoutpkt,
{ "Output Packets", "sflow_245.ifoutpkt",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifoutmcast,
{ "Output Multicast Packets", "sflow_245.ifoutmcast",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifoutbcast,
{ "Output Broadcast Packets", "sflow_245.ifoutbcast",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifoutdisc,
{ "Output Discarded Packets", "sflow_245.ifoutdisc",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifouterr,
{ "Output Errors", "sflow_245.ifouterr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ifpromisc,
{ "Promiscuous Mode", "sflow_245.ifpromisc",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_dot3StatsAlignmentErrors,
{ "Alignment Errors", "sflow_245.dot3StatsAlignmentErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats Alignment Errors", HFILL}},
{ &hf_sflow_245_dot3StatsFCSErrors,
{ "FCS Errors", "sflow_245.dot3StatsFCSErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats FCS Errors", HFILL}},
{ &hf_sflow_245_dot3StatsSingleCollisionFrames,
{ "Single Collision Frames", "sflow_245.dot3StatsSingleCollisionFrames",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats Single Collision Frames", HFILL}},
{ &hf_sflow_245_dot3StatsMultipleCollisionFrames,
{ "Multiple Collision Frames", "sflow_245.dot3StatsMultipleCollisionFrames",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats Multiple Collision Frames", HFILL}},
{ &hf_sflow_245_dot3StatsSQETestErrors,
{ "SQE Test Errors", "sflow_245.dot3StatsSQETestErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats SQE Test Errors", HFILL}},
{ &hf_sflow_245_dot3StatsDeferredTransmissions,
{ "Deferred Transmissions", "sflow_245.dot3StatsDeferredTransmissions",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats Deferred Transmissions", HFILL}},
{ &hf_sflow_245_dot3StatsLateCollisions,
{ "Late Collisions", "sflow_245.dot3StatsLateCollisions",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats Late Collisions", HFILL}},
{ &hf_sflow_245_dot3StatsExcessiveCollisions,
{ "Excessive Collisions", "sflow_245.dot3StatsExcessiveCollisions",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats Excessive Collisions", HFILL}},
{ &hf_sflow_245_dot3StatsInternalMacTransmitErrors,
{ "Internal Mac Transmit Errors", "sflow_245.dot3StatsInternalMacTransmitErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats Internal Mac Transmit Errors", HFILL}},
{ &hf_sflow_245_dot3StatsCarrierSenseErrors,
{ "Carrier Sense Errors", "sflow_245.dot3StatsCarrierSenseErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats Carrier Sense Errors", HFILL}},
{ &hf_sflow_245_dot3StatsFrameTooLongs,
{ "Frame Too Longs", "sflow_245.dot3StatsFrameTooLongs",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats Frame Too Longs", HFILL}},
{ &hf_sflow_245_dot3StatsInternalMacReceiveErrors,
{ "Internal Mac Receive Errors", "sflow_245.dot3StatsInternalMacReceiveErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats Internal Mac Receive Errors", HFILL}},
{ &hf_sflow_245_dot3StatsSymbolErrors,
{ "Symbol Errors", "sflow_245.dot3StatsSymbolErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot3 Stats Symbol Errors", HFILL}},
{ &hf_sflow_245_dot5StatsLineErrors,
{ "Line Errors", "sflow_245.dot5StatsLineErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Line Errors", HFILL}},
{ &hf_sflow_245_dot5StatsBurstErrors,
{ "Burst Errors", "sflow_245.dot5StatsBurstErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Burst Errors", HFILL}},
{ &hf_sflow_245_dot5StatsACErrors,
{ "AC Errors", "sflow_245.dot5StatsACErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats AC Errors", HFILL}},
{ &hf_sflow_245_dot5StatsAbortTransErrors,
{ "Abort Trans Errors", "sflow_245.dot5StatsAbortTransErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Abort Trans Errors", HFILL}},
{ &hf_sflow_245_dot5StatsInternalErrors,
{ "Internal Errors", "sflow_245.dot5StatsInternalErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Internal Errors", HFILL}},
{ &hf_sflow_245_dot5StatsLostFrameErrors,
{ "Lost Frame Errors", "sflow_245.dot5StatsLostFrameErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Lost Frame Errors", HFILL}},
{ &hf_sflow_245_dot5StatsReceiveCongestions,
{ "Receive Congestions", "sflow_245.dot5StatsReceiveCongestions",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Receive Congestions", HFILL}},
{ &hf_sflow_245_dot5StatsFrameCopiedErrors,
{ "Frame Copied Errors", "sflow_245.dot5StatsFrameCopiedErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Frame Copied Errors", HFILL}},
{ &hf_sflow_245_dot5StatsTokenErrors,
{ "Token Errors", "sflow_245.dot5StatsTokenErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Token Errors", HFILL}},
{ &hf_sflow_245_dot5StatsSoftErrors,
{ "Soft Errors", "sflow_245.dot5StatsSoftErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Soft Errors", HFILL}},
{ &hf_sflow_245_dot5StatsHardErrors,
{ "Hard Errors", "sflow_245.dot5StatsHardErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Hard Errors", HFILL}},
{ &hf_sflow_245_dot5StatsSignalLoss,
{ "Signal Loss", "sflow_245.dot5StatsSignalLoss",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Signal Loss", HFILL}},
{ &hf_sflow_245_dot5StatsTransmitBeacons,
{ "Transmit Beacons", "sflow_245.dot5StatsTransmitBeacons",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Transmit Beacons", HFILL}},
{ &hf_sflow_245_dot5StatsRecoveries,
{ "Recoveries", "sflow_245.dot5StatsRecoveries",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Recoveries", HFILL}},
{ &hf_sflow_245_dot5StatsLobeWires,
{ "Lobe Wires", "sflow_245.dot5StatsLobeWires",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Lobe Wires", HFILL}},
{ &hf_sflow_245_dot5StatsRemoves,
{ "Removes", "sflow_245.dot5StatsRemoves",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Removes", HFILL}},
{ &hf_sflow_245_dot5StatsSingles,
{ "Singles", "sflow_245.dot5StatsSingles",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Singles", HFILL}},
{ &hf_sflow_245_dot5StatsFreqErrors,
{ "Freq Errors", "sflow_245.dot5StatsFreqErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot5 Stats Freq Errors", HFILL}},
{ &hf_sflow_245_dot12InHighPriorityFrames,
{ "In High Priority Frames", "sflow_245.dot12InHighPriorityFrames",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot12 Input High Priority Frames", HFILL}},
{ &hf_sflow_245_dot12InHighPriorityOctets,
{ "In High Priority Octets", "sflow_245.dot12InHighPriorityOctets",
FT_UINT64, BASE_DEC, NULL, 0x0,
"dot12 Input High Priority Octets", HFILL}},
{ &hf_sflow_245_dot12InNormPriorityFrames,
{ "In Normal Priority Frames", "sflow_245.dot12InNormPriorityFrames",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot12 Input Normal Priority Frames", HFILL}},
{ &hf_sflow_245_dot12InNormPriorityOctets,
{ "In Normal Priority Octets", "sflow_245.dot12InNormPriorityOctets",
FT_UINT64, BASE_DEC, NULL, 0x0,
"dot12 Input Normal Priority Octets", HFILL}},
{ &hf_sflow_245_dot12InIPMErrors,
{ "In IPM Errors", "sflow_245.dot12InIPMErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot12 Input IPM Errors", HFILL}},
{ &hf_sflow_245_dot12InOversizeFrameErrors,
{ "In Oversize Frame Errors", "sflow_245.dot12InOversizeFrameErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot12 Input Oversize Frame Errors", HFILL}},
{ &hf_sflow_245_dot12InDataErrors,
{ "In Data Errors", "sflow_245.dot12InDataErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot12 Input Data Errors", HFILL}},
{ &hf_sflow_245_dot12InNullAddressedFrames,
{ "In Null Addressed Frames", "sflow_245.dot12InNullAddressedFrames",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot12 Input Null Addressed Frames", HFILL}},
{ &hf_sflow_245_dot12OutHighPriorityFrames,
{ "Out High Priority Frames", "sflow_245.dot12OutHighPriorityFrames",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot12 Output High Priority Frames", HFILL}},
{ &hf_sflow_245_dot12OutHighPriorityOctets,
{ "Out High Priority Octets", "sflow_245.dot12OutHighPriorityOctets",
FT_UINT64, BASE_DEC, NULL, 0x0,
"dot12 Out High Priority Octets", HFILL}},
{ &hf_sflow_245_dot12TransitionIntoTrainings,
{ "Transition Into Trainings", "sflow_245.dot12TransitionIntoTrainings",
FT_UINT32, BASE_DEC, NULL, 0x0,
"dot12 Transition Into Trainings", HFILL}},
{ &hf_sflow_245_dot12HCInHighPriorityOctets,
{ "HC In High Priority Octets", "sflow_245.dot12HCInHighPriorityOctets",
FT_UINT64, BASE_DEC, NULL, 0x0,
"dot12 HC Input High Priority Octets", HFILL}},
{ &hf_sflow_245_dot12HCInNormPriorityOctets,
{ "HC In Normal Priority Octets", "sflow_245.dot12HCInNormPriorityOctets",
FT_UINT64, BASE_DEC, NULL, 0x0,
"dot12 HC Input Normal Priority Octets", HFILL}},
{ &hf_sflow_245_dot12HCOutHighPriorityOctets,
{ "HC Out High Priority Octets", "sflow_245.dot12HCOutHighPriorityOctets",
FT_UINT64, BASE_DEC, NULL, 0x0,
"dot12 HC Output High Priority Octets", HFILL}},
{ &hf_sflow_245_vlan_id,
{ "VLAN ID", "sflow_245.vlan_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_octets,
{ "Octets", "sflow_245.octets",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_ucastPkts,
{ "Unicast Packets", "sflow_245.ucastPkts",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_multicastPkts,
{ "Multicast Packets", "sflow_245.multicastPkts",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_broadcastPkts,
{ "Broadcast Packets", "sflow_245.broadcastPkts",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_245_discards,
{ "Discards", "sflow_245.discards",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11TransmittedFragmentCount,
{ "Transmitted Fragment Count", "sflow_5.dot11TransmittedFragmentCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11MulticastTransmittedFrameCount,
{ "Multicast Transmitted Frame Count", "sflow_5.dot11MulticastTransmittedFrameCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11FailedCount,
{ "Failed Count", "sflow_5.dot11FailedCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11RetryCount,
{ "Retry Count", "sflow_5.dot11RetryCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11MultipleRetryCount,
{ "Multiple Retry Count", "sflow_5.dot11MultipleRetryCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11FrameDuplicateCount,
{ "Frame Duplicate Count", "sflow_5.dot11FrameDuplicateCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11RTSSuccessCount,
{ "RTS Success Count", "sflow_5.dot11RTSSuccessCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11RTSFailureCount,
{ "Failure Count", "sflow_5.dot11RTSFailureCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11ACKFailureCount,
{ "ACK Failure Count", "sflow_5.dot11ACKFailureCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11ReceivedFragmentCount,
{ "Received Fragment Count", "sflow_5.dot11ReceivedFragmentCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11MulticastReceivedFrameCount,
{ "Multicast Received Frame Count", "sflow_5.dot11MulticastReceivedFrameCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11FCSErrorCount,
{ "FCS Error Count", "sflow_5.dot11FCSErrorCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11TransmittedFrameCount,
{ "Transmitted Frame Count", "sflow_5.dot11TransmittedFrameCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11WEPUndecryptableCount,
{ "WEP Undecryptable Count", "sflow_5.dot11WEPUndecryptableCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11QoSDiscardedFragmentCount,
{ "QoS Discarded Fragment Count", "sflow_5.dot11QoSDiscardedFragmentCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11AssociatedStationCount,
{ "Associated Station Count", "sflow_5.dot11AssociatedStationCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11QoSCFPollsReceivedCount,
{ "QoS CF Polls Received Count", "sflow_5.dot11QoSCFPollsReceivedCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11QoSCFPollsUnusedCount,
{ "QoS CF Polls Unused Count", "sflow_5.dot11QoSCFPollsUnusedCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11QoSCFPollsUnusableCount,
{ "QoS CF Polls Unusable Count", "sflow_5.dot11QoSCFPollsUnusableCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_dot11QoSCFPollsLostCount,
{ "QoS CF Polls Lost Count", "sflow_5.dot11QoSCFPollsLostCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_cpu_5s,
{ "5s CPU Load (100 = 1%)", "sflow_5.cpu_5s",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Average CPU Load Over 5 Seconds (100 = 1%)", HFILL}},
{ &hf_sflow_5_cpu_1m,
{ "1m CPU Load (100 = 1%)", "sflow_5.cpu_1m",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Average CPU Load Over 1 Minute (100 = 1%)", HFILL}},
{ &hf_sflow_5_cpu_5m,
{ "5m CPU Load (100 = 1%)", "sflow_5.cpu_5m",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Average CPU Load Over 5 Minutes (100 = 1%)", HFILL}},
{ &hf_sflow_5_total_memory,
{ "Total Memory", "sflow_5.total_memory",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_free_memory,
{ "Free Memory", "sflow_5.free_memory",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sflow_5_elapsed_time,
{ "Elapsed Time (ms)", "sflow_5.elapsed_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Elapsed Time in ms", HFILL}},
{ &hf_sflow_5_on_channel_time,
{ "On Channel (ms)", "sflow_5.on_channel_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Time in ms Spent on Channel", HFILL}},
{ &hf_sflow_5_on_channel_busy_time,
{ "On Channel Busy (ms)", "sflow_5.channel_busy_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Time in ms Spent on Channel and Busy", HFILL}},
{ &hf_sflow_245_header_frame_length,
{ "Frame Length", "sflow_245.header.frame_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_header_payload_removed,
{ "Payload removed", "sflow_245.header.payload_removed",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_original_packet_header_length,
{ "Original packet length", "sflow_245.header.original_packet_header_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_extended_mpls_in_label_stack_entries,
{ "In Label Stack Entries", "sflow_245.extended_mpls.in_label_stack_entries",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_extended_mpls_in_label,
{ "Label", "sflow_245.extended_mpls.in_label",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_extended_mpls_out_label_stack_entries,
{ "Out Label Stack Entries", "sflow_245.extended_mpls.out_label_stack_entries",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_extended_mpls_out_label,
{ "Label", "sflow_245.extended_mpls.out_label",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_ethernet_length_of_mac_packet,
{ "Length of MAC Packet", "sflow_245.ethernet.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_ethernet_source_mac_address,
{ "Source MAC Address", "sflow_245.ethernet.source_mac_address",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_ethernet_destination_mac_address,
{ "Destination MAC Address", "sflow_245.ethernet.destination_mac_address",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_ethernet_packet_type,
{ "Ethernet Packet Type", "sflow_245.ethernet.packet_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_length_of_ip_packet,
{ "Length of IP Packet", "sflow_245.ip.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_ip_source_port,
{ "Source Port", "sflow_245.ip.source_port",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_ip_destination_port,
{ "Destination Port", "sflow.ip.destination_port",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_ip_tcp_flag_cwr,
{ "TCP Flag (CWR)", "sflow_245.ip.tcp_flag.cwr",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x80,
NULL, HFILL }
},
{ &hf_sflow_245_ip_tcp_flag_ece,
{ "TCP Flag (ECE)", "sflow_245.ip.tcp_flag.ece",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x40,
NULL, HFILL }
},
{ &hf_sflow_245_ip_tcp_flag_urg,
{ "TCP Flag (URG)", "sflow_245.ip.tcp_flag.urg",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x20,
NULL, HFILL }
},
{ &hf_sflow_245_ip_tcp_flag_ack,
{ "TCP Flag (ACK)", "sflow_245.ip.tcp_flag.ack",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x10,
NULL, HFILL }
},
{ &hf_sflow_245_ip_tcp_flag_psh,
{ "TCP Flag (PSH)", "sflow_245.ip.tcp_flag.psh",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x08,
NULL, HFILL }
},
{ &hf_sflow_245_ip_tcp_flag_rst,
{ "TCP Flag (RST)", "sflow_245.ip.tcp_flag.rst",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x04,
NULL, HFILL }
},
{ &hf_sflow_245_ip_tcp_flag_syn,
{ "TCP Flag (SYN)", "sflow_245.ip.tcp_flag.syn",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02,
NULL, HFILL }
},
{ &hf_sflow_245_ip_tcp_flag_fin,
{ "TCP Flag (FIN)", "sflow_245.ip.tcp_flag.fin",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x01,
NULL, HFILL }
},
{ &hf_sflow_245_ipv4_delay,
{ "Delay", "sflow_245.ipv4_delay",
FT_BOOLEAN, 8, TFS(&tfs_low_normal), 0x10,
NULL, HFILL }
},
{ &hf_sflow_245_ipv4_throughput,
{ "Throughput", "sflow_245.ipv4_throughput",
FT_BOOLEAN, 8, TFS(&tfs_high_normal), 0x08,
NULL, HFILL }
},
{ &hf_sflow_245_ipv4_reliability,
{ "Reliability", "sflow_245.ipv4_reliability",
FT_BOOLEAN, 8, TFS(&tfs_high_normal), 0x04,
NULL, HFILL }
},
{ &hf_sflow_245_ipv4_cost,
{ "Cost (RFC1349)", "sflow_245.ipv4_cost",
FT_BOOLEAN, 8, TFS(&tfs_minimize_monetary_normal), 0x02,
NULL, HFILL }
},
{ &hf_sflow_245_ipv6_priority,
{ "Priority", "sflow_245.ipv6_priority",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_user_source_character_set,
{ "Source Character Set", "sflow_5.extended_user.source_character_set",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_user_source_user_string_length,
{ "Source User String Length (bytes)", "sflow_5.extended_user.source_user_string_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_user_destination_character_set,
{ "Destination Character Set", "sflow_5.extended_user.destination_character_set",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_user_destination_user_string_length,
{ "Destination User String Length (bytes)", "sflow_5.extended_user.destination_user_string_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_url_url_length,
{ "URL Length (bytes)", "sflow_5.extended_url.url_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_url_host_length,
{ "Host Length (bytes)", "sflow_5.extended_url.host_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_mpls_tunnel_name_length,
{ "Tunnel Name Length (bytes)", "sflow_5.extended_mpls_tunnel.name_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_mpls_tunnel_id,
{ "Tunnel ID", "sflow_5.extended_mpls_tunnel.id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_mpls_tunnel_cos_value,
{ "Tunnel COS Value", "sflow_5.extended_mpls_tunnel.cos_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_mpls_vc_instance_name_length,
{ "VC Instance Name Length (bytes)", "sflow_5.extended_mpls_vc.instance_name_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_mpls_vc_id,
{ "VLL/VC ID", "sflow_5.extended_mpls_vc.id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_mpls_vc_label_cos_value,
{ "VC Label COS Value", "sflow_5.extended_mpls_vc.label_cos_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_mpls_ftn_description_length,
{ "MPLS FTN Description Length (bytes)", "sflow_5.extended_mpls.ftn_description_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_mpls_ftn_mask,
{ "MPLS FTN Mask", "sflow_5.extended_mpls.ftn_mask",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_mpls_fec_address_prefix_length,
{ "MPLS FEC Address Prefix Length (bytes)", "sflow_5.extended_mpls.fec_address_prefix_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_vlan_tunnel_number_of_layers,
{ "Number of Layers", "sflow_5.extended_vlan_tunnel.number_of_layers",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_vlan_tunnel_tpid_tci_pair,
{ "TPID/TCI Pair as Integer", "sflow_5.extended_vlan_tunnel.tpid_tci_pair",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_oui,
{ "OUI", "sflow_5.extended_80211.oui",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_suite_type,
{ "Suite Type", "sflow_5.extended_80211.suite_type",
FT_UINT8, BASE_DEC, VALS(extended_80211_suite_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_payload_length,
{ "Payload Length", "sflow_5.extended_80211.payload_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_rx_bssid,
{ "BSSID", "sflow_5.extended_80211.rx.bssid",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_rx_version,
{ "Version", "sflow_5.extended_80211.rx.version",
FT_UINT32, BASE_DEC, VALS(sflow_5_ieee80211_versions), 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_rx_channel,
{ "Channel", "sflow_5.extended_80211.rx.channel",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_rx_speed,
{ "Speed", "sflow_5.extended_80211.rx.speed",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_rx_rsni,
{ "RSNI", "sflow_5.extended_80211.rx.rsni",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_rx_rcpi,
{ "RCPI", "sflow_5.extended_80211.rx.rcpi",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_rx_packet_duration,
{ "Packet Duration (ms)", "sflow_5.extended_80211.rx.packet_duration",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_tx_bssid,
{ "BSSID", "sflow_5.extended_80211.tx.bssid",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_tx_version,
{ "Version", "sflow_5.extended_80211.tx.version",
FT_UINT32, BASE_DEC, VALS(sflow_5_ieee80211_versions), 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_tx_retransmissions,
{ "Retransmissions", "sflow_5.extended_80211.tx.retransmissions",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_tx_packet_duration,
{ "Packet Duration (ms)", "sflow_5.extended_80211.tx.packet_duration",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_tx_retransmission_duration,
{ "Retransmission Duration (ms)", "sflow_5.extended_80211.tx.retransmission_duration",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_tx_channel,
{ "Channel", "sflow_5.extended_80211.tx.channel",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_tx_speed,
{ "Speed", "sflow_5.extended_80211.tx.speed",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_tx_power,
{ "Power", "sflow_5.extended_80211.tx.power",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_sequence_number,
{ "Sequence number", "sflow.flow_sample.sequence_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_source_id_class,
{ "Source ID class", "sflow.flow_sample.source_id_class",
FT_UINT32, BASE_DEC, NULL, 0xFF000000,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_sampling_rate,
{ "Sampling rate", "sflow.flow_sample.sampling_rate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_sample_pool,
{ "Sample pool", "sflow.flow_sample.sample_pool",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_dropped_packets,
{ "Dropped packets", "sflow.flow_sample.dropped_packets",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_input_interface,
{ "Input interface (ifIndex)", "sflow.flow_sample.input_interface",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_multiple_outputs,
{ "Multiple outputs", "sflow.flow_sample.multiple_outputs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_output_interface,
{ "Output interface (ifIndex)", "sflow.flow_sample.output_interface",
FT_UINT32, BASE_DEC, NULL, 0x7fffffff,
NULL, HFILL }
},
{ &hf_sflow_enterprise,
{ "Enterprise", "sflow.enterprise",
FT_UINT32, BASE_DEC, NULL, 0xFFFFF000,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_flow_record,
{ "Flow record", "sflow.flow_sample.flow_record",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_source_id_type,
{ "Source ID type", "sflow.flow_sample.source_id_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_source_id_index,
{ "Source ID index", "sflow.flow_sample.source_id_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_input_interface_format,
{ "Input interface format", "sflow.flow_sample.input_interface_format",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_input_interface_value,
{ "Input interface value", "sflow.flow_sample.input_interface_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_output_interface_format,
{ "Output interface format", "sflow.flow_sample.output_interface_format",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_output_interface_value,
{ "Output interface value", "sflow.flow_sample.output_interface_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_counters_sample_sequence_number,
{ "Sequence number", "sflow.counters_sample.sequence_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_counters_sample_source_id_class,
{ "Source ID class", "sflow.counters_sample.source_id_class",
FT_UINT32, BASE_DEC, NULL, 0xFF000000,
NULL, HFILL }
},
{ &hf_sflow_counters_sample_sampling_interval,
{ "Sampling Interval", "sflow.counters_sample.sampling_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_counters_sample_counters_type,
{ "Counters type", "sflow.counters_sample.counters_type",
FT_UINT32, BASE_DEC, VALS(sflow_245_counterstype), 0x0,
NULL, HFILL }
},
{ &hf_sflow_counters_sample_source_id_type,
{ "Source ID type", "sflow.counters_sample.source_id_type",
FT_UINT32, BASE_DEC, NULL, 0xFF000000,
NULL, HFILL }
},
{ &hf_sflow_counters_sample_source_id_index,
{ "Source ID index", "sflow.counters_sample.source_id_index",
FT_UINT32, BASE_DEC, NULL, 0x00FFFFFF,
NULL, HFILL }
},
{ &hf_sflow_counters_sample_counters_records,
{ "Counters records", "sflow.counters_sample.counters_records",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_counters_sample_expanded_source_id_type,
{ "Source ID type", "sflow.counters_sample.source_id_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_counters_sample_expanded_source_id_index,
{ "Source ID index", "sflow.counters_sample.source_id_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_actorsystemid,
{ "Actor System ID", "sflow.lag_port.actor_system_id",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_partneropersystemid,
{ "Partner Oper System ID", "sflow.lag_port.partner_oper_system_id",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_attachedaggid,
{ "Port Attached Agg ID", "sflow.lag_port.attached_agg_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_state,
{ "State", "sflow.lag_port.state",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_actoradminstate,
{ "Actor Admin State", "sflow.lag_port.actor_admin_state",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL }
},
{ &hf_sflow_lag_port_actoroperstate,
{ "Actor Oper State", "sflow.lag_port.actor_oper_state",
FT_BOOLEAN, 32, NULL, 0x00000002,
NULL, HFILL }
},
{ &hf_sflow_lag_port_partneradminstate,
{ "Partner Admin State", "sflow.lag_port.partner_admin_state",
FT_BOOLEAN, 32, NULL, 0x00000004,
NULL, HFILL }
},
{ &hf_sflow_lag_port_partneroperstate,
{ "Partner Oper State", "sflow.lag_port.partner_oper_state",
FT_BOOLEAN, 32, NULL, 0x00000008,
NULL, HFILL }
},
{ &hf_sflow_lag_port_reserved,
{ "Reserved", "sflow.lag_port.reserved",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFF0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_stats_lacpdusrx,
{ "LACPDUs Rx", "sflow.lag_port.lacpdus.rx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_stats_markerpdusrx,
{ "Marker PDUs Rx", "sflow.lag_port.marker_pdus.rx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_stats_markerresponsepdusrx,
{ "Marker Response PDUs Rx", "sflow.lag_port.marker_response_pdus.rx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_stats_unknownrx,
{ "Unknown Rx", "sflow.lag_port.unknown.rx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_stats_illegalrx,
{ "Illegal Rx", "sflow.lag_port.illegal.rx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_stats_lacpdustx,
{ "LACPDUs Tx", "sflow.lag_port.lacpdus.tx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_stats_markerpdustx,
{ "Marker PDUs Tx", "sflow.lag_port.marker_pdus.tx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_lag_port_stats_markerresponsepdustx,
{ "Marker Response PDUs Tx", "sflow.lag_port.marker_response_pdus.tx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_as_type,
{ "AS Type", "sflow.as_type",
FT_UINT32, BASE_DEC, VALS(sflow_245_as_types), 0x0,
NULL, HFILL }
},
{ &hf_sflow_245_ip_protocol,
{ "IP Protocol", "sflow.ip_protocol",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ipproto_val_ext, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_user_source_user,
{ "Source User", "sflow_5.extended_user.source_user",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_user_destination_user,
{ "Destination User", "sflow_5.extended_user.destination_user",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_url_direction,
{ "Direction", "sflow_5.extended_url.direction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_url_url,
{ "URL", "sflow_5.extended_url.url",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_url_host,
{ "Host", "sflow_5.extended_url.host",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_mpls_tunnel_name,
{ "Tunnel Name", "sflow_5.extended_mpls_tunnel.tunnel_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_mpls_vc_instance_name,
{ "VC Instance Name", "sflow_5.extended_mpls_vc.vc_instance_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_mpls_ftn_description,
{ "MPLS FTN Description", "sflow_5.extended_mpls.ftn_description",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_payload,
{ "Payload", "sflow_5.extended_80211.payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_rx_ssid,
{ "SSID", "sflow_5.extended_80211.rx.ssid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_5_extended_80211_tx_ssid,
{ "SSID", "sflow_5.extended_80211.tx.ssid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sflow_flow_sample_index,
{ "Index", "sflow.flow_sample.index",
FT_UINT32, BASE_DEC, NULL, 0x00FFFFFF,
NULL, HFILL }
},
{ &hf_sflow_counters_sample_index,
{ "Index", "sflow.counters_sample.index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint * ett[] = {
&ett_sflow_245,
&ett_sflow_245_sample,
&ett_sflow_5_flow_record,
&ett_sflow_5_counters_record,
&ett_sflow_5_mpls_in_label_stack,
&ett_sflow_5_mpls_out_label_stack,
&ett_sflow_245_extended_data,
&ett_sflow_245_gw_as_dst,
&ett_sflow_245_gw_as_dst_seg,
&ett_sflow_245_gw_community,
&ett_sflow_245_sampled_header,
&ett_sflow_lag_port_state_flags,
};
static ei_register_info ei[] = {
{ &ei_sflow_invalid_address_type, { "sflow.invalid_address_type", PI_MALFORMED, PI_ERROR, "Unknown/invalid address type", EXPFILL }},
};
expert_module_t* expert_sflow;
proto_sflow = proto_register_protocol(
"InMon sFlow",
"sFlow",
"sflow"
);
proto_register_field_array(proto_sflow, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_sflow = expert_register_protocol(proto_sflow);
expert_register_field_array(expert_sflow, ei, array_length(ei));
header_subdissector_table = register_dissector_table("sflow_245.header_protocol", "SFLOW header protocol", proto_sflow, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
sflow_245_module = prefs_register_protocol(proto_sflow, proto_reg_handoff_sflow_245);
range_convert_str(&global_sflow_ports, SFLOW_UDP_PORTS, MAX_UDP_PORT);
prefs_register_obsolete_preference(sflow_245_module, "udp.port");
prefs_register_range_preference(sflow_245_module, "ports",
"sFlow UDP Port(s)",
"Set the port(s) for sFlow messages"
" (default: " SFLOW_UDP_PORTS ")",
&global_sflow_ports, MAX_UDP_PORT);
prefs_register_bool_preference(sflow_245_module, "enable_dissection",
"Dissect data in sampled headers",
"Enabling dissection makes it easy to view protocol details in each of the sampled headers."
" Disabling dissection may reduce noise caused when display filters match the contents of"
" any sampled header(s).",
&global_dissect_samp_headers);
prefs_register_bool_preference(sflow_245_module, "enable_analysis",
"Analyze data in sampled IP headers",
"This option only makes sense if dissection of sampled headers is enabled and probably not even then.",
&global_analyze_samp_ip_headers);
}
void
proto_reg_handoff_sflow_245(void) {
static range_t *sflow_ports;
static gboolean sflow_245_prefs_initialized = FALSE;
if (!sflow_245_prefs_initialized) {
sflow_handle = create_dissector_handle(dissect_sflow_245, proto_sflow);
sflow_245_prefs_initialized = TRUE;
} else {
dissector_delete_uint_range("udp.port", sflow_ports, sflow_handle);
g_free(sflow_ports);
}
sflow_ports = range_copy(global_sflow_ports);
dissector_add_uint_range("udp.port", sflow_ports, sflow_handle);
}
