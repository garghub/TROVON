static int dissect_cnip (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
tvbuff_t *next_tvb;
gint offset;
gint type, exth_len, pf_pcode;
proto_tree *ti;
proto_tree *cnip_tree;
static const gint *pf_fields[] = {
&hf_cnip_pf_sec,
&hf_cnip_pf_pcode,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CN/IP");
col_clear(pinfo->cinfo, COL_INFO);
type = tvb_get_guint8(tvb, 3);
col_add_fstr(pinfo->cinfo, COL_INFO,"Priority: %s Type: %s",
(pinfo->destport == 1629 )? "urgent":"normal",
val_to_str_const(type, type_tuple, "Unknown"));
exth_len = tvb_get_guint8(tvb, 4);
pf_pcode = tvb_get_guint8(tvb, 5) & 0x1F;
offset = 0;
ti = proto_tree_add_item(tree, proto_cnip, tvb, offset, -1, ENC_NA);
cnip_tree = proto_item_add_subtree(ti, ett_cnip);
proto_tree_add_item(cnip_tree, hf_cnip_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cnip_tree, hf_cnip_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cnip_tree, hf_cnip_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cnip_tree, hf_cnip_exth, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(cnip_tree, tvb, offset,
hf_cnip_pf, ett_pf, pf_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cnip_tree, hf_cnip_vcode, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cnip_tree, hf_cnip_sessid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(cnip_tree, hf_cnip_seqno, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(cnip_tree, hf_cnip_tstamp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset += 4 * exth_len;
proto_item_set_len(ti, offset);
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (type == DATA_PACKET) {
if (dissector_try_uint(cnip_dissector_table, pf_pcode, next_tvb, pinfo, tree))
return tvb_captured_length(tvb);
}
else {
expert_add_info_format(pinfo, cnip_tree, &ei_cnip_type_unknown,
"This dissector doesn't yet decode packets of type %s (0x%x)",
val_to_str_const(type, type_tuple, "Unknown"), type);
}
call_data_dissector(next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void proto_register_cnip(void)
{
static hf_register_info hf[] =
{
{&hf_cnip_len,
{"Packet length", "cnip.len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_cnip_ver,
{"Version", "cnip.ver",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_cnip_type,
{"Packet type", "cnip.type",
FT_UINT8, BASE_HEX, VALS(type_tuple), 0,
NULL, HFILL }
},
{&hf_cnip_exth,
{"Ext. Header Size", "cnip.exth",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_cnip_pf,
{"Protocol Flags", "cnip.pf",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_cnip_pf_sec,
{"Protocol Flags", "cnip.sec",
FT_UINT8, BASE_DEC, NULL, 0x20,
NULL, HFILL }
},
{&hf_cnip_pf_pcode,
{"Protocol Code", "cnip.protocol",
FT_UINT8, BASE_DEC, NULL, 0x1F,
NULL, HFILL }
},
{&hf_cnip_vcode,
{"Vendor Code", "cnip.vendorcode",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_cnip_sessid,
{"Session ID", "cnip.sessid",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_cnip_seqno,
{"Sequence Number", "cnip.seqno",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_cnip_tstamp,
{"Time Stamp", "cnip.tstamp",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
}
};
static gint *ett[] =
{
&ett_cnip,
&ett_pf
};
static ei_register_info ei[] = {
{ &ei_cnip_type_unknown, { "cnip.type.unknown", PI_UNDECODED, PI_WARN, "This dissector doesn't yet decode packets of type", EXPFILL }},
};
expert_module_t* expert_cnip;
proto_cnip = proto_register_protocol("Component Network over IP",
"CN/IP", "cnip");
proto_register_field_array(proto_cnip, hf, array_length (hf));
proto_register_subtree_array(ett, array_length (ett));
expert_cnip = expert_register_protocol(proto_cnip);
expert_register_field_array(expert_cnip, ei, array_length(ei));
cnip_dissector_table = register_dissector_table("cnip.protocol",
"CN/IP Protocol", proto_cnip, FT_UINT8, BASE_DEC);
}
void proto_reg_handoff_cnip(void)
{
dissector_handle_t cnip_handle;
cnip_handle = create_dissector_handle(dissect_cnip, proto_cnip);
dissector_add_uint_range_with_preference("udp.port", CNIP_UDP_PORT_RANGE, cnip_handle);
}
