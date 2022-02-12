void
capture_sll(const guchar *pd, int len, packet_counts *ld)
{
guint16 protocol;
if (!BYTES_ARE_IN_FRAME(0, len, SLL_HEADER_SIZE)) {
ld->other++;
return;
}
protocol = pntoh16(&pd[14]);
if (protocol <= 1536) {
switch (protocol) {
case LINUX_SLL_P_802_2:
capture_llc(pd, len, SLL_HEADER_SIZE, ld);
break;
case LINUX_SLL_P_ETHERNET:
capture_eth(pd, SLL_HEADER_SIZE, len, ld);
break;
case LINUX_SLL_P_802_3:
capture_ipx(ld);
break;
case LINUX_SLL_P_PPPHDLC:
capture_ppp_hdlc(pd, len, SLL_HEADER_SIZE, ld);
break;
default:
ld->other++;
break;
}
} else
capture_ethertype(protocol, pd, SLL_HEADER_SIZE, len, ld);
}
static void
dissect_sll(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 pkttype;
guint16 protocol;
guint16 hatype, halen;
proto_item *ti;
tvbuff_t *next_tvb;
proto_tree *fh_tree = NULL;
ethertype_data_t ethertype_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SLL");
col_clear(pinfo->cinfo, COL_INFO);
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
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(pkttype, packet_type_vals, "Unknown (%u)"));
if (tree) {
ti = proto_tree_add_protocol_format(tree, hfi_sll->id, tvb, 0,
SLL_HEADER_SIZE, "Linux cooked capture");
fh_tree = proto_item_add_subtree(ti, ett_sll);
proto_tree_add_item(fh_tree, &hfi_sll_pkttype, tvb, 0, 2, ENC_BIG_ENDIAN);
}
hatype = tvb_get_ntohs(tvb, 2);
halen = tvb_get_ntohs(tvb, 4);
if (tree) {
proto_tree_add_uint(fh_tree, &hfi_sll_hatype, tvb, 2, 2, hatype);
proto_tree_add_uint(fh_tree, &hfi_sll_halen, tvb, 4, 2, halen);
}
switch (halen) {
case 4:
TVB_SET_ADDRESS(&pinfo->dl_src, AT_IPv4, tvb, 6, 4);
COPY_ADDRESS_SHALLOW(&pinfo->src, &pinfo->dl_src);
proto_tree_add_item(fh_tree, &hfi_sll_src_ipv4, tvb, 6, 4, ENC_BIG_ENDIAN);
break;
case 6:
TVB_SET_ADDRESS(&pinfo->dl_src, AT_ETHER, tvb, 6, 6);
COPY_ADDRESS_SHALLOW(&pinfo->src, &pinfo->dl_src);
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
if(!dissector_try_uint(sll_linux_dissector_table, protocol,
next_tvb, pinfo, tree)) {
call_dissector(data_handle, next_tvb, pinfo, tree);
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
int proto_sll;
proto_sll = proto_register_protocol("Linux cooked-mode capture",
"SLL", "sll" );
hfi_sll = proto_registrar_get_nth(proto_sll);
proto_register_fields(proto_sll, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
sll_handle = create_dissector_handle(dissect_sll, proto_sll);
sll_linux_dissector_table = register_dissector_table (
"sll.ltype",
"Linux SLL protocol type",
FT_UINT16,
BASE_HEX
);
}
void
proto_reg_handoff_sll(void)
{
gre_dissector_table = find_dissector_table("gre.proto");
data_handle = find_dissector("data");
ethertype_handle = find_dissector("ethertype");
dissector_add_uint("wtap_encap", WTAP_ENCAP_SLL, sll_handle);
}
