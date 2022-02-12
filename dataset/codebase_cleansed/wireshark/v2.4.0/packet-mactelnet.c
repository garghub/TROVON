static int
dissect_mactelnet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *mactelnet_item;
proto_tree *mactelnet_tree;
proto_item *mactelnet_control_item;
proto_tree *mactelnet_control_tree;
int foundping = -1;
int foundclient = -1;
int foundserver = -1;
guint16 type;
if (tvb_captured_length(tvb) < 18)
return 0;
type = tvb_get_guint8(tvb, 1);
if ((type == 4) || (type == 5)) {
foundping = 1;
} else {
int i = 0;
while (clienttypenames[i].strptr != NULL) {
if (tvb_get_ntohs(tvb, 14) == clienttypenames[i].value) {
foundserver = i;
break;
}
if (tvb_get_ntohs(tvb, 16) == clienttypenames[i].value) {
foundclient = i;
break;
}
i++;
}
}
if ((foundping < 0) && (foundclient < 0) && (foundserver < 0)) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_MACTELNET);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s > %s Direction: %s Type: %s",
tvb_ether_to_str(tvb, 2),
tvb_ether_to_str(tvb, 8),
((foundclient >= 0) || (type == 4) ? "Client->Server" : "Server->Client" ),
val_to_str(type, packettypenames, "Unknown Type:0x%02x")
);
if (tree) {
guint32 offset = 0;
mactelnet_item = proto_tree_add_item(tree, proto_mactelnet, tvb, 0, -1, ENC_NA);
mactelnet_tree = proto_item_add_subtree(mactelnet_item, ett_mactelnet);
proto_tree_add_item(mactelnet_tree, hf_mactelnet_protocolver, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(mactelnet_tree, hf_mactelnet_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(mactelnet_tree, hf_mactelnet_source_mac, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(mactelnet_tree, hf_mactelnet_destination_mac, tvb, offset, 6, ENC_NA);
offset += 6;
if (foundserver >= 0) {
proto_tree_add_item(mactelnet_tree, hf_mactelnet_session_id, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mactelnet_tree, hf_mactelnet_client_type, tvb, offset-2, 2, ENC_BIG_ENDIAN);
offset += 2;
} else if (foundclient >= 0) {
proto_tree_add_item(mactelnet_tree, hf_mactelnet_session_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mactelnet_tree, hf_mactelnet_client_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else if (foundping >= 0) {
offset += 4;
}
if (foundping < 0) {
proto_tree_add_item(mactelnet_tree, hf_mactelnet_databytes, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if (type == 1) {
while(tvb_reported_length_remaining(tvb, offset) > 0) {
if ((tvb_reported_length_remaining(tvb, offset) > 4) && (tvb_get_ntohl(tvb, offset) == control_packet)) {
guint8 datatype;
guint32 datalength;
mactelnet_control_item = proto_tree_add_item(mactelnet_tree, hf_mactelnet_control, tvb, offset, -1, ENC_NA);
mactelnet_control_tree = proto_item_add_subtree(mactelnet_control_item, ett_mactelnet);
proto_tree_add_item(mactelnet_control_tree, hf_mactelnet_control_packet, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
datatype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mactelnet_control_tree, hf_mactelnet_datatype, tvb, offset, 1, ENC_NA);
offset += 1;
datalength = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(mactelnet_control_tree, hf_mactelnet_control_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch (datatype) {
case 1:
proto_tree_add_item(mactelnet_control_tree, hf_mactelnet_control_encryption_key, tvb, offset, datalength, ENC_NA);
break;
case 2:
proto_tree_add_item(mactelnet_control_tree, hf_mactelnet_control_password, tvb, offset, datalength, ENC_NA);
break;
case 3:
proto_tree_add_item(mactelnet_control_tree, hf_mactelnet_control_username, tvb, offset, datalength, ENC_ASCII|ENC_NA);
break;
case 4:
proto_tree_add_item(mactelnet_control_tree, hf_mactelnet_control_terminal, tvb, offset, datalength, ENC_ASCII|ENC_NA);
break;
case 5:
proto_tree_add_item(mactelnet_control_tree, hf_mactelnet_control_width, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case 6:
proto_tree_add_item(mactelnet_control_tree, hf_mactelnet_control_height, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case 9:
break;
}
proto_item_set_len (mactelnet_control_item, datalength + 9);
offset += datalength;
} else {
tvbuff_t *next_client = tvb_new_subset_remaining(tvb, offset);
return call_data_dissector(next_client, pinfo, mactelnet_tree);
}
}
} else if ((type == 4) || (type == 5)) {
tvbuff_t *next_client = tvb_new_subset_remaining(tvb, offset);
return call_data_dissector(next_client, pinfo, mactelnet_tree);
}
}
return tvb_reported_length(tvb);
}
void
proto_register_mactelnet(void)
{
static hf_register_info hf[] = {
{ &hf_mactelnet_control_packet,
{ "Control Packet Magic Number", "mactelnet.control_packet",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mactelnet_type,
{ "Type", "mactelnet.type",
FT_UINT8, BASE_DEC, VALS(packettypenames), 0x0,
"Packet Type", HFILL }
},
{ &hf_mactelnet_protocolver,
{ "Protocol Version", "mactelnet.protocol_version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mactelnet_source_mac,
{ "Source MAC", "mactelnet.source_mac",
FT_ETHER, BASE_NONE, NULL , 0x0,
NULL, HFILL }
},
{ &hf_mactelnet_destination_mac,
{ "Destination MAC", "mactelnet.destination_mac",
FT_ETHER, BASE_NONE, NULL , 0x0,
NULL, HFILL }
},
{ &hf_mactelnet_session_id,
{ "Session ID", "mactelnet.session_id",
FT_UINT16, BASE_HEX, NULL , 0x0,
"Session ID for this connection", HFILL }
},
{ &hf_mactelnet_client_type,
{ "Client Type", "mactelnet.client_type",
FT_UINT16, BASE_HEX, VALS(clienttypenames) , 0x0,
NULL, HFILL }
},
{ &hf_mactelnet_databytes,
{ "Session Data Bytes", "mactelnet.session_bytes",
FT_UINT32, BASE_DEC, NULL , 0x0,
"Session data bytes received", HFILL }
},
{ &hf_mactelnet_datatype,
{ "Data Packet Type", "mactelnet.data_type",
FT_UINT8, BASE_HEX, VALS(controlpackettypenames) , 0x0,
NULL, HFILL }
},
{ &hf_mactelnet_control,
{ "Control Packet", "mactelnet.control",
FT_NONE, BASE_NONE, NULL , 0x0,
NULL, HFILL }
},
{ &hf_mactelnet_control_length,
{ "Control Data Length", "mactelnet.control_length",
FT_UINT32, BASE_DEC, NULL , 0x0,
"Control packet length", HFILL }
},
{ &hf_mactelnet_control_encryption_key,
{ "Encryption Key", "mactelnet.control_encryptionkey",
FT_BYTES, BASE_NONE, NULL , 0x0,
"Login encryption key", HFILL }
},
{ &hf_mactelnet_control_password,
{ "Password MD5", "mactelnet.control_password",
FT_BYTES, BASE_NONE, NULL , 0x0,
"Null padded MD5 password", HFILL }
},
{ &hf_mactelnet_control_username,
{ "Username", "mactelnet.control_username",
FT_STRING, BASE_NONE, NULL , 0x0,
NULL, HFILL }
},
{ &hf_mactelnet_control_terminal,
{ "Terminal Type", "mactelnet.control_terminaltype",
FT_STRING, BASE_NONE, NULL , 0x0,
NULL, HFILL }
},
{ &hf_mactelnet_control_width,
{ "Terminal Width", "mactelnet.control_width",
FT_UINT16, BASE_DEC, NULL , 0x0,
NULL, HFILL }
},
{ &hf_mactelnet_control_height,
{ "Terminal Height", "mactelnet.control_height",
FT_UINT16, BASE_DEC, NULL , 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_mactelnet,
&ett_mactelnet_control,
};
proto_mactelnet = proto_register_protocol ("MikroTik MAC-Telnet Protocol", PROTO_TAG_MACTELNET, "mactelnet");
proto_register_field_array (proto_mactelnet, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_mactelnet(void)
{
dissector_handle_t mactelnet_handle;
mactelnet_handle = create_dissector_handle(dissect_mactelnet, proto_mactelnet);
dissector_add_uint_with_preference("udp.port", MACTELNET_UDP_PORT, mactelnet_handle);
}
