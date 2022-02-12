static gint dissect_netsync_cmd_error( tvbuff_t *tvb, gint offset, proto_tree *tree, guint size _U_)
{
guint64 len = 0;
offset += dissect_uleb128( tvb, offset, &len );
proto_tree_add_item(tree, hf_netsync_cmd_error_msg, tvb,
offset, (gint)len, ENC_ASCII|ENC_NA );
offset += (gint)len;
return offset;
}
static gint dissect_netsync_cmd_bye(tvbuff_t *tvb _U_, gint offset, proto_tree *tree _U_, guint size _U_)
{
return offset;
}
static gint dissect_netsync_cmd_hello(tvbuff_t *tvb, gint offset, proto_tree *tree, guint size _U_)
{
guint64 len = 0;
offset += dissect_uleb128( tvb, offset, &len );
proto_tree_add_item(tree, hf_netsync_cmd_hello_keyname, tvb,
offset, (gint)len, ENC_ASCII|ENC_NA );
offset += (gint)len;
offset += dissect_uleb128( tvb, offset, &len );
proto_tree_add_item(tree, hf_netsync_cmd_hello_key, tvb,
offset, (gint)len, ENC_NA );
offset += (gint)len;
proto_tree_add_item(tree, hf_netsync_cmd_nonce, tvb,
offset, NETSNYC_MERKLE_HASH_LENGTH, ENC_NA );
offset += NETSNYC_MERKLE_HASH_LENGTH;
return offset;
}
static gint dissect_netsync_cmd_anonymous(tvbuff_t *tvb, gint offset, proto_tree *tree, guint size _U_)
{
guint64 len = 0;
proto_tree_add_item(tree, hf_netsync_cmd_anonymous_role, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
offset += dissect_uleb128( tvb, offset, &len );
proto_tree_add_item(tree, hf_netsync_cmd_anonymous_collection, tvb,
offset, (gint)len, ENC_ASCII|ENC_NA );
offset += (gint)len;
proto_tree_add_item(tree, hf_netsync_cmd_nonce, tvb,
offset, NETSNYC_MERKLE_HASH_LENGTH, ENC_NA );
offset += NETSNYC_MERKLE_HASH_LENGTH;
return offset;
}
static gint dissect_netsync_cmd_auth(tvbuff_t *tvb, gint offset, proto_tree *tree, guint size _U_)
{
guint64 len = 0;
proto_tree_add_item(tree, hf_netsync_cmd_auth_role, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
offset += dissect_uleb128( tvb, offset, &len );
proto_tree_add_item(tree, hf_netsync_cmd_auth_collection, tvb,
offset, (gint)len, ENC_ASCII|ENC_NA );
offset += (gint)len;
proto_tree_add_item(tree, hf_netsync_cmd_auth_id, tvb,
offset, NETSNYC_MERKLE_HASH_LENGTH, ENC_NA );
offset += NETSNYC_MERKLE_HASH_LENGTH;
offset += (gint)len;
proto_tree_add_item(tree, hf_netsync_cmd_auth_nonce1, tvb,
offset, NETSNYC_MERKLE_HASH_LENGTH, ENC_NA );
offset += NETSNYC_MERKLE_HASH_LENGTH;
offset += (gint)len;
proto_tree_add_item(tree, hf_netsync_cmd_auth_nonce2, tvb,
offset, NETSNYC_MERKLE_HASH_LENGTH, ENC_NA );
offset += NETSNYC_MERKLE_HASH_LENGTH;
offset += dissect_uleb128( tvb, offset, &len );
proto_tree_add_item(tree, hf_netsync_cmd_auth_sig, tvb,
offset, (gint)len, ENC_NA );
offset += (gint)len;
return offset;
}
static gint dissect_netsync_cmd_confirm(tvbuff_t *tvb, gint offset, proto_tree *tree, guint size _U_)
{
guint64 len = 0;
offset += dissect_uleb128( tvb, offset, &len );
proto_tree_add_item(tree, hf_netsync_cmd_confirm_sig, tvb,
offset, (gint)len, ENC_NA );
offset += (gint)len;
return offset;
}
static gint dissect_netsync_cmd_refine(tvbuff_t *tvb, gint offset, proto_tree *tree, guint size)
{
proto_tree_add_item(tree, hf_netsync_cmd_refine_tree_node, tvb,
offset, size, ENC_NA );
offset += size;
return offset;
}
static gint dissect_netsync_cmd_done(tvbuff_t *tvb, gint offset, proto_tree *tree, guint size _U_)
{
guint64 len = 0;
guint bytes = 0;
bytes = dissect_uleb128( tvb, offset, &len );
proto_tree_add_uint(tree, hf_netsync_cmd_done_level, tvb,
offset, bytes, (guint32)len );
offset += bytes;
proto_tree_add_item(tree, hf_netsync_cmd_done_type, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
return offset;
}
static gint dissect_netsync_cmd_send_data(tvbuff_t *tvb, gint offset, proto_tree *tree, guint size _U_)
{
proto_tree_add_item(tree, hf_netsync_cmd_send_data_type, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item(tree, hf_netsync_cmd_send_data_id, tvb,
offset, NETSNYC_MERKLE_HASH_LENGTH, ENC_NA );
offset += NETSNYC_MERKLE_HASH_LENGTH;
return offset;
}
static gint dissect_netsync_cmd_send_delta(tvbuff_t *tvb, gint offset, proto_tree *tree, guint size _U_)
{
proto_tree_add_item(tree, hf_netsync_cmd_send_delta_type, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item(tree, hf_netsync_cmd_send_delta_base_id, tvb,
offset, NETSNYC_MERKLE_HASH_LENGTH, ENC_NA );
offset += NETSNYC_MERKLE_HASH_LENGTH;
proto_tree_add_item(tree, hf_netsync_cmd_send_delta_ident_id, tvb,
offset, NETSNYC_MERKLE_HASH_LENGTH, ENC_NA );
offset += NETSNYC_MERKLE_HASH_LENGTH;
return offset;
}
static gint dissect_netsync_cmd_data(tvbuff_t *tvb, gint offset, proto_tree *tree, guint size _U_)
{
guint64 len = 0;
proto_tree_add_item(tree, hf_netsync_cmd_data_type, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item(tree, hf_netsync_cmd_data_id, tvb,
offset, NETSNYC_MERKLE_HASH_LENGTH, ENC_NA );
offset += NETSNYC_MERKLE_HASH_LENGTH;
proto_tree_add_item(tree, hf_netsync_cmd_data_compressed, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
offset += dissect_uleb128( tvb, offset, &len );
proto_tree_add_item(tree, hf_netsync_cmd_data_payload, tvb,
offset, (gint)len, ENC_NA );
offset += (gint)len;
return offset;
}
static gint dissect_netsync_cmd_delta(tvbuff_t *tvb, gint offset, proto_tree *tree, guint size _U_)
{
guint64 len = 0;
proto_tree_add_item(tree, hf_netsync_cmd_delta_type, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item(tree, hf_netsync_cmd_delta_base_id, tvb,
offset, NETSNYC_MERKLE_HASH_LENGTH, ENC_NA );
offset += NETSNYC_MERKLE_HASH_LENGTH;
proto_tree_add_item(tree, hf_netsync_cmd_delta_ident_id, tvb,
offset, NETSNYC_MERKLE_HASH_LENGTH, ENC_NA );
offset += NETSNYC_MERKLE_HASH_LENGTH;
proto_tree_add_item(tree, hf_netsync_cmd_delta_compressed, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
offset += dissect_uleb128( tvb, offset, &len );
proto_tree_add_item(tree, hf_netsync_cmd_delta_payload, tvb,
offset, (gint)len, ENC_NA );
offset += (gint)len;
return offset;
}
static gint dissect_netsync_cmd_nonexistent(tvbuff_t *tvb, gint offset, proto_tree *tree, guint size _U_)
{
proto_tree_add_item(tree, hf_netsync_cmd_nonexistent_type, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item(tree, hf_netsync_cmd_nonexistent_id, tvb,
offset, NETSNYC_MERKLE_HASH_LENGTH, ENC_NA );
offset += NETSNYC_MERKLE_HASH_LENGTH;
return offset;
}
static guint
get_netsync_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint64 size = 0;
guint size_bytes;
offset += 2;
size_bytes = dissect_uleb128( tvb, offset, &size );
return 1 + 1 + size_bytes + (guint)size + 4;
}
static int
dissect_netsync_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint offset = 0;
guint8 tmp;
guint8 cmd, version;
guint32 size, size_bytes, shift;
proto_tree *ti,*netsync_tree=NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Netsync");
if (tree == NULL)
return tvb_captured_length(tvb);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
ti = proto_tree_add_item(tree, proto_netsync, tvb, offset, -1, ENC_NA);
netsync_tree = proto_item_add_subtree(ti, ett_netsync);
version = tvb_get_guint8(tvb, offset);
proto_tree_add_item(netsync_tree, hf_netsync_version, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
cmd = tvb_get_guint8(tvb, offset);
proto_tree_add_item(netsync_tree, hf_netsync_command, tvb,
offset, 1, ENC_BIG_ENDIAN );
offset += 1;
size = 0;
size_bytes = 0;
shift = 0;
do {
tmp = tvb_get_guint8(tvb, offset + size_bytes);
size_bytes += 1;
size |= (tmp & 0x7F) << shift;
shift += 7;
} while (tmp & 0x80);
proto_tree_add_uint(netsync_tree, hf_netsync_size, tvb,
offset, size_bytes, size );
offset += size_bytes;
switch (cmd) {
case NETSYNC_CMD_DONE:
dissect_netsync_cmd_done( tvb, offset, netsync_tree, size );
break;
case NETSYNC_CMD_ERROR:
dissect_netsync_cmd_error( tvb, offset, netsync_tree, size );
break;
case NETSYNC_CMD_BYE:
dissect_netsync_cmd_bye( tvb, offset, netsync_tree, size );
break;
case NETSYNC_CMD_HELLO:
dissect_netsync_cmd_hello( tvb, offset, netsync_tree, size );
break;
case NETSYNC_CMD_ANONYMOUS:
dissect_netsync_cmd_anonymous( tvb, offset, netsync_tree, size );
break;
case NETSYNC_CMD_AUTH:
dissect_netsync_cmd_auth( tvb, offset, netsync_tree, size );
break;
case NETSYNC_CMD_CONFIRM:
dissect_netsync_cmd_confirm( tvb, offset, netsync_tree, size );
break;
case NETSYNC_CMD_REFINE:
dissect_netsync_cmd_refine( tvb, offset, netsync_tree, size );
break;
case NETSYNC_CMD_SEND_DATA:
dissect_netsync_cmd_send_data( tvb, offset, netsync_tree, size );
break;
case NETSYNC_CMD_SEND_DELTA:
dissect_netsync_cmd_send_delta( tvb, offset, netsync_tree, size );
break;
case NETSYNC_CMD_DATA:
dissect_netsync_cmd_data( tvb, offset, netsync_tree, size );
break;
case NETSYNC_CMD_DELTA:
dissect_netsync_cmd_delta( tvb, offset, netsync_tree, size );
break;
case NETSYNC_CMD_NONEXISTENT:
dissect_netsync_cmd_nonexistent( tvb, offset, netsync_tree, size );
break;
default:
proto_tree_add_item(netsync_tree, hf_netsync_data, tvb,
offset, size, ENC_NA );
break;
}
offset += size;
proto_tree_add_item(netsync_tree, hf_netsync_checksum, tvb,
offset, 4, ENC_BIG_ENDIAN );
offset += 4;
proto_item_append_text(netsync_tree, " V%d, Cmd: %s (%d), Size: %d",
version, val_to_str(cmd, netsync_cmd_vals, "(0x%x)"), cmd, size );
proto_item_set_len(netsync_tree, 1+1+size_bytes+size+4);
}
return tvb_captured_length(tvb);
}
static int
dissect_netsync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, netsync_desegment, 7, get_netsync_pdu_len,
dissect_netsync_pdu, data);
return tvb_captured_length(tvb);
}
void
proto_register_netsync(void)
{
static hf_register_info hf[] = {
{ &hf_netsync_version,
{ "Version", "netsync.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_command,
{ "Command", "netsync.command",
FT_UINT8, BASE_HEX, VALS(netsync_cmd_vals), 0x0,
NULL, HFILL } },
{ &hf_netsync_size,
{ "Size", "netsync.size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_data,
{ "Data", "netsync.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_checksum,
{ "Checksum", "netsync.checksum",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_hello_keyname,
{ "Key Name", "netsync.cmd.hello.keyname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_hello_key,
{ "Key", "netsync.cmd.hello.key",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_nonce,
{ "Nonce", "netsync.cmd.nonce",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_anonymous_role,
{ "Role", "netsync.cmd.anonymous.role",
FT_UINT8, BASE_DEC, VALS(netsync_role_vals), 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_anonymous_collection,
{ "Collection", "netsync.cmd.anonymous.collection",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_confirm_sig,
{ "Signature", "netsync.cmd.confirm.signature",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_send_data_type,
{ "Type", "netsync.cmd.send_data.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_send_data_id,
{ "ID", "netsync.cmd.send_data.id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_error_msg,
{ "Message", "netsync.cmd.error.msg",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_done_level,
{ "Level", "netsync.cmd.done.level",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_auth_role,
{ "Role", "netsync.cmd.auth.role",
FT_UINT8, BASE_DEC, VALS(netsync_role_vals), 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_auth_collection,
{ "Collection", "netsync.cmd.auth.collection",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_auth_id,
{ "ID", "netsync.cmd.auth.id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_auth_nonce1,
{ "Nonce 1", "netsync.cmd.auth.nonce1",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_auth_nonce2,
{ "Nonce 2", "netsync.cmd.auth.nonce2",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_auth_sig,
{ "Signature", "netsync.cmd.auth.sig",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_data_type,
{ "Type", "netsync.cmd.data.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_data_id,
{ "ID", "netsync.cmd.data.id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_data_compressed,
{ "Compressed", "netsync.cmd.data.compressed",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_data_payload,
{ "Payload", "netsync.cmd.data.payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_delta_type,
{ "Type", "netsync.cmd.delta.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_delta_base_id,
{ "Base ID", "netsync.cmd.delta.base_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_delta_ident_id,
{ "Ident ID", "netsync.cmd.delta.ident_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_delta_compressed,
{ "Compressed", "netsync.cmd.delta.compressed",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_delta_payload,
{ "Payload", "netsync.cmd.delta.payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_refine_tree_node,
{ "Tree Node", "netsync.cmd.refine.tree_node",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_send_delta_type,
{ "Type", "netsync.cmd.send_delta.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_send_delta_base_id,
{ "Base ID", "netsync.cmd.send_delta.base_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_send_delta_ident_id,
{ "Ident ID", "netsync.cmd.send_delta.ident_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_nonexistent_id,
{ "ID", "netsync.cmd.nonexistent.id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_nonexistent_type,
{ "Type", "netsync.cmd.nonexistent.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_netsync_cmd_done_type,
{ "Type", "netsync.cmd.done.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } }
};
static gint *ett[] = {
&ett_netsync,
};
module_t *netsync_module;
proto_netsync = proto_register_protocol("Monotone Netsync", "Netsync", "netsync");
proto_register_field_array(proto_netsync, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
netsync_module = prefs_register_protocol(proto_netsync,
proto_reg_handoff_netsync);
prefs_register_uint_preference(netsync_module, "tcp_port",
"Monotone Netsync TCP Port",
"The TCP port on which Monotone Netsync packets will be sent",
10, &global_tcp_port_netsync);
prefs_register_bool_preference(netsync_module, "desegment_netsync_messages",
"Reassemble Netsync messages spanning multiple TCP segments",
"Whether the Netsync dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&netsync_desegment);
}
void
proto_reg_handoff_netsync(void)
{
static dissector_handle_t netsync_handle;
static guint tcp_port_netsync;
static gboolean initialized = FALSE;
if (!initialized) {
netsync_handle = create_dissector_handle(dissect_netsync, proto_netsync);
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", tcp_port_netsync, netsync_handle);
}
tcp_port_netsync = global_tcp_port_netsync;
dissector_add_uint("tcp.port", global_tcp_port_netsync, netsync_handle);
}
