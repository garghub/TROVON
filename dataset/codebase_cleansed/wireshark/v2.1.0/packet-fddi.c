static void
swap_mac_addr(guint8 *swapped_addr, tvbuff_t *tvb, gint offset)
{
tvb_memcpy(tvb, swapped_addr, offset, 6);
bitswap_buf_inplace(swapped_addr, 6);
}
static const char* fddi_conv_get_filter_type(conv_item_t* conv, conv_filter_type_e filter)
{
if ((filter == CONV_FT_SRC_ADDRESS) && (conv->src_address.type == AT_ETHER))
return "fddi.src";
if ((filter == CONV_FT_DST_ADDRESS) && (conv->dst_address.type == AT_ETHER))
return "fddi.dst";
if ((filter == CONV_FT_ANY_ADDRESS) && (conv->src_address.type == AT_ETHER))
return "fddi.addr";
return CONV_FILTER_INVALID;
}
static int
fddi_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
conv_hash_t *hash = (conv_hash_t*) pct;
const fddi_hdr *ehdr=(const fddi_hdr *)vip;
add_conversation_table_data(hash, &ehdr->src, &ehdr->dst, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, &pinfo->abs_ts, &fddi_ct_dissector_info, PT_NONE);
return 1;
}
static const char* fddi_host_get_filter_type(hostlist_talker_t* host, conv_filter_type_e filter)
{
if ((filter == CONV_FT_ANY_ADDRESS) && (host->myaddress.type == AT_ETHER))
return "fddi.addr";
return CONV_FILTER_INVALID;
}
static int
fddi_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
conv_hash_t *hash = (conv_hash_t*) pit;
const fddi_hdr *ehdr=(const fddi_hdr *)vip;
add_hostlist_table_data(hash, &ehdr->src, 0, TRUE, 1, pinfo->fd->pkt_len, &fddi_host_dissector_info, PT_NONE);
add_hostlist_table_data(hash, &ehdr->dst, 0, FALSE, 1, pinfo->fd->pkt_len, &fddi_host_dissector_info, PT_NONE);
return 1;
}
static gboolean
capture_fddi(const guchar *pd, int offset, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header)
{
int fc;
if (!BYTES_ARE_IN_FRAME(0, len, FDDI_HEADER_SIZE + FDDI_PADDING))
return FALSE;
offset = FDDI_PADDING + FDDI_HEADER_SIZE;
fc = (int) pd[FDDI_P_FC+FDDI_PADDING];
switch (fc) {
case FDDI_FC_LLC_ASYNC + 0 :
case FDDI_FC_LLC_ASYNC + 1 :
case FDDI_FC_LLC_ASYNC + 2 :
case FDDI_FC_LLC_ASYNC + 3 :
case FDDI_FC_LLC_ASYNC + 4 :
case FDDI_FC_LLC_ASYNC + 5 :
case FDDI_FC_LLC_ASYNC + 6 :
case FDDI_FC_LLC_ASYNC + 7 :
case FDDI_FC_LLC_ASYNC + 8 :
case FDDI_FC_LLC_ASYNC + 9 :
case FDDI_FC_LLC_ASYNC + 10 :
case FDDI_FC_LLC_ASYNC + 11 :
case FDDI_FC_LLC_ASYNC + 12 :
case FDDI_FC_LLC_ASYNC + 13 :
case FDDI_FC_LLC_ASYNC + 14 :
case FDDI_FC_LLC_ASYNC + 15 :
return capture_llc(pd, offset, len, cpinfo, pseudo_header);
}
return FALSE;
}
static const gchar *
fddifc_to_str(int fc)
{
static gchar strbuf[128+1];
switch (fc) {
case FDDI_FC_VOID:
return "Void frame";
case FDDI_FC_NRT:
return "Nonrestricted token";
case FDDI_FC_RT:
return "Restricted token";
case FDDI_FC_SMT_INFO:
return "SMT info";
case FDDI_FC_SMT_NSA:
return "SMT Next station address";
case FDDI_FC_MAC_BEACON:
return "MAC beacon";
case FDDI_FC_MAC_CLAIM:
return "MAC claim token";
default:
switch (fc & FDDI_FC_CLFF) {
case FDDI_FC_MAC:
g_snprintf(strbuf, sizeof(strbuf), "MAC frame, control %x", fc & FDDI_FC_ZZZZ);
return strbuf;
case FDDI_FC_SMT:
g_snprintf(strbuf, sizeof(strbuf), "SMT frame, control %x", fc & FDDI_FC_ZZZZ);
return strbuf;
case FDDI_FC_LLC_ASYNC:
if (fc & FDDI_FC_ASYNC_R)
g_snprintf(strbuf, sizeof(strbuf), "Async LLC frame, control %x", fc & FDDI_FC_ZZZZ);
else
g_snprintf(strbuf, sizeof(strbuf), "Async LLC frame, priority %d",
fc & FDDI_FC_ASYNC_PRI);
return strbuf;
case FDDI_FC_LLC_SYNC:
if (fc & FDDI_FC_ZZZZ) {
g_snprintf(strbuf, sizeof(strbuf), "Sync LLC frame, control %x", fc & FDDI_FC_ZZZZ);
return strbuf;
} else
return "Sync LLC frame";
case FDDI_FC_IMP_ASYNC:
g_snprintf(strbuf, sizeof(strbuf), "Implementor async frame, control %x",
fc & FDDI_FC_ZZZZ);
return strbuf;
case FDDI_FC_IMP_SYNC:
g_snprintf(strbuf, sizeof(strbuf), "Implementor sync frame, control %x",
fc & FDDI_FC_ZZZZ);
return strbuf;
default:
return "Unknown frame type";
}
}
}
static void
dissect_fddi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean bitswapped)
{
proto_tree *fh_tree = NULL;
proto_item *ti, *hidden_item;
const gchar *fc_str;
proto_tree *fc_tree;
guchar *src = (guchar*)wmem_alloc(pinfo->pool, 6), *dst = (guchar*)wmem_alloc(pinfo->pool, 6);
guchar src_swapped[6], dst_swapped[6];
tvbuff_t *next_tvb;
static fddi_hdr fddihdrs[4];
static int fddihdr_num = 0;
fddi_hdr *fddihdr;
fddihdr_num++;
if (fddihdr_num >= 4) {
fddihdr_num = 0;
}
fddihdr = &fddihdrs[fddihdr_num];
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FDDI");
fddihdr->fc = tvb_get_guint8(tvb, FDDI_P_FC + FDDI_PADDING);
fc_str = fddifc_to_str(fddihdr->fc);
col_add_str(pinfo->cinfo, COL_INFO, fc_str);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_fddi, tvb, 0, FDDI_HEADER_SIZE+FDDI_PADDING,
"Fiber Distributed Data Interface, %s", fc_str);
fh_tree = proto_item_add_subtree(ti, ett_fddi);
ti = proto_tree_add_uint_format_value(fh_tree, hf_fddi_fc, tvb, FDDI_P_FC + FDDI_PADDING, 1, fddihdr->fc,
"0x%02x (%s)", fddihdr->fc, fc_str);
fc_tree = proto_item_add_subtree(ti, ett_fddi_fc);
proto_tree_add_uint(fc_tree, hf_fddi_fc_clf, tvb, FDDI_P_FC + FDDI_PADDING, 1, fddihdr->fc);
switch ((fddihdr->fc) & FDDI_FC_CLFF) {
case FDDI_FC_SMT:
proto_tree_add_uint(fc_tree, hf_fddi_fc_smt_subtype, tvb, FDDI_P_FC + FDDI_PADDING, 1, fddihdr->fc);
break;
case FDDI_FC_MAC:
if (fddihdr->fc != FDDI_FC_RT)
proto_tree_add_uint(fc_tree, hf_fddi_fc_mac_subtype, tvb, FDDI_P_FC + FDDI_PADDING, 1, fddihdr->fc);
break;
case FDDI_FC_LLC_ASYNC:
if (!((fddihdr->fc) & FDDI_FC_ASYNC_R))
proto_tree_add_uint(fc_tree, hf_fddi_fc_prio, tvb, FDDI_P_FC + FDDI_PADDING, 1, fddihdr->fc);
break;
}
}
if (bitswapped)
swap_mac_addr(dst, tvb, FDDI_P_DHOST + FDDI_PADDING);
else
tvb_memcpy(tvb, dst, FDDI_P_DHOST + FDDI_PADDING, 6);
swap_mac_addr(dst_swapped, tvb, FDDI_P_DHOST + FDDI_PADDING);
set_address(&pinfo->dl_dst, AT_ETHER, 6, dst);
copy_address_shallow(&pinfo->dst, &pinfo->dl_dst);
copy_address_shallow(&fddihdr->dst, &pinfo->dl_dst);
if (fh_tree) {
proto_tree_add_ether(fh_tree, hf_fddi_dst, tvb, FDDI_P_DHOST + FDDI_PADDING, 6, dst);
hidden_item = proto_tree_add_ether(fh_tree, hf_fddi_addr, tvb, FDDI_P_DHOST + FDDI_PADDING, 6, dst);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_ether(fh_tree, hf_fddi_dst, tvb, FDDI_P_DHOST + FDDI_PADDING, 6, dst_swapped);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_ether(fh_tree, hf_fddi_addr, tvb, FDDI_P_DHOST + FDDI_PADDING, 6, dst_swapped);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (bitswapped)
swap_mac_addr(src, tvb, FDDI_P_SHOST + FDDI_PADDING);
else
tvb_memcpy(tvb, src, FDDI_P_SHOST + FDDI_PADDING, 6);
swap_mac_addr(src_swapped, tvb, FDDI_P_SHOST + FDDI_PADDING);
set_address(&pinfo->dl_src, AT_ETHER, 6, src);
copy_address_shallow(&pinfo->src, &pinfo->dl_src);
copy_address_shallow(&fddihdr->src, &pinfo->dl_src);
if (fh_tree) {
proto_tree_add_ether(fh_tree, hf_fddi_src, tvb, FDDI_P_SHOST + FDDI_PADDING, 6, src);
hidden_item = proto_tree_add_ether(fh_tree, hf_fddi_addr, tvb, FDDI_P_SHOST + FDDI_PADDING, 6, src);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_ether(fh_tree, hf_fddi_src, tvb, FDDI_P_SHOST + FDDI_PADDING, 6, src_swapped);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_ether(fh_tree, hf_fddi_addr, tvb, FDDI_P_SHOST + FDDI_PADDING, 6, src_swapped);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
next_tvb = tvb_new_subset_remaining(tvb, FDDI_HEADER_SIZE + FDDI_PADDING);
tap_queue_packet(fddi_tap, pinfo, fddihdr);
switch (fddihdr->fc) {
case FDDI_FC_LLC_ASYNC + 0 :
case FDDI_FC_LLC_ASYNC + 1 :
case FDDI_FC_LLC_ASYNC + 2 :
case FDDI_FC_LLC_ASYNC + 3 :
case FDDI_FC_LLC_ASYNC + 4 :
case FDDI_FC_LLC_ASYNC + 5 :
case FDDI_FC_LLC_ASYNC + 6 :
case FDDI_FC_LLC_ASYNC + 7 :
case FDDI_FC_LLC_ASYNC + 8 :
case FDDI_FC_LLC_ASYNC + 9 :
case FDDI_FC_LLC_ASYNC + 10 :
case FDDI_FC_LLC_ASYNC + 11 :
case FDDI_FC_LLC_ASYNC + 12 :
case FDDI_FC_LLC_ASYNC + 13 :
case FDDI_FC_LLC_ASYNC + 14 :
case FDDI_FC_LLC_ASYNC + 15 :
call_dissector(llc_handle, next_tvb, pinfo, tree);
return;
default :
call_data_dissector(next_tvb, pinfo, tree);
return;
}
}
static int
dissect_fddi_bitswapped(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_fddi(tvb, pinfo, tree, TRUE);
return tvb_captured_length(tvb);
}
static int
dissect_fddi_not_bitswapped(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_fddi(tvb, pinfo, tree, FALSE);
return tvb_captured_length(tvb);
}
void
proto_register_fddi(void)
{
static hf_register_info hf[] = {
{ &hf_fddi_fc,
{ "Frame Control", "fddi.fc", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_fddi_fc_clf,
{ "Class/Length/Format", "fddi.fc.clf", FT_UINT8, BASE_HEX, VALS(clf_vals), FDDI_FC_CLFF,
NULL, HFILL }},
{ &hf_fddi_fc_prio,
{ "Priority", "fddi.fc.prio", FT_UINT8, BASE_DEC, NULL, FDDI_FC_ASYNC_PRI,
NULL, HFILL }},
{ &hf_fddi_fc_smt_subtype,
{ "SMT Subtype", "fddi.fc.smt_subtype", FT_UINT8, BASE_DEC, VALS(smt_subtype_vals), FDDI_FC_ZZZZ,
NULL, HFILL }},
{ &hf_fddi_fc_mac_subtype,
{ "MAC Subtype", "fddi.fc.mac_subtype", FT_UINT8, BASE_DEC, VALS(mac_subtype_vals), FDDI_FC_ZZZZ,
NULL, HFILL }},
{ &hf_fddi_dst,
{ "Destination", "fddi.dst", FT_ETHER, BASE_NONE, NULL, 0x0,
"Destination Hardware Address", HFILL }},
{ &hf_fddi_src,
{ "Source", "fddi.src", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_fddi_addr,
{ "Source or Destination Address", "fddi.addr", FT_ETHER, BASE_NONE, NULL, 0x0,
"Source or Destination Hardware Address", HFILL }},
};
static gint *ett[] = {
&ett_fddi,
&ett_fddi_fc,
};
module_t *fddi_module;
proto_fddi = proto_register_protocol("Fiber Distributed Data Interface",
"FDDI", "fddi");
proto_register_field_array(proto_fddi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
fddi_handle = register_dissector("fddi", dissect_fddi_not_bitswapped, proto_fddi);
fddi_bitswapped_handle = register_dissector("fddi_bitswapped", dissect_fddi_bitswapped, proto_fddi);
fddi_module = prefs_register_protocol(proto_fddi, NULL);
prefs_register_bool_preference(fddi_module, "padding",
"Add 3-byte padding to all FDDI packets",
"Whether the FDDI dissector should add 3-byte padding to all "
"captured FDDI packets (useful with e.g. Tru64 UNIX tcpdump)",
&fddi_padding);
fddi_tap = register_tap("fddi");
register_conversation_table(proto_fddi, TRUE, fddi_conversation_packet, fddi_hostlist_packet);
}
void
proto_reg_handoff_fddi(void)
{
llc_handle = find_dissector_add_dependency("llc", proto_fddi);
dissector_add_uint("wtap_encap", WTAP_ENCAP_FDDI_BITSWAPPED,
fddi_bitswapped_handle);
register_capture_dissector("wtap_encap", WTAP_ENCAP_FDDI, capture_fddi, proto_fddi);
register_capture_dissector("wtap_encap", WTAP_ENCAP_FDDI_BITSWAPPED, capture_fddi, proto_fddi);
}
