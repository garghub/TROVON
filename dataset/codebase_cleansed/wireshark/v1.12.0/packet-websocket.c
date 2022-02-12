static tvbuff_t *
tvb_unmasked(tvbuff_t *tvb, const guint offset, guint payload_length, const guint8 *masking_key)
{
gchar *data_unmask;
tvbuff_t *tvb_unmask = NULL;
guint i;
const guint8 *data_mask;
guint unmasked_length = payload_length > MAX_UNMASKED_LEN ? MAX_UNMASKED_LEN : payload_length;
data_unmask = (gchar *)g_malloc(unmasked_length);
data_mask = tvb_get_ptr(tvb, offset, unmasked_length);
for(i=0; i < unmasked_length; i++) {
data_unmask[i] = data_mask[i] ^ masking_key[i%4];
}
tvb_unmask = tvb_new_real_data(data_unmask, unmasked_length, payload_length);
tvb_set_free_cb(tvb_unmask, g_free);
return tvb_unmask;
}
static int
dissect_websocket_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_tree *ws_tree, guint8 opcode, guint payload_length, guint8 mask, const guint8* masking_key)
{
guint offset = 0;
proto_item *ti_unmask, *ti;
dissector_handle_t handle;
proto_tree *pl_tree, *mask_tree = NULL;
tvbuff_t *payload_tvb = NULL;
heur_dtbl_entry_t *hdtbl_entry;
ti = proto_tree_add_item(ws_tree, hf_ws_payload, tvb, offset, payload_length, ENC_NA);
pl_tree = proto_item_add_subtree(ti, ett_ws_pl);
if (mask) {
payload_tvb = tvb_unmasked(tvb, offset, payload_length, masking_key);
tvb_set_child_real_data_tvbuff(tvb, payload_tvb);
add_new_data_source(pinfo, payload_tvb, payload_length > tvb_captured_length(payload_tvb) ? "Unmasked Data (truncated)" : "Unmasked Data");
ti = proto_tree_add_item(ws_tree, hf_ws_payload_unmask, payload_tvb, offset, payload_length, ENC_NA);
if (payload_length > tvb_captured_length(payload_tvb)) {
proto_item_append_text(ti, " [truncated]");
}
mask_tree = proto_item_add_subtree(ti, ett_ws_mask);
} else {
payload_tvb = tvb_new_subset(tvb, offset, payload_length, -1);
}
handle = dissector_get_uint_handle(port_subdissector_table, pinfo->match_uint);
if (handle != NULL) {
call_dissector_only(handle, payload_tvb, pinfo, tree, NULL);
} else {
dissector_try_heuristic(heur_subdissector_list, payload_tvb, pinfo, tree, &hdtbl_entry, NULL);
}
switch (opcode) {
case WS_CONTINUE:
proto_tree_add_item(pl_tree, hf_ws_payload_continue, tvb, offset, payload_length, ENC_NA);
break;
case WS_TEXT:
if (mask) {
proto_tree_add_item(pl_tree, hf_ws_payload_text_mask, tvb, offset, payload_length, ENC_NA);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_text_unmask, payload_tvb, offset, payload_length, ENC_UTF_8|ENC_NA);
PROTO_ITEM_SET_GENERATED(ti_unmask);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_text, payload_tvb, offset, payload_length, ENC_UTF_8|ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_unmask);
} else {
const gchar *saved_match_string = pinfo->match_string;
void *save_private_data = pinfo->private_data;
pinfo->match_string = NULL;
pinfo->private_data = NULL;
switch (pref_text_type) {
case WEBSOCKET_TEXT:
call_dissector(text_lines_handle, payload_tvb, pinfo, pl_tree);
break;
case WEBSOCKET_JSON:
call_dissector(json_handle, payload_tvb, pinfo, pl_tree);
break;
case WEBSOCKET_SIP:
call_dissector(sip_handle, payload_tvb, pinfo, pl_tree);
break;
case WEBSOCKET_NONE:
default:
proto_tree_add_item(pl_tree, hf_ws_payload_text, tvb, offset, payload_length, ENC_UTF_8|ENC_NA);
break;
}
pinfo->match_string = saved_match_string;
pinfo->private_data = save_private_data;
}
offset += payload_length;
break;
case WS_BINARY:
if (mask) {
proto_tree_add_item(pl_tree, hf_ws_payload_binary_mask, tvb, offset, payload_length, ENC_NA);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_binary_unmask, payload_tvb, offset, payload_length, ENC_NA);
PROTO_ITEM_SET_GENERATED(ti_unmask);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_binary, payload_tvb, offset, payload_length, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_unmask);
} else {
proto_tree_add_item(pl_tree, hf_ws_payload_binary, tvb, offset, payload_length, ENC_NA);
}
offset += payload_length;
break;
case WS_CLOSE:
if (mask) {
proto_tree_add_item(pl_tree, hf_ws_payload_close_mask, tvb, offset, payload_length, ENC_NA);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_close_unmask, payload_tvb, offset, payload_length, ENC_NA);
PROTO_ITEM_SET_GENERATED(ti_unmask);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_close, payload_tvb, offset, payload_length, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_unmask);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_close_status_code, payload_tvb, offset, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(ti_unmask);
if (payload_length > 2) {
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_close_reason, payload_tvb, offset+2, payload_length-2, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(ti_unmask);
}
} else {
proto_tree_add_item(pl_tree, hf_ws_payload_close, tvb, offset, payload_length, ENC_NA);
proto_tree_add_item(pl_tree, hf_ws_payload_close_status_code, tvb, offset, 2, ENC_BIG_ENDIAN);
if (payload_length > 2) {
proto_tree_add_item(pl_tree, hf_ws_payload_close_reason, tvb, offset+2, payload_length-2, ENC_ASCII|ENC_NA);
}
}
offset += payload_length;
break;
case WS_PING:
if (mask) {
proto_tree_add_item(pl_tree, hf_ws_payload_ping_mask, tvb, offset, payload_length, ENC_NA);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_ping_unmask, payload_tvb, offset, payload_length, ENC_NA);
PROTO_ITEM_SET_GENERATED(ti_unmask);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_ping, payload_tvb, offset, payload_length, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_unmask);
} else {
proto_tree_add_item(pl_tree, hf_ws_payload_ping, tvb, offset, payload_length, ENC_NA);
}
offset += payload_length;
break;
case WS_PONG:
if (mask) {
proto_tree_add_item(pl_tree, hf_ws_payload_pong_mask, tvb, offset, payload_length, ENC_NA);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_pong_unmask, payload_tvb, offset, payload_length, ENC_NA);
PROTO_ITEM_SET_GENERATED(ti_unmask);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_pong, payload_tvb, offset, payload_length, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_unmask);
} else {
proto_tree_add_item(pl_tree, hf_ws_payload_pong, tvb, offset, payload_length, ENC_NA);
}
offset += payload_length;
break;
default:
ti = proto_tree_add_item(pl_tree, hf_ws_payload_unknown, tvb, offset, payload_length, ENC_NA);
expert_add_info_format(pinfo, ti, &ei_ws_payload_unknown, "Dissector for Websocket Opcode (%d)"
" code not implemented, Contact Wireshark developers"
" if you want this supported", opcode);
break;
}
return offset;
}
static int
dissect_websocket(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti, *ti_len;
guint8 fin, opcode, mask;
guint length, short_length, payload_length, recurse_length;
guint payload_offset, mask_offset, recurse_offset;
proto_tree *ws_tree = NULL;
const guint8 *masking_key = NULL;
tvbuff_t *tvb_payload;
length = tvb_length(tvb);
if (length < 2) {
pinfo->desegment_len = 2;
return 0;
}
short_length = tvb_get_guint8(tvb, 1) & MASK_WS_PAYLOAD_LEN;
if (short_length == 126) {
if (length < 2+2) {
pinfo->desegment_len = 2+2;
return 0;
}
payload_length = tvb_get_ntohs(tvb, 2);
mask_offset = 2+2;
}
else if (short_length == 127) {
if (length < 2+8) {
pinfo->desegment_len = 2+8;
return 0;
}
payload_length = (guint)tvb_get_ntoh64(tvb, 2);
mask_offset = 2+8;
}
else{
payload_length = short_length;
mask_offset = 2;
}
mask = (tvb_get_guint8(tvb, 1) & MASK_WS_MASK) >> 4;
payload_offset = mask_offset + (mask ? 4 : 0);
if (payload_offset + payload_length < payload_length) {
payload_length = tvb_reported_length_remaining(tvb, payload_offset);
}
if (length < payload_offset + payload_length) {
pinfo->desegment_len = payload_offset + payload_length - length;
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WebSocket");
col_set_str(pinfo->cinfo, COL_INFO, "WebSocket");
if (tree) {
ti = proto_tree_add_item(tree, proto_websocket, tvb, 0, payload_offset, ENC_NA);
ws_tree = proto_item_add_subtree(ti, ett_ws);
}
proto_tree_add_item(ws_tree, hf_ws_fin, tvb, 0, 1, ENC_NA);
fin = (tvb_get_guint8(tvb, 0) & MASK_WS_FIN) >> 4;
proto_tree_add_item(ws_tree, hf_ws_reserved, tvb, 0, 1, ENC_NA);
proto_tree_add_item(ws_tree, hf_ws_opcode, tvb, 0, 1, ENC_NA);
opcode = tvb_get_guint8(tvb, 0) & MASK_WS_OPCODE;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(opcode, ws_opcode_vals, "Unknown Opcode"));
col_append_str(pinfo->cinfo, COL_INFO, fin ? " [FIN]" : " ");
proto_tree_add_item(ws_tree, hf_ws_mask, tvb, 1, 1, ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO, mask ? " [MASKED]" : " ");
ti_len = proto_tree_add_item(ws_tree, hf_ws_payload_length, tvb, 1, 1, ENC_NA);
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
tvb_payload = tvb_new_subset_remaining(tvb, payload_offset);
dissect_websocket_payload(tvb_payload, pinfo, tree, ws_tree, opcode, payload_length, mask, masking_key);
recurse_offset = payload_offset + payload_length;
if (length > recurse_offset) {
recurse_length = dissect_websocket(tvb_new_subset_remaining(tvb, payload_offset+payload_length), pinfo, tree, data);
if (pinfo->desegment_len) pinfo->desegment_offset += recurse_offset;
return recurse_offset + recurse_length;
}
return recurse_offset;
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
NULL, HFILL }
},
{ &hf_ws_payload_unmask,
{ "Unmask Payload", "websocket.payload.unmask",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_continue,
{ "Continue", "websocket.payload.continue",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_text,
{ "Text", "websocket.payload.text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_text_mask,
{ "Text", "websocket.payload.text_mask",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_text_unmask,
{ "Text unmask", "websocket.payload.text_unmask",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_binary,
{ "Binary", "websocket.payload.binary",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_binary_mask,
{ "Binary", "websocket.payload.binary_mask",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_binary_unmask,
{ "Binary", "websocket.payload.binary_unmask",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_close,
{ "Close", "websocket.payload.close",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_close_mask,
{ "Close", "websocket.payload.close_mask",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_close_unmask,
{ "Unmask Close", "websocket.payload.close_unmask",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_close_status_code,
{ "Close", "websocket.payload.close.status_code",
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
{ &hf_ws_payload_ping_mask,
{ "Ping", "websocket.payload.ping_mask",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_ping_unmask,
{ "Ping", "websocket.payload.ping_unmask",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_pong,
{ "Pong", "websocket.payload.pong",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_pong_mask,
{ "Pong", "websocket.payload.pong_mask",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ws_payload_pong_unmask,
{ "Pong", "websocket.payload.pong_unmask",
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
&ett_ws_mask
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
register_heur_dissector_list("ws", &heur_subdissector_list);
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
text_lines_handle = find_dissector("data-text-lines");
json_handle = find_dissector("json");
sip_handle = find_dissector("sip");
}
