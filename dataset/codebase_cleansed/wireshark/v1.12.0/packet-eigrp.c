static void
dissect_eigrp_parameter (proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
proto_item *ti)
{
int offset = 0;
guint8 k1, k2, k3, k4, k5;
k1 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_eigrp_par_k1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
k2 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_eigrp_par_k2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
k3 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_eigrp_par_k3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
k4 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_eigrp_par_k4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
k5 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_eigrp_par_k5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_eigrp_par_k6, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_eigrp_par_holdtime, tvb, offset, 2, ENC_BIG_ENDIAN);
if (k1 == 255 && k2 == 255 && k3 == 255 && k4 == 255 && k5 == 255) {
proto_item_append_text(ti, ": Peer Termination");
expert_add_info(pinfo, ti, &ei_eigrp_peer_termination);
}
}
static void
dissect_eigrp_auth_tlv (proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, proto_item *ti)
{
proto_item *ti_auth_type, *ti_auth_len;
int offset = 0;
guint16 auth_type, auth_len;
auth_type = tvb_get_ntohs(tvb, 0);
auth_len = tvb_get_ntohs(tvb, 2);
proto_item_append_text(ti, " %s", val_to_str_const(auth_type, eigrp_auth2string, ""));
ti_auth_type = proto_tree_add_item(tree, hf_eigrp_auth_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ti_auth_len = proto_tree_add_item(tree, hf_eigrp_auth_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_eigrp_auth_keyid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_eigrp_auth_keyseq, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_eigrp_nullpad, tvb, offset, 8, ENC_NA);
offset += 8;
switch (auth_type) {
case EIGRP_AUTH_TYPE_MD5:
if (EIGRP_AUTH_TYPE_MD5_LEN != auth_len) {
expert_add_info_format(pinfo, ti_auth_len, &ei_eigrp_auth_len, "Invalid auth len %u", auth_len);
} else {
proto_tree_add_item(tree, hf_eigrp_auth_digest, tvb, offset,
EIGRP_AUTH_TYPE_MD5_LEN, ENC_NA);
}
break;
case EIGRP_AUTH_TYPE_SHA256:
if (EIGRP_AUTH_TYPE_SHA256_LEN != auth_len) {
expert_add_info_format(pinfo, ti_auth_len, &ei_eigrp_auth_len, "Invalid auth len %u", auth_len);
} else {
proto_tree_add_item(tree, hf_eigrp_auth_digest, tvb, offset,
EIGRP_AUTH_TYPE_SHA256_LEN, ENC_NA);
}
break;
case EIGRP_AUTH_TYPE_NONE:
case EIGRP_AUTH_TYPE_TEXT:
default:
expert_add_info_format(pinfo, ti_auth_type, &ei_eigrp_auth_type, "Invalid auth type %u", auth_type);
break;
}
}
static void
dissect_eigrp_seq_tlv (proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, proto_item *ti)
{
proto_item *ti_addrlen;
int offset = 0;
guint8 addr_len;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
addr_len = tvb_get_guint8(tvb, offset);
ti_addrlen = proto_tree_add_item(tree, hf_eigrp_seq_addrlen, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (tvb_reported_length_remaining(tvb, offset) < addr_len) {
expert_add_info(pinfo, ti, &ei_eigrp_tlv_trunc);
break;
}
switch (addr_len) {
case 4:
proto_tree_add_item(tree, hf_eigrp_seq_ipv4addr, tvb, offset, addr_len, ENC_BIG_ENDIAN);
break;
case 10:
proto_tree_add_text(tree, tvb, offset, addr_len,
"IPX Address = %08x.%04x.%04x.%04x",
tvb_get_ntohl(tvb, 1), tvb_get_ntohs(tvb, 5),
tvb_get_ntohs(tvb, 7), tvb_get_ntohs(tvb, 9));
break;
case 16:
proto_tree_add_item(tree, hf_eigrp_seq_ipv6addr, tvb, offset, addr_len,
ENC_NA);
break;
default:
expert_add_info(pinfo, ti_addrlen, &ei_eigrp_seq_addrlen);
}
offset += addr_len;
}
}
static void
dissect_eigrp_sw_version (tvbuff_t *tvb, proto_tree *tree,
proto_item *ti)
{
int offset = 0;
guint8 ios_rel_major, ios_rel_minor;
guint8 eigrp_rel_major, eigrp_rel_minor;
ios_rel_major = tvb_get_guint8(tvb, 0);
ios_rel_minor = tvb_get_guint8(tvb, 1);
proto_tree_add_text(tree, tvb, offset, 2, "EIGRP Release: %u.%u",
ios_rel_major, ios_rel_minor);
offset += 2;
proto_item_append_text(ti, ": EIGRP=%u.%u", ios_rel_major, ios_rel_minor);
eigrp_rel_major = tvb_get_guint8(tvb, 2);
eigrp_rel_minor = tvb_get_guint8(tvb, 3);
proto_tree_add_text(tree,tvb,offset, 2, "EIGRP TLV version: %u.%u",
eigrp_rel_major, eigrp_rel_minor);
proto_item_append_text(ti, ", TLV=%u.%u",
eigrp_rel_major, eigrp_rel_minor);
}
static void
dissect_eigrp_next_mcast_seq (tvbuff_t *tvb, proto_tree *tree,
proto_item *ti)
{
proto_tree_add_item(tree, hf_eigrp_next_mcast_seq, tvb, 0, 4,
ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": %u", tvb_get_ntohl(tvb, 0));
}
static void
dissect_eigrp_peer_stubinfo (tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_bitmask(tree, tvb, 0, hf_eigrp_stub_flags, ett_eigrp_stub_flags,
eigrp_stub_flag_fields, ENC_BIG_ENDIAN);
}
static void
dissect_eigrp_peer_termination (packet_info *pinfo, proto_item *ti)
{
expert_add_info(pinfo, ti, &ei_eigrp_peer_termination_graceful);
}
static void
dissect_eigrp_peer_tidlist (proto_tree *tree, tvbuff_t *tvb)
{
proto_item *sub_ti;
proto_tree *sub_tree;
int offset = 0;
guint16 size;
proto_tree_add_item(tree, hf_eigrp_tidlist_flags, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
size = tvb_get_ntohs(tvb, offset) / 2;
proto_tree_add_item(tree, hf_eigrp_tidlist_len, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
sub_ti = proto_tree_add_text(tree, tvb, offset, (size*2), "%d TIDs", size);
sub_tree = proto_item_add_subtree(sub_ti, ett_eigrp_tidlist);
for (; size ; size--) {
proto_tree_add_item(sub_tree, hf_eigrp_tidlist_tid, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
}
}
static int
dissect_eigrp_extdata_flags (proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *sub_ti;
proto_tree *sub_tree;
tvbuff_t *sub_tvb;
sub_ti = proto_tree_add_text(tree, tvb, offset, 1, "External Flags");
sub_tree = proto_item_add_subtree(sub_ti, ett_eigrp_extdata_flags);
sub_tvb = tvb_new_subset_remaining(tvb, offset);
proto_tree_add_item(sub_tree, hf_eigrp_extdata_flag_ext, sub_tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_extdata_flag_cd, sub_tvb, 0, 1,
ENC_BIG_ENDIAN);
offset += 1;
return(offset);
}
static int
dissect_eigrp_metric_flags (proto_tree *tree, tvbuff_t *tvb, int offset, int limit)
{
proto_item *sub_ti;
proto_tree *sub_tree;
tvbuff_t *sub_tvb;
sub_ti = proto_tree_add_text(tree, tvb, offset, limit, "Flags");
sub_tree = proto_item_add_subtree(sub_ti, ett_eigrp_metric_flags);
sub_tvb = tvb_new_subset(tvb, offset, limit, -1);
proto_tree_add_item(sub_tree, hf_eigrp_metric_flags_srcwd, sub_tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_metric_flags_active, sub_tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_metric_flags_repl, sub_tvb, 0, 1,
ENC_BIG_ENDIAN);
offset += limit;
return(offset);
}
static int
dissect_eigrp_ipv4_addr (proto_item *ti, proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, int offset, int unreachable)
{
guint8 ip_addr[4], length;
int addr_len;
proto_item *ti_prefixlen, *ti_dst;
int first = TRUE;
for (; tvb_length_remaining(tvb, offset) > 0; offset += (1 + addr_len)) {
length = tvb_get_guint8(tvb, offset);
addr_len = ipv4_addr_and_mask(tvb, offset + 1, ip_addr, length);
if (addr_len < 0) {
ti_prefixlen = proto_tree_add_item(tree, hf_eigrp_ipv4_prefixlen,
tvb, offset, 1, ENC_BIG_ENDIAN);
expert_add_info_format(pinfo, ti_prefixlen, &ei_eigrp_prefixlen, "Invalid prefix length %u, must be <= 32", length);
addr_len = 4;
} else {
proto_tree_add_item(tree, hf_eigrp_ipv4_prefixlen, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
ti_dst = proto_tree_add_text(tree, tvb, offset, addr_len,
"Destination: %s", ip_to_str(ip_addr));
proto_item_append_text(ti," %c %s/%u", first ? '=':',',
ip_to_str(ip_addr), length);
if (unreachable) {
expert_add_info(pinfo, ti_dst, &ei_eigrp_unreachable);
}
}
first = FALSE;
}
return (offset);
}
static int
dissect_eigrp_ipv6_addr (proto_item *ti, proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, int offset, int unreachable)
{
guint8 length;
int addr_len;
struct e_in6_addr addr;
proto_item *ti_prefixlen, *ti_dst;
int first = TRUE;
for (; tvb_length_remaining(tvb, offset) > 0; offset += (1 + addr_len)) {
length = tvb_get_guint8(tvb, offset);
addr_len = ipv6_addr_and_mask(tvb, offset + 1, &addr, length);
if (addr_len < 0) {
ti_prefixlen = proto_tree_add_item(tree, hf_eigrp_ipv6_prefixlen,
tvb, offset, 1, ENC_BIG_ENDIAN);
expert_add_info_format(pinfo, ti_prefixlen, &ei_eigrp_prefixlen, "Invalid prefix length %u, must be <= 128", length);
addr_len = 16;
} else {
proto_tree_add_item(tree, hf_eigrp_ipv6_prefixlen, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
if ((length < 128) && (length % 8 == 0)) {
addr_len++;
}
ti_dst = proto_tree_add_text(tree, tvb, offset, addr_len,
"Destination: %s", ip6_to_str(&addr));
proto_item_append_text(ti," %c %s/%u", first ? '=':',',
ip6_to_str(&addr), length);
if (unreachable) {
expert_add_info(pinfo, ti_dst, &ei_eigrp_unreachable);
}
}
first = FALSE;
}
return(offset);
}
static int
dissect_eigrp_ipx_addr (proto_item *ti, proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, int offset, int unreachable)
{
proto_item *ti_dst;
ti_dst = proto_tree_add_item(tree, hf_eigrp_ipx_dest, tvb, offset, 4,
ENC_NA);
proto_item_append_text(ti," = %s",
tvb_ipxnet_to_string(tvb, offset));
if (unreachable) {
expert_add_info(pinfo, ti_dst, &ei_eigrp_unreachable);
}
offset +=4;
return(offset);
}
static int
dissect_eigrp_service (proto_item *ti, proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, int offset)
{
int afi, length, remaining;
int sub_offset;
proto_item *sub_ti, *reach_ti;
proto_tree *sub_tree, *reach_tree;
tvbuff_t *sub_tvb, *reach_tvb;
guint16 service, sub_service;
remaining = tvb_length_remaining(tvb, offset);
sub_ti = proto_tree_add_text(tree, tvb, offset, remaining, "SAF Service ");
sub_tree = proto_item_add_subtree(sub_ti, ett_eigrp_tlv_metric);
sub_tvb = tvb_new_subset(tvb, offset, remaining, -1);
sub_offset = 0;
for (; tvb_length_remaining(sub_tvb, sub_offset) > 0; ) {
service = tvb_get_ntohs(sub_tvb, sub_offset);
proto_item_append_text(sub_ti, "%c %s", (sub_offset == 0 ? '=':','),
val_to_str_const(service, eigrp_saf_srv2string, ""));
sub_service = tvb_get_ntohs(sub_tvb, sub_offset+2);
proto_item_append_text(ti, "%c %u:%u", (sub_offset == 0 ? '=':','),
service, sub_service);
proto_tree_add_item(sub_tree, hf_eigrp_saf_service, sub_tvb,
sub_offset, 2, ENC_BIG_ENDIAN);
sub_offset += 2;
proto_tree_add_item(sub_tree, hf_eigrp_saf_subservice, sub_tvb,
sub_offset, 2, ENC_BIG_ENDIAN);
sub_offset += 2;
proto_tree_add_item(sub_tree, hf_eigrp_saf_guid, sub_tvb,
sub_offset, GUID_LEN, ENC_BIG_ENDIAN);
sub_offset += GUID_LEN;
proto_tree_add_item(sub_tree, hf_eigrp_saf_data_type, sub_tvb,
sub_offset, 2, ENC_BIG_ENDIAN);
sub_offset += 2;
length = tvb_get_ntohs(sub_tvb, sub_offset);
proto_tree_add_item(sub_tree, hf_eigrp_saf_data_length, sub_tvb,
sub_offset, 2, ENC_BIG_ENDIAN);
sub_offset += 2;
reach_ti = proto_tree_add_text(sub_tree, sub_tvb, sub_offset, 22,
"Reachability");
reach_tree = proto_item_add_subtree(reach_ti, ett_eigrp_saf_reachability);
reach_tvb = tvb_new_subset(sub_tvb, sub_offset, 22, -1);
afi = tvb_get_ntohs(reach_tvb, 0);
proto_tree_add_item(reach_tree, hf_eigrp_saf_reachability_afi,
reach_tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(reach_tree, hf_eigrp_saf_reachability_port,
reach_tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(reach_tree, hf_eigrp_saf_reachability_protocol,
reach_tvb, 4, 2, ENC_BIG_ENDIAN);
switch (afi) {
case EIGRP_AF_IPv4:
proto_tree_add_item(reach_tree, hf_eigrp_saf_reachability_addr_ipv4,
reach_tvb, 6, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(reach_tree, hf_eigrp_nullpad, reach_tvb, 10, 12,
ENC_NA);
break;
case EIGRP_AF_IPv6:
proto_tree_add_item(reach_tree, hf_eigrp_saf_reachability_addr_ipv6,
reach_tvb, 6, 16, ENC_NA);
break;
default:
proto_tree_add_item(reach_tree, hf_eigrp_saf_reachability_addr_hex,
reach_tvb, 6, 16, ENC_NA);
break;
}
sub_offset += 22;
proto_tree_add_item(sub_tree, hf_eigrp_saf_data_sequence, sub_tvb,
sub_offset, 4, ENC_BIG_ENDIAN);
sub_offset += 4;
if (length > 0) {
tvbuff_t *xml_tvb;
guint8 *test_string, *tok;
xml_tvb = tvb_new_subset(sub_tvb, sub_offset, length, length);
test_string = tvb_get_string(wmem_packet_scope(), xml_tvb, 0, (length < 32 ?
length : 32));
tok = strtok(test_string, " \t\r\n");
if (tok && tok[0] == '<') {
dissector_try_string(media_type_table, "application/xml",
xml_tvb, pinfo, sub_tree, NULL);
} else {
dissector_try_string(media_type_table, "text/plain",
xml_tvb, pinfo, sub_tree, NULL);
}
}
sub_offset += length;
}
offset += sub_offset;
return(offset);
}
static int
dissect_eigrp_legacy_metric (proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *sub_ti;
proto_tree *sub_tree;
tvbuff_t *sub_tvb;
sub_ti = proto_tree_add_text(tree, tvb, offset, 16, "Legacy Metric");
sub_tree = proto_item_add_subtree(sub_ti, ett_eigrp_tlv_metric);
sub_tvb = tvb_new_subset(tvb, offset, 16, -1);
proto_tree_add_item(sub_tree, hf_eigrp_legacy_metric_delay, sub_tvb,
0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_legacy_metric_bw, sub_tvb,
4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_legacy_metric_mtu, sub_tvb,
8, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_legacy_metric_hopcount, sub_tvb,
11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_legacy_metric_rel, sub_tvb,
12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_legacy_metric_load, sub_tvb,
13, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_legacy_metric_intag, sub_tvb,
14, 1, ENC_BIG_ENDIAN);
dissect_eigrp_metric_flags(sub_tree, sub_tvb, 15, 1);
offset += 16;
return(offset);
}
static int
dissect_eigrp_ipx_extdata (proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *sub_ti;
proto_tree *sub_tree;
tvbuff_t *sub_tvb;
int sub_offset = 0;
sub_ti = proto_tree_add_text(tree, tvb, offset, 20, "External Data");
sub_tree = proto_item_add_subtree(sub_ti, ett_eigrp_tlv_extdata);
sub_tvb = tvb_new_subset(tvb, offset, 20, -1);
proto_tree_add_item(sub_tree, hf_eigrp_ipx_extdata_routerid, sub_tvb,
sub_offset, 6, ENC_NA);
sub_offset += 6;
proto_tree_add_item(sub_tree, hf_eigrp_extdata_as, sub_tvb,
sub_offset, 4, ENC_BIG_ENDIAN);
sub_offset += 4;
proto_tree_add_item(sub_tree, hf_eigrp_extdata_tag, sub_tvb,
sub_offset, 4, ENC_BIG_ENDIAN);
sub_offset += 4;
proto_tree_add_item(sub_tree, hf_eigrp_extdata_proto, sub_tvb,
sub_offset, 1, ENC_BIG_ENDIAN);
sub_offset += 1;
dissect_eigrp_extdata_flags(sub_tree, sub_tvb, sub_offset);
sub_offset += 1;
proto_tree_add_item(sub_tree, hf_eigrp_ipx_extdata_metric,
sub_tvb, sub_offset, 2, ENC_BIG_ENDIAN);
sub_offset += 2;
proto_tree_add_item(sub_tree, hf_eigrp_ipx_extdata_delay,
sub_tvb, sub_offset, 2, ENC_BIG_ENDIAN);
sub_offset += 2;
offset += sub_offset;
return(offset);
}
static int
dissect_eigrp_extdata (proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *sub_ti;
proto_tree *sub_tree;
tvbuff_t *sub_tvb;
int sub_offset = 0;
sub_ti = proto_tree_add_text(tree, tvb, offset, 20, "External Data");
sub_tree = proto_item_add_subtree(sub_ti, ett_eigrp_tlv_extdata);
sub_tvb = tvb_new_subset(tvb, offset, 20, -1);
proto_tree_add_item(sub_tree, hf_eigrp_extdata_origrid, sub_tvb,
sub_offset, 4, ENC_BIG_ENDIAN);
sub_offset += 4;
proto_tree_add_item(sub_tree, hf_eigrp_extdata_as, sub_tvb,
sub_offset, 4, ENC_BIG_ENDIAN);
sub_offset += 4;
proto_tree_add_item(sub_tree, hf_eigrp_extdata_tag, sub_tvb,
sub_offset, 4, ENC_BIG_ENDIAN);
sub_offset += 4;
proto_tree_add_item(sub_tree, hf_eigrp_extdata_metric, sub_tvb,
sub_offset, 4, ENC_BIG_ENDIAN);
sub_offset += 4;
proto_tree_add_item(sub_tree, hf_eigrp_extdata_reserved, sub_tvb,
sub_offset, 2, ENC_BIG_ENDIAN);
sub_offset += 2;
proto_tree_add_item(sub_tree, hf_eigrp_extdata_proto, sub_tvb,
sub_offset, 1, ENC_BIG_ENDIAN);
sub_offset += 1;
dissect_eigrp_extdata_flags(sub_tree, sub_tvb, sub_offset);
sub_offset += 1;
offset += sub_offset;
return(offset);
}
static int
dissect_eigrp_nexthop (proto_tree *tree, tvbuff_t *tvb, guint16 afi, int offset)
{
switch (afi) {
case EIGRP_SF_IPv4:
case EIGRP_AF_IPv4:
proto_tree_add_item(tree, hf_eigrp_ipv4_nexthop, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
break;
case EIGRP_SF_IPv6:
case EIGRP_AF_IPv6:
proto_tree_add_item(tree, hf_eigrp_ipv6_nexthop, tvb, offset, 16,
ENC_NA);
offset += 16;
break;
case EIGRP_AF_IPX:
proto_tree_add_item(tree, hf_eigrp_ipx_nexthop_net, tvb, offset, 4,
ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_eigrp_ipx_nexthop_host, tvb, offset, 6,
ENC_NA);
offset += 6;
break;
case EIGRP_SF_COMMON:
break;
default:
break;
}
return(offset);
}
static void
dissect_eigrp_general_tlv (proto_item *ti, proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, guint16 tlv)
{
switch (tlv) {
case EIGRP_TLV_PARAMETER:
dissect_eigrp_parameter(tree, tvb, pinfo, ti);
break;
case EIGRP_TLV_AUTH:
dissect_eigrp_auth_tlv(tree, tvb, pinfo, ti);
break;
case EIGRP_TLV_SEQ:
dissect_eigrp_seq_tlv(tree, tvb, pinfo, ti);
break;
case EIGRP_TLV_SW_VERSION:
dissect_eigrp_sw_version(tvb, tree, ti);
break;
case EIGRP_TLV_NEXT_MCAST_SEQ:
dissect_eigrp_next_mcast_seq(tvb, tree, ti);
break;
case EIGRP_TLV_PEER_STUBINFO:
dissect_eigrp_peer_stubinfo(tvb, tree);
break;
case EIGRP_TLV_PEER_TERMINATION:
dissect_eigrp_peer_termination(pinfo, ti);
break;
case EIGRP_TLV_PEER_TIDLIST:
dissect_eigrp_peer_tidlist(tree, tvb);
break;
default:
expert_add_info_format(pinfo, ti, &ei_eigrp_tlv_type, "Unknown Generic TLV (0x%04x)", tlv);
break;
}
}
static int
dissect_eigrp_ipv4_tlv (proto_item *ti, proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, guint16 tlv)
{
int offset = 0;
int unreachable = FALSE;
proto_tree_add_item(tree, hf_eigrp_ipv4_nexthop, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
if ((tlv & EIGRP_TLV_TYPEMASK) == EIGRP_TLV_EXTERNAL) {
offset = dissect_eigrp_extdata(tree, tvb, offset);
}
offset = dissect_eigrp_legacy_metric(tree, tvb, offset);
offset = dissect_eigrp_ipv4_addr(ti, tree, tvb, pinfo, offset, unreachable);
return offset;
}
static void
dissect_eigrp_atalk_tlv (proto_item *ti, proto_tree *tree, tvbuff_t *tvb,
guint16 tlv)
{
int offset = 0;
if (EIGRP_TLV_AT_CBL == tlv) {
proto_tree_add_text(tree, tvb, 0, 4, "AppleTalk Cable Range = %u-%u",
tvb_get_ntohs(tvb, 0), tvb_get_ntohs(tvb, 2));
proto_tree_add_item(tree, hf_eigrp_atalk_routerid, tvb, 4, 4,
ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": Cable range= %u-%u, Router ID= %u",
tvb_get_ntohs(tvb, 0), tvb_get_ntohs(tvb, 2),
tvb_get_ntohl(tvb, 4));
} else {
proto_tree_add_text(tree, tvb, offset, 4, "NextHop Address = %u.%u",
tvb_get_ntohs(tvb, 0), tvb_get_ntohs(tvb, 2));
offset += 4;
if ((tlv & EIGRP_TLV_TYPEMASK) == EIGRP_TLV_EXTERNAL) {
offset = dissect_eigrp_extdata(tree, tvb,offset);
}
offset = dissect_eigrp_legacy_metric(tree, tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Cable range = %u-%u",
tvb_get_ntohs(tvb, 36), tvb_get_ntohs(tvb, 38));
proto_item_append_text(ti, ": %u-%u",
tvb_get_ntohs(tvb, 36), tvb_get_ntohs(tvb, 38));
}
return;
}
static void
dissect_eigrp_ipv6_tlv (proto_item *ti, proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, guint16 tlv)
{
int offset = 0;
int unreachable = FALSE;
proto_tree_add_item(tree, hf_eigrp_ipv6_nexthop, tvb, offset, 16,
ENC_NA);
offset += 16;
if ((tlv & EIGRP_TLV_TYPEMASK) == EIGRP_TLV_EXTERNAL) {
offset = dissect_eigrp_extdata(tree, tvb, offset);
}
offset = dissect_eigrp_legacy_metric(tree, tvb, offset);
dissect_eigrp_ipv6_addr(ti, tree, tvb, pinfo, offset, unreachable);
return;
}
static int
dissect_eigrp_ipx_tlv (proto_item *ti, proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, guint16 tlv)
{
int offset = 0;
int unreachable = FALSE;
offset = dissect_eigrp_nexthop(tree, tvb, EIGRP_AF_IPX, offset);
if ((tlv & EIGRP_TLV_TYPEMASK) == EIGRP_TLV_EXTERNAL) {
offset = dissect_eigrp_ipx_extdata(tree, tvb, offset);
}
offset = dissect_eigrp_legacy_metric(tree, tvb, offset);
offset = dissect_eigrp_ipx_addr(ti, tree, tvb, pinfo, offset, unreachable);
return offset;
}
static int
dissect_eigrp_multi_topology_tlv (proto_item *ti, proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, guint16 tlv)
{
guint16 afi;
int offset = 2;
int unreachable = FALSE;
proto_tree_add_item(tree, hf_eigrp_tid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
afi = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_eigrp_afi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_eigrp_routerid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_eigrp_legacy_metric_tag, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_eigrp_legacy_metric(tree, tvb, offset);
offset = dissect_eigrp_nexthop(tree, tvb, afi, offset);
if ((tlv & EIGRP_TLV_TYPEMASK) == EIGRP_TLV_EXTERNAL) {
if (afi == EIGRP_AF_IPX) {
offset = dissect_eigrp_ipx_extdata(tree, tvb, offset);
} else {
offset = dissect_eigrp_extdata(tree, tvb, offset);
}
}
switch (afi) {
case EIGRP_AF_IPv4:
offset = dissect_eigrp_ipv4_addr(ti, tree, tvb, pinfo, offset, unreachable);
break;
case EIGRP_AF_IPv6:
offset = dissect_eigrp_ipv6_addr(ti, tree, tvb, pinfo, offset, unreachable);
break;
case EIGRP_AF_IPX:
offset = dissect_eigrp_ipx_addr(ti, tree, tvb, pinfo, offset, unreachable);
break;
case EIGRP_SF_COMMON:
case EIGRP_SF_IPv4:
case EIGRP_SF_IPv6:
offset = dissect_eigrp_service(ti, tree, tvb, pinfo, offset);
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_eigrp_afi, tvb, offset, -1);
}
return offset;
}
static int
dissect_eigrp_metric_comm (proto_tree *tree, tvbuff_t *tvb, int offset, int limit)
{
int comm_type;
while (limit > 0) {
comm_type = tvb_get_ntohs(tvb, offset);
offset++;
switch (comm_type) {
case EIGRP_EXTCOMM_EIGRP:
proto_tree_add_text(tree, tvb, offset, 8,
"Type(EIGRP_EXTCOMM_EIGRP): Flag(0x%02x) Tag(%u)",
tvb_get_ntohs(tvb, 0),
tvb_get_ntohl(tvb, 2));
break;
case EIGRP_EXTCOMM_VRR:
proto_tree_add_text(tree, tvb, offset, 8,
"Type(EIGRP_EXTCOMM_VRR)): RES(0x%02x) RID(0x%04x)",
tvb_get_ntohs(tvb, 0),
tvb_get_ntohl(tvb, 2));
break;
case EIGRP_EXTCOMM_DAD:
proto_tree_add_text(tree, tvb, offset, 8,
"Type(EIGRP_EXTCOMM_DAD): AS(%u):SDLY(%u)",
tvb_get_ntohs(tvb, 0),
tvb_get_ntohl(tvb, 2));
break;
case EIGRP_EXTCOMM_VRHB:
proto_tree_add_text(tree, tvb, offset, 8,
"Type(EIGRP_EXTCOMM_VRHB): REL(%u) HOP(%u) SBW(%u)",
tvb_get_guint8(tvb, 0),
tvb_get_guint8(tvb, 1),
tvb_get_ntohl(tvb, 2));
break;
case EIGRP_EXTCOMM_SRLM:
proto_tree_add_text(tree, tvb, offset, 8,
"Type(EIGRP_EXTCOMM_SRLM): RES(%u) LOAD(%u) MTU(%u)",
tvb_get_guint8(tvb, 0),
tvb_get_guint8(tvb, 1),
tvb_get_ntohl(tvb, 2));
break;
case EIGRP_EXTCOMM_SAR:
proto_tree_add_text(tree, tvb, offset, 8,
"Type(EIGRP_EXTCOMM_SAR): xAS(%u) xRID(%u)",
tvb_get_ntohs(tvb, 0),
tvb_get_ntohl(tvb, 2));
break;
case EIGRP_EXTCOMM_RPM:
proto_tree_add_text(tree, tvb, offset, 8,
"Type(EIGRP_EXTCOMM_RPM): xProto(%u) xMETRIC(%u)",
tvb_get_ntohs(tvb, 0),
tvb_get_ntohl(tvb, 2));
break;
case EIGRP_EXTCOMM_SOO_ASFMT:
case EIGRP_EXTCOMM_SOO_ADRFMT:
proto_tree_add_text(tree, tvb, offset, 8,
"Type(EIGRP_EXTCOMM_SOO): AS(%u) TAG(%u)",
tvb_get_ntohs(tvb, 0),
tvb_get_ntohl(tvb, 2));
break;
}
offset += 8;
limit -= 8;
if (0 != limit%8) {
break;
}
}
return(offset);
}
static int
dissect_eigrp_wide_metric_attr (proto_tree *tree, tvbuff_t *tvb,
int offset, int limit)
{
proto_item *sub_ti;
proto_tree *sub_tree;
tvbuff_t *sub_tvb;
int sub_offset;
guint16 attr_offset = 0;
guint8 attr_opcode = 0;
limit *= 2;
sub_ti = proto_tree_add_text(tree, tvb, offset, limit, "Attributes");
sub_tree = proto_item_add_subtree(sub_ti, ett_eigrp_tlv_attr);
sub_tvb = tvb_new_subset(tvb, offset, limit, -1);
sub_offset = 0;
while (limit > 0) {
attr_opcode = tvb_get_guint8(sub_tvb, sub_offset);
proto_tree_add_item(sub_tree, hf_eigrp_attr_opcode, sub_tvb,
sub_offset, 1, ENC_BIG_ENDIAN);
sub_offset += 1;
attr_offset = tvb_get_guint8(sub_tvb, sub_offset) * 2;
proto_tree_add_item(sub_tree, hf_eigrp_attr_offset, sub_tvb,
sub_offset, 1, ENC_BIG_ENDIAN);
sub_offset += 1;
switch (attr_opcode) {
case EIGRP_ATTR_NOOP:
break;
case EIGRP_ATTR_SCALED:
proto_tree_add_item(sub_tree, hf_eigrp_attr_scaled, sub_tvb,
sub_offset, 4, ENC_BIG_ENDIAN);
break;
case EIGRP_ATTR_TAG:
proto_tree_add_item(sub_tree, hf_eigrp_attr_tag, sub_tvb,
sub_offset, 4, ENC_BIG_ENDIAN);
break;
case EIGRP_ATTR_COMM:
dissect_eigrp_metric_comm(sub_tree,
tvb_new_subset(sub_tvb, sub_offset, 8, -1),
sub_offset, limit);
break;
case EIGRP_ATTR_JITTER:
proto_tree_add_item(sub_tree, hf_eigrp_attr_jitter, sub_tvb,
sub_offset, 4, ENC_BIG_ENDIAN);
break;
case EIGRP_ATTR_QENERGY:
proto_tree_add_item(sub_tree, hf_eigrp_attr_qenergy, sub_tvb,
sub_offset, 4, ENC_BIG_ENDIAN);
break;
case EIGRP_ATTR_ENERGY:
proto_tree_add_item(sub_tree, hf_eigrp_attr_energy, sub_tvb,
sub_offset, 4, ENC_BIG_ENDIAN);
break;
default:
break;
}
sub_offset += attr_offset;
limit -= (EIGRP_ATTR_HDRLEN + attr_offset);
}
offset += sub_offset;
return(offset);
}
static int
dissect_eigrp_wide_metric (proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *sub_ti;
proto_tree *sub_tree;
tvbuff_t *sub_tvb;
gint8 attr_size = 0;
guint64 big_num;
sub_ti = proto_tree_add_text(tree, tvb, offset, 24, "Wide Metric");
sub_tree = proto_item_add_subtree(sub_ti, ett_eigrp_tlv_metric);
sub_tvb = tvb_new_subset(tvb, offset, 24, -1);
attr_size = tvb_get_guint8(sub_tvb, 0);
proto_tree_add_item(sub_tree, hf_eigrp_metric_offset,
sub_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_metric_priority,
sub_tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_metric_rel,
sub_tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_metric_load,
sub_tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_metric_mtu,
sub_tvb, 4, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eigrp_metric_hopcount,
sub_tvb, 7, 1, ENC_BIG_ENDIAN);
big_num = tvb_get_ntoh64(sub_tvb, 8);
big_num >>= 16;
if (big_num == G_GUINT64_CONSTANT(0x0000ffffffffffff)) {
proto_tree_add_text(sub_tree, sub_tvb, 8, 6, "Delay: Infinity");
} else {
proto_tree_add_text(sub_tree, sub_tvb, 8, 6, "Delay: %" G_GINT64_MODIFIER "u", big_num);
}
big_num = tvb_get_ntoh64(sub_tvb, 14);
big_num >>= 16;
if (big_num == G_GUINT64_CONSTANT(0x0000ffffffffffff)) {
proto_tree_add_text(sub_tree, sub_tvb, 14, 6, "Bandwidth: Infinity");
} else {
proto_tree_add_text(sub_tree, sub_tvb, 14, 6, "Bandwidth: %" G_GINT64_MODIFIER "u", big_num);
}
proto_tree_add_item(sub_tree, hf_eigrp_metric_reserved, sub_tvb, 20, 2,
ENC_BIG_ENDIAN);
dissect_eigrp_metric_flags(sub_tree, sub_tvb, 22, 2);
offset += 24;
if (attr_size > 0) {
offset = dissect_eigrp_wide_metric_attr(tree, tvb, offset, attr_size);
}
return(offset);
}
static int
dissect_eigrp_multi_protocol_tlv (proto_item *ti, proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, guint16 tlv)
{
int offset = 0;
guint16 afi;
int unreachable = FALSE;
proto_tree_add_item(tree, hf_eigrp_tid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
afi = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_eigrp_afi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_eigrp_routerid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_eigrp_wide_metric(tree, tvb, offset);
offset = dissect_eigrp_nexthop(tree, tvb, afi, offset);
if ((tlv & EIGRP_TLV_TYPEMASK) == EIGRP_TLV_EXTERNAL) {
if (afi == EIGRP_AF_IPX) {
offset = dissect_eigrp_ipx_extdata(tree, tvb, offset);
} else {
offset = dissect_eigrp_extdata(tree, tvb, offset);
}
}
switch (afi) {
case EIGRP_AF_IPv4:
offset = dissect_eigrp_ipv4_addr(ti, tree, tvb, pinfo, offset, unreachable);
break;
case EIGRP_AF_IPv6:
offset = dissect_eigrp_ipv6_addr(ti, tree, tvb, pinfo, offset, unreachable);
break;
case EIGRP_AF_IPX:
offset = dissect_eigrp_ipx_addr(ti, tree, tvb, pinfo, offset, unreachable);
break;
case EIGRP_SF_COMMON:
case EIGRP_SF_IPv4:
case EIGRP_SF_IPv6:
offset = dissect_eigrp_service(ti, tree, tvb, pinfo, offset);
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_eigrp_afi, tvb, offset, -1);
}
return offset;
}
static guint16 ip_checksum(const guint8 *ptr, int len)
{
vec_t cksum_vec[1];
cksum_vec[0].ptr = ptr;
cksum_vec[0].len = len;
return in_cksum(&cksum_vec[0], 1);
}
static int
dissect_eigrp (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *eigrp_tree = NULL, *tlv_tree;
guint opcode, vrid;
guint16 tlv, checksum, cacl_checksum;
guint32 ack, size, offset = EIGRP_HEADER_LENGTH;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "EIGRP");
col_clear(pinfo->cinfo, COL_INFO);
opcode = tvb_get_guint8(tvb, 1);
ack = tvb_get_ntohl(tvb, 12);
if ((opcode == EIGRP_OPC_HELLO) && (0 != ack)) {
opcode = EIGRP_OPC_ACK;
}
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(opcode, eigrp_opcode2string, "Unknown OpCode (0x%04x)"));
ti = proto_tree_add_protocol_format(tree, proto_eigrp, tvb, 0, -1,
"Cisco EIGRP");
eigrp_tree = proto_item_add_subtree(ti, ett_eigrp);
proto_tree_add_item(eigrp_tree, hf_eigrp_version, tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(eigrp_tree, hf_eigrp_opcode, tvb, 1, 1,
ENC_BIG_ENDIAN);
size = tvb_length(tvb);
checksum = tvb_get_ntohs(tvb, 2);
cacl_checksum = ip_checksum(tvb_get_ptr(tvb, 0, size), size);
if (cacl_checksum == checksum) {
proto_tree_add_text(eigrp_tree, tvb, 2, 2,
"Checksum: 0x%02x [incorrect]",
checksum);
expert_add_info(pinfo, ti, &ei_eigrp_checksum_bad);
} else {
proto_tree_add_text(eigrp_tree, tvb, 2, 2,
"Checksum: 0x%02x [correct]", checksum);
}
proto_tree_add_bitmask(eigrp_tree, tvb, 4, hf_eigrp_flags, ett_eigrp_flags,
eigrp_flag_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(eigrp_tree, hf_eigrp_sequence, tvb, 8, 4,
ENC_BIG_ENDIAN);
proto_tree_add_item(eigrp_tree, hf_eigrp_acknowledge, tvb, 12, 4,
ENC_BIG_ENDIAN);
ti = proto_tree_add_item(eigrp_tree, hf_eigrp_vrid, tvb, 16, 2,
ENC_BIG_ENDIAN);
vrid = (tvb_get_ntohs(tvb, 16) & EIGRP_VRID_MASK);
proto_item_append_text(ti, " %s", val_to_str_const(vrid, eigrp_vrid2string, ""));
proto_tree_add_item(eigrp_tree, hf_eigrp_as, tvb, 18, 2,
ENC_BIG_ENDIAN);
switch (opcode) {
case EIGRP_OPC_IPXSAP:
call_dissector(ipxsap_handle,
tvb_new_subset_remaining(tvb, EIGRP_HEADER_LENGTH), pinfo,
eigrp_tree);
break;
default:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
tlv = tvb_get_ntohs(tvb, offset);
if (tlv == EIGRP_TLV_MTR_TIDLIST) {
tlv = EIGRP_TLV_PEER_TIDLIST;
}
size = tvb_get_ntohs(tvb, offset + 2);
if (size == 0) {
proto_tree_add_expert(eigrp_tree, pinfo, &ei_eigrp_tlv_len, tvb, offset, -1);
return(tvb_length(tvb));
}
ti = proto_tree_add_text(eigrp_tree, tvb, offset, size, "%s",
val_to_str(tlv, eigrp_tlv2string, "Unknown TLV (0x%04x)"));
tlv_tree = proto_item_add_subtree(ti, ett_eigrp_tlv);
proto_tree_add_item(tlv_tree, hf_eigrp_tlv_type, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_eigrp_tlv_len, tvb,
(offset + 2), 2, ENC_BIG_ENDIAN);
switch (tlv & EIGRP_TLV_RANGEMASK) {
case EIGRP_TLV_GENERAL:
dissect_eigrp_general_tlv(ti, tlv_tree, tvb_new_subset_length(tvb, (offset + 4), (size - 4)), pinfo, tlv);
break;
case EIGRP_TLV_IPv4:
dissect_eigrp_ipv4_tlv(ti, tlv_tree, tvb_new_subset_length(tvb, (offset + 4), (size - 4)), pinfo, tlv);
break;
case EIGRP_TLV_ATALK:
dissect_eigrp_atalk_tlv(ti, tlv_tree, tvb_new_subset_length(tvb, (offset + 4), (size - 4)), tlv);
break;
case EIGRP_TLV_IPX:
dissect_eigrp_ipx_tlv(ti, tlv_tree, tvb_new_subset_length(tvb, (offset + 4), (size - 4)), pinfo, tlv);
break;
case EIGRP_TLV_IPv6:
dissect_eigrp_ipv6_tlv(ti, tlv_tree, tvb_new_subset_length(tvb, (offset + 4), (size - 4)), pinfo, tlv);
break;
case EIGRP_TLV_MP:
dissect_eigrp_multi_protocol_tlv(ti, tlv_tree, tvb_new_subset_length(tvb, (offset + 4), (size - 4)),
pinfo, tlv);
break;
case EIGRP_TLV_MTR:
dissect_eigrp_multi_topology_tlv(ti, tlv_tree, tvb_new_subset_length(tvb, (offset + 4), (size - 4)),
pinfo, tlv);
break;
default:
expert_add_info_format(pinfo, ti, &ei_eigrp_tlv_type, "Unknown TLV Group (0x%04x)", tlv);
}
offset += size;
}
break;
}
return(tvb_length(tvb));
}
void
proto_register_eigrp(void)
{
static hf_register_info hf[] = {
{ &hf_eigrp_version,
{ "Version", "eigrp.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Version - Version of EIGRP packet format", HFILL }
},
{ &hf_eigrp_opcode,
{ "Opcode", "eigrp.opcode",
FT_UINT8, BASE_DEC, VALS(eigrp_opcode2string), 0x0,
"Opcode - Operation code indicating the message type", HFILL }
},
{ &hf_eigrp_flags,
{ "Flags", "eigrp.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Flag - Initialization bit and is used in establishing "
"a new neighbor relationship", HFILL }
},
{ &hf_eigrp_sequence,
{ "Sequence", "eigrp.seq",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Sequence number -- used to send messages reliably", HFILL }
},
{ &hf_eigrp_acknowledge,
{ "Acknowledge", "eigrp.ack",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Acknowledge number -- used to send messages reliably", HFILL }
},
{ &hf_eigrp_vrid,
{ "Virtual Router ID", "eigrp.vrid",
FT_UINT16, BASE_DEC, NULL, 0,
"Virtual Router ID - For each Virtual Router, there is a separate topology "
"table and routing/service table; even for matching AS. "
"This field allows the gateway to select which set router to use.", HFILL }
},
{ &hf_eigrp_as,
{ "Autonomous System", "eigrp.as",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Autonomous system number - Each AS has a separate topology table "
"which for a give routing/service table. A gateway can participate "
"in more than one AS. This field allows the gateway to"
"select which set of topology tables to use.", HFILL }
},
{ &hf_eigrp_flags_init,
{ "Init", "eigrp.flags.init",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), EIGRP_INIT_FLAG,
"Init - tells the neighbor to send its full topology table", HFILL }
},
{ &hf_eigrp_flags_condrecv,
{ "Conditional Receive", "eigrp.flags.condrecv",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), EIGRP_CR_FLAG,
"Conditionally Received the next packet if address was in listed "
"in the previous HELLO", HFILL }
},
{ &hf_eigrp_flags_restart,
{ "Restart", "eigrp.flags.restart",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), EIGRP_RS_FLAG,
"Restart flag - Set in the HELLO and the initial "
"UPDATE packets during the nsf signaling period.", HFILL },
},
{ &hf_eigrp_flags_eot,
{ "End Of Table", "eigrp.flags.eot",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), EIGRP_EOT_FLAG,
"End-of-Table - Marks the end of the start-up UPDATES indicating the "
"complete topology database has been sent to a new peer", HFILL }
},
{ &hf_eigrp_tlv_type,
{ "Type", "eigrp.tlv_type",
FT_UINT16, BASE_HEX, VALS(eigrp_tlv2string), 0x0,
"TLV Type", HFILL }
},
{ &hf_eigrp_tlv_len,
{ "Length", "eigrp.tlv.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"TLV Length", HFILL }
},
{ &hf_eigrp_par_k1, { "K1", "eigrp.par.k1", FT_UINT8, BASE_DEC, NULL, 0x0,
"Bandwidth/Throughput Coefficient", HFILL }},
{ &hf_eigrp_par_k2, { "K2", "eigrp.par.k2", FT_UINT8, BASE_DEC, NULL, 0x0,
"Load Coefficient", HFILL }},
{ &hf_eigrp_par_k3, { "K3", "eigrp.par.k3", FT_UINT8, BASE_DEC, NULL, 0x0,
"Delay/Latency Coefficient", HFILL }},
{ &hf_eigrp_par_k4, { "K4", "eigrp.par.k4", FT_UINT8, BASE_DEC, NULL, 0x0,
"Reliability Coefficient", HFILL }},
{ &hf_eigrp_par_k5, { "K5", "eigrp.par.k5", FT_UINT8, BASE_DEC, NULL, 0x0,
"Reliability Coefficient", HFILL }},
{ &hf_eigrp_par_k6, { "K6", "eigrp.par.k6", FT_UINT8, BASE_DEC, NULL, 0x0,
"Extended Metric Coefficient", HFILL }},
{ &hf_eigrp_par_holdtime,
{ "Hold Time", "eigrp.par.holdtime", FT_UINT16, BASE_DEC, NULL, 0x0,
"How long to ignore lost HELLO's", HFILL }
},
{ &hf_eigrp_auth_type,
{ "Type", "eigrp.auth.type",
FT_UINT16, BASE_DEC, VALS(eigrp_auth2string), 0x0,
NULL, HFILL }
},
{ &hf_eigrp_auth_len,
{ "Length", "eigrp.auth.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_auth_keyid,
{ "Key ID", "eigrp.auth.keyid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_auth_keyseq,
{ "Key Sequence", "eigrp.auth.keyseq",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_auth_digest,
{ "Digest", "eigrp.auth.digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_seq_addrlen,
{ "Address length", "eigrp.seq.addrlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_seq_ipv4addr,
{ "IP Address", "eigrp.seq.ipv4addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_seq_ipv6addr,
{ "IPv6 Address", "eigrp.seq.ipv6addr",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_next_mcast_seq,
{ "Multicast Sequence", "eigrp.next_mcast_seq",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_stub_flags,
{ "Stub Options", "eigrp.stub_options",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_stub_flags_connected,
{ "Connected", "eigrp.stub_options.connected",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), EIGRP_PEER_ALLOWS_CONNECTED,
NULL, HFILL }
},
{ &hf_eigrp_stub_flags_static,
{ "Static", "eigrp.stub_options.static",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), EIGRP_PEER_ALLOWS_STATIC,
NULL, HFILL }
},
{ &hf_eigrp_stub_flags_summary,
{ "Summary", "eigrp.stub_options.summary",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), EIGRP_PEER_ALLOWS_SUMMARY,
NULL, HFILL }
},
{ &hf_eigrp_stub_flags_redist,
{ "Redistributed", "eigrp.stub_options.redist",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), EIGRP_PEER_ALLOWS_REDIST,
NULL, HFILL }
},
{ &hf_eigrp_stub_flags_leakmap,
{ "Leak-Map", "eigrp.stub_options.leakmap",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), EIGRP_PEER_ALLOWS_LEAKING,
NULL, HFILL }
},
{ &hf_eigrp_stub_flags_recvonly,
{ "Receive-Only", "eigrp.stub_options.recvonly",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), EIGRP_PEER_ALLOWS_RCVONLY,
NULL, HFILL }
},
{ &hf_eigrp_tid,
{ "Topology", "eigrp.tid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_afi,
{ "AFI", "eigrp.afi",
FT_UINT16, BASE_DEC, VALS(eigrp_afi2string), 0x0,
NULL, HFILL }
},
{ &hf_eigrp_legacy_metric_delay,
{ "Scaled Delay", "eigrp.old_metric.delay",
FT_UINT32, BASE_DEC, NULL, 0x0,
"delay, in 39.1 nanosec interments", HFILL }
},
{ &hf_eigrp_legacy_metric_bw,
{ "Scaled BW", "eigrp.old_metric.bw",
FT_UINT32, BASE_DEC, NULL, 0x0,
"bandwidth, in units of 1 Kbit/sec", HFILL }
},
{ &hf_eigrp_legacy_metric_mtu,
{ "MTU", "eigrp.old_metric.mtu",
FT_UINT24, BASE_DEC, NULL, 0x0,
"MTU, in octets", HFILL }
},
{ &hf_eigrp_legacy_metric_hopcount,
{ "Hop Count", "eigrp.old_metric.hopcount",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of hops to destination", HFILL }
},
{ &hf_eigrp_legacy_metric_rel,
{ "Reliability", "eigrp.old_metric.rel",
FT_UINT8, BASE_DEC, NULL, 0x0,
"percent packets successfully tx/rx", HFILL }
},
{ &hf_eigrp_legacy_metric_load,
{ "Load", "eigrp.old_metric.load",
FT_UINT8, BASE_DEC, NULL, 0x0,
"percent of channel occupied", HFILL }
},
{ &hf_eigrp_legacy_metric_intag,
{ "Route Tag", "eigrp.old_metric.intag",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Internal Route Tag", HFILL }
},
{ &hf_eigrp_tidlist_tid,
{ "TID List", "eigrp.tidlist",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_tidlist_flags,
{ "TID List Flags", "eigrp.tidlist.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_tidlist_len,
{ "TID List Size", "eigrp.tidlist.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_routerid,
{ "RouterID", "eigrp.routerid",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Router ID of injecting router", HFILL }
},
{ &hf_eigrp_legacy_metric_tag,
{ "Tag", "eigrp.old_metric.tag",
FT_UINT32, BASE_DEC, NULL, 0x0,
"route tag", HFILL }
},
{ &hf_eigrp_metric_flags_srcwd,
{ "Source Withdraw", "eigrp.metric.flags.srcwd",
FT_BOOLEAN, 8, TFS(&tfs_true_false), EIGRP_OPAQUE_SRCWD,
"Route Source Withdraw", HFILL }
},
{ &hf_eigrp_metric_flags_active,
{ "Route is Active", "eigrp.metric.flags.active",
FT_BOOLEAN, 8, TFS(&tfs_true_false), EIGRP_OPAQUE_ACTIVE,
"Route is currently in active state", HFILL }
},
{ &hf_eigrp_metric_flags_repl,
{ "Route is Replicated", "eigrp.metric.flags.repl",
FT_BOOLEAN, 8, TFS(&tfs_true_false), EIGRP_OPAQUE_REPL,
"Route is replicated from different tableid", HFILL }
},
{ &hf_eigrp_extdata_origrid,
{ "Originating RouterID", "eigrp.extdata.origrid",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Router ID of redistributing router", HFILL }
},
{ &hf_eigrp_extdata_as,
{ "Originating A.S.", "eigrp.extdata.as",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Autonomous System of redistributing protocol", HFILL }
},
{ &hf_eigrp_extdata_tag,
{ "Administrative Tag", "eigrp.extdata.tag",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Administrative Route Tag", HFILL }
},
{ &hf_eigrp_extdata_metric,
{ "External Metric", "eigrp.extdata.metric",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Metric reported by redistributing protocol", HFILL }
},
{ &hf_eigrp_extdata_reserved,
{ "Reserved", "eigrp.extdata.reserved",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_ipx_extdata_delay,
{ "External Delay", "eigrp.extdata.ipx_delay",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Delay reported by redistributing protocol", HFILL }
},
{ &hf_eigrp_ipx_extdata_metric,
{ "External Metric", "eigrp.extdata.ipx_metric",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Delay reported by redistributing protocol", HFILL }
},
{ &hf_eigrp_extdata_proto,
{ "External Protocol ID", "eigrp.extdata.proto",
FT_UINT8, BASE_DEC, VALS(eigrp_proto2string), 0x0,
NULL, HFILL }
},
{ &hf_eigrp_extdata_flag_ext,
{ "Route is External", "eigrp.opaque.flag.ext",
FT_BOOLEAN, 8, TFS(&tfs_true_false), EIGRP_OPAQUE_EXT,
"External route", HFILL }
},
{ &hf_eigrp_extdata_flag_cd,
{ "Route is Candidate Default", "eigrp.opaque.flag.cd",
FT_BOOLEAN, 8, TFS(&tfs_true_false), EIGRP_OPAQUE_CD,
"Candidate-Default route", HFILL }
},
{ &hf_eigrp_metric_offset,
{ "Offset", "eigrp.metric.offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of 16bit words to reach the start of the"
"destination/attribute information", HFILL }
},
{ &hf_eigrp_metric_priority,
{ "Priority", "eigrp.metric.priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Priority of the prefix for ordering transmission", HFILL }
},
{ &hf_eigrp_metric_rel,
{ "Reliability", "eigrp.metric.reliability",
FT_UINT8, BASE_DEC, NULL, 0x0,
"percent packets successfully tx/rx", HFILL }
},
{ &hf_eigrp_metric_load,
{ "Load", "eigrp.metric.load",
FT_UINT8, BASE_DEC, NULL, 0x0,
"percent of channel occupied", HFILL }
},
{ &hf_eigrp_metric_mtu,
{ "MTU", "eigrp.metric.mtu",
FT_UINT24, BASE_DEC, NULL, 0x0,
"MTU, in octets", HFILL }
},
{ &hf_eigrp_metric_hopcount,
{ "Hop Count", "eigrp.metric.hopcount",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of hops to destination", HFILL }
},
{ &hf_eigrp_metric_reserved,
{ "Reserved", "eigrp.metric.reserved",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_attr_opcode,
{ "Opcode", "eigrp.attr.opcode",
FT_UINT8, BASE_DEC, VALS(eigrp_attr_opcode2string), 0x0,
"Opcode - Operation code indicating the attribute type", HFILL }
},
{ &hf_eigrp_attr_offset,
{ "Offset", "eigrp.attr.offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of 2 byte words of data", HFILL }
},
{ &hf_eigrp_attr_scaled,
{ "Legacy Metric", "eigrp.attr.scaled",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Metric calculated from legacy TLVs", HFILL }
},
{ &hf_eigrp_attr_tag,
{ "Tag", "eigrp.attr.tag",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Tag assigned by admin for dest", HFILL }
},
{ &hf_eigrp_attr_jitter,
{ "Jitter", "eigrp.attr.jitter",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Variation in path delay", HFILL }
},
{ &hf_eigrp_attr_qenergy,
{ "Q-Energy", "eigrp.attr.qenergy",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Non-Active energy usage along path", HFILL }
},
{ &hf_eigrp_attr_energy,
{ "Energy", "eigrp.attr.energy",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Active energy usage along path", HFILL }
},
{ &hf_eigrp_ipv4_nexthop,
{ "NextHop", "eigrp.ipv4.nexthop",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_ipv4_prefixlen,
{ "Prefix Length", "eigrp.ipv4.prefixlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_ipv6_nexthop,
{ "NextHop", "eigrp.ipv6.nexthop",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_ipv6_prefixlen,
{ "Prefix Length", "eigrp.ipv6.prefixlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_ipx_nexthop_net,
{ "NextHop Net", "eigrp.ipx.nexthop_net",
FT_IPXNET, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_ipx_nexthop_host,
{ "NextHop Host", "eigrp.ipx.nexthop_host",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_ipx_extdata_routerid,
{ "External RouterID", "eigrp.ipx.routerid",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Router ID of redistributing router", HFILL }
},
{ &hf_eigrp_ipx_dest,
{ "Destination", "eigrp.ipx.dest",
FT_IPXNET, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_atalk_routerid,
{ "AppleTalk Router ID", "eigrp.atalk.routerid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_saf_service,
{ "Service", "eigrp.saf.service",
FT_UINT16, BASE_DEC, VALS(eigrp_saf_srv2string), 0x0,
NULL, HFILL }
},
{ &hf_eigrp_saf_subservice,
{ "Sub-Service", "eigrp.saf.subservice",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_saf_guid,
{ "GUID", "eigrp.saf.guid",
FT_GUID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_saf_data_type,
{ "Type", "eigrp.saf.data.type",
FT_UINT16, BASE_HEX, VALS(eigrp_saf_type2string), 0x0,
"SAF Message Data Type", HFILL }
},
{ &hf_eigrp_saf_data_length,
{ "Length", "eigrp.saf.data.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_saf_data_sequence,
{ "Sequence", "eigrp.saf.data.sequence",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_saf_reachability_afi,
{ "AFI", "eigrp.saf.data.reachability.afi",
FT_UINT16, BASE_DEC, VALS(eigrp_afi2string), 0x0,
NULL, HFILL }
},
{ &hf_eigrp_saf_reachability_port,
{ "Port", "eigrp.saf.data.reachability.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_saf_reachability_protocol,
{ "Protocol", "eigrp.saf.data.reachability.protocol",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_saf_reachability_addr_ipv4,
{ "IPv4 Addr", "eigrp.saf.data.reachability.addr_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_saf_reachability_addr_ipv6,
{ "IPv6 Addr", "eigrp.saf.data.reachability.addr_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_saf_reachability_addr_hex,
{ "Addr", "eigrp.saf.data.reachability.addr_hex",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_eigrp_nullpad,
{ "Nullpad", "eigrp.nullpad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_eigrp,
&ett_eigrp_flags,
&ett_eigrp_tlv,
&ett_eigrp_tlv_metric,
&ett_eigrp_tlv_attr,
&ett_eigrp_tlv_extdata,
&ett_eigrp_tidlist,
&ett_eigrp_stub_flags,
&ett_eigrp_saf_reachability,
&ett_eigrp_metric_flags,
&ett_eigrp_extdata_flags,
};
static ei_register_info ei[] = {
{ &ei_eigrp_peer_termination, { "eigrp.peer_termination", PI_RESPONSE_CODE, PI_NOTE, "Peer Termination", EXPFILL }},
{ &ei_eigrp_auth_len, { "eigrp.auth.length.invalid", PI_MALFORMED, PI_WARN, "Invalid auth len", EXPFILL }},
{ &ei_eigrp_auth_type, { "eigrp.auth.type.invalid", PI_PROTOCOL, PI_WARN, "Invalid auth type", EXPFILL }},
{ &ei_eigrp_seq_addrlen, { "eigrp.seq.addrlen.invalid", PI_MALFORMED, PI_ERROR, "Invalid address length", EXPFILL }},
{ &ei_eigrp_peer_termination_graceful, { "eigrp.peer_termination_graceful", PI_RESPONSE_CODE, PI_NOTE, "Peer Termination (Graceful Shutdown)", EXPFILL }},
{ &ei_eigrp_prefixlen, { "eigrp.prefixlen.invalid", PI_MALFORMED, PI_WARN, "Invalid prefix length", EXPFILL }},
{ &ei_eigrp_unreachable, { "eigrp.unreachable", PI_RESPONSE_CODE, PI_NOTE, "Unreachable", EXPFILL }},
{ &ei_eigrp_tlv_type, { "eigrp.tlv_type.unknown", PI_PROTOCOL, PI_WARN, "Unknown TLV", EXPFILL }},
{ &ei_eigrp_afi, { "eigrp.afi.unknown", PI_PROTOCOL, PI_WARN, "Unknown AFI", EXPFILL }},
{ &ei_eigrp_checksum_bad, { "eigrp.checksum.bad", PI_CHECKSUM, PI_WARN, "Bad Checksum", EXPFILL }},
{ &ei_eigrp_tlv_len, { "eigrp.tlv.len.invalid", PI_MALFORMED, PI_ERROR, "Corrupt TLV (Length field set to 0)", EXPFILL }},
{ &ei_eigrp_tlv_trunc, { "eigrp.tlv.truncated", PI_MALFORMED, PI_ERROR, "Corrupt TLV (Truncated prematurely)", EXPFILL }},
};
expert_module_t* expert_eigrp;
proto_eigrp = proto_register_protocol(
"Enhanced Interior Gateway Routing Protocol",
"EIGRP",
"eigrp"
);
proto_register_field_array(proto_eigrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_eigrp = expert_register_protocol(proto_eigrp);
expert_register_field_array(expert_eigrp, ei, array_length(ei));
}
void
proto_reg_handoff_eigrp(void)
{
dissector_handle_t eigrp_handle;
ipxsap_handle = find_dissector("ipxsap");
media_type_table = find_dissector_table("media_type");
eigrp_handle = new_create_dissector_handle(dissect_eigrp, proto_eigrp);
dissector_add_uint("ip.proto", IP_PROTO_EIGRP, eigrp_handle);
dissector_add_uint("ddp.type", DDP_EIGRP, eigrp_handle);
dissector_add_uint("ipx.socket", IPX_SOCKET_EIGRP, eigrp_handle);
}
