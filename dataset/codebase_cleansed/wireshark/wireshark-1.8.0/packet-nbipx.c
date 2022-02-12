static void
add_routers(proto_tree *tree, tvbuff_t *tvb, int offset)
{
int i;
int rtr_offset;
guint32 router;
for (i = 0; i < 8; i++) {
rtr_offset = offset + (i << 2);
tvb_memcpy(tvb, (guint8 *)&router, rtr_offset, 4);
if (router != 0) {
proto_tree_add_text(tree, tvb, rtr_offset, 4,
"IPX Network: %s",
ipxnet_to_string((guint8*)&router));
}
}
}
static void
dissect_nbipx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gboolean has_routes;
proto_tree *nbipx_tree = NULL;
proto_item *ti = NULL;
int offset = 0;
guint8 packet_type;
guint8 name_type_flag;
proto_tree *name_type_flag_tree;
proto_item *tf;
char name[(NETBIOS_NAME_LEN - 1)*4 + 1];
int name_type;
gboolean has_payload;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NBIPX");
col_clear(pinfo->cinfo, COL_INFO);
if (pinfo->ipxptype == IPX_PACKET_TYPE_WANBCAST) {
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
name_type_flag = tvb_get_guint8(tvb, offset);
name_type = get_netbios_name(tvb, offset+2, name, (NETBIOS_NAME_LEN - 1)*4 + 1);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s<%02x>",
val_to_str(packet_type, nbipx_data_stream_type_vals, "Unknown"),
name, name_type);
}
if (nbipx_tree) {
tf = proto_tree_add_text(nbipx_tree, tvb, offset, 1,
"Name type flag: 0x%02x", name_type_flag);
name_type_flag_tree = proto_item_add_subtree(tf,
ett_nbipx_name_type_flags);
proto_tree_add_text(name_type_flag_tree, tvb, offset,
1, "%s",
decode_boolean_bitfield(name_type_flag, 0x80, 8,
"Group name", "Unique name"));
proto_tree_add_text(name_type_flag_tree, tvb, offset,
1, "%s",
decode_boolean_bitfield(name_type_flag, 0x40, 8,
"Name in use", "Name not used"));
proto_tree_add_text(name_type_flag_tree, tvb, offset,
1, "%s",
decode_boolean_bitfield(name_type_flag, 0x04, 8,
"Name registered", "Name not registered"));
proto_tree_add_text(name_type_flag_tree, tvb, offset,
1, "%s",
decode_boolean_bitfield(name_type_flag, 0x02, 8,
"Name duplicated", "Name not duplicated"));
proto_tree_add_text(name_type_flag_tree, tvb, offset,
1, "%s",
decode_boolean_bitfield(name_type_flag, 0x01, 8,
"Name deregistered", "Name not deregistered"));
}
offset += 1;
dissect_packet_type(tvb, offset, packet_type, nbipx_tree);
offset += 1;
if (nbipx_tree)
netbios_add_name("Name", tvb, offset, nbipx_tree);
offset += NETBIOS_NAME_LEN;
has_payload = FALSE;
break;
case NBIPX_SESSION_DATA:
case NBIPX_SESSION_END:
case NBIPX_SESSION_END_ACK:
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(packet_type, nbipx_data_stream_type_vals, "Unknown"));
}
dissect_conn_control(tvb, offset, nbipx_tree);
offset += 1;
dissect_packet_type(tvb, offset, packet_type, nbipx_tree);
offset += 1;
if (nbipx_tree) {
proto_tree_add_text(nbipx_tree, tvb, offset, 2,
"Source connection ID: 0x%04X",
tvb_get_letohs(tvb, offset));
}
offset += 2;
if (nbipx_tree) {
proto_tree_add_text(nbipx_tree, tvb, offset, 2,
"Destination connection ID: 0x%04X",
tvb_get_letohs(tvb, offset));
}
offset += 2;
if (nbipx_tree) {
proto_tree_add_text(nbipx_tree, tvb, offset, 2,
"Send sequence number: %u",
tvb_get_letohs(tvb, offset));
}
offset += 2;
if (nbipx_tree) {
proto_tree_add_text(nbipx_tree, tvb, offset, 2,
"Total data length: %u",
tvb_get_letohs(tvb, offset));
}
offset += 2;
if (nbipx_tree) {
proto_tree_add_text(nbipx_tree, tvb, offset, 2,
"Offset: %u",
tvb_get_letohs(tvb, offset));
}
offset += 2;
if (nbipx_tree) {
proto_tree_add_text(nbipx_tree, tvb, offset, 2,
"Data length: %u",
tvb_get_letohs(tvb, offset));
}
offset += 2;
if (nbipx_tree) {
proto_tree_add_text(nbipx_tree, tvb, offset, 2,
"Receive sequence number: %u",
tvb_get_letohs(tvb, offset));
}
offset += 2;
if (nbipx_tree) {
proto_tree_add_text(nbipx_tree, tvb, offset, 2,
"Bytes received: %u",
tvb_get_letohs(tvb, offset));
}
offset += 2;
has_payload = TRUE;
break;
case NBIPX_DIRECTED_DATAGRAM:
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(packet_type, nbipx_data_stream_type_vals, "Unknown"));
}
dissect_conn_control(tvb, offset, nbipx_tree);
offset += 1;
dissect_packet_type(tvb, offset, packet_type, nbipx_tree);
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
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(packet_type, nbipx_data_stream_type_vals, "Unknown"));
}
offset += 1;
dissect_packet_type(tvb, offset, packet_type, nbipx_tree);
offset += 1;
has_payload = FALSE;
}
if (ti != NULL)
proto_item_set_len(ti, offset);
if (has_payload && tvb_offset_exists(tvb, offset)) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_netbios_payload(next_tvb, pinfo, tree);
}
}
static void
dissect_conn_control(tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 conn_control;
proto_item *ti;
proto_tree *cc_tree;
if (tree) {
conn_control = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_text(tree, tvb, offset, 1,
"Connection control: 0x%02x", conn_control);
cc_tree = proto_item_add_subtree(ti, ett_nbipx_conn_ctrl);
proto_tree_add_text(cc_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(conn_control, 0x80, 8,
"System packet", "Non-system packet"));
proto_tree_add_text(cc_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(conn_control, 0x40, 8,
"Acknowledgement required",
"Acknowledgement not required"));
proto_tree_add_text(cc_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(conn_control, 0x20, 8,
"Attention", "No attention"));
proto_tree_add_text(cc_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(conn_control, 0x10, 8,
"End of message", "No end of message"));
proto_tree_add_text(cc_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(conn_control, 0x08, 8,
"Resend", "No resend"));
}
}
static void
dissect_packet_type(tvbuff_t *tvb, int offset, guint8 packet_type,
proto_tree *tree)
{
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"Packet Type: %s (%02X)",
val_to_str(packet_type, nbipx_data_stream_type_vals, "Unknown"),
packet_type);
}
}
void
proto_register_nbipx(void)
{
static gint *ett[] = {
&ett_nbipx,
&ett_nbipx_conn_ctrl,
&ett_nbipx_name_type_flags,
};
proto_nbipx = proto_register_protocol("NetBIOS over IPX",
"NBIPX", "nbipx");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nbipx(void)
{
dissector_handle_t nbipx_handle;
nbipx_handle = create_dissector_handle(dissect_nbipx, proto_nbipx);
dissector_add_uint("ipx.socket", IPX_SOCKET_NETBIOS, nbipx_handle);
}
static void
dissect_nmpi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *nmpi_tree = NULL;
proto_item *ti;
int offset = 0;
guint8 opcode;
guint8 nmpi_name_type;
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
nmpi_name_type = tvb_get_guint8(tvb, offset+1);
name_type = get_netbios_name(tvb, offset+4, name, (NETBIOS_NAME_LEN - 1)*4 + 1);
get_netbios_name(tvb, offset+20, node_name, (NETBIOS_NAME_LEN - 1)*4 + 1);
if (check_col(pinfo->cinfo, COL_INFO)) {
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
}
if (tree) {
proto_tree_add_text(nmpi_tree, tvb, offset, 1,
"Opcode: %s (0x%02x)",
val_to_str(opcode, nmpi_opcode_vals, "Unknown"),
opcode);
proto_tree_add_text(nmpi_tree, tvb, offset+1, 1,
"Name Type: %s (0x%02x)",
val_to_str(nmpi_name_type, nmpi_name_type_vals, "Unknown"),
nmpi_name_type);
proto_tree_add_text(nmpi_tree, tvb, offset+2, 2,
"Message ID: 0x%04x",
tvb_get_letohs(tvb, offset+2));
netbios_add_name("Requested name", tvb, offset+4, nmpi_tree);
netbios_add_name("Source name", tvb, offset+20, nmpi_tree);
}
offset += 1 + 1 + 2 + NETBIOS_NAME_LEN + NETBIOS_NAME_LEN;
if (opcode == IMSLOT_SEND && tvb_offset_exists(tvb, offset)) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_netbios_payload(next_tvb, pinfo, tree);
}
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
