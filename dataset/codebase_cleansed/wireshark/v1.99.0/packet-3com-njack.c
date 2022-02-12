static int
dissect_portsettings(tvbuff_t *tvb, proto_tree *port_tree, guint32 offset)
{
proto_tree_add_item(port_tree, hf_njack_tlv_data,
tvb, offset, 8, ENC_NA);
return offset;
}
static int
dissect_tlvs(tvbuff_t *tvb, proto_tree *njack_tree, guint32 offset)
{
guint8 tlv_type;
guint8 tlv_length;
proto_item *tlv_tree;
for (;;) {
tlv_type = tvb_get_guint8(tvb, offset);
if (tlv_type == NJACK_CMD_ENDOFPACKET) {
proto_tree_add_item(njack_tree, hf_njack_tlv_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
if (tlv_type == NJACK_CMD_GETALLPARMAMS) {
proto_tree_add_item(njack_tree, hf_njack_tlv_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
continue;
}
tlv_length = tvb_get_guint8(tvb, offset + 1);
tlv_tree = proto_tree_add_subtree_format(njack_tree, tvb,
offset, tlv_length + 2, ett_njack_tlv_header, NULL,
"T %02x, L %02x: %s",
tlv_type,
tlv_length,
val_to_str_ext_const(tlv_type, &njack_cmd_vals_ext, "Unknown"));
proto_tree_add_item(tlv_tree, hf_njack_tlv_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tlv_tree, hf_njack_tlv_length,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (tlv_type) {
case NJACK_CMD_STARTOFPARAMS:
break;
case NJACK_CMD_COUNTERMODE:
proto_tree_add_item(tlv_tree, hf_njack_tlv_countermode,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case NJACK_CMD_QUEUEING:
proto_tree_add_item(tlv_tree, hf_njack_tlv_scheduling,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case NJACK_CMD_ADDTAGSCHEME:
proto_tree_add_item(tlv_tree, hf_njack_tlv_addtagscheme,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case NJACK_CMD_REMOVETAG:
proto_tree_add_item(tlv_tree, hf_njack_tlv_portingressmode,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case NJACK_CMD_MAXFRAMESIZE:
proto_tree_add_item(tlv_tree, hf_njack_tlv_maxframesize,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case NJACK_CMD_ENABLESNMPWRITE:
proto_tree_add_item(tlv_tree, hf_njack_tlv_snmpwrite,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case NJACK_CMD_POWERFORWARDING:
proto_tree_add_item(tlv_tree, hf_njack_tlv_powerforwarding,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case NJACK_CMD_DHCPCONTROL:
proto_tree_add_item(tlv_tree, hf_njack_tlv_dhcpcontrol,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case NJACK_CMD_MACADDRESS:
proto_tree_add_item(tlv_tree, hf_njack_tlv_devicemac,
tvb, offset, 6, ENC_NA);
offset += 6;
break;
case NJACK_CMD_VERSION:
proto_tree_add_item(tlv_tree, hf_njack_tlv_version,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
case NJACK_CMD_IPADDRESS:
case NJACK_CMD_NETWORK:
case NJACK_CMD_MASK:
case NJACK_CMD_IPGATEWAY:
proto_tree_add_item(tlv_tree, hf_njack_tlv_typeip,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case NJACK_CMD_GROUP:
case NJACK_CMD_LOCATION:
case NJACK_CMD_PASSWORD:
case NJACK_CMD_ROCOMMUNITY:
case NJACK_CMD_RWCOMMUNITY:
case 0x25:
case NJACK_CMD_PRODUCTNAME:
case NJACK_CMD_SERIALNO:
proto_tree_add_item(tlv_tree, hf_njack_tlv_typestring,
tvb, offset, tlv_length, ENC_ASCII|ENC_NA);
offset += tlv_length;
break;
case NJACK_CMD_PORT1:
case NJACK_CMD_PORT2:
case NJACK_CMD_PORT3:
case NJACK_CMD_PORT4:
if (tlv_length == 8) {
dissect_portsettings(tvb, tlv_tree, offset);
}
offset += tlv_length;
break;
default:
if (tlv_length != 0) {
proto_tree_add_item(tlv_tree, hf_njack_tlv_data,
tvb, offset, tlv_length, ENC_NA);
offset += tlv_length;
}
break;
}
}
return offset;
}
static int
dissect_njack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *njack_tree;
guint32 offset = 0;
guint8 packet_type;
guint8 setresult;
gint remaining;
packet_type = tvb_get_guint8(tvb, 5);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(packet_type, njack_type_vals, "Type 0x%02x"));
ti = proto_tree_add_item(tree, proto_njack, tvb, offset, -1,
ENC_NA);
njack_tree = proto_item_add_subtree(ti, ett_njack);
proto_tree_add_item(njack_tree, hf_njack_magic, tvb, offset, 5,
ENC_ASCII|ENC_NA);
offset += 5;
proto_tree_add_item(njack_tree, hf_njack_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
switch (packet_type) {
case NJACK_TYPE_SET:
proto_tree_add_item(njack_tree, hf_njack_set_length, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(njack_tree, hf_njack_set_salt, tvb, offset,
4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(njack_tree, hf_njack_set_authdata, tvb, offset,
16, ENC_NA);
offset += 16;
offset = dissect_tlvs(tvb, njack_tree, offset);
break;
case NJACK_TYPE_SETRESULT:
setresult = tvb_get_guint8(tvb, offset);
proto_tree_add_item(njack_tree, hf_njack_setresult, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str(setresult, njack_setresult_vals, "[0x%02x]"));
break;
case NJACK_TYPE_GET:
offset = dissect_tlvs(tvb, njack_tree, offset);
break;
case NJACK_TYPE_QUERYRESP:
case NJACK_TYPE_GETRESP:
offset = dissect_tlvs(tvb, njack_tree, offset);
proto_tree_add_item(njack_tree, hf_njack_getresp_unknown1, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
break;
case NJACK_TYPE_DHCPINFO:
default:
remaining = tvb_reported_length_remaining(tvb, offset);
if (remaining > 0) {
proto_tree_add_item(njack_tree, hf_njack_tlv_data,
tvb, offset, remaining, ENC_NA);
offset += remaining;
}
break;
}
return offset;
}
static gboolean
test_njack(tvbuff_t *tvb)
{
if ( (tvb_captured_length(tvb) < 6) ||
(tvb_strncaseeql(tvb, 0, "NJ200", 5) != 0) ) {
return FALSE;
}
return TRUE;
}
static gboolean
dissect_njack_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if ( !test_njack(tvb) ) {
return FALSE;
}
dissect_njack(tvb, pinfo, tree, NULL);
return TRUE;
}
static int
dissect_njack_static(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if ( !test_njack(tvb) ) {
return 0;
}
return dissect_njack(tvb, pinfo, tree, NULL);
}
void
proto_register_njack(void)
{
static hf_register_info hf[] = {
{ &hf_njack_magic,
{ "Magic", "njack.magic", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_njack_type,
{ "Type", "njack.type", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_njack_tlv_type,
{ "TlvType", "njack.tlv.type", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &njack_cmd_vals_ext,
0x0, NULL, HFILL }},
{ &hf_njack_tlv_length,
{ "TlvLength", "njack.tlv.length", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_njack_tlv_data,
{ "TlvData", "njack.tlv.data", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_njack_tlv_version,
{ "TlvFwVersion", "njack.tlv.version", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_njack_tlv_snmpwrite,
{ "TlvTypeSnmpwrite", "njack.tlv.snmpwrite", FT_UINT8, BASE_DEC, VALS(njack_snmpwrite),
0x0, NULL, HFILL }},
{ &hf_njack_tlv_dhcpcontrol,
{ "TlvTypeDhcpControl", "njack.tlv.dhcpcontrol", FT_UINT8, BASE_DEC, VALS(njack_dhcpcontrol),
0x0, NULL, HFILL }},
{ &hf_njack_tlv_devicemac,
{ "TlvTypeDeviceMAC", "njack.tlv.devicemac", FT_ETHER, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_njack_tlv_typeip,
{ "TlvTypeIP", "njack.tlv.typeip", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_njack_tlv_typestring,
{ "TlvTypeString", "njack.tlv.typestring", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_njack_tlv_scheduling,
{ "TlvTypeScheduling", "njack.tlv.scheduling", FT_UINT8, BASE_DEC, VALS(njack_scheduling),
0x0, NULL, HFILL }},
{ &hf_njack_tlv_addtagscheme,
{ "TlvAddTagScheme", "njack.tlv.addtagscheme", FT_UINT8, BASE_DEC, VALS(njack_addtagscheme),
0x0, NULL, HFILL }},
{ &hf_njack_tlv_portingressmode,
{ "TlvTypePortingressmode", "njack.tlv.portingressmode", FT_UINT8, BASE_DEC, VALS(njack_portingressmode),
0x0, NULL, HFILL }},
{ &hf_njack_tlv_maxframesize,
{ "TlvTypeMaxframesize", "njack.tlv.maxframesize", FT_UINT8, BASE_DEC, VALS(njack_maxframesize),
0x0, NULL, HFILL }},
{ &hf_njack_tlv_countermode,
{ "TlvTypeCountermode", "njack.tlv.countermode", FT_UINT8, BASE_DEC, VALS(njack_countermode),
0x0, NULL, HFILL }},
{ &hf_njack_tlv_powerforwarding,
{ "TlvTypePowerforwarding", "njack.tlv.powerforwarding", FT_UINT8, BASE_DEC, VALS(njack_powerforwarding),
0x0, NULL, HFILL }},
{ &hf_njack_set_length,
{ "SetLength", "njack.set.length", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_njack_set_salt,
{ "Salt", "njack.set.salt", FT_UINT32, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_njack_set_authdata,
{ "Authdata", "njack.tlv.authdata", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_njack_setresult,
{ "SetResult", "njack.setresult", FT_UINT8, BASE_HEX, VALS(njack_setresult_vals),
0x0, NULL, HFILL }},
{ &hf_njack_getresp_unknown1,
{ "Unknown1", "njack.getresp.unknown1", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_njack,
&ett_njack_tlv_header,
};
proto_njack = proto_register_protocol(PROTO_LONG_NAME, PROTO_SHORT_NAME, "njack");
proto_register_field_array(proto_njack, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_njack(void)
{
dissector_handle_t njack_handle;
njack_handle = new_create_dissector_handle(dissect_njack_static, proto_njack);
dissector_add_uint("udp.port", PORT_NJACK_PC, njack_handle);
dissector_add_uint("udp.port", PORT_NJACK_SWITCH, njack_handle);
heur_dissector_add("udp", dissect_njack_heur, proto_njack);
}
