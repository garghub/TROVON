static void
dissect_dmx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
guint offset = 0;
guint8 start_code;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DMX");
col_clear(pinfo->cinfo, COL_INFO);
start_code = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dmx_start_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
next_tvb = tvb_new_subset_remaining(tvb, offset);
switch (start_code) {
case DMX_SC_DMX:
call_dissector(dmx_chan_handle, next_tvb, pinfo, tree);
break;
case DMX_SC_TEXT:
call_dissector(dmx_text_handle, next_tvb, pinfo, tree);
break;
case DMX_SC_TEST:
call_dissector(dmx_test_handle, next_tvb, pinfo, tree);
break;
case DMX_SC_RDM:
call_dissector(rdm_handle, next_tvb, pinfo, tree);
break;
case DMX_SC_SIP:
call_dissector(dmx_sip_handle, next_tvb, pinfo, tree);
break;
default:
if (offset < tvb_reported_length(tvb))
call_dissector(data_handle, next_tvb, pinfo, tree);
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
};
proto_dmx = proto_register_protocol("DMX", "DMX", "dmx");
proto_register_field_array(proto_dmx, hf, array_length(hf));
register_dissector("dmx", dissect_dmx, proto_dmx);
}
void
proto_reg_handoff_dmx(void)
{
rdm_handle = find_dissector("rdm");
dmx_chan_handle = find_dissector("dmx-chan");
dmx_test_handle = find_dissector("dmx-test");
dmx_text_handle = find_dissector("dmx-text");
dmx_sip_handle = find_dissector("dmx-sip");
data_handle = find_dissector("data");
}
