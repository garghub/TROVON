static mcpe_session_state_t*
mcpe_get_session_state(packet_info *pinfo) {
conversation_t* conversation;
mcpe_session_state_t* state;
conversation = find_or_create_conversation(pinfo);
state = (mcpe_session_state_t*)conversation_get_proto_data(conversation, proto_mcpe);
if (state == NULL) {
state = (mcpe_session_state_t*)wmem_alloc(wmem_file_scope(), sizeof(mcpe_session_state_t));
state->encrypted = FALSE;
state->encryption_starts_after = 0;
conversation_add_proto_data(conversation, proto_mcpe, state);
}
return state;
}
static void
mcpe_dissect_string(proto_tree *tree, int hf, tvbuff_t *tvb, gint *offset, guint encoding) {
proto_item *ti;
proto_tree *string_tree;
guint32 length;
guint32 length_width;
if (encoding & ENC_LITTLE_ENDIAN) {
length = tvb_get_letohl(tvb, *offset);
length_width = 4;
}
else {
length = tvb_get_ntohs(tvb, *offset);
length_width = 2;
}
if (encoding & ENC_UTF_8) {
guint8 *string;
string = tvb_get_string_enc(wmem_packet_scope(), tvb, *offset + length_width, length, ENC_UTF_8);
ti = proto_tree_add_string(tree, hf, tvb, *offset, length + length_width, string);
string_tree = proto_item_add_subtree(ti, ett_mcpe_string);
proto_tree_add_item(string_tree, hf_mcpe_string_length, tvb,
*offset, length_width, encoding);
*offset += length_width;
proto_tree_add_item(string_tree, hf_mcpe_UTF8_string, tvb,
*offset, length, ENC_UTF_8|ENC_NA);
*offset += length;
}
else {
guint8 *bytes;
bytes = (guint8*)tvb_memdup(wmem_packet_scope(), tvb, *offset + length_width, length);
ti = proto_tree_add_bytes_with_length(tree, hf, tvb, *offset, length + length_width, bytes, length);
string_tree = proto_item_add_subtree(ti, ett_mcpe_string);
proto_tree_add_item(string_tree, hf_mcpe_string_length, tvb,
*offset, length_width, encoding);
*offset += length_width;
proto_tree_add_item(string_tree, hf_mcpe_byte_string, tvb,
*offset, length, ENC_NA);
*offset += length;
}
}
static int
mcpe_dissect_login(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
if (tree) {
gint item_size;
gint offset = 1;
guint32 comp_length;
proto_item *ti;
tvbuff_t *login_tvb;
item_size = 4;
proto_tree_add_item(tree, hf_mcpe_protocol_version, tvb,
offset, item_size, ENC_BIG_ENDIAN);
offset += item_size;
item_size = 4;
proto_tree_add_item_ret_uint(tree, hf_mcpe_login_data_length, tvb,
offset, item_size, ENC_BIG_ENDIAN, &comp_length);
offset += item_size;
item_size = comp_length;
ti = proto_tree_add_item(tree, hf_mcpe_login_data, tvb,
offset, item_size, ENC_NA);
login_tvb = tvb_uncompress(tvb, offset, comp_length);
if (login_tvb) {
guint32 decomp_length;
proto_tree *login_tree;
add_new_data_source(pinfo, login_tvb, "MCPE Decompressed login data");
decomp_length = tvb_captured_length(login_tvb);
offset = 0;
item_size = decomp_length;
ti = proto_tree_add_item(tree, hf_mcpe_login, login_tvb,
offset, item_size, ENC_NA);
login_tree = proto_item_add_subtree(ti, ett_mcpe_login);
proto_item_append_text(ti, " (%u octets)", decomp_length);
PROTO_ITEM_SET_GENERATED(ti);
mcpe_dissect_string(login_tree, hf_mcpe_chain_JSON , login_tvb, &offset, ENC_LITTLE_ENDIAN | ENC_UTF_8);
mcpe_dissect_string(login_tree, hf_mcpe_client_data_JWT, login_tvb, &offset, ENC_LITTLE_ENDIAN | ENC_UTF_8);
}
else {
expert_add_info(pinfo, ti, &ei_mcpe_decompression_failed);
}
}
return tvb_reported_length(tvb);
}
static int
mcpe_dissect_server_to_client_handshake(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
if (tree) {
gint offset = 1;
mcpe_session_state_t *state;
mcpe_dissect_string(tree, hf_mcpe_public_key, tvb, &offset, ENC_BIG_ENDIAN | ENC_UTF_8);
mcpe_dissect_string(tree, hf_mcpe_server_token, tvb, &offset, ENC_BIG_ENDIAN);
state = mcpe_get_session_state(pinfo);
state->encrypted = TRUE;
state->encryption_starts_after = pinfo->num;
}
return tvb_reported_length(tvb);
}
static int
mcpe_dissect_batch(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
if (tree) {
guint32 item_size;
guint32 offset = 1;
proto_item *ti;
guint32 comp_length;
tvbuff_t *batch_tvb;
item_size = 4;
proto_tree_add_item_ret_uint(tree, hf_mcpe_batch_length, tvb,
offset, item_size, ENC_BIG_ENDIAN, &comp_length);
offset += item_size;
item_size = comp_length;
ti = proto_tree_add_item(tree, hf_mcpe_batch_body, tvb,
offset, item_size, ENC_NA);
batch_tvb = tvb_uncompress(tvb, offset, comp_length);
if (batch_tvb) {
guint32 decomp_length;
proto_tree *batch_tree;
add_new_data_source(pinfo, batch_tvb, "MCPE Decompressed batch");
decomp_length = tvb_captured_length(batch_tvb);
offset = 0;
item_size = decomp_length;
ti = proto_tree_add_item(tree, hf_mcpe_batch_records, batch_tvb,
offset, item_size, ENC_NA);
batch_tree = proto_item_add_subtree(ti, ett_mcpe_batch);
proto_item_append_text(ti, " (%u octets)", decomp_length);
PROTO_ITEM_SET_GENERATED(ti);
col_append_str(pinfo->cinfo, COL_INFO, " [");
while (TRUE) {
guint32 record_length;
tvbuff_t *record_tvb;
proto_tree *record_tree;
guint32 packet_id;
gint dissected;
item_size = 4;
proto_tree_add_item_ret_uint(batch_tree, hf_mcpe_batch_record_length, batch_tvb,
offset, item_size, ENC_BIG_ENDIAN, &record_length);
offset += item_size;
record_tvb = tvb_new_subset_length(batch_tvb, offset, record_length);
offset += record_length;
ti = proto_tree_add_item(batch_tree, hf_mcpe_batch_record, record_tvb,
0, -1, ENC_NA);
record_tree = proto_item_add_subtree(ti, ett_mcpe_batch_record);
proto_tree_add_item_ret_uint(record_tree, hf_mcpe_packet_id,
record_tvb, 0, 1, ENC_NA, &packet_id);
proto_item_append_text(ti, " (%s)",
val_to_str(packet_id, mcpe_packet_names, "Unknown ID: %#x"));
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str(packet_id, mcpe_packet_names, "Unknown packet ID: %#x"));
dissected =
dissector_try_uint_new(mcpe_packet_dissectors, packet_id,
record_tvb, pinfo, record_tree, TRUE, data);
if (!dissected) {
expert_add_info(pinfo, ti, &ei_mcpe_unknown_packet_id);
}
if (offset < decomp_length) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
else {
break;
}
}
col_append_str(pinfo->cinfo, COL_INFO, "]");
}
else {
expert_add_info(pinfo, ti, &ei_mcpe_decompression_failed);
}
}
return tvb_reported_length(tvb);
}
static void
mcpe_init_message_names(void)
{
unsigned int i;
for (i = 0; i < array_length(mcpe_packet_handlers); i++) {
mcpe_packet_names[i].value = mcpe_packet_handlers[i].vs.value;
mcpe_packet_names[i].strptr = mcpe_packet_handlers[i].vs.strptr;
}
mcpe_packet_names[array_length(mcpe_packet_handlers)].value = 0;
mcpe_packet_names[array_length(mcpe_packet_handlers)].strptr = NULL;
}
static gboolean
test_mcpe_heur(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
if (tvb_strneql(tvb, 0, "\xFE", 1) == 0) {
if (tvb_captured_length(tvb) >= 2) {
gint8 packet_id = tvb_get_guint8(tvb, 1);
*(dissector_handle_t*)data =
dissector_get_uint_handle(mcpe_packet_dissectors, packet_id);
if (*(dissector_handle_t*)data) {
return TRUE;
}
}
}
return FALSE;
}
static gboolean
dissect_mcpe_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dissector_handle_t handle;
if (test_mcpe_heur(tvb, pinfo, tree, &handle)) {
proto_item *ti;
proto_tree *mcpe_tree;
guint32 message_id;
guint32 packet_id;
tvbuff_t *packet_tvb;
raknet_conversation_set_dissector(pinfo, mcpe_handle);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MCPE");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_mcpe, tvb, 0, -1, ENC_NA);
mcpe_tree = proto_item_add_subtree(ti, ett_mcpe);
proto_tree_add_item_ret_uint(mcpe_tree, hf_mcpe_message_id,
tvb, 0, 1, ENC_NA, &message_id);
DISSECTOR_ASSERT(message_id == 0xFE);
proto_tree_add_item_ret_uint(mcpe_tree, hf_mcpe_packet_id,
tvb, 1, 1, ENC_NA, &packet_id);
proto_item_append_text(ti, " (%s)",
val_to_str(packet_id, mcpe_packet_names, "Unknown ID: %#x"));
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(packet_id, mcpe_packet_names, "Unknown packet ID: %#x"));
packet_tvb = tvb_new_subset_remaining(tvb, 1);
return call_dissector_only(handle, packet_tvb, pinfo, mcpe_tree, data) > 0;
}
else {
return FALSE;
}
}
static int
dissect_mcpe(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
mcpe_session_state_t *state;
state = mcpe_get_session_state(pinfo);
if (state->encrypted && pinfo->num > state->encryption_starts_after) {
proto_item *ti;
gint packet_size;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MCPE");
col_add_str(pinfo->cinfo, COL_INFO, "Encrypted packet");
packet_size = tvb_reported_length(tvb);
ti = proto_tree_add_item(tree, proto_mcpe, tvb, 0, packet_size, ENC_NA);
proto_item_append_text(ti, ", Encrypted packet (%d octets)", packet_size);
expert_add_info(pinfo, ti, &ei_mcpe_encrypted_packet);
return tvb_captured_length(tvb);
}
else {
if (dissect_mcpe_heur(tvb, pinfo, tree, data)) {
return tvb_captured_length(tvb);
}
else {
return 0;
}
}
}
void
proto_register_mcpe(void)
{
static hf_register_info hf[] = {
{ &hf_mcpe_message_id,
{ "MCPE Message ID", "mcpe.message.id",
FT_UINT8, BASE_HEX,
VALS(mcpe_message_names), 0x0,
NULL, HFILL }
},
{ &hf_mcpe_packet_id,
{ "MCPE Packet ID", "mcpe.packet.id",
FT_UINT8, BASE_HEX,
VALS(mcpe_packet_names), 0x0,
NULL, HFILL }
},
{ &hf_mcpe_string_length,
{ "MCPE String length", "mcpe.string.length",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_UTF8_string,
{ "MCPE UTF-8 String", "mcpe.string.UTF8",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_byte_string,
{ "MCPE Byte string", "mcpe.string.bytes",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_protocol_version,
{ "MCPE Protocol version", "mcpe.protocol.version",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_login_data_length,
{ "MCPE Compressed login data length", "mcpe.login.data.length",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_login_data,
{ "MCPE Compressed login data", "mcpe.login.data",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_login,
{ "MCPE Decompressed login data", "mcpe.login",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_chain_JSON,
{ "MCPE Chain JSON", "mcpe.chain.JSON",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_client_data_JWT,
{ "MCPE Client data JWT", "mcpe.client.data.JWT",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_public_key,
{ "MCPE Public key", "mcpe.public.key",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_server_token,
{ "MCPE Server token", "mcpe.server.token",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_batch_length,
{ "MCPE Compressed batch length", "mcpe.batch.length",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_batch_body,
{ "MCPE Compressed batch body", "mcpe.batch.body",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_batch_records,
{ "MCPE Decompressed batch records", "mcpe.batch.records",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_batch_record_length,
{ "MCPE Batch record length", "mcpe.batch.record.length",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_mcpe_batch_record,
{ "MCPE Batch record", "mcpe.batch.record",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_mcpe,
&ett_mcpe_batch,
&ett_mcpe_batch_record,
&ett_mcpe_login,
&ett_mcpe_string,
};
module_t *mcpe_module;
static ei_register_info ei[] = {
{ &ei_mcpe_unknown_packet_id,
{ "mcpe.unknown.id", PI_UNDECODED, PI_WARN,
"MCPE unknown packet ID",
EXPFILL }
},
{ &ei_mcpe_decompression_failed,
{ "mcpe.decompression.failed", PI_MALFORMED, PI_ERROR,
"MCPE packet decompression failed",
EXPFILL }
},
{ &ei_mcpe_encrypted_packet,
{ "mcpe.encrypted", PI_DECRYPTION, PI_NOTE,
"MCPE encrypted packet",
EXPFILL }
},
};
expert_module_t *expert_mcpe;
mcpe_init_message_names();
proto_mcpe = proto_register_protocol ("Minecraft Pocket Edition", "MCPE", "mcpe");
expert_mcpe = expert_register_protocol(proto_mcpe);
expert_register_field_array(expert_mcpe, ei, array_length(ei));
proto_register_field_array(proto_mcpe, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
mcpe_handle =
register_dissector("mcpe", dissect_mcpe, proto_mcpe);
mcpe_packet_dissectors =
register_dissector_table("mcpe.packet.id", "MCPE packets",
proto_mcpe, FT_UINT8, BASE_HEX);
mcpe_module =
prefs_register_protocol(proto_mcpe, proto_reg_handoff_mcpe);
prefs_register_uint_preference(mcpe_module, "udp.port",
"MCPE Server UDP Port",
"Set the UDP port for the MCPE Server",
10, &mcpe_udp_port_requested);
}
void
proto_reg_handoff_mcpe(void)
{
static guint last_server_port;
static gboolean init_done = FALSE;
if (init_done) {
raknet_delete_udp_dissector(last_server_port, mcpe_handle);
}
else {
unsigned int i;
for (i = 0; i < array_length(mcpe_packet_handlers); i++) {
dissector_add_uint(
"mcpe.packet.id",
mcpe_packet_handlers[i].vs.value,
create_dissector_handle(
mcpe_packet_handlers[i].dissector_fp, proto_mcpe));
}
heur_dissector_add("raknet", dissect_mcpe_heur,
"MCPE over RakNet", "mcpe_raknet", proto_mcpe, HEURISTIC_ENABLE);
}
last_server_port = mcpe_udp_port_requested;
init_done = TRUE;
raknet_add_udp_dissector(mcpe_udp_port_requested, mcpe_handle);
}
