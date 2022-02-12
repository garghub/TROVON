static void
dissect_negoex_alert_message(tvbuff_t *tvb,
packet_info *pinfo _U_,
proto_tree *tree,
guint32 start_off)
{
guint32 offset;
offset = start_off;
proto_tree_add_item(tree, hf_negoex_authscheme, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_negoex_errorcode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bytes_format(tree, hf_negoex_data, tvb, offset, -1, NULL,
"The rest of the alert message");
}
static void
dissect_negoex_verify_message(tvbuff_t *tvb,
packet_info *pinfo _U_,
proto_tree *tree,
guint32 start_off)
{
guint32 offset;
guint32 checksum_vector_offset;
guint32 checksum_vector_count;
proto_tree *checksum;
proto_tree *checksum_vector;
offset = start_off;
proto_tree_add_item(tree, hf_negoex_authscheme, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
checksum = proto_tree_add_subtree(tree, tvb, offset, 20, ett_negoex_checksum, NULL, "Checksum");
proto_tree_add_item(checksum, hf_negoex_header_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(checksum, hf_negoex_checksum_scheme, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(checksum, hf_negoex_checksum_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
checksum_vector_offset = tvb_get_letohl(tvb, offset);
checksum_vector_count = tvb_get_letohs(tvb, offset + 4);
checksum_vector = proto_tree_add_subtree_format(checksum, tvb, offset, 8,
ett_negoex_checksum_vector, NULL, "Checksum Vector: %u at %u",
checksum_vector_count,
checksum_vector_offset);
proto_tree_add_item(checksum_vector, hf_negoex_checksum_vector_offset, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(checksum_vector, hf_negoex_checksum_vector_count, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(checksum_vector, hf_negoex_checksum_vector_pad, tvb,
offset, 2, ENC_NA);
proto_tree_add_item(checksum_vector, hf_negoex_checksum, tvb,
checksum_vector_offset, checksum_vector_count, ENC_NA);
}
static void
dissect_negoex_exchange_message(tvbuff_t *tvb,
packet_info *pinfo _U_,
proto_tree *tree,
guint32 start_off)
{
guint32 offset;
guint32 exchange_vector_offset;
guint32 exchange_vector_count;
proto_tree *exchange_vector;
offset = start_off;
proto_tree_add_item(tree, hf_negoex_authscheme, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
exchange_vector_offset = tvb_get_letohl(tvb, offset);
exchange_vector_count = tvb_get_letohs(tvb, offset + 4);
exchange_vector = proto_tree_add_subtree_format(tree, tvb, offset, 8,
ett_negoex_exchange, NULL, "Exchange: %u bytes at %u",
exchange_vector_count, exchange_vector_offset);
proto_tree_add_item(exchange_vector, hf_negoex_exchange_vector_offset, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(exchange_vector, hf_negoex_exchange_vector_count, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(exchange_vector, hf_negoex_exchange_vector_pad, tvb,
offset, 2, ENC_NA);
proto_tree_add_item(exchange_vector, hf_negoex_exchange, tvb,
exchange_vector_offset, exchange_vector_count, ENC_NA);
}
static void
dissect_negoex_nego_message(tvbuff_t *tvb,
packet_info *pinfo _U_,
proto_tree *tree,
guint32 start_off)
{
volatile guint32 offset;
guint32 authscheme_vector_offset;
guint16 authscheme_vector_count;
guint32 extension_vector_offset;
guint32 extension_vector_count;
proto_tree *authscheme_vector;
proto_tree *extension_vector;
guint32 i;
offset = start_off;
TRY {
proto_tree_add_item(tree, hf_negoex_random, tvb, offset, 32, ENC_ASCII);
offset += 32;
proto_tree_add_item(tree, hf_negoex_proto_version, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
authscheme_vector_offset = tvb_get_letohl(tvb, offset);
authscheme_vector_count = tvb_get_letohs(tvb, offset + 4);
authscheme_vector = proto_tree_add_subtree_format(tree, tvb, offset, 8,
ett_negoex_authscheme_vector, NULL, "AuthSchemes: %u at %u",
authscheme_vector_count, authscheme_vector_offset);
proto_tree_add_item(authscheme_vector, hf_negoex_authscheme_vector_offset,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(authscheme_vector, hf_negoex_authscheme_vector_count,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(authscheme_vector, hf_negoex_authscheme_vector_pad,
tvb, offset, 2, ENC_NA);
offset += 2;
for (i = 0; i < authscheme_vector_count; i++) {
proto_tree_add_item(authscheme_vector, hf_negoex_authscheme, tvb,
authscheme_vector_offset + i * 16, 16, ENC_LITTLE_ENDIAN);
}
extension_vector_offset = tvb_get_letohl(tvb, offset);
extension_vector_count = tvb_get_letohs(tvb, offset + 4);
extension_vector = proto_tree_add_subtree_format(tree, tvb, offset, 8,
ett_negoex_extension_vector, NULL, "Extensions: %u at %u",
extension_vector_count, extension_vector_count);
proto_tree_add_item(extension_vector, hf_negoex_extension_vector_offset,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(extension_vector, hf_negoex_extension_vector_count,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(extension_vector, hf_negoex_extension_vector_pad,
tvb, offset, 2, ENC_NA);
offset += 2;
for (i = 0; i < extension_vector_count; i++) {
guint32 byte_vector_offset, byte_vector_count;
proto_tree *bv_tree;
byte_vector_offset = tvb_get_letohl(tvb, offset);
byte_vector_count = tvb_get_letohs(tvb, offset + 4);
bv_tree = proto_tree_add_subtree_format(extension_vector, tvb,
extension_vector_offset + i * 8, 8,
ett_negoex_byte_vector, NULL, "Extension: %u bytes at %u",
byte_vector_count, byte_vector_offset);
proto_tree_add_item(bv_tree, hf_negoex_extension, tvb,
byte_vector_offset, byte_vector_count, ENC_NA);
}
} ENDTRY;
}
static int
dissect_negoex(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
volatile guint32 offset;
proto_tree * volatile negoex_tree;
proto_item *tf;
volatile gboolean done;
guint32 payload_len;
guint32 message_len;
guint32 message_type;
guint32 header_len;
offset = 0;
negoex_tree = NULL;
tf = NULL;
done = FALSE;
payload_len = tvb_reported_length(tvb);
if (tree) {
tf = proto_tree_add_item(tree, proto_negoex, tvb, offset, -1, ENC_NA);
negoex_tree = proto_item_add_subtree(tf, ett_negoex);
}
while (offset < payload_len && !done) {
proto_tree *negoex_msg_tree;
proto_tree *negoex_hdr_tree;
proto_item *msg;
tvbuff_t *msg_tvb;
guint32 start_offset;
start_offset = offset;
TRY {
message_type = tvb_get_letohl(tvb, offset + 8);
negoex_msg_tree = proto_tree_add_subtree_format(negoex_tree, tvb, offset, -1,
ett_negoex_msg, &msg, "NEGOEX %s",
val_to_str_const(message_type,
negoex_message_types,
"Unknown NEGOEX message type"));
negoex_hdr_tree = proto_tree_add_subtree(negoex_msg_tree, tvb, offset, 40, ett_negoex_hdr, NULL, "Header");
proto_tree_add_item(negoex_hdr_tree, hf_negoex_sig,
tvb, offset, 8, ENC_ASCII | ENC_NA);
offset += 8;
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ",
val_to_str_const(message_type,
negoex_message_types,
"Unknown NEGOEX message type"));
proto_tree_add_uint(negoex_hdr_tree, hf_negoex_message_type,
tvb, offset, 4, message_type);
if (message_type > MESSAGE_TYPE_MAX_MSG) {
offset = payload_len;
goto bad_message;
} else {
offset += 4;
}
proto_tree_add_item(negoex_hdr_tree, hf_negoex_sequence_num,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
header_len = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(negoex_hdr_tree, hf_negoex_header_len,
tvb, offset, 4, header_len);
offset += 4;
message_len = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(negoex_hdr_tree, hf_negoex_message_len,
tvb, offset, 4, message_len);
offset += 4;
proto_item_set_len(msg, message_len);
proto_tree_add_item(negoex_hdr_tree, hf_negoex_conversation_id,
tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
msg_tvb = tvb_new_subset_length_caplen(tvb,
start_offset,
MIN(message_len, tvb_captured_length(tvb)),
message_len);
switch (message_type) {
case MESSAGE_TYPE_INITIATOR_NEGO:
case MESSAGE_TYPE_ACCEPTOR_NEGO:
dissect_negoex_nego_message(msg_tvb,
pinfo,
negoex_msg_tree,
offset - start_offset);
break;
case MESSAGE_TYPE_INITIATOR_META_DATA:
case MESSAGE_TYPE_ACCEPTOR_META_DATA:
case MESSAGE_TYPE_CHALLENGE:
case MESSAGE_TYPE_AP_REQUEST:
dissect_negoex_exchange_message(msg_tvb,
pinfo,
negoex_msg_tree,
offset - start_offset);
break;
case MESSAGE_TYPE_VERIFY:
dissect_negoex_verify_message(msg_tvb,
pinfo,
negoex_msg_tree,
offset - start_offset);
break;
case MESSAGE_TYPE_ALERT:
dissect_negoex_alert_message(msg_tvb,
pinfo,
negoex_msg_tree,
offset - start_offset);
break;
default:
proto_tree_add_bytes_format(negoex_msg_tree, hf_negoex_data, tvb, offset, message_len - 40, NULL,
"The rest of the message");
}
offset = start_offset + message_len;
bad_message:
;
} CATCH_NONFATAL_ERRORS {
done = TRUE;
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY;
}
return tvb_captured_length(tvb);
}
void
proto_register_negoex(void)
{
static hf_register_info hf[] = {
{ &hf_negoex_sig,
{ "Signature", "negoex.message.sig", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_negoex_message_type,
{ "MessageType", "negoex.message.type", FT_UINT32, BASE_HEX,
VALS(negoex_message_types), 0x00, NULL, HFILL }},
{ &hf_negoex_sequence_num,
{ "SequencNum", "negoex.message.seq_num", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_negoex_header_len,
{ "cbHeaderLength", "negoex.header.len", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_negoex_message_len,
{ "cbMessageLength", "negoex.message.len", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_negoex_conversation_id,
{ "ConversationID", "negoex.message.conv_id", FT_GUID, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_random,
{ "Random", "negoex.message.random", FT_BYTES, BASE_NONE,
NULL, 0x0, "Random data", HFILL }},
{ &hf_negoex_proto_version,
{ "ProtocolVersion", "negoex.proto_version", FT_UINT64, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_authscheme,
{ "AuthScheme", "negoex.auth_scheme", FT_GUID, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_authscheme_vector_offset,
{ "AuthSchemeArrayOffset", "negoex.auth_scheme_array_offset", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_negoex_authscheme_vector_count,
{ "AuthSchemeCount", "negoex.auth_scheme_array_count", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_negoex_authscheme_vector_pad,
{ "AuthSchemePad", "negoex.auth_scheme_array_pad", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_negoex_extension,
{ "Extension", "negoex.extension", FT_BYTES, BASE_NONE,
NULL, 0x0, "Extension data", HFILL }},
{ &hf_negoex_extension_vector_offset,
{ "ExtensionArrayOffset", "negoex.extension_array_offset", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_negoex_extension_vector_count,
{ "ExtensionCount", "negoex.extension_array_count", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_negoex_extension_vector_pad,
{ "ExtensionPad", "negoex.extension_pad", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_negoex_exchange_vector_offset,
{ "ExchangeOffset", "negoex.exchange_vec_offset", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_exchange_vector_count,
{ "ExchangeByteCount", "negoex.exchange_vec_byte_count", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_exchange_vector_pad,
{ "ExchangePad", "negoex.exchange_vec_pad", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_exchange,
{ "Exchange Bytes", "negoex.exchange", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_checksum_scheme,
{ "ChecksumScheme", "negoex.checksum_scheme", FT_UINT32, BASE_DEC,
VALS(checksum_schemes), 0x0, NULL, HFILL}},
{ &hf_negoex_checksum_vector_offset,
{ "ChecksumOffset", "negoex.checksum_vec_offset", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_checksum_vector_count,
{ "ChecksumCount", "negoex.checksum_vec_count", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_checksum_vector_pad,
{ "ChecksumPad", "negoex.checksum_pad", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_checksum_type,
{ "ChecksumType", "negoex.checksum_type", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_checksum,
{ "Checksum", "negoex.checksum", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_errorcode,
{ "ErrorCode", "negoex.errorcode", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_negoex_data,
{ "Data", "negoex.data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_negoex,
&ett_negoex_msg,
&ett_negoex_hdr,
&ett_negoex_authscheme_vector,
&ett_negoex_extension_vector,
&ett_negoex_exchange,
&ett_negoex_checksum,
&ett_negoex_checksum_vector,
&ett_negoex_byte_vector,
};
proto_negoex = proto_register_protocol (
"SPNEGO Extended Negotiation Security Mechanism",
"NEGOEX",
"negoex"
);
proto_register_field_array(proto_negoex, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
negoex_handle = register_dissector("negoex", dissect_negoex, proto_negoex);
}
void
proto_reg_handoff_negoex(void)
{
gssapi_init_oid("1.3.6.1.4.1.311.2.2.30", proto_negoex, ett_negoex,
negoex_handle, NULL,
"NEGOEX - SPNEGO Extended Negotiation Security Mechanism");
}
