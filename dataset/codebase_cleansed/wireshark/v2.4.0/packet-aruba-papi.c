static int
dissect_papi_license_manager(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *licmgr_tree, *licmgr_subtree;
guint offset_end, payload_len;
ti = proto_tree_add_item(tree, hf_papi_licmgr, tvb, offset, -1, ENC_NA);
licmgr_tree = proto_item_add_subtree(ti, ett_papi_licmgr);
proto_tree_add_item(licmgr_tree, hf_papi_licmgr_unknown, tvb, offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item_ret_uint(licmgr_tree, hf_papi_licmgr_payload_len, tvb, offset, 2, ENC_BIG_ENDIAN, &payload_len);
offset += 2;
col_set_str(pinfo->cinfo, COL_INFO, "PAPI - Licence Manager");
offset_end = offset + payload_len;
while (offset< offset_end) {
guint optlen, type;
proto_item *tlv_item;
type = tvb_get_ntohs(tvb, offset);
optlen = tvb_get_ntohs(tvb, offset+2);
tlv_item = proto_tree_add_item(licmgr_tree, hf_papi_licmgr_tlv, tvb, offset, 2+2+optlen, ENC_NA );
proto_item_append_text(tlv_item, ": (t=%d,l=%d) %s", type, optlen, val_to_str(type, licmgr_type_vals, "Unknown Type (%02d)") );
licmgr_subtree = proto_item_add_subtree(tlv_item, ett_papi_licmgr_tlv);
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_value, tvb, offset, optlen, ENC_NA);
switch (type) {
case 1:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_ip, tvb, offset, 4, ENC_NA);
proto_item_append_text(tlv_item, ": %s", tvb_ip_to_str(tvb, offset));
break;
case 2:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_serial_number, tvb, offset, 32, ENC_ASCII|ENC_NA);
proto_item_append_text(tlv_item, ": %s", tvb_get_string_enc(wmem_packet_scope(),tvb, offset, optlen, ENC_ASCII));
break;
case 3:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_hostname, tvb, offset, optlen, ENC_ASCII|ENC_NA);
proto_item_append_text(tlv_item, ": %s", tvb_get_string_enc(wmem_packet_scope(),tvb, offset, optlen, ENC_ASCII));
break;
case 5:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_mac_address, tvb, offset, optlen, ENC_NA);
proto_item_append_text(tlv_item, ": %s", tvb_get_ether_name(tvb, offset));
break;
case 7:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_license_ap_remaining, tvb, offset, 4, ENC_NA);
proto_item_append_text(tlv_item, ": %u", tvb_get_ntohl(tvb, offset));
break;
case 8:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_license_pef_remaining, tvb, offset, 4, ENC_NA);
proto_item_append_text(tlv_item, ": %u", tvb_get_ntohl(tvb, offset));
break;
case 9:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_license_rfp_remaining, tvb, offset, 4, ENC_NA);
proto_item_append_text(tlv_item, ": %u", tvb_get_ntohl(tvb, offset));
break;
case 10:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_license_xsec_remaining, tvb, offset, 4, ENC_NA);
proto_item_append_text(tlv_item, ": %u", tvb_get_ntohl(tvb, offset));
break;
case 11:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_license_acr_remaining, tvb, offset, 4, ENC_NA);
proto_item_append_text(tlv_item, ": %u", tvb_get_ntohl(tvb, offset));
break;
case 12:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_license_ap_used, tvb, offset, 4, ENC_NA);
proto_item_append_text(tlv_item, ": %u", tvb_get_ntohl(tvb, offset));
break;
case 13:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_license_pef_used, tvb, offset, 4, ENC_NA);
proto_item_append_text(tlv_item, ": %u", tvb_get_ntohl(tvb, offset));
break;
case 14:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_license_rfp_used, tvb, offset, 4, ENC_NA);
proto_item_append_text(tlv_item, ": %u", tvb_get_ntohl(tvb, offset));
break;
case 15:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_license_xsec_used, tvb, offset, 4, ENC_NA);
proto_item_append_text(tlv_item, ": %u", tvb_get_ntohl(tvb, offset));
break;
case 16:
proto_tree_add_item(licmgr_subtree, hf_papi_licmgr_license_acr_used, tvb, offset, 4, ENC_NA);
proto_item_append_text(tlv_item, ": %u", tvb_get_ntohl(tvb, offset));
break;
}
offset += optlen;
}
proto_tree_add_item(licmgr_tree, hf_papi_licmgr_padding, tvb, offset, -1, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
return offset;
}
static int
dissect_papi_debug(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree)
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
proto_tree_add_expert_format(debug_tree, pinfo, &ei_papi_debug_unknown, tvb, offset, 1, "Unknown (%d)", tvb_get_guint8(tvb, offset));
offset +=1;
}
}
return offset;
}
static gboolean
dissect_papi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *papi_tree;
guint offset = 0;
guint32 dest_port, src_port;
tvbuff_t *next_tvb;
if ( tvb_get_ntohs(tvb, offset) != 0x4972 )
return FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PAPI");
col_set_str(pinfo->cinfo, COL_INFO, "PAPI - Aruba AP Control Protocol");
ti = proto_tree_add_item(tree, proto_papi, tvb, 0, -1, ENC_NA);
papi_tree = proto_item_add_subtree(ti, ett_papi);
proto_tree_add_item(papi_tree, hf_papi_hdr_magic, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_dest_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(papi_tree, hf_papi_hdr_src_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(papi_tree, hf_papi_hdr_nat_port_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_garbage, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item_ret_uint(papi_tree, hf_papi_hdr_dest_port, tvb, offset, 2, ENC_BIG_ENDIAN, &dest_port);
offset += 2;
proto_tree_add_item_ret_uint(papi_tree, hf_papi_hdr_src_port, tvb, offset, 2, ENC_BIG_ENDIAN, &src_port);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_packet_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_packet_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_seq_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_message_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(papi_tree, hf_papi_hdr_checksum, tvb, offset, 16, ENC_NA);
offset += 16;
if(dest_port == LICENSE_MANAGER && src_port == LICENSE_MANAGER){
offset = dissect_papi_license_manager(tvb, pinfo, offset, papi_tree);
}
if(g_papi_debug)
{
offset = dissect_papi_debug(tvb, pinfo, offset, papi_tree);
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(next_tvb, pinfo, tree);
return(TRUE);
}
void
proto_register_papi(void)
{
module_t *papi_module;
static hf_register_info hf[] = {
{ &hf_papi_hdr_magic,
{ "Magic", "papi.hdr.magic",
FT_UINT16, BASE_HEX, NULL, 0x0,
"PAPI Header Magic Number", HFILL }
},
{ &hf_papi_hdr_version,
{ "Version", "papi.hdr.version",
FT_UINT16, BASE_DEC, NULL, 0x0,
"PAPI Protocol Version", HFILL }
},
{ &hf_papi_hdr_dest_ip,
{ "Destination IP", "papi.hdr.dest.ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_src_ip,
{ "Source IP", "papi.hdr.src.ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_nat_port_number,
{ "NAT Port Number", "papi.hdr.nat_port_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_garbage,
{ "Garbage", "papi.hdr.garbage",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_dest_port,
{ "Destination Port", "papi.hdr.dest.port",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &papi_port_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_src_port,
{ "Source Port", "papi.hdr.src.port",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &papi_port_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_packet_type,
{ "Packet Type", "papi.hdr.packet.type",
FT_UINT16, BASE_DEC|BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_packet_size,
{ "Packet Size", "papi.hdr.packet.size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_seq_number,
{ "Sequence Number", "papi.hdr.seq_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_hdr_message_code,
{ "Message Code", "papi.hdr.message_code",
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
{ &hf_papi_licmgr,
{ "License Manager", "papi.licmgr",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_unknown,
{ "Unknown", "papi.licmgr.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_payload_len,
{ "Payload Length", "papi.licmgr.payload_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_tlv,
{ "TLV", "papi.licmgr.tlv",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_type,
{ "Type", "papi.licmgr.type",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_length,
{ "Length", "papi.licmgr.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_value,
{ "Value", "papi.licmgr.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_ip,
{ "License Manager IP Address", "papi.licmgr.ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_serial_number,
{ "Serial Number", "papi.licmgr.serial_number",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_hostname,
{ "Hostname", "papi.licmgr.hostname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_mac_address,
{ "MAC Address", "papi.licmgr.mac_address",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_license_ap_remaining,
{ "License AP remaining", "papi.licmgr.license.ap.remaining",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_license_pef_remaining,
{ "License PEF remaining", "papi.licmgr.license.pef.remaining",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_license_rfp_remaining,
{ "License RFP remaining", "papi.licmgr.license.rfp.remaining",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_license_xsec_remaining,
{ "License xSEC remaining", "papi.licmgr.license.xsec.remaining",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_license_acr_remaining,
{ "License ACR remaining", "papi.licmgr.license.acr.remaining",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_license_ap_used,
{ "License AP used", "papi.licmgr.license.ap.used",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_license_pef_used,
{ "License PEF used", "papi.licmgr.license.pef.used",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_license_rfp_used,
{ "License RFP used", "papi.licmgr.license.rfp.used",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_license_xsec_used,
{ "License xSec used", "papi.licmgr.license.xsec.used",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_license_acr_used,
{ "License ACR used", "papi.licmgr.license.acr.used",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_papi_licmgr_padding,
{ "Padding", "papi.licmgr.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_papi,
&ett_papi_licmgr,
&ett_papi_licmgr_tlv
};
static ei_register_info ei[] = {
{ &ei_papi_debug_unknown, { "papi.debug.unknown", PI_PROTOCOL, PI_WARN, "Unknown", EXPFILL }},
};
expert_module_t* expert_papi;
proto_papi = proto_register_protocol("Aruba PAPI", "PAPI", "papi");
proto_register_field_array(proto_papi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_papi = expert_register_protocol(proto_papi);
expert_register_field_array(expert_papi, ei, array_length(ei));
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
papi_handle = create_dissector_handle(dissect_papi, proto_papi);
dissector_add_uint_with_preference("udp.port", UDP_PORT_PAPI, papi_handle);
}
