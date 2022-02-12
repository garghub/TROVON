static tvbuff_t *
tvb_unmasked(tvbuff_t *tvb, packet_info *pinfo, const guint offset, guint payload_length, const guint8 *masking_key)
{
gchar *data_unmask;
guint i;
const guint8 *data_mask;
guint unmasked_length = payload_length > MAX_UNMASKED_LEN ? MAX_UNMASKED_LEN : payload_length;
data_unmask = (gchar *)wmem_alloc(pinfo->pool, unmasked_length);
data_mask = tvb_get_ptr(tvb, offset, unmasked_length);
for(i=0; i < unmasked_length; i++) {
data_unmask[i] = data_mask[i] ^ masking_key[i%4];
}
return tvb_new_real_data(data_unmask, unmasked_length, payload_length);
}
static void
dissect_websocket_control_frame(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 opcode)
{
proto_item *ti;
proto_tree *subtree;
const guint offset = 0, length = tvb_reported_length(tvb);
switch (opcode) {
case WS_CLOSE:
ti = proto_tree_add_item(tree, hf_ws_payload_close, tvb, offset, length, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_ws_control_close);
if (length >= 2) {
proto_tree_add_item(subtree, hf_ws_payload_close_status_code, tvb, offset, 2, ENC_BIG_ENDIAN);
if (length > 2)
proto_tree_add_item(subtree, hf_ws_payload_close_reason, tvb, offset+2, length-2, ENC_UTF_8|ENC_NA);
}
break;
case WS_PING:
proto_tree_add_item(tree, hf_ws_payload_ping, tvb, offset, length, ENC_NA);
break;
case WS_PONG:
proto_tree_add_item(tree, hf_ws_payload_pong, tvb, offset, length, ENC_NA);
break;
default:
ti = proto_tree_add_item(tree, hf_ws_payload_unknown, tvb, offset, length, ENC_NA);
expert_add_info_format(pinfo, ti, &ei_ws_payload_unknown, "Dissector for Websocket Opcode (%d)"
" code not implemented, Contact Wireshark developers"
" if you want this supported", opcode);
break;
}
}
static void
dissect_websocket_data_frame(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_tree *pl_tree, guint8 opcode)
{
proto_item *ti;
const guint offset = 0, length = tvb_reported_length(tvb);
dissector_handle_t handle = NULL;
heur_dtbl_entry_t *hdtbl_entry;
conversation_t *conv;
http_conv_t *http_conv = NULL;
conv = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
if (conv) {
http_conv = (http_conv_t *)conversation_get_proto_data(conv, proto_http);
if (http_conv)
handle = dissector_get_uint_handle(port_subdissector_table, http_conv->server_port);
}
if (handle) {
call_dissector_only(handle, tvb, pinfo, tree, NULL);
return;
} else if (dissector_try_heuristic(heur_subdissector_list, tvb, pinfo, tree, &hdtbl_entry, NULL)) {
return;
}
switch (opcode) {
case WS_TEXT:
{
const gchar *saved_match_string = pinfo->match_string;
pinfo->match_string = NULL;
switch (pref_text_type) {
case WEBSOCKET_TEXT:
case WEBSOCKET_NONE:
default:
call_dissector(text_lines_handle, tvb, pinfo, tree);
break;
case WEBSOCKET_JSON:
call_dissector(json_handle, tvb, pinfo, tree);
break;
case WEBSOCKET_SIP:
call_dissector(sip_handle, tvb, pinfo, tree);
break;
}
pinfo->match_string = saved_match_string;
}
break;
case WS_BINARY:
call_dissector(data_handle, tvb, pinfo, tree);
break;
default:
ti = proto_tree_add_item(pl_tree, hf_ws_payload_unknown, tvb, offset, length, ENC_NA);
expert_add_info_format(pinfo, ti, &ei_ws_payload_unknown, "Dissector for Websocket Opcode (%d)"
" code not implemented, Contact Wireshark developers"
" if you want this supported", opcode);
break;
}
}
static void
dissect_websocket_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_tree *ws_tree, guint8 opcode)
{
const guint offset = 0, length = tvb_reported_length(tvb);
proto_item *ti;
proto_tree *pl_tree;
tvbuff_t *tvb_appdata;
ti = proto_tree_add_item(ws_tree, hf_ws_payload, tvb, offset, length, ENC_NA);
pl_tree = proto_item_add_subtree(ti, ett_ws_pl);
if (opcode == WS_CONTINUE) {
proto_tree_add_item(tree, hf_ws_payload_continue, tvb, offset, length, ENC_NA);
return;
}
tvb_appdata = tvb;
if (opcode & 8) {
dissect_websocket_control_frame(tvb_appdata, pinfo, pl_tree, opcode);
} else {
dissect_websocket_data_frame(tvb_appdata, pinfo, tree, pl_tree, opcode);
}
}
static int
dissect_websocket_frame(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti, *ti_len;
guint8 fin, opcode;
gboolean mask;
guint short_length, payload_length;
guint payload_offset, mask_offset;
proto_tree *ws_tree;
const guint8 *masking_key = NULL;
tvbuff_t *tvb_payload;
short_length = tvb_get_guint8(tvb, 1) & MASK_WS_PAYLOAD_LEN;
mask_offset = 2;
if (short_length == 126) {
payload_length = tvb_get_ntohs(tvb, 2);
mask_offset += 2;
} else if (short_length == 127) {
payload_length = (guint)tvb_get_ntoh64(tvb, 2);
mask_offset += 8;
} else {
payload_length = short_length;
}
mask = (tvb_get_guint8(tvb, 1) & MASK_WS_MASK) != 0;
payload_offset = mask_offset + (mask ? 4 : 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WebSocket");
col_set_str(pinfo->cinfo, COL_INFO, "WebSocket");
ti = proto_tree_add_item(tree, proto_websocket, tvb, 0, payload_offset, ENC_NA);
ws_tree = proto_item_add_subtree(ti, ett_ws);
proto_tree_add_item(ws_tree, hf_ws_fin, tvb, 0, 1, ENC_NA);
fin = (tvb_get_guint8(tvb, 0) & MASK_WS_FIN) >> 4;
proto_tree_add_item(ws_tree, hf_ws_reserved, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ws_tree, hf_ws_opcode, tvb, 0, 1, ENC_BIG_ENDIAN);
opcode = tvb_get_guint8(tvb, 0) & MASK_WS_OPCODE;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(opcode, ws_opcode_vals, "Unknown Opcode"));
col_append_str(pinfo->cinfo, COL_INFO, fin ? " [FIN]" : " ");
proto_tree_add_item(ws_tree, hf_ws_mask, tvb, 1, 1, ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO, mask ? " [MASKED]" : " ");
ti_len = proto_tree_add_item(ws_tree, hf_ws_payload_length, tvb, 1, 1, ENC_BIG_ENDIAN);
if (short_length == 126) {
proto_item_append_text(ti_len, " Extended Payload Length (16 bits)");
proto_tree_add_item(ws_tree, hf_ws_payload_length_ext_16, tvb, 2, 2, ENC_BIG_ENDIAN);
}
else if (short_length == 127) {
proto_item_append_text(ti_len, " Extended Payload Length (64 bits)");
proto_tree_add_item(ws_tree, hf_ws_payload_length_ext_64, tvb, 2, 8, ENC_BIG_ENDIAN);
}
if (mask) {
proto_tree_add_item(ws_tree, hf_ws_masking_key, tvb, mask_offset, 4, ENC_NA);
masking_key = tvb_get_ptr(tvb, mask_offset, 4);
}
if (payload_length > 0) {
if (mask) {
proto_tree_add_item(ws_tree, hf_ws_masked_payload, tvb, payload_offset, payload_length, ENC_NA);
tvb_payload = tvb_unmasked(tvb, pinfo, payload_offset, payload_length, masking_key);
tvb_set_child_real_data_tvbuff(tvb, tvb_payload);
add_new_data_source(pinfo, tvb_payload, "Unmasked data");
} else {
tvb_payload = tvb_new_subset(tvb, payload_offset, payload_length, payload_length);
}
dissect_websocket_payload(tvb_payload, pinfo, tree, ws_tree, opcode);
}
return tvb_captured_length(tvb);
}
static guint
get_websocket_frame_length(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint frame_length, payload_length;
gboolean mask;
frame_length = 2;
mask = tvb_get_guint8(tvb, offset + 1) & MASK_WS_MASK;
payload_length = tvb_get_guint8(tvb, offset + 1) & MASK_WS_PAYLOAD_LEN;
offset += 2;
if (payload_length == 126) {
if (tvb_reported_length_remaining(tvb, offset) < 2)
return 0;
payload_length = tvb_get_ntohs(tvb, offset);
frame_length += 2;
} else if (payload_length == 127) {
if (tvb_reported_length_remaining(tvb, offset) < 8)
return 0;
payload_length = (guint)tvb_get_ntoh64(tvb, offset);
frame_length += 8;
}
if (mask)
frame_length += 4;
frame_length += payload_length;
return frame_length;
}
static int
dissect_websocket(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 2,
get_websocket_frame_length, dissect_websocket_frame, data);
return tvb_captured_length(tvb);
}
void
proto_register_websocket(void)
{
static hf_register_info hf[] = {
{ &hf_ws_fin,
{ "Fin", "websocket.fin",
FT_BOOLEAN, 8, NULL, MASK_WS_FIN,
"Indicates that this is the final fragment in a message", HFILL }
},
{ &hf_ws_reserved,
{ "Reserved", "websocket.rsv",
FT_UINT8, BASE_HEX, NULL, MASK_WS_RSV,
"Must be zero", HFILL }
},
{ &hf_ws_opcode,
{ "Opcode", "websocket.opcode",
FT_UINT8, BASE_DEC, VALS(ws_opcode_vals), MASK_WS_OPCODE,
"Defines the interpretation of the Payload data", HFILL }
},
{ &hf_ws_mask,
{ "Mask", "websocket.mask",
FT_BOOLEAN, 8, NULL, MASK_WS_MASK,
"Defines whether the Payload data is masked", HFILL }
},
{ &hf_ws_payload_length,
{ "Payload length", "websocket.payload_length",
FT_UINT8, BASE_DEC, NULL, MASK_WS_PAYLOAD_LEN,
"The length of the Payload data", HFILL }
},
{ &hf_ws_payload_length_ext_16,
{ "Extended Payload length (16 bits)", "websocket.payload_length_ext_16",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The length (16 bits) of the Payload data", HFILL }
},
{ &hf_ws_payload_length_ext_64,
{ "Extended Payload length (64 bits)", "websocket.payload_length_ext_64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"The length (64 bits) of the Payload data", HFILL }
},
{ &hf_ws_masking_key,
{ "Masking-Key", "websocket.masking_key",
FT_BYTES, BASE_NONE, NULL, 0x0,
"All frames sent from the client to the server are masked by a 32-bit value that is contained within the frame", HFILL }
},
{ &hf_ws_payload,
{ "Payload", "websocket.payload",
FT_NONE, BASE_NONE, NULL, 0x0,
"Payload (after unmasking)", HFILL }
},
{ &hf_ws_masked_payload,
{ "Masked payload", "websocket.masked_payload",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_continue,
{ "Continue", "websocket.payload.continue",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_close,
{ "Close", "websocket.payload.close",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_close_status_code,
{ "Status code", "websocket.payload.close.status_code",
FT_UINT16, BASE_DEC, VALS(ws_close_status_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_close_reason,
{ "Reason", "websocket.payload.close.reason",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_ping,
{ "Ping", "websocket.payload.ping",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_pong,
{ "Pong", "websocket.payload.pong",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_unknown,
{ "Unknown", "websocket.payload.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_ws,
&ett_ws_pl,
&ett_ws_mask,
&ett_ws_control_close,
};
static ei_register_info ei[] = {
{ &ei_ws_payload_unknown, { "websocket.payload.unknown.expert", PI_UNDECODED, PI_NOTE, "Dissector for Websocket Opcode", EXPFILL }},
};
static const enum_val_t text_types[] = {
{"None", "No subdissection", WEBSOCKET_NONE},
{"Line based text", "Line based text", WEBSOCKET_TEXT},
{"As JSON", "As json", WEBSOCKET_JSON},
{"As SIP", "As SIP", WEBSOCKET_SIP},
{NULL, NULL, -1}
};
module_t *websocket_module;
expert_module_t* expert_websocket;
proto_websocket = proto_register_protocol("WebSocket",
"WebSocket", "websocket");
heur_subdissector_list = register_heur_dissector_list("ws");
port_subdissector_table = register_dissector_table("ws.port",
"TCP port for protocols using WebSocket", FT_UINT16, BASE_DEC);
proto_register_field_array(proto_websocket, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_websocket = expert_register_protocol(proto_websocket);
expert_register_field_array(expert_websocket, ei, array_length(ei));
new_register_dissector("websocket", dissect_websocket, proto_websocket);
websocket_module = prefs_register_protocol(proto_websocket, proto_reg_handoff_websocket);
prefs_register_enum_preference(websocket_module, "text_type",
"Dissect websocket text as",
"Select dissector for websocket text",
&pref_text_type, text_types, WEBSOCKET_NONE);
}
void
proto_reg_handoff_websocket(void)
{
data_handle = find_dissector("data");
text_lines_handle = find_dissector("data-text-lines");
json_handle = find_dissector("json");
sip_handle = find_dissector("sip");
proto_http = proto_get_id_by_filter_name("http");
}
