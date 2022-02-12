static void
dissect_hpfeeds_error_pdu(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_hpfeeds_errmsg, tvb, offset, -1, ENC_BIG_ENDIAN);
}
static void
dissect_hpfeeds_info_pdu(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
guint8 len = 0;
proto_item *ti = NULL;
proto_tree *data_subtree = NULL;
guint8 *strptr = NULL;
len = tvb_get_guint8(tvb, offset);
strptr = tvb_get_string(wmem_packet_scope(), tvb, offset + 1, len);
ti = proto_tree_add_text(tree, tvb, offset, -1, "Broker: %s", strptr);
data_subtree = proto_item_add_subtree(ti, ett_hpfeeds);
proto_tree_add_item(data_subtree, hf_hpfeeds_server_len, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(data_subtree, hf_hpfeeds_server, tvb, offset, len,
ENC_BIG_ENDIAN);
offset += len;
proto_tree_add_item(data_subtree, hf_hpfeeds_nonce, tvb, offset, -1,
ENC_BIG_ENDIAN);
}
static void
dissect_hpfeeds_auth_pdu(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
guint8 len = 0;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_hpfeeds_ident_len, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_hpfeeds_ident, tvb,
offset, len, ENC_BIG_ENDIAN);
offset += len;
proto_tree_add_item(tree, hf_hpfeeds_secret, tvb,
offset, -1, ENC_BIG_ENDIAN);
}
static void
dissect_hpfeeds_publish_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset)
{
guint8 len = 0;
guint8 *strptr = NULL;
gint8 channel = CH_EINVAL;
tvbuff_t *json_tvb = NULL;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_hpfeeds_ident_len, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_hpfeeds_ident, tvb, offset, len,
ENC_BIG_ENDIAN);
offset += len;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_hpfeeds_chan_len, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
strptr = tvb_get_string(wmem_packet_scope(), tvb, offset, len);
proto_tree_add_item(tree, hf_hpfeeds_channel, tvb, offset, len,
ENC_BIG_ENDIAN);
offset += len;
channel = str_to_val(strptr, chan_vals, CH_EINVAL);
pinfo->private_data = strptr;
switch (channel) {
case CH_DIONAEA_CAPTURE:
case CH_DIONAEA_DCE:
case CH_DIONAEA_SHELLCODE:
case CH_DIONAEA_UINQUE:
case CH_DIONAEA_CONNECTIONS:
case CH_KIPPO_SESSIONS:
case CH_GLASTOPF_EVENTS:
case CH_GEOLOC_EVENTS:
json_tvb = tvb_new_subset(tvb, offset, -1, -1);
call_dissector(json_hdl, json_tvb, pinfo, tree);
break;
default:
proto_tree_add_item(tree, hf_hpfeeds_payload, tvb, offset, -1,
ENC_NA);
break;
}
}
static void
dissect_hpfeeds_subscribe_pdu(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
guint8 len = 0;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_hpfeeds_ident_len, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_hpfeeds_ident, tvb, offset, len,
ENC_BIG_ENDIAN);
offset += len;
proto_tree_add_item(tree, hf_hpfeeds_channel, tvb, offset, -1,
ENC_BIG_ENDIAN);
}
static guint
get_hpfeeds_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_ntohl(tvb, offset + 0);
}
static void
dissect_hpfeeds_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = HPFEEDS_OPCODE_OFFSET;
guint8 opcode;
proto_item *ti;
proto_tree *data_subtree;
opcode = tvb_get_guint8(tvb, offset);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HPFEEDS");
col_clear(pinfo->cinfo,COL_INFO);
col_add_fstr(pinfo->cinfo, COL_INFO, "Type %s",
val_to_str(opcode, opcode_vals, "Unknown (0x%02x)"));
ti = proto_tree_add_item(tree, hf_hpfeeds_opcode, tvb, offset,
1, ENC_BIG_ENDIAN);
data_subtree = proto_item_add_subtree(ti, ett_hpfeeds);
offset += 1;
if (opcode >= array_length(opcode_vals) - 1) {
expert_add_info_format(pinfo, ti, &ei_hpfeeds_opcode_unknown,
"Unknown value %02x for opcode field", opcode);
}
if (tree) {
switch (opcode) {
case OP_ERROR:
dissect_hpfeeds_error_pdu(tvb, data_subtree, offset);
break;
case OP_INFO:
dissect_hpfeeds_info_pdu(tvb, data_subtree, offset);
break;
case OP_AUTH:
dissect_hpfeeds_auth_pdu(tvb, data_subtree, offset);
break;
case OP_PUBLISH:
dissect_hpfeeds_publish_pdu(tvb, pinfo, data_subtree, offset);
break;
case OP_SUBSCRIBE:
dissect_hpfeeds_subscribe_pdu(tvb, data_subtree, offset);
break;
}
}
}
static void
dissect_hpfeeds(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint msglen = 0;
guint8 offset = 0;
proto_item *ti = NULL;
proto_tree *hpfeeds_tree = NULL;
if (tvb_reported_length(tvb) < HPFEEDS_HDR_LEN)
return;
msglen = tvb_get_ntohl(tvb, offset);
if (tree) {
ti = proto_tree_add_item(tree, proto_hpfeeds, tvb, 0, -1, ENC_NA);
hpfeeds_tree = proto_item_add_subtree(ti, ett_hpfeeds);
proto_tree_add_item(hpfeeds_tree, hf_hpfeeds_msg_length, tvb, offset,
4, ENC_BIG_ENDIAN);
}
if (tvb_reported_length(tvb) < msglen) {
tcp_dissect_pdus(tvb, pinfo, hpfeeds_tree, hpfeeds_desegment, 5,
get_hpfeeds_pdu_len, dissect_hpfeeds_pdu);
} else
dissect_hpfeeds_pdu(tvb, pinfo, hpfeeds_tree);
}
void
proto_register_hpfeeds(void)
{
static hf_register_info hf[] = {
{ &hf_hpfeeds_opcode,
{ "Opcode", "hpfeeds.opcode",
FT_UINT8, BASE_DEC_HEX,
VALS(opcode_vals), 0x0,
NULL, HFILL }
},
{ &hf_hpfeeds_msg_length,
{ "Message Length", "hpfeeds.msglen",
FT_UINT32, BASE_DEC_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hpfeeds_nonce,
{ "Nonce", "hpfeeds.nonce",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hpfeeds_secret,
{ "Secret", "hpfeeds.secret",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hpfeeds_payload,
{ "Payload", "hpfeeds.payload",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hpfeeds_server,
{ "Server", "hpfeeds.server",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hpfeeds_ident,
{ "Ident", "hpfeeds.ident",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hpfeeds_channel,
{ "Channel", "hpfeeds.channel",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hpfeeds_chan_len,
{ "Channel length", "hpfeeds.channel_len",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hpfeeds_ident_len,
{ "Ident length", "hpfeeds.ident_len",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hpfeeds_errmsg,
{ "Error message", "hpfeeds.errmsg",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hpfeeds_server_len,
{ "Server length", "hpfeeds.server_len",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_hpfeeds
};
static ei_register_info ei[] = {
{ &ei_hpfeeds_opcode_unknown, { "hpfeeds.opcode.unknown", PI_PROTOCOL, PI_WARN, "Unknown value for opcode field", EXPFILL }},
};
module_t *hpfeeds_module;
expert_module_t* expert_hpfeeds;
proto_hpfeeds = proto_register_protocol (
"HPFEEDS HoneyPot Feeds Protocol",
"HPFEEDS",
"hpfeeds"
);
proto_register_field_array(proto_hpfeeds, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_hpfeeds = expert_register_protocol(proto_hpfeeds);
expert_register_field_array(expert_hpfeeds, ei, array_length(ei));
hpfeeds_module = prefs_register_protocol(proto_hpfeeds, proto_reg_handoff_hpfeeds);
prefs_register_bool_preference(hpfeeds_module, "desegment_hpfeeds_messages",
"Reassemble HPFEEDS messages spanning multiple TCP segments",
"Whether the HPFEEDS dissector should reassemble messages spanning "
"multiple TCP segments. "
"To use this option, you must also enable \"Allow subdissectors to "
"reassemble TCP streams\" in the TCP protocol settings.",
&hpfeeds_desegment);
prefs_register_uint_preference(hpfeeds_module,
"dissector_port",
"Dissector TCP port",
"Set the TCP port for HPFEEDS messages",
10, &hpfeeds_port_pref);
}
void
proto_reg_handoff_hpfeeds(void)
{
static dissector_handle_t hpfeeds_handle;
static gboolean hpfeeds_prefs_initialized = FALSE;
static gint16 hpfeeds_dissector_port;
if (!hpfeeds_prefs_initialized) {
hpfeeds_handle = create_dissector_handle(dissect_hpfeeds, proto_hpfeeds);
hpfeeds_prefs_initialized = TRUE;
}
else {
dissector_delete_uint("tcp.port",hpfeeds_dissector_port , hpfeeds_handle);
}
hpfeeds_dissector_port = hpfeeds_port_pref;
dissector_add_uint("tcp.port", hpfeeds_dissector_port, hpfeeds_handle);
json_hdl = find_dissector("json");
}
