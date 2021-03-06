static int
dissect_papi_debug(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *debug_tree, *debug_sub_tree;
ti = proto_tree_add_item(tree, hf_papi_debug, tvb, offset, -1, ENC_NA);
debug_tree = proto_item_add_subtree(ti, ett_papi);
while(offset < tvb_reported_length(tvb)) {
switch(tvb_get_guint8(tvb,offset)) {
case 0x00:
ti = proto_tree_add_item(debug_tree, hf_papi_debug_text, tvb, offset+3, tvb_get_ntohs(tvb,offset+1), ENC_ASCII|ENC_NA);
debug_sub_tree = proto_item_add_subtree(ti, ett_papi);
proto_tree_add_item(debug_sub_tree, hf_papi_debug_text_length, tvb, offset+1, 2, ENC_BIG_ENDIAN);
offset += tvb_get_ntohs(tvb, offset+1) + 3;
break;
case 0x01:
proto_tree_add_item(debug_tree, hf_papi_debug_48bits, tvb, offset+1, 6, ENC_BIG_ENDIAN);
offset += 7;
break;
case 0x02:
proto_tree_add_item(debug_tree, hf_papi_debug_8bits, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
break;
case 0x03:
proto_tree_add_item(debug_tree, hf_papi_debug_16bits, tvb, offset+1, 2, ENC_BIG_ENDIAN);
offset += 3;
break;
case 0x04:
proto_tree_add_item(debug_tree, hf_papi_debug_32bits, tvb, offset+1, 4, ENC_BIG_ENDIAN);
offset += 5;
break;
case 0x05:
proto_tree_add_item(debug_tree, hf_papi_debug_ipv4, tvb, offset+1, 4, ENC_BIG_ENDIAN);
offset += 5;
break;
case 0x07:
proto_tree_add_item(debug_tree, hf_papi_debug_16bits, tvb, offset+1, 2, ENC_BIG_ENDIAN);
offset += 3;
break;
case 0x08:
ti = proto_tree_add_item(debug_tree, hf_papi_debug_bytes, tvb, offset+3, tvb_get_ntohs(tvb,offset+1), ENC_NA);
debug_sub_tree = proto_item_add_subtree(ti, ett_papi);
proto_tree_add_item(debug_sub_tree, hf_papi_debug_bytes_length, tvb, offset+1, 2, ENC_BIG_ENDIAN);
offset += tvb_get_ntohs(tvb,offset+1) + 3;
break;
case 0x09:
proto_tree_add_item(debug_tree, hf_papi_debug_64bits, tvb, offset+1, 8, ENC_BIG_ENDIAN);
offset += 9;
break;
default:
proto_tree_add_text(debug_tree, tvb, offset, 1, "Unknown (%d)", tvb_get_guint8(tvb, offset));
offset +=1;
}
}
return offset;
}
static gboolean
dissect_papi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *papi_tree;
guint offset = 0;
tvbuff_t *next_tvb;
if ( tvb_get_ntohs(tvb, offset) != 0x4972 )
return FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PAPI");
col_set_str(pinfo->cinfo, COL_INFO, "PAPI - Aruba AP Control Protocol");
if (tree) {
ti = proto_tree_add_item(tree, proto_papi, tvb, 0, -1, ENC_NA);
papi_tree = proto_item_add_subtree(ti, ett_papi);
proto_tree_add_item(papi_tree, hf_papi_hdr_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_ip_destination, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(papi_tree, hf_papi_hdr_ip_source, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(papi_tree, hf_papi_hdr_unknown, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_unknown, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_port_source, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_port_destination, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_unknown, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_unknown, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_sequence, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_unknown, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_checksum, tvb, offset, 16, ENC_NA);
offset += 16;
if(g_papi_debug)
{
offset = dissect_papi_debug(tvb, offset, papi_tree);
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle,next_tvb, pinfo, tree);
}
return(TRUE);
}
void
proto_register_papi(void)
{
module_t *papi_module;
static hf_register_info hf[] = {
{ &hf_papi_hdr_id,
{ "ID", "papi.hdr.id",
FT_UINT16, BASE_HEX, NULL, 0x0,
"PAPI Header ID (Magic Number ?)", HFILL }
},
{ &hf_papi_hdr_version,
{ "Version", "papi.hdr.version",
FT_UINT16, BASE_DEC, NULL, 0x0,
"PAPI Protocol Version", HFILL }
},
{ &hf_papi_hdr_ip_destination,
{ "IP Destination", "papi.hdr.ip.dst",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_ip_source,
{ "IP Source", "papi.hdr.ip.src",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_port_source,
{ "Port Source", "papi.hdr.port.src",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_port_destination,
{ "Port Destination", "papi.hdr.port.destination",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_unknown,
{ "Unknown", "papi.hdr.unknown",
FT_UINT16, BASE_DEC|BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_sequence,
{ "Sequence", "papi.hdr.sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_checksum,
{ "Checksum", "papi.hdr.checksum",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_debug,
{ "Debug", "papi.debug",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_debug_text,
{ "Debug (Text)", "papi.debug.text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_debug_text_length,
{ "Debug Text Length", "papi.debug.text_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_debug_bytes,
{ "Debug (Bytes)", "papi.debug.bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_debug_bytes_length,
{ "Debug Bytes Length", "papi.debug.bytes_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_debug_48bits,
{ "Debug (48 Bits)", "papi.debug.48bits",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_debug_8bits,
{ "Debug (8 Bits)", "papi.debug.8bits",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_debug_16bits,
{ "Debug (16 Bits)", "papi.debug.16bits",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_debug_32bits,
{ "Debug (32 Bits)", "papi.debug.32bits",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_debug_ipv4,
{ "Debug (IPv4)", "papi.debug.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_debug_64bits,
{ "Debug (64 Bits)", "papi.debug.64bits",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_papi
};
proto_papi = proto_register_protocol("Aruba PAPI", "PAPI", "papi");
proto_register_field_array(proto_papi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
papi_module = prefs_register_protocol(proto_papi, NULL);
prefs_register_bool_preference(papi_module, "experimental_decode",
"Do experimental decode",
"Attempt to decode parts of the message that aren't fully understood yet",
&g_papi_debug);
}
void
proto_reg_handoff_papi(void)
{
dissector_handle_t papi_handle;
papi_handle = new_create_dissector_handle(dissect_papi, proto_papi);
dissector_add_uint("udp.port", UDP_PORT_PAPI, papi_handle);
data_handle = find_dissector("data");
}
