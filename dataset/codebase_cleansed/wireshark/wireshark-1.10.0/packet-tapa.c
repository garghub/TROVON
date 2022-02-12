static gboolean
check_ascii(tvbuff_t *tvb, gint offset, gint length)
{
gint i;
guint8 buf;
for (i = 0; i < length; i++) {
buf = tvb_get_guint8(tvb, offset+i);
if (buf < 0x20 || buf >= 0x80) {
return FALSE;
}
}
return TRUE;
}
static int
dissect_tapa_discover_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tapa_discover_tree, guint32 offset, gint remaining)
{
proto_tree_add_item(tapa_discover_tree, hf_tapa_discover_reply_switchip, tvb, offset, 4,
ENC_BIG_ENDIAN);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Switch: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
proto_tree_add_item(tapa_discover_tree, hf_tapa_discover_reply_unused, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tapa_discover_tree, hf_tapa_discover_reply_bias, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
remaining -= 6;
proto_tree_add_item(tapa_discover_tree, hf_tapa_discover_reply_pad, tvb, offset, remaining,
ENC_NA);
offset += remaining;
return offset;
}
static int
dissect_tapa_discover_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tapa_discover_tree, guint32 offset, gint remaining)
{
proto_item *item;
proto_tree *tapa_discover_item_tree;
guint8 item_type;
gint item_length;
gchar *item_text;
const gchar *item_type_text;
while (remaining > 0) {
item_type = tvb_get_guint8(tvb, offset);
item_type_text = val_to_str(item_type, tapa_discover_request_vals, "%d");
item_length = tvb_get_ntohs(tvb, offset + 2);
item_text = tvb_format_text(tvb, offset + 4, item_length);
DISSECTOR_ASSERT(item_length > 0);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s: %s",
item_type_text, item_text);
item = proto_tree_add_text(tapa_discover_tree, tvb, offset, 4 + item_length,
"Type %d = %s, length %d, value %s",
item_type, item_type_text, item_length, item_text);
tapa_discover_item_tree = proto_item_add_subtree(item, ett_tapa_discover_req);
proto_tree_add_item(tapa_discover_item_tree, hf_tapa_discover_req_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tapa_discover_item_tree, hf_tapa_discover_req_pad, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tapa_discover_item_tree, hf_tapa_discover_req_length, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tapa_discover_item_tree, hf_tapa_discover_req_value, tvb, offset, item_length,
ENC_NA);
offset += item_length;
remaining -= (item_length + 4);
}
return offset;
}
static int
dissect_tapa_discover_unknown_new_tlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tapa_discover_tree, guint32 offset, gint remaining)
{
proto_item *item;
proto_tree *tapa_discover_item_tree;
guint8 item_type;
gint item_length;
const gchar *item_text;
gboolean is_ascii;
while (remaining > 0) {
item_type = tvb_get_guint8(tvb, offset);
item_length = tvb_get_ntohs(tvb, offset + 2) - 4;
DISSECTOR_ASSERT(item_length > 0);
is_ascii = check_ascii(tvb, offset + 4, item_length);
if (is_ascii)
item_text = tvb_format_text(tvb, offset + 4, item_length);
else
item_text = "BINARY-DATA";
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", T=%d L=%d",
item_type, item_length);
item = proto_tree_add_text(tapa_discover_tree, tvb, offset, 4 + item_length,
"Type %d, length %d, value %s",
item_type, item_length, item_text);
tapa_discover_item_tree = proto_item_add_subtree(item, ett_tapa_discover_req);
proto_tree_add_item(tapa_discover_item_tree, hf_tapa_discover_newtlv_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tapa_discover_item_tree, hf_tapa_discover_newtlv_pad, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tapa_discover_item_tree, hf_tapa_discover_newtlv_length, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
if (is_ascii)
proto_tree_add_item(tapa_discover_item_tree, hf_tapa_discover_newtlv_valuetext,
tvb, offset, item_length, ENC_ASCII|ENC_NA);
else
proto_tree_add_item(tapa_discover_item_tree, hf_tapa_discover_newtlv_valuehex,
tvb, offset, item_length, ENC_NA);
offset += item_length;
remaining -= (item_length + 4);
}
return offset;
}
static int
dissect_tapa_discover(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *tapa_discover_tree = NULL;
guint32 offset = 0;
guint8 packet_type;
guint remaining;
packet_type = tvb_get_guint8(tvb, 0);
remaining = tvb_get_ntohs(tvb, 2) - 4;
DISSECTOR_ASSERT(remaining > 4);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Discover - %s",
val_to_str(packet_type, tapa_discover_type_vals, "Unknown (%d)"));
if (tree) {
ti = proto_tree_add_item(tree, proto_tapa, tvb, offset, -1,
ENC_NA);
tapa_discover_tree = proto_item_add_subtree(ti, ett_tapa_discover);
proto_tree_add_item(tapa_discover_tree, hf_tapa_discover_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tapa_discover_tree, hf_tapa_discover_flags, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tapa_discover_tree, hf_tapa_discover_length, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
switch (packet_type) {
case TAPA_TYPE_REQUEST:
offset = dissect_tapa_discover_req(tvb, pinfo, tapa_discover_tree, offset, remaining);
break;
case TAPA_TYPE_REPLY:
offset = dissect_tapa_discover_reply(tvb, pinfo, tapa_discover_tree, offset, remaining);
break;
case TAPA_TYPE_REQUEST_NEW:
case TAPA_TYPE_REPLY_NEW:
offset = dissect_tapa_discover_unknown_new_tlv(tvb, pinfo, tapa_discover_tree,
offset, remaining);
break;
default:
proto_tree_add_item(tapa_discover_tree, hf_tapa_discover_unknown, tvb, offset,
remaining, ENC_NA);
offset += 1;
break;
}
}
return offset;
}
static int
dissect_tapa_tunnel(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *tapa_tunnel_tree = NULL;
guint32 offset = 0;
guint8 version;
guint8 type;
guint remaining;
version = tvb_get_guint8(tvb, 0) & 0xF0;
type = tvb_get_guint8(tvb, 1);
remaining = tvb_reported_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Tunnel - V=%d, T=%s", version >> 4,
val_to_str(type, tapa_tunnel_type_vals, "Unknown (%d)"));
if (tree) {
ti = proto_tree_add_item(tree, proto_tapa, tvb, offset, -1,
ENC_NA);
tapa_tunnel_tree = proto_item_add_subtree(ti, ett_tapa_tunnel);
proto_tree_add_item(tapa_tunnel_tree, hf_tapa_tunnel_version, tvb, offset, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(tapa_tunnel_tree, hf_tapa_tunnel_five, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tapa_tunnel_tree, hf_tapa_tunnel_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tapa_tunnel_tree, hf_tapa_tunnel_zero, tvb, offset, 8,
ENC_NA);
offset += 8;
proto_tree_add_item(tapa_tunnel_tree, hf_tapa_tunnel_dmac, tvb, offset, 6,
ENC_NA);
offset += 6;
proto_tree_add_item(tapa_tunnel_tree, hf_tapa_tunnel_smac, tvb, offset, 6,
ENC_NA);
offset += 6;
switch (type) {
case TAPA_TUNNEL_TYPE_0:
proto_tree_add_item(tapa_tunnel_tree, hf_tapa_tunnel_0804, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tapa_tunnel_tree, hf_tapa_tunnel_tagsetc, tvb, offset, 6,
ENC_NA);
offset += 6;
break;
case TAPA_TUNNEL_TYPE_1:
proto_tree_add_item(tapa_tunnel_tree, hf_tapa_tunnel_seqno, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tapa_tunnel_tree, hf_tapa_tunnel_length, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
break;
default:
break;
}
proto_tree_add_item(tapa_tunnel_tree, hf_tapa_tunnel_remaining, tvb,
offset, remaining - offset, ENC_NA);
offset = remaining;
}
return offset;
}
static gboolean
test_tapa_discover(tvbuff_t *tvb)
{
guint8 type, req_type;
guint16 length;
if (tvb_length(tvb) < 4)
return FALSE;
type = tvb_get_guint8(tvb, 0);
length = tvb_get_ntohs(tvb, 2);
req_type = tvb_get_guint8(tvb, 4);
if (type < TAPA_TYPE_REQUEST ||
type > TAPA_TYPE_REPLY_NEW ||
length < 12 ||
length > 1472 ||
(type == TAPA_TYPE_REQUEST && (req_type < TAPA_REQUEST_SERIAL || req_type > TAPA_REQUEST_MODEL))) {
return FALSE;
}
return TRUE;
}
static gboolean
test_tapa_tunnel(tvbuff_t *tvb)
{
if (tvb_length(tvb) < 4 ||
(tvb_get_guint8(tvb, 0) & 0xF0) >= 0x40 ||
tvb_get_ntohs(tvb, 2) > 0 ||
tvb_get_guint8(tvb, 1) > 1) {
return FALSE;
}
return TRUE;
}
static int
dissect_tapa_static(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (test_tapa_discover(tvb)) {
return dissect_tapa_discover(tvb, pinfo, tree);
} else if (test_tapa_tunnel(tvb)) {
return dissect_tapa_tunnel(tvb, pinfo, tree);
} else
return 0;
}
void
proto_register_tapa(void)
{
static hf_register_info hf[] = {
{ &hf_tapa_discover_type,
{ "Type", "tapa.discover.type", FT_UINT8, BASE_DEC, VALS(tapa_discover_type_vals),
0x0, NULL, HFILL }},
{ &hf_tapa_discover_flags,
{ "Flags", "tapa.discover.flags", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_length,
{ "Length", "tapa.discover.length", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_req_type,
{ "Req type", "tapa.discover.req.type", FT_UINT8, BASE_DEC, VALS(tapa_discover_request_vals),
0x0, NULL, HFILL }},
{ &hf_tapa_discover_req_pad,
{ "Req padding", "tapa.discover.req.pad", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_req_length,
{ "Req length", "tapa.discover.req.length", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_req_value,
{ "Req value", "tapa.discover.req.value", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_reply_switchip,
{ "Switch Ip", "tapa.discover.reply.switchip", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_reply_unused,
{ "Reply unused", "tapa.discover.reply.unused", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_reply_bias,
{ "Reply bias", "tapa.discover.reply.bias", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_reply_pad,
{ "Reply pad", "tapa.discover.reply.pad", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_newtlv_type,
{ "New tlv type", "tapa.discover.newtlv.type", FT_UINT8, BASE_DEC, VALS(tapa_discover_request_vals),
0x0, NULL, HFILL }},
{ &hf_tapa_discover_newtlv_pad,
{ "New tlv padding", "tapa.discover.newtlv.pad", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_newtlv_length,
{ "New tlv length", "tapa.discover.newtlv.length", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_newtlv_valuetext,
{ "New tlv value", "tapa.discover.newtlv.valuetext", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_newtlv_valuehex,
{ "New tlv value", "tapa.discover.newtlv.valuehex", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_discover_unknown,
{ "Tapa unknown packet", "tapa.discover.unknown", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_tunnel_version,
{ "Tapa tunnel version", "tapa.tunnel.version", FT_UINT8, BASE_HEX, NULL,
0xF0, NULL, HFILL }},
{ &hf_tapa_tunnel_five,
{ "Tapa tunnel five", "tapa.tunnel.five", FT_UINT8, BASE_HEX, NULL,
0x0F, NULL, HFILL }},
{ &hf_tapa_tunnel_type,
{ "Tapa tunnel type", "tapa.tunnel.type", FT_UINT8, BASE_HEX, VALS(tapa_tunnel_type_vals),
0x0, NULL, HFILL }},
{ &hf_tapa_tunnel_zero,
{ "Tapa tunnel zeroes", "tapa.tunnel.zero", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_tunnel_dmac,
{ "Tapa tunnel dest mac", "tapa.tunnel.dmac", FT_ETHER, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_tunnel_smac,
{ "Tapa tunnel src mac", "tapa.tunnel.smac", FT_ETHER, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_tunnel_0804,
{ "Tapa tunnel 0804", "tapa.tunnel.0804", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_tunnel_tagsetc,
{ "Tapa tunnel tags, seqno, pad", "tapa.tunnel.tags", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_tunnel_seqno,
{ "Tapa tunnel seqno", "tapa.tunnel.seqno", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_tunnel_length,
{ "Tapa tunnel length", "tapa.tunnel.length", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_tapa_tunnel_remaining,
{ "Tapa tunnel all data", "tapa.tunnel.remaining", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_tapa_discover,
&ett_tapa_discover_req,
&ett_tapa_tunnel,
};
proto_tapa = proto_register_protocol(PROTO_LONG_NAME,
PROTO_SHORT_NAME, "tapa");
proto_register_field_array(proto_tapa, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("tapa", dissect_tapa_static, proto_tapa);
}
void
proto_reg_handoff_tapa(void)
{
dissector_handle_t tapa_handle;
tapa_handle = find_dissector("tapa");
dissector_add_uint("udp.port", PORT_TAPA, tapa_handle);
}
