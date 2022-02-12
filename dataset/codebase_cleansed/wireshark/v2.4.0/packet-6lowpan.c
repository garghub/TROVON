static void
lowpan_pfxcpy(void *dst, const void *src, size_t bits)
{
memcpy(dst, src, bits>>3);
if (bits & 0x7) {
guint8 mask = ((0xff00) >> (bits & 0x7));
guint8 last = ((const guint8 *)src)[bits>>3] & mask;
((guint8 *)dst)[bits>>3] &= ~mask;
((guint8 *)dst)[bits>>3] |= last;
}
}
static guint
lowpan_context_hash(gconstpointer key)
{
return (((const lowpan_context_key *)key)->cid) | (((const lowpan_context_key *)key)->pan << 8);
}
static gboolean
lowpan_context_equal(gconstpointer a, gconstpointer b)
{
return (((const lowpan_context_key *)a)->pan == ((const lowpan_context_key *)b)->pan) &&
(((const lowpan_context_key *)a)->cid == ((const lowpan_context_key *)b)->cid);
}
static lowpan_context_data *
lowpan_context_find(guint8 cid, guint16 pan)
{
lowpan_context_key key;
lowpan_context_data *data;
if (cid == LOWPAN_CONTEXT_LINK_LOCAL) return &lowpan_context_local;
key.pan = pan;
key.cid = cid;
data = (lowpan_context_data *)g_hash_table_lookup(lowpan_context_table, &key);
if (data) return data;
if (pan != IEEE802154_BCAST_PAN) {
key.pan = IEEE802154_BCAST_PAN;
data = (lowpan_context_data *)g_hash_table_lookup(lowpan_context_table, &key);
if (data) return data;
}
return &lowpan_context_default;
}
void
lowpan_context_insert(guint8 cid, guint16 pan, guint8 plen, struct e_in6_addr *prefix, guint frame)
{
lowpan_context_key key;
lowpan_context_data *data;
gpointer pkey;
gpointer pdata;
if (plen > 128) return;
if (!prefix) return;
if (!lowpan_context_table) return;
key.pan = pan;
key.cid = cid;
if (g_hash_table_lookup_extended(lowpan_context_table, &key, NULL, &pdata)) {
data = (lowpan_context_data *)pdata;
if ( (data->plen == plen) && (memcmp(&data->prefix, prefix, (plen+7)/8) == 0) ) {
return;
}
}
pkey = wmem_memdup(NULL, &key, sizeof(key));
data = wmem_new(NULL, lowpan_context_data);
data->frame = frame;
data->plen = plen;
memset(&data->prefix, 0, sizeof(struct e_in6_addr));
lowpan_pfxcpy(&data->prefix, prefix, plen);
g_hash_table_insert(lowpan_context_table, pkey, data);
}
static void
lowpan_context_free(gpointer data)
{
wmem_free(NULL, data);
}
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
static void
lowpan_addr16_with_panid_to_ifcid(guint16 panid, guint16 addr, guint8 *ifcid)
{
ifcid[0] = (panid >> 8) & 0xfd;
ifcid[1] = (panid >> 0) & 0xff;
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
ieee802154_hints_t *hints;
if (pinfo->dl_src.type == AT_EUI64) {
memcpy(ifcid, pinfo->dl_src.data, LOWPAN_IFC_ID_LEN);
ifcid[0] ^= 0x02;
return TRUE;
}
hints = (ieee802154_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_get_id_by_filter_name(IEEE802154_PROTOABBREV_WPAN), 0);
if (hints) {
if (rfc4944_short_address_format) {
lowpan_addr16_with_panid_to_ifcid(hints->src_pan, hints->src16, ifcid);
} else {
lowpan_addr16_to_ifcid(hints->src16, ifcid);
}
return TRUE;
} else {
memset(ifcid, 0, LOWPAN_IFC_ID_LEN);
return FALSE;
}
}
static gboolean
lowpan_dldst_to_ifcid(packet_info *pinfo, guint8 *ifcid)
{
ieee802154_hints_t *hints;
if (pinfo->dl_dst.type == AT_EUI64) {
memcpy(ifcid, pinfo->dl_dst.data, LOWPAN_IFC_ID_LEN);
ifcid[0] ^= 0x02;
return TRUE;
}
hints = (ieee802154_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_get_id_by_filter_name(IEEE802154_PROTOABBREV_WPAN), 0);
if (hints) {
if (rfc4944_short_address_format) {
lowpan_addr16_with_panid_to_ifcid(hints->src_pan, hints->dst16, ifcid);
} else {
lowpan_addr16_to_ifcid(hints->dst16, ifcid);
}
return TRUE;
} else {
memset(ifcid, 0, LOWPAN_IFC_ID_LEN);
return FALSE;
}
}
static tvbuff_t *
lowpan_reassemble_ipv6(tvbuff_t *tvb, packet_info *pinfo, struct ws_ip6_hdr *ipv6, struct lowpan_nhdr *nhdr_list)
{
gint length = 0;
gint reported = 0;
guint8 * buffer;
guint8 * cursor;
struct lowpan_nhdr *nhdr;
for (nhdr = nhdr_list; nhdr; nhdr = nhdr->next) {
length += nhdr->length;
reported += nhdr->reported;
}
ipv6->ip6h_plen = g_ntohs(reported);
buffer = (guint8 *)wmem_alloc(pinfo->pool, length + IPv6_HDR_SIZE);
memcpy(buffer, ipv6, IPv6_HDR_SIZE);
cursor = buffer + IPv6_HDR_SIZE;
for (nhdr = nhdr_list; nhdr; nhdr = nhdr->next) {
memcpy(cursor, LOWPAN_NHDR_DATA(nhdr), nhdr->length);
cursor += nhdr->length;
};
return tvb_new_child_real_data(tvb, buffer, length + IPv6_HDR_SIZE, reported + IPv6_HDR_SIZE);
}
static guint8
lowpan_parse_nhc_proto(tvbuff_t *tvb, gint offset)
{
if (!tvb_bytes_exist(tvb, offset, 1)) return IP_PROTO_NONE;
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
dissect_6lowpan_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint offset = 0;
for (;;) {
if (!tvb_reported_length_remaining(tvb, offset)) return FALSE;
if (tvb_get_bits8(tvb, offset*8, LOWPAN_PATTERN_IPV6_BITS) == LOWPAN_PATTERN_IPV6) break;
if (tvb_get_bits8(tvb, offset*8, LOWPAN_PATTERN_HC1_BITS) == LOWPAN_PATTERN_HC1) break;
if (tvb_get_bits8(tvb, offset*8, LOWPAN_PATTERN_BC0_BITS) == LOWPAN_PATTERN_BC0) {
offset += 2;
continue;
}
if (tvb_get_bits8(tvb, offset*8, LOWPAN_PATTERN_IPHC_BITS) == LOWPAN_PATTERN_IPHC) break;
if (tvb_get_bits8(tvb, offset*8, LOWPAN_PATTERN_MESH_BITS) == LOWPAN_PATTERN_MESH) {
guint8 mesh = tvb_get_guint8(tvb, offset++);
offset += (mesh & LOWPAN_MESH_HEADER_V) ? 2 : 8;
offset += (mesh & LOWPAN_MESH_HEADER_F) ? 2 : 8;
if ((mesh & LOWPAN_MESH_HEADER_HOPS) == LOWPAN_MESH_HEADER_HOPS) offset++;
continue;
}
if (tvb_get_bits8(tvb, offset*8, LOWPAN_PATTERN_FRAG_BITS) == LOWPAN_PATTERN_FRAG1) {
offset += 4;
continue;
}
if (tvb_get_bits8(tvb, offset*8, LOWPAN_PATTERN_FRAG_BITS) == LOWPAN_PATTERN_FRAGN) break;
return FALSE;
}
dissect_6lowpan(tvb, pinfo, tree, data);
return TRUE;
}
static int
dissect_6lowpan(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *lowpan_tree;
proto_item *lowpan_root;
tvbuff_t *next = tvb;
guint8 src_iid[LOWPAN_IFC_ID_LEN];
guint8 dst_iid[LOWPAN_IFC_ID_LEN];
lowpan_dlsrc_to_ifcid(pinfo, src_iid);
lowpan_dldst_to_ifcid(pinfo, dst_iid);
lowpan_root = proto_tree_add_protocol_format(tree, proto_6lowpan, tvb, 0, -1, "6LoWPAN");
lowpan_tree = proto_item_add_subtree(lowpan_root, ett_6lowpan);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "6LoWPAN");
if (tvb_get_bits8(next, 0, LOWPAN_PATTERN_MESH_BITS) == LOWPAN_PATTERN_MESH) {
next = dissect_6lowpan_mesh(next, pinfo, lowpan_tree, src_iid, dst_iid);
if (!next) return tvb_captured_length(tvb);
}
if (tvb_get_bits8(next, 0, LOWPAN_PATTERN_BC0_BITS) == LOWPAN_PATTERN_BC0) {
next = dissect_6lowpan_bc0(next, pinfo, lowpan_tree);
if (!next) return tvb_captured_length(tvb);
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
}
else if (tvb_get_bits8(next, 0, LOWPAN_PATTERN_IPHC_BITS) == LOWPAN_PATTERN_IPHC) {
next = dissect_6lowpan_iphc(next, pinfo, lowpan_tree, -1, src_iid, dst_iid);
}
else {
dissect_6lowpan_unknown(next, pinfo, lowpan_tree);
return tvb_captured_length(tvb);
}
if (next) {
call_dissector(ipv6_handle, next, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static tvbuff_t *
dissect_6lowpan_ipv6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_bits_item(tree, hf_6lowpan_pattern,
tvb, 0, LOWPAN_PATTERN_IPV6_BITS, ENC_BIG_ENDIAN);
return tvb_new_subset_remaining(tvb, 1);
}
static tvbuff_t *
dissect_6lowpan_hc1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint dgram_size, const guint8 *siid, const guint8 *diid)
{
gint offset = 0;
gint bit_offset;
int i;
guint8 hc1_encoding;
guint8 hc_udp_encoding = 0;
guint8 next_header;
proto_tree * hc_tree;
proto_item * hc_item;
tvbuff_t * ipv6_tvb;
guint8 ipv6_class;
guint32 ipv6_flow;
struct ws_ip6_hdr ipv6;
struct lowpan_nhdr *nhdr_list;
static const int * hc1_encodings[] = {
&hf_6lowpan_hc1_source_prefix,
&hf_6lowpan_hc1_source_ifc,
&hf_6lowpan_hc1_dest_prefix,
&hf_6lowpan_hc1_dest_ifc,
&hf_6lowpan_hc1_class,
&hf_6lowpan_hc1_next,
&hf_6lowpan_hc1_more,
NULL
};
static const int * hc2_encodings[] = {
&hf_6lowpan_hc2_udp_src,
&hf_6lowpan_hc2_udp_dst,
&hf_6lowpan_hc2_udp_len,
NULL
};
hc_tree = proto_tree_add_subtree(tree, tvb, 0, 2, ett_6lowpan_hc1, &hc_item, "HC1 Encoding");
proto_tree_add_bits_item(hc_tree, hf_6lowpan_pattern, tvb, 0, LOWPAN_PATTERN_HC1_BITS, ENC_BIG_ENDIAN);
offset += 1;
hc1_encoding = tvb_get_guint8(tvb, offset);
next_header = ((hc1_encoding & LOWPAN_HC1_NEXT) >> 1);
proto_tree_add_bitmask(hc_tree, tvb, offset, hf_6lowpan_hc1_encoding,
ett_6lowpan_hc1_encoding, hc1_encodings, ENC_NA);
offset += 1;
if (hc1_encoding & LOWPAN_HC1_MORE) {
if (next_header == LOWPAN_HC1_NEXT_UDP) {
hc_udp_encoding = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(tree, tvb, offset, hf_6lowpan_hc2_udp_encoding,
ett_6lowpan_hc2_udp, hc2_encodings, ENC_NA);
offset += 1;
}
else {
expert_add_info(pinfo, hc_item, &ei_6lowpan_hc1_more_bits);
return NULL;
}
}
bit_offset = offset << 3;
ipv6.ip6h_hlim = tvb_get_bits8(tvb, bit_offset, LOWPAN_IPV6_HOP_LIMIT_BITS);
proto_tree_add_uint(tree, hf_6lowpan_hop_limit, tvb, bit_offset>>3,
BITS_TO_BYTE_LEN(bit_offset, LOWPAN_IPV6_HOP_LIMIT_BITS), ipv6.ip6h_hlim);
bit_offset += LOWPAN_IPV6_HOP_LIMIT_BITS;
offset = bit_offset;
if (!(hc1_encoding & LOWPAN_HC1_SOURCE_PREFIX)) {
for (i=0; i<8; i++, bit_offset += 8) {
ipv6.ip6h_src.bytes[i] = tvb_get_bits8(tvb, bit_offset, 8);
}
}
else {
memcpy(ipv6.ip6h_src.bytes, lowpan_llprefix, sizeof(lowpan_llprefix));
}
if (!(hc1_encoding & LOWPAN_HC1_SOURCE_IFC)) {
for (i=8; i<16; i++, bit_offset += 8) {
ipv6.ip6h_src.bytes[i] = tvb_get_bits8(tvb, bit_offset, 8);
}
}
else {
memcpy(&ipv6.ip6h_src.bytes[sizeof(ipv6.ip6h_src) - LOWPAN_IFC_ID_LEN], siid, LOWPAN_IFC_ID_LEN);
}
proto_tree_add_ipv6(tree, hf_6lowpan_source, tvb, offset>>3,
BITS_TO_BYTE_LEN(offset, (bit_offset-offset)), &ipv6.ip6h_src);
offset = bit_offset;
if (!(hc1_encoding & LOWPAN_HC1_DEST_PREFIX)) {
for (i=0; i<8; i++, bit_offset += 8) {
ipv6.ip6h_dst.bytes[i] = tvb_get_bits8(tvb, bit_offset, 8);
}
}
else {
memcpy(ipv6.ip6h_dst.bytes, lowpan_llprefix, sizeof(lowpan_llprefix));
}
if (!(hc1_encoding & LOWPAN_HC1_DEST_IFC)) {
for (i=8; i<16; i++, bit_offset += 8) {
ipv6.ip6h_dst.bytes[i] = tvb_get_bits8(tvb, bit_offset, 8);
}
}
else {
memcpy(&ipv6.ip6h_dst.bytes[sizeof(ipv6.ip6h_dst) - LOWPAN_IFC_ID_LEN], diid, LOWPAN_IFC_ID_LEN);
}
proto_tree_add_ipv6(tree, hf_6lowpan_dest, tvb, offset>>3,
BITS_TO_BYTE_LEN(offset, (bit_offset-offset)), &ipv6.ip6h_dst);
ipv6_class = 0;
ipv6_flow = 0;
if (!(hc1_encoding & LOWPAN_HC1_TRAFFIC_CLASS)) {
ipv6_class = tvb_get_bits8(tvb, bit_offset, LOWPAN_IPV6_TRAFFIC_CLASS_BITS);
proto_tree_add_uint(tree, hf_6lowpan_traffic_class, tvb, bit_offset>>3,
BITS_TO_BYTE_LEN(bit_offset, LOWPAN_IPV6_TRAFFIC_CLASS_BITS), ipv6_class);
bit_offset += LOWPAN_IPV6_TRAFFIC_CLASS_BITS;
ipv6_flow = tvb_get_bits32(tvb, bit_offset, LOWPAN_IPV6_FLOW_LABEL_BITS, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_6lowpan_flow_label, tvb, bit_offset>>3,
BITS_TO_BYTE_LEN(bit_offset, LOWPAN_IPV6_FLOW_LABEL_BITS), ipv6_flow);
bit_offset += LOWPAN_IPV6_FLOW_LABEL_BITS;
}
ipv6.ip6h_vc_flow = ipv6_flow;
ipv6.ip6h_vc_flow |= ((guint32)ipv6_class << LOWPAN_IPV6_FLOW_LABEL_BITS);
ipv6.ip6h_vc_flow |= ((guint32)0x6 << (LOWPAN_IPV6_TRAFFIC_CLASS_BITS + LOWPAN_IPV6_FLOW_LABEL_BITS));
ipv6.ip6h_vc_flow = g_ntohl(ipv6.ip6h_vc_flow);
if (next_header == LOWPAN_HC1_NEXT_UDP) {
ipv6.ip6h_nxt = IP_PROTO_UDP;
}
else if (next_header == LOWPAN_HC1_NEXT_ICMP) {
ipv6.ip6h_nxt = IP_PROTO_ICMPV6;
}
else if (next_header == LOWPAN_HC1_NEXT_TCP) {
ipv6.ip6h_nxt = IP_PROTO_TCP;
}
else {
ipv6.ip6h_nxt = tvb_get_bits8(tvb, bit_offset, LOWPAN_IPV6_NEXT_HEADER_BITS);
proto_tree_add_uint_format_value(tree, hf_6lowpan_next_header, tvb, bit_offset>>3,
BITS_TO_BYTE_LEN(bit_offset, LOWPAN_IPV6_NEXT_HEADER_BITS), ipv6.ip6h_nxt,
"%s (0x%02x)", ipprotostr(ipv6.ip6h_nxt), ipv6.ip6h_nxt);
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
proto_tree_add_uint(tree, hf_6lowpan_udp_src, tvb, offset>>3,
BITS_TO_BYTE_LEN(offset, (bit_offset-offset)), udp.src_port);
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
proto_tree_add_uint(tree, hf_6lowpan_udp_dst, tvb, offset>>3,
BITS_TO_BYTE_LEN(offset, (bit_offset-offset)), udp.dst_port);
udp.dst_port = g_ntohs(udp.dst_port);
if (!(hc_udp_encoding & LOWPAN_HC2_UDP_LENGTH)) {
udp.length = tvb_get_bits16(tvb, bit_offset, LOWPAN_UDP_LENGTH_BITS, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_6lowpan_udp_len, tvb, bit_offset>>3,
BITS_TO_BYTE_LEN(bit_offset, LOWPAN_UDP_LENGTH_BITS), udp.length);
bit_offset += LOWPAN_UDP_LENGTH_BITS;
}
else if (dgram_size >= 0) {
if (dgram_size < IPv6_HDR_SIZE) {
return NULL;
}
udp.length = dgram_size - IPv6_HDR_SIZE;
}
else {
udp.length = tvb_reported_length(tvb);
udp.length -= BITS_TO_BYTE_LEN(0, bit_offset + LOWPAN_UDP_CHECKSUM_BITS);
udp.length += (int)sizeof(struct udp_hdr);
}
udp.length = g_ntohs(udp.length);
udp.checksum = tvb_get_bits16(tvb, bit_offset, LOWPAN_UDP_CHECKSUM_BITS, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_6lowpan_udp_checksum, tvb, bit_offset>>3,
BITS_TO_BYTE_LEN(bit_offset, LOWPAN_UDP_CHECKSUM_BITS), udp.checksum);
bit_offset += LOWPAN_UDP_CHECKSUM_BITS;
udp.checksum = g_ntohs(udp.checksum);
offset = BITS_TO_BYTE_LEN(0, bit_offset);
length = (gint)tvb_ensure_captured_length_remaining(tvb, offset);
nhdr_list = (struct lowpan_nhdr *)wmem_alloc(wmem_packet_scope(), sizeof(struct lowpan_nhdr) + sizeof(struct udp_hdr) + length);
nhdr_list->next = NULL;
nhdr_list->proto = IP_PROTO_UDP;
nhdr_list->length = length + (int)sizeof(struct udp_hdr);
nhdr_list->reported = g_ntohs(udp.length);
memcpy(LOWPAN_NHDR_DATA(nhdr_list), &udp, sizeof(struct udp_hdr));
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr_list) + sizeof(struct udp_hdr), offset, length);
}
else {
gint length;
offset = BITS_TO_BYTE_LEN(0, bit_offset);
length = (gint)tvb_ensure_captured_length_remaining(tvb, offset);
nhdr_list = (struct lowpan_nhdr *)wmem_alloc(wmem_packet_scope(), sizeof(struct lowpan_nhdr) + length);
nhdr_list->next = NULL;
nhdr_list->proto = ipv6.ip6h_nxt;
nhdr_list->length = length;
if (dgram_size < 0) {
nhdr_list->reported = tvb_reported_length_remaining(tvb, offset);
}
else {
nhdr_list->reported = dgram_size - IPv6_HDR_SIZE;
}
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr_list), offset, nhdr_list->length);
}
ipv6_tvb = lowpan_reassemble_ipv6(tvb, pinfo, &ipv6, nhdr_list);
add_new_data_source(pinfo, ipv6_tvb, "Decompressed 6LoWPAN HC1");
return ipv6_tvb;
}
static tvbuff_t *
dissect_6lowpan_iphc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint dgram_size, const guint8 *siid, const guint8 *diid)
{
ieee802154_hints_t *hints;
guint16 hint_panid;
gint offset = 0;
gint length = 0;
proto_tree * iphc_tree;
proto_item * ti_dam = NULL;
guint16 iphc_flags;
guint8 iphc_traffic;
guint8 iphc_hop_limit;
guint8 iphc_src_mode;
guint8 iphc_dst_mode;
guint8 iphc_ctx = 0;
gint iphc_sci = LOWPAN_CONTEXT_DEFAULT;
gint iphc_dci = LOWPAN_CONTEXT_DEFAULT;
lowpan_context_data *sctx;
lowpan_context_data *dctx;
guint8 ipv6_dscp = 0;
guint8 ipv6_ecn = 0;
guint32 ipv6_flowlabel = 0;
struct ws_ip6_hdr ipv6;
tvbuff_t * ipv6_tvb;
struct lowpan_nhdr *nhdr_list;
hints = (ieee802154_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_get_id_by_filter_name(IEEE802154_PROTOABBREV_WPAN), 0);
hint_panid = (hints) ? (hints->src_pan) : (IEEE802154_BCAST_PAN);
iphc_tree = proto_tree_add_subtree(tree, tvb, 0, 2, ett_6lowpan_iphc, NULL, "IPHC Header");
proto_tree_add_bits_item(iphc_tree, hf_6lowpan_pattern, tvb, 0, LOWPAN_PATTERN_IPHC_BITS, ENC_BIG_ENDIAN);
iphc_flags = tvb_get_ntohs(tvb, offset);
iphc_traffic = (iphc_flags & LOWPAN_IPHC_FLAG_FLOW) >> LOWPAN_IPHC_FLAG_OFFSET_FLOW;
iphc_hop_limit = (iphc_flags & LOWPAN_IPHC_FLAG_HLIM) >> LOWPAN_IPHC_FLAG_OFFSET_HLIM;
iphc_src_mode = (iphc_flags & LOWPAN_IPHC_FLAG_SRC_MODE) >> LOWPAN_IPHC_FLAG_OFFSET_SRC_MODE;
iphc_dst_mode = (iphc_flags & LOWPAN_IPHC_FLAG_DST_MODE) >> LOWPAN_IPHC_FLAG_OFFSET_DST_MODE;
if (tree) {
const value_string *am_vs;
proto_tree_add_uint (iphc_tree, hf_6lowpan_iphc_flag_tf, tvb, offset, 2, iphc_flags & LOWPAN_IPHC_FLAG_FLOW);
proto_tree_add_boolean (iphc_tree, hf_6lowpan_iphc_flag_nhdr, tvb, offset, 2, iphc_flags & LOWPAN_IPHC_FLAG_NHDR);
proto_tree_add_uint (iphc_tree, hf_6lowpan_iphc_flag_hlim, tvb, offset, 2, iphc_flags & LOWPAN_IPHC_FLAG_HLIM);
proto_tree_add_boolean (iphc_tree, hf_6lowpan_iphc_flag_cid, tvb, offset, 2, iphc_flags & LOWPAN_IPHC_FLAG_CONTEXT_ID);
proto_tree_add_boolean (iphc_tree, hf_6lowpan_iphc_flag_sac, tvb, offset, 2, iphc_flags & LOWPAN_IPHC_FLAG_SRC_COMP);
am_vs = iphc_flags & LOWPAN_IPHC_FLAG_SRC_COMP ? lowpan_iphc_saddr_stateful_modes : lowpan_iphc_addr_modes;
proto_tree_add_uint_format_value(iphc_tree, hf_6lowpan_iphc_flag_sam, tvb, offset, 2, iphc_flags & LOWPAN_IPHC_FLAG_SRC_MODE,
"%s (0x%04x)", val_to_str_const(iphc_src_mode, am_vs, "Reserved"), iphc_src_mode);
proto_tree_add_boolean (iphc_tree, hf_6lowpan_iphc_flag_mcast, tvb, offset, 2, iphc_flags & LOWPAN_IPHC_FLAG_MCAST_COMP);
proto_tree_add_boolean (iphc_tree, hf_6lowpan_iphc_flag_dac, tvb, offset, 2, iphc_flags & LOWPAN_IPHC_FLAG_DST_COMP);
if (iphc_flags & LOWPAN_IPHC_FLAG_MCAST_COMP) {
if (iphc_flags & LOWPAN_IPHC_FLAG_DST_COMP) {
am_vs = lowpan_iphc_mcast_stateful_modes;
} else {
am_vs = lowpan_iphc_mcast_modes;
}
} else {
if (iphc_flags & LOWPAN_IPHC_FLAG_DST_COMP) {
am_vs = lowpan_iphc_daddr_stateful_modes;
} else {
am_vs = lowpan_iphc_addr_modes;
}
}
ti_dam = proto_tree_add_uint_format_value(iphc_tree, hf_6lowpan_iphc_flag_dam, tvb, offset, 2,
iphc_flags & LOWPAN_IPHC_FLAG_DST_MODE, "%s (0x%04x)", val_to_str_const(iphc_dst_mode, am_vs, "Reserved"), iphc_dst_mode);
}
offset += 2;
if (iphc_flags & LOWPAN_IPHC_FLAG_CONTEXT_ID) {
iphc_ctx = tvb_get_guint8(tvb, offset);
iphc_sci = (iphc_ctx & LOWPAN_IPHC_FLAG_SCI) >> LOWPAN_IPHC_FLAG_OFFSET_SCI;
iphc_dci = (iphc_ctx & LOWPAN_IPHC_FLAG_DCI) >> LOWPAN_IPHC_FLAG_OFFSET_DCI;
proto_tree_add_uint(iphc_tree, hf_6lowpan_iphc_sci, tvb, offset, 1, iphc_ctx & LOWPAN_IPHC_FLAG_SCI);
proto_tree_add_uint(iphc_tree, hf_6lowpan_iphc_dci, tvb, offset, 1, iphc_ctx & LOWPAN_IPHC_FLAG_DCI);
offset += 1;
}
if (!(iphc_flags & LOWPAN_IPHC_FLAG_SRC_COMP)) {
iphc_sci = LOWPAN_CONTEXT_LINK_LOCAL;
}
if (!(iphc_flags & LOWPAN_IPHC_FLAG_DST_COMP)) {
iphc_dci = LOWPAN_CONTEXT_LINK_LOCAL;
}
sctx = lowpan_context_find(iphc_sci, hint_panid);
dctx = lowpan_context_find(iphc_dci, hint_panid);
offset <<= 3;
if (iphc_traffic != LOWPAN_IPHC_FLOW_COMPRESSED) {
ipv6_ecn = tvb_get_bits8(tvb, offset, LOWPAN_IPHC_ECN_BITS);
proto_tree_add_bits_item(tree, hf_6lowpan_ecn, tvb, offset, LOWPAN_IPHC_ECN_BITS, ENC_BIG_ENDIAN);
offset += LOWPAN_IPHC_ECN_BITS;
}
if ((iphc_traffic == LOWPAN_IPHC_FLOW_CLASS_LABEL) || (iphc_traffic == LOWPAN_IPHC_FLOW_CLASS)) {
ipv6_dscp = tvb_get_bits8(tvb, offset, LOWPAN_IPHC_DSCP_BITS);
proto_tree_add_bits_item(tree, hf_6lowpan_dscp, tvb, offset, LOWPAN_IPHC_DSCP_BITS, LOWPAN_IPHC_DSCP_BITS);
offset += LOWPAN_IPHC_DSCP_BITS;
}
if (ipv6_dscp || ipv6_ecn) {
proto_item *tclass_item;
tclass_item = proto_tree_add_uint(tree, hf_6lowpan_traffic_class, tvb, 0, 0,
(ipv6_dscp << LOWPAN_IPHC_ECN_BITS) | ipv6_ecn);
PROTO_ITEM_SET_GENERATED(tclass_item);
}
if ((iphc_traffic == LOWPAN_IPHC_FLOW_CLASS_LABEL) || (iphc_traffic == LOWPAN_IPHC_FLOW_ECN_LABEL)) {
guint pad_bits = ((4 - offset) & 0x7);
if (pad_bits) {
proto_tree_add_bits_item(tree, hf_6lowpan_padding, tvb, offset, pad_bits, ENC_BIG_ENDIAN);
}
offset += pad_bits;
ipv6_flowlabel = tvb_get_bits32(tvb, offset, LOWPAN_IPHC_LABEL_BITS, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_6lowpan_flow_label, tvb, offset, LOWPAN_IPHC_LABEL_BITS, ENC_BIG_ENDIAN);
offset += LOWPAN_IPHC_LABEL_BITS;
}
ipv6.ip6h_vc_flow = ipv6_flowlabel;
ipv6.ip6h_vc_flow |= ((guint32)ipv6_ecn << LOWPAN_IPV6_FLOW_LABEL_BITS);
ipv6.ip6h_vc_flow |= ((guint32)ipv6_dscp << (LOWPAN_IPHC_ECN_BITS + LOWPAN_IPV6_FLOW_LABEL_BITS));
ipv6.ip6h_vc_flow |= ((guint32)0x6 << (LOWPAN_IPV6_TRAFFIC_CLASS_BITS + LOWPAN_IPV6_FLOW_LABEL_BITS));
ipv6.ip6h_vc_flow = g_ntohl(ipv6.ip6h_vc_flow);
offset >>= 3;
if (!(iphc_flags & LOWPAN_IPHC_FLAG_NHDR)) {
ipv6.ip6h_nxt = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_6lowpan_next_header, tvb, offset, 1, ipv6.ip6h_nxt,
"%s (0x%02x)", ipprotostr(ipv6.ip6h_nxt), ipv6.ip6h_nxt);
offset += 1;
}
if (iphc_hop_limit == LOWPAN_IPHC_HLIM_1) {
ipv6.ip6h_hlim = 1;
}
else if (iphc_hop_limit == LOWPAN_IPHC_HLIM_64) {
ipv6.ip6h_hlim = 64;
}
else if (iphc_hop_limit == LOWPAN_IPHC_HLIM_255) {
ipv6.ip6h_hlim = 255;
}
else {
ipv6.ip6h_hlim = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_6lowpan_hop_limit, tvb, offset, 1, ipv6.ip6h_hlim);
offset += 1;
}
length = 0;
memset(&ipv6.ip6h_src, 0, sizeof(ipv6.ip6h_src));
if ((iphc_flags & LOWPAN_IPHC_FLAG_SRC_COMP) && (iphc_src_mode == LOWPAN_IPHC_ADDR_SRC_UNSPEC)) {
sctx = &lowpan_context_default;
}
else if (iphc_src_mode == LOWPAN_IPHC_ADDR_COMPRESSED) {
memcpy(&ipv6.ip6h_src.bytes[sizeof(ipv6.ip6h_src) - LOWPAN_IFC_ID_LEN], siid, LOWPAN_IFC_ID_LEN);
}
else if (iphc_src_mode == LOWPAN_IPHC_ADDR_FULL_INLINE) {
if (!(iphc_flags & LOWPAN_IPHC_FLAG_SRC_COMP)) sctx = &lowpan_context_default;
length = (int)sizeof(ipv6.ip6h_src);
tvb_memcpy(tvb, &ipv6.ip6h_src, offset, length);
}
else if (iphc_src_mode == LOWPAN_IPHC_ADDR_64BIT_INLINE) {
length = 8;
tvb_memcpy(tvb, &ipv6.ip6h_src.bytes[sizeof(ipv6.ip6h_src) - length], offset, length);
}
else if (iphc_src_mode == LOWPAN_IPHC_ADDR_16BIT_INLINE) {
length = 2;
ipv6.ip6h_src.bytes[11] = 0xff;
ipv6.ip6h_src.bytes[12] = 0xfe;
tvb_memcpy(tvb, &ipv6.ip6h_src.bytes[sizeof(ipv6.ip6h_src) - length], offset, length);
}
lowpan_pfxcpy(&ipv6.ip6h_src, &sctx->prefix, sctx->plen);
siid = &ipv6.ip6h_src.bytes[sizeof(ipv6.ip6h_src) - LOWPAN_IFC_ID_LEN];
proto_tree_add_ipv6(tree, hf_6lowpan_source, tvb, offset, length, &ipv6.ip6h_src);
if (sctx->plen) {
proto_item *ti;
ti = proto_tree_add_ipv6(iphc_tree, hf_6lowpan_iphc_sctx_prefix, tvb, 0, 0, &sctx->prefix);
PROTO_ITEM_SET_GENERATED(ti);
if ( sctx->frame ) {
ti = proto_tree_add_uint(iphc_tree, hf_6lowpan_iphc_sctx_origin, tvb, 0, 0, sctx->frame);
PROTO_ITEM_SET_GENERATED(ti);
}
}
offset += length;
length = 0;
memset(&ipv6.ip6h_dst, 0, sizeof(ipv6.ip6h_dst));
if ((iphc_flags & LOWPAN_IPHC_FLAG_MCAST_COMP) && !(iphc_flags & LOWPAN_IPHC_FLAG_DST_COMP)) {
if (iphc_dst_mode == LOWPAN_IPHC_ADDR_FULL_INLINE) {
length = (int)sizeof(ipv6.ip6h_dst);
tvb_memcpy(tvb, &ipv6.ip6h_dst.bytes[sizeof(ipv6.ip6h_dst) - length], offset, length);
}
else if (iphc_dst_mode == LOWPAN_IPHC_MCAST_48BIT) {
ipv6.ip6h_dst.bytes[0] = 0xff;
ipv6.ip6h_dst.bytes[1] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[11] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[12] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[13] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[14] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[15] = tvb_get_guint8(tvb, offset + (length++));
}
else if (iphc_dst_mode == LOWPAN_IPHC_MCAST_32BIT) {
ipv6.ip6h_dst.bytes[0] = 0xff;
ipv6.ip6h_dst.bytes[1] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[13] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[14] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[15] = tvb_get_guint8(tvb, offset + (length++));
}
else if (iphc_dst_mode == LOWPAN_IPHC_MCAST_8BIT) {
ipv6.ip6h_dst.bytes[0] = 0xff;
ipv6.ip6h_dst.bytes[1] = 0x02;
ipv6.ip6h_dst.bytes[15] = tvb_get_guint8(tvb, offset + (length++));
}
else {
expert_add_info(pinfo, ti_dam, &ei_6lowpan_illegal_dest_addr_mode);
return NULL;
}
}
else if ((iphc_flags & LOWPAN_IPHC_FLAG_MCAST_COMP) && (iphc_flags & LOWPAN_IPHC_FLAG_DST_COMP)) {
if (iphc_dst_mode == LOWPAN_IPHC_MCAST_STATEFUL_48BIT) {
ipv6.ip6h_dst.bytes[0] = 0xff;
ipv6.ip6h_dst.bytes[1] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[2] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[3] = (dctx->plen > 64) ? (64) : (dctx->plen);
memcpy(&ipv6.ip6h_dst.bytes[4], &dctx->prefix, 8);
ipv6.ip6h_dst.bytes[12] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[13] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[14] = tvb_get_guint8(tvb, offset + (length++));
ipv6.ip6h_dst.bytes[15] = tvb_get_guint8(tvb, offset + (length++));
}
else {
expert_add_info(pinfo, ti_dam, &ei_6lowpan_illegal_dest_addr_mode);
return NULL;
}
}
else {
if ((iphc_flags & LOWPAN_IPHC_FLAG_DST_COMP) && (iphc_dst_mode == LOWPAN_IPHC_ADDR_FULL_INLINE)) {
expert_add_info(pinfo, ti_dam, &ei_6lowpan_illegal_dest_addr_mode);
return NULL;
}
else if (iphc_dst_mode == LOWPAN_IPHC_ADDR_COMPRESSED) {
memcpy(&ipv6.ip6h_dst.bytes[sizeof(ipv6.ip6h_dst) - LOWPAN_IFC_ID_LEN], diid, LOWPAN_IFC_ID_LEN);
}
else if (iphc_dst_mode == LOWPAN_IPHC_ADDR_FULL_INLINE) {
dctx = &lowpan_context_default;
length = (int)sizeof(ipv6.ip6h_dst);
tvb_memcpy(tvb, &ipv6.ip6h_dst, offset, length);
}
else if (iphc_dst_mode == LOWPAN_IPHC_ADDR_64BIT_INLINE) {
length = 8;
tvb_memcpy(tvb, &ipv6.ip6h_dst.bytes[sizeof(ipv6.ip6h_dst) - length], offset, length);
}
else if (iphc_dst_mode == LOWPAN_IPHC_ADDR_16BIT_INLINE) {
length = 2;
ipv6.ip6h_dst.bytes[11] = 0xff;
ipv6.ip6h_dst.bytes[12] = 0xfe;
tvb_memcpy(tvb, &ipv6.ip6h_dst.bytes[sizeof(ipv6.ip6h_dst) - length], offset, length);
}
lowpan_pfxcpy(&ipv6.ip6h_dst, &dctx->prefix, dctx->plen);
diid = &ipv6.ip6h_dst.bytes[sizeof(ipv6.ip6h_dst) - LOWPAN_IFC_ID_LEN];
}
proto_tree_add_ipv6(tree, hf_6lowpan_dest, tvb, offset, length, &ipv6.ip6h_dst);
if (dctx->plen) {
proto_item *ti;
ti = proto_tree_add_ipv6(iphc_tree, hf_6lowpan_iphc_dctx_prefix, tvb, 0, 0, &dctx->prefix);
PROTO_ITEM_SET_GENERATED(ti);
if ( dctx->frame ) {
ti = proto_tree_add_uint(iphc_tree, hf_6lowpan_iphc_dctx_origin, tvb, 0, 0, dctx->frame);
PROTO_ITEM_SET_GENERATED(ti);
}
}
offset += length;
if (iphc_flags & LOWPAN_IPHC_FLAG_NHDR) {
ipv6.ip6h_nxt = lowpan_parse_nhc_proto(tvb, offset);
nhdr_list = dissect_6lowpan_iphc_nhc(tvb, pinfo, tree, offset, dgram_size - IPv6_HDR_SIZE, siid, diid);
}
else {
length = (gint)tvb_ensure_captured_length_remaining(tvb, offset);
nhdr_list = (struct lowpan_nhdr *)wmem_alloc(wmem_packet_scope(), sizeof(struct lowpan_nhdr) + length);
nhdr_list->next = NULL;
nhdr_list->proto = ipv6.ip6h_nxt;
nhdr_list->length = length;
if (dgram_size < 0) {
nhdr_list->reported = tvb_reported_length_remaining(tvb, offset);
}
else {
nhdr_list->reported = dgram_size - IPv6_HDR_SIZE;
}
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr_list), offset, nhdr_list->length);
}
ipv6_tvb = lowpan_reassemble_ipv6(tvb, pinfo, &ipv6, nhdr_list);
add_new_data_source(pinfo, ipv6_tvb, "Decompressed 6LoWPAN IPHC");
return ipv6_tvb;
}
static struct lowpan_nhdr *
dissect_6lowpan_iphc_nhc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, gint dgram_size, const guint8 *siid, const guint8 *diid)
{
gint length;
proto_item * ti = NULL;
proto_tree * nhc_tree = NULL;
struct lowpan_nhdr *nhdr;
if (tvb_get_bits8(tvb, offset<<3, LOWPAN_NHC_PATTERN_EXT_IPV6_BITS) == LOWPAN_NHC_PATTERN_EXT_IPV6) {
guint8 ext_flags;
tvbuff_t *iphc_tvb;
nhc_tree = proto_tree_add_subtree(tree, tvb, offset, 2, ett_6lowpan_nhc_ext, &ti, "IPv6 extension header");
proto_tree_add_bits_item(nhc_tree, hf_6lowpan_nhc_pattern, tvb, offset<<3, LOWPAN_NHC_PATTERN_EXT_BITS, ENC_BIG_ENDIAN);
ext_flags = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(nhc_tree, hf_6lowpan_nhc_ext_eid, tvb, offset, 1, ext_flags & LOWPAN_NHC_EXT_EID);
proto_tree_add_boolean(nhc_tree, hf_6lowpan_nhc_ext_nh, tvb, offset, 1, ext_flags & LOWPAN_NHC_EXT_NHDR);
if (ext_flags & LOWPAN_NHC_EXT_NHDR) {
}
offset += 1;
iphc_tvb = dissect_6lowpan_iphc(tvb_new_subset_remaining(tvb, offset), pinfo, tree, dgram_size, siid, diid);
if (!iphc_tvb) return NULL;
nhdr = (struct lowpan_nhdr *)wmem_alloc0(wmem_packet_scope(), sizeof(struct lowpan_nhdr) + tvb_captured_length(iphc_tvb));
nhdr->next = NULL;
nhdr->proto = IP_PROTO_IPV6;
nhdr->length = tvb_captured_length(iphc_tvb);
nhdr->reported = tvb_reported_length(iphc_tvb);
tvb_memcpy(iphc_tvb, LOWPAN_NHDR_DATA(nhdr), 0, nhdr->length);
return nhdr;
}
if (tvb_get_bits8(tvb, offset<<3, LOWPAN_NHC_PATTERN_EXT_BITS) == LOWPAN_NHC_PATTERN_EXT) {
struct ip6_ext ipv6_ext = {0, 0};
guint8 ext_flags;
guint8 ext_hlen;
guint8 ext_len;
guint8 ext_proto;
proto_item *ti_ext_len = NULL;
ext_proto = lowpan_parse_nhc_proto(tvb, offset);
nhc_tree = proto_tree_add_subtree(tree, tvb, offset, 2, ett_6lowpan_nhc_ext, NULL, "IPv6 extension header");
proto_tree_add_bits_item(nhc_tree, hf_6lowpan_nhc_pattern, tvb, offset<<3, LOWPAN_NHC_PATTERN_EXT_BITS, ENC_BIG_ENDIAN);
ext_flags = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(nhc_tree, hf_6lowpan_nhc_ext_eid, tvb, offset, 1, ext_flags & LOWPAN_NHC_EXT_EID);
proto_tree_add_boolean(nhc_tree, hf_6lowpan_nhc_ext_nh, tvb, offset, 1, ext_flags & LOWPAN_NHC_EXT_NHDR);
offset += 1;
if (!(ext_flags & LOWPAN_NHC_EXT_NHDR)) {
ipv6_ext.ip6e_nxt = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(nhc_tree, hf_6lowpan_nhc_ext_next, tvb, offset, 1, ipv6_ext.ip6e_nxt,
"%s (0x%02x)", ipprotostr(ipv6_ext.ip6e_nxt), ipv6_ext.ip6e_nxt);
proto_item_set_end(ti, tvb, offset+1);
offset += 1;
}
if (ext_proto == IP_PROTO_FRAGMENT) {
ext_hlen = 1;
length = (guint8)sizeof(struct ip6_frag);
ext_len = length - ext_hlen;
proto_tree_add_item(nhc_tree, hf_6lowpan_nhc_ext_reserved, tvb, offset, 1, ENC_NA);
} else {
ext_hlen = (guint8)sizeof(struct ip6_ext);
ext_len = tvb_get_guint8(tvb, offset);
ti_ext_len = proto_tree_add_uint(nhc_tree, hf_6lowpan_nhc_ext_length, tvb, offset, 1, ext_len);
offset += 1;
length = ext_hlen + ext_len;
length = (length + 7) & ~0x7;
ipv6_ext.ip6e_len = length>>3;
ipv6_ext.ip6e_len -= 1;
}
nhdr = (struct lowpan_nhdr *)wmem_alloc0(wmem_packet_scope(), sizeof(struct lowpan_nhdr) + length);
nhdr->next = NULL;
nhdr->proto = ext_proto;
nhdr->length = length;
nhdr->reported = length;
if (ext_flags & LOWPAN_NHC_EXT_NHDR) {
ipv6_ext.ip6e_nxt = lowpan_parse_nhc_proto(tvb, offset+ext_len);
}
memcpy(LOWPAN_NHDR_DATA(nhdr), &ipv6_ext, ext_hlen);
if (!tvb_bytes_exist(tvb, offset, ext_len)) {
call_data_dissector(tvb_new_subset_remaining(tvb, offset), pinfo, nhc_tree);
nhdr->length = tvb_captured_length_remaining(tvb, offset) + ext_hlen;
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr) + ext_hlen, offset, tvb_captured_length_remaining(tvb, offset));
return nhdr;
}
if (ext_proto == IP_PROTO_FRAGMENT) {
call_data_dissector(tvb_new_subset_length(tvb, offset+1, ext_len-1), pinfo, nhc_tree);
} else {
call_data_dissector(tvb_new_subset_length(tvb, offset, ext_len), pinfo, nhc_tree);
}
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr) + ext_hlen, offset, ext_len);
offset += ext_len;
if (length > ext_hlen + ext_len) {
guint8 padding = length - (ext_hlen + ext_len);
guint8 *pad_ptr = LOWPAN_NHDR_DATA(nhdr) + ext_hlen + ext_len;
if (ext_proto != IP_PROTO_HOPOPTS && ext_proto != IP_PROTO_DSTOPTS) {
expert_add_info(pinfo, ti_ext_len, &ei_6lowpan_bad_ext_header_length);
}
if (padding == 1) {
pad_ptr[0] = IP6OPT_PAD1;
} else {
pad_ptr[0] = IP6OPT_PADN;
pad_ptr[1] = padding - 2;
}
}
if (ext_flags & LOWPAN_NHC_EXT_NHDR) {
nhdr->next = dissect_6lowpan_iphc_nhc(tvb, pinfo, tree, offset, dgram_size - nhdr->reported, siid, diid);
}
else if (ipv6_ext.ip6e_nxt != IP_PROTO_NONE) {
length = (gint)tvb_ensure_captured_length_remaining(tvb, offset);
nhdr->next = (struct lowpan_nhdr *)wmem_alloc(wmem_packet_scope(), sizeof(struct lowpan_nhdr) + length);
nhdr->next->next = NULL;
nhdr->next->proto = ipv6_ext.ip6e_nxt;
nhdr->next->length = length;
if (dgram_size < 0) {
nhdr->next->reported = tvb_reported_length_remaining(tvb, offset);
}
else {
nhdr->next->reported = dgram_size - nhdr->reported;
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
guint16 udp_src_port, udp_dst_port;
nhc_tree = proto_tree_add_subtree(tree, tvb, 0, 1, ett_6lowpan_nhc_udp, NULL, "UDP header compression");
proto_tree_add_bits_item(nhc_tree, hf_6lowpan_nhc_pattern, tvb, offset<<3, LOWPAN_NHC_PATTERN_UDP_BITS, ENC_BIG_ENDIAN);
proto_tree_add_item(nhc_tree, hf_6lowpan_nhc_udp_checksum, tvb, offset, 1, ENC_NA);
proto_tree_add_item(nhc_tree, hf_6lowpan_nhc_udp_ports, tvb, offset, 1, ENC_NA);
udp_flags = tvb_get_guint8(tvb, offset);
offset += 1;
switch (udp_flags & LOWPAN_NHC_UDP_PORTS) {
case LOWPAN_NHC_UDP_PORT_INLINE:
udp_src_port = tvb_get_ntohs(tvb, offset);
udp_dst_port = tvb_get_ntohs(tvb, offset+2);
src_bitlen = 16;
dst_bitlen = 16;
break;
case LOWPAN_NHC_UDP_PORT_8BIT_DST:
udp_src_port = tvb_get_ntohs(tvb, offset);
udp_dst_port = LOWPAN_PORT_8BIT_OFFSET + tvb_get_guint8(tvb, offset + 2);
src_bitlen = 16;
dst_bitlen = 8;
break;
case LOWPAN_NHC_UDP_PORT_8BIT_SRC:
udp_src_port = LOWPAN_PORT_8BIT_OFFSET + tvb_get_guint8(tvb, offset);
udp_dst_port = tvb_get_ntohs(tvb, offset + 1);
src_bitlen = 8;
dst_bitlen = 16;
break;
case LOWPAN_NHC_UDP_PORT_12BIT:
udp_src_port = LOWPAN_PORT_12BIT_OFFSET + (tvb_get_guint8(tvb, offset) >> 4);
udp_dst_port = LOWPAN_PORT_12BIT_OFFSET + (tvb_get_guint8(tvb, offset) & 0x0f);
src_bitlen = 4;
dst_bitlen = 4;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
proto_tree_add_uint(tree, hf_6lowpan_udp_src, tvb, offset, BITS_TO_BYTE_LEN(offset<<3, src_bitlen), udp_src_port);
proto_tree_add_uint(tree, hf_6lowpan_udp_dst, tvb, offset+(src_bitlen>>3), BITS_TO_BYTE_LEN((offset<<3)+src_bitlen, dst_bitlen), udp_dst_port);
offset += ((src_bitlen + dst_bitlen)>>3);
udp.src_port = g_htons(udp_src_port);
udp.dst_port = g_htons(udp_dst_port);
if (!(udp_flags & LOWPAN_NHC_UDP_CHECKSUM)) {
tvb_memcpy(tvb, &udp.checksum, offset, sizeof(udp.checksum));
proto_tree_add_checksum(tree, tvb, offset, hf_6lowpan_udp_checksum, -1, NULL, pinfo, 0, ENC_BIG_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
offset += 2;
}
else {
udp.checksum = 0;
}
if (dgram_size < 0) {
length = tvb_reported_length_remaining(tvb, offset);
udp.length = g_htons(length + (int)sizeof(struct udp_hdr));
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
cksum_phdr.length = g_htonl(length + (int)sizeof(struct udp_hdr));
memset(cksum_phdr.zero, 0, sizeof(cksum_phdr.zero));
cksum_phdr.proto = IP_PROTO_UDP;
SET_CKSUM_VEC_PTR(cksum_vec[0], (const guint8 *)&cksum_phdr, sizeof(cksum_phdr));
SET_CKSUM_VEC_PTR(cksum_vec[1], (const guint8 *)&udp, sizeof(struct udp_hdr));
SET_CKSUM_VEC_TVB(cksum_vec[2], tvb, offset, length);
udp.checksum = in_cksum(cksum_vec, 3);
if (udp.checksum == 0) udp.checksum = 0xffff;
}
#endif
length = (gint)tvb_ensure_captured_length_remaining(tvb, offset);
nhdr = (struct lowpan_nhdr *)wmem_alloc(wmem_packet_scope(), sizeof(struct lowpan_nhdr) + sizeof(struct udp_hdr) + length);
nhdr->next = NULL;
nhdr->proto = IP_PROTO_UDP;
nhdr->length = length + (int)sizeof(struct udp_hdr);
nhdr->reported = g_ntohs(udp.length);
memcpy(LOWPAN_NHDR_DATA(nhdr), &udp, sizeof(struct udp_hdr));
tvb_memcpy(tvb, LOWPAN_NHDR_DATA(nhdr) + sizeof(struct udp_hdr), offset, tvb_captured_length_remaining(tvb, offset));
return nhdr;
}
return NULL;
}
static tvbuff_t *
dissect_6lowpan_bc0(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 seqnum;
proto_tree * bcast_tree;
bcast_tree = proto_tree_add_subtree(tree, tvb, 0, 2, ett_6lowpan_bcast, NULL, "Broadcast Header");
proto_tree_add_bits_item(bcast_tree, hf_6lowpan_pattern, tvb, 0, LOWPAN_PATTERN_BC0_BITS, ENC_BIG_ENDIAN);
seqnum = tvb_get_guint8(tvb, 1);
proto_tree_add_uint(bcast_tree, hf_6lowpan_bcast_seqnum, tvb, 1, 1, seqnum);
return tvb_new_subset_remaining(tvb, 2);
}
static tvbuff_t *
dissect_6lowpan_mesh(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 *siid, guint8 *diid)
{
gint offset = 0;
guint8 mesh_header;
proto_tree * mesh_tree;
proto_tree * flag_tree;
proto_item * ti;
ieee802154_hints_t *hints;
mesh_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_6lowpan_mesh, &ti, "Mesh Header");
mesh_header = tvb_get_guint8(tvb, offset);
flag_tree = proto_tree_add_subtree(mesh_tree, tvb, offset, 1, ett_6lowpan_mesh, NULL, "Flags");
proto_tree_add_bits_item(flag_tree, hf_6lowpan_pattern, tvb, offset * 8, LOWPAN_PATTERN_MESH_BITS, ENC_BIG_ENDIAN);
proto_tree_add_boolean(flag_tree, hf_6lowpan_mesh_v, tvb, offset, 1, mesh_header & LOWPAN_MESH_HEADER_V);
proto_tree_add_boolean(flag_tree, hf_6lowpan_mesh_f, tvb, offset, 1, mesh_header & LOWPAN_MESH_HEADER_F);
proto_tree_add_uint(flag_tree, hf_6lowpan_mesh_hops, tvb, offset, 1, mesh_header & LOWPAN_MESH_HEADER_HOPS);
offset += 1;
if ((mesh_header & LOWPAN_MESH_HEADER_HOPS) == LOWPAN_MESH_HEADER_HOPS) {
proto_tree_add_item(mesh_tree, hf_6lowpan_mesh_hops8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (!(mesh_header & LOWPAN_MESH_HEADER_V)) {
proto_tree_add_item(mesh_tree, hf_6lowpan_mesh_orig64,
tvb, offset, 8, ENC_BIG_ENDIAN);
set_address_tvb(&pinfo->src, AT_EUI64, 8, tvb, offset);
copy_address_shallow(&pinfo->net_src, &pinfo->src);
tvb_memcpy(tvb, siid, offset, LOWPAN_IFC_ID_LEN);
siid[0] ^= 0x02;
offset += 8;
}
else {
guint16 addr16 = tvb_get_ntohs(tvb, offset);
guint8 * ifcid;
proto_tree_add_uint(mesh_tree, hf_6lowpan_mesh_orig16, tvb, offset, 2, addr16);
ifcid = (guint8 *)wmem_alloc(pinfo->pool, 8);
hints = (ieee802154_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_get_id_by_filter_name(IEEE802154_PROTOABBREV_WPAN), 0);
if (hints && rfc4944_short_address_format) {
lowpan_addr16_with_panid_to_ifcid(hints->src_pan, addr16, ifcid);
} else {
lowpan_addr16_to_ifcid(addr16, ifcid);
}
set_address(&pinfo->src, AT_EUI64, 8, ifcid);
copy_address_shallow(&pinfo->net_src, &pinfo->src);
memcpy(siid, ifcid, LOWPAN_IFC_ID_LEN);
offset += 2;
}
if (!(mesh_header & LOWPAN_MESH_HEADER_F)) {
proto_tree_add_item(mesh_tree, hf_6lowpan_mesh_dest64,
tvb, offset, 8, ENC_BIG_ENDIAN);
set_address_tvb(&pinfo->dst, AT_EUI64, 8, tvb, offset);
copy_address_shallow(&pinfo->net_dst, &pinfo->dst);
tvb_memcpy(tvb, diid, offset, LOWPAN_IFC_ID_LEN);
diid[0] ^= 0x02;
offset += 8;
}
else {
guint16 addr16 = tvb_get_ntohs(tvb, offset);
guint8 * ifcid;
proto_tree_add_uint(mesh_tree, hf_6lowpan_mesh_dest16, tvb, offset, 2, addr16);
ifcid = (guint8 *)wmem_alloc(pinfo->pool, 8);
hints = (ieee802154_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_get_id_by_filter_name(IEEE802154_PROTOABBREV_WPAN), 0);
if (hints && rfc4944_short_address_format) {
lowpan_addr16_with_panid_to_ifcid(hints->src_pan, addr16, ifcid);
} else {
lowpan_addr16_to_ifcid(addr16, ifcid);
}
set_address(&pinfo->dst, AT_EUI64, 8, ifcid);
copy_address_shallow(&pinfo->net_dst, &pinfo->dst);
memcpy(diid, ifcid, LOWPAN_IFC_ID_LEN);
offset += 2;
}
proto_item_set_end(ti, tvb, offset);
return tvb_new_subset_remaining(tvb, offset);
}
static tvbuff_t *
dissect_6lowpan_frag_first(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, const guint8 *siid, const guint8 *diid)
{
gint offset = 0;
gint frag_size;
guint16 dgram_size;
guint16 dgram_tag;
proto_tree * frag_tree;
proto_item * ti;
proto_item * length_item;
tvbuff_t * new_tvb;
tvbuff_t * frag_tvb;
fragment_head * frag_data;
gboolean save_fragmented;
frag_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_6lowpan_frag, &ti, "Fragmentation Header");
dgram_size = tvb_get_bits16(tvb, (offset * 8) + LOWPAN_PATTERN_FRAG_BITS, LOWPAN_FRAG_DGRAM_SIZE_BITS, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(frag_tree, hf_6lowpan_pattern, tvb, offset * 8, LOWPAN_PATTERN_FRAG_BITS, ENC_BIG_ENDIAN);
length_item = proto_tree_add_uint(frag_tree, hf_6lowpan_frag_dgram_size, tvb, offset, 2, dgram_size);
offset += 2;
dgram_tag = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(frag_tree, hf_6lowpan_frag_dgram_tag, tvb, offset, 2, dgram_tag);
offset += 2;
proto_item_set_end(ti, tvb, offset);
frag_tvb = tvb_new_subset_remaining(tvb, offset);
if (tvb_get_bits8(frag_tvb, 0, LOWPAN_PATTERN_IPV6_BITS) == LOWPAN_PATTERN_IPV6) {
frag_tvb = dissect_6lowpan_ipv6(frag_tvb, pinfo, tree);
}
else if (tvb_get_bits8(frag_tvb, 0, LOWPAN_PATTERN_HC1_BITS) == LOWPAN_PATTERN_HC1) {
if (dgram_size < IPv6_HDR_SIZE) {
expert_add_info_format(pinfo, length_item, &ei_6lowpan_bad_ipv6_header_length,
"Length is less than IPv6 header length %u", IPv6_HDR_SIZE);
}
frag_tvb = dissect_6lowpan_hc1(frag_tvb, pinfo, tree, dgram_size, siid, diid);
}
else if (tvb_get_bits8(frag_tvb, 0, LOWPAN_PATTERN_IPHC_BITS) == LOWPAN_PATTERN_IPHC) {
if (dgram_size < IPv6_HDR_SIZE) {
expert_add_info_format(pinfo, length_item, &ei_6lowpan_bad_ipv6_header_length,
"Length is less than IPv6 header length %u", IPv6_HDR_SIZE);
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
frag_size = tvb_captured_length(frag_tvb);
tvb_set_reported_length(frag_tvb, frag_size);
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
frag_data = fragment_add_check(&lowpan_reassembly_table,
frag_tvb, 0, pinfo, dgram_tag, NULL,
0, frag_size, (frag_size < dgram_size));
new_tvb = process_reassembled_data(frag_tvb, 0, pinfo,
"Reassembled 6LoWPAN", frag_data, &lowpan_frag_items,
NULL, tree);
pinfo->fragmented = save_fragmented;
if (new_tvb) {
return new_tvb;
} else {
call_data_dissector(frag_tvb, pinfo, proto_tree_get_root(tree));
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
proto_tree * frag_tree;
proto_item * ti;
tvbuff_t * new_tvb;
fragment_head * frag_data;
gboolean save_fragmented;
frag_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_6lowpan_frag, &ti, "Fragmentation Header");
dgram_size = tvb_get_bits16(tvb, (offset * 8) + LOWPAN_PATTERN_FRAG_BITS, LOWPAN_FRAG_DGRAM_SIZE_BITS, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(frag_tree, hf_6lowpan_pattern, tvb, offset * 8, LOWPAN_PATTERN_FRAG_BITS, ENC_BIG_ENDIAN);
proto_tree_add_uint(frag_tree, hf_6lowpan_frag_dgram_size, tvb, offset, 2, dgram_size);
offset += 2;
dgram_tag = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(frag_tree, hf_6lowpan_frag_dgram_tag, tvb, offset, 2, dgram_tag);
offset += 2;
dgram_offset = tvb_get_guint8(tvb, offset) * 8;
proto_tree_add_uint(frag_tree, hf_6lowpan_frag_dgram_offset, tvb, offset, 1, dgram_offset);
offset += 1;
frag_size = tvb_reported_length_remaining(tvb, offset);
proto_item_set_end(ti, tvb, offset);
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
frag_data = fragment_add_check(&lowpan_reassembly_table,
tvb, offset, pinfo, dgram_tag, NULL,
dgram_offset, frag_size, ((dgram_offset + frag_size) < dgram_size));
new_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled 6LoWPAN", frag_data, &lowpan_frag_items,
NULL, tree);
pinfo->fragmented = save_fragmented;
if (new_tvb) {
return new_tvb;
}
else {
new_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(new_tvb, pinfo, proto_tree_get_root(tree));
return NULL;
}
}
void
dissect_6lowpan_unknown(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t * data_tvb;
if (tvb_get_bits8(tvb, 0, LOWPAN_PATTERN_IPHC_BITS) == LOWPAN_PATTERN_IPHC) {
proto_tree_add_bits_item(tree, hf_6lowpan_pattern, tvb, 0, LOWPAN_PATTERN_IPHC_BITS, ENC_BIG_ENDIAN);
}
else {
guint8 pattern = tvb_get_guint8(tvb, 0);
proto_tree_add_uint_bits_format_value(tree, hf_6lowpan_pattern, tvb, 0, 8, pattern, "Unknown (0x%02x)", pattern);
}
data_tvb = tvb_new_subset_remaining(tvb, 1);
call_data_dissector(data_tvb, pinfo, proto_tree_get_root(tree));
}
static void
proto_shutdown_6lowpan(void)
{
g_hash_table_destroy(lowpan_context_table);
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
{ &hf_6lowpan_padding,
{ "Padding", "6lowpan.padding",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_hc1_encoding,
{ "HC1 Encoding", "6lowpan.hc1.encoding",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
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
{ &hf_6lowpan_hc2_udp_encoding,
{ "HC_UDP Encoding", "6lowpan.hc2.udp.encoding",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
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
{ &hf_6lowpan_iphc_sctx_prefix,
{ "Source context", "6lowpan.iphc.sctx.prefix", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_6lowpan_iphc_sctx_origin,
{ "Origin", "6lowpan.iphc.sctx.origin", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_6lowpan_iphc_dctx_prefix,
{ "Destination context", "6lowpan.iphc.dctx.prefix", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_6lowpan_iphc_dctx_origin,
{ "Origin", "6lowpan.iphc.dctx.origin", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
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
{ &hf_6lowpan_nhc_ext_reserved,
{ "Reserved octet", "6lowpan.nhc.ext.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_nhc_udp_checksum,
{ "Checksum", "6lowpan.nhc.udp.checksum",
FT_BOOLEAN, 8, TFS(&lowpan_compression), LOWPAN_NHC_UDP_CHECKSUM, NULL, HFILL }},
{ &hf_6lowpan_nhc_udp_ports,
{ "Ports", "6lowpan.nhc.udp.ports",
FT_UINT8, BASE_DEC, VALS(lowpan_udp_ports), LOWPAN_NHC_UDP_PORTS, NULL, HFILL }},
{ &hf_6lowpan_traffic_class,
{ "Traffic class", "6lowpan.class",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_flow_label,
{ "Flow label", "6lowpan.flow",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_ecn,
{ "ECN", "6lowpan.ecn",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_6lowpan_dscp,
{ "DSCP", "6lowpan.dscp",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
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
{ "Reassembled 6LoWPAN length", "6lowpan.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }}
};
static gint *ett[] = {
&ett_6lowpan,
&ett_6lowpan_hc1,
&ett_6lowpan_hc1_encoding,
&ett_6lowpan_hc2_udp,
&ett_6lowpan_iphc,
&ett_6lowpan_nhc_ext,
&ett_6lowpan_nhc_udp,
&ett_6lowpan_bcast,
&ett_6lowpan_mesh,
&ett_6lowpan_mesh_flags,
&ett_6lowpan_frag,
&ett_6lowpan_fragment,
&ett_6lowpan_fragments
};
static ei_register_info ei[] = {
{ &ei_6lowpan_hc1_more_bits, { "6lowpan.hc1_more_bits", PI_MALFORMED, PI_ERROR, "HC1 more bits expected for illegal next header type.", EXPFILL }},
{ &ei_6lowpan_illegal_dest_addr_mode, { "6lowpan.illegal_dest_addr_mode", PI_MALFORMED, PI_ERROR, "Illegal destination address mode", EXPFILL }},
{ &ei_6lowpan_bad_ipv6_header_length, { "6lowpan.bad_ipv6_header_length", PI_MALFORMED, PI_ERROR, "Length is less than IPv6 header length", EXPFILL }},
{ &ei_6lowpan_bad_ext_header_length, { "6lowpan.bad_ext_header_length", PI_MALFORMED, PI_ERROR, "Extension header not 8-octet aligned", EXPFILL }},
};
int i;
module_t *prefs_module;
expert_module_t* expert_6lowpan;
lowpan_context_table = g_hash_table_new_full(lowpan_context_hash, lowpan_context_equal, lowpan_context_free, lowpan_context_free);
proto_6lowpan = proto_register_protocol("IPv6 over Low power Wireless Personal Area Networks", "6LoWPAN", "6lowpan");
proto_register_field_array(proto_6lowpan, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_6lowpan = expert_register_protocol(proto_6lowpan);
expert_register_field_array(expert_6lowpan, ei, array_length(ei));
handle_6lowpan = register_dissector("6lowpan", dissect_6lowpan, proto_6lowpan);
reassembly_table_register(&lowpan_reassembly_table, &addresses_reassembly_table_functions);
register_init_routine(proto_init_6lowpan);
register_shutdown_routine(proto_shutdown_6lowpan);
memset((gchar*)lowpan_context_prefs, 0, sizeof(lowpan_context_prefs));
prefs_module = prefs_register_protocol(proto_6lowpan, prefs_6lowpan_apply);
prefs_register_bool_preference(prefs_module, "rfc4944_short_address_format",
"Derive IID according to RFC 4944",
"Derive IID from a short 16-bit address according to RFC 4944 (using the PAN ID).",
&rfc4944_short_address_format);
for (i = 0; i < LOWPAN_CONTEXT_MAX; i++) {
char *pref_name, *pref_title;
pref_name = wmem_strdup_printf(wmem_epan_scope(), "context%d", i);
pref_title = wmem_strdup_printf(wmem_epan_scope(), "Context %d", i);
prefs_register_string_preference(prefs_module, pref_name, pref_title,
"IPv6 prefix to use for stateful address decompression.",
&lowpan_context_prefs[i]);
}
}
static void
proto_init_6lowpan(void)
{
lowpan_context_local.frame = 0;
lowpan_context_local.plen = LOWPAN_CONTEXT_LINK_LOCAL_BITS;
memcpy(&lowpan_context_local.prefix, lowpan_llprefix, sizeof(lowpan_llprefix));
prefs_6lowpan_apply();
}
void
prefs_6lowpan_apply(void)
{
int i;
struct e_in6_addr prefix;
gchar *prefix_str;
gchar *prefix_len_str;
guint32 prefix_len;
gchar prefix_buf[48];
for (i = 0; i < LOWPAN_CONTEXT_MAX; i++) {
if (!lowpan_context_prefs[i]) continue;
g_strlcpy(prefix_buf, lowpan_context_prefs[i], 48);
if ((prefix_str = strtok(prefix_buf, "/")) == NULL) continue;
if ((prefix_len_str = strtok(NULL, "/")) == NULL) continue;
if (sscanf(prefix_len_str, "%u", &prefix_len) != 1) continue;
if (!str_to_ip6(prefix_str, &prefix)) continue;
lowpan_context_insert(i, IEEE802154_BCAST_PAN, prefix_len, &prefix, 0);
}
}
void
proto_reg_handoff_6lowpan(void)
{
ipv6_handle = find_dissector_add_dependency("ipv6", proto_6lowpan);
dissector_add_for_decode_as(IEEE802154_PROTOABBREV_WPAN_PANID, handle_6lowpan);
heur_dissector_add(IEEE802154_PROTOABBREV_WPAN, dissect_6lowpan_heur, "6LoWPAN over IEEE 802.15.4", "6lowpan_wlan", proto_6lowpan, HEURISTIC_ENABLE);
dissector_add_uint("btl2cap.psm", BTL2CAP_PSM_LE_IPSP, handle_6lowpan);
dissector_add_for_decode_as("btl2cap.cid", handle_6lowpan);
}
