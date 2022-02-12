static int
dissect_g723(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
guint octet;
proto_item *ti;
proto_tree *g723_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "G.723.1");
if (tree) {
ti = proto_tree_add_item(tree, proto_g723, tvb, 0, -1, ENC_NA);
g723_tree = proto_item_add_subtree(ti, ett_g723);
octet = tvb_get_guint8(tvb,offset);
proto_tree_add_item(g723_tree, hf_g723_frame_size_and_codec, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(g723_tree, hf_g723_lpc_B5_B0, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((octet & 0x1) == 1 )
return tvb_captured_length(tvb);
}
return tvb_captured_length(tvb);
}
void
proto_reg_handoff_g723(void)
{
dissector_handle_t g723_handle;
g723_handle = create_dissector_handle(dissect_g723, proto_g723);
dissector_add_uint("rtp.pt", PT_G723, g723_handle);
}
void
proto_register_g723(void)
{
static hf_register_info hf[] = {
{ &hf_g723_frame_size_and_codec,
{ "Frame size and codec type", "g723.frame_size_and_codec",
FT_UINT8, BASE_HEX, VALS(g723_frame_size_and_codec_type_value), 0x03,
"RATEFLAG_B0", HFILL }
},
{ &hf_g723_lpc_B5_B0,
{ "LPC_B5...LPC_B0", "g723.lpc.b5b0",
FT_UINT8, BASE_HEX, NULL, 0xfc,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_g723,
};
proto_g723 = proto_register_protocol("G.723","G.723", "g723");
proto_register_field_array(proto_g723, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
