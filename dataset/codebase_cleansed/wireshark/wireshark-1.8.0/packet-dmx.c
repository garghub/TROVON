static void
dissect_dmx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb = NULL;
unsigned offset = 0;
guint8 start_code;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DMX");
col_clear(pinfo->cinfo, COL_INFO);
start_code = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dmx_start_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (start_code) {
case DMX_SC_DMX:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(dmx_chan_handle, next_tvb, pinfo, tree);
break;
case DMX_SC_TEXT:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(dmx_text_handle, next_tvb, pinfo, tree);
break;
case DMX_SC_TEST:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(dmx_test_handle, next_tvb, pinfo, tree);
break;
case DMX_SC_RDM:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(rdm_handle, next_tvb, pinfo, tree);
break;
case DMX_SC_SIP:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(dmx_sip_handle, next_tvb, pinfo, tree);
break;
default:
if (offset < tvb_length(tvb))
proto_tree_add_item(tree, hf_dmx_frame_data, tvb,
offset, -1, ENC_NA);
break;
}
}
void
proto_register_dmx(void)
{
static hf_register_info hf[] = {
{ &hf_dmx_start_code,
{ "Start Code", "dmx.start_code",
FT_UINT8, BASE_HEX, VALS(dmx_sc_vals), 0x0,
NULL, HFILL }},
{ &hf_dmx_frame_data,
{ "Frame Data", "dmx.frame_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_dmx
};
proto_dmx = proto_register_protocol("DMX", "DMX", "dmx");
proto_register_field_array(proto_dmx, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("dmx", dissect_dmx, proto_dmx);
}
void
proto_reg_handoff_dmx(void)
{
static gboolean dmx_initialized = FALSE;
if (!dmx_initialized) {
rdm_handle = find_dissector("rdm");
dmx_chan_handle = find_dissector("dmx-chan");
dmx_test_handle = find_dissector("dmx-test");
dmx_text_handle = find_dissector("dmx-text");
dmx_sip_handle = find_dissector("dmx-sip");
dmx_initialized = TRUE;
}
}
