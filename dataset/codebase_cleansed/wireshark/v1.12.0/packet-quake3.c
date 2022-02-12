static void
dissect_quake3_ConnectionlessPacket(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, int* direction)
{
proto_tree *cl_tree = NULL;
proto_item *text_item = NULL;
proto_tree *text_tree = NULL;
guint8 *text;
int len;
int offset;
guint32 marker;
int command;
int command_len;
gboolean command_finished = FALSE;
marker = tvb_get_ntohl(tvb, 0);
if (tree) {
proto_item *cl_item = NULL;
cl_item = proto_tree_add_text(tree, tvb,
0, -1, "Connectionless");
cl_tree = proto_item_add_subtree(cl_item, ett_quake3_connectionless);
proto_tree_add_uint(cl_tree, hf_quake3_connectionless_marker,
tvb, 0, 4, marker);
}
offset = 4;
text = tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &len, ENC_ASCII|ENC_NA);
if (cl_tree) {
text_item = proto_tree_add_string(cl_tree,
hf_quake3_connectionless_text,
tvb, offset, len, text);
text_tree = proto_item_add_subtree(text_item, ett_quake3_connectionless_text);
}
command = COMMAND_UNKNOWN;
command_len = 0;
if (strncmp(text, "statusResponse", 14) == 0) {
command = COMMAND_statusResponse;
*direction = DIR_S2C;
command_len = 14;
}
else if (strncmp(text, "getstatus", 9) == 0) {
command = COMMAND_getstatus;
*direction = DIR_C2S;
command_len = 9;
}
else if (strncmp(text, "infoResponse", 12) == 0) {
command = COMMAND_infoResponse;
*direction = DIR_S2C;
command_len = 12;
}
else if (strncmp(text, "getinfo", 7) == 0) {
command = COMMAND_getinfo;
*direction = DIR_C2S;
command_len = 7;
}
else if (strncmp(text, "challengeResponse", 17) == 0) {
command = COMMAND_challengeResponse;
*direction = DIR_S2C;
command_len = 17;
}
else if (strncmp(text, "getchallenge", 12) == 0) {
command = COMMAND_getchallenge;
*direction = DIR_C2S;
command_len = 12;
}
else if (strncmp(text, "connectResponse", 15) == 0) {
command = COMMAND_connectResponse;
*direction = DIR_S2C;
command_len = 15;
}
else if (strncmp(text, "connect", 7) == 0) {
command = COMMAND_connect;
*direction = DIR_C2S;
command_len = 7;
}
else if (strncmp(text, "rconResponse", 12) == 0) {
command = COMMAND_rconResponse;
*direction = DIR_S2C;
command_len = 12;
}
else if (strncmp(text, "rcon", 4) == 0) {
command = COMMAND_rcon;
*direction = DIR_C2S;
command_len = 4;
}
else if (strncmp(text, "getmotdResponse", 15) == 0) {
command = COMMAND_getmotdResponse;
*direction = DIR_M2C;
command_len = 15;
}
else if (strncmp(text, "getmotd", 7) == 0) {
command = COMMAND_getmotd;
*direction = DIR_C2M;
command_len = 7;
}
else if (strncmp(text, "getserversResponse", 18) == 0) {
int base;
command = COMMAND_getserversResponse;
*direction = DIR_M2C;
command_len = 18;
if (text_item) {
proto_item_set_len(text_item, tvb_length_remaining(tvb, offset));
proto_item_set_text(text_item, "Text: getserversResponse<DATA>");
}
if (text_tree)
proto_tree_add_string(text_tree, hf_quake3_connectionless_command,
tvb, offset, command_len,
val_to_str_const(command, names_command, "Unknown"));
command_finished = TRUE;
base = offset + 18;
while (tvb_reported_length_remaining(tvb, base) >= 7) {
guint32 ip_addr;
guint16 udp_port;
ip_addr = tvb_get_ipv4(tvb, base + 1);
udp_port = tvb_get_ntohs(tvb, base + 5);
if (text_tree) {
proto_item *server_item;
proto_tree *server_tree;
server_item = proto_tree_add_text(text_tree,
tvb, base, 7,
"Server: %s:%u",
get_hostname(ip_addr),
udp_port);
server_tree = proto_item_add_subtree(
server_item,
ett_quake3_server);
proto_tree_add_ipv4(server_tree, hf_quake3_server_addr,
tvb, base + 1, 4, ip_addr);
proto_tree_add_uint(server_tree, hf_quake3_server_port,
tvb, base + 5, 2, udp_port);
}
base += 7;
}
}
else if (strncmp(text, "getservers", 10) == 0) {
command = COMMAND_getservers;
*direction = DIR_C2M;
command_len = 10;
}
else if (strncmp(text, "getKeyAuthorize", 15) == 0) {
command = COMMAND_getKeyAuthorize;
*direction = DIR_C2M;
command_len = 15;
}
else if (strncmp(text, "getIpAuthorize", 14) == 0) {
command = COMMAND_getIpAuthorize;
*direction = DIR_C2M;
command_len = 14;
}
else if (strncmp(text, "ipAuthorize", 11) == 0) {
command = COMMAND_ipAuthorize;
*direction = DIR_M2C;
command_len = 11;
}
else {
*direction = DIR_UNKNOWN;
}
if (text_tree && command_finished == FALSE) {
proto_tree_add_string(text_tree, hf_quake3_connectionless_command,
tvb, offset, command_len,
val_to_str_const(command, names_command, "Unknown"));
}
}
static void
dissect_quake3_client_commands(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
call_dissector(data_handle,tvb, pinfo, tree);
}
static void
dissect_quake3_server_commands(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
call_dissector(data_handle,tvb, pinfo, tree);
}
static void
dissect_quake3_GamePacket(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int *direction)
{
proto_tree *game_tree = NULL;
guint32 seq1;
guint32 seq2;
int rel1;
int rel2;
int offset;
guint rest_length;
*direction = (pinfo->destport == gbl_quake3_server_port) ?
DIR_C2S : DIR_S2C;
if (tree) {
proto_item *game_item;
game_item = proto_tree_add_text(tree, tvb, 0, -1, "Game");
game_tree = proto_item_add_subtree(game_item, ett_quake3_game);
}
offset = 0;
seq1 = tvb_get_letohs(tvb, offset);
rel1 = seq1 & 0x8000 ? 1 : 0;
seq1 &= ~0x8000;
if (game_tree) {
proto_item *seq1_item = proto_tree_add_text(game_tree,
tvb, offset, 2, "Current Sequence: %u (%s)",
seq1, val_to_str(rel1,names_reliable,"%u"));
proto_tree *seq1_tree = proto_item_add_subtree(
seq1_item, ett_quake3_game_seq1);
proto_tree_add_uint(seq1_tree, hf_quake3_game_seq1,
tvb, offset, 2, seq1);
proto_tree_add_boolean(seq1_tree, hf_quake3_game_rel1,
tvb, offset+1, 1, rel1);
}
offset += 2;
seq2 = tvb_get_letohs(tvb, offset);
rel2 = seq2 & 0x8000 ? 1 : 0;
seq2 &= ~0x8000;
if (game_tree) {
proto_item *seq2_item = proto_tree_add_text(game_tree,
tvb, offset, 2, "Acknowledge Sequence: %u (%s)",
seq2, val_to_str(rel2,names_reliable,"%u"));
proto_tree *seq2_tree = proto_item_add_subtree(
seq2_item, ett_quake3_game_seq2);
proto_tree_add_uint(seq2_tree, hf_quake3_game_seq2,
tvb, offset, 2, seq2);
proto_tree_add_boolean(seq2_tree, hf_quake3_game_rel2,
tvb, offset+1, 1, rel2);
}
offset += 2;
if (*direction == DIR_C2S) {
guint16 qport = tvb_get_letohs(tvb, offset);
if (game_tree) {
proto_tree_add_uint(game_tree, hf_quake3_game_qport,
tvb, offset, 2, qport);
}
offset +=2;
}
rest_length = tvb_reported_length(tvb) - offset;
if (rest_length) {
tvbuff_t *next_tvb =
tvb_new_subset(tvb, offset, rest_length , rest_length);
if (*direction == DIR_C2S) {
proto_tree *c_tree = NULL;
if (tree) {
proto_item *c_item;
c_item = proto_tree_add_text(game_tree, next_tvb,
0, -1, "Client Commands");
c_tree = proto_item_add_subtree(
c_item, ett_quake3_game_clc);
}
dissect_quake3_client_commands(next_tvb, pinfo, c_tree);
}
else {
proto_tree *c_tree = NULL;
if (tree) {
proto_item *c_item;
c_item = proto_tree_add_text(game_tree, next_tvb,
0, -1, "Server Commands");
c_tree = proto_item_add_subtree(
c_item, ett_quake3_game_svc);
}
dissect_quake3_server_commands(next_tvb, pinfo, c_tree);
}
}
}
static void
dissect_quake3(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *quake3_tree = NULL;
proto_item *dir_item = NULL;
int direction;
direction = DIR_UNKNOWN;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "QUAKE3");
if (tree) {
proto_item *quake3_item;
quake3_item = proto_tree_add_item(tree, proto_quake3,
tvb, 0, -1, ENC_NA);
quake3_tree = proto_item_add_subtree(quake3_item, ett_quake3);
dir_item = proto_tree_add_none_format(
quake3_tree,
hf_quake3_direction, tvb, 0, 0,
"Direction: %s",
val_to_str(direction,
names_direction, "%u"));
}
if (tvb_get_ntohl(tvb, 0) == 0xffffffff) {
col_set_str(pinfo->cinfo, COL_INFO, "Connectionless ");
proto_tree_add_uint_format(quake3_tree,
hf_quake3_connectionless,
tvb, 0, 0, 1,
"Type: Connectionless");
dissect_quake3_ConnectionlessPacket(
tvb, pinfo, quake3_tree, &direction);
}
else {
col_set_str(pinfo->cinfo, COL_INFO, "Game ");
proto_tree_add_uint_format(quake3_tree,
hf_quake3_game,
tvb, 0, 0, 1,
"Type: Game");
dissect_quake3_GamePacket(
tvb, pinfo, quake3_tree, &direction);
}
if (direction != DIR_UNKNOWN && dir_item)
proto_item_set_text(dir_item,
"Direction: %s",
val_to_str(direction,
names_direction, "%u"));
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(direction,
names_direction, "%u"));
}
void
proto_register_quake3(void)
{
static hf_register_info hf[] = {
{ &hf_quake3_direction,
{ "Direction", "quake3.direction",
FT_NONE, BASE_NONE, NULL, 0x0,
"Packet Direction", HFILL }},
{ &hf_quake3_connectionless,
{ "Connectionless", "quake3.connectionless",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_quake3_game,
{ "Game", "quake3.game",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_quake3_connectionless_marker,
{ "Marker", "quake3.connectionless.marker",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_quake3_connectionless_text,
{ "Text", "quake3.connectionless.text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_quake3_connectionless_command,
{ "Command", "quake3.connectionless.command",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_quake3_server_addr,
{ "Server Address", "quake3.server.addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Server IP Address", HFILL }},
{ &hf_quake3_server_port,
{ "Server Port", "quake3.server.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Server UDP Port", HFILL }},
{ &hf_quake3_game_seq1,
{ "Sequence Number", "quake3.game.seq1",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Sequence number of the current packet", HFILL }},
{ &hf_quake3_game_rel1,
{ "Reliable", "quake3.game.rel1",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Packet is reliable and may be retransmitted", HFILL }},
{ &hf_quake3_game_seq2,
{ "Sequence Number", "quake3.game.seq2",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Sequence number of the last received packet", HFILL }},
{ &hf_quake3_game_rel2,
{ "Reliable", "quake3.game.rel2",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Packet was reliable and may be retransmitted", HFILL }},
{ &hf_quake3_game_qport,
{ "QPort", "quake3.game.qport",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Quake III Arena Client Port", HFILL }}
};
static gint *ett[] = {
&ett_quake3,
&ett_quake3_connectionless,
&ett_quake3_connectionless_text,
&ett_quake3_server,
&ett_quake3_game,
&ett_quake3_game_seq1,
&ett_quake3_game_seq2,
&ett_quake3_game_clc,
&ett_quake3_game_svc
};
module_t *quake3_module;
proto_quake3 = proto_register_protocol("Quake III Arena Network Protocol",
"QUAKE3", "quake3");
proto_register_field_array(proto_quake3, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
quake3_module = prefs_register_protocol(proto_quake3,
proto_reg_handoff_quake3);
prefs_register_uint_preference(quake3_module, "udp.arena_port",
"Quake III Arena Server UDP Base Port",
"Set the UDP base port for the Quake III Arena Server",
10, &gbl_quake3_server_port);
prefs_register_uint_preference(quake3_module, "udp.master_port",
"Quake III Arena Master Server UDP Base Port",
"Set the UDP base port for the Quake III Arena Master Server",
10, &gbl_quake3_master_port);
}
void
proto_reg_handoff_quake3(void)
{
static gboolean initialized=FALSE;
static dissector_handle_t quake3_handle;
static guint server_port;
static guint master_port;
int i;
if (!initialized) {
quake3_handle = create_dissector_handle(dissect_quake3,
proto_quake3);
data_handle = find_dissector("data");
initialized=TRUE;
} else {
for (i=0;i<4;i++)
dissector_delete_uint("udp.port", server_port+i, quake3_handle);
for (i=0;i<4;i++)
dissector_delete_uint("udp.port", master_port+i, quake3_handle);
}
server_port = gbl_quake3_server_port;
master_port = gbl_quake3_master_port;
for (i=0;i<4;i++)
dissector_add_uint("udp.port", gbl_quake3_server_port + i,
quake3_handle);
for (i=0;i<4;i++)
dissector_add_uint("udp.port", gbl_quake3_master_port + i,
quake3_handle);
}
