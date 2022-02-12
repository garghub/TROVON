static int
dissect_qllc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *qllc_tree;
proto_item *qllc_ti;
gboolean *q_bit_set;
guint8 addr, ctrl;
gboolean command = FALSE;
if (data == NULL)
return 0;
q_bit_set = (gboolean *)data;
if (!(*q_bit_set)) {
call_dissector(sna_handle, tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "QLLC");
col_clear(pinfo->cinfo, COL_INFO);
qllc_ti = proto_tree_add_item(tree, proto_qllc, tvb, 0, -1, ENC_NA);
qllc_tree = proto_item_add_subtree(qllc_ti, ett_qllc);
addr = tvb_get_guint8(tvb, 0);
proto_tree_add_item(qllc_tree, hf_qllc_address, tvb, 0, 1, ENC_BIG_ENDIAN);
ctrl = tvb_get_guint8(tvb, 1);
if (ctrl != QRR && addr == 0xff) {
command = TRUE;
}
if (ctrl == QRD_QDISC_VALUE) {
if (command) {
col_set_str(pinfo->cinfo, COL_INFO, QDISC_TEXT);
proto_tree_add_uint_format_value(qllc_tree, hf_qllc_control, tvb,
1, 1, ctrl, "%s (0x%02x)", QDISC_TEXT, ctrl);
}
else {
col_set_str(pinfo->cinfo, COL_INFO, QRD_TEXT);
proto_tree_add_uint_format_value(qllc_tree, hf_qllc_control, tvb,
1, 1, ctrl, "%s (0x%02x)", QRD_TEXT, ctrl);
}
}
else {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(ctrl, qllc_control_vals,
"Control Field: 0x%02x (unknown)"));
proto_tree_add_uint(qllc_tree, hf_qllc_control, tvb,
1, 1, ctrl);
}
if (ctrl == QXID || ctrl == QTEST || ctrl == QFRMR) {
}
return tvb_captured_length(tvb);
}
void
proto_register_qllc(void)
{
static hf_register_info hf[] = {
{ &hf_qllc_address,
{ "Address Field", "qllc.address", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_qllc_control,
{ "Control Field", "qllc.control", FT_UINT8, BASE_HEX,
VALS(qllc_control_vals), 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_qllc,
};
proto_qllc = proto_register_protocol("Qualified Logical Link Control", "QLLC", "qllc");
proto_register_field_array(proto_qllc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("qllc", dissect_qllc, proto_qllc);
}
void
proto_reg_handoff_qllc(void)
{
sna_handle = find_dissector_add_dependency("sna", proto_qllc);
}
