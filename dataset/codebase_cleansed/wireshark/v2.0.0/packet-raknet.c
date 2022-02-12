static int
raknet_dissect_0x00(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_tree *sub_tree;
gint item_size;
gint offset;
sub_tree = init_raknet(tvb, pinfo, tree, &offset);
if (sub_tree != NULL) {
item_size = 8;
proto_tree_add_item(sub_tree, hf_raknet_general_elapsed_time, tvb,
offset, item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 16;
proto_tree_add_item(sub_tree, hf_raknet_general_magic, tvb, offset,
item_size, ENC_NA);
}
return tvb_reported_length(tvb);
}
static int
raknet_dissect_0x01(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_tree *sub_tree;
gint item_size;
gint offset;
sub_tree = init_raknet(tvb, pinfo, tree, &offset);
if (sub_tree != NULL) {
item_size = 8;
proto_tree_add_item(sub_tree, hf_raknet_general_elapsed_time, tvb,
offset, item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 16;
proto_tree_add_item(sub_tree, hf_raknet_general_magic, tvb, offset,
item_size, ENC_NA);
}
return tvb_reported_length(tvb);
}
static int
raknet_dissect_0x02(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_tree *sub_tree;
gint item_size;
gint offset;
sub_tree = init_raknet(tvb, pinfo, tree, &offset);
if (sub_tree != NULL) {
item_size = 8;
proto_tree_add_item(sub_tree, hf_raknet_general_elapsed_time, tvb,
offset, item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 16;
proto_tree_add_item(sub_tree, hf_raknet_general_magic, tvb, offset,
item_size, ENC_NA);
}
return tvb_reported_length(tvb);
}
static int
raknet_dissect_0x05(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_tree *sub_tree;
gint item_size;
gint offset;
sub_tree = init_raknet(tvb, pinfo, tree, &offset);
if (sub_tree != NULL) {
item_size = 16;
proto_tree_add_item(sub_tree, hf_raknet_general_magic, tvb, offset,
item_size, ENC_NA);
offset += item_size;
item_size = 1;
proto_tree_add_item(sub_tree, hf_raknet_general_raknet_proto_ver, tvb,
offset, item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = -1;
proto_tree_add_item(sub_tree, hf_raknet_0x05_null_padding, tvb, offset,
item_size, ENC_NA);
}
return tvb_reported_length(tvb);
}
static int
raknet_dissect_0x06(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_tree *sub_tree;
gint item_size;
gint offset;
sub_tree = init_raknet(tvb, pinfo, tree, &offset);
if (sub_tree != NULL) {
item_size = 16;
proto_tree_add_item(sub_tree, hf_raknet_general_magic, tvb, offset,
item_size, ENC_NA);
offset += item_size;
item_size = 8;
proto_tree_add_item(sub_tree, hf_raknet_general_server_id, tvb, offset,
item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 1;
proto_tree_add_item(sub_tree, hf_raknet_0x06_server_security, tvb,
offset, item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 2;
proto_tree_add_item(sub_tree, hf_raknet_general_mtu_size, tvb, offset,
item_size, ENC_BIG_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int
raknet_dissect_0x07(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_tree *sub_tree;
gint item_size;
gint offset;
sub_tree = init_raknet(tvb, pinfo, tree, &offset);
if (sub_tree != NULL) {
item_size = 16;
proto_tree_add_item(sub_tree, hf_raknet_general_magic, tvb, offset,
item_size, ENC_NA);
offset += item_size;
item_size = 1;
proto_tree_add_item(sub_tree, hf_raknet_general_security, tvb, offset,
item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 4;
proto_tree_add_item(sub_tree, hf_raknet_0x07_cookie, tvb, offset,
item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 2;
proto_tree_add_item(sub_tree, hf_raknet_general_udp_port, tvb, offset,
item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 2;
proto_tree_add_item(sub_tree, hf_raknet_general_mtu_size, tvb, offset,
item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 8;
proto_tree_add_item(sub_tree, hf_raknet_general_client_id, tvb, offset,
item_size, ENC_BIG_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int
raknet_dissect_0x08(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_tree *sub_tree;
gint item_size;
gint offset;
sub_tree = init_raknet(tvb, pinfo, tree, &offset);
if (sub_tree != NULL) {
item_size = 16;
proto_tree_add_item(sub_tree, hf_raknet_general_magic, tvb, offset,
item_size, ENC_NA);
offset += item_size;
item_size = 8;
proto_tree_add_item(sub_tree, hf_raknet_general_server_id, tvb, offset,
item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 1;
proto_tree_add_item(sub_tree, hf_raknet_general_security, tvb, offset,
item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 4;
proto_tree_add_item(sub_tree, hf_raknet_0x07_cookie, tvb, offset,
item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 2;
proto_tree_add_item(sub_tree, hf_raknet_general_udp_port, tvb, offset,
item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 2;
proto_tree_add_item(sub_tree, hf_raknet_general_mtu_size, tvb, offset,
item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 1;
proto_tree_add_item(sub_tree, hf_raknet_general_security, tvb, offset,
item_size, ENC_BIG_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int
raknet_dissect_0x19(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_tree *sub_tree;
gint item_size;
gint offset;
sub_tree = init_raknet(tvb, pinfo, tree, &offset);
if (sub_tree != NULL) {
item_size = 1;
proto_tree_add_item(sub_tree, hf_raknet_general_raknet_proto_ver, tvb,
offset, item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 16;
proto_tree_add_item(sub_tree, hf_raknet_general_magic, tvb, offset,
item_size, ENC_NA);
offset += item_size;
item_size = 8;
proto_tree_add_item(sub_tree, hf_raknet_general_server_id, tvb, offset,
item_size, ENC_BIG_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int
raknet_dissect_0x1C(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_tree *sub_tree;
gint item_size;
gint str_size;
gint offset;
sub_tree = init_raknet(tvb, pinfo, tree, &offset);
if (sub_tree != NULL) {
item_size = 8;
proto_tree_add_item(sub_tree, hf_raknet_general_elapsed_time, tvb,
offset, item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 8;
proto_tree_add_item(sub_tree, hf_raknet_general_server_id, tvb, offset,
item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 16;
proto_tree_add_item(sub_tree, hf_raknet_general_magic, tvb, offset,
item_size, ENC_NA);
offset += item_size;
str_size = tvb_get_ntohs(tvb, offset);
item_size = 2;
proto_tree_add_item(sub_tree, hf_raknet_0x1C_server_id_str_len, tvb,
offset, item_size, ENC_BIG_ENDIAN);
offset += item_size;
proto_tree_add_item(sub_tree, hf_raknet_0x1C_server_id_str, tvb, offset,
str_size, ENC_NA|ENC_ASCII);
}
return tvb_reported_length(tvb);
}
static void
raknet_init_packet_names(void)
{
unsigned int i;
for (i = 0; i < RAKNET_PACKET_ID_COUNT; i++) {
packet_names[i].value = raknet_handler[i].vs.value;
packet_names[i].strptr = raknet_handler[i].vs.strptr;
}
packet_names[RAKNET_PACKET_ID_COUNT].value = 0;
packet_names[RAKNET_PACKET_ID_COUNT].strptr = NULL;
}
static proto_tree *
init_raknet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset)
{
proto_tree *sub_tree;
proto_item *ti;
guint8 packet_id;
*offset = 0;
ti = proto_tree_add_item(tree, proto_raknet, tvb, 0, -1, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_raknet);
packet_id = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(sub_tree, hf_raknet_packet_id, tvb, *offset,
1, ENC_BIG_ENDIAN);
*offset += 1;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(packet_id, packet_names, "Unknown (%#x)"));
proto_item_append_text(ti, ", Packet id %#x", packet_id);
return sub_tree;
}
static void
dissect_raknet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 packet_id;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RAKNET");
col_clear(pinfo->cinfo, COL_INFO);
packet_id = tvb_get_guint8(tvb, 0);
if (!dissector_try_uint_new(raknet_dissector_table, packet_id, tvb,
pinfo, tree, TRUE, NULL)) {
proto_tree_add_expert(tree, pinfo, &ei_raknet_uknown_id, tvb,
0, 1);
}
}
void
proto_register_raknet(void)
{
static hf_register_info hf[] = {
{ &hf_raknet_packet_id,
{ "RAKNET Packet ID", "raknet.id",
FT_UINT8, BASE_HEX,
VALS(packet_names), 0x0,
NULL, HFILL }
},
{ &hf_raknet_general_client_id,
{ "RAKNET Client ID", "raknet.client_id",
FT_UINT64, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_raknet_general_elapsed_time,
{ "RAKNET time since start (ms)", "raknet.elapsed_time",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_raknet_general_magic,
{ "RAKNET magic", "raknet.con_pingopen_magic",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_raknet_general_mtu_size,
{ "RAKNET MTU size", "raknet.MTU_size",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_raknet_general_raknet_proto_ver,
{ "RAKNET RakNet protocol version", "raknet.proto_ver",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_raknet_general_server_id,
{ "RAKNET Server ID", "raknet.server_id",
FT_UINT64, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_raknet_general_security,
{ "RAKNET security", "raknet.security",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_raknet_general_udp_port,
{ "RAKNET UDP port", "raknet.UDP_port",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_raknet_0x05_null_padding,
{ "RAKNET Null padding", "raknet.null_padding",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_raknet_0x06_server_security,
{ "RAKNET Server security", "raknet.server_security",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_raknet_0x07_cookie,
{ "RAKNET cookie", "raknet.cookie",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_raknet_0x1C_server_id_str_len,
{ "RAKNET Server ID string len", "raknet.server_id_str_len",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_raknet_0x1C_server_id_str,
{ "RAKNET Server ID string", "raknet.server_id_str",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_raknet,
};
static ei_register_info ei[] = {
{ &ei_raknet_uknown_id, { "raknet.unknown.id", PI_UNDECODED, PI_ERROR,
"RakNet unknown or not implemented packet id",
EXPFILL }
}
};
expert_module_t *expert_raknet;
raknet_init_packet_names();
expert_raknet = expert_register_protocol(proto_raknet);
expert_register_field_array(expert_raknet, ei, array_length(ei));
proto_raknet = proto_register_protocol (
"RAKNET game libs",
"RAKNET",
"raknet"
);
proto_register_field_array(proto_raknet, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
raknet_dissector_table =
register_dissector_table("raknet.packet_id", "RakNet libs packet ids",
FT_UINT8, BASE_HEX);
register_dissector("raknet", dissect_raknet, proto_raknet);
}
void
proto_reg_handoff_raknet(void)
{
dissector_handle_t raknet_handle_tmp;
unsigned int i;
for (i = 0; i < RAKNET_PACKET_ID_COUNT; i++) {
raknet_handle_tmp =
new_create_dissector_handle(raknet_handler[i].dissector_fp,
proto_raknet);
dissector_add_uint("raknet.packet_id", raknet_handler[i].vs.value,
raknet_handle_tmp);
}
}
