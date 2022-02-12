static gint
dissect_sflow_245_sampled_header(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, volatile gint offset) {
guint32 version, header_proto, frame_length, stripped;
volatile guint32 header_length;
tvbuff_t *next_tvb;
proto_tree *sflow_245_header_tree;
proto_item *ti;
gboolean save_writable;
gboolean save_in_error_pkt;
address save_dl_src;
address save_dl_dst;
address save_net_src;
address save_net_dst;
address save_src;
address save_dst;
void *pd_save;
version = tvb_get_ntohl(tvb, 0);
header_proto = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_sflow_245_header_protocol, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
frame_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Frame Length: %u bytes", frame_length);
offset += 4;
if (version == 5) {
stripped = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Payload removed: %u bytes", stripped);
offset += 4;
}
header_length = tvb_get_ntohl(tvb, offset);
offset += 4;
if (header_length % 4)
header_length += 4 - (header_length % 4);
ti = proto_tree_add_item(tree, hf_sflow_245_header, tvb, offset, header_length, ENC_NA);
sflow_245_header_tree = proto_item_add_subtree(ti, ett_sflow_245_sampled_header);
next_tvb = tvb_new_subset(tvb, offset, header_length, frame_length);
save_writable = col_get_writable(pinfo->cinfo);
save_in_error_pkt = pinfo->flags.in_error_pkt;
if (!global_analyze_samp_ip_headers) {
pinfo->flags.in_error_pkt = TRUE;
}
col_set_writable(pinfo->cinfo, FALSE);
save_dl_src = pinfo->dl_src;
save_dl_dst = pinfo->dl_dst;
save_net_src = pinfo->net_src;
save_net_dst = pinfo->net_dst;
save_src = pinfo->src;
save_dst = pinfo->dst;
pd_save = pinfo->private_data;
TRY
{
switch (header_proto) {
case SFLOW_245_HEADER_ETHERNET:
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_245_HEADER_TOKENRING:
call_dissector(tr_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_245_HEADER_FDDI:
call_dissector(fddi_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_245_HEADER_FRAME_RELAY:
call_dissector(fr_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_245_HEADER_X25:
call_dissector(x25_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_245_HEADER_PPP:
call_dissector(ppp_hdlc_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_245_HEADER_SMDS:
call_dissector(smds_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_245_HEADER_AAL5:
case SFLOW_245_HEADER_AAL5_IP:
call_dissector(aal5_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_245_HEADER_IPv4:
call_dissector(ipv4_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_245_HEADER_IPv6:
call_dissector(ipv6_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_245_HEADER_MPLS:
call_dissector(mpls_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_5_HEADER_POS:
call_dissector(pos_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_5_HEADER_80211_MAC:
call_dissector(ieee80211_mac_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_5_HEADER_80211_AMPDU:
call_dissector(ieee80211_ampdu_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
case SFLOW_5_HEADER_80211_AMSDU_SUBFRAME:
call_dissector(ieee80211_amsdu_subframe_handle, next_tvb, pinfo, sflow_245_header_tree);
break;
default:
break;
}
}
CATCH_BOUNDS_ERRORS {
pinfo->private_data = pd_save;
}
ENDTRY;
col_set_writable(pinfo->cinfo, save_writable);
pinfo->flags.in_error_pkt = save_in_error_pkt;
pinfo->dl_src = save_dl_src;
pinfo->dl_dst = save_dl_dst;
pinfo->net_src = save_net_src;
pinfo->net_dst = save_net_dst;
pinfo->src = save_src;
pinfo->dst = save_dst;
offset += header_length;
return offset;
}
static gint
dissect_sflow_245_address_type(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, gint offset,
struct sflow_address_type *hf_type,
struct sflow_address_details *addr_detail) {
guint32 addr_type;
int len;
proto_item *pi;
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
pi = proto_tree_add_text(tree, tvb, offset - 4, 4, "Unknown address type (%u)", addr_type);
expert_add_info_format(pinfo, pi, PI_MALFORMED, PI_ERROR, "Unknown/invalid address type");
}
if (addr_detail) {
addr_detail->addr_type = addr_type;
switch (len) {
case 4:
tvb_memcpy(tvb, addr_detail->agent_address.v4, offset, len);
break;
case 16:
tvb_memcpy(tvb, addr_detail->agent_address.v6, offset, len);
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
struct sflow_address_type addr_type = {hf_sflow_245_nexthop_v4, hf_sflow_245_nexthop_v6};
offset = dissect_sflow_245_address_type(tvb, pinfo, tree, offset, &addr_type, NULL);
proto_tree_add_item(tree, hf_sflow_245_nexthop_src_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_nexthop_dst_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_mpls_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset) {
guint32 in_label_count, out_label_count, i, j;
proto_tree *in_stack;
proto_item *ti_in;
proto_tree *out_stack;
proto_item *ti_out;
struct sflow_address_type addr_type = {hf_sflow_245_nexthop_v4, hf_sflow_245_nexthop_v6};
offset = dissect_sflow_245_address_type(tvb, pinfo, tree, offset, &addr_type, NULL);
in_label_count = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "In Label Stack Entries: %u", in_label_count);
offset += 4;
ti_in = proto_tree_add_text(tree, tvb, offset, -1, "In Label Stack");
in_stack = proto_item_add_subtree(ti_in, ett_sflow_5_mpls_in_label_stack);
for (i = 0, j = 0; i < (in_label_count & 0x000000ff); i++, j += 4) {
proto_tree_add_text(in_stack, tvb, offset, 4, "Label %u: %u", i + 1, tvb_get_ntohl(tvb, offset + j));
}
offset = offset + in_label_count * 4;
out_label_count = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Out Label Stack Entries: %u", out_label_count);
offset += 4;
ti_out = proto_tree_add_text(tree, tvb, offset, -1, "Out Label Stack");
out_stack = proto_item_add_subtree(ti_out, ett_sflow_5_mpls_in_label_stack);
for (i = 0, j = 0; i < (out_label_count & 0x000000ff); i++, j += 4) {
proto_tree_add_text(out_stack, tvb, offset, 4, "Label %u: %u", i + 1, tvb_get_ntohl(tvb, offset + j));
}
offset = offset + out_label_count * 4;
return offset;
}
static gint
dissect_sflow_5_extended_nat(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset) {
struct sflow_address_type addr_type = {hf_sflow_245_ipv4_src,
hf_sflow_245_ipv6_src};
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
struct sflow_address_type addr_type = {hf_sflow_245_nexthop_v4, hf_sflow_245_nexthop_v6};
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
ti = proto_tree_add_text(tree, tvb, offset + len - kludge, kludge,
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
guint32 length, type;
guint64 src, dest;
length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Length of MAC Packet: %u bytes", length);
offset += 4;
src = tvb_get_ntoh64(tvb, offset) >> 16;
proto_tree_add_text(tree, tvb, offset, 8, "Source MAC Address: 0x%" G_GINT64_MODIFIER "X", src);
offset += 8;
dest = tvb_get_ntoh64(tvb, offset) >> 16;
proto_tree_add_text(tree, tvb, offset, 8, "Destination MAC Address: 0x%" G_GINT64_MODIFIER "X", dest);
offset += 8;
type = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Ethernet Packet Type: %u", type);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_ipv4(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 length, protocol, src_port, dest_port;
guint8 flags, tos;
length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Length of IP Packet: %u bytes", length);
offset += 4;
protocol = tvb_get_ntohl(tvb, offset);
switch (protocol) {
case 6:
proto_tree_add_text(tree, tvb, offset, 4, "IP Protocol: %s (%u)", "TCP", protocol);
break;
case 17:
proto_tree_add_text(tree, tvb, offset, 4, "IP Protocol: %s (%u)", "UDP", protocol);
break;
default:
proto_tree_add_text(tree, tvb, offset, 4, "IP Protocol: %u (look up against protocol numbers)", protocol);
break;
}
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ipv4_src, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ipv4_dst, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
src_port = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Source Port: %u", src_port);
offset += 4;
dest_port = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Destination Port: %u", dest_port);
offset += 4;
flags = tvb_get_guint8(tvb, offset);
flags >> 7 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (CWR): 1....... (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (CWR): 0....... (Not Set)");
(flags & 0x40) >> 6 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (ECE): .1...... (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (ECE): .0...... (Not Set)");
(flags & 0x20) >> 5 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (URG): ..1..... (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (URG): ..0..... (Not Set)");
(flags & 0x10) >> 4 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (ACK): ...1.... (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (ACK): ...0.... (Not Set)");
(flags & 0x08) >> 3 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (PSH): ....1... (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (PSH): ....0... (Not Set)");
(flags & 0x04) >> 2 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (RST): .....1.. (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (RST): .....0.. (Not Set)");
(flags & 0x02) >> 1 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (SYN): ......1. (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (SYN): ......0. (Not Set)");
flags & 0x01 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (FIN): .......1 (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (FIN): .......0 (Not Set)");
offset += 4;
tos = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "%s",
val_to_str_const(tos >> 5, sflow_245_ipv4_precedence_types, "Unknown precedence type"));
(tos & 0x10) >> 4 ?
proto_tree_add_text(tree, tvb, offset, 1, "Delay: ...1... (Low)") :
proto_tree_add_text(tree, tvb, offset, 1, "Delay: ...0... (Normal)");
(tos & 0x08) >> 3 ?
proto_tree_add_text(tree, tvb, offset, 1, "Throughput: ....1.. (High)") :
proto_tree_add_text(tree, tvb, offset, 1, "Throughput: ....0.. (Normal)");
(tos & 0x04) >> 2 ?
proto_tree_add_text(tree, tvb, offset, 1, "Reliability: .....1. (High)") :
proto_tree_add_text(tree, tvb, offset, 1, "Reliability: .....0. (Normal)");
(tos & 0x02) >> 1 ?
proto_tree_add_text(tree, tvb, offset, 1, "Cost (RFC1349): ......1 (Minimize Monetary)") :
proto_tree_add_text(tree, tvb, offset, 1, "Cost (RFC1349): ......0 (Normal)");
offset += 4;
return offset;
}
static gint
dissect_sflow_5_ipv6(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 length, protocol, src_port, dest_port, priority;
guint8 flags;
length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Length of IP Packet: %u bytes", length);
offset += 4;
protocol = tvb_get_ntohl(tvb, offset);
switch (protocol) {
case 6:
proto_tree_add_text(tree, tvb, offset, 4, "IP Protocol: %s (%u)", "TCP", protocol);
break;
case 17:
proto_tree_add_text(tree, tvb, offset, 4, "IP Protocol: %s (%u)", "UDP", protocol);
break;
default:
proto_tree_add_text(tree, tvb, offset, 4, "IP Protocol: %u (look up against protocol numbers)", protocol);
break;
}
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ipv6_src, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_sflow_245_ipv6_dst, tvb, offset, 16, ENC_NA);
offset += 16;
src_port = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Source Port: %u", src_port);
offset += 4;
dest_port = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Destination Port: %u", dest_port);
offset += 4;
flags = tvb_get_guint8(tvb, offset);
flags >> 7 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (CWR): 1....... (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (CWR): 0....... (Not Set)");
(flags & 0x40) >> 6 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (ECE): .1...... (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (ECE): .0...... (Not Set)");
(flags & 0x20) >> 5 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (URG): ..1..... (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (URG): ..0..... (Not Set)");
(flags & 0x10) >> 4 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (ACK): ...1.... (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (ACK): ...0.... (Not Set)");
(flags & 0x08) >> 3 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (PSH): ....1... (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (PSH): ....0... (Not Set)");
(flags & 0x04) >> 2 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (RST): .....1.. (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (RST): .....0.. (Not Set)");
(flags & 0x02) >> 1 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (SYN): ......1. (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (SYN): ......0. (Not Set)");
flags & 0x01 ?
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (FIN): .......1 (Set)") :
proto_tree_add_text(tree, tvb, offset, 1, "TCP Flag (FIN): .......0 (Not Set)");
offset += 4;
priority = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Priority: %u", priority);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_user(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 src_charset, src_length, dest_charset, dest_length, i;
proto_item *src;
proto_item *dest;
src_charset = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Source Character Set: %u", src_charset);
offset += 4;
src_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Source User String Length: %u bytes", src_length);
offset += 4;
src = proto_tree_add_text(tree, tvb, offset, src_length, "Source User: ");
for (i = 0; i < src_length; i++) {
proto_item_append_text(src, "%c", tvb_get_guint8(tvb, offset++));
}
if (src_length % 4)
offset = offset + (4 - src_length % 4);
dest_charset = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Destination Character Set: %u", dest_charset);
offset += 4;
dest_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Destination User String Length: %u bytes", dest_length);
offset += 4;
dest = proto_tree_add_text(tree, tvb, offset, dest_length, "Destination User: ");
for (i = 0; i < dest_length; i++) {
proto_item_append_text(dest, "%c", tvb_get_guint8(tvb, offset++));
}
if (dest_length % 4)
offset = offset + (4 - dest_length % 4);
return offset;
}
static gint
dissect_sflow_5_extended_url(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 direction, url_length, host_length, i;
proto_item *url;
proto_item *host;
direction = tvb_get_ntohl(tvb, offset);
switch (direction) {
case 1:
proto_tree_add_text(tree, tvb, offset, 4, "Source Address is Server(%u)", direction);
break;
case 2:
proto_tree_add_text(tree, tvb, offset, 4, "Destination Address is Server (%u)", direction);
break;
default:
proto_tree_add_text(tree, tvb, offset, 4, "Server Unspecified (%u)", direction);
break;
}
offset += 4;
url_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "URL Length: %u bytes", url_length);
offset += 4;
url = proto_tree_add_text(tree, tvb, offset, url_length, "URL: ");
for (i = 0; i < url_length; i++) {
proto_item_append_text(url, "%c", tvb_get_guint8(tvb, offset++));
}
if (url_length % 4)
offset = offset + (4 - url_length % 4);
host_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Host Length: %u bytes", host_length);
offset += 4;
host = proto_tree_add_text(tree, tvb, offset, host_length, "Host: ");
for (i = 0; i < host_length; i++) {
proto_item_append_text(host, "%c", tvb_get_guint8(tvb, offset++));
}
if (host_length % 4)
offset = offset + (4 - host_length % 4);
return offset;
}
static gint
dissect_sflow_5_extended_mpls_tunnel(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 name_length, id, cos, i;
proto_item *tunnel;
name_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Tunnel Name Length: %u bytes", name_length);
offset += 4;
tunnel = proto_tree_add_text(tree, tvb, offset, name_length, "Tunnel Name: ");
for (i = 0; i < name_length; i++) {
proto_item_append_text(tunnel, "%c", tvb_get_guint8(tvb, offset++));
}
if (name_length % 4)
offset = offset + (4 - name_length % 4);
id = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Tunnel ID: %u", id);
offset += 4;
cos = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Tunnel COS Value: %u", cos);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_mpls_vc(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 name_length, id, cos, i;
proto_item *vc_name;
name_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "VC Instance Name Length: %u bytes", name_length);
offset += 4;
vc_name = proto_tree_add_text(tree, tvb, offset, name_length, "VC Instance Name: ");
for (i = 0; i < name_length; i++) {
proto_item_append_text(vc_name, "%c", tvb_get_guint8(tvb, offset++));
}
if (name_length % 4)
offset = offset + (4 - name_length % 4);
id = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "VLL/VC ID: %u", id);
offset += 4;
cos = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "VC Label COS Value: %u", cos);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_mpls_fec(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 length, mask, i;
proto_item *desc;
length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "MPLS FTN Description Length: %u bytes", length);
offset += 4;
desc = proto_tree_add_text(tree, tvb, offset, length, "MPLS FTN Description: ");
for (i = 0; i < length; i++) {
proto_item_append_text(desc, "%c", tvb_get_guint8(tvb, offset++));
}
if (length % 4)
offset = offset + (4 - length % 4);
mask = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "MPLS FTN Mask: %u", mask);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_mpls_lvp_fec(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 length;
length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "MPLS FEC Address Prefix Length: %u bytes", length);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_vlan_tunnel(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 num, i, pair;
num = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Number of Layers: %u", num);
offset += 4;
for (i = 0; i < num; i++) {
pair = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "TPID/TCI Pair as Integer: %u", pair);
offset += 4;
}
return offset;
}
static gint
dissect_sflow_5_extended_80211_payload(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 cipher_suite, OUI, suite_type, length, i;
proto_item *data;
cipher_suite = tvb_get_ntohl(tvb, offset);
OUI = cipher_suite >> 8;
suite_type = cipher_suite & 0x000000ff;
if (OUI == 0x000FAC) {
proto_tree_add_text(tree, tvb, offset, 3, "OUI: Default (0x%X)", OUI);
offset += 3;
switch (suite_type) {
case 0:
proto_tree_add_text(tree, tvb, offset, 1, "Suite Type: Use group cipher suite (%u)", suite_type);
break;
case 1:
proto_tree_add_text(tree, tvb, offset, 1, "Suite Type: WEP-40 (%u)", suite_type);
break;
case 2:
proto_tree_add_text(tree, tvb, offset, 1, "Suite Type: TKIP (%u)", suite_type);
break;
case 4:
proto_tree_add_text(tree, tvb, offset, 1, "Suite Type: CCMP (%u)", suite_type);
break;
case 5:
proto_tree_add_text(tree, tvb, offset, 1, "Suite Type: WEP-104 (%u)", suite_type);
break;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Suite Type: Reserved (%u)", suite_type);
break;
}
} else {
proto_tree_add_text(tree, tvb, offset, 3, "OUI: Other vender (0x%X)", OUI);
offset += 3;
proto_tree_add_text(tree, tvb, offset, 1, "Suite Type: Vender specific (%u)", suite_type);
}
offset++;
length = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Payload Length: %u bytes", length);
offset += 4;
data = proto_tree_add_text(tree, tvb, offset, length, "Payload: 0x");
for (i = 0; i < length; i++) {
proto_item_append_text(data, "%X", tvb_get_guint8(tvb, offset++));
}
if (length % 4)
offset = offset + (4 - length % 4);
return offset;
}
static gint
dissect_sflow_5_extended_80211_rx(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 ssid_length, i, version, channel, rsni, rcpi, duration;
guint64 bssid, speed;
proto_item *ssid;
ssid_length = tvb_get_ntohl(tvb, offset);
offset += 4;
ssid = proto_tree_add_text(tree, tvb, offset, ssid_length, "SSID: ");
for (i = 0; i < ssid_length; i++) {
proto_item_append_text(ssid, "%c", tvb_get_guint8(tvb, offset++));
}
if (ssid_length % 4)
offset = offset + (4 - ssid_length % 4);
bssid = tvb_get_ntoh64(tvb, offset) >> 16;
proto_tree_add_text(tree, tvb, offset, 8, "BSSID: 0x%" G_GINT64_MODIFIER "X", bssid);
offset += 8;
version = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Version: %s",
val_to_str_const(version, sflow_5_ieee80211_versions, "Unknown"));
offset += 4;
channel = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Channel: %u", channel);
offset += 4;
speed = tvb_get_ntoh64(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 8, "Speed: %" G_GINT64_MODIFIER "u", speed);
offset += 8;
rsni = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "RSNI: %u", rsni);
offset += 4;
rcpi = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "RCPI: %u", rcpi);
offset += 4;
duration = tvb_get_ntohl(tvb, offset);
duration == 0 ?
proto_tree_add_text(tree, tvb, offset, 4, "Packet Duration: Unknown") :
proto_tree_add_text(tree, tvb, offset, 4, "Packet Duration: %u (ms)", duration);
offset += 4;
return offset;
}
static gint
dissect_sflow_5_extended_80211_tx(tvbuff_t *tvb, proto_tree *tree, gint offset) {
guint32 ssid_length, version, transmissions, packet_duration, retrans_duration,
channel, power, i;
guint64 bssid, speed;
proto_item *ssid;
ssid_length = tvb_get_ntohl(tvb, offset);
if (ssid_length > 32)
ssid_length = 32;
offset += 4;
ssid = proto_tree_add_text(tree, tvb, offset, ssid_length, "SSID: ");
for (i = 0; i < ssid_length; i++) {
proto_item_append_text(ssid, "%c", tvb_get_guint8(tvb, offset++));
}
if (ssid_length % 4)
offset = offset + (4 - ssid_length % 4);
bssid = tvb_get_ntoh64(tvb, offset) >> 16;
proto_tree_add_text(tree, tvb, offset, 8, "BSSID: 0x%" G_GINT64_MODIFIER "X", bssid);
offset += 8;
version = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Version: %s",
val_to_str_const(version, sflow_5_ieee80211_versions, "Unknown"));
offset += 4;
transmissions = tvb_get_ntohl(tvb, offset);
switch (transmissions) {
case 0:
proto_tree_add_text(tree, tvb, offset, 4, "Retransmission: Unknown");
break;
case 1:
proto_tree_add_text(tree, tvb, offset, 4,
"Retransmission: Packet transmitted sucessfully on first attempt");
break;
default:
proto_tree_add_text(tree, tvb, offset, 4, "Retransmissions: %u", transmissions - 1);
break;
}
offset += 4;
packet_duration = tvb_get_ntohl(tvb, offset);
packet_duration == 0 ?
proto_tree_add_text(tree, tvb, offset, 4, "Packet Duration: Unknown") :
proto_tree_add_text(tree, tvb, offset, 4, "Packet Duration: %u (ms)", packet_duration);
offset += 4;
retrans_duration = tvb_get_ntohl(tvb, offset);
retrans_duration == 0 ?
proto_tree_add_text(tree, tvb, offset, 4, "Retransmission Duration: Unknown") :
proto_tree_add_text(tree, tvb, offset, 4, "Retransmission Duration: %u (ms)", retrans_duration);
offset += 4;
channel = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Channel: %u", channel);
offset += 4;
speed = tvb_get_ntoh64(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 8, "Speed: %" G_GINT64_MODIFIER "u", speed);
offset += 8;
power = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Power: %u (mW)", power);
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
struct sflow_24_flow_sample_header flow_header;
proto_tree *extended_data_tree;
proto_item *ti;
guint32 packet_type, extended_data, ext_type, i, output;
tvb_memcpy(tvb, (guint8 *) & flow_header, offset, sizeof (flow_header));
proto_tree_add_text(tree, tvb, offset, 4,
"Sequence number: %u", g_ntohl(flow_header.sequence_number));
proto_item_append_text(parent, ", seq %u", g_ntohl(flow_header.sequence_number));
proto_tree_add_text(tree, tvb, offset + 4, 4,
"Source ID class: %u index: %u",
g_ntohl(flow_header.source_id) >> 24,
g_ntohl(flow_header.source_id) & 0x00ffffff);
proto_tree_add_text(tree, tvb, offset + 8, 4,
"Sampling rate: 1 out of %u packets",
g_ntohl(flow_header.sampling_rate));
proto_tree_add_text(tree, tvb, offset + 12, 4,
"Sample pool: %u total packets",
g_ntohl(flow_header.sample_pool));
proto_tree_add_text(tree, tvb, offset + 16, 4,
"Dropped packets: %u",
g_ntohl(flow_header.drops));
proto_tree_add_text(tree, tvb, offset + 20, 4,
"Input interface: ifIndex %u",
g_ntohl(flow_header.input));
output = g_ntohl(flow_header.output);
if (output >> 31) {
output & 0x7fffffff ?
proto_tree_add_text(tree, tvb, offset + 24, 4,
"Multiple outputs: %u interfaces", output & 0x7fffffff) :
proto_tree_add_text(tree, tvb, offset + 24, 4,
"Multiple outputs: unknown number");
} else {
proto_tree_add_text(tree, tvb, offset + 24, 4,
"Output interface: ifIndex %u", output & 0x7fffffff);
}
offset += (int)sizeof (flow_header);
packet_type = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_sflow_245_packet_information_type, tvb, offset, 4, packet_type);
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
ti = proto_tree_add_text(tree, tvb, offset, -1, "%s",
val_to_str_const(ext_type, sflow_245_extended_data_types, "Unknown extended information"));
extended_data_tree = proto_item_add_subtree(ti, ett_sflow_245_extended_data);
proto_tree_add_uint(extended_data_tree, hf_sflow_245_extended_information_type, tvb, offset, 4, ext_type);
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
ti = proto_tree_add_text(tree, tvb, offset, -1, "%s",
val_to_str_const(format, sflow_5_flow_record_type, "Unknown sample format"));
flow_data_tree = proto_item_add_subtree(ti, ett_sflow_5_flow_record);
proto_tree_add_text(flow_data_tree, tvb, offset, 4, "Enterprise: standard sFlow (%u)", enterprise);
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
ti = proto_tree_add_text(tree, tvb, offset, -1, "Unknown enterprise format");
flow_data_tree = proto_item_add_subtree(ti, ett_sflow_5_flow_record);
proto_tree_add_text(flow_data_tree, tvb, offset, -1, "Enterprise: Non-standard sFlow (%u)", enterprise);
}
proto_item_set_end(ti, tvb, offset);
return offset;
}
static gint
dissect_sflow_5_generic_interface(proto_tree *counter_data_tree, tvbuff_t *tvb, gint offset) {
struct if_counters ifc;
tvb_memcpy(tvb, (guint8 *) & ifc, offset, sizeof (ifc));
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifindex, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_iftype, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(counter_data_tree, hf_sflow_245_ifspeed, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
switch (tvb_get_ntohl(tvb, offset)) {
case 1:
proto_tree_add_text(counter_data_tree, tvb, offset, 4, "IfDirection: Full-Duplex");
break;
case 2:
proto_tree_add_text(counter_data_tree, tvb, offset, 4, "IfDirection: Half-Duplex");
break;
case 3:
proto_tree_add_text(counter_data_tree, tvb, offset, 4, "IfDirection: In");
break;
case 4:
proto_tree_add_text(counter_data_tree, tvb, offset, 4, "IfDirection: Out");
break;
default:
proto_tree_add_text(counter_data_tree, tvb, offset, 4, "IfDirection: Unknown");
break;
}
offset += 4;
if (tvb_get_ntohl(tvb, offset)&0x00000001) {
proto_tree_add_text(counter_data_tree, tvb, offset, 4, "IfAdminStatus: Up");
} else {
proto_tree_add_text(counter_data_tree, tvb, offset, 4, "IfAdminStatus: Down");
}
if (tvb_get_ntohl(tvb, offset)&0x00000002) {
proto_tree_add_text(counter_data_tree, tvb, offset, 4, "IfOperStatus: Up");
} else {
proto_tree_add_text(counter_data_tree, tvb, offset, 4, "IfOperStatus: Down");
}
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
struct ethernet_counters ethc;
tvb_memcpy(tvb, (guint8 *) & ethc, offset, sizeof (ethc));
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
struct token_ring_counters tokc;
tvb_memcpy(tvb, (guint8 *) & tokc, offset, sizeof (tokc));
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
struct vg_counters vgc;
tvb_memcpy(tvb, (guint8 *) & vgc, offset, sizeof (vgc));
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
struct vlan_counters vlanc;
tvb_memcpy(tvb, (guint8 *) & vlanc, offset, sizeof (vlanc));
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
struct ieee80211_if_counters ieee80211;
tvb_memcpy(tvb, (guint8 *) & ieee80211, offset, sizeof (ieee80211));
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
struct processor proc;
tvb_memcpy(tvb, (guint8 *) & proc, offset, sizeof (proc));
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
struct radio_utilization radio;
tvb_memcpy(tvb, (guint8 *) & radio, offset, sizeof (radio));
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
ti = proto_tree_add_text(tree, tvb, offset, -1, "%s",
val_to_str_const(format, sflow_5_counters_record_type, "Unknown sample format"));
counter_data_tree = proto_item_add_subtree(ti, ett_sflow_5_counters_record);
proto_tree_add_text(counter_data_tree, tvb, offset, 4, "Enterprise: standard sFlow (%u)", enterprise);
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
ti = proto_tree_add_text(tree, tvb, offset, -1, "%s", "Unknown enterprise format");
counter_data_tree = proto_item_add_subtree(ti, ett_sflow_5_counters_record);
proto_tree_add_text(counter_data_tree, tvb, offset, -1, "Enterprise: Non-standard sFlow (%u)", enterprise);
}
proto_item_set_end(ti, tvb, offset);
return offset;
}
static void
dissect_sflow_5_flow_sample(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, gint offset, proto_item *parent) {
struct sflow_5_flow_sample_header flow_header;
guint32 i, output;
tvb_memcpy(tvb, (guint8 *) & flow_header, offset, sizeof (flow_header));
proto_tree_add_text(tree, tvb, offset, 4,
"Sequence number: %u", g_ntohl(flow_header.sequence_number));
offset += 4;
proto_item_append_text(parent, ", seq %u", g_ntohl(flow_header.sequence_number));
proto_tree_add_text(tree, tvb, offset, 4,
"Source ID class: %u index: %u",
g_ntohl(flow_header.source_id) >> 24,
g_ntohl(flow_header.source_id) & 0x00ffffff);
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Sampling rate: 1 out of %u packets",
g_ntohl(flow_header.sampling_rate));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Sample pool: %u total packets",
g_ntohl(flow_header.sample_pool));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Dropped packets: %u",
g_ntohl(flow_header.drops));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Input interface: ifIndex %u",
g_ntohl(flow_header.input));
offset += 4;
output = g_ntohl(flow_header.output);
if (output >> 31) {
output & 0x7fffffff ?
proto_tree_add_text(tree, tvb, offset, 4,
"Multiple outputs: %u interfaces", output & 0x7fffffff) :
proto_tree_add_text(tree, tvb, offset, 4,
"Multiple outputs: unknown number");
} else {
proto_tree_add_text(tree, tvb, offset, 4,
"Output interface: ifIndex %u", output & 0x7fffffff);
}
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Flow record: %u",
g_ntohl(flow_header.records));
offset += 4;
for (i = 0; i < (g_ntohl(flow_header.records)&0x000000ff); i++) {
offset = dissect_sflow_5_flow_record(tvb, pinfo, tree, offset);
}
}
static void
dissect_sflow_5_expanded_flow_sample(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, gint offset, proto_item *parent) {
struct sflow_5_expanded_flow_sample_header flow_header;
guint32 i;
tvb_memcpy(tvb, (guint8 *) & flow_header, offset, sizeof (flow_header));
proto_tree_add_text(tree, tvb, offset, 4,
"Sequence number: %u", g_ntohl(flow_header.sequence_number));
offset += 4;
proto_item_append_text(parent, ", seq %u", g_ntohl(flow_header.sequence_number));
proto_tree_add_text(tree, tvb, offset, 4,
"Source ID type: %u",
g_ntohl(flow_header.source_id_type));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Source ID index: %u",
g_ntohl(flow_header.source_id_index));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Sampling rate: 1 out of %u packets",
g_ntohl(flow_header.sampling_rate));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Sample pool: %u total packets",
g_ntohl(flow_header.sample_pool));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Dropped packets: %u",
g_ntohl(flow_header.drops));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Input interface format: %u",
g_ntohl(flow_header.input_format));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Input interface value: %u",
g_ntohl(flow_header.input_value));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Output interface format: %u",
g_ntohl(flow_header.output_format));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Output interface value: %u",
g_ntohl(flow_header.output_value));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4,
"Flow record: %u",
g_ntohl(flow_header.records));
offset += 4;
for (i = 0; i < (g_ntohl(flow_header.records)&0x000000ff); i++) {
offset = dissect_sflow_5_flow_record(tvb, pinfo, tree, offset);
}
}
static gint
dissect_sflow_24_counters_sample(tvbuff_t *tvb, proto_tree *tree, gint offset, proto_item *parent) {
struct sflow_24_counters_sample_header counters_header;
struct if_counters ifc;
struct ethernet_counters ethc;
struct token_ring_counters tokc;
struct vg_counters vgc;
struct vlan_counters vlanc;
tvb_memcpy(tvb, (guint8 *) & counters_header, offset, sizeof (counters_header));
proto_tree_add_text(tree, tvb, offset, 4,
"Sequence number: %u",
g_ntohl(counters_header.sequence_number));
proto_item_append_text(parent, ", seq %u", g_ntohl(counters_header.sequence_number));
proto_tree_add_text(tree, tvb, offset + 4, 4,
"Source ID class: %u index: %u",
g_ntohl(counters_header.source_id) >> 24,
g_ntohl(counters_header.source_id) & 0x00ffffff);
proto_tree_add_text(tree, tvb, offset + 8, 4,
"Sampling Interval: %u",
g_ntohl(counters_header.sampling_interval));
proto_tree_add_text(tree, tvb, offset + 12, 4, "Counters type: %s",
val_to_str_const(g_ntohl(counters_header.counters_type),
sflow_245_counterstype, "Unknown type"));
offset += (int)sizeof (counters_header);
switch (g_ntohl(counters_header.counters_type)) {
case SFLOW_245_COUNTERS_GENERIC:
case SFLOW_245_COUNTERS_ETHERNET:
case SFLOW_245_COUNTERS_TOKENRING:
case SFLOW_245_COUNTERS_FDDI:
case SFLOW_245_COUNTERS_VG:
case SFLOW_245_COUNTERS_WAN:
tvb_memcpy(tvb, (guint8 *) & ifc, offset, sizeof (ifc));
proto_item_append_text(parent, ", ifIndex %u", g_ntohl(ifc.ifIndex));
proto_tree_add_item(tree, hf_sflow_245_ifindex, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_iftype, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_sflow_245_ifspeed, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
switch (tvb_get_ntohl(tvb, offset)) {
case 1:
proto_tree_add_text(tree, tvb, offset, 4, "IfDirection: Full-Duplex");
break;
case 2:
proto_tree_add_text(tree, tvb, offset, 4, "IfDirection: Half-Duplex");
break;
case 3:
proto_tree_add_text(tree, tvb, offset, 4, "IfDirection: In");
break;
case 4:
proto_tree_add_text(tree, tvb, offset, 4, "IfDirection: Out");
break;
default:
proto_tree_add_text(tree, tvb, offset, 4, "IfDirection: Unknown");
break;
}
offset += 4;
if (tvb_get_ntohl(tvb, offset)&0x00000001) {
proto_tree_add_text(tree, tvb, offset, 4, "IfAdminStatus: Up");
} else {
proto_tree_add_text(tree, tvb, offset, 4, "IfAdminStatus: Down");
}
if (tvb_get_ntohl(tvb, offset)&0x00000002) {
proto_tree_add_text(tree, tvb, offset, 4, "IfOperStatus: Up");
} else {
proto_tree_add_text(tree, tvb, offset, 4, "IfOperStatus: Down");
}
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
switch (g_ntohl(counters_header.counters_type)) {
case SFLOW_245_COUNTERS_ETHERNET:
tvb_memcpy(tvb, (guint8 *) & ethc, offset, sizeof (ethc));
offset += (int)sizeof (ethc);
break;
case SFLOW_245_COUNTERS_TOKENRING:
tvb_memcpy(tvb, (guint8 *) & tokc, offset, sizeof (tokc));
offset += (int)sizeof (tokc);
break;
case SFLOW_245_COUNTERS_VG:
tvb_memcpy(tvb, (guint8 *) & vgc, offset, sizeof (vgc));
offset += (int)sizeof (vgc);
break;
case SFLOW_245_COUNTERS_VLAN:
tvb_memcpy(tvb, (guint8 *) & vlanc, offset, sizeof (vlanc));
offset += (int)sizeof (vlanc);
break;
default:
break;
}
return offset;
}
static void
dissect_sflow_5_counters_sample(tvbuff_t *tvb, proto_tree *tree, gint offset, proto_item *parent) {
struct sflow_5_counters_sample_header counters_header;
guint32 i;
tvb_memcpy(tvb, (guint8 *) & counters_header, offset, sizeof (counters_header));
proto_tree_add_text(tree, tvb, offset, 4, "Sequence number: %u", g_ntohl(counters_header.sequence_number));
proto_item_append_text(parent, ", seq %u", g_ntohl(counters_header.sequence_number));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4, "Source ID type: %u", g_ntohl(counters_header.source_id) >> 24);
proto_tree_add_text(tree, tvb, offset, 4, "Source ID index: %u", g_ntohl(counters_header.source_id) & 0x00ffffff);
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4, "Counters records: %u", g_ntohl(counters_header.records));
offset += 4;
for (i = 0; i < (g_ntohl(counters_header.records)&0x000000ff); i++) {
offset = dissect_sflow_5_counters_record(tvb, tree, offset);
}
}
static void
dissect_sflow_5_expanded_counters_sample(tvbuff_t *tvb, proto_tree *tree, gint offset, proto_item *parent) {
struct sflow_5_expanded_counters_sample_header counters_header;
guint32 i;
tvb_memcpy(tvb, (guint8 *) & counters_header, offset, sizeof (counters_header));
proto_tree_add_text(tree, tvb, offset, 4, "Sequence number: %u", g_ntohl(counters_header.sequence_number));
proto_item_append_text(parent, ", seq %u", g_ntohl(counters_header.sequence_number));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4, "Source ID type: %u", g_ntohl(counters_header.source_id_type));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4, "Source ID index: %u", g_ntohl(counters_header.source_id_index));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4, "Counters records: %u", g_ntohl(counters_header.records));
offset += 4;
for (i = 0; i < (g_ntohl(counters_header.records)&0x000000ff); i++) {
offset = dissect_sflow_5_counters_record(tvb, tree, offset);
}
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
ti = proto_tree_add_text(tree, tvb, offset, -1, "%s",
val_to_str_const(format, sflow_245_sampletype, "Unknown sample format"));
sflow_245_sample_tree = proto_item_add_subtree(ti, ett_sflow_245_sample);
proto_tree_add_text(sflow_245_sample_tree, tvb, offset, 4, "Enterprise: standard sFlow (%u)", enterprise);
proto_tree_add_item(sflow_245_sample_tree, hf_sflow_245_sampletype, tvb, offset, 4, ENC_BIG_ENDIAN);
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
default:
break;
}
tvb_ensure_bytes_exist(tvb, offset, length);
offset += length;
} else {
ti = proto_tree_add_text(tree, tvb, offset, -1, "%s", "Unknown enterprise format");
sflow_245_sample_tree = proto_item_add_subtree(ti, ett_sflow_245_sample);
proto_tree_add_text(sflow_245_sample_tree, tvb, offset, -1, "Enterprise: Non-standard sFlow (%u)", enterprise);
}
} else {
ti = proto_tree_add_text(tree, tvb, offset, -1, "%s",
val_to_str_const(sample_type, sflow_245_sampletype, "Unknown sample type"));
sflow_245_sample_tree = proto_item_add_subtree(ti, ett_sflow_245_sample);
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
struct sflow_address_details addr_details;
struct sflow_address_type addr_type = {hf_sflow_agent_address_v4, hf_sflow_agent_address_v6};
guint32 numsamples;
volatile guint offset = 0;
guint i = 0;
version = tvb_get_ntohl(tvb, offset);
if (version != 2 && version != 4 && version != 5) {
return 0;
}
addr_details.addr_type = tvb_get_ntohl(tvb, offset + 4);
switch (addr_details.addr_type) {
case ADDR_TYPE_UNKNOWN:
case ADDR_TYPE_IPV4:
case ADDR_TYPE_IPV6:
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
offset = dissect_sflow_245_address_type(tvb, pinfo, sflow_245_tree, offset,
&addr_type, &addr_details);
switch (addr_details.addr_type) {
case ADDR_TYPE_UNKNOWN:
break;
case ADDR_TYPE_IPV4:
col_append_fstr(pinfo->cinfo, COL_INFO, ", agent %s", ip_to_str(addr_details.agent_address.v4));
break;
case ADDR_TYPE_IPV6:
col_append_fstr(pinfo->cinfo, COL_INFO, ", agent %s",
ip6_to_str((struct e_in6_addr *) addr_details.agent_address.v6));
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
return tvb_length(tvb);
}
void
proto_register_sflow(void) {
module_t *sflow_245_module;
static hf_register_info hf[] = {
{ &hf_sflow_version,
{ "Datagram version", "sflow_245.version",
FT_UINT32, BASE_DEC, NULL, 0x0,
"sFlow datagram version", HFILL}},
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
#if 0
{ &hf_sflow_5_ieee80211_version,
{ "Version", "sflow_245.ieee80211_version",
FT_UINT32, BASE_DEC, VALS(sflow_5_ieee80211_versions), 0x0,
"IEEE 802.11 Version", HFILL}},
#endif
#if 0
{ &hf_sflow_245_ipv4_precedence_type,
{ "Precedence", "sflow_245.ipv4_precedence_type",
FT_UINT8, BASE_DEC, VALS(sflow_245_ipv4_precedence_types), 0x0,
"IPv4 Precedence Type", HFILL}},
#endif
{ &hf_sflow_5_flow_record_format,
{ "Format", "sflow_245.flow_record_format",
FT_UINT32, BASE_DEC, VALS(sflow_5_flow_record_type), 0x0,
"Format of sFlow flow record", HFILL}},
{ &hf_sflow_5_counters_record_format,
{ "Format", "sflow_245.counters_record_format",
FT_UINT32, BASE_DEC, VALS(sflow_5_counters_record_type), 0x0,
"Format of sFlow counters record", HFILL}},
{ &hf_sflow_245_header_protocol,
{ "Header protocol", "sflow_245.header_protocol",
FT_UINT32, BASE_DEC, VALS(sflow_245_header_protocol), 0x0,
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
{ "Next hop", "sflow_245.nexthop",
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
#if 0
{ &hf_sflow_245_ifdirection,
{ "Interface Direction", "sflow_245.ifdirection",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
#endif
#if 0
{ &hf_sflow_245_ifstatus,
{ "Interface Status", "sflow_245.ifstatus",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
#endif
{ &hf_sflow_245_ifinoct,
{ "Input Octets", "sflow_245.ifinoct",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Interface Input Octets", HFILL}},
{ &hf_sflow_245_ifinpkt,
{ "Input Packets", "sflow_245.ifinpkt",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface Input Packets", HFILL}},
{ &hf_sflow_245_ifinmcast,
{ "Input Multicast Packets", "sflow_245.ifinmcast",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface Input Multicast Packets", HFILL}},
{ &hf_sflow_245_ifinbcast,
{ "Input Broadcast Packets", "sflow_245.ifinbcast",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface Input Broadcast Packets", HFILL}},
{ &hf_sflow_245_ifindisc,
{ "Input Discarded Packets", "sflow_245.ifindisc",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface Input Discarded Packets", HFILL}},
{ &hf_sflow_245_ifinerr,
{ "Input Errors", "sflow_245.ifinerr",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface Input Errors", HFILL}},
{ &hf_sflow_245_ifinunk,
{ "Input Unknown Protocol Packets", "sflow_245.ifinunk",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface Input Unknown Protocol Packets", HFILL}},
{ &hf_sflow_245_ifoutoct,
{ "Output Octets", "sflow_245.ifoutoct",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Outterface Output Octets", HFILL}},
{ &hf_sflow_245_ifoutpkt,
{ "Output Packets", "sflow_245.ifoutpkt",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface Output Packets", HFILL}},
{ &hf_sflow_245_ifoutmcast,
{ "Output Multicast Packets", "sflow_245.ifoutmcast",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface Output Multicast Packets", HFILL}},
{ &hf_sflow_245_ifoutbcast,
{ "Output Broadcast Packets", "sflow_245.ifoutbcast",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface Output Broadcast Packets", HFILL}},
{ &hf_sflow_245_ifoutdisc,
{ "Output Discarded Packets", "sflow_245.ifoutdisc",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface Output Discarded Packets", HFILL}},
{ &hf_sflow_245_ifouterr,
{ "Output Errors", "sflow_245.ifouterr",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface Output Errors", HFILL}},
{ &hf_sflow_245_ifpromisc,
{ "Promiscuous Mode", "sflow_245.ifpromisc",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface Promiscuous Mode", HFILL}},
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
};
proto_sflow = proto_register_protocol(
"InMon sFlow",
"sFlow",
"sflow"
);
proto_register_field_array(proto_sflow, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
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
"Enabling dissection makes it easy to view protocol details in each of the sampled headers. Disabling dissection may reduce noise caused when display filters match the contents of any sampled header(s).",
&global_dissect_samp_headers);
prefs_register_bool_preference(sflow_245_module, "enable_analysis",
"Analyze data in sampled IP headers",
"This option only makes sense if dissection of sampled headers is enabled and probably not even then.",
&global_analyze_samp_ip_headers);
}
static void
sflow_245_delete_callback(guint32 port) {
if (port) {
dissector_delete_uint("udp.port", port, sflow_handle);
}
}
static void
sflow_245_add_callback(guint32 port) {
if (port) {
dissector_add_uint("udp.port", port, sflow_handle);
}
}
void
proto_reg_handoff_sflow_245(void) {
static range_t *sflow_ports;
static gboolean sflow_245_prefs_initialized = FALSE;
if (!sflow_245_prefs_initialized) {
sflow_handle = new_create_dissector_handle(dissect_sflow_245, proto_sflow);
data_handle = find_dissector("data");
sflow_245_prefs_initialized = TRUE;
} else {
range_foreach(sflow_ports, sflow_245_delete_callback);
g_free(sflow_ports);
}
sflow_ports = range_copy(global_sflow_ports);
range_foreach(sflow_ports, sflow_245_add_callback);
if (global_dissect_samp_headers) {
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
tr_handle = find_dissector("tr");
fddi_handle = find_dissector("fddi");
fr_handle = find_dissector("fr");
x25_handle = find_dissector("x.25");
ppp_hdlc_handle = find_dissector("ppp_hdlc");
#if 0
smds_handle = find_dissector("smds");
#else
smds_handle = data_handle;
#endif
#if 0
aal5_handle = find_dissector("aal5");
#else
aal5_handle = data_handle;
#endif
ipv4_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
mpls_handle = find_dissector("mpls");
#if 0
pos_handle = find_dissector("pos");
#else
pos_handle = data_handle;
#endif
ieee80211_mac_handle = find_dissector("wlan");
#if 0
ieee80211_ampdu_handle = find_dissector("ampdu");
ieee80211_amsdu_subframe_handle = find_dissector("wlan_aggregate");
#else
ieee80211_ampdu_handle = data_handle;
ieee80211_amsdu_subframe_handle = data_handle;
#endif
} else {
eth_withoutfcs_handle = data_handle;
tr_handle = data_handle;
fddi_handle = data_handle;
fr_handle = data_handle;
x25_handle = data_handle;
ppp_hdlc_handle = data_handle;
smds_handle = data_handle;
aal5_handle = data_handle;
ipv4_handle = data_handle;
ipv6_handle = data_handle;
mpls_handle = data_handle;
pos_handle = data_handle;
ieee80211_mac_handle = data_handle;
ieee80211_ampdu_handle = data_handle;
ieee80211_amsdu_subframe_handle = data_handle;
}
}
