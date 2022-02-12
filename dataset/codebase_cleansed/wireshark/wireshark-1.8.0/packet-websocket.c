tvbuff_t *
tvb_unmasked(tvbuff_t *tvb, const int offset, int payload_length, const guint8 *masking_key)
{
gchar *data_unmask;
tvbuff_t *tvb_unmask = NULL;
int i;
const guint8 *data_mask;
int unmasked_length = payload_length > MAX_UNMASKED_LEN ? MAX_UNMASKED_LEN : payload_length;
data_unmask = g_malloc(unmasked_length);
data_mask = tvb_get_ptr(tvb, offset, unmasked_length);
for(i=0; i < unmasked_length; i++){
data_unmask[i] = data_mask[i] ^ masking_key[i%4];
}
tvb_unmask = tvb_new_real_data(data_unmask, unmasked_length, unmasked_length);
tvb_set_free_cb(tvb_unmask, g_free);
return tvb_unmask;
}
static int
dissect_websocket_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ws_tree, guint8 opcode, guint64 payload_length, guint8 mask, const guint8* masking_key)
{
int offset = 0;
int payload_length_32bit;
proto_item *ti_unmask, *ti;
proto_tree *pl_tree, *mask_tree = NULL;
tvbuff_t *unmask_tvb = NULL;
payload_length_32bit = (int)payload_length;
if (payload_length != (guint64)payload_length_32bit) {
proto_tree_add_text(ws_tree, tvb, offset, -1, "Payload length %" G_GINT64_MODIFIER "u is too large to dissect",
payload_length);
return tvb_length(tvb);
}
ti = proto_tree_add_item(ws_tree, hf_ws_payload, tvb, offset, payload_length_32bit, ENC_NA);
pl_tree = proto_item_add_subtree(ti, ett_ws_pl);
if(mask){
unmask_tvb = tvb_unmasked(tvb, offset, payload_length_32bit, masking_key);
tvb_set_child_real_data_tvbuff(tvb, unmask_tvb);
add_new_data_source(pinfo, unmask_tvb, payload_length_32bit > (int) tvb_length(unmask_tvb) ? "Unmasked Data (truncated)" : "Unmasked Data");
ti = proto_tree_add_item(ws_tree, hf_ws_payload_unmask, unmask_tvb, offset, payload_length_32bit, ENC_NA);
mask_tree = proto_item_add_subtree(ti, ett_ws_mask);
}
switch(opcode){
case WS_CONTINUE:
proto_tree_add_item(pl_tree, hf_ws_payload_continue, tvb, offset, payload_length_32bit, ENC_NA);
break;
case WS_TEXT:
if(mask){
proto_tree_add_item(pl_tree, hf_ws_payload_text_mask, tvb, offset, payload_length_32bit, ENC_NA);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_text_unmask, unmask_tvb, offset, payload_length_32bit, ENC_UTF_8|ENC_NA);
PROTO_ITEM_SET_GENERATED(ti_unmask);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_text, unmask_tvb, offset, payload_length_32bit, ENC_UTF_8|ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_unmask);
}else{
proto_tree_add_item(pl_tree, hf_ws_payload_text, tvb, offset, payload_length_32bit, ENC_UTF_8|ENC_NA);
}
offset += payload_length_32bit;
break;
case WS_BINARY:
if(mask){
proto_tree_add_item(pl_tree, hf_ws_payload_binary_mask, tvb, offset, payload_length_32bit, ENC_NA);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_binary_unmask, unmask_tvb, offset, payload_length_32bit, ENC_NA);
PROTO_ITEM_SET_GENERATED(ti_unmask);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_binary, unmask_tvb, offset, payload_length_32bit, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_unmask);
}else{
proto_tree_add_item(pl_tree, hf_ws_payload_binary, tvb, offset, payload_length_32bit, ENC_NA);
}
offset += payload_length_32bit;
break;
case WS_CLOSE:
if(mask){
proto_tree_add_item(pl_tree, hf_ws_payload_close_mask, tvb, offset, payload_length_32bit, ENC_NA);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_close_unmask, unmask_tvb, offset, payload_length_32bit, ENC_NA);
PROTO_ITEM_SET_GENERATED(ti_unmask);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_close, unmask_tvb, offset, payload_length_32bit, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_unmask);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_close_status_code, unmask_tvb, offset, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(ti_unmask);
if(payload_length_32bit > 2){
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_close_reason, unmask_tvb, offset+2, payload_length_32bit-2, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(ti_unmask);
}
}else{
proto_tree_add_item(pl_tree, hf_ws_payload_close, tvb, offset, payload_length_32bit, ENC_NA);
proto_tree_add_item(pl_tree, hf_ws_payload_close_status_code, tvb, offset, 2, ENC_BIG_ENDIAN);
if(payload_length_32bit > 2){
proto_tree_add_item(pl_tree, hf_ws_payload_close_reason, tvb, offset+2, payload_length_32bit-2, ENC_ASCII|ENC_NA);
}
}
offset += payload_length_32bit;
break;
case WS_PING:
if(mask){
proto_tree_add_item(pl_tree, hf_ws_payload_ping_mask, tvb, offset, payload_length_32bit, ENC_NA);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_ping_unmask, unmask_tvb, offset, payload_length_32bit, ENC_NA);
PROTO_ITEM_SET_GENERATED(ti_unmask);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_ping, unmask_tvb, offset, payload_length_32bit, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_unmask);
}else{
proto_tree_add_item(pl_tree, hf_ws_payload_ping, tvb, offset, payload_length_32bit, ENC_NA);
}
offset += payload_length_32bit;
break;
case WS_PONG:
if(mask){
proto_tree_add_item(pl_tree, hf_ws_payload_pong_mask, tvb, offset, payload_length_32bit, ENC_NA);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_pong_unmask, unmask_tvb, offset, payload_length_32bit, ENC_NA);
PROTO_ITEM_SET_GENERATED(ti_unmask);
ti_unmask = proto_tree_add_item(mask_tree, hf_ws_payload_pong, unmask_tvb, offset, payload_length_32bit, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_unmask);
}else{
proto_tree_add_item(pl_tree, hf_ws_payload_pong, tvb, offset, payload_length_32bit, ENC_NA);
}
offset += payload_length_32bit;
break;
default:
ti = proto_tree_add_item(pl_tree, hf_ws_payload_unknown, tvb, offset, payload_length_32bit, ENC_NA);
expert_add_info_format(pinfo, ti, PI_UNDECODED, PI_NOTE, "Dissector for Websocket Opcode (%d)"
" code not implemented, Contact Wireshark developers"
" if you want this supported", opcode);
break;
}
return offset;
}
static int
dissect_websocket(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *ti_len;
proto_tree *ws_tree = NULL;
int offset = 0;
guint8 fin, opcode, mask;
const guint8 *masking_key = NULL;
guint64 payload_length;
tvbuff_t *tvb_payload = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WebSocket");
col_set_str(pinfo->cinfo, COL_INFO, "WebSocket");
if (tree) {
ti = proto_tree_add_item(tree, proto_websocket, tvb, 0, -1, ENC_NA);
ws_tree = proto_item_add_subtree(ti, ett_ws);
}
proto_tree_add_item(ws_tree, hf_ws_fin, tvb, offset, 1, ENC_NA);
fin = (tvb_get_guint8(tvb, offset) & MASK_WS_FIN) >> 4;
proto_tree_add_item(ws_tree, hf_ws_reserved, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ws_tree, hf_ws_opcode, tvb, offset, 1, ENC_NA);
opcode = tvb_get_guint8(tvb, offset) & MASK_WS_OPCODE;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(opcode, ws_opcode_vals, "Unknown Opcode"));
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", fin ? "[FIN]" : "");
offset +=1;
proto_tree_add_item(ws_tree, hf_ws_mask, tvb, offset, 1, ENC_NA);
mask = (tvb_get_guint8(tvb, offset) & MASK_WS_MASK) >> 4;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", mask ? "[MASKED]" : "");
ti_len = proto_tree_add_item(ws_tree, hf_ws_payload_length, tvb, offset, 1, ENC_NA);
payload_length = (guint64)tvb_get_guint8(tvb, offset) & MASK_WS_PAYLOAD_LEN;
offset +=1;
switch(payload_length){
case 126:
proto_item_append_text(ti_len, " Extended Payload Length (16 bits)");
proto_tree_add_item(ws_tree, hf_ws_payload_length_ext_16, tvb, offset, 2, ENC_BIG_ENDIAN);
payload_length = (guint64)tvb_get_ntohs(tvb, offset);
offset += 2;
break;
case 127:
proto_item_append_text(ti_len, " Extended Payload Length (64 bits)");
proto_tree_add_item(ws_tree, hf_ws_payload_length_ext_64, tvb, offset, 8, ENC_BIG_ENDIAN);
payload_length = tvb_get_ntoh64(tvb, offset);
offset += 8;
break;
default:
break;
}
if(mask){
proto_tree_add_item(ws_tree, hf_ws_masking_key, tvb, offset, 4, ENC_NA);
masking_key = tvb_get_ptr(tvb, offset, 4);
offset += 4;
}
tvb_payload = tvb_new_subset_remaining(tvb, offset);
offset += dissect_websocket_payload(tvb_payload, pinfo, ws_tree, opcode, payload_length, mask, masking_key);
return offset;
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
{ "Extended Payload length (16 bits)", "websocket.payload_length_ext_64",
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
proto_websocket = proto_register_protocol("WebSocket",
"WebSocket", "websocket");
proto_register_field_array(proto_websocket, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("websocket", dissect_websocket, proto_websocket);
}
