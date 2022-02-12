static int
dissect_hyperscsi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint hs_hdr1, hs_hdr2, hs_hdr3;
guint8 hs_res;
guint16 hs_tagno;
guint16 hs_fragno;
gint offset = 0;
proto_tree *hs_hdr_tree, *hs_pdu_tree;
proto_tree *hs_tree;
proto_item *ti;
guint8 hs_cmd, hs_ver;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HyperSCSI");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_hyperscsi, tvb, offset, -1, ENC_NA);
hs_tree = proto_item_add_subtree(ti, ett_hyperscsi);
hs_hdr1 = tvb_get_guint8(tvb, offset);
offset++;
hs_hdr2 = tvb_get_guint8(tvb, offset);
offset++;
hs_hdr3 = tvb_get_guint8(tvb, offset);
offset++;
hs_res = hs_hdr1 >> 4;
hs_tagno = ((hs_hdr1 & 0x0F) << 5 ) | (hs_hdr2 >> 3);
hs_fragno = ((hs_hdr2 &0X03) << 8 ) | hs_hdr3;
if (tree) {
hs_hdr_tree = proto_tree_add_subtree(hs_tree, tvb, 0, 3, ett_hs_hdr, NULL, "HyperSCSI Header");
proto_tree_add_uint(hs_hdr_tree, hf_hs_res, tvb, 0, 1, hs_res);
proto_tree_add_uint(hs_hdr_tree, hf_hs_tagno, tvb, 0, 2, hs_tagno);
proto_tree_add_item(hs_hdr_tree, hf_hs_lastfrag, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(hs_hdr_tree, hf_hs_fragno, tvb, 1, 2, hs_fragno);
}
hs_ver = tvb_get_guint8(tvb, offset++);
hs_cmd = tvb_get_guint8(tvb, offset);
hs_cmd &= OPCODE_MASK;
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str(hs_cmd, hscsi_opcodes, "Unknown HyperSCSI Request or Response (%u)"));
if (tree) {
hs_pdu_tree = proto_tree_add_subtree(hs_tree, tvb, 3, -1, ett_hs_pdu, NULL, "HyperSCSI PDU");
proto_tree_add_uint(hs_pdu_tree, hf_hs_ver, tvb, 3, 1, hs_ver);
proto_tree_add_uint(hs_pdu_tree, hf_hs_cmd, tvb, 4, 1, hs_cmd);
}
return tvb_captured_length(tvb);
}
void
proto_register_hyperscsi(void)
{
static hf_register_info hf[] = {
{ &hf_hs_res,
{ "Reserved", "hyperscsi.reserved", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_hs_tagno,
{ "Tag No", "hyperscsi.tagno", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_hs_lastfrag,
{ "Last Fragment", "hyperscsi.lastfrag", FT_BOOLEAN, 8, TFS(&tfs_lastfrag), 0x04, NULL, HFILL}},
{ &hf_hs_fragno,
{ "Fragment No", "hyperscsi.fragno", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_hs_ver,
{ "HyperSCSI Version", "hyperscsi.version", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_hs_cmd,
{ "HyperSCSI Command", "hyperscsi.cmd", FT_UINT8, BASE_DEC, VALS(hscsi_opcodes), 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_hyperscsi,
&ett_hs_hdr,
&ett_hs_pdu,
};
proto_hyperscsi = proto_register_protocol("HyperSCSI", "HyperSCSI", "hyperscsi");
proto_register_field_array(proto_hyperscsi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("hyperscsi", dissect_hyperscsi, proto_hyperscsi);
}
void
proto_reg_handoff_hyperscsi(void)
{
dissector_handle_t hs_handle;
hs_handle = find_dissector("hyperscsi");
dissector_add_uint("ethertype", ETHERTYPE_HYPERSCSI, hs_handle);
}
