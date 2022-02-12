static gboolean
capture_null( const guchar *pd, int offset _U_, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_ )
{
guint32 null_header;
if (!BYTES_ARE_IN_FRAME(0, len, 2))
return FALSE;
if (pd[0] == 0xFF && pd[1] == 0x03) {
return call_capture_dissector(ppp_hdlc_cap_handle, pd, 0, len, cpinfo, pseudo_header);
} else {
if (!BYTES_ARE_IN_FRAME(0, len, (int)sizeof(null_header)))
return FALSE;
memcpy((char *)&null_header, (const char *)&pd[0], sizeof(null_header));
if ((null_header & 0xFFFF0000) != 0) {
if ((null_header & 0xFF000000) == 0 &&
(null_header & 0x00FF0000) < 0x00060000) {
null_header >>= 16;
} else {
null_header = GUINT32_SWAP_LE_BE(null_header);
}
} else {
if ((null_header & 0x000000FF) == 0 &&
(null_header & 0x0000FF00) < 0x00000600) {
null_header = GUINT16_SWAP_LE_BE(null_header & 0xFFFF);
}
}
if (null_header > IEEE_802_3_MAX_LEN)
return try_capture_dissector("ethertype", null_header, pd, 4, len, cpinfo, pseudo_header);
else
return try_capture_dissector("null.bsd", null_header, pd, 4, len, cpinfo, pseudo_header);
}
return FALSE;
}
static int
dissect_null(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint32 null_header;
proto_tree *fh_tree;
proto_item *ti;
tvbuff_t *next_tvb;
if (tvb_get_ntohs(tvb, 0) == 0xFF03) {
call_dissector(ppp_hdlc_handle, tvb, pinfo, tree);
} else {
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "N/A");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "N/A");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "N/A");
col_set_str(pinfo->cinfo, COL_INFO, "Null/Loopback");
tvb_memcpy(tvb, (guint8 *)&null_header, 0, sizeof(null_header));
if ((null_header & 0xFFFF0000) != 0) {
if ((null_header & 0xFF000000) == 0 &&
(null_header & 0x00FF0000) < 0x00060000) {
null_header >>= 16;
} else {
null_header = GUINT32_SWAP_LE_BE(null_header);
}
} else {
if ((null_header & 0x000000FF) == 0 &&
(null_header & 0x0000FF00) < 0x00000600) {
null_header = GUINT16_SWAP_LE_BE(null_header & 0xFFFF);
}
}
if (null_header > IEEE_802_3_MAX_LEN) {
if (tree) {
ti = proto_tree_add_item(tree, proto_null, tvb, 0, 4, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_null);
proto_tree_add_uint(fh_tree, hf_null_etype, tvb, 0, 4,
(guint16) null_header);
}
next_tvb = tvb_new_subset_remaining(tvb, 4);
if (!dissector_try_uint(ethertype_dissector_table,
(guint16) null_header, next_tvb, pinfo, tree))
call_data_dissector(next_tvb, pinfo, tree);
} else {
if (tree) {
ti = proto_tree_add_item(tree, proto_null, tvb, 0, 4, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_null);
proto_tree_add_uint(fh_tree, hf_null_family, tvb, 0, 4, null_header);
}
next_tvb = tvb_new_subset_remaining(tvb, 4);
if (!dissector_try_uint(null_dissector_table, null_header,
next_tvb, pinfo, tree)) {
call_data_dissector(next_tvb, pinfo, tree);
}
}
}
return tvb_captured_length(tvb);
}
static int
dissect_loop(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint32 loop_family;
proto_tree *fh_tree;
proto_item *ti;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "N/A");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "N/A");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "N/A");
col_set_str(pinfo->cinfo, COL_INFO, "Null/Loopback");
loop_family = tvb_get_ntohl(tvb, 0);
if (tree) {
ti = proto_tree_add_item(tree, proto_null, tvb, 0, 4, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_null);
proto_tree_add_uint(fh_tree, hf_null_family, tvb, 0, 4, loop_family);
}
next_tvb = tvb_new_subset_remaining(tvb, 4);
if (!dissector_try_uint(null_dissector_table, loop_family,
next_tvb, pinfo, tree)) {
call_data_dissector(next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
void
proto_register_null(void)
{
static hf_register_info hf[] = {
{ &hf_null_etype,
{ "Type", "null.type", FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }},
{ &hf_null_family,
{ "Family", "null.family", FT_UINT32, BASE_DEC, VALS(family_vals), 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_null,
};
proto_null = proto_register_protocol("Null/Loopback", "Null", "null");
proto_register_field_array(proto_null, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
null_dissector_table = register_dissector_table("null.type",
"Null type", proto_null, FT_UINT32, BASE_DEC);
register_capture_dissector_table("null.bsd", "Null/Loopback BSD AF");
}
void
proto_reg_handoff_null(void)
{
dissector_handle_t null_handle, loop_handle;
capture_dissector_handle_t null_cap_handle;
ppp_hdlc_handle = find_dissector_add_dependency("ppp_hdlc", proto_null);
ethertype_dissector_table = find_dissector_table("ethertype");
null_handle = create_dissector_handle(dissect_null, proto_null);
dissector_add_uint("wtap_encap", WTAP_ENCAP_NULL, null_handle);
loop_handle = create_dissector_handle(dissect_loop, proto_null);
dissector_add_uint("wtap_encap", WTAP_ENCAP_LOOP, loop_handle);
null_cap_handle = create_capture_dissector_handle(capture_null, proto_null);
capture_dissector_add_uint("wtap_encap", WTAP_ENCAP_NULL, null_cap_handle);
capture_dissector_add_uint("wtap_encap", WTAP_ENCAP_LOOP, null_cap_handle);
ppp_hdlc_cap_handle = find_capture_dissector("ppp_hdlc");
}
