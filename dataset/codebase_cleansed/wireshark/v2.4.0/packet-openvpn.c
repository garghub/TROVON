static gboolean
check_for_valid_hmac(guint32 hmac)
{
gint c = 0;
if ((hmac & 0x000000FF) == 0x00000000) {
c++;
}
if ((hmac & 0x0000FF00) == 0x00000000) {
c++;
}
if ((hmac & 0x00FF0000) == 0x00000000) {
c++;
}
if ((hmac & 0xFF000000) == 0x00000000) {
c++;
}
if (c > 1) {
return FALSE;
} else {
return TRUE;
}
}
static int
dissect_openvpn_msg_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *openvpn_tree, proto_tree *parent_tree, gint offset)
{
gboolean tls_auth;
guint openvpn_keyid;
guint openvpn_opcode;
guint32 msg_mpid = -1;
guint32 msg_sessionid = -1;
guint8 openvpn_predict_tlsauth_arraylength;
proto_item *ti2;
proto_tree *packetarray_tree, *type_tree;
guint32 msg_length_remaining;
gboolean msg_lastframe;
fragment_head *frag_msg;
tvbuff_t *new_tvb;
gboolean save_fragmented;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_clear(pinfo->cinfo,COL_INFO);
openvpn_opcode = tvb_get_bits8(tvb, offset*8, 5);
col_append_fstr(pinfo->cinfo, COL_INFO, "MessageType: %s",
val_to_str_const(openvpn_opcode, openvpn_message_types, "Unknown Messagetype"));
openvpn_keyid = tvb_get_bits8(tvb, offset*8 + 5, 3);
proto_item_append_text(parent_tree, ", Opcode: %s, Key ID: %d",
val_to_str(openvpn_opcode, openvpn_message_types, "Unknown (0x%02x)"),
openvpn_keyid);
ti2 = proto_tree_add_item(openvpn_tree, hf_openvpn_pdu_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti2, " [opcode/key_id]");
type_tree = proto_item_add_subtree(ti2, ett_openvpn_type);
proto_tree_add_item(type_tree, hf_openvpn_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(type_tree, hf_openvpn_keyid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (openvpn_opcode == P_DATA_V2) {
proto_tree_add_item(openvpn_tree, hf_openvpn_peerid, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
} else if (openvpn_opcode != P_DATA_V1) {
msg_sessionid = tvb_get_bits32(tvb, offset*8+32, 32, ENC_BIG_ENDIAN);
proto_tree_add_item(openvpn_tree, hf_openvpn_sessionid, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
openvpn_predict_tlsauth_arraylength = tvb_get_guint8(tvb, offset);
if (pref_tls_auth_override == FALSE) {
if ((openvpn_opcode != P_DATA_V1)
&& (openvpn_predict_tlsauth_arraylength > 0)
&& check_for_valid_hmac(tvb_get_ntohl(tvb, offset))) {
tls_auth = TRUE;
} else {
tls_auth = FALSE;
}
} else {
tls_auth = pref_tls_auth;
}
if (tls_auth == TRUE) {
proto_tree_add_item(openvpn_tree, hf_openvpn_hmac, tvb, offset, tls_auth_hmac_size, ENC_NA);
offset += tls_auth_hmac_size;
if (tvb_reported_length_remaining(tvb, offset) >= 8) {
proto_tree_add_item(openvpn_tree, hf_openvpn_pid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (pref_long_format) {
proto_tree_add_item(openvpn_tree, hf_openvpn_net_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
}
if (tvb_reported_length_remaining(tvb, offset) >= 1) {
gint pid_arraylength = tvb_get_guint8(tvb, offset);
gint i;
proto_tree_add_item(openvpn_tree, hf_openvpn_mpid_arraylength, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (pid_arraylength > 0) {
packetarray_tree = proto_tree_add_subtree(openvpn_tree, tvb, offset, 0, ett_openvpn_packetarray, NULL, "Packet-ID Array");
for (i = 0; i < pid_arraylength; i++) {
proto_tree_add_item(packetarray_tree, hf_openvpn_mpid_arrayelement, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if (tvb_reported_length_remaining(tvb, offset) >= 8) {
proto_tree_add_item(openvpn_tree, hf_openvpn_rsessionid, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
}
}
if (openvpn_opcode != P_ACK_V1) {
if (tvb_reported_length_remaining(tvb, offset) >= 4) {
msg_mpid = tvb_get_bits32(tvb, offset*8, 32, ENC_BIG_ENDIAN);
proto_tree_add_item(openvpn_tree, hf_openvpn_mpid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
}
msg_length_remaining = tvb_reported_length_remaining(tvb, offset);
if (msg_length_remaining == 0) {
return tvb_captured_length(tvb);
}
if (openvpn_opcode != P_CONTROL_V1) {
proto_tree *data_tree;
data_tree = proto_tree_add_subtree_format(openvpn_tree, tvb, offset, -1,
ett_openvpn_data, NULL, "Data (%d bytes)",
tvb_captured_length_remaining(tvb, offset));
proto_tree_add_item(data_tree, hf_openvpn_data, tvb, offset, -1, ENC_NA);
return tvb_captured_length(tvb);
}
if (msg_length_remaining == 100) {
msg_lastframe = FALSE;
} else {
msg_lastframe = TRUE;
}
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_next(
&msg_reassembly_table,
tvb,
offset,
pinfo,
msg_sessionid,
NULL,
msg_length_remaining,
!(msg_lastframe));
if ((frag_msg == NULL) || (frag_msg->next != NULL)) {
proto_tree *data_tree;
data_tree = proto_tree_add_subtree_format(openvpn_tree, tvb, offset, -1,
ett_openvpn_data, NULL, "Message fragment (%d bytes)",
tvb_captured_length_remaining(tvb, offset));
proto_tree_add_item(data_tree, hf_openvpn_fragment_bytes, tvb, offset, -1, ENC_NA);
}
new_tvb = NULL;
if (frag_msg) {
if (msg_lastframe) {
new_tvb = process_reassembled_data(tvb, offset, pinfo, "Reassembled Message",
frag_msg, &openvpn_frag_items, NULL, openvpn_tree);
if (frag_msg->next != NULL) {
col_append_str(pinfo->cinfo, COL_INFO, " (Message Reassembled ");
}
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " (Message fragment %d) ", msg_mpid);
if (pinfo->num != frag_msg->reassembled_in) {
proto_tree_add_uint(openvpn_tree, hf_openvpn_reassembled_in,
tvb, 0, 0, frag_msg->reassembled_in);
}
}
}
pinfo->fragmented = save_fragmented;
if (new_tvb) {
call_dissector(ssl_handle, new_tvb, pinfo, parent_tree);
}
return tvb_captured_length(tvb);
}
static guint
get_msg_length(packet_info *pinfo _U_, tvbuff_t *tvb, gint offset, void *data _U_)
{
return (guint)tvb_get_ntohs(tvb, offset) + 2;
}
static int
dissect_openvpn_msg_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *openvpn_tree;
ti = proto_tree_add_item(tree, proto_openvpn, tvb, 0, -1, ENC_NA);
openvpn_tree = proto_item_add_subtree(ti, ett_openvpn);
proto_tree_add_item(openvpn_tree, hf_openvpn_plen, tvb, 0, 2, ENC_BIG_ENDIAN);
return dissect_openvpn_msg_common(tvb, pinfo, openvpn_tree, tree, 2);
}
static int
dissect_openvpn_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus( tvb, pinfo, tree,
TRUE,
2,
get_msg_length,
dissect_openvpn_msg_tcp, data);
return tvb_captured_length(tvb);
}
static int
dissect_openvpn_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *openvpn_tree;
ti = proto_tree_add_item(tree, proto_openvpn, tvb, 0, -1, ENC_NA);
openvpn_tree = proto_item_add_subtree(ti, ett_openvpn);
return dissect_openvpn_msg_common(tvb, pinfo, openvpn_tree, tree, 0);
}
void
proto_register_openvpn(void)
{
static hf_register_info hf[] = {
{ &hf_openvpn_plen,
{ "Packet Length", "openvpn.plen",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_pdu_type,
{ "Type", "openvpn.type",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_opcode,
{ "Opcode", "openvpn.opcode",
FT_UINT8, BASE_HEX,
VALS(openvpn_message_types), P_OPCODE_MASK,
NULL, HFILL }
},
{ &hf_openvpn_keyid,
{ "Key ID", "openvpn.keyid",
FT_UINT8, BASE_DEC,
NULL, P_KEY_ID_MASK,
NULL, HFILL }
},
{ &hf_openvpn_peerid,
{ "Peer ID", "openvpn.peerid",
FT_UINT24, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_sessionid,
{ "Session ID", "openvpn.sessionid",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_hmac,
{ "HMAC", "openvpn.hmac",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_pid,
{ "Packet-ID", "openvpn.pid",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_net_time,
{ "Net Time", "openvpn.net_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_rsessionid,
{ "Remote Session ID", "openvpn.rsessionid",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_mpid,
{ "Message Packet-ID", "openvpn.mpid",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_mpid_arraylength,
{ "Message Packet-ID Array Length", "openvpn.mpidarraylength",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_mpid_arrayelement,
{ "Message Packet-ID Array Element", "openvpn.mpidarrayelement",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_data,
{ "Data", "openvpn.data",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_fragment_bytes,
{ "Fragment bytes", "openvpn.fragment_bytes",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_openvpn_fragments,
{ "Message fragments", "openvpn.fragments",
FT_NONE, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_openvpn_fragment,
{ "Message fragment", "openvpn.fragment",
FT_FRAMENUM, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_openvpn_fragment_overlap,
{ "Message fragment overlap", "openvpn.fragment.overlap",
FT_BOOLEAN, 0,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_openvpn_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data", "openvpn.fragment.overlap.conflicts",
FT_BOOLEAN, 0,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_openvpn_fragment_multiple_tails,
{ "Message has multiple tail fragments", "openvpn.fragment.multiple_tails",
FT_BOOLEAN, 0,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_openvpn_fragment_too_long_fragment,
{ "Message fragment too long", "openvpn.fragment.too_long_fragment",
FT_BOOLEAN, 0,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_openvpn_fragment_error,
{ "Message defragmentation error", "openvpn.fragment.error",
FT_FRAMENUM, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_openvpn_fragment_count,
{ "Message fragment count", "openvpn.fragment.count",
FT_UINT32, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_openvpn_reassembled_in,
{ "Reassembled message in frame", "openvpn.reassembled.in",
FT_FRAMENUM, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_openvpn_reassembled_length,
{"Reassembled message length", "openvpn.reassembled.length",
FT_UINT32, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_openvpn,
&ett_openvpn_type,
&ett_openvpn_data,
&ett_openvpn_packetarray,
&ett_openvpn_fragment,
&ett_openvpn_fragments
};
module_t *openvpn_module;
proto_openvpn = proto_register_protocol (
PNAME,
PSNAME,
PFNAME
);
proto_register_field_array(proto_openvpn, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
openvpn_udp_handle = register_dissector("openvpn.udp", dissect_openvpn_udp, proto_openvpn);
openvpn_tcp_handle = register_dissector("openvpn.tcp", dissect_openvpn_tcp, proto_openvpn);
reassembly_table_register(&msg_reassembly_table,
&addresses_reassembly_table_functions);
openvpn_module = prefs_register_protocol(proto_openvpn, NULL);
prefs_register_bool_preference(openvpn_module,
"tls_auth_detection_override",
"override tls-auth detection",
"If tls-auth detection fails, you can choose to override detection and set tls-auth yourself",
&pref_tls_auth_override);
prefs_register_bool_preference(openvpn_module,
"tls_auth",
"--tls-auth used?",
"If the parameter --tls-auth is used, the following preferences must also be defined.",
&pref_tls_auth);
prefs_register_uint_preference(openvpn_module,
"tls_auth_hmac_size",
"size of the HMAC header in bytes",
"If the parameter --tls-auth is used, a HMAC header is being inserted.\n"
"The default HMAC algorithm is SHA-1 which generates a 160 bit HMAC,"
" therefore 20 bytes should be ok.\n"
"The value must be between 20 (160 bits) and 64 (512 bits).",
10, &tls_auth_hmac_size);
prefs_register_bool_preference(openvpn_module,
"long_format",
"packet-id for replay protection includes optional time_t timestamp?",
"If the parameter --tls-auth is used, an additional packet-id for replay protection"
" is inserted after the HMAC signature."
" This field can either be 4 bytes or 8 bytes including an optional time_t timestamp long.\n"
" This option is only evaluated if tls_auth_hmac_size > 0.\n"
" The default value is TRUE.",
&pref_long_format);
}
void
proto_reg_handoff_openvpn(void)
{
ssl_handle = find_dissector_add_dependency("ssl", proto_openvpn);
dissector_add_uint_with_preference("tcp.port", OPENVPN_PORT, openvpn_tcp_handle);
dissector_add_uint_with_preference("udp.port", OPENVPN_PORT, openvpn_udp_handle);
}
