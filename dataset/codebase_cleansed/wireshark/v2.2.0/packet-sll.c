static void sll_prompt(packet_info *pinfo, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "SLL protocol type 0x%04x as",
GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_sll, 0)));
}
static gpointer sll_value(packet_info *pinfo)
{
return p_get_proto_data(pinfo->pool, pinfo, proto_sll, 0);
}
static gboolean
capture_sll(const guchar *pd, int offset _U_, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_)
{
guint16 protocol;
if (!BYTES_ARE_IN_FRAME(0, len, SLL_HEADER_SIZE))
return FALSE;
protocol = pntoh16(&pd[14]);
if (protocol <= 1536) {
return try_capture_dissector("sll.ltype", protocol, pd, SLL_HEADER_SIZE, len, cpinfo, pseudo_header);
} else {
return try_capture_dissector("ethertype", protocol, pd, SLL_HEADER_SIZE, len, cpinfo, pseudo_header);
}
return FALSE;
}
static int
dissect_sll(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint16 pkttype;
guint16 protocol;
guint16 hatype, halen;
proto_item *ti;
tvbuff_t *next_tvb;
proto_tree *fh_tree;
ethertype_data_t ethertype_data;
pkttype = tvb_get_ntohs(tvb, 0);
switch (pkttype) {
case LINUX_SLL_HOST:
case LINUX_SLL_BROADCAST:
case LINUX_SLL_MULTICAST:
pinfo->p2p_dir = P2P_DIR_RECV;
break;
case LINUX_SLL_OUTGOING:
pinfo->p2p_dir = P2P_DIR_SENT;
break;
}
hatype = tvb_get_ntohs(tvb, 2);
halen = tvb_get_ntohs(tvb, 4);
if (hatype == LINUX_SLL_P_NETLINK) {
return call_dissector(netlink_handle, tvb, pinfo, tree);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SLL");
col_clear(pinfo->cinfo, COL_INFO);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(pkttype, packet_type_vals, "Unknown (%u)"));
ti = proto_tree_add_protocol_format(tree, hfi_sll->id, tvb, 0,
SLL_HEADER_SIZE, "Linux cooked capture");
fh_tree = proto_item_add_subtree(ti, ett_sll);
proto_tree_add_item(fh_tree, &hfi_sll_pkttype, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint(fh_tree, &hfi_sll_hatype, tvb, 2, 2, hatype);
proto_tree_add_uint(fh_tree, &hfi_sll_halen, tvb, 4, 2, halen);
switch (halen) {
case 4:
set_address_tvb(&pinfo->dl_src, AT_IPv4, 4, tvb, 6);
copy_address_shallow(&pinfo->src, &pinfo->dl_src);
proto_tree_add_item(fh_tree, &hfi_sll_src_ipv4, tvb, 6, 4, ENC_BIG_ENDIAN);
break;
case 6:
set_address_tvb(&pinfo->dl_src, AT_ETHER, 6, tvb, 6);
copy_address_shallow(&pinfo->src, &pinfo->dl_src);
proto_tree_add_item(fh_tree, &hfi_sll_src_eth, tvb, 6, 6, ENC_NA);
break;
case 0:
break;
default:
proto_tree_add_item(fh_tree, &hfi_sll_src_other, tvb,
6, halen > 8 ? 8 : halen, ENC_NA);
break;
}
protocol = tvb_get_ntohs(tvb, 14);
next_tvb = tvb_new_subset_remaining(tvb, SLL_HEADER_SIZE);
if (protocol <= 1536) {
proto_tree_add_uint(fh_tree, &hfi_sll_ltype, tvb, 14, 2,
protocol);
p_add_proto_data(pinfo->pool, pinfo, proto_sll, 0, GUINT_TO_POINTER((guint)protocol));
if(!dissector_try_uint(sll_linux_dissector_table, protocol,
next_tvb, pinfo, tree)) {
call_data_dissector(next_tvb, pinfo, tree);
}
} else {
switch (hatype) {
case ARPHRD_IPGRE:
proto_tree_add_uint(fh_tree, &hfi_sll_gretype, tvb, 14, 2,
protocol);
dissector_try_uint(gre_dissector_table,
protocol, next_tvb, pinfo, tree);
break;
default:
ethertype_data.etype = protocol;
ethertype_data.offset_after_ethertype = SLL_HEADER_SIZE;
ethertype_data.fh_tree = fh_tree;
ethertype_data.etype_id = hfi_sll_etype.id;
ethertype_data.trailer_id = hfi_sll_trailer.id;
ethertype_data.fcs_len = 0;
call_dissector_with_data(ethertype_handle, tvb, pinfo, tree, &ethertype_data);
break;
}
}
return tvb_captured_length(tvb);
}
void
proto_register_sll(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_sll_pkttype,
&hfi_sll_hatype,
&hfi_sll_halen,
&hfi_sll_src_eth,
&hfi_sll_src_ipv4,
&hfi_sll_src_other,
&hfi_sll_ltype,
&hfi_sll_gretype,
&hfi_sll_etype,
&hfi_sll_trailer,
};
#endif
static gint *ett[] = {
&ett_sll
};
static build_valid_func sll_da_build_value[1] = {sll_value};
static decode_as_value_t sll_da_values = {sll_prompt, 1, sll_da_build_value};
static decode_as_t sll_da = {"sll.ltype", "Link", "sll.ltype", 1, 0, &sll_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
proto_sll = proto_register_protocol("Linux cooked-mode capture",
"SLL", "sll" );
hfi_sll = proto_registrar_get_nth(proto_sll);
proto_register_fields(proto_sll, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
sll_handle = create_dissector_handle(dissect_sll, proto_sll);
sll_linux_dissector_table = register_dissector_table (
"sll.ltype",
"Linux SLL protocol type",
proto_sll, FT_UINT16,
BASE_HEX
);
register_capture_dissector_table("sll.ltype", "Linux SLL protocol");
register_decode_as(&sll_da);
}
void
proto_reg_handoff_sll(void)
{
gre_dissector_table = find_dissector_table("gre.proto");
ethertype_handle = find_dissector_add_dependency("ethertype", proto_sll);
netlink_handle = find_dissector_add_dependency("netlink", proto_sll);
dissector_add_uint("wtap_encap", WTAP_ENCAP_SLL, sll_handle);
register_capture_dissector("wtap_encap", WTAP_ENCAP_SLL, capture_sll, hfi_sll->id);
}
