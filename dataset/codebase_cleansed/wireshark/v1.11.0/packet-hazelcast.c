static void dissect_hazelcast(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
tcp_dissect_pdus(tvb, pinfo, tree, hazelcast_desegment, 13, get_hazelcast_message_len, dissect_hazelcast_message);
}
static guint get_hazelcast_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset) {
guint messageLength;
guint headerKeyLength;
guint headerValueLength;
messageLength = tvb_get_ntohl(tvb, offset);
headerKeyLength = tvb_get_ntohl(tvb, offset+4);
headerValueLength = tvb_get_ntohl(tvb, offset+8);
return messageLength + headerKeyLength + headerValueLength + 13;
}
static void dissect_hazelcast_message(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree) {
guint8 version;
guint8 flags;
guint8 operation;
guint8 lockCountFlag;
guint8 timeoutFlag;
guint8 ttlFlag;
guint8 txnFlag;
guint8 longValueFlag;
guint8 versionFlag;
guint8 lockAddrNullFlag;
guint32 nameLength;
guint32 keyLength;
guint32 valueLength;
gint offset = 0;
proto_tree *hcast_tree = NULL;
proto_tree *flag_tree = NULL;
proto_item *tf = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HAZELCAST");
col_set_str(pinfo->cinfo, COL_INFO, "Hazelcast distributed object goodness");
if (tree) {
proto_item *ti = NULL;
ti = proto_tree_add_item(tree, proto_hazelcast, tvb, 0, -1, ENC_NA);
hcast_tree = proto_item_add_subtree(ti, ett_hazelcast);
}
if (tvb_length_remaining(tvb, 0) < 13) {
col_set_str(pinfo->cinfo, COL_INFO, "Hazelcast too short");
return;
}
version = tvb_get_guint8(tvb, 12);
if ( version != 6 ) {
col_set_str(pinfo->cinfo, COL_INFO, "Hazelcast unsupported version");
return;
}
proto_tree_add_item(hcast_tree, hf_hazelcast_headerLength, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hcast_tree, hf_hazelcast_headerKeyLength, tvb, offset, 4, ENC_BIG_ENDIAN);
keyLength = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(hcast_tree, hf_hazelcast_headerValueLength, tvb, offset, 4, ENC_BIG_ENDIAN);
valueLength = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(hcast_tree, hf_hazelcast_headerVersion, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hcast_tree, hf_hazelcast_operation, tvb, offset, 1, ENC_BIG_ENDIAN);
operation = tvb_get_guint8(tvb, offset);
col_clear(pinfo->cinfo,COL_INFO);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str(operation, operationTypes, "Unknown (0x%02x)"));
offset += 1;
proto_tree_add_item(hcast_tree, hf_hazelcast_blockID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hcast_tree, hf_hazelcast_threadID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
flags = tvb_get_guint8(tvb, offset);
tf = proto_tree_add_item(hcast_tree, hf_hazelcast_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flag_tree = proto_item_add_subtree(tf, ett_hazelcast_flags);
proto_tree_add_item(flag_tree, hf_hazelcast_flags_lockCount, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_hazelcast_flags_timeout, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_hazelcast_flags_ttl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_hazelcast_flags_txn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_hazelcast_flags_longValue, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_hazelcast_flags_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_hazelcast_flags_client, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_hazelcast_flags_lockAddrNull, tvb, offset, 1, ENC_BIG_ENDIAN);
lockCountFlag = flags & HAZELCAST_LOCKCOUNT_FLAG;
timeoutFlag = flags & HAZELCAST_TIMEOUT_FLAG;
ttlFlag = flags & HAZELCAST_TTL_FLAG;
txnFlag = flags & HAZELCAST_TXN_FLAG;
longValueFlag = flags & HAZELCAST_LONGVALUE_FLAG;
versionFlag = flags & HAZELCAST_VERSION_FLAG;
lockAddrNullFlag = flags & HAZELCAST_LOCKADDRNULL_FLAG;
offset += 1;
if ( lockCountFlag ) {
proto_tree_add_item(hcast_tree, hf_hazelcast_lockCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if ( timeoutFlag ) {
proto_tree_add_item(hcast_tree, hf_hazelcast_timeout, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
if ( ttlFlag ) {
proto_tree_add_item(hcast_tree, hf_hazelcast_ttl, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
if ( txnFlag ) {
proto_tree_add_item(hcast_tree, hf_hazelcast_txnID, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
if ( longValueFlag ) {
proto_tree_add_item(hcast_tree, hf_hazelcast_longValue, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
if ( versionFlag ) {
proto_tree_add_item(hcast_tree, hf_hazelcast_version, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
if ( lockAddrNullFlag == 0 ) {
proto_tree_add_item(hcast_tree, hf_hazelcast_lockAddrIP, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hcast_tree, hf_hazelcast_lockAddrPort, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(hcast_tree, hf_hazelcast_callID, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(hcast_tree, hf_hazelcast_responseType, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hcast_tree, hf_hazelcast_nameLength, tvb, offset, 4, ENC_BIG_ENDIAN);
nameLength = tvb_get_ntohl(tvb, offset);
offset += 4;
if ( nameLength > 0 ) {
proto_tree_add_item(hcast_tree, hf_hazelcast_name, tvb, offset, nameLength, ENC_ASCII);
offset += nameLength;
}
proto_tree_add_item(hcast_tree, hf_hazelcast_indexCount, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hcast_tree, hf_hazelcast_keyPartitionHash, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hcast_tree, hf_hazelcast_valuePartitionHash, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if ( keyLength > 0 ) {
proto_tree_add_item(hcast_tree, hf_hazelcast_keys, tvb, offset, keyLength, ENC_NA);
offset += keyLength;
}
if ( valueLength > 0 ) {
proto_tree_add_item(hcast_tree, hf_hazelcast_values, tvb, offset, valueLength, ENC_NA);
}
}
void proto_register_hazelcast(void) {
static hf_register_info hf[] = {
{ &hf_hazelcast_headerLength,
{ "Hazelcast hdr length", "hazelcast.hdr.length", FT_UINT32, BASE_DEC, NULL, 0x0, "header length", HFILL }
},
{ &hf_hazelcast_headerKeyLength,
{ "Hazelcast hdr key length", "hazelcast.hdr.keylength", FT_UINT32, BASE_DEC, NULL, 0x0, "header key length", HFILL }
},
{ &hf_hazelcast_headerValueLength,
{ "Hazelcast hdr value length", "hazelcast.hdr.valuelength", FT_UINT32, BASE_DEC, NULL, 0x0, "header value length", HFILL }
},
{ &hf_hazelcast_headerVersion,
{ "Hazelcast hdr version", "hazelcast.hdr.version", FT_UINT8, BASE_DEC, NULL, 0x0, "header version", HFILL }
},
{ &hf_hazelcast_operation,
{ "Hazelcast operation", "hazelcast.operation", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &operationTypes_ext, 0x0, "operation", HFILL }
},
{ &hf_hazelcast_blockID,
{ "Hazelcast blockID", "hazelcast.blockID", FT_UINT32, BASE_HEX, NULL, 0x0, "blockID", HFILL }
},
{ &hf_hazelcast_threadID,
{ "Hazelcast threadID", "hazelcast.threadID", FT_UINT32, BASE_DEC, NULL, 0x0, "threadID", HFILL }
},
{ &hf_hazelcast_flags,
{ "hazelcast flags", "hazelcast.flags", FT_UINT32, BASE_HEX, NULL, 0x0, "flags", HFILL }
},
{ &hf_hazelcast_flags_lockCount,
{ "hazelcast lockCount flag", "hazelcast.flags.lockCount", FT_BOOLEAN, 8, NULL, HAZELCAST_LOCKCOUNT_FLAG, NULL, HFILL }
},
{ &hf_hazelcast_flags_timeout,
{ "hazelcast timeout flag", "hazelcast.flags.timeout", FT_BOOLEAN, 8, NULL, HAZELCAST_TIMEOUT_FLAG, NULL, HFILL }
},
{ &hf_hazelcast_flags_ttl,
{ "hazelcast ttl flag", "hazelcast.flags.ttl", FT_BOOLEAN, 8, NULL, HAZELCAST_TTL_FLAG, NULL, HFILL }
},
{ &hf_hazelcast_flags_txn,
{ "hazelcast txn flag", "hazelcast.flags.txn", FT_BOOLEAN, 8, NULL, HAZELCAST_TXN_FLAG, NULL, HFILL }
},
{ &hf_hazelcast_flags_longValue,
{ "hazelcast longValue flag", "hazelcast.flags.longValue", FT_BOOLEAN, 8, NULL, HAZELCAST_LONGVALUE_FLAG, NULL, HFILL }
},
{ &hf_hazelcast_flags_version,
{ "hazelcast version flag", "hazelcast.flags.version", FT_BOOLEAN, 8, NULL, HAZELCAST_VERSION_FLAG, NULL, HFILL }
},
{ &hf_hazelcast_flags_client,
{ "hazelcast client flag", "hazelcast.flags.client", FT_BOOLEAN, 8, NULL, HAZELCAST_CLIENT_FLAG, NULL, HFILL }
},
{ &hf_hazelcast_flags_lockAddrNull,
{ "hazelcast lockAddrNull flag", "hazelcast.flags.lockAddrNull", FT_BOOLEAN, 8, NULL, HAZELCAST_LOCKADDRNULL_FLAG, NULL, HFILL }
},
{ &hf_hazelcast_timeout,
{ "hazelcast timeout", "hazelcast.timeout", FT_UINT64, BASE_DEC, NULL, 0x0, "timeout", HFILL }
},
{ &hf_hazelcast_ttl,
{ "hazelcast ttl", "hazelcast.ttl", FT_UINT64, BASE_DEC, NULL, 0x0, "ttl", HFILL }
},
{ &hf_hazelcast_longValue,
{ "hazelcast longValue", "hazelcast.longValue", FT_UINT64, BASE_DEC, NULL, 0x0, "longValue", HFILL }
},
{ &hf_hazelcast_txnID,
{ "hazelcast txnID", "hazelcast.txnID", FT_UINT64, BASE_DEC, NULL, 0x0, "txnID", HFILL }
},
{ &hf_hazelcast_version,
{ "hazelcast version", "hazelcast.version", FT_UINT64, BASE_DEC, NULL, 0x0, "version", HFILL }
},
{ &hf_hazelcast_lockCount,
{ "hazelcast lockCount", "hazelcast.lockCount", FT_UINT32, BASE_DEC, NULL, 0x0, "lockCount", HFILL }
},
{ &hf_hazelcast_lockAddrIP,
{ "hazelcast lock address IP", "hazelcast.lockaddr.ip", FT_IPv4, BASE_NONE, NULL, 0x0, "lockAddrIP", HFILL }
},
{ &hf_hazelcast_lockAddrPort,
{ "hazelcast lock address Port", "hazelcast.lockaddr.port", FT_UINT32, BASE_DEC, NULL, 0x0, "lockAddrPort", HFILL }
},
{ &hf_hazelcast_callID,
{ "hazelcast callID", "hazelcast.callID", FT_INT64, BASE_DEC, NULL, 0x0, "callID", HFILL }
},
{ &hf_hazelcast_responseType,
{ "hazelcast response type", "hazelcast.responseType", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &responseTypes_ext, 0x0, "responseType", HFILL }
},
{ &hf_hazelcast_nameLength,
{ "hazelcast name length", "hazelcast.nameLength", FT_UINT32, BASE_DEC, NULL, 0x0, "nameLength", HFILL }
},
{ &hf_hazelcast_name,
{ "hazelcast name", "hazelcast.name", FT_STRING, BASE_NONE, NULL, 0x0, "name", HFILL }
},
{ &hf_hazelcast_indexCount,
{ "hazelcast indexCount", "hazelcast.indexCount", FT_UINT8, BASE_DEC, NULL, 0x0, "indexCount", HFILL }
},
{ &hf_hazelcast_keyPartitionHash,
{ "hazelcast keyPartitionHash", "hazelcast.keyPartitionHash", FT_UINT32, BASE_HEX, NULL, 0x0, "keyPartitionHash", HFILL }
},
{ &hf_hazelcast_valuePartitionHash,
{ "hazelcast valuePartitionHash", "hazelcast.valuePartitionHash", FT_UINT32, BASE_HEX, NULL, 0x0, "valuePartitionHash", HFILL }
},
{ &hf_hazelcast_keys,
{ "hazelcast keys", "hazelcast.keys", FT_BYTES, BASE_NONE, NULL, 0x0, "keys", HFILL }
},
{ &hf_hazelcast_values,
{ "hazelcast values", "hazelcast.values", FT_BYTES, BASE_NONE, NULL, 0x0, "values", HFILL }
}
};
static gint *ett[] = {
&ett_hazelcast,
&ett_hazelcast_flags
};
module_t *hazelcast_module;
proto_hazelcast = proto_register_protocol (
"Hazelcast Wire Protocol",
"HAZELCAST",
"hzlcst"
);
proto_register_field_array(proto_hazelcast, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
hazelcast_module = prefs_register_protocol(proto_hazelcast, NULL);
prefs_register_bool_preference(hazelcast_module, "desegment",
"Reassemble hazelcast messages spanning multiple TCP segments",
"Whether the hazel dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&hazelcast_desegment);
prefs_register_uint_preference(hazelcast_module, "tcp.port",
"Hazelcast TCP Port",
" Hazelcast TCP port if other than the default",
10,
&gPORT_PREF);
hazelcast_tap = register_tap("hzlcst");
}
void
proto_reg_handoff_hazelcast(void) {
static gboolean initialized = FALSE;
static dissector_handle_t hazelcast_handle;
static int currentPort;
if (!initialized) {
hazelcast_handle = create_dissector_handle(dissect_hazelcast, proto_hazelcast);
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", currentPort, hazelcast_handle);
}
currentPort = gPORT_PREF;
dissector_add_uint("tcp.port", currentPort, hazelcast_handle);
}
