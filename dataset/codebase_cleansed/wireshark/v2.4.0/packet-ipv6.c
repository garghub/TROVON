ipv6_pinfo_t *p_get_ipv6_pinfo(packet_info *pinfo)
{
return (ipv6_pinfo_t *)p_get_proto_data(pinfo->pool, pinfo, proto_ipv6, IPV6_PROTO_PINFO);
}
static void p_add_ipv6_nxt(packet_info *pinfo, guint8 nxt)
{
guint8 *ptr;
ptr = (guint8 *)wmem_memdup(pinfo->pool, &nxt, sizeof(guint8));
p_add_proto_data(pinfo->pool, pinfo, proto_ipv6,
(pinfo->curr_layer_num<<8) | IPV6_PROTO_VALUE, ptr);
}
static guint8 *p_get_ipv6_nxt(packet_info *pinfo)
{
return (guint8 *)p_get_proto_data(pinfo->pool, pinfo, proto_ipv6,
(pinfo->curr_layer_num<<8) | IPV6_PROTO_VALUE);
}
static gpointer ipv6_value(packet_info *pinfo)
{
guint8 *nxt = p_get_ipv6_nxt(pinfo);
if (nxt == NULL) {
return GUINT_TO_POINTER(255);
}
return GUINT_TO_POINTER((guint)*nxt);
}
static void ipv6_prompt(packet_info *pinfo, gchar *result)
{
gpointer value = ipv6_value(pinfo);
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "IP protocol %u as", GPOINTER_TO_UINT(value));
}
static const char* ipv6_conv_get_filter_type(conv_item_t* conv, conv_filter_type_e filter)
{
if ((filter == CONV_FT_SRC_ADDRESS) && (conv->src_address.type == AT_IPv6))
return "ipv6.src";
if ((filter == CONV_FT_DST_ADDRESS) && (conv->dst_address.type == AT_IPv6))
return "ipv6.dst";
if ((filter == CONV_FT_ANY_ADDRESS) && (conv->src_address.type == AT_IPv6))
return "ipv6.addr";
return CONV_FILTER_INVALID;
}
static int
ipv6_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
conv_hash_t *hash = (conv_hash_t*) pct;
const struct ws_ip6_hdr *ip6h = (const struct ws_ip6_hdr *)vip;
address src;
address dst;
set_address_ipv6(&src, &ip6h->ip6h_src);
set_address_ipv6(&dst, &ip6h->ip6h_dst);
add_conversation_table_data(hash, &src, &dst, 0, 0, 1,
pinfo->fd->pkt_len, &pinfo->rel_ts, &pinfo->abs_ts,
&ipv6_ct_dissector_info, PT_NONE);
return 1;
}
static const char* ipv6_host_get_filter_type(hostlist_talker_t* host, conv_filter_type_e filter)
{
if ((filter == CONV_FT_ANY_ADDRESS) && (host->myaddress.type == AT_IPv6))
return "ipv6.addr";
return CONV_FILTER_INVALID;
}
static int
ipv6_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
conv_hash_t *hash = (conv_hash_t*) pit;
const struct ws_ip6_hdr *ip6h = (const struct ws_ip6_hdr *)vip;
address src;
address dst;
set_address_ipv6(&src, &ip6h->ip6h_src);
set_address_ipv6(&dst, &ip6h->ip6h_dst);
add_hostlist_table_data(hash, &src, 0, TRUE, 1,
pinfo->fd->pkt_len, &ipv6_host_dissector_info, PT_NONE);
add_hostlist_table_data(hash, &dst, 0, FALSE, 1,
pinfo->fd->pkt_len, &ipv6_host_dissector_info, PT_NONE);
return 1;
}
static gboolean
ipv6_filter_valid(packet_info *pinfo)
{
return proto_is_frame_protocol(pinfo->layers, "ipv6");
}
static gchar*
ipv6_build_filter(packet_info *pinfo)
{
return g_strdup_printf("ipv6.addr eq %s and ipv6.addr eq %s",
address_to_str(pinfo->pool, &pinfo->net_src),
address_to_str(pinfo->pool, &pinfo->net_dst));
}
static gint
ipv6_previous_layer_id(packet_info *pinfo)
{
wmem_list_frame_t *layer;
layer = wmem_list_tail(pinfo->layers);
DISSECTOR_ASSERT(layer);
layer = wmem_list_frame_prev(layer);
if (layer != NULL) {
return GPOINTER_TO_INT(wmem_list_frame_data(layer));
}
return -1;
}
static inline gint
ipv6_opt_type_hdr(gint type)
{
const gint (*p)[2] = _ipv6_opt_type_hdr;
for (; (*p)[1] != IPv6_OPT_HDR_ANY; p++) {
if ((*p)[0] == type) {
return (*p)[1];
}
}
return IPv6_OPT_HDR_ANY;
}
static gboolean
capture_ipv6(const guchar *pd, int offset, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header)
{
guint8 nxt;
if (!BYTES_ARE_IN_FRAME(offset, len, IPv6_HDR_SIZE))
return FALSE;
capture_dissector_increment_count(cpinfo, proto_ipv6);
nxt = pd[offset+6];
offset += IPv6_HDR_SIZE;
return try_capture_dissector("ip.proto", nxt, pd, offset, len, cpinfo, pseudo_header);
}
static gboolean
capture_ipv6_exthdr(const guchar *pd, int offset, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header)
{
guint8 nxt;
int advance;
if (!BYTES_ARE_IN_FRAME(offset, len, 2))
return FALSE;
nxt = pd[offset];
switch (nxt) {
case IP_PROTO_FRAGMENT:
advance = IPv6_FRAGMENT_HDR_SIZE;
break;
default:
advance = (pd[offset+1] + 1) << 3;
break;
}
if (!BYTES_ARE_IN_FRAME(offset, len, advance))
return FALSE;
offset += advance;
return try_capture_dissector("ip.proto", nxt, pd, offset, len, cpinfo, pseudo_header);
}
static void
add_geoip_info_entry(proto_tree *geoip_info_tree, proto_item *geoip_info_item, tvbuff_t *tvb, gint offset, const struct e_in6_addr *ip, int isdst)
{
guint num_dbs = geoip_db_num_dbs();
guint item_cnt = 0;
guint dbnum;
for (dbnum = 0; dbnum < num_dbs; dbnum++) {
char *geoip_str = geoip_db_lookup_ipv6(dbnum, *ip, NULL);
int db_type = geoip_db_type(dbnum);
int geoip_hf, geoip_local_hf;
switch (db_type) {
case GEOIP_COUNTRY_EDITION_V6:
geoip_hf = hf_geoip_country;
geoip_local_hf = (isdst) ? hf_geoip_dst_country : hf_geoip_src_country;
break;
#if NUM_DB_TYPES > 31
case GEOIP_CITY_EDITION_REV0_V6:
case GEOIP_CITY_EDITION_REV1_V6:
geoip_hf = hf_geoip_city;
geoip_local_hf = (isdst) ? hf_geoip_dst_city : hf_geoip_src_city;
break;
case GEOIP_ORG_EDITION_V6:
geoip_hf = hf_geoip_org;
geoip_local_hf = (isdst) ? hf_geoip_dst_org : hf_geoip_src_org;
break;
case GEOIP_ISP_EDITION_V6:
geoip_hf = hf_geoip_isp;
geoip_local_hf = (isdst) ? hf_geoip_dst_isp : hf_geoip_src_isp;
break;
case GEOIP_ASNUM_EDITION_V6:
geoip_hf = hf_geoip_asnum;
geoip_local_hf = (isdst) ? hf_geoip_dst_asnum : hf_geoip_src_asnum;
break;
#endif
case WS_LAT_FAKE_EDITION:
geoip_hf = hf_geoip_lat;
geoip_local_hf = (isdst) ? hf_geoip_dst_lat : hf_geoip_src_lat;
break;
case WS_LON_FAKE_EDITION:
geoip_hf = hf_geoip_lon;
geoip_local_hf = (isdst) ? hf_geoip_dst_lon : hf_geoip_src_lon;
break;
default:
continue;
}
if (geoip_str) {
proto_item *item;
if (db_type == WS_LAT_FAKE_EDITION || db_type == WS_LON_FAKE_EDITION) {
item = proto_tree_add_double_format_value(geoip_info_tree, geoip_local_hf, tvb,
offset, 16, g_ascii_strtod(geoip_str, NULL), "%s", geoip_str);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_double_format_value(geoip_info_tree, geoip_hf, tvb,
offset, 16, g_ascii_strtod(geoip_str, NULL), "%s", geoip_str);
PROTO_ITEM_SET_GENERATED(item);
PROTO_ITEM_SET_HIDDEN(item);
} else {
item = proto_tree_add_string(geoip_info_tree, geoip_local_hf, tvb,
offset, 16, geoip_str);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_string(geoip_info_tree, geoip_hf, tvb,
offset, 16, geoip_str);
PROTO_ITEM_SET_GENERATED(item);
PROTO_ITEM_SET_HIDDEN(item);
}
item_cnt++;
proto_item_append_text(geoip_info_item, "%s%s", plurality(item_cnt, "", ", "), geoip_str);
wmem_free(NULL, geoip_str);
}
}
if (item_cnt == 0)
proto_item_append_text(geoip_info_item, "Unknown");
}
static void
add_geoip_info(proto_tree *tree, tvbuff_t *tvb, gint offset, const struct e_in6_addr *src, const struct e_in6_addr *dst)
{
guint num_dbs;
proto_item *geoip_info_item;
proto_tree *geoip_info_tree;
num_dbs = geoip_db_num_dbs();
if (num_dbs < 1)
return;
geoip_info_tree = proto_tree_add_subtree(tree, tvb, offset + IP6H_SRC, 16, ett_geoip_info, &geoip_info_item, "Source GeoIP: ");
PROTO_ITEM_SET_GENERATED(geoip_info_item);
add_geoip_info_entry(geoip_info_tree, geoip_info_item, tvb, offset + IP6H_SRC, src, 0);
geoip_info_tree = proto_tree_add_subtree(tree, tvb, offset + IP6H_DST, 16, ett_geoip_info, &geoip_info_item, "Destination GeoIP: ");
PROTO_ITEM_SET_GENERATED(geoip_info_item);
add_geoip_info_entry(geoip_info_tree, geoip_info_item, tvb, offset + IP6H_DST, dst, 1);
}
static gboolean
ipv6_reassemble_do(tvbuff_t **tvb_ptr, gint *offset_ptr, packet_info *pinfo, proto_tree *ipv6_tree,
guint32 plen, guint16 frag_off, gboolean frag_flg, guint32 frag_ident,
gboolean *show_data_ptr)
{
fragment_head *ipfd_head;
tvbuff_t *next_tvb;
gboolean update_col_info = TRUE;
pinfo->fragmented = TRUE;
*show_data_ptr = TRUE;
if (!ipv6_reassemble) {
if (frag_off == 0) {
*show_data_ptr = FALSE;
}
return FALSE;
}
if (tvb_bytes_exist(*tvb_ptr, *offset_ptr, plen)) {
ipfd_head = fragment_add_check(&ipv6_reassembly_table,
*tvb_ptr, *offset_ptr, pinfo, frag_ident, NULL,
frag_off, plen, frag_flg);
next_tvb = process_reassembled_data(*tvb_ptr, *offset_ptr, pinfo, "Reassembled IPv6",
ipfd_head, &ipv6_frag_items, &update_col_info, ipv6_tree);
if (next_tvb) {
*offset_ptr = 0;
*tvb_ptr = next_tvb;
pinfo->fragmented = FALSE;
*show_data_ptr = FALSE;
return TRUE;
}
}
return FALSE;
}
static proto_item *
_proto_tree_add_ipv6_vector_address(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const struct e_in6_addr *value_ptr, int idx)
{
address addr;
gchar *str;
set_address_ipv6(&addr, value_ptr);
str = address_with_resolution_to_str(wmem_packet_scope(), &addr);
return proto_tree_add_ipv6_format(tree, hfindex, tvb, start, length,
value_ptr, "Address[%d]: %s", idx, str);
}
static void
dissect_routing6_rt0(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *rthdr_tree,
struct rthdr_proto_item *rthdr_ti, struct ip6_rthdr rt)
{
proto_item *ti;
gint idx;
gint rt0_addr_count;
const struct e_in6_addr *addr = NULL;
proto_tree_add_item(rthdr_tree, hf_ipv6_routing_src_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
if (rt.ip6r_len % 2 != 0) {
expert_add_info_format(pinfo, rthdr_ti->len, &ei_ipv6_routing_invalid_length,
"IPv6 Routing Header extension header length must not be odd");
}
rt0_addr_count = rt.ip6r_len / 2;
if (rt.ip6r_segleft > rt0_addr_count) {
expert_add_info_format(pinfo, rthdr_ti->segs, &ei_ipv6_routing_invalid_segleft,
"IPv6 Type 0 Routing Header segments left field must not exceed address count (%u)", rt0_addr_count);
}
for (idx = 1; idx <= rt0_addr_count; idx++) {
addr = tvb_get_ptr_ipv6(tvb, offset);
ti = _proto_tree_add_ipv6_vector_address(rthdr_tree, hf_ipv6_routing_src_addr, tvb,
offset, IPv6_ADDR_SIZE, addr, idx);
offset += IPv6_ADDR_SIZE;
if (in6_is_addr_multicast(addr)) {
expert_add_info(pinfo, ti, &ei_ipv6_src_route_list_multicast_addr);
}
}
if (addr != NULL && pinfo->dst.type == AT_IPv6 && rt.ip6r_segleft > 0) {
alloc_address_wmem_ipv6(pinfo->pool, &pinfo->dst, addr);
}
}
static void
dissect_routing6_mipv6(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *rthdr_tree,
struct rthdr_proto_item *rthdr_ti, struct ip6_rthdr rt)
{
proto_item *ti;
const struct e_in6_addr *addr;
proto_tree_add_item(rthdr_tree, hf_ipv6_routing_mipv6_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
if (rt.ip6r_len != 2) {
expert_add_info_format(pinfo, rthdr_ti->len, &ei_ipv6_routing_invalid_length,
"IPv6 Type 2 Routing Header extension header length must equal 2");
}
if (rt.ip6r_segleft != 1) {
expert_add_info_format(pinfo, rthdr_ti->segs, &ei_ipv6_routing_invalid_segleft,
"IPv6 Type 2 Routing Header segments left field must equal 1");
}
addr = tvb_get_ptr_ipv6(tvb, offset);
ti = _proto_tree_add_ipv6_vector_address(rthdr_tree, hf_ipv6_routing_mipv6_home_address, tvb,
offset, IPv6_ADDR_SIZE, addr, 1);
if (in6_is_addr_multicast(addr)) {
expert_add_info(pinfo, ti, &ei_ipv6_src_route_list_multicast_addr);
}
if (pinfo->dst.type == AT_IPv6 && rt.ip6r_segleft > 0) {
alloc_address_wmem_ipv6(pinfo->pool, &pinfo->dst, addr);
}
}
static void
dissect_routing6_rpl(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *rthdr_tree,
struct rthdr_proto_item *rthdr_ti, struct ip6_rthdr rt)
{
proto_item *pi = proto_tree_get_parent(rthdr_tree);
proto_item *ti;
guint8 cmprI, cmprE, cmprX, pad;
guint32 reserved;
gint idx;
gint rpl_addr_count;
struct e_in6_addr rpl_fulladdr;
const struct e_in6_addr *ip6_dst_addr, *ip6_src_addr;
wmem_array_t *rpl_addr_vector = NULL;
guint i;
if ((pinfo->dst.type != AT_IPv6) || (pinfo->src.type != AT_IPv6))
return;
ip6_dst_addr = (const struct e_in6_addr *)pinfo->dst.data;
ip6_src_addr = (const struct e_in6_addr *)pinfo->src.data;
if (in6_is_addr_multicast(ip6_dst_addr)) {
expert_add_info(pinfo, pi, &ei_ipv6_dst_addr_not_multicast);
}
proto_tree_add_item(rthdr_tree, hf_ipv6_routing_rpl_cmprI, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rthdr_tree, hf_ipv6_routing_rpl_cmprE, tvb, offset, 4, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(rthdr_tree, hf_ipv6_routing_rpl_pad, tvb, offset, 4, ENC_BIG_ENDIAN);
cmprI = tvb_get_guint8(tvb, offset) & 0xF0;
cmprE = tvb_get_guint8(tvb, offset) & 0x0F;
pad = tvb_get_guint8(tvb, offset + 1) & 0xF0;
cmprI >>= 4;
pad >>= 4;
if (cmprI == 0 && cmprE == 0 && pad != 0) {
expert_add_info_format(pinfo, ti, &ei_ipv6_routing_rpl_cmpri_cmpre_pad, "When cmprI equals 0 and cmprE equals 0, pad MUST equal 0 but instead was %d", pad);
}
ti = proto_tree_add_item(rthdr_tree, hf_ipv6_routing_rpl_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
reserved = tvb_get_bits32(tvb, ((offset + 1) * 8) + 4, 20, ENC_BIG_ENDIAN);
if (reserved != 0) {
expert_add_info_format(pinfo, ti, &ei_ipv6_routing_rpl_reserved, "Reserved field must equal 0 but instead was %d", reserved);
}
rpl_addr_count = 0;
if (rt.ip6r_len > 0) {
rpl_addr_count = (((rt.ip6r_len * 8) - pad - (16 - cmprE)) / (16 - cmprI)) + 1;
}
ti = proto_tree_add_int(rthdr_tree, hf_ipv6_routing_rpl_addr_count, tvb, offset, 2, rpl_addr_count);
PROTO_ITEM_SET_GENERATED(ti);
if (rpl_addr_count < 0) {
expert_add_info_format(pinfo, ti, &ei_ipv6_routing_rpl_addr_count_ge0, "Calculated total address count must be greater than or equal to 0, instead was %d", rpl_addr_count);
}
else if (rt.ip6r_segleft > (guint)rpl_addr_count) {
expert_add_info_format(pinfo, rthdr_ti->segs, &ei_ipv6_routing_invalid_segleft,
"IPv6 RPL Routing Header segments left field must not exceed address count (%d)", rpl_addr_count);
}
if (rpl_addr_count > 0) {
offset += 4;
if (g_ipv6_rpl_srh_strict_rfc_checking)
rpl_addr_vector = wmem_array_sized_new(wmem_packet_scope(), IPv6_ADDR_SIZE, rpl_addr_count);
for (idx = 1; idx <= rpl_addr_count; idx++) {
if (idx == rpl_addr_count)
cmprX = 16 - cmprE;
else
cmprX = 16 - cmprI;
proto_tree_add_item(rthdr_tree, hf_ipv6_routing_rpl_addr, tvb, offset, cmprX, ENC_NA);
memcpy(&rpl_fulladdr, ip6_dst_addr, IPv6_ADDR_SIZE);
tvb_memcpy(tvb, &rpl_fulladdr.bytes[16-cmprX], offset, cmprX);
ti = _proto_tree_add_ipv6_vector_address(rthdr_tree, hf_ipv6_routing_rpl_fulladdr, tvb,
offset, cmprX, &rpl_fulladdr, idx);
PROTO_ITEM_SET_GENERATED(ti);
offset += cmprX;
if (memcmp(&rpl_fulladdr, ip6_src_addr, IPv6_ADDR_SIZE) == 0) {
expert_add_info(pinfo, ti, &ei_ipv6_src_route_list_src_addr);
}
if (memcmp(&rpl_fulladdr, ip6_dst_addr, IPv6_ADDR_SIZE) == 0) {
expert_add_info(pinfo, ti, &ei_ipv6_src_route_list_dst_addr);
}
if (in6_is_addr_multicast(&rpl_fulladdr)) {
expert_add_info(pinfo, ti, &ei_ipv6_src_route_list_multicast_addr);
}
if (g_ipv6_rpl_srh_strict_rfc_checking) {
for (i = 0; i < wmem_array_get_count(rpl_addr_vector); i++) {
if (memcmp(&rpl_fulladdr, wmem_array_index(rpl_addr_vector, i), IPv6_ADDR_SIZE) == 0) {
expert_add_info(pinfo, ti, &ei_ipv6_src_route_list_mult_inst_same_addr);
break;
}
}
wmem_array_append(rpl_addr_vector, &rpl_fulladdr, 1);
}
if (pinfo->dst.type == AT_IPv6 && rt.ip6r_segleft > 0) {
alloc_address_wmem_ipv6(pinfo->pool, &pinfo->dst, &rpl_fulladdr);
}
}
}
}
static void
dissect_routing6_srh(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *rthdr_tree,
struct rthdr_proto_item *rthdr_ti, struct ip6_rthdr rt)
{
proto_item *ti;
gint offlim, offstart;
gint idx;
gint srh_first_seg, srh_addr_count;
const struct e_in6_addr *addr;
proto_tree *rthdr_srh_addr_tree;
static const int *srh_flags[] = {
&hf_ipv6_routing_srh_flag_unused1,
&hf_ipv6_routing_srh_flag_p,
&hf_ipv6_routing_srh_flag_o,
&hf_ipv6_routing_srh_flag_a,
&hf_ipv6_routing_srh_flag_h,
&hf_ipv6_routing_srh_flag_unused2,
NULL
};
srh_first_seg = tvb_get_guint8(tvb, offset);
proto_tree_add_item(rthdr_tree, hf_ipv6_routing_srh_first_seg, tvb, offset, 1, ENC_NA);
offset += 1;
srh_addr_count = srh_first_seg + 1;
ti = proto_tree_add_bitmask(rthdr_tree, tvb, offset, hf_ipv6_routing_srh_flags,
ett_ipv6_routing_srh_flags, srh_flags, ENC_BIG_ENDIAN);
expert_add_info_format(pinfo, ti, &ei_ipv6_routing_undecoded,
"Dissection for SRH TLVs not yet implemented");
offset += 1;
proto_tree_add_item(rthdr_tree, hf_ipv6_routing_srh_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
if (rt.ip6r_segleft > srh_first_seg) {
expert_add_info_format(pinfo, rthdr_ti->segs, &ei_ipv6_routing_invalid_segleft,
"IPv6 Type 4 Routing Header segments left field must not exceed first segment (%u)", srh_first_seg);
}
offstart = offset;
offlim = offset + srh_addr_count * IPv6_ADDR_SIZE;
addr = tvb_get_ptr_ipv6(tvb, offset);
if (in6_is_addr_multicast(addr)) {
expert_add_info(pinfo, ti, &ei_ipv6_src_route_list_multicast_addr);
}
ti = _proto_tree_add_ipv6_vector_address(rthdr_tree, hf_ipv6_routing_srh_addr, tvb,
offset, IPv6_ADDR_SIZE, addr, 0);
if (rt.ip6r_segleft == 1) {
proto_item_append_text(ti, " [next segment]");
}
if (pinfo->dst.type == AT_IPv6 && rt.ip6r_segleft > 0) {
alloc_address_wmem_ipv6(pinfo->pool, &pinfo->dst, addr);
}
offset += IPv6_ADDR_SIZE;
for (idx = 1; offset < offlim; offset += IPv6_ADDR_SIZE, idx++) {
addr = tvb_get_ptr_ipv6(tvb, offset);
if (in6_is_addr_multicast(addr)) {
expert_add_info(pinfo, ti, &ei_ipv6_src_route_list_multicast_addr);
}
ti = _proto_tree_add_ipv6_vector_address(rthdr_tree, hf_ipv6_routing_srh_addr, tvb,
offset, IPv6_ADDR_SIZE, addr, idx);
if (idx == rt.ip6r_segleft - 1) {
proto_item_append_text(ti, " [next segment]");
}
}
rthdr_srh_addr_tree = proto_tree_add_subtree_format(rthdr_tree, tvb, offstart, srh_addr_count * IPv6_ADDR_SIZE,
ett_ipv6_routing_srh_vect, &ti, "Segments in Traversal Order");
PROTO_ITEM_SET_GENERATED(ti);
offset -= IPv6_ADDR_SIZE;
for (idx = srh_first_seg; offset >= offstart; offset -= IPv6_ADDR_SIZE, idx--) {
addr = tvb_get_ptr_ipv6(tvb, offset);
ti = _proto_tree_add_ipv6_vector_address(rthdr_srh_addr_tree, hf_ipv6_routing_srh_addr, tvb,
offset, IPv6_ADDR_SIZE, addr, idx);
if (idx == rt.ip6r_segleft - 1) {
proto_item_append_text(ti, " [next segment]");
}
}
}
static void
dissect_routing6_unknown(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *rthdr_tree,
struct rthdr_proto_item *rthdr_ti _U_, struct ip6_rthdr rt)
{
gint len;
proto_item *ti;
len = ((rt.ip6r_len + 1) << 3) - 4;
ti = proto_tree_add_item(rthdr_tree, hf_ipv6_routing_unknown_data, tvb, offset, len, ENC_NA);
expert_add_info(pinfo, ti, &ei_ipv6_routing_undecoded);
}
static int
dissect_routing6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data) {
struct ip6_rthdr rt;
guint len;
proto_tree *rthdr_tree, *root_tree;
proto_item *pi, *ti;
struct rthdr_proto_item rthdr_ti;
int offset = 0;
tvbuff_t *next_tvb;
ipv6_pinfo_t *ipv6_pinfo = p_get_ipv6_pinfo(pinfo);
col_append_sep_str(pinfo->cinfo, COL_INFO, " , ", "IPv6 routing");
tvb_memcpy(tvb, (guint8 *)&rt, offset, sizeof(rt));
len = (rt.ip6r_len + 1) << 3;
root_tree = tree;
if (pinfo->dst.type == AT_IPv6) {
ipv6_pinfo->frag_plen -= len;
if (ipv6_pinfo->ipv6_tree != NULL) {
root_tree = ipv6_pinfo->ipv6_tree;
ipv6_pinfo->ipv6_item_len += len;
}
}
pi = proto_tree_add_item(root_tree, proto_ipv6_routing, tvb, offset, len, ENC_NA);
proto_item_append_text(pi, " (%s)", val_to_str(rt.ip6r_type, routing_header_type, "Unknown type %u"));
rthdr_tree = proto_item_add_subtree(pi, ett_ipv6_routing_proto);
proto_tree_add_item(rthdr_tree, hf_ipv6_routing_nxt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
rthdr_ti.len = proto_tree_add_item(rthdr_tree, hf_ipv6_routing_len, tvb, offset, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_uint(rthdr_tree, hf_ipv6_routing_len_oct, tvb, offset, 1, len);
PROTO_ITEM_SET_GENERATED(ti);
if (ipv6_exthdr_hide_len_oct_field) {
PROTO_ITEM_SET_HIDDEN(ti);
proto_item_append_text(rthdr_ti.len, " (%d bytes)", len);
}
offset += 1;
rthdr_ti.type = proto_tree_add_item(rthdr_tree, hf_ipv6_routing_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
rthdr_ti.segs = proto_tree_add_item(rthdr_tree, hf_ipv6_routing_segleft, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (rt.ip6r_type) {
case IPv6_RT_HEADER_SOURCE_ROUTING:
dissect_routing6_rt0(tvb, offset, pinfo, rthdr_tree, &rthdr_ti, rt);
expert_add_info(pinfo, rthdr_ti.type, &ei_ipv6_routing_deprecated);
break;
case IPv6_RT_HEADER_NIMROD:
dissect_routing6_unknown(tvb, offset, pinfo, rthdr_tree, &rthdr_ti, rt);
expert_add_info(pinfo, rthdr_ti.type, &ei_ipv6_routing_deprecated);
break;
case IPv6_RT_HEADER_MobileIP:
dissect_routing6_mipv6(tvb, offset, pinfo, rthdr_tree, &rthdr_ti, rt);
break;
case IPv6_RT_HEADER_RPL:
dissect_routing6_rpl(tvb, offset, pinfo, rthdr_tree, &rthdr_ti, rt);
break;
case IPv6_RT_HEADER_SEGMENT_ROUTING:
dissect_routing6_srh(tvb, offset, pinfo, rthdr_tree, &rthdr_ti, rt);
break;
default:
dissect_routing6_unknown(tvb, offset, pinfo, rthdr_tree, &rthdr_ti, rt);
break;
}
p_add_ipv6_nxt(pinfo, rt.ip6r_nxt);
next_tvb = tvb_new_subset_remaining(tvb, len);
ipv6_dissect_next(rt.ip6r_nxt, next_tvb, pinfo, tree, (ws_ip *)data);
return tvb_captured_length(tvb);
}
static int
dissect_fraghdr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data) {
proto_item *pi, *ti;
proto_tree *frag_tree, *root_tree;
guint8 nxt;
guint16 offlg;
guint16 frag_off;
gboolean frag_flg;
guint32 frag_ident;
gint offset = 0;
ipv6_pinfo_t *ipv6_pinfo = p_get_ipv6_pinfo(pinfo);
gboolean show_data = FALSE;
gboolean reassembled;
tvbuff_t *next_tvb;
nxt = tvb_get_guint8(tvb, offset);
offlg = tvb_get_ntohs(tvb, offset + 2);
frag_off = offlg & IP6F_OFF_MASK;
frag_flg = offlg & IP6F_MORE_FRAG;
frag_ident = tvb_get_ntohl(tvb, offset + 4);
col_add_fstr(pinfo->cinfo, COL_INFO, "IPv6 fragment (off=%u more=%s ident=0x%08x nxt=%u)",
frag_off, frag_flg ? "y" : "n", frag_ident, nxt);
root_tree = tree;
if (pinfo->dst.type == AT_IPv6) {
ipv6_pinfo->frag_plen -= IPv6_FRAGMENT_HDR_SIZE;
if (ipv6_pinfo->ipv6_tree != NULL) {
root_tree = ipv6_pinfo->ipv6_tree;
ipv6_pinfo->ipv6_item_len += IPv6_FRAGMENT_HDR_SIZE;
}
}
pi = proto_tree_add_item(root_tree, proto_ipv6_fraghdr, tvb, offset, IPv6_FRAGMENT_HDR_SIZE, ENC_NA);
if (ipv6_pinfo != NULL && ipv6_pinfo->jumbo_plen != 0) {
expert_add_info(pinfo, pi, &ei_ipv6_opt_jumbo_fragment);
}
frag_tree = proto_item_add_subtree(pi, ett_ipv6_fraghdr_proto);
proto_tree_add_item(frag_tree, hf_ipv6_fraghdr_nxt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(frag_tree, hf_ipv6_fraghdr_reserved_octet, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti = proto_tree_add_item(frag_tree, hf_ipv6_fraghdr_offset, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%d bytes)", frag_off);
proto_tree_add_item(frag_tree, hf_ipv6_fraghdr_reserved_bits, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(frag_tree, hf_ipv6_fraghdr_more, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(frag_tree, hf_ipv6_fraghdr_ident, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (ipv6_pinfo != NULL && ipv6_pinfo->frag_plen > 0) {
if ((frag_off != 0) || frag_flg) {
reassembled = ipv6_reassemble_do(&tvb, &offset, pinfo, root_tree, ipv6_pinfo->frag_plen,
frag_off, frag_flg, frag_ident, &show_data);
if (show_data) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
if (reassembled) {
ipv6_pinfo->frag_plen = 0;
next_tvb = tvb_new_subset_remaining(tvb, offset);
ipv6_dissect_next(nxt, next_tvb, pinfo, tree, (ws_ip *)data);
return tvb_captured_length(tvb);
}
}
}
p_add_ipv6_nxt(pinfo, nxt);
next_tvb = tvb_new_subset_remaining(tvb, offset);
ipv6_dissect_next(nxt, next_tvb, pinfo, tree, (ws_ip *)data);
return tvb_captured_length(tvb);
}
static gint
dissect_opt_jumbo(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *opt_tree,
struct opt_proto_item *opt_ti, guint8 opt_len)
{
proto_item *pi = proto_tree_get_parent(opt_tree);
proto_item *ti;
guint32 jumbo_plen = 0;
ipv6_pinfo_t *ipv6_pinfo = p_get_ipv6_pinfo(pinfo);
if (opt_len != 4) {
expert_add_info_format(pinfo, opt_ti->len, &ei_ipv6_opt_invalid_len,
"Jumbo Payload: Invalid length (%u bytes)", opt_len);
}
ti = proto_tree_add_item_ret_uint(opt_tree, hf_ipv6_opt_jumbo, tvb, offset, 4, ENC_BIG_ENDIAN, &jumbo_plen);
offset += 4;
if (ipv6_pinfo != NULL && ipv6_pinfo->ip6_plen != 0) {
expert_add_info(pinfo, pi, &ei_ipv6_opt_jumbo_prohibited);
}
if (jumbo_plen < 65536) {
expert_add_info(pinfo, ti, &ei_ipv6_opt_jumbo_truncated);
}
return offset;
}
static gint
dissect_opt_rpl(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *opt_tree,
struct opt_proto_item *opt_ti, guint8 opt_len)
{
static const int *rpl_flags[] = {
&hf_ipv6_opt_rpl_flag_o,
&hf_ipv6_opt_rpl_flag_r,
&hf_ipv6_opt_rpl_flag_f,
&hf_ipv6_opt_rpl_flag_rsv,
NULL
};
if (opt_len < 4) {
expert_add_info_format(pinfo, opt_ti->len, &ei_ipv6_opt_invalid_len,
"RPL Option: Invalid length (%u bytes)", opt_len);
}
proto_tree_add_bitmask(opt_tree, tvb, offset, hf_ipv6_opt_rpl_flag, ett_ipv6_opt_rpl, rpl_flags, ENC_NA);
offset += 1;
proto_tree_add_item(opt_tree, hf_ipv6_opt_rpl_instance_id, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(opt_tree, hf_ipv6_opt_rpl_senderrank, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static gint
dissect_opt_tel(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *opt_tree,
struct opt_proto_item *opt_ti, guint8 opt_len)
{
if (opt_len != 1) {
expert_add_info_format(pinfo, opt_ti->len, &ei_ipv6_opt_invalid_len,
"Tunnel Encapsulation Limit: Invalid length (%u bytes)", opt_len);
}
proto_tree_add_item(opt_tree, hf_ipv6_opt_tel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static gint
dissect_opt_rtalert(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *opt_tree,
struct opt_proto_item *opt_ti, guint8 opt_len)
{
if (opt_len != 2) {
expert_add_info_format(pinfo, opt_ti->len, &ei_ipv6_opt_invalid_len,
"Router alert: Invalid Length (%u bytes)", opt_len);
}
proto_tree_add_item(opt_tree, hf_ipv6_opt_rtalert, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static gint
dissect_opt_quickstart(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *opt_tree,
struct opt_proto_item *opt_ti, guint8 opt_len, ws_ip *iph)
{
proto_item *pi = proto_tree_get_parent(opt_tree);
proto_item *ti;
guint8 command, function, rate;
guint32 qs_ttl = 0;
if (opt_len != 6) {
expert_add_info_format(pinfo, opt_ti->len, &ei_ipv6_opt_invalid_len,
"Quick-Start: Invalid Length (%u bytes)", opt_len);
}
command = tvb_get_guint8(tvb, offset);
function = command >> 4;
rate = command & QS_RATE_MASK;
proto_tree_add_item(opt_tree, hf_ipv6_opt_qs_func, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (function) {
case QS_RATE_REQUEST:
proto_tree_add_item(opt_tree, hf_ipv6_opt_qs_rate, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item_ret_uint(opt_tree, hf_ipv6_opt_qs_ttl, tvb, offset, 1, ENC_BIG_ENDIAN, &qs_ttl);
proto_item_append_text(pi, ", %s, QS TTL %u",
val_to_str_ext(rate, &qs_rate_vals_ext, "Unknown (%u)"),
qs_ttl);
if (iph != NULL) {
guint8 ttl_diff;
ttl_diff = (iph->ip_ttl - qs_ttl) % 256;
ti = proto_tree_add_uint(opt_tree, hf_ipv6_opt_qs_ttl_diff, tvb, offset, 1, ttl_diff);
PROTO_ITEM_SET_GENERATED(ti);
proto_item_append_text(pi, ", QS TTL diff %u", ttl_diff);
}
offset += 1;
proto_tree_add_item(opt_tree, hf_ipv6_opt_qs_nonce, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_ipv6_opt_qs_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case QS_RATE_REPORT:
proto_tree_add_item(opt_tree, hf_ipv6_opt_qs_rate, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(pi, ", %s", val_to_str_ext(rate, &qs_rate_vals_ext, "Unknown (%u)"));
offset += 1;
proto_tree_add_item(opt_tree, hf_ipv6_opt_qs_unused, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(opt_tree, hf_ipv6_opt_qs_nonce, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_ipv6_opt_qs_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
default:
break;
}
return offset;
}
static gint
dissect_opt_calipso(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *opt_tree,
struct opt_proto_item *opt_ti, guint8 opt_len)
{
guint32 cmpt_length = 0;
if (opt_len < 8) {
expert_add_info_format(pinfo, opt_ti->len, &ei_ipv6_opt_invalid_len,
"CALIPSO: Invalid Length (%u bytes)", opt_len);
}
proto_tree_add_item(opt_tree, hf_ipv6_opt_calipso_doi, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(opt_tree, hf_ipv6_opt_calipso_cmpt_length, tvb,
offset, 1, ENC_BIG_ENDIAN, &cmpt_length);
offset += 1;
proto_tree_add_item(opt_tree, hf_ipv6_opt_calipso_sens_level, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_checksum(opt_tree, tvb, offset, hf_ipv6_opt_calipso_checksum, -1,
NULL, pinfo, 0, ENC_BIG_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
offset += 2;
proto_tree_add_item(opt_tree, hf_ipv6_opt_calipso_cmpt_bitmap, tvb,
offset, cmpt_length*4, ENC_NA);
offset += cmpt_length*4;
return offset;
}
static gint
dissect_opt_smf_dpd(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_, proto_tree *opt_tree,
struct opt_proto_item *opt_ti _U_, guint8 opt_len)
{
guint8 hash_tid;
guint8 tid_len;
gint ident_len;
proto_tree_add_item(opt_tree, hf_ipv6_opt_smf_dpd_hash_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
hash_tid = tvb_get_guint8(tvb, offset);
if (hash_tid & 0x80) {
proto_tree_add_item(opt_tree, hf_ipv6_opt_smf_dpd_hav, tvb, offset, opt_len, ENC_NA);
return offset + opt_len;
}
proto_tree_add_item(opt_tree, hf_ipv6_opt_smf_dpd_tid_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_ipv6_opt_smf_dpd_tid_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ident_len = opt_len - 1;
if (hash_tid & 0x70) {
tid_len = (hash_tid & 0x0f) + 1;
proto_tree_add_item(opt_tree, hf_ipv6_opt_smf_dpd_tagger_id, tvb, offset, tid_len, ENC_NA);
offset += tid_len;
ident_len -= tid_len;
}
if (ident_len > 0) {
proto_tree_add_item(opt_tree, hf_ipv6_opt_smf_dpd_ident, tvb, offset, ident_len, ENC_NA);
offset += ident_len;
}
return offset;
}
static gint
dissect_opt_home_address(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *opt_tree,
struct opt_proto_item *opt_ti, guint8 opt_len)
{
if (opt_len != 16) {
expert_add_info_format(pinfo, opt_ti->len, &ei_ipv6_opt_invalid_len,
"Home Address: Invalid length (%u bytes)", opt_len);
}
proto_tree_add_item(opt_tree, hf_ipv6_opt_mipv6_home_address, tvb, offset, IPv6_ADDR_SIZE, ENC_NA);
alloc_address_tvb_ipv6(pinfo->pool, &pinfo->src, tvb, offset);
offset += IPv6_ADDR_SIZE;
return offset;
}
static gint
dissect_opt_ilnp_nonce(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_, proto_tree *opt_tree,
struct opt_proto_item *opt_ti _U_, guint8 opt_len)
{
proto_tree_add_item(opt_tree, hf_ipv6_opt_ilnp_nonce, tvb, offset, opt_len, ENC_NA);
offset += opt_len;
return offset;
}
static gint
dissect_opt_lio(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_, proto_tree *opt_tree,
struct opt_proto_item *opt_ti _U_, guint8 opt_len)
{
guint32 lid_len = 0;
proto_tree_add_item_ret_uint(opt_tree, hf_ipv6_opt_lio_len, tvb, offset, 1, ENC_BIG_ENDIAN, &lid_len);
offset += 1;
if (lid_len + 1 > opt_len) {
lid_len = opt_len - 1;
}
proto_tree_add_item(opt_tree, hf_ipv6_opt_lio_id, tvb, offset, lid_len, ENC_BIG_ENDIAN|ENC_ASCII);
offset += lid_len;
return offset;
}
static gint
dissect_opt_mpl(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_, proto_tree *opt_tree,
struct opt_proto_item *opt_ti _U_, guint8 opt_len _U_)
{
static const int *mpl_flags[] = {
&hf_ipv6_opt_mpl_flag_s,
&hf_ipv6_opt_mpl_flag_m,
&hf_ipv6_opt_mpl_flag_v,
&hf_ipv6_opt_mpl_flag_rsv,
NULL
};
static const guint8 seed_id_len_arr[4] = {0, 2, 8, 16};
guint8 seed_id_len;
proto_tree_add_bitmask(opt_tree, tvb, offset, hf_ipv6_opt_mpl_flag, ett_ipv6_opt_mpl, mpl_flags, ENC_NA);
seed_id_len = seed_id_len_arr[tvb_get_guint8(tvb, offset) >> 6];
offset +=1;
proto_tree_add_item(opt_tree, hf_ipv6_opt_mpl_sequence, tvb, offset, 1, ENC_NA);
offset +=1;
if (seed_id_len > 0) {
proto_tree_add_item(opt_tree, hf_ipv6_opt_mpl_seed_id, tvb, offset, seed_id_len, ENC_NA);
offset += seed_id_len;
}
return offset;
}
static gint
dissect_opt_dff(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *opt_tree,
struct opt_proto_item *opt_ti, guint8 opt_len)
{
static const int *dff_flags[] = {
&hf_ipv6_opt_dff_flag_ver,
&hf_ipv6_opt_dff_flag_dup,
&hf_ipv6_opt_dff_flag_ret,
&hf_ipv6_opt_dff_flag_rsv,
NULL
};
if (opt_len != 3) {
expert_add_info_format(pinfo, opt_ti->len, &ei_ipv6_opt_invalid_len,
"IPv6 DFF: Invalid length (%u bytes)", opt_len);
}
proto_tree_add_bitmask(opt_tree, tvb, offset, hf_ipv6_opt_dff_flags,
ett_ipv6_opt_dff_flags, dff_flags, ENC_NA);
offset += 1;
proto_tree_add_item(opt_tree, hf_ipv6_opt_dff_seqnum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static gint
dissect_opt_unknown(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *opt_tree,
struct opt_proto_item *opt_ti _U_, guint8 opt_len)
{
proto_item *ti;
ti = proto_tree_add_item(opt_tree, hf_ipv6_opt_unknown, tvb,
offset, opt_len, ENC_NA);
expert_add_info(pinfo, ti, &ei_ipv6_opt_unknown_data);
return offset + opt_len;
}
static int
dissect_opts(tvbuff_t *tvb, int offset, proto_tree *tree, packet_info *pinfo, ws_ip *iph, const int exthdr_proto)
{
gint len, offset_end;
guint8 nxt;
proto_tree *exthdr_tree, *opt_tree, *opt_type_tree, *root_tree;
proto_item *pi, *ti, *ti_len;
int hf_exthdr_item_nxt, hf_exthdr_item_len, hf_exthdr_item_len_oct;
int ett_exthdr_proto;
guint8 opt_type, opt_len, opt_start;
gint opt_hdr_type;
const gchar *opt_name;
gboolean hopopts;
struct opt_proto_item opt_ti;
ipv6_pinfo_t *ipv6_pinfo = p_get_ipv6_pinfo(pinfo);
tvbuff_t *next_tvb;
hopopts = (exthdr_proto == proto_ipv6_hopopts);
nxt = tvb_get_guint8(tvb, offset);
len = (tvb_get_guint8(tvb, offset + 1) + 1) << 3;
offset_end = offset + len;
root_tree = tree;
if (pinfo->dst.type == AT_IPv6) {
ipv6_pinfo->frag_plen -= len;
if (ipv6_pinfo->ipv6_tree != NULL) {
root_tree = ipv6_pinfo->ipv6_tree;
ipv6_pinfo->ipv6_item_len += len;
}
}
ti = proto_tree_add_item(root_tree, exthdr_proto, tvb, offset, len, ENC_NA);
if (hopopts && ipv6_previous_layer_id(pinfo) != proto_ipv6) {
expert_add_info(pinfo, ti, &ei_ipv6_hopopts_not_first);
}
if (exthdr_proto == proto_ipv6_hopopts) {
hf_exthdr_item_nxt = hf_ipv6_hopopts_nxt;
hf_exthdr_item_len = hf_ipv6_hopopts_len;
hf_exthdr_item_len_oct = hf_ipv6_hopopts_len_oct;
ett_exthdr_proto = ett_ipv6_hopopts_proto;
} else if (exthdr_proto == proto_ipv6_dstopts) {
hf_exthdr_item_nxt = hf_ipv6_dstopts_nxt;
hf_exthdr_item_len = hf_ipv6_dstopts_len;
hf_exthdr_item_len_oct = hf_ipv6_dstopts_len_oct;
ett_exthdr_proto = ett_ipv6_dstopts_proto;
} else {
DISSECTOR_ASSERT_NOT_REACHED();
}
exthdr_tree = proto_item_add_subtree(ti, ett_exthdr_proto);
proto_tree_add_item(exthdr_tree, hf_exthdr_item_nxt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti_len = proto_tree_add_item(exthdr_tree, hf_exthdr_item_len, tvb, offset, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_uint(exthdr_tree, hf_exthdr_item_len_oct, tvb, offset, 1, len);
PROTO_ITEM_SET_GENERATED(ti);
if (ipv6_exthdr_hide_len_oct_field) {
PROTO_ITEM_SET_HIDDEN(ti);
proto_item_append_text(ti_len, " (%d bytes)", len);
}
offset += 1;
while (offset < offset_end) {
opt_type = tvb_get_guint8(tvb, offset);
opt_len = tvb_get_guint8(tvb, offset + 1);
opt_name = val_to_str_ext(opt_type, &ipv6_opt_type_vals_ext, "Unknown IPv6 Option (%u)");
pi = proto_tree_add_none_format(exthdr_tree, hf_ipv6_opt, tvb, offset, 2 + opt_len,
"%s", opt_name);
opt_tree = proto_item_add_subtree(pi, ett_ipv6_opt);
opt_ti.type = proto_tree_add_item(opt_tree, hf_ipv6_opt_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (opt_type == IP6OPT_PAD1) {
proto_tree_add_item(opt_tree, hf_ipv6_opt_pad1, tvb, offset, 1, ENC_NA);
offset += 1;
continue;
}
if ((opt_hdr_type = ipv6_opt_type_hdr(opt_type)) != IPv6_OPT_HDR_ANY) {
if (hopopts && (opt_hdr_type == IPv6_OPT_HDR_DST)) {
expert_add_info_format(pinfo, opt_ti.type, &ei_ipv6_opt_header_mismatch,
"%s must use a destination options header", opt_name);
}
else if (!hopopts && (opt_hdr_type == IPv6_OPT_HDR_HBH)) {
expert_add_info_format(pinfo, opt_ti.type, &ei_ipv6_opt_header_mismatch,
"%s must use a hop-by-hop options header", opt_name);
}
}
opt_type_tree = proto_item_add_subtree(opt_ti.type, ett_ipv6_opt_type);
proto_tree_add_item(opt_type_tree, hf_ipv6_opt_type_action, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_type_tree, hf_ipv6_opt_type_change, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_type_tree, hf_ipv6_opt_type_rest, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
opt_ti.len = proto_tree_add_item(opt_tree, hf_ipv6_opt_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (opt_type == IP6OPT_PADN) {
proto_tree_add_item(opt_tree, hf_ipv6_opt_padn, tvb, offset, opt_len, ENC_NA);
offset += opt_len;
continue;
}
opt_start = offset;
switch (opt_type) {
case IP6OPT_JUMBO:
offset = dissect_opt_jumbo(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
break;
case IP6OPT_RPL:
offset = dissect_opt_rpl(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
break;
case IP6OPT_TEL:
offset = dissect_opt_tel(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
break;
case IP6OPT_RTALERT:
offset = dissect_opt_rtalert(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
break;
case IP6OPT_QUICKSTART:
offset = dissect_opt_quickstart(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len, iph);
break;
case IP6OPT_CALIPSO:
offset = dissect_opt_calipso(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
break;
case IP6OPT_SMF_DPD:
offset = dissect_opt_smf_dpd(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
break;
case IP6OPT_HOME_ADDRESS:
offset = dissect_opt_home_address(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
break;
case IP6OPT_ILNP_NONCE:
offset = dissect_opt_ilnp_nonce(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
break;
case IP6OPT_LIO:
offset = dissect_opt_lio(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
break;
case IP6OPT_MPL:
offset = dissect_opt_mpl(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
break;
case IP6OPT_IP_DFF:
offset = dissect_opt_dff(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
break;
case IP6OPT_ENDI:
offset = dissect_opt_unknown(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
expert_add_info(pinfo, opt_ti.type, &ei_ipv6_opt_deprecated);
break;
case IP6OPT_EXP_1E:
case IP6OPT_EXP_3E:
case IP6OPT_EXP_5E:
case IP6OPT_EXP_7E:
case IP6OPT_EXP_9E:
case IP6OPT_EXP_BE:
case IP6OPT_EXP_DE:
case IP6OPT_EXP_FE:
proto_tree_add_item(opt_tree, hf_ipv6_opt_experimental, tvb,
offset, opt_len, ENC_NA);
offset += opt_len;
break;
default:
offset = dissect_opt_unknown(tvb, offset, pinfo, opt_tree, &opt_ti, opt_len);
break;
}
if (offset < opt_start + opt_len) {
ti = proto_tree_add_item(opt_tree, hf_ipv6_opt_unknown_data, tvb,
offset, opt_start + opt_len - offset, ENC_NA);
expert_add_info(pinfo, ti, &ei_ipv6_opt_unknown_data);
offset = opt_start + opt_len;
}
}
p_add_ipv6_nxt(pinfo, nxt);
next_tvb = tvb_new_subset_remaining(tvb, len);
ipv6_dissect_next(nxt, next_tvb, pinfo, tree, iph);
return tvb_captured_length(tvb);
}
static int
dissect_hopopts(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, " , ", "IPv6 hop-by-hop options");
return dissect_opts(tvb, 0, tree, pinfo, (ws_ip *)data, proto_ipv6_hopopts);
}
static int
dissect_dstopts(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, " , ", "IPv6 destination options");
return dissect_opts(tvb, 0, tree, pinfo, (ws_ip *)data, proto_ipv6_dstopts);
}
static guint32
ipv6_get_jumbo_plen(tvbuff_t *tvb, gint offset)
{
gint offset_end, hdr_len;
gint opt_type, opt_len;
guint32 jumbo_plen;
if (!tvb_bytes_exist(tvb, offset, 2)) {
return 0;
}
hdr_len = (tvb_get_guint8(tvb, offset + 1) + 1) * 8;
offset_end = offset + hdr_len;
offset +=2;
while (offset < offset_end && tvb_bytes_exist(tvb, offset, 6)) {
opt_type = tvb_get_guint8(tvb, offset);
offset += 1;
if (opt_type == IP6OPT_PAD1) {
continue;
}
opt_len = tvb_get_guint8(tvb, offset);
offset += 1;
if (opt_type == IP6OPT_JUMBO && opt_len == 4) {
jumbo_plen = tvb_get_guint32(tvb, offset, ENC_BIG_ENDIAN);
if (jumbo_plen > G_MAXUINT16) {
return jumbo_plen;
}
return 0;
}
offset += opt_len;
}
return 0;
}
static void
add_ipv6_address(proto_tree *tree, tvbuff_t *tvb, int offset,
gint hf_addr, gint hf_host)
{
address addr;
const char *name;
proto_item *ti;
proto_tree_add_item(tree, hf_addr, tvb, offset, IPv6_ADDR_SIZE, ENC_NA);
ti = proto_tree_add_item(tree, hf_ipv6_addr, tvb, offset, IPv6_ADDR_SIZE, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
set_address_ipv6_tvb(&addr, tvb, offset);
name = address_to_display(wmem_packet_scope(), &addr);
ti = proto_tree_add_string(tree, hf_host, tvb, offset, IPv6_ADDR_SIZE, name);
PROTO_ITEM_SET_GENERATED(ti);
PROTO_ITEM_SET_HIDDEN(ti);
ti = proto_tree_add_string(tree, hf_ipv6_host, tvb, offset, IPv6_ADDR_SIZE, name);
PROTO_ITEM_SET_GENERATED(ti);
PROTO_ITEM_SET_HIDDEN(ti);
}
static void
add_ipv6_address_6to4(proto_tree *tree, tvbuff_t *tvb, int offset,
gint hf_gateway, gint hf_sla_id)
{
if (tvb_get_ntohs(tvb, offset) != 0x2002)
return;
struct { gint gateway, sla_id; } hf[2] = {
{ hf_gateway, hf_sla_id},
{ hf_ipv6_6to4_gateway_ipv4, hf_ipv6_6to4_sla_id}
};
proto_item *ti;
for (int i = 0; i < 2; i++) {
ti = proto_tree_add_item(tree, hf[i].gateway, tvb, offset + 2, 4, ENC_BIG_ENDIAN);
ADDRESS_SET_GENERATED_HIDDEN(ti);
ti = proto_tree_add_item(tree, hf[i].sla_id, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
ADDRESS_SET_GENERATED_HIDDEN(ti);
}
}
static void
add_ipv6_address_teredo(proto_tree *tree, tvbuff_t *tvb, int offset,
gint hf_server, gint hf_port, gint hf_client)
{
if (tvb_get_ntohl(tvb, offset) != 0x20010000)
return;
guint16 mapped_port = tvb_get_ntohs(tvb, offset + 10) ^ 0xffff;
guint32 client_v4 = tvb_get_ipv4(tvb, offset + 12) ^ 0xffffffff;
struct { gint server, port, client; } hf[2] = {
{ hf_server, hf_port, hf_client },
{ hf_ipv6_teredo_server_ipv4, hf_ipv6_teredo_port, hf_ipv6_teredo_client_ipv4 }
};
proto_item *ti;
for (int i = 0; i < 2; i++) {
ti = proto_tree_add_item(tree, hf[i].server, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
ADDRESS_SET_GENERATED_HIDDEN(ti);
ti = proto_tree_add_uint(tree, hf[i].port, tvb, offset + 10, 2, mapped_port);
ADDRESS_SET_GENERATED_HIDDEN(ti);
ti = proto_tree_add_ipv4(tree, hf[i].client, tvb, offset + 12, 4, client_v4);
ADDRESS_SET_GENERATED_HIDDEN(ti);
}
}
static void
add_ipv6_address_slaac(proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_slaac)
{
if (!(tvb_get_guint8(tvb, offset + 8) & 0x02) ||
!(tvb_get_ntohs(tvb, offset + 11) == 0xfffe)) {
return;
}
guint8 *mac_addr = (guint8 *)wmem_alloc(wmem_packet_scope(), 6);
tvb_memcpy(tvb, mac_addr, offset + 8, 3);
tvb_memcpy(tvb, mac_addr+3, offset + 13, 3);
mac_addr[0] &= ~0x02;
struct { gint mac; } hf[2] = {
{ hf_slaac },
{ hf_ipv6_sa_mac }
};
proto_item *ti;
for (int i = 0; i < 2; i++) {
ti = proto_tree_add_ether(tree, hf[i].mac, tvb, offset + 8, 6, mac_addr);
ADDRESS_SET_GENERATED_HIDDEN(ti);
}
}
static void
add_ipv6_address_isatap(proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_isatap)
{
if ((tvb_get_ntohl(tvb, offset + 8) & 0xfcffffff) != 0x00005efe)
return;
struct { gint ipv4; } hf[2] = {
{ hf_isatap },
{ hf_ipv6_isatap_ipv4 }
};
proto_item *ti;
for (int i = 0; i < 2; i++) {
ti = proto_tree_add_item(tree, hf[i].ipv4, tvb, offset + 12, 4, ENC_BIG_ENDIAN);
ADDRESS_SET_GENERATED_HIDDEN(ti);
}
}
static void
add_ipv6_address_embed_ipv4(proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_embed)
{
static const guint8 ipv6_embedded_ipv4_well_known_prefix[] = {
0x00, 0x64, 0xFF, 0x9B,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};
if (tvb_memeql(tvb, offset, ipv6_embedded_ipv4_well_known_prefix, 12) != 0)
return;
struct { gint embed; } hf[2] = {
{ hf_embed },
{ hf_ipv6_embed_ipv4 }
};
proto_item *ti;
for (int i = 0; i < 2; i++) {
ti = proto_tree_add_item(tree, hf[i].embed, tvb, offset + 12, 4, ENC_NA);
ADDRESS_SET_GENERATED_HIDDEN(ti);
}
}
static int
dissect_ipv6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *ipv6_tree, *pt;
proto_item *ipv6_item, *ti, *pi;
proto_item *ti_ipv6_plen = NULL, *ti_ipv6_version;
guint8 ip6_tcls, ip6_nxt, ip6_hlim;
guint32 ip6_flow;
const struct e_in6_addr *ip6_src, *ip6_dst;
guint32 plen;
int offset;
guint reported_plen;
tvbuff_t *next_tvb;
gboolean save_fragmented;
ipv6_pinfo_t *ipv6_pinfo;
int version;
ws_ip *iph;
struct ws_ip6_hdr *ip6_hdr;
offset = 0;
ipv6_pinfo = wmem_new0(pinfo->pool, ipv6_pinfo_t);
p_add_proto_data(pinfo->pool, pinfo, proto_ipv6, IPV6_PROTO_PINFO, ipv6_pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPv6");
col_clear(pinfo->cinfo, COL_INFO);
ipv6_item = proto_tree_add_item(tree, proto_ipv6, tvb, offset, IPv6_HDR_SIZE, ENC_NA);
ipv6_tree = proto_item_add_subtree(ipv6_item, ett_ipv6_proto);
if (!ipv6_exthdr_under_root) {
ipv6_pinfo->ipv6_tree = ipv6_tree;
ipv6_pinfo->ipv6_item_len = IPv6_HDR_SIZE;
}
version = tvb_get_bits8(tvb, (offset + IP6H_CTL_VFC) * 8, 4);
ti_ipv6_version = proto_tree_add_item(ipv6_tree, hf_ipv6_version, tvb,
offset + IP6H_CTL_VFC, 1, ENC_BIG_ENDIAN);
pi = proto_tree_add_item(ipv6_tree, hf_ip_version, tvb,
offset + IP6H_CTL_VFC, 1, ENC_BIG_ENDIAN);
proto_item_append_text(pi, " [This field makes the filter match on \"ip.version == 6\" possible]");
PROTO_ITEM_SET_HIDDEN(pi);
if (version != 6) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Bogus IPv6 version (%u, must be 6)", version);
expert_add_info_format(pinfo, ti_ipv6_version, &ei_ipv6_bogus_ipv6_version, "Bogus IPv6 version");
return offset + IP6H_CTL_VFC;
}
if (tvb_reported_length(tvb) < IPv6_HDR_SIZE) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Invalid IPv6 header (%u bytes, need exactly 40)",
tvb_reported_length(tvb));
expert_add_info_format(pinfo, ipv6_item, &ei_ipv6_invalid_header,
"IPv6 header must be exactly 40 bytes");
}
ti = proto_tree_add_item(ipv6_tree, hf_ipv6_tclass, tvb,
offset + IP6H_CTL_VFC, 4, ENC_BIG_ENDIAN);
ip6_tcls = tvb_get_bits8(tvb, (offset + IP6H_CTL_VFC) * 8 + 4, 8);
proto_item_append_text(ti, " (DSCP: %s, ECN: %s)",
val_to_str_ext_const(IPDSFIELD_DSCP(ip6_tcls), &dscp_short_vals_ext, "Unknown"),
val_to_str_ext_const(IPDSFIELD_ECN(ip6_tcls), &ecn_short_vals_ext, "Unknown"));
pt = proto_item_add_subtree(ti, ett_ipv6_traffic_class);
proto_tree_add_item(pt, hf_ipv6_tclass_dscp, tvb,
offset + IP6H_CTL_VFC, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_ipv6_tclass_ecn, tvb,
offset + IP6H_CTL_VFC, 4, ENC_BIG_ENDIAN);
col_add_str(pinfo->cinfo, COL_DSCP_VALUE,
val_to_str_ext(IPDSFIELD_DSCP(ip6_tcls), &dscp_short_vals_ext, "%u"));
proto_tree_add_item_ret_uint(ipv6_tree, hf_ipv6_flow, tvb,
offset + IP6H_CTL_FLOW, 4, ENC_BIG_ENDIAN, &ip6_flow);
ti_ipv6_plen = proto_tree_add_item(ipv6_tree, hf_ipv6_plen, tvb,
offset + IP6H_CTL_PLEN, 2, ENC_BIG_ENDIAN);
ipv6_pinfo->ip6_plen = tvb_get_guint16(tvb, offset + IP6H_CTL_PLEN, ENC_BIG_ENDIAN);
ipv6_pinfo->frag_plen = ipv6_pinfo->ip6_plen;
proto_tree_add_item(ipv6_tree, hf_ipv6_nxt, tvb, offset + IP6H_CTL_NXT, 1, ENC_NA);
ip6_nxt = tvb_get_guint8(tvb, offset + IP6H_CTL_NXT);
proto_tree_add_item(ipv6_tree, hf_ipv6_hlim, tvb,
offset + IP6H_CTL_HLIM, 1, ENC_BIG_ENDIAN);
ip6_hlim = tvb_get_guint8(tvb, offset + IP6H_CTL_HLIM);
add_ipv6_address(ipv6_tree, tvb, offset + IP6H_SRC, hf_ipv6_src, hf_ipv6_src_host);
ip6_src = tvb_get_ptr_ipv6(tvb, offset + IP6H_SRC);
alloc_address_wmem_ipv6(pinfo->pool, &pinfo->net_src, ip6_src);
copy_address_shallow(&pinfo->src, &pinfo->net_src);
add_ipv6_address(ipv6_tree, tvb, offset + IP6H_DST, hf_ipv6_dst, hf_ipv6_dst_host);
ip6_dst = tvb_get_ptr_ipv6(tvb, offset + IP6H_DST);
alloc_address_wmem_ipv6(pinfo->pool, &pinfo->net_dst, ip6_dst);
copy_address_shallow(&pinfo->dst, &pinfo->net_dst);
if (tree) {
if (ipv6_summary_in_tree) {
proto_item_append_text(ipv6_item, ", Src: %s, Dst: %s",
address_with_resolution_to_str(wmem_packet_scope(), &pinfo->src),
address_with_resolution_to_str(wmem_packet_scope(), &pinfo->dst));
}
add_ipv6_address_6to4(ipv6_tree, tvb, offset + IP6H_SRC,
hf_ipv6_src_6to4_gateway_ipv4, hf_ipv6_src_6to4_sla_id);
add_ipv6_address_6to4(ipv6_tree, tvb, offset + IP6H_DST,
hf_ipv6_dst_6to4_gateway_ipv4, hf_ipv6_dst_6to4_sla_id);
add_ipv6_address_teredo(ipv6_tree, tvb, offset + IP6H_SRC,
hf_ipv6_src_teredo_server_ipv4, hf_ipv6_src_teredo_port, hf_ipv6_src_teredo_client_ipv4);
add_ipv6_address_teredo(ipv6_tree, tvb, offset + IP6H_DST,
hf_ipv6_dst_teredo_server_ipv4, hf_ipv6_dst_teredo_port, hf_ipv6_dst_teredo_client_ipv4);
add_ipv6_address_slaac(ipv6_tree, tvb, offset + IP6H_SRC, hf_ipv6_src_sa_mac);
add_ipv6_address_slaac(ipv6_tree, tvb, offset + IP6H_DST, hf_ipv6_dst_sa_mac);
add_ipv6_address_isatap(ipv6_tree, tvb, offset + IP6H_SRC, hf_ipv6_src_isatap_ipv4);
add_ipv6_address_isatap(ipv6_tree, tvb, offset + IP6H_DST, hf_ipv6_dst_isatap_ipv4);
add_ipv6_address_embed_ipv4(ipv6_tree, tvb, offset + IP6H_SRC, hf_ipv6_src_embed_ipv4);
add_ipv6_address_embed_ipv4(ipv6_tree, tvb, offset + IP6H_DST, hf_ipv6_dst_embed_ipv4);
}
#ifdef HAVE_GEOIP_V6
if (tree && ipv6_use_geoip) {
add_geoip_info(ipv6_tree, tvb, offset, ip6_src, ip6_dst);
}
#endif
ip6_hdr = (struct ws_ip6_hdr *)tvb_memdup(wmem_packet_scope(), tvb, offset, IPv6_HDR_SIZE);
tap_queue_packet(ip6_hdr_tap, pinfo, ip6_hdr);
offset += IPv6_HDR_SIZE;
plen = ipv6_pinfo->ip6_plen;
if (plen == 0 && ip6_nxt == IP_PROTO_HOPOPTS) {
ipv6_pinfo->jumbo_plen = ipv6_get_jumbo_plen(tvb, offset);
if (ipv6_pinfo->jumbo_plen != 0) {
proto_item_append_text(ti_ipv6_plen, " (Jumbogram)");
plen = ipv6_pinfo->jumbo_plen;
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "Invalid IPv6 payload length");
expert_add_info(pinfo, ti_ipv6_plen, &ei_ipv6_opt_jumbo_missing);
}
}
reported_plen = tvb_reported_length(tvb) - IPv6_HDR_SIZE;
if (!pinfo->flags.in_error_pkt && plen > reported_plen) {
expert_add_info_format(pinfo, ti_ipv6_plen, &ei_ipv6_plen_exceeds_framing,
"IPv6 payload length exceeds framing length (%d bytes)", reported_plen);
}
iph = wmem_new0(wmem_packet_scope(), ws_ip);
iph->ip_ver = 6;
iph->ip_tos = ip6_tcls;
iph->ip_flw = ip6_flow;
iph->ip_len = plen;
iph->ip_nxt = ip6_nxt;
iph->ip_ttl = ip6_hlim;
alloc_address_wmem_ipv6(wmem_packet_scope(), &iph->ip_src, ip6_src);
alloc_address_wmem_ipv6(wmem_packet_scope(), &iph->ip_dst, ip6_dst);
set_actual_length(tvb, IPv6_HDR_SIZE + plen);
save_fragmented = pinfo->fragmented;
p_add_ipv6_nxt(pinfo, ip6_nxt);
next_tvb = tvb_new_subset_remaining(tvb, offset);
ipv6_dissect_next(ip6_nxt, next_tvb, pinfo, tree, iph);
pinfo->fragmented = save_fragmented;
return tvb_captured_length(tvb);
}
void
ipv6_dissect_next(guint nxt, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, ws_ip *iph)
{
dissector_handle_t nxt_handle;
ipv6_pinfo_t *ipv6_pinfo;
switch (nxt) {
case IP_PROTO_HOPOPTS:
case IP_PROTO_ROUTING:
case IP_PROTO_FRAGMENT:
case IP_PROTO_DSTOPTS:
case IP_PROTO_AH:
case IP_PROTO_MIPV6:
case IP_PROTO_SHIM6:
nxt_handle = dissector_get_uint_handle(ip_dissector_table, nxt);
break;
default:
nxt_handle = NULL;
break;
}
if (nxt_handle != NULL) {
call_dissector_with_data(nxt_handle, tvb, pinfo, tree, iph);
return;
}
if (pinfo->dst.type == AT_IPv6) {
ipv6_pinfo = p_get_ipv6_pinfo(pinfo);
if (ipv6_pinfo->ipv6_tree != NULL) {
proto_item_set_len(proto_tree_get_parent(ipv6_pinfo->ipv6_tree), ipv6_pinfo->ipv6_item_len);
ipv6_pinfo->ipv6_tree = NULL;
}
if (iph != NULL) {
iph->ip_nxt = nxt;
tap_queue_packet(ipv6_ws_tap, pinfo, iph);
}
}
if (nxt == IP_PROTO_NONE) {
col_set_str(pinfo->cinfo, COL_INFO, "IPv6 no next header");
call_data_dissector(tvb, pinfo, tree);
return;
}
if (ip_try_dissect(try_heuristic_first, nxt, tvb, pinfo, tree, iph)) {
return;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown IP Protocol: %s (%u)", ipprotostr(nxt), nxt);
call_data_dissector(tvb, pinfo, tree);
}
void
proto_register_ipv6(void)
{
static hf_register_info hf_ipv6[] = {
{ &hf_ipv6_version,
{ "Version", "ipv6.version",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_ip_version,
{ "Version", "ip.version",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_ipv6_tclass,
{ "Traffic Class", "ipv6.tclass",
FT_UINT32, BASE_HEX, NULL, 0x0FF00000,
NULL, HFILL }
},
{ &hf_ipv6_tclass_dscp,
{ "Differentiated Services Codepoint", "ipv6.tclass.dscp",
FT_UINT32, BASE_DEC | BASE_EXT_STRING, &dscp_vals_ext, 0x0FC00000,
NULL, HFILL }
},
{ &hf_ipv6_tclass_ecn,
{ "Explicit Congestion Notification", "ipv6.tclass.ecn",
FT_UINT32, BASE_DEC | BASE_EXT_STRING, &ecn_vals_ext, 0x00300000,
NULL, HFILL }
},
{ &hf_ipv6_flow,
{ "Flow Label", "ipv6.flow",
FT_UINT32, BASE_HEX, NULL, 0x000FFFFF,
NULL, HFILL }
},
{ &hf_ipv6_plen,
{ "Payload Length", "ipv6.plen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_nxt,
{ "Next Header", "ipv6.nxt",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ipproto_val_ext, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_hlim,
{ "Hop Limit", "ipv6.hlim",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_src,
{ "Source", "ipv6.src",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Source IPv6 Address", HFILL }
},
{ &hf_ipv6_src_host,
{ "Source Host", "ipv6.src_host",
FT_STRING, BASE_NONE, NULL, 0x0,
"Source IPv6 Host", HFILL }
},
{ &hf_ipv6_src_sa_mac,
{ "Source SA MAC", "ipv6.src_sa_mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Source IPv6 Stateless Autoconfiguration MAC Address", HFILL }
},
{ &hf_ipv6_src_isatap_ipv4,
{ "Source ISATAP IPv4", "ipv6.src_isatap_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Source IPv6 ISATAP Encapsulated IPv4 Address", HFILL }
},
{ &hf_ipv6_src_6to4_gateway_ipv4,
{ "Source 6to4 Gateway IPv4", "ipv6.src_6to4_gw_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Source IPv6 6to4 Gateway IPv4 Address", HFILL }
},
{ &hf_ipv6_src_6to4_sla_id,
{ "Source 6to4 SLA ID", "ipv6.src_6to4_sla_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Source IPv6 6to4 SLA ID", HFILL }
},
{ &hf_ipv6_src_teredo_server_ipv4,
{ "Source Teredo Server IPv4", "ipv6.src_ts_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Source IPv6 Teredo Server Encapsulated IPv4 Address", HFILL }
},
{ &hf_ipv6_src_teredo_port,
{ "Source Teredo Port", "ipv6.src_tc_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Source IPv6 Teredo Client Mapped Port", HFILL }
},
{ &hf_ipv6_src_teredo_client_ipv4,
{ "Source Teredo Client IPv4", "ipv6.src_tc_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Source IPv6 Teredo Client Encapsulated IPv4 Address", HFILL }
},
{ &hf_ipv6_src_embed_ipv4,
{ "Source Embedded IPv4", "ipv6.src_embed_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Source IPv4-Embedded IPv6 Address with Well-Known Prefix", HFILL }
},
{ &hf_ipv6_dst,
{ "Destination", "ipv6.dst",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Destination IPv6 Address", HFILL }
},
{ &hf_ipv6_dst_host,
{ "Destination Host", "ipv6.dst_host",
FT_STRING, BASE_NONE, NULL, 0x0,
"Destination IPv6 Host", HFILL }
},
{ &hf_ipv6_dst_sa_mac,
{ "Destination SA MAC", "ipv6.dst_sa_mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Destination IPv6 Stateless Autoconfiguration MAC Address", HFILL }
},
{ &hf_ipv6_dst_isatap_ipv4,
{ "Destination ISATAP IPv4", "ipv6.dst_isatap_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Destination IPv6 ISATAP Encapsulated IPv4 Address", HFILL }
},
{ &hf_ipv6_dst_6to4_gateway_ipv4,
{ "Destination 6to4 Gateway IPv4", "ipv6.dst_6to4_gw_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Destination IPv6 6to4 Gateway IPv4 Address", HFILL }
},
{ &hf_ipv6_dst_6to4_sla_id,
{ "Destination 6to4 SLA ID", "ipv6.dst_6to4_sla_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Destination IPv6 6to4 SLA ID", HFILL }
},
{ &hf_ipv6_dst_teredo_server_ipv4,
{ "Destination Teredo Server IPv4", "ipv6.dst_ts_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Destination IPv6 Teredo Server Encapsulated IPv4 Address", HFILL }
},
{ &hf_ipv6_dst_teredo_port,
{ "Destination Teredo Port", "ipv6.dst_tc_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Destination IPv6 Teredo Client Mapped Port", HFILL }
},
{ &hf_ipv6_dst_teredo_client_ipv4,
{ "Destination Teredo Client IPv4", "ipv6.dst_tc_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Destination IPv6 Teredo Client Encapsulated IPv4 Address", HFILL }
},
{ &hf_ipv6_dst_embed_ipv4,
{ "Destination Embedded IPv4", "ipv6.dst_embed_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Destination IPv4-Embedded IPv6 Address with Well-Known Prefix", HFILL }
},
{ &hf_ipv6_addr,
{ "Source or Destination Address", "ipv6.addr",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_host,
{ "Source or Destination Host", "ipv6.host",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_sa_mac,
{ "SA MAC", "ipv6.sa_mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
"IPv6 Stateless Autoconfiguration MAC Address", HFILL }
},
{ &hf_ipv6_isatap_ipv4,
{ "ISATAP IPv4", "ipv6.isatap_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"IPv6 ISATAP Encapsulated IPv4 Address", HFILL }
},
{ &hf_ipv6_6to4_gateway_ipv4,
{ "6to4 Gateway IPv4", "ipv6.6to4_gw_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"IPv6 6to4 Gateway IPv4 Address", HFILL }
},
{ &hf_ipv6_6to4_sla_id,
{ "6to4 SLA ID", "ipv6.6to4_sla_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"IPv6 6to4 SLA ID", HFILL }
},
{ &hf_ipv6_teredo_server_ipv4,
{ "Teredo Server IPv4", "ipv6.ts_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"IPv6 Teredo Server Encapsulated IPv4 Address", HFILL }
},
{ &hf_ipv6_teredo_port,
{ "Teredo Port", "ipv6.tc_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"IPv6 Teredo Client Mapped Port", HFILL }
},
{ &hf_ipv6_teredo_client_ipv4,
{ "Teredo Client IPv4", "ipv6.tc_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"IPv6 Teredo Client Encapsulated IPv4 Address", HFILL }
},
{ &hf_ipv6_embed_ipv4,
{ "Embedded IPv4", "ipv6.embed_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"IPv4-Embedded IPv6 Address with Well-Known Prefix", HFILL }
},
#ifdef HAVE_GEOIP_V6
{ &hf_geoip_country,
{ "Source or Destination GeoIP Country", "ipv6.geoip.country",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_city,
{ "Source or Destination GeoIP City", "ipv6.geoip.city",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_org,
{ "Source or Destination GeoIP Organization", "ipv6.geoip.org",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_isp,
{ "Source or Destination GeoIP ISP", "ipv6.geoip.isp",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_asnum,
{ "Source or Destination GeoIP AS Number", "ipv6.geoip.asnum",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_lat,
{ "Source or Destination GeoIP Latitude", "ipv6.geoip.lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_lon,
{ "Source or Destination GeoIP Longitude", "ipv6.geoip.lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_src_country,
{ "Source GeoIP Country", "ipv6.geoip.src_country",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_src_city,
{ "Source GeoIP City", "ipv6.geoip.src_city",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_src_org,
{ "Source GeoIP Organization", "ipv6.geoip.src_org",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_src_isp,
{ "Source GeoIP ISP", "ipv6.geoip.src_isp",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_src_asnum,
{ "Source GeoIP AS Number", "ipv6.geoip.src_asnum",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_src_lat,
{ "Source GeoIP Latitude", "ipv6.geoip.src_lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_src_lon,
{ "Source GeoIP Longitude", "ipv6.geoip.src_lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_dst_country,
{ "Destination GeoIP Country", "ipv6.geoip.dst_country",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_dst_city,
{ "Destination GeoIP City", "ipv6.geoip.dst_city",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_dst_org,
{ "Destination GeoIP Organization", "ipv6.geoip.dst_org",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_dst_isp,
{ "Destination GeoIP ISP", "ipv6.geoip.dst_isp",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_dst_asnum,
{ "Destination GeoIP AS Number", "ipv6.geoip.dst_asnum",
FT_STRING, STR_UNICODE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_dst_lat,
{ "Destination GeoIP Latitude", "ipv6.geoip.dst_lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geoip_dst_lon,
{ "Destination GeoIP Longitude", "ipv6.geoip.dst_lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_ipv6_opt,
{ "IPv6 Option", "ipv6.opt",
FT_NONE, BASE_NONE, NULL, 0x0,
"Option", HFILL }
},
{ &hf_ipv6_opt_type,
{ "Type", "ipv6.opt.type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &ipv6_opt_type_vals_ext, 0x0,
"Option type", HFILL }
},
{ &hf_ipv6_opt_type_action,
{ "Action", "ipv6.opt.type.action",
FT_UINT8, BASE_DEC, VALS(ipv6_opt_type_action_vals), 0xC0,
"Action for unrecognized option type", HFILL }
},
{ &hf_ipv6_opt_type_change,
{ "May Change", "ipv6.opt.type.change",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
"Whether the option data may change en-route", HFILL }
},
{ &hf_ipv6_opt_type_rest,
{ "Low-Order Bits", "ipv6.opt.type.rest",
FT_UINT8, BASE_HEX, NULL, 0x1F,
"Remaining low-order bits", HFILL }
},
{ &hf_ipv6_opt_length,
{ "Length", "ipv6.opt.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option length in octets", HFILL }
},
{ &hf_ipv6_opt_pad1,
{ "Pad1", "ipv6.opt.pad1",
FT_NONE, BASE_NONE, NULL, 0x0,
"Pad1 Option", HFILL }
},
{ &hf_ipv6_opt_padn,
{ "PadN", "ipv6.opt.padn",
FT_BYTES, BASE_NONE|BASE_ALLOW_ZERO, NULL, 0x0,
"PadN Option", HFILL }
},
{ &hf_ipv6_opt_rtalert,
{ "Router Alert", "ipv6.opt.router_alert",
FT_UINT16, BASE_DEC, VALS(ipv6_opt_rtalert_vals), 0x0,
"Router Alert Option", HFILL }
},
{ &hf_ipv6_opt_tel,
{ "Tunnel Encapsulation Limit", "ipv6.opt.tel",
FT_UINT8, BASE_DEC, NULL, 0x0,
"How many further levels of encapsulation are permitted", HFILL }
},
{ &hf_ipv6_opt_jumbo,
{ "Payload Length", "ipv6.opt.jumbo",
FT_UINT32, BASE_DEC, NULL, 0x0,
"IPv6 (Jumbo) Payload Length", HFILL }
},
{ &hf_ipv6_opt_calipso_doi,
{ "CALIPSO Domain of Interpretation", "ipv6.opt.calipso.doi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_calipso_cmpt_length,
{ "Compartment Length", "ipv6.opt.calipso.cmpt.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_calipso_sens_level,
{ "Sensitivity Level", "ipv6.opt.calipso.sens_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_calipso_checksum,
{ "Checksum", "ipv6.opt.calipso.checksum",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_calipso_cmpt_bitmap,
{ "Compartment Bitmap", "ipv6.opt.calipso.cmpt_bitmap",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_smf_dpd_hash_bit,
{ "H-bit", "ipv6.opt.smf_dpd.hash_bit",
FT_BOOLEAN, 8, NULL, 0x80,
"Hash indicator", HFILL }
},
{ &hf_ipv6_opt_smf_dpd_tid_type,
{ "TaggerID Type", "ipv6.opt.smf_dpd.tid_type",
FT_UINT8, BASE_DEC, VALS(ipv6_opt_smf_dpd_tidty_vals), 0x70,
NULL, HFILL }
},
{ &hf_ipv6_opt_smf_dpd_tid_len,
{ "TaggerID Length", "ipv6.opt.smf_dpd.tid_len",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_ipv6_opt_smf_dpd_tagger_id,
{ "TaggerID", "ipv6.opt.smf_dpd.tagger_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_smf_dpd_ident,
{ "Identifier", "ipv6.opt.smf_dpd.ident",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_smf_dpd_hav,
{ "Hash Assist Value", "ipv6.opt.smf_dpd.hav",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_qs_func,
{ "Function", "ipv6.opt.qs_func",
FT_UINT8, BASE_DEC, VALS(qs_func_vals), QS_FUNC_MASK,
NULL, HFILL }
},
{ &hf_ipv6_opt_qs_rate,
{ "Rate", "ipv6.opt.qs_rate",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &qs_rate_vals_ext, QS_RATE_MASK,
NULL, HFILL }
},
{ &hf_ipv6_opt_qs_ttl,
{ "QS TTL", "ipv6.opt.qs_ttl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_qs_ttl_diff,
{ "TTL Diff", "ipv6.opt.qs_ttl_diff",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_qs_unused,
{ "Not Used", "ipv6.opt.qs_unused",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_qs_nonce,
{ "QS Nonce", "ipv6.opt.qs_nonce",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFC,
NULL, HFILL }
},
{ &hf_ipv6_opt_qs_reserved,
{ "Reserved", "ipv6.opt.qs_reserved",
FT_UINT32, BASE_HEX, NULL, 0x0003,
NULL, HFILL }
},
{ &hf_ipv6_opt_mipv6_home_address,
{ "MIPv6 Home Address", "ipv6.opt.mipv6.home_address",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_rpl_flag,
{ "Flag", "ipv6.opt.rpl.flag",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_rpl_flag_o,
{ "Down", "ipv6.opt.rpl.flag.o",
FT_BOOLEAN, 8, NULL, 0x80,
"The packet is expected to progress Up or Down", HFILL }
},
{ &hf_ipv6_opt_rpl_flag_r,
{ "Rank Error", "ipv6.opt.rpl.flag.r",
FT_BOOLEAN, 8, NULL, 0x40,
"Whether a rank error was detected", HFILL }
},
{ &hf_ipv6_opt_rpl_flag_f,
{ "Forwarding Error", "ipv6.opt.rpl.flag.f",
FT_BOOLEAN, 8, NULL, 0x20,
"Set if the node cannot forward the packet further towards the destination", HFILL }
},
{ &hf_ipv6_opt_rpl_flag_rsv,
{ "Reserved", "ipv6.opt.rpl.flag.rsv",
FT_UINT8, BASE_HEX, NULL, 0x1F,
"Reserved (must be zero)", HFILL }
},
{ &hf_ipv6_opt_rpl_instance_id,
{ "RPLInstanceID", "ipv6.opt.rpl.instance_id",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The DODAG instance along which the packet is sent", HFILL }
},
{ &hf_ipv6_opt_rpl_senderrank,
{ "Sender Rank", "ipv6.opt.rpl.sender_rank",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Set to zero by the source and to DAGRank(rank) by a router that forwards inside the RPL network", HFILL }
},
{ &hf_ipv6_opt_ilnp_nonce,
{ "ILNP Nonce", "ipv6.opt.ilnp_nonce",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_lio_len,
{ "LineIDLen", "ipv6.opt.lio.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_lio_id,
{ "Line ID", "ipv6.opt.lio.line_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_mpl_flag,
{ "Flag", "ipv6.opt.mpl.flag",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_mpl_flag_s,
{ "Seed ID Length", "ipv6.opt.mpl.flag.s",
FT_UINT8, BASE_DEC, NULL, 0xC0,
"Identifies the length of Seed ID", HFILL }
},
{ &hf_ipv6_opt_mpl_flag_m,
{ "Largest Sequence", "ipv6.opt.mpl.flag.m",
FT_BOOLEAN, 8, NULL, 0x20,
"Indicates Sequence is known to be the largest sequence number", HFILL }
},
{ &hf_ipv6_opt_mpl_flag_v,
{ "Version", "ipv6.opt.mpl.flag.v",
FT_BOOLEAN, 8, NULL, 0x10,
"0 indicates this option conforms to RFC<TBC>", HFILL }
},
{ &hf_ipv6_opt_mpl_flag_rsv,
{ "Reserved", "ipv6.opt.mpl.flag.rsv",
FT_UINT8, BASE_HEX, NULL, 0x0F,
"Reserved (must be zero)", HFILL }
},
{ &hf_ipv6_opt_mpl_sequence,
{ "Sequence", "ipv6.opt.mpl.sequence",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Identifies relative ordering of MPL Data Messages from the MPL Seed identified by Seed ID", HFILL }
},
{ &hf_ipv6_opt_mpl_seed_id,
{ "Seed ID", "ipv6.opt.mpl.seed_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Uniquely identifies the MPL Seed that initiated dissemination of the MPL Data Message", HFILL }
},
{ &hf_ipv6_opt_dff_flags,
{ "Flags", "ipv6.opt.dff.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_dff_flag_ver,
{ "Version (VER)", "ipv6.opt.dff.flag.ver",
FT_UINT8, BASE_DEC, NULL, 0xC0,
"The version of DFF that is used", HFILL }
},
{ &hf_ipv6_opt_dff_flag_dup,
{ "Duplicate (DUP)", "ipv6.opt.dff.flag.dup",
FT_BOOLEAN, 8, NULL, 0x20,
"Indicates the packet is being retransmitted", HFILL }
},
{ &hf_ipv6_opt_dff_flag_ret,
{ "Return (RET)", "ipv6.opt.dff.flag.ret",
FT_BOOLEAN, 8, NULL, 0x10,
"Must be set to 1 prior to sending the packet back to the Previous Hop", HFILL }
},
{ &hf_ipv6_opt_dff_flag_rsv,
{ "Reserved", "ipv6.opt.dff.flag.rsv",
FT_UINT8, BASE_HEX, NULL, 0x0F,
"Reserved (must be zero)", HFILL }
},
{ &hf_ipv6_opt_dff_seqnum,
{ "Sequence Number", "ipv6.opt.dff.sequence_number",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_experimental,
{ "Experimental Option", "ipv6.opt.experimental",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_opt_unknown_data,
{ "Unknown Data", "ipv6.opt_unknown_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Not interpreted data", HFILL }
},
{ &hf_ipv6_opt_unknown,
{ "Unknown Option Payload", "ipv6.opt.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_fragment,
{ "IPv6 Fragment", "ipv6.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_fragment_overlap,
{ "Fragment overlap", "ipv6.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }
},
{ &hf_ipv6_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "ipv6.fragment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }
},
{ &hf_ipv6_fragment_multiple_tails,
{ "Multiple tail fragments found", "ipv6.fragment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }
},
{ &hf_ipv6_fragment_too_long_fragment,
{ "Fragment too long", "ipv6.fragment.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }
},
{ &hf_ipv6_fragment_error,
{ "Defragmentation error", "ipv6.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }
},
{ &hf_ipv6_fragment_count,
{ "Fragment count", "ipv6.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_fragments,
{ "IPv6 Fragments", "ipv6.fragments",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_reassembled_in,
{ "Reassembled IPv6 in frame", "ipv6.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This IPv6 packet is reassembled in this frame", HFILL }
},
{ &hf_ipv6_reassembled_length,
{ "Reassembled IPv6 length", "ipv6.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }
},
{ &hf_ipv6_reassembled_data,
{ "Reassembled IPv6 data", "ipv6.reassembled.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"The reassembled payload", HFILL }
}
};
static hf_register_info hf_ipv6_hopopts[] = {
{ &hf_ipv6_hopopts_nxt,
{ "Next Header", "ipv6.hopopts.nxt",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ipproto_val_ext, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_hopopts_len,
{ "Length", "ipv6.hopopts.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Extension header length in 8-octet words (minus 1)", HFILL }
},
{ &hf_ipv6_hopopts_len_oct,
{ "Length", "ipv6.hopopts.len_oct",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, 0x0,
"Extension header length in octets", HFILL }
}
};
static hf_register_info hf_ipv6_dstopts[] = {
{ &hf_ipv6_dstopts_nxt,
{ "Next Header", "ipv6.dstopts.nxt",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ipproto_val_ext, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_dstopts_len,
{ "Length", "ipv6.dstopts.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Extension header length in 8-octet words (minus 1)", HFILL }
},
{ &hf_ipv6_dstopts_len_oct,
{ "Length", "ipv6.dstopts.len_oct",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, 0x0,
"Extension header length in octets", HFILL }
}
};
static hf_register_info hf_ipv6_routing[] = {
{ &hf_ipv6_routing_nxt,
{ "Next Header", "ipv6.routing.nxt",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ipproto_val_ext, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_routing_len,
{ "Length", "ipv6.routing.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Extension header length in 8-octet words (minus 1)", HFILL }
},
{ &hf_ipv6_routing_len_oct,
{ "Length", "ipv6.routing.len_oct",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, 0x0,
"Extension header length in octets", HFILL }
},
{ &hf_ipv6_routing_type,
{ "Type", "ipv6.routing.type",
FT_UINT8, BASE_DEC, VALS(routing_header_type), 0x0,
"Routing Header Type", HFILL }
},
{ &hf_ipv6_routing_segleft,
{ "Segments Left", "ipv6.routing.segleft",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Routing Header Segments Left", HFILL }
},
{ &hf_ipv6_routing_unknown_data,
{ "Type-Specific Data", "ipv6.routing.unknown_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Unknown routing header type-specific data", HFILL }
},
{ &hf_ipv6_routing_src_reserved,
{ "Reserved", "ipv6.routing.src.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Must be zero", HFILL }
},
{ &hf_ipv6_routing_src_addr,
{ "Address", "ipv6.routing.src.addr",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Source Routing Header Address", HFILL }},
{ &hf_ipv6_routing_mipv6_reserved,
{ "Reserved", "ipv6.routing.mipv6.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Must be zero", HFILL }
},
{ &hf_ipv6_routing_mipv6_home_address,
{ "Home Address", "ipv6.routing.mipv6.home_address",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_routing_rpl_cmprI,
{ "Compressed Internal Octets (CmprI)", "ipv6.routing.rpl.cmprI",
FT_UINT32, BASE_DEC, NULL, IP6RRPL_BITMASK_CMPRI,
"Elided octets from all but last segment", HFILL }
},
{ &hf_ipv6_routing_rpl_cmprE,
{ "Compressed Final Octets (CmprE)", "ipv6.routing.rpl.cmprE",
FT_UINT32, BASE_DEC, NULL, IP6RRPL_BITMASK_CMPRE,
"Elided octets from last segment address", HFILL }
},
{ &hf_ipv6_routing_rpl_pad,
{ "Padding Bytes", "ipv6.routing.rpl.pad",
FT_UINT32, BASE_DEC, NULL, IP6RRPL_BITMASK_PAD,
NULL, HFILL }
},
{ &hf_ipv6_routing_rpl_reserved,
{ "Reserved", "ipv6.routing.rpl.reserved",
FT_UINT32, BASE_DEC, NULL, IP6RRPL_BITMASK_RESERVED,
"Must be zero", HFILL }
},
{ &hf_ipv6_routing_rpl_addr_count,
{ "Total Address Count", "ipv6.routing.rpl.addr_count",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ipv6_routing_rpl_addr,
{ "Address", "ipv6.routing.rpl.address",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ipv6_routing_rpl_fulladdr,
{ "Full Address", "ipv6.routing.rpl.full_address",
FT_IPv6, BASE_NONE, NULL, 0,
"Uncompressed IPv6 Address", HFILL }
},
{ &hf_ipv6_routing_srh_first_seg,
{ "First segment", "ipv6.routing.srh.first_segment",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Index of the first segment", HFILL }
},
{ &hf_ipv6_routing_srh_flags,
{ "Flags", "ipv6.routing.srh.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_routing_srh_flag_unused1,
{ "Unused", "ipv6.routing.srh.flag_unused1",
FT_UINT8, BASE_HEX, NULL, 0x80,
"Unset on transmission and ignored on receipt", HFILL }
},
{ &hf_ipv6_routing_srh_flag_p,
{ "Protected", "ipv6.routing.srh.flag_p",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x40,
NULL, HFILL }
},
{ &hf_ipv6_routing_srh_flag_o,
{ "OAM", "ipv6.routing.srh.flag_o",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x20,
NULL, HFILL }
},
{ &hf_ipv6_routing_srh_flag_a,
{ "Alert", "ipv6.routing.srh.flag_a",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x10,
NULL, HFILL }
},
{ &hf_ipv6_routing_srh_flag_h,
{ "HMAC", "ipv6.routing.srh.flag_h",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x08,
NULL, HFILL }
},
{ &hf_ipv6_routing_srh_flag_unused2,
{ "Unused", "ipv6.routing.srh.flag_unused2",
FT_UINT8, BASE_HEX, NULL, 0x07,
NULL, HFILL }
},
{ &hf_ipv6_routing_srh_reserved,
{ "Reserved", "ipv6.routing.srh.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Must be zero", HFILL }
},
{ &hf_ipv6_routing_srh_addr,
{ "Address", "ipv6.routing.srh.addr",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Segment address", HFILL }
}
};
static hf_register_info hf_ipv6_fraghdr[] = {
{ &hf_ipv6_fraghdr_nxt,
{ "Next header", "ipv6.fraghdr.nxt",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ipproto_val_ext, 0x0,
NULL, HFILL }
},
{ &hf_ipv6_fraghdr_reserved_octet,
{ "Reserved octet", "ipv6.fraghdr.reserved_octet",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Should always be 0", HFILL }
},
{ &hf_ipv6_fraghdr_offset,
{ "Offset", "ipv6.fraghdr.offset",
FT_UINT16, BASE_DEC, NULL, IP6F_OFF_MASK,
"Fragment Offset", HFILL }
},
{ &hf_ipv6_fraghdr_reserved_bits,
{ "Reserved bits", "ipv6.fraghdr.reserved_bits",
FT_UINT16, BASE_DEC, NULL, IP6F_RESERVED_MASK,
NULL, HFILL }
},
{ &hf_ipv6_fraghdr_more,
{ "More Fragments", "ipv6.fraghdr.more",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), IP6F_MORE_FRAG,
NULL, HFILL }
},
{ &hf_ipv6_fraghdr_ident,
{ "Identification", "ipv6.fraghdr.ident",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Fragment Identification", HFILL }
}
};
static gint *ett_ipv6[] = {
&ett_ipv6_proto,
&ett_ipv6_traffic_class,
#ifdef HAVE_GEOIP_V6
&ett_geoip_info,
#endif
&ett_ipv6_opt,
&ett_ipv6_opt_type,
&ett_ipv6_opt_rpl,
&ett_ipv6_opt_mpl,
&ett_ipv6_opt_dff_flags,
&ett_ipv6_fragment,
&ett_ipv6_fragments
};
static gint *ett_ipv6_hopopts[] = {
&ett_ipv6_hopopts_proto
};
static gint *ett_ipv6_routing[] = {
&ett_ipv6_routing_proto,
&ett_ipv6_routing_srh_flags,
&ett_ipv6_routing_srh_vect
};
static gint *ett_ipv6_fraghdr[] = {
&ett_ipv6_fraghdr_proto
};
static gint *ett_ipv6_dstopts[] = {
&ett_ipv6_dstopts_proto
};
static ei_register_info ei_ipv6[] = {
{ &ei_ipv6_opt_jumbo_missing,
{ "ipv6.opt.jumbo.missing", PI_MALFORMED, PI_ERROR,
"IPv6 payload length equals 0 and Hop-By-Hop present and Jumbo Payload option missing", EXPFILL }
},
{ &ei_ipv6_opt_jumbo_prohibited,
{ "ipv6.opt.jumbo.prohibited", PI_PROTOCOL, PI_WARN,
"When IPv6 payload length does not equal 0 a Jumbo Payload option must not be present", EXPFILL }
},
{ &ei_ipv6_opt_jumbo_truncated,
{ "ipv6.opt.jumbo.truncated", PI_PROTOCOL, PI_WARN,
"Jumbo Payload option present and jumbo length < 65536", EXPFILL }
},
{ &ei_ipv6_opt_jumbo_fragment,
{ "ipv6.opt.jumbo.fragment", PI_PROTOCOL, PI_WARN,
"Jumbo Payload option cannot be used with a fragment header", EXPFILL }
},
{ &ei_ipv6_opt_invalid_len,
{ "ipv6.opt.invalid_len", PI_MALFORMED, PI_ERROR,
"Invalid IPv6 option length", EXPFILL }
},
{ &ei_ipv6_opt_unknown_data,
{ "ipv6.opt.unknown_data.expert", PI_UNDECODED, PI_NOTE,
"Unknown Data (not interpreted)", EXPFILL }
},
{ &ei_ipv6_plen_exceeds_framing,
{ "ipv6.plen_exceeds_framing", PI_PROTOCOL, PI_WARN,
"IPv6 payload length does not match expected framing length", EXPFILL }
},
{ &ei_ipv6_bogus_ipv6_version,
{ "ipv6.bogus_ipv6_version", PI_MALFORMED, PI_ERROR,
"Bogus IP version", EXPFILL }
},
{ &ei_ipv6_invalid_header,
{ "ipv6.invalid_header", PI_MALFORMED, PI_ERROR,
"Invalid IPv6 header", EXPFILL }
},
{ &ei_ipv6_opt_header_mismatch,
{ "ipv6.opt.header_mismatch", PI_PROTOCOL, PI_WARN,
"Wrong options extension header for type", EXPFILL }
},
{ &ei_ipv6_opt_deprecated,
{ "ipv6.opt.deprecated", PI_DEPRECATED, PI_NOTE,
"Option type is deprecated", EXPFILL }
}
};
static ei_register_info ei_ipv6_hopopts[] = {
{ &ei_ipv6_hopopts_not_first,
{ "ipv6.hopopts.not_first", PI_PROTOCOL, PI_ERROR,
"IPv6 Hop-by-Hop extension header must appear immediately after IPv6 header", EXPFILL }
}
};
static ei_register_info ei_ipv6_routing[] = {
{ &ei_ipv6_dst_addr_not_multicast,
{ "ipv6.dst_addr.not_multicast", PI_PROTOCOL, PI_WARN,
"Destination address must not be a multicast address", EXPFILL }
},
{ &ei_ipv6_src_route_list_mult_inst_same_addr,
{ "ipv6.src_route_list.mult_inst_same_addr", PI_PROTOCOL, PI_WARN,
"Multiple instances of the same address must not appear in the source route list", EXPFILL }
},
{ &ei_ipv6_src_route_list_src_addr,
{ "ipv6.src_route_list.src_addr", PI_PROTOCOL, PI_WARN,
"Source address must not appear in the source route list", EXPFILL }
},
{ &ei_ipv6_src_route_list_dst_addr,
{ "ipv6.src_route_list.dst_addr", PI_PROTOCOL, PI_WARN,
"Destination address must not appear in the source route list", EXPFILL }
},
{ &ei_ipv6_src_route_list_multicast_addr,
{ "ipv6.src_route_list.multicast_addr", PI_PROTOCOL, PI_WARN,
"Multicast addresses must not appear in the source route list", EXPFILL }
},
{ &ei_ipv6_routing_rpl_cmpri_cmpre_pad,
{ "ipv6.routing.rpl.cmprI_cmprE_pad", PI_PROTOCOL, PI_WARN,
"When cmprI equals 0 and cmprE equals 0, pad MUST equal 0 but instead was X", EXPFILL }
},
{ &ei_ipv6_routing_rpl_addr_count_ge0,
{ "ipv6.routing.rpl.addr_count_ge0", PI_MALFORMED, PI_ERROR,
"Calculated total address count must be greater than or equal to 0, instead was X", EXPFILL }
},
{ &ei_ipv6_routing_rpl_reserved,
{ "ipv6.routing.rpl.reserved_not0", PI_PROTOCOL, PI_NOTE,
"Reserved field must equal 0 but instead was X", EXPFILL }
},
{ &ei_ipv6_routing_invalid_length,
{ "ipv6.routing.invalid_length", PI_MALFORMED, PI_ERROR,
"Invalid IPv6 Routing header length", EXPFILL }
},
{ &ei_ipv6_routing_invalid_segleft,
{ "ipv6.routing.invalid_segleft", PI_PROTOCOL, PI_WARN,
"IPv6 Routing Header segments left field must not exceed address count", EXPFILL }
},
{ &ei_ipv6_routing_undecoded,
{ "ipv6.routing.undecoded", PI_UNDECODED, PI_NOTE,
"Undecoded IPv6 routing header field", EXPFILL }
},
{ &ei_ipv6_routing_deprecated,
{ "ipv6.routing.deprecated", PI_DEPRECATED, PI_NOTE,
"Routing header type is deprecated", EXPFILL }
}
};
static build_valid_func ipv6_da_build_value[1] = {ipv6_value};
static decode_as_value_t ipv6_da_values = {ipv6_prompt, 1, ipv6_da_build_value};
static decode_as_t ipv6_da = {"ipv6", "Network", "ip.proto", 1, 0, &ipv6_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
static decode_as_t ipv6_hopopts_da = {"ipv6.hopopts", "Network", "ip.proto", 1, 0, &ipv6_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
static decode_as_t ipv6_routing_da = {"ipv6.routing", "Network", "ip.proto", 1, 0, &ipv6_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
static decode_as_t ipv6_fraghdr_da = {"ipv6.fraghdr", "Network", "ip.proto", 1, 0, &ipv6_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
static decode_as_t ipv6_dstopts_da = {"ipv6.dstopts", "Network", "ip.proto", 1, 0, &ipv6_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
module_t *ipv6_module;
expert_module_t* expert_ipv6;
expert_module_t* expert_ipv6_hopopts;
expert_module_t* expert_ipv6_routing;
proto_ipv6 = proto_register_protocol("Internet Protocol Version 6", "IPv6", "ipv6");
proto_register_field_array(proto_ipv6, hf_ipv6, array_length(hf_ipv6));
proto_register_subtree_array(ett_ipv6, array_length(ett_ipv6));
expert_ipv6 = expert_register_protocol(proto_ipv6);
expert_register_field_array(expert_ipv6, ei_ipv6, array_length(ei_ipv6));
proto_ipv6_hopopts = proto_register_protocol("IPv6 Hop-by-Hop Option", "IPv6 Hop-by-Hop", "ipv6.hopopts");
proto_register_field_array(proto_ipv6_hopopts, hf_ipv6_hopopts, array_length(hf_ipv6_hopopts));
proto_register_subtree_array(ett_ipv6_hopopts, array_length(ett_ipv6_hopopts));
expert_ipv6_hopopts = expert_register_protocol(proto_ipv6_hopopts);
expert_register_field_array(expert_ipv6_hopopts, ei_ipv6_hopopts, array_length(ei_ipv6_hopopts));
proto_ipv6_routing = proto_register_protocol("Routing Header for IPv6", "IPv6 Routing", "ipv6.routing");
proto_register_field_array(proto_ipv6_routing, hf_ipv6_routing, array_length(hf_ipv6_routing));
proto_register_subtree_array(ett_ipv6_routing, array_length(ett_ipv6_routing));
expert_ipv6_routing = expert_register_protocol(proto_ipv6_routing);
expert_register_field_array(expert_ipv6_routing, ei_ipv6_routing, array_length(ei_ipv6_routing));
proto_ipv6_fraghdr = proto_register_protocol("Fragment Header for IPv6", "IPv6 Fragment", "ipv6.fraghdr");
proto_register_field_array(proto_ipv6_fraghdr, hf_ipv6_fraghdr, array_length(hf_ipv6_fraghdr));
proto_register_subtree_array(ett_ipv6_fraghdr, array_length(ett_ipv6_fraghdr));
proto_ipv6_dstopts = proto_register_protocol("Destination Options for IPv6", "IPv6 Destination", "ipv6.dstopts");
proto_register_field_array(proto_ipv6_dstopts, hf_ipv6_dstopts, array_length(hf_ipv6_dstopts));
proto_register_subtree_array(ett_ipv6_dstopts, array_length(ett_ipv6_dstopts));
ipv6_module = prefs_register_protocol(proto_ipv6, NULL);
prefs_register_bool_preference(ipv6_module, "defragment",
"Reassemble fragmented IPv6 datagrams",
"Whether fragmented IPv6 datagrams should be reassembled",
&ipv6_reassemble);
prefs_register_bool_preference(ipv6_module, "summary_in_tree",
"Show IPv6 summary in protocol tree",
"Whether the IPv6 summary line should be shown in the protocol tree",
&ipv6_summary_in_tree);
#ifdef HAVE_GEOIP_V6
prefs_register_bool_preference(ipv6_module, "use_geoip" ,
"Enable GeoIP lookups",
"Whether to look up IPv6 addresses in each GeoIP database we have loaded",
&ipv6_use_geoip);
#endif
prefs_register_bool_preference(ipv6_module, "perform_strict_rpl_srh_rfc_checking",
"Perform strict checking for RPL Source Routing Headers (RFC 6554)",
"Check that all RPL Source Routed packets conform to RFC 6554 and do not visit a node more than once",
&g_ipv6_rpl_srh_strict_rfc_checking);
prefs_register_bool_preference(ipv6_module, "try_heuristic_first",
"Try heuristic sub-dissectors first",
"Try to decode a packet using an heuristic sub-dissector before using a sub-dissector registered to a specific port",
&try_heuristic_first);
prefs_register_bool_preference(ipv6_module, "exthdr_under_root_protocol_tree",
"Display IPv6 extension headers under the root protocol tree",
"Whether to display IPv6 extension headers as a separate protocol or a sub-protocol of the IPv6 packet",
&ipv6_exthdr_under_root);
prefs_register_bool_preference(ipv6_module, "exthdr_hide_len_oct_field",
"Use a single field for IPv6 extension header length",
"If enabled the Length field in octets will be hidden",
&ipv6_exthdr_hide_len_oct_field);
ipv6_handle = register_dissector("ipv6", dissect_ipv6, proto_ipv6);
reassembly_table_register(&ipv6_reassembly_table,
&addresses_reassembly_table_functions);
ip6_hdr_tap = register_tap("ipv6");
ipv6_ws_tap = register_tap("ipv6_ws");
register_decode_as(&ipv6_da);
register_decode_as(&ipv6_hopopts_da);
register_decode_as(&ipv6_routing_da);
register_decode_as(&ipv6_fraghdr_da);
register_decode_as(&ipv6_dstopts_da);
register_conversation_table(proto_ipv6, TRUE, ipv6_conversation_packet, ipv6_hostlist_packet);
register_conversation_filter("ipv6", "IPv6", ipv6_filter_valid, ipv6_build_filter);
register_capture_dissector("ipv6", capture_ipv6, proto_ipv6);
}
void
proto_reg_handoff_ipv6(void)
{
dissector_handle_t ipv6_hopopts_handle;
dissector_handle_t ipv6_routing_handle;
dissector_handle_t ipv6_fraghdr_handle;
dissector_handle_t ipv6_dstopts_handle;
capture_dissector_handle_t ipv6_cap_handle;
capture_dissector_handle_t ipv6_ext_cap_handle;
dissector_add_uint("ethertype", ETHERTYPE_IPv6, ipv6_handle);
dissector_add_uint("erf.types.type", ERF_TYPE_IPV6, ipv6_handle);
dissector_add_uint("ppp.protocol", PPP_IPV6, ipv6_handle);
dissector_add_uint("ppp.protocol", ETHERTYPE_IPv6, ipv6_handle);
dissector_add_uint("gre.proto", ETHERTYPE_IPv6, ipv6_handle);
dissector_add_uint("ip.proto", IP_PROTO_IPV6, ipv6_handle);
dissector_add_uint("null.type", BSD_AF_INET6_BSD, ipv6_handle);
dissector_add_uint("null.type", BSD_AF_INET6_FREEBSD, ipv6_handle);
dissector_add_uint("null.type", BSD_AF_INET6_DARWIN, ipv6_handle);
dissector_add_uint("chdlc.protocol", ETHERTYPE_IPv6, ipv6_handle);
dissector_add_uint("fr.nlpid", NLPID_IP6, ipv6_handle);
dissector_add_uint("osinl.excl", NLPID_IP6, ipv6_handle);
dissector_add_uint("x.25.spi", NLPID_IP6, ipv6_handle);
dissector_add_uint("arcnet.protocol_id", ARCNET_PROTO_IPv6, ipv6_handle);
dissector_add_uint("juniper.proto", JUNIPER_PROTO_IP6, ipv6_handle);
dissector_add_uint("juniper.proto", JUNIPER_PROTO_MPLS_IP6, ipv6_handle);
dissector_add_uint("pwach.channel_type", PW_ACH_TYPE_IPV6, ipv6_handle);
dissector_add_uint("sflow_245.header_protocol", SFLOW_245_HEADER_IPv6, ipv6_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_RAW_IP6, ipv6_handle);
dissector_add_uint("enc", BSD_AF_INET6_BSD, ipv6_handle);
dissector_add_uint("vxlan.next_proto", VXLAN_IPV6, ipv6_handle);
dissector_add_uint("nsh.next_proto", NSH_IPV6, ipv6_handle);
dissector_add_for_decode_as_with_preference("udp.port", ipv6_handle);
ipv6_hopopts_handle = create_dissector_handle(dissect_hopopts, proto_ipv6_hopopts);
dissector_add_uint("ip.proto", IP_PROTO_HOPOPTS, ipv6_hopopts_handle);
ipv6_routing_handle = create_dissector_handle(dissect_routing6, proto_ipv6_routing);
dissector_add_uint("ip.proto", IP_PROTO_ROUTING, ipv6_routing_handle);
ipv6_fraghdr_handle = create_dissector_handle(dissect_fraghdr, proto_ipv6_fraghdr);
dissector_add_uint("ip.proto", IP_PROTO_FRAGMENT, ipv6_fraghdr_handle);
ipv6_dstopts_handle = create_dissector_handle(dissect_dstopts, proto_ipv6_dstopts);
dissector_add_uint("ip.proto", IP_PROTO_DSTOPTS, ipv6_dstopts_handle);
ip_dissector_table = find_dissector_table("ip.proto");
ipv6_cap_handle = find_capture_dissector("ipv6");
capture_dissector_add_uint("ethertype", ETHERTYPE_IPv6, ipv6_cap_handle);
capture_dissector_add_uint("enc", BSD_AF_INET6_BSD, ipv6_cap_handle);
capture_dissector_add_uint("null.bsd", BSD_AF_INET6_BSD, ipv6_cap_handle);
capture_dissector_add_uint("null.bsd", BSD_AF_INET6_FREEBSD, ipv6_cap_handle);
capture_dissector_add_uint("null.bsd", BSD_AF_INET6_DARWIN, ipv6_cap_handle);
capture_dissector_add_uint("fr.nlpid", NLPID_IP6, ipv6_cap_handle);
ipv6_ext_cap_handle = create_capture_dissector_handle(capture_ipv6_exthdr, proto_ipv6_hopopts);
capture_dissector_add_uint("ip.proto", IP_PROTO_HOPOPTS, ipv6_ext_cap_handle);
ipv6_ext_cap_handle = create_capture_dissector_handle(capture_ipv6_exthdr, proto_ipv6_routing);
capture_dissector_add_uint("ip.proto", IP_PROTO_ROUTING, ipv6_ext_cap_handle);
ipv6_ext_cap_handle = create_capture_dissector_handle(capture_ipv6_exthdr, proto_ipv6_fraghdr);
capture_dissector_add_uint("ip.proto", IP_PROTO_FRAGMENT, ipv6_ext_cap_handle);
ipv6_ext_cap_handle = create_capture_dissector_handle(capture_ipv6_exthdr, proto_ipv6_dstopts);
capture_dissector_add_uint("ip.proto", IP_PROTO_DSTOPTS, ipv6_ext_cap_handle);
}
