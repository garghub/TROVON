static int dissect_ethercat_frame(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
tvbuff_t *next_tvb;
proto_item *ti;
proto_tree *ethercat_frame_tree;
gint offset = 0;
EtherCATFrameParserHDR hdr;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ECATF");
col_clear(pinfo->cinfo, COL_INFO);
if (tree)
{
ti = proto_tree_add_item(tree, proto_ethercat_frame, tvb, offset, EtherCATFrameParserHDR_Len, ENC_NA);
ethercat_frame_tree = proto_item_add_subtree(ti, ett_ethercat_frame);
proto_tree_add_item(ethercat_frame_tree, hf_ethercat_frame_length, tvb, offset, EtherCATFrameParserHDR_Len, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ethercat_frame_tree, hf_ethercat_frame_reserved, tvb, offset, EtherCATFrameParserHDR_Len, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ethercat_frame_tree, hf_ethercat_frame_type, tvb, offset, EtherCATFrameParserHDR_Len, ENC_LITTLE_ENDIAN);
}
hdr.hdr = tvb_get_letohs(tvb, offset);
offset = EtherCATFrameParserHDR_Len;
next_tvb = tvb_new_subset_remaining (tvb, offset);
if (!dissector_try_uint(ethercat_frame_dissector_table, hdr.v.protocol,
next_tvb, pinfo, tree))
{
col_add_fstr (pinfo->cinfo, COL_PROTOCOL, "0x%04x", hdr.v.protocol);
call_data_dissector(next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
void proto_register_ethercat_frame(void)
{
static hf_register_info hf[] =
{
{ &hf_ethercat_frame_length,
{ "Length", "ecatf.length",
FT_UINT16, BASE_HEX, NULL, 0x07FF,
NULL, HFILL }
},
{ &hf_ethercat_frame_reserved,
{ "Reserved", "ecatf.reserved",
FT_UINT16, BASE_HEX, VALS(ethercat_frame_reserved_vals), 0x0800,
NULL, HFILL}
},
{ &hf_ethercat_frame_type,
{ "Type", "ecatf.type",
FT_UINT16, BASE_HEX, VALS(EthercatFrameTypes), 0xF000,
"E88A4 Types", HFILL }
}
};
static gint *ett[] =
{
&ett_ethercat_frame
};
proto_ethercat_frame = proto_register_protocol("EtherCAT frame header",
"ETHERCAT","ecatf");
proto_register_field_array(proto_ethercat_frame,hf,array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("ecatf", dissect_ethercat_frame, proto_ethercat_frame);
ethercat_frame_dissector_table = register_dissector_table("ecatf.type", "EtherCAT frame type",
proto_ethercat_frame, FT_UINT8, BASE_DEC);
}
void proto_reg_handoff_ethercat_frame(void)
{
dissector_handle_t ethercat_frame_handle;
ethercat_frame_handle = find_dissector("ecatf");
dissector_add_uint("ethertype", ETHERTYPE_ECATF, ethercat_frame_handle);
dissector_add_uint("udp.port", ETHERTYPE_ECATF, ethercat_frame_handle);
dissector_add_uint("tcp.port", ETHERTYPE_ECATF, ethercat_frame_handle);
}
