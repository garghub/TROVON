static int
dissect_bvlc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_item *ti_bdt;
proto_item *ti_fdt;
proto_tree *bvlc_tree;
proto_tree *bdt_tree;
proto_tree *fdt_tree;
gint offset;
guint8 bvlc_type;
guint8 bvlc_function;
guint16 bvlc_length;
guint16 packet_length;
guint npdu_length;
guint length_remaining;
guint16 bvlc_result;
tvbuff_t *next_tvb;
offset = 0;
bvlc_type = tvb_get_guint8(tvb, offset);
if (try_val_to_str(bvlc_type, bvlc_types) == NULL)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BVLC");
col_set_str(pinfo->cinfo, COL_INFO, "BACnet Virtual Link Control");
bvlc_function = tvb_get_guint8(tvb, offset+1);
packet_length = tvb_get_ntohs(tvb, offset+2);
length_remaining = tvb_reported_length_remaining(tvb, offset);
if (bvlc_function > 0x08) {
bvlc_length = 4;
} else if(bvlc_function == 0x04) {
bvlc_length = 10;
} else {
bvlc_length = packet_length;
}
if (bvlc_length < 4) {
return 0;
}
if (tree) {
ti = proto_tree_add_item(tree, proto_bvlc, tvb, 0,
bvlc_length, ENC_NA);
bvlc_tree = proto_item_add_subtree(ti, ett_bvlc);
proto_tree_add_uint(bvlc_tree, hf_bvlc_type, tvb, offset, 1,
bvlc_type);
offset ++;
proto_tree_add_uint(bvlc_tree, hf_bvlc_function, tvb,
offset, 1, bvlc_function);
offset ++;
if (length_remaining != packet_length)
proto_tree_add_uint_format_value(bvlc_tree, hf_bvlc_length, tvb, offset,
2, bvlc_length,
"%d of %d bytes (invalid length - expected %d bytes)",
bvlc_length, packet_length, length_remaining);
else
proto_tree_add_uint_format_value(bvlc_tree, hf_bvlc_length, tvb, offset,
2, bvlc_length, "%d of %d bytes BACnet packet length",
bvlc_length, packet_length);
offset += 2;
switch (bvlc_function) {
case 0x00:
bvlc_result = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(bvlc_tree, hf_bvlc_result, tvb,
offset, 2, bvlc_result,"0x%04x (%s)",
bvlc_result,
val_to_str_const(bvlc_result,
bvlc_result_names,
"Unknown"));
break;
case 0x01:
case 0x03:
ti_bdt = proto_tree_add_item(bvlc_tree, proto_bvlc, tvb,
offset, bvlc_length-4, ENC_NA);
bdt_tree = proto_item_add_subtree(ti_bdt, ett_bdt);
while ((bvlc_length - offset) > 9) {
proto_tree_add_item(bdt_tree, hf_bvlc_bdt_ip,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(bdt_tree, hf_bvlc_bdt_port,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(bdt_tree,
hf_bvlc_bdt_mask, tvb, offset, 4,
ENC_NA);
offset += 4;
}
break;
case 0x02:
break;
case 0x05:
proto_tree_add_item(bvlc_tree, hf_bvlc_reg_ttl,
tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x06:
break;
case 0x07:
ti_fdt = proto_tree_add_item(bvlc_tree, proto_bvlc, tvb,
offset, bvlc_length -4, ENC_NA);
fdt_tree = proto_item_add_subtree(ti_fdt, ett_fdt);
while ((bvlc_length - offset) > 9) {
proto_tree_add_item(fdt_tree, hf_bvlc_fdt_ip,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(fdt_tree, hf_bvlc_fdt_port,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(fdt_tree,
hf_bvlc_fdt_ttl, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(fdt_tree,
hf_bvlc_fdt_timeout, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
}
break;
case 0x08:
proto_tree_add_item(bvlc_tree, hf_bvlc_fdt_ip,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(bvlc_tree, hf_bvlc_fdt_port,
tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x04:
proto_tree_add_item(bvlc_tree, hf_bvlc_fwd_ip,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(bvlc_tree, hf_bvlc_fwd_port,
tvb, offset, 2, ENC_BIG_ENDIAN);
default:
break;
}
}
npdu_length = packet_length - bvlc_length;
next_tvb = tvb_new_subset(tvb,bvlc_length,-1,npdu_length);
if (!dissector_try_uint(bvlc_dissector_table,
bvlc_function, next_tvb, pinfo, tree)) {
call_data_dissector(next_tvb, pinfo, tree);
}
return tvb_reported_length(tvb);
}
void
proto_register_bvlc(void)
{
static hf_register_info hf[] = {
{ &hf_bvlc_type,
{ "Type", "bvlc.type",
FT_UINT8, BASE_HEX, VALS(bvlc_types), 0,
NULL, HFILL }
},
{ &hf_bvlc_function,
{ "Function", "bvlc.function",
FT_UINT8, BASE_HEX, VALS(bvlc_function_names), 0,
"BVLC Function", HFILL }
},
{ &hf_bvlc_length,
{ "BVLC-Length", "bvlc.length",
FT_UINT16, BASE_DEC, NULL, 0,
"Length of BVLC", HFILL }
},
{ &hf_bvlc_result,
{ "Result", "bvlc.result",
FT_UINT16, BASE_HEX, NULL, 0,
"Result Code", HFILL }
},
{ &hf_bvlc_bdt_ip,
{ "IP", "bvlc.bdt_ip",
FT_IPv4, BASE_NONE, NULL, 0,
"BDT IP", HFILL }
},
{ &hf_bvlc_bdt_port,
{ "Port", "bvlc.bdt_port",
FT_UINT16, BASE_DEC, NULL, 0,
"BDT Port", HFILL }
},
{ &hf_bvlc_bdt_mask,
{ "Mask", "bvlc.bdt_mask",
FT_BYTES, BASE_NONE, NULL, 0,
"BDT Broadcast Distribution Mask", HFILL }
},
{ &hf_bvlc_reg_ttl,
{ "TTL", "bvlc.reg_ttl",
FT_UINT16, BASE_DEC, NULL, 0,
"Foreign Device Time To Live", HFILL }
},
{ &hf_bvlc_fdt_ip,
{ "IP", "bvlc.fdt_ip",
FT_IPv4, BASE_NONE, NULL, 0,
"FDT IP", HFILL }
},
{ &hf_bvlc_fdt_port,
{ "Port", "bvlc.fdt_port",
FT_UINT16, BASE_DEC, NULL, 0,
"FDT Port", HFILL }
},
{ &hf_bvlc_fdt_ttl,
{ "TTL", "bvlc.fdt_ttl",
FT_UINT16, BASE_DEC, NULL, 0,
"Foreign Device Time To Live", HFILL }
},
{ &hf_bvlc_fdt_timeout,
{ "Timeout", "bvlc.fdt_timeout",
FT_UINT16, BASE_DEC, NULL, 0,
"Foreign Device Timeout (seconds)", HFILL }
},
{ &hf_bvlc_fwd_ip,
{ "IP", "bvlc.fwd_ip",
FT_IPv4, BASE_NONE, NULL, 0,
"FWD IP", HFILL }
},
{ &hf_bvlc_fwd_port,
{ "Port", "bvlc.fwd_port",
FT_UINT16, BASE_DEC, NULL, 0,
"FWD Port", HFILL }
},
};
static gint *ett[] = {
&ett_bvlc,
&ett_bdt,
&ett_fdt,
};
module_t *bvlc_module;
proto_bvlc = proto_register_protocol("BACnet Virtual Link Control",
"BVLC", "bvlc");
proto_register_field_array(proto_bvlc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
bvlc_module = prefs_register_protocol(proto_bvlc, proto_reg_handoff_bvlc);
prefs_register_uint_preference(bvlc_module, "additional_udp_port",
"Additional UDP port", "Set an additional UDP port, "
"besides the standard X'BAC0' (47808) port.",
10, &global_additional_bvlc_udp_port);
register_dissector("bvlc", dissect_bvlc, proto_bvlc);
bvlc_dissector_table = register_dissector_table("bvlc.function",
"BVLC Function", proto_bvlc, FT_UINT8, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
}
void
proto_reg_handoff_bvlc(void)
{
static gboolean bvlc_initialized = FALSE;
static dissector_handle_t bvlc_handle;
static guint additional_bvlc_udp_port;
if (!bvlc_initialized)
{
bvlc_handle = find_dissector("bvlc");
dissector_add_uint("udp.port", 0xBAC0, bvlc_handle);
bvlc_initialized = TRUE;
}
else
{
if (additional_bvlc_udp_port != 0) {
dissector_delete_uint("udp.port", additional_bvlc_udp_port, bvlc_handle);
}
}
if (global_additional_bvlc_udp_port != 0) {
dissector_add_uint("udp.port", global_additional_bvlc_udp_port, bvlc_handle);
}
additional_bvlc_udp_port = global_additional_bvlc_udp_port;
}
