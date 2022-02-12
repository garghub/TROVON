static void
lowpan_addr16_to_ifcid(guint16 addr, guint8 *ifcid)
{
ifcid[0] = 0x00;
ifcid[1] = 0x00;
ifcid[2] = 0x00;
ifcid[3] = 0xff;
ifcid[4] = 0xfe;
ifcid[5] = 0x00;
ifcid[6] = (addr >> 8) & 0xff;
ifcid[7] = (addr >> 0) & 0xff;
}
static gboolean
lowpan_dlsrc_to_ifcid(packet_info *pinfo, guint8 *ifcid)
{
ieee802154_packet * packet = (ieee802154_packet *)pinfo->private_data;
if (pinfo->dl_src.type == AT_EUI64) {
memcpy(ifcid, pinfo->dl_src.data, LOWPAN_IFC_ID_LEN);
ifcid[0] ^= 0x02;
return TRUE;
}
if (packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) {
guint64 addr;
addr = pntoh64(&packet->src64);
memcpy(ifcid, &addr, LOWPAN_IFC_ID_LEN);
ifcid[0] ^= 0x02;
return TRUE;
}
if (packet->src_addr_mode == IEEE802154_FCF_ADDR_SHORT) {
lowpan_addr16_to_ifcid(packet->src16, ifcid);
return TRUE;
}
return FALSE;
}
static gboolean
lowpan_dldst_to_ifcid(packet_info *pinfo, guint8 *ifcid)
{
ieee802154_packet * packet = (ieee802154_packet *)pinfo->private_data;
if (pinfo->dl_dst.type == AT_EUI64) {
memcpy(ifcid, pinfo->dl_dst.data, LOWPAN_IFC_ID_LEN);
ifcid[0] ^= 0x02;
return TRUE;
}
if (packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT) {
guint64 addr;
addr = pntoh64(&packet->dst64);
memcpy(ifcid, &addr, LOWPAN_IFC_ID_LEN);
ifcid[0] ^= 0x02;
return TRUE;
}
if (packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT) {
lowpan_addr16_to_ifcid(packet->dst16, ifcid);
return TRUE;
}
return FALSE;
}
static tvbuff_t *
lowpan_reassemble_ipv6(tvbuff_t *tvb, struct ip6_hdr *ipv6, struct lowpan_nhdr *nhdr_list)
{
gint length = 0;
gint reported = 0;
guint8 * buffer;
guint8 * cursor;
struct lowpan_nhdr *nhdr;
tvbuff_t *ret;
for (nhdr = nhdr_list; nhdr; nhdr = nhdr->next) {
length += nhdr->length;
reported += nhdr->reported;
}
ipv6->ip6_plen = g_ntohs(reported);
buffer = (guint8 *)g_malloc(length + sizeof(struct ip6_hdr));
memcpy(buffer, ipv6, sizeof(struct ip6_hdr));
cursor = buffer + sizeof(struct ip6_hdr);
for (nhdr = nhdr_list; nhdr; nhdr = nhdr->next) {
memcpy(cursor, LOWPAN_NHDR_DATA(nhdr), nhdr->length);
cursor += nhdr->length;
};
ret = tvb_new_child_real_data(tvb, buffer, length + sizeof(struct ip6_hdr), reported + sizeof(struct ip6_hdr));
tvb_set_free_cb(ret, g_free);
return ret;
}
static guint8
lowpan_parse_nhc_proto(tvbuff_t *tvb, gint offset)
{
if (!tvb_bytes_exist(tvb, offset, sizeof(guint8))) return IP_PROTO_NONE;
if (tvb_get_bits8(tvb, offset<<3, LOWPAN_NHC_PATTERN_EXT_BITS) == LOWPAN_NHC_PATTERN_EXT) {
guint8 eid = (tvb_get_guint8(tvb, offset) & LOWPAN_NHC_EXT_EID) >> LOWPAN_NHC_EXT_EID_OFFSET;
switch (eid) {
case LOWPAN_NHC_EID_HOP_BY_HOP:
return IP_PROTO_HOPOPTS;
case LOWPAN_NHC_EID_ROUTING:
return IP_PROTO_ROUTING;
case LOWPAN_NHC_EID_FRAGMENT:
return IP_PROTO_FRAGMENT;
case LOWPAN_NHC_EID_DEST_OPTIONS:
return IP_PROTO_DSTOPTS;
case LOWPAN_NHC_EID_MOBILITY:
return IP_PROTO_MIPV6;
case LOWPAN_NHC_EID_IPV6:
return IP_PROTO_IPV6;
default:
return IP_PROTO_NONE;
};
}
if (tvb_get_bits8(tvb, offset<<3, LOWPAN_NHC_PATTERN_UDP_BITS) == LOWPAN_NHC_PATTERN_UDP) {
return IP_PROTO_UDP;
}
return IP_PROTO_NONE;
}
static gboolean
dissect_6lowpan_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
do {
if (tvb_get_bits8(tvb, 0, LOWPAN_PATTERN_IPV6_BITS) == LOWPAN_PATTERN_IPV6) break;
if (tvb_get_bits8(tvb, 0, LOWPAN_PATTERN_HC1_BITS) == LOWPAN_PATTERN_HC1) break;
if (tvb_get_bits8(tvb, 0, LOWPAN_PATTERN_BC0_BITS) == LOWPAN_PATTERN_BC0) break;
if (tvb_get_bits8(tvb, 0, LOWPAN_PATTERN_IPHC_BITS) == LOWPAN_PATTERN_IPHC) break;
if (tvb_get_bits8(tvb, 0, LOWPAN_PATTERN_MESH_BITS) == LOWPAN_PATTERN_MESH) break;
if (tvb_get_bits8(tvb, 0, LOWPAN_PATTERN_FRAG_BITS) == LOWPAN_PATTERN_FRAG1) break;
if (tvb_get_bits8(tvb, 0, LOWPAN_PATTERN_FRAG_BITS) == LOWPAN_PATTERN_FRAGN) break;
return FALSE;
} while(0);
dissect_6lowpan(tvb, pinfo, tree);
return TRUE;
}
static void
dissect_6lowpan(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *volatile lowpan_tree = NULL;
proto_item *volatile lowpan_root = NULL;
tvbuff_t * next = tvb;
guint8 src_iid[LOWPAN_IFC_ID_LEN];
guint8 dst_iid[LOWPAN_IFC_ID_LEN];
lowpan_dlsrc_to_ifcid(pinfo, src_iid);
lowpan_dldst_to_ifcid(pinfo, dst_iid);
if (tree) {
lowpan_root = proto_tree_add_protocol_format(tree, proto_6lowpan, tvb, 0, tvb_length(tvb), "6LoWPAN");
lowpan_tree = proto_item_add_subtree(lowpan_root, ett_6lowpan);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "6LoWPAN");
if (tvb_get_bits8(next, 0, LOWPAN_PATTERN_MESH_BITS) == LOWPAN_PATTERN_MESH) {
next = dissect_6lowpan_mesh(next, pinfo, lowpan_tree);
if (!next) return;
}
if (tvb_get_bits8(next, 0, LOWPAN_PATTERN_BC0_BITS) == LOWPAN_PATTERN_BC0) {
next = dissect_6lowpan_bc0(next, pinfo, lowpan_tree);
if (!next) return;
}
if (tvb_get_bits8(next, 0, LOWPAN_PATTERN_FRAG_BITS) == LOWPAN_PATTERN_FRAG1) {
next = dissect_6lowpan_frag_first(next, pinfo, lowpan_tree, src_iid, dst_iid);
}
else if (tvb_get_bits8(next, 0, LOWPAN_PATTERN_FRAG_BITS) == LOWPAN_PATTERN_FRAGN) {
next = dissect_6lowpan_frag_middle(next, pinfo, lowpan_tree);
}
else if (tvb_get_bits8(next, 0, LOWPAN_PATTERN_IPV6_BITS) == LOWPAN_PATTERN_IPV6) {
next = dissect_6lowpan_ipv6(next, pinfo, lowpan_tree);
}
else if (tvb_get_bits8(next, 0, LOWPAN_PATTERN_HC1_BITS) == LOWPAN_PATTERN_HC1) {
next = dissect_6lowpan_hc1(next, pinfo, lowpan_tree, -1, src_iid, dst_iid);
if (next) add_new_data_source(pinfo, next, "6LoWPAN");
}
else if (tvb_get_bits8(next, 0, LOWPAN_PATTERN_IPHC_BITS) == LOWPAN_PATTERN_IPHC) {
next = dissect_6lowpan_iphc(next, pinfo, lowpan_tree, -1, src_iid, dst_iid);
if (next) add_new_data_source(pinfo, next, "6LoWPAN");
}
else {
dissect_6lowpan_unknown(next, pinfo, lowpan_tree);
return;
}
if (next) {
call_dissector(ipv6_handle, next, pinfo, tree);
}
}
static tvbuff_t *
dissect_6lowpan_ipv6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree) {
proto_tree_add_bits_item(tree, hf_6lowpan_pattern, tvb, 0, LOWPAN_PATTERN_IPV6_BITS, ENC_BIG_ENDIAN);
}
return tvb_new_subset_remaining(tvb, sizeof(guint8));
}
static tvbuff_t *
dissect_6lowpan_hc1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint dgram_size, guint8 *siid, guint8 *diid)
{
gint offset = 0;
gint bit_offset;
int i;
guint8 hc1_encoding;
guint8 hc_udp_encoding = 0;
guint8 next_header;
proto_tree * hc_tree = NULL;
proto_item * ti;
tvbuff_t * ipv6_tvb;
guint8 ipv6_class;
struct ip6_hdr ipv6;
struct lowpan_nhdr *nhdr_list;
if (tree) {
ti = proto_tree_add_text(tree, tvb, 0, sizeof(guint16), "HC1 Encoding");
hc_tree = proto_item_add_subtree(ti, ett_6lowpan_hc1);
proto_tree_add_bits_item(hc_tree, hf_6lowpan_pattern, tvb, 0, LOWPAN_PATTERN_HC1_BITS, ENC_BIG_ENDIAN);
}
offset += sizeof(guint8);
hc1_encoding = tvb_get_guint8(tvb, offset);
next_header = ((hc1_encoding & LOWPAN_HC1_NEXT) >> 1);
if (tree) {
proto_tree_add_boolean(hc_tree, hf_6lowpan_hc1_source_prefix, tvb, offset, sizeof(guint8), hc1_encoding & LOWPAN_HC1_SOURCE_PREFIX);
proto_tree_add_boolean(hc_tree, hf_6lowpan_hc1_source_ifc, tvb, offset, sizeof(guint8), hc1_encoding & LOWPAN_HC1_SOURCE_IFC);
proto_tree_add_boolean(hc_tree, hf_6lowpan_hc1_dest_prefix, tvb, offset, sizeof(guint8), hc1_encoding & LOWPAN_HC1_DEST_PREFIX);
proto_tree_add_boolean(hc_tree, hf_6lowpan_hc1_dest_ifc, tvb, offset, sizeof(guint8), hc1_encoding & LOWPAN_HC1_DEST_IFC);
proto_tree_add_boolean(hc_tree, hf_6lowpan_hc1_class, tvb, offset, sizeof(guint8), hc1_encoding & LOWPAN_HC1_TRAFFIC_CLASS);
proto_tree_add_uint(hc_tree, hf_6lowpan_hc1_next, tvb, offset, sizeof(guint8), hc1_encoding & LOWPAN_HC1_NEXT);
proto_tree_add_boolean(hc_tree, hf_6lowpan_hc1_more, tvb, offset, sizeof(guint8), hc1_encoding & LOWPAN_HC1_MORE);
}
offset += sizeof(guint8);
if (hc1_encoding & LOWPAN_HC1_MORE) {
if (next_header == LOWPAN_HC1_NEXT_UDP) {
hc_udp_encoding = tvb_get_guint8(tvb, offset);
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, sizeof(guint8), "HC_UDP Encoding");
hc_tree = proto_item_add_subtree(ti, ett_6lowpan_hc2_udp);
proto_tree_add_boolean(hc_tree, hf_6lowpan_hc2_udp_src, tvb, offset, sizeof(guint8), hc_udp_encoding & LOWPAN_HC2_UDP_SRCPORT);
proto_tree_add_boolean(hc_tree, hf_6lowpan_hc2_udp_dst, tvb, offset, sizeof(guint8), hc_udp_encoding & LOWPAN_HC2_UDP_DSTPORT);
proto_tree_add_boolean(hc_tree, hf_6lowpan_hc2_udp_len, tvb, offset, sizeof(guint8), hc_udp_encoding & LOWPAN_HC2_UDP_LENGTH);
}
offset += sizeof(guint8);
}
else {
expert_add_info_format(pinfo, NULL, PI_MALFORMED, PI_ERROR, "HC1 more bits expected for illegal next header type.");
return NULL;
}
}
bit_offset = offset << 3;
ipv6.ip6_hops = tvb_get_bits8(tvb, bit_offset, LOWPAN_IPV6_HOP_LIMIT_BITS);
if (tree) {
proto_tree_add_uint(tree, hf_6lowpan_hop_limit, tvb, bit_offset>>3,
BITS_TO_BYTE_LEN(bit_offset, LOWPAN_IPV6_HOP_LIMIT_BITS), ipv6.ip6_hops);
}
bit_offset += LOWPAN_IPV6_HOP_LIMIT_BITS;
offset = bit_offset;
if (!(hc1_encoding & LOWPAN_HC1_SOURCE_PREFIX)) {
for (i=0; i<8; i++, bit_offset += 8) {
ipv6.ip6_src.bytes[i] = tvb_get_bits8(tvb, bit_offset, 8);
}
}
else {
memcpy(ipv6.ip6_src.bytes, lowpan_llprefix, sizeof(lowpan_llprefix));
}
if (!(hc1_encoding & LOWPAN_HC1_SOURCE_IFC)) {
for (i=8; i<16; i++, bit_offset += 8) {
ipv6.ip6_src.bytes[i] = tvb_get_bits8(tvb, bit_offset, 8);
}
}
else {
memcpy(&ipv6.ip6_src.bytes[sizeof(ipv6.ip6_src) - LOWPAN_IFC_ID_LEN], siid, LOWPAN_IFC_ID_LEN);
}
if (tree) {
proto_tree_add_ipv6(tree, hf_6lowpan_source, tvb, offset>>3,
BITS_TO_BYTE_LEN(offset, (bit_offset-offset)), (guint8 *)&ipv6.ip6_src);
}
offset = bit_offset;
if (!(hc1_encoding & LOWPAN_HC1_DEST_PREFIX)) {
for (i=0; i<8; i++, bit_offset += 8) {
ipv6.ip6_dst.bytes[i] = tvb_get_bits8(tvb, bit_offset, 8);
}
}
else {
memcpy(ipv6.ip6_dst.bytes, lowpan_llprefix, sizeof(lowpan_llprefix));
}
if (!(hc1_encoding & LOWPAN_HC1_DEST_IFC)) {
for (i=8; i<16; i++, bit_offset += 8) {
ipv6.ip6_dst.bytes[i] = tvb_get_bits8(tvb, bit_offset, 8);
}
}
else {
memcpy(&ipv6.ip6_dst.bytes[sizeof(ipv6.ip6_dst) - LOWPAN_IFC_ID_LEN], diid, LOWPAN_IFC_ID_LEN);
}
if (tree) {
proto_tree_add_ipv6(tree, hf_6lowpan_dest, tvb, offset>>3,
BITS_TO_BYTE_LEN(offset, (bit_offset-offset)), (guint8 *)&ipv6.ip6_dst);
}
ipv6_class = 0;
ipv6.ip6_flow = 0;
if (!(hc1_encoding & LOWPAN_HC1_TRAFFIC_CLASS)) {
ipv6_class = tvb_get_bits8(tvb, bit_offset, LOWPAN_IPV6_TRAFFIC_CLASS_BITS);
if (tree) {
proto_tree_add_uint(tree, hf_6lowpan_traffic_class, tvb, bit_offset>>3,
BITS_TO_BYTE_LEN(bit_offset, LOWPAN_IPV6_TRAFFIC_CLASS_BITS), ipv6_class);
}
bit_offset += LOWPAN_IPV6_TRAFFIC_CLASS_BITS;
ipv6.ip6_flow = tvb_get_bits32(tvb, bit_offset, LOWPAN_IPV6_FLOW_LABEL_BITS, ENC_BIG_ENDIAN);
if (tree) {
proto_tree_add_uint(tree, hf_6lowpan_flow_label, tvb, bit_offset>>3,
BITS_TO_BYTE_LEN(bit_offset, LOWPAN_IPV6_FLOW_LABEL_BITS), ipv6.ip6_flow);
}
bit_offset += LOWPAN_IPV6_FLOW_LABEL_BITS;
}
ipv6.ip6_flow = g_ntohl(ipv6.ip6_flow | (ipv6_class << LOWPAN_IPV6_FLOW_LABEL_BITS));
ipv6.ip6_vfc = ((0x6 << 4) | (ipv6_class >> 4));
if (next_header == LOWPAN_HC1_NEXT_UDP) {
ipv6.ip6_nxt = IP_PROTO_UDP;
}
else if (next_header == LOWPAN_HC1_NEXT_ICMP) {
ipv6.ip6_nxt = IP_PROTO_ICMPV6;
}
else if (next_header == LOWPAN_HC1_NEXT_TCP) {
ipv6.ip6_nxt = IP_PROTO_TCP;
}
else {
ipv6.ip6_nxt = tvb_get_bits8(tvb, bit_offset, LOWPAN_IPV6_NEXT_HEADER_BITS);
if (tree) {
proto_tree_add_uint_format(tree, hf_6lowpan_next_header, tvb, bit_offset>>3,
BITS_TO_BYTE_LEN(bit_offset, LOWPAN_IPV6_NEXT_HEADER_BITS), ipv6.ip6_nxt,
"Next header: %s (0x%02x)", ipprotostr(ipv6.ip6_nxt), ipv6.ip6_nxt);
}
bit_offset += LOWPAN_IPV6_NEXT_HEADER_BITS;
}
if ((hc1_encoding & LOWPAN_HC1_MORE) && (next_header == LOWPAN_HC1_NEXT_UDP)) {
struct udp_hdr udp;
gint length;
offset = bit_offset;
if (hc_udp_encoding & LOWPAN_HC2_UDP_SRCPORT) {
udp.src_port = tvb_get_bits8(tvb, bit_offset, LOWPAN_UDP_PORT_COMPRESSED_BITS) + LOWPAN_PORT_12BIT_OFFSET;
bit_offset += LOWPAN_UDP_PORT_COMPRESSED_BITS;
}
else {
udp.src_port = tvb_get_bits16(tvb, bit_offset, LOWPAN_UDP_PORT_BITS, ENC_BIG_ENDIAN);
bit_offset += LOWPAN_UDP_PORT_BITS;
}
if (tree) {
proto_tree_add_uint(tree, hf_6lowpan_udp_src, tvb, offset>>3,
BITS_TO_BYTE_LEN(offset, (bit_offset-offset)), udp.src_port);
}
udp.src_port = g_ntohs(udp.src_port);
offset = bit_offset;
if (hc_udp_encoding & LOWPAN_HC2_UDP_DSTPORT) {
udp.dst_port = tvb_get_bits8(tvb, bit_offset, LOWPAN_UDP_PORT_COMPRESSED_BITS) + LOWPAN_PORT_12BIT_OFFSET;
bit_offset += LOWPAN_UDP_PORT_COMPRESSED_BITS;
}
else {
udp.dst_port = tvb_get_bits16(tvb, bit_offset, LOWPAN_UDP_PORT_BITS, ENC_BIG_ENDIAN);
bit_offset += LOWPAN_UDP_PORT_BITS;
}
if (tree) {
proto_tree_add_uint(tree, hf_6lowpan_udp_dst, tvb, offset>>3,
BITS_TO_BYTE_LEN(offset, (bit_offset-offset)), udp.dst_port);
}
udp.dst_port = g_ntohs(udp.dst_port);
if (!(hc_udp_encoding & LOWPAN_HC2_UDP_LENGTH)) {
udp.length = tvb_get_bits16(tvb, bit_offset, LOWPAN_UDP_LENGTH_BITS, ENC_BIG_ENDIAN);
if (tree) {
proto_tree_add_uint(tree, hf_6lowpan_udp_len, tvb, bit_offset>>3,
BITS_TO_BYTE_LEN(bit_offset, LOWPAN_UDP_LENGTH_BITS), udp.length);
}
bit_offset += LOWPAN_UDP_LENGTH_BITS;
}
else if (dgram_size >= 0) {
if (dgram_size < (gint)sizeof(struct ip6_hdr)) {
return NULL;
}
udp.length = dgram_size - (gint)sizeof(struct ip6_hdr);
}
else {
udp.length = tvb_reported_length(tvb);
udp.length -= BITS_TO_BYTE_LEN(0, bit_offset + LOWPAN_UDP_CHECKSUM_BITS);
udp.length += sizeof(struct udp_hdr);
}
udp.length = g_ntohs(udp.length);
udp.checksum = tvb_get_bits16(tvb, bit_offset, LOWPAN_UDP_CHECKSUM_BITS, ENC_BIG_ENDIAN);
if (tree) {
proto_tree_add_uint(tree, hf_6lowpan_udp_checksum, tvb, bit_offset>>3,
BITS_TO_BYTE_LEN(bit_offset, LOWPAN_UDP_CHECKSUM_BITS), udp.checksum);
}
bit_offset += LOWPAN_UDP_CHECKSUM_BITS;
udp.checksum = g_ntohs(udp.checksum);
offset = BITS_TO_BYTE_LEN(0, bit_offset);
length = (gint)tvb_ensure_length_remaining(tvb, offset);
nhdr_list = (struct lowpan_nhdr *)ep_alloc(sizeof(struct lowpan_nhdr) + sizeof(struct udp_hdr) + length);
nhdr_list->next = NULL;
nhdr_list->proto = IP_PROTO_UDP;
nhdr_list->length = length + sizeof(struct udp_hdr);
nhdr_list->reported = g_ntohs(udp.length);
memcpy(LOWPAN_NHDR_DATA(nhdr_list), &udp, sizeof(struct udp_hdr));
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr_list) + sizeof(struct udp_hdr), offset, length);
}
else {
gint length;
offset = BITS_TO_BYTE_LEN(0, bit_offset);
length = (gint)tvb_ensure_length_remaining(tvb, offset);
nhdr_list = (struct lowpan_nhdr *)ep_alloc(sizeof(struct lowpan_nhdr) + length);
nhdr_list->next = NULL;
nhdr_list->proto = ipv6.ip6_nxt;
nhdr_list->length = length;
if (dgram_size < 0) {
nhdr_list->reported = tvb_reported_length_remaining(tvb, offset);
}
else {
nhdr_list->reported = dgram_size - sizeof(struct ip6_hdr);
}
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr_list), offset, nhdr_list->length);
}
ipv6_tvb = lowpan_reassemble_ipv6(tvb, &ipv6, nhdr_list);
return ipv6_tvb;
}
static tvbuff_t *
dissect_6lowpan_iphc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint dgram_size, guint8 *siid, guint8 *diid)
{
gint offset = 0;
gint length = 0;
proto_tree * iphc_tree = NULL;
proto_item * ti = NULL;
proto_item * ti_dam = NULL;
guint16 iphc_flags;
guint8 iphc_traffic;
guint8 iphc_hop_limit;
guint8 iphc_src_mode;
guint8 iphc_dst_mode;
guint8 iphc_ctx = 0;
gint iphc_sci = LOWPAN_CONTEXT_DEFAULT;
gint iphc_dci = LOWPAN_CONTEXT_DEFAULT;
guint8 ipv6_class = 0;
struct ip6_hdr ipv6;
tvbuff_t * ipv6_tvb;
struct lowpan_nhdr *nhdr_list;
if (tree) {
ti = proto_tree_add_text(tree, tvb, 0, sizeof(guint16), "IPHC Header");
iphc_tree = proto_item_add_subtree(ti, ett_6lowpan_iphc);
proto_tree_add_bits_item(iphc_tree, hf_6lowpan_pattern, tvb, 0, LOWPAN_PATTERN_IPHC_BITS, ENC_BIG_ENDIAN);
}
iphc_flags = tvb_get_ntohs(tvb, offset);
iphc_traffic = (iphc_flags & LOWPAN_IPHC_FLAG_FLOW) >> LOWPAN_IPHC_FLAG_OFFSET_FLOW;
iphc_hop_limit = (iphc_flags & LOWPAN_IPHC_FLAG_HLIM) >> LOWPAN_IPHC_FLAG_OFFSET_HLIM;
iphc_src_mode = (iphc_flags & LOWPAN_IPHC_FLAG_SRC_MODE) >> LOWPAN_IPHC_FLAG_OFFSET_SRC_MODE;
iphc_dst_mode = (iphc_flags & LOWPAN_IPHC_FLAG_DST_MODE) >> LOWPAN_IPHC_FLAG_OFFSET_DST_MODE;
if (tree) {
const value_string *dam_vs;
proto_tree_add_uint (iphc_tree, hf_6lowpan_iphc_flag_tf, tvb, offset, sizeof(guint16), iphc_flags & LOWPAN_IPHC_FLAG_FLOW);
proto_tree_add_boolean (iphc_tree, hf_6lowpan_iphc_flag_nhdr, tvb, offset, sizeof(guint16), iphc_flags & LOWPAN_IPHC_FLAG_NHDR);
proto_tree_add_uint (iphc_tree, hf_6lowpan_iphc_flag_hlim, tvb, offset, sizeof(guint16), iphc_flags & LOWPAN_IPHC_FLAG_HLIM);
proto_tree_add_boolean (iphc_tree, hf_6lowpan_iphc_flag_cid, tvb, offset, sizeof(guint16), iphc_flags & LOWPAN_IPHC_FLAG_CONTEXT_ID);
proto_tree_add_boolean (iphc_tree, hf_6lowpan_iphc_flag_sac, tvb, offset, sizeof(guint16), iphc_flags & LOWPAN_IPHC_FLAG_SRC_COMP);
proto_tree_add_uint(iphc_tree, hf_6lowpan_iphc_flag_sam, tvb, offset, sizeof(guint16), iphc_flags & LOWPAN_IPHC_FLAG_SRC_MODE);
proto_tree_add_boolean (iphc_tree, hf_6lowpan_iphc_flag_mcast, tvb, offset, sizeof(guint16), iphc_flags & LOWPAN_IPHC_FLAG_MCAST_COMP);
proto_tree_add_boolean (iphc_tree, hf_6lowpan_iphc_flag_dac, tvb, offset, sizeof(guint16), iphc_flags & LOWPAN_IPHC_FLAG_DST_COMP);
dam_vs = (iphc_flags & LOWPAN_IPHC_FLAG_MCAST_COMP) ? (lowpan_iphc_mcast_modes) : (lowpan_iphc_addr_modes);
ti_dam = proto_tree_add_uint_format_value(iphc_tree, hf_6lowpan_iphc_flag_dam, tvb, offset, sizeof(guint16),
iphc_flags & LOWPAN_IPHC_FLAG_DST_MODE, "%s (0x%04x)", val_to_str(iphc_dst_mode, dam_vs, "Reserved"), iphc_dst_mode);
}
offset += sizeof(guint16);
if (iphc_flags & LOWPAN_IPHC_FLAG_CONTEXT_ID) {
iphc_ctx = tvb_get_guint8(tvb, offset);
iphc_sci = (iphc_ctx & LOWPAN_IPHC_FLAG_SCI) >> LOWPAN_IPHC_FLAG_OFFSET_SCI;
iphc_dci = (iphc_ctx & LOWPAN_IPHC_FLAG_DCI) >> LOWPAN_IPHC_FLAG_OFFSET_DCI;
if (tree) {
proto_tree_add_uint(iphc_tree, hf_6lowpan_iphc_sci, tvb, offset, sizeof(guint8), iphc_ctx & LOWPAN_IPHC_FLAG_SCI);
proto_tree_add_uint(iphc_tree, hf_6lowpan_iphc_dci, tvb, offset, sizeof(guint8), iphc_ctx & LOWPAN_IPHC_FLAG_DCI);
}
offset += sizeof(guint8);
}
if (!(iphc_flags & LOWPAN_IPHC_FLAG_SRC_COMP)) {
iphc_sci = LOWPAN_CONTEXT_LINK_LOCAL;
}
if (!(iphc_flags & LOWPAN_IPHC_FLAG_DST_COMP)) {
iphc_dci = LOWPAN_CONTEXT_LINK_LOCAL;
}
offset <<= 3;
if (iphc_traffic != LOWPAN_IPHC_FLOW_COMPRESSED) {
ipv6_class |= tvb_get_bits8(tvb, offset, LOWPAN_IPHC_ECN_BITS);
offset += LOWPAN_IPHC_ECN_BITS;
}
if ((iphc_traffic == LOWPAN_IPHC_FLOW_CLASS_LABEL) || (iphc_traffic == LOWPAN_IPHC_FLOW_CLASS)) {
ipv6_class |= (tvb_get_bits8(tvb, offset, LOWPAN_IPHC_DSCP_BITS) << LOWPAN_IPHC_ECN_BITS);
offset += LOWPAN_IPHC_DSCP_BITS;
}
if ((tree) && (iphc_traffic != LOWPAN_IPHC_FLOW_COMPRESSED)) {
proto_tree * tf_tree;
ti = proto_tree_add_uint(tree, hf_6lowpan_traffic_class, tvb, offset>>3, sizeof(guint8), ipv6_class);
tf_tree = proto_item_add_subtree(ti, ett_6lopwan_traffic_class);
proto_tree_add_uint(tf_tree, hf_6lowpan_ecn, tvb, offset>>3, sizeof(guint8), ipv6_class & LOWPAN_IPHC_TRAFFIC_ECN);
proto_tree_add_uint(tf_tree, hf_6lowpan_dscp, tvb, offset>>3, sizeof(guint8), ipv6_class & LOWPAN_IPHC_TRAFFIC_DSCP);
}
if ((iphc_traffic == LOWPAN_IPHC_FLOW_CLASS_LABEL) || (iphc_traffic == LOWPAN_IPHC_FLOW_ECN_LABEL)) {
offset += ((4 - offset) & 0x7);
ipv6.ip6_flow = tvb_get_bits32(tvb, offset, LOWPAN_IPHC_LABEL_BITS, ENC_BIG_ENDIAN);
if (tree) {
proto_tree_add_bits_item(tree, hf_6lowpan_flow_label, tvb, offset, LOWPAN_IPHC_LABEL_BITS, ENC_BIG_ENDIAN);
}
offset += LOWPAN_IPHC_LABEL_BITS;
}
else ipv6.ip6_flow = 0;
ipv6.ip6_flow = g_ntohl(ipv6.ip6_flow) | (ipv6_class << LOWPAN_IPV6_FLOW_LABEL_BITS);
ipv6.ip6_vfc = (0x6 << 4) | (ipv6_class >> 4);
offset >>= 3;
if (!(iphc_flags & LOWPAN_IPHC_FLAG_NHDR)) {
ipv6.ip6_nxt = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint_format(tree, hf_6lowpan_next_header, tvb, offset, sizeof(guint8), ipv6.ip6_nxt,
"Next header: %s (0x%02x)", ipprotostr(ipv6.ip6_nxt), ipv6.ip6_nxt);
}
offset += sizeof(guint8);
}
if (iphc_hop_limit == LOWPAN_IPHC_HLIM_1) {
ipv6.ip6_hlim = 1;
}
else if (iphc_hop_limit == LOWPAN_IPHC_HLIM_64) {
ipv6.ip6_hlim = 64;
}
else if (iphc_hop_limit == LOWPAN_IPHC_HLIM_255) {
ipv6.ip6_hlim = 255;
}
else {
ipv6.ip6_hlim = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_6lowpan_hop_limit, tvb, offset, sizeof(guint8), ipv6.ip6_hlim);
}
offset += sizeof(guint8);
}
memcpy(&ipv6.ip6_src, &lowpan_context_table[iphc_sci], sizeof(ipv6.ip6_src));
if ((iphc_flags & LOWPAN_IPHC_FLAG_SRC_COMP) && (iphc_src_mode == LOWPAN_IPHC_ADDR_SRC_UNSPEC)) {
length = 0;
memset(&ipv6.ip6_src, 0, sizeof(ipv6.ip6_src));
}
else if (iphc_src_mode == LOWPAN_IPHC_ADDR_COMPRESSED) {
length = 0;
memcpy(&ipv6.ip6_src.bytes[sizeof(ipv6.ip6_src) - LOWPAN_IFC_ID_LEN], siid, LOWPAN_IFC_ID_LEN);
}
else if (iphc_src_mode == LOWPAN_IPHC_ADDR_FULL_INLINE) {
length = sizeof(ipv6.ip6_src);
}
else if (iphc_src_mode == LOWPAN_IPHC_ADDR_64BIT_INLINE) {
length = sizeof(guint64);
}
else if (iphc_src_mode == LOWPAN_IPHC_ADDR_16BIT_INLINE) {
length = sizeof(guint16);
ipv6.ip6_src.bytes[11] = 0xff;
ipv6.ip6_src.bytes[12] = 0xfe;
}
if (length) {
tvb_memcpy(tvb, &ipv6.ip6_src.bytes[sizeof(ipv6.ip6_src) - length], offset, length);
}
siid = &ipv6.ip6_src.bytes[sizeof(ipv6.ip6_src) - LOWPAN_IFC_ID_LEN];
if (tree) {
proto_tree_add_ipv6(tree, hf_6lowpan_source, tvb, offset, length, (guint8 *)&ipv6.ip6_src);
}
offset += length;
if ((iphc_flags & LOWPAN_IPHC_FLAG_MCAST_COMP) && !(iphc_flags & LOWPAN_IPHC_FLAG_DST_COMP)) {
length = 0;
memset(&ipv6.ip6_dst, 0, sizeof(ipv6.ip6_dst));
if (iphc_dst_mode == LOWPAN_IPHC_ADDR_FULL_INLINE) {
length = sizeof(ipv6.ip6_dst);
tvb_memcpy(tvb, &ipv6.ip6_dst.bytes[sizeof(ipv6.ip6_dst) - length], offset, length);
}
else if (iphc_dst_mode == LOWPAN_IPHC_MCAST_48BIT) {
ipv6.ip6_dst.bytes[0] = 0xff;
ipv6.ip6_dst.bytes[1] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[11] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[12] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[13] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[14] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[15] = tvb_get_guint8(tvb, offset + (length++));
}
else if (iphc_dst_mode == LOWPAN_IPHC_MCAST_32BIT) {
ipv6.ip6_dst.bytes[0] = 0xff;
ipv6.ip6_dst.bytes[1] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[13] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[14] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[15] = tvb_get_guint8(tvb, offset + (length++));
}
else if (iphc_dst_mode == LOWPAN_IPHC_MCAST_8BIT) {
ipv6.ip6_dst.bytes[0] = 0xff;
ipv6.ip6_dst.bytes[1] = 0x02;
ipv6.ip6_dst.bytes[15] = tvb_get_guint8(tvb, offset + (length++));
}
else {
expert_add_info_format(pinfo, ti_dam, PI_MALFORMED, PI_ERROR, "Illegal destination address mode");
return NULL;
}
}
else if ((iphc_flags & LOWPAN_IPHC_FLAG_MCAST_COMP) && (iphc_flags & LOWPAN_IPHC_FLAG_DST_COMP)) {
length = 0;
memset(&ipv6.ip6_dst, 0, sizeof(ipv6.ip6_dst));
if (iphc_dst_mode == LOWPAN_IPHC_MCAST_STATEFUL_48BIT) {
ipv6.ip6_dst.bytes[0] = 0xff;
ipv6.ip6_dst.bytes[1] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[2] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[12] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[13] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[14] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6_dst.bytes[15] = tvb_get_guint8(tvb, offset + (length++));
}
else {
expert_add_info_format(pinfo, ti_dam, PI_MALFORMED, PI_ERROR, "Illegal destination address mode");
return NULL;
}
}
else {
length = 0;
memcpy(&ipv6.ip6_dst, &lowpan_context_table[iphc_dci], sizeof(ipv6.ip6_dst));
if ((iphc_flags & LOWPAN_IPHC_FLAG_DST_COMP) && (iphc_dst_mode == 0)) {
expert_add_info_format(pinfo, ti_dam, PI_MALFORMED, PI_ERROR, "Illegal destination address mode");
return NULL;
}
else if (iphc_dst_mode == LOWPAN_IPHC_ADDR_COMPRESSED) {
length = 0;
memcpy(&ipv6.ip6_dst.bytes[sizeof(ipv6.ip6_dst) - LOWPAN_IFC_ID_LEN], diid, LOWPAN_IFC_ID_LEN);
}
else if (iphc_dst_mode == LOWPAN_IPHC_ADDR_FULL_INLINE) {
length = sizeof(ipv6.ip6_dst);
}
else if (iphc_dst_mode == LOWPAN_IPHC_ADDR_64BIT_INLINE) {
length = sizeof(guint64);
}
else if (iphc_dst_mode == LOWPAN_IPHC_ADDR_16BIT_INLINE) {
length = sizeof(guint16);
ipv6.ip6_dst.bytes[11] = 0xff;
ipv6.ip6_dst.bytes[12] = 0xfe;
}
if (length) {
tvb_memcpy(tvb, &ipv6.ip6_dst.bytes[sizeof(ipv6.ip6_dst) - length], offset, length);
}
diid = &ipv6.ip6_dst.bytes[sizeof(ipv6.ip6_dst) - LOWPAN_IFC_ID_LEN];
}
if (tree) {
proto_tree_add_ipv6(tree, hf_6lowpan_dest, tvb, offset, length, (guint8 *)&ipv6.ip6_dst);
}
offset += length;
if (iphc_flags & LOWPAN_IPHC_FLAG_NHDR) {
ipv6.ip6_nxt = lowpan_parse_nhc_proto(tvb, offset);
nhdr_list = dissect_6lowpan_iphc_nhc(tvb, pinfo, tree, offset, dgram_size - sizeof(struct ip6_hdr), siid, diid);
}
else {
length = (gint)tvb_ensure_length_remaining(tvb, offset);
nhdr_list = (struct lowpan_nhdr *)ep_alloc(sizeof(struct lowpan_nhdr) + length);
nhdr_list->next = NULL;
nhdr_list->proto = ipv6.ip6_nxt;
nhdr_list->length = length;
if (dgram_size < 0) {
nhdr_list->reported = tvb_reported_length_remaining(tvb, offset);
}
else {
nhdr_list->reported = dgram_size - sizeof(struct ip6_hdr);
}
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr_list), offset, nhdr_list->length);
}
ipv6_tvb = lowpan_reassemble_ipv6(tvb, &ipv6, nhdr_list);
return ipv6_tvb;
}
static struct lowpan_nhdr *
dissect_6lowpan_iphc_nhc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, gint dgram_size, guint8 *siid, guint8 *diid)
{
gint length;
proto_item * ti = NULL;
proto_tree * nhc_tree = NULL;
struct lowpan_nhdr *nhdr;
if (tvb_get_bits8(tvb, offset<<3, LOWPAN_NHC_PATTERN_EXT_IPV6_BITS) == LOWPAN_NHC_PATTERN_EXT_IPV6) {
guint8 ext_flags;
tvbuff_t *iphc_tvb;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, sizeof(guint16), "IPv6 extension header");
nhc_tree = proto_item_add_subtree(ti, ett_6lowpan_nhc_ext);
proto_tree_add_bits_item(nhc_tree, hf_6lowpan_nhc_pattern, tvb, offset<<3, LOWPAN_NHC_PATTERN_EXT_BITS, ENC_BIG_ENDIAN);
}
ext_flags = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(nhc_tree, hf_6lowpan_nhc_ext_eid, tvb, offset, sizeof(guint8), ext_flags & LOWPAN_NHC_EXT_EID);
proto_tree_add_boolean(nhc_tree, hf_6lowpan_nhc_ext_nh, tvb, offset, sizeof(guint8), ext_flags & LOWPAN_NHC_EXT_NHDR);
if (ext_flags & LOWPAN_NHC_EXT_NHDR) {
}
}
offset += sizeof(guint8);
iphc_tvb = dissect_6lowpan_iphc(tvb_new_subset_remaining(tvb, offset), pinfo, tree, dgram_size, siid, diid);
if (!iphc_tvb) return NULL;
nhdr = (struct lowpan_nhdr *)ep_alloc0(sizeof(struct lowpan_nhdr) + tvb_length(iphc_tvb));
nhdr->next = NULL;
nhdr->proto = IP_PROTO_IPV6;
nhdr->length = tvb_length(iphc_tvb);
nhdr->reported = tvb_reported_length(iphc_tvb);
tvb_memcpy(iphc_tvb, LOWPAN_NHDR_DATA(nhdr), 0, nhdr->length);
return nhdr;
}
if (tvb_get_bits8(tvb, offset<<3, LOWPAN_NHC_PATTERN_EXT_BITS) == LOWPAN_NHC_PATTERN_EXT) {
struct ip6_ext ipv6_ext;
guint8 ext_flags;
guint8 ext_len;
guint8 ext_proto;
ext_proto = lowpan_parse_nhc_proto(tvb, offset);
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, sizeof(guint16), "IPv6 extension header");
nhc_tree = proto_item_add_subtree(ti, ett_6lowpan_nhc_ext);
proto_tree_add_bits_item(nhc_tree, hf_6lowpan_nhc_pattern, tvb, offset<<3, LOWPAN_NHC_PATTERN_EXT_BITS, ENC_BIG_ENDIAN);
}
ext_flags = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(nhc_tree, hf_6lowpan_nhc_ext_eid, tvb, offset, sizeof(guint8), ext_flags & LOWPAN_NHC_EXT_EID);
proto_tree_add_boolean(nhc_tree, hf_6lowpan_nhc_ext_nh, tvb, offset, sizeof(guint8), ext_flags & LOWPAN_NHC_EXT_NHDR);
}
offset += sizeof(guint8);
if (!(ext_flags & LOWPAN_NHC_EXT_NHDR)) {
ipv6_ext.ip6e_nxt = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint_format(nhc_tree, hf_6lowpan_nhc_ext_next, tvb, offset, sizeof(guint8), ipv6_ext.ip6e_nxt,
"Next header: %s (0x%02x)", ipprotostr(ipv6_ext.ip6e_nxt), ipv6_ext.ip6e_nxt);
proto_item_set_end(ti, tvb, offset+sizeof(guint8));
}
offset += sizeof(guint8);
}
ext_len = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(nhc_tree, hf_6lowpan_nhc_ext_length, tvb, offset, sizeof(guint8), ext_len);
}
offset += sizeof(guint8);
length = sizeof(struct ip6_ext) + ext_len;
length = (length + 7) & ~0x7;
nhdr = (struct lowpan_nhdr *)ep_alloc0(sizeof(struct lowpan_nhdr) + length);
nhdr->next = NULL;
nhdr->proto = ext_proto;
nhdr->length = length;
nhdr->reported = length;
if (ext_flags & LOWPAN_NHC_EXT_NHDR) {
ipv6_ext.ip6e_nxt = lowpan_parse_nhc_proto(tvb, offset+ext_len);
}
ipv6_ext.ip6e_len = nhdr->reported>>3;
ipv6_ext.ip6e_len -= 1;
memcpy(LOWPAN_NHDR_DATA(nhdr), &ipv6_ext, sizeof(struct ip6_ext));
if (!tvb_bytes_exist(tvb, offset, ext_len)) {
call_dissector(data_handle, tvb_new_subset_remaining(tvb, offset), pinfo, nhc_tree);
nhdr->length = tvb_length_remaining(tvb, offset) + sizeof(struct ip6_ext);
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr) + sizeof(struct ip6_ext), offset, tvb_length_remaining(tvb, offset));
return nhdr;
}
call_dissector(data_handle, tvb_new_subset(tvb, offset, ext_len, ext_len), pinfo, nhc_tree);
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr) + sizeof(struct ip6_ext), offset, ext_len);
offset += ext_len;
if (ext_flags & LOWPAN_NHC_EXT_NHDR) {
nhdr->next = dissect_6lowpan_iphc_nhc(tvb, pinfo, tree, offset, dgram_size - ext_len - sizeof(struct ip6_ext), siid, diid);
}
else {
length = (gint)tvb_ensure_length_remaining(tvb, offset);
nhdr->next = (struct lowpan_nhdr *)ep_alloc(sizeof(struct lowpan_nhdr) + length);
nhdr->next->next = NULL;
nhdr->next->proto = ipv6_ext.ip6e_nxt;
nhdr->next->length = length;
if (dgram_size < 0) {
nhdr->next->reported = tvb_reported_length_remaining(tvb, offset);
}
else {
nhdr->next->reported = dgram_size - ext_len - sizeof(struct ip6_ext);
}
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr->next), offset, nhdr->next->length);
}
return nhdr;
}
if (tvb_get_bits8(tvb, offset<<3, LOWPAN_NHC_PATTERN_UDP_BITS) == LOWPAN_NHC_PATTERN_UDP) {
struct udp_hdr udp;
gint src_bitlen;
gint dst_bitlen;
guint8 udp_flags;
if (tree) {
ti = proto_tree_add_text(tree, tvb, 0, sizeof(guint8), "UDP header compression");
nhc_tree = proto_item_add_subtree(ti, ett_6lowpan_nhc_udp);
proto_tree_add_bits_item(nhc_tree, hf_6lowpan_nhc_pattern, tvb, offset<<3, LOWPAN_NHC_PATTERN_UDP_BITS, ENC_BIG_ENDIAN);
}
udp_flags = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_boolean(nhc_tree, hf_6lowpan_nhc_udp_checksum, tvb, offset, sizeof(guint8), udp_flags & LOWPAN_NHC_UDP_CHECKSUM);
proto_tree_add_boolean(nhc_tree, hf_6lowpan_nhc_udp_src, tvb, offset, sizeof(guint8), udp_flags & LOWPAN_NHC_UDP_SRCPORT);
proto_tree_add_boolean(nhc_tree, hf_6lowpan_nhc_udp_dst, tvb, offset, sizeof(guint8), udp_flags & LOWPAN_NHC_UDP_DSTPORT);
}
offset += sizeof(guint8);
switch (udp_flags & (LOWPAN_NHC_UDP_SRCPORT | LOWPAN_NHC_UDP_DSTPORT)) {
case (LOWPAN_NHC_UDP_SRCPORT | LOWPAN_NHC_UDP_DSTPORT):
udp.src_port = LOWPAN_PORT_12BIT_OFFSET + (tvb_get_guint8(tvb, offset) >> 4);
udp.dst_port = LOWPAN_PORT_12BIT_OFFSET + (tvb_get_guint8(tvb, offset) & 0x0f);
src_bitlen = 4;
dst_bitlen = 4;
break;
case LOWPAN_NHC_UDP_SRCPORT:
udp.src_port = LOWPAN_PORT_8BIT_OFFSET + tvb_get_guint8(tvb, offset);
udp.dst_port = tvb_get_ntohs(tvb, offset + 1);
src_bitlen = 8;
dst_bitlen = 16;
break;
case LOWPAN_NHC_UDP_DSTPORT:
udp.src_port = tvb_get_ntohs(tvb, offset);
udp.dst_port = LOWPAN_PORT_8BIT_OFFSET + tvb_get_guint8(tvb, offset + 2);
src_bitlen = 16;
dst_bitlen = 8;
break;
default:
udp.src_port = tvb_get_ntohs(tvb, offset);
udp.dst_port = tvb_get_ntohs(tvb, offset+2);
src_bitlen = 16;
dst_bitlen = 16;
break;
}
if (tree) {
proto_tree_add_uint(tree, hf_6lowpan_udp_src, tvb, offset, BITS_TO_BYTE_LEN(offset<<3, src_bitlen), udp.src_port);
proto_tree_add_uint(tree, hf_6lowpan_udp_dst, tvb, offset+(src_bitlen>>3), BITS_TO_BYTE_LEN((offset<<3)+src_bitlen, dst_bitlen), udp.dst_port);
}
offset += ((src_bitlen + dst_bitlen)>>3);
udp.src_port = g_ntohs(udp.src_port);
udp.dst_port = g_ntohs(udp.dst_port);
if (!(udp_flags & LOWPAN_NHC_UDP_CHECKSUM)) {
udp.checksum = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_6lowpan_udp_checksum, tvb, offset, sizeof(guint16), udp.checksum);
}
offset += sizeof(guint16);
udp.checksum = g_ntohs(udp.checksum);
}
else {
udp.checksum = 0;
}
if (dgram_size < 0) {
length = tvb_reported_length_remaining(tvb, offset);
udp.length = g_htons(length + sizeof(struct udp_hdr));
}
else {
udp.length = g_htons(dgram_size);
}
#if 0
if ((udp_flags & LOWPAN_NHC_UDP_CHECKSUM) && tvb_bytes_exist(tvb, offset, length)) {
vec_t cksum_vec[3];
struct {
struct e_in6_addr src;
struct e_in6_addr dst;
guint32 length;
guint8 zero[3];
guint8 proto;
} cksum_phdr;
memcpy(&cksum_phdr.src, pinfo->src.data, sizeof(struct e_in6_addr));
memcpy(&cksum_phdr.dst, pinfo->dst.data, sizeof(struct e_in6_addr));
cksum_phdr.length = g_htonl(length + sizeof(struct udp_hdr));
memset(cksum_phdr.zero, 0, sizeof(cksum_phdr.zero));
cksum_phdr.proto = IP_PROTO_UDP;
cksum_vec[0].ptr = (const guint8 *)&cksum_phdr;
cksum_vec[0].len = sizeof(cksum_phdr);
cksum_vec[1].ptr = (const guint8 *)&udp;
cksum_vec[1].len = sizeof(struct udp_hdr);
cksum_vec[2].ptr = tvb_get_ptr(tvb, offset, length);
cksum_vec[2].len = length;
udp.checksum = in_cksum(cksum_vec, 3);
if (udp.checksum == 0) udp.checksum = 0xffff;
}
#endif
length = (gint)tvb_ensure_length_remaining(tvb, offset);
nhdr = (struct lowpan_nhdr *)ep_alloc(sizeof(struct lowpan_nhdr) + sizeof(struct udp_hdr) + length);
nhdr->next = NULL;
nhdr->proto = IP_PROTO_UDP;
nhdr->length = length + sizeof(struct udp_hdr);
nhdr->reported = g_ntohs(udp.length);
memcpy(LOWPAN_NHDR_DATA(nhdr), &udp, sizeof(struct udp_hdr));
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr) + sizeof(struct udp_hdr), offset, tvb_length_remaining(tvb, offset));
return nhdr;
}
return NULL;
}
static tvbuff_t *
dissect_6lowpan_bc0(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 seqnum;
proto_tree * bcast_tree;
proto_item * ti;
if (tree) {
ti = proto_tree_add_text(tree, tvb, 0, sizeof(guint16), "Broadcast Header");
bcast_tree = proto_item_add_subtree(ti, ett_6lowpan_bcast);
proto_tree_add_bits_item(bcast_tree, hf_6lowpan_pattern, tvb, 0, LOWPAN_PATTERN_BC0_BITS, ENC_BIG_ENDIAN);
seqnum = tvb_get_guint8(tvb, sizeof(guint8));
proto_tree_add_uint(bcast_tree, hf_6lowpan_bcast_seqnum, tvb, sizeof(guint8), sizeof(guint8), seqnum);
}
return tvb_new_subset_remaining(tvb, sizeof(guint16));
}
static tvbuff_t *
dissect_6lowpan_mesh(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
guint8 mesh_header;
proto_tree * mesh_tree = NULL;
proto_item * ti = NULL;
const guint8 * src_ifcid;
const guint8 * dst_ifcid;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, 0, "Mesh Header");
mesh_tree = proto_item_add_subtree(ti, ett_6lowpan_mesh);
}
mesh_header = tvb_get_guint8(tvb, offset);
if (tree) {
proto_item * flag_item;
proto_tree * flag_tree;
flag_item = proto_tree_add_text(mesh_tree, tvb, offset, sizeof(guint8), "Flags");
flag_tree = proto_item_add_subtree(flag_item, ett_6lowpan_mesh);
proto_tree_add_bits_item(flag_tree, hf_6lowpan_pattern, tvb, offset * 8, LOWPAN_PATTERN_MESH_BITS, ENC_BIG_ENDIAN);
proto_tree_add_boolean(flag_tree, hf_6lowpan_mesh_v, tvb, offset, sizeof(guint8), mesh_header & LOWPAN_MESH_HEADER_V);
proto_tree_add_boolean(flag_tree, hf_6lowpan_mesh_f, tvb, offset, sizeof(guint8), mesh_header & LOWPAN_MESH_HEADER_F);
if ((mesh_header & LOWPAN_MESH_HEADER_HOPS)==15)
{
guint8 HopsLeft;
proto_tree_add_uint(flag_tree, hf_6lowpan_mesh_hops, tvb, offset, sizeof(guint8), mesh_header & LOWPAN_MESH_HEADER_HOPS);
offset += sizeof(guint8);
HopsLeft=tvb_get_guint8(tvb, offset);
proto_tree_add_uint(mesh_tree, hf_6lowpan_mesh_hops8, tvb, offset, sizeof(guint8), HopsLeft);
}
else
proto_tree_add_uint(flag_tree, hf_6lowpan_mesh_hops, tvb, offset, sizeof(guint8), mesh_header & LOWPAN_MESH_HEADER_HOPS);
}
offset += sizeof(guint8);
if (!(mesh_header & LOWPAN_MESH_HEADER_V)) {
guint64 addr64 = tvb_get_ntoh64(tvb, offset);
if (tree) {
proto_tree_add_uint64(mesh_tree, hf_6lowpan_mesh_orig64, tvb, offset, sizeof(guint64), addr64);
}
src_ifcid = tvb_get_ptr(tvb, offset, sizeof(guint64));
offset += sizeof(guint64);
}
else {
guint16 addr16 = tvb_get_ntohs(tvb, offset);
guint8 * ifcid;
if (tree) {
proto_tree_add_uint(mesh_tree, hf_6lowpan_mesh_orig16, tvb, offset, sizeof(guint16), addr16);
}
ifcid = (guint8 *)ep_alloc(sizeof(guint64));
lowpan_addr16_to_ifcid(addr16, ifcid);
src_ifcid = ifcid;
offset += sizeof(guint16);
}
SET_ADDRESS(&pinfo->src, AT_EUI64, sizeof(guint64), src_ifcid);
SET_ADDRESS(&pinfo->net_src, AT_EUI64, sizeof(guint64), src_ifcid);
if (!(mesh_header & LOWPAN_MESH_HEADER_F)) {
guint64 addr64 = tvb_get_ntoh64(tvb, offset);
if (tree) {
proto_tree_add_uint64(mesh_tree, hf_6lowpan_mesh_dest64, tvb, offset, sizeof(guint64), addr64);
}
dst_ifcid = tvb_get_ptr(tvb, offset, sizeof(guint64));
offset += sizeof(guint64);
}
else {
guint16 addr16 = tvb_get_ntohs(tvb, offset);
guint8 * ifcid;
if (tree) {
proto_tree_add_uint(mesh_tree, hf_6lowpan_mesh_dest16, tvb, offset, sizeof(guint16), addr16);
}
ifcid = (guint8 *)ep_alloc(sizeof(guint64));
lowpan_addr16_to_ifcid(addr16, ifcid);
dst_ifcid = ifcid;
offset += sizeof(guint16);
}
SET_ADDRESS(&pinfo->dst, AT_EUI64, sizeof(guint64), dst_ifcid);
SET_ADDRESS(&pinfo->net_dst, AT_EUI64, sizeof(guint64), dst_ifcid);
if (tree) {
proto_item_set_end(ti, tvb, offset);
}
return tvb_new_subset_remaining(tvb, offset);
}
static tvbuff_t *
dissect_6lowpan_frag_first(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 *siid, guint8 *diid)
{
gint offset = 0;
gint frag_size;
guint16 dgram_size;
guint16 dgram_tag;
proto_tree * frag_tree = NULL;
proto_item * ti = NULL;
proto_item * length_item = NULL;
tvbuff_t * new_tvb = NULL;
tvbuff_t * frag_tvb = NULL;
fragment_data * frag_data = NULL;
gboolean save_fragmented;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, 0, "Fragmentation Header");
frag_tree = proto_item_add_subtree(ti, ett_6lowpan_frag);
}
dgram_size = tvb_get_bits16(tvb, (offset * 8) + LOWPAN_PATTERN_FRAG_BITS, LOWPAN_FRAG_DGRAM_SIZE_BITS, ENC_BIG_ENDIAN);
if (tree) {
proto_tree_add_bits_item(frag_tree, hf_6lowpan_pattern, tvb, offset * 8, LOWPAN_PATTERN_FRAG_BITS, ENC_BIG_ENDIAN);
length_item = proto_tree_add_uint(frag_tree, hf_6lowpan_frag_dgram_size, tvb, offset, sizeof(guint16), dgram_size);
}
offset += sizeof(guint16);
dgram_tag = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(frag_tree, hf_6lowpan_frag_dgram_tag, tvb, offset, sizeof(guint16), dgram_tag);
}
offset += sizeof(guint16);
if (tree) {
proto_item_set_end(ti, tvb, offset);
}
frag_tvb = tvb_new_subset_remaining(tvb, offset);
if (tvb_get_bits8(frag_tvb, 0, LOWPAN_PATTERN_IPV6_BITS) == LOWPAN_PATTERN_IPV6) {
frag_tvb = dissect_6lowpan_ipv6(frag_tvb, pinfo, tree);
}
else if (tvb_get_bits8(frag_tvb, 0, LOWPAN_PATTERN_HC1_BITS) == LOWPAN_PATTERN_HC1) {
if (dgram_size < (gint)sizeof(struct ip6_hdr)) {
expert_add_info_format(pinfo, length_item, PI_MALFORMED,
PI_ERROR, "Length is less than IPv6 header length %u",
(guint)sizeof(struct ip6_hdr));
}
frag_tvb = dissect_6lowpan_hc1(frag_tvb, pinfo, tree, dgram_size, siid, diid);
}
else if (tvb_get_bits8(frag_tvb, 0, LOWPAN_PATTERN_IPHC_BITS) == LOWPAN_PATTERN_IPHC) {
if (dgram_size < (gint)sizeof(struct ip6_hdr)) {
expert_add_info_format(pinfo, length_item, PI_MALFORMED,
PI_ERROR, "Length is less than IPv6 header length %u",
(guint)sizeof(struct ip6_hdr));
}
frag_tvb = dissect_6lowpan_iphc(frag_tvb, pinfo, tree, dgram_size, siid, diid);
}
else {
dissect_6lowpan_unknown(frag_tvb, pinfo, tree);
return NULL;
}
if (frag_tvb == NULL) {
return NULL;
}
frag_size = tvb_length(frag_tvb);
tvb_set_reported_length(frag_tvb, frag_size);
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
frag_data = fragment_add_check(frag_tvb, 0, pinfo, dgram_tag,
lowpan_fragment_table, lowpan_reassembled_table,
0, frag_size, (frag_size < dgram_size));
new_tvb = process_reassembled_data(frag_tvb, 0, pinfo,
"6LowPAN", frag_data, &lowpan_frag_items,
NULL, tree);
pinfo->fragmented = save_fragmented;
if (new_tvb) {
return new_tvb;
}
else {
call_dissector(data_handle, frag_tvb, pinfo, proto_tree_get_root(tree));
return NULL;
}
}
static tvbuff_t *
dissect_6lowpan_frag_middle(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
gint frag_size;
guint16 dgram_size;
guint16 dgram_tag;
guint16 dgram_offset = 0;
proto_tree * frag_tree = NULL;
proto_item * ti = NULL;
tvbuff_t * new_tvb = NULL;
fragment_data * frag_data = NULL;
gboolean save_fragmented;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, 0, "Fragmentation Header");
frag_tree = proto_item_add_subtree(ti, ett_6lowpan_frag);
}
dgram_size = tvb_get_bits16(tvb, (offset * 8) + LOWPAN_PATTERN_FRAG_BITS, LOWPAN_FRAG_DGRAM_SIZE_BITS, ENC_BIG_ENDIAN);
if (tree) {
proto_tree_add_bits_item(frag_tree, hf_6lowpan_pattern, tvb, offset * 8, LOWPAN_PATTERN_FRAG_BITS, ENC_BIG_ENDIAN);
proto_tree_add_uint(frag_tree, hf_6lowpan_frag_dgram_size, tvb, offset, sizeof(guint16), dgram_size);
}
offset += sizeof(guint16);
dgram_tag = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(frag_tree, hf_6lowpan_frag_dgram_tag, tvb, offset, sizeof(guint16), dgram_tag);
}
offset += sizeof(guint16);
dgram_offset = tvb_get_guint8(tvb, offset) * 8;
if (tree) {
proto_tree_add_uint(frag_tree, hf_6lowpan_frag_dgram_offset, tvb, offset, sizeof(guint8), dgram_offset);
}
offset += sizeof(guint8);
frag_size = tvb_reported_length_remaining(tvb, offset);
if (tree) {
proto_item_set_end(ti, tvb, offset);
}
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
frag_data = fragment_add_check(tvb, offset, pinfo, dgram_tag,
lowpan_fragment_table, lowpan_reassembled_table,
dgram_offset, frag_size, ((dgram_offset + frag_size) < dgram_size));
new_tvb = process_reassembled_data(tvb, offset, pinfo,
"6LowPAN", frag_data, &lowpan_frag_items,
NULL, tree);
pinfo->fragmented = save_fragmented;
if (new_tvb) {
return new_tvb;
}
else {
new_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, new_tvb, pinfo, proto_tree_get_root(tree));
return NULL;
}
}
void
dissect_6lowpan_unknown(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t * data_tvb;
if (tree) {
proto_tree_add_bits_item(tree, hf_6lowpan_pattern, tvb, 0, 8, ENC_BIG_ENDIAN);
}
data_tvb = tvb_new_subset_remaining(tvb, sizeof(guint8));
call_dissector(data_handle, data_tvb, pinfo, proto_tree_get_root(tree));
}
void
proto_register_6lowpan(void)
{
static hf_register_info hf[] = {
{ &hf_6lowpan_pattern,
{ "Pattern", "6lowpan.pattern",
FT_UINT8, BASE_HEX, VALS(lowpan_patterns), 0x0, NULL, HFILL }},
{ &hf_6lowpan_nhc_pattern,
{ "Pattern", "6lowpan.nhc.pattern",
FT_UINT8, BASE_HEX, VALS(lowpan_nhc_patterns), 0x0, NULL, HFILL }},
{ &hf_6lowpan_hc1_source_prefix,
{ "Source prefix", "6lowpan.hc1.src_prefix",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_HC1_SOURCE_PREFIX, NULL, HFILL }},
{ &hf_6lowpan_hc1_source_ifc,
{ "Source interface", "6lowpan.hc1.src_ifc",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_HC1_SOURCE_IFC, NULL, HFILL }},
{ &hf_6lowpan_hc1_dest_prefix,
{ "Destination prefix", "6lowpan.hc1.dst_prefix",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_HC1_DEST_PREFIX, NULL, HFILL }},
{ &hf_6lowpan_hc1_dest_ifc,
{ "Destination interface", "6lowpan.hc1.dst_ifc",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_HC1_DEST_IFC, NULL, HFILL }},
{ &hf_6lowpan_hc1_class,
{ "Traffic class and flow label", "6lowpan.hc1.class",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_HC1_TRAFFIC_CLASS, NULL, HFILL }},
{ &hf_6lowpan_hc1_next,
{ "Next header", "6lowpan.hc1.next",
FT_UINT8, BASE_HEX, VALS(lowpan_hc1_next), LOWPAN_HC1_NEXT, NULL, HFILL }},
{ &hf_6lowpan_hc1_more,
{ "More HC bits", "6lowpan.hc1.more",
FT_BOOLEAN, 8, NULL, LOWPAN_HC1_MORE, NULL, HFILL }},
{ &hf_6lowpan_hc2_udp_src,
{ "Source port", "6lowpan.hc2.udp.src",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_HC2_UDP_SRCPORT, NULL, HFILL }},
{ &hf_6lowpan_hc2_udp_dst,
{ "Destination port", "6lowpan.hc2.udp.dst",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_HC2_UDP_DSTPORT, NULL, HFILL }},
{ &hf_6lowpan_hc2_udp_len,
{ "Length", "6lowpan.hc2.udp.length",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_HC2_UDP_LENGTH, NULL, HFILL }},
{ &hf_6lowpan_iphc_flag_tf,
{ "Traffic class and flow label", "6lowpan.iphc.tf",
FT_UINT16, BASE_HEX, VALS(lowpan_iphc_traffic), LOWPAN_IPHC_FLAG_FLOW, "traffic class and flow control encoding", HFILL }},
{ &hf_6lowpan_iphc_flag_nhdr,
{ "Next header", "6lowpan.iphc.nh",
FT_BOOLEAN, 16, TFS(&lowpan_compression), LOWPAN_IPHC_FLAG_NHDR, NULL, HFILL }},
{ &hf_6lowpan_iphc_flag_hlim,
{ "Hop limit", "6lowpan.iphc.hlim",
FT_UINT16, BASE_HEX, VALS(lowpan_iphc_hop_limit), LOWPAN_IPHC_FLAG_HLIM, NULL, HFILL }},
{ &hf_6lowpan_iphc_flag_cid,
{ "Context identifier extension", "6lowpan.iphc.cid",
FT_BOOLEAN, 16, NULL, LOWPAN_IPHC_FLAG_CONTEXT_ID, NULL, HFILL }},
{ &hf_6lowpan_iphc_flag_sac,
{ "Source address compression", "6lowpan.iphc.sac",
FT_BOOLEAN, 16, TFS(&lowpan_iphc_addr_compression), LOWPAN_IPHC_FLAG_SRC_COMP, NULL, HFILL }},
{ &hf_6lowpan_iphc_flag_sam,
{ "Source address mode", "6lowpan.iphc.sam",
FT_UINT16, BASE_HEX, VALS(lowpan_iphc_addr_modes), LOWPAN_IPHC_FLAG_SRC_MODE, NULL, HFILL }},
{ &hf_6lowpan_iphc_flag_mcast,
{ "Multicast address compression", "6lowpan.iphc.m",
FT_BOOLEAN, 16, NULL, LOWPAN_IPHC_FLAG_MCAST_COMP, NULL, HFILL }},
{ &hf_6lowpan_iphc_flag_dac,
{ "Destination address compression","6lowpan.iphc.dac",
FT_BOOLEAN, 16, TFS(&lowpan_iphc_addr_compression), LOWPAN_IPHC_FLAG_DST_COMP, NULL, HFILL }},
{ &hf_6lowpan_iphc_flag_dam,
{ "Destination address mode", "6lowpan.iphc.dam",
FT_UINT16, BASE_HEX, VALS(lowpan_iphc_addr_modes), LOWPAN_IPHC_FLAG_DST_MODE, NULL, HFILL }},
{ &hf_6lowpan_iphc_sci,
{ "Source context identifier", "6lowpan.iphc.sci",
FT_UINT8, BASE_HEX, NULL, LOWPAN_IPHC_FLAG_SCI, NULL, HFILL }},
{ &hf_6lowpan_iphc_dci,
{ "Destination context identifier", "6lowpan.iphc.dci",
FT_UINT8, BASE_HEX, NULL, LOWPAN_IPHC_FLAG_DCI, NULL, HFILL }},
{ &hf_6lowpan_nhc_ext_eid,
{ "Header ID", "6lowpan.nhc.ext.eid",
FT_UINT8, BASE_HEX, VALS(lowpan_nhc_eid), LOWPAN_NHC_EXT_EID, NULL, HFILL }},
{ &hf_6lowpan_nhc_ext_nh,
{ "Next header", "6lowpan.nhc.ext.nh",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_NHC_EXT_NHDR, NULL, HFILL }},
{ &hf_6lowpan_nhc_ext_next,
{ "Next header", "6lowpan.nhc.ext.next",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_nhc_ext_length,
{ "Header length", "6lowpan.nhc.ext.length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_nhc_udp_checksum,
{ "Checksum", "6lowpan.nhc.udp.checksum",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_NHC_UDP_CHECKSUM, NULL, HFILL }},
{ &hf_6lowpan_nhc_udp_src,
{ "Source port", "6lowpan.nhc.udp.src",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_NHC_UDP_SRCPORT, NULL, HFILL }},
{ &hf_6lowpan_nhc_udp_dst,
{ "Destination port", "6lowpan.nhc.udp.dst",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_NHC_UDP_DSTPORT, NULL, HFILL }},
{ &hf_6lowpan_traffic_class,
{ "Traffic class", "6lowpan.class",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_flow_label,
{ "Flow label", "6lowpan.flow",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_ecn,
{ "ECN", "6lowpan.ecn",
FT_UINT8, BASE_HEX, NULL, LOWPAN_IPHC_TRAFFIC_ECN, NULL, HFILL }},
{ &hf_6lowpan_dscp,
{ "DSCP", "6lowpan.dscp",
FT_UINT8, BASE_HEX, NULL, LOWPAN_IPHC_TRAFFIC_DSCP, NULL, HFILL }},
{ &hf_6lowpan_next_header,
{ "Next header", "6lowpan.next",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_hop_limit,
{ "Hop limit", "6lowpan.hops",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_source,
{ "Source", "6lowpan.src",
FT_IPv6, BASE_NONE, NULL, 0x0, "Source IPv6 address", HFILL }},
{ &hf_6lowpan_dest,
{ "Destination", "6lowpan.dst",
FT_IPv6, BASE_NONE, NULL, 0x0, "Destination IPv6 address", HFILL }},
{ &hf_6lowpan_udp_src,
{ "Source port", "6lowpan.udp.src",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_udp_dst,
{ "Destination port", "6lowpan.udp.dst",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_udp_len,
{ "UDP length", "6lowpan.udp.length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_udp_checksum,
{ "UDP checksum", "6lowpan.udp.checksum",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_bcast_seqnum,
{ "Sequence number", "6lowpan.bcast.seqnum",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_mesh_v,
{ "V", "6lowpan.mesh.v",
FT_BOOLEAN, 8, NULL, LOWPAN_MESH_HEADER_V, "short originator address present", HFILL }},
{ &hf_6lowpan_mesh_f,
{ "D", "6lowpan.mesh.f",
FT_BOOLEAN, 8, NULL, LOWPAN_MESH_HEADER_F, "short destination address present", HFILL }},
{ &hf_6lowpan_mesh_hops,
{ "Hops left", "6lowpan.mesh.hops",
FT_UINT8, BASE_DEC, NULL, LOWPAN_MESH_HEADER_HOPS, NULL, HFILL }},
{ &hf_6lowpan_mesh_hops8,
{ "Deep Hops left (Flags.Hops left == 15)", "6lowpan.mesh.hops8",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_mesh_orig16,
{ "Originator", "6lowpan.mesh.orig16",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_mesh_orig64,
{ "Originator", "6lowpan.mesh.orig64",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_mesh_dest16,
{ "Destination", "6lowpan.mesh.dest16",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_mesh_dest64,
{ "Destination", "6lowpan.mesh.dest64",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_frag_dgram_size,
{ "Datagram size", "6lowpan.frag.size",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_frag_dgram_tag,
{ "Datagram tag", "6lowpan.frag.tag",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_frag_dgram_offset,
{ "Datagram offset", "6lowpan.frag.offset",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_fragments,
{ "Message fragments", "6lowpan.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_6lowpan_fragment,
{ "Message fragment", "6lowpan.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_6lowpan_fragment_overlap,
{ "Message fragment overlap", "6lowpan.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_6lowpan_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data", "6lowpan.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_6lowpan_fragment_multiple_tails,
{ "Message has multiple tail fragments", "6lowpan.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_6lowpan_fragment_too_long_fragment,
{ "Message fragment too long", "6lowpan.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_6lowpan_fragment_error,
{ "Message defragmentation error", "6lowpan.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_6lowpan_fragment_count,
{ "Message fragment count", "6lowpan.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_6lowpan_reassembled_in,
{ "Reassembled in", "6lowpan.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_6lowpan_reassembled_length,
{ "Reassembled 6LowPAN length", "6lowpan.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }}
};
static gint *ett[] = {
&ett_6lowpan,
&ett_6lowpan_hc1,
&ett_6lowpan_hc2_udp,
&ett_6lowpan_iphc,
&ett_6lowpan_nhc_ext,
&ett_6lowpan_nhc_udp,
&ett_6lowpan_bcast,
&ett_6lowpan_mesh,
&ett_6lowpan_mesh_flags,
&ett_6lowpan_frag,
&ett_6lopwan_traffic_class,
&ett_6lowpan_fragment,
&ett_6lowpan_fragments
};
int i;
module_t *prefs_module;
static gchar init_context_str[] = "2002:db8::ff:fe00:0";
proto_6lowpan = proto_register_protocol("IPv6 over IEEE 802.15.4", "6LoWPAN", "6lowpan");
proto_register_field_array(proto_6lowpan, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("6lowpan", dissect_6lowpan, proto_6lowpan);
register_init_routine(proto_init_6lowpan);
memset(lowpan_context_table, 0, sizeof(lowpan_context_table));
memset((gchar*)lowpan_context_prefs, 0, sizeof(lowpan_context_prefs));
lowpan_context_table[LOWPAN_CONTEXT_LINK_LOCAL].bytes[0] = 0xfe;
lowpan_context_table[LOWPAN_CONTEXT_LINK_LOCAL].bytes[1] = 0x80;
lowpan_context_prefs[LOWPAN_CONTEXT_DEFAULT] = init_context_str;
lowpan_context_table[LOWPAN_CONTEXT_DEFAULT].bytes[0] = 0x20;
lowpan_context_table[LOWPAN_CONTEXT_DEFAULT].bytes[1] = 0x02;
lowpan_context_table[LOWPAN_CONTEXT_DEFAULT].bytes[2] = 0x0d;
lowpan_context_table[LOWPAN_CONTEXT_DEFAULT].bytes[3] = 0xb8;
lowpan_context_table[LOWPAN_CONTEXT_DEFAULT].bytes[11] = 0xff;
lowpan_context_table[LOWPAN_CONTEXT_DEFAULT].bytes[12] = 0xfe;
prefs_module = prefs_register_protocol(proto_6lowpan, prefs_6lowpan_apply);
for (i = 0; i < LOWPAN_CONTEXT_COUNT; i++) {
GString *pref_name, *pref_title, *pref_desc;
pref_name = g_string_new("");
pref_title = g_string_new("");
pref_desc = g_string_new("");
g_string_printf(pref_name, "context%d", i);
g_string_printf(pref_title, "Context %d", i);
g_string_printf(pref_desc, "IPv6 prefix to use for stateful address decompression.");
prefs_register_string_preference(prefs_module, pref_name->str, pref_title->str,
pref_desc->str, &lowpan_context_prefs[i]);
g_string_free(pref_name, FALSE);
g_string_free(pref_title, FALSE);
g_string_free(pref_desc, FALSE);
}
}
static void
proto_init_6lowpan(void)
{
fragment_table_init(&lowpan_fragment_table);
reassembled_table_init(&lowpan_reassembled_table);
}
void
prefs_6lowpan_apply(void)
{
int i;
for (i = 0; i < LOWPAN_CONTEXT_COUNT; i++) {
if (!(lowpan_context_prefs[i]) || (inet_pton(AF_INET6, lowpan_context_prefs[i], &lowpan_context_table[i]) != 1)) {
memset(&lowpan_context_table[i], 0, sizeof(struct e_in6_addr));
}
}
}
void
proto_reg_handoff_6lowpan(void)
{
data_handle = find_dissector("data");
ipv6_handle = find_dissector("ipv6");
heur_dissector_add("wpan", dissect_6lowpan_heur, proto_6lowpan);
}
