static void
dissect_macctrl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ti;
proto_tree *macctrl_tree = NULL;
proto_tree *pause_times_tree = NULL;
guint16 opcode;
guint16 pause_time;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MAC CTRL");
col_clear(pinfo->cinfo, COL_INFO);
opcode = tvb_get_ntohs(tvb, 0);
if (tree) {
ti = proto_tree_add_item(tree, proto_macctrl, tvb, 0, 46, ENC_NA);
macctrl_tree = proto_item_add_subtree(ti, ett_macctrl);
proto_tree_add_uint(macctrl_tree, hf_macctrl_opcode, tvb, 0, 2, opcode);
}
switch (opcode) {
case MACCTRL_PAUSE:
pause_time = tvb_get_ntohs(tvb, 2);
col_add_fstr(pinfo->cinfo, COL_INFO, "MAC PAUSE: pause_time: %u quanta",
pause_time);
if (tree)
proto_tree_add_uint(macctrl_tree, hf_macctrl_pause_time, tvb, 2, 2,
pause_time);
break;
case MACCTRL_CLASS_BASED_FLOW_CNTRL_PAUSE:
col_set_str(pinfo->cinfo, COL_INFO, "MAC CLASS BASED FLOW CONTROL PAUSE");
if (tree) {
int i;
proto_tree_add_bitmask(macctrl_tree, tvb, 2, hf_macctrl_cbfc_enbv,
ett_macctrl_cbfc_enbv, macctrl_cbfc_enbv_list, ENC_BIG_ENDIAN);
ti = proto_tree_add_text(macctrl_tree, tvb, 4, 8*2, "CBFC Class Pause Times");
pause_times_tree = proto_item_add_subtree(ti, ett_macctrl_cbfc_pause_times);
for (i=0; i<8; i++) {
proto_tree_add_item(pause_times_tree, *macctrl_cbfc_pause_times_list[i], tvb, 4+i*2, 2, ENC_BIG_ENDIAN);
}
}
break;
}
}
void
proto_register_macctrl(void)
{
static hf_register_info hf[] = {
{ &hf_macctrl_opcode,
{ "Opcode", "macc.opcode", FT_UINT16, BASE_HEX,
VALS(opcode_vals), 0x0, "MAC Control opcode", HFILL}},
{ &hf_macctrl_pause_time,
{ "pause_time", "macc.pause_time", FT_UINT16, BASE_DEC,
NULL, 0x0, "MAC control PAUSE frame pause_time", HFILL }},
{ &hf_macctrl_cbfc_enbv,
{ "CBFC Class Enable Vector", "macc.cbfc.enbv", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_macctrl_cbfc_enbv_c0,
{ "C0", "macc.cbfc.enbv.c0", FT_BOOLEAN, 16,
NULL, 0x01, NULL, HFILL }},
{ &hf_macctrl_cbfc_enbv_c1,
{ "C1", "macc.cbfc.enbv.c1", FT_BOOLEAN, 16,
NULL, 0x02, NULL, HFILL }},
{ &hf_macctrl_cbfc_enbv_c2,
{ "C2", "macc.cbfc.enbv.c2", FT_BOOLEAN, 16,
NULL, 0x04, NULL, HFILL }},
{ &hf_macctrl_cbfc_enbv_c3,
{ "C3", "macc.cbfc.enbv.c3", FT_BOOLEAN, 16,
NULL, 0x08, NULL, HFILL }},
{ &hf_macctrl_cbfc_enbv_c4,
{ "C4", "macc.cbfc.enbv.c4", FT_BOOLEAN, 16,
NULL, 0x10, NULL, HFILL }},
{ &hf_macctrl_cbfc_enbv_c5,
{ "C5", "macc.cbfc.enbv.c5", FT_BOOLEAN, 16,
NULL, 0x20, NULL, HFILL }},
{ &hf_macctrl_cbfc_enbv_c6,
{ "C6", "macc.cbfc.enbv.c6", FT_BOOLEAN, 16,
NULL, 0x40, NULL, HFILL }},
{ &hf_macctrl_cbfc_enbv_c7,
{ "C7", "macc.cbfc.enbv.c7", FT_BOOLEAN, 16,
NULL, 0x80, NULL, HFILL }},
{ &hf_macctrl_cbfc_pause_time_c0,
{ "C0", "macc.cbfc.pause_time.c0", FT_UINT16, BASE_DEC,
NULL, 0x00, NULL, HFILL }},
{ &hf_macctrl_cbfc_pause_time_c1,
{ "C1", "macc.cbfc.pause_time.c1", FT_UINT16, BASE_DEC,
NULL, 0x00, NULL, HFILL }},
{ &hf_macctrl_cbfc_pause_time_c2,
{ "C2", "macc.cbfc.pause_time.c2", FT_UINT16, BASE_DEC,
NULL, 0x00, NULL, HFILL }},
{ &hf_macctrl_cbfc_pause_time_c3,
{ "C3", "macc.cbfc.pause_time.c3", FT_UINT16, BASE_DEC,
NULL, 0x00, NULL, HFILL }},
{ &hf_macctrl_cbfc_pause_time_c4,
{ "C4", "macc.cbfc.pause_time.c4", FT_UINT16, BASE_DEC,
NULL, 0x00, NULL, HFILL }},
{ &hf_macctrl_cbfc_pause_time_c5,
{ "C5", "macc.cbfc.pause_time.c5", FT_UINT16, BASE_DEC,
NULL, 0x00, NULL, HFILL }},
{ &hf_macctrl_cbfc_pause_time_c6,
{ "C6", "macc.cbfc.pause_time.c6", FT_UINT16, BASE_DEC,
NULL, 0x00, NULL, HFILL }},
{ &hf_macctrl_cbfc_pause_time_c7,
{ "C7", "macc.cbfc.pause_time.c7", FT_UINT16, BASE_DEC,
NULL, 0x00, NULL, HFILL }}
};
static gint *ett[] = {
&ett_macctrl,
&ett_macctrl_cbfc_enbv,
&ett_macctrl_cbfc_pause_times
};
proto_macctrl = proto_register_protocol("MAC Control", "MACC", "macc");
proto_register_field_array(proto_macctrl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_macctrl(void)
{
dissector_handle_t macctrl_handle;
macctrl_handle = create_dissector_handle(dissect_macctrl, proto_macctrl);
dissector_add_uint("ethertype", ETHERTYPE_MAC_CONTROL, macctrl_handle);
}
