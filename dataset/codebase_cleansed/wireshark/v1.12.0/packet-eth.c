void
capture_eth(const guchar *pd, int offset, int len, packet_counts *ld)
{
guint16 etype, length;
int ethhdr_type;
if (!BYTES_ARE_IN_FRAME(offset, len, ETH_HEADER_SIZE)) {
ld->other++;
return;
}
etype = pntoh16(&pd[offset+12]);
if (etype <= IEEE_802_3_MAX_LEN) {
if ((pd[offset] == 0x01 || pd[offset] == 0x0C) && pd[offset+1] == 0x00
&& pd[offset+2] == 0x0C && pd[offset+3] == 0x00
&& pd[offset+4] == 0x00) {
capture_isl(pd, offset, len, ld);
return;
}
}
if (etype > IEEE_802_3_MAX_LEN && etype < ETHERNET_II_MIN_LEN) {
ld->other++;
return;
}
if (etype <= IEEE_802_3_MAX_LEN && etype != ETHERTYPE_UNK) {
length = etype;
if (pd[offset+14] == 0xff && pd[offset+15] == 0xff) {
ethhdr_type = ETHERNET_802_3;
}
else {
ethhdr_type = ETHERNET_802_2;
}
length += offset + ETH_HEADER_SIZE;
if (len > length)
len = length;
} else {
ethhdr_type = ETHERNET_II;
}
offset += ETH_HEADER_SIZE;
switch (ethhdr_type) {
case ETHERNET_802_3:
capture_ipx(ld);
break;
case ETHERNET_802_2:
capture_llc(pd, offset, len, ld);
break;
case ETHERNET_II:
capture_ethertype(etype, pd, offset, len, ld);
break;
}
}
static proto_tree *
dissect_eth_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree,
int fcs_len)
{
proto_item *ti = NULL;
eth_hdr *ehdr;
gboolean is_802_2;
proto_tree *fh_tree = NULL;
const guint8 *src_addr, *dst_addr;
static eth_hdr ehdrs[4];
static int ehdr_num=0;
proto_tree *tree;
proto_item *addr_item;
proto_tree *addr_tree=NULL;
ethertype_data_t ethertype_data;
heur_dtbl_entry_t *hdtbl_entry = NULL;
ehdr_num++;
if(ehdr_num>=4){
ehdr_num=0;
}
ehdr=&ehdrs[ehdr_num];
tree=parent_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Ethernet");
src_addr=tvb_get_ptr(tvb, 6, 6);
SET_ADDRESS(&pinfo->dl_src, AT_ETHER, 6, src_addr);
SET_ADDRESS(&pinfo->src, AT_ETHER, 6, src_addr);
SET_ADDRESS(&ehdr->src, AT_ETHER, 6, src_addr);
dst_addr=tvb_get_ptr(tvb, 0, 6);
SET_ADDRESS(&pinfo->dl_dst, AT_ETHER, 6, dst_addr);
SET_ADDRESS(&pinfo->dst, AT_ETHER, 6, dst_addr);
SET_ADDRESS(&ehdr->dst, AT_ETHER, 6, dst_addr);
ehdr->type = tvb_get_ntohs(tvb, 12);
tap_queue_packet(eth_tap, pinfo, ehdr);
if (dissector_try_heuristic(heur_subdissector_list, tvb, pinfo, parent_tree, &hdtbl_entry, NULL))
return fh_tree;
if (ehdr->type <= IEEE_802_3_MAX_LEN) {
if ((tvb_get_guint8(tvb, 0) == 0x01 ||
tvb_get_guint8(tvb, 0) == 0x0C) &&
tvb_get_guint8(tvb, 1) == 0x00 &&
tvb_get_guint8(tvb, 2) == 0x0C &&
tvb_get_guint8(tvb, 3) == 0x00 &&
tvb_get_guint8(tvb, 4) == 0x00) {
dissect_isl(tvb, pinfo, parent_tree, fcs_len);
return fh_tree;
}
}
if (ehdr->type > IEEE_802_3_MAX_LEN && ehdr->type < ETHERNET_II_MIN_LEN) {
tvbuff_t *next_tvb;
col_add_fstr(pinfo->cinfo, COL_INFO,
"Ethernet Unknown: Invalid length/type: 0x%04x (%d)",
ehdr->type, ehdr->type);
ti = proto_tree_add_protocol_format(tree, proto_eth, tvb, 0, ETH_HEADER_SIZE,
"Ethernet Unknown, Src: %s (%s), Dst: %s (%s)",
get_ether_name(src_addr), ether_to_str(src_addr),
get_ether_name(dst_addr), ether_to_str(dst_addr));
fh_tree = proto_item_add_subtree(ti, ett_ether);
addr_item = proto_tree_add_ether(fh_tree, hf_eth_dst, tvb, 0, 6, dst_addr);
if (addr_item)
addr_tree = proto_item_add_subtree(addr_item, ett_addr);
addr_item=proto_tree_add_string(addr_tree, hf_eth_dst_resolved, tvb, 0, 6,
get_ether_name(dst_addr));
PROTO_ITEM_SET_GENERATED(addr_item);
PROTO_ITEM_SET_HIDDEN(addr_item);
proto_tree_add_ether(addr_tree, hf_eth_addr, tvb, 0, 6, dst_addr);
addr_item=proto_tree_add_string(addr_tree, hf_eth_addr_resolved, tvb, 0, 6,
get_ether_name(dst_addr));
PROTO_ITEM_SET_GENERATED(addr_item);
PROTO_ITEM_SET_HIDDEN(addr_item);
proto_tree_add_item(addr_tree, hf_eth_lg, tvb, 0, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_eth_ig, tvb, 0, 3, ENC_BIG_ENDIAN);
addr_item = proto_tree_add_ether(fh_tree, hf_eth_src, tvb, 6, 6, src_addr);
if (addr_item)
addr_tree = proto_item_add_subtree(addr_item, ett_addr);
addr_item=proto_tree_add_string(addr_tree, hf_eth_src_resolved, tvb, 6, 6,
get_ether_name(src_addr));
PROTO_ITEM_SET_GENERATED(addr_item);
PROTO_ITEM_SET_HIDDEN(addr_item);
proto_tree_add_ether(addr_tree, hf_eth_addr, tvb, 6, 6, src_addr);
addr_item=proto_tree_add_string(addr_tree, hf_eth_addr_resolved, tvb, 6, 6,
get_ether_name(src_addr));
PROTO_ITEM_SET_GENERATED(addr_item);
PROTO_ITEM_SET_HIDDEN(addr_item);
proto_tree_add_item(addr_tree, hf_eth_lg, tvb, 6, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_eth_ig, tvb, 6, 3, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(fh_tree, hf_eth_invalid_lentype, tvb, 12, 2, ENC_BIG_ENDIAN);
expert_add_info_format(pinfo, ti, &ei_eth_invalid_lentype,
"Invalid length/type: 0x%04x (%d)", ehdr->type, ehdr->type);
next_tvb = tvb_new_subset_remaining(tvb, 14);
call_dissector(data_handle, next_tvb, pinfo, parent_tree);
return fh_tree;
}
if (ehdr->type <= IEEE_802_3_MAX_LEN && ehdr->type != ETHERTYPE_UNK) {
is_802_2 = check_is_802_2(tvb, fcs_len);
col_add_fstr(pinfo->cinfo, COL_INFO, "IEEE 802.3 Ethernet %s",
(is_802_2 ? "" : "Raw "));
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_eth, tvb, 0, ETH_HEADER_SIZE,
"IEEE 802.3 Ethernet %s", (is_802_2 ? "" : "Raw "));
fh_tree = proto_item_add_subtree(ti, ett_ieee8023);
}
if(!proto_field_is_referenced(parent_tree, proto_eth)){
tree=NULL;
fh_tree=NULL;
}
addr_item=proto_tree_add_ether(fh_tree, hf_eth_dst, tvb, 0, 6, dst_addr);
if(addr_item){
addr_tree = proto_item_add_subtree(addr_item, ett_addr);
}
addr_item=proto_tree_add_string(addr_tree, hf_eth_dst_resolved, tvb, 0, 6,
get_ether_name(dst_addr));
PROTO_ITEM_SET_GENERATED(addr_item);
PROTO_ITEM_SET_HIDDEN(addr_item);
proto_tree_add_ether(addr_tree, hf_eth_addr, tvb, 0, 6, dst_addr);
addr_item=proto_tree_add_string(addr_tree, hf_eth_addr_resolved, tvb, 0, 6,
get_ether_name(dst_addr));
PROTO_ITEM_SET_GENERATED(addr_item);
PROTO_ITEM_SET_HIDDEN(addr_item);
proto_tree_add_item(addr_tree, hf_eth_lg, tvb, 0, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_eth_ig, tvb, 0, 3, ENC_BIG_ENDIAN);
addr_item=proto_tree_add_ether(fh_tree, hf_eth_src, tvb, 6, 6, src_addr);
if(addr_item){
addr_tree = proto_item_add_subtree(addr_item, ett_addr);
}
addr_item=proto_tree_add_string(addr_tree, hf_eth_src_resolved, tvb, 6, 6,
get_ether_name(src_addr));
PROTO_ITEM_SET_GENERATED(addr_item);
PROTO_ITEM_SET_HIDDEN(addr_item);
proto_tree_add_ether(addr_tree, hf_eth_addr, tvb, 6, 6, src_addr);
addr_item=proto_tree_add_string(addr_tree, hf_eth_addr_resolved, tvb, 6, 6,
get_ether_name(src_addr));
PROTO_ITEM_SET_GENERATED(addr_item);
PROTO_ITEM_SET_HIDDEN(addr_item);
proto_tree_add_item(addr_tree, hf_eth_lg, tvb, 6, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_eth_ig, tvb, 6, 3, ENC_BIG_ENDIAN);
dissect_802_3(ehdr->type, is_802_2, tvb, ETH_HEADER_SIZE, pinfo,
parent_tree, fh_tree, hf_eth_len, hf_eth_trailer, &ei_eth_len, fcs_len);
} else {
if (eth_interpret_as_fw1_monitor) {
if ((dst_addr[0] == 'i') || (dst_addr[0] == 'I') ||
(dst_addr[0] == 'o') || (dst_addr[0] == 'O')) {
call_dissector(fw1_handle, tvb, pinfo, parent_tree);
return fh_tree;
}
}
col_set_str(pinfo->cinfo, COL_INFO, "Ethernet II");
if (parent_tree) {
if (PTREE_DATA(parent_tree)->visible) {
ti = proto_tree_add_protocol_format(parent_tree, proto_eth, tvb, 0, ETH_HEADER_SIZE,
"Ethernet II, Src: %s (%s), Dst: %s (%s)",
get_ether_name(src_addr), ether_to_str(src_addr),
get_ether_name(dst_addr), ether_to_str(dst_addr));
}
else {
ti = proto_tree_add_item(parent_tree, proto_eth, tvb, 0, ETH_HEADER_SIZE, ENC_NA);
}
fh_tree = proto_item_add_subtree(ti, ett_ether2);
}
addr_item=proto_tree_add_ether(fh_tree, hf_eth_dst, tvb, 0, 6, dst_addr);
if(addr_item){
addr_tree = proto_item_add_subtree(addr_item, ett_addr);
}
addr_item=proto_tree_add_string(addr_tree, hf_eth_dst_resolved, tvb, 0, 6,
get_ether_name(dst_addr));
PROTO_ITEM_SET_GENERATED(addr_item);
PROTO_ITEM_SET_HIDDEN(addr_item);
proto_tree_add_ether(addr_tree, hf_eth_addr, tvb, 0, 6, dst_addr);
addr_item=proto_tree_add_string(addr_tree, hf_eth_addr_resolved, tvb, 0, 6,
get_ether_name(dst_addr));
PROTO_ITEM_SET_GENERATED(addr_item);
PROTO_ITEM_SET_HIDDEN(addr_item);
proto_tree_add_item(addr_tree, hf_eth_lg, tvb, 0, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_eth_ig, tvb, 0, 3, ENC_BIG_ENDIAN);
addr_item=proto_tree_add_ether(fh_tree, hf_eth_src, tvb, 6, 6, src_addr);
if(addr_item){
addr_tree = proto_item_add_subtree(addr_item, ett_addr);
if (tvb_get_guint8(tvb, 6) & 0x01) {
expert_add_info(pinfo, addr_item, &ei_eth_src_not_group);
}
}
addr_item=proto_tree_add_string(addr_tree, hf_eth_src_resolved, tvb, 6, 6,
get_ether_name(src_addr));
PROTO_ITEM_SET_GENERATED(addr_item);
PROTO_ITEM_SET_HIDDEN(addr_item);
proto_tree_add_ether(addr_tree, hf_eth_addr, tvb, 6, 6, src_addr);
addr_item=proto_tree_add_string(addr_tree, hf_eth_addr_resolved, tvb, 6, 6,
get_ether_name(src_addr));
PROTO_ITEM_SET_GENERATED(addr_item);
PROTO_ITEM_SET_HIDDEN(addr_item);
proto_tree_add_item(addr_tree, hf_eth_lg, tvb, 6, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_eth_ig, tvb, 6, 3, ENC_BIG_ENDIAN);
ethertype_data.etype = ehdr->type;
ethertype_data.offset_after_ethertype = ETH_HEADER_SIZE;
ethertype_data.fh_tree = fh_tree;
ethertype_data.etype_id = hf_eth_type;
ethertype_data.trailer_id = hf_eth_trailer;
ethertype_data.fcs_len = fcs_len;
call_dissector_with_data(ethertype_handle, tvb, pinfo, parent_tree, &ethertype_data);
}
return fh_tree;
}
static gboolean check_is_802_2(tvbuff_t *tvb, int fcs_len)
{
volatile gboolean is_802_2;
volatile int length;
gint captured_length, reported_length;
is_802_2 = TRUE;
TRY {
if (tvb_get_ntohs(tvb, 14) == 0xffff) {
is_802_2 = FALSE;
}
else if (ccsds_heuristic_length || ccsds_heuristic_version ||
ccsds_heuristic_header || ccsds_heuristic_bit) {
gboolean CCSDS_len = TRUE;
gboolean CCSDS_ver = TRUE;
gboolean CCSDS_head = TRUE;
gboolean CCSDS_bit = TRUE;
if (ccsds_heuristic_length) {
length = tvb_get_ntohs(tvb, 12);
reported_length = tvb_reported_length_remaining(tvb, ETH_HEADER_SIZE);
if (fcs_len > 0) {
if (reported_length >= fcs_len)
reported_length -= fcs_len;
}
if (length > reported_length) {
length = reported_length;
}
captured_length = tvb_captured_length_remaining(tvb, ETH_HEADER_SIZE);
if (captured_length > length)
captured_length = length;
if (captured_length >= 6) {
if (length != 7 + tvb_get_ntohs(tvb, ETH_HEADER_SIZE + 4))
CCSDS_len = FALSE;
}
}
if ((ccsds_heuristic_version) && (tvb_get_bits8(tvb, 8*ETH_HEADER_SIZE, 3)!=0))
CCSDS_ver = FALSE;
if ((ccsds_heuristic_header) && (tvb_get_bits8(tvb, 8*ETH_HEADER_SIZE + 4, 1)!=1))
CCSDS_head = FALSE;
if ((ccsds_heuristic_bit) && (tvb_get_bits8(tvb, 8*ETH_HEADER_SIZE + 16*6, 1)!=0))
CCSDS_bit = FALSE;
if (CCSDS_len && CCSDS_ver && CCSDS_head && CCSDS_bit)
is_802_2 = FALSE;
}
}
CATCH_BOUNDS_ERRORS {
;
}
ENDTRY;
return is_802_2;
}
void
add_ethernet_trailer(packet_info *pinfo, proto_tree *tree, proto_tree *fh_tree,
int trailer_id, tvbuff_t *tvb, tvbuff_t *trailer_tvb, int fcs_len)
{
proto_item *item;
proto_tree *checksum_tree;
heur_dtbl_entry_t *hdtbl_entry;
if (trailer_tvb) {
guint trailer_length, trailer_reported_length;
guint padding_length = 0;
gboolean has_fcs = FALSE;
tvbuff_t *real_trailer_tvb;
trailer_length = tvb_captured_length(trailer_tvb);
trailer_reported_length = tvb_reported_length(trailer_tvb);
if (eth_assume_padding && pinfo->fd->pkt_len>=60) {
if ( (pinfo->fd->pkt_len - trailer_reported_length) < 60 )
padding_length = 60 - (pinfo->fd->pkt_len - trailer_reported_length);
if (padding_length > 0) {
tvb_ensure_bytes_exist(tvb, 0, padding_length);
proto_tree_add_item(fh_tree, hf_eth_padding, trailer_tvb, 0,
padding_length, ENC_NA);
trailer_length -= padding_length;
trailer_reported_length -= padding_length;
}
}
if (fcs_len != 0) {
if (fcs_len == 4 || (tvb_reported_length(tvb) >= 64 &&
trailer_reported_length >= 4)) {
if (trailer_length < trailer_reported_length) {
trailer_reported_length -= 4;
if (trailer_length > trailer_reported_length)
trailer_length = trailer_reported_length;
has_fcs = TRUE;
} else {
trailer_length -= 4;
trailer_reported_length -= 4;
has_fcs = TRUE;
}
}
}
if (fcs_len==4)
real_trailer_tvb = tvb_new_subset(trailer_tvb, padding_length,
trailer_length, trailer_reported_length);
else
real_trailer_tvb = tvb_new_subset_remaining(trailer_tvb, padding_length);
if (tvb_reported_length(real_trailer_tvb) != 0) {
if (dissector_try_heuristic(eth_trailer_subdissector_list,
real_trailer_tvb, pinfo, tree, &hdtbl_entry, NULL) ) {
if (fcs_len!=4)
return;
} else {
if (trailer_length != 0) {
tvb_ensure_bytes_exist(tvb, 0, trailer_length);
proto_tree_add_item(fh_tree, trailer_id, real_trailer_tvb, 0,
trailer_length, ENC_NA);
}
}
}
if (has_fcs) {
guint32 sent_fcs = tvb_get_ntohl(trailer_tvb, padding_length+trailer_length);
if(eth_check_fcs){
guint32 fcs = crc32_802_tvb(tvb, tvb_captured_length(tvb) - 4);
if (fcs == sent_fcs) {
item = proto_tree_add_uint_format_value(fh_tree, hf_eth_fcs, trailer_tvb,
padding_length+trailer_length, 4, sent_fcs,
"0x%08x [correct]", sent_fcs);
checksum_tree = proto_item_add_subtree(item, ett_eth_fcs);
item = proto_tree_add_boolean(checksum_tree, hf_eth_fcs_good, trailer_tvb,
padding_length+trailer_length, 4, TRUE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_eth_fcs_bad, trailer_tvb,
padding_length+trailer_length, 4, FALSE);
PROTO_ITEM_SET_GENERATED(item);
} else {
item = proto_tree_add_uint_format_value(fh_tree, hf_eth_fcs, trailer_tvb,
padding_length+trailer_length, 4, sent_fcs,
"0x%08x [incorrect, should be 0x%08x]",
sent_fcs, fcs);
checksum_tree = proto_item_add_subtree(item, ett_eth_fcs);
item = proto_tree_add_boolean(checksum_tree, hf_eth_fcs_good, trailer_tvb,
padding_length+trailer_length, 4, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_eth_fcs_bad, trailer_tvb,
padding_length+trailer_length, 4, TRUE);
PROTO_ITEM_SET_GENERATED(item);
expert_add_info(pinfo, item, &ei_eth_fcs_bad);
col_append_str(pinfo->cinfo, COL_INFO, " [ETHERNET FRAME CHECK SEQUENCE INCORRECT]");
}
}else{
item = proto_tree_add_uint_format_value(fh_tree, hf_eth_fcs, trailer_tvb,
padding_length+trailer_length, 4, sent_fcs,
"0x%08x [validiation disabled]", sent_fcs);
checksum_tree = proto_item_add_subtree(item, ett_eth_fcs);
item = proto_tree_add_boolean(checksum_tree, hf_eth_fcs_good, trailer_tvb,
padding_length+trailer_length, 4, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_eth_fcs_bad, trailer_tvb,
padding_length+trailer_length, 4, FALSE);
PROTO_ITEM_SET_GENERATED(item);
}
trailer_length += 4;
}
proto_tree_set_appendix(fh_tree, tvb, tvb_captured_length(tvb) - padding_length - trailer_length, padding_length + trailer_length);
}
}
static void
dissect_eth_maybefcs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *fh_tree;
if ( (eth_trailer_length > 0) && (eth_trailer_length < tvb_captured_length(tvb)) ) {
tvbuff_t *next_tvb;
guint total_trailer_length;
total_trailer_length = eth_trailer_length + (eth_assume_fcs ? 4 : 0);
next_tvb = tvb_new_subset(tvb, 0,
tvb_captured_length(tvb) - total_trailer_length,
tvb_reported_length(tvb) - total_trailer_length);
fh_tree = dissect_eth_common(next_tvb, pinfo, tree, 0);
next_tvb = tvb_new_subset_remaining(tvb, tvb_captured_length(tvb) - total_trailer_length);
add_ethernet_trailer(pinfo, tree, fh_tree, hf_eth_trailer, tvb, next_tvb,
eth_assume_fcs ? 4 : pinfo->pseudo_header->eth.fcs_len);
} else {
dissect_eth_common(tvb, pinfo, tree, eth_assume_fcs ? 4 : pinfo->pseudo_header->eth.fcs_len);
}
}
static void
dissect_eth_withoutfcs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_eth_common(tvb, pinfo, tree, 0);
}
static void
dissect_eth_withfcs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_eth_common(tvb, pinfo, tree, 4);
}
void
proto_register_eth(void)
{
static hf_register_info hf[] = {
{ &hf_eth_dst,
{ "Destination", "eth.dst", FT_ETHER, BASE_NONE, NULL, 0x0,
"Destination Hardware Address", HFILL }},
{ &hf_eth_dst_resolved,
{ "Destination (resolved)", "eth.dst_resolved", FT_STRING, BASE_NONE,
NULL, 0x0, "Destination Hardware Address (resolved)", HFILL }},
{ &hf_eth_src,
{ "Source", "eth.src", FT_ETHER, BASE_NONE, NULL, 0x0,
"Source Hardware Address", HFILL }},
{ &hf_eth_src_resolved,
{ "Source (resolved)", "eth.src_resolved", FT_STRING, BASE_NONE,
NULL, 0x0, "Source Hardware Address (resolved)", HFILL }},
{ &hf_eth_len,
{ "Length", "eth.len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eth_type,
{ "Type", "eth.type", FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }},
{ &hf_eth_invalid_lentype,
{ "Invalid length/type", "eth.invalid_lentype", FT_UINT16, BASE_HEX_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_eth_addr,
{ "Address", "eth.addr", FT_ETHER, BASE_NONE, NULL, 0x0,
"Source or Destination Hardware Address", HFILL }},
{ &hf_eth_addr_resolved,
{ "Address (resolved)", "eth.addr_resolved", FT_STRING, BASE_NONE,
NULL, 0x0, "Source or Destination Hardware Address (resolved)",
HFILL }},
{ &hf_eth_padding,
{ "Padding", "eth.padding", FT_BYTES, BASE_NONE, NULL, 0x0,
"Ethernet Padding", HFILL }},
{ &hf_eth_trailer,
{ "Trailer", "eth.trailer", FT_BYTES, BASE_NONE, NULL, 0x0,
"Ethernet Trailer or Checksum", HFILL }},
{ &hf_eth_fcs,
{ "Frame check sequence", "eth.fcs", FT_UINT32, BASE_HEX, NULL, 0x0,
"Ethernet checksum", HFILL }},
{ &hf_eth_fcs_good,
{ "FCS Good", "eth.fcs_good", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum matches packet content; False: doesn't match content or not checked", HFILL }},
{ &hf_eth_fcs_bad,
{ "FCS Bad", "eth.fcs_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum doesn't matche packet content; False: does match content or not checked", HFILL }},
{ &hf_eth_lg,
{ "LG bit", "eth.lg", FT_BOOLEAN, 24,
TFS(&lg_tfs), 0x020000,
"Specifies if this is a locally administered or globally unique (IEEE assigned) address", HFILL }},
{ &hf_eth_ig,
{ "IG bit", "eth.ig", FT_BOOLEAN, 24,
TFS(&ig_tfs), 0x010000,
"Specifies if this is an individual (unicast) or group (broadcast/multicast) address", HFILL }}
};
static gint *ett[] = {
&ett_ieee8023,
&ett_ether2,
&ett_ether,
&ett_addr,
&ett_eth_fcs
};
static ei_register_info ei[] = {
{ &ei_eth_invalid_lentype, { "eth.invalid_lentype", PI_PROTOCOL, PI_WARN, "Invalid length/type", EXPFILL }},
{ &ei_eth_src_not_group, { "eth.src_not_group", PI_PROTOCOL, PI_WARN, "Source MAC must not be a group address: IEEE 802.3-2002, Section 3.2.3(b)", EXPFILL }},
{ &ei_eth_fcs_bad, { "eth.fcs_bad.expert", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
{ &ei_eth_len, { "eth.len.past_end", PI_MALFORMED, PI_ERROR, "Length field value goes past the end of the payload", EXPFILL }},
};
module_t *eth_module;
expert_module_t* expert_eth;
proto_eth = proto_register_protocol("Ethernet", "Ethernet", "eth");
proto_register_field_array(proto_eth, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_eth = expert_register_protocol(proto_eth);
expert_register_field_array(expert_eth, ei, array_length(ei));
register_heur_dissector_list("eth", &heur_subdissector_list);
register_heur_dissector_list("eth.trailer", &eth_trailer_subdissector_list);
eth_module = prefs_register_protocol(proto_eth, NULL);
prefs_register_bool_preference(eth_module, "assume_padding",
"Assume short frames which include a trailer contain padding",
"Some devices add trailing data to frames. When this setting is checked "
"the Ethernet dissector will assume there has been added padding to the "
"frame before the trailer was added. Uncheck if a device added a trailer "
"before the frame was padded.",
&eth_assume_padding);
prefs_register_uint_preference(eth_module, "trailer_length",
"Fixed ethernet trailer length",
"Some TAPs add a fixed length ethernet trailer at the end "
"of the frame, but before the (optional) FCS. Make sure it "
"gets interpreted correctly.",
10, &eth_trailer_length);
prefs_register_bool_preference(eth_module, "assume_fcs",
"Assume packets have FCS",
"Some Ethernet adapters and drivers include the FCS at the end of a packet, others do not. "
"The Ethernet dissector attempts to guess whether a captured packet has an FCS, "
"but it cannot always guess correctly.",
&eth_assume_fcs);
prefs_register_bool_preference(eth_module, "check_fcs",
"Validate the Ethernet checksum if possible",
"Whether to validate the Frame Check Sequence",
&eth_check_fcs);
prefs_register_bool_preference(eth_module, "interpret_as_fw1_monitor",
"Attempt to interpret as FireWall-1 monitor file",
"Whether packets should be interpreted as coming from CheckPoint FireWall-1 monitor file if they look as if they do",
&eth_interpret_as_fw1_monitor);
prefs_register_static_text_preference(eth_module, "ccsds_heuristic",
"These are the conditions to match a payload against in order to determine if this\n"
"is a CCSDS (Consultative Committee for Space Data Systems) packet within\n"
"an 802.3 packet. A packet is considered as a possible CCSDS packet only if\n"
"one or more of the conditions are checked.",
"Describe the conditions that must be true for the CCSDS dissector to be called");
prefs_register_bool_preference(eth_module, "ccsds_heuristic_length",
"CCSDS Length in header matches payload size",
"Set the condition that must be true for the CCSDS dissector to be called",
&ccsds_heuristic_length);
prefs_register_bool_preference(eth_module, "ccsds_heuristic_version",
"CCSDS Version # is zero",
"Set the condition that must be true for the CCSDS dissector to be called",
&ccsds_heuristic_version);
prefs_register_bool_preference(eth_module, "ccsds_heuristic_header",
"CCSDS Secondary Header Flag is set",
"Set the condition that must be true for the CCSDS dissector to be called",
&ccsds_heuristic_header);
prefs_register_bool_preference(eth_module, "ccsds_heuristic_bit",
"CCSDS Spare bit is cleared",
"Set the condition that must be true for the CCSDS dissector to be called",
&ccsds_heuristic_bit);
register_dissector("eth_withoutfcs", dissect_eth_withoutfcs, proto_eth);
register_dissector("eth_withfcs", dissect_eth_withfcs, proto_eth);
register_dissector("eth", dissect_eth_maybefcs, proto_eth);
eth_tap = register_tap("eth");
}
void
proto_reg_handoff_eth(void)
{
dissector_handle_t eth_maybefcs_handle, eth_withoutfcs_handle;
fw1_handle = find_dissector("fw1");
ethertype_handle = find_dissector("ethertype");
data_handle = find_dissector("data");
eth_maybefcs_handle = find_dissector("eth");
dissector_add_uint("wtap_encap", WTAP_ENCAP_ETHERNET, eth_maybefcs_handle);
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
dissector_add_uint("ethertype", ETHERTYPE_ETHBRIDGE, eth_withoutfcs_handle);
dissector_add_uint("chdlc.protocol", ETHERTYPE_ETHBRIDGE, eth_withoutfcs_handle);
dissector_add_uint("gre.proto", ETHERTYPE_ETHBRIDGE, eth_withoutfcs_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_ETHERNET, eth_withoutfcs_handle);
dissector_add_handle("udp.port", eth_withoutfcs_handle);
}
