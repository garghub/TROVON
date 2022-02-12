static void
add_routers(proto_tree *tree, tvbuff_t *tvb, int offset)
{
int i;
for (i = 0; i < 8; i++) {
if (tvb_get_ntohl(tvb, offset) != 0) {
proto_tree_add_item(tree, hf_nbipx_ipx_network, tvb, offset, 4, ENC_NA);
}
offset += 4;
}
}
static void
dissect_netbios_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
heur_dtbl_entry_t *hdtbl_entry;
if (!dissector_try_heuristic(netbios_heur_subdissector_list,
tvb, pinfo, tree, &hdtbl_entry, NULL))
call_data_dissector(tvb, pinfo, tree);
}
static int
dissect_nbipx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
gboolean has_routes;
proto_tree *nbipx_tree = NULL;
proto_item *ti = NULL;
int offset = 0;
guint8 packet_type;
proto_tree *name_type_flag_tree;
proto_item *tf;
char name[(NETBIOS_NAME_LEN - 1)*4 + 1];
int name_type;
gboolean has_payload;
tvbuff_t *next_tvb;
ipxhdr_t *ipxh;
if (data == NULL)
return 0;
ipxh = (ipxhdr_t*)data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NBIPX");
col_clear(pinfo->cinfo, COL_INFO);
if (ipxh->ipx_type == IPX_PACKET_TYPE_WANBCAST) {
has_routes = TRUE;
} else {
has_routes = FALSE;
if (tvb_reported_length(tvb) == 50) {
packet_type = tvb_get_guint8(tvb, offset + 32 + 1);
switch (packet_type) {
case NBIPX_FIND_NAME:
case NBIPX_NAME_RECOGNIZED:
case NBIPX_CHECK_NAME:
case NBIPX_NAME_IN_USE:
case NBIPX_DEREGISTER_NAME:
has_routes = TRUE;
break;
}
}
}
if (tree) {
ti = proto_tree_add_item(tree, proto_nbipx, tvb, 0,
-1, ENC_NA);
nbipx_tree = proto_item_add_subtree(ti, ett_nbipx);
}
if (has_routes) {
if (tree)
add_routers(nbipx_tree, tvb, 0);
offset += 32;
}
packet_type = tvb_get_guint8(tvb, offset + 1);
switch (packet_type) {
case NBIPX_FIND_NAME:
case NBIPX_NAME_RECOGNIZED:
case NBIPX_CHECK_NAME:
case NBIPX_NAME_IN_USE:
case NBIPX_DEREGISTER_NAME:
name_type = get_netbios_name(tvb, offset+2, name, (NETBIOS_NAME_LEN - 1)*4 + 1);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s<%02x>",
val_to_str_const(packet_type, nbipx_data_stream_type_vals, "Unknown"),
name, name_type);
if (nbipx_tree) {
tf = proto_tree_add_item(nbipx_tree, hf_nbipx_name_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
name_type_flag_tree = proto_item_add_subtree(tf, ett_nbipx_name_type_flags);
proto_tree_add_item(name_type_flag_tree, hf_nbipx_name_flags_group, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(name_type_flag_tree, hf_nbipx_name_flags_in_use, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(name_type_flag_tree, hf_nbipx_name_flags_registered, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(name_type_flag_tree, hf_nbipx_name_flags_duplicated, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(name_type_flag_tree, hf_nbipx_name_flags_deregistered, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
offset += 1;
proto_tree_add_uint(nbipx_tree, hf_nbipx_packettype, tvb, offset, 1, packet_type);
offset += 1;
if (nbipx_tree)
netbios_add_name("Name", tvb, offset, nbipx_tree);
offset += NETBIOS_NAME_LEN;
has_payload = FALSE;
break;
case NBIPX_SESSION_DATA:
case NBIPX_SESSION_END:
case NBIPX_SESSION_END_ACK:
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(packet_type, nbipx_data_stream_type_vals, "Unknown"));
dissect_conn_control(tvb, offset, nbipx_tree);
offset += 1;
proto_tree_add_uint(nbipx_tree, hf_nbipx_packettype, tvb, offset, 1, packet_type);
offset += 1;
proto_tree_add_item(nbipx_tree, hf_nbipx_session_src_conn_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(nbipx_tree, hf_nbipx_session_dest_conn_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(nbipx_tree, hf_nbipx_session_send_seq_number, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(nbipx_tree, hf_nbipx_session_total_data_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(nbipx_tree, hf_nbipx_session_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(nbipx_tree, hf_nbipx_session_data_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(nbipx_tree, hf_nbipx_session_recv_seq_number, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(nbipx_tree, hf_nbipx_session_bytes_received, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
has_payload = TRUE;
break;
case NBIPX_DIRECTED_DATAGRAM:
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(packet_type, nbipx_data_stream_type_vals, "Unknown"));
dissect_conn_control(tvb, offset, nbipx_tree);
offset += 1;
proto_tree_add_uint(nbipx_tree, hf_nbipx_packettype, tvb, offset, 1, packet_type);
offset += 1;
if (nbipx_tree)
netbios_add_name("Receiver's Name", tvb, offset,
nbipx_tree);
offset += NETBIOS_NAME_LEN;
if (nbipx_tree)
netbios_add_name("Sender's Name", tvb, offset,
nbipx_tree);
offset += NETBIOS_NAME_LEN;
has_payload = TRUE;
break;
default:
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(packet_type, nbipx_data_stream_type_vals, "Unknown"));
offset += 1;
proto_tree_add_uint(nbipx_tree, hf_nbipx_packettype, tvb, offset, 1, packet_type);
offset += 1;
has_payload = FALSE;
}
if (ti != NULL)
proto_item_set_len(ti, offset);
if (has_payload && tvb_offset_exists(tvb, offset)) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_netbios_payload(next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static void
dissect_conn_control(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *cc_tree;
if (tree) {
ti = proto_tree_add_item(tree, hf_nbipx_conn_control, tvb, offset, 1, ENC_LITTLE_ENDIAN);
cc_tree = proto_item_add_subtree(ti, ett_nbipx_conn_ctrl);
proto_tree_add_item(cc_tree, hf_nbipx_conn_control_sys_packet, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cc_tree, hf_nbipx_conn_control_ack, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cc_tree, hf_nbipx_conn_control_attention, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cc_tree, hf_nbipx_conn_control_end_msg, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cc_tree, hf_nbipx_conn_control_resend, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
}
void
proto_register_nbipx(void)
{
static hf_register_info hf[] = {
{ &hf_nbipx_packettype,
{ "Packet Type", "nmpi.packettype",
FT_UINT8, BASE_HEX, VALS(nbipx_data_stream_type_vals), 0,
NULL, HFILL }
},
{ &hf_nbipx_name_flags,
{ "Name type flag", "nmpi.name_flags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_nbipx_name_flags_group,
{ "Name", "nmpi.name_flags.group",
FT_BOOLEAN, 8, TFS(&tfs_group_unique_name), 0x80,
NULL, HFILL }
},
{ &hf_nbipx_name_flags_in_use,
{ "In use", "nmpi.name_flags.in_use",
FT_BOOLEAN, 8, TFS(&tfs_used_notused), 0x40,
NULL, HFILL }
},
{ &hf_nbipx_name_flags_registered,
{ "Registered", "nmpi.name_flags.registered",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04,
NULL, HFILL }
},
{ &hf_nbipx_name_flags_duplicated,
{ "Duplicated", "nmpi.name_flags.duplicated",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_nbipx_name_flags_deregistered,
{ "Deregistered", "nmpi.name_flags.deregistered",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_nbipx_conn_control,
{ "Connection control", "nmpi.conn_control",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_nbipx_conn_control_sys_packet,
{ "Packet", "nmpi.conn_control.sys_packet",
FT_BOOLEAN, 8, TFS(&tfs_system_non_system), 0x80,
NULL, HFILL }
},
{ &hf_nbipx_conn_control_ack,
{ "Acknowledgement", "nmpi.conn_control.ack",
FT_BOOLEAN, 8, TFS(&tfs_required_not_required), 0x40,
NULL, HFILL }
},
{ &hf_nbipx_conn_control_attention,
{ "Attention", "nmpi.conn_control.attention",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }
},
{ &hf_nbipx_conn_control_end_msg,
{ "End of message", "nmpi.conn_control.end_msg",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
NULL, HFILL }
},
{ &hf_nbipx_conn_control_resend,
{ "Resend", "nmpi.conn_control.resend",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }
},
{ &hf_nbipx_session_src_conn_id,
{ "Source connection ID", "nmpi.session.src_conn_id",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_nbipx_session_dest_conn_id,
{ "Destination connection ID", "nmpi.session.dest_conn_id",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_nbipx_session_send_seq_number,
{ "Send sequence number", "nmpi.session.send_seq_number",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_nbipx_session_total_data_length,
{ "Total data length", "nmpi.session.total_data_length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_nbipx_session_offset,
{ "Offset", "nmpi.session.offset",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_nbipx_session_data_length,
{ "Data length", "nmpi.session.data_length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_nbipx_session_recv_seq_number,
{ "Receive sequence number", "nmpi.session.recv_seq_number",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_nbipx_session_bytes_received,
{ "Bytes received", "nmpi.session.bytes_received",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_nbipx_ipx_network,
{ "IPX Network", "nmpi.ipx_network",
FT_IPXNET, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_nbipx_opcode,
{ "Opcode", "nmpi.opcode",
FT_UINT8, BASE_HEX, VALS(nmpi_opcode_vals), 0,
NULL, HFILL }
},
{ &hf_nbipx_name_type,
{ "Name Type", "nmpi.name_type",
FT_UINT8, BASE_HEX, VALS(nmpi_name_type_vals), 0,
NULL, HFILL }
},
{ &hf_nbipx_messageid,
{ "Message ID", "nmpi.messageid",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_nbipx,
&ett_nbipx_conn_ctrl,
&ett_nbipx_name_type_flags,
};
proto_nbipx = proto_register_protocol("NetBIOS over IPX", "NBIPX", "nbipx");
proto_register_field_array(proto_nbipx, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nbipx(void)
{
dissector_handle_t nbipx_handle;
nbipx_handle = create_dissector_handle(dissect_nbipx, proto_nbipx);
dissector_add_uint("ipx.socket", IPX_SOCKET_NETBIOS, nbipx_handle);
netbios_heur_subdissector_list = find_heur_dissector_list("netbios");
}
static int
dissect_nmpi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *nmpi_tree = NULL;
proto_item *ti;
int offset = 0;
guint8 opcode;
char name[(NETBIOS_NAME_LEN - 1)*4 + 1];
int name_type;
char node_name[(NETBIOS_NAME_LEN - 1)*4 + 1];
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NMPI");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_nmpi, tvb, offset, 68,
ENC_NA);
nmpi_tree = proto_item_add_subtree(ti, ett_nmpi);
add_routers(nmpi_tree, tvb, offset);
}
offset += 32;
opcode = tvb_get_guint8(tvb, offset);
name_type = get_netbios_name(tvb, offset+4, name, (NETBIOS_NAME_LEN - 1)*4 + 1);
get_netbios_name(tvb, offset+20, node_name, (NETBIOS_NAME_LEN - 1)*4 + 1);
switch (opcode) {
case INAME_CLAIM:
col_add_fstr(pinfo->cinfo, COL_INFO, "Claim name %s<%02x>",
name, name_type);
break;
case INAME_DELETE:
col_add_fstr(pinfo->cinfo, COL_INFO, "Delete name %s<%02x>",
name, name_type);
break;
case INAME_QUERY:
col_add_fstr(pinfo->cinfo, COL_INFO, "Query name %s<%02x>",
name, name_type);
break;
case INAME_FOUND:
col_add_fstr(pinfo->cinfo, COL_INFO, "Name %s<%02x> found",
name, name_type);
break;
case IMSG_HANGUP:
col_add_fstr(pinfo->cinfo, COL_INFO,
"Messenger hangup on %s<%02x>", name, name_type);
break;
case IMSLOT_SEND:
col_add_fstr(pinfo->cinfo, COL_INFO,
"Mailslot write to %s<%02x>", name, name_type);
break;
case IMSLOT_FIND:
col_add_fstr(pinfo->cinfo, COL_INFO,
"Find mailslot name %s<%02x>", name, name_type);
break;
case IMSLOT_NAME:
col_add_fstr(pinfo->cinfo, COL_INFO,
"Mailslot name %s<%02x> found", name, name_type);
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO,
"Unknown NMPI op 0x%02x: name %s<%02x>",
opcode, name, name_type);
break;
}
if (tree) {
proto_tree_add_item(nmpi_tree, hf_nbipx_opcode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(nmpi_tree, hf_nbipx_name_type, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(nmpi_tree, hf_nbipx_messageid, tvb, offset+2, 2, ENC_LITTLE_ENDIAN);
netbios_add_name("Requested name", tvb, offset+4, nmpi_tree);
netbios_add_name("Source name", tvb, offset+20, nmpi_tree);
}
offset += 1 + 1 + 2 + NETBIOS_NAME_LEN + NETBIOS_NAME_LEN;
if (opcode == IMSLOT_SEND && tvb_offset_exists(tvb, offset)) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_netbios_payload(next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
void
proto_register_nmpi(void)
{
static gint *ett[] = {
&ett_nmpi,
&ett_nmpi_name_type_flags,
};
proto_nmpi = proto_register_protocol("Name Management Protocol over IPX",
"NMPI", "nmpi");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nmpi(void)
{
dissector_handle_t nmpi_handle;
nmpi_handle = create_dissector_handle(dissect_nmpi, proto_nmpi);
dissector_add_uint("ipx.socket", IPX_SOCKET_NWLINK_SMB_NAMEQUERY,
nmpi_handle);
dissector_add_uint("ipx.socket", IPX_SOCKET_NWLINK_SMB_MAILSLOT,
nmpi_handle);
}
