static void
save_link_state_protocol_id(packet_info *pinfo, guint8 protocol_id) {
link_state_data *data =
(link_state_data*)p_get_proto_data(pinfo->pool, pinfo, proto_bgp, LINK_STATE_DATA_KEY);
if (!data) {
data = wmem_new0(pinfo->pool, link_state_data);
data->ostart = -1;
data->oend = -1;
data->tlen = 0;
data->link_state_attr_present = FALSE;
data->subtree2 = NULL;
}
data->protocol_id = protocol_id;
p_add_proto_data(pinfo->pool, pinfo, proto_bgp, LINK_STATE_DATA_KEY, data);
return;
}
static void
save_link_state_attr_position(packet_info *pinfo, gint ostart, gint oend, guint16 tlen, proto_tree *subtree2) {
link_state_data *data =
(link_state_data*)p_get_proto_data(pinfo->pool, pinfo, proto_bgp, LINK_STATE_DATA_KEY);
if (!data) {
data = wmem_new0(pinfo->pool, link_state_data);
data->protocol_id = BGP_LS_NLRI_PROTO_ID_UNKNOWN;
}
data->ostart = ostart;
data->oend = oend;
data->tlen = tlen;
data->link_state_attr_present = TRUE;
data->subtree2 = subtree2;
p_add_proto_data(pinfo->pool, pinfo, proto_bgp, LINK_STATE_DATA_KEY, data);
return;
}
static link_state_data*
load_link_state_data(packet_info *pinfo) {
link_state_data *data =
(link_state_data*)p_get_proto_data(pinfo->pool, pinfo, proto_bgp, LINK_STATE_DATA_KEY);
return data;
}
static int
detect_add_path_prefix4(tvbuff_t *tvb, gint offset, gint end) {
guint32 addr_len;
guint8 prefix_len;
gint o;
for (o = offset + 4; o < end; o += 4) {
prefix_len = tvb_get_guint8(tvb, o);
if( prefix_len > 32) {
return 0;
}
addr_len = (prefix_len + 7) / 8;
o += 1 + addr_len;
if( o > end ) {
return 0;
}
if (prefix_len % 8) {
if( tvb_get_guint8(tvb, o - 1 ) & (0xFF >> (prefix_len % 8)) ) {
return 0;
}
}
}
for (o = offset; o < end; ) {
prefix_len = tvb_get_guint8(tvb, o);
if( prefix_len == 0 && end - offset > 1 ) {
return 1;
}
if( prefix_len > 32) {
return 1;
}
addr_len = (prefix_len + 7) / 8;
o += 1 + addr_len;
if( o > end ) {
return 1;
}
if (prefix_len % 8) {
if( tvb_get_guint8(tvb, o - 1 ) & (0xFF >> (prefix_len % 8)) ) {
return 1;
}
}
}
return 0;
}
static int
decode_path_prefix4(proto_tree *tree, packet_info *pinfo, int hf_path_id, int hf_addr, tvbuff_t *tvb, gint offset,
const char *tag)
{
proto_tree *prefix_tree;
union {
guint8 addr_bytes[4];
guint32 addr;
} ip_addr;
guint8 plen;
int length;
guint32 path_identifier;
address addr;
path_identifier = tvb_get_ntohl(tvb, offset);
plen = tvb_get_guint8(tvb, offset + 4);
length = tvb_get_ipv4_addr_with_prefix_len(tvb, offset + 4 + 1, ip_addr.addr_bytes, plen);
if (length < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_length_invalid, tvb, offset + 4 , 1, "%s length %u invalid (> 32)",
tag, plen);
return -1;
}
set_address(&addr, AT_IPv4, 4, ip_addr.addr_bytes);
prefix_tree = proto_tree_add_subtree_format(tree, tvb, offset, 4 + 1 + length,
ett_bgp_prefix, NULL, "%s/%u PathId %u ",
address_to_str(wmem_packet_scope(), &addr), plen, path_identifier);
proto_tree_add_item(prefix_tree, hf_path_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(prefix_tree, hf_bgp_prefix_length, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_ipv4(prefix_tree, hf_addr, tvb, offset + 4 + 1, length, ip_addr.addr);
return(4 + 1 + length);
}
static int
decode_prefix4(proto_tree *tree, packet_info *pinfo, proto_item *parent_item, int hf_addr, tvbuff_t *tvb, gint offset,
guint16 tlen, const char *tag)
{
proto_tree *prefix_tree;
union {
guint8 addr_bytes[4];
guint32 addr;
} ip_addr;
guint8 plen;
int length;
address addr;
plen = tvb_get_guint8(tvb, offset);
length = tvb_get_ipv4_addr_with_prefix_len(tvb, offset + 1, ip_addr.addr_bytes, plen);
if (length < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_length_invalid, tvb, offset, 1, "%s length %u invalid (> 32)",
tag, plen);
return -1;
}
set_address(&addr, AT_IPv4, 4, ip_addr.addr_bytes);
prefix_tree = proto_tree_add_subtree_format(tree, tvb, offset,
tlen != 0 ? tlen : 1 + length, ett_bgp_prefix, NULL,
"%s/%u", address_to_str(wmem_packet_scope(), &addr), plen);
proto_item_append_text(parent_item, " (%s/%u)",
address_to_str(wmem_packet_scope(), &addr), plen);
proto_tree_add_uint_format(prefix_tree, hf_bgp_prefix_length, tvb, offset, 1, plen, "%s prefix length: %u",
tag, plen);
proto_tree_add_ipv4(prefix_tree, hf_addr, tvb, offset + 1, length,
ip_addr.addr);
return(1 + length);
}
static int
decode_prefix6(proto_tree *tree, packet_info *pinfo, int hf_addr, tvbuff_t *tvb, gint offset,
guint16 tlen, const char *tag)
{
proto_tree *prefix_tree;
struct e_in6_addr addr;
address addr_str;
int plen;
int length;
plen = tvb_get_guint8(tvb, offset);
length = tvb_get_ipv6_addr_with_prefix_len(tvb, offset + 1, &addr, plen);
if (length < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_length_invalid, tvb, offset, 1, "%s length %u invalid",
tag, plen);
return -1;
}
set_address(&addr_str, AT_IPv6, 16, addr.bytes);
prefix_tree = proto_tree_add_subtree_format(tree, tvb, offset,
tlen != 0 ? tlen : 1 + length, ett_bgp_prefix, NULL, "%s/%u",
address_to_str(wmem_packet_scope(), &addr_str), plen);
proto_tree_add_uint_format(prefix_tree, hf_bgp_prefix_length, tvb, offset, 1, plen, "%s prefix length: %u",
tag, plen);
proto_tree_add_ipv6(prefix_tree, hf_addr, tvb, offset + 1, length, &addr);
return(1 + length);
}
static int
decode_fspec_match_prefix6(proto_tree *tree, proto_item *parent_item, int hf_addr,
tvbuff_t *tvb, gint offset, guint16 tlen, packet_info *pinfo)
{
proto_tree *prefix_tree;
struct e_in6_addr addr;
address addr_str;
int plen;
int length;
int poffset_place = 1;
int plength_place = 0;
plen = tvb_get_guint8(tvb, offset);
if (plen == 0)
{
plen = tvb_get_guint8(tvb, offset+1);
poffset_place = 0;
plength_place = 1;
}
length = tvb_get_ipv6_addr_with_prefix_len(tvb, offset + 2, &addr, plen);
if (length < 0) {
expert_add_info_format(pinfo, parent_item, &ei_bgp_prefix_length_err, "Length is invalid %u", plen);
return -1;
}
set_address(&addr_str, AT_IPv6, 16, addr.bytes);
prefix_tree = proto_tree_add_subtree_format(tree, tvb, offset,
tlen != 0 ? tlen : 1 + length, ett_bgp_prefix, NULL, "%s/%u",
address_to_str(wmem_packet_scope(), &addr_str), plen);
proto_tree_add_item(prefix_tree, hf_bgp_flowspec_nlri_ipv6_pref_len, tvb, offset + plength_place, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(prefix_tree, hf_bgp_flowspec_nlri_ipv6_pref_offset, tvb, offset + poffset_place, 1, ENC_BIG_ENDIAN);
proto_tree_add_ipv6(prefix_tree, hf_addr, tvb, offset + 2, length, &addr);
if (parent_item != NULL)
proto_item_append_text(parent_item, " (%s/%u)",
address_to_str(wmem_packet_scope(), &addr_str), plen);
return(2 + length);
}
const char*
decode_bgp_rd(tvbuff_t *tvb, gint offset)
{
guint16 rd_type;
wmem_strbuf_t *strbuf;
rd_type = tvb_get_ntohs(tvb,offset);
strbuf = wmem_strbuf_new_label(wmem_packet_scope());
switch (rd_type) {
case FORMAT_AS2_LOC:
wmem_strbuf_append_printf(strbuf, "%u:%u", tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohl(tvb, offset + 4));
break;
case FORMAT_IP_LOC:
wmem_strbuf_append_printf(strbuf, "%s:%u", tvb_ip_to_str(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 6));
break ;
case FORMAT_AS4_LOC:
wmem_strbuf_append_printf(strbuf, "%u:%u", tvb_get_ntohl(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 6));
break ;
default:
wmem_strbuf_append_printf(strbuf, "Unknown (0x%04x) RD type",rd_type);
break;
}
return wmem_strbuf_get_str(strbuf);
}
static int
decode_mcast_vpn_nlri_addresses(proto_tree *tree, tvbuff_t *tvb,
gint offset)
{
guint8 addr_len;
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_source_length, tvb, offset,
1, ENC_BIG_ENDIAN);
addr_len = tvb_get_guint8(tvb, offset);
if (addr_len != 32 && addr_len != 128)
return -1;
offset++;
if (addr_len == 32) {
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_source_addr_ipv4, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_source_addr_ipv6, tvb,
offset, 16, ENC_NA);
offset += 16;
}
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_group_length, tvb, offset,
1, ENC_BIG_ENDIAN);
addr_len = tvb_get_guint8(tvb, offset);
if (addr_len != 32 && addr_len != 128)
return -1;
offset++;
if (addr_len == 32) {
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_group_addr_ipv4, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_group_addr_ipv6, tvb,
offset, 16, ENC_NA);
offset += 16;
}
return offset;
}
static void
decode_bgp_flow_spec_dec_operator(proto_tree *tree, tvbuff_t *tvb, gint offset)
{
static const int * flags[] = {
&hf_bgp_flowspec_nlri_op_eol,
&hf_bgp_flowspec_nlri_op_and,
&hf_bgp_flowspec_nlri_op_val_len,
&hf_bgp_flowspec_nlri_op_un_bit4,
&hf_bgp_flowspec_nlri_op_lt,
&hf_bgp_flowspec_nlri_op_gt,
&hf_bgp_flowspec_nlri_op_eq,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_bgp_flowspec_nlri_op_flags, ett_bgp_flow_spec_nlri_op_flags, flags, ENC_NA);
}
static int
decode_bgp_nlri_op_dec_value(proto_tree *parent_tree, proto_item *parent_item, tvbuff_t *tvb, gint offset)
{
guint8 nlri_operator;
guint cursor_op_val=0;
guint8 value_len=0;
guint value=0;
guint8 shift_amount=0;
guint first_loop=0;
proto_item_append_text(parent_item," (");
do {
nlri_operator = tvb_get_guint8(tvb, offset+cursor_op_val);
shift_amount = nlri_operator&0x30;
shift_amount = shift_amount >> 4;
value_len = 1 << shift_amount;
decode_bgp_flow_spec_dec_operator(parent_tree, tvb, offset+cursor_op_val);
if (first_loop == 0)
{
proto_item_append_text(parent_item,"%s%s%s%s",
((nlri_operator & BGPNLRI_FSPEC_AND_BIT) == 0) ? "" : "&& ",
((nlri_operator & BGPNLRI_FSPEC_GREATER_THAN) == 0) ? "" : ">",
((nlri_operator & BGPNLRI_FSPEC_LESS_THAN) == 0) ? "" : "<",
((nlri_operator & BGPNLRI_FSPEC_EQUAL) == 0) ? "" : "=");
first_loop = 1;
}
else
{
proto_item_append_text(parent_item," %s%s%s%s",
((nlri_operator & BGPNLRI_FSPEC_AND_BIT) == 0) ? "|| " : "&& ",
((nlri_operator & BGPNLRI_FSPEC_GREATER_THAN) == 0) ? "" : ">",
((nlri_operator & BGPNLRI_FSPEC_LESS_THAN) == 0) ? "" : "<",
((nlri_operator & BGPNLRI_FSPEC_EQUAL) == 0) ? "" : "=");
}
cursor_op_val++;
switch (value_len) {
case 1:
proto_tree_add_item(parent_tree, hf_bgp_flowspec_nlri_dec_val_8, tvb, offset+cursor_op_val, 1,ENC_BIG_ENDIAN);
value = tvb_get_guint8(tvb,offset+cursor_op_val);
break;
case 2:
proto_tree_add_item(parent_tree, hf_bgp_flowspec_nlri_dec_val_16, tvb, offset+cursor_op_val, 2,ENC_BIG_ENDIAN);
value = tvb_get_ntohs(tvb,offset+cursor_op_val);
break;
case 3:
proto_tree_add_item(parent_tree, hf_bgp_flowspec_nlri_dec_val_32, tvb, offset+cursor_op_val, 4, ENC_BIG_ENDIAN);
value = tvb_get_ntohl(tvb,offset+cursor_op_val);
break;
case 4:
proto_tree_add_item(parent_tree, hf_bgp_flowspec_nlri_dec_val_64, tvb, offset+cursor_op_val, 8, ENC_BIG_ENDIAN);
break;
default:
return -1;
}
cursor_op_val = cursor_op_val + value_len;
proto_item_append_text(parent_item,"%u", value);
} while ((nlri_operator&BGPNLRI_FSPEC_END_OF_LST) == 0);
proto_item_append_text(parent_item,")");
return (cursor_op_val);
}
static void
decode_bgp_flow_spec_bitmask_operator(proto_tree *tree, tvbuff_t *tvb, gint offset)
{
static const int * flags[] = {
&hf_bgp_flowspec_nlri_op_eol,
&hf_bgp_flowspec_nlri_op_and,
&hf_bgp_flowspec_nlri_op_val_len,
&hf_bgp_flowspec_nlri_op_un_bit4,
&hf_bgp_flowspec_nlri_op_un_bit5,
&hf_bgp_flowspec_nlri_op_flg_not,
&hf_bgp_flowspec_nlri_op_flg_match,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_bgp_flowspec_nlri_op_flags, ett_bgp_flow_spec_nlri_op_flags, flags, ENC_NA);
}
static int
decode_bgp_nlri_op_tcpf_value(proto_tree *parent_tree, proto_item *parent_item, tvbuff_t *tvb, gint offset)
{
guint8 nlri_operator;
guint8 tcp_flags;
guint cursor_op_val=0;
guint8 value_len=0;
guint8 shift_amount=0;
guint first_loop=0;
static const int * nlri_tcp_flags[] = {
&hf_bgp_flowspec_nlri_tcp_flags_cwr,
&hf_bgp_flowspec_nlri_tcp_flags_ecn,
&hf_bgp_flowspec_nlri_tcp_flags_urg,
&hf_bgp_flowspec_nlri_tcp_flags_ack,
&hf_bgp_flowspec_nlri_tcp_flags_push,
&hf_bgp_flowspec_nlri_tcp_flags_reset,
&hf_bgp_flowspec_nlri_tcp_flags_syn,
&hf_bgp_flowspec_nlri_tcp_flags_fin,
NULL
};
proto_item_append_text(parent_item," (");
do {
nlri_operator = tvb_get_guint8(tvb, offset+cursor_op_val);
shift_amount = nlri_operator&0x30;
shift_amount = shift_amount >> 4;
value_len = 1 << shift_amount;
decode_bgp_flow_spec_bitmask_operator(parent_tree, tvb, offset+cursor_op_val);
if (first_loop == 0)
{
proto_item_append_text(parent_item,"%s%s%s%s",
((nlri_operator & BGPNLRI_FSPEC_AND_BIT) == 0) ? "" : "&& ",
((nlri_operator & BGPNLRI_FSPEC_GREATER_THAN) == 0) ? "" : ">",
((nlri_operator & BGPNLRI_FSPEC_LESS_THAN) == 0) ? "" : "<",
((nlri_operator & BGPNLRI_FSPEC_EQUAL) == 0) ? "" : "=");
first_loop = 1;
}
else
{
proto_item_append_text(parent_item," %s%s%s%s",
((nlri_operator & BGPNLRI_FSPEC_AND_BIT) == 0) ? "|| " : "&& ",
((nlri_operator & BGPNLRI_FSPEC_GREATER_THAN) == 0) ? "" : ">",
((nlri_operator & BGPNLRI_FSPEC_LESS_THAN) == 0) ? "" : "<",
((nlri_operator & BGPNLRI_FSPEC_EQUAL) == 0) ? "" : "=");
}
cursor_op_val++;
if (value_len == 2) {
cursor_op_val++;
}
proto_tree_add_bitmask(parent_tree, tvb, offset+cursor_op_val, hf_bgp_flowspec_nlri_tcp_flags, ett_bgp_flow_spec_nlri_tcp, nlri_tcp_flags, ENC_NA);
tcp_flags = tvb_get_guint8(tvb,offset+cursor_op_val);
proto_item_append_text(parent_item," %s%s%s%s%s%s",
((tcp_flags & BGPNLRI_FSPEC_TH_URG) == 0) ? "" : "U",
((tcp_flags & BGPNLRI_FSPEC_TH_ACK) == 0) ? "" : "A",
((tcp_flags & BGPNLRI_FSPEC_TH_PUSH) == 0) ? "" : "P",
((tcp_flags & BGPNLRI_FSPEC_TH_RST) == 0) ? "" : "R",
((tcp_flags & BGPNLRI_FSPEC_TH_SYN) == 0) ? "" : "S",
((tcp_flags & BGPNLRI_FSPEC_TH_FIN) == 0) ? "" : "F");
cursor_op_val = cursor_op_val + value_len;
} while ((nlri_operator&BGPNLRI_FSPEC_END_OF_LST) == 0);
proto_item_append_text(parent_item,")");
return (cursor_op_val);
}
static int
decode_bgp_nlri_op_fflag_value(proto_tree *parent_tree, proto_item *parent_item, tvbuff_t *tvb, gint offset)
{
guint8 nlri_operator;
guint8 fragment_flags;
guint cursor_op_val=0;
guint8 value_len=0;
guint8 shift_amount=0;
guint first_loop=0;
static const int * nlri_flags[] = {
&hf_bgp_flowspec_nlri_fflag_lf,
&hf_bgp_flowspec_nlri_fflag_ff,
&hf_bgp_flowspec_nlri_fflag_isf,
&hf_bgp_flowspec_nlri_fflag_df,
NULL
};
proto_item_append_text(parent_item," (");
do {
nlri_operator = tvb_get_guint8(tvb, offset+cursor_op_val);
shift_amount = nlri_operator&0x30;
shift_amount = shift_amount >> 4;
value_len = 1 << shift_amount;
decode_bgp_flow_spec_bitmask_operator(parent_tree, tvb, offset+cursor_op_val);
if (first_loop == 0)
{
proto_item_append_text(parent_item,"%s%s%s%s",
((nlri_operator & BGPNLRI_FSPEC_AND_BIT) == 0) ? "" : "&& ",
((nlri_operator & BGPNLRI_FSPEC_GREATER_THAN) == 0) ? "" : ">",
((nlri_operator & BGPNLRI_FSPEC_LESS_THAN) == 0) ? "" : "<",
((nlri_operator & BGPNLRI_FSPEC_EQUAL) == 0) ? "" : "=");
first_loop = 1;
}
else
{
proto_item_append_text(parent_item," %s%s%s%s",
((nlri_operator & BGPNLRI_FSPEC_AND_BIT) == 0) ? "|| " : "&& ",
((nlri_operator & BGPNLRI_FSPEC_GREATER_THAN) == 0) ? "" : ">",
((nlri_operator & BGPNLRI_FSPEC_LESS_THAN) == 0) ? "" : "<",
((nlri_operator & BGPNLRI_FSPEC_EQUAL) == 0) ? "" : "=");
}
cursor_op_val++;
if (value_len != 1) {
return -1;
}
fragment_flags = tvb_get_guint8(tvb,offset+cursor_op_val);
proto_tree_add_bitmask(parent_tree, tvb, offset+cursor_op_val, hf_bgp_flowspec_nlri_fflag, ett_bgp_flow_spec_nlri_ff, nlri_flags, ENC_NA);
proto_item_append_text(parent_item," %s%s%s%s",
((fragment_flags & BGPNLRI_FSPEC_FG_DF) == 0) ? "" : "DF",
((fragment_flags & BGPNLRI_FSPEC_FG_ISF) == 0) ? "" : "IsF",
((fragment_flags & BGPNLRI_FSPEC_FG_FF) == 0) ? "" : "FF",
((fragment_flags & BGPNLRI_FSPEC_FG_LF) == 0) ? "" : "LF");
cursor_op_val = cursor_op_val + value_len;
} while ((nlri_operator&BGPNLRI_FSPEC_END_OF_LST) == 0);
proto_item_append_text(parent_item,")");
return (cursor_op_val);
}
static int
decode_bgp_nlri_op_dscp_value(proto_tree *parent_tree, proto_item *parent_item, tvbuff_t *tvb, gint offset)
{
guint8 nlri_operator;
guint8 dscp_flags;
guint cursor_op_val=0;
guint8 value_len=0;
guint8 shift_amount=0;
guint first_loop=0;
proto_item_append_text(parent_item," (");
do {
nlri_operator = tvb_get_guint8(tvb, offset+cursor_op_val);
shift_amount = nlri_operator&0x30;
shift_amount = shift_amount >> 4;
value_len = 1 << shift_amount;
decode_bgp_flow_spec_bitmask_operator(parent_tree, tvb, offset+cursor_op_val);
if (first_loop == 0)
{
proto_item_append_text(parent_item,"%s%s%s%s",
((nlri_operator & BGPNLRI_FSPEC_AND_BIT) == 0) ? "" : "&& ",
((nlri_operator & BGPNLRI_FSPEC_GREATER_THAN) == 0) ? "" : ">",
((nlri_operator & BGPNLRI_FSPEC_LESS_THAN) == 0) ? "" : "<",
((nlri_operator & BGPNLRI_FSPEC_EQUAL) == 0) ? "" : "=");
first_loop = 1;
}
else
{
proto_item_append_text(parent_item," %s%s%s%s",
((nlri_operator & BGPNLRI_FSPEC_AND_BIT) == 0) ? "|| " : "&& ",
((nlri_operator & BGPNLRI_FSPEC_GREATER_THAN) == 0) ? "" : ">",
((nlri_operator & BGPNLRI_FSPEC_LESS_THAN) == 0) ? "" : "<",
((nlri_operator & BGPNLRI_FSPEC_EQUAL) == 0) ? "" : "=");
}
cursor_op_val++;
if (value_len != 1) {
return -1;
}
dscp_flags = tvb_get_guint8(tvb,offset+cursor_op_val);
proto_tree_add_item(parent_tree, hf_bgp_flowspec_nlri_dscp, tvb, offset+cursor_op_val, 1, ENC_BIG_ENDIAN);
proto_item_append_text(parent_item,"%s",val_to_str_ext_const(dscp_flags,&dscp_vals_ext, "Unknown DSCP"));
cursor_op_val = cursor_op_val + value_len;
} while ((nlri_operator&BGPNLRI_FSPEC_END_OF_LST) == 0);
proto_item_append_text(parent_item,")");
return (cursor_op_val);
}
static int
decode_flowspec_nlri(proto_tree *tree, tvbuff_t *tvb, gint offset, guint16 afi, packet_info *pinfo)
{
guint tot_flow_len;
guint offset_len;
guint cursor_fspec;
gint filter_len = -1;
guint16 len_16;
proto_item *item;
proto_item *filter_item;
proto_tree *nlri_tree;
proto_tree *filter_tree;
if (afi != AFNUM_INET && afi != AFNUM_INET6)
{
expert_add_info(pinfo, NULL, &ei_bgp_afi_type_not_supported);
return(-1);
}
tot_flow_len = tvb_get_guint8(tvb, offset);
if (tot_flow_len >= 240)
{
len_16 = tvb_get_ntohs(tvb, offset);
tot_flow_len = len_16 & 0x0FFF;
offset_len = 2;
} else {
offset_len = 1;
}
item = proto_tree_add_item(tree, hf_bgp_flowspec_nlri_t, tvb, offset,
tot_flow_len+offset_len, ENC_NA);
proto_item_set_text(item, "FLOW_SPEC_NLRI (%u byte%s)",
tot_flow_len+offset_len, plurality(tot_flow_len+offset_len, "", "s"));
nlri_tree = proto_item_add_subtree(item, ett_bgp_flow_spec_nlri);
proto_tree_add_uint(nlri_tree, hf_bgp_flowspec_nlri_length, tvb, offset,
offset_len, tot_flow_len);
offset = offset + offset_len;
cursor_fspec = 0;
while (cursor_fspec < tot_flow_len)
{
filter_item = proto_tree_add_item(nlri_tree, hf_bgp_flowspec_nlri_filter, tvb, offset+cursor_fspec, 1, ENC_NA);
filter_tree = proto_item_add_subtree(filter_item, ett_bgp_flow_spec_nlri_filter);
proto_tree_add_item(filter_tree, hf_bgp_flowspec_nlri_filter_type, tvb, offset+cursor_fspec, 1, ENC_BIG_ENDIAN);
proto_item_append_text(filter_item, ": %s", val_to_str(tvb_get_guint8(tvb,offset+cursor_fspec), flowspec_nlri_opvaluepair_type, "Unknown filter %d"));
switch (tvb_get_guint8(tvb,offset+cursor_fspec)) {
case BGPNLRI_FSPEC_DST_PFIX:
cursor_fspec++;
if (afi == AFNUM_INET)
filter_len = decode_prefix4(filter_tree, pinfo, filter_item, hf_bgp_flowspec_nlri_dst_pref_ipv4,
tvb, offset+cursor_fspec, 0, "Destination IP filter");
else if (afi == AFNUM_INET6)
filter_len = decode_fspec_match_prefix6(filter_tree, filter_item, hf_bgp_flowspec_nlri_dst_ipv6_pref,
tvb, offset+cursor_fspec, 0, pinfo);
else cursor_fspec = tot_flow_len;
if (filter_len == -1)
cursor_fspec= tot_flow_len;
break;
case BGPNLRI_FSPEC_SRC_PFIX:
cursor_fspec++;
if (afi == AFNUM_INET)
filter_len = decode_prefix4(filter_tree, pinfo, filter_item, hf_bgp_flowspec_nlri_src_pref_ipv4,
tvb, offset+cursor_fspec, 0, "Source IP filter");
else if (afi == AFNUM_INET6)
filter_len = decode_fspec_match_prefix6(filter_tree, filter_item, hf_bgp_flowspec_nlri_src_ipv6_pref,
tvb, offset+cursor_fspec, 0, pinfo);
else cursor_fspec = tot_flow_len;
if (filter_len == -1)
cursor_fspec= tot_flow_len;
break;
case BGPNLRI_FSPEC_IP_PROTO:
cursor_fspec++;
filter_len = decode_bgp_nlri_op_dec_value(filter_tree, filter_item, tvb, offset+cursor_fspec);
break;
case BGPNLRI_FSPEC_PORT:
cursor_fspec++;
filter_len = decode_bgp_nlri_op_dec_value(filter_tree, filter_item, tvb, offset+cursor_fspec);
break;
case BGPNLRI_FSPEC_DST_PORT:
cursor_fspec++;
filter_len = decode_bgp_nlri_op_dec_value(filter_tree, filter_item, tvb, offset+cursor_fspec);
break;
case BGPNLRI_FSPEC_SRC_PORT:
cursor_fspec++;
filter_len = decode_bgp_nlri_op_dec_value(filter_tree, filter_item, tvb, offset+cursor_fspec);
break;
case BGPNLRI_FSPEC_ICMP_TP:
cursor_fspec++;
filter_len = decode_bgp_nlri_op_dec_value(filter_tree, filter_item, tvb, offset+cursor_fspec);
break;
case BGPNLRI_FSPEC_ICMP_CD:
cursor_fspec++;
filter_len = decode_bgp_nlri_op_dec_value(filter_tree, filter_item, tvb, offset+cursor_fspec);
break;
case BGPNLRI_FSPEC_TCP_FLAGS:
cursor_fspec++;
filter_len = decode_bgp_nlri_op_tcpf_value(filter_tree, filter_item, tvb, offset+cursor_fspec);
break;
case BGPNLRI_FSPEC_PCK_LEN:
cursor_fspec++;
filter_len = decode_bgp_nlri_op_dec_value(filter_tree, filter_item, tvb, offset+cursor_fspec);
break;
case BGPNLRI_FSPEC_DSCP:
cursor_fspec++;
filter_len = decode_bgp_nlri_op_dscp_value(filter_tree, filter_item, tvb, offset+cursor_fspec);
break;
case BGPNLRI_FSPEC_FRAGMENT:
cursor_fspec++;
filter_len = decode_bgp_nlri_op_fflag_value(filter_tree, filter_item, tvb, offset+cursor_fspec);
break;
default:
return -1;
}
if (filter_len>0)
cursor_fspec += filter_len;
else
break;
proto_item_set_len(filter_item,filter_len+1);
}
return(tot_flow_len+offset_len-1);
}
static int
decode_mcast_vpn_nlri(proto_tree *tree, tvbuff_t *tvb, gint offset, guint16 afi)
{
guint8 route_type, length, ip_length;
proto_item *item;
proto_tree *nlri_tree;
guint32 route_key_length;
int ret;
ip_length = (afi == AFNUM_INET) ? 4 : 16;
route_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_route_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_length, tvb, offset,
1, ENC_BIG_ENDIAN);
offset++;
if (length < tvb_reported_length_remaining(tvb, offset))
return -1;
item = proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_t, tvb, offset,
length, ENC_NA);
proto_item_set_text(item, "%s (%u byte%s)",
val_to_str_const(route_type, mcast_vpn_route_type, "Unknown"),
length, plurality(length, "", "s"));
nlri_tree = proto_item_add_subtree(item, ett_bgp_mcast_vpn_nlri);
switch (route_type) {
case MCAST_VPN_RTYPE_INTRA_AS_IPMSI_AD:
item = proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_rd, tvb,
offset, BGP_ROUTE_DISTINGUISHER_SIZE,
ENC_NA);
proto_item_set_text(item, "Route Distinguisher: %s",
decode_bgp_rd(tvb, offset));
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
if (afi == AFNUM_INET)
proto_tree_add_item(nlri_tree,
hf_bgp_mcast_vpn_nlri_origin_router_ipv4,
tvb, offset, ip_length, ENC_BIG_ENDIAN);
else
proto_tree_add_item(nlri_tree,
hf_bgp_mcast_vpn_nlri_origin_router_ipv6,
tvb, offset, ip_length, ENC_NA);
break;
case MCAST_VPN_RTYPE_INTER_AS_IPMSI_AD:
item = proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_rd, tvb,
offset, BGP_ROUTE_DISTINGUISHER_SIZE,
ENC_NA);
proto_item_set_text(item, "Route Distinguisher: %s",
decode_bgp_rd(tvb, offset));
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_source_as, tvb,
offset, 4, ENC_BIG_ENDIAN);
break;
case MCAST_VPN_RTYPE_SPMSI_AD:
item = proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_rd, tvb,
offset, BGP_ROUTE_DISTINGUISHER_SIZE,
ENC_NA);
proto_item_set_text(item, "Route Distinguisher: %s",
decode_bgp_rd(tvb, offset));
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
ret = decode_mcast_vpn_nlri_addresses(nlri_tree, tvb, offset);
if (ret < 0)
return -1;
break;
case MCAST_VPN_RTYPE_LEAF_AD:
route_key_length = length - ip_length;
item = proto_tree_add_item(nlri_tree,
hf_bgp_mcast_vpn_nlri_route_key, tvb,
offset, route_key_length, ENC_NA);
proto_item_set_text(item, "Route Key (%u byte%s)", route_key_length,
plurality(route_key_length, "", "s"));
offset += route_key_length;
if (afi == AFNUM_INET)
proto_tree_add_item(nlri_tree,
hf_bgp_mcast_vpn_nlri_origin_router_ipv4,
tvb, offset, ip_length, ENC_BIG_ENDIAN);
else
proto_tree_add_item(nlri_tree,
hf_bgp_mcast_vpn_nlri_origin_router_ipv6,
tvb, offset, ip_length, ENC_NA);
break;
case MCAST_VPN_RTYPE_SOURCE_ACTIVE_AD:
item = proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_rd, tvb,
offset, BGP_ROUTE_DISTINGUISHER_SIZE,
ENC_NA);
proto_item_set_text(item, "Route Distinguisher: %s",
decode_bgp_rd(tvb, offset));
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
ret = decode_mcast_vpn_nlri_addresses(nlri_tree, tvb, offset);
if (ret < 0)
return -1;
break;
case MCAST_VPN_RTYPE_SHARED_TREE_JOIN:
case MCAST_VPN_RTYPE_SOURCE_TREE_JOIN:
item = proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_rd, tvb,
offset, BGP_ROUTE_DISTINGUISHER_SIZE,
ENC_NA);
proto_item_set_text(item, "Route Distinguisher: %s",
decode_bgp_rd(tvb, offset));
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_source_as, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ret = decode_mcast_vpn_nlri_addresses(nlri_tree, tvb, offset);
if (ret < 0)
return -1;
break;
}
return 2 + length;
}
static guint
decode_mdt_safi(proto_tree *tree, tvbuff_t *tvb, gint offset)
{
const guint ip_length = 4;
const guint mdt_safi_nlri_length_bits = 128;
guint length;
gint orig_offset = offset;
proto_item *item;
length = tvb_get_guint8(tvb, offset);
if (length != mdt_safi_nlri_length_bits)
return -1;
offset++;
item = proto_tree_add_item(tree, hf_bgp_mdt_nlri_safi_rd, tvb,
offset, BGP_ROUTE_DISTINGUISHER_SIZE, ENC_NA);
proto_item_set_text(item, "Route Distinguisher: %s",
decode_bgp_rd(tvb, offset));
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
proto_tree_add_item(tree, hf_bgp_mdt_nlri_safi_ipv4_addr, tvb,
offset, ip_length, ENC_BIG_ENDIAN);
offset += ip_length;
proto_tree_add_item(tree, hf_bgp_mdt_nlri_safi_group_addr, tvb,
offset, ip_length, ENC_BIG_ENDIAN);
offset += ip_length;
return offset - orig_offset;
}
static guint
decode_MPLS_stack(tvbuff_t *tvb, gint offset, wmem_strbuf_t *stack_strbuf)
{
guint32 label_entry;
gint indx;
indx = offset ;
label_entry = 0x000000 ;
wmem_strbuf_truncate(stack_strbuf, 0);
while ((label_entry & BGP_MPLS_BOTTOM_L_STACK) == 0) {
label_entry = tvb_get_ntoh24(tvb, indx) ;
if((indx == offset)&&(label_entry==0||label_entry==0x800000)) {
wmem_strbuf_append(stack_strbuf, "0 (withdrawn)");
return (1);
}
wmem_strbuf_append_printf(stack_strbuf, "%u%s", label_entry >> 4,
((label_entry & BGP_MPLS_BOTTOM_L_STACK) == 0) ? "," : " (bottom)");
indx += 3 ;
if ((label_entry & BGP_MPLS_BOTTOM_L_STACK) == 0) {
wmem_strbuf_append(stack_strbuf, " (BOGUS: Bottom of Stack NOT set!)");
break;
}
}
return((indx - offset) / 3);
}
static guint
decode_MPLS_stack_tree(tvbuff_t *tvb, gint offset, proto_tree *parent_tree)
{
guint32 label_entry=0;
gint indx;
proto_tree *labels_tree=NULL;
proto_item *labels_item=NULL;
proto_item *label_item=NULL;
indx = offset ;
label_entry = 0x000000 ;
labels_item = proto_tree_add_item(parent_tree, hf_bgp_update_mpls_label, tvb, offset, 3, ENC_NA);
proto_item_append_text(labels_item, ": ");
labels_tree = proto_item_add_subtree(labels_item, ett_bgp_mpls_labels);
while ((label_entry & BGP_MPLS_BOTTOM_L_STACK) == 0) {
label_entry = tvb_get_ntoh24(tvb, indx);
label_item = proto_tree_add_item(labels_tree, hf_bgp_update_mpls_label_value, tvb, indx, 3, ENC_BIG_ENDIAN);
if((indx == offset)&&(label_entry==0||label_entry==0x800000)) {
proto_item_append_text(labels_item, " (withdrawn)");
proto_item_append_text(label_item, " (withdrawn)");
return (1);
}
proto_item_append_text(labels_item, "%u%s", label_entry >> 4,
((label_entry & BGP_MPLS_BOTTOM_L_STACK) == 0) ? "," : " (bottom)");
proto_item_append_text(label_item, "%u%s", label_entry >> 4,
((label_entry & BGP_MPLS_BOTTOM_L_STACK) == 0) ? "," : " (bottom)");
indx += 3 ;
if ((label_entry & BGP_MPLS_BOTTOM_L_STACK) == 0) {
proto_item_append_text(labels_item, " (BOGUS: Bottom of Stack NOT set!)");
break;
}
}
proto_item_set_len(labels_item, (indx - offset));
return((indx - offset) / 3);
}
static int
mp_addr_to_str (guint16 afi, guint8 safi, tvbuff_t *tvb, gint offset, wmem_strbuf_t *strbuf, gint nhlen)
{
int length;
guint16 rd_type;
switch (afi) {
case AFNUM_INET:
switch (safi) {
case SAFNUM_UNICAST:
case SAFNUM_MULCAST:
case SAFNUM_UNIMULC:
case SAFNUM_MPLS_LABEL:
case SAFNUM_ENCAPSULATION:
case SAFNUM_ROUTE_TARGET:
length = nhlen;
if (nhlen == 4) {
wmem_strbuf_append(strbuf, tvb_ip_to_str(tvb, offset));
} else if (nhlen == 16) {
wmem_strbuf_append(strbuf, tvb_ip6_to_str(tvb, offset));
} else {
wmem_strbuf_append(strbuf, "Unknown address");
}
break;
case SAFNUM_TUNNEL:
length = 4;
wmem_strbuf_append(strbuf, tvb_ip_to_str(tvb, offset));
break;
case SAFNUM_LAB_VPNUNICAST:
case SAFNUM_LAB_VPNMULCAST:
case SAFNUM_LAB_VPNUNIMULC:
rd_type=tvb_get_ntohs(tvb,offset) ;
wmem_strbuf_truncate(strbuf, 0);
switch (rd_type) {
case FORMAT_AS2_LOC:
length = 12;
wmem_strbuf_append_printf(strbuf, "Empty Label Stack RD=%u:%u IPv4=%s",
tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohl(tvb, offset + 4),
tvb_ip_to_str(tvb, offset + 8));
break;
case FORMAT_IP_LOC:
length = 12;
wmem_strbuf_append_printf(strbuf, "Empty Label Stack RD=%s:%u IPv4=%s",
tvb_ip_to_str(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 6),
tvb_ip_to_str(tvb, offset + 8));
break ;
case FORMAT_AS4_LOC:
length = 12;
wmem_strbuf_append_printf(strbuf, "Empty Label Stack RD=%u.%u:%u IPv4=%s",
tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 4),
tvb_get_ntohs(tvb, offset + 6),
tvb_ip_to_str(tvb, offset + 8));
break ;
default:
length = 0 ;
wmem_strbuf_append_printf(strbuf, "Unknown (0x%04x) labeled VPN IPv4 address format",rd_type);
break;
}
break;
default:
length = 0 ;
wmem_strbuf_truncate(strbuf, 0);
wmem_strbuf_append_printf(strbuf, "Unknown SAFI (%u) for AFI %u", safi, afi);
break;
}
break;
case AFNUM_INET6:
wmem_strbuf_truncate(strbuf, 0);
switch (safi) {
case SAFNUM_UNICAST:
case SAFNUM_MULCAST:
case SAFNUM_UNIMULC:
case SAFNUM_MPLS_LABEL:
case SAFNUM_ENCAPSULATION:
case SAFNUM_TUNNEL:
length = 16;
wmem_strbuf_append_printf(strbuf, "%s", tvb_ip6_to_str(tvb, offset));
break;
case SAFNUM_LAB_VPNUNICAST:
case SAFNUM_LAB_VPNMULCAST:
case SAFNUM_LAB_VPNUNIMULC:
rd_type=tvb_get_ntohs(tvb,offset) ;
switch (rd_type) {
case FORMAT_AS2_LOC:
length = 8 + 16;
wmem_strbuf_append_printf(strbuf, "Empty Label Stack RD=%u:%u IPv6=%s",
tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohl(tvb, offset + 4),
tvb_ip6_to_str(tvb, offset + 8));
break;
case FORMAT_IP_LOC:
length = 8 + 16;
wmem_strbuf_append_printf(strbuf, "Empty Label Stack RD=%s:%u IPv6=%s",
tvb_ip_to_str(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 6),
tvb_ip6_to_str(tvb, offset + 8));
break ;
case FORMAT_AS4_LOC:
length = 8 + 16;
wmem_strbuf_append_printf(strbuf, "Empty Label Stack RD=%u:%u IPv6=%s",
tvb_get_ntohl(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 6),
tvb_ip6_to_str(tvb, offset + 8));
break ;
default:
length = 0 ;
wmem_strbuf_append_printf(strbuf, "Unknown (0x%04x) labeled VPN IPv6 address format",rd_type);
break;
}
break;
default:
length = 0 ;
wmem_strbuf_append_printf(strbuf, "Unknown SAFI (%u) for AFI %u", safi, afi);
break;
}
break;
case AFNUM_L2VPN:
case AFNUM_L2VPN_OLD:
wmem_strbuf_truncate(strbuf, 0);
switch (safi) {
case SAFNUM_LAB_VPNUNICAST:
case SAFNUM_LAB_VPNMULCAST:
case SAFNUM_LAB_VPNUNIMULC:
case SAFNUM_VPLS:
length = 4;
wmem_strbuf_append_printf(strbuf, "IPv4=%s",
tvb_ip_to_str(tvb, offset));
break;
default:
length = 0 ;
wmem_strbuf_append_printf(strbuf, "Unknown SAFI (%u) for AFI %u", safi, afi);
break;
}
break;
case AFNUM_LINK_STATE:
length = nhlen;
if (nhlen == 4) {
wmem_strbuf_append(strbuf, tvb_ip_to_str(tvb, offset));
} else if (nhlen == 16) {
wmem_strbuf_append(strbuf, tvb_ip6_to_str(tvb, offset));
} else {
wmem_strbuf_append(strbuf, "Unknown address");
}
break;
default:
length = 0 ;
wmem_strbuf_truncate(strbuf, 0);
wmem_strbuf_append_printf(strbuf, "Unknown AFI (%u) value", afi);
break;
}
return(length) ;
}
static int decode_bgp_link_node_descriptor(tvbuff_t *tvb, proto_tree *tree, gint offset, packet_info *pinfo, int length)
{
guint16 sub_length;
guint16 type;
guint16 diss_length;
proto_item* tlv_item;
proto_tree* tlv_tree;
diss_length = 0;
while (length > 0 ) {
if (length < 4) {
expert_add_info_format(pinfo, tree, &ei_bgp_ls_error,
"Unknown data in Link-State Link NLRI!");
diss_length += length;
break;
}
type = tvb_get_ntohs(tvb, offset);
sub_length = tvb_get_ntohs(tvb, offset + 2);
switch (type) {
case BGP_NLRI_TLV_AUTONOMOUS_SYSTEM:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_autonomous_system, tvb, offset, sub_length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_mp_reach_nlri);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (sub_length != BGP_NLRI_TLV_LEN_AUTONOMOUS_SYSTEM) {
expert_add_info_format(pinfo, tree, &ei_bgp_ls_error,
"Autonomous system TLV length should be %u bytes! (%u)",
BGP_NLRI_TLV_LEN_AUTONOMOUS_SYSTEM, sub_length);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_autonomous_system_id, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
break;
case BGP_NLRI_TLV_BGP_LS_IDENTIFIER:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_bgp_ls_identifier, tvb, offset, sub_length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_mp_reach_nlri);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (sub_length != BGP_NLRI_TLV_LEN_BGP_LS_IDENTIFIER) {
expert_add_info_format(pinfo, tree, &ei_bgp_ls_error,
"BGP-LS TLV length should be %u bytes! (%u)",
BGP_NLRI_TLV_LEN_BGP_LS_IDENTIFIER, sub_length);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_bgp_ls_identifier_id, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
break;
case BGP_NLRI_TLV_AREA_ID:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_area_id, tvb, offset, sub_length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_mp_reach_nlri);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (sub_length != BGP_NLRI_TLV_LEN_AREA_ID) {
expert_add_info_format(pinfo, tree, &ei_bgp_ls_error,
"Area ID TLV length should be %u bytes! (%u)",
BGP_NLRI_TLV_LEN_AREA_ID, sub_length);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_area_id_id, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
break;
case BGP_NLRI_TLV_IGP_ROUTER_ID:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_igp_router, tvb, offset, sub_length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_mp_reach_nlri);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_igp_router_id, tvb, offset + 4, sub_length, ENC_NA);
break;
default:
expert_add_info_format(pinfo, tree, &ei_bgp_ls_error, "Undefined node Descriptor Sub-TLV type (%u)!", type);
}
length -= 4 + sub_length;
offset += 4 + sub_length;
diss_length += 4 + sub_length;
}
return diss_length;
}
static int decode_bgp_link_node_nlri_tlvs(tvbuff_t *tvb, proto_tree *tree, gint offset, packet_info *pinfo, guint16 expected_sub_tlv)
{
guint16 length;
guint16 type;
proto_tree* tlv_tree;
proto_item* tlv_item;
type = tvb_get_ntohs(tvb, offset);
length = tvb_get_ntohs(tvb, offset + 2);
if (expected_sub_tlv != type) {
expert_add_info_format(pinfo, tree, &ei_bgp_ls_error, "Expected/actual tlv mismatch, expected: %u, actual: %u", expected_sub_tlv, type);
}
switch(type){
case BGP_NLRI_TLV_LOCAL_NODE_DESCRIPTORS:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_local_node_descriptors, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_mp_reach_nlri);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
decode_bgp_link_node_descriptor(tvb, tlv_tree, offset + 4, pinfo, length);
break;
case BGP_NLRI_TLV_REMOTE_NODE_DESCRIPTORS:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_remote_node_descriptors, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_mp_reach_nlri);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
decode_bgp_link_node_descriptor(tvb, tlv_tree, offset + 4, pinfo, length);
break;
}
return length +4 ;
}
static int decode_bgp_link_node_nlri_common_fields(tvbuff_t *tvb,
proto_tree *tree, gint offset, packet_info *pinfo, int length) {
int dissected_length;
int tmp_length;
if (length < 12) {
expert_add_info_format(pinfo, tree, &ei_bgp_ls_error,
"Link State NLRI length is lower than 12 bytes! (%d)", length);
return length;
}
proto_tree_add_item(tree, hf_bgp_ls_nlri_node_protocol_id, tvb, offset, 1, ENC_BIG_ENDIAN);
save_link_state_protocol_id(pinfo, tvb_get_guint8(tvb, offset));
proto_tree_add_item(tree, hf_bgp_ls_nlri_node_identifier, tvb, offset + 1, 8, ENC_BIG_ENDIAN);
dissected_length = 9;
offset += dissected_length;
length -= dissected_length;
if (length > 0 && length < 4) {
expert_add_info_format(pinfo, tree, &ei_bgp_ls_error,
"Unknown data in Link-State Link NLRI! length = %d bytes", length);
return dissected_length;
}
if (length < 1)
return dissected_length;
tmp_length = decode_bgp_link_node_nlri_tlvs(tvb, tree, offset, pinfo,
BGP_NLRI_TLV_LOCAL_NODE_DESCRIPTORS);
if (tmp_length < 0) {
return -1;
}
dissected_length += tmp_length;
return dissected_length;
}
static int decode_bgp_link_nlri_link_descriptors(tvbuff_t *tvb,
proto_tree *tree, gint offset, packet_info *pinfo, int length) {
guint16 sub_length;
guint16 type;
guint16 diss_length;
guint16 tmp16;
proto_item* tlv_item;
proto_tree* tlv_tree;
proto_item* tlv_sub_item;
proto_tree* tlv_sub_tree;
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_nlri_link_descriptors_tlv, tvb, offset, length + 4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_mp_reach_nlri);
diss_length = 0;
while (length > 0) {
if (length < 4) {
expert_add_info_format(pinfo, tree, &ei_bgp_ls_error,
"Unknown data in Link-State Link NLRI!");
diss_length += length;
break;
}
type = tvb_get_ntohs(tvb, offset);
sub_length = tvb_get_ntohs(tvb, offset + 2);
switch (type) {
case BGP_NLRI_TLV_LINK_LOCAL_REMOTE_IDENTIFIERS:
if(sub_length != BGP_NLRI_TLV_LEN_LINK_LOCAL_REMOTE_IDENTIFIERS){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error,
"Unexpected Link Local/Remote Identifiers TLV's length (%u), it must be %u bytes!",
sub_length, BGP_NLRI_TLV_LEN_LINK_LOCAL_REMOTE_IDENTIFIERS);
return -1;
}
tlv_sub_item = proto_tree_add_item(tlv_tree,
hf_bgp_ls_tlv_link_local_remote_identifiers, tvb, offset,
sub_length + 4, ENC_NA);
tlv_sub_tree = proto_item_add_subtree(tlv_sub_item, ett_bgp_mp_reach_nlri);
break;
case BGP_NLRI_TLV_IPV4_INTERFACE_ADDRESS:
if(sub_length != BGP_NLRI_TLV_LEN_IPV4_INTERFACE_ADDRESS){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error,
"Unexpected IPv4 Interface Address TLV's length (%u), it must be %u bytes!",
sub_length, BGP_NLRI_TLV_LEN_IPV4_INTERFACE_ADDRESS);
return -1;
}
tlv_sub_item = proto_tree_add_item(tlv_tree,
hf_bgp_ls_tlv_ipv4_interface_address, tvb, offset,
sub_length + 4, ENC_NA);
tlv_sub_tree = proto_item_add_subtree(tlv_sub_item, ett_bgp_mp_reach_nlri);
break;
case BGP_NLRI_TLV_IPV4_NEIGHBOR_ADDRESS:
if(sub_length != BGP_NLRI_TLV_LEN_IPV4_NEIGHBOR_ADDRESS){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error,
"Unexpected IPv4 Neighbor Address TLV's length (%u), it must be %u bytes!",
sub_length, BGP_NLRI_TLV_LEN_IPV4_NEIGHBOR_ADDRESS);
return -1;
}
tlv_sub_item = proto_tree_add_item(tlv_tree,
hf_bgp_ls_tlv_ipv4_neighbor_address, tvb, offset,
sub_length + 4, ENC_NA);
tlv_sub_tree = proto_item_add_subtree(tlv_sub_item, ett_bgp_mp_reach_nlri);
break;
case BGP_NLRI_TLV_IPV6_INTERFACE_ADDRESS:
if(sub_length != BGP_NLRI_TLV_LEN_IPV6_INTERFACE_ADDRESS){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error,
"Unexpected IPv6 Interface Address TLV's length (%u), it must be %u bytes!",
sub_length, BGP_NLRI_TLV_LEN_IPV6_INTERFACE_ADDRESS);
return -1;
}
tlv_sub_item = proto_tree_add_item(tlv_tree,
hf_bgp_ls_tlv_ipv6_interface_address, tvb, offset,
sub_length + 4, ENC_NA);
tlv_sub_tree = proto_item_add_subtree(tlv_sub_item, ett_bgp_mp_reach_nlri);
break;
case BGP_NLRI_TLV_IPV6_NEIGHBOR_ADDRESS:
if(sub_length != BGP_NLRI_TLV_IPV6_NEIGHBOR_ADDRESS){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error,
"Unexpected IPv6 Neighbor Address TLV's length (%u), it must be %u bytes!",
sub_length, BGP_NLRI_TLV_IPV6_NEIGHBOR_ADDRESS);
return -1;
}
tlv_sub_item = proto_tree_add_item(tlv_tree,
hf_bgp_ls_tlv_ipv6_neighbor_address, tvb, offset,
sub_length + 4, ENC_NA);
tlv_sub_tree = proto_item_add_subtree(tlv_sub_item, ett_bgp_mp_reach_nlri);
break;
case BGP_NLRI_TLV_MULTI_TOPOLOGY_ID:
if(sub_length != BGP_NLRI_TLV_LEN_MULTI_TOPOLOGY_ID){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error,
"Unexpected Multi Topology ID TLV's length (%u), it must be %u bytes!",
sub_length, BGP_NLRI_TLV_LEN_MULTI_TOPOLOGY_ID);
return -1;
}
tlv_sub_item = proto_tree_add_item(tlv_tree,
hf_bgp_ls_tlv_multi_topology_id, tvb, offset, sub_length + 4,
ENC_NA);
tlv_sub_tree = proto_item_add_subtree(tlv_sub_item, ett_bgp_mp_reach_nlri);
break;
default:
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error,
"Unknown Link Descriptor TLV Code (%u)!", type);
return -1;
}
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
switch (type) {
case BGP_NLRI_TLV_LINK_LOCAL_REMOTE_IDENTIFIERS:
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_nlri_link_local_identifier, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_nlri_link_remote_identifier, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
break;
case BGP_NLRI_TLV_IPV4_INTERFACE_ADDRESS:
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_nlri_ipv4_interface_address, tvb, offset + 4,
BGP_NLRI_TLV_LEN_IPV4_INTERFACE_ADDRESS, ENC_BIG_ENDIAN);
break;
case BGP_NLRI_TLV_IPV4_NEIGHBOR_ADDRESS:
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_nlri_ipv4_neighbor_address, tvb, offset + 4,
BGP_NLRI_TLV_LEN_IPV4_INTERFACE_ADDRESS, ENC_BIG_ENDIAN);
break;
case BGP_NLRI_TLV_IPV6_INTERFACE_ADDRESS:
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_nlri_ipv6_interface_address, tvb, offset + 4,
BGP_NLRI_TLV_LEN_IPV6_INTERFACE_ADDRESS, ENC_NA);
break;
case BGP_NLRI_TLV_IPV6_NEIGHBOR_ADDRESS:
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_nlri_ipv6_neighbor_address, tvb, offset + 4,
BGP_NLRI_TLV_LEN_IPV6_INTERFACE_ADDRESS, ENC_NA);
break;
case BGP_NLRI_TLV_MULTI_TOPOLOGY_ID:
tmp16 = tvb_get_ntohs(tvb, offset + 4);
tmp16 >>= 12;
if(tmp16){
expert_add_info_format(pinfo, tlv_sub_tree, &ei_bgp_ls_error, "Reserved bits of Multi Topology ID must be set to zero! (%u)", tmp16);
}
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_nlri_multi_topology_id, tvb, offset + 4,
BGP_NLRI_TLV_LEN_MULTI_TOPOLOGY_ID, ENC_BIG_ENDIAN);
break;
}
length -= 4 + sub_length;
offset += 4 + sub_length;
diss_length += 4 + sub_length;
}
return diss_length;
}
static int decode_bgp_link_nlri_prefix_descriptors(tvbuff_t *tvb,
proto_tree *tree, gint offset, packet_info *pinfo, int length) {
guint16 sub_length;
guint16 type;
guint16 diss_length;
guint16 tmp16;
proto_item* tlv_item;
proto_tree* tlv_tree;
proto_item* tlv_sub_item;
proto_tree* tlv_sub_tree;
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_nlri_prefix_descriptors_tlv, tvb, offset, length + 4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_mp_reach_nlri);
diss_length = 0;
while (length > 0) {
if (length < 4) {
expert_add_info_format(pinfo, tree, &ei_bgp_ls_error,
"Unknown data in Link-State Link NLRI!");
diss_length += length;
break;
}
type = tvb_get_ntohs(tvb, offset);
sub_length = tvb_get_ntohs(tvb, offset + 2);
switch (type) {
case BGP_NLRI_TLV_MULTI_TOPOLOGY_ID:
if(sub_length != BGP_NLRI_TLV_LEN_MULTI_TOPOLOGY_ID){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error,
"Unexpected Multi Topology ID TLV's length (%u), it must be %u bytes!",
sub_length, BGP_NLRI_TLV_LEN_MULTI_TOPOLOGY_ID);
return -1;
}
tlv_sub_item = proto_tree_add_item(tlv_tree,
hf_bgp_ls_tlv_multi_topology_id, tvb, offset, sub_length + 4,
ENC_NA);
tlv_sub_tree = proto_item_add_subtree(tlv_sub_item, ett_bgp_mp_reach_nlri);
break;
case BGP_NLRI_TLV_OSPF_ROUTE_TYPE:
tlv_sub_item = proto_tree_add_item(tlv_tree,
hf_bgp_ls_tlv_ospf_route_type, tvb, offset, sub_length + 4,
ENC_NA);
tlv_sub_tree = proto_item_add_subtree(tlv_sub_item, ett_bgp_mp_reach_nlri);
break;
case BGP_NLRI_TLV_IP_REACHABILITY_INFORMATION:
tlv_sub_item = proto_tree_add_item(tlv_tree,
hf_bgp_ls_tlv_ip_reachability_information, tvb, offset, sub_length + 4,
ENC_NA);
tlv_sub_tree = proto_item_add_subtree(tlv_sub_item, ett_bgp_mp_reach_nlri);
break;
default:
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error,
"Unknown Prefix Descriptor TLV Code (%u)!", type);
return -1;
}
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
switch (type) {
case BGP_NLRI_TLV_MULTI_TOPOLOGY_ID:
tmp16 = tvb_get_ntohs(tvb, offset + 4);
tmp16 >>= 12;
if(tmp16){
expert_add_info_format(pinfo, tlv_sub_tree, &ei_bgp_ls_error, "Reserved bits of Multi Topology ID must be set to zero! (%u)", tmp16);
}
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_nlri_multi_topology_id, tvb, offset + 4,
BGP_NLRI_TLV_LEN_MULTI_TOPOLOGY_ID, ENC_BIG_ENDIAN);
break;
case BGP_NLRI_TLV_OSPF_ROUTE_TYPE:
if (sub_length != 1) {
expert_add_info_format(pinfo, tlv_sub_tree, &ei_bgp_ls_error, "OSPF Route Type length must be \"1\"");
break;
}
proto_tree_add_item(tlv_sub_tree, hf_bgp_ls_nlri_ospf_route_type, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
break;
case BGP_NLRI_TLV_IP_REACHABILITY_INFORMATION:
if (decode_prefix4(tlv_sub_tree, pinfo, tlv_sub_item, hf_bgp_ls_nlri_ip_reachability_prefix_ip,
tvb, offset + 4, 0, "Reachability") == -1)
return diss_length;
break;
}
length -= 4 + sub_length;
offset += 4 + sub_length;
diss_length += 4 + sub_length;
}
return diss_length;
}
static int
decode_link_state_attribute_tlv(proto_tree *tree, tvbuff_t *tvb, gint offset, packet_info *pinfo, guint8 protocol_id)
{
guint16 type;
guint16 length;
guint8 tmp8;
guint16 tmp16;
guint32 tmp32;
gfloat tmp_float;
guint32 mask;
int n;
proto_item* tlv_item;
proto_tree* tlv_tree;
proto_item* tlv_sub_item;
proto_tree* tlv_sub_tree;
type = tvb_get_ntohs(tvb, offset);
length = tvb_get_ntohs(tvb, offset + 2);
switch (type) {
case BGP_NLRI_TLV_MULTI_TOPOLOGY_ID:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_multi_topology_id, tvb, offset, length + 4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
for (n = 0; n < (length / BGP_NLRI_TLV_LEN_MULTI_TOPOLOGY_ID); n++) {
tmp16 = tvb_get_ntohs(tvb, offset + 4 + (n * BGP_NLRI_TLV_LEN_MULTI_TOPOLOGY_ID));
tmp16 >>= 12;
if(tmp16){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Reserved bits of Multi Topology ID must be set to zero! (%u)", tmp16);
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_nlri_multi_topology_id, tvb, offset + 4 + (n * BGP_NLRI_TLV_LEN_MULTI_TOPOLOGY_ID),
BGP_NLRI_TLV_LEN_MULTI_TOPOLOGY_ID, ENC_BIG_ENDIAN);
}
break;
case BGP_NLRI_TLV_NODE_FLAG_BITS:
{
static const int * flags[] = {
&hf_bgp_ls_node_flag_bits_overload,
&hf_bgp_ls_node_flag_bits_attached,
&hf_bgp_ls_node_flag_bits_external,
&hf_bgp_ls_node_flag_bits_abr,
NULL
};
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_node_flags_bits, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if(length != BGP_NLRI_TLV_LEN_NODE_FLAG_BITS){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected Node Flags Bits TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_LEN_NODE_FLAG_BITS);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask_list(tlv_tree, tvb, offset+4, 1, flags, ENC_NA);
tmp8 = tvb_get_guint8(tvb, offset+4) & 0x0f;
if(tmp8){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Reserved flag bits are not set to zero (%u).", tmp8);
}
}
break;
case BGP_NLRI_TLV_OPAQUE_NODE_PROPERTIES:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_opaque_node_properties, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_opaque_node_properties_value, tvb, offset + 4, length, ENC_NA);
break;
case BGP_NLRI_TLV_NODE_NAME:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_node_name, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_node_name_value, tvb, offset + 4, length, ENC_ASCII|ENC_NA);
break;
case BGP_NLRI_TLV_IS_IS_AREA_IDENTIFIER:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_is_is_area_identifier, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_is_is_area_identifier_value, tvb, offset + 4, length, ENC_NA);
break;
case BGP_LS_SR_TLV_SR_CAPABILITY:
{
static const int *sr_capabilities_flags[] = {
&hf_bgp_ls_sr_tlv_capabilities_flags_i,
&hf_bgp_ls_sr_tlv_capabilities_flags_v,
&hf_bgp_ls_sr_tlv_capabilities_flags_h,
&hf_bgp_ls_sr_tlv_capabilities_flags_reserved,
NULL
};
gint offset2;
gint remaining_data;
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_sr_tlv_capabilities, tvb, offset, length + 4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tlv_tree, tvb, offset + 4, hf_bgp_ls_sr_tlv_capabilities_flags,
ett_bgp_link_state, sr_capabilities_flags, ENC_BIG_ENDIAN);
offset2 = offset + 4 + 2;
remaining_data = length - 2;
while (remaining_data > 0) {
guint16 sid_len = 0;
proto_tree_add_item(tlv_tree, hf_bgp_ls_sr_tlv_capabilities_range_size, tvb, offset2, 3, ENC_BIG_ENDIAN);
offset2 += 3;
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset2, 2, ENC_BIG_ENDIAN);
offset2 += 2;
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset2, 2, ENC_BIG_ENDIAN);
sid_len = tvb_get_ntohs(tvb, offset2);
offset2 += 2;
if (sid_len == 3) {
proto_tree_add_item(tlv_tree, hf_bgp_ls_sr_tlv_capabilities_sid_label, tvb, offset2, 3, ENC_BIG_ENDIAN);
offset2 += 3;
remaining_data -= 10;
} else {
proto_tree_add_item(tlv_tree, hf_bgp_ls_sr_tlv_capabilities_sid_index, tvb, offset2, 4, ENC_BIG_ENDIAN);
offset2 += 4;
remaining_data -= 11;
}
}
}
break;
case BGP_LS_SR_TLV_SR_ALGORITHM:
{
gint offset2;
gint remaining_data;
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_sr_tlv_algorithm, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
offset2 = offset + 4;
remaining_data = length;
while (remaining_data > 0) {
proto_tree_add_item(tlv_tree, hf_bgp_ls_sr_tlv_algorithm_value, tvb, offset2, 1, ENC_NA);
offset2 += 1;
remaining_data -= 1;
}
}
break;
case BGP_NLRI_TLV_IPV4_ROUTER_ID_OF_LOCAL_NODE:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_ipv4_router_id_of_local_node, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if(length != BGP_NLRI_TLV_LEN_IPV4_ROUTER_ID_OF_LOCAL_NODE){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected IPv4 Router-ID TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_LEN_IPV4_ROUTER_ID_OF_LOCAL_NODE);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_ipv4_router_id_value, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
break;
case BGP_NLRI_TLV_IPV6_ROUTER_ID_OF_LOCAL_NODE:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_ipv6_router_id_of_local_node, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if(length != BGP_NLRI_TLV_LEN_IPV6_ROUTER_ID_OF_LOCAL_NODE){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected IPv6 Router-ID TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_LEN_IPV6_ROUTER_ID_OF_LOCAL_NODE);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_ipv6_router_id_value, tvb, offset + 4, BGP_NLRI_TLV_LEN_IPV6_ROUTER_ID_OF_LOCAL_NODE, ENC_NA);
break;
case BGP_NLRI_TLV_IPV4_ROUTER_ID_OF_REMOTE_NODE:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_ipv4_router_id_of_remote_node, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if(length != BGP_NLRI_TLV_LEN_IPV4_ROUTER_ID_OF_REMOTE_NODE){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected IPv4 Router-ID TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_LEN_IPV4_ROUTER_ID_OF_REMOTE_NODE);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_ipv4_router_id_value, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
break;
case BGP_NLRI_TLV_IPV6_ROUTER_ID_OF_REMOTE_NODE:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_ipv6_router_id_of_remote_node, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if(length != BGP_NLRI_TLV_LEN_IPV6_ROUTER_ID_OF_REMOTE_NODE){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected IPv6 Router-ID TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_LEN_IPV6_ROUTER_ID_OF_REMOTE_NODE);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_ipv6_router_id_value, tvb, offset + 4, BGP_NLRI_TLV_LEN_IPV6_ROUTER_ID_OF_REMOTE_NODE, ENC_NA);
break;
case BGP_NLRI_TLV_ADMINISTRATIVE_GROUP_COLOR:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_administrative_group_color, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if(length != BGP_NLRI_TLV_LEN_ADMINISTRATIVE_GROUP_COLOR){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected Administrative group (color) TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_LEN_ADMINISTRATIVE_GROUP_COLOR);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
tmp32 = tvb_get_ntohl(tvb, offset + 4);
tlv_sub_item = proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_administrative_group_color_value, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
tlv_sub_tree = proto_item_add_subtree(tlv_sub_item, ett_bgp_prefix);
mask = 1;
for(n = 0; n<32; n++){
if( tmp32 & mask ) proto_tree_add_uint(tlv_sub_tree, hf_bgp_ls_tlv_administrative_group, tvb, offset + 4, 4, n);
mask <<= 1;
}
break;
case BGP_NLRI_TLV_MAX_LINK_BANDWIDTH:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_max_link_bandwidth, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if(length != BGP_NLRI_TLV_LEN_MAX_LINK_BANDWIDTH){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected Maximum link bandwidth TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_LEN_MAX_LINK_BANDWIDTH);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
tmp_float = tvb_get_ntohieee_float(tvb, offset + 4)*8/1000000;
proto_tree_add_float_format(tlv_tree, hf_bgp_ls_bandwidth_value, tvb, offset + 4, 4, tmp_float, "Maximum link bandwidth: %.2f Mbps", tmp_float);
break;
case BGP_NLRI_TLV_MAX_RESERVABLE_LINK_BANDWIDTH:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_max_reservable_link_bandwidth, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if(length != BGP_NLRI_TLV_LEN_MAX_RESERVABLE_LINK_BANDWIDTH){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected Maximum reservable link bandwidth TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_LEN_MAX_RESERVABLE_LINK_BANDWIDTH);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
tmp_float = tvb_get_ntohieee_float(tvb, offset + 4)*8/1000000;
proto_tree_add_float_format(tlv_tree, hf_bgp_ls_bandwidth_value, tvb, offset + 4, 4, tmp_float, "Maximum reservable link bandwidth: %.2f Mbps", tmp_float);
break;
case BGP_NLRI_TLV_UNRESERVED_BANDWIDTH:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_unreserved_bandwidth, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if(length != BGP_NLRI_TLV_LEN_UNRESERVED_BANDWIDTH){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected Unreserved bandwidth TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_LEN_UNRESERVED_BANDWIDTH);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
for(n = 0; n<8; n++){
tmp_float = tvb_get_ntohieee_float(tvb, offset + 4 + (4 * n))*8/1000000;
tlv_sub_item = proto_tree_add_float_format(tlv_tree, hf_bgp_ls_bandwidth_value, tvb, offset + 4 + (4 * n), 4, tmp_float, "Unreserved Bandwidth: %.2f Mbps", tmp_float);
proto_item_prepend_text(tlv_sub_item, "Priority %u, ", n);
}
break;
case BGP_NLRI_TLV_TE_DEFAULT_METRIC:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_te_default_metric, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if (length == BGP_NLRI_TLV_LEN_TE_DEFAULT_METRIC_OLD) {
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_warn,
"Old TE Default Metric TLV's length (%u), it should be %u bytes!",
length,
BGP_NLRI_TLV_LEN_TE_DEFAULT_METRIC_NEW);
}
if (length != BGP_NLRI_TLV_LEN_TE_DEFAULT_METRIC_OLD && length != BGP_NLRI_TLV_LEN_TE_DEFAULT_METRIC_NEW) {
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error,
"Unexpected TE Default Metric TLV's length (%u), it must be %u or %u bytes!",
length,
BGP_NLRI_TLV_LEN_TE_DEFAULT_METRIC_OLD,
BGP_NLRI_TLV_LEN_TE_DEFAULT_METRIC_NEW);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (length == BGP_NLRI_TLV_LEN_TE_DEFAULT_METRIC_OLD) {
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_te_default_metric_value_old, tvb, offset + 4, 3, ENC_BIG_ENDIAN);
} else if (length == BGP_NLRI_TLV_LEN_TE_DEFAULT_METRIC_NEW) {
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_te_default_metric_value, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
}
break;
case BGP_NLRI_TLV_LINK_PROTECTION_TYPE:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_link_protection_type, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if(length != BGP_NLRI_TLV_LEN_LINK_PROTECTION_TYPE){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected Link Protection Type TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_LEN_LINK_PROTECTION_TYPE);
break;
}
else {
static const int * nlri_flags[] = {
&hf_bgp_ls_link_protection_type_extra_traffic,
&hf_bgp_ls_link_protection_type_unprotected,
&hf_bgp_ls_link_protection_type_shared,
&hf_bgp_ls_link_protection_type_dedicated_1to1,
&hf_bgp_ls_link_protection_type_dedicated_1plus1,
&hf_bgp_ls_link_protection_type_enhanced,
NULL
};
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
tmp8 = tvb_get_guint8(tvb, offset + 4);
tlv_sub_item = proto_tree_add_bitmask(tlv_tree, tvb, offset + 4, hf_bgp_ls_tlv_link_protection_type_value, ett_bgp_mp_reach_nlri, nlri_flags, ENC_NA);
tmp8 >>= 6;
if(tmp8){
expert_add_info_format(pinfo, tlv_sub_item, &ei_bgp_ls_error, "Reserved Protection Capabilities bits are not set to zero (%u).", tmp8);
}
tmp8 = tvb_get_guint8(tvb, offset + 4 + 1);
if(tmp8){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Reserved field is not set to zero. (%u)", tmp8);
}
}
break;
case BGP_NLRI_TLV_MPLS_PROTOCOL_MASK:
{
static const int * flags[] = {
&hf_bgp_ls_mpls_protocol_mask_flag_l,
&hf_bgp_ls_mpls_protocol_mask_flag_r,
NULL
};
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_mpls_protocol_mask, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if(length != BGP_NLRI_TLV_LEN_MPLS_PROTOCOL_MASK){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected MPLS Protocol Mask TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_LEN_MPLS_PROTOCOL_MASK);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask_list(tlv_tree, tvb, offset+4, 1, flags, ENC_NA);
tmp8 = tvb_get_guint8(tvb, offset + 4) & 0x3f;
if(tmp8){
proto_tree_add_expert_format(tlv_tree, pinfo, &ei_bgp_ls_error, tvb, offset + 4, 1,
"Reserved flags are not set to zero (%u).", tmp8);
}
}
break;
case BGP_NLRI_TLV_METRIC:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_metric, tvb, offset, length + 4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if (length > BGP_NLRI_TLV_LEN_MAX_METRIC) {
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error,
"Unexpected Metric TLV's length (%u), it must be less than %u bytes!",
length, BGP_NLRI_TLV_LEN_MAX_METRIC);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (length == 1) {
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_metric_value1, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
} else if (length == 2) {
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_metric_value2, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
} else if (length == 3) {
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_metric_value3, tvb, offset + 4, 3, ENC_BIG_ENDIAN);
}
break;
case BGP_NLRI_TLV_SHARED_RISK_LINK_GROUP:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_shared_risk_link_group, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
tmp16 = length;
n = 0;
while(tmp16 > 0){
if(tmp16 < 4) {
proto_tree_add_expert_format(tlv_tree, pinfo, &ei_bgp_ls_error,
tvb, offset + 4 + (n * 4), tmp16,
"Shared Risk Link Group Value must be 4 bytes long (%u).", tmp16);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_shared_risk_link_group_value, tvb, offset + 4 + (n * 4), 4, ENC_BIG_ENDIAN);
tmp16 -= 4;
n++;
}
break;
case BGP_NLRI_TLV_OPAQUE_LINK_ATTRIBUTE:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_opaque_link_attribute, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_opaque_link_attribute_value, tvb, offset + 4, length, ENC_NA);
break;
case BGP_NLRI_TLV_LINK_NAME_ATTRIBUTE:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_link_name_attribute, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_link_name_attribute_value, tvb, offset + 4, length, ENC_ASCII|ENC_NA);
break;
case BGP_LS_SR_TLV_ADJ_SID:
{
static const int *adj_sid_isis_flags[] = {
&hf_bgp_ls_sr_tlv_adjacency_sid_flags_fi,
&hf_bgp_ls_sr_tlv_adjacency_sid_flags_bi,
&hf_bgp_ls_sr_tlv_adjacency_sid_flags_vi,
&hf_bgp_ls_sr_tlv_adjacency_sid_flags_li,
&hf_bgp_ls_sr_tlv_adjacency_sid_flags_si,
NULL
};
static const int *adj_sid_ospf_flags[] = {
&hf_bgp_ls_sr_tlv_adjacency_sid_flags_bo,
&hf_bgp_ls_sr_tlv_adjacency_sid_flags_vo,
&hf_bgp_ls_sr_tlv_adjacency_sid_flags_lo,
&hf_bgp_ls_sr_tlv_adjacency_sid_flags_so,
NULL
};
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_sr_tlv_adjacency_sid, tvb, offset, length + 4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (protocol_id == BGP_LS_NLRI_PROTO_ID_OSPF) {
proto_tree_add_bitmask(tlv_tree, tvb, offset + 4, hf_bgp_ls_sr_tlv_adjacency_sid_flags,
ett_bgp_link_state, adj_sid_ospf_flags, ENC_BIG_ENDIAN);
} else {
proto_tree_add_bitmask(tlv_tree, tvb, offset + 4, hf_bgp_ls_sr_tlv_adjacency_sid_flags,
ett_bgp_link_state, adj_sid_isis_flags, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_sr_tlv_adjacency_sid_weight, tvb, offset + 5, 1, ENC_BIG_ENDIAN);
if (length == 7) {
proto_tree_add_item(tlv_tree, hf_bgp_ls_sr_tlv_adjacency_sid_label, tvb, offset + 8, 3, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tlv_tree, hf_bgp_ls_sr_tlv_adjacency_sid_index, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
}
}
break;
case BGP_LS_SR_TLV_LAN_ADJ_SID:
break;
case BGP_NLRI_TLV_IGP_FLAGS:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_igp_flags, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if(length != BGP_NLRI_TLV_LEN_IGP_FLAGS){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected IGP Flags TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_IGP_FLAGS);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_igp_flags_flag_d, tvb, offset + 4, 1, ENC_NA);
tmp8 = tvb_get_guint8(tvb, offset + 4) & 0x7F;
if(tmp8){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Reserved flags are not set to zero (%u).", tmp8);
}
break;
case BGP_NLRI_TLV_ROUTE_TAG:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_route_tag, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if(length % 4 != 0) {
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected Route Tag TLV's length (%u mod 4 != 0) ",
length);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
tmp16 = length;
n = 0;
while(tmp16){
if(tmp16 < 4) {
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Route Tag must be 4 bytes long (%u).", tmp16);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_route_tag_value, tvb, offset + 4 + (n * 4), 4, ENC_BIG_ENDIAN);
tmp16 -= 4;
n++;
}
break;
case BGP_NLRI_TLV_EXTENDED_TAG:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_route_extended_tag, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if(length % 8 != 0) {
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected Route Extended Tag TLV's length (%u mod 8 != 0) ",
length);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
tmp16 = length;
n = 0;
while(tmp16){
if(tmp16 < 8) {
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Route Extended Tag must be 8 bytes long (%u).", tmp16);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_route_extended_tag_value, tvb, offset + 4 + (n * 8), 8, ENC_BIG_ENDIAN);
tmp16 -= 8;
n++;
}
break;
case BGP_NLRI_TLV_PREFIX_METRIC:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_tlv_prefix_metric, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
if(length != BGP_NLRI_TLV_LEN_PREFIX_METRIC){
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected Prefix Metric TLV's length (%u), it must be %u bytes!",
length, BGP_NLRI_TLV_LEN_PREFIX_METRIC);
break;
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_tlv_prefix_metric_value, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
break;
case BGP_NLRI_TLV_OSPF_FORWARDING_ADDRESS:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_ospf_forwarding_address, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (length == 4) {
proto_tree_add_item(tlv_tree, hf_bgp_ls_ospf_forwarding_address_ipv4_address, tvb, offset + 4, length, ENC_BIG_ENDIAN);
}
else if (length == 16) {
proto_tree_add_item(tlv_tree, hf_bgp_ls_ospf_forwarding_address_ipv6_address, tvb, offset + 4, length, ENC_NA);
}
else {
expert_add_info_format(pinfo, tlv_tree, &ei_bgp_ls_error, "Unexpected Prefix Metric TLV's length (%u), it must be 4 or 16 bytes!", length);
break;
}
break;
case BGP_NLRI_TLV_OPAQUE_PREFIX_ATTRIBUTE:
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_opaque_prefix_attribute, tvb, offset, length+4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_opaque_prefix_attribute_value, tvb, offset + 4, length, ENC_NA);
break;
case BGP_LS_SR_TLV_PREFIX_SID:
{
static const int *prefix_sid_isis_flags[] = {
&hf_bgp_ls_sr_tlv_prefix_sid_flags_r,
&hf_bgp_ls_sr_tlv_prefix_sid_flags_n,
&hf_bgp_ls_sr_tlv_prefix_sid_flags_p,
&hf_bgp_ls_sr_tlv_prefix_sid_flags_e,
&hf_bgp_ls_sr_tlv_prefix_sid_flags_v,
&hf_bgp_ls_sr_tlv_prefix_sid_flags_l,
NULL
};
static const int *prefix_sid_ospf_flags[] = {
&hf_bgp_ls_sr_tlv_prefix_sid_flags_np,
&hf_bgp_ls_sr_tlv_prefix_sid_flags_m,
&hf_bgp_ls_sr_tlv_prefix_sid_flags_e,
&hf_bgp_ls_sr_tlv_prefix_sid_flags_v,
&hf_bgp_ls_sr_tlv_prefix_sid_flags_l,
NULL
};
tlv_item = proto_tree_add_item(tree, hf_bgp_ls_sr_tlv_prefix_sid, tvb, offset, length + 4, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_bgp_link_state);
proto_tree_add_item(tlv_tree, hf_bgp_ls_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_bgp_ls_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (protocol_id == BGP_LS_NLRI_PROTO_ID_OSPF) {
proto_tree_add_bitmask(tlv_tree, tvb, offset + 4, hf_bgp_ls_sr_tlv_prefix_sid_flags,
ett_bgp_link_state, prefix_sid_ospf_flags, ENC_BIG_ENDIAN);
} else {
proto_tree_add_bitmask(tlv_tree, tvb, offset + 4, hf_bgp_ls_sr_tlv_prefix_sid_flags,
ett_bgp_link_state, prefix_sid_isis_flags, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tlv_tree, hf_bgp_ls_sr_tlv_prefix_sid_algo, tvb, offset + 5, 1, ENC_BIG_ENDIAN);
if (length == 7) {
proto_tree_add_item(tlv_tree, hf_bgp_ls_sr_tlv_prefix_sid_label, tvb, offset + 8, 3, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tlv_tree, hf_bgp_ls_sr_tlv_prefix_sid_index, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
}
}
break;
case BGP_LS_SR_TLV_RANGE:
break;
case BGP_LS_SR_TLV_BINDING_SID:
break;
default:
expert_add_info_format(pinfo, tree, &ei_bgp_ls_error,
"Unknown Prefix Descriptor TLV Code (%u)!", type);
break;
}
return length + 4;
}
static int decode_evpn_nlri_esi(proto_tree *tree, tvbuff_t *tvb, gint offset, packet_info *pinfo) {
guint8 esi_type = 0;
proto_tree *esi_tree;
proto_item *ti;
wmem_allocator_t *buffer_value_string = NULL;
ti = proto_tree_add_item(tree, hf_bgp_evpn_nlri_esi, tvb, offset, 10, ENC_NA);
esi_tree = proto_item_add_subtree(ti, ett_bgp_evpn_nlri_esi);
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_type, tvb, offset, 1, ENC_BIG_ENDIAN);
esi_type = tvb_get_guint8(tvb, offset);
switch (esi_type) {
case BGP_NLRI_EVPN_ESI_VALUE :
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_value, tvb,
offset+1, 9, ENC_NA);
proto_item_append_text(ti, ": %s",
tvb_bytes_to_str_punct(buffer_value_string, tvb, offset + 1, 9, ' '));
break;
case BGP_NLRI_EVPN_ESI_LACP :
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_lacp_mac, tvb,
offset+1, 6, ENC_NA);
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_portk, tvb,
offset+7, 2, ENC_NA);
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_remain, tvb,
offset+9, 1, ENC_NA);
proto_item_append_text(ti, ": %s, Key: %s",
tvb_ether_to_str(tvb,offset+1),
tvb_bytes_to_str_punct(buffer_value_string, tvb, offset + 7, 2, ' '));
break;
case BGP_NLRI_EVPN_ESI_MSTP :
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_rb_mac, tvb,
offset+1, 6, ENC_NA);
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_rbprio, tvb,
offset+7, 2, ENC_NA);
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_remain, tvb,
offset+9, 1, ENC_NA);
proto_item_append_text(ti, ": %s, Priority: %s",
tvb_ether_to_str(tvb,offset+1),
tvb_bytes_to_str_punct(buffer_value_string, tvb, offset + 7, 2, ' '));
break;
case BGP_NLRI_EVPN_ESI_MAC :
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_sys_mac, tvb,
offset+1, 6, ENC_NA);
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_mac_discr, tvb,
offset+7, 2, ENC_NA);
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_remain, tvb,
offset+9, 1, ENC_NA);
proto_item_append_text(ti, ": %s, Discriminator: %s",
tvb_ether_to_str(tvb,offset+1),
tvb_bytes_to_str_punct(buffer_value_string, tvb, offset + 7, 2, ' '));
break;
case BGP_NLRI_EVPN_ESI_RID :
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_router_id, tvb,
offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_router_discr, tvb,
offset+5, 4, ENC_NA);
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_remain, tvb,
offset+9, 1, ENC_NA);
proto_item_append_text(ti, ": %s, Discriminator: %s",
tvb_ip_to_str(tvb,offset+1),
tvb_bytes_to_str_punct(buffer_value_string, tvb, offset + 5, 4, ' '));
break;
case BGP_NLRI_EVPN_ESI_ASN :
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_asn, tvb,
offset+1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_asn_discr, tvb,
offset+5, 4, ENC_NA);
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_remain, tvb,
offset+9, 1, ENC_NA);
proto_item_append_text(ti, ": %u, Discriminator: %s",
tvb_get_ntohl(tvb,offset+1),
tvb_bytes_to_str_punct(buffer_value_string, tvb, offset + 5, 4, ' '));
break;
case BGP_NLRI_EVPN_ESI_RES :
proto_tree_add_item(esi_tree, hf_bgp_evpn_nlri_esi_reserved, tvb,
offset+1, 9, ENC_NA);
break;
default :
expert_add_info_format(pinfo, tree, &ei_bgp_evpn_nlri_esi_type_err,
"Invalid EVPN ESI (%u)!", esi_type);
return (-1);
}
return(0);
}
static int decode_evpn_nlri(proto_tree *tree, tvbuff_t *tvb, gint offset, packet_info *pinfo) {
int start_offset = offset;
proto_tree *prefix_tree;
proto_item *ti;
guint8 route_type;
guint labnum;
guint8 nlri_len;
guint8 ip_len;
guint32 total_length = 0;
proto_item *item;
wmem_strbuf_t *stack_strbuf;
route_type = tvb_get_guint8(tvb, offset);
if (route_type == 0 || route_type > 5) {
expert_add_info_format(pinfo, tree, &ei_bgp_evpn_nlri_rt_type_err,
"Invalid EVPN Route Type (%u)!", route_type);
return -1;
}
nlri_len = tvb_get_guint8(tvb, offset + 1);
ti = proto_tree_add_item(tree, hf_bgp_evpn_nlri, tvb, start_offset,
nlri_len+2, ENC_NA);
prefix_tree = proto_item_add_subtree(ti, ett_bgp_evpn_nlri);
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_rt, tvb, start_offset,
1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": %s", val_to_str(tvb_get_guint8(tvb, offset), evpnrtypevals, "Unknown capability %d"));
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_len, tvb, start_offset+1,
1, ENC_BIG_ENDIAN);
if (route_type == EVPN_ETH_SEGMENT_ROUTE && nlri_len < 21) {
expert_add_info_format(pinfo, prefix_tree, &ei_bgp_evpn_nlri_rt4_len_err,
"Invalid length (%u) of EVPN NLRI Route Type 4 (Ethernet Segment Route)!", nlri_len);
return -1;
}
item = proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_rd, tvb, start_offset+2,
8, ENC_NA);
proto_item_append_text(item, " (%s)", decode_bgp_rd(tvb, offset + 2));
switch (route_type) {
case EVPN_AD_ROUTE:
decode_evpn_nlri_esi(prefix_tree, tvb, start_offset+10, pinfo);
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_etag, tvb, start_offset+20,
4, ENC_BIG_ENDIAN);
stack_strbuf = wmem_strbuf_new_label(wmem_packet_scope());
labnum = decode_MPLS_stack(tvb, offset + 24,
stack_strbuf);
proto_tree_add_string(prefix_tree, hf_bgp_evpn_nlri_mpls_ls, tvb, start_offset+24,
labnum*3, wmem_strbuf_get_str(stack_strbuf));
total_length = 25 + 2;
break;
case EVPN_MAC_ROUTE:
decode_evpn_nlri_esi(prefix_tree, tvb, start_offset+10, pinfo);
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_etag, tvb, start_offset+20,
4, ENC_BIG_ENDIAN);
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_maclen, tvb, start_offset+24,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_mac_addr, tvb, start_offset+25,
6, ENC_NA);
ip_len = tvb_get_guint8(tvb, offset + 31) / 8;
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_iplen, tvb, start_offset+31,
1, ENC_BIG_ENDIAN);
total_length = 31;
if (ip_len == 4) {
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_ip_addr, tvb, start_offset+32,
4, ENC_NA);
total_length += 4;
} else if (ip_len == 16) {
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_ipv6_addr, tvb, start_offset+32,
16, ENC_NA);
total_length += 16;
} else if (ip_len == 0) {
proto_tree_add_expert(prefix_tree, pinfo, &ei_bgp_evpn_nlri_rt4_no_ip, tvb, start_offset+32, 1);
} else {
return -1;
}
stack_strbuf = wmem_strbuf_new_label(wmem_packet_scope());
labnum = decode_MPLS_stack(tvb, offset + total_length + 1,
stack_strbuf);
proto_tree_add_string(prefix_tree, hf_bgp_evpn_nlri_mpls_ls, tvb, start_offset+total_length+1,
labnum*3, wmem_strbuf_get_str(stack_strbuf));
total_length = total_length + 4;
break;
case EVPN_INC_MCAST_TREE:
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_etag, tvb, start_offset+10,
4, ENC_BIG_ENDIAN);
ip_len = tvb_get_guint8(tvb, offset + 14) / 8;
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_iplen, tvb, start_offset+14,
1, ENC_BIG_ENDIAN);
total_length = 15;
if (ip_len == 4) {
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_ip_addr, tvb, start_offset+15,
4, ENC_NA);
total_length += 4;
} else if (ip_len == 16) {
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_ipv6_addr, tvb, start_offset+15,
16, ENC_NA);
total_length += 16;
} else if (ip_len == 0) {
proto_tree_add_expert(prefix_tree, pinfo, &ei_bgp_evpn_nlri_rt4_no_ip, tvb, start_offset, 1);
} else {
expert_add_info_format(pinfo, prefix_tree, &ei_bgp_evpn_nlri_rt4_len_err,
"Invalid length of IP Address (%u) in EVPN NLRI Route Type 3 (Iclusive Multicast Tree Route)!", ip_len);
return -1;
}
break;
case EVPN_ETH_SEGMENT_ROUTE:
decode_evpn_nlri_esi(prefix_tree, tvb, start_offset+10, pinfo);
ip_len = tvb_get_guint8(tvb, offset + 20) / 8;
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_iplen, tvb, start_offset+20,
1, ENC_BIG_ENDIAN);
total_length = 21;
if (ip_len == 4) {
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_ip_addr, tvb, start_offset+21,
4, ENC_NA);
total_length += 4;
} else if (ip_len == 16) {
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_ipv6_addr, tvb, start_offset+21,
16, ENC_NA);
total_length += 16;
} else if (ip_len == 0) {
proto_tree_add_expert(prefix_tree, pinfo, &ei_bgp_evpn_nlri_rt4_no_ip, tvb, start_offset, 1);
} else {
expert_add_info_format(pinfo, prefix_tree, &ei_bgp_evpn_nlri_rt4_len_err,
"Invalid length of IP Address (%u) in EVPN NLRI Route Type 4 (Ethernet Segment Route)!", ip_len);
return -1;
}
break;
case EVPN_IP_PREFIX_ROUTE:
decode_evpn_nlri_esi(prefix_tree, tvb, start_offset+10, pinfo);
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_etag, tvb, start_offset+20,
4, ENC_BIG_ENDIAN);
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_prefix_len, tvb, start_offset+24,
1, ENC_BIG_ENDIAN);
switch (nlri_len) {
case 34 :
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_ip_addr, tvb, start_offset+25,
4, ENC_NA);
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_ipv4_gtw, tvb, start_offset+29,
4, ENC_NA);
decode_MPLS_stack_tree(tvb, start_offset+33, prefix_tree);
total_length = 36;
break;
case 58 :
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_ipv6_addr, tvb, start_offset+25,
16, ENC_NA);
proto_tree_add_item(prefix_tree, hf_bgp_evpn_nlri_ipv6_gtw, tvb, start_offset+41,
16, ENC_NA);
decode_MPLS_stack_tree(tvb, start_offset+57, prefix_tree);
total_length = 60;
break;
default :
expert_add_info_format(pinfo, prefix_tree, &ei_bgp_evpn_nlri_rt4_len_err,
"Invalid total nlri length (%u) in EVPN NLRI Route Type 5 (IP prefix Route)!", nlri_len);
return -1;
}
break;
default:
return -1;
}
return total_length;
}
static int
decode_prefix_MP(proto_tree *tree, int hf_addr4, int hf_addr6,
guint16 afi, guint8 safi, tvbuff_t *tvb, gint offset,
const char *tag, packet_info *pinfo)
{
int start_offset = offset;
proto_item *ti;
proto_tree *prefix_tree;
proto_item *nlri_ti;
proto_tree *nlri_tree;
proto_item *disting_item;
proto_tree *disting_tree;
int total_length;
int length;
int tmp_length;
guint plen;
guint labnum;
guint16 tnl_id;
union {
guint8 addr_bytes[4];
guint32 addr;
} ip4addr;
address addr;
struct e_in6_addr ip6addr;
guint16 rd_type;
guint16 nlri_type;
guint16 tmp16;
wmem_strbuf_t *stack_strbuf;
wmem_strbuf_t *comm_strbuf;
switch (afi) {
case AFNUM_INET:
switch (safi) {
case SAFNUM_UNICAST:
case SAFNUM_MULCAST:
case SAFNUM_UNIMULC:
total_length = decode_prefix4(tree, pinfo, NULL,hf_addr4, tvb, offset, 0, tag);
if (total_length < 0)
return -1;
break;
case SAFNUM_MPLS_LABEL:
plen = tvb_get_guint8(tvb, offset);
stack_strbuf = wmem_strbuf_new_label(wmem_packet_scope());
labnum = decode_MPLS_stack(tvb, offset + 1, stack_strbuf);
offset += (1 + labnum * 3);
if (plen <= (labnum * 3*8)) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Labeled IPv4 prefix length %u invalid",
tag, plen);
return -1;
}
plen -= (labnum * 3*8);
length = tvb_get_ipv4_addr_with_prefix_len(tvb, offset, ip4addr.addr_bytes, plen);
if (length < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Labeled IPv4 prefix length %u invalid",
tag, plen + (labnum * 3*8));
return -1;
}
set_address(&addr, AT_IPv4, 4, ip4addr.addr_bytes);
prefix_tree = proto_tree_add_subtree_format(tree, tvb, start_offset,
(offset + length) - start_offset,
ett_bgp_prefix, NULL,
"Label Stack=%s IPv4=%s/%u",
wmem_strbuf_get_str(stack_strbuf),
address_to_str(wmem_packet_scope(), &addr), plen);
proto_tree_add_uint_format(prefix_tree, hf_bgp_prefix_length, tvb, start_offset, 1, plen + labnum * 3 * 8,
"%s Prefix length: %u", tag, plen + labnum * 3 * 8);
proto_tree_add_string_format(prefix_tree, hf_bgp_label_stack, tvb, start_offset + 1, 3 * labnum, wmem_strbuf_get_str(stack_strbuf),
"%s Label Stack: %s", tag, wmem_strbuf_get_str(stack_strbuf));
proto_tree_add_ipv4(prefix_tree, hf_addr4, tvb, offset,
length, ip4addr.addr);
total_length = (1 + labnum*3) + length;
break;
case SAFNUM_MCAST_VPN:
total_length = decode_mcast_vpn_nlri(tree, tvb, offset, afi);
if (total_length < 0)
return -1;
break;
case SAFNUM_MDT:
total_length = decode_mdt_safi(tree, tvb, offset);
if (total_length < 0)
return -1;
break;
case SAFNUM_ROUTE_TARGET:
plen = tvb_get_guint8(tvb, offset);
if (plen == 0) {
proto_tree_add_string(tree, hf_bgp_wildcard_route_target, tvb, offset, 1, tag);
total_length = 1;
break;
}
if ((plen < 32) || (plen > 96)) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_length_invalid, tvb, offset, 1,
"%s Route target length %u invalid",
tag, plen);
return -1;
}
length = (plen + 7)/8;
comm_strbuf = wmem_strbuf_new_label(wmem_packet_scope());
switch (tvb_get_ntohs(tvb, offset + 1 + 4)) {
case BGP_EXT_COM_RT_AS2:
wmem_strbuf_append_printf(comm_strbuf, "%u:%u",
tvb_get_ntohs(tvb, offset + 1 + 6),
tvb_get_ntohl(tvb, offset + 1 + 8));
break;
case BGP_EXT_COM_RT_IP4:
wmem_strbuf_append_printf(comm_strbuf, "%s:%u",
tvb_ip_to_str(tvb, offset + 1 + 6),
tvb_get_ntohs(tvb, offset + 1 + 10));
break;
case BGP_EXT_COM_RT_AS4:
wmem_strbuf_append_printf(comm_strbuf, "%u:%u",
tvb_get_ntohl(tvb, 6),
tvb_get_ntohs(tvb, offset + 1 + 10));
break;
default:
wmem_strbuf_append_printf(comm_strbuf, "Invalid RT type");
break;
}
prefix_tree = proto_tree_add_subtree_format(tree, tvb, offset + 1, length,
ett_bgp_prefix, NULL, "%s %u:%s/%u",
tag, tvb_get_ntohl(tvb, offset + 1 + 0),
wmem_strbuf_get_str(comm_strbuf),
plen);
proto_tree_add_item(prefix_tree, hf_bgp_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(prefix_tree, hf_bgp_originating_as, tvb, offset + 1, 4, ENC_BIG_ENDIAN);
proto_tree_add_string(prefix_tree, hf_bgp_community_prefix, tvb, offset + 1 + 4, length - 4, wmem_strbuf_get_str(comm_strbuf));
total_length = 1 + length;
break;
case SAFNUM_ENCAPSULATION:
plen = tvb_get_guint8(tvb, offset);
if (plen != 32){
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_length_invalid, tvb, offset, 1,
"%s IPv4 address length %u invalid",
tag, plen);
return -1;
}
offset += 1;
proto_tree_add_item(tree, hf_bgp_endpoint_address, tvb, offset, 4, ENC_NA);
total_length = 5;
break;
case SAFNUM_TUNNEL:
plen = tvb_get_guint8(tvb, offset);
if (plen <= 16){
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Tunnel IPv4 prefix length %u invalid",
tag, plen);
return -1;
}
tnl_id = tvb_get_ntohs(tvb, offset + 1);
offset += 3;
plen -= 16;
length = tvb_get_ipv4_addr_with_prefix_len(tvb, offset, ip4addr.addr_bytes, plen);
if (length < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Tunnel IPv4 prefix length %u invalid",
tag, plen + 16);
return -1;
}
set_address(&addr, AT_IPv4, 4, ip4addr.addr_bytes);
prefix_tree = proto_tree_add_subtree_format(tree, tvb, start_offset,
(offset + length) - start_offset,
ett_bgp_prefix, NULL,
"Tunnel Identifier=0x%x IPv4=%s/%u",
tnl_id, address_to_str(wmem_packet_scope(), &addr), plen);
proto_tree_add_item(prefix_tree, hf_bgp_prefix_length, tvb, start_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(prefix_tree, hf_bgp_mp_nlri_tnl_id, tvb,
start_offset + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_ipv4(prefix_tree, hf_addr4, tvb, offset,
length, ip4addr.addr);
total_length = 1 + 2 + length;
break;
case SAFNUM_LAB_VPNUNICAST:
case SAFNUM_LAB_VPNMULCAST:
case SAFNUM_LAB_VPNUNIMULC:
plen = tvb_get_guint8(tvb, offset);
stack_strbuf = wmem_strbuf_new_label(wmem_packet_scope());
labnum = decode_MPLS_stack(tvb, offset + 1, stack_strbuf);
offset += (1 + labnum * 3);
if (plen <= (labnum * 3*8)) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Labeled VPN IPv4 prefix length %u invalid",
tag, plen);
return -1;
}
plen -= (labnum * 3*8);
if (plen < 8*8) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Labeled VPN IPv4 prefix length %u invalid",
tag, plen + (labnum * 3*8));
return -1;
}
plen -= 8*8;
length = tvb_get_ipv4_addr_with_prefix_len(tvb, offset + 8, ip4addr.addr_bytes, plen);
if (length < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Labeled VPN IPv4 prefix length %u invalid",
tag, plen + (labnum * 3*8) + 8*8);
return -1;
}
set_address(&addr, AT_IPv4, 4, ip4addr.addr_bytes);
prefix_tree = proto_tree_add_subtree_format(tree, tvb, start_offset,
(offset + 8 + length) - start_offset,
ett_bgp_prefix, NULL, "BGP Prefix");
proto_tree_add_item(prefix_tree, hf_bgp_prefix_length, tvb, start_offset, 1, ENC_NA);
proto_tree_add_string(prefix_tree, hf_bgp_label_stack, tvb, start_offset + 1, 3 * labnum, wmem_strbuf_get_str(stack_strbuf));
proto_tree_add_string(prefix_tree, hf_bgp_rd, tvb, start_offset + 1 + 3 * labnum, 8, decode_bgp_rd(tvb, offset));
proto_tree_add_ipv4(prefix_tree, hf_addr4, tvb, offset + 8, length, ip4addr.addr);
total_length = (1 + labnum * 3 + 8) + length;
break;
case SAFNUM_FSPEC_RULE:
case SAFNUM_FSPEC_VPN_RULE:
total_length = decode_flowspec_nlri(tree, tvb, offset, afi, pinfo);
if(total_length < 0)
return(-1);
total_length++;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_unknown_safi, tvb, start_offset, 0,
"Unknown SAFI (%u) for AFI %u", safi, afi);
return -1;
}
break;
case AFNUM_INET6:
switch (safi) {
case SAFNUM_UNICAST:
case SAFNUM_MULCAST:
case SAFNUM_UNIMULC:
total_length = decode_prefix6(tree, pinfo, hf_addr6, tvb, offset, 0, tag);
if (total_length < 0)
return -1;
break;
case SAFNUM_MPLS_LABEL:
plen = tvb_get_guint8(tvb, offset);
stack_strbuf = wmem_strbuf_new_label(wmem_packet_scope());
labnum = decode_MPLS_stack(tvb, offset + 1, stack_strbuf);
offset += (1 + labnum * 3);
if (plen <= (labnum * 3*8)) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Labeled IPv6 prefix length %u invalid", tag, plen);
return -1;
}
plen -= (labnum * 3*8);
length = tvb_get_ipv6_addr_with_prefix_len(tvb, offset, &ip6addr, plen);
if (length < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Labeled IPv6 prefix length %u invalid",
tag, plen + (labnum * 3*8));
return -1;
}
set_address(&addr, AT_IPv6, 16, ip6addr.bytes);
proto_tree_add_string_format(tree, hf_bgp_label_stack, tvb, start_offset,
(offset + length) - start_offset,
wmem_strbuf_get_str(stack_strbuf), "Label Stack=%s, IPv6=%s/%u",
wmem_strbuf_get_str(stack_strbuf),
address_to_str(wmem_packet_scope(), &addr), plen);
total_length = (1 + labnum * 3) + length;
break;
case SAFNUM_ENCAPSULATION:
plen = tvb_get_guint8(tvb, offset);
if (plen != 128){
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_length_invalid, tvb, offset, 1,
"%s IPv6 address length %u invalid",
tag, plen);
return -1;
}
offset += 1;
proto_tree_add_item(tree, hf_bgp_endpoint_address_ipv6, tvb, offset, 16, ENC_NA);
total_length = 17;
break;
case SAFNUM_TUNNEL:
plen = tvb_get_guint8(tvb, offset);
if (plen <= 16){
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Tunnel IPv6 prefix length %u invalid",
tag, plen);
return -1;
}
tnl_id = tvb_get_ntohs(tvb, offset + 1);
offset += 3;
plen -= 16;
length = tvb_get_ipv6_addr_with_prefix_len(tvb, offset, &ip6addr, plen);
if (length < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Tunnel IPv6 prefix length %u invalid",
tag, plen + 16);
return -1;
}
set_address(&addr, AT_IPv6, 16, ip6addr.bytes);
prefix_tree = proto_tree_add_subtree_format(tree, tvb, start_offset,
(offset + length) - start_offset,
ett_bgp_prefix, NULL,
"Tunnel Identifier=0x%x IPv6=%s/%u",
tnl_id, address_to_str(wmem_packet_scope(), &addr), plen);
proto_tree_add_item(prefix_tree, hf_bgp_prefix_length, tvb, start_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(prefix_tree, hf_bgp_mp_nlri_tnl_id, tvb,
start_offset + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_ipv6(prefix_tree, hf_addr6, tvb, offset, length, &ip6addr);
total_length = (1 + 2) + length;
break;
case SAFNUM_LAB_VPNUNICAST:
case SAFNUM_LAB_VPNMULCAST:
case SAFNUM_LAB_VPNUNIMULC:
plen = tvb_get_guint8(tvb, offset);
stack_strbuf = wmem_strbuf_new_label(wmem_packet_scope());
labnum = decode_MPLS_stack(tvb, offset + 1, stack_strbuf);
offset += (1 + labnum * 3);
if (plen <= (labnum * 3*8)) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Labeled VPN IPv6 prefix length %u invalid", tag, plen);
return -1;
}
plen -= (labnum * 3*8);
rd_type = tvb_get_ntohs(tvb,offset);
if (plen < 8*8) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Labeled VPN IPv6 prefix length %u invalid",
tag, plen + (labnum * 3*8));
return -1;
}
plen -= 8*8;
switch (rd_type) {
case FORMAT_AS2_LOC:
length = tvb_get_ipv6_addr_with_prefix_len(tvb, offset + 8, &ip6addr, plen);
if (length < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Labeled VPN IPv6 prefix length %u invalid",
tag, plen + (labnum * 3*8) + 8*8);
return -1;
}
set_address(&addr, AT_IPv6, 16, ip6addr.bytes);
proto_tree_add_string_format(tree, hf_bgp_label_stack, tvb, start_offset,
(offset + 8 + length) - start_offset,
wmem_strbuf_get_str(stack_strbuf), "Label Stack=%s RD=%u:%u, IPv6=%s/%u",
wmem_strbuf_get_str(stack_strbuf),
tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohl(tvb, offset + 4),
address_to_str(wmem_packet_scope(), &addr), plen);
total_length = (1 + labnum * 3 + 8) + length;
break;
case FORMAT_IP_LOC:
length = tvb_get_ipv6_addr_with_prefix_len(tvb, offset + 8, &ip6addr, plen);
if (length < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Labeled VPN IPv6 prefix length %u invalid",
tag, plen + (labnum * 3*8) + 8*8);
return -1;
}
set_address(&addr, AT_IPv6, 16, &ip6addr);
proto_tree_add_string_format(tree, hf_bgp_label_stack, tvb, start_offset,
(offset + 8 + length) - start_offset,
wmem_strbuf_get_str(stack_strbuf), "Label Stack=%s RD=%s:%u, IPv6=%s/%u",
wmem_strbuf_get_str(stack_strbuf),
tvb_ip_to_str(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 6),
address_to_str(wmem_packet_scope(), &addr), plen);
total_length = (1 + labnum * 3 + 8) + length;
break;
case FORMAT_AS4_LOC:
length = tvb_get_ipv6_addr_with_prefix_len(tvb, offset + 8, &ip6addr, plen);
if (length < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_prefix_length_invalid, tvb, start_offset, 1,
"%s Labeled VPN IPv6 prefix length %u invalid",
tag, plen + (labnum * 3*8) + 8*8);
return -1;
}
set_address(&addr, AT_IPv6, 16, ip6addr.bytes);
proto_tree_add_string_format(tree, hf_bgp_label_stack, tvb, start_offset,
(offset + 8 + length) - start_offset,
"Label Stack=%s RD=%u.%u:%u, IPv6=%s/%u",
wmem_strbuf_get_str(stack_strbuf),
tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 4),
tvb_get_ntohs(tvb, offset + 6),
address_to_str(wmem_packet_scope(), &addr), plen);
total_length = (1 + labnum * 3 + 8) + length;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_unknown_label_vpn, tvb, start_offset, 0,
"Unknown labeled VPN IPv6 address format %u", rd_type);
return -1;
}
break;
case SAFNUM_FSPEC_RULE:
case SAFNUM_FSPEC_VPN_RULE:
total_length = decode_flowspec_nlri(tree, tvb, offset, afi, pinfo);
if(total_length < 0)
return(-1);
total_length++;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_unknown_safi, tvb, start_offset, 0,
"Unknown SAFI (%u) for AFI %u", safi, afi);
return -1;
}
break;
case AFNUM_L2VPN:
case AFNUM_L2VPN_OLD:
switch (safi) {
case SAFNUM_LAB_VPNUNICAST:
case SAFNUM_LAB_VPNMULCAST:
case SAFNUM_LAB_VPNUNIMULC:
case SAFNUM_VPLS:
plen = tvb_get_ntohs(tvb,offset);
proto_tree_add_item(tree, hf_bgp_vplsad_length, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_string(tree, hf_bgp_vplsad_rd, tvb, offset+2, 8, decode_bgp_rd(tvb, offset+2));
if(plen == 12)
{
proto_tree_add_item(tree, hf_bgp_bgpad_pe_addr, tvb, offset+10, 4, ENC_NA);
}else{
proto_tree_add_item(tree, hf_bgp_vplsbgp_ce_id, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bgp_vplsbgp_labelblock_offset, tvb, offset+12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bgp_vplsbgp_labelblock_size, tvb, offset+14, 2, ENC_BIG_ENDIAN);
stack_strbuf = wmem_strbuf_new_label(wmem_packet_scope());
decode_MPLS_stack(tvb, offset + 16, stack_strbuf);
proto_tree_add_string(tree, hf_bgp_vplsbgp_labelblock_base, tvb, offset+16, plen-14, wmem_strbuf_get_str(stack_strbuf));
}
total_length = plen+2;
break;
case SAFNUM_EVPN:
total_length = decode_evpn_nlri(tree, tvb, offset, pinfo);
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_unknown_safi, tvb, start_offset, 0,
"Unknown SAFI (%u) for AFI %u", safi, afi);
return -1;
}
break;
case AFNUM_LINK_STATE:
nlri_type = tvb_get_ntohs(tvb, offset);
total_length = tvb_get_ntohs(tvb, offset + 2);
length = total_length;
total_length += 4;
if (safi == SAFNUM_LINK_STATE) {
ti = proto_tree_add_item(tree, hf_bgp_ls_safi72_nlri, tvb, offset, total_length , ENC_NA);
} else if (safi == SAFNUM_LAB_VPNUNICAST) {
ti = proto_tree_add_item(tree, hf_bgp_ls_safi128_nlri, tvb, offset, total_length , ENC_NA);
} else
return -1;
prefix_tree = proto_item_add_subtree(ti, ett_bgp_mp_reach_nlri);
proto_tree_add_item(prefix_tree, hf_bgp_ls_nlri_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(prefix_tree, hf_bgp_ls_nlri_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
offset += 4;
if (safi == SAFNUM_LAB_VPNUNICAST) {
if (length < BGP_ROUTE_DISTINGUISHER_SIZE) {
if (length == 0) {
expert_add_info_format(pinfo, prefix_tree, &ei_bgp_ls_error,
"Unexpected end of SAFI 128 NLRI, Route Distinguisher field is required!");
}
if (length > 0) {
expert_add_info_format(pinfo, prefix_tree, &ei_bgp_ls_error,
"Unexpected Route Distinguisher length (%u)!",
length);
}
break;
}
disting_item = proto_tree_add_item(prefix_tree, hf_bgp_ls_safi128_nlri_route_distinguisher,
tvb, offset, BGP_ROUTE_DISTINGUISHER_SIZE, ENC_NA);
disting_tree = proto_item_add_subtree(disting_item, ett_bgp_mp_reach_nlri);
tmp16 = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(disting_tree, hf_bgp_ls_safi128_nlri_route_distinguisher_type,
tvb, offset, 2, ENC_BIG_ENDIAN);
switch (tmp16) {
case 0:
proto_tree_add_item(disting_tree, hf_bgp_ls_safi128_nlri_route_dist_admin_asnum_2,
tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(disting_tree, hf_bgp_ls_safi128_nlri_route_dist_asnum_4,
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
break;
case 1:
proto_tree_add_item(disting_tree, hf_bgp_ls_safi128_nlri_route_dist_admin_ipv4,
tvb, offset + 2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(disting_tree, hf_bgp_ls_safi128_nlri_route_dist_asnum_2,
tvb, offset + 6, 2, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(disting_tree, hf_bgp_ls_safi128_nlri_route_dist_admin_asnum_4,
tvb, offset + 2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(disting_tree, hf_bgp_ls_safi128_nlri_route_dist_asnum_2,
tvb, offset + 6, 2, ENC_BIG_ENDIAN);
break;
default:
expert_add_info_format(pinfo, disting_tree, &ei_bgp_ls_error,
"Unknown Route Distinguisher type (%u)", tmp16);
}
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
length -= BGP_ROUTE_DISTINGUISHER_SIZE;
}
switch (nlri_type) {
case LINK_STATE_LINK_NLRI:
nlri_ti = proto_tree_add_item(prefix_tree,
hf_bgp_ls_nlri_link_nlri_type, tvb, offset, length,
ENC_NA);
nlri_tree = proto_item_add_subtree(nlri_ti, ett_bgp_mp_reach_nlri);
tmp_length = decode_bgp_link_node_nlri_common_fields(tvb, nlri_tree,
offset, pinfo, length);
if (tmp_length < 1)
return -1;
offset += tmp_length;
length -= tmp_length;
if (length > 0 && length < 4) {
expert_add_info_format(pinfo, nlri_tree, &ei_bgp_ls_error,
"Unknown data in Link-State Link NLRI!");
break;
}
if (length < 1)
break;
tmp_length = decode_bgp_link_node_nlri_tlvs(tvb, nlri_tree, offset,
pinfo, BGP_NLRI_TLV_REMOTE_NODE_DESCRIPTORS);
if (tmp_length < 1)
return -1;
offset += tmp_length;
length -= tmp_length;
if (length > 0 && length < 4) {
expert_add_info_format(pinfo, nlri_tree, &ei_bgp_ls_error,
"Unknown data in Link-State Link NLRI, length = %d bytes.", length);
break;
}
if (length < 1)
break;
tmp_length = decode_bgp_link_nlri_link_descriptors(tvb, nlri_tree,
offset, pinfo, length);
if (tmp_length < 1)
return -1;
break;
case LINK_STATE_NODE_NLRI:
nlri_ti = proto_tree_add_item(prefix_tree,
hf_bgp_ls_nlri_node_nlri_type, tvb, offset, length,
ENC_NA);
nlri_tree = proto_item_add_subtree(nlri_ti, ett_bgp_mp_reach_nlri);
tmp_length = decode_bgp_link_node_nlri_common_fields(tvb, nlri_tree,
offset, pinfo, length);
if (tmp_length < 1)
return -1;
break;
case LINK_STATE_IPV4_TOPOLOGY_PREFIX_NLRI:
nlri_ti = proto_tree_add_item(prefix_tree,
hf_bgp_ls_ipv4_topology_prefix_nlri_type, tvb, offset, length,
ENC_NA);
nlri_tree = proto_item_add_subtree(nlri_ti, ett_bgp_mp_reach_nlri);
tmp_length = decode_bgp_link_node_nlri_common_fields(tvb, nlri_tree,
offset, pinfo, length);
if (tmp_length < 1)
return -1;
offset += tmp_length;
length -= tmp_length;
if (length > 0 && length < 4) {
expert_add_info_format(pinfo, nlri_tree, &ei_bgp_ls_error,
"Unknown data in Link-State Link NLRI, length = %d bytes.", length);
break;
}
if (length < 1)
break;
tmp_length = decode_bgp_link_nlri_prefix_descriptors(tvb, nlri_tree,
offset, pinfo, length);
if (tmp_length < 1)
return -1;
break;
case LINK_STATE_IPV6_TOPOLOGY_PREFIX_NLRI:
nlri_ti = proto_tree_add_item(prefix_tree,
hf_bgp_ls_ipv6_topology_prefix_nlri_type, tvb, offset, length,
ENC_NA);
nlri_tree = proto_item_add_subtree(nlri_ti, ett_bgp_mp_reach_nlri);
tmp_length = decode_bgp_link_node_nlri_common_fields(tvb, nlri_tree,
offset, pinfo, length);
if (tmp_length < 1)
return -1;
offset += tmp_length;
length -= tmp_length;
if (length > 0 && length < 4) {
expert_add_info_format(pinfo, nlri_tree, &ei_bgp_ls_error,
"Unknown data in Link-State Link NLRI!");
break;
}
if (length < 1)
break;
tmp_length = decode_bgp_link_nlri_prefix_descriptors(tvb, nlri_tree,
offset, pinfo, length);
if (tmp_length < 1)
return -1;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_ls_error, tvb, start_offset, 0,
"Unknown Link-State NLRI type (%u)", afi);
}
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_bgp_unknown_afi, tvb, start_offset, 0,
"Unknown AFI (%u) value", afi);
return -1;
}
return(total_length);
}
static int
dissect_bgp_capability_item(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset, gboolean action)
{
proto_tree *cap_tree;
proto_item *ti;
proto_item *ti_len;
guint8 ctype;
guint8 clen;
ti = proto_tree_add_item(tree, hf_bgp_cap, tvb, offset, -1, ENC_NA);
cap_tree = proto_item_add_subtree(ti, ett_bgp_cap);
proto_tree_add_item(cap_tree, hf_bgp_cap_type, tvb, offset, 1, ENC_BIG_ENDIAN);
ctype = tvb_get_guint8(tvb, offset);
proto_item_append_text(ti, ": %s", val_to_str(ctype, capability_vals, "Unknown capability %d"));
offset += 1;
ti_len = proto_tree_add_item(cap_tree, hf_bgp_cap_length, tvb, offset, 1, ENC_BIG_ENDIAN);
clen = tvb_get_guint8(tvb, offset);
proto_item_set_len(ti, clen+2);
offset += 1;
if(action){
proto_tree_add_item(cap_tree, hf_bgp_cap_action, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_set_len(ti, clen+3);
offset += 1;
}
switch (ctype) {
case BGP_CAPABILITY_RESERVED:
if (clen != 0) {
expert_add_info_format(pinfo, ti_len, &ei_bgp_cap_len_bad, "Capability length %u wrong, must be = 0", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
}
offset += clen;
break;
case BGP_CAPABILITY_MULTIPROTOCOL:
if (clen != 4) {
expert_add_info_format(pinfo, ti_len, &ei_bgp_cap_len_bad, "Capability length %u is wrong, must be = 4", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
offset += clen;
}
else {
proto_tree_add_item(cap_tree, hf_bgp_cap_mp_afi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cap_tree, hf_bgp_cap_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(cap_tree, hf_bgp_cap_mp_safi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case BGP_CAPABILITY_GRACEFUL_RESTART:
if ((clen < 6) && (clen != 2)) {
expert_add_info_format(pinfo, ti_len, &ei_bgp_cap_len_bad, "Capability length %u too short, must be greater than 6", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
offset += clen;
}
else {
int eclen = offset + clen;
static const int * timer_flags[] = {
&hf_bgp_cap_gr_timers_restart_flag,
&hf_bgp_cap_gr_timers_restart_time,
NULL
};
if (clen == 2){
expert_add_info(pinfo, ti_len, &ei_bgp_cap_gr_helper_mode_only);
}
proto_tree_add_bitmask(cap_tree, tvb, offset, hf_bgp_cap_gr_timers, ett_bgp_cap, timer_flags, ENC_BIG_ENDIAN);
offset += 2;
while (offset < eclen) {
static const int * flags[] = {
&hf_bgp_cap_gr_flag_pfs,
NULL
};
proto_tree_add_item(cap_tree, hf_bgp_cap_gr_afi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cap_tree, hf_bgp_cap_gr_safi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(cap_tree, tvb, offset, hf_bgp_cap_gr_flag, ett_bgp_cap, flags, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
case BGP_CAPABILITY_4_OCTET_AS_NUMBER:
if (clen != 4) {
expert_add_info_format(pinfo, ti_len, &ei_bgp_cap_len_bad, "Capability length %u is wrong, must be = 4", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
offset += clen;
}
else {
proto_tree_add_item(cap_tree, hf_bgp_cap_4as, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case BGP_CAPABILITY_DYNAMIC_CAPABILITY:
if (clen > 0) {
int eclen = offset + clen;
while (offset < eclen) {
proto_tree_add_item(cap_tree, hf_bgp_cap_dc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
case BGP_CAPABILITY_ADDITIONAL_PATHS:
if (clen != 4) {
expert_add_info_format(pinfo, ti_len, &ei_bgp_cap_len_bad, "Capability length %u is wrong, must be = 4", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
offset += clen;
}
else {
proto_tree_add_item(cap_tree, hf_bgp_cap_ap_afi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cap_tree, hf_bgp_cap_ap_safi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cap_tree, hf_bgp_cap_ap_sendreceive, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case BGP_CAPABILITY_FQDN:{
guint8 hostname_len, domain_name_len;
proto_tree_add_item(cap_tree, hf_bgp_cap_fqdn_hostname_len, tvb, offset, 1, ENC_NA);
hostname_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(cap_tree, hf_bgp_cap_fqdn_hostname, tvb, offset, hostname_len, ENC_ASCII|ENC_NA);
offset += hostname_len;
proto_tree_add_item(cap_tree, hf_bgp_cap_fqdn_domain_name_len, tvb, offset, 1, ENC_NA);
domain_name_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(cap_tree, hf_bgp_cap_fqdn_domain_name, tvb, offset, domain_name_len, ENC_ASCII|ENC_NA);
offset += domain_name_len;
}
break;
case BGP_CAPABILITY_ENHANCED_ROUTE_REFRESH:
case BGP_CAPABILITY_ROUTE_REFRESH_CISCO:
case BGP_CAPABILITY_ROUTE_REFRESH:
case BGP_CAPABILITY_CP_ORF:
if (clen != 0) {
expert_add_info_format(pinfo, ti_len, &ei_bgp_cap_len_bad, "Capability length %u wrong, must be = 0", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
}
offset += clen;
break;
case BGP_CAPABILITY_ORF_CISCO:
case BGP_CAPABILITY_COOPERATIVE_ROUTE_FILTERING:
if (clen < 6) {
expert_add_info_format(pinfo, ti_len, &ei_bgp_cap_len_bad, "Capability length %u too short, must be greater than 6", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
offset += clen;
}
else {
guint8 orfnum;
int i;
proto_tree_add_item(cap_tree, hf_bgp_cap_orf_afi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cap_tree, hf_bgp_cap_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(cap_tree, hf_bgp_cap_orf_safi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
orfnum = tvb_get_guint8(tvb, offset);
proto_tree_add_item(cap_tree, hf_bgp_cap_orf_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for (i=0; i<orfnum; i++) {
proto_tree_add_item(cap_tree, hf_bgp_cap_orf_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cap_tree, hf_bgp_cap_orf_sendreceive, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
case BGP_CAPABILITY_MULTISESSION_CISCO:
if (clen < 1) {
expert_add_info_format(pinfo, ti_len, &ei_bgp_cap_len_bad, "Capability length %u too short, must be greater than 1", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
offset += clen;
}
else {
proto_tree_add_item(cap_tree, hf_bgp_cap_multisession_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
default:
if (clen != 0) {
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
}
offset += clen;
break;
}
return offset;
}
static void
dissect_bgp_open(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo)
{
guint8 optlen;
int ptype;
int plen;
int cend;
int oend;
int offset;
proto_item *ti;
proto_tree *opt_tree;
proto_tree *par_tree;
offset = BGP_MARKER_SIZE + 2 + 1;
proto_tree_add_item(tree, hf_bgp_open_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bgp_open_myas, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bgp_open_holdtime, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bgp_open_identifier, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_bgp_open_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
optlen = tvb_get_guint8(tvb, offset);
offset += 1;
if (optlen > 0) {
oend = offset + optlen;
ti = proto_tree_add_item(tree, hf_bgp_open_opt_params, tvb, offset, optlen, ENC_NA);
opt_tree = proto_item_add_subtree(ti, ett_bgp_options);
while (offset < oend) {
ti = proto_tree_add_item(opt_tree, hf_bgp_open_opt_param, tvb, offset, -1, ENC_NA);
par_tree = proto_item_add_subtree(ti, ett_bgp_options);
proto_tree_add_item(par_tree, hf_bgp_open_opt_param_type, tvb, offset, 1, ENC_BIG_ENDIAN);
ptype = tvb_get_guint8(tvb, offset);
proto_item_append_text(ti, ": %s", val_to_str(ptype, bgp_open_opt_vals, "Unknown Parameter %d"));
offset += 1;
proto_tree_add_item(par_tree, hf_bgp_open_opt_param_len, tvb, offset, 1, ENC_BIG_ENDIAN);
plen = tvb_get_guint8(tvb, offset);
proto_item_set_len(ti, plen+2);
offset += 1;
switch (ptype) {
case BGP_OPTION_AUTHENTICATION:
proto_tree_add_item(par_tree, hf_bgp_open_opt_param_auth, tvb, offset, plen, ENC_NA);
offset += plen;
break;
case BGP_OPTION_CAPABILITY:
cend = offset + plen;
while (offset < cend) {
offset = dissect_bgp_capability_item(tvb, par_tree, pinfo, offset, FALSE);
}
break;
default:
proto_tree_add_item(opt_tree, hf_bgp_open_opt_param_unknown, tvb, offset, plen, ENC_NA);
break;
}
}
}
}
static guint8
heuristic_as2_or_4_from_as_path(tvbuff_t *tvb, gint as_path_offset, gint end_attr_offset, guint8 bgpa_type, gint *number_as_segment)
{
gint counter_as_segment=0;
gint offset_check=0;
guint8 assumed_as_len=0;
gint asn_is_null=0;
gint j=0;
gint k=0;
gint k_save=0;
guint8 next_type=0;
guint8 length=0;
k = as_path_offset;
if (bgpa_type == BGPTYPE_AS4_PATH) {
assumed_as_len = 4;
while (k < end_attr_offset)
{
k++;
length = tvb_get_guint8(tvb, k);
k++;
k = k + (length*assumed_as_len);
counter_as_segment++;
}
*number_as_segment = counter_as_segment;
return(4);
}
if (bgp_asn_len != 0) {
assumed_as_len = bgp_asn_len;
while (k < end_attr_offset)
{
k++;
length = tvb_get_guint8(tvb, k);
k++;
k = k + (length*assumed_as_len);
counter_as_segment++;
}
*number_as_segment = counter_as_segment;
return(bgp_asn_len);
}
if (as_path_offset == end_attr_offset)
{
*number_as_segment = 0;
return(bgp_asn_len);
}
k_save = k;
k++;
length = tvb_get_guint8(tvb, k++);
offset_check = k + 2*length;
next_type = tvb_get_guint8(tvb, offset_check);
if (offset_check == end_attr_offset)
assumed_as_len = 2;
else if (next_type == AS_SET ||
next_type == AS_SEQUENCE ||
next_type == AS_CONFED_SEQUENCE ||
next_type == AS_CONFED_SET) {
for (j=0; j < length && !asn_is_null; j++) {
if(tvb_get_ntohs(tvb, k+(2*j)) == 0) {
asn_is_null = 1;
}
}
if (asn_is_null == 0)
assumed_as_len = 2;
else
assumed_as_len = 4;
}
else
assumed_as_len = 4;
k = k_save;
while (k < end_attr_offset)
{
k++;
length = tvb_get_guint8(tvb, k);
k++;
k = k + (length*assumed_as_len);
counter_as_segment++;
}
if (k == end_attr_offset) {
*number_as_segment = counter_as_segment;
return(assumed_as_len);
} else
return(-1);
}
static int
dissect_bgp_update_ext_com(proto_tree *parent_tree, tvbuff_t *tvb, guint16 tlen, guint tvb_off)
{
int offset=0;
int end=0;
int i=0;
guint8 com_type_high_byte;
guint8 com_stype_low_byte;
guint8 dscp_flags;
guint8 esi_label_flag;
proto_tree *communities_tree;
proto_tree *community_tree;
proto_item *communities_item=NULL;
proto_item *community_item=NULL;
gfloat linkband;
guint16 as_num;
guint16 tunnel_type=0;
offset = tvb_off ;
end = tvb_off + tlen ;
communities_item = proto_tree_add_item(parent_tree, hf_bgp_ext_communities, tvb, offset, tlen, ENC_NA);
communities_tree = proto_item_add_subtree(communities_item, ett_bgp_extended_communities);
proto_item_append_text(communities_item, ": (%u communit%s)", tlen/8, plurality(tlen/8, "y", "ies"));
while (offset < end) {
com_type_high_byte = tvb_get_guint8(tvb,offset);
com_stype_low_byte = tvb_get_guint8(tvb,offset+1);
community_item = proto_tree_add_item(communities_tree, hf_bgp_ext_community, tvb, offset, 8, ENC_NA);
community_tree = proto_item_add_subtree(community_item,ett_bgp_extended_community);
switch (com_type_high_byte) {
case BGP_EXT_COM_TYPE_HIGH_TR_AS2:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_stype_tr_as2, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_as2, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_an4, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s %s: %u%s%d",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
val_to_str_const(com_stype_low_byte, bgpext_com_stype_tr_as2, "Unknown"),
tvb_get_ntohs(tvb,offset+2),":",tvb_get_ntohl(tvb,offset+4));
break;
case BGP_EXT_COM_TYPE_HIGH_NTR_AS2:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_stype_ntr_as2, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_as2, tvb, offset+2, 2, ENC_BIG_ENDIAN);
if (com_stype_low_byte == BGP_EXT_COM_STYPE_AS2_LBW) {
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_link_bw, tvb, offset+4, 4, ENC_BIG_ENDIAN);
linkband = tvb_get_ntohieee_float(tvb,offset+4);
as_num = tvb_get_ntohs(tvb,offset+2);
proto_item_append_text(community_item, ": ASN %u, %.3f Mbps", as_num,linkband*8/1000000);
} else {
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_an4, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s %s: %u%s%d",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
val_to_str_const(com_stype_low_byte, bgpext_com_stype_ntr_as2, "Unknown"),
tvb_get_ntohs(tvb,offset+2),":",tvb_get_ntohl(tvb,offset+4));
}
break;
case BGP_EXT_COM_TYPE_HIGH_TR_IP4:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_stype_tr_IP4, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_IP4, tvb, offset+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_an2, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s %s: %s%s%u",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
val_to_str_const(com_stype_low_byte, bgpext_com_stype_tr_IP4, "Unknown"),
tvb_ip_to_str(tvb, offset+2),":",tvb_get_ntohs(tvb,offset+6));
break;
case BGP_EXT_COM_TYPE_HIGH_NTR_IP4:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_IP4, tvb, offset+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_an2, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s: %s%s%u",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
tvb_ip_to_str(tvb, offset+2),":",tvb_get_ntohs(tvb,offset+6));
break;
case BGP_EXT_COM_TYPE_HIGH_TR_AS4:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_stype_tr_as4, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_as4, tvb, offset+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_an2, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s %s: %u.%u(%u):%u",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
val_to_str_const(com_stype_low_byte, bgpext_com_stype_tr_as4, "Unknown"),
tvb_get_ntohs(tvb,offset+2),tvb_get_ntohs(tvb,offset+4) ,tvb_get_ntohl(tvb,offset+2),
tvb_get_ntohs(tvb,offset+6));
break;
case BGP_EXT_COM_TYPE_HIGH_NTR_AS4:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_stype_ntr_as4, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_as4, tvb, offset+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_an2, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s %s: %u.%u:%u",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
val_to_str_const(com_stype_low_byte, bgpext_com_stype_ntr_as4, "Unknown"),
tvb_get_ntohs(tvb,offset+2),tvb_get_ntohs(tvb,offset+4), tvb_get_ntohs(tvb,offset+6));
break;
case BGP_EXT_COM_TYPE_HIGH_TR_OPAQUE:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_stype_tr_opaque, tvb, offset+1, 1, ENC_BIG_ENDIAN);
switch (com_stype_low_byte) {
case BGP_EXT_COM_STYPE_OPA_OSPF:
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_IP4, tvb, offset+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_ospf_rtype, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_ospf_rtype_option, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " Area: %s, Type: %s", tvb_ip_to_str(tvb,offset+2),
val_to_str_const(tvb_get_guint8(tvb,offset+6),
bgpext_com_ospf_rtype, "Unknown"));
break;
case BGP_EXT_COM_STYPE_OPA_ENCAP:
tunnel_type = tvb_get_ntohs(tvb,offset+6);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_unknown32, tvb, offset+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_tunnel_type, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s %s: %s",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
val_to_str_const(com_stype_low_byte, bgpext_com_stype_tr_opaque, "Unknown"),
val_to_str_const(tunnel_type, bgpext_com_tunnel_type, "Unknown"));
break;
case BGP_EXT_COM_STYPE_OPA_COLOR:
case BGP_EXT_COM_STYPE_OPA_DGTW:
default:
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_unknown16, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_unknown32, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s %s: 0x%02x 0x%04x",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
val_to_str_const(com_stype_low_byte, bgpext_com_stype_tr_opaque, "Unknown"),
tvb_get_ntohs(tvb,offset+2) ,tvb_get_ntohl(tvb,offset+4));
break;
}
break;
case BGP_EXT_COM_TYPE_HIGH_NTR_OPAQUE:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_stype_ntr_opaque, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_unknown16, tvb, offset+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_unknown32, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s %s: 0x%02x 0x%04x",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
val_to_str_const(com_stype_low_byte, bgpext_com_stype_ntr_opaque, "Unknown"),
tvb_get_ntohs(tvb,offset+2) ,tvb_get_ntohl(tvb,offset+4));
break;
case BGP_EXT_COM_TYPE_HIGH_TR_QOS:
case BGP_EXT_COM_TYPE_HIGH_NTR_QOS:
{
static const int * qos_flags[] = {
&hf_bgp_ext_com_qos_flags_remarking,
&hf_bgp_ext_com_qos_flags_ignore_remarking,
&hf_bgp_ext_com_qos_flags_agg_marking,
NULL
};
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s: 0x%02x",val_to_str(com_type_high_byte, bgpext_com_type_high,
"Unknown type: 0x%02x"),com_type_high_byte);
proto_tree_add_bitmask(community_tree, tvb, offset, hf_bgp_ext_com_qos_flags, ett_bgp_ext_com_flags, qos_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_qos_set_number, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_qos_tech_type, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_qos_marking_o, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_qos_marking_a, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_qos_default_to_zero, tvb, offset+7, 1, ENC_BIG_ENDIAN);
}
break;
case BGP_EXT_COM_TYPE_HIGH_TR_COS:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s: 0x%02x",val_to_str(com_type_high_byte, bgpext_com_type_high,
"Unknown type: 0x%02x"),com_type_high_byte);
for (i=1; i < 8; i++) {
static const int * cos_flags[] = {
&hf_bgp_ext_com_cos_flags_be,
&hf_bgp_ext_com_cos_flags_ef,
&hf_bgp_ext_com_cos_flags_af,
&hf_bgp_ext_com_cos_flags_le,
NULL
};
proto_tree_add_bitmask(community_tree, tvb, offset+i, hf_bgp_ext_com_cos_flags, ett_bgp_ext_com_flags, cos_flags, ENC_BIG_ENDIAN);
}
break;
case BGP_EXT_COM_TYPE_HIGH_TR_EVPN:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_stype_tr_evpn, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_l2_esi_label_flag, tvb, offset+2, 1, ENC_BIG_ENDIAN);
esi_label_flag = tvb_get_guint8(tvb, offset+2);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_unknown16, tvb, offset+3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_update_mpls_label_value, tvb, offset+5, 3, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s %s: %s Label: %u",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
val_to_str_const(com_stype_low_byte, bgpext_com_stype_tr_evpn, "Unknown"),
((esi_label_flag & BGP_EXT_COM_ESI_LABEL_FLAGS) == 0) ? "All active redundancy" : "Single Active redundancy",
tvb_get_ntoh24(tvb,offset+5));
break;
case BGP_EXT_COM_TYPE_HIGH_TR_EXP:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_stype_tr_exp, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s %s",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
val_to_str_const(com_stype_low_byte, bgpext_com_stype_tr_exp, "Unknown"));
switch (com_stype_low_byte) {
case BGP_EXT_COM_STYPE_EXP_F_TR:
proto_tree_add_item(community_tree, hf_bgp_update_path_attribute_community_as,
tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_flow_rate_float, tvb, offset+4, 4, ENC_BIG_ENDIAN);
break;
case BGP_EXT_COM_STYPE_EXP_F_TA:
proto_tree_add_item(community_tree, hf_bgp_ext_com_flow_act_allset, tvb, offset+2, 5, ENC_NA);
proto_tree_add_item(community_tree, hf_bgp_ext_com_flow_act_samp_act, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_flow_act_term_act, tvb, offset+7, 1, ENC_BIG_ENDIAN);
break;
case BGP_EXT_COM_STYPE_EXP_F_RED:
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_as2, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_an4, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " RT %u:%u", tvb_get_ntohs(tvb,offset+2), tvb_get_ntohl(tvb,offset+4));
break;
case BGP_EXT_COM_STYPE_EXP_F_RMARK:
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_fs_remark, tvb, offset+7, 1, ENC_BIG_ENDIAN);
dscp_flags = tvb_get_guint8(tvb,offset+7);
proto_item_append_text(community_item, "%s", val_to_str_ext_const(dscp_flags,&dscp_vals_ext, "Unknown DSCP"));
break;
case BGP_EXT_COM_STYPE_EXP_L2:
{
static const int * com_l2_flags[] = {
&hf_bgp_ext_com_l2_flag_d,
&hf_bgp_ext_com_l2_flag_z1,
&hf_bgp_ext_com_l2_flag_f,
&hf_bgp_ext_com_l2_flag_z345,
&hf_bgp_ext_com_l2_flag_c,
&hf_bgp_ext_com_l2_flag_s,
NULL
};
proto_tree_add_item(community_tree, hf_bgp_ext_com_l2_encaps,tvb,offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(community_tree, tvb, offset+3, hf_bgp_ext_com_l2_c_flags, ett_bgp_ext_com_l2_flags, com_l2_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_l2_mtu, tvb, offset+4, 2, ENC_BIG_ENDIAN);
}
break;
}
break;
case BGP_EXT_COM_TYPE_HIGH_TR_EXP_FSIP4:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_stype_tr_exp_fs_ip4, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_IP4, tvb, offset+2, 4, ENC_NA);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_an2, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s %s: %s%s%u",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
val_to_str_const(com_stype_low_byte, bgpext_com_stype_tr_exp_fs_ip4, "Unknown"),
tvb_ip_to_str(tvb, offset+2),":",tvb_get_ntohs(tvb,offset+6));
break;
case BGP_EXT_COM_TYPE_HIGH_TR_EXP_FSAS4:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_stype_tr_exp_fs_as4, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_as4, tvb, offset+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_an2, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s %s: %u.%u(%u):%u",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
val_to_str_const(com_stype_low_byte, bgpext_com_stype_tr_exp_fs_as4, "Unknown"),
tvb_get_ntohs(tvb,offset+2),tvb_get_ntohs(tvb,offset+4) ,tvb_get_ntohl(tvb,offset+2),
tvb_get_ntohs(tvb,offset+6));
break;
case BGP_EXT_COM_TYPE_HIGH_TR_FLOW:
default:
proto_tree_add_item(community_tree, hf_bgp_ext_com_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_stype_low_unknown, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_unknown16, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_ext_com_value_unknown32, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(community_item, " %s : 0x%02x 0x%04x",
val_to_str_const(com_type_high_byte, bgpext_com_type_high, "Unknown"),
tvb_get_ntohs(tvb,offset+2) ,tvb_get_ntohl(tvb,offset+4));
break;
}
offset = offset + 8;
}
return(0);
}
static int
dissect_bgp_update_pmsi_attr(packet_info *pinfo, proto_tree *parent_tree, tvbuff_t *tvb, guint16 tlen, guint tvb_off)
{
int offset=0;
guint8 tunnel_type=0;
guint8 opaque_value_type=0;
guint8 rn_addr_length=0;
guint16 tunnel_id_len=0;
guint16 opaque_value_length=0;
proto_item *tunnel_id_item=NULL;
proto_item *opaque_value_type_item=NULL;
proto_item *pmsi_tunnel_type_item=NULL;
proto_tree *tunnel_id_tree=NULL;
offset = tvb_off ;
tunnel_id_len = tlen - 5;
proto_tree_add_item(parent_tree, hf_bgp_pmsi_tunnel_flags, tvb, offset,
1, ENC_BIG_ENDIAN);
pmsi_tunnel_type_item = proto_tree_add_item(parent_tree, hf_bgp_pmsi_tunnel_type, tvb, offset+1,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(parent_tree, hf_bgp_update_mpls_label_value_20bits, tvb, offset+2, 3, ENC_BIG_ENDIAN);
tunnel_id_item = proto_tree_add_item(parent_tree, hf_bgp_pmsi_tunnel_id, tvb, offset+5,
tunnel_id_len, ENC_NA);
tunnel_id_tree = proto_item_add_subtree(tunnel_id_item, ett_bgp_pmsi_tunnel_id);
tunnel_type = tvb_get_guint8(tvb, offset+1);
switch(tunnel_type) {
case PMSI_TUNNEL_NOPRESENT:
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_not_present, tvb, offset+1, 1, ENC_NA);
break;
case PMSI_TUNNEL_RSVPTE_P2MP:
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_rsvp_p2mp_id, tvb, offset+5, 4, ENC_NA);
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_rsvp_p2mp_tunnel_id, tvb, offset+11, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_rsvp_p2mp_ext_tunnel_idv4, tvb, offset+13, 4, ENC_NA);
proto_item_append_text(tunnel_id_item, ": Id %u, Ext Id %s",
tvb_get_ntohs(tvb, offset+11), tvb_ip_to_str(tvb, offset+13));
break;
case PMSI_TUNNEL_MLDP_P2MP:
case PMSI_TUNNEL_MLDP_MP2MP:
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_mldp_fec_el_type, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_mldp_fec_el_afi, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_mldp_fec_el_adr_len, tvb, offset+8, 1, ENC_BIG_ENDIAN);
rn_addr_length = tvb_get_guint8(tvb, offset+8);
if( rn_addr_length ==4)
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_mldp_fec_el_root_nodev4, tvb, offset+9, 4, ENC_NA);
else
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_mldp_fec_el_root_nodev6, tvb, offset+9, 4, ENC_NA);
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_mldp_fec_el_opa_len, tvb, offset+9+rn_addr_length, 2, ENC_BIG_ENDIAN);
opaque_value_type_item = proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_mldp_fec_el_opa_val_type,
tvb, offset+11+rn_addr_length, 1, ENC_BIG_ENDIAN);
opaque_value_type = tvb_get_guint8(tvb, offset+11+rn_addr_length);
if(opaque_value_type == PMSI_MLDP_FEC_TYPE_GEN_LSP) {
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_mldp_fec_el_opa_val_len, tvb, offset+12+rn_addr_length, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_mldp_fec_el_opa_value_rn, tvb, offset+14+rn_addr_length, 4, ENC_BIG_ENDIAN);
proto_item_append_text(tunnel_id_item, ": Type: %s root node: %s Id: %u",
val_to_str_const(tvb_get_guint8(tvb, offset+5), fec_types_vals, "Unknown"),
tvb_ip_to_str(tvb, offset+9),
tvb_get_ntohl(tvb, offset+14+rn_addr_length));
} else if (opaque_value_type == PMSI_MLDP_FEC_TYPE_EXT_TYPE) {
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_mldp_fec_el_opa_val_ext_type, tvb, offset+12+rn_addr_length, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_mldp_fec_el_opa_val_ext_len, tvb, offset+14+rn_addr_length, 2, ENC_BIG_ENDIAN);
opaque_value_length = tvb_get_ntohs(tvb, offset+14+rn_addr_length);
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_mldp_fec_el_opa_value_str, tvb, offset+16+rn_addr_length,
opaque_value_length, ENC_ASCII|ENC_NA);
}
else {
expert_add_info_format(pinfo, opaque_value_type_item, &ei_bgp_attr_pmsi_opaque_type,
"Opaque Value type %u wrong, must be modulo 1 or 255", opaque_value_type);
}
break;
case PMSI_TUNNEL_PIMSSM:
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_pimssm_root_node, tvb, offset+5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_pimssm_pmc_group, tvb, offset+9, 4, ENC_BIG_ENDIAN);
proto_item_append_text(tunnel_id_item, ": < %s, %s >",
tvb_ip_to_str(tvb, offset+5),
tvb_ip_to_str(tvb, offset+9));
break;
case PMSI_TUNNEL_PIMSM:
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_pimsm_sender, tvb, offset+5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_pimsm_pmc_group, tvb, offset+9, 4, ENC_BIG_ENDIAN);
proto_item_append_text(tunnel_id_item, ": < %s, %s >",
tvb_ip_to_str(tvb, offset+5),
tvb_ip_to_str(tvb, offset+9));
break;
case PMSI_TUNNEL_BIDIR_PIM:
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_pimbidir_sender, tvb, offset+5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_pimbidir_pmc_group, tvb, offset+9, 4, ENC_BIG_ENDIAN);
proto_item_append_text(tunnel_id_item, ": < %s, %s >",
tvb_ip_to_str(tvb, offset+5),
tvb_ip_to_str(tvb, offset+9));
break;
case PMSI_TUNNEL_INGRESS:
proto_tree_add_item(tunnel_id_tree, hf_bgp_pmsi_tunnel_ingress_rep_addr, tvb, offset+5, 4, ENC_BIG_ENDIAN);
proto_item_append_text(tunnel_id_item, ": tunnel end point -> %s",
tvb_ip_to_str(tvb, offset+5));
break;
default:
expert_add_info_format(pinfo, pmsi_tunnel_type_item, &ei_bgp_attr_pmsi_tunnel_type,
"Tunnel type %u wrong", tunnel_type);
break;
}
return(0);
}
static void
dissect_bgp_path_attr(proto_tree *subtree, tvbuff_t *tvb, guint16 path_attr_len, guint tvb_off, packet_info *pinfo)
{
guint8 bgpa_flags;
guint8 bgpa_type;
gint o;
gint q=0;
gint end=0;
int advance;
proto_item *ti;
proto_item *ti_communities;
proto_item *ti_community;
proto_item *attr_len_item;
proto_item *aigp_type_item;
proto_tree *subtree2;
proto_tree *subtree3;
proto_tree *subtree4;
proto_tree *subtree5;
proto_tree *subtree6;
proto_tree *attr_set_subtree;
proto_tree *as_path_segment_tree;
gint number_as_segment=0;
proto_tree *communities_tree;
proto_tree *community_tree;
proto_tree *cluster_list_tree;
int i=0, j, k;
guint8 type=0;
guint8 length=0;
wmem_strbuf_t *junk_emstr;
guint32 aggregator_as;
guint16 ssa_type;
guint16 ssa_len;
guint8 ssa_v3_len;
guint16 encaps_tunnel_type;
guint16 encaps_tunnel_len;
guint8 encaps_tunnel_subtype;
guint8 encaps_tunnel_sublen;
guint8 aigp_type;
o = tvb_off;
junk_emstr = wmem_strbuf_new_label(wmem_packet_scope());
while (i < path_attr_len) {
proto_item *ti_pa, *ti_flags;
int off;
guint16 alen, aoff, tlen, aoff_save;
guint16 af;
guint8 saf, snpa;
guint8 nexthop_len;
guint8 asn_len = 0;
static const int * path_flags[] = {
&hf_bgp_update_path_attribute_flags_optional,
&hf_bgp_update_path_attribute_flags_transitive,
&hf_bgp_update_path_attribute_flags_partial,
&hf_bgp_update_path_attribute_flags_extended_length,
NULL
};
bgpa_flags = tvb_get_guint8(tvb, o + i);
bgpa_type = tvb_get_guint8(tvb, o + i+1);
if (bgpa_flags & BGP_ATTR_FLAG_EXTENDED_LENGTH) {
alen = tvb_get_ntohs(tvb, o + i + BGP_SIZE_OF_PATH_ATTRIBUTE);
aoff = BGP_SIZE_OF_PATH_ATTRIBUTE+2;
} else {
alen = tvb_get_guint8(tvb, o + i + BGP_SIZE_OF_PATH_ATTRIBUTE);
aoff = BGP_SIZE_OF_PATH_ATTRIBUTE+1;
}
tlen = alen;
ti_pa = proto_tree_add_item(subtree, hf_bgp_update_path_attribute, tvb, o + i, tlen + aoff, ENC_NA);
proto_item_append_text(ti_pa, " - %s", val_to_str(bgpa_type, bgpattr_type, "Unknown (%u)"));
subtree2 = proto_item_add_subtree(ti_pa, ett_bgp_attr);
ti_flags = proto_tree_add_bitmask(subtree2, tvb, o + i, hf_bgp_update_path_attribute_flags, ett_bgp_attr_flags, path_flags, ENC_NA);
proto_item_append_text(ti_flags,"%s%s%s%s",
((bgpa_flags & BGP_ATTR_FLAG_OPTIONAL) == 0) ? ": Well-known" : ": Optional",
((bgpa_flags & BGP_ATTR_FLAG_TRANSITIVE) == 0) ? ", Non-transitive" : ", Transitive",
((bgpa_flags & BGP_ATTR_FLAG_PARTIAL) == 0) ? ", Complete" : ", Partial",
((bgpa_flags & BGP_ATTR_FLAG_EXTENDED_LENGTH) == 0) ? "" : ", Extended Length");
proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_type_code, tvb, o + i + 1, 1, ENC_BIG_ENDIAN);
attr_len_item = proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_length, tvb, o + i + BGP_SIZE_OF_PATH_ATTRIBUTE,
aoff - BGP_SIZE_OF_PATH_ATTRIBUTE, ENC_BIG_ENDIAN);
switch (bgpa_type) {
case BGPTYPE_ORIGIN:
if (tlen != 1) {
proto_tree_add_expert_format(subtree2, pinfo, &ei_bgp_length_invalid, tvb, o + i + aoff, tlen,
"Origin (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
} else {
proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_origin, tvb,
o + i + aoff, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti_pa, ": %s", val_to_str_const(tvb_get_guint8(tvb, o + i + aoff), bgpattr_origin, "Unknown"));
}
break;
case BGPTYPE_AS_PATH:
case BGPTYPE_AS4_PATH:
asn_len = heuristic_as2_or_4_from_as_path(tvb, o+i+aoff, o+i+aoff+tlen,
bgpa_type, &number_as_segment);
if (asn_len == 255)
{
expert_add_info_format(pinfo, ti_pa, &ei_bgp_attr_as_path_as_len_err,
"ASN length uncalculated by heuristic : %u", asn_len);
break;
}
proto_item_append_text(ti_pa,": ");
if(tlen == 0) {
proto_item_append_text(ti_pa,"empty");
}
q = o + i + aoff;
for (k=0; k < number_as_segment; k++)
{
type = tvb_get_guint8(tvb, q);
length = tvb_get_guint8(tvb, q+1);
ti = proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_as_path_segment, tvb,
q, length * asn_len + 2, ENC_NA);
proto_item_append_text(ti,": ");
as_path_segment_tree = proto_item_add_subtree(ti, ett_bgp_as_path_segment);
proto_tree_add_item(as_path_segment_tree, hf_bgp_update_path_attribute_as_path_segment_type, tvb,
q, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(as_path_segment_tree, hf_bgp_update_path_attribute_as_path_segment_length, tvb,
q+1, 1, ENC_BIG_ENDIAN);
switch(type)
{
case AS_SET:
proto_item_append_text(ti_pa, "{");
proto_item_append_text(ti, "{");
break;
case AS_CONFED_SET:
proto_item_append_text(ti_pa, "[");
proto_item_append_text(ti, "[");
break;
case AS_CONFED_SEQUENCE:
proto_item_append_text(ti_pa, "(");
proto_item_append_text(ti, "(");
break;
}
q = q + 2;
for (j = 0; j < length; j++)
{
if(asn_len == 2) {
proto_tree_add_item(as_path_segment_tree,
hf_bgp_update_path_attribute_as_path_segment_as2,
tvb, q, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti_pa, "%u",
tvb_get_ntohs(tvb, q));
proto_item_append_text(ti, "%u",
tvb_get_ntohs(tvb, q));
}
else if (asn_len == 4) {
proto_tree_add_item(as_path_segment_tree,
hf_bgp_update_path_attribute_as_path_segment_as4,
tvb, q, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti_pa, "%u",
tvb_get_ntohl(tvb, q));
proto_item_append_text(ti, "%u",
tvb_get_ntohl(tvb, q));
}
if (j != length-1)
{
proto_item_append_text(ti_pa, "%s",
(type == AS_SET || type == AS_CONFED_SET) ?
", " : " ");
proto_item_append_text(ti, "%s",
(type == AS_SET || type == AS_CONFED_SET) ?
", " : " ");
}
q += asn_len;
}
switch(type)
{
case AS_SET:
proto_item_append_text(ti_pa, "} ");
proto_item_append_text(ti, "}");
break;
case AS_CONFED_SET:
proto_item_append_text(ti_pa, "] ");
proto_item_append_text(ti, "]");
break;
case AS_CONFED_SEQUENCE:
proto_item_append_text(ti_pa, ") ");
proto_item_append_text(ti, ")");
break;
default:
proto_item_append_text(ti_pa, " ");
break;
}
}
break;
case BGPTYPE_NEXT_HOP:
if (tlen != 4) {
proto_tree_add_expert_format(subtree2, pinfo, &ei_bgp_length_invalid, tvb, o + i + aoff, tlen,
"Next hop (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
} else {
proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_next_hop, tvb,
o + i + aoff, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti_pa, ": %s ", tvb_ip_to_str(tvb, o + i + aoff));
}
break;
case BGPTYPE_MULTI_EXIT_DISC:
if (tlen != 4) {
proto_tree_add_expert_format(subtree2, pinfo, &ei_bgp_length_invalid, tvb, o + i + aoff, tlen,
"Multiple exit discriminator (invalid): %u byte%s",
tlen, plurality(tlen, "", "s"));
} else {
proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_multi_exit_disc, tvb,
o + i + aoff, tlen, ENC_BIG_ENDIAN);
proto_item_append_text(ti_pa,": %u", tvb_get_ntohl(tvb, o + i + aoff));
}
break;
case BGPTYPE_LOCAL_PREF:
if (tlen != 4) {
proto_tree_add_expert_format(subtree2, pinfo, &ei_bgp_length_invalid, tvb, o + i + aoff, tlen,
"Local preference (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
} else {
proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_local_pref, tvb,
o + i + aoff, tlen, ENC_BIG_ENDIAN);
proto_item_append_text(ti_pa, ": %u", tvb_get_ntohl(tvb, o + i + aoff));
}
break;
case BGPTYPE_ATOMIC_AGGREGATE:
if (tlen != 0) {
proto_tree_add_expert_format(subtree2, pinfo, &ei_bgp_length_invalid, tvb, o + i + aoff, tlen,
"Atomic aggregate (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
}
break;
case BGPTYPE_AGGREGATOR:
if (tlen != 6 && tlen != 8) {
proto_tree_add_expert_format(subtree2, pinfo, &ei_bgp_length_invalid, tvb, o + i + aoff, tlen,
"Aggregator (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
break;
}
case BGPTYPE_AS4_AGGREGATOR:
if (bgpa_type == BGPTYPE_AS4_AGGREGATOR && tlen != 8)
proto_tree_add_expert_format(subtree2, pinfo, &ei_bgp_length_invalid, tvb, o + i + aoff, tlen,
"Aggregator (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
else {
asn_len = tlen - 4;
aggregator_as = (asn_len == 2) ?
tvb_get_ntohs(tvb, o + i + aoff) :
tvb_get_ntohl(tvb, o + i + aoff);
proto_tree_add_uint(subtree2, hf_bgp_update_path_attribute_aggregator_as, tvb,
o + i + aoff, asn_len, aggregator_as);
proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_aggregator_origin, tvb,
o + i + aoff + asn_len, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti_pa, ": AS: %u origin: %s", aggregator_as,
tvb_ip_to_str(tvb, o + i + aoff + asn_len));
}
break;
case BGPTYPE_COMMUNITIES:
if (tlen % 4 != 0) {
proto_tree_add_expert_format(subtree2, pinfo, &ei_bgp_length_invalid, tvb, o + i + aoff, tlen,
"Communities (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
break;
}
proto_item_append_text(ti_pa, ": ");
ti_communities = proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_communities,
tvb, o + i + aoff, tlen, ENC_NA);
communities_tree = proto_item_add_subtree(ti_communities,
ett_bgp_communities);
proto_item_append_text(ti_communities, ": ");
q = o + i + aoff;
end = q + tlen;
while (q < end) {
guint32 community = tvb_get_ntohl(tvb, q);
if ((community & 0xFFFF0000) == FOURHEX0 ||
(community & 0xFFFF0000) == FOURHEXF) {
proto_tree_add_item(communities_tree, hf_bgp_update_path_attribute_community_well_known,
tvb, q - 3 + aoff, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti_pa, "%s ", val_to_str_const(community, community_vals, "Reserved"));
proto_item_append_text(ti_communities, "%s ", val_to_str_const(community, community_vals, "Reserved"));
}
else {
ti_community = proto_tree_add_item(communities_tree, hf_bgp_update_path_attribute_community, tvb,
q - 3 + aoff, 4, ENC_NA);
community_tree = proto_item_add_subtree(ti_community,
ett_bgp_community);
proto_tree_add_item(community_tree, hf_bgp_update_path_attribute_community_as,
tvb, q - 3 + aoff, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_update_path_attribute_community_value,
tvb, q - 1 + aoff, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti_pa, "%u:%u ",tvb_get_ntohs(tvb, q - 3 + aoff),
tvb_get_ntohs(tvb, q -1 + aoff));
proto_item_append_text(ti_communities, "%u:%u ",tvb_get_ntohs(tvb, q - 3 + aoff),
tvb_get_ntohs(tvb, q -1 + aoff));
proto_item_append_text(ti_community, ": %u:%u ",tvb_get_ntohs(tvb, q - 3 + aoff),
tvb_get_ntohs(tvb, q -1 + aoff));
}
q += 4;
}
break;
case BGPTYPE_ORIGINATOR_ID:
if (tlen != 4) {
proto_tree_add_expert_format(subtree2, pinfo, &ei_bgp_length_invalid, tvb, o + i + aoff, tlen,
"Originator identifier (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
} else {
proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_originator_id, tvb,
o + i + aoff, tlen, ENC_BIG_ENDIAN);
proto_item_append_text(ti_pa, ": %s ", tvb_ip_to_str(tvb, o + i + aoff));
}
break;
case BGPTYPE_MP_REACH_NLRI:
af = tvb_get_ntohs(tvb, o + i + aoff);
proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_mp_reach_nlri_address_family, tvb,
o + i + aoff, 2, ENC_BIG_ENDIAN);
saf = tvb_get_guint8(tvb, o + i + aoff + 2) ;
proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_mp_reach_nlri_safi, tvb,
o + i + aoff+2, 1, ENC_BIG_ENDIAN);
nexthop_len = tvb_get_guint8(tvb, o + i + aoff + 3);
subtree3 = proto_tree_add_subtree_format(subtree2, tvb, o + i + aoff + 3,
nexthop_len + 1, ett_bgp_mp_nhna, NULL,
"Next hop network address (%d byte%s)",
nexthop_len, plurality(nexthop_len, "", "s"));
switch (af) {
default:
proto_tree_add_expert(subtree3, pinfo, &ei_bgp_unknown_afi, tvb, o + i + aoff + 4, nexthop_len);
break;
case AFNUM_INET:
case AFNUM_INET6:
case AFNUM_L2VPN:
case AFNUM_L2VPN_OLD:
case AFNUM_LINK_STATE:
j = 0;
while (j < nexthop_len) {
advance = mp_addr_to_str(af, saf, tvb, o + i + aoff + 4 + j,
junk_emstr, nexthop_len) ;
if (advance == 0)
break;
if (j + advance > nexthop_len)
break;
proto_tree_add_string(subtree3, hf_bgp_update_path_attribute_mp_reach_nlri_next_hop, tvb,
o + i + aoff + 4 + j, advance, wmem_strbuf_get_str(junk_emstr));
j += advance;
}
break;
}
aoff_save = aoff;
tlen -= nexthop_len + 4;
aoff += nexthop_len + 4 ;
off = 0;
snpa = tvb_get_guint8(tvb, o + i + aoff);
ti = proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_mp_reach_nlri_nbr_snpa, tvb,
o + i + aoff, 1, ENC_BIG_ENDIAN);
off++;
if (snpa) {
subtree3 = proto_item_add_subtree(ti, ett_bgp_mp_snpa);
for (; snpa > 0; snpa--) {
guint8 snpa_length = tvb_get_guint8(tvb, o + i + aoff + off);
proto_tree_add_item(subtree3, hf_bgp_update_path_attribute_mp_reach_nlri_snpa_length, tvb,
o + i + aoff + off, 1, ENC_BIG_ENDIAN);
off++;
proto_tree_add_item(subtree3, hf_bgp_update_path_attribute_mp_reach_nlri_snpa, tvb,
o + i + aoff + off, snpa_length, ENC_NA);
off += snpa_length;
}
}
tlen -= off;
aoff += off;
subtree3 = proto_tree_add_subtree_format(subtree2, tvb, o + i + aoff, tlen,
ett_bgp_mp_reach_nlri, NULL, "Network layer reachability information (%u byte%s)",
tlen, plurality(tlen, "", "s"));
if (tlen) {
if (af != AFNUM_INET && af != AFNUM_INET6 && af != AFNUM_L2VPN && af != AFNUM_LINK_STATE) {
proto_tree_add_expert(subtree3, pinfo, &ei_bgp_unknown_afi, tvb, o + i + aoff, tlen);
} else {
while (tlen > 0) {
advance = decode_prefix_MP(subtree3,
hf_bgp_mp_reach_nlri_ipv4_prefix,
hf_bgp_mp_reach_nlri_ipv6_prefix,
af, saf,
tvb, o + i + aoff, "MP Reach NLRI", pinfo);
if (advance < 0)
break;
tlen -= advance;
aoff += advance;
}
}
}
aoff = aoff_save;
break;
case BGPTYPE_MP_UNREACH_NLRI:
af = tvb_get_ntohs(tvb, o + i + aoff);
proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_mp_unreach_nlri_address_family, tvb,
o + i + aoff, 2, ENC_BIG_ENDIAN);
saf = tvb_get_guint8(tvb, o + i + aoff + 2) ;
proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_mp_unreach_nlri_safi, tvb,
o + i + aoff+2, 1, ENC_BIG_ENDIAN);
subtree3 = proto_tree_add_subtree_format(subtree2, tvb, o + i + aoff + 3,
tlen - 3, ett_bgp_mp_unreach_nlri, NULL, "Withdrawn routes (%u byte%s)", tlen - 3,
plurality(tlen - 3, "", "s"));
aoff_save = aoff;
tlen -= 3;
aoff += 3;
if (tlen > 0) {
while (tlen > 0) {
advance = decode_prefix_MP(subtree3,
hf_bgp_mp_unreach_nlri_ipv4_prefix,
hf_bgp_mp_unreach_nlri_ipv6_prefix,
af, saf,
tvb, o + i + aoff, "MP Unreach NLRI", pinfo);
if (advance < 0)
break;
tlen -= advance;
aoff += advance;
}
}
aoff = aoff_save;
break;
case BGPTYPE_CLUSTER_LIST:
if (tlen % 4 != 0) {
proto_tree_add_expert_format(subtree2, pinfo, &ei_bgp_length_invalid, tvb, o + i + aoff, tlen,
"Cluster list (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
break;
}
ti = proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_cluster_list,
tvb, o + i + aoff, tlen, ENC_NA);
cluster_list_tree = proto_item_add_subtree(ti,
ett_bgp_cluster_list);
q = o + i + aoff;
end = q + tlen;
proto_item_append_text(ti, ":");
proto_item_append_text(ti_pa, ":");
while (q < end) {
proto_tree_add_item(cluster_list_tree, hf_bgp_update_path_attribute_cluster_id,
tvb, q - 3 + aoff, 4, ENC_NA);
proto_item_append_text(ti, " %s", tvb_ip_to_str(tvb, q-3+aoff));
proto_item_append_text(ti_pa, " %s", tvb_ip_to_str(tvb, q-3+aoff));
q += 4;
}
break;
case BGPTYPE_EXTENDED_COMMUNITY:
if (tlen %8 != 0) {
expert_add_info_format(pinfo, attr_len_item, &ei_bgp_ext_com_len_bad,
"Community length %u wrong, must be modulo 8", tlen);
} else {
dissect_bgp_update_ext_com(subtree2, tvb, tlen, o+i+aoff);
}
break;
case BGPTYPE_SAFI_SPECIFIC_ATTR:
q = o + i + aoff;
end = o + i + aoff + tlen ;
while(q < end) {
ssa_type = tvb_get_ntohs(tvb, q) & BGP_SSA_TYPE;
ssa_len = tvb_get_ntohs(tvb, q + 2);
subtree3 = proto_tree_add_subtree_format(subtree2, tvb, q, MIN(ssa_len + 4, end - q),
ett_bgp_ssa, NULL, "%s Information",
val_to_str_const(ssa_type, bgp_ssa_type, "Unknown SSA"));
proto_tree_add_item(subtree3, hf_bgp_ssa_t, tvb,
q, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree3, hf_bgp_ssa_type, tvb, q, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree3, hf_bgp_ssa_len, tvb, q + 2, 2, ENC_BIG_ENDIAN);
if ((ssa_len == 0) || (q + ssa_len > end)) {
proto_tree_add_expert_format(subtree3, pinfo, &ei_bgp_length_invalid, tvb, q + 2,
end - q - 2, "Invalid Length of %u", ssa_len);
break;
}
switch (ssa_type) {
case BGP_SSA_L2TPv3:
proto_tree_add_item(subtree3, hf_bgp_ssa_l2tpv3_pref, tvb,
q + 4, 2, ENC_BIG_ENDIAN);
subtree4 = proto_tree_add_subtree(subtree3, tvb, q + 6, 1, ett_bgp_ssa_subtree, NULL, "Flags");
proto_tree_add_item(subtree4, hf_bgp_ssa_l2tpv3_s, tvb,
q + 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree4, hf_bgp_ssa_l2tpv3_unused, tvb,
q + 6, 1, ENC_BIG_ENDIAN);
ssa_v3_len = tvb_get_guint8(tvb, q + 7);
if (ssa_v3_len + 8 == ssa_len){
proto_tree_add_item(subtree3, hf_bgp_ssa_l2tpv3_cookie_len, tvb,
q + 7, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_expert_format(subtree3, pinfo, &ei_bgp_length_invalid, tvb, q + 7, 1,
"Invalid Cookie Length of %u", ssa_v3_len);
q += ssa_len + 4;
break;
}
proto_tree_add_item(subtree3, hf_bgp_ssa_l2tpv3_session_id, tvb,
q + 8, 4, ENC_BIG_ENDIAN);
if (ssa_v3_len)
proto_tree_add_item(subtree3, hf_bgp_ssa_l2tpv3_cookie, tvb,
q + 12, ssa_v3_len, ENC_NA);
q += ssa_len + 4;
break;
case BGP_SSA_mGRE:
case BGP_SSA_IPSec:
case BGP_SSA_MPLS:
default:
proto_tree_add_item(subtree3, hf_bgp_ssa_value, tvb,
q + 4, ssa_len, ENC_NA);
q += ssa_len + 4;
break;
case BGP_SSA_L2TPv3_IN_IPSec:
case BGP_SSA_mGRE_IN_IPSec:
q += 4;
break;
}
}
break;
case BGPTYPE_TUNNEL_ENCAPS_ATTR:
q = o + i + aoff;
end = o + i + aoff + tlen;
subtree3 = proto_tree_add_subtree(subtree2, tvb, q, tlen, ett_bgp_tunnel_tlv, NULL, "TLV Encodings");
while (q < end) {
encaps_tunnel_type = tvb_get_ntohs(tvb, q);
encaps_tunnel_len = tvb_get_ntohs(tvb, q + 2);
subtree4 = proto_tree_add_subtree_format(subtree3, tvb, q, encaps_tunnel_len + 4,
ett_bgp_tunnel_tlv_subtree, NULL, "%s (%u bytes)",
val_to_str_const(encaps_tunnel_type, bgp_attr_tunnel_type, "Unknown"), encaps_tunnel_len + 4);
proto_tree_add_item(subtree4, hf_bgp_update_encaps_tunnel_tlv_type, tvb, q, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree4, hf_bgp_update_encaps_tunnel_tlv_len, tvb, q + 2, 2, ENC_BIG_ENDIAN);
subtree5 = proto_tree_add_subtree(subtree4, tvb, q + 4, encaps_tunnel_len, ett_bgp_tunnel_subtlv, NULL, "Sub-TLV Encodings");
q += 4;
j = q + encaps_tunnel_len;
while ( q < j ) {
encaps_tunnel_subtype = tvb_get_guint8(tvb, q);
encaps_tunnel_sublen = tvb_get_guint8(tvb, q + 1);
subtree6 = proto_tree_add_subtree_format(subtree5, tvb, q, encaps_tunnel_sublen + 2, ett_bgp_tunnel_tlv_subtree, NULL, "%s (%u bytes)", val_to_str_const(encaps_tunnel_subtype, subtlv_type, "Unknown"), encaps_tunnel_sublen + 2);
proto_tree_add_item(subtree6, hf_bgp_update_encaps_tunnel_subtlv_type, tvb, q, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree6, hf_bgp_update_encaps_tunnel_subtlv_len, tvb, q + 1, 1, ENC_BIG_ENDIAN);
switch (encaps_tunnel_subtype) {
case TUNNEL_SUBTLV_ENCAPSULATION:
if (encaps_tunnel_type == TUNNEL_TYPE_L2TP_OVER_IP) {
proto_tree_add_item(subtree6, hf_bgp_update_encaps_tunnel_subtlv_session_id, tvb, q + 2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree6, hf_bgp_update_encaps_tunnel_subtlv_cookie, tvb, q + 6, encaps_tunnel_sublen - 4, ENC_NA);
} else if (encaps_tunnel_type == TUNNEL_TYPE_GRE) {
proto_tree_add_item(subtree6, hf_bgp_update_encaps_tunnel_subtlv_gre_key, tvb, q + 2, 4, ENC_BIG_ENDIAN);
}
break;
case TUNNEL_SUBTLV_PROTO_TYPE:
proto_tree_add_item(subtree6, hf_bgp_update_encaps_tunnel_subtlv_gre_key, tvb, q + 2, 2, ENC_BIG_ENDIAN);
break;
case TUNNEL_SUBTLV_COLOR:
proto_tree_add_item(subtree6, hf_bgp_update_encaps_tunnel_subtlv_color_value, tvb, q + 6, 4, ENC_BIG_ENDIAN);
break;
case TUNNEL_SUBTLV_LOAD_BALANCE:
if (encaps_tunnel_type == TUNNEL_TYPE_L2TP_OVER_IP || encaps_tunnel_type == TUNNEL_TYPE_GRE) {
proto_tree_add_item(subtree6, hf_bgp_update_encaps_tunnel_subtlv_lb_block_length, tvb, q + 2, 4, ENC_BIG_ENDIAN);
}
break;
default:
break;
}
q += 2 + encaps_tunnel_sublen;
}
}
break;
case BGPTYPE_AIGP:
q = o + i + aoff;
ti = proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_aigp, tvb, q, tlen, ENC_NA);
subtree3 = proto_item_add_subtree(ti, ett_bgp_aigp_attr);
aigp_type_item = proto_tree_add_item(subtree3, hf_bgp_aigp_type, tvb, q, 1, ENC_BIG_ENDIAN);
aigp_type = tvb_get_guint8(tvb,q);
switch (aigp_type) {
case AIGP_TLV_TYPE :
proto_tree_add_item(subtree3, hf_bgp_aigp_tlv_length, tvb, q+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree3, hf_bgp_aigp_accu_igp_metric, tvb, q+3, 8, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": %" G_GINT64_MODIFIER "u", tvb_get_ntoh64(tvb, q+3));
proto_item_append_text(ti_pa, ": %" G_GINT64_MODIFIER "u", tvb_get_ntoh64(tvb, q+3));
break;
default :
expert_add_info_format(pinfo, aigp_type_item, &ei_bgp_attr_aigp_type,
"AIGP type %u unknown", aigp_type);
}
break;
case BGPTYPE_LINK_STATE_ATTR:
case BGPTYPE_LINK_STATE_OLD_ATTR:
q = o + i + aoff;
end = o + i + aoff + tlen;
save_link_state_attr_position(pinfo, q, end, tlen, subtree2);
break;
case BGPTYPE_PMSI_TUNNEL_ATTR:
dissect_bgp_update_pmsi_attr(pinfo, subtree2, tvb, tlen, o+i+aoff);
break;
case BGPTYPE_ATTR_SET:
if (alen >= 4) {
proto_tree_add_item(subtree2, hf_bgp_update_path_attribute_attrset_origin_as, tvb,
o + i + aoff, 4, ENC_BIG_ENDIAN);
if (alen > 4) {
ti = proto_tree_add_item(subtree2, hf_bgp_update_path_attributes, tvb, o+i+aoff+4, alen-4, ENC_NA);
attr_set_subtree = proto_item_add_subtree(ti, ett_bgp_attrs);
dissect_bgp_path_attr(attr_set_subtree, tvb, alen-4, o+i+aoff+4, pinfo);
}
} else {
proto_tree_add_expert_format(subtree2, pinfo, &ei_bgp_length_invalid, tvb, o + i + aoff, alen,
"Attribute set (invalid): %u bytes%s",
alen, plurality(alen, "", "s"));
}
break;
default:
proto_tree_add_item(subtree2, hf_bgp_update_path_attributes_unknown, tvb, o + i + aoff, tlen, ENC_NA);
break;
}
i += alen + aoff;
}
{
link_state_data *data = load_link_state_data(pinfo);
if (data && data->link_state_attr_present) {
ti = proto_tree_add_item(data->subtree2, hf_bgp_update_path_attribute_link_state, tvb, data->ostart, data->tlen, ENC_NA);
subtree3 = proto_item_add_subtree(ti, ett_bgp_link_state);
while (data->ostart < data->oend) {
advance = decode_link_state_attribute_tlv(subtree3, tvb, data->ostart, pinfo, data->protocol_id);
if (advance < 0) {
break;
}
data->ostart += advance;
}
}
}
}
static void
dissect_bgp_update(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo)
{
guint16 hlen;
gint o;
gint end=0;
guint16 len;
proto_item *ti;
proto_tree *subtree;
int i;
hlen = tvb_get_ntohs(tvb, BGP_MARKER_SIZE);
o = BGP_HEADER_SIZE;
len = tvb_get_ntohs(tvb, o);
proto_tree_add_item(tree, hf_bgp_update_withdrawn_routes_length, tvb, o, 2, ENC_BIG_ENDIAN);
o += 2;
if (len > 0) {
ti = proto_tree_add_item(tree, hf_bgp_update_withdrawn_routes, tvb, o, len, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_bgp_unfeas);
end = o + len;
if( detect_add_path_prefix4(tvb, o, end) ) {
while (o < end) {
i = decode_path_prefix4(subtree, pinfo, hf_bgp_nlri_path_id, hf_bgp_withdrawn_prefix, tvb, o,
"Withdrawn route");
if (i < 0)
return;
o += i;
}
} else {
while (o < end) {
i = decode_prefix4(subtree, pinfo, NULL, hf_bgp_withdrawn_prefix, tvb, o, len,
"Withdrawn route");
if (i < 0)
return;
o += i;
}
}
}
len = tvb_get_ntohs(tvb, o);
proto_tree_add_item(tree, hf_bgp_update_total_path_attribute_length, tvb, o, 2, ENC_BIG_ENDIAN);
if (len > 0) {
ti = proto_tree_add_item(tree, hf_bgp_update_path_attributes, tvb, o+2, len, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_bgp_attrs);
dissect_bgp_path_attr(subtree, tvb, len-4, o+2, pinfo);
o += 2 + len;
len = hlen - o;
if (len > 0) {
ti = proto_tree_add_item(tree, hf_bgp_update_nlri, tvb, o, len, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_bgp_nlri);
end = o + len;
if( detect_add_path_prefix4(tvb, o, end) ) {
while (o < end) {
i = decode_path_prefix4(subtree, pinfo, hf_bgp_nlri_path_id, hf_bgp_nlri_prefix, tvb, o,
"NLRI");
if (i < 0)
return;
o += i;
}
} else {
while (o < end) {
i = decode_prefix4(subtree, pinfo, NULL, hf_bgp_nlri_prefix, tvb, o, 0,
"NLRI");
if (i < 0)
return;
o += i;
}
}
}
}
}
static void
dissect_bgp_notification(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo)
{
int hlen;
int offset;
guint major_error;
proto_item *ti;
hlen = tvb_get_ntohs(tvb, BGP_MARKER_SIZE);
offset = BGP_MARKER_SIZE + 2 + 1;
proto_tree_add_item(tree, hf_bgp_notify_major_error, tvb, offset, 1, ENC_BIG_ENDIAN);
major_error = tvb_get_guint8(tvb, offset);
offset += 1;
switch(major_error){
case BGP_MAJOR_ERROR_MSG_HDR:
proto_tree_add_item(tree, hf_bgp_notify_minor_msg_hdr, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case BGP_MAJOR_ERROR_OPEN_MSG:
proto_tree_add_item(tree, hf_bgp_notify_minor_open_msg, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case BGP_MAJOR_ERROR_UPDATE_MSG:
proto_tree_add_item(tree,hf_bgp_notify_minor_update_msg, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case BGP_MAJOR_ERROR_HT_EXPIRED:
proto_tree_add_item(tree, hf_bgp_notify_minor_ht_expired, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case BGP_MAJOR_ERROR_STATE_MACHINE:
proto_tree_add_item(tree, hf_bgp_notify_minor_state_machine, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case BGP_MAJOR_ERROR_CEASE:
proto_tree_add_item(tree, hf_bgp_notify_minor_cease, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case BGP_MAJOR_ERROR_CAP_MSG:
proto_tree_add_item(tree, hf_bgp_notify_minor_cap_msg, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
ti = proto_tree_add_item(tree, hf_bgp_notify_minor_unknown, tvb, offset, 1, ENC_BIG_ENDIAN);
expert_add_info_format(pinfo, ti, &ei_bgp_notify_minor_unknown, "Unknown notification error (%d)",major_error);
break;
}
offset += 1;
if (hlen > BGP_MIN_NOTIFICATION_MSG_SIZE) {
proto_tree_add_item(tree, hf_bgp_notify_data, tvb, offset, hlen - BGP_MIN_NOTIFICATION_MSG_SIZE, ENC_NA);
}
}
static void
dissect_bgp_route_refresh(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo)
{
int p;
int pend;
guint16 hlen;
proto_item *ti;
proto_item *ti1;
proto_tree *subtree;
proto_tree *subtree1;
guint8 orftype;
guint16 orflen;
guint8 entryflag;
int entrylen;
int advance;
if (!tree)
return;
hlen = tvb_get_ntohs(tvb, BGP_MARKER_SIZE);
p = BGP_HEADER_SIZE;
proto_tree_add_item(tree, hf_bgp_route_refresh_afi, tvb, p, 2, ENC_BIG_ENDIAN);
p += 2;
proto_tree_add_item(tree, hf_bgp_route_refresh_subtype, tvb, p, 1, ENC_BIG_ENDIAN);
p++;
proto_tree_add_item(tree, hf_bgp_route_refresh_safi, tvb, p, 1, ENC_BIG_ENDIAN);
p++;
if ( hlen == BGP_HEADER_SIZE + 4 )
return;
while (p < hlen) {
ti = proto_tree_add_item(tree, hf_bgp_route_refresh_orf, tvb, p, 4, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_bgp_orf);
proto_tree_add_item(subtree, hf_bgp_route_refresh_orf_flag, tvb, p, 1, ENC_BIG_ENDIAN);
p += 1;
ti1 = proto_tree_add_item(subtree, hf_bgp_route_refresh_orf_type, tvb, p , 1, ENC_BIG_ENDIAN);
orftype = tvb_get_guint8(tvb, p);
p += 1;
proto_tree_add_item(subtree, hf_bgp_route_refresh_orf_length, tvb, p , 2, ENC_BIG_ENDIAN);
orflen = tvb_get_ntohs(tvb, p);
proto_item_set_len(ti, orflen + 4);
p += 2;
if (orftype != BGP_ORF_PREFIX_CISCO) {
expert_add_info_format(pinfo, ti1, &ei_bgp_route_refresh_orf_type_unknown, "ORFEntry-Unknown (type %u)", orftype);
p += orflen;
continue;
}
pend = p + orflen;
while (p < pend) {
ti1 = proto_tree_add_item(subtree, hf_bgp_route_refresh_orf_entry_prefixlist, tvb, p, 1, ENC_NA);
subtree1 = proto_item_add_subtree(ti1, ett_bgp_orf_entry);
proto_tree_add_item(subtree1, hf_bgp_route_refresh_orf_entry_action, tvb, p, 1, ENC_BIG_ENDIAN);
entryflag = tvb_get_guint8(tvb, p);
if (((entryflag & BGP_ORF_ACTION) >> 6) == BGP_ORF_REMOVEALL) {
p++;
continue;
}
proto_tree_add_item(subtree1, hf_bgp_route_refresh_orf_entry_match, tvb, p, 1, ENC_BIG_ENDIAN);
p++;
proto_tree_add_item(subtree1, hf_bgp_route_refresh_orf_entry_sequence, tvb, p, 4, ENC_BIG_ENDIAN);
p +=4;
proto_tree_add_item(subtree1, hf_bgp_route_refresh_orf_entry_prefixmask_lower, tvb, p, 1, ENC_BIG_ENDIAN);
p++;
proto_tree_add_item(subtree1, hf_bgp_route_refresh_orf_entry_prefixmask_upper, tvb, p, 1, ENC_BIG_ENDIAN);
p++;
advance = decode_prefix4(subtree1, pinfo, NULL, hf_bgp_route_refresh_orf_entry_ip, tvb, p, 0, "ORF");
if (advance < 0)
break;
entrylen = 7 + 1 + advance;
proto_item_set_len(ti1, entrylen);
p += advance;
}
}
}
static void
dissect_bgp_capability(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo)
{
int offset = 0;
int mend;
mend = offset + tvb_get_ntohs(tvb, offset + BGP_MARKER_SIZE);
offset += BGP_HEADER_SIZE;
while (offset < mend) {
offset = dissect_bgp_capability_item(tvb, tree, pinfo, offset, TRUE);
}
}
static void
dissect_bgp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean first)
{
guint16 bgp_len;
guint8 bgp_type;
const char *typ;
proto_item *ti_len = NULL;
proto_tree *bgp_tree = NULL;
bgp_len = tvb_get_ntohs(tvb, BGP_MARKER_SIZE);
bgp_type = tvb_get_guint8(tvb, BGP_MARKER_SIZE + 2);
typ = val_to_str(bgp_type, bgptypevals, "Unknown message type (0x%02x)");
if (first)
col_add_str(pinfo->cinfo, COL_INFO, typ);
else
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", typ);
if (tree) {
proto_item *ti;
ti = proto_tree_add_item(tree, proto_bgp, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, " - %s", typ);
switch (bgp_type) {
case BGP_OPEN:
bgp_tree = proto_item_add_subtree(ti, ett_bgp_open);
break;
case BGP_UPDATE:
bgp_tree = proto_item_add_subtree(ti, ett_bgp_update);
break;
case BGP_NOTIFICATION:
bgp_tree = proto_item_add_subtree(ti, ett_bgp_notification);
break;
case BGP_KEEPALIVE:
bgp_tree = proto_item_add_subtree(ti, ett_bgp);
break;
case BGP_ROUTE_REFRESH_CISCO:
case BGP_ROUTE_REFRESH:
bgp_tree = proto_item_add_subtree(ti, ett_bgp_route_refresh);
break;
case BGP_CAPABILITY:
bgp_tree = proto_item_add_subtree(ti, ett_bgp_capability);
break;
default:
bgp_tree = proto_item_add_subtree(ti, ett_bgp);
break;
}
proto_tree_add_item(bgp_tree, hf_bgp_marker, tvb, 0, 16, ENC_NA);
ti_len = proto_tree_add_item(bgp_tree, hf_bgp_length, tvb, 16, 2, ENC_BIG_ENDIAN);
}
if (bgp_len < BGP_HEADER_SIZE || bgp_len > BGP_MAX_PACKET_SIZE) {
expert_add_info_format(pinfo, ti_len, &ei_bgp_length_invalid, "Length is invalid %u", bgp_len);
return;
}
proto_tree_add_item(bgp_tree, hf_bgp_type, tvb, 16 + 2, 1, ENC_BIG_ENDIAN);
switch (bgp_type) {
case BGP_OPEN:
dissect_bgp_open(tvb, bgp_tree, pinfo);
break;
case BGP_UPDATE:
dissect_bgp_update(tvb, bgp_tree, pinfo);
break;
case BGP_NOTIFICATION:
dissect_bgp_notification(tvb, bgp_tree, pinfo);
break;
case BGP_KEEPALIVE:
break;
case BGP_ROUTE_REFRESH_CISCO:
case BGP_ROUTE_REFRESH:
dissect_bgp_route_refresh(tvb, bgp_tree, pinfo);
break;
case BGP_CAPABILITY:
dissect_bgp_capability(tvb, bgp_tree, pinfo);
break;
default:
break;
}
}
static int
dissect_bgp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
volatile int offset = 0;
gint reported_length_remaining;
guint8 bgp_marker[BGP_MARKER_SIZE];
static guchar marker[] = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};
proto_item *ti;
proto_tree *bgp_tree;
guint16 bgp_len;
int offset_before;
guint length_remaining;
guint length;
volatile gboolean first = TRUE;
tvbuff_t *volatile next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BGP");
col_clear(pinfo->cinfo, COL_INFO);
while ((reported_length_remaining = tvb_reported_length_remaining(tvb, offset))
> 0) {
if (reported_length_remaining > BGP_MARKER_SIZE)
reported_length_remaining = BGP_MARKER_SIZE;
tvb_memcpy(tvb, bgp_marker, offset, reported_length_remaining);
if (memcmp(bgp_marker, marker, reported_length_remaining) == 0) {
break;
}
offset++;
}
if (offset > 0) {
ti = proto_tree_add_item(tree, proto_bgp, tvb, 0, -1, ENC_NA);
bgp_tree = proto_item_add_subtree(ti, ett_bgp);
proto_tree_add_item(bgp_tree, hf_bgp_continuation, tvb, 0, offset, ENC_NA);
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
length_remaining = tvb_ensure_captured_length_remaining(tvb, offset);
if (bgp_desegment && pinfo->can_desegment) {
if (length_remaining < BGP_HEADER_SIZE) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return tvb_captured_length(tvb);
}
}
bgp_len = tvb_get_ntohs(tvb, offset + BGP_MARKER_SIZE);
if (bgp_len < BGP_HEADER_SIZE) {
show_reported_bounds_error(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
if (bgp_desegment && pinfo->can_desegment) {
if (length_remaining < bgp_len) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = bgp_len - length_remaining;
return tvb_captured_length(tvb);
}
}
length = length_remaining;
if (length > bgp_len)
length = bgp_len;
next_tvb = tvb_new_subset(tvb, offset, length, bgp_len);
TRY {
dissect_bgp_pdu(next_tvb, pinfo, tree, first);
}
CATCH_NONFATAL_ERRORS {
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
first = FALSE;
offset_before = offset;
offset += bgp_len;
if (offset <= offset_before)
break;
}
return tvb_captured_length(tvb);
}
void
proto_register_bgp(void)
{
static hf_register_info hf[] = {
{ &hf_bgp_marker,
{ "Marker", "bgp.marker", FT_BYTES, BASE_NONE,
NULL, 0x0, "Must be set to all ones (16 Bytes)", HFILL }},
{ &hf_bgp_length,
{ "Length", "bgp.length", FT_UINT16, BASE_DEC,
NULL, 0x0, "The total length of the message, including the header in octets", HFILL }},
{ &hf_bgp_prefix_length,
{ "Prefix Length", "bgp.prefix_length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_rd,
{ "Route Distinguisher", "bgp.rd", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_continuation,
{ "Continuation", "bgp.continuation", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_originating_as,
{ "Originating AS", "bgp.originating_as", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_community_prefix,
{ "Community Prefix", "bgp.community_prefix", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_endpoint_address,
{ "Endpoint Address", "bgp.endpoint_address", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_endpoint_address_ipv6,
{ "Endpoint Address", "bgp.endpoint_address_ipv6", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_label_stack,
{ "Label Stack", "bgp.label_stack", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_vplsad_length,
{ "Length", "bgp.vplsad.length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_vplsad_rd,
{ "RD", "bgp.vplsad.rd", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_bgpad_pe_addr,
{ "PE Addr", "bgp.ad.pe_addr", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_vplsbgp_ce_id,
{ "CE-ID", "bgp.vplsbgp.ce_id", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_vplsbgp_labelblock_offset,
{ "Label Block Offset", "bgp.vplsbgp.labelblock.offset", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_vplsbgp_labelblock_size,
{ "Label Block Size", "bgp.vplsbgp.labelblock.size", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_vplsbgp_labelblock_base,
{ "Label Block Base", "bgp.vplsbgp.labelblock.base", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_wildcard_route_target,
{ "Wildcard route target", "bgp.wildcard_route_target", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_type,
{ "Type", "bgp.type", FT_UINT8, BASE_DEC,
VALS(bgptypevals), 0x0, "BGP message type", HFILL }},
{ &hf_bgp_open_version,
{ "Version", "bgp.open.version", FT_UINT8, BASE_DEC,
NULL, 0x0, "The protocol version number", HFILL }},
{ &hf_bgp_open_myas,
{ "My AS", "bgp.open.myas", FT_UINT16, BASE_DEC,
NULL, 0x0, "The Autonomous System number of the sender", HFILL }},
{ &hf_bgp_open_holdtime,
{ "Hold Time", "bgp.open.holdtime", FT_UINT16, BASE_DEC,
NULL, 0x0, "The number of seconds the sender proposes for Hold Time", HFILL }},
{ &hf_bgp_open_identifier,
{ "BGP Identifier", "bgp.open.identifier", FT_IPv4, BASE_NONE,
NULL, 0x0, "The BGP Identifier of the sender", HFILL }},
{ &hf_bgp_open_opt_len,
{ "Optional Parameters Length", "bgp.open.opt.len", FT_UINT8, BASE_DEC,
NULL, 0x0, "The total length of the Optional Parameters field in octets", HFILL }},
{ &hf_bgp_open_opt_params,
{ "Optional Parameters", "bgp.open.opt", FT_NONE, BASE_NONE,
NULL, 0x0, "List of optional parameters", HFILL }},
{ &hf_bgp_open_opt_param,
{ "Optional Parameter", "bgp.open.opt.param", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_open_opt_param_type,
{ "Parameter Type", "bgp.open.opt.param.type", FT_UINT8, BASE_DEC,
VALS(bgp_open_opt_vals), 0x0, "Unambiguously identifies individual parameters", HFILL }},
{ &hf_bgp_open_opt_param_len,
{ "Parameter Length", "bgp.open.opt.param.len", FT_UINT8, BASE_DEC,
NULL, 0x0, "Length of the Parameter Value", HFILL }},
{ &hf_bgp_open_opt_param_auth,
{ "Authentication Data", "bgp.open.opt.param.auth", FT_BYTES, BASE_NONE,
NULL, 0x0, "Deprecated", HFILL }},
{ &hf_bgp_open_opt_param_unknown,
{ "Unknown", "bgp.open.opt.param.unknown", FT_BYTES, BASE_NONE,
NULL, 0x0, "Unknown Parameter", HFILL }},
{ &hf_bgp_notify_major_error,
{ "Major error Code", "bgp.notify.major_error", FT_UINT8, BASE_DEC,
VALS(bgpnotify_major), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_msg_hdr,
{ "Minor error Code (Message Header)", "bgp.notify.minor_error", FT_UINT8, BASE_DEC,
VALS(bgpnotify_minor_msg_hdr), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_open_msg,
{ "Minor error Code (Open Message)", "bgp.notify.minor_error_open", FT_UINT8, BASE_DEC,
VALS(bgpnotify_minor_open_msg), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_update_msg,
{ "Minor error Code (Update Message)", "bgp.notify.minor_error_update", FT_UINT8, BASE_DEC,
VALS(bgpnotify_minor_update_msg), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_ht_expired,
{ "Minor error Code (Hold Timer Expired)", "bgp.notify.minor_error_expired", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_state_machine,
{ "Minor error Code (State Machine)", "bgp.notify.minor_error_state", FT_UINT8, BASE_DEC,
VALS(bgpnotify_minor_state_machine), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_cease,
{ "Minor error Code (Cease)", "bgp.notify.minor_error_cease", FT_UINT8, BASE_DEC,
VALS(bgpnotify_minor_cease), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_cap_msg,
{ "Minor error Code (Capability Message)", "bgp.notify.minor_error_capability", FT_UINT8, BASE_DEC,
VALS(bgpnotify_minor_cap_msg), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_unknown,
{ "Minor error Code (Unknown)", "bgp.notify.minor_error_unknown", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_notify_data,
{ "Data", "bgp.notify.minor_data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_afi,
{ "Address family identifier (AFI)", "bgp.route_refresh.afi", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_subtype,
{ "Subtype", "bgp.route_refresh.subtype", FT_UINT8, BASE_DEC,
VALS(route_refresh_subtype_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_safi,
{ "Subsequent address family identifier (SAFI)", "bgp.route_refresh.safi", FT_UINT8, BASE_DEC,
VALS(bgpattr_nlri_safi), 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf,
{ "ORF information", "bgp.route_refresh.orf", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_flag,
{ "ORF flag", "bgp.route_refresh.orf.flag", FT_UINT8, BASE_DEC,
VALS(orf_when_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_type,
{ "ORF type", "bgp.route_refresh.orf.type", FT_UINT8, BASE_DEC,
VALS(orf_type_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_length,
{ "ORF length", "bgp.route_refresh.orf.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_prefixlist,
{ "ORFEntry PrefixList", "bgp.route_refresh.orf.entry", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_action,
{ "ORFEntry Action", "bgp.route_refresh.orf.entry.action", FT_UINT8, BASE_DEC,
VALS(orf_entry_action_vals), BGP_ORF_ACTION, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_match,
{ "ORFEntry Match", "bgp.route_refresh.orf.entry.match", FT_UINT8, BASE_DEC,
VALS(orf_entry_match_vals), BGP_ORF_MATCH, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_sequence,
{ "ORFEntry Sequence", "bgp.route_refresh.orf.entry.sequence", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_prefixmask_lower,
{ "ORFEntry PrefixMask length lower bound", "bgp.route_refresh.orf.entry.prefixmask_lower", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_prefixmask_upper,
{ "ORFEntry PrefixMask length upper bound", "bgp.route_refresh.orf.entry.prefixmask_upper", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_ip,
{ "ORFEntry IP address", "bgp.route_refresh.orf.entry.ip", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap,
{ "Capability", "bgp.cap", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_type,
{ "Type", "bgp.cap.type", FT_UINT8, BASE_DEC,
VALS(capability_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_length,
{ "Length", "bgp.cap.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_action,
{ "Action", "bgp.cap.action", FT_UINT8, BASE_DEC,
VALS(bgpcap_action), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_unknown,
{ "Unknown", "bgp.cap.unknown", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_reserved,
{ "Reserved", "bgp.cap.reserved", FT_BYTES, BASE_NONE,
NULL, 0x0, "Must be Zero", HFILL }},
{ &hf_bgp_cap_mp_afi,
{ "AFI", "bgp.cap.mp.afi", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_mp_safi,
{ "SAFI", "bgp.cap.mp.safi", FT_UINT8, BASE_DEC,
VALS(bgpattr_nlri_safi), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_gr_timers,
{ "Restart Timers", "bgp.cap.gr.timers", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_gr_timers_restart_flag,
{ "Restart", "bgp.cap.gr.timers.restart_flag", FT_BOOLEAN, 16,
TFS(&tfs_yes_no), 0x8000, NULL, HFILL }},
{ &hf_bgp_cap_gr_timers_restart_time,
{ "Time", "bgp.cap.gr.timers.restart_time", FT_UINT16, BASE_DEC,
NULL, 0x0FFF, "in us", HFILL }},
{ &hf_bgp_cap_gr_afi,
{ "AFI", "bgp.cap.gr.afi", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_gr_safi,
{ "SAFI", "bgp.cap.gr.safi", FT_UINT8, BASE_DEC,
VALS(bgpattr_nlri_safi), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_gr_flag,
{ "Flag", "bgp.cap.gr.flag", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_gr_flag_pfs,
{ "Preserve forwarding state", "bgp.cap.gr.flag.pfs", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), 0x80, NULL, HFILL }},
{ &hf_bgp_cap_4as,
{ "AS Number", "bgp.cap.4as", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_dc,
{ "Capability Dynamic", "bgp.cap.dc", FT_UINT8, BASE_DEC,
VALS(capability_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_ap_afi,
{ "AFI", "bgp.cap.ap.afi", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_ap_safi,
{ "SAFI", "bgp.cap.ap.safi", FT_UINT8, BASE_DEC,
VALS(bgpattr_nlri_safi), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_ap_sendreceive,
{ "Send/Receive", "bgp.cap.ap.sendreceive", FT_UINT8, BASE_DEC,
VALS(orf_send_recv_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_orf_afi,
{ "AFI", "bgp.cap.orf.afi", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_orf_safi,
{ "SAFI", "bgp.cap.orf.safi", FT_UINT8, BASE_DEC,
VALS(bgpattr_nlri_safi), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_orf_number,
{ "Number", "bgp.cap.orf.number", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_orf_type,
{ "Type", "bgp.cap.orf.type", FT_UINT8, BASE_DEC,
VALS(orf_type_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_orf_sendreceive,
{ "Send Receive", "bgp.cap.orf.sendreceive", FT_UINT8, BASE_DEC,
VALS(orf_send_recv_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_fqdn_hostname_len,
{ "Hostname Length", "bgp.cap.orf.fqdn.hostname.len", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_fqdn_hostname,
{ "Hostname", "bgp.cap.orf.fqdn.hostname", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_fqdn_domain_name_len,
{ "Domain Name Length", "bgp.cap.orf.fqdn.domain_name.len", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_fqdn_domain_name,
{ "Domain Name", "bgp.cap.orf.fqdn.domain_name", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_multisession_flags,
{ "Flag", "bgp.cap.multisession.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_update_withdrawn_routes_length,
{ "Withdrawn Routes Length", "bgp.update.withdrawn_routes.length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_withdrawn_routes,
{ "Withdrawn Routes", "bgp.update.withdrawn_routes", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_aggregator_as,
{ "Aggregator AS", "bgp.update.path_attribute.aggregator_as", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attributes,
{ "Path attributes", "bgp.update.path_attributes", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attributes_unknown,
{ "Unknown Path attributes", "bgp.update.path_attributes.unknown", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_total_path_attribute_length,
{ "Total Path Attribute Length", "bgp.update.path_attributes.length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_aggregator_origin,
{ "Aggregator origin", "bgp.update.path_attribute.aggregator_origin", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_as_path_segment,
{ "AS Path segment", "bgp.update.path_attribute.as_path_segment", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_as_path_segment_type,
{ "Segment type", "bgp.update.path_attribute.as_path_segment.type", FT_UINT8, BASE_DEC,
VALS(as_segment_type), 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_as_path_segment_length,
{ "Segment length (number of ASN)", "bgp.update.path_attribute.as_path_segment.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_as_path_segment_as2,
{ "AS2", "bgp.update.path_attribute.as_path_segment.as2", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_as_path_segment_as4,
{ "AS4", "bgp.update.path_attribute.as_path_segment.as4", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_communities,
{ "Communities", "bgp.update.path_attribute.communities", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_community,
{ "Community", "bgp.update.path_attribute.community", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_community_well_known,
{ "Community Well-known", "bgp.update.path_attribute.community_wellknown", FT_UINT32, BASE_HEX,
VALS(community_vals), 0x0, "Reserved", HFILL}},
{ &hf_bgp_update_path_attribute_community_as,
{ "Community AS", "bgp.update.path_attribute.community_as", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_community_value,
{ "Community value", "bgp.update.path_attribute.community_value", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_local_pref,
{ "Local preference", "bgp.update.path_attribute.local_pref", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_attrset_origin_as,
{ "Origin AS", "bgp.update.path_attribute.attr_set.origin_as", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_multi_exit_disc,
{ "Multiple exit discriminator", "bgp.update.path_attribute.multi_exit_disc", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_next_hop,
{ "Next hop", "bgp.update.path_attribute.next_hop", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_origin,
{ "Origin", "bgp.update.path_attribute.origin", FT_UINT8, BASE_DEC,
VALS(bgpattr_origin), 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute,
{ "Path Attribute", "bgp.update.path_attribute", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_flags,
{ "Flags", "bgp.update.path_attribute.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_flags_optional,
{ "Optional", "bgp.update.path_attribute.flags.optional", FT_BOOLEAN, 8,
TFS(&tfs_optional_wellknown), BGP_ATTR_FLAG_OPTIONAL, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_flags_transitive,
{ "Transitive", "bgp.update.path_attribute.flags.transitive", FT_BOOLEAN, 8,
TFS(&tfs_transitive_non_transitive), BGP_ATTR_FLAG_TRANSITIVE, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_flags_partial,
{ "Partial", "bgp.update.path_attribute.flags.partial", FT_BOOLEAN, 8,
TFS(&tfs_partial_complete), BGP_ATTR_FLAG_PARTIAL, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_flags_extended_length,
{ "Length", "bgp.update.path_attribute.flags.extended_length", FT_BOOLEAN, 8,
TFS(&tfs_extended_regular_length), BGP_ATTR_FLAG_EXTENDED_LENGTH, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_type_code,
{ "Type Code", "bgp.update.path_attribute.type_code", FT_UINT8, BASE_DEC,
VALS(bgpattr_type), 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_length,
{ "Length", "bgp.update.path_attribute.length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_link_state,
{ "Link State", "bgp.update.path_attribute.link_state", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_mp_reach_nlri_address_family,
{ "Address family identifier (AFI)", "bgp.update.path_attribute.mp_reach_nlri.afi", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_update_path_attribute_mp_reach_nlri_safi,
{ "Subsequent address family identifier (SAFI)", "bgp.update.path_attribute.mp_reach_nlri.afi", FT_UINT8, BASE_DEC,
VALS(bgpattr_nlri_safi), 0x0, NULL, HFILL }},
{ &hf_bgp_update_path_attribute_mp_reach_nlri_next_hop,
{ "Next Hop", "bgp.update.path_attribute.mp_reach_nlri.next_hop", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_update_path_attribute_mp_reach_nlri_nbr_snpa,
{ "Number of Subnetwork points of attachment (SNPA)", "bgp.update.path_attribute.mp_reach_nlri.nbr_snpa", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_update_path_attribute_mp_reach_nlri_snpa_length,
{ "SNPA Length", "bgp.update.path_attribute.mp_reach_nlri.snpa_length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_update_path_attribute_mp_reach_nlri_snpa,
{ "SNPA", "bgp.update.path_attribute.mp_reach_nlri.snpa", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_update_path_attribute_mp_unreach_nlri_address_family,
{ "Address family identifier (AFI)", "bgp.update.path_attribute.mp_unreach_nlri.afi", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_update_path_attribute_mp_unreach_nlri_safi,
{ "Subsequent address family identifier (SAFI)", "bgp.update.path_attribute.mp_unreach_nlri.afi", FT_UINT8, BASE_DEC,
VALS(bgpattr_nlri_safi), 0x0, NULL, HFILL }},
{ &hf_bgp_pmsi_tunnel_flags,
{ "Flags", "bgp.update.path_attribute.pmsi.tunnel.flags", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_type,
{ "Tunnel Type", "bgp.update.path_attribute.pmsi.tunnel.type", FT_UINT8, BASE_DEC,
VALS(pmsi_tunnel_type), 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_id,
{ "Tunnel ID", "bgp.update.path_attribute.pmsi.tunnel.id", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_not_present,
{ "Tunnel ID not present", "bgp.update.path_attribute.pmsi.tunnel_id.not_present", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_mpls_label,
{ "MPLS Label Stack", "bgp.update.path_attribute.mpls_label", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_mpls_label_value_20bits,
{ "MPLS Label", "bgp.update.path_attribute.mpls_label_value_20bits", FT_UINT24,
BASE_DEC, NULL, 0xFFFFF0, NULL, HFILL}},
{ &hf_bgp_update_mpls_label_value,
{ "MPLS Label", "bgp.update.path_attribute.mpls_label_value", FT_UINT24,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_rsvp_p2mp_id,
{ "RSVP P2MP id", "bgp.update.path_attribute.pmsi.rsvp.id", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_rsvp_p2mp_tunnel_id,
{ "RSVP P2MP tunnel id", "bgp.update.path_attribute.pmsi.rsvp.tunnel_id", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_rsvp_p2mp_ext_tunnel_idv4,
{ "RSVP P2MP extended tunnel id", "bgp.update.path_attribute.pmsi.rsvp.ext_tunnel_idv4", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_mldp_fec_el_type,
{ "mLDP P2MP FEC element type", "bgp.update.path_attribute.pmsi.mldp.fec.type", FT_UINT8, BASE_DEC,
VALS(fec_types_vals), 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_mldp_fec_el_afi,
{"mLDP P2MP FEC element address family", "bgp.update.path_attribute.pmsi.mldp.fec.address_family", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_mldp_fec_el_adr_len,
{"mLDP P2MP FEC element address length", "bgp.update.path_attribute.pmsi.mldp.fec.address_length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_mldp_fec_el_root_nodev4,
{"mLDP P2MP FEC element root node address", "bgp.update.path_attribute.pmsi.mldp.fec.root_nodev4", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_mldp_fec_el_root_nodev6,
{"mLDP P2MP FEC element root node address", "bgp.update.path_attribute.pmsi.mldp.fec.root_nodev6", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_mldp_fec_el_opa_len,
{"mLDP P2MP FEC element opaque length", "bgp.update.path_attribute.pmsi.mldp.fec.opaque_length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_mldp_fec_el_opa_val_type,
{"mLDP P2MP FEC element opaque value type", "bgp.update.path_attribute.pmsi.mldp.fec.opaque_value_type", FT_UINT8, BASE_DEC,
VALS(pmsi_mldp_fec_opaque_value_type), 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_mldp_fec_el_opa_val_len,
{"mLDP P2MP FEC element opaque value length", "bgp.update.path_attribute.pmsi.mldp.fec.opaque_value_length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_mldp_fec_el_opa_value_rn,
{"mLDP P2MP FEC element opaque value unique Id", "bgp.update.path_attribute.pmsi.mldp.fec.opaque_value_unique_id_rn", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_mldp_fec_el_opa_value_str,
{"mLDP P2MP FEC element opaque value unique Id", "bgp.update.path_attribute.pmsi.mldp.fec.opaque_value_unique_id_str", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_mldp_fec_el_opa_val_ext_type,
{"mLDP P2MP FEC element opaque extended value type", "bgp.update.path_attribute.pmsi.mldp.fec.opaque_ext_value_type", FT_UINT16, BASE_DEC,
VALS(pmsi_mldp_fec_opa_extented_type), 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_mldp_fec_el_opa_val_ext_len,
{"mLDP P2MP FEC element opaque extended length", "bgp.update.path_attribute.pmsi.mldp.fec.opaque_ext_length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_pimsm_sender,
{"PIM-SM Tree tunnel sender address", "bgp.update.path_attribute.pmsi.pimsm.sender_address", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_pimsm_pmc_group,
{"PIM-SM Tree tunnel P-multicast group", "bgp.update.path_attribute.pmsi.pimsm.pmulticast_group", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_pimssm_root_node,
{"PIM-SSM Tree tunnel Root Node", "bgp.update.path_attribute.pmsi.pimssm.root_node", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_pimssm_pmc_group,
{"PIM-SSM Tree tunnel P-multicast group", "bgp.update.path_attribute.pmsi.pimssm.pmulticast_group", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_pimbidir_sender,
{"BIDIR-PIM Tree Tunnel sender address", "bgp.update.path_attribute.pmsi.bidir_pim_tree.sender", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_pimbidir_pmc_group,
{"BIDIR-PIM Tree Tunnel P-multicast group", "bgp.update.path_attribute.pmsi.bidir_pim_tree.pmulticast_group", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_pmsi_tunnel_ingress_rep_addr,
{"Tunnel type ingress replication IP end point", "bgp.update.path_attribute.pmsi.ingress_rep_ip", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_aigp,
{ "AIGP Attribute", "bgp.update.path_attribute.aigp", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_aigp_type,
{"AIGP attribute type", "bgp.update.attribute.aigp.type", FT_UINT8, BASE_DEC,
VALS(aigp_tlv_type), 0x0, NULL, HFILL }},
{ &hf_bgp_aigp_tlv_length,
{"AIGP TLV length", "bgp.update.attribute.aigp.length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_aigp_accu_igp_metric,
{"AIGP Accumulated IGP Metric", "bgp.update.attribute.aigp.accu_igp_metric", FT_UINT64, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_originator_id,
{ "Originator identifier", "bgp.update.path_attribute.originator_id", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_cluster_list,
{ "Cluster List", "bgp.path_attribute.cluster_list", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_path_attribute_cluster_id,
{ "Cluster ID", "bgp.path_attribute.cluster_id", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_encaps_tunnel_tlv_len,
{ "length", "bgp.update.encaps_tunnel_tlv_len", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_encaps_tunnel_tlv_type,
{ "Type code", "bgp.update.encaps_tunnel_tlv_type", FT_UINT16, BASE_DEC,
VALS(bgp_attr_tunnel_type), 0x0, NULL, HFILL}},
{ &hf_bgp_update_encaps_tunnel_subtlv_len,
{ "length", "bgp.update.encaps_tunnel_tlv_sublen", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_encaps_tunnel_subtlv_type,
{ "Type code", "bgp.update.encaps_tunnel_subtlv_type", FT_UINT8, BASE_DEC,
VALS(subtlv_type), 0x0, NULL, HFILL}},
{ &hf_bgp_update_encaps_tunnel_subtlv_session_id,
{ "Session ID", "bgp.update.encaps_tunnel_tlv_subtlv_session_id", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_encaps_tunnel_subtlv_cookie,
{ "Cookie", "bgp.update.encaps_tunnel_tlv_subtlv_cookie", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_encaps_tunnel_subtlv_gre_key,
{ "GRE Key", "bgp.update.encaps_tunnel_tlv_subtlv_gre_key", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_encaps_tunnel_subtlv_color_value,
{ "Color Value", "bgp.update.encaps_tunnel_tlv_subtlv_color_value", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_encaps_tunnel_subtlv_lb_block_length,
{ "Load-balancing block length", "bgp.update.encaps_tunnel_tlv_subtlv_lb_block_length", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ssa_t,
{ "Transitive bit", "bgp.ssa_t", FT_BOOLEAN, 8,
NULL, 0x80, "SSA Transitive bit", HFILL}},
{ &hf_bgp_ssa_type,
{ "SSA Type", "bgp.ssa_type", FT_UINT16, BASE_DEC,
VALS(bgp_ssa_type), 0x7FFF, NULL, HFILL}},
{ &hf_bgp_ssa_len,
{ "Length", "bgp.ssa_len", FT_UINT16, BASE_DEC,
NULL, 0x0, "SSA Length", HFILL}},
{ &hf_bgp_ssa_value,
{ "Value", "bgp.ssa_value", FT_BYTES, BASE_NONE,
NULL, 0x0, "SSA Value", HFILL}},
{ &hf_bgp_ssa_l2tpv3_pref,
{ "Preference", "bgp.ssa_l2tpv3_pref", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ssa_l2tpv3_s,
{ "Sequencing bit", "bgp.ssa_l2tpv3_s", FT_BOOLEAN, 8,
NULL, 0x80, "Sequencing S-bit", HFILL}},
{ &hf_bgp_ssa_l2tpv3_unused,
{ "Unused", "bgp.ssa_l2tpv3_Unused", FT_BOOLEAN, 8,
NULL, 0x7F, "Unused Flags", HFILL}},
{ &hf_bgp_ssa_l2tpv3_cookie_len,
{ "Cookie Length", "bgp.ssa_l2tpv3_cookie_len", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ssa_l2tpv3_session_id,
{ "Session ID", "bgp.ssa_l2tpv3_session_id", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ssa_l2tpv3_cookie,
{ "Cookie", "bgp.ssa_l2tpv3_cookie", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_withdrawn_prefix,
{ "Withdrawn prefix", "bgp.withdrawn_prefix", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_update_nlri,
{ "Network Layer Reachability Information (NLRI)", "bgp.update.nlri", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mp_reach_nlri_ipv4_prefix,
{ "MP Reach NLRI IPv4 prefix", "bgp.mp_reach_nlri_ipv4_prefix", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mp_unreach_nlri_ipv4_prefix,
{ "MP Unreach NLRI IPv4 prefix", "bgp.mp_unreach_nlri_ipv4_prefix", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mp_reach_nlri_ipv6_prefix,
{ "MP Reach NLRI IPv6 prefix", "bgp.mp_reach_nlri_ipv6_prefix", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mp_unreach_nlri_ipv6_prefix,
{ "MP Unreach NLRI IPv6 prefix", "bgp.mp_unreach_nlri_ipv6_prefix", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mp_nlri_tnl_id,
{ "MP Reach NLRI Tunnel Identifier", "bgp.mp_nlri_tnl_id", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_nlri_prefix,
{ "NLRI prefix", "bgp.nlri_prefix", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_nlri_path_id,
{ "NLRI path id", "bgp.nlri_path_id", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_t,
{ "MCAST-VPN nlri", "bgp.mcast_vpn_nlri", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_route_type,
{ "Route Type", "bgp.mcast_vpn_nlri_route_type", FT_UINT8,
BASE_DEC, VALS(mcast_vpn_route_type), 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_length,
{ "Length", "bgp.mcast_vpn_nlri_length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_rd,
{ "Route Distinguisher", "bgp.mcast_vpn_nlri_rd", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_origin_router_ipv4,
{ "Originating Router", "bgp.mcast_vpn_nlri_origin_router_ipv4", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_origin_router_ipv6,
{ "Originating Router", "bgp.mcast_vpn_nlri_origin_router_ipv6", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_source_as,
{ "Source AS", "bgp.mcast_vpn_nlri_source_as", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_source_length,
{ "Multicast Source Length", "bgp.mcast_vpn_nlri_source_length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_group_length,
{ "Multicast Group Length", "bgp.mcast_vpn_nlri_group_length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_source_addr_ipv4,
{ "Multicast Source Address", "bgp.mcast_vpn_nlri_source_addr_ipv4", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_source_addr_ipv6,
{ "Multicast Source Address", "bgp.mcast_vpn_nlri_source_addr_ipv6", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_group_addr_ipv4,
{ "Multicast Group Address", "bgp.mcast_vpn_nlri_group_addr_ipv4", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_group_addr_ipv6,
{ "Group Address", "bgp.mcast_vpn_nlri_group_addr_ipv6", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_route_key,
{ "Route Key", "bgp.mcast_vpn_nlri_route_key", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_flowspec_nlri_t,
{ "FLOW-SPEC nlri", "bgp.flowspec_nlri", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_flowspec_nlri_filter,
{ "Filter", "bgp.flowspec_nlri.filter", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_filter_type,
{ "Filter type", "bgp.flowspec_nlri.filter_type", FT_UINT8, BASE_DEC,
VALS(flowspec_nlri_opvaluepair_type), 0x0, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_length,
{ "NRLI length", "bgp.flowspec_nlri.length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_op_flags,
{ "Operator flags", "bgp.flowspec_nlri.opflags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_dst_pref_ipv4,
{ "Destination IP filter", "bgp.flowspec_nlri.dst_prefix_filter", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_flowspec_nlri_src_pref_ipv4,
{ "Source IP filter", "bgp.flowspec_nlri.src_prefix_filter", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_flowspec_nlri_op_eol,
{ "end-of-list", "bgp.flowspec_nlri.op.eol", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_END_OF_LST, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_op_and,
{ "and", "bgp.flowspec_nlri.op.and", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_AND_BIT, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_op_val_len,
{ "Value length", "bgp.flowspec_nlri.op.val_len", FT_UINT8, BASE_DEC,
VALS(flow_spec_op_len_val), BGPNLRI_FSPEC_VAL_LEN, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_op_un_bit4,
{ "Reserved", "bgp.flowspec_nlri.op.un_bit4", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_UNUSED_BIT4, "Unused (must be zero)",HFILL}},
{ &hf_bgp_flowspec_nlri_op_un_bit5,
{ "Reserved", "bgp.flowspec_nlri.op.un_bit5", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_UNUSED_BIT5, "Unused (must be zero)", HFILL}},
{ &hf_bgp_flowspec_nlri_dec_val_8,
{ "Decimal value", "bgp.flowspec_nlri.dec_val_8", FT_UINT8, BASE_DEC,
NULL, 0X0, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_dec_val_16,
{ "Decimal value", "bgp.flowspec_nlri.dec_val_16", FT_UINT16, BASE_DEC,
NULL, 0X0, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_dec_val_32,
{ "Decimal value", "bgp.flowspec_nlri.dec_val_32", FT_UINT32, BASE_DEC,
NULL, 0X0, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_dec_val_64,
{ "Decimal value", "bgp.flowspec_nlri.dec_val_64", FT_UINT64, BASE_DEC,
NULL, 0X0, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_op_lt,
{ "less than", "bgp.flowspec_nlri.op.lt", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_LESS_THAN, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_op_gt,
{ "greater than", "bgp.flowspec_nlri.op.gt", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_GREATER_THAN, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_op_eq,
{ "equal", "bgp.flowspec_nlri.op.equal", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_EQUAL, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_op_flg_not,
{ "logical negation", "bgp.flowspec_nlri.op.flg_not", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_TCPF_NOTBIT, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_op_flg_match,
{ "Match bit", "bgp.flowspec_nlri.op.flg_match", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_TCPF_MATCHBIT, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_tcp_flags,
{ "TCP flags", "bgp.flowspec_nlri.val_tcp.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_tcp_flags_cwr,
{ "Congestion Window Reduced (CWR)", "bgp.flowspec_nlri.val_tcp.flags.cwr", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_TH_CWR, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_tcp_flags_ecn,
{ "ECN-Echo", "bgp.flowspec_nlri.val_tcp.flags.ecn", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_TH_ECN, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_tcp_flags_urg,
{ "Urgent", "bgp.flowspec_nlri.val_tcp.flags.urg", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_TH_URG, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_tcp_flags_ack,
{ "Acknowledgment", "bgp.flowspec_nlri.val_tcp.flags.ack", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_TH_ACK, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_tcp_flags_push,
{ "Push", "bgp.flowspec_nlri.val_tcp.flags.push", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_TH_PUSH, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_tcp_flags_reset,
{ "Reset", "bgp.flowspec_nlri.val_tcp.flags.reset", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_TH_RST, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_tcp_flags_syn,
{ "Syn", "bgp.flowspec_nlri.val_tcp.flags.syn", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_TH_SYN, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_tcp_flags_fin,
{ "Fin", "bgp.flowspec_nlri.val_tcp.flags.fin", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_TH_FIN, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_fflag,
{ "Fragment Flag", "bgp.flowspec_nlri.val_frag", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_fflag_lf,
{ "Last fragment", "bgp.flowspec_nlri.val_frag_lf", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_FG_LF, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_fflag_ff,
{ "First fragment", "bgp.flowspec_nlri.val_frag_ff", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_FG_FF, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_fflag_isf,
{ "Is a fragment", "bgp.flowspec_nlri.val_frag_isf", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_FG_ISF, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_fflag_df,
{ "Don't fragment", "bgp.flowspec_nlri.val_frag_df", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGPNLRI_FSPEC_FG_DF, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_dscp,
{ "Differentiated Services Codepoint", "bgp.flowspec_nlri.val_dsfield", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&dscp_vals_ext, BGPNLRI_FSPEC_DSCP_BITMASK, NULL, HFILL }},
{ &hf_bgp_flowspec_nlri_src_ipv6_pref,
{ "Source IPv6 prefix", "bgp.flowspec_nlri.src_ipv6_pref", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_flowspec_nlri_dst_ipv6_pref,
{ "Destination IPv6 prefix", "bgp.flowspec_nlri.dst_ipv6_pref", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_flowspec_nlri_ipv6_pref_len,
{ "IPv6 prefix length", "bgp.flowspec_nlri.ipv6_pref_length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_flowspec_nlri_ipv6_pref_offset,
{ "IPv6 prefix offset", "bgp.flowspec_nlri.ipv6_pref_offset", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mdt_nlri_safi_rd,
{ "Route Distinguisher", "bgp.mdt_safi_rd", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mdt_nlri_safi_ipv4_addr,
{ "IPv4 Address", "bgp.mdt_safi_ipv4_addr", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mdt_nlri_safi_group_addr,
{ "Group Address", "bgp.mdt_safi_group_addr", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ext_communities,
{ "Carried extended communities", "bgp.ext_communities", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ext_community,
{ "Community", "bgp.ext_community", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ext_com_type_high,
{ "Community type high", "bgp.ext_com.type_high", FT_UINT8, BASE_HEX,
VALS(bgpext_com_type_high), 0x0, "Type high unknown", HFILL }},
{ &hf_bgp_ext_com_stype_low_unknown,
{ "Community subtype low: unknown", "bgp.ext_com.type_low", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ext_com_stype_tr_evpn,
{ "Subtype evpn", "bgp.ext_com.stype_tr_evpn", FT_UINT8, BASE_HEX,
VALS(bgpext_com_stype_tr_evpn), 0x0, "Subtype unknown", HFILL}},
{ &hf_bgp_ext_com_stype_tr_as2,
{ "Subtype as2", "bgp.ext_com.stype_tr_as2", FT_UINT8, BASE_HEX,
VALS(bgpext_com_stype_tr_as2), 0x0, "Subtype unknown", HFILL}},
{ &hf_bgp_ext_com_stype_ntr_as2,
{ "Subtype non-transitive as2", "bgp.ext_com.stype_ntr_as2", FT_UINT8, BASE_HEX,
VALS(bgpext_com_stype_ntr_as2), 0x0, "Subtype unknown", HFILL}},
{ &hf_bgp_ext_com_stype_tr_as4,
{ "Subtype as4", "bgp.ext_com.stype_tr_as4", FT_UINT8, BASE_HEX,
VALS(bgpext_com_stype_tr_as4), 0x0, "Subtype unknown", HFILL}},
{ &hf_bgp_ext_com_stype_ntr_as4,
{ "Subtype non-transitive as4", "bgp.ext_com.stype_ntr_as4", FT_UINT8, BASE_HEX,
VALS(bgpext_com_stype_ntr_as4), 0x0, "Subtype unknown", HFILL}},
{ &hf_bgp_ext_com_stype_tr_IP4,
{ "Subtype IPv4", "bgp.ext_com.stype_tr_IP4", FT_UINT8, BASE_HEX,
VALS(bgpext_com_stype_tr_IP4), 0x0, "Subtype unknown", HFILL}},
{ &hf_bgp_ext_com_stype_tr_opaque,
{ "Subtype opaque", "bgp.ext_com.stype_tr_opaque", FT_UINT8, BASE_HEX,
VALS(bgpext_com_stype_tr_opaque), 0x0, "Subtype unknown", HFILL}},
{ &hf_bgp_ext_com_stype_ntr_opaque,
{ "Subtype opaque", "bgp.ext_com.stype_ntr_opaque", FT_UINT8, BASE_HEX,
VALS(bgpext_com_stype_ntr_opaque), 0x0, "Subtype unknown", HFILL}},
{ &hf_bgp_ext_com_tunnel_type,
{ "Tunnel types", "bgp.ext_com.tunnel_type", FT_UINT16, BASE_DEC,
VALS(bgpext_com_tunnel_type), 0x0, "Type unknown", HFILL}},
{ &hf_bgp_ext_com_stype_tr_exp,
{ "Subtype Experimental", "bgp.ext_com.stype_tr_exp", FT_UINT8, BASE_HEX,
VALS(bgpext_com_stype_tr_exp), 0x0, "Subtype unknown", HFILL}},
{ &hf_bgp_ext_com_stype_tr_exp_fs_ip4,
{ "Subtype Experimental Flow spec", "bgp.ext_com.stype_tr_exp_fs_ip4", FT_UINT8, BASE_HEX,
VALS(bgpext_com_stype_tr_exp_fs_ip4), 0x0, "Subtype unknown", HFILL}},
{ &hf_bgp_ext_com_stype_tr_exp_fs_as4,
{ "Subtype Experimental Flow spec", "bgp.ext_com.stype_tr_exp_fs_as4", FT_UINT8, BASE_HEX,
VALS(bgpext_com_stype_tr_exp_fs_as4), 0x0, "Subtype unknown", HFILL}},
{ &hf_bgp_ext_com_value_as2,
{ "Two octets AS specific", "bgp.ext_com.value_as2", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ext_com_value_as4,
{ "Four octets AS specific", "bgp.ext_com.value_as4", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ext_com_value_IP4,
{ "IPv4 address specific", "bgp.ext_com.value_IP4", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ext_com_value_an2,
{ "Two octets AN specific", "bgp.ext_com.value_an2", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ext_com_value_an4,
{ "Four octets AN specific", "bgp.ext_com.value_an4", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ext_com_value_link_bw,
{ "Link bandwidth", "bgp.ext_com.value_link_bw", FT_FLOAT, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ext_com_value_ospf_rtype,
{ "OSPF route type", "bgp.ext_com.value_ospf_rtype", FT_UINT8, BASE_DEC,
VALS(bgpext_com_ospf_rtype), 0x0, "OSPF route type unknown", HFILL}},
{ &hf_bgp_ext_com_value_ospf_rtype_option,
{ "OSPF route option", "bgp.ext_com.value_ospf_rtype_option", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGP_OSPF_RTYPE_METRIC_TYPE, NULL, HFILL }},
{ &hf_bgp_ext_com_value_fs_remark,
{ "Remarking value", "bgp.ext_com.value_fs_dscp", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&dscp_vals_ext, BGPNLRI_FSPEC_DSCP_BITMASK, NULL, HFILL }},
{ &hf_bgp_ext_com_value_unknown16,
{ "Two octets Value specific", "bgp.ext_com.value_2octets", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ext_com_value_unknown32,
{ "Four octets Value specific", "bgp.ext_com.value_4octets", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ext_com_flow_act_samp_act,
{ "Sample", "bgp.ext_com_flow.sample", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGP_EXT_COM_FSPEC_ACT_S, NULL, HFILL }},
{ &hf_bgp_ext_com_flow_act_term_act,
{ "Terminal action", "bgp.ext_com_flow.traff_act", FT_BOOLEAN, 8,
TFS(&tfs_set_notset),BGP_EXT_COM_FSPEC_ACT_T,NULL, HFILL}},
{ &hf_bgp_ext_com_flow_rate_float,
{ "Rate shaper", "bgp.ext_com_flow.rate_limit", FT_FLOAT, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ext_com_flow_act_allset,
{ "5 Bytes", "bgp.flowspec_ext_com.emptybytes", FT_BYTES, BASE_NONE,
NULL, 0x0, "Must be set to all 0", HFILL }},
{ &hf_bgp_ext_com_qos_flags,
{ "Flags", "bgp.ext_com_qos.flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_flags_remarking,
{ "Remarking", "bgp.ext_com_qos.flags.remarking", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), 0x10, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_flags_ignore_remarking,
{ "Ignore remarking", "bgp.ext_com_qos.flags.ignore_remarking", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), 0x08, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_flags_agg_marking,
{ "Aggegation of markins", "bgp.ext_com_qos.flags.agg_marking", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), 0x04, NULL, HFILL}},
{ &hf_bgp_ext_com_cos_flags,
{ "Flags byte", "bgp.ext_com_cos.flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_bgp_ext_com_cos_flags_be,
{ "BE class", "bgp.ext_com_cos.flags.be", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x80, NULL, HFILL}},
{ &hf_bgp_ext_com_cos_flags_ef,
{ "EF class", "bgp.ext_com_cos.flags.ef", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x40, NULL, HFILL}},
{ &hf_bgp_ext_com_cos_flags_af,
{ "AF class", "bgp.ext_com_cos.flags.af", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x20, NULL, HFILL}},
{ &hf_bgp_ext_com_cos_flags_le,
{ "LE class", "bgp.ext_com_cos.flags.le", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x10, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_set_number,
{ "QoS Set Number", "bgp.ext_com_qos.set_number", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_tech_type,
{ "Technology Type", "bgp.ext_com_qos.tech_type", FT_UINT8, BASE_HEX,
VALS(qos_tech_type), 0, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_marking_o,
{ "QoS Marking O", "bgp.ext_com_qos.marking_o", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_marking_a,
{ "QoS Marking A", "bgp.ext_com_qos.marking_a", FT_UINT8, BASE_HEX_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_default_to_zero,
{ "Defaults to zero", "bgp.ext_com_qos.default_to_zero", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_bgp_ext_com_l2_encaps,
{ "Encaps Type", "bgp.ext_com_l2.encaps_type", FT_UINT8, BASE_DEC,
VALS(bgp_l2vpn_encaps), 0, NULL, HFILL}},
{ &hf_bgp_ext_com_l2_c_flags,
{ "Control Flags", "bgp.ext_com_l2.c_flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ext_com_l2_flag_d,
{ "Down flag", "bgp.ext_com_l2.flag_d",FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGP_EXT_COM_L2_FLAG_D, NULL, HFILL }},
{ &hf_bgp_ext_com_l2_flag_z1,
{ "Unassigned", "bgp.ext_com_l2.flag_z1",FT_UINT8, BASE_DEC,
NULL, BGP_EXT_COM_L2_FLAG_Z1, "Must be Zero", HFILL }},
{ &hf_bgp_ext_com_l2_flag_f,
{ "Flush flag", "bgp.ext_com_l2.flag_f",FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGP_EXT_COM_L2_FLAG_F, NULL, HFILL }},
{ &hf_bgp_ext_com_l2_flag_z345,
{ "Unassigned", "bgp.ext_com_l2.flag_z345",FT_UINT8, BASE_DEC,
NULL, BGP_EXT_COM_L2_FLAG_Z345, "Must be Zero", HFILL }},
{ &hf_bgp_ext_com_l2_flag_c,
{ "C flag", "bgp.ext_com_l2.flag_c",FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGP_EXT_COM_L2_FLAG_C, NULL, HFILL }},
{ &hf_bgp_ext_com_l2_flag_s,
{ "S flag", "bgp.ext_com_l2.flag_s",FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BGP_EXT_COM_L2_FLAG_S, NULL, HFILL }},
{ &hf_bgp_ext_com_l2_mtu,
{ "Layer-2 MTU", "bgp.ext_com_l2.l2_mtu", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ext_com_l2_esi_label_flag,
{ "Single active bit", "bgp.ext_com_l2.esi_label_flag",FT_BOOLEAN, 8,
TFS(&tfs_esi_label_flag), BGP_EXT_COM_ESI_LABEL_FLAGS, NULL, HFILL }},
{ &hf_bgp_ls_type,
{ "Type", "bgp.ls.type", FT_UINT16, BASE_DEC,
NULL, 0x0, "BGP-LS message type", HFILL }},
{ &hf_bgp_ls_length,
{ "Length", "bgp.ls.length", FT_UINT16, BASE_DEC,
NULL, 0x0, "The total length of the message payload in octets", HFILL }},
{ &hf_bgp_ls_safi72_nlri,
{ "Link State SAFI 72 NLRI", "bgp.ls.nlri_safi72", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_safi128_nlri,
{ "Link State SAFI 128 NLRI", "bgp.ls.nlri_safi128", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_safi128_nlri_route_distinguisher,
{ "Route Distinguisher", "bgp.ls.nlri_safi128_route_distinguisher", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_safi128_nlri_route_distinguisher_type,
{ "Route Distinguisher Type", "bgp.ls.nlri_safi128_route_distinguisher_type", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_safi128_nlri_route_dist_admin_asnum_2,
{ "Administrator Subfield", "bgp.ls.nlri_safi128_route_distinguisher_admin_as_num_2", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_safi128_nlri_route_dist_admin_ipv4,
{ "Administrator Subfield", "bgp.ls.nlri_safi128_route_distinguisher_admin_ipv4", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_safi128_nlri_route_dist_admin_asnum_4,
{ "Administrator Subfield", "bgp.ls.nlri_safi128_route_distinguisher_admin_as_num_4", FT_UINT32,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_safi128_nlri_route_dist_asnum_2,
{ "Assigned Number Subfield", "bgp.ls.nlri_safi128_route_distinguisher_asnum_2", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_safi128_nlri_route_dist_asnum_4,
{ "Assigned Number Subfield", "bgp.ls.nlri_safi128_route_distinguisher_asnum_4", FT_UINT32,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_type,
{ "NLRI Type", "bgp.ls.nlri_type", FT_UINT16,
BASE_DEC, VALS(bgp_ls_nlri_type_vals), 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_length,
{ "NLRI Length", "bgp.ls.nlri_length", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_link_nlri_type,
{ "Link-State NLRI Link NLRI", "bgp.ls.nlri_link", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_link_descriptors_tlv,
{ "Link Descriptors TLV", "bgp.ls.nlri_link_descriptors_tlv", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_prefix_descriptors_tlv,
{ "Prefix Descriptors TLV", "bgp.ls.nlri_prefix_descriptors_tlv", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_link_local_identifier,
{ "Link Local Identifier", "bgp.ls.nlri_link_local_identifier", FT_UINT32,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_link_remote_identifier,
{ "Link Remote Identifier", "bgp.ls.nlri_link_remote_identifier", FT_UINT32,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_ipv4_interface_address,
{ "IPv4 Interface Address", "bgp.ls.nlri_ipv4_interface_address", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_ipv4_neighbor_address,
{ "IPv4 Neighbor Address", "bgp.ls.nlri_ipv4_neighbor_address", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_ipv6_interface_address,
{ "IPv6 Interface Address", "bgp.ls.nlri_ipv6_interface_address", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_ipv6_neighbor_address,
{ "IPv6 Neighbor Address", "bgp.ls.nlri_ipv6_neighbor_address", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_multi_topology_id,
{ "Multi Topology ID", "bgp.ls.nlri_multi_topology_id", FT_UINT16,
BASE_DEC_HEX, NULL, 0xfff, NULL, HFILL}},
{ &hf_bgp_ls_nlri_ospf_route_type,
{ "OSPF Route Type", "bgp.ls.nlri_ospf_route_type", FT_UINT8,
BASE_DEC, VALS(link_state_prefix_descriptors_ospf_route_type), 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_ip_reachability_prefix_ip,
{ "Reachability prefix", "bgp.ls.nlri_ip_reachability_prefix_ip", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_node_nlri_type,
{ "Link-State NLRI Node NLRI", "bgp.ls.nlri_node", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_nlri_node_protocol_id,
{ "Protocol ID", "bgp.ls.nlri_node.protocol_id", FT_UINT8,
BASE_DEC, VALS(link_state_nlri_protocol_id_values), 0x0, NULL, HFILL }},
{ &hf_bgp_ls_nlri_node_identifier,
{ "Identifier", "bgp.ls.nlri_node.identifier", FT_UINT64,
BASE_DEC | BASE_VAL64_STRING, VALS64(link_state_nlri_routing_universe_values), 0x0, NULL, HFILL }},
{ &hf_bgp_ls_ipv4_topology_prefix_nlri_type,
{ "Link-State NLRI IPv4 Topology Prefix", "bgp.ls.ipv4_topology_prefix", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_ipv6_topology_prefix_nlri_type,
{ "Link-State NLRI IPv6 Topology Prefix", "bgp.ls.ipv6_topology_prefix", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_local_node_descriptors,
{ "Local Node Descriptors TLV", "bgp.ls.tlv.local_node_descriptors", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_remote_node_descriptors,
{ "Remote Node Descriptors TLV", "bgp.ls.tlv.remote_node_descriptors", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_autonomous_system,
{ "Autonomous System TLV", "bgp.ls.tlv.autonomous_system", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_autonomous_system_id,
{ "AS ID", "bgp.ls.tlv.autonomous_system.id", FT_UINT32,
BASE_DEC_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_bgp_ls_identifier,
{ "BGP-LS Identifier TLV", "bgp.ls.tlv.bgp_ls_identifier", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_bgp_ls_identifier_id,
{ "BGP-LS ID", "bgp.ls.tlv.bgp_ls_identifier_id", FT_UINT32,
BASE_DEC_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_area_id,
{ "Area ID TLV", "bgp.ls.tlv.area_id", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_area_id_id,
{ "Area ID", "bgp.ls.tlv.area_id.id", FT_UINT32,
BASE_DEC_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_ipv4_router_id_of_local_node,
{ "IPv4 Router-ID of Local Node TLV", "bgp.ls.tlv.ipv4_router_id_of_local_node", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ls_tlv_ipv4_router_id_value,
{ "IPv4 Router-ID", "bgp.ls.tlv.ipv4_router_id_value", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_ipv6_router_id_of_local_node,
{ "IPv6 Router-ID of Local Node TLV", "bgp.ls.tlv.ipv6_router_id_of_local_node", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ls_tlv_ipv6_router_id_value,
{ "IPv6 Router-ID", "bgp.ls.tlv.ipv6_router_id_of_local_node_value", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ls_tlv_ipv4_router_id_of_remote_node,
{ "IPv4 Router-ID of Remote Node TLV", "bgp.ls.tlv.ipv4_router_id_of_remote_node", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ls_tlv_ipv6_router_id_of_remote_node,
{ "IPv6 Router-ID of Remote Node TLV", "bgp.ls.tlv.ipv6_router_id_of_remote_node", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ls_tlv_link_local_remote_identifiers,
{ "Link Local/Remote Identifiers TLV", "bgp.ls.tlv.link_local_remote_identifiers", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ls_tlv_ipv4_interface_address,
{ "IPv4 interface address TLV", "bgp.ls.tlv.ipv4_interface_address", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ls_tlv_ipv4_neighbor_address,
{ "IPv4 neighbor address TLV", "bgp.ls.tlv.ipv4_neighbor_address", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_ipv6_interface_address,
{ "IPv6 interface address TLV", "bgp.ls.tlv.ipv6_interface_address", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_ipv6_neighbor_address,
{ "IPv6 neighbor address TLV", "bgp.ls.tlv.ipv6_neighbor_address", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_multi_topology_id,
{ "Multi Topology ID TLV", "bgp.ls.tlv.multi_topology_id", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_ospf_route_type,
{ "OSPF Route Type TLV", "bgp.ls.tlv.ospf_route_type", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_ip_reachability_information,
{ "IP Reachability Information TLV", "bgp.ls.tlv.ip_reachability_information", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_administrative_group_color,
{ "Administrative group (color) TLV", "bgp.ls.tlv.administrative_group_color", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_administrative_group_color_value,
{ "Group Mask", "bgp.ls.tlv.administrative_group_color_value", FT_UINT32,
BASE_DEC, NULL, 0xffff, NULL, HFILL}},
{ &hf_bgp_ls_tlv_administrative_group,
{ "Group", "bgp.ls.tlv.administrative_group", FT_UINT32,
BASE_DEC, NULL, 0xffff, NULL, HFILL}},
{ &hf_bgp_ls_tlv_max_link_bandwidth,
{ "Maximum link bandwidth TLV", "bgp.ls.tlv.maximum_link_bandwidth", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_max_reservable_link_bandwidth,
{ "Maximum reservable link bandwidth TLV", "bgp.ls.tlv.maximum_reservable_link_bandwidth", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_unreserved_bandwidth,
{ "Unreserved bandwidth TLV", "bgp.ls.tlv.unreserved_bandwidth", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_bandwidth_value,
{"Bandwidth", "bgp.ls.bandwidth_value", FT_FLOAT,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_te_default_metric,
{ "TE Default Metric TLV", "bgp.ls.tlv.te_default_metric", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_te_default_metric_value_old,
{ "TE Default Metric (old format)", "bgp.ls.tlv.te_default_metric_value", FT_UINT24,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ls_tlv_te_default_metric_value,
{ "TE Default Metric", "bgp.ls.tlv.te_default_metric_value", FT_UINT32,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_ls_tlv_link_protection_type,
{ "Link Protection Type TLV", "bgp.ls.tlv.link_protection_type", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_link_protection_type_value,
{ "Protection Capabilities", "bgp.ls.tlv.link_protection_type_value", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_mpls_protocol_mask,
{ "MPLS Protocol Mask TLV", "bgp.ls.tlv.mpls_protocol_mask", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_metric,
{ "Metric TLV", "bgp.ls.tlv.metric", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_metric_value1,
{ "IGP Metric", "bgp.ls.tlv.metric_value", FT_UINT8,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_metric_value2,
{ "IGP Metric", "bgp.ls.tlv.metric_value", FT_UINT16,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_metric_value3,
{ "IGP Metric", "bgp.ls.tlv.metric_value", FT_UINT24,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_shared_risk_link_group,
{ "Shared Risk Link Group TLV", "bgp.ls.tlv.shared_risk_link_group", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_shared_risk_link_group_value,
{ "Shared Risk Link Group Value", "bgp.ls.tlv.shared_risk_link_group_value", FT_UINT32,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_opaque_link_attribute,
{ "Opaque Link Attribute TLV", "bgp.ls.tlv.opaque_link_attribute", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_opaque_link_attribute_value,
{ "Opaque link attributes", "bgp.ls.tlv.opaque_link_attribute_value", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_link_name_attribute,
{ "Opaque Link Attribute TLV", "bgp.ls.tlv.link_name_attribute", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_link_name_attribute_value,
{"Link Name", "bgp.ls.tlv.link_name_attribute_value", FT_STRING,
STR_ASCII, NULL, 0, NULL, HFILL }},
{ &hf_bgp_ls_tlv_igp_flags,
{ "IGP Flags TLV", "bgp.ls.tlv.igp_flags", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_route_tag,
{ "Route Tag TLV", "bgp.ls.tlv.route_tag", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_route_tag_value,
{ "Route Tag Value", "bgp.ls.tlv.route_tag_value", FT_UINT32,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_route_extended_tag,
{ "Extended Route Tag TLV", "bgp.ls.tlv.route_extended_tag", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_route_extended_tag_value,
{"Extended Route Tag", "bgp.ls.tlv.extended_route_tag_value", FT_UINT64,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_prefix_metric,
{ "Prefix Metric TLV", "bgp.ls.tlv.prefix_metric", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_prefix_metric_value,
{ "Prefix Metric", "bgp.ls.tlv.prefix_metric_value", FT_UINT32,
BASE_HEX_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_ospf_forwarding_address,
{ "OSPF Forwarding Address TLV", "bgp.ls.tlv.ospf_forwarding_address", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_ospf_forwarding_address_ipv4_address,
{ "OSPF forwarding IPv4 address", "bgp.ls.tlv.ospf_forwarding_address_ipv4", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_ospf_forwarding_address_ipv6_address,
{ "OSPF forwarding IPv6 address", "bgp.ls.tlv.ospf_forwarding_address_ipv6", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_opaque_prefix_attribute,
{ "Opaque Prefix Attribute TLV", "bgp.ls.tlv.opaque_prefix_attribute", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_opaque_prefix_attribute_value,
{ "Opaque prefix attributes", "bgp.ls.tlv.opaque_prefix_attribute_value", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_igp_router,
{ "IGP Router-ID", "bgp.ls.tlv.igp_router", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_igp_router_id,
{ "IGP ID", "bgp.ls.tlv.igp_router_id", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_node_flags_bits,
{ "Node Flags Bits TLV", "bgp.ls.tlv.node_flags_bits", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_opaque_node_properties,
{ "Opaque Node Properties TLV", "bgp.ls.tlv.opaque_node_properties", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_opaque_node_properties_value,
{ "Opaque Node Properties", "bgp.ls.tlv.opaque_node_properties_value", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_node_name,
{ "Node Name TLV", "bgp.ls.tlv.node_name", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_node_name_value,
{"Node name", "bgp.ls.tlv.node_name_value", FT_STRING,
STR_ASCII, NULL, 0, NULL, HFILL }},
{ &hf_bgp_ls_tlv_is_is_area_identifier,
{ "IS-IS Area Identifier TLV", "bgp.ls.tlv.is_is_area_identifier", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_tlv_is_is_area_identifier_value,
{ "IS-IS Area Identifier", "bgp.ls.tlv.is_is_area_identifier_value", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_link_protection_type_enhanced,
{ "Enhanced", "bgp.ls.link_protection_type.enhanced", FT_BOOLEAN, 8,
TFS(&tfs_capable_not_capable), 0x20, NULL, HFILL }},
{ &hf_bgp_ls_link_protection_type_dedicated_1plus1,
{ "Dedicated 1+1", "bgp.ls.link_protection_type.dedicated_1plus1", FT_BOOLEAN, 8,
TFS(&tfs_capable_not_capable), 0x10, NULL, HFILL }},
{ &hf_bgp_ls_link_protection_type_dedicated_1to1,
{ "Dedicated 1:1", "bgp.ls.link_protection_type.dedicated_1colon1", FT_BOOLEAN, 8,
TFS(&tfs_capable_not_capable), 0x08, NULL, HFILL }},
{ &hf_bgp_ls_link_protection_type_shared,
{ "Shared", "bgp.ls.link_protection_type.shared", FT_BOOLEAN, 8,
TFS(&tfs_capable_not_capable), 0x04, NULL, HFILL }},
{ &hf_bgp_ls_link_protection_type_unprotected,
{ "Unprotected", "bgp.ls.link_protection_type.unprotected", FT_BOOLEAN, 8,
TFS(&tfs_capable_not_capable), 0x02, NULL, HFILL }},
{ &hf_bgp_ls_link_protection_type_extra_traffic,
{ "Extra Traffic", "bgp.ls.link_protection_type.extra_traffic", FT_BOOLEAN, 8,
TFS(&tfs_capable_not_capable), 0x01, NULL, HFILL }},
{ &hf_bgp_ls_mpls_protocol_mask_flag_l,
{ "Label Distribution Protocol (LDP)", "bgp.ls.protocol_mask_tlv.mpls_protocol.l", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL}},
{ &hf_bgp_ls_mpls_protocol_mask_flag_r,
{ "Extension to RSVP for LSP Tunnels (RSVP-TE)", "bgp.ls.protocol_mask_tlv.mpls_protocol.r", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL}},
{ &hf_bgp_ls_igp_flags_flag_d,
{ "IS-IS Up/Down Bit", "bgp.ls.protocol_mask_tlv.igp_flags_flag_d.d", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL}},
{ &hf_bgp_ls_node_flag_bits_overload,
{ "Overload Bit", "bgp.ls.node_flag_bits.overload", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL}},
{ &hf_bgp_ls_node_flag_bits_attached,
{ "Attached Bit", "bgp.ls.node_flag_bits.attached", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL}},
{ &hf_bgp_ls_node_flag_bits_external,
{ "External Bit", "bgp.ls.node_flag_bits.external", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL}},
{ &hf_bgp_ls_node_flag_bits_abr,
{ "ABR Bit", "bgp.ls.node_flag_bits.abr", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL}},
{ &hf_bgp_evpn_nlri,
{ "EVPN NLRI", "bgp.evpn.nlri", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_evpn_nlri_rt,
{ "AFI", "bgp.evpn.nlri.rt", FT_UINT8, BASE_DEC,
VALS(evpnrtypevals), 0x0, "EVPN Route Type", HFILL }},
{ &hf_bgp_evpn_nlri_len,
{ "Length", "bgp.evpn.nlri.len", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_evpn_nlri_rd,
{ "Route Distinguisher", "bgp.evpn.nlri.rd", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_evpn_nlri_esi,
{ "ESI", "bgp.evpn.nlri.esi", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_type,
{ "ESI Type", "bgp.evpn.nlri.esi.type", FT_UINT8,
BASE_DEC, VALS(evpn_nlri_esi_type), 0x0, "EVPN ESI type", HFILL }},
{ &hf_bgp_evpn_nlri_esi_lacp_mac,
{ "CE LACP system MAC", "bgp.evpn.nlri.esi.lacp_mac", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_portk,
{ "LACP port key", "bgp.evpn.nlri.esi.lacp_portkey", FT_BYTES,
SEP_SPACE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_remain,
{ "Remaining bytes", "bgp.evpn.nlri.esi.remaining", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_reserved,
{ "Reserved value all 0xff", "bgp.evpn.nlri.esi.reserved", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_value,
{ "ESI 9 bytes value", "bgp.evpn.nlri.esi.arbitrary_bytes", FT_BYTES,
SEP_SPACE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_rb_mac,
{ "ESI root bridge MAC", "bgp.evpn.nlri.esi.root_brige", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_rbprio,
{ "ESI root bridge priority", "bgp.evpn.nlri.esi.rb_prio", FT_BYTES,
SEP_SPACE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_sys_mac,
{ "ESI system MAC", "bgp.evpn.nlri.esi.system_mac", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_mac_discr,
{ "ESI system mac discriminator", "bgp.evpn.nlri.esi.system_mac_discr", FT_BYTES,
SEP_SPACE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_router_id,
{ "ESI router ID", "bgp.evpn.nlri.esi.router_id", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_router_discr,
{ "ESI router discriminator", "bgp.evpn.nlri.esi.router_discr", FT_BYTES,
SEP_SPACE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_asn,
{ "ESI ASN", "bgp.evpn.nlri.esi.asn", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_esi_asn_discr,
{ "ESI ASN discriminator", "bgp.evpn.nlri.esi.asn_discr", FT_BYTES,
SEP_SPACE, NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_evpn_nlri_etag,
{ "Ethernet Tag ID", "bgp.evpn.nlri.etag", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_evpn_nlri_mpls_ls,
{ "MPLS Label Stack", "bgp.evpn.nlri.mpls_ls", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_evpn_nlri_maclen,
{ "MAC Address Length", "bgp.evpn.nlri.maclen", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_evpn_nlri_mac_addr,
{ "MAC Address", "bgp.evpn.nlri.mac_addr", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_evpn_nlri_iplen,
{ "IP Address Length", "bgp.evpn.nlri.iplen", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_evpn_nlri_prefix_len,
{ "IP prefix length", "bgp.evpn.nlri.prefix_len", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_evpn_nlri_ip_addr,
{ "IPv4 address", "bgp.evpn.nlri.ip.addr", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_evpn_nlri_ipv6_addr,
{ "IPv6 address", "bgp.evpn.nlri.ipv6.addr", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_evpn_nlri_ipv4_gtw,
{ "IPv4 Gateway address", "bgp.evpn.nlri.ipv4.gtw_addr", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_evpn_nlri_ipv6_gtw,
{ "IPv6 Gateway address", "bgp.evpn.nlri.ipv6.gtw_addr", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_capabilities,
{ "SR Capabilities", "bgp.ls.sr.tlv.capabilities", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_capabilities_flags,
{ "Flags", "bgp.ls.sr.tlv.capabilities.flags", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_capabilities_flags_i,
{ "MPLS IPv4 flag (I)", "bgp.ls.sr.tlv.capabilities.flags.i", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_CAPABILITY_FLAG_I, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_capabilities_flags_v,
{ "MPLS IPv6 flag (V)", "bgp.ls.sr.tlv.capabilities.flags.v", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_CAPABILITY_FLAG_V, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_capabilities_flags_h,
{ "SR-IPv6 flag (H)", "bgp.ls.sr.tlv.capabilities.flags.h", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_CAPABILITY_FLAG_H, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_capabilities_flags_reserved,
{ "Reserved", "bgp.ls.sr.tlv.capabilities.flags.reserved", FT_UINT8,
BASE_HEX, NULL, 0x1F, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_capabilities_range_size,
{ "Range Size", "bgp.ls.sr.tlv.capabilities.range_size", FT_UINT24,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_capabilities_sid_label,
{ "From Label", "bgp.ls.sr.tlv.capabilities.sid.label", FT_UINT24,
BASE_DEC, NULL, 0x0FFFFF, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_capabilities_sid_index,
{ "From Index", "bgp.ls.sr.tlv.capabilities.sid.index", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_algorithm,
{ "SR Algorithm", "bgp.ls.sr.tlv.algorithm", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_algorithm_value,
{ "SR Algorithm", "bgp.ls.sr.tlv.algorithm.value", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid,
{ "Prefix SID TLV", "bgp.ls.sr.tlv.prefix.sid", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid_flags,
{ "Flags", "bgp.ls.sr.tlv.prefix.sid.flags", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid_flags_r,
{ "Re-advertisement (R)", "bgp.ls.sr.tlv.prefix.sid.flags.r", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_PREFIX_SID_FLAG_R, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid_flags_n,
{ "Node-SID (N)", "bgp.ls.sr.tlv.prefix.sid.flags.n", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_PREFIX_SID_FLAG_N, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid_flags_np,
{ "No-PHP (NP)", "bgp.ls.sr.tlv.prefix.sid.flags.np", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_PREFIX_SID_FLAG_NP, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid_flags_p,
{ "No-PHP (P)", "bgp.ls.sr.tlv.prefix.sid.flags.p", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_PREFIX_SID_FLAG_P, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid_flags_m,
{ "Mapping Server Flag (M)", "bgp.ls.sr.tlv.prefix.sid.flags.m", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_PREFIX_SID_FLAG_M, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid_flags_e,
{ "Explicit-Null (E)", "bgp.ls.sr.tlv.prefix.sid.flags.e", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_PREFIX_SID_FLAG_E, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid_flags_v,
{ "Value (V)", "bgp.ls.sr.tlv.prefix.sid.flags.v", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_PREFIX_SID_FLAG_V, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid_flags_l,
{ "Local (L)", "bgp.ls.sr.tlv.prefix.sid.flags.l", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_PREFIX_SID_FLAG_L, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid_algo,
{ "Algorithm", "bgp.ls.sr.tlv.prefix.sid.algo", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid_label,
{ "SID/Label", "bgp.ls.sr.tlv.prefix.sid.label", FT_UINT24,
BASE_DEC, NULL, 0x0FFFFF, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_prefix_sid_index,
{ "SID/Index", "bgp.ls.sr.tlv.prefix.sid.index", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid,
{ "Adjacency SID TLV", "bgp.ls.sr.tlv.adjacency.sid", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_flags,
{ "Flags", "bgp.ls.sr.tlv.adjacency.sid.flags", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_flags_fi,
{ "Address-Family flag (F)", "bgp.ls.sr.tlv.adjacency.sid.flags.f", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_ADJACENCY_SID_FLAG_FI, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_flags_bo,
{ "Backup Flag (B)", "bgp.ls.sr.tlv.adjacency.sid.flags.b", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_ADJACENCY_SID_FLAG_BO, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_flags_bi,
{ "Backup Flag (B)", "bgp.ls.sr.tlv.adjacency.sid.flags.b", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_ADJACENCY_SID_FLAG_BI, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_flags_vo,
{ "Value Flag (V)", "bgp.ls.sr.tlv.adjacency.sid.flags.v", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_ADJACENCY_SID_FLAG_VO, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_flags_vi,
{ "Value Flag (V)", "bgp.ls.sr.tlv.adjacency.sid.flags.v", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_ADJACENCY_SID_FLAG_VI, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_flags_lo,
{ "Local Flag (L)", "bgp.ls.sr.tlv.adjacency.sid.flags.l", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_ADJACENCY_SID_FLAG_LO, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_flags_li,
{ "Local Flag (L)", "bgp.ls.sr.tlv.adjacency.sid.flags.l", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_ADJACENCY_SID_FLAG_LI, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_flags_so,
{ "Set Flag (S)", "bgp.ls.sr.tlv.adjacency.sid.flags.s", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_ADJACENCY_SID_FLAG_SO, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_flags_si,
{ "Set Flag (S)", "bgp.ls.sr.tlv.adjacency.sid.flags.s", FT_BOOLEAN,
8, TFS(&tfs_set_notset), BGP_LS_SR_ADJACENCY_SID_FLAG_SI, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_weight,
{ "Weight", "bgp.ls.sr.tlv.adjacency.sid.weight", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_label,
{ "SID/Label", "bgp.ls.sr.tlv.adjacency.sid.label", FT_UINT24,
BASE_DEC, NULL, 0x0FFFFF, NULL, HFILL}},
{ &hf_bgp_ls_sr_tlv_adjacency_sid_index,
{ "SID/Index", "bgp.ls.sr.tlv.adjacency.sid.index", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}}
};
static gint *ett[] = {
&ett_bgp,
&ett_bgp_prefix,
&ett_bgp_unfeas,
&ett_bgp_attrs,
&ett_bgp_attr,
&ett_bgp_attr_flags,
&ett_bgp_mp_nhna,
&ett_bgp_mp_reach_nlri,
&ett_bgp_mp_unreach_nlri,
&ett_bgp_mp_snpa,
&ett_bgp_nlri,
&ett_bgp_open,
&ett_bgp_update,
&ett_bgp_notification,
&ett_bgp_route_refresh,
&ett_bgp_capability,
&ett_bgp_as_path_segment,
&ett_bgp_as_path_segment_asn,
&ett_bgp_communities,
&ett_bgp_community,
&ett_bgp_cluster_list,
&ett_bgp_options,
&ett_bgp_option,
&ett_bgp_cap,
&ett_bgp_extended_communities,
&ett_bgp_extended_community,
&ett_bgp_extended_com_fspec_redir,
&ett_bgp_ext_com_flags,
&ett_bgp_ext_com_l2_flags,
&ett_bgp_ssa,
&ett_bgp_ssa_subtree,
&ett_bgp_orf,
&ett_bgp_orf_entry,
&ett_bgp_mcast_vpn_nlri,
&ett_bgp_flow_spec_nlri,
&ett_bgp_flow_spec_nlri_filter,
&ett_bgp_flow_spec_nlri_op_flags,
&ett_bgp_flow_spec_nlri_tcp,
&ett_bgp_flow_spec_nlri_ff,
&ett_bgp_tunnel_tlv,
&ett_bgp_tunnel_tlv_subtree,
&ett_bgp_tunnel_subtlv,
&ett_bgp_tunnel_subtlv_subtree,
&ett_bgp_link_state,
&ett_bgp_evpn_nlri,
&ett_bgp_evpn_nlri_esi,
&ett_bgp_mpls_labels,
&ett_bgp_pmsi_tunnel_id,
&ett_bgp_aigp_attr,
};
static ei_register_info ei[] = {
{ &ei_bgp_cap_len_bad, { "bgp.cap.length.bad", PI_MALFORMED, PI_ERROR, "Capability length is wrong", EXPFILL }},
{ &ei_bgp_cap_gr_helper_mode_only, { "bgp.cap.gr.helper_mode_only", PI_REQUEST_CODE, PI_CHAT, "Graceful Restart Capability supported in Helper mode only", EXPFILL }},
{ &ei_bgp_notify_minor_unknown, { "bgp.notify.minor_error.unknown", PI_UNDECODED, PI_NOTE, "Unknown notification error", EXPFILL }},
{ &ei_bgp_route_refresh_orf_type_unknown, { "bgp.route_refresh.orf.type.unknown", PI_CHAT, PI_ERROR, "ORFEntry-Unknown", EXPFILL }},
{ &ei_bgp_length_invalid, { "bgp.length.invalid", PI_MALFORMED, PI_ERROR, "Length is invalid", EXPFILL }},
{ &ei_bgp_prefix_length_invalid, { "bgp.prefix_length.invalid", PI_MALFORMED, PI_ERROR, "Prefix length is invalid", EXPFILL }},
{ &ei_bgp_afi_type_not_supported, { "bgp.afi_type_not_supported", PI_PROTOCOL, PI_ERROR, "AFI Type not supported", EXPFILL }},
{ &ei_bgp_unknown_afi, { "bgp.unknown_afi", PI_PROTOCOL, PI_ERROR, "Unknown Address Family", EXPFILL }},
{ &ei_bgp_unknown_safi, { "bgp.unknown_safi", PI_PROTOCOL, PI_ERROR, "Unknown SAFI", EXPFILL }},
{ &ei_bgp_unknown_label_vpn, { "bgp.unknown_label", PI_PROTOCOL, PI_ERROR, "Unknown Label VPN", EXPFILL }},
{ &ei_bgp_ls_error, { "bgp.ls.error", PI_PROTOCOL, PI_ERROR, "Link State error", EXPFILL }},
{ &ei_bgp_ls_warn, { "bgp.ls.warn", PI_PROTOCOL, PI_WARN, "Link State warning", EXPFILL }},
{ &ei_bgp_ext_com_len_bad, { "bgp.ext_com.length.bad", PI_PROTOCOL, PI_ERROR, "Extended community length is wrong", EXPFILL }},
{ &ei_bgp_evpn_nlri_rt4_len_err, { "bgp.evpn.len", PI_MALFORMED, PI_ERROR, "Length is invalid", EXPFILL }},
{ &ei_bgp_evpn_nlri_rt_type_err, { "bgp.evpn.type", PI_MALFORMED, PI_ERROR, "EVPN Route Type is invalid", EXPFILL }},
{ &ei_bgp_evpn_nlri_esi_type_err, { "bgp.evpn.esi_type", PI_MALFORMED, PI_ERROR, "EVPN ESI Type is invalid", EXPFILL }},
{ &ei_bgp_evpn_nlri_rt4_no_ip, { "bgp.evpn.no_ip", PI_PROTOCOL, PI_NOTE, "IP Address: NOT INCLUDED", EXPFILL }},
{ &ei_bgp_attr_pmsi_tunnel_type, { "bgp.attr.pmsi.tunnel_type", PI_PROTOCOL, PI_ERROR, "Unknown Tunnel type", EXPFILL }},
{ &ei_bgp_attr_pmsi_opaque_type, { "bgp.attr.pmsi.opaque_type", PI_PROTOCOL, PI_ERROR, "Unvalid pmsi opaque type", EXPFILL }},
{ &ei_bgp_attr_aigp_type, { "bgp.attr.aigp.type", PI_MALFORMED, PI_NOTE, "Unknown AIGP attribute type", EXPFILL}},
{ &ei_bgp_prefix_length_err, { "bgp.prefix.length", PI_MALFORMED, PI_ERROR, "Unvalid IPv6 prefix length", EXPFILL}},
{ &ei_bgp_attr_as_path_as_len_err, { "bgp.attr.as_path.as_len", PI_UNDECODED, PI_ERROR, "unable to determine 4 or 2 bytes ASN", EXPFILL}}
};
module_t *bgp_module;
expert_module_t* expert_bgp;
static const enum_val_t asn_len[] = {
{"auto-detect", "Auto-detect", 0},
{"2", "2 octet", 2},
{"4", "4 octet", 4},
{NULL, NULL, -1}
};
proto_bgp = proto_register_protocol("Border Gateway Protocol",
"BGP", "bgp");
proto_register_field_array(proto_bgp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_bgp = expert_register_protocol(proto_bgp);
expert_register_field_array(expert_bgp, ei, array_length(ei));
bgp_module = prefs_register_protocol(proto_bgp, NULL);
prefs_register_bool_preference(bgp_module, "desegment",
"Reassemble BGP messages spanning multiple TCP segments",
"Whether the BGP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&bgp_desegment);
prefs_register_enum_preference(bgp_module, "asn_len",
"Length of the AS number",
"BGP dissector detect the length of the AS number in AS_PATH attributes automatically or manually (NOTE: Automatic detection is not 100% accurate)",
&bgp_asn_len, asn_len, FALSE);
bgp_handle = register_dissector("bgp", dissect_bgp, proto_bgp);
}
void
proto_reg_handoff_bgp(void)
{
dissector_add_uint("tcp.port", BGP_TCP_PORT, bgp_handle);
}
